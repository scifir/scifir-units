#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../special_units/aid.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("aid class") {
	SECTION("Constructors of aid class")
	{
		aid a;
		CHECK(a.astronomical_type == aid::NONE);
		CHECK(a.universe == "");
		CHECK(a.galaxy == "");
		CHECK(a.solar_system == "");
		CHECK(a.astronomical_body == "");
		aid b2 = aid(aid::PLANET,"universe","milky-way","solar-system","earth");
		aid b(b2);
		CHECK(b.astronomical_type == aid::PLANET);
		CHECK(b.universe == "universe");
		CHECK(b.galaxy == "milky-way");
		CHECK(b.solar_system == "solar-system");
		CHECK(b.astronomical_body == "earth");
		aid c2 = aid(aid::PLANET,"universe","milky-way","solar-system","earth");
		aid c(std::move(c2));
		CHECK(c.astronomical_type == aid::PLANET);
		CHECK(c.universe == "universe");
		CHECK(c.galaxy == "milky-way");
		CHECK(c.solar_system == "solar-system");
		CHECK(c.astronomical_body == "earth");
		aid d2(aid::UNIVERSE,"universe-a123");
		CHECK(d2.astronomical_type == aid::UNIVERSE);
		CHECK(d2.universe == "universe-a123");
		CHECK(d2.galaxy == "");
		CHECK(d2.solar_system == "");
		CHECK(d2.astronomical_body == "");
		aid d("universe","milky-way");
		CHECK(d.astronomical_type == aid::GALAXY);
		CHECK(d.universe == "universe");
		CHECK(d.galaxy == "milky-way");
		CHECK(d.solar_system == "");
		CHECK(d.astronomical_body == "");
		aid e("universe","milky-way","solar-system");
		CHECK(e.astronomical_type == aid::SOLAR_SYSTEM);
		CHECK(e.universe == "universe");
		CHECK(e.galaxy == "milky-way");
		CHECK(e.solar_system == "solar-system");
		CHECK(e.astronomical_body == "");
		aid f(aid::PLANET,"universe","milky-way","solar-system","earth");
		CHECK(f.astronomical_type == aid::PLANET);
		CHECK(f.universe == "universe");
		CHECK(f.galaxy == "milky-way");
		CHECK(f.solar_system == "solar-system");
		CHECK(f.astronomical_body == "earth");
		aid g("(P)universe:milky-way:solar-system:earth");
		CHECK(g.astronomical_type == aid::PLANET);
		CHECK(g.universe == "universe");
		CHECK(g.galaxy == "milky-way");
		CHECK(g.solar_system == "solar-system");
		CHECK(g.astronomical_body == "earth");
		aid h("(G)universe:milky-way");
		CHECK(h.astronomical_type == aid::GALAXY);
		CHECK(h.universe == "universe");
		CHECK(h.galaxy == "milky-way");
		CHECK(h.solar_system == "");
		CHECK(h.astronomical_body == "");
		aid i("(SS)universe:milky-way:solar-system");
		CHECK(i.astronomical_type == aid::SOLAR_SYSTEM);
		CHECK(i.universe == "universe");
		CHECK(i.galaxy == "milky-way");
		CHECK(i.solar_system == "solar-system");
		CHECK(i.astronomical_body == "");
		aid j("");
		CHECK(j.astronomical_type == aid::NONE);
		CHECK(j.universe == "");
		CHECK(j.galaxy == "");
		CHECK(j.solar_system == "");
		CHECK(j.astronomical_body == "");
		aid k("(SS) universe:milky-way:solar-system");
		CHECK(k.astronomical_type == aid::SOLAR_SYSTEM);
		CHECK(k.universe == "universe");
		CHECK(k.galaxy == "milky-way");
		CHECK(k.solar_system == "solar-system");
		CHECK(k.astronomical_body == "");
		aid l("(G) universe:milky-way");
		CHECK(l.astronomical_type == aid::GALAXY);
		CHECK(l.universe == "universe");
		CHECK(l.galaxy == "milky-way");
		CHECK(l.solar_system == "");
		CHECK(l.astronomical_body == "");
	}

	SECTION("Constructors of aid class that use the enum astronomical_body")
	{
		aid a(astronomical_body::NONE);
		CHECK(a.astronomical_type == aid::NONE);
		CHECK(a.universe == "");
		CHECK(a.galaxy == "");
		CHECK(a.solar_system == "");
		CHECK(a.astronomical_body == "");
		aid a2(astronomical_body::MILKY_WAY);
		CHECK(a2.astronomical_type == aid::GALAXY);
		CHECK(a2.universe == "universe");
		CHECK(a2.galaxy == "milky-way");
		CHECK(a2.solar_system == "");
		CHECK(a2.astronomical_body == "");
		aid a3(astronomical_body::ANDROMEDA);
		CHECK(a3.astronomical_type == aid::GALAXY);
		CHECK(a3.universe == "universe");
		CHECK(a3.galaxy == "andromeda");
		CHECK(a3.solar_system == "");
		CHECK(a3.astronomical_body == "");
		aid a4(astronomical_body::SOLAR_SYSTEM);
		CHECK(a4.astronomical_type == aid::SOLAR_SYSTEM);
		CHECK(a4.universe == "universe");
		CHECK(a4.galaxy == "milky-way");
		CHECK(a4.solar_system == "solar-system");
		CHECK(a4.astronomical_body == "");
		aid a5(astronomical_body::SUN);
		CHECK(a5.astronomical_type == aid::STAR);
		CHECK(a5.universe == "universe");
		CHECK(a5.galaxy == "milky-way");
		CHECK(a5.solar_system == "solar-system");
		CHECK(a5.astronomical_body == "sun");
		aid a6(astronomical_body::MOON);
		CHECK(a6.astronomical_type == aid::MOON);
		CHECK(a6.universe == "universe");
		CHECK(a6.galaxy == "milky-way");
		CHECK(a6.solar_system == "solar-system");
		CHECK(a6.astronomical_body == "moon");
		aid a7(astronomical_body::MERCURY);
		CHECK(a7.astronomical_type == aid::PLANET);
		CHECK(a7.universe == "universe");
		CHECK(a7.galaxy == "milky-way");
		CHECK(a7.solar_system == "solar-system");
		CHECK(a7.astronomical_body == "mercury");
		aid a8(astronomical_body::VENUS);
		CHECK(a8.astronomical_type == aid::PLANET);
		CHECK(a8.universe == "universe");
		CHECK(a8.galaxy == "milky-way");
		CHECK(a8.solar_system == "solar-system");
		CHECK(a8.astronomical_body == "venus");
		aid a9(astronomical_body::EARTH);
		CHECK(a9.astronomical_type == aid::PLANET);
		CHECK(a9.universe == "universe");
		CHECK(a9.galaxy == "milky-way");
		CHECK(a9.solar_system == "solar-system");
		CHECK(a9.astronomical_body == "earth");
		aid a10(astronomical_body::MARS);
		CHECK(a10.astronomical_type == aid::PLANET);
		CHECK(a10.universe == "universe");
		CHECK(a10.galaxy == "milky-way");
		CHECK(a10.solar_system == "solar-system");
		CHECK(a10.astronomical_body == "mars");
		aid a11(astronomical_body::JUPITER);
		CHECK(a11.astronomical_type == aid::PLANET);
		CHECK(a11.universe == "universe");
		CHECK(a11.galaxy == "milky-way");
		CHECK(a11.solar_system == "solar-system");
		CHECK(a11.astronomical_body == "jupiter");
		aid a12(astronomical_body::SATURN);
		CHECK(a12.astronomical_type == aid::PLANET);
		CHECK(a12.universe == "universe");
		CHECK(a12.galaxy == "milky-way");
		CHECK(a12.solar_system == "solar-system");
		CHECK(a12.astronomical_body == "saturn");
		aid a13(astronomical_body::URANUS);
		CHECK(a13.astronomical_type == aid::PLANET);
		CHECK(a13.universe == "universe");
		CHECK(a13.galaxy == "milky-way");
		CHECK(a13.solar_system == "solar-system");
		CHECK(a13.astronomical_body == "uranus");
		aid a14(astronomical_body::NEPTUNE);
		CHECK(a14.astronomical_type == aid::PLANET);
		CHECK(a14.universe == "universe");
		CHECK(a14.galaxy == "milky-way");
		CHECK(a14.solar_system == "solar-system");
		CHECK(a14.astronomical_body == "neptune");
		aid a15(astronomical_body::CERES);
		CHECK(a15.astronomical_type == aid::PLANET);
		CHECK(a15.universe == "universe");
		CHECK(a15.galaxy == "milky-way");
		CHECK(a15.solar_system == "solar-system");
		CHECK(a15.astronomical_body == "ceres");
		aid a16(astronomical_body::ORCUS);
		CHECK(a16.astronomical_type == aid::PLANET);
		CHECK(a16.universe == "universe");
		CHECK(a16.galaxy == "milky-way");
		CHECK(a16.solar_system == "solar-system");
		CHECK(a16.astronomical_body == "orcus");
		aid a17(astronomical_body::PLUTO);
		CHECK(a17.astronomical_type == aid::PLANET);
		CHECK(a17.universe == "universe");
		CHECK(a17.galaxy == "milky-way");
		CHECK(a17.solar_system == "solar-system");
		CHECK(a17.astronomical_body == "pluto");
		aid a18(astronomical_body::HAUMEA);
		CHECK(a18.astronomical_type == aid::PLANET);
		CHECK(a18.universe == "universe");
		CHECK(a18.galaxy == "milky-way");
		CHECK(a18.solar_system == "solar-system");
		CHECK(a18.astronomical_body == "haumea");
		aid a19(astronomical_body::QUAOAR);
		CHECK(a19.astronomical_type == aid::PLANET);
		CHECK(a19.universe == "universe");
		CHECK(a19.galaxy == "milky-way");
		CHECK(a19.solar_system == "solar-system");
		CHECK(a19.astronomical_body == "quaoar");
		aid a20(astronomical_body::MAKEMAKE);
		CHECK(a20.astronomical_type == aid::PLANET);
		CHECK(a20.universe == "universe");
		CHECK(a20.galaxy == "milky-way");
		CHECK(a20.solar_system == "solar-system");
		CHECK(a20.astronomical_body == "makemake");
		aid a21(astronomical_body::GONGGONG);
		CHECK(a21.astronomical_type == aid::PLANET);
		CHECK(a21.universe == "universe");
		CHECK(a21.galaxy == "milky-way");
		CHECK(a21.solar_system == "solar-system");
		CHECK(a21.astronomical_body == "gonggong");
		aid a22(astronomical_body::ERIS);
		CHECK(a22.astronomical_type == aid::PLANET);
		CHECK(a22.universe == "universe");
		CHECK(a22.galaxy == "milky-way");
		CHECK(a22.solar_system == "solar-system");
		CHECK(a22.astronomical_body == "eris");
		aid a23(astronomical_body::SEDNA);
		CHECK(a23.astronomical_type == aid::PLANET);
		CHECK(a23.universe == "universe");
		CHECK(a23.galaxy == "milky-way");
		CHECK(a23.solar_system == "solar-system");
		CHECK(a23.astronomical_body == "sedna");
		aid a24(astronomical_body::IO);
		CHECK(a24.astronomical_type == aid::MOON);
		CHECK(a24.universe == "universe");
		CHECK(a24.galaxy == "milky-way");
		CHECK(a24.solar_system == "solar-system");
		CHECK(a24.astronomical_body == "io");
		aid a25(astronomical_body::EUROPA);
		CHECK(a25.astronomical_type == aid::MOON);
		CHECK(a25.universe == "universe");
		CHECK(a25.galaxy == "milky-way");
		CHECK(a25.solar_system == "solar-system");
		CHECK(a25.astronomical_body == "europa");
		aid a26(astronomical_body::GANYMEDE);
		CHECK(a26.astronomical_type == aid::MOON);
		CHECK(a26.universe == "universe");
		CHECK(a26.galaxy == "milky-way");
		CHECK(a26.solar_system == "solar-system");
		CHECK(a26.astronomical_body == "ganymede");
		aid a27(astronomical_body::CALLISTO);
		CHECK(a27.astronomical_type == aid::MOON);
		CHECK(a27.universe == "universe");
		CHECK(a27.galaxy == "milky-way");
		CHECK(a27.solar_system == "solar-system");
		CHECK(a27.astronomical_body == "callisto");
		aid a28(astronomical_body::MIMAS);
		CHECK(a28.astronomical_type == aid::MOON);
		CHECK(a28.universe == "universe");
		CHECK(a28.galaxy == "milky-way");
		CHECK(a28.solar_system == "solar-system");
		CHECK(a28.astronomical_body == "mimas");
		aid a29(astronomical_body::ENCELADUS);
		CHECK(a29.astronomical_type == aid::MOON);
		CHECK(a29.universe == "universe");
		CHECK(a29.galaxy == "milky-way");
		CHECK(a29.solar_system == "solar-system");
		CHECK(a29.astronomical_body == "enceladus");
		aid a30(astronomical_body::TETHYS);
		CHECK(a30.astronomical_type == aid::MOON);
		CHECK(a30.universe == "universe");
		CHECK(a30.galaxy == "milky-way");
		CHECK(a30.solar_system == "solar-system");
		CHECK(a30.astronomical_body == "tethys");
		aid a31(astronomical_body::DIONE);
		CHECK(a31.astronomical_type == aid::MOON);
		CHECK(a31.universe == "universe");
		CHECK(a31.galaxy == "milky-way");
		CHECK(a31.solar_system == "solar-system");
		CHECK(a31.astronomical_body == "dione");
		aid a32(astronomical_body::RHEA);
		CHECK(a32.astronomical_type == aid::MOON);
		CHECK(a32.universe == "universe");
		CHECK(a32.galaxy == "milky-way");
		CHECK(a32.solar_system == "solar-system");
		CHECK(a32.astronomical_body == "rhea");
		aid a33(astronomical_body::TITAN);
		CHECK(a33.astronomical_type == aid::MOON);
		CHECK(a33.universe == "universe");
		CHECK(a33.galaxy == "milky-way");
		CHECK(a33.solar_system == "solar-system");
		CHECK(a33.astronomical_body == "titan");
		aid a34(astronomical_body::IAPETUS);
		CHECK(a34.astronomical_type == aid::MOON);
		CHECK(a34.universe == "universe");
		CHECK(a34.galaxy == "milky-way");
		CHECK(a34.solar_system == "solar-system");
		CHECK(a34.astronomical_body == "iapetus");
		aid a35(astronomical_body::MIRANDA);
		CHECK(a35.astronomical_type == aid::MOON);
		CHECK(a35.universe == "universe");
		CHECK(a35.galaxy == "milky-way");
		CHECK(a35.solar_system == "solar-system");
		CHECK(a35.astronomical_body == "miranda");
		aid a36(astronomical_body::ARIEL);
		CHECK(a36.astronomical_type == aid::MOON);
		CHECK(a36.universe == "universe");
		CHECK(a36.galaxy == "milky-way");
		CHECK(a36.solar_system == "solar-system");
		CHECK(a36.astronomical_body == "ariel");
		aid a37(astronomical_body::UMBRIEL);
		CHECK(a37.astronomical_type == aid::MOON);
		CHECK(a37.universe == "universe");
		CHECK(a37.galaxy == "milky-way");
		CHECK(a37.solar_system == "solar-system");
		CHECK(a37.astronomical_body == "umbriel");
		aid a38(astronomical_body::TITANIA);
		CHECK(a38.astronomical_type == aid::MOON);
		CHECK(a38.universe == "universe");
		CHECK(a38.galaxy == "milky-way");
		CHECK(a38.solar_system == "solar-system");
		CHECK(a38.astronomical_body == "titania");
		aid a39(astronomical_body::OBERON);
		CHECK(a39.astronomical_type == aid::MOON);
		CHECK(a39.universe == "universe");
		CHECK(a39.galaxy == "milky-way");
		CHECK(a39.solar_system == "solar-system");
		CHECK(a39.astronomical_body == "oberon");
		aid a40(astronomical_body::TRITON);
		CHECK(a40.astronomical_type == aid::MOON);
		CHECK(a40.universe == "universe");
		CHECK(a40.galaxy == "milky-way");
		CHECK(a40.solar_system == "solar-system");
		CHECK(a40.astronomical_body == "triton");
		aid a41(astronomical_body::CHARON);
		CHECK(a41.astronomical_type == aid::MOON);
		CHECK(a41.universe == "universe");
		CHECK(a41.galaxy == "milky-way");
		CHECK(a41.solar_system == "solar-system");
		CHECK(a41.astronomical_body == "charon");
		aid a42(astronomical_body::DYSNOMIA);
		CHECK(a42.astronomical_type == aid::MOON);
		CHECK(a42.universe == "universe");
		CHECK(a42.galaxy == "milky-way");
		CHECK(a42.solar_system == "solar-system");
		CHECK(a42.astronomical_body == "dysnomia");
	}

	SECTION("Assignments of aid class")
	{
		aid b;
		aid b2 = aid(aid::PLANET,"universe","milky-way","solar-system","earth");
		b = b2;
		CHECK(b.astronomical_type == aid::PLANET);
		CHECK(b.universe == "universe");
		CHECK(b.galaxy == "milky-way");
		CHECK(b.solar_system == "solar-system");
		CHECK(b.astronomical_body == "earth");
		aid c;
		aid c2 = aid(aid::PLANET,"universe","milky-way","solar-system","earth");
		c = std::move(c2);
		CHECK(c.astronomical_type == aid::PLANET);
		CHECK(c.universe == "universe");
		CHECK(c.galaxy == "milky-way");
		CHECK(c.solar_system == "solar-system");
		CHECK(c.astronomical_body == "earth");
		aid d;
		d = "(SS)universe:milky-way:solar-system";
		CHECK(d.astronomical_type == aid::SOLAR_SYSTEM);
		CHECK(d.universe == "universe");
		CHECK(d.galaxy == "milky-way");
		CHECK(d.solar_system == "solar-system");
		CHECK(d.astronomical_body == "");
		aid e;
		e = "(P)universe:milky-way:solar-system:earth";
		CHECK(e.astronomical_type == aid::PLANET);
		CHECK(e.universe == "universe");
		CHECK(e.galaxy == "milky-way");
		CHECK(e.solar_system == "solar-system");
		CHECK(e.astronomical_body == "earth");
		aid f;
		f = "(G)universe:milky-way";
		CHECK(f.astronomical_type == aid::GALAXY);
		CHECK(f.universe == "universe");
		CHECK(f.galaxy == "milky-way");
		CHECK(f.solar_system == "");
		CHECK(f.astronomical_body == "");
	}

	SECTION("Functions of unknown places of aid class")
	{
		aid a("(P)unknown-universe:unknown-galaxy:unknown-solar-system:unknown-planet");
		CHECK(a.has_unknown_universe());
		CHECK(a.has_unknown_galaxy());
		CHECK(a.has_unknown_solar_system());
		CHECK(a.has_unknown_planet());
		aid a2("(P) no-universe:galaxy-123:strange-solar-system:planet-124a");
		CHECK(a2.has_no_universe());
		aid b("(MN)unknown-universe:unknown-galaxy:unknown-solar-system:unknown-moon");
		CHECK(b.has_unknown_universe());
		CHECK(b.has_unknown_galaxy());
		CHECK(b.has_unknown_solar_system());
		CHECK(b.has_unknown_moon());
		aid b2("(P) universe:no-galaxy:solar-system-12b:planet-45c");
		CHECK(b2.has_no_galaxy());
		aid c("(ST)unknown-universe:unknown-galaxy:unknown-solar-system:unknown-star");
		CHECK(c.has_unknown_universe());
		CHECK(c.has_unknown_galaxy());
		CHECK(c.has_unknown_solar_system());
		CHECK(c.has_unknown_star());
		aid c2("(P) universe:milky-way:no-solar-system:unknown-planet");
		CHECK(c2.has_no_solar_system());
		aid d("(A)unknown-universe:unknown-galaxy:unknown-solar-system:unknown-asteroid");
		CHECK(d.has_unknown_universe());
		CHECK(d.has_unknown_galaxy());
		CHECK(d.has_unknown_solar_system());
		CHECK(d.has_unknown_asteroid());
	}

	SECTION("display() of aid class")
	{
		aid a("(SS)universe:milky-way:solar-system");
		CHECK(a.display() == "(SS)universe:milky-way:solar-system");
		aid b("(U)universe");
		CHECK(b.display() == "(U)universe");
		aid c("(G)universe:milky-way");
		CHECK(c.display() == "(G)universe:milky-way");
		aid d("(P)universe:milky-way:solar-system:mars");
		CHECK(d.display() == "(P)universe:milky-way:solar-system:mars");
		aid e;
		CHECK(e.display() == "");
	}

	SECTION("to_string() of aid class")
	{
		aid a("(SS)universe:milky-way:solar-system");
		CHECK(to_string(a) == "(SS)universe:milky-way:solar-system");
		aid b("(U)universe");
		CHECK(to_string(b) == "(U)universe");
		aid c("(G)universe:milky-way");
		CHECK(to_string(c) == "(G)universe:milky-way");
		aid d("(P)universe:milky-way:solar-system:mars");
		CHECK(to_string(d) == "(P)universe:milky-way:solar-system:mars");
		aid e;
		CHECK(to_string(e) == "");
	}

	SECTION("to_string() of aid::type")
	{
		CHECK(to_string(aid::UNIVERSE) == "U");
		CHECK(to_string(aid::GALAXY) == "G");
		CHECK(to_string(aid::SOLAR_SYSTEM) == "SS");
		CHECK(to_string(aid::PLANET) == "P");
		CHECK(to_string(aid::STAR) == "ST");
		CHECK(to_string(aid::ASTEROID) == "A");
		CHECK(to_string(aid::MOON) == "MN");
		CHECK(to_string(aid::METEOR) == "MT");
		CHECK(to_string(aid::NONE) == "");
	}

	SECTION("create_astronomical_type()")
	{
		CHECK(create_astronomical_type("U") == aid::UNIVERSE);
		CHECK(create_astronomical_type("G") == aid::GALAXY);
		CHECK(create_astronomical_type("SS") == aid::SOLAR_SYSTEM);
		CHECK(create_astronomical_type("P") == aid::PLANET);
		CHECK(create_astronomical_type("ST") == aid::STAR);
		CHECK(create_astronomical_type("A") == aid::ASTEROID);
		CHECK(create_astronomical_type("MN") == aid::MOON);
		CHECK(create_astronomical_type("MT") == aid::METEOR);
		CHECK(create_astronomical_type("") == aid::NONE);
	}

	SECTION("Operators of aid class")
	{
		aid a("(G)universe:milky-way");
		aid b("(G)universe:milky-way");
		aid c("(G)universe:andromeda");
		CHECK(bool(a == b));
		CHECK((a == c) == false);
		CHECK(bool(a != c));
	}

	SECTION("String operators of aid class")
	{
		CHECK(bool(aid("(SS)universe:milky-way:solar-system") == "(SS)universe:milky-way:solar-system"));
		CHECK(bool(aid("(SS)universe:milky-way:solar-system") != "(SS)universe:milky-way:alpha-centauri"));
		CHECK(bool("(SS)universe:milky-way:alpha-centauri" == aid("(SS)universe:milky-way:alpha-centauri")));
		CHECK(bool("(SS)universe:milky-way:alpha-centauri" != aid("(SS)universe:milky-way:solar-system")));
		string a = "aid ";
		a += aid("(SS)universe:milky-way:alpha-centauri");
		CHECK(a == "aid (SS)universe:milky-way:alpha-centauri");
		aid b = aid("(SS)universe:milky-way:alpha-centauri");
		CHECK("b " + b == "b (SS)universe:milky-way:alpha-centauri");
		CHECK(b + " b" == "(SS)universe:milky-way:alpha-centauri b");
	}

	SECTION("Streams of aid class")
	{
		ostringstream a;
        a << aid("(SS)universe:milky-way:alpha-centauri");
        CHECK(a.str() == "(SS)universe:milky-way:alpha-centauri");
        stringstream b;
        b << "(SS)universe:milky-way:alpha-centauri";
        aid b2;
        b >> b2;
        CHECK(to_string(b2) == "(SS)universe:milky-way:alpha-centauri");
	}
}