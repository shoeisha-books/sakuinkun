/**
 * @file MeCabCtrl.cpp
 * @brief MeCabコントローラー
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 * Copyright (C) 2024 Shoeisha Co., Ltd.
 */

#include "MeCabCtrl.h"
#include <sstream>
#include <iostream>

#include <mecab/mecab.h>
#include <boost/locale.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/nowide/convert.hpp>

using namespace sakuin;

namespace
{
std::wstring mergeAllUserDicText(const std::vector<std::wstring>& userDicFiles)
{
    return L"";
}
}

MeCabCtrl::MeCabCtrl()
{

}

MeCabCtrl::~MeCabCtrl()
{

}

bool MeCabCtrl::loadDic(const std::wstring& systemDicPath)
{
    return loadDic(systemDicPath, std::vector<std::wstring>());
}

bool MeCabCtrl::loadDic(const std::wstring& systemDicPath, const std::vector<std::wstring>& userDicFiles)
{
    model_.reset();
    auto userDicText = mergeAllUserDicText(userDicFiles);
    
    std::stringstream ss;
    ss << "-r rc/mecabrc -d "
        << "dic"
        //       << " --node-format=%pS%f[6] --unk-format=%M --eos-format= ";
        << " --node-format=%pS%f[7] --unk-format=%M --eos-format= ";

    auto arg = ss.str();

    model_ = std::shared_ptr<MeCab::Model>(
        MeCab::createModel(arg.c_str())
        );

    if (!model_)
    {
        std::cout << MeCab::getLastError() << std::endl;
        model_.reset();
    }

    // @TODO 各種エラー処理
    
    return true;
}

std::wstring MeCabCtrl::calcYomi(const std::wstring& word)const
{
    std::wstring ret;
    if (model_)
    {
        auto lattice = std::shared_ptr<MeCab::Lattice>(model_->createLattice());
        std::string uniWord = boost::nowide::narrow(word);
        lattice->set_sentence(uniWord.c_str());
        auto tagger = std::shared_ptr<MeCab::Tagger>(model_->createTagger());
        auto parseres = tagger->parse(lattice.get());
        ret = boost::nowide::widen(lattice->toString());

        //std::cout << boost::nowide::narrow(ret) << std::endl;
    }
    return ret;
}

std::wstring MeCabCtrl::getModelVer()
{
    // @TODO 直値
    return L"0.996";
}

std::wstring MeCabCtrl::getTaggerVer()
{
    // @TODO 直値
    return L"0.996";
}
