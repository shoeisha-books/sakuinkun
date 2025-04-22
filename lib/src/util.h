/**
 * @file util.h
 * @brief 便利関数詰め合わせ
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 * Copyright (C) 2024 Shoeisha Co., Ltd.
 */

#pragma once
#include <string>
#include "sakuinkunpp/IndexDesc.hpp"

namespace sakuin
{
extern std::wstring convToRoman(int num, bool cap = true);
extern int convFromRoman(const std::wstring& roman);
extern std::wstring getUUID();
extern std::wstring calcPageStr(int origPage, const IndexDesc& header);
extern std::wstring getUserDir();
}
