cmake_minimum_required(VERSION 3.13.0)

cmake_policy(SET CMP0048 NEW) # This policy sets the VERSION variable with the project() command

project(scifir-units VERSION 2.0.0 DESCRIPTION "scifir-units is a library of units of measurement, angles, coordinates, fields, and related data, all lightweight, that help in the development of scientific software and scientific machines" HOMEPAGE_URL "https://www.github.com/scifir/scifir-units" LANGUAGES "CXX")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER_VERSION 13.2)

include(extra/FindLinuxDistribution.cmake)

if (DEFINED LINUX_LIBRARY_DIR)
	set(Boost_LIBRARY_DIR ${LINUX_LIBRARY_DIR})
endif()

if (NOT DEFINED LINUX_LIBRARY_DIR AND PLATFORM MATCHES "linux")
	set(CMAKE_LIBRARY_PATH "/usr/lib/*;/usr/lib;/usr/lib64")
endif()

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(BUILD_TESTING "Build test programs" OFF)
option(DEBUG_FLAGS "Add debug flags" OFF)
option(WARNING_FLAGS "Add warning flags" OFF)

if(DEBUG_FLAGS)
	if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Og")
	endif()
	if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
	endif()
	if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /EHsc")
	endif()
endif()

if(WARNING_FLAGS)
	if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
	endif()
	if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
	endif()
	if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall")
	endif()
endif()

