#include "sakuinkunpp/SakuinKun.hpp"
int main(int argc, char* argv[])
{
    auto helpMessage =
R"(さくいんくん
cmd: sakuin-clipp )";
    // コンソールアプリもそのうち作る
    sakuin::SakuinKun::getInstance().initialize();
    return 0;
}
