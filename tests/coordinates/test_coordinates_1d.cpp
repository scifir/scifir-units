#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "catch2/catch_test_macros.hpp"
#include "../../coordinates/coordinates_1d.hpp"
#include "../../units/unit_basic.hpp"

#include <string>
#include <sstream>

using namespace std;
using namespace scifir;

TEST_CASE("class coordinates_1d","Complete test of coordinates_1d")
{
	SECTION("Constructors of coordinates_1d classes")
	{
		scifir::coordinates_1d<> a;
		REQUIRE (bool(to_string(a) == "(0 m)"));
		REQUIRE (bool(to_string(a.x) == "0 m"));
		scifir::coordinates_1d<> a2(5_m);
		scifir::coordinates_1d<> a3(a2);
		REQUIRE (bool(to_string(a3) == "(5 m)"));
		scifir::coordinates_1d<> a4(5_m);
		scifir::coordinates_1d<> a5(move(a4));
		REQUIRE (bool(to_string(a3) == "(5 m)"));
		scifir::coordinates_1d<> b(100_m);
		cout << "b: " << to_string(b) << endl;
		REQUIRE (bool(to_string(b) == "(100 m)"));
		scifir::point_1d<> c2(100_m);
		scifir::coordinates_1d<> c(c2);
		cout << "c: " << to_string(c) << endl;
		REQUIRE (bool(to_string(c) == "(100 m)"));
		scifir::coordinates_1d<> d("(1 m)");
		REQUIRE (bool(to_string(d) == "(1 m)"));
		scifir::coordinates_1d<> e("1 m");
		REQUIRE (bool(to_string(e) == "(1 m)"));
	}

	SECTION("Assignments of coordinates_1d classes")
	{
		scifir::coordinates_1d<> a(10_m);
		scifir::coordinates_1d<> b(20_m);
		a = b;
		REQUIRE (bool(to_string(a) == "(20 m)"));
		scifir::coordinates_1d<> c(10_m);
		scifir::coordinates_1d<> d(30_m);
		c = move(d);
		REQUIRE (bool(to_string(c) == "(30 m)"));
		scifir::coordinates_1d<> e(10_m);
		scifir::point_1d<> f(15_m);
		e = f;
		REQUIRE (bool(to_string(e) == "(15 m)"));
	}

	SECTION("move(), set_position() and distance_to_origin()")
	{
		scifir::coordinates_1d<> a(5_m);
		a.set_position(25_m);
		REQUIRE (bool(to_string(a) == "(25 m)"));
		scifir::coordinates_1d<> b(10_m);
		b.move(35_m);
		REQUIRE (bool(to_string(b) == "(45 m)"));
		scifir::coordinates_1d<> c(10_m);
		scifir::length d = c.distance_to_origin();
		REQUIRE (bool(to_string(d) == "10 m"));
	}

	SECTION("distance() functions")
	{
		scifir::coordinates_1d<> a(10_m);
		scifir::coordinates_1d<> b(15_m);
		REQUIRE (bool(to_string(distance(a,b)) == "5 m"));
		scifir::coordinates_1d<> c(20_m);
		scifir::point_1d<> d(35_m);
		REQUIRE (bool(to_string(distance(c,d)) == "15 m"));
		REQUIRE (bool(to_string(distance(d,c)) == "15 m"));
	}

	SECTION("Relational operators")
	{
		scifir::coordinates_1d a(7_m);
		scifir::coordinates_1d b(7_m);
		scifir::coordinates_1d c(6_m);
		REQUIRE(bool(a == b));
		REQUIRE(bool((a == c)) == false);
		REQUIRE(bool(a != c));
		scifir::point_1d d(7_m);
		scifir::point_1d e(5_m);
		REQUIRE(bool(a == d));
		REQUIRE(bool(a != e));
		REQUIRE(bool(d == a));
		REQUIRE(bool(e != a));
	}

	SECTION("String operators")
	{
		scifir::coordinates_1d a(7_m);
		REQUIRE(bool(a == "(7 m)"));
		REQUIRE(bool(a != "(6 m)"));
		REQUIRE(bool("(7 m)" == a));
		REQUIRE(bool("(6 m)" != a));
		std::string b = "x: ";
		b += a;
		REQUIRE(bool(b == "x: (7 m)"));
		REQUIRE(bool(("x: " + a) == "x: (7 m)"));
		REQUIRE(bool("x: (7 m)" == ("x: " + a)));
	}

	SECTION("Display of coordinates_1d classes")
	{
		scifir::coordinates_1d a(2_m);
		std::ostringstream out;
		out << a;
		REQUIRE(bool(out.str() == "(2 m)"));
		std::istringstream iss("(1 m)");
		scifir::coordinates_1d b;
		iss >> b;
		REQUIRE(bool(to_string(b) == "(1 m)"));
	}
}