if(BUILD_TESTING AND (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage -lgcov")
endif()

if(DEFINED(${INCLUDE_PATH}))
	include_directories(${INCLUDE_PATH})
endif()
if(DEFINED(${LINK_PATH}))
	link_directories(${LINK_PATH})
endif()

set(Boost_NO_BOOST_CMAKE ON)
set(Boost_NO_SYSTEM_PATHS ON)
set(Boost_USE_DEBUG_LIBS        OFF)
set(Boost_USE_RELEASE_LIBS       ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.66.0 REQUIRED COMPONENTS system)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
endif()

if(!Boost_FOUND)
  message("Boost not found, configure Boost_ variables properly and/or install Boost adequately. You can search the documentation of FindBoost, part of CMake, to learn the Boost_ variables to configure. Inside the README.md of scifir-units is also the explanation of how to configure Boost_ variables.")
endif()

# Files to compile

set(TARGET_H
coordinates
fields
meca_number
predefined_units
special_units
topology
units
util)

file(GLOB_RECURSE TARGET_SRC coordinates/*.cpp fields/*.cpp meca_number/*.cpp predefined_units/*.cpp special_units/*.cpp topology/*.cpp units/*.cpp util/*.cpp)

# Project to build

add_library(scifir-units ${TARGET_SRC})
target_link_libraries(scifir-units Boost::system icuuc)

# Define variables for cross-compiling

if(CMAKE_SYSTEM_NAME STREQUAL "Linux" OR CMAKE_GENERATOR STREQUAL "MinGW Makefiles")
  target_compile_definitions(scifir-units PUBLIC "IS_LINUX")
  target_compile_definitions(scifir-units PUBLIC "IS_UNIX")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  target_compile_definitions(scifir-units PUBLIC "IS_MACOS")
  target_compile_definitions(scifir-units PUBLIC "IS_UNIX")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_compile_definitions(scifir-units PUBLIC "IS_WINDOWS")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Android")
  target_compile_definitions(scifir-units PUBLIC "IS_ANDROID")
  target_compile_definitions(scifir-units PUBLIC "IS_UNIX")
endif()

# Install the project

install(TARGETS scifir-units ARCHIVE DESTINATION lib)
install(FILES units.hpp DESTINATION include/scifir)
install(DIRECTORY ${TARGET_H} DESTINATION include/scifir/units
	FILES_MATCHING PATTERN "*.hpp")
install(FILES extra/scifir-units.pc DESTINATION share/pkgconfig)

# Tests, only if BUILD_TESTING is set to ON

if(BUILD_TESTING)

	find_package(Catch2 CONFIG REQUIRED)

	if(!Catch2_FOUND)
		message("Catch2 not found, tests can't be build.")
	endif()

	if(Catch2_FOUND)
		enable_testing()

		add_executable(test_sizeof tests/test_sizeof.cpp)
		target_link_libraries(test_sizeof PRIVATE scifir-units Boost::system icuuc)

		add_executable(test_prefix tests/units/test_prefix.cpp)
		target_link_libraries(test_prefix PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME prefix COMMAND test_prefix)
		set_tests_properties(prefix PROPERTIES LABELS tests)

		add_executable(test_dimension tests/units/test_dimension.cpp)
		target_link_libraries(test_dimension PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME dimension COMMAND test_dimension)
		set_tests_properties(dimension PROPERTIES LABELS tests)

		add_executable(test_scalar_unit tests/units/test_scalar_unit.cpp)
		target_link_libraries(test_scalar_unit PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME scalar_unit COMMAND test_scalar_unit)
		set_tests_properties(scalar_unit PROPERTIES LABELS tests)

		add_executable(test_vector_unit_2d tests/units/test_vector_unit_2d.cpp)
		target_link_libraries(test_vector_unit_2d PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME vector_unit_2d COMMAND test_vector_unit_2d)
		set_tests_properties(vector_unit_2d PROPERTIES LABELS tests)

		add_executable(test_vector_unit_3d tests/units/test_vector_unit_3d.cpp)
		target_link_libraries(test_vector_unit_3d PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME vector_unit_3d COMMAND test_vector_unit_3d)
		set_tests_properties(vector_unit_3d PROPERTIES LABELS tests)

		add_executable(test_vector_unit_nd tests/units/test_vector_unit_nd.cpp)
		target_link_libraries(test_vector_unit_nd PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME vector_unit_nd COMMAND test_vector_unit_nd)
		set_tests_properties(vector_unit_nd PROPERTIES LABELS tests)

		add_executable(test_angle tests/meca_number/test_angle.cpp)
		target_link_libraries(test_angle PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME angle COMMAND test_angle)
		set_tests_properties(angle PROPERTIES LABELS tests)

		add_executable(test_unit_basic tests/units/test_unit_basic.cpp)
		target_link_libraries(test_unit_basic PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME unit_basic COMMAND test_unit_basic)
		set_tests_properties(unit_basic PROPERTIES LABELS tests)

		add_executable(test_unit_abbreviation tests/units/test_unit_abbreviation.cpp)
		target_link_libraries(test_unit_abbreviation PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME unit_abbreviation COMMAND test_unit_abbreviation)
		set_tests_properties(unit_abbreviation PROPERTIES LABELS tests)

		add_executable(test_coordinates_1d tests/coordinates/test_coordinates_1d.cpp)
		target_link_libraries(test_coordinates_1d PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME coordinates_1d COMMAND test_coordinates_1d)
		set_tests_properties(coordinates_1d PROPERTIES LABELS tests)

		add_executable(test_coordinates_2d tests/coordinates/test_coordinates_2d.cpp)
		target_link_libraries(test_coordinates_2d PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME coordinates_2d COMMAND test_coordinates_2d)
		set_tests_properties(coordinates_2d PROPERTIES LABELS tests)

		add_executable(test_coordinates_2dr tests/coordinates/test_coordinates_2dr.cpp)
		target_link_libraries(test_coordinates_2dr PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME coordinates_2dr COMMAND test_coordinates_2dr)
		set_tests_properties(coordinates_2dr PROPERTIES LABELS tests)

		add_executable(test_coordinates_3d tests/coordinates/test_coordinates_3d.cpp)
		target_link_libraries(test_coordinates_3d PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME coordinates_3d COMMAND test_coordinates_3d)
		set_tests_properties(coordinates_3d PROPERTIES LABELS tests)

		add_executable(test_coordinates_3dr tests/coordinates/test_coordinates_3dr.cpp)
		target_link_libraries(test_coordinates_3dr PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME coordinates_3dr COMMAND test_coordinates_3dr)
		set_tests_properties(coordinates_3dr PROPERTIES LABELS tests)

		add_executable(test_coordinates_nd tests/coordinates/test_coordinates_nd.cpp)
		target_link_libraries(test_coordinates_nd PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME coordinates_nd COMMAND test_coordinates_nd)
		set_tests_properties(coordinates_nd PROPERTIES LABELS tests)

		add_executable(test_coordinates_ndr tests/coordinates/test_coordinates_ndr.cpp)
		target_link_libraries(test_coordinates_ndr PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME coordinates_ndr COMMAND test_coordinates_ndr)
		set_tests_properties(coordinates_ndr PROPERTIES LABELS tests)

		add_executable(test_point_2d tests/topology/test_point_2d.cpp)
		target_link_libraries(test_point_2d PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME point_2d COMMAND test_point_2d)
		set_tests_properties(point_2d PROPERTIES LABELS tests)

		add_executable(test_point_3d tests/topology/test_point_3d.cpp)
		target_link_libraries(test_point_3d PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME point_3d COMMAND test_point_3d)
		set_tests_properties(point_3d PROPERTIES LABELS tests)

		add_executable(test_aid tests/special_units/test_aid.cpp)
		target_link_libraries(test_aid PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME aid COMMAND test_aid)
		set_tests_properties(aid PROPERTIES LABELS tests)

		add_executable(test_percentage tests/special_units/test_percentage.cpp)
		target_link_libraries(test_percentage PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME percentage COMMAND test_percentage)
		set_tests_properties(percentage PROPERTIES LABELS tests)

		add_executable(test_pH tests/special_units/test_pH.cpp)
		target_link_libraries(test_pH PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME pH COMMAND test_pH)
		set_tests_properties(pH PROPERTIES LABELS tests)

		add_executable(test_pOH tests/special_units/test_pOH.cpp)
		target_link_libraries(test_pOH PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME pOH COMMAND test_pOH)
		set_tests_properties(pOH PROPERTIES LABELS tests)

		add_executable(test_pixel tests/special_units/test_pixel.cpp)
		target_link_libraries(test_pixel PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME pixel COMMAND test_pixel)
		set_tests_properties(pixel PROPERTIES LABELS tests)

		add_executable(test_size_2d tests/special_units/test_size_2d.cpp)
		target_link_libraries(test_size_2d PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME size_2d COMMAND test_size_2d)
		set_tests_properties(size_2d PROPERTIES LABELS tests)

		add_executable(test_size_3d tests/special_units/test_size_3d.cpp)
		target_link_libraries(test_size_3d PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME size_3d COMMAND test_size_3d)
		set_tests_properties(size_3d PROPERTIES LABELS tests)

		add_executable(test_size_nd tests/special_units/test_size_nd.cpp)
		target_link_libraries(test_size_nd PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME size_nd COMMAND test_size_nd)
		set_tests_properties(size_nd PROPERTIES LABELS tests)

		add_executable(test_zid tests/special_units/test_zid.cpp)
		target_link_libraries(test_zid PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME zid COMMAND test_zid)
		set_tests_properties(zid PROPERTIES LABELS tests)

		add_executable(test_types tests/util/test_types.cpp)
		target_link_libraries(test_types PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME types COMMAND test_types)
		set_tests_properties(types PROPERTIES LABELS tests)

		add_executable(benchmark_units tests/benchmark_units.cpp)
		target_link_libraries(benchmark_units PRIVATE Catch2::Catch2WithMain scifir-units Boost::system icuuc)
		add_test(NAME benchmark_units COMMAND benchmark_units)
		set_tests_properties(benchmark_units PROPERTIES LABELS benchmarks)

		include(CTest)
		include(Catch)
	endif()

endif()

# Package the project

set(CPACK_PACKAGE_NAME "scifir-units")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "scifir-units is a library of units of measurement, angles, coordinates, fields, and related data, all lightweight, that help in the development of scientific software and scientific machines")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_PACKAGE_VENDOR "Scifir")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_PACKAGE_CONTACT "ismael.correa.castro@gmail.com")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://www.github.com/scifir/scifir-units")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libicu-dev (>= 72.1), libboost-system1.74-dev (>= 1.74)")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Ismael Correa Castro <${CPACK_PACKAGE_CONTACT}>")

include(CPack)