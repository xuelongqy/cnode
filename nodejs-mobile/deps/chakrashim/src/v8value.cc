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
#include <limits.h>
#include <math.h>

#ifdef __APPLE__
inline int isnan(double x) {
  return std::isnan(x);
}

int isfinite(double x) {
  return std::isfinite(x);
}
#endif

namespace v8 {

using jsrt::ContextShim;

static bool IsOfType(const Value* ref, JsValueType type) {
  JsValueType valueType;
  if (JsGetValueType(const_cast<Value*>(ref), &valueType) != JsNoError) {
    return false;
  }
  return valueType == type;
}

bool Value::IsUndefined() const {
  return this == jsrt::GetUndefined();
}

bool Value::IsNull() const {
  return this == jsrt::GetNull();
}

bool Value::IsNullOrUndefined() const {
  return IsNull() || IsUndefined();
}

bool Value::IsTrue() const {
  return this == jsrt::GetTrue();
}

bool Value::IsFalse() const {
  return this == jsrt::GetFalse();
}

#define ISJSVALUETYPE(Type) \
bool Value::Is##Type() const { \
  return IsOfType(this, JsValueType::Js##Type); \
}

ISJSVALUETYPE(String)
ISJSVALUETYPE(Symbol)
ISJSVALUETYPE(Function)
ISJSVALUETYPE(Array)
ISJSVALUETYPE(ArrayBuffer)
ISJSVALUETYPE(TypedArray)
ISJSVALUETYPE(DataView)
ISJSVALUETYPE(Boolean)
ISJSVALUETYPE(Number)

bool Value::IsObject() const {
  JsValueType type;
  if (JsGetValueType((JsValueRef)this, &type) != JsNoError) {
    return false;
  }

  return type >= JsValueType::JsObject && type != JsSymbol;
}

bool Value::IsExternal() const {
  return External::IsExternal(this);
}

#define DEFINE_TYPEDARRAY_CHECK(ArrayType) \
  bool Value::Is##ArrayType##Array() const { \
  JsTypedArrayType typedArrayType; \
  return JsGetTypedArrayInfo(const_cast<Value*>(this), \
                             &typedArrayType, \
                             nullptr, nullptr, nullptr) == JsNoError && \
  typedArrayType == JsTypedArrayType::JsArrayType##ArrayType; \
}

DEFINE_TYPEDARRAY_CHECK(Uint8)
DEFINE_TYPEDARRAY_CHECK(Uint8Clamped)
DEFINE_TYPEDARRAY_CHECK(Int8)
DEFINE_TYPEDARRAY_CHECK(Uint16)
DEFINE_TYPEDARRAY_CHECK(Int16)
DEFINE_TYPEDARRAY_CHECK(Uint32)
DEFINE_TYPEDARRAY_CHECK(Int32)
DEFINE_TYPEDARRAY_CHECK(Float32)
DEFINE_TYPEDARRAY_CHECK(Float64)

bool Value::IsArrayBufferView() const {
  return IsTypedArray() || IsDataView();
}

bool Value::IsInt32() const {
  if (!IsNumber()) {
    return false;
  }

  double value = NumberValue();

  // check that the value is smaller than int 32 bit maximum
  if (value > INT_MAX || value < INT_MIN) {
    return false;
  }

  return trunc(value) == value;
}

bool Value::IsUint32() const {
  if (!IsNumber()) {
    return false;
  }

  double value = NumberValue();
  // check that the value is smaller than 32 bit maximum
  if (value < 0 || value > UINT_MAX) {
    return false;
  }

  return trunc(value) == value;
}

bool Value::IsProxy() const {
  bool isProxy = false;
  if (JsGetProxyProperties((JsValueRef)this, &isProxy, nullptr,
                           nullptr) == JsNoError) {
    return isProxy;
  }

  return false;
}

bool Value::IsPromise() const {
  // If the call to JsGetPromiseState returns successfully, then we must have
  // a valid Promise object.
  JsPromiseState state = JsPromiseStatePending;
  return (JsGetPromiseState((JsValueRef)this, &state) == JsNoError);
}

#define IS_TYPE_FUNCTION(v8ValueFunc, chakrashimFunc) \
bool Value::v8ValueFunc() const { \
JsValueRef resultRef = JS_INVALID_REFERENCE; \
JsErrorCode errorCode = jsrt::Call##chakrashimFunc( \
  const_cast<Value*>(this), &resultRef); \
if (errorCode != JsNoError) { \
  return false; \
} \
return Local<Value>(resultRef)->BooleanValue(); \
}

