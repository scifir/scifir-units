#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../coordinates/coordinates_nd.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class coordinates_nd<T> and coordinates_nd<float>")
{
	SECTION("Constructors of coordinates_nd<> class")
	{
		coordinates_nd<> a;
		CHECK(to_string(a) == "[empty]");
		coordinates_nd<> a2(5_m,5_m,1_m);
		coordinates_nd<> a3(a2);
		CHECK(to_string(a3) == "(5 m,5 m,1 m)");
		coordinates_nd<> a4(5_m,5_m,1_m);
		coordinates_nd<> a5(move(a4));
		CHECK(to_string(a5) == "(5 m,5 m,1 m)");
		coordinates_nd<> b6(8_m);
		CHECK(to_string(b6) == "(8 m)");
		coordinates_nd<> b7(6_m,4_m);
		CHECK(to_string(b7) == "(6 m,4 m)");
		coordinates_nd<> b8(100_m,angle(90.0f));
		CHECK(to_string(b8) == "(0 m,100 m)");
		coordinates_nd<> b(100_m,10_m,1_m);
		CHECK(to_string(b) == "(100 m,10 m,1 m)");
		coordinates_nd<> b2(100_m,angle(90),1_m);
		CHECK(to_string(b2) == "(0 m,100 m,1 m)");
		coordinates_nd<> b3(100_m,angle(0),angle(0));
		CHECK(to_string(b3) == "(0 m,0 m,100 m)");
		coordinates_nd<> b4(vector<length>{100_m,50_m,20_m});
		CHECK(to_string(b4) == "(100 m,50 m,20 m)");
		//coordinates_nd<> b4(angle(0),angle(0),10_m);
		//CHECK(to_string(b4) == "(0 m,0 m,100 m)");
		point_nd<> c2(100_m,1_m,2_m);
		coordinates_nd<> c(c2);
		CHECK(to_string(c) == "(100 m,1 m,2 m)");
		point_nd<> c4(100_m,1_m,2_m);
		coordinates_nd<> c3(std::move(c4));
		CHECK(to_string(c3) == "(100 m,1 m,2 m)");
		coordinates_nd<> d("(1 m)");
		CHECK(to_string(d) == "(1 m)");
		coordinates_nd<> d2("(1 m,5 m)");
		CHECK(to_string(d2) == "(1 m,5 m)");
		coordinates_nd<> d3("(1 m,45\u00B0)");
		CHECK(to_string(d3) == "(0.7 m,0.7 m)");
		coordinates_nd<> d4("(1 m,5 m,2 m)");
		CHECK(to_string(d4) == "(1 m,5 m,2 m)");
		coordinates_nd<> e("1 m,5 m,2 m");
		CHECK(to_string(e) == "(1 m,5 m,2 m)");
		coordinates_nd<> f("2 m,45\u00B0,3 m");
		CHECK(to_string(f) == "(1.41 m,1.41 m,3 m)");
		coordinates_nd<> g("2 m,45\u00B0,20\u00B0");
		CHECK(to_string(g) == "(0.48 m,0.48 m,1.87 m)");
		coordinates_nd<> h(",,");
		CHECK(to_string(h) == "[empty]");
	}

	SECTION("Constructors of coordinates_nd<float> class")
	{
		coordinates_nd<float> a;
		CHECK(to_string(a) == "[empty]");
		coordinates_nd<float> a2(5.0f,5.0f,1.0f);
		coordinates_nd<float> a3(a2);
		CHECK(to_string(a3) == "(5,5,1)");
		coordinates_nd<float> a4(5.0f,5.0f,1.0f);
		coordinates_nd<float> a5(move(a4));
		CHECK(to_string(a5) == "(5,5,1)");
		coordinates_nd<float> b(100.0f,10.0f,1.0f);
		CHECK(to_string(b) == "(100,10,1)");
		coordinates_nd<float> b2(100.0f,angle(90),1.0f);
		CHECK(to_string(b2) == "(0,100,1)");
		coordinates_nd<float> b3(100.0f,angle(0),angle(0));
		CHECK(to_string(b3) == "(0,0,100)");
		coordinates_nd<float> b4(vector<float>{100.0f,50.0f,20.0f});
		CHECK(to_string(b4) == "(100,50,20)");
		//coordinates_nd<> b4(angle(0),angle(0),10_m);
		//CHECK(to_string(b4) == "(0 m,0 m,100 m)");
		point_nd<float> c2(100.0f,1.0f,2.0f);
		coordinates_nd<float> c(c2);
		CHECK(to_string(c) == "(100,1,2)");
		point_nd<float> c4(100.0f,1.0f,2.0f);
		coordinates_nd<float> c3(std::move(c4));
		CHECK(to_string(c3) == "(100,1,2)");
		coordinates_nd<float> d("(1)");
		CHECK(to_string(d) == "(1)");
		coordinates_nd<float> d2("(1,5)");
		CHECK(to_string(d2) == "(1,5)");
		coordinates_nd<float> d3("(1,45\u00B0)");
		CHECK(to_string(d3) == "(0.7,0.7)");
		coordinates_nd<float> d4("(1,5,2)");
		CHECK(to_string(d4) == "(1,5,2)");
		coordinates_nd<float> e("1,5,2");
		CHECK(to_string(e) == "(1,5,2)");
		coordinates_nd<float> f("2,45\u00B0,3");
		CHECK(to_string(f) == "(1.41,1.41,3)");
		coordinates_nd<float> g("2,45\u00B0,20\u00B0");
		CHECK(to_string(g) == "(0.48,0.48,1.87)");
	}

	SECTION("Assignments of coordinates_nd<> class")
	{
		coordinates_nd<> a;
		coordinates_nd<> a2(5_m,5_m,1_m);
		a = a2;
		CHECK(to_string(a) == "(5 m,5 m,1 m)");
		coordinates_nd<> b;
		coordinates_nd<> b2(5_m,5_m,1_m);
		b = std::move(b2);
		CHECK(to_string(b) == "(5 m,5 m,1 m)");
		coordinates_nd<> c;
		point_nd<> c2(100_m,1_m,2_m);
		c = c2;
		CHECK(to_string(c) == "(100 m,1 m,2 m)");
		coordinates_nd<> c3;
		point_nd<> c4(100_m,1_m,2_m);
		c3 = std::move(c4);
		CHECK(to_string(c3) == "(100 m,1 m,2 m)");
		coordinates_nd<> d;
		d = "(1 m)";
		CHECK(to_string(d) == "(1 m)");
		coordinates_nd<> d2;
		d2 = "(1 m,5 m)";
		CHECK(to_string(d2) == "(1 m,5 m)");
		coordinates_nd<> d3;
		d3 = "(1 m,45\u00B0)";
		CHECK(to_string(d3) == "(0.7 m,0.7 m)");
		coordinates_nd<> d4;
		d4 = "(1 m,5 m,2 m)";
		CHECK(to_string(d4) == "(1 m,5 m,2 m)");
		coordinates_nd<> e;
		e = "1 m,5 m,2 m";
		CHECK(to_string(e) == "(1 m,5 m,2 m)");
		coordinates_nd<> f;
		f = "2 m,45\u00B0,3 m";
		CHECK(to_string(f) == "(1.41 m,1.41 m,3 m)");
		coordinates_nd<> g;
		g = "2 m,45\u00B0,20\u00B0";
		CHECK(to_string(g) == "(0.48 m,0.48 m,1.87 m)");
	}

	SECTION("Assignments of coordinates_nd<float> class")
	{
		coordinates_nd<float> a;
		coordinates_nd<float> a2(5.0f,5.0f,1.0f);
		a = a2;
		CHECK(to_string(a) == "(5,5,1)");
		coordinates_nd<float> b;
		coordinates_nd<float> b2(5.0f,5.0f,1.0f);
		b = std::move(b2);
		CHECK(to_string(b) == "(5,5,1)");
		coordinates_nd<float> c;
		point_nd<float> c2(100.0f,1.0f,2.0f);
		c = c2;
		CHECK(to_string(c) == "(100,1,2)");
		coordinates_nd<float> c3;
		point_nd<float> c4(100.0f,1.0f,2.0f);
		c3 = std::move(c4);
		CHECK(to_string(c3) == "(100,1,2)");
		coordinates_nd<float> d;
		d = "(1)";
		CHECK(to_string(d) == "(1)");
		coordinates_nd<float> d2;
		d2 = "(1,5)";
		CHECK(to_string(d2) == "(1,5)");
		coordinates_nd<float> d3;
		d3 = "(1,45\u00B0)";
		CHECK(to_string(d3) == "(0.7,0.7)");
		coordinates_nd<float> d4;
		d4 = "(1,5,2)";
		CHECK(to_string(d4) == "(1,5,2)");
		coordinates_nd<float> e;
		e = "1,5,2";
		CHECK(to_string(e) == "(1,5,2)");
		coordinates_nd<float> f;
		f = "2,45\u00B0,3";
		CHECK(to_string(f) == "(1.41,1.41,3)");
		coordinates_nd<float> g;
		g = "2,45\u00B0,20\u00B0";
		CHECK(to_string(g) == "(0.48,0.48,1.87)");
	}

	SECTION("Origin of coordinates_nd<> class")
	{
		coordinates_nd<> a(vector<length>{2_m,3_m,5_m,4_m});
		coordinates_nd<> b = coordinates_nd<>::origin(a,coordinates_nd<>(vector<length>{1_m,8_m,3_m,2_m}));
		CHECK(b.values[0] == 3_m);
		CHECK(b.values[1] == 11_m);
		CHECK(b.values[2] == 8_m);
		CHECK(b.values[3] == 6_m);
	}

	SECTION("Values of different coordinates systems of coordinates_nd<> class")
	{
		coordinates_nd<> a(7_m,4_m,2_m);
		CHECK(a.get_p().display() == "8.06 m");
		CHECK(a.get_theta().display() == "29.74\u00B0");
		CHECK(a.get_r().display() == "8.3 m");
		CHECK(a.get_phi().display() == "76.06\u00B0");
		coordinates_nd<> b(7_m);
		CHECK(bool(b.get_p() == length()));
		CHECK(bool(b.get_theta() == angle()));
		CHECK(bool(b.get_r() == length()));
		CHECK(bool(b.get_phi() == angle()));
	}

	SECTION("Values of different coordinates systems of coordinates_nd<float> class")
	{
		coordinates_nd<float> c(7.0f,4.0f,2.0f);
		CHECK(std::fabs(c.get_p() - 8.06f) < 0.01f);
		CHECK(c.get_theta().display() == "29.74\u00B0");
		CHECK(std::fabs(c.get_r() - 8.3f) < 0.01f);
		CHECK(c.get_phi().display() == "76.06\u00B0");
		coordinates_nd<float> b(7.0f);
		CHECK(b.get_p() == 0.0f);
		CHECK(bool(b.get_theta() == angle()));
		CHECK(b.get_r() == 0.0f);
		CHECK(bool(b.get_phi() == angle()));
	}

	SECTION("Geographic coordinates of coordinates_nd<> class")
	{
		coordinates_nd<> a(vector<length>{100000_m,100000_m,6371000_m});
		CHECK(to_string(a.get_latitude()) == "88.73\u00B0");
		CHECK(to_string(a.get_longitude()) == "45\u00B0");
		CHECK(to_string(a.get_altitude()) == "15806.6 m");
	}

	SECTION("Geographic coordinates of coordinates_nd<float> class")
	{
		coordinates_nd<float> a(vector<float>{100000.0f,100000.0f,6371000.0f});
		CHECK(to_string(a.get_latitude()) == "88.73\u00B0");
		CHECK(to_string(a.get_longitude()) == "45\u00B0");
		CHECK(std::fabs(a.get_altitude() - 15806.44f) < 0.01f);
	}

	SECTION("set_position(), rotate() and move() of coordinates_nd<> class")
	{
		coordinates_nd<> a;
		a.set_position(5_m,5_m,1_m);
		CHECK(to_string(a) == "(5 m,5 m,1 m)");
		a.set_position(5_m,angle(30.0f),1_m);
		CHECK(to_string(a) == "(4.33 m,2.5 m,1 m)");
		a.set_position(5_m,angle(30.0f),angle(45.0f));
		CHECK(to_string(a) == "(3.06 m,1.76 m,3.53 m)");
		/*a.set_position(angle(30.0f),angle(45.0f),100_m);
		cout << "geographical coordinates: " << to_string(a) << endl;
		CHECK(to_string(a) == "(61.23 m,61.23 m,50 m)");*/
		coordinates_nd<> b2(20_m,angle(60.0f));
		b2.rotate_in_2d(angle(15.0f));
		CHECK(to_string(b2) == "(5.17 m,19.31 m)");
		coordinates_nd<> b(5_m,3_m,1_m);
		b.rotate_in_3d(1,angle(45.0f));
		CHECK(to_string(b) == "(5 m,1.41 m,2.82 m)");
		coordinates_nd<> c(7_m,4_m,2_m);
		c.rotate_in_3d(2,angle(45.0f));
		CHECK(to_string(c) == "(3.53 m,4 m,6.36 m)");
		coordinates_nd<> d(4_m,2_m,3_m);
		d.rotate_in_3d(3,angle(45.0f));
		CHECK(to_string(d) == "(1.41 m,4.24 m,3 m)");
		coordinates_nd<> e(1_m,2_m,3_m);
		displacement_3d e2(3_m,angle(0.0f),angle(0.0f));
		e.move(e2);
		CHECK(to_string(e) == "(1 m,2 m,6 m)");
		coordinates_nd<> f(1_m,2_m,3_m);
		f.move(2_m,1_m,3_m);
		CHECK(to_string(f) == "(3 m,3 m,6 m)");
		coordinates_nd<> g(1_m,2_m,3_m);
		g.move(2_m,angle(45.0f),3_m);
		CHECK(to_string(g) == "(2.41 m,3.41 m,6 m)");
		coordinates_nd<> h(1_m,2_m,3_m);
		h.move(2_m,angle(0.0f),angle(45.0f));
		CHECK(to_string(h) == "(2.41 m,2 m,4.41 m)");
	}

	SECTION("set_position(), rotate() and move() of coordinates_nd<float> class")
	{
		coordinates_nd<float> a;
		a.set_position(5.0f,5.0f,1.0f);
		CHECK(to_string(a) == "(5,5,1)");
		a.set_position(5.0f,angle(30.0f),1.0f);
		CHECK(to_string(a) == "(4.33,2.5,1)");
		a.set_position(5.0f,angle(30.0f),angle(45.0f));
		CHECK(to_string(a) == "(3.06,1.76,3.53)");
		/*a.set_position(angle(30.0f),angle(45.0f),100_m);
		cout << "geographical coordinates: " << to_string(a) << endl;
		CHECK(to_string(a) == "(61.23 m,61.23 m,50 m)");*/
		coordinates_nd<float> b2(20.0f,angle(60.0f));
		b2.rotate_in_2d(angle(15.0f));
		CHECK(to_string(b2) == "(5.17,19.31)");
		coordinates_nd<float> b(5.0f,3.0f,1.0f);
		b.rotate_in_3d(1,angle(45.0f));
		CHECK(to_string(b) == "(5,1.41,2.82)");
		coordinates_nd<float> c(7.0f,4.0f,2.0f);
		c.rotate_in_3d(2,angle(45.0f));
		CHECK(to_string(c) == "(3.53,4,6.36)");
		coordinates_nd<float> d(4.0f,2.0f,3.0f);
		d.rotate_in_3d(3,angle(45.0f));
		CHECK(to_string(d) == "(1.41,4.24,3)");
		coordinates_nd<float> e(1.0f,2.0f,3.0f);
		displacement_3d e2(3_m,angle(0.0f),angle(0.0f));
		e.move(e2);
		CHECK(to_string(e) == "(1,2,6)");
		coordinates_nd<float> f(1.0f,2.0f,3.0f);
		f.move(2.0f,1.0f,3.0f);
		CHECK(to_string(f) == "(3,3,6)");
		coordinates_nd<float> g(1.0f,2.0f,3.0f);
		g.move(2.0f,angle(45.0f),3.0f);
		CHECK(to_string(g) == "(2.41,3.41,6)");
		coordinates_nd<float> h(1.0f,2.0f,3.0f);
		h.move(2.0f,angle(0.0f),angle(45.0f));
		CHECK(to_string(h) == "(2.41,2,4.41)");
	}

	SECTION("Display of coordinates_nd<> class")
	{
		coordinates_nd<> a(2_m,3_m,5_m);
		CHECK(a.display_cartesian_2d() == "[no-2d]");
		CHECK(a.display_polar() == "[no-2d]");
		CHECK(a.display_cartesian_3d() == "(2 m,3 m,5 m)");
		CHECK(a.display_cylindrical() == "(3.6 m,56.3\u00B0,5 m)");
		CHECK(a.display_spherical() == "(6.16 m,56.3\u00B0,35.79\u00B0)");
		coordinates_nd<> b(5_m,angle(30.0f));
		CHECK(b.display_cartesian_2d() == "(4.33 m,2.5 m)");
		CHECK(b.display_polar() == "(5 m,30\u00B0)");
		CHECK(b.display_cartesian_3d() == "[no-3d]");
		CHECK(b.display_cylindrical() == "[no-3d]");
		CHECK(b.display_spherical() == "[no-3d]");
		/*coordinates_nd<> b(2_m,3_m,10000_km);
		cout << "b display geographical: " << b.display_geographical() << endl;
		CHECK(b.display_geographical() == "");*/
	}

	SECTION("Display of coordinates_nd<float> class")
	{
		coordinates_nd<float> a(2.0f,3.0f,5.0f);
		CHECK(a.display_cartesian_2d() == "[no-2d]");
		CHECK(a.display_polar() == "[no-2d]");
		CHECK(a.display_cartesian_3d() == "(2,3,5)");
		CHECK(a.display_cylindrical() == "(3.6,56.3\u00B0,5)");
		CHECK(a.display_spherical() == "(6.16,56.3\u00B0,35.79\u00B0)");
		coordinates_nd<float> b(5.0f,angle(30.0f));
		CHECK(b.display_cartesian_2d() == "(4.33,2.5)");
		CHECK(b.display_polar() == "(5,30\u00B0)");
		CHECK(b.display_cartesian_3d() == "[no-3d]");
		CHECK(b.display_cylindrical() == "[no-3d]");
		CHECK(b.display_spherical() == "[no-3d]");
		/*coordinates_nd<float> b(2_m,3_m,10000_km);
		cout << "b display geographical: " << b.display_geographical() << endl;
		CHECK(b.display_geographical() == "");*/
	}

	SECTION("to_string() of coordinates_nd<> class")
	{
		coordinates_nd<> a(2_m,3_m,5_m);
		CHECK(to_string(a) == "(2 m,3 m,5 m)");
	}

	SECTION("to_string() of coordinates_nd<float> class")
	{
		coordinates_nd<float> a(2.0f,3.0f,5.0f);
		CHECK(to_string(a) == "(2,3,5)");
	}

	SECTION("distance() of coordinates_nd<> class")
	{
		coordinates_nd<> a(7_m,3_m,1_m);
		coordinates_nd<> b(6_m,2_m,1_m);
		CHECK(distance(a,b).display() == "1.41 m");
		coordinates_nd<> b2(6_m,2_m);
		CHECK(bool(distance(a,b2) == length()));
		point_nd<> c(7_m,3_m,1_m);
		CHECK(distance(a,c).display() == "0 m");
		CHECK(distance(c,a).display() == "0 m");
		CHECK(distance(b,c).display() == "1.41 m");
		CHECK(distance(c,b).display() == "1.41 m");
		point_nd<> c2(7_m,3_m);
		CHECK(bool(distance(a,c2) == length()));
		CHECK(bool(distance(c2,a) == length()));
	}

	SECTION("distance() of coordinates_nd<float> class")
	{
		coordinates_nd<float> a(7.0f,3.0f,1.0f);
		coordinates_nd<float> b(6.0f,2.0f,1.0f);
		CHECK(std::fabs(distance(a,b) - 1.41f) < 0.01f);
		coordinates_nd<float> b2(6.0f,2.0f);
		CHECK(distance(a,b2) == 0.0f);
		point_nd<float> c(7.0f,3.0f,1.0f);
		CHECK(std::fabs(distance(a,c) - 0.0f) < 0.01f);
		CHECK(std::fabs(distance(c,a) - 0.0f) < 0.01f);
		CHECK(std::fabs(distance(b,c) - 1.41f) < 0.01f);
		CHECK(std::fabs(distance(c,b) - 1.41f) < 0.01f);
		point_nd<float> c2(7.0f,3.0f);
		CHECK(distance(a,c2) == 0.0f);
		CHECK(distance(c2,a) == 0.0f);
	}

	SECTION("Relational operators of coordinates_nd<> class")
	{
		coordinates_nd<> a(7_m,3_m,1_m);
		coordinates_nd<> b(7_m,3_m,1_m);
		coordinates_nd<> c(6_m,2_m,1_m);
		coordinates_nd<> c2(6_m,2_m);
		CHECK(bool(a == b));
		CHECK((a == c) == false);
		CHECK((a == c2) == false);
		CHECK(bool(a != c));
		point_nd<> d(7_m,3_m,1_m);
		point_nd<> e(5_m,1_m,1_m);
		point_nd<> e2(5_m,1_m);
		CHECK(bool(a == d));
		CHECK(bool(a != e));
		CHECK((a == e2) == false);
		CHECK((e2 == a) == false);
		CHECK(bool(d == a));
		CHECK(bool(e != a));
	}

	SECTION("Relational operators of coordinates_nd<float> class")
	{
		coordinates_nd<float> a(7.0f,3.0f,1.0f);
		coordinates_nd<float> b(7.0f,3.0f,1.0f);
		coordinates_nd<float> c(6.0f,2.0f,1.0f);
		CHECK(bool(a == b));
		CHECK((a == c) == false);
		CHECK(bool(a != c));
		point_nd<float> d(7.0f,3.0f,1.0f);
		point_nd<float> e(5.0f,1.0f,1.0f);
		CHECK(bool(a == d));
		CHECK(bool(a != e));
		CHECK(bool(d == a));
		CHECK(bool(e != a));
	}

	SECTION("String operators of coordinates_nd<> class")
	{
		coordinates_nd<> a(7_m,4_m,2_m);
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

	SECTION("String operators of coordinates_nd<float> class")
	{
		coordinates_nd<float> a(7.0f,4.0f,2.0f);
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

	SECTION("Stream operators of coordinates_nd<> class")
	{
		coordinates_nd<> a(2_m,3_m,2_m);
		ostringstream out;
		out << a;
		CHECK(out.str() == "(2 m,3 m,2 m)");
		istringstream iss("(1 m,2 m,1 m)");
		coordinates_nd<> b;
		iss >> b;
		CHECK(to_string(b) == "(1 m,2 m,1 m)");
	}

	SECTION("Stream operators of coordinates_nd<float> class")
	{
		coordinates_nd<float> a(2.0f,3.0f,2.0f);
		ostringstream out;
		out << a;
		CHECK(out.str() == "(2,3,2)");
		istringstream iss("(1,2,1)");
		coordinates_nd<float> b;
		iss >> b;
		CHECK(to_string(b) == "(1,2,1)");
	}
}
