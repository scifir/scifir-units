#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "units.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TEST_CASE("dimension class","Full test of dimension class") {
	dimension a = create_dimension("m",dimension::positive);
	REQUIRE (bool(a.dimension_type == dimension::m));
	REQUIRE (bool(a.dimension_sign == dimension::positive));
	REQUIRE (bool(a.prefix.prefix_type == prefix::no_prefix));
	REQUIRE (bool(a.get_symbol() == "m"));
	dimension b = create_dimension("m",dimension::negative);
	REQUIRE (bool(b.dimension_sign == dimension::negative));
	vector<dimension> c = create_dimensions("m*s2/C4");
	REQUIRE (bool(to_string(c) == "m*s2/C4"));
	vector<dimension> d = create_derived_dimensions("N2");
	cout << "d: " << to_string(d) << endl;
	REQUIRE (bool(to_string(d) == "kg2*m2/s4"));
}

