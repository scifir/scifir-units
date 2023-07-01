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
	
	SECTION("Creation of basic dimension classes") {
		dimension a = create_dimension("m",dimension::positive);
		REQUIRE (bool(a.get_symbol() == "m"));
		dimension b = create_dimension("s",dimension::positive);
		REQUIRE (bool(b.get_symbol() == "s"));
		dimension c = create_dimension("g",dimension::positive);
		REQUIRE (bool(c.get_symbol() == "g"));
		dimension d = create_dimension("C",dimension::positive);
		REQUIRE (bool(d.get_symbol() == "C"));
		dimension e = create_dimension("K",dimension::positive);
		REQUIRE (bool(e.get_symbol() == "K"));
		dimension f = create_dimension("mol",dimension::positive);
		REQUIRE (bool(f.get_symbol() == "mol"));
		dimension g = create_dimension("cd",dimension::positive);
		REQUIRE (bool(g.get_symbol() == "cd"));
		dimension h = create_dimension("B",dimension::positive);
		REQUIRE (bool(h.get_symbol() == "B"));
		dimension i = create_dimension("rad",dimension::positive);
		REQUIRE (bool(i.get_symbol() == "rad"));
		dimension j = create_dimension("sr",dimension::positive);
		REQUIRE (bool(j.get_symbol() == "sr"));
		dimension k = create_dimension("money",dimension::positive);
		REQUIRE (bool(k.get_symbol() == "money"));
	}
	
	vector<dimension> c = create_dimensions("m*s2/C4");
	REQUIRE (bool(to_string(c) == "m*s2/C4"));
	vector<dimension> d = create_derived_dimensions("N2");
	REQUIRE (bool(to_string(d) == "kg2*m2/s4"));
}

