#pragma once

#include "sakuinkun/ReferenceType.h"

#include <string>
#include <compare>

struct ReferenceData;

namespace sakuin
{

class IndexDesc;

// 参照（ノンブルや「を見よ」など）
class Reference
{
public:
    Reference()
        : Reference(ReferenceType::Nombre, 0, L"")
    { }
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Reference(ReferenceType type, int page, const std::wstring& refStr);

    /// <summary>
    /// Cインタフェース用構造体取得
    /// </summary>
    /// <returns></returns>
    bool getData(const IndexDesc& header, ReferenceData& data)const;

    /// <summary>
    /// 参照タイプ取得
    /// </summary>
    /// <returns></returns>
    ReferenceType getType()const;

    /// <summary>
    /// ソート用ページ取得
    /// </summary>
    /// <returns></returns>
    int getPage()const;

    /// <summary>
    /// 参照文字列取得
    /// </summary>
    /// <returns></returns>
    std::wstring getRefStr()const;

    std::strong_ordering operator<=>(const Reference& that)const;

private:
    ReferenceType type_;
    int page_;              // ソート用
    std::wstring refStr_;

    std::wstring calcDispStr(const IndexDesc& desc)const;
};
}
