#pragma once
#include <string>
#include <vector>
#include <memory>

namespace MeCab
{
class Model;
}

namespace sakuin
{
class MeCabCtrl
{
public:
    MeCabCtrl();

    ~MeCabCtrl();

    bool loadDic(const std::wstring& systemDicPath, const std::vector<std::wstring>& userDicFiles);
    bool loadDic(const std::wstring& systemDicPath);

    std::wstring calcYomi(const std::wstring& word)const;

    static std::wstring getModelVer();
    static std::wstring getTaggerVer();

private:

    std::shared_ptr<MeCab::Model> model_;
};
}
