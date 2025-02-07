#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../units/vector_unit_3d.hpp"
#include "../../units/base_units.hpp"
#include "../../units/special_names.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class vector_unit_3d")
{
	SECTION("Constructors of vector_unit_3d class")
	{
		vector_unit_3d a;
		CHECK(to_string(a) == "0 [empty] 0θ 0Φ");
		vector_unit_3d b("100 g",50,20);
		vector_unit_3d c(b);
		CHECK(to_string(c) == "100 g 50θ 20Φ");
		vector_unit_3d b2("100 g",50,20);
		vector_unit_3d c2(std::move(b2));
		CHECK(to_string(c2) == "100 g 50θ 20Φ");
		vector_unit_3d p(30.0f, dimension::PASCAL, prefix::KILO, 20.0f, 30.0f);
		CHECK(to_string(p) == "30 kPa 20θ 30Φ");
		vector_unit_3d p2(30.0, dimension::PASCAL, prefix::KILO, 20.0f, 30.0f);
		CHECK(to_string(p2) == "30 kPa 20θ 30Φ");
		vector_unit_3d p3(30.0l, dimension::PASCAL, prefix::KILO, 20.0f, 30.0f);
		CHECK(to_string(p3) == "30 kPa 20θ 30Φ");
		vector_unit_3d p4(30, dimension::PASCAL, prefix::KILO, 20.0f, 30.0f);
		CHECK(to_string(p4) == "30 kPa 20θ 30Φ");
		vector_unit_3d p5(30.0f, dimension::PASCAL, prefix::KILO, angle(20.0f), angle(30.0f));
		CHECK(to_string(p5) == "30 kPa 20θ 30Φ");
		vector_unit_3d p6(30.0, dimension::PASCAL, prefix::KILO, angle(20.0f), angle(30.0f));
		CHECK(to_string(p6) == "30 kPa 20θ 30Φ");
		vector_unit_3d p7(30.0l, dimension::PASCAL, prefix::KILO, angle(20.0f), angle(30.0f));
		CHECK(to_string(p7) == "30 kPa 20θ 30Φ");
		vector_unit_3d p8(30, dimension::PASCAL, prefix::KILO, angle(20.0f), angle(30.0f));
		CHECK(to_string(p8) == "30 kPa 20θ 30Φ");
		vector_unit_3d d(50.0f,"m",20,20);
		CHECK(to_string(d) == "50 m 20θ 20Φ");
		vector_unit_3d e(50.0f,"m",angle(20.0f),angle(20.0f));
		CHECK(to_string(e) == "50 m 20θ 20Φ");
		vector_unit_3d d2(50.0,"m",20,20);
		CHECK(to_string(d2) == "50 m 20θ 20Φ");
		vector_unit_3d e2(50.0,"m",angle(20.0f),angle(20.0f));
		CHECK(to_string(e2) == "50 m 20θ 20Φ");
		vector_unit_3d d3(50.0l,"m",20,20);
		CHECK(to_string(d3) == "50 m 20θ 20Φ");
		vector_unit_3d e3(50.0l,"m",angle(20.0f),angle(20.0f));
		CHECK(to_string(e3) == "50 m 20θ 20Φ");
		vector_unit_3d d4(50,"m",20,20);
		CHECK(to_string(d4) == "50 m 20θ 20Φ");
		vector_unit_3d e4(50,"m",angle(20.0f),angle(20.0f));
		CHECK(to_string(e4) == "50 m 20θ 20Φ");
		vector_unit_3d f(50.0f,{dimension("m",dimension::NUMERATOR)},20,20);
		CHECK(to_string(f) == "50 m 20θ 20Φ");
		vector_unit_3d g(50.0f,{dimension("m",dimension::NUMERATOR)},angle(20.0f),angle(20.0f));
		CHECK(to_string(g) == "50 m 20θ 20Φ");
		vector_unit_3d f2(50.0,{dimension("m",dimension::NUMERATOR)},20,20);
		CHECK(to_string(f2) == "50 m 20θ 20Φ");
		vector_unit_3d g2(50.0,{dimension("m",dimension::NUMERATOR)},angle(20.0f),angle(20.0f));
		CHECK(to_string(g2) == "50 m 20θ 20Φ");
		vector_unit_3d f3(50.0l,{dimension("m",dimension::NUMERATOR)},20,20);
		CHECK(to_string(f3) == "50 m 20θ 20Φ");
		vector_unit_3d g3(50.0l,{dimension("m",dimension::NUMERATOR)},angle(20.0f),angle(20.0f));
		CHECK(to_string(g3) == "50 m 20θ 20Φ");
		vector_unit_3d f4(50,{dimension("m",dimension::NUMERATOR)},20,20);
		CHECK(to_string(f4) == "50 m 20θ 20Φ");
		vector_unit_3d g4(50,{dimension("m",dimension::NUMERATOR)},angle(20.0f),angle(20.0f));
		CHECK(to_string(g4) == "50 m 20θ 20Φ");
		scalar_unit h2 = scalar_unit("50 g");
		vector_unit_3d h(h2,20,20);
		CHECK(to_string(h) == "50 g 20θ 20Φ");
		vector_unit_3d i(h2,angle(20.0f),angle(20.0f));
		CHECK(to_string(i) == "50 g 20θ 20Φ");
		vector_unit_3d j("100 g",24,24);
		CHECK(to_string(j) == "100 g 24θ 24Φ");
		vector_unit_3d k("100 g",angle(24.0f),angle(24.0f));
		CHECK(to_string(k) == "100 g 24θ 24Φ");
		vector_unit_3d l("100 g 20 20");
		CHECK(to_string(l) == "100 g 20θ 20Φ");
		vector_unit_3d m("100 g 20º 20º");
		CHECK(to_string(m) == "100 g 20θ 20Φ");
		vector_unit_3d n = vector_unit_3d::cartesian_3d("m",1,1,1);
		CHECK(to_string(n) == "1.73 m 45θ 54.73Φ");
		vector_unit_3d o = vector_unit_3d::cylindrical("m",1,angle(45.0f),1);
		CHECK(to_string(o) == "1.41 m 45θ 45Φ");
	}

	SECTION("Assignments of vector_unit_3d class")
	{
		vector_unit_3d a("10 N",angle(10.0f),angle(5.0f));
		vector_unit_3d b("20 N",angle(20.0f),angle(30.0f));
		a = b;
		CHECK(to_string(a) == "20 N 20θ 30Φ");
		vector_unit_3d c("5 N",angle(5.0f),angle(15.0f));
		vector_unit_3d d("30 N",angle(15.0f),angle(20.0f));
		c = std::move(d);
		CHECK(to_string(c) == "30 N 15θ 20Φ");
		vector_unit_3d e("10 N",angle(10.0f),angle(10.0f));
		scalar_unit e2 = scalar_unit("5 N");
		e = e2;
		CHECK(to_string(e) == "5 N 10θ 10Φ");
		vector_unit_3d f("10 N",angle(10.0f),angle(10.0f));
		f = std::move(scalar_unit("5 N"));
		CHECK(to_string(f) == "5 N 10θ 10Φ");
		vector_unit_3d g("10 N",angle(10.0f),angle(10.0f));
		g = "8 N 15θ 30Φ";
		CHECK(to_string(g) == "8 N 15θ 30Φ");
	}

	SECTION("point_to() function of vector_unit_3d class")
	{
		vector_unit_3d a("10 N",20.0f,30.0f);
		a.point_to(direction::LEFT);
		CHECK(a.theta.get_value() == 270.0f);
		CHECK(a.phi.get_value() == 90.0f);
		a.point_to(direction::RIGHT);
		CHECK(a.theta.get_value() == 90.0f);
		CHECK(a.phi.get_value() == 90.0f);
		a.point_to(direction::TOP);
		CHECK(a.theta.get_value() == 0.0f);
		CHECK(a.phi.get_value() == 0.0f);
		a.point_to(direction::BOTTOM);
		CHECK(a.theta.get_value() == 0.0f);
		CHECK(a.phi.get_value() == 180.0f);
		a.point_to(direction::LEFT_TOP);
		CHECK(a.theta.get_value() == 270.0f);
		CHECK(a.phi.get_value() == 45.0f);
		a.point_to(direction::RIGHT_TOP);
		CHECK(a.theta.get_value() == 90.0f);
		CHECK(a.phi.get_value() == 45.0f);
		a.point_to(direction::RIGHT_BOTTOM);
		CHECK(a.theta.get_value() == 90.0f);
		CHECK(a.phi.get_value() == 135.0f);
		a.point_to(direction::LEFT_BOTTOM);
		CHECK(a.theta.get_value() == 270.0f);
		CHECK(a.phi.get_value() == 135.0f);
		a.point_to(direction::FRONT);
		CHECK(a.theta.get_value() == 0.0f);
		CHECK(a.phi.get_value() == 90.0f);
		a.point_to(direction::BACK);
		CHECK(a.theta.get_value() == 180.0f);
		CHECK(a.phi.get_value() == 90.0f);
		a.point_to(direction::LEFT_FRONT);
		CHECK(a.theta.get_value() == 315.0f);
		CHECK(a.phi.get_value() == 90.0f);
		a.point_to(direction::RIGHT_FRONT);
		CHECK(a.theta.get_value() == 45.0f);
		CHECK(a.phi.get_value() == 90.0f);
		a.point_to(direction::TOP_FRONT);
		CHECK(a.theta.get_value() == 0.0f);
		CHECK(a.phi.get_value() == 45.0f);
		a.point_to(direction::BOTTOM_FRONT);
		CHECK(a.theta.get_value() == 0.0f);
		CHECK(a.phi.get_value() == 135.0f);
		a.point_to(direction::LEFT_BACK);
		CHECK(a.theta.get_value() == 225.0f);
		CHECK(a.phi.get_value() == 90.0f);
		a.point_to(direction::RIGHT_BACK);
		CHECK(a.theta.get_value() == 135.0f);
		CHECK(a.phi.get_value() == 90.0f);
		a.point_to(direction::TOP_BACK);
		CHECK(a.theta.get_value() == 180.0f);
		CHECK(a.phi.get_value() == 45.0f);
		a.point_to(direction::BOTTOM_BACK);
		CHECK(a.theta.get_value() == 180.0f);
		CHECK(a.phi.get_value() == 135.0f);
		a.point_to(direction::LEFT_TOP_FRONT);
		CHECK(a.theta.get_value() == 315.0f);
		CHECK(a.phi.get_value() == 45.0f);
		a.point_to(direction::RIGHT_TOP_FRONT);
		CHECK(a.theta.get_value() == 45.0f);
		CHECK(a.phi.get_value() == 45.0f);
		a.point_to(direction::LEFT_BOTTOM_FRONT);
		CHECK(a.theta.get_value() == 315.0f);
		CHECK(a.phi.get_value() == 135.0f);
		a.point_to(direction::RIGHT_BOTTOM_FRONT);
		CHECK(a.theta.get_value() == 45.0f);
		CHECK(a.phi.get_value() == 135.0f);
		a.point_to(direction::LEFT_TOP_BACK);
		CHECK(a.theta.get_value() == 225.0f);
		CHECK(a.phi.get_value() == 45.0f);
		a.point_to(direction::RIGHT_TOP_BACK);
		CHECK(a.theta.get_value() == 135.0f);
		CHECK(a.phi.get_value() == 45.0f);
		a.point_to(direction::LEFT_BOTTOM_BACK);
		CHECK(a.theta.get_value() == 225.0f);
		CHECK(a.phi.get_value() == 135.0f);
		a.point_to(direction::RIGHT_BOTTOM_BACK);
		CHECK(a.theta.get_value() == 135.0f);
		CHECK(a.phi.get_value() == 135.0f);
	}

	SECTION("Operators of vector_unit_3d class with other vector_unit_3d class")
	{
		vector_unit_3d a("10 N",20.0f,30.0f);
		vector_unit_3d a2("10 N",20.0f,30.0f);
		a += a2;
		CHECK(to_string(a) == "19.99 N 20θ 29.99Φ");
		vector_unit_3d a3("10 N",20.0f,30.0f);
		vector_unit_3d a4("10 g",20.0f,30.0f);
		a3 += a4;
		CHECK(to_string(a3) == "10 N 20θ 30Φ");
		vector_unit_3d b("10 N",20.0f,30.0f);
		vector_unit_3d b2("5 N",20.0f,30.0f);
		b -= b2;
		CHECK(to_string(b) == "4.99 N 20θ 30Φ");
		vector_unit_3d b3("10 N",20.0f,30.0f);
		vector_unit_3d b4("5 g",20.0f,30.0f);
		b3 -= b4;
		CHECK(to_string(b3) == "10 N 20θ 30Φ");
		vector_unit_3d c("10 N",20.0f,30.0f);
		vector_unit_3d c2("5 N",20.0f,30.0f);
		CHECK(to_string(c + c2) == "14.99 N 20θ 30Φ");
		vector_unit_3d c3("10 N",20.0f,30.0f);
		vector_unit_3d c4("5 g",20.0f,30.0f);
		CHECK(to_string(c3 + c4) == "0 [empty] 0θ 0Φ");
		vector_unit_3d d("10 N",20.0f,30.0f);
		vector_unit_3d d2("5 N",20.0f,30.0f);
		CHECK(to_string(d - d2) == "4.99 N 20θ 30Φ");
		vector_unit_3d d3("10 N",20.0f,30.0f);
		vector_unit_3d d4("5 g",20.0f,30.0f);
		CHECK(to_string(d3 - d4) == "0 [empty] 0θ 0Φ");
	}

	SECTION("Operators of vector_unit_3d class with scalar_unit class")
	{
		vector_unit_3d a("10 N",10.0f,10.0f);
		scalar_unit a2("5 g");
		CHECK(to_string(a * a2) == "50 g*kg*m/s2 10θ 10Φ");
		vector_unit_3d a3 = (a * a2);
		a3.change_dimensions("N*g");
		CHECK(to_string(a3) == "50 N*g 10θ 10Φ");
		CHECK(to_string(a2 * a) == "50 g*kg*m/s2 10θ 10Φ");
		vector_unit_3d b("10 N",10.0f,10.0f);
		scalar_unit b2("5 g");
		CHECK(to_string(b / b2) == "2000 m/s2 10θ 10Φ");
		vector_unit_3d c("10 N",10.0f,10.0f);
		scalar_unit c2(10_N / 5_N);
		CHECK(to_string(c ^ c2) == "100 N2 10θ 10Φ");
		vector_unit_3d c3("10 N",10.0f,10.0f);
		scalar_unit c4(10_N);
		CHECK(to_string(c3 ^ c4) == "0 [empty] 0θ 0Φ");
	}

	SECTION("Numeric operators of vector_unit_3d class")
	{
		vector_unit_3d a("10 N",20.0f,20.0f);
		CHECK(to_string(a + 10.0f) == "20 N 20θ 20Φ");
		CHECK(to_string(10.0f + a) == "20 N 20θ 20Φ");
		vector_unit_3d b("10 N",20.0f,20.0f);
		CHECK(to_string(b - 5.0f) == "5 N 20θ 20Φ");
		CHECK(to_string(20.0f - b) == "10 N 20θ 20Φ");
		vector_unit_3d c("10 N",20.0f,20.0f);
		CHECK(to_string(c * 2.0f) == "20 N 20θ 20Φ");
		CHECK(to_string(2.0f * c) == "20 N 20θ 20Φ");
		vector_unit_3d d("10 N",20.0f,20.0f);
		CHECK(to_string(d / 2.0f) == "5 N 20θ 20Φ");
		CHECK(to_string(20.0f / d) == "2 1/N 20θ 20Φ");
		vector_unit_3d e("10 N",20.0f,20.0f);
		CHECK(to_string(e ^ 2) == "100 N2 20θ 20Φ");
		vector_unit_3d f("10 N",20.0f,20.0f);
		f += 5.0f;
		CHECK(to_string(f) == "15 N 20θ 20Φ");
		vector_unit_3d g("10 N",20.0f,20.0f);
		g -= 5.0f;
		CHECK(to_string(g) == "5 N 20θ 20Φ");
		vector_unit_3d h("10 N",20.0f,20.0f);
		h *= 2.0f;
		CHECK(to_string(h) == "20 N 20θ 20Φ");
		vector_unit_3d i("10 N",20.0f,20.0f);
		i *= -2.0f;
		CHECK(to_string(i) == "20 N 200θ 160Φ");
		vector_unit_3d j("10 N",20.0f,20.0f);
		j /= 2.0f;
		CHECK(to_string(j) == "5 N 20θ 20Φ");
		vector_unit_3d k("10 N",20.0f,20.0f);
		k /= -2.0f;
		CHECK(to_string(k) == "5 N 200θ 160Φ");
	}

	SECTION("Projections of vector_unit_3d class")
	{
		vector_unit_3d a("2 N",10.0f,10.0f);
		CHECK(a.x_projection().display(2) == "0.34 N");
		CHECK(a.y_projection().display(2) == "0.06 N");
		CHECK(a.z_projection().display(2) == "1.96 N");
	}

	SECTION("Invertion of vector_unit_3d class")
	{
		vector_unit_3d a("2 N",10.0f,10.0f);
		a.invert();
		CHECK(to_string(a) == "2 N 190θ 170Φ");
	}

	SECTION("Display of vector_unit_3d class")
	{
		vector_unit_3d a(1,"N",20,20);
		CHECK(a.vectorial_display() == "1 N 20θ 20Φ");
		CHECK(a.vectorial_base_display() == "1 kg*m/s2 20θ 20Φ");
		CHECK(a.vectorial_custom_display("g*m/s2") == "1000 g*m/s2 20θ 20Φ");
	}

	SECTION("Math functions of vector_unit_3d class")
	{
		vector_unit_3d a("2 N",10.0f,10.0f);
		CHECK(bool(scifir::norm(a) == scalar_unit("2 N")));
		vector_unit_3d b("4 N2",10.0f,10.0f);
		CHECK(bool(scifir::sqrt(b) == scalar_unit("2 N")));
		vector_unit_3d c("8 N3",10.0f,10.0f);
		CHECK(bool(scifir::sqrt_nth(c,3) == scalar_unit("2 N")));
		vector_unit_3d d("2 N",10.0f,10.0f);
		vector_unit_3d d2("1 m",10.0f,10.0f);
		CHECK(bool(scifir::dot_product(d,d2).display() == scalar_unit("1.99 kg*m2/s2")));
		vector_unit_3d e("2 N",10.0f,10.0f);
		vector_unit_3d e2("1 m",10.0f,10.0f);
		CHECK(bool(scifir::cross_product(e,e2) == vector_unit_3d("0 kg*m2/s2 0θ 0Φ")));
		vector_unit_3d e3("2 N",10.0f,10.0f);
		vector_unit_3d e4("1 m",100.0f,100.0f);
		CHECK(bool(scifir::cross_product(e3,e4).vectorial_display() == vector_unit_3d("1.97 kg*m2/s2 8.21θ 80.00Φ")));
		vector_unit_3d f("2 N",10.0f,10.0f);
		vector_unit_3d f2("1 m",20.0f,20.0f);
		CHECK(bool(scifir::angle_between(f,f2).display() == angle("10.29\u00B0")));
		vector_unit_3d g("2 N",10.0f,10.0f);
		vector_unit_3d g2("1 m",10.0f,10.0f);
		CHECK(scifir::same_direction(g,g2) == true);
		CHECK(scifir::parallel(g,g2) == true);
		vector_unit_3d g3("2 N",10.0f,10.0f);
		vector_unit_3d g4("1 m",10.0f,20.0f);
		CHECK(scifir::same_direction(g3,g4) == false);
		CHECK(scifir::parallel(g3,g4) == false);
		vector_unit_3d h("2 N",0.0f,0.0f);
		vector_unit_3d h2("1 m",0.0f,90.0f);
		CHECK(scifir::orthogonal(h,h2) == true);
	}

	SECTION("Comparison operators of vector_unit_3d class")
	{
		vector_unit_3d a("2 N",10.0f,10.0f);
		vector_unit_3d a2("2 N",10.0f,10.0f);
		CHECK(bool(a == a2));
		vector_unit_3d b("2 N",10.0f,10.0f);
		vector_unit_3d b2("2 N",20.0f,10.0f);
		CHECK(bool(b != b2));
	}

	SECTION("String operations with vector_unit_3d class")
	{
		vector_unit_3d a("2 N",10.0f,10.0f);
		CHECK(bool(a == "2 N 10θ 10Φ"));
		CHECK(bool(a != "3 N 10θ 10Φ"));
		CHECK(bool("2 N 10θ 10Φ" == a));
		CHECK(bool("3 N 10θ 10Φ" != a));
		vector_unit_3d b("2 N",10.0f,10.0f);
		string b2 = "b: ";
		b2 += b;
		CHECK("b: 2 N 10θ 10Φ");
		vector_unit_3d c("2 N",10.0f,10.0f);
		CHECK(("b: " + c) == "b: 2 N 10θ 10Φ");
		CHECK((c + " b") == "2 N 10θ 10Φ b");
	}

	SECTION("Stream operators of vector_unit_3d class")
    {
        ostringstream a;
        a << vector_unit_3d("2 N",10.0f,10.0f);
        CHECK(a.str() == "2 N 10θ 10Φ");
        stringstream b;
        b << "3 N 10θ 10Φ";
        vector_unit_3d b2("1 N",angle(5.0f),angle(2.0f));
        b >> b2;
        CHECK(bool(b2 == "3 N 10θ 10Φ"));
    }
}
