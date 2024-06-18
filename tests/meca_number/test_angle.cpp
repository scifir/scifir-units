#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../meca_number/angle.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("angle class","Full test of angle class") {
	SECTION("Constructors of angle classes")
    {
        angle a;
        REQUIRE (a.get_value() == 0.0f);
        angle b(10.0f);
        REQUIRE (b.get_value() == 10.0f);
        angle c(15.0);
        REQUIRE (c.get_value() == 15.0);
        angle d((long double)20.0);
        REQUIRE (d.get_value() == (long double)20.0);
        angle e(d);
        REQUIRE (e.get_value() == (long double)20.0);
        angle f(std::move(c));
        REQUIRE (f.get_value() == 15.0);
        angle g(5);
        REQUIRE (g.get_value() == 5.0f);
        angle h("10\u00B0");
        REQUIRE (h.get_value() == 10.0f);
        angle i("15\u00BA");
        REQUIRE (i.get_value() == 15.0f);
        scalar_unit j2("7 N");
        angle j(j2);
        REQUIRE (j.get_value() == 0.0f);
        scalar_unit k2("7 N");
        scalar_unit k3("2 N");
        angle k(scalar_unit(k2/k3));
        REQUIRE (k.get_value() == 3.5f);
    }

    SECTION("Assignments of angle classes")
    {
        angle a2(10.0f);
        angle a;
        a = a2;
        REQUIRE (a.get_value() == 10.0f);
        angle b;
        b = angle(40.0f);
        REQUIRE (b.get_value() == 40.0f);
        angle c;
        c = 8.0f;
        REQUIRE (c.get_value() == 8.0f);
        angle d;
        d = "10 \u00B0";
        REQUIRE (d.get_value() == 10.0f);
        angle e;
        e = "10 \u00BA";
        REQUIRE (e.get_value() == 10.0f);
        scalar_unit f2("7 N");
        scalar_unit f3("2 N");
        angle f;
        f = scalar_unit(f2/f3);
        REQUIRE (f.get_value() == 3.5f);
        scalar_unit g2("2 N");
        angle g;
        g = scalar_unit(g2);
        REQUIRE (g.get_value() == 0.0f);
    }

    SECTION("Operators of angle classes with angle classes")
    {
        angle a(30.0f);
        angle a2(20.0f);
        REQUIRE (bool((a + a2) == angle(50.0f)));
        angle b(30.0f);
        angle b2(20.0f);
        REQUIRE (bool((b - b2) == angle(10.0f)));
        angle c(30.0f);
        angle c2(2.0f);
        REQUIRE (bool((c * c2) == angle(60.0f)));
        angle d(30.0f);
        angle d2(2.0f);
        REQUIRE (bool((d / d2) == angle(15.0f)));
        angle e(5.0f);
        angle e2(2.0f);
        REQUIRE (bool((e ^ e2) == angle(25.0f)));
        angle f(10.0f);
        f += angle(5.0f);
        REQUIRE (bool(f.get_value() == 15.0f));
        angle g(10.0f);
        g -= angle(5.0f);
        REQUIRE (bool(g.get_value() == 5.0f));
        angle h(10.0f);
        h *= angle(2.0f);
        REQUIRE (bool(h.get_value() == 20.0f));
        angle i(10.0f);
        i /= angle(2.0f);
        REQUIRE (bool(i.get_value() == 5.0f));
        angle j(10.0f);
        j ^= angle(2.0f);
        REQUIRE (bool(j.get_value() == 100.0f));
    }

    SECTION("Operators of angle classes with numbers")
    {
        angle a(10.0f);
        a++;
        REQUIRE (bool(a.get_value() == 11.0f));
        angle b(10.0f);
        ++b;
        REQUIRE (bool(b.get_value() == 11.0f));
        angle c(10.0f);
        c--;
        REQUIRE (bool(c.get_value() == 9.0f));
        angle d(10.0f);
        --d;
        REQUIRE (bool(d.get_value() == 9.0f));
    }

    SECTION("Functions of values and normalize_value()")
    {
        angle a(45.0f);
        a.invert();
        REQUIRE (bool(a.get_value() == 225.0f));
        angle b(365.0f);
        REQUIRE (bool(b.get_value() == 5.0f));
        angle c(-10.0f);
        REQUIRE (bool(c.get_value() == 350.0f));
    }

    SECTION("Display of angles")
    {
        angle a(45.0f);
        REQUIRE (bool(a.display() == "45\u00B0"));
        angle b(-0.0f);
        REQUIRE (bool(b.display() == "0\u00B0"));
        angle c(60.0f);
        REQUIRE (bool(to_string(c) == "60\u00B0"));
    }

    SECTION("is_angle function")
    {
        REQUIRE (bool(is_angle("10\u00B0") == true));
        REQUIRE (bool(is_angle("10.0\u00B0") == true));
        REQUIRE (bool(is_angle("10A\u00B0") == false));
        REQUIRE (bool(is_angle("10") == false));
        REQUIRE (bool(is_angle("10.0.9\u00B0") == false));
    }

    SECTION("Parallel and orthogonal functions")
    {
        REQUIRE (bool(scifir::parallel(angle(30.0f),angle(210.0f))) == true);
        REQUIRE (bool(scifir::parallel(angle(20.0f),angle(20.0f))) == true);
        REQUIRE (bool(scifir::parallel(angle(30.0f),angle(200.0f))) == false);
        REQUIRE (bool(scifir::orthogonal(angle(30.0f),angle(120.0f))) == true);
        REQUIRE (bool(scifir::orthogonal(angle(30.0f),angle(110.0f))) == false);
        REQUIRE (bool(scifir::orthogonal(angle(30.0f),angle(300.0f))) == true);
        REQUIRE (bool(scifir::orthogonal(angle(30.0f),angle(290.0f))) == false);
    }

    SECTION("Math functions of angle class")
    {
        REQUIRE (bool(scifir::sqrt(angle(25.0f)) == angle(5.0f)));
        REQUIRE (bool(std::fabs(float(scifir::sqrt_nth(angle(125.0f),3)) - 5.0f) < 0.00001f));
        REQUIRE (bool(std::fabs(scifir::sin(angle(20.0f)) - 0.34202f) < 0.00001f));
        REQUIRE (bool(std::fabs(scifir::sin(angle(45.0f)) - 0.70710f) < 0.00001f));
        REQUIRE (bool(std::fabs(scifir::cos(angle(45.0f)) - 0.70710f) < 0.00001f));
        REQUIRE (bool(std::fabs(scifir::tan(angle(45.0f)) - 1.0f) < 0.00001f));
        REQUIRE (bool(std::fabs(float(scifir::asin(0.45f) - angle(26.74368f))) < 0.00001f));
        REQUIRE (bool(std::fabs(float(scifir::acos(0.45f) - angle(63.25631f))) < 0.00001f));
        REQUIRE (bool(std::fabs(float(scifir::atan(0.45f) - angle(24.22774f))) < 0.00001f));
        REQUIRE (bool(std::fabs(scifir::sinh(angle(45.0f)) - 0.868671f) < 0.00001f));
        REQUIRE (bool(std::fabs(scifir::cosh(angle(45.0f)) - 1.32461f) < 0.00001f));
        REQUIRE (bool(std::fabs(scifir::tanh(angle(45.0f)) - 0.655794f) < 0.00001f));
        REQUIRE (bool(std::fabs(float(scifir::asinh(45.0f) - angle(257.82f))) < 0.01f));
        REQUIRE (bool(std::fabs(float(scifir::acosh(45.0f) - angle(257.81f))) < 0.01f));
        REQUIRE (bool(std::fabs(float(scifir::atanh(0.5f) - angle(31.47f))) < 0.01f));
    }

    SECTION("Comparators of angle class")
    {
        REQUIRE (bool(angle(10.0f) == angle(10.0f)));
        REQUIRE (bool((angle(10.0f) == angle(6.0f)) == false));
        REQUIRE (bool(angle(10.0f) != angle(7.0f)));
        REQUIRE (bool(angle(5.0f) < angle(10.0f)));
        REQUIRE (bool((angle(10.0f) < angle(5.0f)) == false));
        REQUIRE (bool(angle(10.0f) > angle(5.0f)));
        REQUIRE (bool((angle(5.0f) > angle(10.0f)) == false));
        REQUIRE (bool((angle(6.0f) <= angle(8.0f))));
        REQUIRE (bool(angle(10.0f) >= angle(5.0f)));
    }

    SECTION("String operators of angle class")
    {
        REQUIRE (bool(angle(10.0f) == "10\u00B0"));
        REQUIRE (bool(angle(10.0f) != "8\u00B0"));
        REQUIRE (bool("10\u00B0" == angle(10.0f)));
        REQUIRE (bool("8\u00B0" != angle(10.0f)));
        string a = "angle: ";
        a += angle(20.0f);
        REQUIRE (bool(a == "angle: 20\u00B0"));
        REQUIRE (bool(("angle: " + angle(20.0f)) == "angle: 20\u00B0"));
        REQUIRE (bool(("angle: 20\u00B0" == "angle: " + angle(20.0f))));
        REQUIRE (bool((angle(20.0f)) + " angle" == "20\u00B0 angle"));
    }

    SECTION("Stream operators of angle class")
    {
        ostringstream a;
        a << angle(15.0f);
        REQUIRE (bool(a.str() == "15\u00B0"));
        stringstream b;
        b << "15\u00B0";
        angle b2;
        b >> b2;
        REQUIRE (bool(b2.get_value() == 15.0f));
    }
}