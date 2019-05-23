cmake_minimum_required(VERSION 3.7.1)

include_directories(../../ "${CMAKE_INSTALL_PREFIX}/include")
link_directories("${CMAKE_INSTALL_PREFIX}/lib")

#set(CMAKE_CXX_COMPILER C:/Programas/MSYS2/mingw64/bin/g++.exe)

set(TARGET_LOCAL_H
meca_numbers.hpp)

set(TARGET_H
coordinates
coordinates/light
fields
meca_number
predefined_units
special_units
topology
units
util)

file(GLOB_RECURSE TARGET_SRC coordinates/*.cpp coordinates/light/*.cpp fields/*.cpp meca_number/*.cpp predefined_units/*.cpp special_units/*.cpp topology/*.cpp units/*.cpp util/*.cpp)

project(msci_units)

add_library(msci_units ${TARGET_SRC})
target_link_libraries(msci_units boost_locale-mt boost_system-mt boost_thread-mt iconv)

install(TARGETS msci_units ARCHIVE DESTINATION lib)
install(FILES units.hpp DESTINATION include/msci)
install(FILES ${TARGET_LOCAL_H} DESTINATION include/msci/units)
install(DIRECTORY ${TARGET_H} DESTINATION include/msci/units
	FILES_MATCHING PATTERN "*.hpp")
