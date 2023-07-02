#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "units.hpp"

#include "unicode/unistr.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TEST_CASE("dimension class","Full test of dimension class") {
	dimension a = dimension("m",dimension::positive);
	REQUIRE (bool(a.dimension_type == dimension::m));
	REQUIRE (bool(a.dimension_sign == dimension::positive));
	REQUIRE (bool(a.prefix.prefix_type == prefix::no_prefix));
	REQUIRE (bool(a.get_symbol() == "m"));
	dimension b = dimension("m",dimension::negative);
	REQUIRE (bool(b.dimension_sign == dimension::negative));
	
	SECTION("Creation of basic dimension classes") {
		dimension a = dimension("m",dimension::positive);
		REQUIRE (bool(a.get_symbol() == "m"));
		dimension b = dimension("s",dimension::positive);
		REQUIRE (bool(b.get_symbol() == "s"));
		dimension c = dimension("g",dimension::positive);
		REQUIRE (bool(c.get_symbol() == "g"));
		dimension d = dimension("C",dimension::positive);
		REQUIRE (bool(d.get_symbol() == "C"));
		dimension e = dimension("K",dimension::positive);
		REQUIRE (bool(e.get_symbol() == "K"));
		dimension f = dimension("mol",dimension::positive);
		REQUIRE (bool(f.get_symbol() == "mol"));
		dimension g = dimension("cd",dimension::positive);
		REQUIRE (bool(g.get_symbol() == "cd"));
		dimension h = dimension("B",dimension::positive);
		REQUIRE (bool(h.get_symbol() == "B"));
		dimension i = dimension("rad",dimension::positive);
		REQUIRE (bool(i.get_symbol() == "rad"));
		dimension j = dimension("sr",dimension::positive);
		REQUIRE (bool(j.get_symbol() == "sr"));
		dimension k = dimension("money",dimension::positive);
		REQUIRE (bool(k.get_symbol() == "money"));
	}
	
	SECTION("Testing of length classes") {
		dimension a = dimension("Ym",dimension::positive);
		REQUIRE (bool(to_string(a) == "Ym"));
		dimension b = dimension("Zm",dimension::positive);
		REQUIRE (bool(to_string(b) == "Zm"));
		dimension c = dimension("Em",dimension::positive);
		REQUIRE (bool(to_string(c) == "Em"));
		dimension d = dimension("Pm",dimension::positive);
		REQUIRE (bool(to_string(d) == "Pm"));
		dimension e = dimension("Tm",dimension::positive);
		REQUIRE (bool(to_string(e) == "Tm"));
		dimension f = dimension("Gm",dimension::positive);
		REQUIRE (bool(to_string(f) == "Gm"));
		dimension g = dimension("Mm",dimension::positive);
		REQUIRE (bool(to_string(g) == "Mm"));
		dimension h = dimension("km",dimension::positive);
		REQUIRE (bool(to_string(h) == "km"));
		dimension i = dimension("hm",dimension::positive);
		REQUIRE (bool(to_string(i) == "hm"));
		dimension j = dimension("dam",dimension::positive);
		REQUIRE (bool(to_string(j) == "dam"));
		dimension k = dimension("dm",dimension::positive);
		REQUIRE (bool(to_string(k) == "dm"));
		dimension l = dimension("cm",dimension::positive);
		REQUIRE (bool(to_string(l) == "cm"));
		dimension m = dimension("mm",dimension::positive);
		REQUIRE (bool(to_string(m) == "mm"));
		dimension n = dimension("um",dimension::positive);
		REQUIRE (bool(to_string(n) == "\u00B5m"));
		//dimension n2 = dimension("\u00B5m",dimension::positive);
		//cout << "n2: " << to_string(n2) << endl;
		//string n2_icu;
		//icu::UnicodeString("\u00B5m").toUTF8String(n2_icu);
		//REQUIRE (bool(to_string(n2) == n2_icu));
		dimension o = dimension("nm",dimension::positive);
		REQUIRE (bool(to_string(o) == "nm"));
		dimension p = dimension("pm",dimension::positive);
		REQUIRE (bool(to_string(p) == "pm"));
		dimension q = dimension("fm",dimension::positive);
		REQUIRE (bool(to_string(q) == "fm"));
		dimension r = dimension("am",dimension::positive);
		REQUIRE (bool(to_string(r) == "am"));
		dimension s = dimension("zm",dimension::positive);
		REQUIRE (bool(to_string(s) == "zm"));
		dimension t = dimension("ym",dimension::positive);
		REQUIRE (bool(to_string(t) == "ym"));
	}
	
	vector<dimension> c = create_dimensions("m*s2/C4");
	REQUIRE (bool(to_string(c) == "m*s2/C4"));
	vector<dimension> d = create_derived_dimensions("N2");
	REQUIRE (bool(to_string(d) == "kg2*m2/s4"));
}

