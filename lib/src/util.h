#pragma once
#include <string>
#include "sakuinkunpp/IndexDesc.hpp"

namespace sakuin
{
extern std::wstring convToRoman(int num, bool cap = true);
extern int convFromRoman(const std::wstring& roman);
extern std::wstring getUUID();
extern std::wstring calcPageStr(int origPage, const IndexDesc& header);
}
