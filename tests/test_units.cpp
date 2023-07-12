#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "units.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TEST_CASE("scalar_unit class","Full test of scalar_units") {
	mass a(100,"g");
	ostringstream a_out;
	a_out << a;
	REQUIRE (a_out.str() == "1 hg");
	mass b(50,"g");
	ostringstream b_out;
	b_out << b;
	REQUIRE (b_out.str() == "5 dag");
	mass c("5.2*10^3 m");
	ostringstream c_out;
	c_out << c;
	REQUIRE (c_out.str() == "5.19 km");
	REQUIRE (c.custom_display("sci") == "5.19e3 m");
	REQUIRE (bool((a + b) == 150_g));
	REQUIRE (bool((a - b) == 50_g));
	REQUIRE (bool((a * b) == "5000 g2"));
	REQUIRE (bool(to_string(a / b) == "2 [empty]"));
	a += b;
	REQUIRE (bool(a == 150_g));
	a = mass(100,"g");
	a -= b;
	REQUIRE (bool(a == 50_g));
	a = mass(100,"g");
	REQUIRE (bool((a + 20) == 120_g));
	REQUIRE (bool((a - 10) == 90_g));
	REQUIRE (bool((a * 5) == 500_g));
	REQUIRE (bool((a / 2) == 50_g));
	REQUIRE (bool((a ^ 3) == "1000000 g3"));
	REQUIRE (bool((20 + a) == 120_g));
	REQUIRE (bool((150 - a) == 50_g));
	REQUIRE (bool((3 * a) == 300_g));
	REQUIRE (bool((200 / a) == "2 1/g"));
	a = mass(100,"g");
	a += 10;
	REQUIRE (bool(a == 110_g));
	a = mass(100,"g");
	a -= 5;
	REQUIRE (bool(a == 95_g));
	a = mass(100,"g");
	a *= 2;
	REQUIRE (bool(a == 200_g));
	a = mass(100,"g");
	a /= 4;
	REQUIRE (bool(a == 25_g));
	a = mass(100,"g");
	a++;
	REQUIRE (bool(a == 101_g));
	a = mass(100,"g");
	++a;
	REQUIRE (bool(a == 101_g));
	a = mass(100,"g");
	a--;
	REQUIRE (bool(a == 99_g));
	a = mass(100,"g");
	--a;
	REQUIRE (bool(a == 99_g));
	a = mass(100,"g");
	a.change_dimensions("kg");
	a_out = ostringstream();
	a_out << a;
	REQUIRE (bool(a_out.str() == "1 hg"));
	REQUIRE (bool(a.custom_display("mg") == "100000 mg"));
	REQUIRE (bool(a.has_dimensions("g")));
	REQUIRE (bool(a.has_dimensions("kg")));
	REQUIRE (bool(a.has_dimensions("mg")));
	REQUIRE_FALSE(bool(a.has_empty_dimensions()));
	a = mass(100,"g");
	b = mass(50,"g");
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
	REQUIRE (bool(h.display_derived() == "10 kg*m/s2"));
	
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
