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
		prefix b = prefix(prefix::KILO);
		CHECK(b.prefix_type == prefix::KILO);
		prefix c = prefix(b);
		CHECK(c.prefix_type == prefix::KILO);
		prefix d = prefix("d");
		CHECK(d.prefix_type == prefix::DECI);
		c = d;
		CHECK(c.prefix_type == prefix::DECI);
		CHECK(d.get_conversion_factor() == -1);
		CHECK(d.get_name() == "deci");
		CHECK(d.get_symbol() == "d");
		CHECK(bool(d < b));
		CHECK(bool(b > d));
		prefix e = prefix("Y");
		CHECK(e.prefix_type == prefix::YOTTA);
	}

	SECTION("Creation of prefix class") {
		prefix a2 = prefix("Q");
		CHECK(a2.prefix_type == prefix::QUETTA);
		prefix a1 = prefix("R");
		CHECK(a1.prefix_type == prefix::RONNA);
		prefix a = prefix("Y");
		CHECK(a.prefix_type == prefix::YOTTA);
		prefix b = prefix("Z");
		CHECK(b.prefix_type == prefix::ZETTA);
		prefix c = prefix("E");
		CHECK(c.prefix_type == prefix::EXA);
		prefix d = prefix("P");
		CHECK(d.prefix_type == prefix::PETA);
		prefix e = prefix("T");
		CHECK(e.prefix_type == prefix::TERA);
		prefix f = prefix("G");
		CHECK(f.prefix_type == prefix::GIGA);
		prefix g = prefix("M");
		CHECK(g.prefix_type == prefix::MEGA);
		prefix h = prefix("k");
		CHECK(h.prefix_type == prefix::KILO);
		prefix i = prefix("h");
		CHECK(i.prefix_type == prefix::HECTO);
		prefix j = prefix("da");
		CHECK(j.prefix_type == prefix::DECA);
		prefix k = prefix("");
		CHECK(k.prefix_type == prefix::NONE);
		prefix l = prefix("c");
		CHECK(l.prefix_type == prefix::CENTI);
		prefix m = prefix("m");
		CHECK(m.prefix_type == prefix::MILLI);
		prefix n2 = prefix("µ");
		CHECK(n2.prefix_type == prefix::MICRO);
		prefix o = prefix("n");
		CHECK(o.prefix_type == prefix::NANO);
		prefix p = prefix("p");
		CHECK(p.prefix_type == prefix::PICO);
		prefix q = prefix("f");
		CHECK(q.prefix_type == prefix::FEMTO);
		prefix r = prefix("a");
		CHECK(r.prefix_type == prefix::ATTO);
		prefix s = prefix("z");
		CHECK(s.prefix_type == prefix::ZEPTO);
		prefix t = prefix("y");
		CHECK(t.prefix_type == prefix::YOCTO);
		prefix u = prefix("r");
		CHECK(u.prefix_type == prefix::RONTO);
		prefix v = prefix("q");
		CHECK(v.prefix_type == prefix::QUECTO);
	}

	SECTION("get_conversion_factor(), get_name() and get_symbol()")
	{
		prefix a0 = prefix(prefix::NONE);
		CHECK(a0.get_conversion_factor() == 0);
		CHECK(a0.get_name() == "");
		CHECK(a0.get_symbol() == "");
		prefix a02 = prefix(prefix::QUETTA);
		CHECK(a02.get_conversion_factor() == 30);
		CHECK(a02.get_name() == "quetta");
		CHECK(a02.get_symbol() == "Q");
		prefix a01 = prefix(prefix::RONNA);
		CHECK(a01.get_conversion_factor() == 27);
		CHECK(a01.get_name() == "ronna");
		CHECK(a01.get_symbol() == "R");
		prefix a = prefix(prefix::YOTTA);
		CHECK(a.get_conversion_factor() == 24);
		CHECK(a.get_name() == "yotta");
		CHECK(a.get_symbol() == "Y");
		prefix a2 = prefix(prefix::ZETTA);
		CHECK(a2.get_conversion_factor() == 21);
		CHECK(a2.get_name() == "zetta");
		CHECK(a2.get_symbol() == "Z");
		prefix a3 = prefix(prefix::EXA);
		CHECK(a3.get_conversion_factor() == 18);
		CHECK(a3.get_name() == "exa");
		CHECK(a3.get_symbol() == "E");
		prefix a4 = prefix(prefix::PETA);
		CHECK(a4.get_conversion_factor() == 15);
		CHECK(a4.get_name() == "peta");
		CHECK(a4.get_symbol() == "P");
		prefix a5 = prefix(prefix::TERA);
		CHECK(a5.get_conversion_factor() == 12);
		CHECK(a5.get_name() == "tera");
		CHECK(a5.get_symbol() == "T");
		prefix a6 = prefix(prefix::GIGA);
		CHECK(a6.get_conversion_factor() == 9);
		CHECK(a6.get_name() == "giga");
		CHECK(a6.get_symbol() == "G");
		prefix a7 = prefix(prefix::MEGA);
		CHECK(a7.get_conversion_factor() == 6);
		CHECK(a7.get_name() == "mega");
		CHECK(a7.get_symbol() == "M");
		prefix a8 = prefix(prefix::KILO);
		CHECK(a8.get_conversion_factor() == 3);
		CHECK(a8.get_name() == "kilo");
		CHECK(a8.get_symbol() == "k");
		prefix a9 = prefix(prefix::HECTO);
		CHECK(a9.get_conversion_factor() == 2);
		CHECK(a9.get_name() == "hecto");
		CHECK(a9.get_symbol() == "h");
		prefix a10 = prefix(prefix::DECA);
		CHECK(a10.get_conversion_factor() == 1);
		CHECK(a10.get_name() == "deca");
		CHECK(a10.get_symbol() == "da");
		prefix a11 = prefix(prefix::DECI);
		CHECK(a11.get_conversion_factor() == -1);
		CHECK(a11.get_name() == "deci");
		CHECK(a11.get_symbol() == "d");
		prefix a12 = prefix(prefix::CENTI);
		CHECK(a12.get_conversion_factor() == -2);
		CHECK(a12.get_name() == "centi");
		CHECK(a12.get_symbol() == "c");
		prefix a13 = prefix(prefix::MILLI);
		CHECK(a13.get_conversion_factor() == -3);
		CHECK(a13.get_name() == "milli");
		CHECK(a13.get_symbol() == "m");
		prefix a14 = prefix(prefix::MICRO);
		CHECK(a14.get_conversion_factor() == -6);
		CHECK(a14.get_name() == "micro");
		CHECK(a14.get_symbol() == "µ");
		prefix a15 = prefix(prefix::NANO);
		CHECK(a15.get_conversion_factor() == -9);
		CHECK(a15.get_name() == "nano");
		CHECK(a15.get_symbol() == "n");
		prefix a16 = prefix(prefix::PICO);
		CHECK(a16.get_conversion_factor() == -12);
		CHECK(a16.get_name() == "pico");
		CHECK(a16.get_symbol() == "p");
		prefix a17 = prefix(prefix::FEMTO);
		CHECK(a17.get_conversion_factor() == -15);
		CHECK(a17.get_name() == "femto");
		CHECK(a17.get_symbol() == "f");
		prefix a18 = prefix(prefix::ATTO);
		CHECK(a18.get_conversion_factor() == -18);
		CHECK(a18.get_name() == "atto");
		CHECK(a18.get_symbol() == "a");
		prefix a19 = prefix(prefix::ZEPTO);
		CHECK(a19.get_conversion_factor() == -21);
		CHECK(a19.get_name() == "zepto");
		CHECK(a19.get_symbol() == "z");
		prefix a20 = prefix(prefix::YOCTO);
		CHECK(a20.get_conversion_factor() == -24);
		CHECK(a20.get_name() == "yocto");
		CHECK(a20.get_symbol() == "y");
		prefix a21 = prefix(prefix::RONTO);
		CHECK(a21.get_conversion_factor() == -27);
		CHECK(a21.get_name() == "ronto");
		CHECK(a21.get_symbol() == "r");
		prefix a22 = prefix(prefix::QUECTO);
		CHECK(a22.get_conversion_factor() == -30);
		CHECK(a22.get_name() == "quecto");
		CHECK(a22.get_symbol() == "q");
	}

	SECTION("Test of closest_prefix") {
		prefix a = prefix("k");
		prefix b = closest_prefix(a,2);
		CHECK(b.prefix_type == prefix::KILO);
		prefix c = closest_prefix(a,3);
		CHECK(c.prefix_type == prefix::MEGA);
		prefix d = closest_prefix(a,-1);
		CHECK(d.prefix_type == prefix::HECTO);
		prefix e = closest_prefix(a,-2);
		CHECK(e.prefix_type == prefix::DECA);
		prefix f = closest_prefix(a,-3);
		CHECK(f.prefix_type == prefix::NONE);
		prefix g = closest_prefix(a,-6);
		CHECK(g.prefix_type == prefix::MILLI);
	}

	SECTION("Test of create_prefix_by_factor") {
		CHECK(create_prefix_by_factor(0).prefix_type == prefix::NONE);
		CHECK(create_prefix_by_factor(1).prefix_type == prefix::DECA);
		CHECK(create_prefix_by_factor(2).prefix_type == prefix::HECTO);
		CHECK(create_prefix_by_factor(-1).prefix_type == prefix::DECI);
		CHECK(create_prefix_by_factor(-2).prefix_type == prefix::CENTI);
		CHECK(create_prefix_by_factor(3).prefix_type == prefix::KILO);
		CHECK(create_prefix_by_factor(5).prefix_type == prefix::KILO);
		CHECK(create_prefix_by_factor(6).prefix_type == prefix::MEGA);
		CHECK(create_prefix_by_factor(9).prefix_type == prefix::GIGA);
		CHECK(create_prefix_by_factor(12).prefix_type == prefix::TERA);
		CHECK(create_prefix_by_factor(15).prefix_type == prefix::PETA);
		CHECK(create_prefix_by_factor(18).prefix_type == prefix::EXA);
		CHECK(create_prefix_by_factor(21).prefix_type == prefix::ZETTA);
		CHECK(create_prefix_by_factor(24).prefix_type == prefix::YOTTA);
		CHECK(create_prefix_by_factor(27).prefix_type == prefix::RONNA);
		CHECK(create_prefix_by_factor(30).prefix_type == prefix::QUETTA);
		CHECK(create_prefix_by_factor(-3).prefix_type == prefix::MILLI);
		CHECK(create_prefix_by_factor(-6).prefix_type == prefix::MICRO);
		CHECK(create_prefix_by_factor(-9).prefix_type == prefix::NANO);
		CHECK(create_prefix_by_factor(-12).prefix_type == prefix::PICO);
		CHECK(create_prefix_by_factor(-15).prefix_type == prefix::FEMTO);
		CHECK(create_prefix_by_factor(-18).prefix_type == prefix::ATTO);
		CHECK(create_prefix_by_factor(-21).prefix_type == prefix::ZEPTO);
		CHECK(create_prefix_by_factor(-24).prefix_type == prefix::YOCTO);
		CHECK(create_prefix_by_factor(-27).prefix_type == prefix::RONTO);
		CHECK(create_prefix_by_factor(-30).prefix_type == prefix::QUECTO);
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
