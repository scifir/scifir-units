#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../units/vector_unit_3d.hpp"
#include "../../units/unit_basic.hpp"
#include "../../units/unit_abbreviation.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class vector_unit_3d","Complete test of vector_unit_3d")
{
	SECTION("Constructors of vector_unit_3d classes")
	{
		vector_unit_3d a;
		REQUIRE (bool(to_string(a) == "0 [empty] 0\u03B8 0\u03A6"));
		vector_unit_3d b = vector_unit_3d("100 g",50,20);
		vector_unit_3d c = vector_unit_3d(b);
		REQUIRE (bool(to_string(c) == "100 g 50\u03B8 20\u03A6"));
		vector_unit_3d b2 = vector_unit_3d("100 g",50,20);
		vector_unit_3d c2 = vector_unit_3d(std::move(b2));
		REQUIRE (bool(to_string(c2) == "100 g 50\u03B8 20\u03A6"));
		vector_unit_3d d = vector_unit_3d(50,"m",20,20);
		REQUIRE (bool(to_string(d) == "50 m 20\u03B8 20\u03A6"));
		vector_unit_3d e = vector_unit_3d(50,"m",angle(20.0f),angle(20.0f));
		REQUIRE (bool(to_string(e) == "50 m 20\u03B8 20\u03A6"));
		vector_unit_3d f = vector_unit_3d(50,{dimension("m",dimension::POSITIVE)},20,20);
		REQUIRE (bool(to_string(f) == "50 m 20\u03B8 20\u03A6"));
		vector_unit_3d g = vector_unit_3d(50,{dimension("m",dimension::POSITIVE)},angle(20.0f),angle(20.0f));
		REQUIRE (bool(to_string(g) == "50 m 20\u03B8 20\u03A6"));
		scalar_unit h2 = scalar_unit("50 g");
		vector_unit_3d h = vector_unit_3d(h2,20,20);
		REQUIRE (bool(to_string(h) == "50 g 20\u03B8 20\u03A6"));
		vector_unit_3d i = vector_unit_3d(h2,angle(20.0f),angle(20.0f));
		REQUIRE (bool(to_string(i) == "50 g 20\u03B8 20\u03A6"));
		vector_unit_3d j("100 g",24,24);
		REQUIRE (bool(to_string(j) == "100 g 24\u03B8 24\u03A6"));
		vector_unit_3d k("100 g",angle(24.0f),angle(24.0f));
		REQUIRE (bool(to_string(k) == "100 g 24\u03B8 24\u03A6"));
		vector_unit_3d l("100 g 20 20");
		REQUIRE (bool(to_string(l) == "100 g 20\u03B8 20\u03A6"));
		vector_unit_3d m("100 g 20º 20º");
		REQUIRE (bool(to_string(m) == "100 g 20\u03B8 20\u03A6"));
		vector_unit_3d n = vector_unit_3d::cartesian_3d("m",1,1,1);
		REQUIRE (bool(to_string(n) == "1.73 m 45θ 54.73Φ"));
		vector_unit_3d o = vector_unit_3d::cylindrical("m",1,angle(45.0f),1);
		REQUIRE (bool(to_string(o) == "1.41 m 45θ 45Φ"));
	}

	SECTION("Assignments of vector_unit_3d classes")
	{
		vector_unit_3d a("10 N",angle(10.0f),angle(5.0f));
		vector_unit_3d b("20 N",angle(20.0f),angle(30.0f));
		a = b;
		REQUIRE (bool(to_string(a) == "20 N 20\u03B8 30\u03A6"));
		vector_unit_3d c("5 N",angle(5.0f),angle(15.0f));
		vector_unit_3d d("30 N",angle(15.0f),angle(20.0f));
		c = std::move(d);
		REQUIRE (bool(to_string(c) == "30 N 15\u03B8 20\u03A6"));
		vector_unit_3d e("10 N",angle(10.0f),angle(10.0f));
		scalar_unit e2 = scalar_unit("5 N");
		e = e2;
		REQUIRE (bool(to_string(e) == "5 N 10\u03B8 10\u03A6"));
		vector_unit_3d f("10 N",angle(10.0f),angle(10.0f));
		f = std::move(scalar_unit("5 N"));
		REQUIRE (bool(to_string(f) == "5 N 10\u03B8 10\u03A6"));
	}

	SECTION("point_to() function of vector_unit_3d classes")
	{
		vector_unit_3d a("10 N",20.0f,30.0f);
		a.point_to(direction::LEFT);
		REQUIRE (bool(a.theta.get_value() == 270.0f));
		REQUIRE (bool(a.phi.get_value() == 90.0f));
		a.point_to(direction::RIGHT);
		REQUIRE (bool(a.theta.get_value() == 90.0f));
		REQUIRE (bool(a.phi.get_value() == 90.0f));
		a.point_to(direction::TOP);
		REQUIRE (bool(a.theta.get_value() == 0.0f));
		REQUIRE (bool(a.phi.get_value() == 0.0f));
		a.point_to(direction::BOTTOM);
		REQUIRE (bool(a.theta.get_value() == 0.0f));
		REQUIRE (bool(a.phi.get_value() == 180.0f));
		a.point_to(direction::LEFT_TOP);
		REQUIRE (bool(a.theta.get_value() == 270.0f));
		REQUIRE (bool(a.phi.get_value() == 45.0f));
		a.point_to(direction::RIGHT_TOP);
		REQUIRE (bool(a.theta.get_value() == 90.0f));
		REQUIRE (bool(a.phi.get_value() == 45.0f));
		a.point_to(direction::RIGHT_BOTTOM);
		REQUIRE (bool(a.theta.get_value() == 90.0f));
		REQUIRE (bool(a.phi.get_value() == 135.0f));
		a.point_to(direction::LEFT_BOTTOM);
		REQUIRE (bool(a.theta.get_value() == 270.0f));
		REQUIRE (bool(a.phi.get_value() == 135.0f));
		a.point_to(direction::FRONT);
		REQUIRE (bool(a.theta.get_value() == 0.0f));
		REQUIRE (bool(a.phi.get_value() == 90.0f));
		a.point_to(direction::BACK);
		REQUIRE (bool(a.theta.get_value() == 180.0f));
		REQUIRE (bool(a.phi.get_value() == 90.0f));
		a.point_to(direction::LEFT_FRONT);
		REQUIRE (bool(a.theta.get_value() == 315.0f));
		REQUIRE (bool(a.phi.get_value() == 90.0f));
		a.point_to(direction::RIGHT_FRONT);
		REQUIRE (bool(a.theta.get_value() == 45.0f));
		REQUIRE (bool(a.phi.get_value() == 90.0f));
		a.point_to(direction::TOP_FRONT);
		REQUIRE (bool(a.theta.get_value() == 0.0f));
		REQUIRE (bool(a.phi.get_value() == 45.0f));
		a.point_to(direction::BOTTOM_FRONT);
		REQUIRE (bool(a.theta.get_value() == 0.0f));
		REQUIRE (bool(a.phi.get_value() == 135.0f));
		a.point_to(direction::LEFT_BACK);
		REQUIRE (bool(a.theta.get_value() == 225.0f));
		REQUIRE (bool(a.phi.get_value() == 90.0f));
		a.point_to(direction::RIGHT_BACK);
		REQUIRE (bool(a.theta.get_value() == 135.0f));
		REQUIRE (bool(a.phi.get_value() == 90.0f));
		a.point_to(direction::TOP_BACK);
		REQUIRE (bool(a.theta.get_value() == 180.0f));
		REQUIRE (bool(a.phi.get_value() == 45.0f));
		a.point_to(direction::BOTTOM_BACK);
		REQUIRE (bool(a.theta.get_value() == 180.0f));
		REQUIRE (bool(a.phi.get_value() == 135.0f));
		a.point_to(direction::LEFT_TOP_FRONT);
		REQUIRE (bool(a.theta.get_value() == 315.0f));
		REQUIRE (bool(a.phi.get_value() == 45.0f));
		a.point_to(direction::RIGHT_TOP_FRONT);
		REQUIRE (bool(a.theta.get_value() == 45.0f));
		REQUIRE (bool(a.phi.get_value() == 45.0f));
		a.point_to(direction::LEFT_BOTTOM_FRONT);
		REQUIRE (bool(a.theta.get_value() == 315.0f));
		REQUIRE (bool(a.phi.get_value() == 135.0f));
		a.point_to(direction::RIGHT_BOTTOM_FRONT);
		REQUIRE (bool(a.theta.get_value() == 45.0f));
		REQUIRE (bool(a.phi.get_value() == 135.0f));
		a.point_to(direction::LEFT_TOP_BACK);
		REQUIRE (bool(a.theta.get_value() == 225.0f));
		REQUIRE (bool(a.phi.get_value() == 45.0f));
		a.point_to(direction::RIGHT_TOP_BACK);
		REQUIRE (bool(a.theta.get_value() == 135.0f));
		REQUIRE (bool(a.phi.get_value() == 45.0f));
		a.point_to(direction::LEFT_BOTTOM_BACK);
		REQUIRE (bool(a.theta.get_value() == 225.0f));
		REQUIRE (bool(a.phi.get_value() == 135.0f));
		a.point_to(direction::RIGHT_BOTTOM_BACK);
		REQUIRE (bool(a.theta.get_value() == 135.0f));
		REQUIRE (bool(a.phi.get_value() == 135.0f));
	}

	SECTION("Operators of vector_unit_3d classes with other vector_unit_3d classes")
	{
		vector_unit_3d a("10 N",20.0f,30.0f);
		vector_unit_3d a2("10 N",20.0f,30.0f);
		a += a2;
		REQUIRE (bool(to_string(a) == "19.99 N 20\u03B8 29.99\u03A6"));
		vector_unit_3d a3("10 N",20.0f,30.0f);
		vector_unit_3d a4("10 g",20.0f,30.0f);
		a3 += a4;
		REQUIRE (bool(to_string(a3) == "10 N 20\u03B8 30\u03A6"));
		vector_unit_3d b("10 N",20.0f,30.0f);
		vector_unit_3d b2("5 N",20.0f,30.0f);
		b -= b2;
		REQUIRE (bool(to_string(b) == "4.99 N 20\u03B8 30\u03A6"));
		vector_unit_3d b3("10 N",20.0f,30.0f);
		vector_unit_3d b4("5 g",20.0f,30.0f);
		b3 -= b4;
		REQUIRE (bool(to_string(b3) == "10 N 20\u03B8 30\u03A6"));
		vector_unit_3d c("10 N",20.0f,30.0f);
		vector_unit_3d c2("5 N",20.0f,30.0f);
		REQUIRE (bool(to_string(c + c2) == "14.99 N 20\u03B8 30\u03A6"));
		vector_unit_3d c3("10 N",20.0f,30.0f);
		vector_unit_3d c4("5 g",20.0f,30.0f);
		REQUIRE (bool(to_string(c3 + c4) == "0 [empty] 0\u03B8 0\u03A6"));
		vector_unit_3d d("10 N",20.0f,30.0f);
		vector_unit_3d d2("5 N",20.0f,30.0f);
		REQUIRE (bool(to_string(d - d2) == "4.99 N 20\u03B8 30\u03A6"));
		vector_unit_3d d3("10 N",20.0f,30.0f);
		vector_unit_3d d4("5 g",20.0f,30.0f);
		REQUIRE (bool(to_string(d3 - d4) == "0 [empty] 0\u03B8 0\u03A6"));
	}

	SECTION("Operators of vector_unit_3d classes with scalar_unit classes")
	{
		vector_unit_3d a("10 N",10.0f,10.0f);
		scalar_unit a2("5 g");
		REQUIRE (bool(to_string(a * a2) == "50 g*kg*m/s2 10\u03B8 10\u03A6"));
		vector_unit_3d a3 = (a * a2);
		a3.change_dimensions("N*g");
		REQUIRE (bool(to_string(a3) == "50 N*g 10\u03B8 10\u03A6"));
		REQUIRE (bool(to_string(a2 * a) == "50 g*kg*m/s2 10\u03B8 10\u03A6"));
		vector_unit_3d b("10 N",10.0f,10.0f);
		scalar_unit b2("5 g");
		REQUIRE (bool(to_string(b / b2) == "2000 m/s2 10\u03B8 10\u03A6"));
		vector_unit_3d c("10 N",10.0f,10.0f);
		scalar_unit c2(10_N / 5_N);
		REQUIRE (bool(to_string(c ^ c2) == "100 N2 10\u03B8 10\u03A6"));
		vector_unit_3d c3("10 N",10.0f,10.0f);
		scalar_unit c4(10_N);
		REQUIRE (bool(to_string(c3 ^ c4) == "0 [empty] 0\u03B8 0\u03A6"));
	}

	SECTION("Numeric operators of vector_unit_3d classes")
	{
		vector_unit_3d a("10 N",20.0f,20.0f);
		REQUIRE (bool(to_string(a + 10.0f) == "20 N 20\u03B8 20\u03A6"));
		REQUIRE (bool(to_string(10.0f + a) == "20 N 20\u03B8 20\u03A6"));
		vector_unit_3d b("10 N",20.0f,20.0f);
		REQUIRE (bool(to_string(b - 5.0f) == "5 N 20\u03B8 20\u03A6"));
		REQUIRE (bool(to_string(20.0f - b) == "10 N 20\u03B8 20\u03A6"));
		vector_unit_3d c("10 N",20.0f,20.0f);
		REQUIRE (bool(to_string(c * 2.0f) == "20 N 20\u03B8 20\u03A6"));
		REQUIRE (bool(to_string(2.0f * c) == "20 N 20\u03B8 20\u03A6"));
		vector_unit_3d d("10 N",20.0f,20.0f);
		REQUIRE (bool(to_string(d / 2.0f) == "5 N 20\u03B8 20\u03A6"));
		REQUIRE (bool(to_string(20.0f / d) == "2 1/N 20\u03B8 20\u03A6"));
		vector_unit_3d e("10 N",20.0f,20.0f);
		REQUIRE (bool(to_string(e ^ 2) == "100 N2 20\u03B8 20\u03A6"));
		vector_unit_3d f("10 N",20.0f,20.0f);
		f += 5.0f;
		REQUIRE (bool(to_string(f) == "15 N 20\u03B8 20\u03A6"));
		vector_unit_3d g("10 N",20.0f,20.0f);
		g -= 5.0f;
		REQUIRE (bool(to_string(g) == "5 N 20\u03B8 20\u03A6"));
		vector_unit_3d h("10 N",20.0f,20.0f);
		h *= 2.0f;
		REQUIRE (bool(to_string(h) == "20 N 20\u03B8 20\u03A6"));
		vector_unit_3d i("10 N",20.0f,20.0f);
		i *= -2.0f;
		REQUIRE (bool(to_string(i) == "20 N 200\u03B8 160\u03A6"));
		vector_unit_3d j("10 N",20.0f,20.0f);
		j /= 2.0f;
		REQUIRE (bool(to_string(j) == "5 N 20\u03B8 20\u03A6"));
		vector_unit_3d k("10 N",20.0f,20.0f);
		k /= -2.0f;
		REQUIRE (bool(to_string(k) == "5 N 200\u03B8 160\u03A6"));
	}

	SECTION("Projections of vector_unit_3d classes")
	{
		vector_unit_3d a("2 N",10.0f,10.0f);
		REQUIRE (bool(a.x_projection().display(2) == "0.34 N"));
		REQUIRE (bool(a.y_projection().display(2) == "0.06 N"));
		REQUIRE (bool(a.z_projection().display(2) == "1.96 N"));
	}

	SECTION("Invertion of vector_unit_3d classes")
	{
		vector_unit_3d a("2 N",10.0f,10.0f);
		a.invert();
		REQUIRE (bool(to_string(a) == "2 N 190\u03B8 170\u03A6"));
	}

	SECTION("Display of vector_unit_3d classes")
	{
		vector_unit_3d a = vector_unit_3d(1,"N",20,20);
		REQUIRE (bool(a.vectorial_display() == "1 N 20\u03B8 20\u03A6"));
		REQUIRE (bool(a.vectorial_derived_display() == "1 kg*m/s2 20\u03B8 20\u03A6"));
		REQUIRE (bool(a.vectorial_custom_display("g*m/s2") == "1000 g*m/s2 20\u03B8 20\u03A6"));
	}

	SECTION("Math functions of vector_unit_3d classes")
	{
		vector_unit_3d a("2 N",10.0f,10.0f);
		REQUIRE (bool(scifir::norm(a) == scalar_unit("2 N")));
		vector_unit_3d b("4 N2",10.0f,10.0f);
		REQUIRE (bool(scifir::sqrt(b) == scalar_unit("2 N")));
		vector_unit_3d c("8 N3",10.0f,10.0f);
		REQUIRE (bool(scifir::sqrt_nth(c,3) == scalar_unit("2 N")));
		vector_unit_3d d("2 N",10.0f,10.0f);
		vector_unit_3d d2("1 m",10.0f,10.0f);
		REQUIRE (bool(scifir::dot_product(d,d2).display() == scalar_unit("1.99 kg*m2/s2")));
		vector_unit_3d e("2 N",10.0f,10.0f);
		vector_unit_3d e2("1 m",10.0f,10.0f);
		REQUIRE (bool(scifir::cross_product(e,e2) == vector_unit_3d("0 kg*m2/s2 0\u03B8 0\u03A6")));
		vector_unit_3d e3("2 N",10.0f,10.0f);
		vector_unit_3d e4("1 m",100.0f,100.0f);
		REQUIRE (bool(scifir::cross_product(e3,e4).vectorial_display() == vector_unit_3d("1.97 kg*m2/s2 8.21\u03B8 80.00\u03A6")));
		vector_unit_3d f("2 N",10.0f,10.0f);
		vector_unit_3d f2("1 m",20.0f,20.0f);
		REQUIRE (bool(scifir::angle_between(f,f2).display() == angle("10.29\u00B0")));
		vector_unit_3d g("2 N",10.0f,10.0f);
		vector_unit_3d g2("1 m",10.0f,10.0f);
		REQUIRE (bool(scifir::same_direction(g,g2) == true));
		REQUIRE (bool(scifir::parallel(g,g2) == true));
		vector_unit_3d g3("2 N",10.0f,10.0f);
		vector_unit_3d g4("1 m",10.0f,20.0f);
		REQUIRE (bool(scifir::same_direction(g3,g4) == false));
		REQUIRE (bool(scifir::parallel(g3,g4) == false));
		vector_unit_3d h("2 N",0.0f,0.0f);
		vector_unit_3d h2("1 m",0.0f,90.0f);
		REQUIRE (bool(scifir::orthogonal(h,h2) == true));
	}

	SECTION("Comparison operators of vector_unit_3d classes")
	{
		vector_unit_3d a("2 N",10.0f,10.0f);
		vector_unit_3d a2("2 N",10.0f,10.0f);
		REQUIRE (bool(a == a2));
		vector_unit_3d b("2 N",10.0f,10.0f);
		vector_unit_3d b2("2 N",20.0f,10.0f);
		REQUIRE (bool(b != b2));
	}

	SECTION("String operations with vector_unit_3d classes")
	{
		vector_unit_3d a("2 N",10.0f,10.0f);
		REQUIRE (bool(a == "2 N 10\u03B8 10\u03A6"));
		REQUIRE (bool(a != "3 N 10\u03B8 10\u03A6"));
		REQUIRE (bool("2 N 10\u03B8 10\u03A6" == a));
		REQUIRE (bool("3 N 10\u03B8 10\u03A6" != a));
		vector_unit_3d b("2 N",10.0f,10.0f);
		string b2 = "b: ";
		b2 += b;
		REQUIRE (bool("b: 2 N 10\u03B8 10\u03A6"));
		vector_unit_3d c("2 N",10.0f,10.0f);
		REQUIRE (bool(("b: " + c) == "b: 2 N 10\u03B8 10\u03A6"));
		REQUIRE (bool((c + " b") == "2 N 10\u03B8 10\u03A6 b"));
	}

	SECTION("Stream operators of vector_unit_3d class")
    {
        ostringstream a;
        a << vector_unit_3d("2 N",10.0f,10.0f);
        REQUIRE (bool(a.str() == "2 N 10\u03B8 10\u03A6"));
        stringstream b;
        b << "3 N 10\u03B8 10\u03A6";
        vector_unit_3d b2("1 N",angle(5.0f),angle(2.0f));
        b >> b2;
        REQUIRE (bool(b2 == "3 N 10\u03B8 10\u03A6"));
    }
}
