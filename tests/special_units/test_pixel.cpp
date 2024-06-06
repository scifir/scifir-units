#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../special_units/pixel.hpp"
#include "../../units/unit_basic.hpp"
#include "../../units/unit_abbreviation.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("pixel class","Full test of pixel class") {
	SECTION("Constructors of pixel class")
    {
        pixel a = pixel();
        REQUIRE (bool(a.get_value() == 0.0f));
        pixel b2 = pixel(6.0f);
        pixel b = pixel(b2);
        REQUIRE (bool(b.get_value() == 6.0f));
        pixel c2 = pixel(5.0f);
        pixel c = pixel(move(c2));
        REQUIRE (bool(c.get_value() == 5.0f));
        pixel d = pixel(4.0f);
        REQUIRE (bool(d.get_value() == 4.0f));
        pixel e = pixel(5.0);
        REQUIRE (bool(e.get_value() == 5.0f));
        pixel f = pixel((long double)6.0);
        REQUIRE (bool(f.get_value() == 6.0f));
        pixel g = pixel(3);
        REQUIRE (bool(g.get_value() == 3.0f));
        pixel h = pixel("3.5");
        REQUIRE (bool(h.get_value() == 3.5f));
        pixel h2 = pixel("3.5px");
        REQUIRE (bool(h2.get_value() == 3.5f));
        pixel h3 = pixel("3.5 px");
        REQUIRE (bool(h3.get_value() == 3.5f));
        scalar_unit i2 = 80_g;
        pixel i = pixel(i2 / 10_g);
        REQUIRE (bool(i.get_value() == 8.0f));
        scalar_unit j2 = 80_g;
        pixel j = pixel(j2);
        REQUIRE (bool(j.get_value() == 0.0f));
    }

    SECTION("Assignments of pixel class")
    {
        pixel a;
        pixel a2(10.0f);
        a = a2;
        REQUIRE (bool(a.get_value() == 10.0f));
        pixel b;
        pixel b2(8.0f);
        b = std::move(b2);
        REQUIRE (bool(b.get_value() == 8.0f));
        pixel c;
        c = 5.0f;
        REQUIRE (bool(c.get_value() == 5.0f));
        pixel d;
        d = "5.0";
        REQUIRE (bool(d.get_value() == 5.0f));
        pixel d2;
        d2 = "5.0px";
        REQUIRE (bool(d2.get_value() == 5.0f));
        pixel d3;
        d3 = "5.0 px";
        REQUIRE (bool(d3.get_value() == 5.0f));
        pixel e;
        e = scalar_unit(3_N/1.5_N);
        REQUIRE (bool(e.get_value() == 2.0f));
        pixel f;
        f = scalar_unit(3_N);
        REQUIRE (bool(f.get_value() == 0.0f));
    }

    SECTION("float cast and get_value() of pixel class")
    {
        pixel a(4.0f);
        REQUIRE (bool(float(a) == 4.0f));
        pixel b(3.0f);
        REQUIRE (bool(b.get_value() == 3.0f));
    }

    SECTION("Operators of pixel class with pixel class")
    {
        pixel a(3.0f);
        REQUIRE (bool(a + pixel(2.0f) == pixel(5.0f)));
        pixel b(3.0f);
        REQUIRE (bool(b - pixel(1.0f) == pixel(2.0f)));
        pixel c(2.0f);
        pixel c2(3.0f);
        REQUIRE (bool((c * c2) == pixel(6.0f)));
        pixel d(6.0f);
        pixel d2(3.0f);
        REQUIRE (bool((d / d2) == pixel(2.0f)));
        pixel e(6.0f);
        pixel e2(2.0f);
        REQUIRE (bool((e ^ e2) == pixel(36.0f)));
        pixel f(4.0f);
        f += pixel(2.0f);
        REQUIRE (bool(f == pixel(6.0f)));
        pixel g(4.0f);
        g -= pixel(2.0f);
        REQUIRE (bool(g == pixel(2.0f)));
        pixel h(4.0f);
        h *= pixel(2.0f);
        REQUIRE (bool(h == pixel(8.0f)));
        pixel i(4.0f);
        i /= pixel(2.0f);
        REQUIRE (bool(i == pixel(2.0f)));
        pixel j(4.0f);
        j ^= pixel(2.0f);
        REQUIRE (bool(j == pixel(16.0f)));
    }

    SECTION("Numeric operators of pixel class")
    {
        pixel a(3.0f);
        REQUIRE (bool((a + 2.0f) == pixel(5.0f)));
        pixel b(3.0f);
        REQUIRE (bool((b - 1.0f) == pixel(2.0f)));
        pixel c(3.0f);
        REQUIRE (bool((c * 2.0f) == pixel(6.0f)));
        pixel d(3.0f);
        REQUIRE (bool((d / 1.5f) == pixel(2.0f)));
        pixel e(3.0f);
        REQUIRE (bool((e ^ 2.0f) == pixel(9.0f)));
        pixel f(3.0f);
        REQUIRE (bool((2.0f + f) == pixel(5.0f)));
        pixel g(3.0f);
        REQUIRE (bool((5.0f - g) == pixel(2.0f)));
        pixel h(3.0f);
        REQUIRE (bool((2.0f * h) == pixel(6.0f)));
        pixel i(2.5f);
        REQUIRE (bool((5.0f / i) == pixel(2.0f)));
        pixel j(3.0f);
        REQUIRE (bool((5.0f ^ j) == pixel(125.0f)));
        pixel k(5.0f);
        k += 1.0f;
        REQUIRE (bool(k.get_value() == 6.0f));
        pixel l(6.0f);
        l -= 2.0f;
        REQUIRE (bool(l.get_value() == 4.0f));
        pixel m(6.0f);
        m *= 2.0f;
        REQUIRE (bool(m.get_value() == 12.0f));
        pixel n(6.0f);
        n /= 2.0f;
        REQUIRE (bool(n.get_value() == 3.0f));
        pixel o(6.0f);
        o ^= 2.0f;
        REQUIRE (bool(o.get_value() == 36.0f));
        pixel p(6.0f);
        p++;
        REQUIRE (bool(p.get_value() == 7.0f));
        pixel q(8.0f);
        ++q;
        REQUIRE (bool(q.get_value() == 9.0f));
        pixel r(6.0f);
        r--;
        REQUIRE (bool(r.get_value() == 5.0f));
        pixel s(8.0f);
        --s;
        REQUIRE (bool(s.get_value() == 7.0f));
    }

    SECTION("to_string() function of pixel class")
    {
        pixel a(3.0f);
        REQUIRE (bool(to_string(a) == "3 px"));
    }

    SECTION("is_pixel() function")
    {
        REQUIRE (bool(is_pixel("4.5 px") == true));
        REQUIRE (bool(is_pixel("4.5px") == true));
        REQUIRE (bool(is_pixel("4.5") == true));
        REQUIRE (bool(is_pixel("4.5.0") == false));
        REQUIRE (bool(is_pixel("asd") == false));
    }

    SECTION("sqrt() and sqrt_nth() functions of pixel class")
    {
        pixel a (4.0f);
        REQUIRE (bool(scifir::sqrt(a) == pixel(2.0f)));
        pixel b (8.0f);
        REQUIRE (bool(scifir::sqrt_nth(b,3) == pixel(2.0f)));
    }

    SECTION("Comparison operators of pixel class with pH classes")
    {
        REQUIRE (bool((pixel(3.0f) == pixel(3.0f)) == true));
        REQUIRE (bool((pixel(3.0f) == pixel(2.0f)) == false));
        REQUIRE (bool((pixel(3.0f) != pixel(2.0f)) == true));
        REQUIRE (bool((pixel(3.0f) > pixel(2.0f)) == true));
        REQUIRE (bool((pixel(2.0f) > pixel(3.0f)) == false));
        REQUIRE (bool((pixel(3.0f) >= pixel(2.0f)) == true));
        REQUIRE (bool((pixel(3.0f) < pixel(4.0f)) == true));
        REQUIRE (bool((pixel(4.0f) < pixel(3.0f)) == false));
        REQUIRE (bool((pixel(3.0f) <= pixel(4.0f)) == true));
    }

    SECTION("Comparison operators of pixel class with numeric types")
    {
        REQUIRE (bool((pixel(3.0f) == 3.0f) == true));
        REQUIRE (bool((pixel(3.0f) == 2.0f) == false));
        REQUIRE (bool((pixel(3.0f) != 2.0f) == true));
        REQUIRE (bool((3.0f == pixel(3.0f)) == true));
        REQUIRE (bool((2.0f == pixel(3.0f)) == false));
        REQUIRE (bool((2.0f != pixel(3.0f)) == true));
        REQUIRE (bool((pixel(3.0f) > 2.0f) == true));
        REQUIRE (bool((pixel(3.0f) >= 2.0f) == true));
        REQUIRE (bool((pixel(3.0f) < 4.0f) == true));
        REQUIRE (bool((pixel(3.0f) <= 4.0f) == true));
        REQUIRE (bool((2.0f < pixel(3.0f)) == true));
        REQUIRE (bool((2.0f <= pixel(3.0f)) == true));
        REQUIRE (bool((4.0f > pixel(3.0f)) == true));
        REQUIRE (bool((4.0f >= pixel(3.0f)) == true));
    }

    SECTION("String operators with pixel class")
    {
        REQUIRE (bool(pixel(3.0f) == "3.0"));
        REQUIRE (bool(pixel(3.0f) != "2.0"));
        REQUIRE (bool("3.0" == pixel(3.0f)));
        REQUIRE (bool("2.0" != pixel(3.0f)));
        string a = "pixel: ";
        a += pixel(4.0f);
        REQUIRE (bool(a == "pixel: 4 px"));
        REQUIRE (bool(("pixel: " + pixel(5.0f)) == "pixel: 5 px"));
        REQUIRE (bool((pixel(5.0f) + " (pixel)") == "5 px (pixel)"));
    }

    SECTION("Stream operators of pixel class")
    {
        ostringstream a;
        a << pixel(8.0f);
        REQUIRE (bool(a.str() == "8 px"));
        stringstream b;
        b << "3.0 px";
        pixel b2;
        b >> b2;
        REQUIRE (bool(b2.get_value() == 3.0f));
    }
}