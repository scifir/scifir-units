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
		CHECK(to_string(a.aid) == "");
		CHECK(a.country == "");
		CHECK(a.regions.size() == 0);
		CHECK(a.zone == "");
		zid b2(aid(astronomical_body::MARS),"no-country",{"southern-highlands"},"noachis-terra");
		zid b(b2);
		CHECK(to_string(b.aid) == "(P)universe:milky-way:solar-system:mars");
		CHECK(b.country == "no-country");
		CHECK(b.regions == vector<string>{"southern-highlands"});
		CHECK(b.zone == "noachis-terra");
		zid c2(aid(astronomical_body::EARTH),"chile",{"region-metropolitana","santiago"},"providencia");
		zid c(std::move(c2));
		CHECK(to_string(c.aid) == "(P)universe:milky-way:solar-system:earth");
		CHECK(c.country == "chile");
		CHECK(c.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(c.zone == "providencia");
		zid d(aid(astronomical_body::EARTH),"chile",{"region-metropolitana","santiago"},"providencia");
		CHECK(to_string(d.aid) == "(P)universe:milky-way:solar-system:earth");
		CHECK(d.country == "chile");
		CHECK(d.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(d.zone == "providencia");
		zid e(aid(astronomical_body::EARTH),"chile:region-metropolitana:santiago:providencia");
		CHECK(to_string(e.aid) == "(P)universe:milky-way:solar-system:earth");
		CHECK(e.country == "chile");
		CHECK(e.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(e.zone == "providencia");
		zid f("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
		CHECK(to_string(f.aid) == "(P)universe:milky-way:solar-system:earth");
		CHECK(f.country == "chile");
		CHECK(f.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(f.zone == "providencia");
		zid g("chile:region-metropolitana:santiago:providencia");
		CHECK(to_string(g.aid) == "");
		CHECK(g.country == "chile");
		CHECK(g.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(g.zone == "providencia");
		zid h("");
		CHECK(to_string(h.aid) == "");
		CHECK(h.country == "");
		CHECK(h.regions.size() == 0);
		CHECK(h.zone == "");
	}

	SECTION("Assignments of zid class")
	{
		zid b;
		zid b2(aid(astronomical_body::MARS),"no-country",{"southern-highlands"},"noachis-terra");
		b = b2;
		CHECK(to_string(b.aid) == "(P)universe:milky-way:solar-system:mars");
		CHECK(b.country == "no-country");
		CHECK(b.regions == vector<string>{"southern-highlands"});
		CHECK(b.zone == "noachis-terra");
		zid c;
		zid c2(aid(astronomical_body::EARTH),"chile",{"region-metropolitana","santiago"},"providencia");
		c = std::move(c2);
		CHECK(to_string(c.aid) == "(P)universe:milky-way:solar-system:earth");
		CHECK(c.country == "chile");
		CHECK(c.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(c.zone == "providencia");
		zid d;
		d = "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia";
		CHECK(to_string(d.aid) == "(P)universe:milky-way:solar-system:earth");
		CHECK(d.country == "chile");
		CHECK(d.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(d.zone == "providencia");
		zid e;
		e = "chile:region-metropolitana:santiago:providencia";
		CHECK(to_string(e.aid) == "");
		CHECK(e.country == "chile");
		CHECK(e.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(e.zone == "providencia");
	}

	SECTION("has_no_country() ad has_unknown_country() of zid class")
	{
		zid a("unknown-country:big-mountains");
		CHECK(a.has_unknown_country());
		zid b("(P)universe:milky-way:solar-system:mars no-country:southern-highlands:noachis-terra");
		CHECK(b.has_no_country());
		zid c("(P)universe:milky-way:solar-system:earth argentina:provincia-de-buenos-aires:buenos-aires:san-telmo");
		CHECK(c.has_no_country() == false);
		CHECK(c.has_unknown_country() == false);
	}

	SECTION("display() and partial_display() of zid class")
	{
		zid a("(P)universe:milky-way:solar-system:earth argentina:provincia-de-buenos-aires:buenos-aires:san-telmo");
		CHECK(a.display() == "(P)universe:milky-way:solar-system:earth argentina:provincia-de-buenos-aires:buenos-aires:san-telmo");
		CHECK(a.partial_display() == "argentina:provincia-de-buenos-aires:buenos-aires:san-telmo");
		zid b("");
		CHECK(b.display() == "");
		CHECK(b.partial_display() == "");
	}

	SECTION("to_string() of zid class")
	{
		zid a;
		CHECK(to_string(a) == "");
		zid b(aid(astronomical_body::MARS),"no-country",{"southern-highlands"},"noachis-terra");
		CHECK(to_string(b) == "(P)universe:milky-way:solar-system:mars no-country:southern-highlands:noachis-terra");
	}

	SECTION("Operators of zid class")
	{
		zid a("(P)universe:milky-way:solar-system:mars no-country:southern-highlands:noachis-terra");
		zid b("(P)universe:milky-way:solar-system:mars no-country:southern-highlands:noachis-terra");
		zid c("(P)universe:milky-way:solar-system:mars no-country:southern-highlands:hesperia-planum");
		zid d("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
		zid e("(P)universe:milky-way:solar-system:mars no-country:northern-lowlands:utopia-basin");
		zid f("(P)universe:milky-way:solar-system:earth argentina:provincia-de-buenos-aires:buenos-aires:san-telmo");
		CHECK(bool(a == b));
		CHECK((a == c) == false);
		CHECK((a == d) == false);
		CHECK((a == e) == false);
		CHECK((d == f) == false);
		CHECK(bool(a != c));
	}

	SECTION("String operators of zid class")
	{
		CHECK(bool(zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia") == "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia"));
		CHECK(bool(zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia") != "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:macul"));
		CHECK(bool("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia" == zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia")));
		CHECK(bool("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia" != zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:macul")));
		string a = "zid ";
		a += zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
		CHECK(a == "zid (P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
		zid b = zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
		CHECK("b " + b == "b (P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
		CHECK(b + " b" == "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia b");
	}

	SECTION("Streams of zid class")
	{
		ostringstream a;
        a << zid("(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
        CHECK(a.str() == "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
        stringstream b;
        b << "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia";
        zid b2;
        b >> b2;
        CHECK(to_string(b2) == "(P)universe:milky-way:solar-system:earth chile:region-metropolitana:santiago:providencia");
	}
}