#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"
#include "units.hpp"

using namespace std;

TEST_CASE("class vector_unit_2d","Complete test of vector_unit_2d")
{
	SECTION("Initialization of vector_unit_2d classes")
	{
		vector_unit_2d a;
		REQUIRE (bool(to_string(a) == "0 [empty] 0\u03B8"));
		vector_unit_2d b = vector_unit_2d("100 g",50);
		vector_unit_2d c = vector_unit_2d(b);
		REQUIRE (bool(to_string(c) == "1 hg 50\u03B8"));
		vector_unit_2d d = vector_unit_2d(50,"m",20);
		REQUIRE (bool(to_string(d) == "5 dam 20\u03B8"));
		vector_unit_2d e = vector_unit_2d(50,"m",angle(20));
		REQUIRE (bool(to_string(e) == "5 dam 20\u03B8"));
		vector_unit_2d f = vector_unit_2d(50,{dimension("m",dimension::POSITIVE)},20);
		REQUIRE (bool(to_string(f) == "5 dam 20\u03B8"));
		vector_unit_2d g = vector_unit_2d(50,{dimension("m",dimension::POSITIVE)},angle(20));
		REQUIRE (bool(to_string(g) == "5 dam 20\u03B8"));
		scalar_unit h2 = scalar_unit("50 g");
		vector_unit_2d h = vector_unit_2d(h2,20);
		REQUIRE (bool(to_string(h) == "5 dag 20\u03B8"));
		vector_unit_2d i = vector_unit_2d(h2,angle(20));
		REQUIRE (bool(to_string(i) == "5 dag 20\u03B8"));
		vector_unit_2d j("100 g",24);
		REQUIRE (bool(to_string(j) == "1 hg 24\u03B8"));
		vector_unit_2d k("100 g",angle(24));
		REQUIRE (bool(to_string(k) == "1 hg 24\u03B8"));
		vector_unit_2d l("100 g 20");
		REQUIRE (bool(to_string(l) == "1 hg 20\u03B8"));
		vector_unit_2d m("100 g 20º");
		REQUIRE (bool(to_string(m) == "1 hg 20\u03B8"));
		vector_unit_2d n = vector_unit_2d::cartesian_2d("m",1,1);
		REQUIRE (bool(to_string(n) == "1.41 m 45\u03B8"));
	}
}

