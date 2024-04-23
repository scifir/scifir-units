#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "../../units.hpp"

using namespace std;

TEST_CASE("class coordinates_2d","Complete test of coordinates_2d")
{
	SECTION("Constructors of coordinates_2d classes")
	{
		coordinates_2d<> a;
		REQUIRE (bool(to_string(a) == "(0 m,0 m)"));
		coordinates_2d<> a2(5_m,5_m);
		coordinates_2d<> a3(a2);
		REQUIRE (bool(to_string(a3) == "(5 m,5 m)"));
		coordinates_2d<> a4(5_m,5_m);
		coordinates_2d<> a5(move(a4));
		REQUIRE (bool(to_string(a3) == "(5 m,5 m)"));
		coordinates_2d<> b(100_m,10_m);
		REQUIRE (bool(to_string(b) == "(100 m,10 m)"));
		coordinates_2d<> b2(100_m,angle(90));
		cout << "here: " << to_string(b2) << endl;
		REQUIRE (bool(to_string(b2) == "(0.0 m,100 m)"));
		point_2d<> c2(100_m,1_m);
		coordinates_2d<> c(c2);
		REQUIRE (bool(to_string(c) == "(100 m,1 m)"));
		coordinates_2d<> d("(1 m,5 m)");
		REQUIRE (bool(to_string(d) == "(1 m,5 m)"));
		coordinates_2d<> e("1 m,5 m");
		REQUIRE (bool(to_string(e) == "(1 m,5 m)"));
	}

	SECTION("Operations of coordinates_2d classes")
	{
		
	}

	SECTION("Display of coordinates_2d classes")
	{
		
	}
}
