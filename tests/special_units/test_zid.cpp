#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../special_units/zid.hpp"
#include "../../special_units/aid.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("zid class") {
	SECTION("Constructors of zid class")
	{
		zid a;
		CHECK (bool(to_string(a.aid) == ""));
		CHECK (bool(a.country == ""));
		CHECK (bool(a.regions.size() == 0));
		CHECK (bool(a.zone == ""));
		zid b2(aid(astronomical_body::MARS),"no-country",{"southern-highlands"},"noachis-terra");
		zid b(b2);
		CHECK (bool(to_string(b.aid) == "(P)universe:milky-way:solar-system:mars"));
		CHECK (bool(b.country == "no-country"));
		CHECK (bool(b.regions == vector<string>{"southern-highlands"}));
		CHECK (bool(b.zone == "noachis-terra"));
		zid c2(aid(astronomical_body::EARTH),"chile",{"region-metropolitana","santiago"},"providencia");
		zid c(std::move(c2));
		CHECK (bool(to_string(c.aid) == "(P)universe:milky-way:solar-system:earth"));
		CHECK (bool(c.country == "chile"));
		CHECK (bool(c.regions == vector<string>{"region-metropolitana","santiago"}));
		CHECK (bool(c.zone == "providencia"));
		zid d(aid(astronomical_body::EARTH),"chile",{"region-metropolitana","santiago"},"providencia");
		CHECK (bool(to_string(d.aid) == "(P)universe:milky-way:solar-system:earth"));
		CHECK (bool(d.country == "chile"));
		CHECK (bool(d.regions == vector<string>{"region-metropolitana","santiago"}));
		CHECK (bool(d.zone == "providencia"));
		zid e(aid(astronomical_body::EARTH),"chile:region-metropolitana:santiago:providencia");
		CHECK (bool(to_string(e.aid) == "(P)universe:milky-way:solar-system:earth"));
		CHECK (bool(e.country == "chile"));
		CHECK (bool(e.regions == vector<string>{"region-metropolitana","santiago"}));
		CHECK (bool(e.zone == "providencia"));
		zid f("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
		CHECK (bool(to_string(f.aid) == "(P)universe:milky-way:solar-system:earth"));
		CHECK (bool(f.country == "chile"));
		CHECK (bool(f.regions == vector<string>{"region-metropolitana","santiago"}));
		CHECK (bool(f.zone == "providencia"));
		zid g("chile:region-metropolitana:santiago:providencia");
		CHECK (bool(to_string(g.aid) == ""));
		CHECK (bool(g.country == "chile"));
		CHECK (bool(g.regions == vector<string>{"region-metropolitana","santiago"}));
		CHECK (bool(g.zone == "providencia"));
		zid h("");
		CHECK (bool(to_string(h.aid) == ""));
		CHECK (bool(h.country == ""));
		CHECK (bool(h.regions.size() == 0));
		CHECK (bool(h.zone == ""));
	}

	SECTION("Assignments of zid class")
	{
		zid b;
		zid b2(aid(astronomical_body::MARS),"no-country",{"southern-highlands"},"noachis-terra");
		b = b2;
		CHECK (bool(to_string(b.aid) == "(P)universe:milky-way:solar-system:mars"));
		CHECK (bool(b.country == "no-country"));
		CHECK (bool(b.regions == vector<string>{"southern-highlands"}));
		CHECK (bool(b.zone == "noachis-terra"));
		zid c;
		zid c2(aid(astronomical_body::EARTH),"chile",{"region-metropolitana","santiago"},"providencia");
		c = std::move(c2);
		CHECK (bool(to_string(c.aid) == "(P)universe:milky-way:solar-system:earth"));
		CHECK (bool(c.country == "chile"));
		CHECK (bool(c.regions == vector<string>{"region-metropolitana","santiago"}));
		CHECK (bool(c.zone == "providencia"));
		zid d;
		d = "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia";
		CHECK (bool(to_string(d.aid) == "(P)universe:milky-way:solar-system:earth"));
		CHECK (bool(d.country == "chile"));
		CHECK (bool(d.regions == vector<string>{"region-metropolitana","santiago"}));
		CHECK (bool(d.zone == "providencia"));
		zid e;
		e = "chile:region-metropolitana:santiago:providencia";
		CHECK (bool(to_string(e.aid) == ""));
		CHECK (bool(e.country == "chile"));
		CHECK (bool(e.regions == vector<string>{"region-metropolitana","santiago"}));
		CHECK (bool(e.zone == "providencia"));
	}

	SECTION("to_string() of zid class")
	{
		zid a;
		CHECK (bool(to_string(a) == ""));
		zid b(aid(astronomical_body::MARS),"no-country",{"southern-highlands"},"noachis-terra");
		CHECK (bool(to_string(b) == "(P)universe:milky-way:solar-system:mars no-country:southern-highlands:noachis-terra"));
	}

	SECTION("Operators of zid class")
	{
		zid a("(P)universe:milky-way:solar-system:mars no-country:southern-highlands:noachis-terra");
		zid b("(P)universe:milky-way:solar-system:mars no-country:southern-highlands:noachis-terra");
		zid c("(P)universe:milky-way:solar-system:mars no-country:southern-highlands:hesperia-planum");
		zid d("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
		zid e("(P)universe:milky-way:solar-system:mars no-country:northern-lowlands:utopia-basin");
		zid f("(P)universe:milky-way:solar-system:earth argentina:provincia-de-buenos-aires:buenos-aires:san-telmo");
		CHECK (bool(a == b));
		CHECK (bool((a == c) == false));
		CHECK (bool((a == d) == false));
		CHECK (bool((a == e) == false));
		CHECK (bool((d == f) == false));
		CHECK (bool(a != c));
	}

	SECTION("String operators of zid class")
	{
		CHECK (bool(zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia") == "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia"));
		CHECK (bool(zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia") != "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:macul"));
		CHECK (bool("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia" == zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia")));
		CHECK (bool("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia" != zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:macul")));
		string a = "zid ";
		a += zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
		CHECK (bool(a == "zid (P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia"));
		zid b = zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
		CHECK (bool("b " + b == "b (P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia"));
		CHECK (bool(b + " b" == "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia b"));
	}

	SECTION("Streams of zid class")
	{
		ostringstream a;
        a << zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
        CHECK (bool(a.str() == "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia"));
        stringstream b;
        b << "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia";
        zid b2;
        b >> b2;
        CHECK (bool(to_string(b2) == "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia"));
	}
}