#pragma once
#include <string>

// 索引ヘッダ
struct IndexDescData;

namespace sakuin
{
class IndexDesc
{
public:

    IndexDesc(int offset, int romanPageNum, bool romanCap, const std::wstring& repeat);

    bool getData(IndexDescData& data)const;

    int getOffset()const;

    int getRomanPageNum()const;

    bool isRomanCap()const;

    std::wstring getRepeat()const;

private:
    int offset_ = 0;
    int romanPageNum_ = 0;
    bool romanCap_ = true;
    std::wstring repeat_ = L"";
};
}