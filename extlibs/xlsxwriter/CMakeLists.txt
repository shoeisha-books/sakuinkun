cmake_minimum_required(VERSION 3.28)

add_library(xlsxwriter SHARED IMPORTED GLOBAL)
set_target_properties(xlsxwriter PROPERTIES IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/vcpkg_installed/x64-windows/bin/xlsxwriter.dll)
set_target_properties(xlsxwriter PROPERTIES IMPORTED_IMPLIB ${CMAKE_BINARY_DIR}/vcpkg_installed/x64-windows/lib/xlsxwriter.lib)
set_target_properties(xlsxwriter PROPERTIES IMPORTED_INCLUDE_DIRECTORIES ${CMAKE_BINARY_DIR}/vcpkg_installed/x64-windows/include)

