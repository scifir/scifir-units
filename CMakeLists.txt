cmake_minimum_required(VERSION 3.7.1)

#set(CMAKE_CXX_COMPILER clang++-13)

include_directories(.)
link_directories("${CMAKE_INSTALL_PREFIX}/lib")

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
target_link_libraries(msci_units boost_locale boost_system icuuc)

add_executable(test_sizeof tests/test_sizeof.cpp)
target_link_libraries(test_sizeof msci_units boost_locale boost_system icuuc)

#add_executable(test_units tests/test_units.cpp)
#target_link_libraries(test_units msci_units boost_locale boost_system)

install(TARGETS msci_units ARCHIVE DESTINATION lib)
install(FILES units.hpp DESTINATION include/msci)
install(FILES ${TARGET_LOCAL_H} DESTINATION include/msci/units)
install(DIRECTORY ${TARGET_H} DESTINATION include/msci/units
	FILES_MATCHING PATTERN "*.hpp")
