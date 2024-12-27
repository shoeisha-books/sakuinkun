/**
 * @file Reference.cpp
 * @brief 参照クラス
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 * Copyright (C) 2024 Shoeisha Co., Ltd.
 */

#include "sakuinkunpp/Reference.hpp"
#include "sakuinkunpp/IndexDesc.hpp"
#include "util.h"
#include "sakuin_def.h"
#include <stdexcept>
#include <boost/nowide/convert.hpp>

using namespace sakuin;

Reference::Reference(ReferenceType type, int page, const std::wstring& refStr)
    : type_(type), page_(page), refStr_(refStr)
{

}

bool Reference::getData(const IndexDesc& desc, ReferenceData& data)const
{
    switch (type_)
    {
    case ReferenceType::Nombre:
        data.type = 0;
        break;
    case ReferenceType::Range:
        data.type = 1;
        break;
    case ReferenceType::See:
        data.type = 2;
        break;
    case ReferenceType::SeeAlso:
        data.type = 3;
        break;
    case ReferenceType::Manual:
        data.type = 4;
        break;
    default:
        data.type = -1;
        break;
    }

    data.page = page_;

    auto dispStr = calcDispStr(desc);
    if (dispStr.size() >= data.disp_str_len - 1)
    {
        throw std::runtime_error("Too Large RefStr: " + boost::nowide::narrow(refStr_));
        return false;
    }

    std::wcsncpy(data.disp_str, dispStr.c_str(), dispStr.length());
    data.disp_str[dispStr.length()] = L'\0';

    return true;
}

ReferenceType Reference::getType()const
{
    return type_;
}

int Reference::getPage()const
{
    return page_;
}

std::wstring Reference::getRefStr()const
{
    return refStr_;
}

std::strong_ordering Reference::operator<=>(const Reference& that)const
{
    auto comp = page_ <=> that.page_;
    return comp;
}

std::wstring Reference::calcDispStr(const IndexDesc& desc)const
{
    switch (type_)
    {
    case ReferenceType::Nombre:
        return calcPageStr(page_, desc);
    case ReferenceType::Range:
        return calcPageStr(page_, desc) + RangeMark + refStr_;
    case ReferenceType::See:
        return SeeMark + refStr_;
    case ReferenceType::SeeAlso:
        return SeeAlsoMark + refStr_;
    case ReferenceType::Manual:
        return refStr_;
    }
    return L"";
}
