#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
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

	SECTION("Operations of vector_unit_2d classes")
	{
		vector_unit_2d a = vector_unit_2d(100,"m",20);
		vector_unit_2d b = vector_unit_2d(50,"m",40);
		a += b;
		cout << "a: " << a << endl;
		vector_unit_2d c = vector_unit_2d(100,"m",20);
		vector_unit_2d d = vector_unit_2d(50,"m",40);
		c -= d;
		cout << "c: " << d << endl;
		cout << "a + b: " << (a + b) << endl;
		cout << "a - b: " << (a - b) << endl;
		scalar_unit e = scalar_unit("100 m");
		cout << "a * b: " << (a * e) << endl;
		cout << "a / b: " << (a / e) << endl;
		//cout << (a ^ (100_m / 50_m)) << endl;
		vector_unit_2d f = vector_unit_2d(100,"m",10);
		REQUIRE(bool(to_string(f + 50) == "1.50 hm 10\u03B8"));
		REQUIRE(bool(to_string(f - 50) == "5 dam 10\u03B8"));
		REQUIRE(bool(to_string(f * 2) == "2 hm 10\u03B8"));
		REQUIRE(bool(to_string(f / 4) == "2.50 dam 10\u03B8"));
		REQUIRE(bool(to_string(f ^ 2) == "10000 m2 10\u03B8"));
		REQUIRE(bool(to_string(50 + f) == "1.50 hm 10\u03B8"));
		REQUIRE(bool(to_string(150 - f) == "5 dam 10\u03B8"));
		REQUIRE(bool(to_string(2 * f) == "2 hm 10\u03B8"));
		REQUIRE(bool(to_string(200 / f) == "2 1/m 10\u03B8"));
		vector_unit_2d g = vector_unit_2d(100,"m",10);
		g += 10;
		REQUIRE(bool(to_string(g) == "1.10 hm 10\u03B8"));
		vector_unit_2d h = vector_unit_2d(100,"m",10);
		h -= 10;
		REQUIRE(bool(to_string(h) == "9 dam 10\u03B8"));
		vector_unit_2d i = vector_unit_2d(100,"m",10);
		i *= 2;
		REQUIRE(bool(to_string(i) == "2 hm 10\u03B8"));
		vector_unit_2d j = vector_unit_2d(100,"m",10);
		j /= 2;
		REQUIRE(bool(to_string(j) == "5 dam 10\u03B8"));
		REQUIRE(bool(to_string(i.x_projection()) == "1.96 hm"));
		REQUIRE(bool(to_string(i.y_projection()) == "3.47 dam"));
		vector_unit_2d k = vector_unit_2d(100,"m",10);
		k.invert();
		REQUIRE(bool(to_string(k) == "1 hm 190\u03B8"));
	}

	SECTION("Display of vector_unit_2d classes")
	{
		vector_unit_2d a = vector_unit_2d(1,"N",20);
		REQUIRE (bool(a.vectorial_display() == "1 N 20\u03B8"));
		REQUIRE (bool(a.vectorial_derived_display() == "1 kg*m/s2 20\u03B8"));
		REQUIRE (bool(a.vectorial_custom_display("g*m/s2") == "1000 g*m/s2 20\u03B8"));
	}
}

