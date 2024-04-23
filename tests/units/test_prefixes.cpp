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
		prefix a = create_prefix_by_factor(3);
		REQUIRE (bool(a.prefix_type == prefix::k));
		prefix b = create_prefix_by_factor(5);
		REQUIRE (bool(b.prefix_type == prefix::k));
		prefix c = create_prefix_by_factor(6);
		REQUIRE (bool(c.prefix_type == prefix::M));
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
