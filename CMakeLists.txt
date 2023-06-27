cmake_minimum_required(VERSION 3.7.1)

find_package(Catch2 REQUIRED)

#set(CMAKE_CXX_COMPILER clang++-13)

include_directories(.)
link_directories("${CMAKE_INSTALL_PREFIX}/lib")

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(TARGET_LOCAL_H
units.hpp)

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

enable_testing()

project(scifir_units VERSION 2.0.0)

add_library(scifir_units ${TARGET_SRC})
target_link_libraries(scifir_units boost_system icuuc)

add_executable(test_sizeof tests/test_sizeof.cpp)
target_link_libraries(test_sizeof scifir_units boost_system icuuc)

add_executable(test_units tests/test_units.cpp)
target_link_libraries(test_units PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME test_units COMMAND test_units)
set_tests_properties(test_units PROPERTIES LABELS test)

add_executable(benchmark_units tests/benchmark_units.cpp)
target_link_libraries(benchmark_units PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME benchmark_units COMMAND benchmark_units)
set_tests_properties(benchmark_units PROPERTIES LABELS benchmark)

include(CTest)
include(Catch)
catch_discover_tests(test_units)

install(TARGETS scifir_units ARCHIVE DESTINATION lib)
install(FILES units.hpp DESTINATION include/msci)
install(FILES ${TARGET_LOCAL_H} DESTINATION include/msci/units)
install(DIRECTORY ${TARGET_H} DESTINATION include/msci/units
	FILES_MATCHING PATTERN "*.hpp")
	
set(CPACK_PACKAGE_NAME "scifir-units")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "C++ library of units, angles, special units, points and coordinates")
set(CPACK_PACKAGE_VENDOR "Scifir")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_PACKAGE_CONTACT "ismael.correa.castro@gmail.com")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libicu-dev (>= 72.1), libboost-system1.74-dev (>= 1.74)")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Ismael Correa Castro <${CPACK_PACKAGE_CONTACT}>")

include(CPack)
