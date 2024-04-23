#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../coordinates/coordinates_2dr.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class coordinates_2dr","Complete test of coordinates_2dr")
{
	SECTION("Constructors of coordinates_2dr classes")
	{
		coordinates_2dr<> a;
		cout << "a coordinates 2dr: " << to_string(a) << endl;
		REQUIRE (bool(to_string(a) == "(0 m,0 m;0\u00B0)"));
		coordinates_2dr<> a2(5_m,5_m,angle(0));
		coordinates_2dr<> a3(a2);
		REQUIRE (bool(to_string(a3) == "(5 m,5 m;0\u00B0)"));
		coordinates_2dr<> a4(5_m,5_m,angle(0));
		coordinates_2dr<> a5(move(a4));
		REQUIRE (bool(to_string(a3) == "(5 m,5 m;0\u00B0)"));
		coordinates_2dr<> b(100_m,10_m,angle(0));
		REQUIRE (bool(to_string(b) == "(100 m,10 m;0\u00B0)"));
		coordinates_2dr<> b2(100_m,angle(90),angle(0));
		REQUIRE (bool(to_string(b2) == "(0.0 m,100 m;0\u00B0)"));
		point_2d<> c2(100_m,1_m);
		coordinates_2dr<> c(c2,angle(0));
		REQUIRE (bool(to_string(c) == "(100 m,1 m;0\u00B0)"));
		coordinates_2d<> c3(100_m,1_m);
		coordinates_2dr<> c4(c3,angle(0));
		REQUIRE (bool(to_string(c) == "(100 m,1 m;0\u00B0)"));
		coordinates_2dr<> d("(1 m,5 m;0\u00B0)");
		REQUIRE (bool(to_string(d) == "(1 m,5 m;0\u00B0)"));
		coordinates_2dr<> e("1 m,5 m;0\u00B0");
		REQUIRE (bool(to_string(e) == "(1 m,5 m;0\u00B0)"));
	}

	SECTION("Operations of coordinates_2dr classes")
	{
		
	}

	SECTION("Display of coordinates_2dr classes")
	{
		
	}
}

