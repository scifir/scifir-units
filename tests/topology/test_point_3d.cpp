#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../topology/point_3d.hpp"
#include "../../coordinates/coordinates_3d.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class point_3d<T> and point_3d<float>")
{
	SECTION("Constructors of point_3d<> class")
	{
		point_3d<> a;
		CHECK(to_string(a) == "(0 m,0 m,0 m)");
		point_3d<> a2(5_m,5_m,1_m);
		point_3d<> a3(a2);
		CHECK(to_string(a3) == "(5 m,5 m,1 m)");
		point_3d<> a4(5_m,5_m,1_m);
		point_3d<> a5(move(a4));
		CHECK(to_string(a3) == "(5 m,5 m,1 m)");
		point_3d<> b(100_m,10_m,1_m);
		CHECK(to_string(b) == "(100 m,10 m,1 m)");
		point_3d<> b2(100_m,angle(90),1_m);
		CHECK(to_string(b2) == "(0 m,100 m,1 m)");
		point_3d<> b3(100_m,angle(0),angle(0));
		CHECK(to_string(b3) == "(0 m,0 m,100 m)");
		//point_3d<> b4(angle(0),angle(0),10_m);
		//CHECK(to_string(b4) == "(0 m,0 m,100 m)");
		coordinates_3d<> c2(100_m,1_m,2_m);
		point_3d<> c(c2);
		CHECK(to_string(c) == "(100 m,1 m,2 m)");
		coordinates_3d<> c4(100_m,1_m,2_m);
		point_3d<> c3(std::move(c4));
		CHECK(to_string(c3) == "(100 m,1 m,2 m)");
		point_3d<> d("(1 m,5 m,2 m)");
		CHECK(to_string(d) == "(1 m,5 m,2 m)");
		point_3d<> e("1 m,5 m,2 m");
		CHECK(to_string(e) == "(1 m,5 m,2 m)");
		point_3d<> f("2 m,45\u00B0,3 m");
		CHECK(to_string(f) == "(1.41 m,1.41 m,3 m)");
		point_3d<> g("2 m,45\u00B0,20\u00B0");
		CHECK(to_string(g) == "(0.48 m,0.48 m,1.87 m)");
		point_3d<> h(",,");
		CHECK(to_string(h) == "(0 m,0 m,0 m)");
	}

	SECTION("Constructors of point_3d<float> class")
	{
		point_3d<float> a;
		CHECK(to_string(a) == "(0,0,0)");
		point_3d<float> a2(5.0f,5.0f,1.0f);
		point_3d<float> a3(a2);
		CHECK(to_string(a3) == "(5,5,1)");
		point_3d<float> a4(5.0f,5.0f,1.0f);
		point_3d<float> a5(move(a4));
		CHECK(to_string(a3) == "(5,5,1)");
		point_3d<float> b(100.0f,10.0f,1.0f);
		CHECK(to_string(b) == "(100,10,1)");
		point_3d<float> b2(100.0f,angle(90),1.0f);
		CHECK(to_string(b2) == "(0,100,1)");
		point_3d<float> b3(100.0f,angle(0),angle(0));
		CHECK(to_string(b3) == "(0,0,100)");
		//point_3d<> b4(angle(0),angle(0),10_m);
		//CHECK(to_string(b4) == "(0 m,0 m,100 m)");
		coordinates_3d<float> c2(100.0f,1.0f,2.0f);
		point_3d<float> c(c2);
		CHECK(to_string(c) == "(100,1,2)");
		coordinates_3d<float> c4(100.0f,1.0f,2.0f);
		point_3d<float> c3(std::move(c4));
		CHECK(to_string(c3) == "(100,1,2)");
		point_3d<float> d("(1,5,2)");
		CHECK(to_string(d) == "(1,5,2)");
		point_3d<float> e("1,5,2");
		CHECK(to_string(e) == "(1,5,2)");
		point_3d<float> f("2,45\u00B0,3");
		CHECK(to_string(f) == "(1.41,1.41,3)");
		point_3d<float> g("2,45\u00B0,20\u00B0");
		CHECK(to_string(g) == "(0.48,0.48,1.87)");
	}

	SECTION("Assignments of point_3d<> class")
	{
		point_3d<> a;
		point_3d<> a2(5_m,5_m,1_m);
		a = a2;
		CHECK(to_string(a) == "(5 m,5 m,1 m)");
		point_3d<> b;
		point_3d<> b2(5_m,5_m,1_m);
		b = std::move(b2);
		CHECK(to_string(b) == "(5 m,5 m,1 m)");
		point_3d<> c;
		coordinates_3d<> c2(100_m,1_m,2_m);
		c = c2;
		CHECK(to_string(c) == "(100 m,1 m,2 m)");
		point_3d<> c3;
		coordinates_3d<> c4(100_m,1_m,2_m);
		c3 = std::move(c4);
		CHECK(to_string(c3) == "(100 m,1 m,2 m)");
		point_3d<> d;
		d = "(1 m,5 m,2 m)";
		CHECK(to_string(d) == "(1 m,5 m,2 m)");
		point_3d<> e;
		e = "1 m,5 m,2 m";
		CHECK(to_string(e) == "(1 m,5 m,2 m)");
		point_3d<> f;
		f = "2 m,45\u00B0,3 m";
		CHECK(to_string(f) == "(1.41 m,1.41 m,3 m)");
		point_3d<> g;
		g = "2 m,45\u00B0,20\u00B0";
		CHECK(to_string(g) == "(0.48 m,0.48 m,1.87 m)");
	}

	SECTION("Assignments of point_3d<float> class")
	{
		point_3d<float> a;
		point_3d<float> a2(5.0f,5.0f,1.0f);
		a = a2;
		CHECK(to_string(a) == "(5,5,1)");
		point_3d<float> b;
		point_3d<float> b2(5.0f,5.0f,1.0f);
		b = std::move(b2);
		CHECK(to_string(b) == "(5,5,1)");
		point_3d<float> c;
		coordinates_3d<float> c2(100.0f,1.0f,2.0f);
		c = c2;
		CHECK(to_string(c) == "(100,1,2)");
		point_3d<float> c3;
		coordinates_3d<float> c4(100.0f,1.0f,2.0f);
		c3 = std::move(c4);
		CHECK(to_string(c3) == "(100,1,2)");
		point_3d<float> d;
		d = "(1,5,2)";
		CHECK(to_string(d) == "(1,5,2)");
		point_3d<float> e;
		e = "1,5,2";
		CHECK(to_string(e) == "(1,5,2)");
		point_3d<float> f;
		f = "2,45\u00B0,3";
		CHECK(to_string(f) == "(1.41,1.41,3)");
		point_3d<float> g;
		g = "2,45\u00B0,20\u00B0";
		CHECK(to_string(g) == "(0.48,0.48,1.87)");
	}

	SECTION("Values of different coordinates systems of point_3d<> class")
	{
		point_3d<> c(7_m,4_m,2_m);
		CHECK(c.get_p().display() == "8.06 m");
		CHECK(c.get_theta().display() == "29.74\u00B0");
		CHECK(c.get_r().display() == "8.3 m");
		CHECK(c.get_phi().display() == "76.06\u00B0");
	}

	SECTION("Values of different coordinates systems of point_3d<float> class")
	{
		point_3d<float> c(7.0f,4.0f,2.0f);
		CHECK(std::fabs(c.get_p() - 8.06f) < 0.01f);
		CHECK(c.get_theta().display() == "29.74\u00B0");
		CHECK(std::fabs(c.get_r() - 8.3f) < 0.01f);
		CHECK(c.get_phi().display() == "76.06\u00B0");
	}

	SECTION("Geographic coordinates of point_3d<> class")
	{
		point_3d<> a(100000_m,100000_m,6371000_m);
		CHECK(to_string(a.get_latitude()) == "88.73\u00B0");
		CHECK(to_string(a.get_longitude()) == "45\u00B0");
		CHECK(to_string(a.get_altitude()) == "15806.6 m");
	}

	SECTION("Geographic coordinates of point_3d<float> class")
	{
		point_3d<float> a(100000.0f,100000.0f,6371000.0f);
		CHECK(to_string(a.get_latitude()) == "88.73\u00B0");
		CHECK(to_string(a.get_longitude()) == "45\u00B0");
		CHECK(std::fabs(a.get_altitude() - 15806.44f) < 0.01f);
	}

	SECTION("set_position(), rotate() and move() of point_3d<> class")
	{
		point_3d<> a;
		a.set_position(5_m,5_m,1_m);
		CHECK(to_string(a) == "(5 m,5 m,1 m)");
		a.set_position(5_m,angle(30.0f),1_m);
		CHECK(to_string(a) == "(4.33 m,2.5 m,1 m)");
		a.set_position(5_m,angle(30.0f),angle(45.0f));
		CHECK(to_string(a) == "(3.06 m,1.76 m,3.53 m)");
		/*a.set_position(angle(30.0f),angle(45.0f),100_m);
		cout << "geographical coordinates: " << to_string(a) << endl;
		CHECK(to_string(a) == "(61.23 m,61.23 m,50 m)");*/
		point_3d<> b(5_m,3_m,1_m);
		b.rotate_in_x(angle(45.0f));
		CHECK(to_string(b) == "(5 m,1.41 m,2.82 m)");
		point_3d<> c(7_m,4_m,2_m);
		c.rotate_in_y(angle(45.0f));
		CHECK(to_string(c) == "(3.53 m,4 m,6.36 m)");
		point_3d<> d(4_m,2_m,3_m);
		d.rotate_in_z(angle(45.0f));
		CHECK(to_string(d) == "(1.41 m,4.24 m,3 m)");
		point_3d<> e(1_m,2_m,3_m);
		displacement_3d e2(3_m,angle(0.0f),angle(0.0f));
		e.move(e2);
		CHECK(to_string(e) == "(1 m,2 m,6 m)");
		point_3d<> f(1_m,2_m,3_m);
		f.move(2_m,1_m,3_m);
		CHECK(to_string(f) == "(3 m,3 m,6 m)");
		point_3d<> g(1_m,2_m,3_m);
		g.move(2_m,angle(45.0f),3_m);
		CHECK(to_string(g) == "(2.41 m,3.41 m,6 m)");
		point_3d<> h(1_m,2_m,3_m);
		h.move(2_m,angle(0.0f),angle(45.0f));
		CHECK(to_string(h) == "(2.41 m,2 m,4.41 m)");
	}

	SECTION("set_position(), rotate() and move() of point_3d<float> class")
	{
		point_3d<float> a;
		a.set_position(5.0f,5.0f,1.0f);
		CHECK(to_string(a) == "(5,5,1)");
		a.set_position(5.0f,angle(30.0f),1.0f);
		CHECK(to_string(a) == "(4.33,2.5,1)");
		a.set_position(5.0f,angle(30.0f),angle(45.0f));
		CHECK(to_string(a) == "(3.06,1.76,3.53)");
		/*a.set_position(angle(30.0f),angle(45.0f),100_m);
		cout << "geographical coordinates: " << to_string(a) << endl;
		CHECK(to_string(a) == "(61.23 m,61.23 m,50 m)");*/
		point_3d<float> b(5.0f,3.0f,1.0f);
		b.rotate_in_x(angle(45.0f));
		CHECK(to_string(b) == "(5,1.41,2.82)");
		point_3d<float> c(7.0f,4.0f,2.0f);
		c.rotate_in_y(angle(45.0f));
		CHECK(to_string(c) == "(3.53,4,6.36)");
		point_3d<float> d(4.0f,2.0f,3.0f);
		d.rotate_in_z(angle(45.0f));
		CHECK(to_string(d) == "(1.41,4.24,3)");
		point_3d<float> e(1.0f,2.0f,3.0f);
		displacement_3d e2(3_m,angle(0.0f),angle(0.0f));
		e.move(e2);
		CHECK(to_string(e) == "(1,2,6)");
		point_3d<float> f(1.0f,2.0f,3.0f);
		f.move(2.0f,1.0f,3.0f);
		CHECK(to_string(f) == "(3,3,6)");
		point_3d<float> g(1.0f,2.0f,3.0f);
		g.move(2.0f,angle(45.0f),3.0f);
		CHECK(to_string(g) == "(2.41,3.41,6)");
		point_3d<float> h(1.0f,2.0f,3.0f);
		h.move(2.0f,angle(0.0f),angle(45.0f));
		CHECK(to_string(h) == "(2.41,2,4.41)");
	}

	SECTION("Display of point_3d<> class")
	{
		point_3d<> a(2_m,3_m,5_m);
		CHECK(a.display_cartesian() == "(2 m,3 m,5 m)");
		CHECK(a.display_cylindrical() == "(3.6 m,56.3\u00B0,5 m)");
		CHECK(a.display_spherical() == "(6.16 m,56.3\u00B0,35.79\u00B0)");
		/*point_3d<> b(2_m,3_m,10000_km);
		cout << "b display geographical: " << b.display_geographical() << endl;
		CHECK(b.display_geographical() == "");*/
	}

	SECTION("Display of point_3d<float> class")
	{
		point_3d<float> a(2.0f,3.0f,5.0f);
		CHECK(a.display_cartesian() == "(2,3,5)");
		CHECK(a.display_cylindrical() == "(3.6,56.3\u00B0,5)");
		CHECK(a.display_spherical() == "(6.16,56.3\u00B0,35.79\u00B0)");
		/*point_3d<> b(2_m,3_m,10000_km);
		cout << "b display geographical: " << b.display_geographical() << endl;
		CHECK(b.display_geographical() == "");*/
	}

	SECTION("to_string() of point_3d<> class")
	{
		point_3d<> a(2_m,3_m,5_m);
		CHECK(to_string(a) == "(2 m,3 m,5 m)");
	}

	SECTION("to_string() of point_3d<float> class")
	{
		point_3d<float> a(2.0f,3.0f,5.0f);
		CHECK(to_string(a) == "(2,3,5)");
	}

	SECTION("distance() of point_3d<> class")
	{
		point_3d<> a(7_m,3_m,1_m);
		point_3d<> b(6_m,2_m,1_m);
		CHECK(distance(a,b).display() == "1.41 m");
		coordinates_3d<> c(7_m,3_m,1_m);
		CHECK(distance(a,c).display() == "0 m");
		CHECK(distance(c,a).display() == "0 m");
		CHECK(distance(b,c).display() == "1.41 m");
		CHECK(distance(c,b).display() == "1.41 m");
	}

	SECTION("distance() of point_3d<float> class")
	{
		point_3d<float> a(7.0f,3.0f,1.0f);
		point_3d<float> b(6.0f,2.0f,1.0f);
		CHECK(std::fabs(distance(a,b) - 1.41f) < 0.01f);
		coordinates_3d<float> c(7.0f,3.0f,1.0f);
		CHECK(std::fabs(distance(a,c) - 0.0f) < 0.01f);
		CHECK(std::fabs(distance(c,a) - 0.0f) < 0.01f);
		CHECK(std::fabs(distance(b,c) - 1.41f) < 0.01f);
		CHECK(std::fabs(distance(c,b) - 1.41f) < 0.01f);
	}

	SECTION("Relational operators of point_3d<> class")
	{
		point_3d<> a(7_m,3_m,1_m);
		point_3d<> b(7_m,3_m,1_m);
		point_3d<> c(6_m,2_m,1_m);
		CHECK(bool(a == b));
		CHECK((a == c) == false);
		CHECK(bool(a != c));
		coordinates_3d<> d(7_m,3_m,1_m);
		coordinates_3d<> e(5_m,1_m,1_m);
		CHECK(bool(a == d));
		CHECK(bool(a != e));
		CHECK(bool(d == a));
		CHECK(bool(e != a));
	}

	SECTION("Relational operators of point_3d<float> class")
	{
		point_3d<float> a(7.0f,3.0f,1.0f);
		point_3d<float> b(7.0f,3.0f,1.0f);
		point_3d<float> c(6.0f,2.0f,1.0f);
		CHECK(bool(a == b));
		CHECK((a == c) == false);
		CHECK(bool(a != c));
		coordinates_3d<float> d(7.0f,3.0f,1.0f);
		coordinates_3d<float> e(5.0f,1.0f,1.0f);
		CHECK(bool(a == d));
		CHECK(bool(a != e));
		CHECK(bool(d == a));
		CHECK(bool(e != a));
	}

	SECTION("String operators of point_3d<> class")
	{
		point_3d<> a(7_m,4_m,2_m);
		CHECK(bool(a == "(7 m,4 m,2 m)"));
		CHECK(bool(a != "(6 m,3 m,2 m)"));
		CHECK(bool("(7 m,4 m,2 m)" == a));
		CHECK(bool("(6 m,3 m,2 m)" != a));
		string b = "x: ";
		b += a;
		CHECK(b == "x: (7 m,4 m,2 m)");
		CHECK(("x: " + a) == "x: (7 m,4 m,2 m)");
		CHECK("x: (7 m,4 m,2 m)" == ("x: " + a));
	}

	SECTION("String operators of point_3d<float> class")
	{
		point_3d<float> a(7.0f,4.0f,2.0f);
		CHECK(bool(a == "(7,4,2)"));
		CHECK(bool(a != "(6,3,2)"));
		CHECK(bool("(7,4,2)" == a));
		CHECK(bool("(6,3,2)" != a));
		string b = "x: ";
		b += a;
		CHECK(b == "x: (7,4,2)");
		CHECK(("x: " + a) == "x: (7,4,2)");
		CHECK("x: (7,4,2)" == ("x: " + a));
	}

	SECTION("Stream operators of point_3d<> class")
	{
		point_3d<> a(2_m,3_m,2_m);
		ostringstream out;
		out << a;
		CHECK(out.str() == "(2 m,3 m,2 m)");
		istringstream iss("(1 m,2 m,1 m)");
		point_3d<> b;
		iss >> b;
		CHECK(to_string(b) == "(1 m,2 m,1 m)");
	}

	SECTION("Stream operators of point_3d<float> class")
	{
		point_3d<float> a(2.0f,3.0f,2.0f);
		ostringstream out;
		out << a;
		CHECK(out.str() == "(2,3,2)");
		istringstream iss("(1,2,1)");
		point_3d<float> b;
		iss >> b;
		CHECK(to_string(b) == "(1,2,1)");
	}
}
