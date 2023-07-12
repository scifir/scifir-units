#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"
#include "units.hpp"

using namespace std;

TEST_CASE("class vector_unit_nd","Complete test of vector_unit_nd")
{
	SECTION("Initialization of vector_unit_nd classes")
	{
		vector_unit_nd a("100 g",{20,50});
		ostringstream a_out;
		a_out << a;
		REQUIRE (bool(a_out.str() == "100 g 20\u00B0 50\u00B0"));
		vector_unit_nd b("100 g",{angle(35),angle(54)});
		REQUIRE (bool(to_string(b) == "100 g 35\u00B0 54\u00B0"));
	}
}

