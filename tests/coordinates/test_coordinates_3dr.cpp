#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../coordinates/coordinates_3dr.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class coordinates_3dr<T>","Complete test of coordinates_3dr")
{
	SECTION("Constructors of coordinates_3dr<> classes")
	{
		coordinates_3dr<> a;
		REQUIRE (bool(to_string(a) == "(0 m,0 m,0 m;0\u00B0,0\u00B0)"));
		coordinates_3dr<> a2(5_m,5_m,1_m,angle(0),angle(0));
		coordinates_3dr<> a3(a2);
		REQUIRE (bool(to_string(a3) == "(5 m,5 m,1 m;0\u00B0,0\u00B0)"));
		coordinates_3dr<> a4(5_m,5_m,1_m,angle(0),angle(0));
		coordinates_3dr<> a5(move(a4));
		REQUIRE (bool(to_string(a3) == "(5 m,5 m,1 m;0\u00B0,0\u00B0)"));
		coordinates_3dr<> b(100_m,10_m,1_m,angle(0),angle(0));
		REQUIRE (bool(to_string(b) == "(100 m,10 m,1 m;0\u00B0,0\u00B0)"));
		coordinates_3dr<> b2(100_m,angle(90),1_m,angle(0),angle(0));
		REQUIRE (bool(to_string(b2) == "(0 m,100 m,1 m;0\u00B0,0\u00B0)"));
		coordinates_3dr<> b3(100_m,angle(0),angle(0),angle(0),angle(0));
		REQUIRE (bool(to_string(b3) == "(0 m,0 m,100 m;0\u00B0,0\u00B0)"));
		//coordinates_3dr<> b4(angle(0),angle(0),10_m);
		//REQUIRE (bool(to_string(b4) == "(0 m,0 m,100 m)"));
		point_3d<> c2(100_m,1_m,2_m);
		coordinates_3dr<> c(c2,angle(0),angle(0));
		REQUIRE (bool(to_string(c) == "(100 m,1 m,2 m;0\u00B0,0\u00B0)"));
		coordinates_3d<> c5(100_m,1_m,2_m);
		coordinates_3dr<> c6(c5,angle(0),angle(0));
		REQUIRE (bool(to_string(c6) == "(100 m,1 m,2 m;0\u00B0,0\u00B0)"));
		coordinates_3dr<> c3(100_m,1_m,2_m,angle(0),angle(0));
		coordinates_3dr<> c4(c3);
		REQUIRE (bool(to_string(c) == "(100 m,1 m,2 m;0\u00B0,0\u00B0)"));
		coordinates_3dr<> d("(1 m,5 m,2 m;0\u00B0,0\u00B0)");
		REQUIRE (bool(to_string(d) == "(1 m,5 m,2 m;0\u00B0,0\u00B0)"));
		coordinates_3dr<> e("1 m,5 m,2 m;0\u00B0,0\u00B0");
		REQUIRE (bool(to_string(e) == "(1 m,5 m,2 m;0\u00B0,0\u00B0)"));
		coordinates_3dr<> f("2 m,45\u00B0,3 m;20\u00B0,40\u00B0");
		REQUIRE (bool(to_string(f) == "(1.41 m,1.41 m,3 m;20\u00B0,40\u00B0)"));
		coordinates_3dr<> g("2 m,45\u00B0,20\u00B0;20\u00B0,40\u00B0");
		REQUIRE (bool(to_string(g) == "(0.48 m,0.48 m,1.87 m;20\u00B0,40\u00B0)"));
	}

	SECTION("Constructors of coordinates_3dr<float> classes")
	{
		coordinates_3dr<float> a;
		REQUIRE (bool(to_string(a) == "(0,0,0;0\u00B0,0\u00B0)"));
		coordinates_3dr<float> a2(5.0f,5.0f,1.0f,angle(0),angle(0));
		coordinates_3dr<float> a3(a2);
		REQUIRE (bool(to_string(a3) == "(5,5,1;0\u00B0,0\u00B0)"));
		coordinates_3dr<float> a4(5.0f,5.0f,1.0f,angle(0),angle(0));
		coordinates_3dr<float> a5(move(a4));
		REQUIRE (bool(to_string(a3) == "(5,5,1;0\u00B0,0\u00B0)"));
		coordinates_3dr<float> b(100.0f,10.0f,1.0f,angle(0),angle(0));
		REQUIRE (bool(to_string(b) == "(100,10,1;0\u00B0,0\u00B0)"));
		coordinates_3dr<float> b2(100.0f,angle(90),1.0f,angle(0),angle(0));
		REQUIRE (bool(to_string(b2) == "(0,100,1;0\u00B0,0\u00B0)"));
		coordinates_3dr<float> b3(100.0f,angle(0),angle(0),angle(0),angle(0));
		REQUIRE (bool(to_string(b3) == "(0,0,100;0\u00B0,0\u00B0)"));
		//coordinates_3dr<float> b4(angle(0),angle(0),10_m);
		//REQUIRE (bool(to_string(b4) == "(0,0,100)"));
		point_3d<float> c2(100.0f,1.0f,2.0f);
		coordinates_3dr<float> c(c2,angle(0),angle(0));
		REQUIRE (bool(to_string(c) == "(100,1,2;0\u00B0,0\u00B0)"));
		coordinates_3d<float> c5(100.0f,1.0f,2.0f);
		coordinates_3dr<float> c6(c5,angle(0),angle(0));
		REQUIRE (bool(to_string(c6) == "(100,1,2;0\u00B0,0\u00B0)"));
		coordinates_3dr<float> c3(100.0f,1.0f,2.0f,angle(0),angle(0));
		coordinates_3dr<float> c4(c3);
		REQUIRE (bool(to_string(c) == "(100,1,2;0\u00B0,0\u00B0)"));
		coordinates_3dr<float> d("(1,5,2;0\u00B0,0\u00B0)");
		REQUIRE (bool(to_string(d) == "(1,5,2;0\u00B0,0\u00B0)"));
		coordinates_3dr<float> e("1,5,2;0\u00B0,0\u00B0");
		REQUIRE (bool(to_string(e) == "(1,5,2;0\u00B0,0\u00B0)"));
		coordinates_3dr<float> f("2,45\u00B0,3;20\u00B0,40\u00B0");
		REQUIRE (bool(to_string(f) == "(1.41,1.41,3;20\u00B0,40\u00B0)"));
		coordinates_3dr<float> g("2,45\u00B0,20\u00B0;20\u00B0,40\u00B0");
		REQUIRE (bool(to_string(g) == "(0.48,0.48,1.87;20\u00B0,40\u00B0)"));
	}

	SECTION("Assignments of coordinates_3dr<> classes")
	{
		coordinates_3dr<> a;
		coordinates_3dr<> a2(5_m,5_m,1_m,angle(20.0f),angle(30.0f));
		a = a2;
		REQUIRE (bool(to_string(a) == "(5 m,5 m,1 m;20\u00B0,30\u00B0)"));
		coordinates_3dr<> b;
		coordinates_3dr<> b2(5_m,5_m,1_m,angle(20.0f),angle(30.0f));
		b = std::move(b2);
		REQUIRE (bool(to_string(b) == "(5 m,5 m,1 m;20\u00B0,30\u00B0)"));
		coordinates_3dr<> c;
		point_3d<> c2(100_m,1_m,2_m);
		c = c2;
		REQUIRE (bool(to_string(c) == "(100 m,1 m,2 m;0\u00B0,0\u00B0)"));
		coordinates_3dr<> d;
		coordinates_3d<> d2(100_m,1_m,2_m);
		d = d2;
		REQUIRE (bool(to_string(d) == "(100 m,1 m,2 m;0\u00B0,0\u00B0)"));
	}

	SECTION("Assignments of coordinates_3dr<float> classes")
	{
		coordinates_3dr<float> a;
		coordinates_3dr<float> a2(5.0f,5.0f,1.0f,angle(20.0f),angle(30.0f));
		a = a2;
		REQUIRE (bool(to_string(a) == "(5,5,1;20\u00B0,30\u00B0)"));
		coordinates_3dr<float> b;
		coordinates_3dr<float> b2(5.0f,5.0f,1.0f,angle(20.0f),angle(30.0f));
		b = std::move(b2);
		REQUIRE (bool(to_string(b) == "(5,5,1;20\u00B0,30\u00B0)"));
		coordinates_3dr<float> c;
		point_3d<float> c2(100.0f,1.0f,2.0f);
		c = c2;
		REQUIRE (bool(to_string(c) == "(100,1,2;0\u00B0,0\u00B0)"));
		coordinates_3dr<float> d;
		point_3d<float> d2(100.0f,1.0f,2.0f);
		d = d2;
		REQUIRE (bool(to_string(d) == "(100,1,2;0\u00B0,0\u00B0)"));
	}

	SECTION("Values of different coordinates systems of coordinates_3dr<> classes")
	{
		coordinates_3dr<> c(7_m,4_m,2_m,angle(20.0f),angle(30.0f));
		REQUIRE (bool(c.get_p().display() == "8.06 m"));
		REQUIRE (bool(c.get_spherical_theta().display() == "29.74\u00B0"));
		REQUIRE (bool(c.get_r().display() == "8.3 m"));
		REQUIRE (bool(c.get_spherical_phi().display() == "76.06\u00B0"));
		/*REQUIRE (bool(c.get_latitude() == angle(0.0f)));
		REQUIRE (bool(c.get_longitude() == angle(29.74f)));
		REQUIRE (bool(c.get_altitude() == "0 m"));*/
	}

	SECTION("Values of different coordinates systems of coordinates_3dr<float> classes")
	{
		coordinates_3dr<float> c(7.0f,4.0f,2.0f,angle(20.0f),angle(30.0f));
		REQUIRE (bool(std::fabs(c.get_p() - 8.06f) < 0.01f));
		REQUIRE (bool(c.get_spherical_theta().display() == "29.74\u00B0"));
		REQUIRE (bool(std::fabs(c.get_r() - 8.3f) < 0.01f));
		REQUIRE (bool(c.get_spherical_phi().display() == "76.06\u00B0"));
		/*REQUIRE (bool(c.get_latitude() == angle(0.0f)));
		REQUIRE (bool(c.get_longitude() == angle(29.74f)));
		REQUIRE (bool(c.get_altitude() == "0 m"));*/
	}

	SECTION("set_position(), rotate() and move() of coordinates_3dr<> classes")
	{
		coordinates_3dr<> a;
		a.set_position(5_m,5_m,1_m);
		REQUIRE (bool(to_string(a) == "(5 m,5 m,1 m;0\u00B0,0\u00B0)"));
		a.set_position(5_m,angle(30.0f),1_m);
		REQUIRE (bool(to_string(a) == "(4.33 m,2.5 m,1 m;0\u00B0,0\u00B0)"));
		a.set_position(5_m,angle(30.0f),angle(45.0f));
		REQUIRE (bool(to_string(a) == "(3.06 m,1.76 m,3.53 m;0\u00B0,0\u00B0)"));
		/*a.set_position(angle(30.0f),angle(45.0f),100_m);
		cout << "geographical coordinates: " << to_string(a) << endl;
		REQUIRE (bool(to_string(a) == "(61.23 m,61.23 m,50 m)"));*/
		coordinates_3dr<> b(5_m,3_m,1_m,angle(20.0f),angle(30.0f));
		b.rotate_in_x(angle(45.0f));
		REQUIRE (bool(to_string(b) == "(5 m,1.41 m,2.82 m;20\u00B0,30\u00B0)"));
		coordinates_3dr<> c(7_m,4_m,2_m,angle(20.0f),angle(30.0f));
		c.rotate_in_y(angle(45.0f));
		REQUIRE (bool(to_string(c) == "(3.53 m,4 m,6.36 m;20\u00B0,30\u00B0)"));
		coordinates_3dr<> d(4_m,2_m,3_m,angle(20.0f),angle(30.0f));
		d.rotate_in_z(angle(45.0f));
		REQUIRE (bool(to_string(d) == "(1.41 m,4.24 m,3 m;20\u00B0,30\u00B0)"));
		coordinates_3dr<> e(1_m,2_m,3_m,angle(20.0f),angle(30.0f));
		displacement_3d e2(3_m,angle(0.0f),angle(0.0f));
		e.move(e2);
		REQUIRE (bool(to_string(e) == "(1 m,2 m,6 m;20\u00B0,30\u00B0)"));
		coordinates_3dr<> f(1_m,2_m,3_m,angle(20.0f),angle(30.0f));
		f.move(2_m,1_m,3_m);
		REQUIRE (bool(to_string(f) == "(3 m,3 m,6 m;20\u00B0,30\u00B0)"));
		coordinates_3dr<> g(1_m,2_m,3_m,angle(20.0f),angle(30.0f));
		g.move(2_m,angle(45.0f),3_m);
		REQUIRE (bool(to_string(g) == "(2.41 m,3.41 m,6 m;20\u00B0,30\u00B0)"));
		coordinates_3dr<> h(1_m,2_m,3_m,angle(20.0f),angle(30.0f));
		h.move(2_m,angle(0.0f),angle(45.0f));
		REQUIRE (bool(to_string(h) == "(2.41 m,2 m,4.41 m;20\u00B0,30\u00B0)"));
	}

	SECTION("set_position(), rotate() and move() of coordinates_3dr<float> classes")
	{
		coordinates_3dr<float> a;
		a.set_position(5.0f,5.0f,1.0f);
		REQUIRE (bool(to_string(a) == "(5,5,1;0\u00B0,0\u00B0)"));
		a.set_position(5.0f,angle(30.0f),1.0f);
		REQUIRE (bool(to_string(a) == "(4.33,2.5,1;0\u00B0,0\u00B0)"));
		a.set_position(5.0f,angle(30.0f),angle(45.0f));
		REQUIRE (bool(to_string(a) == "(3.06,1.76,3.53;0\u00B0,0\u00B0)"));
		/*a.set_position(angle(30.0f),angle(45.0f),100_m);
		cout << "geographical coordinates: " << to_string(a) << endl;
		REQUIRE (bool(to_string(a) == "(61.23 m,61.23 m,50 m)"));*/
		coordinates_3dr<float> b(5.0f,3.0f,1.0f,angle(20.0f),angle(30.0f));
		b.rotate_in_x(angle(45.0f));
		REQUIRE (bool(to_string(b) == "(5,1.41,2.82;20\u00B0,30\u00B0)"));
		coordinates_3dr<float> c(7.0f,4.0f,2.0f,angle(20.0f),angle(30.0f));
		c.rotate_in_y(angle(45.0f));
		REQUIRE (bool(to_string(c) == "(3.53,4,6.36;20\u00B0,30\u00B0)"));
		coordinates_3dr<float> d(4.0f,2.0f,3.0f,angle(20.0f),angle(30.0f));
		d.rotate_in_z(angle(45.0f));
		REQUIRE (bool(to_string(d) == "(1.41,4.24,3;20\u00B0,30\u00B0)"));
		coordinates_3dr<float> e(1.0f,2.0f,3.0f,angle(20.0f),angle(30.0f));
		displacement_3d e2(3_m,angle(0.0f),angle(0.0f));
		e.move(e2);
		REQUIRE (bool(to_string(e) == "(1,2,6;20\u00B0,30\u00B0)"));
		coordinates_3dr<float> f(1.0f,2.0f,3.0f,angle(20.0f),angle(30.0f));
		f.move(2.0f,1.0f,3.0f);
		REQUIRE (bool(to_string(f) == "(3,3,6;20\u00B0,30\u00B0)"));
		coordinates_3dr<float> g(1.0f,2.0f,3.0f,angle(20.0f),angle(30.0f));
		g.move(2.0f,angle(45.0f),3.0f);
		REQUIRE (bool(to_string(g) == "(2.41,3.41,6;20\u00B0,30\u00B0)"));
		coordinates_3dr<float> h(1.0f,2.0f,3.0f,angle(20.0f),angle(30.0f));
		h.move(2.0f,angle(0.0f),angle(45.0f));
		REQUIRE (bool(to_string(h) == "(2.41,2,4.41;20\u00B0,30\u00B0)"));
	}

	SECTION("Display of coordinates_3dr<> classes")
	{
		coordinates_3dr<> a(2_m,3_m,5_m,angle(20.0f),angle(30.0f));
		REQUIRE (bool(a.display_cylindrical() == "(3.6 m,56.3\u00B0,5 m;20\u00B0,30\u00B0)"));
		REQUIRE (bool(a.display_spherical() == "(6.16 m,56.3\u00B0,35.79\u00B0;20\u00B0,30\u00B0)"));
		/*coordinates_3dr<> b(2_m,3_m,10000_km);
		cout << "b display geographical: " << b.display_geographical() << endl;
		REQUIRE (bool(b.display_geographical() == ""));*/
	}

	SECTION("Display of coordinates_3dr<float> classes")
	{
		coordinates_3dr<float> a(2.0f,3.0f,5.0f,angle(20.0f),angle(30.0f));
		REQUIRE (bool(a.display_cylindrical() == "(3.6,56.3\u00B0,5;20\u00B0,30\u00B0)"));
		REQUIRE (bool(a.display_spherical() == "(6.16,56.3\u00B0,35.79\u00B0;20\u00B0,30\u00B0)"));
		/*coordinates_3dr<> b(2_m,3_m,10000_km);
		cout << "b display geographical: " << b.display_geographical() << endl;
		REQUIRE (bool(b.display_geographical() == ""));*/
	}

	SECTION("to_string() of coordinates_3dr<>")
	{
		coordinates_3dr<> a(2_m,3_m,5_m,angle(20.0f),angle(30.0f));
		REQUIRE (bool(to_string(a) == "(2 m,3 m,5 m;20\u00B0,30\u00B0)"));
	}

	SECTION("to_string() of coordinates_3dr<float>")
	{
		coordinates_3dr<float> a(2.0f,3.0f,5.0f,angle(20.0f),angle(30.0f));
		REQUIRE (bool(to_string(a) == "(2,3,5;20\u00B0,30\u00B0)"));
	}

	SECTION("distance() of coordinates_3dr<>")
	{
		coordinates_3dr<> a(7_m,3_m,1_m,angle(20.0f),angle(30.0f));
		coordinates_3dr<> b(6_m,2_m,1_m,angle(20.0f),angle(30.0f));
		REQUIRE (bool(distance(a,b).display() == "1.41 m"));
		point_3d<> c(7_m,3_m,1_m);
		REQUIRE (bool(distance(a,c).display() == "0 m"));
		REQUIRE (bool(distance(c,a).display() == "0 m"));
		REQUIRE (bool(distance(b,c).display() == "1.41 m"));
		REQUIRE (bool(distance(c,b).display() == "1.41 m"));
		coordinates_3d<> d(7_m,3_m,1_m);
		REQUIRE (bool(distance(a,d).display() == "0 m"));
		REQUIRE (bool(distance(d,a).display() == "0 m"));
		REQUIRE (bool(distance(b,d).display() == "1.41 m"));
		REQUIRE (bool(distance(d,b).display() == "1.41 m"));
	}

	SECTION("distance() of coordinates_3dr<float>")
	{
		coordinates_3dr<float> a(7.0f,3.0f,1.0f,angle(20.0f),angle(30.0f));
		coordinates_3dr<float> b(6.0f,2.0f,1.0f,angle(20.0f),angle(30.0f));
		REQUIRE (bool(std::fabs(distance(a,b) - 1.41f) < 0.01f));
		point_3d<float> c(7.0f,3.0f,1.0f);
		REQUIRE (bool(std::fabs(distance(a,c) - 0.0f) < 0.01f));
		REQUIRE (bool(std::fabs(distance(c,a) - 0.0f) < 0.01f));
		REQUIRE (bool(std::fabs(distance(b,c) - 1.41f) < 0.01f));
		REQUIRE (bool(std::fabs(distance(c,b) - 1.41f) < 0.01f));
		coordinates_3d<float> d(7.0f,3.0f,1.0f);
		REQUIRE (bool(distance(a,d) == 0.0f));
		REQUIRE (bool(distance(d,a) == 0.0f));
		REQUIRE (bool(std::fabs(distance(b,d) - 1.41f) < 0.01f));
		REQUIRE (bool(std::fabs(distance(d,b) - 1.41f) < 0.01f));
	}

	SECTION("Relational operators of coordinates_3dr<>")
	{
		coordinates_3dr<> a(7_m,3_m,1_m,angle(20.0f),angle(30.0f));
		coordinates_3dr<> b(7_m,3_m,1_m,angle(20.0f),angle(30.0f));
		coordinates_3dr<> c(6_m,2_m,1_m,angle(20.0f),angle(30.0f));
		REQUIRE(bool(a == b));
		REQUIRE(bool((a == c) == false));
		REQUIRE(bool(a != c));
		point_3d<> d(7_m,3_m,1_m);
		point_3d<> e(5_m,1_m,1_m);
		REQUIRE(bool(a == d));
		REQUIRE(bool(a != e));
		REQUIRE(bool(d == a));
		REQUIRE(bool(e != a));
	}

	SECTION("Relational operators of coordinates_3dr<float>")
	{
		coordinates_3dr<float> a(7.0f,3.0f,1.0f,angle(20.0f),angle(30.0f));
		coordinates_3dr<float> b(7.0f,3.0f,1.0f,angle(20.0f),angle(30.0f));
		coordinates_3dr<float> c(6.0f,2.0f,1.0f,angle(20.0f),angle(30.0f));
		REQUIRE(bool(a == b));
		REQUIRE(bool((a == c) == false));
		REQUIRE(bool(a != c));
		point_3d<float> d(7.0f,3.0f,1.0f);
		point_3d<float> e(5.0f,1.0f,1.0f);
		REQUIRE(bool(a == d));
		REQUIRE(bool(a != e));
		REQUIRE(bool(d == a));
		REQUIRE(bool(e != a));
	}

	SECTION("String operators of coordinates_3dr<>")
	{
		coordinates_3dr<> a(7_m,4_m,2_m,angle(20.0f),angle(30.0f));
		REQUIRE(bool(a == "(7 m,4 m,2 m;20\u00B0,30\u00B0)"));
		REQUIRE(bool(a != "(6 m,3 m,2 m;20\u00B0,30\u00B0)"));
		REQUIRE(bool("(7 m,4 m,2 m;20\u00B0,30\u00B0)" == a));
		REQUIRE(bool("(6 m,3 m,2 m;20\u00B0,30\u00B0)" != a));
		string b = "x: ";
		b += a;
		REQUIRE(bool(b == "x: (7 m,4 m,2 m;20\u00B0,30\u00B0)"));
		REQUIRE(bool(("x: " + a) == "x: (7 m,4 m,2 m;20\u00B0,30\u00B0)"));
		REQUIRE(bool("x: (7 m,4 m,2 m;20\u00B0,30\u00B0)" == ("x: " + a)));
	}

	SECTION("String operators of coordinates_3dr<float>")
	{
		coordinates_3dr<float> a(7.0f,4.0f,2.0f,angle(20.0f),angle(30.0f));
		REQUIRE(bool(a == "(7,4,2;20\u00B0,30\u00B0)"));
		REQUIRE(bool(a != "(6,3,2;20\u00B0,30\u00B0)"));
		REQUIRE(bool("(7,4,2;20\u00B0,30\u00B0)" == a));
		REQUIRE(bool("(6,3,2;20\u00B0,30\u00B0)" != a));
		string b = "x: ";
		b += a;
		REQUIRE(bool(b == "x: (7,4,2;20\u00B0,30\u00B0)"));
		REQUIRE(bool(("x: " + a) == "x: (7,4,2;20\u00B0,30\u00B0)"));
		REQUIRE(bool("x: (7,4,2;20\u00B0,30\u00B0)" == ("x: " + a)));
	}

	SECTION("Stream operators of coordinates_3dr<> classes")
	{
		coordinates_3dr<> a(2_m,3_m,2_m,angle(20.0f),angle(30.0f));
		ostringstream out;
		out << a;
		REQUIRE(bool(out.str() == "(2 m,3 m,2 m;20\u00B0,30\u00B0)"));
		istringstream iss("(1 m,2 m,1 m;30\u00B0,40\u00B0)");
		coordinates_3dr<> b;
		iss >> b;
		REQUIRE(bool(to_string(b) == "(1 m,2 m,1 m;30\u00B0,40\u00B0)"));
	}

	SECTION("Stream operators of coordinates_3dr<float> classes")
	{
		coordinates_3dr<float> a(2.0f,3.0f,2.0f,angle(20.0f),angle(30.0f));
		ostringstream out;
		out << a;
		REQUIRE(bool(out.str() == "(2,3,2;20\u00B0,30\u00B0)"));
		istringstream iss("(1,2,1;30\u00B0,40\u00B0)");
		coordinates_3dr<float> b;
		iss >> b;
		REQUIRE(bool(to_string(b) == "(1,2,1;30\u00B0,40\u00B0)"));
	}
}
