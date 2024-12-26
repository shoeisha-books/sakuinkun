#include "libsakuin.h"
int main()
{
    const char* argv[] =
    {
        "mecab_dict_index",
        "-f",
        "shiftjis",
        "-t",
        "shiftjis",
        "-d",
        "./dic",
        "-o",
        "./outdic"
    };
    constexpr int argc = sizeof(argv) / 8;
   // mecab_dict_index(argc, (char**)argv);

    dummy();
    return 0;
}