#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../meca_number/complex_number.hpp"
#include "../../units/unit_basic.hpp"
#include "../../predefined_units/space_units.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("complex_number<> class") {
	SECTION("Constructors of complex_number<> class")
	{
		complex_number<mass> a;
		CHECK(to_string(a) == "0 g + 0 g(i)");
		complex_number<mass> b2(10_g,1_g);
		complex_number<mass> b(b2);
		CHECK(to_string(b) == "10 g + 1 g(i)");
		complex_number<mass> c2(10_g,1_g);
		complex_number<mass> c(std::move(c2));
		CHECK(to_string(c) == "10 g + 1 g(i)");
		complex_number<mass> d(15_g,10_g);
		CHECK(to_string(d) == "15 g + 10 g(i)");
		complex_number<mass> e("10 g + 2 g(i)");
		CHECK(to_string(e) == "10 g + 2 g(i)");
		complex_number<mass> f("10 g");
		CHECK(to_string(f) == "0 g + 0 g(i)");
		complex_number<mass> g("10 g - 2 g(i)");
		CHECK(to_string(g) == "10 g - 2 g(i)");
		complex_number<mass> h("15 g","5 g");
		CHECK(to_string(h) == "15 g + 5 g(i)");
		complex_number<mass> i("10 g + 2 g");
		CHECK(to_string(i) == "0 g + 0 g(i)");
		/*complex_number<scalar_unit> j("10 g + 2 g(i)");
		CHECK(to_string(j) == "10 g + 2 g(i)");*/
    }

	SECTION("Assignments of complex_number<> class")
    {
		complex_number<mass> b;
        complex_number<mass> b2(10_g,1_g);
		b = b2;
		CHECK(to_string(b) == "10 g + 1 g(i)");
		complex_number<mass> c;
        complex_number<mass> c2(10_g,1_g);
		c = std::move(c2);
		CHECK(to_string(c) == "10 g + 1 g(i)");
    }

	SECTION("Operators of complex_number<> with another complex_number<>")
	{
		complex_number<mass> a(5_g,3_g);
		complex_number<mass> b(10_g,5_g);
		CHECK(bool((a + b) == complex_number<mass>(15_g,8_g)));
		complex_number<mass> c(5_g,3_g);
		complex_number<mass> d(3_g,2_g);
		CHECK(bool((c - d) == complex_number<mass>(2_g,1_g)));
		complex_number<mass> e(5_g,3_g);
		complex_number<mass> f(10_g,5_g);
		CHECK(bool((e * f) == complex_number<scalar_unit>(scalar_unit("35 g2"),scalar_unit("55 g2"))));
		complex_number<scalar_unit> g("100 g2","25 g2");
		complex_number<mass> h(3_g,2_g);
		CHECK(bool(to_string(g / h) == "0.03 1/g + 0.01 1/g(i)"));
		complex_number<mass> i(5_g,3_g);
		complex_number<mass> j(10_g,5_g);
		i += j;
		CHECK(bool(i == complex_number<mass>(15_g,8_g)));
		complex_number<mass> k(5_g,3_g);
		complex_number<mass> l(3_g,2_g);
		k -= l;
		CHECK(bool(k == complex_number<mass>(2_g,1_g)));
	}

	SECTION("Conjugate of complex_number<> class")
	{
		complex_number<mass> a(5_g,3_g);
		CHECK(bool(a.get_conjugate() == complex_number<mass>(5_g,scalar_unit(-3.0f,"g"))));
	}

	SECTION("Polar form of complex_number<> class")
	{
		complex_number<mass> a(5_g,3_g);
		CHECK(bool(a.get_r().display() == "5.83 g"));
		CHECK(std::fabs(a.get_argument().get_value() - 30.96f) < 0.01f);
		complex_number<length> b(scalar_unit(-5.0f,"m"),0_m);
		CHECK(std::fabs(b.get_argument().get_value() - 180.0f) < 0.01f);
		complex_number<length> c(0_m,10_m);
		CHECK(c.get_argument().get_value() == 0.0f);
	}

	SECTION("Reciprocal of complex_number<> class")
	{
		complex_number<mass> a(5_g,3_g);
		CHECK(bool(a.get_reciprocal().display() == "0.14 1/g - 0.08 1/g(i)"));
	}

	SECTION("to_string() function of complex_number<> class")
	{
		complex_number<mass> a(10_g,1_g);
		CHECK(a.display() == "10 g + 1 g(i)");
	}

	SECTION("to_string() function of complex_number<> class")
	{
		complex_number<mass> a(10_g,1_g);
		CHECK(to_string(a) == "10 g + 1 g(i)");
	}

	SECTION("is_complex() function")
	{
		CHECK(is_complex("10 g + 2 g(i)") == true);
		CHECK(is_complex("0 g + 0 g(i)") == true);
		CHECK(is_complex("0.5 g + 0.2 g(i)") == true);
		CHECK(is_complex("10 g + 2 g + 3 g(i)") == false);
		CHECK(is_complex("0.4.1 g + 0..2 g(i)") == false);
		CHECK(is_complex("10g + 0.2 g(i)") == false);
		CHECK(is_complex("10 g2m + 0.2 g(i)") == false);
		CHECK(is_complex("10 2m + 0.2 g(i)") == false);
		CHECK(is_complex("15 g + 0..2 g(i)") == false);
		CHECK(is_complex("10 g + 2g(i)") == false);
		CHECK(is_complex("10 g + 2 g2m(i)") == false);
		CHECK(is_complex("10 m + 2 2g(i)") == false);
		CHECK(is_complex("30 g + 20 g") == false);
		CHECK(is_complex("30 g +") == false);
		CHECK(is_complex("30 g +(j)") == false);
		CHECK(is_complex("0 g") == false);
		CHECK(is_complex("0 g(i)") == false);
		CHECK(is_complex("(i)") == false);
		CHECK(is_complex("+") == false);
	}

	SECTION("Math functions of complex_number<> class")
	{
		complex_number<mass> a(5_g,3_g);
		CHECK(bool(scifir::abs(a).display() == "5.83 g"));
		CHECK(bool(scifir::sqrt(a).display() == "3.29 [empty] + 0.64 [empty](i)"));
		complex_number<area> b(scalar_unit("100 m2"),scalar_unit("25 m2"));
		CHECK(bool(scifir::sqrt(b).display() == "14.25 m + 1.24 m(i)"));
		complex_number<area> c(scalar_unit("100 m2"),scalar_unit(-25.0f,"m2"));
		CHECK(bool(scifir::sqrt(c).display() == "14.25 m - 1.24 m(i)"));
		complex_number<area> d(scalar_unit("100 m2"),scalar_unit(0.0f,"m2"));
		CHECK(bool(scifir::sqrt(d).display() == "14.14 m + 0 m(i)"));
	}

	SECTION("Comparison operators of complex_number<> class")
    {
        CHECK(bool(complex_number<mass>(15_g,2_g) == complex_number<mass>(15_g,2_g)));
        CHECK((complex_number<mass>(15_g,2_g) == complex_number<mass>(10_g,3_g)) == false);
        CHECK(bool(complex_number<mass>(15_g,2_g) != complex_number<mass>(10_g,3_g)));
    }

    SECTION("String operators of complex_number<> class")
    {
        CHECK(bool(complex_number<mass>(15_g,2_g) == "15 g + 2 g(i)"));
        CHECK(bool(complex_number<mass>(15_g,2_g) != "10 g + 3 g(i)"));
        CHECK(bool("15 g + 2 g(i)" == complex_number<mass>(15_g,2_g)));
        CHECK(bool("10 g + 3 g(i)" != complex_number<mass>(15_g,2_g)));
        string a = "complex_number: ";
        a += complex_number<mass>(15_g,2_g);
        CHECK(a == "complex_number: 15 g + 2 g(i)");
        CHECK(("complex_number: " + complex_number<mass>(15_g,2_g)) == "complex_number: 15 g + 2 g(i)");
        CHECK(("complex_number: 15 g + 2 g(i)" == "complex_number: " + complex_number<mass>(15_g,2_g)));
        CHECK((complex_number<mass>(15_g,2_g)) + " complex_number" == "15 g + 2 g(i) complex_number");
    }

    SECTION("Stream operators of complex_number<> class")
    {
        ostringstream a;
        a << complex_number<mass>(15_g,2_g);
        CHECK(a.str() == "15 g + 2 g(i)");
        stringstream b;
        b << "15 g + 2 g(i)";
        complex_number<mass> b2;
        b >> b2;
        CHECK(to_string(b2) == "15 g + 2 g(i)");
    }
}