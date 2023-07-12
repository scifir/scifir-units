#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"
#include "units.hpp"

using namespace std;

TEST_CASE("class vector_unit_3d","Complete test of vector_unit_3d")
{
	SECTION("Initialization of vector_unit_3d classes")
	{
		vector_unit_3d a("100 g",20,50);
		ostringstream a_out;
		a_out << a;
		REQUIRE (bool(a_out.str() == "100 g 20\u03B8 50\u03A6"));
		vector_unit_3d b("100 g",angle(35),angle(54));
		REQUIRE (bool(to_string(b) == "100 g 35\u03B8 54\u03A6"));
	}
}
