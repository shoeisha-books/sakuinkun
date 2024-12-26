#pragma once

// 参照タイプ
enum class ReferenceType
{
    Nombre = 0,     // 通常のノンブル
    Range,          // 範囲
    See,            // 「を見よ」（→）
    SeeAlso,        // 「をも見よ」（⇒）
    Manual,         // 手動設定
    Invalid = -1    // 不正
};

extern const wchar_t* RangeMark;
extern const wchar_t* SeeMark;
extern const wchar_t* SeeAlsoMark;
