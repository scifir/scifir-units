#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../coordinates/coordinates_3d.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class coordinates_3d","Complete test of coordinates_3d")
{
	SECTION("Constructors of coordinates_3d classes")
	{
		coordinates_3d<> a;
		REQUIRE (bool(to_string(a) == "(0 m,0 m,0 m)"));
		coordinates_3d<> a2(5_m,5_m,1_m);
		coordinates_3d<> a3(a2);
		REQUIRE (bool(to_string(a3) == "(5 m,5 m,1 m)"));
		coordinates_3d<> a4(5_m,5_m,1_m);
		coordinates_3d<> a5(move(a4));
		REQUIRE (bool(to_string(a3) == "(5 m,5 m,1 m)"));
		coordinates_3d<> b(100_m,10_m,1_m);
		REQUIRE (bool(to_string(b) == "(100 m,10 m,1 m)"));
		coordinates_3d<> b2(100_m,angle(90),1_m);
		REQUIRE (bool(to_string(b2) == "(0 m,100 m,1 m)"));
		coordinates_3d<> b3(100_m,angle(0),angle(0));
		REQUIRE (bool(to_string(b3) == "(0 m,0 m,100 m)"));
		//coordinates_3d<> b4(angle(0),angle(0),10_m);
		//REQUIRE (bool(to_string(b4) == "(0 m,0 m,100 m)"));
		point_3d<> c2(100_m,1_m,2_m);
		coordinates_3d<> c(c2);
		REQUIRE (bool(to_string(c) == "(100 m,1 m,2 m)"));
		coordinates_3d<> d("(1 m,5 m,2 m)");
		REQUIRE (bool(to_string(d) == "(1 m,5 m,2 m)"));
		coordinates_3d<> e("1 m,5 m,2 m");
		REQUIRE (bool(to_string(e) == "(1 m,5 m,2 m)"));
	}

	SECTION("Operations of coordinates_3d classes")
	{
		
	}

	SECTION("Display of coordinates_3d classes")
	{
		
	}
}
