cmake_minimum_required(VERSION 3.7.1)

find_package(Catch2 REQUIRED)

set(CMAKE_CXX_STANDARD 17)
if(WITH_GCOV)
	set(CMAKE_CXX_FLAGS "--coverage -fprofile-arcs -ftest-coverage")
	set(CMAKE_EXE_LINKER_FLAGS "--coverage -lgcov")
endif()
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/build)

#set(CMAKE_CXX_COMPILER clang++-13)

if((NOT_DEFINED(${PLATFORM})) OR (${PLATFORM} MATCHES "linux"))
	include_directories(.)
	link_directories("${CMAKE_INSTALL_PREFIX}/lib")
elseif(${PLATFORM} MATCHES "wsl")
	include_directories(. "/usr/include/c++/11" "/usr/include")
	link_directories("/usr/lib/x86_64-linux-gnu")
endif()
if((DEFINED(${INCLUDE_PATH})))
	include_directories(. ${INCLUDE_PATH})
endif()
if((DEFINED(${LINK_PATH})))
	link_directories(${LINK_PATH})
endif()

#set(CMAKE_SYSTEM_NAME Windows)
#set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)

#set(CMAKE_RC_COMPILER windres)
#set(CMAKE_RANLIB ranlib)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)

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
#target_link_libraries(scifir_units boost_system icuuc comdlg32 gdi32)

add_executable(test_sizeof tests/test_sizeof.cpp)
target_link_libraries(test_sizeof PRIVATE scifir_units boost_system icuuc)

add_executable(test_prefixes tests/units/test_prefixes.cpp)
target_link_libraries(test_prefixes PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME test_prefixes COMMAND test_prefixes)
set_tests_properties(test_prefixes PROPERTIES LABELS tests)

add_executable(test_dimensions tests/units/test_dimensions.cpp)
target_link_libraries(test_dimensions PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME test_dimensions COMMAND test_dimensions)
set_tests_properties(test_dimensions PROPERTIES LABELS tests)

add_executable(test_scalar_unit tests/units/test_scalar_unit.cpp)
target_link_libraries(test_scalar_unit PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME test_scalar_unit COMMAND test_scalar_unit)
set_tests_properties(test_scalar_unit PROPERTIES LABELS tests)

add_executable(test_vector_unit_2d tests/units/test_vector_unit_2d.cpp)
target_link_libraries(test_vector_unit_2d PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME test_vector_unit_2d COMMAND test_vector_unit_2d)
set_tests_properties(test_vector_unit_2d PROPERTIES LABELS tests)

add_executable(test_vector_unit_3d tests/units/test_vector_unit_3d.cpp)
target_link_libraries(test_vector_unit_3d PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME test_vector_unit_3d COMMAND test_vector_unit_3d)
set_tests_properties(test_vector_unit_3d PROPERTIES LABELS tests)

add_executable(test_vector_unit_nd tests/units/test_vector_unit_nd.cpp)
target_link_libraries(test_vector_unit_nd PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME test_vector_unit_nd COMMAND test_vector_unit_nd)
set_tests_properties(test_vector_unit_nd PROPERTIES LABELS tests)

add_executable(test_unit_basic tests/units/test_unit_basic.cpp)
target_link_libraries(test_unit_basic PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME test_unit_basic COMMAND test_unit_basic)
set_tests_properties(test_unit_basic PROPERTIES LABELS tests)

add_executable(test_coordinates_1d tests/coordinates/test_coordinates_1d.cpp)
target_link_libraries(test_coordinates_1d PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME test_coordinates_1d COMMAND test_coordinates_1d)
set_tests_properties(test_coordinates_1d PROPERTIES LABELS tests)

add_executable(test_coordinates_2d tests/coordinates/test_coordinates_2d.cpp)
target_link_libraries(test_coordinates_2d PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME test_coordinates_2d COMMAND test_coordinates_2d)
set_tests_properties(test_coordinates_2d PROPERTIES LABELS tests)

add_executable(test_coordinates_2dr tests/coordinates/test_coordinates_2dr.cpp)
target_link_libraries(test_coordinates_2dr PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME test_coordinates_2dr COMMAND test_coordinates_2dr)
set_tests_properties(test_coordinates_2dr PROPERTIES LABELS tests)

add_executable(test_coordinates_3d tests/coordinates/test_coordinates_3d.cpp)
target_link_libraries(test_coordinates_3d PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME test_coordinates_3d COMMAND test_coordinates_3d)
set_tests_properties(test_coordinates_3d PROPERTIES LABELS tests)

add_executable(test_coordinates_3dr tests/coordinates/test_coordinates_3dr.cpp)
target_link_libraries(test_coordinates_3dr PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME test_coordinates_3dr COMMAND test_coordinates_3dr)
set_tests_properties(test_coordinates_3dr PROPERTIES LABELS tests)

add_executable(test_coordinates_nd tests/coordinates/test_coordinates_nd.cpp)
target_link_libraries(test_coordinates_nd PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME test_coordinates_nd COMMAND test_coordinates_nd)
set_tests_properties(test_coordinates_nd PROPERTIES LABELS tests)

add_executable(test_coordinates_ndr tests/coordinates/test_coordinates_ndr.cpp)
target_link_libraries(test_coordinates_ndr PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME test_coordinates_ndr COMMAND test_coordinates_ndr)
set_tests_properties(test_coordinates_ndr PROPERTIES LABELS tests)

add_executable(test_percentage tests/special_units/test_percentage.cpp)
target_link_libraries(test_percentage PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME test_percentage COMMAND test_percentage)
set_tests_properties(test_percentage PROPERTIES LABELS tests)

add_executable(benchmark_units tests/benchmark_units.cpp)
target_link_libraries(benchmark_units PRIVATE Catch2::Catch2 scifir_units boost_system icuuc)
add_test(NAME benchmark_units COMMAND benchmark_units)
set_tests_properties(benchmark_units PROPERTIES LABELS benchmarks)

include(CTest)
include(Catch)
#catch_discover_tests(test_units)

install(TARGETS scifir_units ARCHIVE DESTINATION lib)
install(FILES units.hpp DESTINATION include/scifir)
install(FILES ${TARGET_LOCAL_H} DESTINATION include/scifir/units)
install(DIRECTORY ${TARGET_H} DESTINATION include/scifir/units
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
