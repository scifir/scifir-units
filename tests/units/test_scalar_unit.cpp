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

TEST_CASE("scalar_unit class","Full test of scalar_unit class") {
	SECTION("Constructors of scalar_unit classes")
	{
		scalar_unit a;
		REQUIRE (bool(to_string(a) == "0 [empty]"));
		scalar_unit b = scalar_unit("100 g");
		scalar_unit c = scalar_unit(b);
		REQUIRE (bool(to_string(c) == "100 g"));
		scalar_unit d = scalar_unit(100.0f,"g");
		REQUIRE (bool(to_string(d) == "100 g"));
		scalar_unit e = scalar_unit(100.0f,{dimension("g",dimension::POSITIVE)});
		REQUIRE (bool(to_string(e) == "100 g"));
		scalar_unit f = scalar_unit("100 g");
		REQUIRE (bool(to_string(f) == "100 g"));
	}

	SECTION("Assignments of scalar_unit classes")
	{
		scalar_unit a("50 g");
		scalar_unit b("100 g");
		a = b;
		REQUIRE (bool(to_string(a) == "100 g"));
		scalar_unit a2("50 g");
		scalar_unit b2("100 N");
		a2 = b2;
		REQUIRE (bool(to_string(a2) == "50 g"));
		scalar_unit c("20 m");
		c = scalar_unit("10 m");
		REQUIRE (bool(to_string(c) == "10 m"));
		c = scalar_unit("10 g");
		REQUIRE (bool(to_string(c) == "10 m"));
	}

	SECTION("Float cast")
	{
		scalar_unit a("50 g");
		REQUIRE (bool(float(a) == 50.0f));
	}

	SECTION("Operators of scalar_unit classes with other scalar_unit classes")
	{
		scalar_unit a("30 g");
		scalar_unit b("25 g");
		REQUIRE (bool(to_string(a + b) == "55 g"));
		scalar_unit a2("30 g");
		scalar_unit b2("25 N");
		REQUIRE (bool(to_string(a2 + b2) == "0 [empty]"));
		scalar_unit c("30 g");
		scalar_unit d("25 g");
		REQUIRE (bool(to_string(c - d) == "5 g"));
		scalar_unit c2("30 g");
		scalar_unit d2("25 N");
		REQUIRE (bool(to_string(c2 - d2) == "0 [empty]"));
		scalar_unit e("30 g");
		scalar_unit f("25 g");
		REQUIRE (bool(to_string(e * f) == "750 g2"));
		scalar_unit e2("30 N");
		scalar_unit f2("2 g");
		REQUIRE (bool(to_string(e2 / f2) == "15000 m/s2"));
		scalar_unit g("3 g");
		scalar_unit h = 30_N/10_N;
		REQUIRE (bool(to_string(g ^ h) == "27 g3"));
		scalar_unit g2("3 g");
		scalar_unit h2 = 30_N;
		REQUIRE (bool(to_string(g2 ^ h2) == "0 [empty]"));
		scalar_unit i("3 g");
		scalar_unit j = 30_g;
		i += j;
		REQUIRE (bool(to_string(i) == "33 g"));
		scalar_unit i2("3 g");
		scalar_unit j2 = 30_N;
		i2 += j2;
		REQUIRE (bool(to_string(i2) == "3 g"));
		scalar_unit k("30 g");
		scalar_unit l = 3_g;
		k -= l;
		REQUIRE (bool(to_string(k) == "27 g"));
		scalar_unit k2("3 g");
		scalar_unit l2 = 30_N;
		k2 -= l2;
		REQUIRE (bool(to_string(k2) == "3 g"));
	}

	SECTION("Operations of scalar_unit classes with numbers")
	{
		scalar_unit f = scalar_unit(100.0f,"m");
		REQUIRE(bool(to_string(f + 50) == "150 m"));
		REQUIRE(bool(to_string(f - 50) == "50 m"));
		REQUIRE(bool(to_string(f * 2) == "200 m"));
		REQUIRE(bool(to_string(f / 4) == "25 m"));
		REQUIRE(bool(to_string(f ^ 2) == "10000 m2"));
		REQUIRE(bool(to_string(50 + f) == "150 m"));
		REQUIRE(bool(to_string(150 - f) == "50 m"));
		REQUIRE(bool(to_string(2 * f) == "200 m"));
		REQUIRE(bool(to_string(200 / f) == "2 1/m"));
		scalar_unit g = scalar_unit(100.0f,"m");
		g += 10;
		REQUIRE(bool(to_string(g) == "110 m"));
		scalar_unit h = scalar_unit(100.0f,"m");
		h -= 10;
		REQUIRE(bool(to_string(h) == "90 m"));
		scalar_unit i = scalar_unit(100.0f,"m");
		i *= 2;
		REQUIRE(bool(to_string(i) == "200 m"));
		scalar_unit i2 = scalar_unit(100.0f,"m");
		i2 *= -2;
		REQUIRE(bool(to_string(i2) == "-200 m"));
		scalar_unit j = scalar_unit(100.0f,"m");
		j /= 2;
		REQUIRE(bool(to_string(j) == "50 m"));
		scalar_unit j2 = scalar_unit(100.0f,"m");
		j2 /= -2;
		REQUIRE(bool(to_string(j2) == "-50 m"));
	}

	SECTION("change_dimensions() of scalar_unit classes")
	{
		scalar_unit a("50 N");
		a.change_dimensions("g*m/s2");
		REQUIRE (bool(a == "50000 g*m/s2"));
		scalar_unit b("50 N2");
		scalar_unit c("20 N*g*m/s2");
		b.change_dimensions(c);
		cout << "b: " << b << endl;
		REQUIRE (bool(b == "50000 N*g*m/s2"));
	}

	SECTION("display_dimensions() of scalar_unit classes")
	{
		scalar_unit a("50 m");
		REQUIRE (bool(a.display_dimensions() == "m"));
		scalar_unit b("50 1/m");
		REQUIRE (bool(b.display_dimensions() == "1/m"));
		scalar_unit c("50 m/s");
		REQUIRE (bool(c.display_dimensions() == "m/s"));
		scalar_unit d = 10_N/5_N;
		REQUIRE (bool(d.display_dimensions() == "[empty]"));
		scalar_unit e("2 N");
		REQUIRE (bool(to_string(e.get_derived_dimensions()) == "kg*m/s2"));
	}

	SECTION("Display of scalar_unit classes")
	{
		scalar_unit a = scalar_unit(1.0f,"N");
		REQUIRE (bool(a.display() == "1 N"));
		REQUIRE (bool(a.derived_display() == "1 kg*m/s2"));
		REQUIRE (bool(a.custom_display("g*m/s2") == "1000 g*m/s2"));
		scalar_unit b("100 m");
		REQUIRE (bool(b.display() == "100 m"));
		REQUIRE (bool(b.display(2,false,true) == "1 hm"));
		scalar_unit c("10 N");
		cout << "derived display: " << c.derived_display(2,false,true) << endl;
		REQUIRE (bool(c.derived_display(2,false,true) == "10 kg*m/s2"));
		scalar_unit d("1000 N");
		cout << "custom display: " << d.custom_display("sci",2,true) << endl;
	}

	SECTION("Math functions of scalar_unit classes")
	{
		scalar_unit a("2 N");
		REQUIRE (bool(scifir::abs(a) == 2.0f));
		scalar_unit b("4 N2");
		REQUIRE (bool(scifir::sqrt(b) == scalar_unit("2 N")));
		scalar_unit c("8 N3");
		REQUIRE (bool(scifir::sqrt_nth(c,3) == scalar_unit("2 N")));
		scalar_unit d("2 N");
		REQUIRE (bool(scifir::pow(d,2) == "4 N2"));
	}

	SECTION("Comparison operators of scalar_unit classes")
	{
		scalar_unit a("2 N");
		scalar_unit a2("2 N");
		REQUIRE (bool(a == a2));
		scalar_unit b("2 N");
		scalar_unit b2("2 N2");
		REQUIRE (bool(b != b2));
	}

	SECTION("String operations with scalar_unit classes")
	{
		scalar_unit a("2 N");
		REQUIRE (bool(a == "2 N"));
		REQUIRE (bool(a != "3 N"));
		REQUIRE (bool("2 N" == a));
		REQUIRE (bool("3 N" != a));
		scalar_unit b("2 N");
		string b2 = "b: ";
		b2 += b;
		REQUIRE (bool("b: 2 N"));
		scalar_unit c("2 N");
		REQUIRE (bool(("b: " + c) == "b: 2 N"));
		REQUIRE (bool((c + " b") == "2 N b"));
	}

	SECTION("Stream operators of scalar_unit class")
    {
        ostringstream a;
        a << scalar_unit("2 N");
        REQUIRE (bool(a.str() == "2 N"));
        stringstream b;
        b << "3 N";
        scalar_unit b2("1 N");
        b >> b2;
        REQUIRE (bool(b2 == "3 N"));
    }

	mass a(100.0f,"g");
	ostringstream a_out;
	a_out << a;
	REQUIRE (a_out.str() == "100 g");
	mass b(50.0f,"g");
	ostringstream b_out;
	b_out << b;
	REQUIRE (b_out.str() == "50 g");
	mass c("5.2*10^3 m");
	ostringstream c_out;
	c_out << c;
	REQUIRE (c_out.str() == "5200 m");
	REQUIRE (c.custom_display("sci") == "5.19e3 m");
	REQUIRE (bool((a + b) == 150_g));
	REQUIRE (bool((a - b) == 50_g));
	REQUIRE (bool((a * b) == "5000 g2"));
	REQUIRE (bool(to_string(a / b) == "2 [empty]"));
	a += b;
	REQUIRE (bool(a == 150_g));
	a = mass(100.0f,"g");
	a -= b;
	REQUIRE (bool(a == 50_g));
	a = mass(100.0f,"g");
	REQUIRE (bool((a + 20) == 120_g));
	REQUIRE (bool((a - 10) == 90_g));
	REQUIRE (bool((a * 5) == 500_g));
	REQUIRE (bool((a / 2) == 50_g));
	REQUIRE (bool((a ^ 3) == "1000000 g3"));
	REQUIRE (bool((20 + a) == 120_g));
	REQUIRE (bool((150 - a) == 50_g));
	REQUIRE (bool((3 * a) == 300_g));
	REQUIRE (bool((200 / a) == "2 1/g"));
	a = mass(100.0f,"g");
	a += 10;
	REQUIRE (bool(a == 110_g));
	a = mass(100.0f,"g");
	a -= 5;
	REQUIRE (bool(a == 95_g));
	a = mass(100.0f,"g");
	a *= 2;
	REQUIRE (bool(a == 200_g));
	a = mass(100.0f,"g");
	a /= 4;
	REQUIRE (bool(a == 25_g));
	a = mass(100.0f,"g");
	a++;
	REQUIRE (bool(a == 101_g));
	a = mass(100.0f,"g");
	++a;
	REQUIRE (bool(a == 101_g));
	a = mass(100.0f,"g");
	a--;
	REQUIRE (bool(a == 99_g));
	a = mass(100.0f,"g");
	--a;
	REQUIRE (bool(a == 99_g));
	a = mass(100.0f,"g");
	a.change_dimensions("kg");
	a_out = ostringstream();
	a_out << a;
	REQUIRE (bool(a_out.str() == "0.1 kg"));
	REQUIRE (bool(a.custom_display("mg") == "100000 mg"));
	REQUIRE (bool(a.has_dimensions("g")));
	REQUIRE (bool(a.has_dimensions("kg")));
	REQUIRE (bool(a.has_dimensions("mg")));
	REQUIRE_FALSE(bool(a.has_empty_dimensions()));
	a = mass(100.0f,"g");
	b = mass(50.0f,"g");
	REQUIRE (bool((a / b).has_empty_dimensions()));
	REQUIRE (bool(a < 110_g));
	REQUIRE_FALSE (bool(a < 90_g));
	REQUIRE (bool(a > 70_g));
	REQUIRE_FALSE (bool(a > 120_g));
	REQUIRE (bool(a <= 100_g));
	REQUIRE_FALSE (bool(a <= 90_g));
	REQUIRE (bool(a >= 100_g));
	REQUIRE_FALSE (bool(a >= 110_g));
	mass d = 1.676853_g;
	REQUIRE (bool(d.display(0) == "1.67685 g"));
	scifir::time_duration e = scifir::time_duration("10d 10h");
	REQUIRE (bool(e.display_as_time() >= "10d 10h"));
	scalar_unit f = scalar_unit("10 km*m");
	REQUIRE (bool(sqrt(f) == scalar_unit("100 m")));
	scalar_unit g = scalar_unit("1000 km*m*m");
	REQUIRE (bool(sqrt_nth(g,3) == "100 m"));
	scalar_unit h = 10_N;
	REQUIRE (bool(h.derived_display() == "10 kg*m/s2"));
	
	SECTION("is_scalar_unit") {
		REQUIRE(bool(is_scalar_unit("1 m") == true));
		REQUIRE(bool(is_scalar_unit("1.5 C") == true));
		REQUIRE(bool(is_scalar_unit("1.5e6 s") == true));
		REQUIRE(bool(is_scalar_unit("1.5*10^34 m") == true));
		REQUIRE(bool(is_scalar_unit("12.37 m/s*C") == true));
		REQUIRE(bool(is_scalar_unit("ms") == false));
		REQUIRE(bool(is_scalar_unit("ms/C*s") == false));
		REQUIRE(bool(is_scalar_unit("1.23e5") == false));
		REQUIRE(bool(is_scalar_unit("1.23e m") == false));
		REQUIRE(bool(is_scalar_unit("1.5*10^ m") == false));
		REQUIRE(bool(is_scalar_unit("101") == false));
		REQUIRE(bool(is_scalar_unit("10.1") == false));
		REQUIRE(bool(is_scalar_unit("101 ") == false));
		REQUIRE(bool(is_scalar_unit("10.1 ") == false));
	}
}
