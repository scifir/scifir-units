#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../special_units/size_3d.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("class size_3d<T> and size_3d<float>") {
	SECTION("Constructors of size_3d<> class")
	{
		size_3d<> a;
		CHECK(to_string(a) == "0 m * 0 m * 0 m");
		size_3d<> b2(2_m,3_m,1_m);
		size_3d<> b(b2);
		CHECK(to_string(b) == "2 m * 3 m * 1 m");
		size_3d<> c2(2_m,3_m,1_m);
		size_3d<> c(std::move(c2));
		CHECK(to_string(c) == "2 m * 3 m * 1 m");
		size_3d d(1_m,1_m,2_m);
		CHECK(to_string(d) == "1 m * 1 m * 2 m");
		size_3d<> e("1 m","1 m","3 m");
		CHECK(to_string(e) == "1 m * 1 m * 3 m");
		size_3d<> f("1 m * 1 m * 3 m");
		CHECK(to_string(f) == "1 m * 1 m * 3 m");
	}

	SECTION("Constructors of size_3d<float> class")
	{
		size_3d<float> a;
		CHECK(to_string(a) == "0 * 0 * 0");
		size_3d<float> b2(2.0f,3.0f,1.0f);
		size_3d<float> b(b2);
		CHECK(to_string(b) == "2 * 3 * 1");
		size_3d<float> c2(2.0f,3.0f,1.0f);
		size_3d<float> c(std::move(c2));
		CHECK(to_string(c) == "2 * 3 * 1");
		size_3d<float> d(1.0f,1.0f,2.0f);
		CHECK(to_string(d) == "1 * 1 * 2");
		size_3d<float> e("1","1","3");
		CHECK(to_string(e) == "1 * 1 * 3");
		size_3d<float> f("1 * 1 * 3");
		CHECK(to_string(f) == "1 * 1 * 3");
	}

	SECTION("Assignments of size_3d<> class")
	{
		size_3d<> a;
		size_3d<> a2(2_m,3_m,1_m);
		a = a2;
		CHECK(to_string(a) == "2 m * 3 m * 1 m");
		size_3d<> b;
		size_3d<> b2(2_m,3_m,1_m);
		b = std::move(b2);
		CHECK(to_string(b) == "2 m * 3 m * 1 m");
		size_3d<> c(2_m,3_m,1_m);
		c = "5 m * 6 m * 2 m";
		CHECK(to_string(c) == "5 m * 6 m * 2 m");
	}

	SECTION("Assignments of size_3d<float> class")
	{
		size_3d<float> a;
		size_3d<float> a2(2.0f,3.0f,1.0f);
		a = a2;
		CHECK(to_string(a) == "2 * 3 * 1");
		size_3d<float> b;
		size_3d<float> b2(2.0f,3.0f,1.0f);
		b = std::move(b2);
		CHECK(to_string(b) == "2 * 3 * 1");
		size_3d<float> c(2.0f,3.0f,1.0f);
		c = "5 * 6 * 2";
		CHECK(to_string(c) == "5 * 6 * 2");
	}

	SECTION("Operators of size_3d<> class")
	{
		size_3d<> a(2_m,5_m,4_m);
		size_3d<> b(3_m,1_m,2_m);
		CHECK(to_string(a + b) == "5 m * 6 m * 6 m");
		size_3d<> c(2_m,5_m,4_m);
		size_3d<> d(1_m,2_m,3_m);
		CHECK(to_string(c - d) == "1 m * 3 m * 1 m");
		size_3d<> e(2_m,5_m,4_m);
		size_3d<> f(1_m,1_m,1_m);
		e += f;
		CHECK(to_string(e) == "3 m * 6 m * 5 m");
		size_3d<> g(2_m,5_m,4_m);
		size_3d<> h(1_m,1_m,1_m);
		g -= h;
		CHECK(to_string(g) == "1 m * 4 m * 3 m");
	}

	SECTION("Operators of size_3d<float> class")
	{
		size_3d<float> a(2.0f,5.0f,4.0f);
		size_3d<float> b(3.0f,1.0f,2.0f);
		CHECK(to_string(a + b) == "5 * 6 * 6");
		size_3d<float> c(2.0f,5.0f,4.0f);
		size_3d<float> d(1.0f,2.0f,3.0f);
		CHECK(to_string(c - d) == "1 * 3 * 1");
		size_3d<float> e(2.0f,5.0f,4.0f);
		size_3d<float> f(1.0f,1.0f,1.0f);
		e += f;
		CHECK(to_string(e) == "3 * 6 * 5");
		size_3d<float> g(2.0f,5.0f,4.0f);
		size_3d<float> h(1.0f,1.0f,1.0f);
		g -= h;
		CHECK(to_string(g) == "1 * 4 * 3");
	}

	SECTION("get_volume() of size_3d<> class")
	{
		size_3d<> a(2_m,2_m,3_m);
		CHECK(bool(a.get_volume() == "12 m3"));
	}

	SECTION("get_volume() of size_3d<float> class")
	{
		size_3d<float> a(2.0f,2.0f,3.0f);
		CHECK(a.get_volume() == 12.0f);
	}

	SECTION("display() of size_3d<> class")
	{
		size_3d<> a("2 m * 3 m * 4 m");
		CHECK(a.display() == "2 m * 3 m * 4 m");
	}

	SECTION("display() of size_3d<float> class")
	{
		size_3d<float> a("2 * 3 * 4");
		CHECK(a.display() == "2 * 3 * 4");
	}

	SECTION("to_string() of size_3d<> class")
	{
		size_3d<> a("2 m * 3 m * 4 m");
		CHECK(to_string(a) == "2 m * 3 m * 4 m");
	}

	SECTION("to_string() of size_3d<float> class")
	{
		size_3d<float> a("2 * 3 * 4");
		CHECK(to_string(a) == "2 * 3 * 4");
	}

	SECTION("Comparison of size_3d<> class")
	{
		size_3d<> a(2_m,4_m,3_m);
		size_3d<> b(2_m,4_m,3_m);
		size_3d<> c(6_m,5_m,1_m);
		CHECK(bool(a == b));
		CHECK(bool(a != c));
	}

	SECTION("Comparison of size_3d<float> class")
	{
		size_3d<float> a(2.0f,4.0f,3.0f);
		size_3d<float> b(2.0f,4.0f,3.0f);
		size_3d<float> c(6.0f,5.0f,1.0f);
		CHECK(bool(a == b));
		CHECK(bool(a != c));
	}

	SECTION("String operators of size_3d<> class")
	{
		CHECK(bool(size_3d<>(2_m,4_m,3_m) == "2 m * 4 m * 3 m"));
		CHECK(bool(size_3d<>(2_m,4_m,3_m) != "2 m * 3 m * 3 m"));
		CHECK(bool("2 m * 4 m * 3 m" == size_3d<>(2_m,4_m,3_m)));
		CHECK(bool("2 m * 3 m * 3 m" != size_3d<>(2_m,4_m,3_m)));
		string a = "size_3d ";
		a += size_3d<>("2 m * 3 m * 3 m");
		CHECK(a == "size_3d 2 m * 3 m * 3 m");
		size_3d<> b = size_3d<>("2 m * 3 m * 3 m");
		CHECK("b " + b == "b 2 m * 3 m * 3 m");
		CHECK(b + " b" == "2 m * 3 m * 3 m b");
	}

	SECTION("String operators of size_3d<float> class")
	{
		CHECK(bool(size_3d<float>(2.0f,4.0f,3.0f) == "2 * 4 * 3"));
		CHECK(bool(size_3d<float>(2.0f,4.0f,3.0f) != "2 * 3 * 3"));
		CHECK(bool("2 * 4 * 3" == size_3d<float>(2.0f,4.0f,3.0f)));
		CHECK(bool("2 * 3 * 3" != size_3d<float>(2.0f,4.0f,3.0f)));
		string a = "size_3d ";
		a += size_3d<float>("2 * 3 * 3");
		CHECK(a == "size_3d 2 * 3 * 3");
		size_3d<float> b = size_3d<float>("2 * 3 * 3");
		CHECK("b " + b == "b 2 * 3 * 3");
		CHECK(b + " b" == "2 * 3 * 3 b");
	}

	SECTION("Streams of size_3d<> class")
	{
		ostringstream a;
        a << size_3d<>(2_m,3_m,1_m);
        CHECK(a.str() == "2 m * 3 m * 1 m");
        stringstream b;
        b << "1 m * 3 m * 2 m";
        size_3d<> b2;
        b >> b2;
        CHECK(to_string(b2) == "1 m * 3 m * 2 m");
	}

	SECTION("Streams of size_3d<float> class")
	{
		ostringstream a;
        a << size_3d<float>(2.0f,3.0f,1.0f);
        CHECK(a.str() == "2 * 3 * 1");
        stringstream b;
        b << "1 * 3 * 2";
        size_3d<float> b2;
        b >> b2;
        CHECK(to_string(b2) == "1 * 3 * 2");
	}
}