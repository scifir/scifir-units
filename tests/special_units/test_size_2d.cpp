#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../special_units/size_2d.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("size_2d class","Full test of size_2d class") {
	SECTION("Constructors of size_2d<> class")
	{
		size_2d<> a;
		REQUIRE (bool(to_string(a) == "0 m * 0 m"));
		size_2d<> b2(2_m,3_m);
		size_2d<> b(b2);
		REQUIRE (bool(to_string(b) == "2 m * 3 m"));
		size_2d<> c2(2_m,3_m);
		size_2d<> c(std::move(c2));
		REQUIRE (bool(to_string(c) == "2 m * 3 m"));
		size_2d d(1_m,1_m);
		REQUIRE (bool(to_string(d) == "1 m * 1 m"));
		size_2d<> e("1 m","1 m");
		REQUIRE (bool(to_string(e) == "1 m * 1 m"));
		size_2d<> f("1 m * 1 m");
		REQUIRE (bool(to_string(f) == "1 m * 1 m"));
	}

	SECTION("Constructors of size_2d<float> class")
	{
		size_2d<float> a;
		REQUIRE (bool(to_string(a) == "0 * 0"));
		size_2d<float> b2(2.0f,3.0f);
		size_2d<float> b(b2);
		REQUIRE (bool(to_string(b) == "2 * 3"));
		size_2d<float> c2(2.0f,3.0f);
		size_2d<float> c(std::move(c2));
		REQUIRE (bool(to_string(c) == "2 * 3"));
		size_2d d(1.0f,1.0f);
		REQUIRE (bool(to_string(d) == "1 * 1"));
		size_2d<float> e("1","1");
		REQUIRE (bool(to_string(e) == "1 * 1"));
		size_2d<float> f("1 * 1");
		REQUIRE (bool(to_string(f) == "1 * 1"));
	}

	SECTION("Assignments of size_2d<> class")
	{
		size_2d<> a;
		size_2d<> a2(2_m,3_m);
		a = a2;
		REQUIRE (bool(to_string(a) == "2 m * 3 m"));
		size_2d<> b;
		size_2d<> b2(2_m,3_m);
		b = std::move(b2);
		REQUIRE (bool(to_string(b) == "2 m * 3 m"));
	}

	SECTION("Assignments of size_2d<float> class")
	{
		size_2d<float> a;
		size_2d<float> a2(2.0f,3.0f);
		a = a2;
		REQUIRE (bool(to_string(a) == "2 * 3"));
		size_2d<float> b;
		size_2d<float> b2(2.0f,3.0f);
		b = std::move(b2);
		REQUIRE (bool(to_string(b) == "2 * 3"));
	}

	SECTION("Operators of size_2d<> class")
	{
		size_2d<> a(2_m,5_m);
		size_2d<> b(3_m,1_m);
		REQUIRE (bool(to_string(a + b) == "5 m * 6 m"));
		size_2d<> c(2_m,5_m);
		size_2d<> d(1_m,2_m);
		REQUIRE (bool(to_string(c - d) == "1 m * 3 m"));
		size_2d<> e(2_m,5_m);
		size_2d<> f(1_m,1_m);
		e += f;
		REQUIRE (bool(to_string(e) == "3 m * 6 m"));
		size_2d<> g(2_m,5_m);
		size_2d<> h(1_m,1_m);
		g -= h;
		REQUIRE (bool(to_string(g) == "1 m * 4 m"));
	}

	SECTION("Operators of size_2d<float> class")
	{
		size_2d<float> a(2.0f,5.0f);
		size_2d<float> b(3.0f,1.0f);
		REQUIRE (bool(to_string(a + b) == "5 * 6"));
		size_2d<float> c(2.0f,5.0f);
		size_2d<float> d(1.0f,2.0f);
		REQUIRE (bool(to_string(c - d) == "1 * 3"));
		size_2d<float> e(2.0f,5.0f);
		size_2d<float> f(1.0f,1.0f);
		e += f;
		REQUIRE (bool(to_string(e) == "3 * 6"));
		size_2d<float> g(2.0f,5.0f);
		size_2d<float> h(1.0f,1.0f);
		g -= h;
		REQUIRE (bool(to_string(g) == "1 * 4"));
	}

	SECTION("get_area() of size_2d<> class")
	{
		size_2d<> a(2_m,2_m);
		REQUIRE (bool(a.get_area() == "4 m2"));
	}

	SECTION("get_area() of size_2d<float> class")
	{
		size_2d<float> a(2.0f,2.0f);
		REQUIRE (bool(a.get_area() == 4.0f));
	}

	SECTION("to_string() of size_2d<> class")
	{
		size_2d<> a("2 m * 3 m");
		REQUIRE (bool(to_string(a) == "2 m * 3 m"));
	}

	SECTION("to_string() of size_2d<float> class")
	{
		size_2d<float> a("2 * 3");
		REQUIRE (bool(to_string(a) == "2 * 3"));
	}

	SECTION("Comparison of size_2d<> classes")
	{
		size_2d<> a(2_m,4_m);
		size_2d<> b(2_m,4_m);
		size_2d<> c(6_m,5_m);
		REQUIRE (bool(a == b));
		REQUIRE (bool(a != c));
	}

	SECTION("Comparison of size_2d<float> classes")
	{
		size_2d<float> a(2.0f,4.0f);
		size_2d<float> b(2.0f,4.0f);
		size_2d<float> c(6.0f,5.0f);
		REQUIRE (bool(a == b));
		REQUIRE (bool(a != c));
	}

	SECTION("String operators of size_2d<> class")
	{
		REQUIRE (bool(size_2d<>(2_m,4_m) == "2 m * 4 m"));
		REQUIRE (bool(size_2d<>(2_m,4_m) != "2 m * 3 m"));
		REQUIRE (bool("2 m * 4 m" == size_2d<>(2_m,4_m)));
		REQUIRE (bool("2 m * 3 m" != size_2d<>(2_m,4_m)));
		string a = "size_2d ";
		a += size_2d<>("2 m * 3 m");
		REQUIRE (bool(a == "size_2d 2 m * 3 m"));
		size_2d<> b = size_2d<>("2 m * 3 m");
		REQUIRE (bool("b " + b == "b 2 m * 3 m"));
		REQUIRE (bool(b + " b" == "2 m * 3 m b"));
	}

	SECTION("String operators of size_2d<float> class")
	{
		REQUIRE (bool(size_2d<float>(2.0f,4.0f) == "2 * 4"));
		REQUIRE (bool(size_2d<float>(2.0f,4.0f) != "2 * 3"));
		REQUIRE (bool("2 * 4" == size_2d<float>(2.0f,4.0f)));
		REQUIRE (bool("2 * 3" != size_2d<float>(2.0f,4.0f)));
		string a = "size_2d ";
		a += size_2d<float>("2 * 3");
		REQUIRE (bool(a == "size_2d 2 * 3"));
		size_2d<float> b = size_2d<float>("2 * 3");
		REQUIRE (bool("b " + b == "b 2 * 3"));
		REQUIRE (bool(b + " b" == "2 * 3 b"));
	}

	SECTION("Streams of size_2d<> class")
	{
		ostringstream a;
        a << size_2d<>(2_m,3_m);
        REQUIRE (bool(a.str() == "2 m * 3 m"));
        stringstream b;
        b << "1 m * 3 m";
        size_2d<> b2;
        b >> b2;
        REQUIRE (bool(to_string(b2) == "1 m * 3 m"));
	}

	SECTION("Streams of size_2d<float> class")
	{
		ostringstream a;
        a << size_2d<float>(2.0f,3.0f);
        REQUIRE (bool(a.str() == "2 * 3"));
        stringstream b;
        b << "1 * 3";
        size_2d<float> b2;
        b >> b2;
        REQUIRE (bool(to_string(b2) == "1 * 3"));
	}
}