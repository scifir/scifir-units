#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"
#include "units.hpp"

using namespace std;

TEST_CASE("class vector_unit_3d","Complete test of vector_unit_3d")
{
	SECTION("Initialization of vector_unit_3d classes")
	{
		vector_unit_3d a;
		REQUIRE (bool(to_string(a) == "0 [empty] 0\u03B8 0\u03A6"));
		vector_unit_3d b = vector_unit_3d("100 g",50,20);
		vector_unit_3d c = vector_unit_3d(b);
		REQUIRE (bool(to_string(c) == "100 g 50\u03B8 20\u03A6"));
		vector_unit_3d d = vector_unit_3d(50,"m",20,20);
		REQUIRE (bool(to_string(d) == "50 m 20\u03B8 20\u03A6"));
		vector_unit_3d e = vector_unit_3d(50,"m",angle(20),angle(20));
		REQUIRE (bool(to_string(e) == "50 m 20\u03B8 20\u03A6"));
		vector_unit_3d f = vector_unit_3d(50,{dimension("m",dimension::POSITIVE)},20,20);
		REQUIRE (bool(to_string(f) == "50 m 20\u03B8 20\u03A6"));
		vector_unit_3d g = vector_unit_3d(50,{dimension("m",dimension::POSITIVE)},angle(20),angle(20));
		REQUIRE (bool(to_string(g) == "50 m 20\u03B8 20\u03A6"));
		scalar_unit h2 = scalar_unit("50 g");
		vector_unit_3d h = vector_unit_3d(h2,20,20);
		REQUIRE (bool(to_string(h) == "50 g 20\u03B8 20\u03A6"));
		vector_unit_3d i = vector_unit_3d(h2,angle(20),angle(20));
		REQUIRE (bool(to_string(i) == "50 g 20\u03B8 20\u03A6"));
		vector_unit_3d j("100 g",24,24);
		REQUIRE (bool(to_string(j) == "100 g 24\u03B8 24\u03A6"));
		vector_unit_3d k("100 g",angle(24),angle(24));
		REQUIRE (bool(to_string(k) == "100 g 24\u03B8 24\u03A6"));
		vector_unit_3d l("100 g 20 20");
		REQUIRE (bool(to_string(l) == "100 g 20\u03B8 20\u03A6"));
		vector_unit_3d m("100 g 20º 20º");
		REQUIRE (bool(to_string(m) == "100 g 20\u03B8 20\u03A6"));
		vector_unit_3d n = vector_unit_3d::cartesian_3d("m",1,1,1);
		REQUIRE (bool(to_string(n) == "1.73205 m 45θ 54.7356Φ"));
		vector_unit_3d o = vector_unit_3d::cylindrical("m",1,angle(45),1);
		REQUIRE (bool(to_string(o) == "1.41421 m 45θ 45Φ"));
	}
}
