/**
 * @file MeCabCtrl.h
 * @brief MeCabコントローラー
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 * Copyright (C) 2024 Shoeisha Co., Ltd.
 */

#pragma once
#include <string>
#include <vector>
#include <memory>

namespace MeCab
{
class Model;
}

namespace sakuin
{
class MeCabCtrl
{
public:
    MeCabCtrl();

    ~MeCabCtrl();

    bool loadDic(const std::wstring& systemDicPath, const std::vector<std::wstring>& userDicFiles);
    bool loadDic(const std::wstring& systemDicPath);

    std::wstring calcYomi(const std::wstring& word)const;

    static std::wstring getModelVer();
    static std::wstring getTaggerVer();

private:

    std::shared_ptr<MeCab::Model> model_;
};
}
