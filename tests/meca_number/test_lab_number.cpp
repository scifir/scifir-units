#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../meca_number/lab_number.hpp"
#include "../../units/unit_basic.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("lab_number<> class") {
	SECTION("Constructors of lab_number<> class")
	{
		lab_number<mass> a;
		CHECK(to_string(a) == "0 g \u00B1 0 g");
		lab_number<mass> b2(10_g,1_g);
		lab_number<mass> b(b2);
		CHECK(to_string(b) == "10 g \u00B1 1 g");
		lab_number<mass> c2(10_g,1_g);
		lab_number<mass> c(std::move(c2));
		CHECK(to_string(c) == "10 g \u00B1 1 g");
		lab_number<mass> d(15_g,10_g);
		CHECK(to_string(d) == "15 g \u00B1 10 g");
		/*lab_number<mass> e("10 g + 2 g");
		CHECK(to_string(e) == "10 g + 2 g");
		lab_number<mass> f("10 g");
		CHECK(to_string(f) == "0 g + 0 g");*/
    }

    SECTION("Assignments of lab_number<> class")
    {
		lab_number<mass> b;
        lab_number<mass> b2(10_g,1_g);
		b = b2;
		CHECK(to_string(b) == "10 g \u00B1 1 g");
		lab_number<mass> c;
        lab_number<mass> c2(10_g,1_g);
		c = std::move(c2);
		CHECK(to_string(c) == "10 g \u00B1 1 g");
    }

	SECTION("Operators of lab_number<> with another lab_number<>")
	{
		lab_number<mass> a(5_g,3_g);
		lab_number<mass> b(10_g,5_g);
		CHECK(bool((a + b) == lab_number<mass>(15_g,8_g)));
		lab_number<mass> c(5_g,3_g);
		lab_number<mass> d(3_g,2_g);
		CHECK(bool((c - d) == lab_number<mass>(2_g,1_g)));
		lab_number<mass> e(5_g,3_g);
		lab_number<mass> f(10_g,5_g);
		CHECK(bool((e * f) == lab_number<scalar_unit>(scalar_unit("50 g2"),scalar_unit("15 g2"))));
		lab_number<scalar_unit> g(scalar_unit("15 g2"),scalar_unit("6 g2"));
		lab_number<mass> h(3_g,2_g);
		CHECK(bool((g / h) == lab_number<scalar_unit>(scalar_unit("5 g"),scalar_unit("3 g"))));
		lab_number<mass> i(5_g,3_g);
		lab_number<mass> j(10_g,5_g);
		i += j;
		CHECK(bool(i == lab_number<mass>(15_g,8_g)));
		lab_number<mass> k(5_g,3_g);
		lab_number<mass> l(3_g,2_g);
		k -= l;
		CHECK(bool(k == lab_number<mass>(2_g,1_g)));
	}

	SECTION("Display function of lab_number<> class")
	{
		lab_number<mass> a(8_g,6_g);
		CHECK(a.display() == "8 g \u00B1 6 g");
	}

	SECTION("to_string() function of lab_number<> class")
	{
		lab_number<mass> a(10_g,1_g);
		CHECK(to_string(a) == "10 g \u00B1 1 g");
	}

    SECTION("Comparison operators of lab_number<> class")
    {
        CHECK(bool(lab_number<mass>(15_g,2_g) == lab_number<mass>(15_g,2_g)));
        CHECK((lab_number<mass>(15_g,2_g) == lab_number<mass>(10_g,3_g)) == false);
        CHECK(bool(lab_number<mass>(15_g,2_g) != lab_number<mass>(10_g,3_g)));
    }

    SECTION("String operators of lab_number<> class")
    {
        CHECK(bool(lab_number<mass>(15_g,2_g) == "15 g \u00B1 2 g"));
        CHECK(bool(lab_number<mass>(15_g,2_g) != "10 g \u00B1 3 g"));
        CHECK(bool("15 g \u00B1 2 g" == lab_number<mass>(15_g,2_g)));
        CHECK(bool("10 g \u00B1 3 g" != lab_number<mass>(15_g,2_g)));
        string a = "lab_number: ";
        a += lab_number<mass>(15_g,2_g);
        CHECK(a == "lab_number: 15 g \u00B1 2 g");
        CHECK(("lab_number: " + lab_number<mass>(15_g,2_g)) == "lab_number: 15 g \u00B1 2 g");
        CHECK(("lab_number: 15 g \u00B1 2 g" == "lab_number: " + lab_number<mass>(15_g,2_g)));
        CHECK((lab_number<mass>(15_g,2_g)) + " lab_number" == "15 g \u00B1 2 g lab_number");
    }

    SECTION("Stream operators of lab_number<> class")
    {
        ostringstream a;
        a << lab_number<mass>(15_g,2_g);
        CHECK(a.str() == "15 g \u00B1 2 g");
        stringstream b;
        b << "15 g \u00B1 2 g";
        lab_number<mass> b2;
        b >> b2;
        CHECK(to_string(b2) == "15 g \u00B1 2 g");
		stringstream c;
        c << "15 g\u00B12 g";
        lab_number<mass> c2;
        c >> c2;
        CHECK(to_string(c2) == "15 g \u00B1 2 g");
		stringstream d;
        d << "15 g +- 2 g";
        lab_number<mass> d2;
        d >> d2;
        CHECK(to_string(d2) == "15 g \u00B1 2 g");
		stringstream e;
        e << "15 g";
        lab_number<mass> e2;
        e >> e2;
        CHECK(to_string(e2) == "0 g \u00B1 0 g");
    }
}