#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../units/vector_unit_2d.hpp"
#include "../../units/base_units.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class vector_unit_2d")
{
	SECTION("Constructors of vector_unit_2d class")
	{
		vector_unit_2d a;
		CHECK(to_string(a) == "0 [empty] 0θ");
		vector_unit_2d b("100 g",50);
		vector_unit_2d c(b);
		CHECK(to_string(c) == "100 g 50θ");
		vector_unit_2d b2("100 g",50);
		vector_unit_2d c2(std::move(b2));
		CHECK(to_string(c2) == "100 g 50θ");
		vector_unit_2d o(30.0f, dimension::DIMENSION_PASCAL, prefix::KILO, 20.0f);
		CHECK(to_string(o) == "30 kPa 20θ");
		vector_unit_2d o2(30.0, dimension::DIMENSION_PASCAL, prefix::KILO, 20.0f);
		CHECK(to_string(o2) == "30 kPa 20θ");
		vector_unit_2d o3(30.0l, dimension::DIMENSION_PASCAL, prefix::KILO, 20.0f);
		CHECK(to_string(o3) == "30 kPa 20θ");
		vector_unit_2d o4(30, dimension::DIMENSION_PASCAL, prefix::KILO, 20.0f);
		CHECK(to_string(o4) == "30 kPa 20θ");
		vector_unit_2d o5(30.0f, dimension::DIMENSION_PASCAL, prefix::KILO, angle(20.0f));
		CHECK(to_string(o5) == "30 kPa 20θ");
		vector_unit_2d o6(30.0, dimension::DIMENSION_PASCAL, prefix::KILO, angle(20.0f));
		CHECK(to_string(o6) == "30 kPa 20θ");
		vector_unit_2d o7(30.0l, dimension::DIMENSION_PASCAL, prefix::KILO, angle(20.0f));
		CHECK(to_string(o7) == "30 kPa 20θ");
		vector_unit_2d o8(30, dimension::DIMENSION_PASCAL, prefix::KILO, angle(20.0f));
		CHECK(to_string(o8) == "30 kPa 20θ");
		vector_unit_2d d(50.0f,"m",20.0f);
		CHECK(to_string(d) == "50 m 20θ");
		vector_unit_2d e(50.0f,"m",angle(20.0f));
		CHECK(to_string(e) == "50 m 20θ");
		vector_unit_2d d2(50.0,"m",20.0f);
		CHECK(to_string(d2) == "50 m 20θ");
		vector_unit_2d e2(50.0,"m",angle(20.0f));
		CHECK(to_string(e2) == "50 m 20θ");
		vector_unit_2d d3(50.0l,"m",20.0f);
		CHECK(to_string(d3) == "50 m 20θ");
		vector_unit_2d e3(50.0l,"m",angle(20.0f));
		CHECK(to_string(e3) == "50 m 20θ");
		vector_unit_2d d4(50,"m",20.0f);
		CHECK(to_string(d4) == "50 m 20θ");
		vector_unit_2d e4(50,"m",angle(20.0f));
		CHECK(to_string(e4) == "50 m 20θ");
		vector_unit_2d f(50.0f,{dimension("m",dimension::NUMERATOR)},20);
		CHECK(to_string(f) == "50 m 20θ");
		vector_unit_2d g(50.0f,{dimension("m",dimension::NUMERATOR)},angle(20.0f));
		CHECK(to_string(g) == "50 m 20θ");
		vector_unit_2d f2(50.0,{dimension("m",dimension::NUMERATOR)},20);
		CHECK(to_string(f2) == "50 m 20θ");
		vector_unit_2d g2(50.0,{dimension("m",dimension::NUMERATOR)},angle(20.0f));
		CHECK(to_string(g2) == "50 m 20θ");
		vector_unit_2d f3(50.0l,{dimension("m",dimension::NUMERATOR)},20);
		CHECK(to_string(f3) == "50 m 20θ");
		vector_unit_2d g3(50.0l,{dimension("m",dimension::NUMERATOR)},angle(20.0f));
		CHECK(to_string(g3) == "50 m 20θ");
		vector_unit_2d f4(50,{dimension("m",dimension::NUMERATOR)},20);
		CHECK(to_string(f4) == "50 m 20θ");
		vector_unit_2d g4(50,{dimension("m",dimension::NUMERATOR)},angle(20.0f));
		CHECK(to_string(g4) == "50 m 20θ");
		scalar_unit h2 = scalar_unit("50 g");
		vector_unit_2d h(h2,20);
		CHECK(to_string(h) == "50 g 20θ");
		vector_unit_2d i(h2,angle(20.0f));
		CHECK(to_string(i) == "50 g 20θ");
		vector_unit_2d j("100 g",24);
		CHECK(to_string(j) == "100 g 24θ");
		vector_unit_2d k("100 g",angle(24.0f));
		CHECK(to_string(k) == "100 g 24θ");
		vector_unit_2d m("100 g 20°");
		CHECK(to_string(m) == "100 g 20θ");
		vector_unit_2d n = vector_unit_2d::cartesian_2d("m",1,1);
		CHECK(to_string(n) == "1.41 m 45θ");
	}

	SECTION("Assignments of vector_unit_2d class")
	{
		vector_unit_2d a("10 N",angle(10.0f));
		vector_unit_2d b("20 N",angle(20.0f));
		a = b;
		CHECK(to_string(a) == "20 N 20θ");
		vector_unit_2d c("10 N",angle(10.0f));
		vector_unit_2d d("30 N",angle(15.0f));
		c = std::move(d);
		CHECK(to_string(c) == "30 N 15θ");
		vector_unit_2d e("10 N",angle(10.0f));
		scalar_unit e2 = scalar_unit("5 N");
		e = e2;
		CHECK(to_string(e) == "5 N 10θ");
		vector_unit_2d e3("10 N",angle(10.0f));
		e3 = scalar_unit("5 N");
		CHECK(to_string(e3) == "5 N 10θ");
		vector_unit_2d f("10 N",angle(10.0f));
		f = std::move(scalar_unit("5 N"));
		CHECK(to_string(f) == "5 N 10θ");
		vector_unit_2d g("10 N",angle(10.0f));
		g = "8 N 15θ";
		CHECK(to_string(g) == "8 N 15θ");
	}

	SECTION("point_to() function of vector_unit_2d class")
	{
		vector_unit_2d a("10 N",20.0f);
		a.point_to(direction::LEFT);
		CHECK(a.theta.get_value() == 180.0f);
		a.point_to(direction::RIGHT);
		CHECK(a.theta.get_value() == 0.0f);
		a.point_to(direction::TOP);
		CHECK(a.theta.get_value() == 90.0f);
		a.point_to(direction::BOTTOM);
		CHECK(a.theta.get_value() == 270.0f);
		a.point_to(direction::LEFT_TOP);
		CHECK(a.theta.get_value() == 135.0f);
		a.point_to(direction::RIGHT_TOP);
		CHECK(a.theta.get_value() == 45.0f);
		a.point_to(direction::RIGHT_BOTTOM);
		CHECK(a.theta.get_value() == 315.0f);
		a.point_to(direction::LEFT_BOTTOM);
		CHECK(a.theta.get_value() == 225.0f);
	}

	SECTION("Operations of vector_unit_2d class with other vector_unit_2d class")
	{
		vector_unit_2d a(100.0f,"m",20);
		vector_unit_2d b(50.0f,"m",40);
		a += b;
		vector_unit_2d a2(100.0f,"m",20);
		vector_unit_2d b2(50.0f,"g",40);
		a2 += b2;
		vector_unit_2d c(100.0f,"m",20);
		vector_unit_2d d(50.0f,"m",40);
		c -= d;
		vector_unit_2d c2(100.0f,"m",20);
		vector_unit_2d d2(50.0f,"g",40);
		c2 -= d2;
		vector_unit_2d e(100.0f,"m",20);
		CHECK(to_string(e + vector_unit_2d(100.0f,"m",20)) == "200 m 20θ");
		CHECK(to_string(e + vector_unit_2d(100.0f,"g",20)) == "0 [empty] 0θ");
		vector_unit_2d f(100.0f,"m",20);
		CHECK(to_string(f - vector_unit_2d(20.0f,"m",20)) == "80 m 20θ");
		CHECK(to_string(f - vector_unit_2d(100.0f,"g",20)) == "0 [empty] 0θ");
	}

	SECTION("Operations of vector_unit_2d class with scalar_unit class")
	{
		vector_unit_2d a(100.0f,"m",10);
		scalar_unit b = scalar_unit("2 m");
		scalar_unit b2 = 2_m/1_m;
		CHECK(to_string(a ^ b) == "0 [empty] 0θ");
		CHECK(to_string(a ^ b2) == "10000 m2 10θ");
		vector_unit_2d c(100.0f,"m",10);
		scalar_unit d = scalar_unit("2 m");
		CHECK(to_string(d * c) == "200 m2 10θ");
		CHECK(to_string(c * d) == "200 m2 10θ");
		vector_unit_2d e(100.0f,"m2",10);
		scalar_unit f = scalar_unit("2 m");
		CHECK(to_string(e / f) == "50 m 10θ");
	}

	SECTION("Operations of vector_unit_2d class with numbers")
	{
		vector_unit_2d f(100.0f,"m",10);
		CHECK(to_string(f + 50) == "150 m 10θ");
		CHECK(to_string(f - 50) == "50 m 10θ");
		CHECK(to_string(f * 2) == "200 m 10θ");
		CHECK(to_string(f / 4) == "25 m 10θ");
		CHECK(to_string(f ^ 2) == "10000 m2 10θ");
		CHECK(to_string(50 + f) == "150 m 10θ");
		CHECK(to_string(150 - f) == "50 m 10θ");
		CHECK(to_string(2 * f) == "200 m 10θ");
		CHECK(to_string(200 / f) == "2 1/m 10θ");
		vector_unit_2d g(100.0f,"m",10);
		g += 10;
		CHECK(to_string(g) == "110 m 10θ");
		vector_unit_2d h(100.0f,"m",10);
		h -= 10;
		CHECK(to_string(h) == "90 m 10θ");
		vector_unit_2d i(100.0f,"m",10);
		i *= 2;
		CHECK(to_string(i) == "200 m 10θ");
		vector_unit_2d i2(100.0f,"m",10);
		i2 *= -2;
		CHECK(to_string(i2) == "200 m 190θ");
		vector_unit_2d j(100.0f,"m",10);
		j /= 2;
		CHECK(to_string(j) == "50 m 10θ");
		vector_unit_2d j2(100.0f,"m",10);
		j2 /= -2;
		CHECK(to_string(j2) == "50 m 190θ");
		CHECK(to_string(i.x_projection()) == "196.96 m");
		CHECK(to_string(i.y_projection()) == "34.72 m");
		vector_unit_2d k(100.0f,"m",10);
		k.invert();
		CHECK(to_string(k) == "100 m 190θ");
	}

	SECTION("Projections of vector_unit_2d class")
	{
		vector_unit_2d a("2 N",10.0f);
		CHECK(a.x_projection().display(2) == "1.96 N");
		CHECK(a.y_projection().display(2) == "0.34 N");
	}

	SECTION("Invertion of vector_unit_2d class")
	{
		vector_unit_2d a("2 N",10.0f);
		a.invert();
		CHECK(to_string(a) == "2 N 190θ");
	}

	SECTION("Display of vector_unit_2d class")
	{
		vector_unit_2d a(1.0f,"N",20);
		CHECK(a.vectorial_display() == "1 N 20θ");
		CHECK(a.vectorial_base_display() == "1 kg*m/s2 20θ");
		CHECK(a.vectorial_custom_display("g*m/s2") == "1000 g*m/s2 20θ");
	}

	SECTION("Math functions of vector_unit_2d class")
	{
		vector_unit_2d a("2 N",10.0f);
		CHECK(bool(scifir::norm(a) == scalar_unit("2 N")));
		vector_unit_2d b("4 N2",10.0f);
		CHECK(bool(scifir::sqrt(b) == scalar_unit("2 N")));
		vector_unit_2d c("8 N3",10.0f);
		CHECK(bool(scifir::sqrt_nth(c,3) == scalar_unit("2 N")));
		vector_unit_2d d("2 N",10.0f);
		vector_unit_2d d2("1 m",10.0f);
		CHECK(bool(scifir::dot_product(d,d2).display() == scalar_unit("1.99 kg*m2/s2")));
		vector_unit_2d f("2 N",10.0f);
		vector_unit_2d f2("1 m",20.0f);
		CHECK(bool(scifir::angle_between(f,f2).display() == angle("10°")));
		vector_unit_2d g("2 N",10.0f);
		vector_unit_2d g2("1 m",10.0f);
		CHECK(scifir::same_direction(g,g2) == true);
		CHECK(scifir::parallel(g,g2) == true);
		vector_unit_2d g3("2 N",10.0f);
		vector_unit_2d g4("1 m",15.0f);
		CHECK(scifir::same_direction(g3,g4) == false);
		CHECK(scifir::parallel(g3,g4) == false);
		vector_unit_2d h("2 N",0.0f);
		vector_unit_2d h2("1 m",90.0f);
		CHECK(scifir::orthogonal(h,h2) == true);
	}

	SECTION("Comparison operators of vector_unit_2d class")
	{
		vector_unit_2d a("2 N",10.0f);
		vector_unit_2d a2("2 N",10.0f);
		CHECK(bool(a == a2));
		vector_unit_2d b("2 N",10.0f);
		vector_unit_2d b2("2 N",20.0f);
		CHECK(bool(b != b2));
	}

	SECTION("String operations with vector_unit_2d class")
	{
		vector_unit_2d a("2 N",10.0f);
		CHECK(bool(a == "2 N 10θ"));
		CHECK(bool(a != "3 N 10θ"));
		CHECK(bool("2 N 10θ" == a));
		CHECK(bool("3 N 10θ" != a));
		vector_unit_2d b("2 N",10.0f);
		string b2 = "b: ";
		b2 += b;
		CHECK("b: 2 N 10θ");
		vector_unit_2d c("2 N",10.0f);
		CHECK(("b: " + c) == "b: 2 N 10θ");
		CHECK((c + " b") == "2 N 10θ b");
	}

	SECTION("Display of vector_unit_2d class")
	{
		vector_unit_2d a(1.0f,"N",20);
		CHECK(a.vectorial_display() == "1 N 20θ");
		CHECK(a.vectorial_base_display() == "1 kg*m/s2 20θ");
		CHECK(a.vectorial_custom_display("g*m/s2") == "1000 g*m/s2 20θ");
	}

	SECTION("Stream operators of vector_unit_2d class")
    {
        ostringstream a;
        a << vector_unit_2d("2 N",10.0f);
        CHECK(a.str() == "2 N 10θ");
        stringstream b;
        b << "3 N 10θ";
        vector_unit_2d b2("1 N",angle(0.0f));
        b >> b2;
        CHECK(bool(b2 == "3 N 10θ"));
    }
}

