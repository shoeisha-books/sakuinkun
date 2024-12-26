#pragma once
#include <string>
#include <compare>

struct KeyWordData;

namespace sakuin
{
// キーワード
class KeyWord
{
public:
    KeyWord()
        : KeyWord(L"", L"")
    { }
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="word"></param>
    /// <param name="yomi"></param>
    KeyWord(const std::wstring& word, const std::wstring& yomi);

    /// <summary>
    /// 有効か
    /// </summary>
    /// <returns></returns>
    bool valid()const;

    /// <summary>
    /// 単語取得
    /// </summary>
    /// <returns>単語</returns>
    std::wstring getWord()const;

    /// <summary>
    /// 読み取得
    /// </summary>
    /// <returns>読み</returns>
    std::wstring getYomi()const;

    /// <summary>
    /// Cインタフェース用構造体取得 
    /// </summary>
    /// <returns></returns>
    bool getData(KeyWordData& data)const;

    std::strong_ordering operator<=>(const KeyWord& that)const;

private:
    std::wstring word_;
    std::wstring yomi_;
};
}
