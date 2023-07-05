#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "units.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TEST_CASE("percentage class","Full test of percentage class") {
	SECTION("Base functionalities of percentage class") {
		percentage a = percentage("90%");
		REQUIRE (bool(a.get_factor() == 0.9f));
		REQUIRE (bool(to_string(a) == "90%"));
		percentage b = percentage("110%");
		REQUIRE (bool(b.get_factor() == 1.1f));
		percentage c = percentage("1 ppm");
		REQUIRE (bool(c.get_factor() == 0.000001f));
		percentage d = percentage("1 ppb");
		REQUIRE (bool(d.get_factor() == 0.000000001f));
		percentage e = percentage("1 ppt");
		REQUIRE (bool(e.get_factor() == 0.000000000001f));
		percentage f = percentage("1 ppq");
		REQUIRE (bool(f.get_factor() == 0.000000000000001f));
	}
}


