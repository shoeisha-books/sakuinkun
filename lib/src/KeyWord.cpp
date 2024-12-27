/**
 * @file KeyWord.cpp
 * @brief キーワードクラス
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 * Copyright (C) 2024 Shoeisha Co., Ltd.
 */

#include "sakuinkunpp/KeyWord.hpp"
#include "sakuin_def.h"
#include <boost/nowide/convert.hpp>
#include <stdexcept>

using namespace sakuin;
KeyWord::KeyWord(const std::wstring& word, const std::wstring& yomi)
    : word_(word), yomi_(yomi)
{

}

bool KeyWord::valid()const
{
    return !word_.empty();
}

std::wstring KeyWord::getWord()const
{
    return word_;
}

std::wstring KeyWord::getYomi()const
{
    return yomi_;
}

bool KeyWord::getData(KeyWordData& data)const
{
    auto word = word_;
    auto yomi = yomi_;
    if (word.size() >= data.word_len - 1)
    {
        throw std::runtime_error("Too Large Word: " + boost::nowide::narrow(word));
    }
    if (yomi.size() >= data.yomi_len - 1)
    {
        throw std::runtime_error("Too Large Yomi: " + boost::nowide::narrow(yomi));
    }

    std::wcsncpy(data.word, word.c_str(), word.length());
    std::wcsncpy(data.yomi, yomi.c_str(), yomi.length());

    data.word[word.length()] = L'\0';
    data.yomi[yomi.length()] = L'\0';
    return true;
}

std::strong_ordering KeyWord::operator<=>(const KeyWord& that)const
{
    auto comp = yomi_ <=> that.yomi_;
    return comp;
}
