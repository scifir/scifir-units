#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../units/vector_unit_nd.hpp"
#include "../../units/base_units.hpp"
#include "../../units/special_names.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class vector_unit_nd")
{
	SECTION("Constructors of vector_unit_nd class")
	{
		vector_unit_nd a;
		CHECK(to_string(a) == "0 [empty]");
		vector_unit_nd b("100 g",{50,20,20});
		vector_unit_nd c(b);
		CHECK(to_string(c) == "100 g 50° 20° 20°");
		vector_unit_nd b2("100 g",{50,20,20});
		vector_unit_nd c2(std::move(b2));
		CHECK(to_string(c2) == "100 g 50° 20° 20°");
		vector_unit_nd s(30.0f, dimension::PASCAL, prefix::KILO, { 20.0f, 30.0f });
		CHECK(to_string(s) == "30 kPa 20° 30°");
		vector_unit_nd s2(30.0, dimension::PASCAL, prefix::KILO, { 20.0f, 30.0f });
		CHECK(to_string(s2) == "30 kPa 20° 30°");
		vector_unit_nd s3(30.0l, dimension::PASCAL, prefix::KILO, { 20.0f, 30.0f });
		CHECK(to_string(s3) == "30 kPa 20° 30°");
		vector_unit_nd s4(30, dimension::PASCAL, prefix::KILO, { 20.0f, 30.0f });
		CHECK(to_string(s4) == "30 kPa 20° 30°");
		vector_unit_nd s5(30.0f, dimension::PASCAL, prefix::KILO, { angle(20.0f), angle(30.0f) });
		CHECK(to_string(s5) == "30 kPa 20° 30°");
		vector_unit_nd s6(30.0, dimension::PASCAL, prefix::KILO, { angle(20.0f), angle(30.0f) });
		CHECK(to_string(s6) == "30 kPa 20° 30°");
		vector_unit_nd s7(30.0l, dimension::PASCAL, prefix::KILO, { angle(20.0f), angle(30.0f) });
		CHECK(to_string(s7) == "30 kPa 20° 30°");
		vector_unit_nd s8(30, dimension::PASCAL, prefix::KILO, { angle(20.0f), angle(30.0f) });
		CHECK(to_string(s8) == "30 kPa 20° 30°");
		vector_unit_nd q(50.0f,"m");
		CHECK(to_string(q) == "50 m");
		vector_unit_nd q2(50.0,"m");
		CHECK(to_string(q2) == "50 m");
		vector_unit_nd q3(50.0l,"m");
		CHECK(to_string(q3) == "50 m");
		vector_unit_nd q4(50,"m");
		CHECK(to_string(q4) == "50 m");
		vector_unit_nd d(50.0f,"m",{20,20,20});
		CHECK(to_string(d) == "50 m 20° 20° 20°");
		vector_unit_nd e(50.0f,"m",{angle(20.0f),angle(20.0f)});
		CHECK(to_string(e) == "50 m 20° 20°");
		vector_unit_nd d2(50.0,"m",{20,20,20});
		CHECK(to_string(d2) == "50 m 20° 20° 20°");
		vector_unit_nd e2(50.0,"m",{angle(20.0f),angle(20.0f)});
		CHECK(to_string(e2) == "50 m 20° 20°");
		vector_unit_nd d3(50.0l,"m",{20,20,20});
		CHECK(to_string(d3) == "50 m 20° 20° 20°");
		vector_unit_nd e3(50.0l,"m",{angle(20.0f),angle(20.0f)});
		CHECK(to_string(e3) == "50 m 20° 20°");
		vector_unit_nd d4(50,"m",{20,20,20});
		CHECK(to_string(d4) == "50 m 20° 20° 20°");
		vector_unit_nd e4(50,"m",{angle(20.0f),angle(20.0f)});
		CHECK(to_string(e4) == "50 m 20° 20°");
		vector_unit_nd r(50.0f,{dimension("m",dimension::NUMERATOR)});
		CHECK(to_string(r) == "50 m");
		vector_unit_nd r2(50.0,{dimension("m",dimension::NUMERATOR)});
		CHECK(to_string(r2) == "50 m");
		vector_unit_nd r3(50.0l,{dimension("m",dimension::NUMERATOR)});
		CHECK(to_string(r3) == "50 m");
		vector_unit_nd r4(50,{dimension("m",dimension::NUMERATOR)});
		CHECK(to_string(r4) == "50 m");
		vector_unit_nd f(50.0f,{dimension("m",dimension::NUMERATOR)},{20,20,20});
		CHECK(to_string(f) == "50 m 20° 20° 20°");
		vector_unit_nd g(50.0f,{dimension("m",dimension::NUMERATOR)},{angle(20.0f),angle(20.0f)});
		CHECK(to_string(g) == "50 m 20° 20°");
		vector_unit_nd f2(50.0,{dimension("m",dimension::NUMERATOR)},{20,20,20});
		CHECK(to_string(f2) == "50 m 20° 20° 20°");
		vector_unit_nd g2(50.0,{dimension("m",dimension::NUMERATOR)},{angle(20.0f),angle(20.0f)});
		CHECK(to_string(g2) == "50 m 20° 20°");
		vector_unit_nd f3(50.0l,{dimension("m",dimension::NUMERATOR)},{20,20,20});
		CHECK(to_string(f3) == "50 m 20° 20° 20°");
		vector_unit_nd g3(50.0l,{dimension("m",dimension::NUMERATOR)},{angle(20.0f),angle(20.0f)});
		CHECK(to_string(g3) == "50 m 20° 20°");
		vector_unit_nd f4(50,{dimension("m",dimension::NUMERATOR)},{20,20,20});
		CHECK(to_string(f4) == "50 m 20° 20° 20°");
		vector_unit_nd g4(50,{dimension("m",dimension::NUMERATOR)},{angle(20.0f),angle(20.0f)});
		CHECK(to_string(g4) == "50 m 20° 20°");
		scalar_unit h2 = scalar_unit("50 g");
		vector_unit_nd h(h2,{20,20,20});
		CHECK(to_string(h) == "50 g 20° 20° 20°");
		vector_unit_nd i(h2,{angle(20.0f),angle(20.0f)});
		CHECK(to_string(i) == "50 g 20° 20°");
		vector_unit_nd j("100 g",{24,24,24});
		CHECK(to_string(j) == "100 g 24° 24° 24°");
		vector_unit_nd k("100 g",{angle(24.0f),angle(24.0f)});
		CHECK(to_string(k) == "100 g 24° 24°");
		vector_unit_nd l("100 g 20 20 20");
		CHECK(to_string(l) == "100 g 20° 20° 20°");
		vector_unit_nd m("100 g 20° 20° 20° 20°");
		CHECK(to_string(m) == "100 g 20° 20° 20° 20°");
		vector_unit_nd n = vector_unit_nd::cartesian_2d("m",1,1);
		CHECK(to_string(n) == "1.41 m 45°");
		vector_unit_nd o = vector_unit_nd::cartesian_3d("m",1,1,1);
		CHECK(to_string(o) == "1.73 m 45° 54.73°");
		vector_unit_nd p = vector_unit_nd::cylindrical("m",1,angle(45.0f),1);
		CHECK(to_string(p) == "1.41 m 45° 45°");
	}

	SECTION("Assignments of vector_unit_nd class")
	{
		vector_unit_nd a("10 g");
		vector_unit_nd b("100 g",{50,20,20});
		a = b;
		CHECK(to_string(a) == "100 g 50° 20° 20°");
		vector_unit_nd c("10 g");
		vector_unit_nd d("100 g",{50,20,20});
		c = std::move(d);
		CHECK(to_string(c) == "100 g 50° 20° 20°");
		vector_unit_nd e("10 g",{50.0f,20.0f});
		scalar_unit f("100 g");
		e = f;
		CHECK(to_string(e) == "100 g 50° 20°");
		vector_unit_nd g("10 g",{50.0f,20.0f});
		scalar_unit h("100 g");
		g = std::move(h);
		CHECK(to_string(g) == "100 g 50° 20°");
		vector_unit_nd i("10 N",{angle(10.0f),angle(15.0f),angle(40.0f)});
		i = "100 N 50° 20° 30°";
		CHECK(to_string(i) == "100 N 50° 20° 30°");
	}

	SECTION("point_to() function of vector_unit_nd class for the 1d case")
	{
		vector_unit_nd a("10 N");
		a.point_to(direction::LEFT);
		CHECK(a.get_value() <= 0);
		a.point_to(direction::RIGHT);
		CHECK(a.get_value() >= 0);
	}

	SECTION("point_to() function of vector_unit_nd class for the 2d case")
	{
		vector_unit_nd a("10 N",vector<float>{20.0f});
		a.point_to(direction::LEFT);
		CHECK(a.angles[0].get_value() == 180.0f);
		a.point_to(direction::RIGHT);
		CHECK(a.angles[0].get_value() == 0.0f);
		a.point_to(direction::TOP);
		CHECK(a.angles[0].get_value() == 90.0f);
		a.point_to(direction::BOTTOM);
		CHECK(a.angles[0].get_value() == 270.0f);
		a.point_to(direction::LEFT_TOP);
		CHECK(a.angles[0].get_value() == 135.0f);
		a.point_to(direction::RIGHT_TOP);
		CHECK(a.angles[0].get_value() == 45.0f);
		a.point_to(direction::RIGHT_BOTTOM);
		CHECK(a.angles[0].get_value() == 315.0f);
		a.point_to(direction::LEFT_BOTTOM);
		CHECK(a.angles[0].get_value() == 225.0f);
	}

	SECTION("point_to() function of vector_unit_nd class for the 3d case")
	{
		vector_unit_nd a("10 N",{20.0f,30.0f});
		a.point_to(direction::LEFT);
		CHECK(a.angles[0].get_value() == 270.0f);
		CHECK(a.angles[1].get_value() == 90.0f);
		a.point_to(direction::RIGHT);
		CHECK(a.angles[0].get_value() == 90.0f);
		CHECK(a.angles[1].get_value() == 90.0f);
		a.point_to(direction::TOP);
		CHECK(a.angles[0].get_value() == 0.0f);
		CHECK(a.angles[1].get_value() == 0.0f);
		a.point_to(direction::BOTTOM);
		CHECK(a.angles[0].get_value() == 0.0f);
		CHECK(a.angles[1].get_value() == 180.0f);
		a.point_to(direction::LEFT_TOP);
		CHECK(a.angles[0].get_value() == 270.0f);
		CHECK(a.angles[1].get_value() == 45.0f);
		a.point_to(direction::RIGHT_TOP);
		CHECK(a.angles[0].get_value() == 90.0f);
		CHECK(a.angles[1].get_value() == 45.0f);
		a.point_to(direction::RIGHT_BOTTOM);
		CHECK(a.angles[0].get_value() == 90.0f);
		CHECK(a.angles[1].get_value() == 135.0f);
		a.point_to(direction::LEFT_BOTTOM);
		CHECK(a.angles[0].get_value() == 270.0f);
		CHECK(a.angles[1].get_value() == 135.0f);
		a.point_to(direction::FRONT);
		CHECK(a.angles[0].get_value() == 0.0f);
		CHECK(a.angles[1].get_value() == 90.0f);
		a.point_to(direction::BACK);
		CHECK(a.angles[0].get_value() == 180.0f);
		CHECK(a.angles[1].get_value() == 90.0f);
		a.point_to(direction::LEFT_FRONT);
		CHECK(a.angles[0].get_value() == 315.0f);
		CHECK(a.angles[1].get_value() == 90.0f);
		a.point_to(direction::RIGHT_FRONT);
		CHECK(a.angles[0].get_value() == 45.0f);
		CHECK(a.angles[1].get_value() == 90.0f);
		a.point_to(direction::TOP_FRONT);
		CHECK(a.angles[0].get_value() == 0.0f);
		CHECK(a.angles[1].get_value() == 45.0f);
		a.point_to(direction::BOTTOM_FRONT);
		CHECK(a.angles[0].get_value() == 0.0f);
		CHECK(a.angles[1].get_value() == 135.0f);
		a.point_to(direction::LEFT_BACK);
		CHECK(a.angles[0].get_value() == 225.0f);
		CHECK(a.angles[1].get_value() == 90.0f);
		a.point_to(direction::RIGHT_BACK);
		CHECK(a.angles[0].get_value() == 135.0f);
		CHECK(a.angles[1].get_value() == 90.0f);
		a.point_to(direction::TOP_BACK);
		CHECK(a.angles[0].get_value() == 180.0f);
		CHECK(a.angles[1].get_value() == 45.0f);
		a.point_to(direction::BOTTOM_BACK);
		CHECK(a.angles[0].get_value() == 180.0f);
		CHECK(a.angles[1].get_value() == 135.0f);
		a.point_to(direction::LEFT_TOP_FRONT);
		CHECK(a.angles[0].get_value() == 315.0f);
		CHECK(a.angles[1].get_value() == 45.0f);
		a.point_to(direction::RIGHT_TOP_FRONT);
		CHECK(a.angles[0].get_value() == 45.0f);
		CHECK(a.angles[1].get_value() == 45.0f);
		a.point_to(direction::LEFT_BOTTOM_FRONT);
		CHECK(a.angles[0].get_value() == 315.0f);
		CHECK(a.angles[1].get_value() == 135.0f);
		a.point_to(direction::RIGHT_BOTTOM_FRONT);
		CHECK(a.angles[0].get_value() == 45.0f);
		CHECK(a.angles[1].get_value() == 135.0f);
		a.point_to(direction::LEFT_TOP_BACK);
		CHECK(a.angles[0].get_value() == 225.0f);
		CHECK(a.angles[1].get_value() == 45.0f);
		a.point_to(direction::RIGHT_TOP_BACK);
		CHECK(a.angles[0].get_value() == 135.0f);
		CHECK(a.angles[1].get_value() == 45.0f);
		a.point_to(direction::LEFT_BOTTOM_BACK);
		CHECK(a.angles[0].get_value() == 225.0f);
		CHECK(a.angles[1].get_value() == 135.0f);
		a.point_to(direction::RIGHT_BOTTOM_BACK);
		CHECK(a.angles[0].get_value() == 135.0f);
		CHECK(a.angles[1].get_value() == 135.0f);
	}

	SECTION("Operators of vector_unit_nd class with other vector_unit_nd class")
	{
		vector_unit_nd a("10 N",{20.0f,30.0f});
		vector_unit_nd a2("10 N",{20.0f,30.0f});
		a += a2;
		CHECK(to_string(a) == "19.99 N 20° 29.99°");
		vector_unit_nd a_2("10 N",vector<float>{20.0f});
		vector_unit_nd a2_2("10 N",vector<float>{20.0f});
		a_2 += a2_2;
		CHECK(to_string(a_2) == "20 N 20°");
		vector_unit_nd a_3("10 N");
		vector_unit_nd a2_3("10 N");
		a_3 += a2_3;
		CHECK(to_string(a_3) == "20 N");
		vector_unit_nd a3("10 N",{20.0f,30.0f});
		vector_unit_nd a4("10 g",{20.0f,30.0f});
		a3 += a4;
		CHECK(to_string(a3) == "10 N 20° 30°");
		vector_unit_nd b("10 N",{20.0f,30.0f});
		vector_unit_nd b2("5 N",{20.0f,30.0f});
		b -= b2;
		CHECK(to_string(b) == "4.99 N 20° 30°");
		vector_unit_nd b3("10 N",{20.0f,30.0f});
		vector_unit_nd b4("5 g",{20.0f,30.0f});
		b3 -= b4;
		CHECK(to_string(b3) == "10 N 20° 30°");
		vector_unit_nd c("10 N",{20.0f,30.0f});
		vector_unit_nd c2("5 N",{20.0f,30.0f});
		CHECK(to_string(c + c2) == "14.99 N 20° 30°");
		vector_unit_nd c_2("10 N",vector<float>{20.0f});
		vector_unit_nd c2_2("5 N",vector<float>{20.0f});
		CHECK(to_string(c_2 + c2_2) == "14.99 N 20°");
		vector_unit_nd c_3("10 N");
		vector_unit_nd c2_3("5 N");
		CHECK(to_string(c_3 + c2_3) == "15 N");
		vector_unit_nd c_4("10 N",{20.0f,30.0f,15.0f});
		vector_unit_nd c2_4("5 N",{20.0f,30.0f,15.0f});
		CHECK(to_string(c_4 + c2_4) == "0 [empty]");
		vector_unit_nd c3("10 N",{20.0f,30.0f});
		vector_unit_nd c4("5 g",{20.0f,30.0f});
		CHECK(to_string(c3 + c4) == "0 [empty]");
		vector_unit_nd d("10 N",{20.0f,30.0f});
		vector_unit_nd d2("5 N",{20.0f,30.0f});
		CHECK(to_string(d - d2) == "4.99 N 20° 30°");
		vector_unit_nd d_2("10 N",vector<float>{20.0f});
		vector_unit_nd d2_2("5 N",vector<float>{20.0f});
		CHECK(to_string(d_2 - d2_2) == "5 N 20°");
		vector_unit_nd d_3("10 N");
		vector_unit_nd d2_3("5 N");
		CHECK(to_string(d_3 - d2_3) == "5 N");
		vector_unit_nd d_4("10 N",{20.0f,30.0f,15.0f});
		vector_unit_nd d2_4("5 N",{20.0f,30.0f,15.0f});
		CHECK(to_string(d_4 - d2_4) == "0 [empty]");
		vector_unit_nd d3("10 N",{20.0f,30.0f});
		vector_unit_nd d4("5 g",{20.0f,30.0f});
		CHECK(to_string(d3 - d4) == "0 [empty]");
	}

	SECTION("Operators of vector_unit_nd class with scalar_unit class")
	{
		vector_unit_nd a("10 N",{10.0f,10.0f});
		scalar_unit a2("5 g");
		CHECK(to_string(a * a2) == "50 g*kg*m/s2 10° 10°");
		vector_unit_nd a_2("10 N",vector<float>{10.0f});
		CHECK(to_string(a_2 * a2) == "50 g*kg*m/s2 10°");
		vector_unit_nd a_3("10 N");
		CHECK(to_string(a_3 * a2) == "50 g*kg*m/s2");
		vector_unit_nd a_4("10 N",{10.0f,10.0f,20.0f});
		CHECK(to_string(a_4 * a2) == "50 g*kg*m/s2 10° 10° 20°");
		vector_unit_nd a3 = (a * a2);
		a3.change_dimensions("N*g");
		CHECK(to_string(a3) == "50 N*g 10° 10°");
		CHECK(to_string(a2 * a) == "50 g*kg*m/s2 10° 10°");
		CHECK(to_string(a2 * a_2) == "50 g*kg*m/s2 10°");
		CHECK(to_string(a2 * a_3) == "50 g*kg*m/s2");
		CHECK(to_string(a2 * a_4) == "50 g*kg*m/s2 10° 10° 20°");
		vector_unit_nd b("10 N",{10.0f,10.0f});
		scalar_unit b2("5 g");
		CHECK(to_string(b / b2) == "2000 m/s2 10° 10°");
		vector_unit_nd b_2("10 N",vector<float>{10.0f});
		CHECK(to_string(b_2 / b2) == "2000 m/s2 10°");
		vector_unit_nd b_3("10 N");
		CHECK(to_string(b_3 / b2) == "2000 m/s2");
		vector_unit_nd b_4("10 N",{10.0f,10.0f,20.0f});
		CHECK(to_string(b_4 / b2) == "2000 m/s2 10° 10° 20°");
		vector_unit_nd c("10 N",{10.0f,10.0f});
		scalar_unit c2(10_N / 5_N);
		CHECK(to_string(c ^ c2) == "100 N2 10° 10°");
		vector_unit_nd c_2("10 N",vector<float>{10.0f});
		CHECK(to_string(c_2 ^ c2) == "100 N2 10°");
		vector_unit_nd c_3("10 N");
		CHECK(to_string(c_3 ^ c2) == "100 N2");
		vector_unit_nd c_4("10 N",{10.0f,10.0f,20.0f});
		CHECK(to_string(c_4 ^ c2) == "100 N2 10° 10° 20°");
		vector_unit_nd c3("10 N",{10.0f,10.0f});
		scalar_unit c4(10_N);
		CHECK(to_string(c3 ^ c4) == "0 [empty]");
	}

	SECTION("Numeric operators of vector_unit_nd class")
	{
		vector_unit_nd a("10 N",{20.0f,20.0f});
		CHECK(to_string(a + 10.0f) == "20 N 20° 20°");
		CHECK(to_string(10.0f + a) == "20 N 20° 20°");
		vector_unit_nd b("10 N",{20.0f,20.0f});
		CHECK(to_string(b - 5.0f) == "5 N 20° 20°");
		CHECK(to_string(20.0f - b) == "10 N 20° 20°");
		vector_unit_nd c("10 N",{20.0f,20.0f});
		CHECK(to_string(c * 2.0f) == "20 N 20° 20°");
		CHECK(to_string(2.0f * c) == "20 N 20° 20°");
		vector_unit_nd d("10 N",{20.0f,20.0f});
		CHECK(to_string(d / 2.0f) == "5 N 20° 20°");
		CHECK(to_string(20.0f / d) == "2 1/N 20° 20°");
		vector_unit_nd e("10 N",{20.0f,20.0f});
		CHECK(to_string(e ^ 2) == "100 N2 20° 20°");
		vector_unit_nd f("10 N",{20.0f,20.0f});
		f += 5.0f;
		CHECK(to_string(f) == "15 N 20° 20°");
		vector_unit_nd g("10 N",{20.0f,20.0f});
		g -= 5.0f;
		CHECK(to_string(g) == "5 N 20° 20°");
		vector_unit_nd h("10 N",{20.0f,20.0f});
		h *= 2.0f;
		CHECK(to_string(h) == "20 N 20° 20°");
		vector_unit_nd i("10 N",{20.0f,20.0f});
		i *= -2.0f;
		CHECK(to_string(i) == "20 N 200° 160°");
		vector_unit_nd j("10 N",{20.0f,20.0f});
		j /= 2.0f;
		CHECK(to_string(j) == "5 N 20° 20°");
		vector_unit_nd k("10 N",{20.0f,20.0f});
		k /= -2.0f;
		CHECK(to_string(k) == "5 N 200° 160°");
	}

	SECTION("Projections of vector_unit_nd class")
	{
		vector_unit_nd a("2 N",{10.0f,10.0f});
		CHECK(a.x_projection().display(2) == "0.34 N");
		CHECK(a.y_projection().display(2) == "0.06 N");
		CHECK(a.z_projection().display(2) == "1.96 N");
		CHECK(a.n_projection(1).display(2) == "0.34 N");
		CHECK(a.n_projection(2).display(2) == "0.06 N");
		CHECK(a.n_projection(3).display(2) == "1.96 N");
		CHECK(a.n_projection(4).display(2) == "0 [empty]");
		vector_unit_nd b("2 N",vector<float>{10.0f});
		CHECK(b.x_projection().display(2) == "1.96 N");
		CHECK(b.y_projection().display(2) == "0.34 N");
		CHECK(b.z_projection().display(2) == "0 [empty]");
		vector_unit_nd c("2 N");
		CHECK(c.x_projection().display(2) == "2 N");
		CHECK(c.y_projection().display(2) == "0 [empty]");
		CHECK(c.z_projection().display(2) == "0 [empty]");
		vector_unit_nd d("2 N",{10.0f,10.0f,20.0f});
		CHECK(d.x_projection().display(2) == "0 [empty]");
		CHECK(d.y_projection().display(2) == "0 [empty]");
		CHECK(d.z_projection().display(2) == "0 [empty]");
	}

	SECTION("Invertion of vector_unit_nd class")
	{
		vector_unit_nd a("2 N",{10.0f,10.0f});
		a.invert();
		CHECK(to_string(a) == "2 N 190° 170°");
		vector_unit_nd b("2 N",vector<float>{10.0f});
		b.invert();
		CHECK(to_string(b) == "2 N 190°");
	}

	SECTION("Display of vector_unit_nd class")
	{
		vector_unit_nd a(1,"N",{20,20,20,20});
		CHECK(a.vectorial_display() == "1 N 20° 20° 20° 20°");
		CHECK(a.vectorial_base_display() == "1 kg*m/s2 20° 20° 20° 20°");
		CHECK(a.vectorial_custom_display("g*m/s2") == "1000 g*m/s2 20° 20° 20° 20°");
	}

	SECTION("Math functions of vector_unit_nd class")
	{
		vector_unit_nd a("2 N",{10.0f,10.0f});
		CHECK(bool(scifir::norm(a) == scalar_unit("2 N")));
		vector_unit_nd b("4 N2",{10.0f,10.0f});
		CHECK(bool(scifir::sqrt(b) == scalar_unit("2 N")));
		vector_unit_nd c("8 N3",{10.0f,10.0f});
		CHECK(bool(scifir::sqrt_nth(c,3) == scalar_unit("2 N")));
		vector_unit_nd d("2 N",{10.0f,10.0f});
		vector_unit_nd d2("1 m",{10.0f,10.0f});
		CHECK(bool(scifir::dot_product(d,d2).display() == scalar_unit("1.99 kg*m2/s2")));
		vector_unit_nd e("2 N",{10.0f,10.0f});
		vector_unit_nd e2("1 m",{10.0f,10.0f});
		CHECK(bool(scifir::cross_product(e,e2) == vector_unit_nd("0 kg*m2/s2 0° 0°")));
		vector_unit_nd e3("2 N",{10.0f,10.0f});
		vector_unit_nd e4("1 m",{100.0f,100.0f});
		CHECK(bool(scifir::cross_product(e3,e4).vectorial_display() == vector_unit_nd("1.97 kg*m2/s2 8.21° 80.00°")));
		vector_unit_nd e5("2 N",{10.0f,10.0f});
		vector_unit_nd e6("1 m",vector<float>{100.0f});
		CHECK(bool(scifir::cross_product(e5,e6).vectorial_display() == vector_unit_nd()));
		vector_unit_nd f("2 N",{10.0f,10.0f});
		vector_unit_nd f2("1 m",{20.0f,20.0f});
		CHECK(bool(scifir::angle_between(f,f2).display() == angle("10.29°")));
		vector_unit_nd g("2 N",{10.0f,10.0f});
		vector_unit_nd g2("1 m",{10.0f,10.0f});
		CHECK(scifir::same_nd(g,g2) == true);
		CHECK(scifir::same_direction(g,g2) == true);
		CHECK(scifir::parallel(g,g2) == true);
		vector_unit_nd g3("2 N",{10.0f,10.0f});
		vector_unit_nd g4("1 m",{10.0f,20.0f});
		CHECK(scifir::same_nd(g3,g4) == true);
		CHECK(scifir::same_direction(g3,g4) == false);
		CHECK(scifir::parallel(g3,g4) == false);
		vector_unit_nd g5("2 N",vector<float>{10.0f});
		vector_unit_nd g6("1 m",{10.0f,20.0f});
		CHECK(scifir::same_nd(g5,g6) == false);
		CHECK(scifir::same_direction(g5,g6) == false);
		CHECK(scifir::parallel(g5,g6) == false);
		CHECK(scifir::orthogonal(g5,g6) == false);
		vector_unit_nd g7("2 N",vector<float>{10.0f});
		vector_unit_nd g8("1 m",vector<float>{10.0f});
		vector_unit_nd g9("1 m",vector<float>{100.0f});
		CHECK(scifir::parallel(g7,g8) == true);
		CHECK(scifir::orthogonal(g7,g8) == false);
		CHECK(scifir::parallel(g7,g9) == false);
		CHECK(scifir::orthogonal(g7,g9) == true);
		vector_unit_nd h("2 N",{0.0f,0.0f});
		vector_unit_nd h2("1 m",{0.0f,90.0f});
		CHECK(scifir::orthogonal(h,h2) == true);
		vector_unit_nd i("2 N");
		vector_unit_nd i2("1 m");
		CHECK(scifir::parallel(i,i2) == true);
		CHECK(scifir::orthogonal(i,i2) == false);
	}

	SECTION("Comparison operators of vector_unit_nd class")
	{
		vector_unit_nd a("2 N",{10.0f,10.0f});
		vector_unit_nd a2("2 N",{10.0f,10.0f});
		CHECK(bool(a == a2));
		vector_unit_nd b("2 N",{10.0f,10.0f});
		vector_unit_nd b2("2 N",{20.0f,10.0f});
		CHECK(bool(b != b2));
	}

	SECTION("String operations with vector_unit_nd class")
	{
		vector_unit_nd a("2 N",{10.0f,10.0f});
		CHECK(bool(a == "2 N 10° 10°"));
		CHECK(bool(a != "3 N 10° 10°"));
		CHECK(bool("2 N 10° 10°" == a));
		CHECK(bool("3 N 10° 10°" != a));
		vector_unit_nd b("2 N",{10.0f,10.0f});
		string b2 = "b: ";
		b2 += b;
		CHECK("b: 2 N 10° 10°");
		vector_unit_nd c("2 N",{10.0f,10.0f});
		CHECK(("b: " + c) == "b: 2 N 10° 10°");
		CHECK((c + " b") == "2 N 10° 10° b");
	}

	SECTION("Stream operators of vector_unit_nd class")
    {
        ostringstream a;
        a << vector_unit_nd("2 N",{10.0f,10.0f});
        CHECK(a.str() == "2 N 10° 10°");
        stringstream b;
        b << "3 N 10° 10°";
        vector_unit_nd b2("1 N",{angle(5.0f),angle(2.0f)});
        b >> b2;
        CHECK(bool(b2 == "3 N 10° 10°"));
    }
}

