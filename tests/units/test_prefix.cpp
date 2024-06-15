//#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../units/prefix.hpp"

#include "unicode/unistr.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("prefix class","Full test of prefix class") {
	SECTION("Functionalities of prefix class") {
		prefix a = prefix();
		REQUIRE (bool(a.prefix_type == 0));
		prefix b = prefix(prefix::k);
		REQUIRE (bool(b.prefix_type == prefix::k));
		prefix c = prefix(b);
		REQUIRE (bool(c.prefix_type == prefix::k));
		prefix d = prefix("d");
		REQUIRE (bool(d.prefix_type == prefix::d));
		c = d;
		REQUIRE (bool(c.prefix_type == prefix::d));
		REQUIRE (bool(d.get_conversion_factor() == -1));
		REQUIRE (bool(d.get_name() == "deci"));
		REQUIRE (bool(d.get_symbol() == "d"));
		REQUIRE (bool(d < b));
		REQUIRE (bool(b > d));
		prefix e = prefix("Y");
		REQUIRE (bool(e.prefix_type == prefix::Y));
	}

	SECTION("Creation of prefix classes") {
		prefix a = prefix("Y");
		REQUIRE (bool(a.prefix_type == prefix::Y));
		prefix b = prefix("Z");
		REQUIRE (bool(b.prefix_type == prefix::Z));
		prefix c = prefix("E");
		REQUIRE (bool(c.prefix_type == prefix::E));
		prefix d = prefix("P");
		REQUIRE (bool(d.prefix_type == prefix::P));
		prefix e = prefix("T");
		REQUIRE (bool(e.prefix_type == prefix::T));
		prefix f = prefix("G");
		REQUIRE (bool(f.prefix_type == prefix::G));
		prefix g = prefix("M");
		REQUIRE (bool(g.prefix_type == prefix::M));
		prefix h = prefix("k");
		REQUIRE (bool(h.prefix_type == prefix::k));
		prefix i = prefix("h");
		REQUIRE (bool(i.prefix_type == prefix::h));
		prefix j = prefix("da");
		REQUIRE (bool(j.prefix_type == prefix::da));
		prefix k = prefix("");
		REQUIRE (bool(k.prefix_type == prefix::no_prefix));
		prefix l = prefix("c");
		REQUIRE (bool(l.prefix_type == prefix::c));
		prefix m = prefix("m");
		REQUIRE (bool(m.prefix_type == prefix::m));
		prefix n = prefix("u");
		REQUIRE (bool(n.prefix_type == prefix::u));
		//prefix j = prefix("\u00B5");
		//REQUIRE (bool(j.prefix_type == prefix::u));
		prefix o = prefix("n");
		REQUIRE (bool(o.prefix_type == prefix::n));
		prefix p = prefix("p");
		REQUIRE (bool(p.prefix_type == prefix::p));
		prefix q = prefix("f");
		REQUIRE (bool(q.prefix_type == prefix::f));
		prefix r = prefix("a");
		REQUIRE (bool(r.prefix_type == prefix::a));
		prefix s = prefix("z");
		REQUIRE (bool(s.prefix_type == prefix::z));
		prefix t = prefix("y");
		REQUIRE (bool(t.prefix_type == prefix::y));
	}

	SECTION("get_conversion_factor(), get_name() and get_symbol()")
	{
		prefix a0 = prefix(prefix::no_prefix);
		REQUIRE (bool(a0.get_conversion_factor() == 0));
		REQUIRE (bool(a0.get_name() == ""));
		REQUIRE (bool(a0.get_symbol() == ""));
		prefix a = prefix(prefix::Y);
		REQUIRE (bool(a.get_conversion_factor() == 24));
		REQUIRE (bool(a.get_name() == "yotta"));
		REQUIRE (bool(a.get_symbol() == "Y"));
		prefix a2 = prefix(prefix::Z);
		REQUIRE (bool(a2.get_conversion_factor() == 21));
		REQUIRE (bool(a2.get_name() == "zetta"));
		REQUIRE (bool(a2.get_symbol() == "Z"));
		prefix a3 = prefix(prefix::E);
		REQUIRE (bool(a3.get_conversion_factor() == 18));
		REQUIRE (bool(a3.get_name() == "exa"));
		REQUIRE (bool(a3.get_symbol() == "E"));
		prefix a4 = prefix(prefix::P);
		REQUIRE (bool(a4.get_conversion_factor() == 15));
		REQUIRE (bool(a4.get_name() == "peta"));
		REQUIRE (bool(a4.get_symbol() == "P"));
		prefix a5 = prefix(prefix::T);
		REQUIRE (bool(a5.get_conversion_factor() == 12));
		REQUIRE (bool(a5.get_name() == "tera"));
		REQUIRE (bool(a5.get_symbol() == "T"));
		prefix a6 = prefix(prefix::G);
		REQUIRE (bool(a6.get_conversion_factor() == 9));
		REQUIRE (bool(a6.get_name() == "giga"));
		REQUIRE (bool(a6.get_symbol() == "G"));
		prefix a7 = prefix(prefix::M);
		REQUIRE (bool(a7.get_conversion_factor() == 6));
		REQUIRE (bool(a7.get_name() == "mega"));
		REQUIRE (bool(a7.get_symbol() == "M"));
		prefix a8 = prefix(prefix::k);
		REQUIRE (bool(a8.get_conversion_factor() == 3));
		REQUIRE (bool(a8.get_name() == "kilo"));
		REQUIRE (bool(a8.get_symbol() == "k"));
		prefix a9 = prefix(prefix::h);
		REQUIRE (bool(a9.get_conversion_factor() == 2));
		REQUIRE (bool(a9.get_name() == "hecto"));
		REQUIRE (bool(a9.get_symbol() == "h"));
		prefix a10 = prefix(prefix::da);
		REQUIRE (bool(a10.get_conversion_factor() == 1));
		REQUIRE (bool(a10.get_name() == "deca"));
		REQUIRE (bool(a10.get_symbol() == "da"));
		prefix a11 = prefix(prefix::d);
		REQUIRE (bool(a11.get_conversion_factor() == -1));
		REQUIRE (bool(a11.get_name() == "deci"));
		REQUIRE (bool(a11.get_symbol() == "d"));
		prefix a12 = prefix(prefix::c);
		REQUIRE (bool(a12.get_conversion_factor() == -2));
		REQUIRE (bool(a12.get_name() == "centi"));
		REQUIRE (bool(a12.get_symbol() == "c"));
		prefix a13 = prefix(prefix::m);
		REQUIRE (bool(a13.get_conversion_factor() == -3));
		REQUIRE (bool(a13.get_name() == "milli"));
		REQUIRE (bool(a13.get_symbol() == "m"));
		prefix a14 = prefix(prefix::u);
		REQUIRE (bool(a14.get_conversion_factor() == -6));
		REQUIRE (bool(a14.get_name() == "micro"));
		REQUIRE (bool(a14.get_symbol() == "\u00B5"));
		prefix a15 = prefix(prefix::n);
		REQUIRE (bool(a15.get_conversion_factor() == -9));
		REQUIRE (bool(a15.get_name() == "nano"));
		REQUIRE (bool(a15.get_symbol() == "n"));
		prefix a16 = prefix(prefix::p);
		REQUIRE (bool(a16.get_conversion_factor() == -12));
		REQUIRE (bool(a16.get_name() == "pico"));
		REQUIRE (bool(a16.get_symbol() == "p"));
		prefix a17 = prefix(prefix::f);
		REQUIRE (bool(a17.get_conversion_factor() == -15));
		REQUIRE (bool(a17.get_name() == "femto"));
		REQUIRE (bool(a17.get_symbol() == "f"));
		prefix a18 = prefix(prefix::a);
		REQUIRE (bool(a18.get_conversion_factor() == -18));
		REQUIRE (bool(a18.get_name() == "atto"));
		REQUIRE (bool(a18.get_symbol() == "a"));
		prefix a19 = prefix(prefix::z);
		REQUIRE (bool(a19.get_conversion_factor() == -21));
		REQUIRE (bool(a19.get_name() == "zepto"));
		REQUIRE (bool(a19.get_symbol() == "z"));
		prefix a20 = prefix(prefix::y);
		REQUIRE (bool(a20.get_conversion_factor() == -24));
		REQUIRE (bool(a20.get_name() == "yocto"));
		REQUIRE (bool(a20.get_symbol() == "y"));
	}

	SECTION("Test of closest_prefix") {
		prefix a = prefix("k");
		prefix b = closest_prefix(a,2);
		REQUIRE (bool(b.prefix_type == prefix::k));
		prefix c = closest_prefix(a,3);
		REQUIRE (bool(c.prefix_type == prefix::M));
		prefix d = closest_prefix(a,-1);
		REQUIRE (bool(d.prefix_type == prefix::h));
		prefix e = closest_prefix(a,-2);
		REQUIRE (bool(e.prefix_type == prefix::da));
		prefix f = closest_prefix(a,-3);
		REQUIRE (bool(f.prefix_type == prefix::no_prefix));
		prefix g = closest_prefix(a,-6);
		REQUIRE (bool(g.prefix_type == prefix::m));
	}

	SECTION("Test of create_prefix_by_factor") {
		REQUIRE (bool(create_prefix_by_factor(0).prefix_type == prefix::no_prefix));
		REQUIRE (bool(create_prefix_by_factor(1).prefix_type == prefix::da));
		REQUIRE (bool(create_prefix_by_factor(2).prefix_type == prefix::h));
		REQUIRE (bool(create_prefix_by_factor(-1).prefix_type == prefix::d));
		REQUIRE (bool(create_prefix_by_factor(-2).prefix_type == prefix::c));
		REQUIRE (bool(create_prefix_by_factor(3).prefix_type == prefix::k));
		REQUIRE (bool(create_prefix_by_factor(5).prefix_type == prefix::k));
		REQUIRE (bool(create_prefix_by_factor(6).prefix_type == prefix::M));
		REQUIRE (bool(create_prefix_by_factor(9).prefix_type == prefix::G));
		REQUIRE (bool(create_prefix_by_factor(12).prefix_type == prefix::T));
		REQUIRE (bool(create_prefix_by_factor(15).prefix_type == prefix::P));
		REQUIRE (bool(create_prefix_by_factor(18).prefix_type == prefix::E));
		REQUIRE (bool(create_prefix_by_factor(21).prefix_type == prefix::Z));
		REQUIRE (bool(create_prefix_by_factor(24).prefix_type == prefix::Y));
		REQUIRE (bool(create_prefix_by_factor(-3).prefix_type == prefix::m));
		REQUIRE (bool(create_prefix_by_factor(-6).prefix_type == prefix::u));
		REQUIRE (bool(create_prefix_by_factor(-9).prefix_type == prefix::n));
		REQUIRE (bool(create_prefix_by_factor(-12).prefix_type == prefix::p));
		REQUIRE (bool(create_prefix_by_factor(-15).prefix_type == prefix::f));
		REQUIRE (bool(create_prefix_by_factor(-18).prefix_type == prefix::a));
		REQUIRE (bool(create_prefix_by_factor(-21).prefix_type == prefix::z));
		REQUIRE (bool(create_prefix_by_factor(-24).prefix_type == prefix::y));
	}

	SECTION("Functionalities of prefix class") {
		prefix a = prefix("k");
		prefix b = prefix("k");
		REQUIRE (bool(a == b));
		prefix c = prefix("M");
		REQUIRE (bool(a != c));
		REQUIRE (bool(a < c));
		REQUIRE (bool(a <= c));
		REQUIRE (bool(c > a));
		REQUIRE (bool(c >= a));
		ostringstream a_out;
		a_out << a;
		REQUIRE (bool(a_out.str() == "k"));
	}
}
