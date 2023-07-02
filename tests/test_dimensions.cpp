#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "units.hpp"

#include "unicode/unistr.h"

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
	
	SECTION("Testing of length classes") {
		dimension a = create_dimension("Ym",dimension::positive);
		REQUIRE (bool(to_string(a) == "Ym"));
		dimension b = create_dimension("Zm",dimension::positive);
		REQUIRE (bool(to_string(b) == "Zm"));
		dimension c = create_dimension("Em",dimension::positive);
		REQUIRE (bool(to_string(c) == "Em"));
		dimension d = create_dimension("Pm",dimension::positive);
		REQUIRE (bool(to_string(d) == "Pm"));
		dimension e = create_dimension("Tm",dimension::positive);
		REQUIRE (bool(to_string(e) == "Tm"));
		dimension f = create_dimension("Gm",dimension::positive);
		REQUIRE (bool(to_string(f) == "Gm"));
		dimension g = create_dimension("Mm",dimension::positive);
		REQUIRE (bool(to_string(g) == "Mm"));
		dimension h = create_dimension("km",dimension::positive);
		REQUIRE (bool(to_string(h) == "km"));
		dimension i = create_dimension("hm",dimension::positive);
		REQUIRE (bool(to_string(i) == "hm"));
		dimension j = create_dimension("dam",dimension::positive);
		REQUIRE (bool(to_string(j) == "dam"));
		dimension k = create_dimension("dm",dimension::positive);
		REQUIRE (bool(to_string(k) == "dm"));
		dimension l = create_dimension("cm",dimension::positive);
		REQUIRE (bool(to_string(l) == "cm"));
		dimension m = create_dimension("mm",dimension::positive);
		REQUIRE (bool(to_string(m) == "mm"));
		dimension n = create_dimension("um",dimension::positive);
		REQUIRE (bool(to_string(n) == "\u00B5m"));
		//dimension n2 = create_dimension("\u00B5m",dimension::positive);
		//cout << "n2: " << to_string(n2) << endl;
		//string n2_icu;
		//icu::UnicodeString("\u00B5m").toUTF8String(n2_icu);
		//REQUIRE (bool(to_string(n2) == n2_icu));
		dimension o = create_dimension("nm",dimension::positive);
		REQUIRE (bool(to_string(o) == "nm"));
		dimension p = create_dimension("pm",dimension::positive);
		REQUIRE (bool(to_string(p) == "pm"));
		dimension q = create_dimension("fm",dimension::positive);
		REQUIRE (bool(to_string(q) == "fm"));
		dimension r = create_dimension("am",dimension::positive);
		REQUIRE (bool(to_string(r) == "am"));
		dimension s = create_dimension("zm",dimension::positive);
		REQUIRE (bool(to_string(s) == "zm"));
		dimension t = create_dimension("ym",dimension::positive);
		REQUIRE (bool(to_string(t) == "ym"));
	}
	
	vector<dimension> c = create_dimensions("m*s2/C4");
	REQUIRE (bool(to_string(c) == "m*s2/C4"));
	vector<dimension> d = create_derived_dimensions("N2");
	REQUIRE (bool(to_string(d) == "kg2*m2/s4"));
}

