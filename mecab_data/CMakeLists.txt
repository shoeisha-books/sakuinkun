cmake_minimum_required(VERSION 3.18)

# コピー元ファイルに ${CMAKE_CURRENT_SOURCE_DIR} を付けて絶対パスにする
set(DicFiles
    "${CMAKE_CURRENT_SOURCE_DIR}/dic/char.bin"
    "${CMAKE_CURRENT_SOURCE_DIR}/dic/dicrc"
    "${CMAKE_CURRENT_SOURCE_DIR}/dic/matrix.bin"
    "${CMAKE_CURRENT_SOURCE_DIR}/dic/sys.dic"
    "${CMAKE_CURRENT_SOURCE_DIR}/dic/unk.dic"
)

set(RcFiles
    "${CMAKE_CURRENT_SOURCE_DIR}/rc/mecabrc"
)

set(InstallDir "${CMAKE_CURRENT_SOURCE_DIR}/../_install")

add_custom_target(mecab_data ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory "${InstallDir}/$<CONFIG>/dic"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${DicFiles} "${InstallDir}/$<CONFIG>/dic"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${InstallDir}/$<CONFIG>/rc"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${RcFiles} "${InstallDir}/$<CONFIG>/rc"
    SOURCES ${DicFiles} ${RcFiles}
)