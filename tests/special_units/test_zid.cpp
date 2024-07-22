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
		CHECK(a.zone_type == zid::NONE);
		zid b2(aid(astronomical_body::MARS),zid::ZONE,"no-country",{"southern-highlands"},"noachis-terra");
		zid b(b2);
		CHECK(to_string(b.aid) == "(P)universe:milky-way:solar-system:mars");
		CHECK(b.country == "no-country");
		CHECK(b.regions == vector<string>{"southern-highlands"});
		CHECK(b.zone == "noachis-terra");
		CHECK(b.zone_type == zid::ZONE);
		zid c2(aid(astronomical_body::EARTH),zid::ZONE,"chile",{"region-metropolitana","santiago"},"providencia");
		zid c(std::move(c2));
		CHECK(to_string(c.aid) == "(P)universe:milky-way:solar-system:earth");
		CHECK(c.country == "chile");
		CHECK(c.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(c.zone == "providencia");
		CHECK(c.zone_type == zid::ZONE);
		zid d2(aid(astronomical_body::EARTH),zid::COUNTRY,"chile");
		CHECK(to_string(d2.aid) == "(P)universe:milky-way:solar-system:earth");
		CHECK(d2.country == "chile");
		CHECK(d2.regions.size() == 0);
		CHECK(d2.zone == "");
		CHECK(d2.zone_type == zid::COUNTRY);
		zid d3(aid(astronomical_body::EARTH),"chile",{"region-metropolitana","chacabuco"});
		CHECK(to_string(d3.aid) == "(P)universe:milky-way:solar-system:earth");
		CHECK(d3.country == "chile");
		CHECK(d3.regions == vector<string>{"region-metropolitana","chacabuco"});
		CHECK(d3.zone == "");
		CHECK(d3.zone_type == zid::REGION);
		zid d(aid(astronomical_body::EARTH),zid::ZONE,"chile",{"region-metropolitana","santiago"},"providencia");
		CHECK(to_string(d.aid) == "(P)universe:milky-way:solar-system:earth");
		CHECK(d.country == "chile");
		CHECK(d.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(d.zone == "providencia");
		CHECK(d.zone_type == zid::ZONE);
		zid d4(aid(astronomical_body::EARTH),zid::SETTLEMENT,"chile",{"region-metropolitana"},"santiago");
		CHECK(to_string(d4.aid) == "(P)universe:milky-way:solar-system:earth");
		CHECK(d4.country == "chile");
		CHECK(d4.regions == vector<string>{"region-metropolitana"});
		CHECK(d4.zone == "santiago");
		CHECK(d4.zone_type == zid::SETTLEMENT);
		zid e(aid(astronomical_body::EARTH),"(Z) chile:region-metropolitana:santiago:providencia");
		CHECK(to_string(e.aid) == "(P)universe:milky-way:solar-system:earth");
		CHECK(e.country == "chile");
		CHECK(e.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(e.zone == "providencia");
		CHECK(e.zone_type == zid::ZONE);
		zid e2(aid(astronomical_body::EARTH),"(Z)chile:region-metropolitana:santiago:providencia");
		CHECK(to_string(e2.aid) == "(P)universe:milky-way:solar-system:earth");
		CHECK(e2.country == "chile");
		CHECK(e2.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(e2.zone == "providencia");
		CHECK(e2.zone_type == zid::ZONE);
		zid f("(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia");
		CHECK(to_string(f.aid) == "(P)universe:milky-way:solar-system:earth");
		CHECK(f.country == "chile");
		CHECK(f.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(f.zone == "providencia");
		CHECK(f.zone_type == zid::ZONE);
		zid f2("(P)universe:milky-way:solar-system:earth (Z)chile:region-metropolitana:santiago:providencia");
		CHECK(to_string(f2.aid) == "(P)universe:milky-way:solar-system:earth");
		CHECK(f2.country == "chile");
		CHECK(f2.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(f2.zone == "providencia");
		CHECK(f2.zone_type == zid::ZONE);
		zid g("(Z) chile:region-metropolitana:santiago:providencia");
		CHECK(to_string(g.aid) == "");
		CHECK(g.country == "chile");
		CHECK(g.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(g.zone == "providencia");
		CHECK(g.zone_type == zid::ZONE);
		zid g2("(Z)chile:region-metropolitana:santiago:providencia");
		CHECK(to_string(g2.aid) == "");
		CHECK(g2.country == "chile");
		CHECK(g2.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(g2.zone == "providencia");
		CHECK(g2.zone_type == zid::ZONE);
		zid h("");
		CHECK(to_string(h.aid) == "");
		CHECK(h.country == "");
		CHECK(h.regions.size() == 0);
		CHECK(h.zone == "");
		CHECK(h.zone_type == zid::NONE);
		zid i("(S) chile:region-metropolitana:santiago");
		CHECK(to_string(i.aid) == "");
		CHECK(i.country == "chile");
		CHECK(i.regions == vector<string>{"region-metropolitana"});
		CHECK(i.zone == "santiago");
		CHECK(i.zone_type == zid::SETTLEMENT);
	}

	SECTION("Assignments of zid class")
	{
		zid b;
		zid b2(aid(astronomical_body::MARS),zid::ZONE,"no-country",{"southern-highlands"},"noachis-terra");
		b = b2;
		CHECK(to_string(b.aid) == "(P)universe:milky-way:solar-system:mars");
		CHECK(b.country == "no-country");
		CHECK(b.regions == vector<string>{"southern-highlands"});
		CHECK(b.zone == "noachis-terra");
		CHECK(b.zone_type == zid::ZONE);
		zid c;
		zid c2(aid(astronomical_body::EARTH),zid::ZONE,"chile",{"region-metropolitana","santiago"},"providencia");
		c = std::move(c2);
		CHECK(to_string(c.aid) == "(P)universe:milky-way:solar-system:earth");
		CHECK(c.country == "chile");
		CHECK(c.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(c.zone == "providencia");
		CHECK(c.zone_type == zid::ZONE);
		zid d;
		d = "(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia";
		CHECK(to_string(d.aid) == "(P)universe:milky-way:solar-system:earth");
		CHECK(d.country == "chile");
		CHECK(d.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(d.zone == "providencia");
		CHECK(d.zone_type == zid::ZONE);
		zid e;
		e = "(Z) chile:region-metropolitana:santiago:providencia";
		CHECK(to_string(e.aid) == "");
		CHECK(e.country == "chile");
		CHECK(e.regions == vector<string>{"region-metropolitana","santiago"});
		CHECK(e.zone == "providencia");
		CHECK(e.zone_type == zid::ZONE);
	}

	SECTION("has_no_country() ad has_unknown_country() of zid class")
	{
		zid a("(R) unknown-country:big-mountains");
		CHECK(a.has_unknown_country());
		zid b("(P)universe:milky-way:solar-system:mars (Z) no-country:southern-highlands:noachis-terra");
		CHECK(b.has_no_country());
		zid c("(P)universe:milky-way:solar-system:earth (Z) argentina:provincia-de-buenos-aires:buenos-aires:san-telmo");
		CHECK(c.has_no_country() == false);
		CHECK(c.has_unknown_country() == false);
	}

	SECTION("display() and partial_display() of zid class")
	{
		zid a("(P)universe:milky-way:solar-system:earth (Z) argentina:provincia-de-buenos-aires:buenos-aires:san-telmo");
		CHECK(a.display() == "(P)universe:milky-way:solar-system:earth (Z) argentina:provincia-de-buenos-aires:buenos-aires:san-telmo");
		CHECK(a.partial_display() == "(Z) argentina:provincia-de-buenos-aires:buenos-aires:san-telmo");
		zid b("");
		CHECK(b.display() == "");
		CHECK(b.partial_display() == "");
	}

	SECTION("to_string() of zid class")
	{
		zid a;
		CHECK(to_string(a) == "");
		zid b(aid(astronomical_body::MARS),zid::ZONE,"no-country",{"southern-highlands"},"noachis-terra");
		CHECK(to_string(b) == "(P)universe:milky-way:solar-system:mars (Z) no-country:southern-highlands:noachis-terra");
	}

	SECTION("to_string() of zid::type")
	{
		CHECK(to_string(zid::NONE) == "");
		CHECK(to_string(zid::COUNTRY) == "C");
		CHECK(to_string(zid::REGION) == "R");
		CHECK(to_string(zid::SETTLEMENT) == "S");
		CHECK(to_string(zid::ZONE) == "Z");
	}

	SECTION("create_zone_type() of zid::type")
	{
		CHECK(create_zone_type("") == zid::NONE);
		CHECK(create_zone_type("C") == zid::COUNTRY);
		CHECK(create_zone_type("R") == zid::REGION);
		CHECK(create_zone_type("S") == zid::SETTLEMENT);
		CHECK(create_zone_type("Z") == zid::ZONE);
	}

	SECTION("Operators of zid class")
	{
		zid a("(P)universe:milky-way:solar-system:mars (Z) no-country:southern-highlands:noachis-terra");
		zid b("(P)universe:milky-way:solar-system:mars (Z) no-country:southern-highlands:noachis-terra");
		zid c("(P)universe:milky-way:solar-system:mars (Z) no-country:southern-highlands:hesperia-planum");
		zid d("(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia");
		zid e("(P)universe:milky-way:solar-system:mars (Z) no-country:northern-lowlands:utopia-basin");
		zid f("(P)universe:milky-way:solar-system:earth (Z) argentina:provincia-de-buenos-aires:buenos-aires:san-telmo");
		CHECK(bool(a == b));
		CHECK((a == c) == false);
		CHECK((a == d) == false);
		CHECK((a == e) == false);
		CHECK((d == f) == false);
		CHECK(bool(a != c));
	}

	SECTION("String operators of zid class")
	{
		CHECK(bool(zid("(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia") == "(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia"));
		CHECK(bool(zid("(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia") != "(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:macul"));
		CHECK(bool("(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia" == zid("(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia")));
		CHECK(bool("(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia" != zid("(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:macul")));
		string a = "zid ";
		a += zid("(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia");
		CHECK(a == "zid (P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia");
		zid b = zid("(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia");
		CHECK("b " + b == "b (P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia");
		CHECK(b + " b" == "(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia b");
	}

	SECTION("Streams of zid class")
	{
		ostringstream a;
        a << zid("(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia");
        CHECK(a.str() == "(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia");
        stringstream b;
        b << "(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia";
        zid b2;
        b >> b2;
        CHECK(to_string(b2) == "(P)universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia");
	}
}