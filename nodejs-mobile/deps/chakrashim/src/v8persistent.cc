// Copyright Microsoft. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and / or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#include "v8chakra.h"

namespace v8 {

void CHAKRA_CALLBACK Utils::WeakReferenceCallbackWrapperCallback(JsRef ref,
                                                                 void* data) {
  if (jsrt::IsolateShim::GetCurrent()->IsDisposing()) {
    return;
  }

  const chakrashim::WeakReferenceCallbackWrapper* callbackWrapper =
    reinterpret_cast<const chakrashim::WeakReferenceCallbackWrapper*>(data);
  if (callbackWrapper->isWeakCallbackInfo) {
    WeakCallbackInfo<void>::Callback callback;
    void* fields[kInternalFieldsInWeakCallback] = {};
    WeakCallbackInfo<void> info(Isolate::GetCurrent(),
                                callbackWrapper->parameters,
                                fields, &callback);
    callbackWrapper->infoCallback(info);
  } else {
    WeakCallbackData<Value, void> data(Isolate::GetCurrent(),
                                       callbackWrapper->parameters,
                                       static_cast<Value*>(ref));
    callbackWrapper->dataCallback(data);
  }
}

namespace chakrashim {

static void CHAKRA_CALLBACK DummyObjectBeforeCollectCallback(JsRef ref,
                                                             void* data) {
  // Do nothing, only used to revive an object temporarily
}

void ClearObjectWeakReferenceCallback(JsValueRef object, bool revive) {
  if (jsrt::IsolateShim::GetCurrent()->IsDisposing()) {
    return;
  }

  JsSetObjectBeforeCollectCallback(
    object, nullptr, revive ? DummyObjectBeforeCollectCallback : nullptr);
}

template <class Callback, class Func>
void SetObjectWeakReferenceCallbackCommon(
    JsValueRef object,
    Callback callback,
    WeakReferenceCallbackWrapper** weakWrapper,
    const Func& initWrapper) {
  if (callback == nullptr || object == JS_INVALID_REFERENCE) {
    return;
  }

  // This will be called once per instance
  // We do not share the _weakWrapper.
  // The memory is allocated per request and released similarly.
  // previous shared_ptr interface was actually doing the same.
  // however in case the instance was shared(which is not in motion)
  // it was keeping the callback until the shared counter reaches to unique
  // state.
  assert(!*weakWrapper && "This should be nullptr.");
  *weakWrapper = new WeakReferenceCallbackWrapper();

  WeakReferenceCallbackWrapper* callbackWrapper = (*weakWrapper);
  initWrapper(callbackWrapper);

  JsSetObjectBeforeCollectCallback(
    object, callbackWrapper,
    v8::Utils::WeakReferenceCallbackWrapperCallback);
}

void SetObjectWeakReferenceCallback(
    JsValueRef object,
    WeakCallbackInfo<void>::Callback callback,
    void* parameters,
    WeakReferenceCallbackWrapper** weakWrapper) {
  SetObjectWeakReferenceCallbackCommon(
    object, callback, weakWrapper,
    [=](WeakReferenceCallbackWrapper* callbackWrapper) {
      callbackWrapper->parameters = parameters;
      callbackWrapper->infoCallback = callback;
      callbackWrapper->isWeakCallbackInfo = true;
  });
}

void SetObjectWeakReferenceCallback(
    JsValueRef object,
    WeakCallbackData<Value, void>::Callback callback,
    void* parameters,
    WeakReferenceCallbackWrapper** weakWrapper) {
  SetObjectWeakReferenceCallbackCommon(
    object, callback, weakWrapper,
    [=](WeakReferenceCallbackWrapper* callbackWrapper) {
      callbackWrapper->parameters = parameters;
      callbackWrapper->dataCallback = callback;
      callbackWrapper->isWeakCallbackInfo = false;
  });
}

}  // namespace chakrashim
}  // namespace v8
