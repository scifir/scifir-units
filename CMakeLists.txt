cmake_minimum_required(VERSION 3.8.2)

include_directories(C:/Programas/MSYS2/mingw64/include .)
link_directories(C:/Programas/MSYS2/mingw64/lib)

set(CMAKE_CXX_COMPILER C:/Programas/MSYS2/mingw64/bin/g++.exe)

set(TARGET_LOCAL_H
chemistry.hpp
meca_numbers.hpp
spatial_math.hpp
units.hpp)

set(TARGET_H
biology
chemistry
informatics
math
physics)

file(GLOB_RECURSE TARGET_SRC biology/*.cpp chemistry/*.cpp informatics/*.cpp math/*.cpp physics/*.cpp)

project(magickscience)

add_library(magickscience ${TARGET_SRC})
target_link_libraries(magickscience boost_locale-mt boost_system-mt boost_thread-mt iconv)

install(TARGETS magickscience ARCHIVE DESTINATION lib)
install(FILES ${TARGET_LOCAL_H} DESTINATION include/magickscience)
install(DIRECTORY ${TARGET_H} DESTINATION include/magickscience
	FILES_MATCHING PATTERN "*.hpp")
