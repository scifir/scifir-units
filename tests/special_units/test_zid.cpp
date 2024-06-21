#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../special_units/zid.hpp"
#include "../../special_units/aid.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("zid class","Full test of zid class") {
	SECTION("Constructors of zid class")
	{
		zid a;
		REQUIRE (bool(to_string(a.aid) == ""));
		REQUIRE (bool(a.country == ""));
		REQUIRE (bool(a.regions.size() == 0));
		REQUIRE (bool(a.zone == ""));
		zid b2(aid(astronomical_body::MARS),"no-country",{"southern-highlands"},"noachis-terra");
		zid b(b2);
		REQUIRE (bool(to_string(b.aid) == "(P)universe:milky-way:solar-system:mars"));
		REQUIRE (bool(b.country == "no-country"));
		REQUIRE (bool(b.regions == vector<string>{"southern-highlands"}));
		REQUIRE (bool(b.zone == "noachis-terra"));
		zid c2(aid(astronomical_body::EARTH),"chile",{"region-metropolitana","santiago"},"providencia");
		zid c(std::move(c2));
		REQUIRE (bool(to_string(c.aid) == "(P)universe:milky-way:solar-system:earth"));
		REQUIRE (bool(c.country == "chile"));
		REQUIRE (bool(c.regions == vector<string>{"region-metropolitana","santiago"}));
		REQUIRE (bool(c.zone == "providencia"));
		zid d(aid(astronomical_body::EARTH),"chile",{"region-metropolitana","santiago"},"providencia");
		REQUIRE (bool(to_string(d.aid) == "(P)universe:milky-way:solar-system:earth"));
		REQUIRE (bool(d.country == "chile"));
		REQUIRE (bool(d.regions == vector<string>{"region-metropolitana","santiago"}));
		REQUIRE (bool(d.zone == "providencia"));
		zid e(aid(astronomical_body::EARTH),"chile:region-metropolitana:santiago:providencia");
		REQUIRE (bool(to_string(e.aid) == "(P)universe:milky-way:solar-system:earth"));
		REQUIRE (bool(e.country == "chile"));
		REQUIRE (bool(e.regions == vector<string>{"region-metropolitana","santiago"}));
		REQUIRE (bool(e.zone == "providencia"));
		zid f("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
		REQUIRE (bool(to_string(f.aid) == "(P)universe:milky-way:solar-system:earth"));
		REQUIRE (bool(f.country == "chile"));
		REQUIRE (bool(f.regions == vector<string>{"region-metropolitana","santiago"}));
		REQUIRE (bool(f.zone == "providencia"));
		zid g("chile:region-metropolitana:santiago:providencia");
		REQUIRE (bool(to_string(g.aid) == ""));
		REQUIRE (bool(g.country == "chile"));
		REQUIRE (bool(g.regions == vector<string>{"region-metropolitana","santiago"}));
		REQUIRE (bool(g.zone == "providencia"));
		zid h("");
		REQUIRE (bool(to_string(h.aid) == ""));
		REQUIRE (bool(h.country == ""));
		REQUIRE (bool(h.regions.size() == 0));
		REQUIRE (bool(h.zone == ""));
	}

	SECTION("Assignments of zid class")
	{
		zid b;
		zid b2(aid(astronomical_body::MARS),"no-country",{"southern-highlands"},"noachis-terra");
		b = b2;
		REQUIRE (bool(to_string(b.aid) == "(P)universe:milky-way:solar-system:mars"));
		REQUIRE (bool(b.country == "no-country"));
		REQUIRE (bool(b.regions == vector<string>{"southern-highlands"}));
		REQUIRE (bool(b.zone == "noachis-terra"));
		zid c;
		zid c2(aid(astronomical_body::EARTH),"chile",{"region-metropolitana","santiago"},"providencia");
		c = std::move(c2);
		REQUIRE (bool(to_string(c.aid) == "(P)universe:milky-way:solar-system:earth"));
		REQUIRE (bool(c.country == "chile"));
		REQUIRE (bool(c.regions == vector<string>{"region-metropolitana","santiago"}));
		REQUIRE (bool(c.zone == "providencia"));
		zid d;
		d = "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia";
		REQUIRE (bool(to_string(d.aid) == "(P)universe:milky-way:solar-system:earth"));
		REQUIRE (bool(d.country == "chile"));
		REQUIRE (bool(d.regions == vector<string>{"region-metropolitana","santiago"}));
		REQUIRE (bool(d.zone == "providencia"));
		zid e;
		e = "chile:region-metropolitana:santiago:providencia";
		REQUIRE (bool(to_string(e.aid) == ""));
		REQUIRE (bool(e.country == "chile"));
		REQUIRE (bool(e.regions == vector<string>{"region-metropolitana","santiago"}));
		REQUIRE (bool(e.zone == "providencia"));
	}

	SECTION("to_string() of zid class")
	{
		zid a;
		REQUIRE (bool(to_string(a) == ""));
		zid b(aid(astronomical_body::MARS),"no-country",{"southern-highlands"},"noachis-terra");
		REQUIRE (bool(to_string(b) == "(P)universe:milky-way:solar-system:mars no-country:southern-highlands:noachis-terra"));
	}

	SECTION("Operators of zid class")
	{
		zid a("(P)universe:milky-way:solar-system:mars no-country:southern-highlands:noachis-terra");
		zid b("(P)universe:milky-way:solar-system:mars no-country:southern-highlands:noachis-terra");
		zid c("(P)universe:milky-way:solar-system:mars no-country:southern-highlands:hesperia-planum");
		zid d("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
		zid e("(P)universe:milky-way:solar-system:mars no-country:northern-lowlands:utopia-basin");
		zid f("(P)universe:milky-way:solar-system:earth argentina:provincia-de-buenos-aires:buenos-aires:san-telmo");
		REQUIRE (bool(a == b));
		REQUIRE (bool((a == c) == false));
		REQUIRE (bool((a == d) == false));
		REQUIRE (bool((a == e) == false));
		REQUIRE (bool((d == f) == false));
		REQUIRE (bool(a != c));
	}

	SECTION("String operators of zid class")
	{
		REQUIRE (bool(zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia") == "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia"));
		REQUIRE (bool(zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia") != "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:macul"));
		REQUIRE (bool("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia" == zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia")));
		REQUIRE (bool("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia" != zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:macul")));
		string a = "zid ";
		a += zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
		REQUIRE (bool(a == "zid (P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia"));
		zid b = zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
		REQUIRE (bool("b " + b == "b (P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia"));
		REQUIRE (bool(b + " b" == "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia b"));
	}

	SECTION("Streams of zid class")
	{
		ostringstream a;
        a << zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
        REQUIRE (bool(a.str() == "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia"));
        stringstream b;
        b << "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia";
        zid b2;
        b >> b2;
        REQUIRE (bool(to_string(b2) == "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia"));
	}
}