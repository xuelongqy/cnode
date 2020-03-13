// Copyright 2014 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/inspector/v8-debugger-script.h"

#include "src/inspector/protocol-platform.h"
#include "src/inspector/string-util.h"
#include "src/inspector/search-util.h"

#include "src/jsrtinspectorhelpers.h"
#include "src/jsrtutils.h"

namespace v8_inspector {

using jsrt::InspectorHelpers;

static const char hexDigits[17] = "0123456789ABCDEF";

static void appendUnsignedAsHex(uint64_t number, String16Builder* destination) {
  for (size_t i = 0; i < 8; ++i) {
    UChar c = hexDigits[number & 0xF];
    destination->append(c);
    number >>= 4;
  }
}

// Hash algorithm for substrings is described in "Über die Komplexität der
// Multiplikation in
// eingeschränkten Branchingprogrammmodellen" by Woelfe.
// http://opendatastructures.org/versions/edition-0.1d/ods-java/node33.html#SECTION00832000000000000000
static String16 calculateHash(const String16& str) {
  static uint64_t prime[] = {0x3FB75161, 0xAB1F4E4F, 0x82675BC5, 0xCD924D35,
                             0x81ABE279};
  static uint64_t random[] = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476,
                              0xC3D2E1F0};
  static uint32_t randomOdd[] = {0xB4663807, 0xCC322BF5, 0xD4F91BBD, 0xA7BEA11D,
                                 0x8F462907};

  uint64_t hashes[] = {0, 0, 0, 0, 0};
  uint64_t zi[] = {1, 1, 1, 1, 1};

  const size_t hashesSize = arraysize(hashes);

  size_t current = 0;
  const uint32_t* data = nullptr;
  size_t sizeInBytes = sizeof(UChar) * str.length();
  data = reinterpret_cast<const uint32_t*>(str.characters16());
  for (size_t i = 0; i < sizeInBytes / 4; i += 4) {
    uint32_t v = data[i];
    uint64_t xi = v * randomOdd[current] & 0x7FFFFFFF;
    hashes[current] = (hashes[current] + zi[current] * xi) % prime[current];
    zi[current] = (zi[current] * random[current]) % prime[current];
    current = current == hashesSize - 1 ? 0 : current + 1;
  }
  if (sizeInBytes % 4) {
    uint32_t v = 0;
    for (size_t i = sizeInBytes - sizeInBytes % 4; i < sizeInBytes; ++i) {
      v <<= 8;
      v |= reinterpret_cast<const uint8_t*>(data)[i];
    }
    uint64_t xi = v * randomOdd[current] & 0x7FFFFFFF;
    hashes[current] = (hashes[current] + zi[current] * xi) % prime[current];
    zi[current] = (zi[current] * random[current]) % prime[current];
    current = current == hashesSize - 1 ? 0 : current + 1;
  }

  for (size_t i = 0; i < hashesSize; ++i)
    hashes[i] = (hashes[i] + zi[i] * (prime[i] - 1)) % prime[i];

  String16Builder hash;
  for (size_t i = 0; i < hashesSize; ++i) appendUnsignedAsHex(hashes[i], &hash);
  return hash.toString();
}

static JsErrorCode GetNamedStringValue(JsValueRef object,
                                       jsrt::CachedPropertyIdRef cachedIdRef,
                                       String16* value) {
  JsErrorCode err = JsNoError;

  JsValueRef propValue;
  err = jsrt::GetProperty(object, cachedIdRef, &propValue);
  if (err != JsNoError) {
    return err;
  }

  int stringLength = 0;
  err = JsGetStringLength(propValue, &stringLength);
  if (err != JsNoError) {
    return err;
  }

  std::unique_ptr<UChar[]> buffer(new UChar[stringLength]);
  err = JsCopyStringUtf16(propValue, 0, stringLength, buffer.get(), nullptr);
  if (err != JsNoError) {
    return err;
  }

  String16 str(buffer.get(), stringLength);
  value->swap(str);

  return JsNoError;
}

V8DebuggerScript::V8DebuggerScript(v8::Isolate* isolate, JsValueRef scriptData,
                                   bool isLiveEdit, V8InspectorClient* client)
  : m_startLine(0),
    m_startColumn(0),
    m_endColumn(0),
    m_executionContextId(1),
    m_isLiveEdit(false) {
  int scriptId = 0;
  if (jsrt::GetProperty(scriptData, jsrt::CachedPropertyIdRef::scriptId,
                        &scriptId) == JsNoError) {
    m_id = String16::fromInteger(scriptId);
  }

  int lineCount = 0;
  if (jsrt::GetProperty(scriptData, jsrt::CachedPropertyIdRef::lineCount,
                        &lineCount) == JsNoError) {
    m_endLine = lineCount;
  }

  String16 urlValue;
  if (GetNamedStringValue(scriptData, jsrt::CachedPropertyIdRef::fileName,
                          &urlValue) == JsNoError) {
    std::unique_ptr<StringBuffer> url =
        client->resourceNameToUrl(toStringView(urlValue));
    m_url = url ? toString16(url->string()) : urlValue;
  } else if (GetNamedStringValue(scriptData,
                               jsrt::CachedPropertyIdRef::scriptType,
                               &urlValue) == JsNoError) {
    m_url = urlValue;
  }

  v8::Local<v8::Value> sourceValue =
      jsrt::InspectorHelpers::GetScriptSource(scriptId);

  if (!sourceValue.IsEmpty() && sourceValue->IsString()) {
    setSource(isolate, sourceValue.As<v8::String>());
  }
}

V8DebuggerScript::~V8DebuggerScript() {}

const String16& V8DebuggerScript::sourceURL() const {
  return m_sourceURL.isEmpty() ? m_url : m_sourceURL;
}

v8::Local<v8::String> V8DebuggerScript::source(v8::Isolate* isolate) const {
  return m_source.Get(isolate);
}

void V8DebuggerScript::setSource(v8::Isolate* isolate,
                                 v8::Local<v8::String> source) {
  m_source.Reset(isolate, source);

  String16 scriptSource = toProtocolString(source);
  m_hash = calculateHash(scriptSource);
  m_sourceURL = findSourceURL(scriptSource, false);
  m_sourceMappingURL = findSourceMapURL(scriptSource, false);
}

}  // namespace v8_inspector
