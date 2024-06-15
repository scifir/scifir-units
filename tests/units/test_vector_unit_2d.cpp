#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../units/vector_unit_2d.hpp"
#include "../../units/unit_basic.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class vector_unit_2d","Complete test of vector_unit_2d")
{
	SECTION("Constructors of vector_unit_2d classes")
	{
		vector_unit_2d a;
		REQUIRE (bool(to_string(a) == "0 [empty] 0\u03B8"));
		vector_unit_2d b = vector_unit_2d("100 g",50);
		vector_unit_2d c = vector_unit_2d(b);
		REQUIRE (bool(to_string(c) == "100 g 50\u03B8"));
		vector_unit_2d b2 = vector_unit_2d("100 g",50);
		vector_unit_2d c2 = vector_unit_2d(std::move(b2));
		REQUIRE (bool(to_string(c2) == "100 g 50\u03B8"));
		vector_unit_2d d = vector_unit_2d(50.0f,"m",20.0f);
		REQUIRE (bool(to_string(d) == "50 m 20\u03B8"));
		vector_unit_2d e = vector_unit_2d(50.0f,"m",angle(20.0f));
		REQUIRE (bool(to_string(e) == "50 m 20\u03B8"));
		vector_unit_2d d2 = vector_unit_2d(50.0,"m",20.0f);
		REQUIRE (bool(to_string(d2) == "50 m 20\u03B8"));
		vector_unit_2d e2 = vector_unit_2d(50.0,"m",angle(20.0f));
		REQUIRE (bool(to_string(e2) == "50 m 20\u03B8"));
		vector_unit_2d d3 = vector_unit_2d((long double)50.0,"m",20.0f);
		REQUIRE (bool(to_string(d3) == "50 m 20\u03B8"));
		vector_unit_2d e3 = vector_unit_2d((long double)50.0,"m",angle(20.0f));
		REQUIRE (bool(to_string(e3) == "50 m 20\u03B8"));
		vector_unit_2d f = vector_unit_2d(50.0f,{dimension("m",dimension::POSITIVE)},20);
		REQUIRE (bool(to_string(f) == "50 m 20\u03B8"));
		vector_unit_2d g = vector_unit_2d(50.0f,{dimension("m",dimension::POSITIVE)},angle(20.0f));
		REQUIRE (bool(to_string(g) == "50 m 20\u03B8"));
		vector_unit_2d f2 = vector_unit_2d(50.0,{dimension("m",dimension::POSITIVE)},20);
		REQUIRE (bool(to_string(f2) == "50 m 20\u03B8"));
		vector_unit_2d g2 = vector_unit_2d(50.0,{dimension("m",dimension::POSITIVE)},angle(20.0f));
		REQUIRE (bool(to_string(g2) == "50 m 20\u03B8"));
		vector_unit_2d f3 = vector_unit_2d((long double)50.0,{dimension("m",dimension::POSITIVE)},20);
		REQUIRE (bool(to_string(f3) == "50 m 20\u03B8"));
		vector_unit_2d g3 = vector_unit_2d((long double)50.0,{dimension("m",dimension::POSITIVE)},angle(20.0f));
		REQUIRE (bool(to_string(g3) == "50 m 20\u03B8"));
		scalar_unit h2 = scalar_unit("50 g");
		vector_unit_2d h = vector_unit_2d(h2,20);
		REQUIRE (bool(to_string(h) == "50 g 20\u03B8"));
		vector_unit_2d i = vector_unit_2d(h2,angle(20.0f));
		REQUIRE (bool(to_string(i) == "50 g 20\u03B8"));
		vector_unit_2d j("100 g",24);
		REQUIRE (bool(to_string(j) == "100 g 24\u03B8"));
		vector_unit_2d k("100 g",angle(24.0f));
		REQUIRE (bool(to_string(k) == "100 g 24\u03B8"));
		vector_unit_2d l("100 g 20");
		REQUIRE (bool(to_string(l) == "100 g 20\u03B8"));
		vector_unit_2d m("100 g 20º");
		REQUIRE (bool(to_string(m) == "100 g 20\u03B8"));
		vector_unit_2d n = vector_unit_2d::cartesian_2d("m",1,1);
		REQUIRE (bool(to_string(n) == "1.41 m 45\u03B8"));
	}

	SECTION("Assignments of vector_unit_2d classes")
	{
		vector_unit_2d a("10 N",angle(10.0f));
		vector_unit_2d b("20 N",angle(20.0f));
		a = b;
		REQUIRE (bool(to_string(a) == "20 N 20\u03B8"));
		vector_unit_2d c("10 N",angle(10.0f));
		vector_unit_2d d("30 N",angle(15.0f));
		c = std::move(d);
		REQUIRE (bool(to_string(c) == "30 N 15\u03B8"));
		vector_unit_2d e("10 N",angle(10.0f));
		scalar_unit e2 = scalar_unit("5 N");
		e = e2;
		REQUIRE (bool(to_string(e) == "5 N 10\u03B8"));
		vector_unit_2d e3("10 N",angle(10.0f));
		e3 = scalar_unit("5 N");
		REQUIRE (bool(to_string(e3) == "5 N 10\u03B8"));
		vector_unit_2d f("10 N",angle(10.0f));
		f = std::move(scalar_unit("5 N"));
		REQUIRE (bool(to_string(f) == "5 N 10\u03B8"));
	}

	SECTION("point_to() function of vector_unit_2d classes")
	{
		vector_unit_2d a("10 N",20.0f);
		a.point_to(direction::LEFT);
		REQUIRE (bool(a.theta.get_value() == 180.0f));
		a.point_to(direction::RIGHT);
		REQUIRE (bool(a.theta.get_value() == 0.0f));
		a.point_to(direction::TOP);
		REQUIRE (bool(a.theta.get_value() == 90.0f));
		a.point_to(direction::BOTTOM);
		REQUIRE (bool(a.theta.get_value() == 270.0f));
		a.point_to(direction::LEFT_TOP);
		REQUIRE (bool(a.theta.get_value() == 135.0f));
		a.point_to(direction::RIGHT_TOP);
		REQUIRE (bool(a.theta.get_value() == 45.0f));
		a.point_to(direction::RIGHT_BOTTOM);
		REQUIRE (bool(a.theta.get_value() == 315.0f));
		a.point_to(direction::LEFT_BOTTOM);
		REQUIRE (bool(a.theta.get_value() == 225.0f));
	}

	SECTION("Operations of vector_unit_2d classes with other vector_unit_2d classes")
	{
		vector_unit_2d a = vector_unit_2d(100.0f,"m",20);
		vector_unit_2d b = vector_unit_2d(50.0f,"m",40);
		a += b;
		vector_unit_2d a2 = vector_unit_2d(100.0f,"m",20);
		vector_unit_2d b2 = vector_unit_2d(50.0f,"g",40);
		a2 += b2;
		vector_unit_2d c = vector_unit_2d(100.0f,"m",20);
		vector_unit_2d d = vector_unit_2d(50.0f,"m",40);
		c -= d;
		vector_unit_2d c2 = vector_unit_2d(100.0f,"m",20);
		vector_unit_2d d2 = vector_unit_2d(50.0f,"g",40);
		c2 -= d2;
		vector_unit_2d e = vector_unit_2d(100.0f,"m",20);
		REQUIRE(bool(to_string(e + vector_unit_2d(100.0f,"m",20)) == "200 m 20\u03B8"));
		REQUIRE(bool(to_string(e + vector_unit_2d(100.0f,"g",20)) == "0 [empty] 0\u03B8"));
		vector_unit_2d f = vector_unit_2d(100.0f,"m",20);
		cout << "f -: " << to_string(f - vector_unit_2d(20.0f,"m",20)) << endl;
		REQUIRE(bool(to_string(f - vector_unit_2d(20.0f,"m",20)) == "80 m 20\u03B8"));
		REQUIRE(bool(to_string(f - vector_unit_2d(100.0f,"g",20)) == "0 [empty] 0\u03B8"));
	}

	SECTION("Operations of vector_unit_2d classes with scalar_unit classes")
	{
		vector_unit_2d a = vector_unit_2d(100.0f,"m",10);
		scalar_unit b = scalar_unit("2 m");
		scalar_unit b2 = 2_m/1_m;
		REQUIRE(bool(to_string(a ^ b) == "0 [empty] 0\u03B8"));
		REQUIRE(bool(to_string(a ^ b2) == "10000 m2 10\u03B8"));
		vector_unit_2d c = vector_unit_2d(100.0f,"m",10);
		scalar_unit d = scalar_unit("2 m");
		REQUIRE(bool(to_string(d * c) == "200 m2 10\u03B8"));
		REQUIRE(bool(to_string(c * d) == "200 m2 10\u03B8"));
		vector_unit_2d e = vector_unit_2d(100.0f,"m2",10);
		scalar_unit f = scalar_unit("2 m");
		REQUIRE(bool(to_string(e / f) == "50 m 10\u03B8"));
	}

	SECTION("Operations of vector_unit_2d classes with numbers")
	{
		vector_unit_2d f = vector_unit_2d(100.0f,"m",10);
		REQUIRE(bool(to_string(f + 50) == "150 m 10\u03B8"));
		REQUIRE(bool(to_string(f - 50) == "50 m 10\u03B8"));
		REQUIRE(bool(to_string(f * 2) == "200 m 10\u03B8"));
		REQUIRE(bool(to_string(f / 4) == "25 m 10\u03B8"));
		REQUIRE(bool(to_string(f ^ 2) == "10000 m2 10\u03B8"));
		REQUIRE(bool(to_string(50 + f) == "150 m 10\u03B8"));
		REQUIRE(bool(to_string(150 - f) == "50 m 10\u03B8"));
		REQUIRE(bool(to_string(2 * f) == "200 m 10\u03B8"));
		REQUIRE(bool(to_string(200 / f) == "2 1/m 10\u03B8"));
		vector_unit_2d g = vector_unit_2d(100.0f,"m",10);
		g += 10;
		REQUIRE(bool(to_string(g) == "110 m 10\u03B8"));
		vector_unit_2d h = vector_unit_2d(100.0f,"m",10);
		h -= 10;
		REQUIRE(bool(to_string(h) == "90 m 10\u03B8"));
		vector_unit_2d i = vector_unit_2d(100.0f,"m",10);
		i *= 2;
		REQUIRE(bool(to_string(i) == "200 m 10\u03B8"));
		vector_unit_2d i2 = vector_unit_2d(100.0f,"m",10);
		i2 *= -2;
		REQUIRE(bool(to_string(i2) == "200 m 190\u03B8"));
		vector_unit_2d j = vector_unit_2d(100.0f,"m",10);
		j /= 2;
		REQUIRE(bool(to_string(j) == "50 m 10\u03B8"));
		vector_unit_2d j2 = vector_unit_2d(100.0f,"m",10);
		j2 /= -2;
		REQUIRE(bool(to_string(j2) == "50 m 190\u03B8"));
		REQUIRE(bool(to_string(i.x_projection()) == "196.96 m"));
		REQUIRE(bool(to_string(i.y_projection()) == "34.72 m"));
		vector_unit_2d k = vector_unit_2d(100.0f,"m",10);
		k.invert();
		REQUIRE(bool(to_string(k) == "100 m 190\u03B8"));
	}

	SECTION("Projections of vector_unit_2d classes")
	{
		vector_unit_2d a("2 N",10.0f);
		REQUIRE (bool(a.x_projection().display(2) == "1.96 N"));
		REQUIRE (bool(a.y_projection().display(2) == "0.34 N"));
	}

	SECTION("Invertion of vector_unit_2d classes")
	{
		vector_unit_2d a("2 N",10.0f);
		a.invert();
		REQUIRE (bool(to_string(a) == "2 N 190\u03B8"));
	}

	SECTION("Display of vector_unit_2d classes")
	{
		vector_unit_2d a = vector_unit_2d(1.0f,"N",20);
		REQUIRE (bool(a.vectorial_display() == "1 N 20\u03B8"));
		REQUIRE (bool(a.vectorial_derived_display() == "1 kg*m/s2 20\u03B8"));
		REQUIRE (bool(a.vectorial_custom_display("g*m/s2") == "1000 g*m/s2 20\u03B8"));
	}

	SECTION("Math functions of vector_unit_2d classes")
	{
		vector_unit_2d a("2 N",10.0f);
		REQUIRE (bool(scifir::norm(a) == scalar_unit("2 N")));
		vector_unit_2d b("4 N2",10.0f);
		REQUIRE (bool(scifir::sqrt(b) == scalar_unit("2 N")));
		vector_unit_2d c("8 N3",10.0f);
		REQUIRE (bool(scifir::sqrt_nth(c,3) == scalar_unit("2 N")));
		vector_unit_2d d("2 N",10.0f);
		vector_unit_2d d2("1 m",10.0f);
		REQUIRE (bool(scifir::dot_product(d,d2).display() == scalar_unit("1.99 kg*m2/s2")));
		vector_unit_2d f("2 N",10.0f);
		vector_unit_2d f2("1 m",20.0f);
		REQUIRE (bool(scifir::angle_between(f,f2).display() == angle("10\u00B0")));
		vector_unit_2d g("2 N",10.0f);
		vector_unit_2d g2("1 m",10.0f);
		REQUIRE (bool(scifir::same_direction(g,g2) == true));
		REQUIRE (bool(scifir::parallel(g,g2) == true));
		vector_unit_2d g3("2 N",10.0f);
		vector_unit_2d g4("1 m",15.0f);
		REQUIRE (bool(scifir::same_direction(g3,g4) == false));
		REQUIRE (bool(scifir::parallel(g3,g4) == false));
		vector_unit_2d h("2 N",0.0f);
		vector_unit_2d h2("1 m",90.0f);
		REQUIRE (bool(scifir::orthogonal(h,h2) == true));
	}

	SECTION("Comparison operators of vector_unit_2d classes")
	{
		vector_unit_2d a("2 N",10.0f);
		vector_unit_2d a2("2 N",10.0f);
		REQUIRE (bool(a == a2));
		vector_unit_2d b("2 N",10.0f);
		vector_unit_2d b2("2 N",20.0f);
		REQUIRE (bool(b != b2));
	}

	SECTION("String operations with vector_unit_2d classes")
	{
		vector_unit_2d a("2 N",10.0f);
		REQUIRE (bool(a == "2 N 10\u03B8"));
		REQUIRE (bool(a != "3 N 10\u03B8"));
		REQUIRE (bool("2 N 10\u03B8" == a));
		REQUIRE (bool("3 N 10\u03B8" != a));
		vector_unit_2d b("2 N",10.0f);
		string b2 = "b: ";
		b2 += b;
		REQUIRE (bool("b: 2 N 10\u03B8"));
		vector_unit_2d c("2 N",10.0f);
		REQUIRE (bool(("b: " + c) == "b: 2 N 10\u03B8"));
		REQUIRE (bool((c + " b") == "2 N 10\u03B8 b"));
	}

	SECTION("Display of vector_unit_2d classes")
	{
		vector_unit_2d a = vector_unit_2d(1.0f,"N",20);
		REQUIRE (bool(a.vectorial_display() == "1 N 20\u03B8"));
		REQUIRE (bool(a.vectorial_derived_display() == "1 kg*m/s2 20\u03B8"));
		REQUIRE (bool(a.vectorial_custom_display("g*m/s2") == "1000 g*m/s2 20\u03B8"));
	}

	SECTION("Stream operators of vector_unit_2d class")
    {
        ostringstream a;
        a << vector_unit_2d("2 N",10.0f);
        REQUIRE (bool(a.str() == "2 N 10\u03B8"));
        stringstream b;
        b << "3 N 10\u03B8";
        vector_unit_2d b2("1 N",angle(0.0f));
        b >> b2;
        REQUIRE (bool(b2 == "3 N 10\u03B8"));
    }
}

