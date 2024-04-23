#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "../../coordinates/coordinates_1d.hpp"
#include "../../units/unit_basic.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class coordinates_1d","Complete test of coordinates_1d")
{
	SECTION("Constructors of coordinates_1d classes")
	{
		coordinates_1d<> a;
		cout << "a: " << a << endl;
		REQUIRE (bool(to_string(a) == "(0 m)"));
		coordinates_1d<> a2(5_m);
		coordinates_1d<> a3(a2);
		REQUIRE (bool(to_string(a3) == "(5 m)"));
		coordinates_1d<> a4(5_m);
		coordinates_1d<> a5(move(a4));
		REQUIRE (bool(to_string(a3) == "(5 m)"));
		coordinates_1d<> b(100_m);
		cout << "b: " << to_string(b) << endl;
		REQUIRE (bool(to_string(b) == "(100 m)"));
		point_1d<> c2(100_m);
		coordinates_1d<> c(c2);
		cout << "c: " << to_string(c) << endl;
		REQUIRE (bool(to_string(c) == "(100 m)"));
		coordinates_1d<> d("(1 m)");
		REQUIRE (bool(to_string(d) == "(1 m)"));
		coordinates_1d<> e("1 m");
		REQUIRE (bool(to_string(e) == "(1 m)"));
	}

	SECTION("Operations of coordinates_1d classes")
	{
		
	}

	SECTION("Display of coordinates_1d classes")
	{
		
	}
}
