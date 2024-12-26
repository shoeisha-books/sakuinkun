#ifdef WIN32

#include <Windows.h>
constexpr UINT DEFAULT = 0;

struct CodePointUTF8
{
    
    static UINT old_codepoint;
    CodePointUTF8() noexcept
    {
        auto codepoint = GetConsoleOutputCP();
        if (codepoint != DEFAULT && codepoint != CP_UTF8)
        {
            old_codepoint = codepoint;
            SetConsoleOutputCP(CP_UTF8);
        }
    }

    ~CodePointUTF8() noexcept
    {
        restoreCodePoint();
    }

    static void restoreCodePoint() noexcept
    {
        auto codepoint = old_codepoint;
        if (codepoint != DEFAULT && codepoint != CP_UTF8)
        {
            SetConsoleOutputCP(codepoint);
            old_codepoint = DEFAULT;
        }
    }
} codepoint;


UINT CodePointUTF8::old_codepoint = DEFAULT;

#endif