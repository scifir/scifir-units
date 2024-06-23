#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../util/types.hpp"

#include <iostream>

using namespace std;
using namespace scifir;

TEST_CASE("types","Complete test of types functions")
{
	SECTION("display_float()")
	{
		REQUIRE (bool(display_float(1.003f) == "1"));
		REQUIRE (bool(display_float(1.003f,3) == "1.003"));
		REQUIRE (bool(display_float(1.00f) == "1"));
		REQUIRE (bool(display_float(15.0f) == "15"));
	}
}