/**
 * @file ConfigData.h
 * @brief コンフィグデータ
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 * Copyright (C) 2024 Shoeisha Co., Ltd.
 */

#pragma once
#include <string>
#include <vector>

struct VersionData
{
    int majorVer = 3;   // 3
    int minorVer = 0;
    int patchVer = 0;
};

constexpr size_t PathMaxLength = 512;
constexpr size_t DicSummaryMaxLength = 128;

struct UserDicConfigData
{
    std::wstring path;
    std::wstring summary;
};

struct DicConfigData
{
    std::wstring systemDicPath;
    std::vector<UserDicConfigData> userDics;
};

struct LastData
{
    std::wstring workingPath;
};

struct ConfigData
{
    VersionData version;
    DicConfigData dic;
    LastData last;

    static ConfigData getDefault()
    {
        ConfigData ret;
        ret.dic.systemDicPath = L"./dic";
        return ret;
    }
};