// Refer to jsrtcachedpropertyidref.inc for the full list
// DEF_IS_TYPE is not structured correctly in order to be used here
IS_TYPE_FUNCTION(IsBooleanObject, isBooleanObject)
IS_TYPE_FUNCTION(IsDate, isDate)
IS_TYPE_FUNCTION(IsMap, isMap)
IS_TYPE_FUNCTION(IsNativeError, isNativeError)
IS_TYPE_FUNCTION(IsRegExp, isRegExp)
IS_TYPE_FUNCTION(IsAsyncFunction, isAsyncFunction)
IS_TYPE_FUNCTION(IsSet, isSet)
IS_TYPE_FUNCTION(IsStringObject, isStringObject)
IS_TYPE_FUNCTION(IsNumberObject, isNumberObject)
IS_TYPE_FUNCTION(IsMapIterator, isMapIterator)
IS_TYPE_FUNCTION(IsSetIterator, isSetIterator)
IS_TYPE_FUNCTION(IsArgumentsObject, isArgumentsObject)
IS_TYPE_FUNCTION(IsGeneratorObject, isGeneratorObject)
IS_TYPE_FUNCTION(IsGeneratorFunction, isGeneratorFunction)
IS_TYPE_FUNCTION(IsWebAssemblyCompiledModule, isWebAssemblyCompiledModule)
IS_TYPE_FUNCTION(IsWeakMap, isWeakMap)
IS_TYPE_FUNCTION(IsWeakSet, isWeakSet)
IS_TYPE_FUNCTION(IsSymbolObject, isSymbolObject)
IS_TYPE_FUNCTION(IsName, isName)
IS_TYPE_FUNCTION(IsSharedArrayBuffer, isSharedArrayBuffer)
IS_TYPE_FUNCTION(IsModuleNamespaceObject, isModuleNamespaceObject)
#undef IS_TYPE_FUNCTION

bool Value::IsBigIntObject() const {
  // CHAKRA-TODO: BigInt support needed in ChakraCore
  return false;
}

bool Value::IsBigUint64Array() const {
  // CHAKRA-TODO: BigInt support needed in ChakraCore
  return false;
}

MaybeLocal<Boolean> Value::ToBoolean(Local<Context> context) const {
  JsValueRef value;
  if (JsConvertValueToBoolean((JsValueRef)this, &value) != JsNoError) {
    return Local<Boolean>();
  }

  return Local<Boolean>::New(value);
}

MaybeLocal<Number> Value::ToNumber(Local<Context> context) const {
  JsValueRef value;
  if (JsConvertValueToNumber((JsValueRef)this, &value) != JsNoError) {
    return Local<Number>();
  }

  return Local<Number>::New(value);
}

MaybeLocal<String> Value::ToString(Local<Context> context) const {
  JsValueRef value;
  if (JsConvertValueToString((JsValueRef)this, &value) != JsNoError) {
    return Local<String>();
  }

  return Local<String>::New(value);
}

MaybeLocal<String> Value::ToDetailString(Local<Context> context) const {
  return ToString(context);
}

MaybeLocal<Object> Value::ToObject(Local<Context> context) const {
  JsValueRef value;
  if (JsConvertValueToObject((JsValueRef)this, &value) != JsNoError) {
    return Local<Object>();
  }

  return Local<Object>::New(value);
}

MaybeLocal<Integer> Value::ToInteger(Local<Context> context) const {
  Maybe<double> maybe = NumberValue(context);
  if (maybe.IsNothing()) {
    return Local<Integer>();
  }
  double doubleValue = maybe.FromJust();

  double value = isfinite(doubleValue) ? trunc(doubleValue) :
                  (isnan(doubleValue) ? 0 : doubleValue);
  int intValue = static_cast<int>(value);
  if (value == intValue) {
    return Integer::New(nullptr, intValue);
  }

  Value* result = value == doubleValue ?
                    const_cast<Value*>(this) : *Number::New(nullptr, value);
  return Local<Integer>(reinterpret_cast<Integer*>(result));
}

MaybeLocal<Uint32> Value::ToUint32(Local<Context> context) const {
  Local<Integer> jsValue = Integer::NewFromUnsigned(nullptr,
                                                    this->Uint32Value());
  return jsValue.As<Uint32>();
}

MaybeLocal<Int32> Value::ToInt32(Local<Context> context) const {
  Local<Integer> jsValue = Integer::New(nullptr, this->Int32Value());
  return jsValue.As<Int32>();
}

