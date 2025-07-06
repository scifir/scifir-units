#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../coordinates/longitude.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("longitude class") {
	SECTION("Constructors of longitude class")
    {
        longitude a;
        CHECK(a.get_value() == 0.0f);
        longitude b(10.0f);
        CHECK(b.get_value() == 10.0f);
        longitude c(15.0);
        CHECK(c.get_value() == 15.0);
        longitude d((long double)20.0);
        CHECK(d.get_value() == (long double)20.0);
        longitude e(d);
        CHECK(e.get_value() == (long double)20.0);
        longitude f(std::move(c));
        CHECK(f.get_value() == 15.0);
        longitude g(5);
        CHECK(g.get_value() == 5.0f);
        longitude h("10°");
        CHECK(h.get_value() == 10.0f);
		longitude i2("35°E");
        CHECK(i2.get_value() == 35.0f);
        longitude i3("35°W");
        CHECK(i3.get_value() == -35.0f);
        scalar_unit j2("7 N");
        longitude j(j2);
        CHECK(j.get_value() == 0.0f);
        scalar_unit k2("7 N");
        scalar_unit k3("2 N");
        longitude k(scalar_unit(k2/k3));
        CHECK(k.get_value() == 3.5f);
    }

    SECTION("Assignments of longitude class")
    {
        longitude a2(10.0f);
        longitude a;
        a = a2;
        CHECK(a.get_value() == 10.0f);
        longitude b;
        b = longitude(40.0f);
        CHECK(b.get_value() == 40.0f);
        longitude c;
        c = 8.0f;
        CHECK(c.get_value() == 8.0f);
        longitude d;
        d = "10 °";
        CHECK(d.get_value() == 10.0f);
        scalar_unit f2("7 N");
        scalar_unit f3("2 N");
        longitude f;
        f = scalar_unit(f2/f3);
        CHECK(f.get_value() == 3.5f);
        scalar_unit g2("2 N");
        longitude g;
        g = scalar_unit(g2);
        CHECK(g.get_value() == 0.0f);
    }

    SECTION("Operators of longitude class with longitude class")
    {
        longitude a(30.0f);
        longitude a2(20.0f);
        CHECK(bool((a + a2) == longitude(50.0f)));
        longitude b(30.0f);
        longitude b2(20.0f);
        CHECK(bool((b - b2) == longitude(10.0f)));
        longitude c(30.0f);
        longitude c2(2.0f);
        CHECK(bool((c * c2) == longitude(60.0f)));
        longitude d(30.0f);
        longitude d2(2.0f);
        CHECK(bool((d / d2) == longitude(15.0f)));
        longitude e(5.0f);
        longitude e2(2.0f);
        CHECK(bool((e ^ e2) == longitude(25.0f)));
        longitude f(10.0f);
        f += longitude(5.0f);
        CHECK(f.get_value() == 15.0f);
        longitude g(10.0f);
        g -= longitude(5.0f);
        CHECK(g.get_value() == 5.0f);
        longitude h(10.0f);
        h *= longitude(2.0f);
        CHECK(h.get_value() == 20.0f);
        longitude i(10.0f);
        i /= longitude(2.0f);
        CHECK(i.get_value() == 5.0);
        longitude j(10.0f);
        j ^= longitude(2.0f);
        CHECK(j.get_value() == 100.0f);
    }

    SECTION("Functions of values and normalize_value()")
    {
        longitude a(45.0f);
        a.invert();
        CHECK(a.get_value() == -135.0f);
    }

    SECTION("is_longitude() function")
    {
        CHECK(is_longitude("10°") == true);
        CHECK(is_longitude("10°") == true);
        CHECK(is_longitude("10°E") == true);
        CHECK(is_longitude("10°W") == true);
        CHECK(is_longitude("10.0°") == true);
        CHECK(is_longitude("10 deg") == false);
        CHECK(is_longitude("10 rad") == false);
        CHECK(is_longitude("10 grad") == false);
        CHECK(is_longitude("10 tr") == false);
        CHECK(is_longitude("10A°") == false);
        CHECK(is_longitude("10") == false);
        CHECK(is_longitude("10.0.9°") == false);
        CHECK(is_longitude("") == false);
    }
}