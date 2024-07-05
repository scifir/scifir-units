#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../topology/point_2d.hpp"
#include "../../topology/point_2d_impl.hpp"
#include "../../coordinates/coordinates_2d.hpp"
#include "../../util/types.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class point_2d<T> and point_2d<float>")
{
	SECTION("Constructors of point_2d<> class")
	{
		point_2d<> a;
		CHECK(to_string(a) == "(0 m,0 m)");
		point_2d<> a2(5_m,5_m);
		point_2d<> a3(a2);
		CHECK(to_string(a3) == "(5 m,5 m)");
		point_2d<> a4(5_m,5_m);
		point_2d<> a5(std::move(a4));
		CHECK(to_string(a3) == "(5 m,5 m)");
		point_2d<> b(100_m,10_m);
		CHECK(to_string(b) == "(100 m,10 m)");
		point_2d<> b2(100_m,angle(90.0f));
		CHECK(to_string(b2) == "(0 m,100 m)");
		coordinates_2d<> c2(100_m,1_m);
		point_2d<> c(c2);
		CHECK(to_string(c) == "(100 m,1 m)");
		coordinates_2d<> c4(100_m,1_m);
		point_2d<> c3(std::move(c4));
		CHECK(to_string(c3) == "(100 m,1 m)");
		point_2d<> d("(1 m,5 m)");
		CHECK(to_string(d) == "(1 m,5 m)");
		point_2d<> e("1 m,5 m");
		CHECK(to_string(e) == "(1 m,5 m)");
		point_2d<> f("100 m,90\u00B0");
		CHECK(to_string(f) == "(0 m,100 m)");
	}

	SECTION("Constructors of point_2d<float> class")
	{
		point_2d<float> a;
		CHECK(to_string(a) == "(0,0)");
		point_2d<float> a2(5,5);
		point_2d<float> a3(a2);
		CHECK(to_string(a3) == "(5,5)");
		point_2d<float> a4(5,5);
		point_2d<float> a5(std::move(a4));
		CHECK(to_string(a3) == "(5,5)");
		point_2d<float> b(100,10);
		CHECK(to_string(b) == "(100,10)");
		point_2d<float> b2(100,angle(90.0f));
		CHECK(to_string(b2) == "(0,100)");
		coordinates_2d<float> c2(100,1);
		point_2d<float> c(c2);
		CHECK(to_string(c) == "(100,1)");
		coordinates_2d<float> c4(100,1);
		point_2d<float> c3(std::move(c4));
		CHECK(to_string(c3) == "(100,1)");
		point_2d<float> d("(1,5)");
		CHECK(to_string(d) == "(1,5)");
		point_2d<float> e("1,5");
		CHECK(to_string(e) == "(1,5)");
		point_2d<float> f("100,90\u00B0");
		CHECK(to_string(f) == "(0,100)");
	}

	SECTION("Assignments of point_2d<> class")
	{
		point_2d<> a(10_m,5_m);
		point_2d<> b(20_m,8_m);
		a = b;
		CHECK(to_string(a) == "(20 m,8 m)");
		point_2d<> c(10_m,3_m);
		point_2d<> d(30_m,4_m);
		c = std::move(d);
		CHECK(to_string(c) == "(30 m,4 m)");
		point_2d<> e(10_m,6_m);
		coordinates_2d<> f(15_m,2_m);
		e = f;
		CHECK(to_string(e) == "(15 m,2 m)");
		point_2d<> e2(10_m,6_m);
		coordinates_2d<> f2(15_m,2_m);
		e2 = std::move(f2);
		CHECK(to_string(e2) == "(15 m,2 m)");
		point_2d<> g;
		g = "(1 m,5 m)";
		CHECK(to_string(g) == "(1 m,5 m)");
		point_2d<> h;
		h = "1 m,5 m";
		CHECK(to_string(h) == "(1 m,5 m)");
		point_2d<> i;
		i = "100 m,90\u00B0";
		CHECK(to_string(i) == "(0 m,100 m)");
	}

	SECTION("Assignments of point_2d<float> class")
	{
		point_2d<float> a(10,5);
		point_2d<float> b(20,8);
		a = b;
		CHECK(to_string(a) == "(20,8)");
		point_2d<float> c(10,3);
		point_2d<float> d(30,4);
		c = std::move(d);
		CHECK(to_string(c) == "(30,4)");
		point_2d<float> e(10,6);
		coordinates_2d<float> f(15,2);
		e = f;
		CHECK(to_string(e) == "(15,2)");
		point_2d<float> e2(10,6);
		coordinates_2d<float> f2(15,2);
		e2 = std::move(f2);
		CHECK(to_string(e2) == "(15,2)");
		point_2d<float> g;
		g = "(1,5)";
		CHECK(to_string(g) == "(1,5)");
		point_2d<float> h;
		h = "1,5";
		CHECK(to_string(h) == "(1,5)");
		point_2d<float> i;
		i = "100,90\u00B0";
		CHECK(to_string(i) == "(0,100)");
	}

	SECTION("Polar coordinates of point_2d<> class")
	{
		point_2d<> a(5_m,angle(20.0f));
		CHECK(bool(a.get_p() == 5_m));
		CHECK(bool(a.get_theta() == angle(20.0f)));
	}

	SECTION("Polar coordinates of point_2d<float> class")
	{
		point_2d<float> a(5,angle(20.0f));
		CHECK(a.get_p() == 5);
		CHECK(bool(a.get_theta() == angle(20.0f)));
	}

	SECTION("move(), set_position() and distance_to_origin() of point_2d<> class")
	{
		point_2d<> a(5_m,1_m);
		a.set_position(20_m,7_m);
		CHECK(to_string(a) == "(20 m,7 m)");
		a.set_position(10_m,angle(45.0f));
		CHECK(to_string(a) == "(7.07 m,7.07 m)");
		point_2d<> b(10_m,4_m);
		b.move(35_m,10_m);
		CHECK(to_string(b) == "(45 m,14 m)");
		b.move(10_m,angle(30.0f));
		CHECK(to_string(b) == "(53.66 m,19 m)");
		displacement_2d x(20_m,angle(40.0f));
		b.move(x);
		CHECK(to_string(b) == "(68.98 m,31.85 m)");
		point_2d<> c(5_m,6_m);
		length d = c.distance_to_origin();
		CHECK(to_string(d) == "7.81 m");
		point_2d e(20_m,angle(60.0f));
		e.rotate(angle(15.0f));
		CHECK(to_string(e) == "(5.17 m,19.31 m)");
		e.rotate(angle(15.0f));
		CHECK(to_string(e) == "(0 m,20 m)");
	}

	SECTION("move(), set_position() and distance_to_origin() of point_2d<float> class")
	{
		point_2d<float> a(5,1);
		a.set_position(20,7);
		CHECK(to_string(a) == "(20,7)");
		a.set_position(10,angle(45.0f));
		CHECK(to_string(a) == "(7.07,7.07)");
		point_2d<float> b(10,4);
		b.move(35,10);
		CHECK(to_string(b) == "(45,14)");
		b.move(10,angle(30.0f));
		CHECK(to_string(b) == "(53.66,19)");
		displacement_2d x(20_m,angle(40.0f));
		b.move(x);
		CHECK(to_string(b) == "(68.98,31.85)");
		point_2d<float> c(5,6);
		float d = c.distance_to_origin();
		CHECK(display_float(d,2) == "7.81");
		point_2d<float> e(20,angle(60.0f));
		e.rotate(angle(15.0f));
		CHECK(to_string(e) == "(5.17,19.31)");
		e.rotate(angle(15.0f));
		CHECK(to_string(e) == "(0,20)");
	}

	SECTION("display of point_2d<> class")
	{
		point_2d<> a(2_m,3_m);
		CHECK(a.display_cartesian() == "(2 m,3 m)");
		point_2d<> b(2_m,angle(45.0f));
		CHECK(b.display_polar() == "(1.99 m,45\u00B0)");
	}

	SECTION("display of point_2d<float> class")
	{
		point_2d<float> a(2.0f,3.0f);
		CHECK(a.display_cartesian() == "(2,3)");
		point_2d<float> b(2.0f,angle(45.0f));
		CHECK(b.display_polar() == "(2,45\u00B0)");
	}

	SECTION("distance() functions of point_2d<> class")
	{
		point_2d<> a(10_m,10_m);
		point_2d<> b(15_m,10_m);
		CHECK(to_string(distance(a,b)) == "5 m");
		point_2d<> c(20_m,15_m);
		coordinates_2d<> d(35_m,10_m);
		CHECK(to_string(distance(c,d)) == "15.81 m");
		CHECK(to_string(distance(d,c)) == "15.81 m");
	}

	SECTION("distance() functions of point_2d<float> class")
	{
		point_2d<float> a(10,10);
		point_2d<float> b(15,10);
		CHECK(display_float(distance(a,b),2) == "5");
		point_2d<float> c(20,15);
		coordinates_2d<float> d(35,10);
		CHECK(display_float(distance(c,d),2) == "15.81");
		CHECK(display_float(distance(d,c),2) == "15.81");
	}

	SECTION("Relational operators of point_2d<> class")
	{
		point_2d<> a(7_m,3_m);
		point_2d<> b(7_m,3_m);
		point_2d<> c(6_m,2_m);
		CHECK(bool(a == b));
		CHECK((a == c) == false);
		CHECK(bool(a != c));
		coordinates_2d<> d(7_m,3_m);
		coordinates_2d<> e(5_m,1_m);
		CHECK(bool(a == d));
		CHECK(bool(a != e));
		CHECK(bool(d == a));
		CHECK(bool(e != a));
	}

	SECTION("Relational operators of point_2d<float> class")
	{
		point_2d<float> a(7,3);
		point_2d<float> b(7,3);
		point_2d<float> c(6,2);
		CHECK(bool(a == b));
		CHECK((a == c) == false);
		CHECK(bool(a != c));
		coordinates_2d<float> d(7,3);
		coordinates_2d<float> e(5,1);
		CHECK(bool(a == d));
		CHECK(bool(a != e));
		CHECK(bool(d == a));
		CHECK(bool(e != a));
	}

	SECTION("String operators of point_2d<> class")
	{
		point_2d<> a(7_m,4_m);
		CHECK(bool(a == "(7 m,4 m)"));
		CHECK(bool(a != "(6 m,3 m)"));
		CHECK(bool("(7 m,4 m)" == a));
		CHECK(bool("(6 m,3 m)" != a));
		string b = "x: ";
		b += a;
		CHECK(b == "x: (7 m,4 m)");
		CHECK(("x: " + a) == "x: (7 m,4 m)");
		CHECK("x: (7 m,4 m)" == ("x: " + a));
	}

	SECTION("String operators of point_2d<float> class")
	{
		point_2d<float> a(7,4);
		CHECK(bool(a == "(7,4)"));
		CHECK(bool(a != "(6,3)"));
		CHECK(bool("(7,4)" == a));
		CHECK(bool("(6,3)" != a));
		string b = "x: ";
		b += a;
		CHECK(b == "x: (7,4)");
		CHECK(("x: " + a) == "x: (7,4)");
		CHECK("x: (7,4)" == ("x: " + a));
	}

	SECTION("Display of point_2d<> class")
	{
		point_2d<> a(2_m,3_m);
		ostringstream out;
		out << a;
		CHECK(out.str() == "(2 m,3 m)");
		istringstream iss("(1 m,2 m)");
		point_2d b;
		iss >> b;
		CHECK(to_string(b) == "(1 m,2 m)");
	}

	SECTION("Display of point_2d<float> class")
	{
		point_2d<float> a(2,3);
		ostringstream out;
		out << a;
		CHECK(out.str() == "(2,3)");
		istringstream iss("(1,2)");
		point_2d<float> b;
		iss >> b;
		CHECK(to_string(b) == "(1,2)");
	}
}
