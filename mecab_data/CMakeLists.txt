cmake_minimum_required(VERSION 3.18)

set(DicFiles
    dic/char.bin
    dic/dicrc
    dic/matrix.bin
    dic/sys.dic
    dic/unk.dic
)

add_custom_target(mecab_data
    SOURCES ${DicFiles}
)