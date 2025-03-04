#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../coordinates/coordinates_3dr.hpp"
#include "../../units/special_names.hpp"
#include "../../units/unit_abbreviation.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class coordinates_3dr<T> and coordinates_3dr<float>")
{
	SECTION("Constructors of coordinates_3dr<> class")
	{
		coordinates_3dr<> a;
		CHECK(to_string(a) == "(0 m,0 m,0 m;0\u00B0,0\u00B0)");
		coordinates_3dr<> a2(5_m,5_m,1_m,angle(0),angle(0));
		coordinates_3dr<> a3(a2);
		CHECK(to_string(a3) == "(5 m,5 m,1 m;0\u00B0,0\u00B0)");
		coordinates_3dr<> a4(5_m,5_m,1_m,angle(0),angle(0));
		coordinates_3dr<> a5(move(a4));
		CHECK(to_string(a3) == "(5 m,5 m,1 m;0\u00B0,0\u00B0)");
		coordinates_3dr<> b(100_m,10_m,1_m,angle(0),angle(0));
		CHECK(to_string(b) == "(100 m,10 m,1 m;0\u00B0,0\u00B0)");
		coordinates_3dr<> b2(100_m,angle(90),1_m,angle(0),angle(0));
		CHECK(to_string(b2) == "(0 m,100 m,1 m;0\u00B0,0\u00B0)");
		coordinates_3dr<> b3(100_m,angle(0),angle(0),angle(0),angle(0));
		CHECK(to_string(b3) == "(0 m,0 m,100 m;0\u00B0,0\u00B0)");
		//coordinates_3dr<> b4(angle(0),angle(0),10_m);
		//CHECK(to_string(b4) == "(0 m,0 m,100 m)");
		coordinates_3d<> c5(100_m,1_m,2_m);
		coordinates_3dr<> c6(c5,angle(0),angle(0));
		CHECK(to_string(c6) == "(100 m,1 m,2 m;0\u00B0,0\u00B0)");
		coordinates_3d<> c7(100_m,1_m,2_m);
		coordinates_3dr<> c8(std::move(c7),angle(0),angle(0));
		CHECK(to_string(c8) == "(100 m,1 m,2 m;0\u00B0,0\u00B0)");
		coordinates_3dr<> c9(100_m,1_m,2_m,angle(0),angle(0));
		coordinates_3dr<> c10(c9);
		CHECK(to_string(c10) == "(100 m,1 m,2 m;0\u00B0,0\u00B0)");
		coordinates_3dr<> d("(1 m,5 m,2 m;0\u00B0,0\u00B0)");
		CHECK(to_string(d) == "(1 m,5 m,2 m;0\u00B0,0\u00B0)");
		coordinates_3dr<> e("1 m,5 m,2 m;0\u00B0,0\u00B0");
		CHECK(to_string(e) == "(1 m,5 m,2 m;0\u00B0,0\u00B0)");
		coordinates_3dr<> f("2 m,45\u00B0,3 m;20\u00B0,40\u00B0");
		CHECK(to_string(f) == "(1.41 m,1.41 m,3 m;20\u00B0,40\u00B0)");
		coordinates_3dr<> g("2 m,45\u00B0,20\u00B0;20\u00B0,40\u00B0");
		CHECK(to_string(g) == "(0.48 m,0.48 m,1.87 m;20\u00B0,40\u00B0)");
		coordinates_3dr<> h(",,;");
		CHECK(to_string(h) == "(0 m,0 m,0 m;0\u00B0,0\u00B0)");
	}

	SECTION("Constructors of coordinates_3dr<float> class")
	{
		coordinates_3dr<float> a;
		CHECK(to_string(a) == "(0,0,0;0\u00B0,0\u00B0)");
		coordinates_3dr<float> a2(5.0f,5.0f,1.0f,angle(0),angle(0));
		coordinates_3dr<float> a3(a2);
		CHECK(to_string(a3) == "(5,5,1;0\u00B0,0\u00B0)");
		coordinates_3dr<float> a4(5.0f,5.0f,1.0f,angle(0),angle(0));
		coordinates_3dr<float> a5(move(a4));
		CHECK(to_string(a3) == "(5,5,1;0\u00B0,0\u00B0)");
		coordinates_3dr<float> b(100.0f,10.0f,1.0f,angle(0),angle(0));
		CHECK(to_string(b) == "(100,10,1;0\u00B0,0\u00B0)");
		coordinates_3dr<float> b2(100.0f,angle(90),1.0f,angle(0),angle(0));
		CHECK(to_string(b2) == "(0,100,1;0\u00B0,0\u00B0)");
		coordinates_3dr<float> b3(100.0f,angle(0),angle(0),angle(0),angle(0));
		CHECK(to_string(b3) == "(0,0,100;0\u00B0,0\u00B0)");
		//coordinates_3dr<float> b4(angle(0),angle(0),10_m);
		//CHECK(to_string(b4) == "(0,0,100)");
		coordinates_3d<float> c5(100.0f,1.0f,2.0f);
		coordinates_3dr<float> c6(c5,angle(0),angle(0));
		CHECK(to_string(c6) == "(100,1,2;0\u00B0,0\u00B0)");
		coordinates_3d<float> c7(100.0f,1.0f,2.0f);
		coordinates_3dr<float> c8(std::move(c7),angle(0),angle(0));
		CHECK(to_string(c8) == "(100,1,2;0\u00B0,0\u00B0)");
		coordinates_3dr<float> c9(100.0f,1.0f,2.0f,angle(0),angle(0));
		coordinates_3dr<float> c10(c9);
		CHECK(to_string(c10) == "(100,1,2;0\u00B0,0\u00B0)");
		coordinates_3dr<float> d("(1,5,2;0\u00B0,0\u00B0)");
		CHECK(to_string(d) == "(1,5,2;0\u00B0,0\u00B0)");
		coordinates_3dr<float> e("1,5,2;0\u00B0,0\u00B0");
		CHECK(to_string(e) == "(1,5,2;0\u00B0,0\u00B0)");
		coordinates_3dr<float> f("2,45\u00B0,3;20\u00B0,40\u00B0");
		CHECK(to_string(f) == "(1.41,1.41,3;20\u00B0,40\u00B0)");
		coordinates_3dr<float> g("2,45\u00B0,20\u00B0;20\u00B0,40\u00B0");
		CHECK(to_string(g) == "(0.48,0.48,1.87;20\u00B0,40\u00B0)");
	}

	SECTION("Assignments of coordinates_3dr<> class")
	{
		coordinates_3dr<> a;
		coordinates_3dr<> a2(5_m,5_m,1_m,angle(20.0f),angle(30.0f));
		a = a2;
		CHECK(to_string(a) == "(5 m,5 m,1 m;20\u00B0,30\u00B0)");
		coordinates_3dr<> b;
		coordinates_3dr<> b2(5_m,5_m,1_m,angle(20.0f),angle(30.0f));
		b = std::move(b2);
		CHECK(to_string(b) == "(5 m,5 m,1 m;20\u00B0,30\u00B0)");
		coordinates_3dr<> c;
		coordinates_3dr<> d;
		coordinates_3d<> d2(100_m,1_m,2_m);
		d = d2;
		CHECK(to_string(d) == "(100 m,1 m,2 m;0\u00B0,0\u00B0)");
		coordinates_3dr<> d3;
		coordinates_3d<> d4(100_m,1_m,2_m);
		d3 = std::move(d4);
		CHECK(to_string(d3) == "(100 m,1 m,2 m;0\u00B0,0\u00B0)");
		coordinates_3dr<> d5;
		d5 = "(1 m,5 m,2 m;0\u00B0,0\u00B0)";
		CHECK(to_string(d5) == "(1 m,5 m,2 m;0\u00B0,0\u00B0)");
		coordinates_3dr<> e;
		e = "1 m,5 m,2 m;0\u00B0,0\u00B0";
		CHECK(to_string(e) == "(1 m,5 m,2 m;0\u00B0,0\u00B0)");
		coordinates_3dr<> f;
		f = "2 m,45\u00B0,3 m;20\u00B0,40\u00B0";
		CHECK(to_string(f) == "(1.41 m,1.41 m,3 m;20\u00B0,40\u00B0)");
		coordinates_3dr<> g;
		g = "2 m,45\u00B0,20\u00B0;20\u00B0,40\u00B0";
		CHECK(to_string(g) == "(0.48 m,0.48 m,1.87 m;20\u00B0,40\u00B0)");
	}

	SECTION("Assignments of coordinates_3dr<float> class")
	{
		coordinates_3dr<float> a;
		coordinates_3dr<float> a2(5.0f,5.0f,1.0f,angle(20.0f),angle(30.0f));
		a = a2;
		CHECK(to_string(a) == "(5,5,1;20\u00B0,30\u00B0)");
		coordinates_3dr<float> b;
		coordinates_3dr<float> b2(5.0f,5.0f,1.0f,angle(20.0f),angle(30.0f));
		b = std::move(b2);
		CHECK(to_string(b) == "(5,5,1;20\u00B0,30\u00B0)");
		coordinates_3dr<float> c;
		coordinates_3dr<float> d;
		coordinates_3d<float> d2(100.0f,1.0f,2.0f);
		d = d2;
		CHECK(to_string(d) == "(100,1,2;0\u00B0,0\u00B0)");
		coordinates_3dr<float> d3;
		coordinates_3d<float> d4(100.0f,1.0f,2.0f);
		d3 = std::move(d4);
		CHECK(to_string(d3) == "(100,1,2;0\u00B0,0\u00B0)");
		coordinates_3dr<float> d5;
		d5 = "(1,5,2;0\u00B0,0\u00B0)";
		CHECK(to_string(d5) == "(1,5,2;0\u00B0,0\u00B0)");
		coordinates_3dr<float> e;
		e = "1,5,2;0\u00B0,0\u00B0";
		CHECK(to_string(e) == "(1,5,2;0\u00B0,0\u00B0)");
		coordinates_3dr<float> f;
		f = "2,45\u00B0,3;20\u00B0,40\u00B0";
		CHECK(to_string(f) == "(1.41,1.41,3;20\u00B0,40\u00B0)");
		coordinates_3dr<float> g;
		g = "2,45\u00B0,20\u00B0;20\u00B0,40\u00B0";
		CHECK(to_string(g) == "(0.48,0.48,1.87;20\u00B0,40\u00B0)");
	}

	SECTION("Origin of coordinates_3dr<> class")
	{
		coordinates_3dr<> a(2_m,3_m,5_m,angle(30.0f),angle(20.0f));
		coordinates_3dr<> b = coordinates_3dr<>::origin(a,coordinates_3dr<>(1_m,8_m,3_m,30.0_degree,20.0_degree));
		CHECK(b.x == 3_m);
		CHECK(b.y == 11_m);
		CHECK(b.z == 8_m);
	}

	SECTION("Values of different coordinates systems of coordinates_3dr<> class")
	{
		coordinates_3dr<> c(7_m,4_m,2_m,angle(20.0f),angle(30.0f));
		CHECK(c.get_p().display() == "8.06 m");
		CHECK(c.get_spherical_theta().display() == "29.74\u00B0");
		CHECK(c.get_r().display() == "8.3 m");
		CHECK(c.get_spherical_phi().display() == "76.06\u00B0");
	}

	SECTION("Values of different coordinates systems of coordinates_3dr<float> class")
	{
		coordinates_3dr<float> c(7.0f,4.0f,2.0f,angle(20.0f),angle(30.0f));
		CHECK(std::fabs(c.get_p() - 8.06f) < 0.01f);
		CHECK(c.get_spherical_theta().display() == "29.74\u00B0");
		CHECK(std::fabs(c.get_r() - 8.3f) < 0.01f);
		CHECK(c.get_spherical_phi().display() == "76.06\u00B0");
	}

	SECTION("Geographic coordinates of coordinates_3dr<> class")
	{
		coordinates_3dr<> a(100000_m,100000_m,6371000_m,angle(50.0f),angle(20.0f));
		CHECK(to_string(a.get_latitude()) == "88.73\u00B0");
		CHECK(to_string(a.get_longitude()) == "45\u00B0");
		CHECK(to_string(a.get_altitude()) == "15806.6 m");
	}

	SECTION("Geographic coordinates of coordinates_3dr<float> class")
	{
		coordinates_3d<float> a(100000.0f,100000.0f,6371000.0f);
		CHECK(to_string(a.get_latitude()) == "88.73\u00B0");
		CHECK(to_string(a.get_longitude()) == "45\u00B0");
		CHECK(std::fabs(a.get_altitude() - 15806.44f) < 0.01f);
	}

	SECTION("set_position(), rotate() and move() of coordinates_3dr<> class")
	{
		coordinates_3dr<> a;
		a.set_position(5_m,5_m,1_m);
		CHECK(to_string(a) == "(5 m,5 m,1 m;0\u00B0,0\u00B0)");
		a.set_position(5_m,angle(30.0f),1_m);
		CHECK(to_string(a) == "(4.33 m,2.5 m,1 m;0\u00B0,0\u00B0)");
		a.set_position(5_m,angle(30.0f),angle(45.0f));
		CHECK(to_string(a) == "(3.06 m,1.76 m,3.53 m;0\u00B0,0\u00B0)");
		/*a.set_position(angle(30.0f),angle(45.0f),100_m);
		cout << "geographical coordinates: " << to_string(a) << endl;
		CHECK(to_string(a) == "(61.23 m,61.23 m,50 m)");*/
		coordinates_3dr<> b(5_m,3_m,1_m,angle(20.0f),angle(30.0f));
		b.rotate_in_x(angle(45.0f));
		CHECK(to_string(b) == "(5 m,1.41 m,2.82 m;20\u00B0,30\u00B0)");
		coordinates_3dr<> c(7_m,4_m,2_m,angle(20.0f),angle(30.0f));
		c.rotate_in_y(angle(45.0f));
		CHECK(to_string(c) == "(3.53 m,4 m,6.36 m;20\u00B0,30\u00B0)");
		coordinates_3dr<> d(4_m,2_m,3_m,angle(20.0f),angle(30.0f));
		d.rotate_in_z(angle(45.0f));
		CHECK(to_string(d) == "(1.41 m,4.24 m,3 m;20\u00B0,30\u00B0)");
		coordinates_3dr<> e(1_m,2_m,3_m,angle(20.0f),angle(30.0f));
		displacement_3d e2(3_m,angle(0.0f),angle(0.0f));
		e.move(e2);
		CHECK(to_string(e) == "(1 m,2 m,6 m;20\u00B0,30\u00B0)");
		coordinates_3dr<> f(1_m,2_m,3_m,angle(20.0f),angle(30.0f));
		f.move(2_m,1_m,3_m);
		CHECK(to_string(f) == "(3 m,3 m,6 m;20\u00B0,30\u00B0)");
		coordinates_3dr<> g(1_m,2_m,3_m,angle(20.0f),angle(30.0f));
		g.move(2_m,angle(45.0f),3_m);
		CHECK(to_string(g) == "(2.41 m,3.41 m,6 m;20\u00B0,30\u00B0)");
		coordinates_3dr<> h(1_m,2_m,3_m,angle(20.0f),angle(30.0f));
		h.move(2_m,angle(0.0f),angle(45.0f));
		CHECK(to_string(h) == "(2.41 m,2 m,4.41 m;20\u00B0,30\u00B0)");
	}

	SECTION("set_position(), rotate() and move() of coordinates_3dr<float> class")
	{
		coordinates_3dr<float> a;
		a.set_position(5.0f,5.0f,1.0f);
		CHECK(to_string(a) == "(5,5,1;0\u00B0,0\u00B0)");
		a.set_position(5.0f,angle(30.0f),1.0f);
		CHECK(to_string(a) == "(4.33,2.5,1;0\u00B0,0\u00B0)");
		a.set_position(5.0f,angle(30.0f),angle(45.0f));
		CHECK(to_string(a) == "(3.06,1.76,3.53;0\u00B0,0\u00B0)");
		/*a.set_position(angle(30.0f),angle(45.0f),100_m);
		cout << "geographical coordinates: " << to_string(a) << endl;
		CHECK(to_string(a) == "(61.23 m,61.23 m,50 m)");*/
		coordinates_3dr<float> b(5.0f,3.0f,1.0f,angle(20.0f),angle(30.0f));
		b.rotate_in_x(angle(45.0f));
		CHECK(to_string(b) == "(5,1.41,2.82;20\u00B0,30\u00B0)");
		coordinates_3dr<float> c(7.0f,4.0f,2.0f,angle(20.0f),angle(30.0f));
		c.rotate_in_y(angle(45.0f));
		CHECK(to_string(c) == "(3.53,4,6.36;20\u00B0,30\u00B0)");
		coordinates_3dr<float> d(4.0f,2.0f,3.0f,angle(20.0f),angle(30.0f));
		d.rotate_in_z(angle(45.0f));
		CHECK(to_string(d) == "(1.41,4.24,3;20\u00B0,30\u00B0)");
		coordinates_3dr<float> e(1.0f,2.0f,3.0f,angle(20.0f),angle(30.0f));
		displacement_3d e2(3_m,angle(0.0f),angle(0.0f));
		e.move(e2);
		CHECK(to_string(e) == "(1,2,6;20\u00B0,30\u00B0)");
		coordinates_3dr<float> f(1.0f,2.0f,3.0f,angle(20.0f),angle(30.0f));
		f.move(2.0f,1.0f,3.0f);
		CHECK(to_string(f) == "(3,3,6;20\u00B0,30\u00B0)");
		coordinates_3dr<float> g(1.0f,2.0f,3.0f,angle(20.0f),angle(30.0f));
		g.move(2.0f,angle(45.0f),3.0f);
		CHECK(to_string(g) == "(2.41,3.41,6;20\u00B0,30\u00B0)");
		coordinates_3dr<float> h(1.0f,2.0f,3.0f,angle(20.0f),angle(30.0f));
		h.move(2.0f,angle(0.0f),angle(45.0f));
		CHECK(to_string(h) == "(2.41,2,4.41;20\u00B0,30\u00B0)");
	}

	SECTION("Display of coordinates_3dr<> class")
	{
		coordinates_3dr<> a(2_m,3_m,5_m,angle(20.0f),angle(30.0f));
		CHECK(a.display_cartesian() == "(2 m,3 m,5 m;20\u00B0,30\u00B0)");
		CHECK(a.display_cylindrical() == "(3.6 m,56.3\u00B0,5 m;20\u00B0,30\u00B0)");
		CHECK(a.display_spherical() == "(6.16 m,56.3\u00B0,35.79\u00B0;20\u00B0,30\u00B0)");
		/*coordinates_3dr<> b(2_m,3_m,10000_km);
		cout << "b display geographical: " << b.display_geographical() << endl;
		CHECK(b.display_geographical() == "");*/
	}

	SECTION("Display of coordinates_3dr<float> class")
	{
		coordinates_3dr<float> a(2.0f,3.0f,5.0f,angle(20.0f),angle(30.0f));
		CHECK(a.display_cartesian() == "(2,3,5;20\u00B0,30\u00B0)");
		CHECK(a.display_cylindrical() == "(3.6,56.3\u00B0,5;20\u00B0,30\u00B0)");
		CHECK(a.display_spherical() == "(6.16,56.3\u00B0,35.79\u00B0;20\u00B0,30\u00B0)");
		/*coordinates_3dr<> b(2_m,3_m,10000_km);
		cout << "b display geographical: " << b.display_geographical() << endl;
		CHECK(b.display_geographical() == "");*/
	}

	SECTION("to_string() of coordinates_3dr<> class")
	{
		coordinates_3dr<> a(2_m,3_m,5_m,angle(20.0f),angle(30.0f));
		CHECK(to_string(a) == "(2 m,3 m,5 m;20\u00B0,30\u00B0)");
	}

	SECTION("to_string() of coordinates_3dr<float> class")
	{
		coordinates_3dr<float> a(2.0f,3.0f,5.0f,angle(20.0f),angle(30.0f));
		CHECK(to_string(a) == "(2,3,5;20\u00B0,30\u00B0)");
	}

	SECTION("distance() of coordinates_3dr<> class")
	{
		coordinates_3dr<> a(7_m,3_m,1_m,angle(20.0f),angle(30.0f));
		coordinates_3dr<> b(6_m,2_m,1_m,angle(20.0f),angle(30.0f));
		CHECK(distance(a,b).display() == "1.41 m");
		coordinates_3d<> d(7_m,3_m,1_m);
		CHECK(distance(a,d).display() == "0 m");
		CHECK(distance(d,a).display() == "0 m");
		CHECK(distance(b,d).display() == "1.41 m");
		CHECK(distance(d,b).display() == "1.41 m");
	}

	SECTION("distance() of coordinates_3dr<float> class")
	{
		coordinates_3dr<float> a(7.0f,3.0f,1.0f,angle(20.0f),angle(30.0f));
		coordinates_3dr<float> b(6.0f,2.0f,1.0f,angle(20.0f),angle(30.0f));
		CHECK(std::fabs(distance(a,b) - 1.41f) < 0.01f);
		coordinates_3d<float> d(7.0f,3.0f,1.0f);
		CHECK(distance(a,d) == 0.0f);
		CHECK(distance(d,a) == 0.0f);
		CHECK(std::fabs(distance(b,d) - 1.41f) < 0.01f);
		CHECK(std::fabs(distance(d,b) - 1.41f) < 0.01f);
	}

	SECTION("Relational operators of coordinates_3dr<> class")
	{
		coordinates_3dr<> a(7_m,3_m,1_m,angle(20.0f),angle(30.0f));
		coordinates_3dr<> b(7_m,3_m,1_m,angle(20.0f),angle(30.0f));
		coordinates_3dr<> c(6_m,2_m,1_m,angle(20.0f),angle(30.0f));
		CHECK(bool(a == b));
		CHECK((a == c) == false);
		CHECK(bool(a != c));
	}

	SECTION("Relational operators of coordinates_3dr<float> class")
	{
		coordinates_3dr<float> a(7.0f,3.0f,1.0f,angle(20.0f),angle(30.0f));
		coordinates_3dr<float> b(7.0f,3.0f,1.0f,angle(20.0f),angle(30.0f));
		coordinates_3dr<float> c(6.0f,2.0f,1.0f,angle(20.0f),angle(30.0f));
		CHECK(bool(a == b));
		CHECK((a == c) == false);
		CHECK(bool(a != c));
	}

	SECTION("String operators of coordinates_3dr<> class")
	{
		coordinates_3dr<> a(7_m,4_m,2_m,angle(20.0f),angle(30.0f));
		CHECK(bool(a == "(7 m,4 m,2 m;20\u00B0,30\u00B0)"));
		CHECK(bool(a != "(6 m,3 m,2 m;20\u00B0,30\u00B0)"));
		CHECK(bool("(7 m,4 m,2 m;20\u00B0,30\u00B0)" == a));
		CHECK(bool("(6 m,3 m,2 m;20\u00B0,30\u00B0)" != a));
		string b = "x: ";
		b += a;
		CHECK(b == "x: (7 m,4 m,2 m;20\u00B0,30\u00B0)");
		CHECK(("x: " + a) == "x: (7 m,4 m,2 m;20\u00B0,30\u00B0)");
		CHECK("x: (7 m,4 m,2 m;20\u00B0,30\u00B0)" == ("x: " + a));
	}

	SECTION("String operators of coordinates_3dr<float> class")
	{
		coordinates_3dr<float> a(7.0f,4.0f,2.0f,angle(20.0f),angle(30.0f));
		CHECK(bool(a == "(7,4,2;20\u00B0,30\u00B0)"));
		CHECK(bool(a != "(6,3,2;20\u00B0,30\u00B0)"));
		CHECK(bool("(7,4,2;20\u00B0,30\u00B0)" == a));
		CHECK(bool("(6,3,2;20\u00B0,30\u00B0)" != a));
		string b = "x: ";
		b += a;
		CHECK(b == "x: (7,4,2;20\u00B0,30\u00B0)");
		CHECK(("x: " + a) == "x: (7,4,2;20\u00B0,30\u00B0)");
		CHECK("x: (7,4,2;20\u00B0,30\u00B0)" == ("x: " + a));
	}

	SECTION("Stream operators of coordinates_3dr<> class")
	{
		coordinates_3dr<> a(2_m,3_m,2_m,angle(20.0f),angle(30.0f));
		ostringstream out;
		out << a;
		CHECK(out.str() == "(2 m,3 m,2 m;20\u00B0,30\u00B0)");
		istringstream iss("(1 m,2 m,1 m;30\u00B0,40\u00B0)");
		coordinates_3dr<> b;
		iss >> b;
		CHECK(to_string(b) == "(1 m,2 m,1 m;30\u00B0,40\u00B0)");
	}

	SECTION("Stream operators of coordinates_3dr<float> class")
	{
		coordinates_3dr<float> a(2.0f,3.0f,2.0f,angle(20.0f),angle(30.0f));
		ostringstream out;
		out << a;
		CHECK(out.str() == "(2,3,2;20\u00B0,30\u00B0)");
		istringstream iss("(1,2,1;30\u00B0,40\u00B0)");
		coordinates_3dr<float> b;
		iss >> b;
		CHECK(to_string(b) == "(1,2,1;30\u00B0,40\u00B0)");
	}
}
