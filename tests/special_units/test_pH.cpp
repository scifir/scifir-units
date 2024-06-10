#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../special_units/pH.hpp"
#include "../../special_units/pOH.hpp"
#include "../../units/unit_basic.hpp"
#include "../../units/unit_abbreviation.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("pH class","Full test of pH class") {
	SECTION("Constructors of pH class") {
        pH a = pH();
        REQUIRE (bool(a.get_value() == 0.0f));
        pH b2 = pH(6.0f);
        pH b = pH(b2);
        REQUIRE (bool(b.get_value() == 6.0f));
        pH c2 = pH(5.0f);
        pH c = pH(move(c2));
        REQUIRE (bool(c.get_value() == 5.0f));
        pH d = pH(4.0f);
        REQUIRE (bool(d.get_value() == 4.0f));
        pH e = pH("3");
        REQUIRE (bool(e.get_value() == 3.0f));
        scalar_unit f2 = 30_g;
        pH f = pH(f2 / 10_g);
        REQUIRE (bool(f.get_value() == 3.0f));
        scalar_unit g2 = 30_g;
        pH g = pH(g2);
        REQUIRE (bool(g.get_value() == 0.0f));
    }

    SECTION("Assignments of pH class") {
        pH a;
        pH a2(10.0f);
        a = a2;
        REQUIRE (bool(a.get_value() == 10.0f));
        pH b;
        pH b2(8.0f);
        b = std::move(b2);
        REQUIRE (bool(b.get_value() == 8.0f));
        pH c;
        c = 5.0f;
        REQUIRE (bool(c.get_value() == 5.0f));
        pH d;
        d = "5.0";
        REQUIRE (bool(d.get_value() == 5.0f));
        pH e;
        e = scalar_unit(3_N/1.5_N);
        REQUIRE (bool(e.get_value() == 2.0f));
        pH f;
        f = scalar_unit(3_N);
        REQUIRE (bool(f.get_value() == 0.0f));
    }

    SECTION("Values of pH class")
    {
        pH a(4.5f);
        REQUIRE (bool(float(a) == 4.5f));
        pH b(3.2f);
        REQUIRE (bool(b.get_value() == 3.2f));
    }

    SECTION("Operators of pH class with other pH classes")
    {
        pH a(3.0f);
        REQUIRE (bool(a + pH(2.0f) == pH(5.0f)));
        pH b(3.0f);
        REQUIRE (bool(b - pH(1.0f) == pH(2.0f)));
        pH c(4.0f);
        c += pH(2.0f);
        REQUIRE (bool(c == pH(6.0f)));
        pH d(4.0f);
        d -= pH(2.0f);
        REQUIRE (bool(d == pH(2.0f)));
    }

    SECTION("Numeric operators of pH class")
    {
        pH a(3.0f);
        REQUIRE (bool((a + 2.0f) == pH(5.0f)));
        pH b(3.0f);
        REQUIRE (bool((b - 1.0f) == pH(2.0f)));
        pH c(3.0f);
        REQUIRE (bool((2.0f + c) == pH(5.0f)));
        pH d(3.0f);
        REQUIRE (bool((5.0f - d) == pH(2.0f)));
        pH e(5.0f);
        e += 1.0f;
        REQUIRE (bool(e.get_value() == 6.0f));
        pH f(6.0f);
        f -= 2.0f;
        REQUIRE (bool(f.get_value() == 4.0f));
        pH g(6.0f);
        g++;
        REQUIRE (bool(g.get_value() == 7.0f));
        pH h(8.0f);
        ++h;
        REQUIRE (bool(h.get_value() == 9.0f));
        pH i(6.0f);
        i--;
        REQUIRE (bool(i.get_value() == 5.0f));
        pH j(8.0f);
        --j;
        REQUIRE (bool(j.get_value() == 7.0f));
    }

    SECTION("H and OH functions")
    {
        pH a(3.0f);
        pOH b = a.get_pOH();
        REQUIRE (bool(b.get_value() == 11.0f));
    }

    SECTION("Acidic, basic and neutral")
    {
        pH a(4.0f);
        REQUIRE (bool(a.is_acidic() == true));
        REQUIRE (bool(a.is_basic() == false));
        REQUIRE (bool(a.is_neutral() == false));
        pH b(11.0f);
        REQUIRE (bool(b.is_acidic() == false));
        REQUIRE (bool(b.is_basic() == true));
        REQUIRE (bool(b.is_neutral() == false));
        pH c(7.0f);
        REQUIRE (bool(c.is_neutral() == true));
    }

    SECTION("Display of pH")
    {
        pH a(6.5f);
        REQUIRE (bool(a.display() == "6.50"));
        REQUIRE (bool(to_string(a) == "6.50"));
    }

    SECTION("Normalize value of pH")
    {
        pH a(15.0f);
        REQUIRE (bool(a.get_value() == 0.0f));
        pH b(0.5f);
        REQUIRE (bool(b.get_value() == 0.0f));
    }

    SECTION("Comparison operators of pH class with pH classes")
    {
        REQUIRE (bool((pH(3.0f) == pH(3.0f)) == true));
        REQUIRE (bool((pH(3.0f) == pH(2.0f)) == false));
        REQUIRE (bool((pH(3.0f) != pH(2.0f)) == true));
        REQUIRE (bool((pH(3.0f) > pH(2.0f)) == true));
        REQUIRE (bool((pH(2.0f) > pH(3.0f)) == false));
        REQUIRE (bool((pH(3.0f) >= pH(2.0f)) == true));
        REQUIRE (bool((pH(3.0f) < pH(4.0f)) == true));
        REQUIRE (bool((pH(4.0f) < pH(3.0f)) == false));
        REQUIRE (bool((pH(3.0f) <= pH(4.0f)) == true));
    }

    SECTION("Comparison operators of pH class with numeric types")
    {
        REQUIRE (bool((pH(3.0f) == 3.0f) == true));
        REQUIRE (bool((pH(3.0f) == 2.0f) == false));
        REQUIRE (bool((pH(3.0f) != 2.0f) == true));
        REQUIRE (bool((3.0f == pH(3.0f)) == true));
        REQUIRE (bool((2.0f == pH(3.0f)) == false));
        REQUIRE (bool((2.0f != pH(3.0f)) == true));
        REQUIRE (bool((pH(3.0f) > 2.0f) == true));
        REQUIRE (bool((pH(3.0f) >= 2.0f) == true));
        REQUIRE (bool((pH(3.0f) < 4.0f) == true));
        REQUIRE (bool((pH(3.0f) <= 4.0f) == true));
        REQUIRE (bool((2.0f < pH(3.0f)) == true));
        REQUIRE (bool((2.0f <= pH(3.0f)) == true));
        REQUIRE (bool((4.0f > pH(3.0f)) == true));
        REQUIRE (bool((4.0f >= pH(3.0f)) == true));
    }

    SECTION("String operators with pH class")
    {
        REQUIRE (bool(pH(3.0f) == "3.0"));
        REQUIRE (bool(pH(3.0f) != "2.0"));
        REQUIRE (bool("3.0" == pH(3.0f)));
        REQUIRE (bool("2.0" != pH(3.0f)));
        string a = "pH: ";
        a += pH(4.0f);
        REQUIRE (bool(a == "pH: 4"));
        REQUIRE (bool(("pH: " + pH(5.0f)) == "pH: 5"));
        REQUIRE (bool((pH(5.0f) + " pH") == "5 pH"));
    }

    SECTION("Stream operators of pH class")
    {
        ostringstream a;
        a << pH(8.0f);
        REQUIRE (bool(a.str() == "8"));
        stringstream b;
        b << "3.0";
        pH b2;
        b >> b2;
        REQUIRE (bool(b2.get_value() == 3.0f));
    }
}