#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"
#include "units.hpp"

using namespace std;

TEST_CASE("class vector_unit_2d","Complete test of vector_unit_2d")
{
	SECTION("Initialization of vector_unit_2d classes")
	{
		vector_unit_2d a("100 g",24);
		ostringstream a_out;
		a_out << a;
		REQUIRE (bool(a_out.str() == "100 g 24\u03B8"));
		vector_unit_2d b("100 g",angle(37));
		REQUIRE (bool(to_string(b) == "100 g 37\u03B8"));
	}
}

