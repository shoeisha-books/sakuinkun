/**
 * @file IndexDesc.cpp
 * @brief 索引設定クラス
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 * Copyright (C) 2024 Shoeisha Co., Ltd.
 */

#include "sakuinkunpp/IndexDesc.hpp"
#include "sakuin_def.h"


using namespace sakuin;

// 索引ヘッダ

IndexDesc::IndexDesc(int offset, int romanPageNum, bool romanCap, const std::wstring& repeat)
    : offset_(offset), romanPageNum_(romanPageNum), romanCap_(romanCap), repeat_(repeat)
{
    
}

bool IndexDesc::getData(IndexDescData& data)const
{
    data.offset = offset_;
    data.roman_page_num = romanPageNum_;
    data.roman_cap = romanCap_;
    
    auto repeat = repeat_ + L"\0";
    std::wcsncpy(data.repeat, repeat.c_str(), repeat.length());

    return true;
}

int IndexDesc::getOffset()const
{
    return offset_;
}

int IndexDesc::getRomanPageNum()const
{
    return romanPageNum_;
}

bool IndexDesc::isRomanCap()const
{
    return romanCap_;
}

std::wstring IndexDesc::getRepeat()const
{
    return repeat_;
}
