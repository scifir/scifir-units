#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../special_units/pH.hpp"
#include "../../special_units/pOH.hpp"
#include "../../units/base_units.hpp"
#include "../../units/special_names.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("pH class") {
	SECTION("Constructors of pH class") {
        pH a = pH();
        CHECK(a.get_value() == 0.0f);
        pH b2 = pH(6.0f);
        pH b = pH(b2);
        CHECK(b.get_value() == 6.0f);
        pH c2 = pH(5.0f);
        pH c = pH(move(c2));
        CHECK(c.get_value() == 5.0f);
        pH d = pH(4.0f);
        CHECK(d.get_value() == 4.0f);
        pH e = pH("3");
        CHECK(e.get_value() == 3.0f);
        scalar_unit f2 = 30_g;
        pH f = pH(f2 / 10_g);
        CHECK(f.get_value() == 3.0f);
        scalar_unit g2 = 30_g;
        pH g = pH(g2);
        CHECK(g.get_value() == 0.0f);
    }

    SECTION("Assignments of pH class") {
        pH a;
        pH a2(10.0f);
        a = a2;
        CHECK(a.get_value() == 10.0f);
        pH b;
        pH b2(8.0f);
        b = std::move(b2);
        CHECK(b.get_value() == 8.0f);
        pH c;
        c = 5.0f;
        CHECK(c.get_value() == 5.0f);
        pH d;
        d = "5.0";
        CHECK(d.get_value() == 5.0f);
        pH e;
        e = scalar_unit(3_N/1.5_N);
        CHECK(e.get_value() == 2.0f);
        pH f;
        f = scalar_unit(3_N);
        CHECK(f.get_value() == 0.0f);
    }

    SECTION("Values of pH class")
    {
        pH a(4.5f);
        CHECK(float(a) == 4.5f);
        pH b(3.2f);
        CHECK(b.get_value() == 3.2f);
    }

    SECTION("Operators of pH class with other pH class")
    {
        pH a(3.0f);
        CHECK(bool(a + pH(2.0f) == pH(5.0f)));
        pH b(3.0f);
        CHECK(bool(b - pH(1.0f) == pH(2.0f)));
        pH c(4.0f);
        c += pH(2.0f);
        CHECK(bool(c == pH(6.0f)));
        pH d(4.0f);
        d -= pH(2.0f);
        CHECK(bool(d == pH(2.0f)));
    }

    SECTION("Numeric operators of pH class")
    {
        pH a(3.0f);
        CHECK(bool((a + 2.0f) == pH(5.0f)));
        pH b(3.0f);
        CHECK(bool((b - 1.0f) == pH(2.0f)));
        pH c(3.0f);
        CHECK(bool((2.0f + c) == pH(5.0f)));
        pH d(3.0f);
        CHECK(bool((5.0f - d) == pH(2.0f)));
        pH e(5.0f);
        e += 1.0f;
        CHECK(e.get_value() == 6.0f);
        pH f(6.0f);
        f -= 2.0f;
        CHECK(f.get_value() == 4.0f);
        pH g(6.0f);
        g++;
        CHECK(g.get_value() == 7.0f);
        pH h(8.0f);
        ++h;
        CHECK(h.get_value() == 9.0f);
        pH i(6.0f);
        i--;
        CHECK(i.get_value() == 5.0f);
        pH j(8.0f);
        --j;
        CHECK(j.get_value() == 7.0f);
    }

    SECTION("H and OH functions")
    {
        pH a(3.0f);
        pOH b = a.get_pOH();
        CHECK(b.get_value() == 11.0f);
    }

    SECTION("Acidic, basic and neutral")
    {
        pH a(4.0f);
        CHECK(a.is_acidic() == true);
        CHECK(a.is_basic() == false);
        CHECK(a.is_neutral() == false);
        pH b(11.0f);
        CHECK(b.is_acidic() == false);
        CHECK(b.is_basic() == true);
        CHECK(b.is_neutral() == false);
        pH c(7.0f);
        CHECK(c.is_neutral() == true);
    }

    SECTION("Display of pH")
    {
        pH a(6.5f);
        CHECK(a.display() == "6.5");
        CHECK(to_string(a) == "6.5");
    }

    SECTION("Normalize value of pH")
    {
        pH a(15.0f);
        CHECK(a.get_value() == 0.0f);
        pH b(0.5f);
        CHECK(b.get_value() == 0.0f);
    }

    SECTION("Comparison operators of pH class with pH class")
    {
        CHECK((pH(3.0f) == pH(3.0f)) == true);
        CHECK((pH(3.0f) == pH(2.0f)) == false);
        CHECK((pH(3.0f) != pH(2.0f)) == true);
        CHECK((pH(3.0f) > pH(2.0f)) == true);
        CHECK((pH(2.0f) > pH(3.0f)) == false);
        CHECK((pH(3.0f) >= pH(2.0f)) == true);
        CHECK((pH(3.0f) < pH(4.0f)) == true);
        CHECK((pH(4.0f) < pH(3.0f)) == false);
        CHECK((pH(3.0f) <= pH(4.0f)) == true);
    }

    SECTION("Comparison operators of pH class with numeric types")
    {
        CHECK((pH(3.0f) == 3.0f) == true);
        CHECK((pH(3.0f) == 2.0f) == false);
        CHECK((pH(3.0f) != 2.0f) == true);
        CHECK((3.0f == pH(3.0f)) == true);
        CHECK((2.0f == pH(3.0f)) == false);
        CHECK((2.0f != pH(3.0f)) == true);
        CHECK((pH(3.0f) > 2.0f) == true);
        CHECK((pH(3.0f) >= 2.0f) == true);
        CHECK((pH(3.0f) < 4.0f) == true);
        CHECK((pH(3.0f) <= 4.0f) == true);
        CHECK((2.0f < pH(3.0f)) == true);
        CHECK((2.0f <= pH(3.0f)) == true);
        CHECK((4.0f > pH(3.0f)) == true);
        CHECK((4.0f >= pH(3.0f)) == true);
    }

    SECTION("String operators with pH class")
    {
        CHECK(bool(pH(3.0f) == "3.0"));
        CHECK(bool(pH(3.0f) != "2.0"));
        CHECK(bool("3.0" == pH(3.0f)));
        CHECK(bool("2.0" != pH(3.0f)));
        string a = "pH: ";
        a += pH(4.0f);
        CHECK(a == "pH: 4");
        CHECK(("pH: " + pH(5.0f)) == "pH: 5");
        CHECK((pH(5.0f) + " pH") == "5 pH");
    }

    SECTION("Stream operators of pH class")
    {
        ostringstream a;
        a << pH(8.0f);
        CHECK(a.str() == "8");
        stringstream b;
        b << "3.0";
        pH b2;
        b >> b2;
        CHECK(b2.get_value() == 3.0f);
    }
}