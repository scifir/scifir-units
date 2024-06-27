#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../coordinates/coordinates_ndr.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class coordinates_ndr","Complete test of coordinates_ndr")
{
	SECTION("Constructors of coordinates_ndr<> classes")
	{
		coordinates_ndr<> a;
		REQUIRE (bool(to_string(a) == "[empty]"));
		coordinates_ndr<> a2(5_m,5_m,1_m,angle(15.0f),angle(25.0f));
		coordinates_ndr<> a3(a2);
		REQUIRE (bool(to_string(a3) == "(5 m,5 m,1 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> a4(5_m,5_m,1_m,angle(15.0f),angle(25.0f));
		coordinates_ndr<> a5(std::move(a4));
		REQUIRE (bool(to_string(a5) == "(5 m,5 m,1 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> b(8_m);
		REQUIRE (bool(to_string(b) == "(8 m)"));
		coordinates_ndr<> b2(6_m,4_m,angle(20.0f));
		REQUIRE (bool(to_string(b2) == "(6 m,4 m;20\u00B0)"));
		coordinates_ndr<> b3(100_m,angle(90.0f),angle(20.0f));
		REQUIRE (bool(to_string(b3) == "(0 m,100 m;20\u00B0)"));
		coordinates_ndr<> b4(100_m,10_m,1_m,angle(15.0f),angle(25.0f));
		REQUIRE (bool(to_string(b4) == "(100 m,10 m,1 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> b5(100_m,angle(90),1_m,angle(15.0f),angle(25.0f));
		REQUIRE (bool(to_string(b5) == "(0 m,100 m,1 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> b6(100_m,angle(0),angle(0),angle(15.0f),angle(25.0f));
		REQUIRE (bool(to_string(b6) == "(0 m,0 m,100 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> b7(vector<length>{100_m,50_m,20_m},vector<angle>{angle(15.0f),angle(25.0f)});
		REQUIRE (bool(to_string(b7) == "(100 m,50 m,20 m;15\u00B0,25\u00B0)"));
		//coordinates_ndr<> b4(angle(0),angle(0),10_m);
		//REQUIRE (bool(to_string(b4) == "(0 m,0 m,100 m)"));
		point_nd<> c2(100_m,1_m,2_m);
		coordinates_ndr<> c(c2,{angle(15.0f),angle(25.0f)});
		REQUIRE (bool(to_string(c) == "(100 m,1 m,2 m;15\u00B0,25\u00B0)"));
		point_nd<> c4(100_m,1_m,2_m);
		coordinates_ndr<> c3(std::move(c4),{angle(15.0f),angle(25.0f)});
		REQUIRE (bool(to_string(c3) == "(100 m,1 m,2 m;15\u00B0,25\u00B0)"));
		coordinates_nd<> c6(100_m,1_m,2_m);
		coordinates_ndr<> c5(c6,{angle(15.0f),angle(25.0f)});
		REQUIRE (bool(to_string(c5) == "(100 m,1 m,2 m;15\u00B0,25\u00B0)"));
		coordinates_nd<> c8(100_m,1_m,2_m);
		coordinates_ndr<> c7(std::move(c8),{angle(15.0f),angle(25.0f)});
		REQUIRE (bool(to_string(c7) == "(100 m,1 m,2 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> d("(1 m)");
		REQUIRE (bool(to_string(d) == "(1 m)"));
		coordinates_ndr<> d2("(1 m,5 m;20\u00B0)");
		REQUIRE (bool(to_string(d2) == "(1 m,5 m;20\u00B0)"));
		coordinates_ndr<> d3("(1 m,45\u00B0;20\u00B0)");
		REQUIRE (bool(to_string(d3) == "(0.7 m,0.7 m;20\u00B0)"));
		coordinates_ndr<> d4("(1 m,5 m,2 m;15\u00B0,25\u00B0)");
		REQUIRE (bool(to_string(d4) == "(1 m,5 m,2 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> e("1 m,5 m,2 m;15\u00B0,25\u00B0");
		REQUIRE (bool(to_string(e) == "(1 m,5 m,2 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> f("2 m,45\u00B0,3 m;15\u00B0,25\u00B0");
		REQUIRE (bool(to_string(f) == "(1.41 m,1.41 m,3 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> g("2 m,45\u00B0,20\u00B0;15\u00B0,25\u00B0");
		REQUIRE (bool(to_string(g) == "(0.48 m,0.48 m,1.87 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> h("2 m,4 m,5 m,3 m;15\u00B0,25\u00B0,10\u00B0");
		REQUIRE (bool(to_string(h) == "(2 m,4 m,5 m,3 m;15\u00B0,25\u00B0,10\u00B0)"));
	}

	SECTION("Constructors of coordinates_ndr<float> classes")
	{
		coordinates_ndr<float> a;
		REQUIRE (bool(to_string(a) == "[empty]"));
		coordinates_ndr<float> a2(5.0f,5.0f,1.0f,angle(15.0f),angle(25.0f));
		coordinates_ndr<float> a3(a2);
		REQUIRE (bool(to_string(a3) == "(5,5,1;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> a4(5.0f,5.0f,1.0f,angle(15.0f),angle(25.0f));
		coordinates_ndr<float> a5(std::move(a4));
		REQUIRE (bool(to_string(a5) == "(5,5,1;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> b(8.0f);
		REQUIRE (bool(to_string(b) == "(8)"));
		coordinates_ndr<float> b2(6.0f,4.0f,angle(20.0f));
		REQUIRE (bool(to_string(b2) == "(6,4;20\u00B0)"));
		coordinates_ndr<float> b3(100.0f,angle(90.0f),angle(20.0f));
		REQUIRE (bool(to_string(b3) == "(0,100;20\u00B0)"));
		coordinates_ndr<float> b4(100.0f,10.0f,1.0f,angle(15.0f),angle(25.0f));
		REQUIRE (bool(to_string(b4) == "(100,10,1;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> b5(100.0f,angle(90),1.0f,angle(15.0f),angle(25.0f));
		REQUIRE (bool(to_string(b5) == "(0,100,1;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> b6(100.0f,angle(0),angle(0),angle(15.0f),angle(25.0f));
		REQUIRE (bool(to_string(b6) == "(0,0,100;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> b7(vector<float>{100.0f,50.0f,20.0f},vector<angle>{angle(15.0f),angle(25.0f)});
		REQUIRE (bool(to_string(b7) == "(100,50,20;15\u00B0,25\u00B0)"));
		//coordinates_ndr<> b4(angle(0),angle(0),10_m);
		//REQUIRE (bool(to_string(b4) == "(0 m,0 m,100 m)"));
		point_nd<float> c2(100.0f,1.0f,2.0f);
		coordinates_ndr<float> c(c2,{angle(15.0f),angle(25.0f)});
		REQUIRE (bool(to_string(c) == "(100,1,2;15\u00B0,25\u00B0)"));
		point_nd<float> c4(100.0f,1.0f,2.0f);
		coordinates_ndr<float> c3(std::move(c4),{angle(15.0f),angle(25.0f)});
		REQUIRE (bool(to_string(c3) == "(100,1,2;15\u00B0,25\u00B0)"));
		coordinates_nd<float> c6(100.0f,1.0f,2.0f);
		coordinates_ndr<float> c5(c6,{angle(15.0f),angle(25.0f)});
		REQUIRE (bool(to_string(c5) == "(100,1,2;15\u00B0,25\u00B0)"));
		coordinates_nd<float> c8(100.0f,1.0f,2.0f);
		coordinates_ndr<float> c7(std::move(c8),{angle(15.0f),angle(25.0f)});
		REQUIRE (bool(to_string(c7) == "(100,1,2;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> d("(1)");
		REQUIRE (bool(to_string(d) == "(1)"));
		coordinates_ndr<float> d2("(1,5;20\u00B0)");
		REQUIRE (bool(to_string(d2) == "(1,5;20\u00B0)"));
		coordinates_ndr<float> d3("(1,45\u00B0;20\u00B0)");
		REQUIRE (bool(to_string(d3) == "(0.7,0.7;20\u00B0)"));
		coordinates_ndr<float> d4("(1,5,2;15\u00B0,25\u00B0)");
		REQUIRE (bool(to_string(d4) == "(1,5,2;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> e("1,5,2;15\u00B0,25\u00B0");
		REQUIRE (bool(to_string(e) == "(1,5,2;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> f("2,45\u00B0,3;15\u00B0,25\u00B0");
		REQUIRE (bool(to_string(f) == "(1.41,1.41,3;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> g("2,45\u00B0,20\u00B0;15\u00B0,25\u00B0");
		REQUIRE (bool(to_string(g) == "(0.48,0.48,1.87;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> h("2,4,5,3;15\u00B0,25\u00B0,10\u00B0");
		REQUIRE (bool(to_string(h) == "(2,4,5,3;15\u00B0,25\u00B0,10\u00B0)"));
	}

	SECTION("Assignments of coordinates_ndr<> classes")
	{
		coordinates_ndr<> a;
		coordinates_ndr<> a2(5_m,5_m,1_m,angle(15.0f),angle(25.0f));
		a = a2;
		REQUIRE (bool(to_string(a) == "(5 m,5 m,1 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> b;
		coordinates_ndr<> b2(5_m,5_m,1_m,angle(15.0f),angle(25.0f));
		b = std::move(b2);
		REQUIRE (bool(to_string(b) == "(5 m,5 m,1 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> c(5_m,5_m,1_m,angle(15.0f),angle(25.0f));
		point_nd<> c2(100_m,1_m,2_m);
		c = c2;
		REQUIRE (bool(to_string(c) == "(100 m,1 m,2 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> c3(5_m,5_m,1_m,angle(15.0f),angle(25.0f));
		point_nd<> c4(100_m,1_m,2_m);
		c3 = std::move(c4);
		REQUIRE (bool(to_string(c3) == "(100 m,1 m,2 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> c5(5_m,5_m,1_m,angle(15.0f),angle(25.0f));
		point_nd<> c6(100_m,1_m,2_m);
		c5 = c6;
		REQUIRE (bool(to_string(c5) == "(100 m,1 m,2 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> c7(5_m,5_m,1_m,angle(15.0f),angle(25.0f));
		point_nd<> c8(100_m,1_m,2_m);
		c7 = std::move(c8);
		REQUIRE (bool(to_string(c7) == "(100 m,1 m,2 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> d;
		d = "(1 m)";
		REQUIRE (bool(to_string(d) == "(1 m)"));
		coordinates_ndr<> d2;
		d2 = "(1 m,5 m;20\u00B0)";
		REQUIRE (bool(to_string(d2) == "(1 m,5 m;20\u00B0)"));
		coordinates_ndr<> d3;
		d3 = "(1 m,45\u00B0;20\u00B0)";
		REQUIRE (bool(to_string(d3) == "(0.7 m,0.7 m;20\u00B0)"));
		coordinates_ndr<> d4;
		d4 = "(1 m,5 m,2 m;15\u00B0,25\u00B0)";
		REQUIRE (bool(to_string(d4) == "(1 m,5 m,2 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> e;
		e = "1 m,5 m,2 m;15\u00B0,25\u00B0";
		REQUIRE (bool(to_string(e) == "(1 m,5 m,2 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> f;
		f = "2 m,45\u00B0,3 m;15\u00B0,25\u00B0";
		REQUIRE (bool(to_string(f) == "(1.41 m,1.41 m,3 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> g;
		g = "2 m,45\u00B0,20\u00B0;15\u00B0,25\u00B0";
		REQUIRE (bool(to_string(g) == "(0.48 m,0.48 m,1.87 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> h;
		h = "2 m,4 m,5 m,3 m;15\u00B0,25\u00B0,10\u00B0";
		REQUIRE (bool(to_string(h) == "(2 m,4 m,5 m,3 m;15\u00B0,25\u00B0,10\u00B0)"));
	}

	SECTION("Assignments of coordinates_ndr<float> classes")
	{
		coordinates_ndr<float> a;
		coordinates_ndr<float> a2(5.0f,5.0f,1.0f,angle(15.0f),angle(25.0f));
		a = a2;
		REQUIRE (bool(to_string(a) == "(5,5,1;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> b;
		coordinates_ndr<float> b2(5.0f,5.0f,1.0f,angle(15.0f),angle(25.0f));
		b = std::move(b2);
		REQUIRE (bool(to_string(b) == "(5,5,1;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> c(5.0f,5.0f,1.0f,angle(15.0f),angle(25.0f));
		point_nd<float> c2(100.0f,1.0f,2.0f);
		c = c2;
		REQUIRE (bool(to_string(c) == "(100,1,2;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> c3(5.0f,5.0f,1.0f,angle(15.0f),angle(25.0f));
		point_nd<float> c4(100.0f,1.0f,2.0f);
		c3 = std::move(c4);
		REQUIRE (bool(to_string(c3) == "(100,1,2;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> c5(5.0f,5.0f,1.0f,angle(15.0f),angle(25.0f));
		coordinates_nd<float> c6(100.0f,1.0f,2.0f);
		c5 = c6;
		REQUIRE (bool(to_string(c5) == "(100,1,2;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> c7(5.0f,5.0f,1.0f,angle(15.0f),angle(25.0f));
		coordinates_nd<float> c8(100.0f,1.0f,2.0f);
		c7 = std::move(c8);
		REQUIRE (bool(to_string(c7) == "(100,1,2;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> d;
		d = "(1)";
		REQUIRE (bool(to_string(d) == "(1)"));
		coordinates_ndr<float> d2;
		d2 = "(1,5;20\u00B0)";
		REQUIRE (bool(to_string(d2) == "(1,5;20\u00B0)"));
		coordinates_ndr<float> d3;
		d3 = "(1,45\u00B0;20\u00B0)";
		REQUIRE (bool(to_string(d3) == "(0.7,0.7;20\u00B0)"));
		coordinates_ndr<float> d4;
		d4 = "(1,5,2;15\u00B0,25\u00B0)";
		REQUIRE (bool(to_string(d4) == "(1,5,2;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> e;
		e = "1,5,2;15\u00B0,25\u00B0";
		REQUIRE (bool(to_string(e) == "(1,5,2;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> f;
		f = "2,45\u00B0,3;15\u00B0,25\u00B0";
		REQUIRE (bool(to_string(f) == "(1.41,1.41,3;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> g;
		g = "2,45\u00B0,20\u00B0;15\u00B0,25\u00B0";
		REQUIRE (bool(to_string(g) == "(0.48,0.48,1.87;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> h;
		h = "2,4,5,3;15\u00B0,25\u00B0,10\u00B0";
		REQUIRE (bool(to_string(h) == "(2,4,5,3;15\u00B0,25\u00B0,10\u00B0)"));
	}

	SECTION("nd functions of coordinates_ndr<> classes")
	{
		coordinates_ndr<> a(7_m,4_m,2_m,angle(15.0f),angle(25.0f));
		REQUIRE (bool(a.is_nd(3) == true));
		REQUIRE (bool(a.get_nd() == 3));
		a.change_nd({2_m,3_m},vector<angle>{angle(10.0f)});
		REQUIRE (bool(to_string(a) == "(2 m,3 m;10\u00B0)"));
		a.change_nd({2_m,3_m,4_m,5_m},vector<float>{10.0f,20.0f,30.0f});
		REQUIRE (bool(to_string(a) == "(2 m,3 m,4 m,5 m;10\u00B0,20\u00B0,30\u00B0)"));
	}

	SECTION("nd functions of coordinates_ndr<float> classes")
	{
		coordinates_ndr<float> a(7.0f,4.0f,2.0f,angle(15.0f),angle(25.0f));
		REQUIRE (bool(a.is_nd(3) == true));
		REQUIRE (bool(a.get_nd() == 3));
		a.change_nd({2.0f,3.0f},vector<angle>{angle(10.0f)});
		REQUIRE (bool(to_string(a) == "(2,3;10\u00B0)"));
		a.change_nd({2.0f,3.0f,4.0f,5.0f},vector<float>{10.0f,20.0f,30.0f});
		REQUIRE (bool(to_string(a) == "(2,3,4,5;10\u00B0,20\u00B0,30\u00B0)"));
	}

	SECTION("Value and angle functions of coordinates_ndr<> classes")
	{
		coordinates_ndr<> a(7_m,4_m,2_m,angle(15.0f),angle(25.0f));
		REQUIRE (bool(a.get_values().size() == 3));
		REQUIRE (bool(a.get_value(0) == "7 m"));
		REQUIRE (bool(a.get_value(1) == "4 m"));
		REQUIRE (bool(a.get_value(2) == "2 m"));
		REQUIRE (bool(a.get_value(3) == "0 [empty]"));
		a.set_values({2_m,5_m,7_m});
		REQUIRE (bool(a.get_value(0) == "2 m"));
		REQUIRE (bool(a.get_value(1) == "5 m"));
		REQUIRE (bool(a.get_value(2) == "7 m"));
		REQUIRE (bool(a.get_angles().size() == 2));
		REQUIRE (bool(a.get_angle(0) == "15\u00B0"));
		REQUIRE (bool(a.get_angle(1) == "25\u00B0"));
		a.set_angles({angle(45.0f),angle(63.0f)});
		REQUIRE (bool(a.get_angle(0) == "45\u00B0"));
		REQUIRE (bool(a.get_angle(1) == "63\u00B0"));
		a.set_angles(vector<float>{40.0f,58.0f});
		REQUIRE (bool(a.get_angle(0) == "40\u00B0"));
		REQUIRE (bool(a.get_angle(1) == "58\u00B0"));
		REQUIRE (bool(a.get_angle(2) == "0\u00B0"));
		const coordinates_ndr<> b(7_m,4_m,2_m,angle(15.0f),angle(25.0f));
		REQUIRE (bool(b.get_values().size() == 3));
		REQUIRE (bool(b.get_value(0) == "7 m"));
		REQUIRE (bool(b.get_value(1) == "4 m"));
		REQUIRE (bool(b.get_value(2) == "2 m"));
		REQUIRE (bool(b.get_value(3) == "0 [empty]"));
		REQUIRE (bool(b.get_angles().size() == 2));
		REQUIRE (bool(b.get_angle(0) == "15\u00B0"));
		REQUIRE (bool(b.get_angle(1) == "25\u00B0"));
		REQUIRE (bool(b.get_angle(2) == "0\u00B0"));
	}

	SECTION("Value and angle functions of coordinates_ndr<float> classes")
	{
		coordinates_ndr<float> a(7.0f,4.0f,2.0f,angle(15.0f),angle(25.0f));
		REQUIRE (bool(a.get_values().size() == 3));
		REQUIRE (bool(a.get_value(0) == 7.0f));
		REQUIRE (bool(a.get_value(1) == 4.0f));
		REQUIRE (bool(a.get_value(2) == 2.0f));
		REQUIRE (bool(a.get_value(3) == 0.0f));
		a.set_values({2.0f,5.0f,7.0f});
		REQUIRE (bool(a.get_value(0) == 2.0f));
		REQUIRE (bool(a.get_value(1) == 5.0f));
		REQUIRE (bool(a.get_value(2) == 7.0f));
		REQUIRE (bool(a.get_angles().size() == 2));
		REQUIRE (bool(a.get_angle(0) == "15\u00B0"));
		REQUIRE (bool(a.get_angle(1) == "25\u00B0"));
		a.set_angles({angle(45.0f),angle(63.0f)});
		REQUIRE (bool(a.get_angle(0) == "45\u00B0"));
		REQUIRE (bool(a.get_angle(1) == "63\u00B0"));
		a.set_angles(vector<float>{40.0f,58.0f});
		REQUIRE (bool(a.get_angle(0) == "40\u00B0"));
		REQUIRE (bool(a.get_angle(1) == "58\u00B0"));
		REQUIRE (bool(a.get_angle(2) == "0\u00B0"));
		const coordinates_ndr<float> b(7.0f,4.0f,2.0f,angle(15.0f),angle(25.0f));
		REQUIRE (bool(b.get_values().size() == 3));
		REQUIRE (bool(b.get_value(0) == 7.0f));
		REQUIRE (bool(b.get_value(1) == 4.0f));
		REQUIRE (bool(b.get_value(2) == 2.0f));
		REQUIRE (bool(b.get_value(3) == 0.0f));
		REQUIRE (bool(b.get_angles().size() == 2));
		REQUIRE (bool(b.get_angle(0) == "15\u00B0"));
		REQUIRE (bool(b.get_angle(1) == "25\u00B0"));
		REQUIRE (bool(b.get_angle(2) == "0\u00B0"));
	}

	SECTION("Values of different coordinates systems of coordinates_ndr<> classes")
	{
		coordinates_ndr<> a(7_m,4_m,2_m,angle(15.0f),angle(25.0f));
		REQUIRE (bool(a.get_p().display() == "8.06 m"));
		REQUIRE (bool(a.get_spherical_theta().display() == "29.74\u00B0"));
		REQUIRE (bool(a.get_r().display() == "8.3 m"));
		REQUIRE (bool(a.get_spherical_phi().display() == "76.06\u00B0"));
		coordinates_ndr<> b(7_m);
		REQUIRE (bool(b.get_p() == length()));
		REQUIRE (bool(b.get_spherical_theta() == angle()));
		REQUIRE (bool(b.get_r() == length()));
		REQUIRE (bool(b.get_spherical_phi() == angle()));
		/*REQUIRE (bool(c.get_latitude() == angle(0.0f)));
		REQUIRE (bool(c.get_longitude() == angle(29.74f)));
		REQUIRE (bool(c.get_altitude() == "0 m"));*/
	}

	SECTION("Values of different coordinates systems of coordinates_ndr<float> classes")
	{
		coordinates_ndr<float> c(7.0f,4.0f,2.0f,angle(15.0f),angle(25.0f));
		REQUIRE (bool(std::fabs(c.get_p() - 8.06f) < 0.01f));
		REQUIRE (bool(c.get_spherical_theta().display() == "29.74\u00B0"));
		REQUIRE (bool(std::fabs(c.get_r() - 8.3f) < 0.01f));
		REQUIRE (bool(c.get_spherical_phi().display() == "76.06\u00B0"));
		coordinates_ndr<float> b(7.0f);
		REQUIRE (bool(b.get_p() == 0.0f));
		REQUIRE (bool(b.get_spherical_theta() == angle()));
		REQUIRE (bool(b.get_r() == 0.0f));
		REQUIRE (bool(b.get_spherical_phi() == angle()));
		/*REQUIRE (bool(c.get_latitude() == angle(0.0f)));
		REQUIRE (bool(c.get_longitude() == angle(29.74f)));
		REQUIRE (bool(c.get_altitude() == "0 m"));*/
	}

	SECTION("point_to() function of coordinates_ndr<> classes for the 1d case")
	{
		coordinates_ndr<> a(2_m);
		a.point_to(direction::LEFT);
		REQUIRE (bool(a.get_value(0) <= 0));
		a.point_to(direction::RIGHT);
		REQUIRE (bool(a.get_value(0) >= 0));
	}

	SECTION("point_to() function of coordinates_ndr<float> classes for the 1d case")
	{
		coordinates_ndr<float> a(2.0f);
		a.point_to(direction::LEFT);
		REQUIRE (bool(a.get_value(0) <= 0));
		a.point_to(direction::RIGHT);
		REQUIRE (bool(a.get_value(0) >= 0));
	}

	SECTION("point_to() function of coordinates_ndr<> classes for the 2d case")
	{
		coordinates_ndr<> a(5_m,2_m,angle(20.0f));
		a.point_to(direction::LEFT);
		REQUIRE (bool(a.get_angle(0).get_value() == 180.0f));
		a.point_to(direction::RIGHT);
		REQUIRE (bool(a.get_angle(0).get_value() == 0.0f));
		a.point_to(direction::TOP);
		REQUIRE (bool(a.get_angle(0).get_value() == 90.0f));
		a.point_to(direction::BOTTOM);
		REQUIRE (bool(a.get_angle(0).get_value() == 270.0f));
		a.point_to(direction::LEFT_TOP);
		REQUIRE (bool(a.get_angle(0).get_value() == 135.0f));
		a.point_to(direction::RIGHT_TOP);
		REQUIRE (bool(a.get_angle(0).get_value() == 45.0f));
		a.point_to(direction::RIGHT_BOTTOM);
		REQUIRE (bool(a.get_angle(0).get_value() == 315.0f));
		a.point_to(direction::LEFT_BOTTOM);
		REQUIRE (bool(a.get_angle(0).get_value() == 225.0f));
	}

	SECTION("point_to() function of coordinates_ndr<float> classes for the 2d case")
	{
		coordinates_ndr<float> a(5.0f,2.0f,angle(20.0f));
		a.point_to(direction::LEFT);
		REQUIRE (bool(a.get_angle(0).get_value() == 180.0f));
		a.point_to(direction::RIGHT);
		REQUIRE (bool(a.get_angle(0).get_value() == 0.0f));
		a.point_to(direction::TOP);
		REQUIRE (bool(a.get_angle(0).get_value() == 90.0f));
		a.point_to(direction::BOTTOM);
		REQUIRE (bool(a.get_angle(0).get_value() == 270.0f));
		a.point_to(direction::LEFT_TOP);
		REQUIRE (bool(a.get_angle(0).get_value() == 135.0f));
		a.point_to(direction::RIGHT_TOP);
		REQUIRE (bool(a.get_angle(0).get_value() == 45.0f));
		a.point_to(direction::RIGHT_BOTTOM);
		REQUIRE (bool(a.get_angle(0).get_value() == 315.0f));
		a.point_to(direction::LEFT_BOTTOM);
		REQUIRE (bool(a.get_angle(0).get_value() == 225.0f));
	}

	SECTION("point_to() function of coordinates_ndr<> classes for the 3d case")
	{
		coordinates_ndr<> a(5_m,2_m,7_m,angle(20.0f),angle(34.0f));
		a.point_to(direction::LEFT);
		REQUIRE (bool(a.get_angle(0).get_value() == 270.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 90.0f));
		a.point_to(direction::RIGHT);
		REQUIRE (bool(a.get_angle(0).get_value() == 90.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 90.0f));
		a.point_to(direction::TOP);
		REQUIRE (bool(a.get_angle(0).get_value() == 0.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 0.0f));
		a.point_to(direction::BOTTOM);
		REQUIRE (bool(a.get_angle(0).get_value() == 0.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 180.0f));
		a.point_to(direction::LEFT_TOP);
		REQUIRE (bool(a.get_angle(0).get_value() == 270.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 45.0f));
		a.point_to(direction::RIGHT_TOP);
		REQUIRE (bool(a.get_angle(0).get_value() == 90.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 45.0f));
		a.point_to(direction::RIGHT_BOTTOM);
		REQUIRE (bool(a.get_angle(0).get_value() == 90.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 135.0f));
		a.point_to(direction::LEFT_BOTTOM);
		REQUIRE (bool(a.get_angle(0).get_value() == 270.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 135.0f));
		a.point_to(direction::FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 0.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 90.0f));
		a.point_to(direction::BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 180.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 90.0f));
		a.point_to(direction::LEFT_FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 315.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 90.0f));
		a.point_to(direction::RIGHT_FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 45.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 90.0f));
		a.point_to(direction::TOP_FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 0.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 45.0f));
		a.point_to(direction::BOTTOM_FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 0.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 135.0f));
		a.point_to(direction::LEFT_BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 225.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 90.0f));
		a.point_to(direction::RIGHT_BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 135.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 90.0f));
		a.point_to(direction::TOP_BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 180.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 45.0f));
		a.point_to(direction::BOTTOM_BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 180.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 135.0f));
		a.point_to(direction::LEFT_TOP_FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 315.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 45.0f));
		a.point_to(direction::RIGHT_TOP_FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 45.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 45.0f));
		a.point_to(direction::LEFT_BOTTOM_FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 315.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 135.0f));
		a.point_to(direction::RIGHT_BOTTOM_FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 45.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 135.0f));
		a.point_to(direction::LEFT_TOP_BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 225.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 45.0f));
		a.point_to(direction::RIGHT_TOP_BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 135.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 45.0f));
		a.point_to(direction::LEFT_BOTTOM_BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 225.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 135.0f));
		a.point_to(direction::RIGHT_BOTTOM_BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 135.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 135.0f));
	}

	SECTION("point_to() function of coordinates_ndr<float> classes for the 3d case")
	{
		coordinates_ndr<float> a(5.0f,2.0f,7.0f,angle(20.0f),angle(34.0f));
		a.point_to(direction::LEFT);
		REQUIRE (bool(a.get_angle(0).get_value() == 270.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 90.0f));
		a.point_to(direction::RIGHT);
		REQUIRE (bool(a.get_angle(0).get_value() == 90.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 90.0f));
		a.point_to(direction::TOP);
		REQUIRE (bool(a.get_angle(0).get_value() == 0.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 0.0f));
		a.point_to(direction::BOTTOM);
		REQUIRE (bool(a.get_angle(0).get_value() == 0.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 180.0f));
		a.point_to(direction::LEFT_TOP);
		REQUIRE (bool(a.get_angle(0).get_value() == 270.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 45.0f));
		a.point_to(direction::RIGHT_TOP);
		REQUIRE (bool(a.get_angle(0).get_value() == 90.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 45.0f));
		a.point_to(direction::RIGHT_BOTTOM);
		REQUIRE (bool(a.get_angle(0).get_value() == 90.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 135.0f));
		a.point_to(direction::LEFT_BOTTOM);
		REQUIRE (bool(a.get_angle(0).get_value() == 270.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 135.0f));
		a.point_to(direction::FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 0.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 90.0f));
		a.point_to(direction::BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 180.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 90.0f));
		a.point_to(direction::LEFT_FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 315.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 90.0f));
		a.point_to(direction::RIGHT_FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 45.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 90.0f));
		a.point_to(direction::TOP_FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 0.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 45.0f));
		a.point_to(direction::BOTTOM_FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 0.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 135.0f));
		a.point_to(direction::LEFT_BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 225.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 90.0f));
		a.point_to(direction::RIGHT_BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 135.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 90.0f));
		a.point_to(direction::TOP_BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 180.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 45.0f));
		a.point_to(direction::BOTTOM_BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 180.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 135.0f));
		a.point_to(direction::LEFT_TOP_FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 315.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 45.0f));
		a.point_to(direction::RIGHT_TOP_FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 45.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 45.0f));
		a.point_to(direction::LEFT_BOTTOM_FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 315.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 135.0f));
		a.point_to(direction::RIGHT_BOTTOM_FRONT);
		REQUIRE (bool(a.get_angle(0).get_value() == 45.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 135.0f));
		a.point_to(direction::LEFT_TOP_BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 225.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 45.0f));
		a.point_to(direction::RIGHT_TOP_BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 135.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 45.0f));
		a.point_to(direction::LEFT_BOTTOM_BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 225.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 135.0f));
		a.point_to(direction::RIGHT_BOTTOM_BACK);
		REQUIRE (bool(a.get_angle(0).get_value() == 135.0f));
		REQUIRE (bool(a.get_angle(1).get_value() == 135.0f));
	}

	SECTION("set_position(), rotate() and move() of coordinates_ndr<> classes")
	{
		coordinates_ndr<> a(7_m,4_m,2_m,angle(15.0f),angle(25.0f));
		a.set_position(5_m,5_m,1_m);
		REQUIRE (bool(to_string(a) == "(5 m,5 m,1 m;15\u00B0,25\u00B0)"));
		a.set_position(5_m,angle(30.0f),1_m);
		REQUIRE (bool(to_string(a) == "(4.33 m,2.5 m,1 m;15\u00B0,25\u00B0)"));
		a.set_position(5_m,angle(30.0f),angle(45.0f));
		REQUIRE (bool(to_string(a) == "(3.06 m,1.76 m,3.53 m;15\u00B0,25\u00B0)"));
		/*a.set_position(angle(30.0f),angle(45.0f),100_m);
		cout << "geographical coordinates: " << to_string(a) << endl;
		REQUIRE (bool(to_string(a) == "(61.23 m,61.23 m,50 m)"));*/
		coordinates_ndr<> b2(20_m,angle(60.0f),angle(20.0f));
		b2.rotate_in_2d(angle(15.0f));
		REQUIRE (bool(to_string(b2) == "(5.17 m,19.31 m;20\u00B0)"));
		coordinates_ndr<> b(5_m,3_m,1_m,angle(15.0f),angle(25.0f));
		b.rotate_in_3d(1,angle(45.0f));
		REQUIRE (bool(to_string(b) == "(5 m,1.41 m,2.82 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> c(7_m,4_m,2_m,angle(15.0f),angle(25.0f));
		c.rotate_in_3d(2,angle(45.0f));
		REQUIRE (bool(to_string(c) == "(3.53 m,4 m,6.36 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> d(4_m,2_m,3_m,angle(15.0f),angle(25.0f));
		d.rotate_in_3d(3,angle(45.0f));
		REQUIRE (bool(to_string(d) == "(1.41 m,4.24 m,3 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> e(1_m,2_m,3_m,angle(15.0f),angle(25.0f));
		displacement_3d e2(3_m,angle(0.0f),angle(0.0f));
		e.move(e2);
		REQUIRE (bool(to_string(e) == "(1 m,2 m,6 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> f(1_m,2_m,3_m,angle(15.0f),angle(25.0f));
		f.move(2_m,1_m,3_m);
		REQUIRE (bool(to_string(f) == "(3 m,3 m,6 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> g(1_m,2_m,3_m,angle(15.0f),angle(25.0f));
		g.move(2_m,angle(45.0f),3_m);
		REQUIRE (bool(to_string(g) == "(2.41 m,3.41 m,6 m;15\u00B0,25\u00B0)"));
		coordinates_ndr<> h(1_m,2_m,3_m,angle(15.0f),angle(25.0f));
		h.move(2_m,angle(0.0f),angle(45.0f));
		REQUIRE (bool(to_string(h) == "(2.41 m,2 m,4.41 m;15\u00B0,25\u00B0)"));
	}

	SECTION("set_position(), rotate() and move() of coordinates_ndr<float> classes")
	{
		coordinates_ndr<float> a(7.0f,4.0f,2.0f,angle(15.0f),angle(25.0f));
		a.set_position(5.0f,5.0f,1.0f);
		REQUIRE (bool(to_string(a) == "(5,5,1;15\u00B0,25\u00B0)"));
		a.set_position(5.0f,angle(30.0f),1.0f);
		REQUIRE (bool(to_string(a) == "(4.33,2.5,1;15\u00B0,25\u00B0)"));
		a.set_position(5.0f,angle(30.0f),angle(45.0f));
		REQUIRE (bool(to_string(a) == "(3.06,1.76,3.53;15\u00B0,25\u00B0)"));
		/*a.set_position(angle(30.0f),angle(45.0f),100_m);
		cout << "geographical coordinates: " << to_string(a) << endl;
		REQUIRE (bool(to_string(a) == "(61.23 m,61.23 m,50 m)"));*/
		coordinates_ndr<float> b2(20.0f,angle(60.0f),angle(20.0f));
		b2.rotate_in_2d(angle(15.0f));
		REQUIRE (bool(to_string(b2) == "(5.17,19.31;20\u00B0)"));
		coordinates_ndr<float> b(5.0f,3.0f,1.0f,angle(15.0f),angle(25.0f));
		b.rotate_in_3d(1,angle(45.0f));
		REQUIRE (bool(to_string(b) == "(5,1.41,2.82;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> c(7.0f,4.0f,2.0f,angle(15.0f),angle(25.0f));
		c.rotate_in_3d(2,angle(45.0f));
		REQUIRE (bool(to_string(c) == "(3.53,4,6.36;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> d(4.0f,2.0f,3.0f,angle(15.0f),angle(25.0f));
		d.rotate_in_3d(3,angle(45.0f));
		REQUIRE (bool(to_string(d) == "(1.41,4.24,3;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> e(1.0f,2.0f,3.0f,angle(15.0f),angle(25.0f));
		displacement_3d e2(3_m,angle(0.0f),angle(0.0f));
		e.move(e2);
		REQUIRE (bool(to_string(e) == "(1,2,6;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> f(1.0f,2.0f,3.0f,angle(15.0f),angle(25.0f));
		f.move(2.0f,1.0f,3.0f);
		REQUIRE (bool(to_string(f) == "(3,3,6;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> g(1.0f,2.0f,3.0f,angle(15.0f),angle(25.0f));
		g.move(2.0f,angle(45.0f),3.0f);
		REQUIRE (bool(to_string(g) == "(2.41,3.41,6;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> h(1.0f,2.0f,3.0f,angle(15.0f),angle(25.0f));
		h.move(2.0f,angle(0.0f),angle(45.0f));
		REQUIRE (bool(to_string(h) == "(2.41,2,4.41;15\u00B0,25\u00B0)"));
	}

	SECTION("distance_to_origin() of coordinates_ndr<> classes")
	{
		coordinates_ndr<> a(2_m,3_m,5_m,angle(15.0f),angle(25.0f));
		REQUIRE (bool(a.distance_to_origin().display() == "6.16 m"));
	}

	SECTION("distance_to_origin() of coordinates_ndr<float> classes")
	{
		coordinates_ndr<float> a(2.0f,3.0f,5.0f,angle(15.0f),angle(25.0f));
		REQUIRE (bool(std::fabs(a.distance_to_origin() - 6.16f) < 0.01f));
	}

	SECTION("Display of coordinates_ndr<> classes")
	{
		coordinates_ndr<> a(2_m,3_m,5_m,angle(15.0f),angle(25.0f));
		REQUIRE (bool(a.display_polar() == "[no-2d]"));
		REQUIRE (bool(a.display_cylindrical() == "(3.6 m,56.3\u00B0,5 m;15\u00B0,25\u00B0)"));
		REQUIRE (bool(a.display_spherical() == "(6.16 m,56.3\u00B0,35.79\u00B0;15\u00B0,25\u00B0)"));
		coordinates_ndr<> b(2_m,angle(40.0f),angle(15.0f));
		REQUIRE (bool(b.display_polar() == "(2 m,40°;15°)"));
		REQUIRE (bool(b.display_cylindrical() == "[no-3d]"));
		REQUIRE (bool(b.display_spherical() == "[no-3d]"));
		//REQUIRE (bool(b.display_geographical() == "[no-3d]"));
		/*coordinates_ndr<> b(2_m,3_m,10000_km);
		cout << "b display geographical: " << b.display_geographical() << endl;
		REQUIRE (bool(b.display_geographical() == ""));*/
	}

	SECTION("Display of coordinates_ndr<float> classes")
	{
		coordinates_ndr<float> a(2.0f,3.0f,5.0f,angle(15.0f),angle(25.0f));
		REQUIRE (bool(a.display_polar() == "[no-2d]"));
		REQUIRE (bool(a.display_cylindrical() == "(3.6,56.3\u00B0,5;15\u00B0,25\u00B0)"));
		REQUIRE (bool(a.display_spherical() == "(6.16,56.3\u00B0,35.79\u00B0;15\u00B0,25\u00B0)"));
		coordinates_ndr<float> b(2.0f,angle(40.0f),angle(15.0f));
		REQUIRE (bool(b.display_polar() == "(2,40°;15°)"));
		REQUIRE (bool(b.display_cylindrical() == "[no-3d]"));
		REQUIRE (bool(b.display_spherical() == "[no-3d]"));
		/*coordinates_ndr<> b(2_m,3_m,10000_km);
		cout << "b display geographical: " << b.display_geographical() << endl;
		REQUIRE (bool(b.display_geographical() == ""));*/
	}

	SECTION("to_string() of coordinates_ndr<>")
	{
		coordinates_ndr<> a(2_m,3_m,5_m,angle(15.0f),angle(25.0f));
		REQUIRE (bool(to_string(a) == "(2 m,3 m,5 m;15\u00B0,25\u00B0)"));
	}

	SECTION("to_string() of coordinates_ndr<float>")
	{
		coordinates_ndr<float> a(2.0f,3.0f,5.0f,angle(15.0f),angle(25.0f));
		REQUIRE (bool(to_string(a) == "(2,3,5;15\u00B0,25\u00B0)"));
	}

	SECTION("distance() of coordinates_ndr<>")
	{
		coordinates_ndr<> a(7_m,3_m,1_m,angle(15.0f),angle(25.0f));
		coordinates_ndr<> b(6_m,2_m,1_m,angle(15.0f),angle(25.0f));
		REQUIRE (bool(distance(a,b).display() == "1.41 m"));
		coordinates_ndr<> b2(6_m,2_m,angle(20.0f));
		REQUIRE (bool(distance(a,b2) == length()));
		point_nd<> c(7_m,3_m,1_m);
		REQUIRE (bool(distance(a,c).display() == "0 m"));
		REQUIRE (bool(distance(c,a).display() == "0 m"));
		REQUIRE (bool(distance(b,c).display() == "1.41 m"));
		REQUIRE (bool(distance(c,b).display() == "1.41 m"));
		point_nd<> c2(7_m,3_m);
		REQUIRE (bool(distance(a,c2) == length()));
		REQUIRE (bool(distance(c2,a) == length()));
		coordinates_nd<> d(7_m,3_m,1_m);
		REQUIRE (bool(distance(a,d).display() == "0 m"));
		REQUIRE (bool(distance(d,a).display() == "0 m"));
		REQUIRE (bool(distance(b,d).display() == "1.41 m"));
		REQUIRE (bool(distance(d,b).display() == "1.41 m"));
		coordinates_nd<> d2(7_m,3_m);
		REQUIRE (bool(distance(a,d2) == length()));
		REQUIRE (bool(distance(d2,a) == length()));
	}

	SECTION("distance() of coordinates_ndr<float>")
	{
		coordinates_ndr<float> a(7.0f,3.0f,1.0f,angle(15.0f),angle(25.0f));
		coordinates_ndr<float> b(6.0f,2.0f,1.0f,angle(15.0f),angle(25.0f));
		REQUIRE (bool(std::fabs(distance(a,b) - 1.41f) < 0.01f));
		coordinates_ndr<float> b2(6.0f,2.0f,angle(20.0f));
		REQUIRE (bool(distance(a,b2) == 0.0f));
		point_nd<float> c(7.0f,3.0f,1.0f);
		REQUIRE (bool(std::fabs(distance(a,c) - 0.0f) < 0.01f));
		REQUIRE (bool(std::fabs(distance(c,a) - 0.0f) < 0.01f));
		REQUIRE (bool(std::fabs(distance(b,c) - 1.41f) < 0.01f));
		REQUIRE (bool(std::fabs(distance(c,b) - 1.41f) < 0.01f));
		point_nd<float> c2(7.0f,3.0f);
		REQUIRE (bool(distance(a,c2) == 0.0f));
		REQUIRE (bool(distance(c2,a) == 0.0f));
		coordinates_nd<float> d(7.0f,3.0f,1.0f);
		REQUIRE (bool(distance(a,d) == 0.0f));
		REQUIRE (bool(distance(d,a) == 0.0f));
		REQUIRE (bool(std::fabs(distance(b,d) - 1.41f) < 0.01f));
		REQUIRE (bool(std::fabs(distance(d,b) - 1.41f) < 0.01f));
		coordinates_nd<float> d2(7.0f,3.0f);
		REQUIRE (bool(distance(a,d2) == 0.0f));
		REQUIRE (bool(distance(d2,a) == 0.0f));
	}

	SECTION("Relational operators of coordinates_ndr<>")
	{
		coordinates_ndr<> a(7_m,3_m,1_m,angle(15.0f),angle(25.0f));
		coordinates_ndr<> b(7_m,3_m,1_m,angle(15.0f),angle(25.0f));
		coordinates_ndr<> c(6_m,2_m,1_m,angle(15.0f),angle(25.0f));
		coordinates_ndr<> c2(6_m,2_m,angle(20.0f));
		coordinates_ndr<> c3(6_m,2_m,1_m,angle(15.0f),angle(30.0f));
		REQUIRE(bool(a == b));
		REQUIRE(bool((a == c) == false));
		REQUIRE(bool((a == c2) == false));
		REQUIRE(bool(a != c));
		REQUIRE(bool((c == c3) == false));
		point_nd<> d(7_m,3_m,1_m);
		point_nd<> e(5_m,1_m,1_m);
		point_nd<> e2(5_m,1_m);
		REQUIRE(bool(a == d));
		REQUIRE(bool(a != e));
		REQUIRE(bool(a == e2) == false);
		REQUIRE(bool(e2 == a) == false);
		REQUIRE(bool(d == a));
		REQUIRE(bool(e != a));
		coordinates_nd<> f(7_m,3_m,1_m);
		coordinates_nd<> g(5_m,1_m,1_m);
		coordinates_nd<> g2(5_m,1_m);
		REQUIRE(bool(a == f));
		REQUIRE(bool(a != g));
		REQUIRE(bool(a == g2) == false);
		REQUIRE(bool(g2 == a) == false);
		REQUIRE(bool(f == a));
		REQUIRE(bool(g != a));
	}

	SECTION("Relational operators of coordinates_ndr<float>")
	{
		coordinates_ndr<float> a(7.0f,3.0f,1.0f,angle(15.0f),angle(25.0f));
		coordinates_ndr<float> b(7.0f,3.0f,1.0f,angle(15.0f),angle(25.0f));
		coordinates_ndr<float> c(6.0f,2.0f,1.0f,angle(15.0f),angle(25.0f));
		REQUIRE(bool(a == b));
		REQUIRE(bool((a == c) == false));
		REQUIRE(bool(a != c));
		point_nd<float> d(7.0f,3.0f,1.0f);
		point_nd<float> e(5.0f,1.0f,1.0f);
		REQUIRE(bool(a == d));
		REQUIRE(bool(a != e));
		REQUIRE(bool(d == a));
		REQUIRE(bool(e != a));
		coordinates_nd<float> f(7.0f,3.0f,1.0f);
		coordinates_nd<float> g(5.0f,1.0f,1.0f);
		coordinates_nd<float> g2(5.0f,1.0f);
		REQUIRE(bool(a == f));
		REQUIRE(bool(a != g));
		REQUIRE(bool(a == g2) == false);
		REQUIRE(bool(g2 == a) == false);
		REQUIRE(bool(f == a));
		REQUIRE(bool(g != a));
	}

	SECTION("String operators of coordinates_ndr<>")
	{
		coordinates_ndr<> a(7_m,4_m,2_m,angle(15.0f),angle(25.0f));
		REQUIRE(bool(a == "(7 m,4 m,2 m;15\u00B0,25\u00B0)"));
		REQUIRE(bool(a != "(6 m,3 m,2 m;15\u00B0,25\u00B0)"));
		REQUIRE(bool("(7 m,4 m,2 m;15\u00B0,25\u00B0)" == a));
		REQUIRE(bool("(6 m,3 m,2 m;15\u00B0,25\u00B0)" != a));
		string b = "x: ";
		b += a;
		REQUIRE(bool(b == "x: (7 m,4 m,2 m;15\u00B0,25\u00B0)"));
		REQUIRE(bool(("x: " + a) == "x: (7 m,4 m,2 m;15\u00B0,25\u00B0)"));
		REQUIRE(bool("x: (7 m,4 m,2 m;15\u00B0,25\u00B0)" == ("x: " + a)));
	}

	SECTION("String operators of coordinates_ndr<float>")
	{
		coordinates_ndr<float> a(7.0f,4.0f,2.0f,angle(15.0f),angle(25.0f));
		REQUIRE(bool(a == "(7,4,2;15\u00B0,25\u00B0)"));
		REQUIRE(bool(a != "(6,3,2;15\u00B0,25\u00B0)"));
		REQUIRE(bool("(7,4,2;15\u00B0,25\u00B0)" == a));
		REQUIRE(bool("(6,3,2;15\u00B0,25\u00B0)" != a));
		string b = "x: ";
		b += a;
		REQUIRE(bool(b == "x: (7,4,2;15\u00B0,25\u00B0)"));
		REQUIRE(bool(("x: " + a) == "x: (7,4,2;15\u00B0,25\u00B0)"));
		REQUIRE(bool("x: (7,4,2;15\u00B0,25\u00B0)" == ("x: " + a)));
	}

	SECTION("Stream operators of coordinates_ndr<> classes")
	{
		coordinates_ndr<> a(2_m,3_m,2_m,angle(15.0f),angle(25.0f));
		ostringstream out;
		out << a;
		REQUIRE(bool(out.str() == "(2 m,3 m,2 m;15\u00B0,25\u00B0)"));
		istringstream iss("(1 m,2 m,1 m;15\u00B0,25\u00B0)");
		coordinates_ndr<> b;
		iss >> b;
		REQUIRE(bool(to_string(b) == "(1 m,2 m,1 m;15\u00B0,25\u00B0)"));
	}

	SECTION("Stream operators of coordinates_ndr<float> classes")
	{
		coordinates_ndr<float> a(2.0f,3.0f,2.0f,angle(15.0f),angle(25.0f));
		ostringstream out;
		out << a;
		REQUIRE(bool(out.str() == "(2,3,2;15\u00B0,25\u00B0)"));
		istringstream iss("(1,2,1;15\u00B0,25\u00B0)");
		coordinates_ndr<float> b;
		iss >> b;
		REQUIRE(bool(to_string(b) == "(1,2,1;15\u00B0,25\u00B0)"));
	}
}
