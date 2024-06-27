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

TEST_CASE("pixel class") {
	SECTION("Constructors of pixel class")
    {
        pixel a = pixel();
        CHECK (bool(a.get_value() == 0.0f));
        pixel b2 = pixel(6.0f);
        pixel b = pixel(b2);
        CHECK (bool(b.get_value() == 6.0f));
        pixel c2 = pixel(5.0f);
        pixel c = pixel(move(c2));
        CHECK (bool(c.get_value() == 5.0f));
        pixel d = pixel(4.0f);
        CHECK (bool(d.get_value() == 4.0f));
        pixel e = pixel(5.0);
        CHECK (bool(e.get_value() == 5.0f));
        pixel f = pixel((long double)6.0);
        CHECK (bool(f.get_value() == 6.0f));
        pixel g = pixel(3);
        CHECK (bool(g.get_value() == 3.0f));
        pixel h = pixel("3.5");
        CHECK (bool(h.get_value() == 3.5f));
        pixel h2 = pixel("3.5px");
        CHECK (bool(h2.get_value() == 3.5f));
        pixel h3 = pixel("3.5 px");
        CHECK (bool(h3.get_value() == 3.5f));
        scalar_unit i2 = 80_g;
        pixel i = pixel(i2 / 10_g);
        CHECK (bool(i.get_value() == 8.0f));
        scalar_unit j2 = 80_g;
        pixel j = pixel(j2);
        CHECK (bool(j.get_value() == 0.0f));
    }

    SECTION("Assignments of pixel class")
    {
        pixel a;
        pixel a2(10.0f);
        a = a2;
        CHECK (bool(a.get_value() == 10.0f));
        pixel b;
        pixel b2(8.0f);
        b = std::move(b2);
        CHECK (bool(b.get_value() == 8.0f));
        pixel c;
        c = 5.0f;
        CHECK (bool(c.get_value() == 5.0f));
        pixel d;
        d = "5.0";
        CHECK (bool(d.get_value() == 5.0f));
        pixel d2;
        d2 = "5.0px";
        CHECK (bool(d2.get_value() == 5.0f));
        pixel d3;
        d3 = "5.0 px";
        CHECK (bool(d3.get_value() == 5.0f));
        pixel e;
        e = scalar_unit(3_N/1.5_N);
        CHECK (bool(e.get_value() == 2.0f));
        pixel f;
        f = scalar_unit(3_N);
        CHECK (bool(f.get_value() == 0.0f));
    }

    SECTION("float cast and get_value() of pixel class")
    {
        pixel a(4.0f);
        CHECK (bool(float(a) == 4.0f));
        pixel b(3.0f);
        CHECK (bool(b.get_value() == 3.0f));
    }

    SECTION("Operators of pixel class with pixel class")
    {
        pixel a(3.0f);
        CHECK (bool(a + pixel(2.0f) == pixel(5.0f)));
        pixel b(3.0f);
        CHECK (bool(b - pixel(1.0f) == pixel(2.0f)));
        pixel c(2.0f);
        pixel c2(3.0f);
        CHECK (bool((c * c2) == pixel(6.0f)));
        pixel d(6.0f);
        pixel d2(3.0f);
        CHECK (bool((d / d2) == pixel(2.0f)));
        pixel e(6.0f);
        pixel e2(2.0f);
        CHECK (bool((e ^ e2) == pixel(36.0f)));
        pixel f(4.0f);
        f += pixel(2.0f);
        CHECK (bool(f == pixel(6.0f)));
        pixel g(4.0f);
        g -= pixel(2.0f);
        CHECK (bool(g == pixel(2.0f)));
        pixel h(4.0f);
        h *= pixel(2.0f);
        CHECK (bool(h == pixel(8.0f)));
        pixel i(4.0f);
        i /= pixel(2.0f);
        CHECK (bool(i == pixel(2.0f)));
        pixel j(4.0f);
        j ^= pixel(2.0f);
        CHECK (bool(j == pixel(16.0f)));
    }

    SECTION("Numeric operators of pixel class")
    {
        pixel a(3.0f);
        CHECK (bool((a + 2.0f) == pixel(5.0f)));
        pixel b(3.0f);
        CHECK (bool((b - 1.0f) == pixel(2.0f)));
        pixel c(3.0f);
        CHECK (bool((c * 2.0f) == pixel(6.0f)));
        pixel d(3.0f);
        CHECK (bool((d / 1.5f) == pixel(2.0f)));
        pixel e(3.0f);
        CHECK (bool((e ^ 2.0f) == pixel(9.0f)));
        pixel f(3.0f);
        CHECK (bool((2.0f + f) == pixel(5.0f)));
        pixel g(3.0f);
        CHECK (bool((5.0f - g) == pixel(2.0f)));
        pixel h(3.0f);
        CHECK (bool((2.0f * h) == pixel(6.0f)));
        pixel i(2.5f);
        CHECK (bool((5.0f / i) == pixel(2.0f)));
        pixel j(3.0f);
        CHECK (bool((5.0f ^ j) == pixel(125.0f)));
        pixel k(5.0f);
        k += 1.0f;
        CHECK (bool(k.get_value() == 6.0f));
        pixel l(6.0f);
        l -= 2.0f;
        CHECK (bool(l.get_value() == 4.0f));
        pixel m(6.0f);
        m *= 2.0f;
        CHECK (bool(m.get_value() == 12.0f));
        pixel n(6.0f);
        n /= 2.0f;
        CHECK (bool(n.get_value() == 3.0f));
        pixel o(6.0f);
        o ^= 2.0f;
        CHECK (bool(o.get_value() == 36.0f));
        pixel p(6.0f);
        p++;
        CHECK (bool(p.get_value() == 7.0f));
        pixel q(8.0f);
        ++q;
        CHECK (bool(q.get_value() == 9.0f));
        pixel r(6.0f);
        r--;
        CHECK (bool(r.get_value() == 5.0f));
        pixel s(8.0f);
        --s;
        CHECK (bool(s.get_value() == 7.0f));
    }

    SECTION("to_string() function of pixel class")
    {
        pixel a(3.0f);
        CHECK (bool(to_string(a) == "3 px"));
    }

    SECTION("is_pixel() function")
    {
        CHECK (bool(is_pixel("4.5 px") == true));
        CHECK (bool(is_pixel("4.5px") == true));
        CHECK (bool(is_pixel("4.5") == true));
        CHECK (bool(is_pixel("4.5.0") == false));
        CHECK (bool(is_pixel("asd") == false));
    }

    SECTION("sqrt() and sqrt_nth() functions of pixel class")
    {
        pixel a (4.0f);
        CHECK (bool(scifir::sqrt(a) == pixel(2.0f)));
        pixel b (8.0f);
        CHECK (bool(scifir::sqrt_nth(b,3) == pixel(2.0f)));
    }

    SECTION("Comparison operators of pixel class with pH classes")
    {
        CHECK (bool((pixel(3.0f) == pixel(3.0f)) == true));
        CHECK (bool((pixel(3.0f) == pixel(2.0f)) == false));
        CHECK (bool((pixel(3.0f) != pixel(2.0f)) == true));
        CHECK (bool((pixel(3.0f) > pixel(2.0f)) == true));
        CHECK (bool((pixel(2.0f) > pixel(3.0f)) == false));
        CHECK (bool((pixel(3.0f) >= pixel(2.0f)) == true));
        CHECK (bool((pixel(3.0f) < pixel(4.0f)) == true));
        CHECK (bool((pixel(4.0f) < pixel(3.0f)) == false));
        CHECK (bool((pixel(3.0f) <= pixel(4.0f)) == true));
    }

    SECTION("Comparison operators of pixel class with numeric types")
    {
        CHECK (bool((pixel(3.0f) == 3.0f) == true));
        CHECK (bool((pixel(3.0f) == 2.0f) == false));
        CHECK (bool((pixel(3.0f) != 2.0f) == true));
        CHECK (bool((3.0f == pixel(3.0f)) == true));
        CHECK (bool((2.0f == pixel(3.0f)) == false));
        CHECK (bool((2.0f != pixel(3.0f)) == true));
        CHECK (bool((pixel(3.0f) > 2.0f) == true));
        CHECK (bool((pixel(3.0f) >= 2.0f) == true));
        CHECK (bool((pixel(3.0f) < 4.0f) == true));
        CHECK (bool((pixel(3.0f) <= 4.0f) == true));
        CHECK (bool((2.0f < pixel(3.0f)) == true));
        CHECK (bool((2.0f <= pixel(3.0f)) == true));
        CHECK (bool((4.0f > pixel(3.0f)) == true));
        CHECK (bool((4.0f >= pixel(3.0f)) == true));
    }

    SECTION("String operators with pixel class")
    {
        CHECK (bool(pixel(3.0f) == "3.0"));
        CHECK (bool(pixel(3.0f) != "2.0"));
        CHECK (bool("3.0" == pixel(3.0f)));
        CHECK (bool("2.0" != pixel(3.0f)));
        string a = "pixel: ";
        a += pixel(4.0f);
        CHECK (bool(a == "pixel: 4 px"));
        CHECK (bool(("pixel: " + pixel(5.0f)) == "pixel: 5 px"));
        CHECK (bool((pixel(5.0f) + " (pixel)") == "5 px (pixel)"));
    }

    SECTION("Stream operators of pixel class")
    {
        ostringstream a;
        a << pixel(8.0f);
        CHECK (bool(a.str() == "8 px"));
        stringstream b;
        b << "3.0 px";
        pixel b2;
        b >> b2;
        CHECK (bool(b2.get_value() == 3.0f));
    }
}