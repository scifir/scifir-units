#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../nutrition/abv.hpp"
#include "../../units/base_units.hpp"
#include "../../units/special_names.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("abv class") {
	SECTION("Constructors of abv class") {
		abv a;
		CHECK(a.get_value() == 0.0f);
		abv b("23% ABV");
		abv c(b);
		CHECK(c.get_value() == 23.0f);
		abv c2(std::move(b));
		CHECK(c.get_value() == 23.0f);
		abv d(26.0f);
		CHECK(d.get_value() == 26.0f);
		abv d2(26.0);
		CHECK(d2.get_value() == 26.0f);
		abv d3(26.0l);
		CHECK(d3.get_value() == 26.0f);
		abv d4(26);
		CHECK(d4.get_value() == 26.0f);
		abv i("24% ABV");
		CHECK(i.get_value() == 24.0f);
		abv i2("24% ABVa");
		CHECK(i2.get_value() == 0.0f);
		abv i3("24a");
		CHECK(i3.get_value() == 0.0f);
		abv i4("24aqw");
		CHECK(i4.get_value() == 0.0f);
		abv i7("24 a");
		CHECK(i7.get_value() == 0.0f);
		scalar_unit j2 = 100_N;
		abv j(j2 / 10_N);
		CHECK(j.get_value() == 10.0f);
		abv j3(j2);
		CHECK(j3.get_value() == 0.0f);
		abv k(0.3f,abv::RATIO);
		CHECK(std::fabs(k.get_value() - 30.0f) < 0.01f);
		abv k2(0.3,abv::RATIO);
		CHECK(std::fabs(k2.get_value() - 30.0f) < 0.01f);
		abv k3(0.3l,abv::RATIO);
		CHECK(std::fabs(k3.get_value() - 30.0f) < 0.01f);
		abv k4(3,abv::RATIO);
		CHECK(std::fabs(k4.get_value() - 300.0f) < 0.01f);
	}

	SECTION("Assignments of abv class") {
		abv a("40% ABV");
		abv b("20% ABV");
		a = b;
		CHECK(a.get_value() == 20.0f);
		abv c("30% ABV");
		a = std::move(c);
		CHECK(a.get_value() == 30.0f);
		a = 24.0f;
		CHECK(a.get_value() == 24.0f);
		a = 24.0;
		CHECK(a.get_value() == 24.0f);
		a = 24.0l;
		CHECK(a.get_value() == 24.0f);
		a = "29% ABV";
		CHECK(a.get_value() == 29.0f);
		a = "29a";
		CHECK(a.get_value() == 0.0f);
		a = "29aqe";
		CHECK(a.get_value() == 0.0f);
		a = "29 a";
		CHECK(a.get_value() == 0.0f);
		scalar_unit d = 42_N;
		a = d / 21_N;
		CHECK(a.get_value() == 2.0f);
		a = d / 21.0f;
		CHECK(a.get_value() == 0.0f);
	}

	SECTION("Implicit conversion of abv class") {
		abv a = abv("17% ABV");
		CHECK(float(a) == 17.0f);
	}

	SECTION("Base functionalities of abv class") {
		abv a = abv("90% ABV");
		CHECK(a.get_value() == 90.0f);
		CHECK(to_string(a) == "90% ABV");
		abv b = abv("1% ABV");
		CHECK(b.get_value() == 1.0f);
		CHECK(to_string(b) == "1% ABV");
		abv c = abv(30);
		CHECK(to_string(c) == "30% ABV");
		abv d = abv(50);
		CHECK(to_string(d) == "50% ABV");
		abv e = abv(10_m / 1_m);
		CHECK(to_string(e) == "10% ABV");
		abv i = abv("70% ABV");
		CHECK(to_string(i) == "70% ABV");
		i = 65;
		CHECK(to_string(i) == "65% ABV");
		i = "46% ABV";
		CHECK(to_string(i) == "46% ABV");
		i = 50_s / 25_s;
		CHECK(to_string(i) == "2% ABV");
		abv j = abv("34% ABV");
		CHECK(float(j) == 34.0f);
		CHECK(j.get_value() == 34.0f);
		CHECK(to_string(a + j) == "124% ABV");
		CHECK(to_string(a - j) == "56% ABV");
		abv p = abv("50% ABV");
		p = 20;
		CHECK(to_string(p) == "20% ABV");
		abv q = abv("50% ABV");
		CHECK(to_string(q + 10) == "60% ABV");
		abv r = abv("50% ABV");
		CHECK(to_string(r - 10) == "40% ABV");
		abv u = abv("50% ABV");
		u += 20;
		CHECK(to_string(u) == "70% ABV");
		abv v = abv("50% ABV");
		v -= 5;
		CHECK(to_string(v) == "45% ABV");
		abv y = abv("40% ABV");
		y++;
		CHECK(to_string(y) == "41% ABV");
		abv z = abv("30% ABV");
		++z;
		CHECK(to_string(z) == "31% ABV");
		abv aa = abv("40% ABV");
		aa--;
		CHECK(to_string(aa) == "39% ABV");
		abv ab = abv("30% ABV");
		--ab;
		CHECK(to_string(ab) == "29% ABV");
	}

	SECTION("Operators of abv class") {
		abv a(30.0f);
		abv b(20.0f);
		a += b;
		CHECK(a.get_value() == 50.0f);
		abv c(30.0f);
		abv d(20.0f);
		c -= d;
		CHECK(c.get_value() == 10.0f);
	}

	SECTION("to_string() function of abv class") {
		abv a = abv("30% ABV");
		CHECK(to_string(a) == "30% ABV");
	}

	SECTION("Number operators of abv class") {
		abv a("30% ABV");
		CHECK(bool((a + 20.0f) == abv("50% ABV")));
		CHECK(bool((a - 7.0f) == abv("23% ABV")));
		CHECK(bool(a == 30.0f));
		CHECK(bool(a != 20.0f));
		CHECK(bool(a > 20.0f));
		CHECK(bool(a < 35.0f));
		CHECK(bool(a >= 25.0f));
		CHECK(bool(a <= 40.0f));
		CHECK(bool((20.0f + a) == abv("50% ABV")));
		CHECK(bool((37.0f - a) == abv("7% ABV")));
		CHECK(bool(30.0f == a));
		CHECK(bool(20.0f != a));
		CHECK(bool(20.0f < a));
		CHECK(bool(35.0f > a));
		CHECK(bool(25.0f <= a));
		CHECK(bool(40.0f >= a));
	}

	SECTION("is_abv() function")
	{
		CHECK(is_abv("90% ABV") == true);
		CHECK(is_abv("90.0% ABV") == true);
		CHECK(is_abv("90..0% ABV") == false);
		CHECK(is_abv("90sad") == false);
		CHECK(is_abv("90sad% ABV") == false);
		CHECK(is_abv("90sad% asABV") == false);
	}

	SECTION("Operators of abv class with other abv class") {
		abv a = abv("30% ABV");
		abv b = abv("20% ABV");
		CHECK(bool(a > b));
		CHECK(bool(a >= b));
		abv c = abv("30% ABV");
		abv d = abv("20% ABV");
		CHECK(bool(d < c));
		CHECK(bool(d <= c));
		abv e = abv("20% ABV");
		abv f = abv("20% ABV");
		CHECK(bool(e <= f));
		CHECK(bool(e >= f));
		CHECK(bool(e == f));
		CHECK(bool(a != b));
	}

	SECTION("String operators of abv class") {
		CHECK(bool(abv("45% ABV") == "45% ABV"));
		CHECK(bool(abv("45% ABV") != "40% ABV"));
		CHECK(bool("45% ABV" == abv("45% ABV")));
		CHECK(bool("40% ABV" != abv("45% ABV")));
		string a = "abv ";
		a += abv("40% ABV");
		CHECK(a == "abv 40% ABV");
		abv b = abv("20% ABV");
		CHECK("b " + b == "b 20% ABV");
		CHECK(b + " b" == "20% ABV b");
	}

	SECTION("String operators of abv class") {
		abv a = abv("25% ABV");
		ostringstream out;
		out << "a " << a;
		CHECK(out.str() == "a 25% ABV");
		stringstream b;
        b << "72% ABV";
        abv b2;
        b >> b2;
        CHECK(to_string(b2) == "72% ABV");
	}
}
