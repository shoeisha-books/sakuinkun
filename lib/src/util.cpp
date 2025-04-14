/**
 * @file util.cpp
 * @brief 便利関数詰め合わせ
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 * Copyright (C) 2024 Shoeisha Co., Ltd.
 */

#include "util.h"
#include <sstream>
#include <stdexcept>
#include <boost/algorithm/string.hpp>
#include <boost/nowide/convert.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/uuid.hpp>
#include <regex>

namespace sakuin
{
std::wstring convToRoman(int num, bool cap)
{
    if (num >= 4000 || num <= 0)
    {
        throw std::runtime_error("Invalid Num To Convert Into Roman Number");
        return L"";
    }

    std::wstringstream ss;
    while (num > 0)
    {
        if (num >= 1000)
        {
            ss << L"M";
            num -= 1000;
            continue;
        }
        if (num >= 900)
        {
            ss << L"CM";
            num -= 900;
            continue;
        }

        if (num >= 500)
        {
            ss << L"D";
            num -= 500;
            continue;
        }

        if (num >= 400)
        {
            ss << L"CD";
            num -= 400;
            continue;
        }

        if (num >= 100)
        {
            ss << L"C";
            num -= 100;
            continue;
        }

        if (num >= 90)
        {
            ss << L"XC";
            num -= 90;
            continue;
        }

        if (num >= 50)
        {
            ss << L"C";
            num -= 50;
            continue;
        }

        if (num >= 40)
        {
            ss << L"XL";
            num -= 40;
            continue;
        }

        if (num >= 10)
        {
            ss << L"X";
            num -= 10;
            continue;
        }

        if (num >= 9)
        {
            ss << L"IX";
            num -= 9;
            continue;
        }

        if (num >= 5)
        {
            ss << L"V";
            num -= 5;
            continue;
        }

        if (num >= 4)
        {
            ss << L"IV";
            num -= 4;
            continue;
        }

        if (num >= 1)
        {
            ss << L"I";
            num -= 1;
            continue;
        }
    }

    std::wstring ret = ss.str();
    if (!cap)
    {
        boost::to_lower(ret);
    }

    return ret;
}

int convFromRoman(const std::wstring& romanNum)
{
    std::wstring buf = romanNum;
    boost::to_upper(buf);
    
    try {
        // 文字チェック
        if (std::regex_search(buf, std::wregex(L"[^IVXLCDM]")))
        {
            throw std::exception();
        }

        int ret1 = 0;
        // 「I」チェック
        while (buf.size())
        {
            auto lastChar = buf.substr(buf.size() - 1, 1);
            if (lastChar == L"I")
            {
                ret1 += 1;
                buf = buf.substr(0, buf.size() - 1);
            }
            else
            {
                break;
            }
        }

        // 「IV」チェック
        if (buf.substr(buf.size() - 2, 2) == L"IV")
        {
            if (ret1 > 0)
            {
                throw std::exception();
            }
            ret1 = 4;
            buf = buf.substr(0, buf.size() - 2);
        }

        // 「V」チェック
        if (buf.substr(buf.size() - 1, 1) == L"V")
        {
            if (ret1 >= 4)
            {
                throw std::exception();
            }
            ret1 += 5;
            buf = buf.substr(0, buf.size() - 1);
        }

        // 「IX」チェック
        if (buf.substr(buf.size() - 2, 2) == L"IX")
        {
            if (ret1 > 0)
            {
                throw std::exception();
            }
            ret1 = 9;
            buf = buf.substr(0, buf.size() - 2);
        }

        // 文字チェック
        if (std::regex_search(buf, std::wregex(L"[IV]")))
        {
            throw std::exception();
        }

        // 「X」チェック
        int ret10 = 0;
        while (buf.size())
        {
            auto lastChar = buf.substr(buf.size() - 1, 1);
            if (lastChar == L"X")
            {
                ret10 += 1;
                buf = buf.substr(0, buf.size() - 1);
            }
            else
            {
                break;
            }
        }

        // 「XL」チェック
        if (buf.substr(buf.size() - 2, 2) == L"XL")
        {
            if (ret10 > 0)
            {
                throw std::exception();
            }
            ret10 = 4;
            buf = buf.substr(0, buf.size() - 2);
        }

        // 「XC」チェック
        if (buf.substr(buf.size() - 2, 2) == L"XC")
        {
            if (ret10 > 0)
            {
                throw std::exception();
            }
            ret10 += 9;
            buf = buf.substr(0, buf.size() - 1);
        }

        // 文字チェック
        if (std::regex_search(buf, std::wregex(L"[IVXL]")))
        {
            throw std::exception();
        }

        // 「C」チェック
        int ret100 = 0;
        while (buf.size())
        {
            auto lastChar = buf.substr(buf.size() - 1, 1);
            if (lastChar == L"C")
            {
                ret100 += 1;
                buf = buf.substr(0, buf.size() - 1);
            }
            else
            {
                break;
            }
        }

        // 「CD」チェック
        if (buf.substr(buf.size() - 2, 2) == L"CD")
        {
            if (ret100 > 0)
            {
                throw std::exception();
            }
            ret100 = 4;
            buf = buf.substr(0, buf.size() - 2);
        }

        // 「CM」チェック
        if (buf.substr(buf.size() - 2, 2) == L"CM")
        {
            if (ret100 > 0)
            {
                throw std::exception();
            }
            ret100 = 9;
            buf = buf.substr(0, buf.size() - 2);
        }

        // 文字チェック
        if (std::regex_search(buf, std::wregex(L"[IVXLCD]")))
        {
            throw std::exception();
        }

        // 「M」チェック
        int ret1000 = 0;
        while (buf.size())
        {
            auto lastChar = buf.substr(buf.size() - 1, 1);
            if (lastChar == L"M")
            {
                ret1000 += 1;
                buf = buf.substr(0, buf.size() - 1);
            }
            else
            {
                break;
            }
        }
        if (ret1000 > 3)
        {
            throw std::exception();
        }

        return ret1000 * 1000 + ret100 * 100 + ret10 * 10 + ret1;

    }
    catch (...)
    {
        throw std::runtime_error("Invalid Roman Number! " + boost::nowide::narrow(romanNum));
        return -1;
    }
}

std::wstring calcPageStr(int origPage, const IndexDesc& desc)
{
    // オフセット設定
    origPage = origPage + desc.getOffset();

    if (origPage <= desc.getRomanPageNum())
    {
        return convToRoman(origPage, desc.isRomanCap());
    }

    else
    {
        return boost::lexical_cast<std::wstring>(origPage);
    }
}

std::wstring getUUID()
{
    auto uuid = boost::uuids::random_generator()();
    return boost::nowide::widen(boost::lexical_cast<std::string>(uuid));
}

std::wstring getHomeDir()
{
#ifdef _WIN32
    auto homeVal = "USERPROFILE";
#else
    auto homeVal = "HOME";
#endif
    std::string homeDir;
    if (const char* home = std::getenv(homeVal))
    {
        homeDir = home;
    }

    return boost::nowide::widen(homeDir);
}
}
