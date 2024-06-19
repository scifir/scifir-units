#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../special_units/size_nd.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("size_nd class","Full test of size_nd class") {
	SECTION("Constructors of size_nd<> class")
	{
		size_nd<length> a;
		REQUIRE (bool(to_string(a) == "[empty]"));
		size_nd<> b2({2_m,3_m,1_m});
		size_nd<> b(b2);
		REQUIRE (bool(to_string(b) == "2 m * 3 m * 1 m"));
		size_nd<> c2({2_m,3_m,1_m});
		size_nd<> c(std::move(c2));
		REQUIRE (bool(to_string(c) == "2 m * 3 m * 1 m"));
		size_nd d({1_m,1_m,2_m});
		REQUIRE (bool(to_string(d) == "1 m * 1 m * 2 m"));
		size_nd<> e({"1 m","1 m","3 m"});
		REQUIRE (bool(to_string(e) == "1 m * 1 m * 3 m"));
		size_nd<> f("1 m * 1 m * 3 m");
		REQUIRE (bool(to_string(f) == "1 m * 1 m * 3 m"));
	}

	SECTION("Constructors of size_nd<float> class")
	{
		size_nd<float> a;
		REQUIRE (bool(to_string(a) == "[empty]"));
		size_nd<float> b2(vector<float>{2.0f,3.0f,1.0f});
		size_nd<float> b(b2);
		REQUIRE (bool(to_string(b) == "2 * 3 * 1"));
		size_nd<float> c2(vector<float>{2.0f,3.0f,1.0f});
		size_nd<float> c(std::move(c2));
		REQUIRE (bool(to_string(c) == "2 * 3 * 1"));
		size_nd<float> d(vector<float>{1.0f,1.0f,2.0f});
		REQUIRE (bool(to_string(d) == "1 * 1 * 2"));
		size_nd<float> e({"1","1","3"});
		REQUIRE (bool(to_string(e) == "1 * 1 * 3"));
		size_nd<float> f("1 * 1 * 3");
		REQUIRE (bool(to_string(f) == "1 * 1 * 3"));
	}

	SECTION("Assignments of size_nd<> class")
	{
		size_nd<> a;
		size_nd<> a2({2_m,3_m,1_m});
		a = a2;
		REQUIRE (bool(to_string(a) == "2 m * 3 m * 1 m"));
		size_nd<> b;
		size_nd<> b2({2_m,3_m,1_m});
		b = std::move(b2);
		REQUIRE (bool(to_string(b) == "2 m * 3 m * 1 m"));
	}

	SECTION("Assignments of size_nd<float> class")
	{
		size_nd<float> a;
		size_nd<float> a2(vector<float>{2.0f,3.0f,1.0f});
		a = a2;
		REQUIRE (bool(to_string(a) == "2 * 3 * 1"));
		size_nd<float> b;
		size_nd<float> b2(vector<float>{2.0f,3.0f,1.0f});
		b = std::move(b2);
		REQUIRE (bool(to_string(b) == "2 * 3 * 1"));
	}

	SECTION("Operators of size_nd<> class")
	{
		size_nd<> a({2_m,5_m,4_m});
		size_nd<> b({3_m,1_m,2_m});
		size_nd<> b2({3_m,1_m});
		REQUIRE (bool(to_string(a + b) == "5 m * 6 m * 6 m"));
		REQUIRE (bool(to_string(a + b2) == "[empty]"));
		size_nd<> c({2_m,5_m,4_m});
		size_nd<> d({1_m,2_m,3_m});
		size_nd<> d2({1_m,2_m});
		REQUIRE (bool(to_string(c - d) == "1 m * 3 m * 1 m"));
		REQUIRE (bool(to_string(c - d2) == "[empty]"));
		size_nd<> e({2_m,5_m,4_m});
		size_nd<> f({1_m,1_m,1_m});
		e += f;
		REQUIRE (bool(to_string(e) == "3 m * 6 m * 5 m"));
		size_nd<> g({2_m,5_m,4_m});
		size_nd<> h({1_m,1_m,1_m});
		g -= h;
		REQUIRE (bool(to_string(g) == "1 m * 4 m * 3 m"));
	}

	SECTION("Operators of size_nd<float> class")
	{
		size_nd<float> a(vector<float>{2.0f,5.0f,4.0f});
		size_nd<float> b(vector<float>{3.0f,1.0f,2.0f});
		size_nd<float> b2(vector<float>{3.0f,1.0f});
		REQUIRE (bool(to_string(a + b) == "5 * 6 * 6"));
		REQUIRE (bool(to_string(a + b2) == "[empty]"));
		size_nd<float> c(vector<float>{2.0f,5.0f,4.0f});
		size_nd<float> d(vector<float>{1.0f,2.0f,3.0f});
		size_nd<float> d2(vector<float>{1.0f,2.0f});
		REQUIRE (bool(to_string(c - d) == "1 * 3 * 1"));
		REQUIRE (bool(to_string(c - d2) == "[empty]"));
		size_nd<float> e(vector<float>{2.0f,5.0f,4.0f});
		size_nd<float> f(vector<float>{1.0f,1.0f,1.0f});
		e += f;
		REQUIRE (bool(to_string(e) == "3 * 6 * 5"));
		size_nd<float> g(vector<float>{2.0f,5.0f,4.0f});
		size_nd<float> h(vector<float>{1.0f,1.0f,1.0f});
		g -= h;
		REQUIRE (bool(to_string(g) == "1 * 4 * 3"));
	}

	SECTION("get_volume_nd() of size_nd<> class")
	{
		size_nd<> a({2_m,2_m,3_m,2_m});
		REQUIRE (bool(a.get_volume_nd() == "24 m4"));
	}

	SECTION("get_volume_nd() of size_nd<float> class")
	{
		size_nd<float> a(vector<float>{2.0f,2.0f,3.0f,4.0f});
		REQUIRE (bool(a.get_volume_nd() == 48.0f));
	}

	SECTION("to_string() of size_nd<> class")
	{
		size_nd<> a("2 m * 3 m * 4 m");
		REQUIRE (bool(to_string(a) == "2 m * 3 m * 4 m"));
	}

	SECTION("to_string() of size_nd<float> class")
	{
		size_nd<float> a("2 * 3 * 4");
		REQUIRE (bool(to_string(a) == "2 * 3 * 4"));
	}

	SECTION("Comparison of size_nd<> classes")
	{
		size_nd<> a({2_m,4_m,3_m});
		size_nd<> b({2_m,4_m,3_m});
		size_nd<> c({6_m,5_m,1_m});
		size_nd<> d({6_m,5_m});
		REQUIRE (bool(a == b));
		REQUIRE (bool((a == c) == false));
		REQUIRE (bool((a == d) == false));
		REQUIRE (bool(a != c));
	}

	SECTION("Comparison of size_nd<float> classes")
	{
		size_nd<float> a(vector<float>{2.0f,4.0f,3.0f});
		size_nd<float> b(vector<float>{2.0f,4.0f,3.0f});
		size_nd<float> c(vector<float>{6.0f,5.0f,1.0f});
		size_nd<float> d(vector<float>{6.0f,5.0f});
		REQUIRE (bool(a == b));
		REQUIRE (bool((a == c) == false));
		REQUIRE (bool((a == d) == false));
		REQUIRE (bool(a != c));
	}

	SECTION("String operators of size_nd<> class")
	{
		REQUIRE (bool(size_nd<>({2_m,4_m,3_m}) == "2 m * 4 m * 3 m"));
		REQUIRE (bool(size_nd<>({2_m,4_m,3_m}) != "2 m * 3 m * 3 m"));
		REQUIRE (bool("2 m * 4 m * 3 m" == size_nd<>({2_m,4_m,3_m})));
		REQUIRE (bool("2 m * 3 m * 3 m" != size_nd<>({2_m,4_m,3_m})));
		string a = "size_nd ";
		a += size_nd<>("2 m * 3 m * 3 m");
		REQUIRE (bool(a == "size_nd 2 m * 3 m * 3 m"));
		size_nd<> b = size_nd<>("2 m * 3 m * 3 m");
		REQUIRE (bool("b " + b == "b 2 m * 3 m * 3 m"));
		REQUIRE (bool(b + " b" == "2 m * 3 m * 3 m b"));
	}

	SECTION("String operators of size_nd<float> class")
	{
		REQUIRE (bool(size_nd<float>(vector<float>{2.0f,4.0f,3.0f}) == "2 * 4 * 3"));
		REQUIRE (bool(size_nd<float>(vector<float>{2.0f,4.0f,3.0f}) != "2 * 3 * 3"));
		REQUIRE (bool("2 * 4 * 3" == size_nd<float>(vector<float>{2.0f,4.0f,3.0f})));
		REQUIRE (bool("2 * 3 * 3" != size_nd<float>(vector<float>{2.0f,4.0f,3.0f})));
		string a = "size_nd ";
		a += size_nd<float>("2 * 3 * 3");
		REQUIRE (bool(a == "size_nd 2 * 3 * 3"));
		size_nd<float> b = size_nd<float>("2 * 3 * 3");
		REQUIRE (bool("b " + b == "b 2 * 3 * 3"));
		REQUIRE (bool(b + " b" == "2 * 3 * 3 b"));
	}

	SECTION("Streams of size_nd<> class")
	{
		ostringstream a;
        a << size_nd<>({2_m,3_m,1_m});
        REQUIRE (bool(a.str() == "2 m * 3 m * 1 m"));
        stringstream b;
        b << "1 m * 3 m * 2 m";
        size_nd<> b2;
        b >> b2;
        REQUIRE (bool(to_string(b2) == "1 m * 3 m * 2 m"));
	}

	SECTION("Streams of size_nd<float> class")
	{
		ostringstream a;
        a << size_nd<float>(vector<float>{2.0f,3.0f,1.0f});
        REQUIRE (bool(a.str() == "2 * 3 * 1"));
        stringstream b;
        b << "1 * 3 * 2";
        size_nd<float> b2;
        b >> b2;
        REQUIRE (bool(to_string(b2) == "1 * 3 * 2"));
	}
}