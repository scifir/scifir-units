//#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../units/prefix.hpp"

#include "unicode/unistr.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("prefix class") {
	SECTION("Functionalities of prefix class") {
		prefix a = prefix();
		CHECK(a.prefix_type == 0);
		prefix b = prefix(prefix::k);
		CHECK(b.prefix_type == prefix::k);
		prefix c = prefix(b);
		CHECK(c.prefix_type == prefix::k);
		prefix d = prefix("d");
		CHECK(d.prefix_type == prefix::d);
		c = d;
		CHECK(c.prefix_type == prefix::d);
		CHECK(d.get_conversion_factor() == -1);
		CHECK(d.get_name() == "deci");
		CHECK(d.get_symbol() == "d");
		CHECK(bool(d < b));
		CHECK(bool(b > d));
		prefix e = prefix("Y");
		CHECK(e.prefix_type == prefix::Y);
	}

	SECTION("Creation of prefix class") {
		prefix a = prefix("Y");
		CHECK(a.prefix_type == prefix::Y);
		prefix b = prefix("Z");
		CHECK(b.prefix_type == prefix::Z);
		prefix c = prefix("E");
		CHECK(c.prefix_type == prefix::E);
		prefix d = prefix("P");
		CHECK(d.prefix_type == prefix::P);
		prefix e = prefix("T");
		CHECK(e.prefix_type == prefix::T);
		prefix f = prefix("G");
		CHECK(f.prefix_type == prefix::G);
		prefix g = prefix("M");
		CHECK(g.prefix_type == prefix::M);
		prefix h = prefix("k");
		CHECK(h.prefix_type == prefix::k);
		prefix i = prefix("h");
		CHECK(i.prefix_type == prefix::h);
		prefix j = prefix("da");
		CHECK(j.prefix_type == prefix::da);
		prefix k = prefix("");
		CHECK(k.prefix_type == prefix::no_prefix);
		prefix l = prefix("c");
		CHECK(l.prefix_type == prefix::c);
		prefix m = prefix("m");
		CHECK(m.prefix_type == prefix::m);
		prefix n = prefix("u");
		CHECK(n.prefix_type == prefix::u);
		//prefix j = prefix("\u00B5");
		//CHECK(j.prefix_type == prefix::u);
		prefix o = prefix("n");
		CHECK(o.prefix_type == prefix::n);
		prefix p = prefix("p");
		CHECK(p.prefix_type == prefix::p);
		prefix q = prefix("f");
		CHECK(q.prefix_type == prefix::f);
		prefix r = prefix("a");
		CHECK(r.prefix_type == prefix::a);
		prefix s = prefix("z");
		CHECK(s.prefix_type == prefix::z);
		prefix t = prefix("y");
		CHECK(t.prefix_type == prefix::y);
	}

	SECTION("get_conversion_factor(), get_name() and get_symbol()")
	{
		prefix a0 = prefix(prefix::no_prefix);
		CHECK(a0.get_conversion_factor() == 0);
		CHECK(a0.get_name() == "");
		CHECK(a0.get_symbol() == "");
		prefix a = prefix(prefix::Y);
		CHECK(a.get_conversion_factor() == 24);
		CHECK(a.get_name() == "yotta");
		CHECK(a.get_symbol() == "Y");
		prefix a2 = prefix(prefix::Z);
		CHECK(a2.get_conversion_factor() == 21);
		CHECK(a2.get_name() == "zetta");
		CHECK(a2.get_symbol() == "Z");
		prefix a3 = prefix(prefix::E);
		CHECK(a3.get_conversion_factor() == 18);
		CHECK(a3.get_name() == "exa");
		CHECK(a3.get_symbol() == "E");
		prefix a4 = prefix(prefix::P);
		CHECK(a4.get_conversion_factor() == 15);
		CHECK(a4.get_name() == "peta");
		CHECK(a4.get_symbol() == "P");
		prefix a5 = prefix(prefix::T);
		CHECK(a5.get_conversion_factor() == 12);
		CHECK(a5.get_name() == "tera");
		CHECK(a5.get_symbol() == "T");
		prefix a6 = prefix(prefix::G);
		CHECK(a6.get_conversion_factor() == 9);
		CHECK(a6.get_name() == "giga");
		CHECK(a6.get_symbol() == "G");
		prefix a7 = prefix(prefix::M);
		CHECK(a7.get_conversion_factor() == 6);
		CHECK(a7.get_name() == "mega");
		CHECK(a7.get_symbol() == "M");
		prefix a8 = prefix(prefix::k);
		CHECK(a8.get_conversion_factor() == 3);
		CHECK(a8.get_name() == "kilo");
		CHECK(a8.get_symbol() == "k");
		prefix a9 = prefix(prefix::h);
		CHECK(a9.get_conversion_factor() == 2);
		CHECK(a9.get_name() == "hecto");
		CHECK(a9.get_symbol() == "h");
		prefix a10 = prefix(prefix::da);
		CHECK(a10.get_conversion_factor() == 1);
		CHECK(a10.get_name() == "deca");
		CHECK(a10.get_symbol() == "da");
		prefix a11 = prefix(prefix::d);
		CHECK(a11.get_conversion_factor() == -1);
		CHECK(a11.get_name() == "deci");
		CHECK(a11.get_symbol() == "d");
		prefix a12 = prefix(prefix::c);
		CHECK(a12.get_conversion_factor() == -2);
		CHECK(a12.get_name() == "centi");
		CHECK(a12.get_symbol() == "c");
		prefix a13 = prefix(prefix::m);
		CHECK(a13.get_conversion_factor() == -3);
		CHECK(a13.get_name() == "milli");
		CHECK(a13.get_symbol() == "m");
		prefix a14 = prefix(prefix::u);
		CHECK(a14.get_conversion_factor() == -6);
		CHECK(a14.get_name() == "micro");
		CHECK(a14.get_symbol() == "\u00B5");
		prefix a15 = prefix(prefix::n);
		CHECK(a15.get_conversion_factor() == -9);
		CHECK(a15.get_name() == "nano");
		CHECK(a15.get_symbol() == "n");
		prefix a16 = prefix(prefix::p);
		CHECK(a16.get_conversion_factor() == -12);
		CHECK(a16.get_name() == "pico");
		CHECK(a16.get_symbol() == "p");
		prefix a17 = prefix(prefix::f);
		CHECK(a17.get_conversion_factor() == -15);
		CHECK(a17.get_name() == "femto");
		CHECK(a17.get_symbol() == "f");
		prefix a18 = prefix(prefix::a);
		CHECK(a18.get_conversion_factor() == -18);
		CHECK(a18.get_name() == "atto");
		CHECK(a18.get_symbol() == "a");
		prefix a19 = prefix(prefix::z);
		CHECK(a19.get_conversion_factor() == -21);
		CHECK(a19.get_name() == "zepto");
		CHECK(a19.get_symbol() == "z");
		prefix a20 = prefix(prefix::y);
		CHECK(a20.get_conversion_factor() == -24);
		CHECK(a20.get_name() == "yocto");
		CHECK(a20.get_symbol() == "y");
	}

	SECTION("Test of closest_prefix") {
		prefix a = prefix("k");
		prefix b = closest_prefix(a,2);
		CHECK(b.prefix_type == prefix::k);
		prefix c = closest_prefix(a,3);
		CHECK(c.prefix_type == prefix::M);
		prefix d = closest_prefix(a,-1);
		CHECK(d.prefix_type == prefix::h);
		prefix e = closest_prefix(a,-2);
		CHECK(e.prefix_type == prefix::da);
		prefix f = closest_prefix(a,-3);
		CHECK(f.prefix_type == prefix::no_prefix);
		prefix g = closest_prefix(a,-6);
		CHECK(g.prefix_type == prefix::m);
	}

	SECTION("Test of create_prefix_by_factor") {
		CHECK(create_prefix_by_factor(0).prefix_type == prefix::no_prefix);
		CHECK(create_prefix_by_factor(1).prefix_type == prefix::da);
		CHECK(create_prefix_by_factor(2).prefix_type == prefix::h);
		CHECK(create_prefix_by_factor(-1).prefix_type == prefix::d);
		CHECK(create_prefix_by_factor(-2).prefix_type == prefix::c);
		CHECK(create_prefix_by_factor(3).prefix_type == prefix::k);
		CHECK(create_prefix_by_factor(5).prefix_type == prefix::k);
		CHECK(create_prefix_by_factor(6).prefix_type == prefix::M);
		CHECK(create_prefix_by_factor(9).prefix_type == prefix::G);
		CHECK(create_prefix_by_factor(12).prefix_type == prefix::T);
		CHECK(create_prefix_by_factor(15).prefix_type == prefix::P);
		CHECK(create_prefix_by_factor(18).prefix_type == prefix::E);
		CHECK(create_prefix_by_factor(21).prefix_type == prefix::Z);
		CHECK(create_prefix_by_factor(24).prefix_type == prefix::Y);
		CHECK(create_prefix_by_factor(-3).prefix_type == prefix::m);
		CHECK(create_prefix_by_factor(-6).prefix_type == prefix::u);
		CHECK(create_prefix_by_factor(-9).prefix_type == prefix::n);
		CHECK(create_prefix_by_factor(-12).prefix_type == prefix::p);
		CHECK(create_prefix_by_factor(-15).prefix_type == prefix::f);
		CHECK(create_prefix_by_factor(-18).prefix_type == prefix::a);
		CHECK(create_prefix_by_factor(-21).prefix_type == prefix::z);
		CHECK(create_prefix_by_factor(-24).prefix_type == prefix::y);
	}

	SECTION("Functionalities of prefix class") {
		prefix a = prefix("k");
		prefix b = prefix("k");
		CHECK(bool(a == b));
		prefix c = prefix("M");
		CHECK(bool(a != c));
		CHECK(bool(a < c));
		CHECK(bool(a <= c));
		CHECK(bool(c > a));
		CHECK(bool(c >= a));
		ostringstream a_out;
		a_out << a;
		CHECK(a_out.str() == "k");
	}
}
