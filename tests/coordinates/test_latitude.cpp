#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../coordinates/latitude.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("latitude class") {
	SECTION("Constructors of latitude class")
    {
        latitude a;
        CHECK(a.get_value() == 0.0f);
        latitude b(10.0f);
        CHECK(b.get_value() == 10.0f);
        latitude c(15.0);
        CHECK(c.get_value() == 15.0);
        latitude d((long double)20.0);
        CHECK(d.get_value() == (long double)20.0);
        latitude e(d);
        CHECK(e.get_value() == (long double)20.0);
        latitude f(std::move(c));
        CHECK(f.get_value() == 15.0);
        latitude g(5);
        CHECK(g.get_value() == 5.0f);
        latitude h("10°");
        CHECK(h.get_value() == 10.0f);
        latitude i("15º");
        CHECK(i.get_value() == 15.0f);
        latitude i2("20°N");
        CHECK(i2.get_value() == 20.0f);
        latitude i3("20°S");
        CHECK(i3.get_value() == -20.0f);
        scalar_unit j2("7 N");
        latitude j(j2);
        CHECK(j.get_value() == 0.0f);
        scalar_unit k2("7 N");
        scalar_unit k3("2 N");
        latitude k(scalar_unit(k2/k3));
        CHECK(k.get_value() == 3.5f);
    }

    SECTION("Assignments of latitude class")
    {
        latitude a2(10.0f);
        latitude a;
        a = a2;
        CHECK(a.get_value() == 10.0f);
        latitude b;
        b = latitude(40.0f);
        CHECK(b.get_value() == 40.0f);
        latitude c;
        c = 8.0f;
        CHECK(c.get_value() == 8.0f);
        latitude d;
        d = "10 °";
        CHECK(d.get_value() == 10.0f);
        latitude e;
        e = "10 º";
        CHECK(e.get_value() == 10.0f);
        scalar_unit f2("7 N");
        scalar_unit f3("2 N");
        latitude f;
        f = scalar_unit(f2/f3);
        CHECK(f.get_value() == 3.5f);
        scalar_unit g2("2 N");
        latitude g;
        g = scalar_unit(g2);
        CHECK(g.get_value() == 0.0f);
    }

    SECTION("Operators of latitude class with latitude class")
    {
        latitude a(30.0f);
        latitude a2(20.0f);
        CHECK(bool((a + a2) == latitude(50.0f)));
        latitude b(30.0f);
        latitude b2(20.0f);
        CHECK(bool((b - b2) == latitude(10.0f)));
        latitude c(30.0f);
        latitude c2(2.0f);
        CHECK(bool((c * c2) == latitude(60.0f)));
        latitude d(30.0f);
        latitude d2(2.0f);
        CHECK(bool((d / d2) == latitude(15.0f)));
        latitude e(5.0f);
        latitude e2(2.0f);
        CHECK(bool((e ^ e2) == latitude(25.0f)));
        latitude f(10.0f);
        f += latitude(5.0f);
        CHECK(f.get_value() == 15.0f);
        latitude g(10.0f);
        g -= latitude(5.0f);
        CHECK(g.get_value() == 5.0f);
        latitude h(10.0f);
        h *= latitude(2.0f);
        CHECK(h.get_value() == 20.0f);
        latitude i(10.0f);
        i /= latitude(2.0f);
        CHECK(i.get_value() == 5.0);
        latitude j(10.0f);
        j ^= latitude(2.0f);
        CHECK(j.get_value() == 100.0f);
    }

    SECTION("Functions of values and normalize_value()")
    {
        latitude a(45.0f);
        a.invert();
        CHECK(a.get_value() == -45.0f);
    }

    SECTION("is_latitude() function")
    {
        CHECK(is_latitude("10°") == true);
        CHECK(is_latitude("10°") == true);
        CHECK(is_latitude("10°N") == true);
        CHECK(is_latitude("10°S") == true);
        CHECK(is_latitude("10.0°") == true);
        CHECK(is_latitude("10 deg") == false);
        CHECK(is_latitude("10 rad") == false);
        CHECK(is_latitude("10 grad") == false);
        CHECK(is_latitude("10 tr") == false);
        CHECK(is_latitude("10A°") == false);
        CHECK(is_latitude("10") == false);
        CHECK(is_latitude("10.0.9°") == false);
        CHECK(is_latitude("") == false);
    }
}