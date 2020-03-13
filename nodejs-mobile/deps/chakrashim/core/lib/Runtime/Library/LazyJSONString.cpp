//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------

#include "RuntimeLibraryPch.h"

namespace Js
{

LazyJSONString::LazyJSONString(_In_ JSONProperty* jsonContent, charcount_t length, _In_opt_ const char16* gap, charcount_t gapLength, _In_ StaticType* type) :
    JavascriptString(type),
    jsonContent(jsonContent),
    gap(gap),
    gapLength(gapLength)
{
    // Use SetLength to ensure length is valid
    SetLength(length);
}

bool
LazyJSONString::HasComplexGap() const
{
    for (charcount_t i = 0; i < this->gapLength; ++i)
    {
        switch (this->gap[i])
        {
        // This is not exhaustive, just a useful subset of semantics preserving characters
        case _u(' '):
        case _u('\t'):
        case _u('\n'):
            continue;
        default:
            return true;
        }
    }
    return false;
}

DynamicObject*
LazyJSONString::ReconstructObject(_In_ JSONObject* valueList) const
{
    const uint elementCount = valueList->Count();

    // This is just a heuristic, so overflow doesn't matter
    PropertyIndex requestedInlineSlotCapacity = static_cast<PropertyIndex>(elementCount);

    DynamicObject* obj = this->GetLibrary()->CreateObject(
        true, // allowObjectHeaderInlining
        requestedInlineSlotCapacity);

    FOREACH_SLISTCOUNTED_ENTRY(JSONObjectProperty, entry, valueList)
    {
        Var propertyValue = ReconstructVar(&entry.propertyValue);
        JavascriptString* propertyName = entry.propertyName;
        PropertyString* propertyString = PropertyString::TryFromVar(propertyName);
        PropertyValueInfo info;
        if (!propertyString || !propertyString->TrySetPropertyFromCache(obj, propertyValue, this->GetScriptContext(), PropertyOperation_None, &info))
        {
            Js::PropertyRecord const * localPropertyRecord;
            propertyName->GetPropertyRecord(&localPropertyRecord);
            JavascriptOperators::SetProperty(obj, obj, localPropertyRecord->GetPropertyId(),
                propertyValue, &info, this->GetScriptContext());
        }
    }
    NEXT_SLISTCOUNTED_ENTRY;
    return obj;
}

JavascriptArray*
LazyJSONString::ReconstructArray(_In_ JSONArray* jsonArray) const
{
    const uint32 length = jsonArray->length;
    JavascriptArray* arr = this->GetLibrary()->CreateArrayLiteral(length);
    JSONProperty* prop = jsonArray->arr;
    for (uint i = 0; i < length; ++i)
    {
        Var element = ReconstructVar(&prop[i]);
        BOOL result = arr->SetItem(i, element, PropertyOperation_None);
        Assert(result); // Setting item in an array we just allocated should always succeed
    }
    return arr;
}

Var
LazyJSONString::ReconstructVar(_In_ JSONProperty* prop) const
{
    switch (prop->type)
    {
    case JSONContentType::Array:
        return ReconstructArray(prop->arr);
    case JSONContentType::Null:
        return this->GetLibrary()->GetNull();
    case JSONContentType::True:
        return this->GetLibrary()->GetTrue();
    case JSONContentType::False:
        return this->GetLibrary()->GetFalse();
    case JSONContentType::Number:
        return prop->numericValue.value;
    case JSONContentType::String:
        return prop->stringValue;
    case JSONContentType::Object:
        return ReconstructObject(prop->obj);
    default:
        Assume(UNREACHED);
        return nullptr;
    }
}

Var
LazyJSONString::TryParse() const
{
    // If we have thrown away our metadata, we won't be able to Parse
    if (this->jsonContent == nullptr)
    {
        return nullptr;
    }

    // If the gap is complex, this means that parse will be a non-trivial transformation,
    // so fall back to the real parse
    if (this->HasComplexGap())
    {
        return nullptr;
    }

    Var result = ReconstructVar(this->jsonContent);

    return result;
}

const char16*
LazyJSONString::GetSz()
{
    if (this->IsFinalized())
    {
        return this->UnsafeGetBuffer();
    }

    const charcount_t allocSize = this->SafeSzSize();

    Recycler* recycler = GetScriptContext()->GetRecycler();
    char16* target = RecyclerNewArrayLeaf(recycler, char16, allocSize);

    JSONStringBuilder builder(
        this->GetScriptContext(),
        this->jsonContent,
        target,
        allocSize,
        this->gap,
        this->gapLength);

    builder.Build();

    this->SetBuffer(target);

    // You probably aren't going to parse if you are using the string buffer
    // Let's throw away the metadata so we can reclaim the memory
    this->jsonContent = nullptr;

    return target;
}

// static
bool
LazyJSONString::Is(Var var)
{
    return RecyclableObject::Is(var) && VirtualTableInfo<LazyJSONString>::HasVirtualTable(RecyclableObject::FromVar(var));
}

// static
LazyJSONString*
LazyJSONString::TryFromVar(Var var)
{
    return LazyJSONString::Is(var)
        ? reinterpret_cast<LazyJSONString*>(var)
        : nullptr;
}

} // namespace Js
