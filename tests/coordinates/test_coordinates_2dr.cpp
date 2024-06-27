#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../coordinates/coordinates_2dr.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class coordinates_2dr","Complete test of coordinates_2dr")
{
	SECTION("Constructors of coordinates_2dr<> class")
	{
		coordinates_2dr<> a;
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
		REQUIRE (bool(to_string(b2) == "(0 m,100 m;0\u00B0)"));
		point_2d<> c2(100_m,1_m);
		coordinates_2dr<> c(c2,angle(0));
		REQUIRE (bool(to_string(c) == "(100 m,1 m;0\u00B0)"));
		point_2d<> c3(100_m,1_m);
		coordinates_2dr<> c4(std::move(c3),angle(0));
		REQUIRE (bool(to_string(c4) == "(100 m,1 m;0\u00B0)"));
		coordinates_2d<> c5(100_m,1_m);
		coordinates_2dr<> c6(c5,angle(0));
		REQUIRE (bool(to_string(c6) == "(100 m,1 m;0\u00B0)"));
		coordinates_2d<> c7(100_m,1_m);
		coordinates_2dr<> c8(std::move(c7),angle(0));
		REQUIRE (bool(to_string(c8) == "(100 m,1 m;0\u00B0)"));
		coordinates_2dr<> d("(1 m,5 m;0\u00B0)");
		REQUIRE (bool(to_string(d) == "(1 m,5 m;0\u00B0)"));
		coordinates_2dr<> e("100 m,90\u00B0;0\u00B0");
		REQUIRE (bool(to_string(e) == "(0 m,100 m;0\u00B0)"));
	}

	SECTION("Constructors of coordinates_2dr<float> class")
	{
		coordinates_2dr<float> a;
		REQUIRE (bool(to_string(a) == "(0,0;0\u00B0)"));
		coordinates_2dr<float> a2(5,5,angle(40.0f));
		coordinates_2dr<float> a3(a2);
		REQUIRE (bool(to_string(a3) == "(5,5;40\u00B0)"));
		coordinates_2dr<float> a4(5,5,angle(40.0f));
		coordinates_2dr<float> a5(move(a4));
		REQUIRE (bool(to_string(a3) == "(5,5;40\u00B0)"));
		coordinates_2dr<float> b(100,10,angle(40.0f));
		REQUIRE (bool(to_string(b) == "(100,10;40\u00B0)"));
		coordinates_2dr<float> b2(100,angle(90.0f),angle(40.0f));
		REQUIRE (bool(to_string(b2) == "(0,100;40\u00B0)"));
		point_2d<float> c2(100,1);
		coordinates_2dr<float> c(c2,angle(40.0f));
		REQUIRE (bool(to_string(c) == "(100,1;40\u00B0)"));
		point_2d<float> c4(100,1);
		coordinates_2dr<float> c3(std::move(c4),angle(40.0f));
		REQUIRE (bool(to_string(c3) == "(100,1;40\u00B0)"));
		coordinates_2d<float> c6(100,1);
		coordinates_2dr<float> c5(c6,angle(40.0f));
		REQUIRE (bool(to_string(c5) == "(100,1;40\u00B0)"));
		coordinates_2d<float> c8(100,1);
		coordinates_2dr<float> c7(std::move(c8),angle(40.0f));
		REQUIRE (bool(to_string(c7) == "(100,1;40\u00B0)"));
		coordinates_2dr<float> d("(1,5;40\u00B0)");
		REQUIRE (bool(to_string(d) == "(1,5;40\u00B0)"));
		coordinates_2dr<float> e("1,5;40\u00B0");
		REQUIRE (bool(to_string(e) == "(1,5;40\u00B0)"));
		coordinates_2dr<float> f("100,90\u00B0;40\u00B0");
		REQUIRE (bool(to_string(f) == "(0,100;40\u00B0)"));
	}

	SECTION("Assignments of coordinates_2dr<> class")
	{
		coordinates_2dr<> a(10_m,5_m,angle(40.0f));
		coordinates_2dr<> b(20_m,8_m,angle(40.0f));
		a = b;
		REQUIRE (bool(to_string(a) == "(20 m,8 m;40\u00B0)"));
		coordinates_2dr<> c(10_m,3_m,angle(40.0f));
		coordinates_2dr<> d(30_m,4_m,angle(40.0f));
		c = move(d);
		REQUIRE (bool(to_string(c) == "(30 m,4 m;40\u00B0)"));
		coordinates_2dr<> e(10_m,6_m,angle(40.0f));
		point_2d<> f(15_m,2_m);
		e = f;
		REQUIRE (bool(to_string(e) == "(15 m,2 m;40\u00B0)"));
		coordinates_2dr<> e2(10_m,6_m,angle(40.0f));
		point_2d<> f2(15_m,2_m);
		e2 = std::move(f2);
		REQUIRE (bool(to_string(e2) == "(15 m,2 m;40\u00B0)"));
		coordinates_2dr<> g(10_m,6_m,angle(40.0f));
		coordinates_2d<> h(15_m,2_m);
		g = h;
		REQUIRE (bool(to_string(g) == "(15 m,2 m;40\u00B0)"));
		coordinates_2dr<> g2(10_m,6_m,angle(40.0f));
		coordinates_2d<> h2(15_m,2_m);
		g2 = std::move(h2);
		REQUIRE (bool(to_string(g2) == "(15 m,2 m;40\u00B0)"));
		coordinates_2dr<> i;
		i = "(1 m,5 m;0\u00B0)";
		REQUIRE (bool(to_string(i) == "(1 m,5 m;0\u00B0)"));
		coordinates_2dr<> j;
		j = "100 m,90\u00B0;0\u00B0";
		REQUIRE (bool(to_string(j) == "(0 m,100 m;0\u00B0)"));
	}

	SECTION("Assignments of coordinates_2dr<float> class")
	{
		coordinates_2dr<float> a(10,5,angle(40.0f));
		coordinates_2dr<float> b(20,8,angle(40.0f));
		a = b;
		REQUIRE (bool(to_string(a) == "(20,8;40\u00B0)"));
		coordinates_2dr<float> c(10,3,angle(40.0f));
		coordinates_2dr<float> d(30,4,angle(40.0f));
		c = move(d);
		REQUIRE (bool(to_string(c) == "(30,4;40\u00B0)"));
		coordinates_2dr<float> e(10,6,angle(40.0f));
		point_2d<float> f(15,2);
		e = f;
		REQUIRE (bool(to_string(e) == "(15,2;40\u00B0)"));
		coordinates_2dr<float> e2(10,6,angle(40.0f));
		point_2d<float> f2(15,2);
		e2 = std::move(f2);
		REQUIRE (bool(to_string(e2) == "(15,2;40\u00B0)"));
		coordinates_2dr<float> g(10,6,angle(40.0f));
		coordinates_2d<float> h(15,2);
		g = h;
		REQUIRE (bool(to_string(g) == "(15,2;40\u00B0)"));
		coordinates_2dr<float> g2(10,6,angle(40.0f));
		coordinates_2d<float> h2(15,2);
		g2 = std::move(h2);
		REQUIRE (bool(to_string(g2) == "(15,2;40\u00B0)"));
		coordinates_2dr<float> i;
		i = "(1,5;0\u00B0)";
		REQUIRE (bool(to_string(i) == "(1,5;0\u00B0)"));
		coordinates_2dr<float> j;
		j = "100,90\u00B0;0\u00B0";
		REQUIRE (bool(to_string(j) == "(0,100;0\u00B0)"));
	}

	SECTION("Polar coordinates of coordinates_2dr<> class")
	{
		coordinates_2dr a(5_m,angle(20.0f),angle(40.0f));
		REQUIRE(bool(a.get_p() == 5_m));
		REQUIRE(bool(a.get_polar_theta() == angle(20.0f)));
	}

	SECTION("Polar coordinates of coordinates_2dr<float> class")
	{
		coordinates_2dr<float> a(5,angle(20.0f),angle(40.0f));
		REQUIRE(bool(a.get_p() == 5));
		REQUIRE(bool(a.get_polar_theta() == angle(20.0f)));
	}

	SECTION("move(), set_position() and distance_to_origin() of coordinates_2dr<> class")
	{
		coordinates_2dr<> a(5_m,1_m,angle(40.0f));
		a.set_position(20_m,7_m);
		REQUIRE (bool(to_string(a) == "(20 m,7 m;40\u00B0)"));
		a.set_position(10_m,angle(45.0f));
		REQUIRE (bool(to_string(a) == "(7.07 m,7.07 m;40\u00B0)"));
		coordinates_2dr<> b(10_m,4_m,angle(40.0f));
		b.move(35_m,10_m);
		REQUIRE (bool(to_string(b) == "(45 m,14 m;40\u00B0)"));
		b.move(10_m,angle(30.0f));
		REQUIRE (bool(to_string(b) == "(53.66 m,19 m;40\u00B0)"));
		displacement_2d x(20_m,angle(40.0f));
		b.move(x);
		REQUIRE (bool(to_string(b) == "(68.98 m,31.85 m;40\u00B0)"));
		coordinates_2dr<> c(5_m,6_m,angle(40.0f));
		length d = c.distance_to_origin();
		REQUIRE (bool(to_string(d) == "7.81 m"));
		coordinates_2dr e(20_m,angle(60.0f),angle(40.0f));
		e.rotate(angle(15.0f));
		REQUIRE (bool(to_string(e) == "(5.17 m,19.31 m;40\u00B0)"));
		e.rotate(angle(15.0f));
		REQUIRE (bool(to_string(e) == "(0 m,20 m;40\u00B0)"));
	}

	SECTION("move(), set_position() and distance_to_origin() of coordinates_2dr<float> class")
	{
		coordinates_2dr<float> a(5,1,angle(40.0f));
		a.set_position(20,7);
		REQUIRE (bool(to_string(a) == "(20,7;40\u00B0)"));
		a.set_position(10,angle(45.0f));
		REQUIRE (bool(to_string(a) == "(7.07,7.07;40\u00B0)"));
		coordinates_2dr<float> b(10,4,angle(40.0f));
		b.move(35,10);
		REQUIRE (bool(to_string(b) == "(45,14;40\u00B0)"));
		b.move(10,angle(30.0f));
		REQUIRE (bool(to_string(b) == "(53.66,19;40\u00B0)"));
		displacement_2d x(20_m,angle(40.0f));
		b.move(x);
		REQUIRE (bool(to_string(b) == "(68.98,31.85;40\u00B0)"));
		coordinates_2dr<float> c(5,6,angle(40.0f));
		float d = c.distance_to_origin();
		REQUIRE (bool(display_float(d,2) == "7.81"));
		coordinates_2dr<float> e(20,angle(60.0f),angle(40.0f));
		e.rotate(angle(15.0f));
		REQUIRE (bool(to_string(e) == "(5.17,19.31;40\u00B0)"));
		e.rotate(angle(15.0f));
		REQUIRE (bool(to_string(e) == "(0,20;40\u00B0)"));
	}

	SECTION("display of coordinates_2dr<> class")
	{
		coordinates_2dr<> a(2_m,3_m,angle(40.0f));
		REQUIRE(bool(a.display_cartesian() == "(2 m,3 m;40\u00B0)"));
		coordinates_2dr<> b(2_m,angle(45.0f),angle(40.0f));
		REQUIRE(bool(b.display_polar() == "(1.99 m,45\u00B0;40\u00B0)"));
	}

	SECTION("display of coordinates_2dr<float> class")
	{
		coordinates_2dr<float> a(2.0f,3.0f,angle(40.0f));
		REQUIRE(bool(a.display_cartesian() == "(2,3;40\u00B0)"));
		coordinates_2dr<float> b(2.0f,angle(45.0f),angle(40.0f));
		REQUIRE(bool(b.display_polar() == "(2,45\u00B0;40\u00B0)"));
	}

	SECTION("distance() functions of coordinates_2dr<> class")
	{
		coordinates_2dr<> a(10_m,10_m,angle(40.0f));
		coordinates_2dr<> b(15_m,10_m,angle(40.0f));
		REQUIRE (bool(to_string(distance(a,b)) == "5 m"));
		coordinates_2dr<> c(20_m,15_m,angle(40.0f));
		point_2d<> d(35_m,10_m);
		REQUIRE (bool(to_string(distance(c,d)) == "15.81 m"));
		REQUIRE (bool(to_string(distance(d,c)) == "15.81 m"));
		coordinates_2dr<> e(20_m,15_m,angle(40.0f));
		coordinates_2d<> f(35_m,10_m);
		REQUIRE (bool(to_string(distance(e,f)) == "15.81 m"));
		REQUIRE (bool(to_string(distance(f,e)) == "15.81 m"));
	}

	SECTION("distance() functions of coordinates_2dr<float> class")
	{
		coordinates_2dr<float> a(10,10,angle(40.0f));
		coordinates_2dr<float> b(15,10,angle(40.0f));
		REQUIRE (bool(display_float(distance(a,b),2) == "5"));
		coordinates_2dr<float> c(20,15,angle(40.0f));
		point_2d<float> d(35,10);
		REQUIRE (bool(display_float(distance(c,d),2) == "15.81"));
		REQUIRE (bool(display_float(distance(d,c),2) == "15.81"));
		coordinates_2dr<float> e(20,15,angle(40.0f));
		coordinates_2d<float> f(35,10);
		REQUIRE (bool(display_float(distance(e,f),2) == "15.81"));
		REQUIRE (bool(display_float(distance(f,e),2) == "15.81"));
	}

	SECTION("Relational operators of coordinates_2dr<> class")
	{
		coordinates_2dr a(7_m,3_m,angle(40.0f));
		coordinates_2dr b(7_m,3_m,angle(40.0f));
		coordinates_2dr c(6_m,2_m,angle(40.0f));
		REQUIRE(bool(a == b));
		REQUIRE(bool((a == c) == false));
		REQUIRE(bool(a != c));
		point_2d d(7_m,3_m);
		point_2d e(5_m,1_m);
		REQUIRE(bool(a == d));
		REQUIRE(bool(a != e));
		REQUIRE(bool(d == a));
		REQUIRE(bool(e != a));
	}

	SECTION("Relational operators of coordinates_2dr<float> class")
	{
		coordinates_2dr<float> a(7,3,angle(40.0f));
		coordinates_2dr<float> b(7,3,angle(40.0f));
		coordinates_2dr<float> c(6,2,angle(40.0f));
		REQUIRE(bool(a == b));
		REQUIRE(bool((a == c) == false));
		REQUIRE(bool(a != c));
		point_2d<float> d(7,3);
		point_2d<float> e(5,1);
		REQUIRE(bool(a == d));
		REQUIRE(bool(a != e));
		REQUIRE(bool(d == a));
		REQUIRE(bool(e != a));
	}

	SECTION("String operators of coordinates_2dr<> class")
	{
		coordinates_2dr a(7_m,4_m,angle(40.0f));
		REQUIRE(bool(a == "(7 m,4 m;40\u00B0)"));
		REQUIRE(bool(a != "(6 m,3 m;40\u00B0)"));
		REQUIRE(bool("(7 m,4 m;40\u00B0)" == a));
		REQUIRE(bool("(6 m,3 m;40\u00B0)" != a));
		string b = "x: ";
		b += a;
		REQUIRE(bool(b == "x: (7 m,4 m;40\u00B0)"));
		REQUIRE(bool(("x: " + a) == "x: (7 m,4 m;40\u00B0)"));
		REQUIRE(bool("x: (7 m,4 m;40\u00B0)" == ("x: " + a)));
	}

	SECTION("String operators of coordinates_2dr<float> class")
	{
		coordinates_2dr<float> a(7,4,angle(40.0f));
		REQUIRE(bool(a == "(7,4;40\u00B0)"));
		REQUIRE(bool(a != "(6,3;40\u00B0)"));
		REQUIRE(bool("(7,4;40\u00B0)" == a));
		REQUIRE(bool("(6,3;40\u00B0)" != a));
		string b = "x: ";
		b += a;
		REQUIRE(bool(b == "x: (7,4;40\u00B0)"));
		REQUIRE(bool(("x: " + a) == "x: (7,4;40\u00B0)"));
		REQUIRE(bool("x: (7,4;40\u00B0)" == ("x: " + a)));
	}

	SECTION("Display of coordinates_2dr<> class")
	{
		coordinates_2dr a(2_m,3_m,angle(40.0f));
		ostringstream out;
		out << a;
		REQUIRE(bool(out.str() == "(2 m,3 m;40\u00B0)"));
		istringstream iss("(1 m,2 m;40\u00B0)");
		coordinates_2dr b;
		iss >> b;
		REQUIRE(bool(to_string(b) == "(1 m,2 m;40\u00B0)"));
	}

	SECTION("Display of coordinates_2dr<float> class")
	{
		coordinates_2dr<float> a(2,3,angle(40.0f));
		ostringstream out;
		out << a;
		REQUIRE(bool(out.str() == "(2,3;40\u00B0)"));
		istringstream iss("(1,2;40\u00B0)");
		coordinates_2dr<float> b;
		iss >> b;
		REQUIRE(bool(to_string(b) == "(1,2;40\u00B0)"));
	}
}

