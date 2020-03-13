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

#include "v8.h"
#include "jsrtutils.h"
#include "v8-debug.h"
#include "jsrtinspector.h"

#include <assert.h>

namespace v8 {

Context::Scope::Scope(Handle<Context> context) {
  jsrt::IsolateShim * isolateShim = jsrt::IsolateShim::GetCurrent();
  assert(isolateShim != nullptr);
  isolateShim->PushScope(
    reinterpret_cast<jsrt::ContextShim::Scope  *>(this),
    (JsContextRef)*context);
}

Context::Scope::~Scope() {
  jsrt::IsolateShim::GetCurrent()->PopScope(
    reinterpret_cast<jsrt::ContextShim::Scope *>(this));
}

Local<Object> Context::Global() {
  // V8 Global is actually proxy where the actual global is it's prototype.
  // No need to create handle here, the context will keep it alive
  return Local<Object>(static_cast<Object *>(
    jsrt::IsolateShim::GetContextShim(
      reinterpret_cast<JsContextRef *>(this))->GetProxyOfGlobal()));
}

extern bool g_exposeGC;

Local<Context> Context::New(Isolate* external_isolate,
                            bool useGlobalTTState,
                            ExtensionConfiguration* extensions,
                            Handle<ObjectTemplate> global_template,
                            Handle<Value> global_object) {
  // CHAKRA-TODO: extensions and global_object parameter is not implemented
  if (extensions != nullptr || *global_object != JS_INVALID_REFERENCE) {
    CHAKRA_UNIMPLEMENTED_(
    "Context::New with externsions/global_object argument");
    return Local<Context>();
  }

  Local<Object> glob;
  if (!global_template.IsEmpty()) {
    glob = global_template->NewInstance();
    if (glob.IsEmpty()) {
      return Local<Context>();
    }
  }

  JsContextRef context;
  jsrt::IsolateShim* isoShim = jsrt::IsolateShim::FromIsolate(external_isolate);
  if (!isoShim->NewContext(&context, g_exposeGC, useGlobalTTState, *glob)) {
    return Local<Context>();
  }

  Local<Context> thisContext = Local<Context>::New(
      external_isolate, static_cast<Context *>(context));

  if (jsrt::Inspector::IsInspectorEnabled() &&
      isoShim->debugContext == nullptr) {
    // If JavaScript debugging APIs need to be exposed then make sure
    // debugContext is available and chakra_inspector.js is compiled. Inject
    // v8debug object from chakra_inspector.js into this context's global
    // object.
    JsContextRef debugContextRef;
    isoShim->NewContext(&debugContextRef, false, false, *glob);
    jsrt::ContextShim* debugContextShim = isoShim->GetContextShim(
        debugContextRef);

    isoShim->debugContext = debugContextShim;

    {
      Local<Context> debugContextLocal = Local<Context>::New(
          external_isolate, static_cast<Context *>(debugContextRef));

      Context::Scope context_scope(debugContextLocal);

      JsValueRef chakraDebugObject;
      if (debugContextShim->ExecuteChakraInspectorShimJS(&chakraDebugObject)) {
        jsrt::Inspector::SetChakraDebugObject(chakraDebugObject);
      }
    }
  }

  return thisContext;
}

Local<Context> Context::GetCurrent() {
  JsContextRef current = jsrt::ContextShim::GetCurrent()->GetContextRef();

  // Don't need to create a ref here, because a context can't keep itself alive
  // anyway.
  return Local<Context>(static_cast<Context *>(current));
}

Isolate* Context::GetIsolate() {
  return Isolate::GetCurrent();
}

void Context::Enter() {
  // CHAKRA-TODO - Figure out what to do here.
  CHAKRA_UNIMPLEMENTED();
}

void Context::Exit() {
  // CHAKRA-TODO - Figure out what to do here.
  CHAKRA_UNIMPLEMENTED();
}

void* Context::GetAlignedPointerFromEmbedderData(int index) {
  jsrt::ContextShim * contextShim =
    jsrt::IsolateShim::GetCurrent()->GetContextShim((JsContextRef)this);
  return contextShim->GetAlignedPointerFromEmbedderData(index);
}

void Context::SetAlignedPointerInEmbedderData(int index, void* value) {
  jsrt::ContextShim * contextShim =
    jsrt::IsolateShim::GetCurrent()->GetContextShim((JsContextRef)this);
  return contextShim->SetAlignedPointerInEmbedderData(index, value);
}

void Context::SetEmbedderData(int index, Local<Value> value) {
    SetAlignedPointerInEmbedderData(index, *value);
}

uint32_t Context::GetNumberOfEmbedderDataFields() {
  jsrt::ContextShim * contextShim =
      jsrt::IsolateShim::GetCurrent()->GetContextShim((JsContextRef)this);
  return contextShim->GetNumberOfEmbedderDataFields();
}

Local<Value> Context::GetEmbedderData(int index) {
  return Local<Value>(GetAlignedPointerFromEmbedderData(index));
}

void Context::SetSecurityToken(Handle<Value> token) {
  // CHAKRA-TODO
}

Handle<Value> Context::GetSecurityToken() {
  // CHAKRA-TODO
  return Handle<Value>();
}

void Context::AllowCodeGenerationFromStrings(bool allow) {
  // CHAKRA-TODO
}

void Context::CacheGlobalProperties() {
  jsrt::IsolateShim::GetContextShim(
      reinterpret_cast<JsContextRef *>(this))->CacheGlobalProperties();
}

void Context::ResolveGlobalChanges(Local<Object> sandbox) {
  jsrt::IsolateShim::GetContextShim(
      reinterpret_cast<JsContextRef *>(this))
    ->ResolveGlobalChanges((JsValueRef)*sandbox);
}
}  // namespace v8
