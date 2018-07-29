#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"
#include "units.hpp"

using namespace std;

TEST_CASE("class vector unit","Test of vector units")
{
	auto_vector a("100 g",20,50);
	ostringstream a_out;
	a_out << a;
	REQUIRE (a_out.str() == "100 g 20\u03B8 50\u03A6");
}
