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
		CHECK (bool(a.prefix_type == 0));
		prefix b = prefix(prefix::k);
		CHECK (bool(b.prefix_type == prefix::k));
		prefix c = prefix(b);
		CHECK (bool(c.prefix_type == prefix::k));
		prefix d = prefix("d");
		CHECK (bool(d.prefix_type == prefix::d));
		c = d;
		CHECK (bool(c.prefix_type == prefix::d));
		CHECK (bool(d.get_conversion_factor() == -1));
		CHECK (bool(d.get_name() == "deci"));
		CHECK (bool(d.get_symbol() == "d"));
		CHECK (bool(d < b));
		CHECK (bool(b > d));
		prefix e = prefix("Y");
		CHECK (bool(e.prefix_type == prefix::Y));
	}

	SECTION("Creation of prefix classes") {
		prefix a = prefix("Y");
		CHECK (bool(a.prefix_type == prefix::Y));
		prefix b = prefix("Z");
		CHECK (bool(b.prefix_type == prefix::Z));
		prefix c = prefix("E");
		CHECK (bool(c.prefix_type == prefix::E));
		prefix d = prefix("P");
		CHECK (bool(d.prefix_type == prefix::P));
		prefix e = prefix("T");
		CHECK (bool(e.prefix_type == prefix::T));
		prefix f = prefix("G");
		CHECK (bool(f.prefix_type == prefix::G));
		prefix g = prefix("M");
		CHECK (bool(g.prefix_type == prefix::M));
		prefix h = prefix("k");
		CHECK (bool(h.prefix_type == prefix::k));
		prefix i = prefix("h");
		CHECK (bool(i.prefix_type == prefix::h));
		prefix j = prefix("da");
		CHECK (bool(j.prefix_type == prefix::da));
		prefix k = prefix("");
		CHECK (bool(k.prefix_type == prefix::no_prefix));
		prefix l = prefix("c");
		CHECK (bool(l.prefix_type == prefix::c));
		prefix m = prefix("m");
		CHECK (bool(m.prefix_type == prefix::m));
		prefix n = prefix("u");
		CHECK (bool(n.prefix_type == prefix::u));
		//prefix j = prefix("\u00B5");
		//CHECK (bool(j.prefix_type == prefix::u));
		prefix o = prefix("n");
		CHECK (bool(o.prefix_type == prefix::n));
		prefix p = prefix("p");
		CHECK (bool(p.prefix_type == prefix::p));
		prefix q = prefix("f");
		CHECK (bool(q.prefix_type == prefix::f));
		prefix r = prefix("a");
		CHECK (bool(r.prefix_type == prefix::a));
		prefix s = prefix("z");
		CHECK (bool(s.prefix_type == prefix::z));
		prefix t = prefix("y");
		CHECK (bool(t.prefix_type == prefix::y));
	}

	SECTION("get_conversion_factor(), get_name() and get_symbol()")
	{
		prefix a0 = prefix(prefix::no_prefix);
		CHECK (bool(a0.get_conversion_factor() == 0));
		CHECK (bool(a0.get_name() == ""));
		CHECK (bool(a0.get_symbol() == ""));
		prefix a = prefix(prefix::Y);
		CHECK (bool(a.get_conversion_factor() == 24));
		CHECK (bool(a.get_name() == "yotta"));
		CHECK (bool(a.get_symbol() == "Y"));
		prefix a2 = prefix(prefix::Z);
		CHECK (bool(a2.get_conversion_factor() == 21));
		CHECK (bool(a2.get_name() == "zetta"));
		CHECK (bool(a2.get_symbol() == "Z"));
		prefix a3 = prefix(prefix::E);
		CHECK (bool(a3.get_conversion_factor() == 18));
		CHECK (bool(a3.get_name() == "exa"));
		CHECK (bool(a3.get_symbol() == "E"));
		prefix a4 = prefix(prefix::P);
		CHECK (bool(a4.get_conversion_factor() == 15));
		CHECK (bool(a4.get_name() == "peta"));
		CHECK (bool(a4.get_symbol() == "P"));
		prefix a5 = prefix(prefix::T);
		CHECK (bool(a5.get_conversion_factor() == 12));
		CHECK (bool(a5.get_name() == "tera"));
		CHECK (bool(a5.get_symbol() == "T"));
		prefix a6 = prefix(prefix::G);
		CHECK (bool(a6.get_conversion_factor() == 9));
		CHECK (bool(a6.get_name() == "giga"));
		CHECK (bool(a6.get_symbol() == "G"));
		prefix a7 = prefix(prefix::M);
		CHECK (bool(a7.get_conversion_factor() == 6));
		CHECK (bool(a7.get_name() == "mega"));
		CHECK (bool(a7.get_symbol() == "M"));
		prefix a8 = prefix(prefix::k);
		CHECK (bool(a8.get_conversion_factor() == 3));
		CHECK (bool(a8.get_name() == "kilo"));
		CHECK (bool(a8.get_symbol() == "k"));
		prefix a9 = prefix(prefix::h);
		CHECK (bool(a9.get_conversion_factor() == 2));
		CHECK (bool(a9.get_name() == "hecto"));
		CHECK (bool(a9.get_symbol() == "h"));
		prefix a10 = prefix(prefix::da);
		CHECK (bool(a10.get_conversion_factor() == 1));
		CHECK (bool(a10.get_name() == "deca"));
		CHECK (bool(a10.get_symbol() == "da"));
		prefix a11 = prefix(prefix::d);
		CHECK (bool(a11.get_conversion_factor() == -1));
		CHECK (bool(a11.get_name() == "deci"));
		CHECK (bool(a11.get_symbol() == "d"));
		prefix a12 = prefix(prefix::c);
		CHECK (bool(a12.get_conversion_factor() == -2));
		CHECK (bool(a12.get_name() == "centi"));
		CHECK (bool(a12.get_symbol() == "c"));
		prefix a13 = prefix(prefix::m);
		CHECK (bool(a13.get_conversion_factor() == -3));
		CHECK (bool(a13.get_name() == "milli"));
		CHECK (bool(a13.get_symbol() == "m"));
		prefix a14 = prefix(prefix::u);
		CHECK (bool(a14.get_conversion_factor() == -6));
		CHECK (bool(a14.get_name() == "micro"));
		CHECK (bool(a14.get_symbol() == "\u00B5"));
		prefix a15 = prefix(prefix::n);
		CHECK (bool(a15.get_conversion_factor() == -9));
		CHECK (bool(a15.get_name() == "nano"));
		CHECK (bool(a15.get_symbol() == "n"));
		prefix a16 = prefix(prefix::p);
		CHECK (bool(a16.get_conversion_factor() == -12));
		CHECK (bool(a16.get_name() == "pico"));
		CHECK (bool(a16.get_symbol() == "p"));
		prefix a17 = prefix(prefix::f);
		CHECK (bool(a17.get_conversion_factor() == -15));
		CHECK (bool(a17.get_name() == "femto"));
		CHECK (bool(a17.get_symbol() == "f"));
		prefix a18 = prefix(prefix::a);
		CHECK (bool(a18.get_conversion_factor() == -18));
		CHECK (bool(a18.get_name() == "atto"));
		CHECK (bool(a18.get_symbol() == "a"));
		prefix a19 = prefix(prefix::z);
		CHECK (bool(a19.get_conversion_factor() == -21));
		CHECK (bool(a19.get_name() == "zepto"));
		CHECK (bool(a19.get_symbol() == "z"));
		prefix a20 = prefix(prefix::y);
		CHECK (bool(a20.get_conversion_factor() == -24));
		CHECK (bool(a20.get_name() == "yocto"));
		CHECK (bool(a20.get_symbol() == "y"));
	}

	SECTION("Test of closest_prefix") {
		prefix a = prefix("k");
		prefix b = closest_prefix(a,2);
		CHECK (bool(b.prefix_type == prefix::k));
		prefix c = closest_prefix(a,3);
		CHECK (bool(c.prefix_type == prefix::M));
		prefix d = closest_prefix(a,-1);
		CHECK (bool(d.prefix_type == prefix::h));
		prefix e = closest_prefix(a,-2);
		CHECK (bool(e.prefix_type == prefix::da));
		prefix f = closest_prefix(a,-3);
		CHECK (bool(f.prefix_type == prefix::no_prefix));
		prefix g = closest_prefix(a,-6);
		CHECK (bool(g.prefix_type == prefix::m));
	}

	SECTION("Test of create_prefix_by_factor") {
		CHECK (bool(create_prefix_by_factor(0).prefix_type == prefix::no_prefix));
		CHECK (bool(create_prefix_by_factor(1).prefix_type == prefix::da));
		CHECK (bool(create_prefix_by_factor(2).prefix_type == prefix::h));
		CHECK (bool(create_prefix_by_factor(-1).prefix_type == prefix::d));
		CHECK (bool(create_prefix_by_factor(-2).prefix_type == prefix::c));
		CHECK (bool(create_prefix_by_factor(3).prefix_type == prefix::k));
		CHECK (bool(create_prefix_by_factor(5).prefix_type == prefix::k));
		CHECK (bool(create_prefix_by_factor(6).prefix_type == prefix::M));
		CHECK (bool(create_prefix_by_factor(9).prefix_type == prefix::G));
		CHECK (bool(create_prefix_by_factor(12).prefix_type == prefix::T));
		CHECK (bool(create_prefix_by_factor(15).prefix_type == prefix::P));
		CHECK (bool(create_prefix_by_factor(18).prefix_type == prefix::E));
		CHECK (bool(create_prefix_by_factor(21).prefix_type == prefix::Z));
		CHECK (bool(create_prefix_by_factor(24).prefix_type == prefix::Y));
		CHECK (bool(create_prefix_by_factor(-3).prefix_type == prefix::m));
		CHECK (bool(create_prefix_by_factor(-6).prefix_type == prefix::u));
		CHECK (bool(create_prefix_by_factor(-9).prefix_type == prefix::n));
		CHECK (bool(create_prefix_by_factor(-12).prefix_type == prefix::p));
		CHECK (bool(create_prefix_by_factor(-15).prefix_type == prefix::f));
		CHECK (bool(create_prefix_by_factor(-18).prefix_type == prefix::a));
		CHECK (bool(create_prefix_by_factor(-21).prefix_type == prefix::z));
		CHECK (bool(create_prefix_by_factor(-24).prefix_type == prefix::y));
	}

	SECTION("Functionalities of prefix class") {
		prefix a = prefix("k");
		prefix b = prefix("k");
		CHECK (bool(a == b));
		prefix c = prefix("M");
		CHECK (bool(a != c));
		CHECK (bool(a < c));
		CHECK (bool(a <= c));
		CHECK (bool(c > a));
		CHECK (bool(c >= a));
		ostringstream a_out;
		a_out << a;
		CHECK (bool(a_out.str() == "k"));
	}
}
