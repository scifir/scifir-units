#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../units/scalar_unit.hpp"
#include "../../units/unit_basic.hpp"
#include "../../units/unit_abbreviation.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("scalar_unit class") {
	SECTION("Constructors of scalar_unit classes")
	{
		scalar_unit a;
		CHECK(to_string(a) == "0 [empty]");
		scalar_unit b = scalar_unit("100 g");
		scalar_unit c = scalar_unit(b);
		CHECK(to_string(c) == "100 g");
		scalar_unit d = scalar_unit(100.0f,"g");
		CHECK(to_string(d) == "100 g");
		scalar_unit e = scalar_unit(100.0f,{dimension("g",dimension::POSITIVE)});
		CHECK(to_string(e) == "100 g");
		scalar_unit f = scalar_unit("100 g");
		CHECK(to_string(f) == "100 g");
		scalar_unit g = scalar_unit("2E5 g");
		CHECK(to_string(g) == "200000 g");
	}

	SECTION("Assignments of scalar_unit classes")
	{
		scalar_unit a("50 g");
		scalar_unit b("100 g");
		a = b;
		CHECK(to_string(a) == "100 g");
		scalar_unit a2("50 g");
		scalar_unit b2("100 N");
		a2 = b2;
		CHECK(to_string(a2) == "50 g");
		scalar_unit c("20 m");
		c = scalar_unit("10 m");
		CHECK(to_string(c) == "10 m");
		c = scalar_unit("10 g");
		CHECK(to_string(c) == "10 m");
	}

	SECTION("Float cast")
	{
		scalar_unit a("50 g");
		CHECK(float(a) == 50.0f);
	}

	SECTION("Operators of scalar_unit classes with other scalar_unit classes")
	{
		scalar_unit a("30 g");
		scalar_unit b("25 g");
		CHECK(to_string(a + b) == "55 g");
		scalar_unit a2("30 g");
		scalar_unit b2("25 N");
		CHECK(to_string(a2 + b2) == "0 [empty]");
		scalar_unit c("30 g");
		scalar_unit d("25 g");
		CHECK(to_string(c - d) == "5 g");
		scalar_unit c2("30 g");
		scalar_unit d2("25 N");
		CHECK(to_string(c2 - d2) == "0 [empty]");
		scalar_unit e("30 g");
		scalar_unit f("25 g");
		CHECK(to_string(e * f) == "750 g2");
		scalar_unit e2("30 N");
		scalar_unit f2("2 g");
		CHECK(to_string(e2 / f2) == "15000 m/s2");
		scalar_unit g("3 g");
		scalar_unit h = 30_N/10_N;
		CHECK(to_string(g ^ h) == "27 g3");
		scalar_unit g2("3 g");
		scalar_unit h2 = 30_N;
		CHECK(to_string(g2 ^ h2) == "0 [empty]");
		scalar_unit i("3 g");
		scalar_unit j = 30_g;
		i += j;
		CHECK(to_string(i) == "33 g");
		scalar_unit i2("3 g");
		scalar_unit j2 = 30_N;
		i2 += j2;
		CHECK(to_string(i2) == "3 g");
		scalar_unit k("30 g");
		scalar_unit l = 3_g;
		k -= l;
		CHECK(to_string(k) == "27 g");
		scalar_unit k2("3 g");
		scalar_unit l2 = 30_N;
		k2 -= l2;
		CHECK(to_string(k2) == "3 g");
	}

	SECTION("Operations of scalar_unit classes with numbers")
	{
		scalar_unit f = scalar_unit(100.0f,"m");
		CHECK(to_string(f + 50) == "150 m");
		CHECK(to_string(f - 50) == "50 m");
		CHECK(to_string(f * 2) == "200 m");
		CHECK(to_string(f / 4) == "25 m");
		CHECK(to_string(f ^ 2) == "10000 m2");
		CHECK(to_string(50 + f) == "150 m");
		CHECK(to_string(150 - f) == "50 m");
		CHECK(to_string(2 * f) == "200 m");
		CHECK(to_string(200 / f) == "2 1/m");
		scalar_unit g = scalar_unit(100.0f,"m");
		g += 10;
		CHECK(to_string(g) == "110 m");
		scalar_unit h = scalar_unit(100.0f,"m");
		h -= 10;
		CHECK(to_string(h) == "90 m");
		scalar_unit i = scalar_unit(100.0f,"m");
		i *= 2;
		CHECK(to_string(i) == "200 m");
		scalar_unit i2 = scalar_unit(100.0f,"m");
		i2 *= -2;
		CHECK(to_string(i2) == "-200 m");
		scalar_unit j = scalar_unit(100.0f,"m");
		j /= 2;
		CHECK(to_string(j) == "50 m");
		scalar_unit j2 = scalar_unit(100.0f,"m");
		j2 /= -2;
		CHECK(to_string(j2) == "-50 m");
	}

	SECTION("change_dimensions() of scalar_unit classes")
	{
		scalar_unit a("50 N");
		a.change_dimensions("g*m/s2");
		CHECK(bool(a == "50000 g*m/s2"));
		scalar_unit b("50 N2");
		scalar_unit c("20 N*g*m/s2");
		b.change_dimensions(c);
		CHECK(bool(b == "50000 N*g*m/s2"));
		scalar_unit b2("50 N");
		scalar_unit c2("20 N*g*m/s2");
		b2.change_dimensions(c2);
		CHECK(bool(b2 == "50 N"));
		scalar_unit b3("50 N*kg");
		scalar_unit c3("20 N*kg");
		b3.change_dimensions(c3);
		CHECK(bool(b3 == "50 N*kg"));
		scalar_unit d("50 N*kg");
		d.change_dimensions("N*kg");
		CHECK(bool(d == "50 N*kg"));
		scalar_unit e("50 N*kg");
		e.change_dimensions("kg");
		CHECK(bool(e == "50 N*kg"));
	}

	SECTION("display_dimensions() of scalar_unit classes")
	{
		scalar_unit a("50 m");
		CHECK(a.display_dimensions() == "m");
		scalar_unit b("50 1/m");
		CHECK(b.display_dimensions() == "1/m");
		scalar_unit c("50 m/s");
		CHECK(c.display_dimensions() == "m/s");
		scalar_unit d = 10_N/5_N;
		CHECK(d.display_dimensions() == "[empty]");
		scalar_unit e("2 N");
		CHECK(to_string(e.get_derived_dimensions()) == "kg*m/s2");
	}

	SECTION("Display of scalar_unit classes")
	{
		scalar_unit a = scalar_unit(1.0f,"N");
		CHECK(a.display() == "1 N");
		CHECK(a.derived_display() == "1 kg*m/s2");
		CHECK(a.custom_display("g*m/s2") == "1000 g*m/s2");
		scalar_unit b("100 m");
		CHECK(b.display() == "100 m");
		CHECK(b.display(2,false,true) == "1 hm");
		scalar_unit c("10 N");
		CHECK(c.derived_display(2,false,true) == "10 kg*m/s2");
		scalar_unit d("0 m");
		CHECK(d.display(2,false,true) == "0 m");
		scalar_unit e("1 AU");
		CHECK(e.derived_display(2,false,true) == "1.49598e+11 m");
		scalar_unit f("1 km/h");
		CHECK(f.custom_display("m/s",2,true) == "0.27 [m/s]");
	}

	SECTION("Math functions of scalar_unit classes")
	{
		scalar_unit a("2 N");
		CHECK(scifir::abs(a) == 2.0f);
		scalar_unit b("4 N2");
		CHECK(bool(scifir::sqrt(b) == scalar_unit("2 N")));
		scalar_unit c("8 N3");
		CHECK(bool(scifir::sqrt_nth(c,3) == scalar_unit("2 N")));
		scalar_unit d("2 N");
		CHECK(bool(scifir::pow(d,2) == "4 N2"));
	}

	SECTION("Comparison operators of scalar_unit classes with other scalar_unit classes")
	{
		scalar_unit a("2 N");
		scalar_unit a2("2 N");
		CHECK(bool(a == a2));
		scalar_unit b("2 N");
		scalar_unit b2("2 N2");
		CHECK(bool(b != b2));
		CHECK(bool(scalar_unit("2 N") > scalar_unit("1 N")));
		CHECK(bool(scalar_unit("2 N") >= scalar_unit("2 N")));
		CHECK(bool(scalar_unit("1 N") < scalar_unit("2 N")));
		CHECK(bool(scalar_unit("1 N") <= scalar_unit("2 N")));
	}

	SECTION("Comparison operators of scalar_unit classes with strings")
	{
		CHECK(bool(scalar_unit("2 N") == "2 N"));
		CHECK(bool(scalar_unit("2 N") != "1 N"));
		CHECK(bool(scalar_unit("2 N") > "1 N"));
		CHECK(bool(scalar_unit("2 N") >= "2 N"));
		CHECK(bool(scalar_unit("2 N") < "3 N"));
		CHECK(bool(scalar_unit("2 N") <= "3 N"));
		CHECK(bool("2 N" == scalar_unit("2 N")));
		CHECK(bool("1 N" != scalar_unit("2 N")));
		CHECK(bool("1 N" < scalar_unit("2 N")));
		CHECK(bool("2 N" <= scalar_unit("2 N")));
		CHECK(bool("3 N" > scalar_unit("2 N")));
		CHECK(bool("3 N" >= scalar_unit("2 N")));
	}

	SECTION("Comparison operators of scalar_unit classes with numeric types")
	{
		CHECK(bool(scalar_unit("2 N") == 2));
		CHECK(bool(scalar_unit("2 N") != 1));
		CHECK(bool(scalar_unit("2 N") > 1));
		CHECK(bool(scalar_unit("2 N") >= 2));
		CHECK(bool(scalar_unit("2 N") < 3));
		CHECK(bool(scalar_unit("2 N") <= 3));
		CHECK(bool(2 == scalar_unit("2 N")));
		CHECK(bool(1 != scalar_unit("2 N")));
		CHECK(bool(1 < scalar_unit("2 N")));
		CHECK(bool(2 <= scalar_unit("2 N")));
		CHECK(bool(3 > scalar_unit("2 N")));
		CHECK(bool(3 >= scalar_unit("2 N")));
	}

	SECTION("String operations with scalar_unit classes")
	{
		scalar_unit a("2 N");
		CHECK(bool(a == "2 N"));
		CHECK(bool(a != "3 N"));
		CHECK(bool("2 N" == a));
		CHECK(bool("3 N" != a));
		scalar_unit b("2 N");
		string b2 = "b: ";
		b2 += b;
		CHECK("b: 2 N");
		scalar_unit c("2 N");
		CHECK(("b: " + c) == "b: 2 N");
		CHECK((c + " b") == "2 N b");
	}

	SECTION("Stream operators of scalar_unit class")
    {
        ostringstream a;
        a << scalar_unit("2 N");
        CHECK(a.str() == "2 N");
        stringstream b;
        b << "3 N";
        scalar_unit b2("1 N");
        b >> b2;
        CHECK(bool(b2 == "3 N"));
    }

	mass a(100.0f,"g");
	ostringstream a_out;
	a_out << a;
	CHECK(a_out.str() == "100 g");
	mass b(50.0f,"g");
	ostringstream b_out;
	b_out << b;
	CHECK(b_out.str() == "50 g");
	mass c("5.2*10^3 m");
	ostringstream c_out;
	c_out << c;
	CHECK(c_out.str() == "5200 m");
	CHECK(c.custom_display("sci") == "5.19e3 m");
	CHECK(bool((a + b) == 150_g));
	CHECK(bool((a - b) == 50_g));
	CHECK(bool((a * b) == "5000 g2"));
	CHECK(to_string(a / b) == "2 [empty]");
	a += b;
	CHECK(bool(a == 150_g));
	a = mass(100.0f,"g");
	a -= b;
	CHECK(bool(a == 50_g));
	a = mass(100.0f,"g");
	CHECK(bool((a + 20) == 120_g));
	CHECK(bool((a - 10) == 90_g));
	CHECK(bool((a * 5) == 500_g));
	CHECK(bool((a / 2) == 50_g));
	CHECK(bool((a ^ 3) == "1000000 g3"));
	CHECK(bool((20 + a) == 120_g));
	CHECK(bool((150 - a) == 50_g));
	CHECK(bool((3 * a) == 300_g));
	CHECK(bool((200 / a) == "2 1/g"));
	a = mass(100.0f,"g");
	a += 10;
	CHECK(bool(a == 110_g));
	a = mass(100.0f,"g");
	a -= 5;
	CHECK(bool(a == 95_g));
	a = mass(100.0f,"g");
	a *= 2;
	CHECK(bool(a == 200_g));
	a = mass(100.0f,"g");
	a /= 4;
	CHECK(bool(a == 25_g));
	a = mass(100.0f,"g");
	a++;
	CHECK(bool(a == 101_g));
	a = mass(100.0f,"g");
	++a;
	CHECK(bool(a == 101_g));
	a = mass(100.0f,"g");
	a--;
	CHECK(bool(a == 99_g));
	a = mass(100.0f,"g");
	--a;
	CHECK(bool(a == 99_g));
	a = mass(100.0f,"g");
	a.change_dimensions("kg");
	a_out = ostringstream();
	a_out << a;
	CHECK(a_out.str() == "0.1 kg");
	CHECK(a.custom_display("mg") == "100000 mg");
	CHECK(a.has_dimensions("g"));
	CHECK(a.has_dimensions("kg"));
	CHECK(a.has_dimensions("mg"));
	CHECK_FALSE(a.has_empty_dimensions());
	a = mass(100.0f,"g");
	b = mass(50.0f,"g");
	CHECK((a / b).has_empty_dimensions());
	CHECK(bool(a < 110_g));
	CHECK_FALSE(bool(a < 90_g));
	CHECK(bool(a > 70_g));
	CHECK_FALSE(bool(a > 120_g));
	CHECK(bool(a <= 100_g));
	CHECK_FALSE(bool(a <= 90_g));
	CHECK(bool(a >= 100_g));
	CHECK_FALSE(bool(a >= 110_g));
	mass d = 1.676853_g;
	CHECK(d.display(0) == "1.67685 g");
	scifir::time_duration e = scifir::time_duration("10d 10h");
	CHECK(e.display_as_time() >= "10d 10h");
	scalar_unit f = scalar_unit("10 km*m");
	CHECK(bool(sqrt(f) == scalar_unit("100 m")));
	scalar_unit g = scalar_unit("1000 km*m*m");
	CHECK(bool(sqrt_nth(g,3) == "100 m"));
	scalar_unit h = 10_N;
	CHECK(h.derived_display() == "10 kg*m/s2");

	SECTION("is_scalar_unit() function")
	{
		CHECK(is_scalar_unit("1 m") == true);
		CHECK(is_scalar_unit("7 m2") == true);
		CHECK(is_scalar_unit("2 m/s2") == true);
		CHECK(is_scalar_unit("5 m2/s2") == true);
		CHECK(is_scalar_unit("7 $") == false);
		CHECK(is_scalar_unit("8 $2") == false);
		CHECK(is_scalar_unit("2 m$") == false);
		CHECK(is_scalar_unit("2 m2$") == false);
		CHECK(is_scalar_unit("4 g2$/m") == false);
		CHECK(is_scalar_unit("4 g/$") == false);
		CHECK(is_scalar_unit("6 m/$2") == false);
		CHECK(is_scalar_unit("9 s/m$") == false);
		CHECK(is_scalar_unit("9 s/m2$") == false);
		CHECK(is_scalar_unit("1.5 C") == true);
		CHECK(is_scalar_unit("1.5e6 s") == true);
		CHECK(is_scalar_unit("1.5*10^34 m") == true);
		CHECK(is_scalar_unit("12.37 m/s*C") == true);
		CHECK(is_scalar_unit("ms") == false);
		CHECK(is_scalar_unit("ms/C*s") == false);
		CHECK(is_scalar_unit("1.23e5") == false);
		CHECK(is_scalar_unit("1.23e m") == false);
		CHECK(is_scalar_unit("1.5*10^ m") == false);
		CHECK(is_scalar_unit("101") == false);
		CHECK(is_scalar_unit("10.1") == false);
		CHECK(is_scalar_unit("101 ") == false);
		CHECK(is_scalar_unit("10.1 ") == false);
	}
}
