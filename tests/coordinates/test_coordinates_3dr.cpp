#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "../../units.hpp"

using namespace std;

TEST_CASE("class coordinates_3dr","Complete test of coordinates_3dr")
{
	SECTION("Constructors of coordinates_3dr classes")
	{
		coordinates_3dr<> a;
		REQUIRE (bool(to_string(a) == "(0 m,0 m,0 m;0\u00B0,0\u00B0)"));
		coordinates_3dr<> a2(5_m,5_m,1_m,angle(0),angle(0));
		coordinates_3dr<> a3(a2);
		REQUIRE (bool(to_string(a3) == "(5 m,5 m,1 m;0\u00B0,0\u00B0)"));
		coordinates_3dr<> a4(5_m,5_m,1_m,angle(0),angle(0));
		coordinates_3dr<> a5(move(a4));
		REQUIRE (bool(to_string(a3) == "(5 m,5 m,1 m;0\u00B0,0\u00B0)"));
		coordinates_3dr<> b(100_m,10_m,1_m,angle(0),angle(0));
		REQUIRE (bool(to_string(b) == "(100 m,10 m,1 m;0\u00B0,0\u00B0)"));
		coordinates_3dr<> b2(100_m,angle(90),1_m,angle(0),angle(0));
		REQUIRE (bool(to_string(b2) == "(0.0 m,100 m,1 m;0\u00B0,0\u00B0)"));
		coordinates_3dr<> b3(100_m,angle(0),angle(0),angle(0),angle(0));
		REQUIRE (bool(to_string(b3) == "(0 m,0 m,100 m;0\u00B0,0\u00B0)"));
		//coordinates_3d<> b4(angle(0),angle(0),10_m);
		//REQUIRE (bool(to_string(b4) == "(0 m,0 m,100 m)"));
		point_3d<> c2(100_m,1_m,2_m);
		coordinates_3dr<> c(c2,angle(0),angle(0));
		REQUIRE (bool(to_string(c) == "(100 m,1 m,2 m;0\u00B0,0\u00B0)"));
		coordinates_3d<> c3(100_m,1_m,2_m);
		coordinates_3dr<> c4(c3,angle(0),angle(0));
		REQUIRE (bool(to_string(c) == "(100 m,1 m,2 m;0\u00B0,0\u00B0)"));
		coordinates_3dr<> d("(1 m,5 m,2 m;0\u00B0,0\u00B0)");
		REQUIRE (bool(to_string(d) == "(1 m,5 m,2 m;0\u00B0,0\u00B0)"));
		coordinates_3dr<> e("1 m,5 m,2 m;0\u00B0,0\u00B0");
		REQUIRE (bool(to_string(e) == "(1 m,5 m,2 m;0\u00B0,0\u00B0)"));
	}

	SECTION("Operations of coordinates_3dr classes")
	{
		
	}

	SECTION("Display of coordinates_3dr classes")
	{
		
	}
}
