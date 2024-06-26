#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../topology/point_nd.hpp"
#include "../../topology/point_nd_impl.hpp"
#include "../../coordinates/coordinates_nd.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class point_nd","Complete test of point_nd")
{
	SECTION("Constructors of point_nd<> classes")
	{
		point_nd<> a;
		REQUIRE (bool(to_string(a) == "[empty]"));
		point_nd<> a2(5_m,5_m,1_m);
		point_nd<> a3(a2);
		REQUIRE (bool(to_string(a3) == "(5 m,5 m,1 m)"));
		point_nd<> a4(5_m,5_m,1_m);
		point_nd<> a5(move(a4));
		REQUIRE (bool(to_string(a3) == "(5 m,5 m,1 m)"));
		point_nd<> b6(8_m);
		REQUIRE (bool(to_string(b6) == "(8 m)"));
		point_nd<> b7(6_m,4_m);
		REQUIRE (bool(to_string(b7) == "(6 m,4 m)"));
		point_nd<> b8(100_m,angle(90.0f));
		REQUIRE (bool(to_string(b8) == "(0 m,100 m)"));
		point_nd<> b(100_m,10_m,1_m);
		REQUIRE (bool(to_string(b) == "(100 m,10 m,1 m)"));
		point_nd<> b2(100_m,angle(90),1_m);
		REQUIRE (bool(to_string(b2) == "(0 m,100 m,1 m)"));
		point_nd<> b3(100_m,angle(0),angle(0));
		REQUIRE (bool(to_string(b3) == "(0 m,0 m,100 m)"));
		//point_nd<> b4(angle(0),angle(0),10_m);
		//REQUIRE (bool(to_string(b4) == "(0 m,0 m,100 m)"));
		coordinates_nd<> c2(100_m,1_m,2_m);
		point_nd<> c(c2);
		REQUIRE (bool(to_string(c) == "(100 m,1 m,2 m)"));
		point_nd<> d("(1 m)");
		REQUIRE (bool(to_string(d) == "(1 m)"));
		point_nd<> d2("(1 m,5 m)");
		REQUIRE (bool(to_string(d2) == "(1 m,5 m)"));
		point_nd<> d3("(1 m,45\u00B0)");
		REQUIRE (bool(to_string(d3) == "(0.7 m,0.7 m)"));
		point_nd<> d4("(1 m,5 m,2 m)");
		REQUIRE (bool(to_string(d4) == "(1 m,5 m,2 m)"));
		point_nd<> e("1 m,5 m,2 m");
		REQUIRE (bool(to_string(e) == "(1 m,5 m,2 m)"));
		point_nd<> f("2 m,45\u00B0,3 m");
		REQUIRE (bool(to_string(f) == "(1.41 m,1.41 m,3 m)"));
		point_nd<> g("2 m,45\u00B0,20\u00B0");
		REQUIRE (bool(to_string(g) == "(0.48 m,0.48 m,1.87 m)"));
	}

	SECTION("Constructors of point_nd<float> classes")
	{
		point_nd<float> a;
		REQUIRE (bool(to_string(a) == "[empty]"));
		point_nd<float> a2(5.0f,5.0f,1.0f);
		point_nd<float> a3(a2);
		REQUIRE (bool(to_string(a3) == "(5,5,1)"));
		point_nd<float> a4(5.0f,5.0f,1.0f);
		point_nd<float> a5(move(a4));
		REQUIRE (bool(to_string(a3) == "(5,5,1)"));
		point_nd<float> b(100.0f,10.0f,1.0f);
		REQUIRE (bool(to_string(b) == "(100,10,1)"));
		point_nd<float> b2(100.0f,angle(90),1.0f);
		REQUIRE (bool(to_string(b2) == "(0,100,1)"));
		point_nd<float> b3(100.0f,angle(0),angle(0));
		REQUIRE (bool(to_string(b3) == "(0,0,100)"));
		//point_nd<> b4(angle(0),angle(0),10_m);
		//REQUIRE (bool(to_string(b4) == "(0 m,0 m,100 m)"));
		coordinates_nd<float> c2(100.0f,1.0f,2.0f);
		point_nd<float> c(c2);
		REQUIRE (bool(to_string(c) == "(100,1,2)"));
		point_nd<float> d("(1)");
		REQUIRE (bool(to_string(d) == "(1)"));
		point_nd<float> d2("(1,5)");
		REQUIRE (bool(to_string(d2) == "(1,5)"));
		point_nd<float> d3("(1,45\u00B0)");
		REQUIRE (bool(to_string(d3) == "(0.7,0.7)"));
		point_nd<float> d4("(1,5,2)");
		REQUIRE (bool(to_string(d4) == "(1,5,2)"));
		point_nd<float> e("1,5,2");
		REQUIRE (bool(to_string(e) == "(1,5,2)"));
		point_nd<float> f("2,45\u00B0,3");
		REQUIRE (bool(to_string(f) == "(1.41,1.41,3)"));
		point_nd<float> g("2,45\u00B0,20\u00B0");
		REQUIRE (bool(to_string(g) == "(0.48,0.48,1.87)"));
	}

	SECTION("Assignments of point_nd<> classes")
	{
		point_nd<> a;
		point_nd<> a2(5_m,5_m,1_m);
		a = a2;
		REQUIRE (bool(to_string(a) == "(5 m,5 m,1 m)"));
		point_nd<> b;
		point_nd<> b2(5_m,5_m,1_m);
		b = std::move(b2);
		REQUIRE (bool(to_string(b) == "(5 m,5 m,1 m)"));
		point_nd<> c;
		coordinates_nd<> c2(100_m,1_m,2_m);
		c = c2;
		REQUIRE (bool(to_string(c) == "(100 m,1 m,2 m)"));
	}

	SECTION("Assignments of point_nd<float> classes")
	{
		point_nd<float> a;
		point_nd<float> a2(5.0f,5.0f,1.0f);
		a = a2;
		REQUIRE (bool(to_string(a) == "(5,5,1)"));
		point_nd<float> b;
		point_nd<float> b2(5.0f,5.0f,1.0f);
		b = std::move(b2);
		REQUIRE (bool(to_string(b) == "(5,5,1)"));
		point_nd<float> c;
		coordinates_nd<float> c2(100.0f,1.0f,2.0f);
		c = c2;
		REQUIRE (bool(to_string(c) == "(100,1,2)"));
	}

	SECTION("Values of different coordinates systems of point_nd<> classes")
	{
		point_nd<> a(7_m,4_m,2_m);
		REQUIRE (bool(a.get_p().display() == "8.06 m"));
		REQUIRE (bool(a.get_theta().display() == "29.74\u00B0"));
		REQUIRE (bool(a.get_r().display() == "8.3 m"));
		REQUIRE (bool(a.get_phi().display() == "76.06\u00B0"));
		point_nd<> b(7_m);
		REQUIRE (bool(b.get_p() == length()));
		REQUIRE (bool(b.get_theta() == angle()));
		REQUIRE (bool(b.get_r() == length()));
		REQUIRE (bool(b.get_phi() == angle()));
		/*REQUIRE (bool(c.get_latitude() == angle(0.0f)));
		REQUIRE (bool(c.get_longitude() == angle(29.74f)));
		REQUIRE (bool(c.get_altitude() == "0 m"));*/
	}

	SECTION("Values of different coordinates systems of point_nd<float> classes")
	{
		point_nd<float> c(7.0f,4.0f,2.0f);
		REQUIRE (bool(std::fabs(c.get_p() - 8.06f) < 0.01f));
		REQUIRE (bool(c.get_theta().display() == "29.74\u00B0"));
		REQUIRE (bool(std::fabs(c.get_r() - 8.3f) < 0.01f));
		REQUIRE (bool(c.get_phi().display() == "76.06\u00B0"));
		point_nd<float> b(7.0f);
		REQUIRE (bool(b.get_p() == 0.0f));
		REQUIRE (bool(b.get_theta() == angle()));
		REQUIRE (bool(b.get_r() == 0.0f));
		REQUIRE (bool(b.get_phi() == angle()));
		/*REQUIRE (bool(c.get_latitude() == angle(0.0f)));
		REQUIRE (bool(c.get_longitude() == angle(29.74f)));
		REQUIRE (bool(c.get_altitude() == "0 m"));*/
	}

	SECTION("set_position(), rotate() and move() of point_nd<> classes")
	{
		point_nd<> a;
		a.set_position(5_m,5_m,1_m);
		REQUIRE (bool(to_string(a) == "(5 m,5 m,1 m)"));
		a.set_position(5_m,angle(30.0f),1_m);
		REQUIRE (bool(to_string(a) == "(4.33 m,2.5 m,1 m)"));
		a.set_position(5_m,angle(30.0f),angle(45.0f));
		REQUIRE (bool(to_string(a) == "(3.06 m,1.76 m,3.53 m)"));
		/*a.set_position(angle(30.0f),angle(45.0f),100_m);
		cout << "geographical coordinates: " << to_string(a) << endl;
		REQUIRE (bool(to_string(a) == "(61.23 m,61.23 m,50 m)"));*/
		point_nd<> b2(20_m,angle(60.0f));
		b2.rotate_in_2d(angle(15.0f));
		REQUIRE (bool(to_string(b2) == "(5.17 m,19.31 m)"));
		point_nd<> b(5_m,3_m,1_m);
		b.rotate_in_3d(1,angle(45.0f));
		REQUIRE (bool(to_string(b) == "(5 m,1.41 m,2.82 m)"));
		point_nd<> c(7_m,4_m,2_m);
		c.rotate_in_3d(2,angle(45.0f));
		REQUIRE (bool(to_string(c) == "(3.53 m,4 m,6.36 m)"));
		point_nd<> d(4_m,2_m,3_m);
		d.rotate_in_3d(3,angle(45.0f));
		REQUIRE (bool(to_string(d) == "(1.41 m,4.24 m,3 m)"));
		point_nd<> e(1_m,2_m,3_m);
		displacement_3d e2(3_m,angle(0.0f),angle(0.0f));
		e.move(e2);
		REQUIRE (bool(to_string(e) == "(1 m,2 m,6 m)"));
		point_nd<> f(1_m,2_m,3_m);
		f.move(2_m,1_m,3_m);
		REQUIRE (bool(to_string(f) == "(3 m,3 m,6 m)"));
		point_nd<> g(1_m,2_m,3_m);
		g.move(2_m,angle(45.0f),3_m);
		REQUIRE (bool(to_string(g) == "(2.41 m,3.41 m,6 m)"));
		point_nd<> h(1_m,2_m,3_m);
		h.move(2_m,angle(0.0f),angle(45.0f));
		REQUIRE (bool(to_string(h) == "(2.41 m,2 m,4.41 m)"));
	}

	SECTION("set_position(), rotate() and move() of point_nd<float> classes")
	{
		point_nd<float> a;
		a.set_position(5.0f,5.0f,1.0f);
		REQUIRE (bool(to_string(a) == "(5,5,1)"));
		a.set_position(5.0f,angle(30.0f),1.0f);
		REQUIRE (bool(to_string(a) == "(4.33,2.5,1)"));
		a.set_position(5.0f,angle(30.0f),angle(45.0f));
		REQUIRE (bool(to_string(a) == "(3.06,1.76,3.53)"));
		/*a.set_position(angle(30.0f),angle(45.0f),100_m);
		cout << "geographical coordinates: " << to_string(a) << endl;
		REQUIRE (bool(to_string(a) == "(61.23 m,61.23 m,50 m)"));*/
		point_nd<float> b2(20.0f,angle(60.0f));
		b2.rotate_in_2d(angle(15.0f));
		REQUIRE (bool(to_string(b2) == "(5.17,19.31)"));
		point_nd<float> b(5.0f,3.0f,1.0f);
		b.rotate_in_3d(1,angle(45.0f));
		REQUIRE (bool(to_string(b) == "(5,1.41,2.82)"));
		point_nd<float> c(7.0f,4.0f,2.0f);
		c.rotate_in_3d(2,angle(45.0f));
		REQUIRE (bool(to_string(c) == "(3.53,4,6.36)"));
		point_nd<float> d(4.0f,2.0f,3.0f);
		d.rotate_in_3d(3,angle(45.0f));
		REQUIRE (bool(to_string(d) == "(1.41,4.24,3)"));
		point_nd<float> e(1.0f,2.0f,3.0f);
		displacement_3d e2(3_m,angle(0.0f),angle(0.0f));
		e.move(e2);
		REQUIRE (bool(to_string(e) == "(1,2,6)"));
		point_nd<float> f(1.0f,2.0f,3.0f);
		f.move(2.0f,1.0f,3.0f);
		REQUIRE (bool(to_string(f) == "(3,3,6)"));
		point_nd<float> g(1.0f,2.0f,3.0f);
		g.move(2.0f,angle(45.0f),3.0f);
		REQUIRE (bool(to_string(g) == "(2.41,3.41,6)"));
		point_nd<float> h(1.0f,2.0f,3.0f);
		h.move(2.0f,angle(0.0f),angle(45.0f));
		REQUIRE (bool(to_string(h) == "(2.41,2,4.41)"));
	}

	SECTION("Display of point_nd<> classes")
	{
		point_nd<> a(2_m,3_m,5_m);
		REQUIRE (bool(a.display_polar() == "[no-2d]"));
		REQUIRE (bool(a.display_cylindrical() == "(3.6 m,56.3\u00B0,5 m)"));
		REQUIRE (bool(a.display_spherical() == "(6.16 m,56.3\u00B0,35.79\u00B0)"));
		point_nd<> b(5_m,angle(30.0f));
		REQUIRE (bool(b.display_polar() == "(5 m,30\u00B0)"));
		REQUIRE (bool(b.display_cylindrical() == "[no-3d]"));
		REQUIRE (bool(b.display_spherical() == "[no-3d]"));
		/*point_nd<> b(2_m,3_m,10000_km);
		cout << "b display geographical: " << b.display_geographical() << endl;
		REQUIRE (bool(b.display_geographical() == ""));*/
	}

	SECTION("Display of point_nd<float> classes")
	{
		point_nd<float> a(2.0f,3.0f,5.0f);
		REQUIRE (bool(a.display_polar() == "[no-2d]"));
		REQUIRE (bool(a.display_cylindrical() == "(3.6,56.3\u00B0,5)"));
		REQUIRE (bool(a.display_spherical() == "(6.16,56.3\u00B0,35.79\u00B0)"));
		point_nd<float> b(5.0f,angle(30.0f));
		REQUIRE (bool(b.display_polar() == "(5,30\u00B0)"));
		REQUIRE (bool(b.display_cylindrical() == "[no-3d]"));
		REQUIRE (bool(b.display_spherical() == "[no-3d]"));
		/*point_nd<float> b(2_m,3_m,10000_km);
		cout << "b display geographical: " << b.display_geographical() << endl;
		REQUIRE (bool(b.display_geographical() == ""));*/
	}

	SECTION("to_string() of point_nd<>")
	{
		point_nd<> a(2_m,3_m,5_m);
		REQUIRE (bool(to_string(a) == "(2 m,3 m,5 m)"));
	}

	SECTION("to_string() of point_nd<float>")
	{
		point_nd<float> a(2.0f,3.0f,5.0f);
		REQUIRE (bool(to_string(a) == "(2,3,5)"));
	}

	SECTION("distance() of point_nd<>")
	{
		point_nd<> a(7_m,3_m,1_m);
		point_nd<> b(6_m,2_m,1_m);
		REQUIRE (bool(distance(a,b).display() == "1.41 m"));
		point_nd<> b2(6_m,2_m);
		REQUIRE (bool(distance(a,b2) == length()));
		coordinates_nd<> c(7_m,3_m,1_m);
		REQUIRE (bool(distance(a,c).display() == "0 m"));
		REQUIRE (bool(distance(c,a).display() == "0 m"));
		REQUIRE (bool(distance(b,c).display() == "1.41 m"));
		REQUIRE (bool(distance(c,b).display() == "1.41 m"));
		coordinates_nd<> c2(7_m,3_m);
		REQUIRE (bool(distance(a,c2) == length()));
		REQUIRE (bool(distance(c2,a) == length()));
	}

	SECTION("distance() of point_nd<float>")
	{
		point_nd<float> a(7.0f,3.0f,1.0f);
		point_nd<float> b(6.0f,2.0f,1.0f);
		REQUIRE (bool(std::fabs(distance(a,b) - 1.41f) < 0.01f));
		point_nd<float> b2(6.0f,2.0f);
		REQUIRE (bool(distance(a,b2) == 0.0f));
		coordinates_nd<float> c(7.0f,3.0f,1.0f);
		REQUIRE (bool(std::fabs(distance(a,c) - 0.0f) < 0.01f));
		REQUIRE (bool(std::fabs(distance(c,a) - 0.0f) < 0.01f));
		REQUIRE (bool(std::fabs(distance(b,c) - 1.41f) < 0.01f));
		REQUIRE (bool(std::fabs(distance(c,b) - 1.41f) < 0.01f));
		coordinates_nd<float> c2(7.0f,3.0f);
		REQUIRE (bool(distance(a,c2) == 0.0f));
		REQUIRE (bool(distance(c2,a) == 0.0f));
	}

	SECTION("Relational operators of point_nd<>")
	{
		point_nd<> a(7_m,3_m,1_m);
		point_nd<> b(7_m,3_m,1_m);
		point_nd<> c(6_m,2_m,1_m);
		point_nd<> c2(6_m,2_m);
		REQUIRE(bool(a == b));
		REQUIRE(bool((a == c) == false));
		REQUIRE(bool((a == c2) == false));
		REQUIRE(bool(a != c));
		coordinates_nd<> d(7_m,3_m,1_m);
		coordinates_nd<> e(5_m,1_m,1_m);
		coordinates_nd<> e2(5_m,1_m);
		REQUIRE(bool(a == d));
		REQUIRE(bool(a != e));
		REQUIRE(bool(a == e2) == false);
		REQUIRE(bool(e2 == a) == false);
		REQUIRE(bool(d == a));
		REQUIRE(bool(e != a));
	}

	SECTION("Relational operators of point_nd<float>")
	{
		point_nd<float> a(7.0f,3.0f,1.0f);
		point_nd<float> b(7.0f,3.0f,1.0f);
		point_nd<float> c(6.0f,2.0f,1.0f);
		REQUIRE(bool(a == b));
		REQUIRE(bool((a == c) == false));
		REQUIRE(bool(a != c));
		coordinates_nd<float> d(7.0f,3.0f,1.0f);
		coordinates_nd<float> e(5.0f,1.0f,1.0f);
		REQUIRE(bool(a == d));
		REQUIRE(bool(a != e));
		REQUIRE(bool(d == a));
		REQUIRE(bool(e != a));
	}

	SECTION("String operators of point_nd<>")
	{
		point_nd<> a(7_m,4_m,2_m);
		REQUIRE(bool(a == "(7 m,4 m,2 m)"));
		REQUIRE(bool(a != "(6 m,3 m,2 m)"));
		REQUIRE(bool("(7 m,4 m,2 m)" == a));
		REQUIRE(bool("(6 m,3 m,2 m)" != a));
		string b = "x: ";
		b += a;
		REQUIRE(bool(b == "x: (7 m,4 m,2 m)"));
		REQUIRE(bool(("x: " + a) == "x: (7 m,4 m,2 m)"));
		REQUIRE(bool("x: (7 m,4 m,2 m)" == ("x: " + a)));
	}

	SECTION("String operators of point_nd<float>")
	{
		point_nd<float> a(7.0f,4.0f,2.0f);
		REQUIRE(bool(a == "(7,4,2)"));
		REQUIRE(bool(a != "(6,3,2)"));
		REQUIRE(bool("(7,4,2)" == a));
		REQUIRE(bool("(6,3,2)" != a));
		string b = "x: ";
		b += a;
		REQUIRE(bool(b == "x: (7,4,2)"));
		REQUIRE(bool(("x: " + a) == "x: (7,4,2)"));
		REQUIRE(bool("x: (7,4,2)" == ("x: " + a)));
	}

	SECTION("Stream operators of point_nd<> classes")
	{
		point_nd<> a(2_m,3_m,2_m);
		ostringstream out;
		out << a;
		REQUIRE(bool(out.str() == "(2 m,3 m,2 m)"));
		istringstream iss("(1 m,2 m,1 m)");
		point_nd<> b;
		iss >> b;
		REQUIRE(bool(to_string(b) == "(1 m,2 m,1 m)"));
	}

	SECTION("Stream operators of point_nd<float> classes")
	{
		point_nd<float> a(2.0f,3.0f,2.0f);
		ostringstream out;
		out << a;
		REQUIRE(bool(out.str() == "(2,3,2)"));
		istringstream iss("(1,2,1)");
		point_nd<float> b;
		iss >> b;
		REQUIRE(bool(to_string(b) == "(1,2,1)"));
	}
}