Local<Boolean> Value::ToBoolean(Isolate* isolate) const {
  return FromMaybe(ToBoolean(Local<Context>()));
}

Local<Number> Value::ToNumber(Isolate* isolate) const {
  return FromMaybe(ToNumber(Local<Context>()));
}

Local<String> Value::ToString(Isolate* isolate) const {
  return FromMaybe(ToString(Local<Context>()));
}

Local<String> Value::ToDetailString(Isolate* isolate) const {
  return FromMaybe(ToDetailString(Local<Context>()));
}

Local<Object> Value::ToObject(Isolate* isolate) const {
  return FromMaybe(ToObject(Local<Context>()));
}

Local<Integer> Value::ToInteger(Isolate* isolate) const {
  return FromMaybe(ToInteger(Local<Context>()));
}

Local<Uint32> Value::ToUint32(Isolate* isolate) const {
  return FromMaybe(ToUint32(Local<Context>()));
}

Local<Int32> Value::ToInt32(Isolate* isolate) const {
  return FromMaybe(ToInt32(Local<Context>()));
}

MaybeLocal<Uint32> Value::ToArrayIndex(Local<Context> context) const {
  if (IsNumber()) {
    return ToUint32(context);
  }

  MaybeLocal<String> maybeString = ToString(context);
  bool isUint32;
  uint32_t uint32Value;
  if (maybeString.IsEmpty() ||
      jsrt::TryParseUInt32(*FromMaybe(maybeString),
                           &isUint32, &uint32Value) != JsNoError) {
    return Local<Uint32>();
  }

  return Integer::NewFromUnsigned(nullptr, uint32Value).As<Uint32>();
}

Local<Uint32> Value::ToArrayIndex() const {
  return FromMaybe(ToArrayIndex(Local<Context>()));
}

Maybe<bool> Value::BooleanValue(Local<Context> context) const {
  bool value;
  if (jsrt::ValueToNative</*LIKELY*/true>(JsConvertValueToBoolean,
                                          JsBooleanToBool,
                                          (JsValueRef)this,
                                          &value) != JsNoError) {
    return Nothing<bool>();
  }
  return Just(value);
}

Maybe<double> Value::NumberValue(Local<Context> context) const {
  double value;
  if (jsrt::ValueToDoubleLikely((JsValueRef)this, &value) != JsNoError) {
    return Nothing<double>();
  }
  return Just(value);
}

Maybe<int64_t> Value::IntegerValue(Local<Context> context) const {
  Maybe<double> maybe = NumberValue(context);
  if (maybe.IsNothing()) {
      return Nothing<int64_t>();
  }

  double value = maybe.FromJust();
  if (isnan(value)) {
      return Just<int64_t>(0);
  }

  return Just(static_cast<int64_t>(value));
}

Maybe<uint32_t> Value::Uint32Value(Local<Context> context) const {
  Maybe<int32_t> maybe = Int32Value(context);
  return maybe.IsNothing() ?
    Nothing<uint32_t>() : Just(static_cast<uint32_t>(maybe.FromJust()));
}

Maybe<int32_t> Value::Int32Value(Local<Context> context) const {
  int intValue;
  if (jsrt::ValueToIntLikely((JsValueRef)this, &intValue) != JsNoError) {
    return Nothing<int32_t>();
  }
  return Just(intValue);
}

bool Value::BooleanValue() const {
  return FromMaybe(BooleanValue(Local<Context>()));
}

double Value::NumberValue() const {
  return FromMaybe(NumberValue(Local<Context>()));
}

int64_t Value::IntegerValue() const {
  return FromMaybe(IntegerValue(Local<Context>()));
}

uint32_t Value::Uint32Value() const {
  return FromMaybe(Uint32Value(Local<Context>()));
}

int32_t Value::Int32Value() const {
  return FromMaybe(Int32Value(Local<Context>()));
}

Maybe<bool> Value::Equals(Local<Context> context, Handle<Value> that) const {
  bool equals;
  if (JsEquals((JsValueRef)this, *that, &equals) != JsNoError) {
    return Nothing<bool>();
  }

  return Just(equals);
}

bool Value::Equals(Handle<Value> that) const {
  return FromMaybe(Equals(Local<Context>(), that));
}

bool Value::StrictEquals(Handle<Value> that) const {
  bool strictEquals;
  if (JsStrictEquals((JsValueRef)this, *that, &strictEquals) != JsNoError) {
    return false;
  }

  return strictEquals;
}

bool Value::SameValue(Local<Value> that) const {
  CHAKRA_UNIMPLEMENTED();
  return false;
}

}  // namespace v8
