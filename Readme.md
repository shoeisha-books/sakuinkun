# さくいんくん

ver 3.0

## これは何？

翔泳社編集部内製の索引生成ツールです。各所で話題にしたところ「使ってみたい」との声をいただきましたので、もともと社内で使っていたものを更改するのにあわせて、OSSとしてリリースすることにしました。

元（Ver 1～2、非公開）はC#アプリであり、NuGetでMeCabやXML、XLSXなどのライブラリを取得していましたが、メンテをサボっているうちに依存ライブラリが動かなくなったので全面的に刷新しました。

## していること

PDFのコメント注釈を解釈し、読みでソートして索引原稿を生成しています。

コメント注釈はxfdfファイルであり、XML形式なので誰でも読めるはずです。読みの推測もMeCab＋ipadicでやっているので、そんなに難しくないはず。

でも、C#⇔C++のバインディング（P/Invoke）にいろいろハマりました。

## 構成

ライブラリ部分はC++で作成しています。利用している外部ライブラリは以下のとおり。

- boost
- libxml2
- xlsxwriter
- picojson
- libmecab

アプリケーションは
- Sakuinkun：GUI（C#）
- sakuin-cli：CUI（兼C++リファレンス実装）

使い方等はそれぞれのアプリケーションによります。

## 参考文献

- 『本の索引の作り方』藤田節子 著、地人書館 刊（2019/10/28）、ISBN978-4-8052-0932-5

## 作者
- Satoshi Yamamoto
