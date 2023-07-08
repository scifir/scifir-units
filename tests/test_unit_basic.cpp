#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "units.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TEST_CASE("basic units","Full test of basic units") {
	SECTION("Basic functionalities of basic units") {
		
	}

	SECTION("time_duration class") {
		scifir::time_duration a = scifir::time_duration("365 d");
		REQUIRE (bool(a.display_years() == "1 y"));
		scifir::time_duration b = scifir::time_duration("30 d");
		REQUIRE (bool(b.display_months() == "1 months"));
		scifir::time_duration c = scifir::time_duration("7 d");
		REQUIRE (bool(c.display_weeks() == "1 weeks"));
		scifir::time_duration d = scifir::time_duration("24 h");
		REQUIRE (bool(d.display_days() == "1 d"));
		scifir::time_duration e = scifir::time_duration("3600 s");
		REQUIRE (bool(e.display_hours() == "1 h"));
		scifir::time_duration f = scifir::time_duration("60 s");
		REQUIRE (bool(f.display_minutes() == "1 min"));
		scifir::time_duration g = scifir::time_duration("35 s");
		REQUIRE (bool(g.display_seconds() == "35 s"));
	}

	SECTION("mass class") {
		mass a = mass("5 ppm","10000000 g");
		REQUIRE (bool(to_string(a) == "5 dag"));
	}

	SECTION("mole class") {
		mole a = mole("1 ppm","1000000 g");
		REQUIRE (bool(to_string(a) == "1 g"));
	}
}

