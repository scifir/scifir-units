#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../special_units/aid.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("aid class","Full test of aid class") {
	SECTION("Constructors of aid class")
	{
		aid a;
		REQUIRE (bool(a.astronomical_type == aid::NONE));
		REQUIRE (bool(a.universe == ""));
		REQUIRE (bool(a.galaxy == ""));
		REQUIRE (bool(a.solar_system == ""));
		REQUIRE (bool(a.astronomical_body == ""));
		aid b2 = aid(aid::PLANET,"universe","milky-way","solar-system","earth");
		aid b(b2);
		REQUIRE (bool(b.astronomical_type == aid::PLANET));
		REQUIRE (bool(b.universe == "universe"));
		REQUIRE (bool(b.galaxy == "milky-way"));
		REQUIRE (bool(b.solar_system == "solar-system"));
		REQUIRE (bool(b.astronomical_body == "earth"));
		aid c2 = aid(aid::PLANET,"universe","milky-way","solar-system","earth");
		aid c(std::move(c2));
		REQUIRE (bool(c.astronomical_type == aid::PLANET));
		REQUIRE (bool(c.universe == "universe"));
		REQUIRE (bool(c.galaxy == "milky-way"));
		REQUIRE (bool(c.solar_system == "solar-system"));
		REQUIRE (bool(c.astronomical_body == "earth"));
		aid d("universe","milky-way");
		REQUIRE (bool(d.astronomical_type == aid::GALAXY));
		REQUIRE (bool(d.universe == "universe"));
		REQUIRE (bool(d.galaxy == "milky-way"));
		REQUIRE (bool(d.solar_system == ""));
		REQUIRE (bool(d.astronomical_body == ""));
		aid e("universe","milky-way","solar-system");
		REQUIRE (bool(e.astronomical_type == aid::SOLAR_SYSTEM));
		REQUIRE (bool(e.universe == "universe"));
		REQUIRE (bool(e.galaxy == "milky-way"));
		REQUIRE (bool(e.solar_system == "solar-system"));
		REQUIRE (bool(e.astronomical_body == ""));
		aid f(aid::PLANET,"universe","milky-way","solar-system","earth");
		REQUIRE (bool(f.astronomical_type == aid::PLANET));
		REQUIRE (bool(f.universe == "universe"));
		REQUIRE (bool(f.galaxy == "milky-way"));
		REQUIRE (bool(f.solar_system == "solar-system"));
		REQUIRE (bool(f.astronomical_body == "earth"));
		aid g("(P)universe:milky-way:solar-system:earth");
		REQUIRE (bool(g.astronomical_type == aid::PLANET));
		REQUIRE (bool(g.universe == "universe"));
		REQUIRE (bool(g.galaxy == "milky-way"));
		REQUIRE (bool(g.solar_system == "solar-system"));
		REQUIRE (bool(g.astronomical_body == "earth"));
		aid h("(G)universe:milky-way");
		REQUIRE (bool(h.astronomical_type == aid::GALAXY));
		REQUIRE (bool(h.universe == "universe"));
		REQUIRE (bool(h.galaxy == "milky-way"));
		REQUIRE (bool(h.solar_system == ""));
		REQUIRE (bool(h.astronomical_body == ""));
		aid i("(SS)universe:milky-way:solar-system");
		REQUIRE (bool(i.astronomical_type == aid::SOLAR_SYSTEM));
		REQUIRE (bool(i.universe == "universe"));
		REQUIRE (bool(i.galaxy == "milky-way"));
		REQUIRE (bool(i.solar_system == "solar-system"));
		REQUIRE (bool(i.astronomical_body == ""));
		aid j("");
		REQUIRE (bool(j.astronomical_type == aid::NONE));
		REQUIRE (bool(j.universe == ""));
		REQUIRE (bool(j.galaxy == ""));
		REQUIRE (bool(j.solar_system == ""));
		REQUIRE (bool(j.astronomical_body == ""));
	}

	SECTION("Constructors of aid class that use the enum astronomical_body")
	{
		aid a(astronomical_body::NONE);
		REQUIRE (bool(a.astronomical_type == aid::NONE));
		REQUIRE (bool(a.universe == ""));
		REQUIRE (bool(a.galaxy == ""));
		REQUIRE (bool(a.solar_system == ""));
		REQUIRE (bool(a.astronomical_body == ""));
		aid a2(astronomical_body::MILKY_WAY);
		REQUIRE (bool(a2.astronomical_type == aid::GALAXY));
		REQUIRE (bool(a2.universe == "universe"));
		REQUIRE (bool(a2.galaxy == "milky-way"));
		REQUIRE (bool(a2.solar_system == ""));
		REQUIRE (bool(a2.astronomical_body == ""));
		aid a3(astronomical_body::ANDROMEDA);
		REQUIRE (bool(a3.astronomical_type == aid::GALAXY));
		REQUIRE (bool(a3.universe == "universe"));
		REQUIRE (bool(a3.galaxy == "andromeda"));
		REQUIRE (bool(a3.solar_system == ""));
		REQUIRE (bool(a3.astronomical_body == ""));
		aid a4(astronomical_body::SOLAR_SYSTEM);
		REQUIRE (bool(a4.astronomical_type == aid::SOLAR_SYSTEM));
		REQUIRE (bool(a4.universe == "universe"));
		REQUIRE (bool(a4.galaxy == "milky-way"));
		REQUIRE (bool(a4.solar_system == "solar-system"));
		REQUIRE (bool(a4.astronomical_body == ""));
		aid a5(astronomical_body::SUN);
		REQUIRE (bool(a5.astronomical_type == aid::STAR));
		REQUIRE (bool(a5.universe == "universe"));
		REQUIRE (bool(a5.galaxy == "milky-way"));
		REQUIRE (bool(a5.solar_system == "solar-system"));
		REQUIRE (bool(a5.astronomical_body == "sun"));
		aid a6(astronomical_body::MOON);
		REQUIRE (bool(a6.astronomical_type == aid::MOON));
		REQUIRE (bool(a6.universe == "universe"));
		REQUIRE (bool(a6.galaxy == "milky-way"));
		REQUIRE (bool(a6.solar_system == "solar-system"));
		REQUIRE (bool(a6.astronomical_body == "moon"));
		aid a7(astronomical_body::MERCURY);
		REQUIRE (bool(a7.astronomical_type == aid::PLANET));
		REQUIRE (bool(a7.universe == "universe"));
		REQUIRE (bool(a7.galaxy == "milky-way"));
		REQUIRE (bool(a7.solar_system == "solar-system"));
		REQUIRE (bool(a7.astronomical_body == "mercury"));
		aid a8(astronomical_body::VENUS);
		REQUIRE (bool(a8.astronomical_type == aid::PLANET));
		REQUIRE (bool(a8.universe == "universe"));
		REQUIRE (bool(a8.galaxy == "milky-way"));
		REQUIRE (bool(a8.solar_system == "solar-system"));
		REQUIRE (bool(a8.astronomical_body == "venus"));
		aid a9(astronomical_body::EARTH);
		REQUIRE (bool(a9.astronomical_type == aid::PLANET));
		REQUIRE (bool(a9.universe == "universe"));
		REQUIRE (bool(a9.galaxy == "milky-way"));
		REQUIRE (bool(a9.solar_system == "solar-system"));
		REQUIRE (bool(a9.astronomical_body == "earth"));
		aid a10(astronomical_body::MARS);
		REQUIRE (bool(a10.astronomical_type == aid::PLANET));
		REQUIRE (bool(a10.universe == "universe"));
		REQUIRE (bool(a10.galaxy == "milky-way"));
		REQUIRE (bool(a10.solar_system == "solar-system"));
		REQUIRE (bool(a10.astronomical_body == "mars"));
		aid a11(astronomical_body::JUPITER);
		REQUIRE (bool(a11.astronomical_type == aid::PLANET));
		REQUIRE (bool(a11.universe == "universe"));
		REQUIRE (bool(a11.galaxy == "milky-way"));
		REQUIRE (bool(a11.solar_system == "solar-system"));
		REQUIRE (bool(a11.astronomical_body == "jupiter"));
		aid a12(astronomical_body::SATURN);
		REQUIRE (bool(a12.astronomical_type == aid::PLANET));
		REQUIRE (bool(a12.universe == "universe"));
		REQUIRE (bool(a12.galaxy == "milky-way"));
		REQUIRE (bool(a12.solar_system == "solar-system"));
		REQUIRE (bool(a12.astronomical_body == "saturn"));
		aid a13(astronomical_body::URANUS);
		REQUIRE (bool(a13.astronomical_type == aid::PLANET));
		REQUIRE (bool(a13.universe == "universe"));
		REQUIRE (bool(a13.galaxy == "milky-way"));
		REQUIRE (bool(a13.solar_system == "solar-system"));
		REQUIRE (bool(a13.astronomical_body == "uranus"));
		aid a14(astronomical_body::NEPTUNE);
		REQUIRE (bool(a14.astronomical_type == aid::PLANET));
		REQUIRE (bool(a14.universe == "universe"));
		REQUIRE (bool(a14.galaxy == "milky-way"));
		REQUIRE (bool(a14.solar_system == "solar-system"));
		REQUIRE (bool(a14.astronomical_body == "neptune"));
		aid a15(astronomical_body::CERES);
		REQUIRE (bool(a15.astronomical_type == aid::PLANET));
		REQUIRE (bool(a15.universe == "universe"));
		REQUIRE (bool(a15.galaxy == "milky-way"));
		REQUIRE (bool(a15.solar_system == "solar-system"));
		REQUIRE (bool(a15.astronomical_body == "ceres"));
		aid a16(astronomical_body::ORCUS);
		REQUIRE (bool(a16.astronomical_type == aid::PLANET));
		REQUIRE (bool(a16.universe == "universe"));
		REQUIRE (bool(a16.galaxy == "milky-way"));
		REQUIRE (bool(a16.solar_system == "solar-system"));
		REQUIRE (bool(a16.astronomical_body == "orcus"));
		aid a17(astronomical_body::PLUTO);
		REQUIRE (bool(a17.astronomical_type == aid::PLANET));
		REQUIRE (bool(a17.universe == "universe"));
		REQUIRE (bool(a17.galaxy == "milky-way"));
		REQUIRE (bool(a17.solar_system == "solar-system"));
		REQUIRE (bool(a17.astronomical_body == "pluto"));
		aid a18(astronomical_body::HAUMEA);
		REQUIRE (bool(a18.astronomical_type == aid::PLANET));
		REQUIRE (bool(a18.universe == "universe"));
		REQUIRE (bool(a18.galaxy == "milky-way"));
		REQUIRE (bool(a18.solar_system == "solar-system"));
		REQUIRE (bool(a18.astronomical_body == "haumea"));
		aid a19(astronomical_body::QUAOAR);
		REQUIRE (bool(a19.astronomical_type == aid::PLANET));
		REQUIRE (bool(a19.universe == "universe"));
		REQUIRE (bool(a19.galaxy == "milky-way"));
		REQUIRE (bool(a19.solar_system == "solar-system"));
		REQUIRE (bool(a19.astronomical_body == "quaoar"));
		aid a20(astronomical_body::MAKEMAKE);
		REQUIRE (bool(a20.astronomical_type == aid::PLANET));
		REQUIRE (bool(a20.universe == "universe"));
		REQUIRE (bool(a20.galaxy == "milky-way"));
		REQUIRE (bool(a20.solar_system == "solar-system"));
		REQUIRE (bool(a20.astronomical_body == "makemake"));
		aid a21(astronomical_body::GONGGONG);
		REQUIRE (bool(a21.astronomical_type == aid::PLANET));
		REQUIRE (bool(a21.universe == "universe"));
		REQUIRE (bool(a21.galaxy == "milky-way"));
		REQUIRE (bool(a21.solar_system == "solar-system"));
		REQUIRE (bool(a21.astronomical_body == "gonggong"));
		aid a22(astronomical_body::ERIS);
		REQUIRE (bool(a22.astronomical_type == aid::PLANET));
		REQUIRE (bool(a22.universe == "universe"));
		REQUIRE (bool(a22.galaxy == "milky-way"));
		REQUIRE (bool(a22.solar_system == "solar-system"));
		REQUIRE (bool(a22.astronomical_body == "eris"));
		aid a23(astronomical_body::SEDNA);
		REQUIRE (bool(a23.astronomical_type == aid::PLANET));
		REQUIRE (bool(a23.universe == "universe"));
		REQUIRE (bool(a23.galaxy == "milky-way"));
		REQUIRE (bool(a23.solar_system == "solar-system"));
		REQUIRE (bool(a23.astronomical_body == "sedna"));
		aid a24(astronomical_body::IO);
		REQUIRE (bool(a24.astronomical_type == aid::MOON));
		REQUIRE (bool(a24.universe == "universe"));
		REQUIRE (bool(a24.galaxy == "milky-way"));
		REQUIRE (bool(a24.solar_system == "solar-system"));
		REQUIRE (bool(a24.astronomical_body == "io"));
		aid a25(astronomical_body::EUROPA);
		REQUIRE (bool(a25.astronomical_type == aid::MOON));
		REQUIRE (bool(a25.universe == "universe"));
		REQUIRE (bool(a25.galaxy == "milky-way"));
		REQUIRE (bool(a25.solar_system == "solar-system"));
		REQUIRE (bool(a25.astronomical_body == "europa"));
		aid a26(astronomical_body::GANYMEDE);
		REQUIRE (bool(a26.astronomical_type == aid::MOON));
		REQUIRE (bool(a26.universe == "universe"));
		REQUIRE (bool(a26.galaxy == "milky-way"));
		REQUIRE (bool(a26.solar_system == "solar-system"));
		REQUIRE (bool(a26.astronomical_body == "ganymede"));
		aid a27(astronomical_body::CALLISTO);
		REQUIRE (bool(a27.astronomical_type == aid::MOON));
		REQUIRE (bool(a27.universe == "universe"));
		REQUIRE (bool(a27.galaxy == "milky-way"));
		REQUIRE (bool(a27.solar_system == "solar-system"));
		REQUIRE (bool(a27.astronomical_body == "callisto"));
		aid a28(astronomical_body::MIMAS);
		REQUIRE (bool(a28.astronomical_type == aid::MOON));
		REQUIRE (bool(a28.universe == "universe"));
		REQUIRE (bool(a28.galaxy == "milky-way"));
		REQUIRE (bool(a28.solar_system == "solar-system"));
		REQUIRE (bool(a28.astronomical_body == "mimas"));
		aid a29(astronomical_body::ENCELADUS);
		REQUIRE (bool(a29.astronomical_type == aid::MOON));
		REQUIRE (bool(a29.universe == "universe"));
		REQUIRE (bool(a29.galaxy == "milky-way"));
		REQUIRE (bool(a29.solar_system == "solar-system"));
		REQUIRE (bool(a29.astronomical_body == "enceladus"));
		aid a30(astronomical_body::TETHYS);
		REQUIRE (bool(a30.astronomical_type == aid::MOON));
		REQUIRE (bool(a30.universe == "universe"));
		REQUIRE (bool(a30.galaxy == "milky-way"));
		REQUIRE (bool(a30.solar_system == "solar-system"));
		REQUIRE (bool(a30.astronomical_body == "tethys"));
		aid a31(astronomical_body::DIONE);
		REQUIRE (bool(a31.astronomical_type == aid::MOON));
		REQUIRE (bool(a31.universe == "universe"));
		REQUIRE (bool(a31.galaxy == "milky-way"));
		REQUIRE (bool(a31.solar_system == "solar-system"));
		REQUIRE (bool(a31.astronomical_body == "dione"));
		aid a32(astronomical_body::RHEA);
		REQUIRE (bool(a32.astronomical_type == aid::MOON));
		REQUIRE (bool(a32.universe == "universe"));
		REQUIRE (bool(a32.galaxy == "milky-way"));
		REQUIRE (bool(a32.solar_system == "solar-system"));
		REQUIRE (bool(a32.astronomical_body == "rhea"));
		aid a33(astronomical_body::TITAN);
		REQUIRE (bool(a33.astronomical_type == aid::MOON));
		REQUIRE (bool(a33.universe == "universe"));
		REQUIRE (bool(a33.galaxy == "milky-way"));
		REQUIRE (bool(a33.solar_system == "solar-system"));
		REQUIRE (bool(a33.astronomical_body == "titan"));
		aid a34(astronomical_body::IAPETUS);
		REQUIRE (bool(a34.astronomical_type == aid::MOON));
		REQUIRE (bool(a34.universe == "universe"));
		REQUIRE (bool(a34.galaxy == "milky-way"));
		REQUIRE (bool(a34.solar_system == "solar-system"));
		REQUIRE (bool(a34.astronomical_body == "iapetus"));
		aid a35(astronomical_body::MIRANDA);
		REQUIRE (bool(a35.astronomical_type == aid::MOON));
		REQUIRE (bool(a35.universe == "universe"));
		REQUIRE (bool(a35.galaxy == "milky-way"));
		REQUIRE (bool(a35.solar_system == "solar-system"));
		REQUIRE (bool(a35.astronomical_body == "miranda"));
		aid a36(astronomical_body::ARIEL);
		REQUIRE (bool(a36.astronomical_type == aid::MOON));
		REQUIRE (bool(a36.universe == "universe"));
		REQUIRE (bool(a36.galaxy == "milky-way"));
		REQUIRE (bool(a36.solar_system == "solar-system"));
		REQUIRE (bool(a36.astronomical_body == "ariel"));
		aid a37(astronomical_body::UMBRIEL);
		REQUIRE (bool(a37.astronomical_type == aid::MOON));
		REQUIRE (bool(a37.universe == "universe"));
		REQUIRE (bool(a37.galaxy == "milky-way"));
		REQUIRE (bool(a37.solar_system == "solar-system"));
		REQUIRE (bool(a37.astronomical_body == "umbriel"));
		aid a38(astronomical_body::TITANIA);
		REQUIRE (bool(a38.astronomical_type == aid::MOON));
		REQUIRE (bool(a38.universe == "universe"));
		REQUIRE (bool(a38.galaxy == "milky-way"));
		REQUIRE (bool(a38.solar_system == "solar-system"));
		REQUIRE (bool(a38.astronomical_body == "titania"));
		aid a39(astronomical_body::OBERON);
		REQUIRE (bool(a39.astronomical_type == aid::MOON));
		REQUIRE (bool(a39.universe == "universe"));
		REQUIRE (bool(a39.galaxy == "milky-way"));
		REQUIRE (bool(a39.solar_system == "solar-system"));
		REQUIRE (bool(a39.astronomical_body == "oberon"));
		aid a40(astronomical_body::TRITON);
		REQUIRE (bool(a40.astronomical_type == aid::MOON));
		REQUIRE (bool(a40.universe == "universe"));
		REQUIRE (bool(a40.galaxy == "milky-way"));
		REQUIRE (bool(a40.solar_system == "solar-system"));
		REQUIRE (bool(a40.astronomical_body == "triton"));
		aid a41(astronomical_body::CHARON);
		REQUIRE (bool(a41.astronomical_type == aid::MOON));
		REQUIRE (bool(a41.universe == "universe"));
		REQUIRE (bool(a41.galaxy == "milky-way"));
		REQUIRE (bool(a41.solar_system == "solar-system"));
		REQUIRE (bool(a41.astronomical_body == "charon"));
		aid a42(astronomical_body::DYSNOMIA);
		REQUIRE (bool(a42.astronomical_type == aid::MOON));
		REQUIRE (bool(a42.universe == "universe"));
		REQUIRE (bool(a42.galaxy == "milky-way"));
		REQUIRE (bool(a42.solar_system == "solar-system"));
		REQUIRE (bool(a42.astronomical_body == "dysnomia"));
	}

	SECTION("Assignments of aid class")
	{
		aid b;
		aid b2 = aid(aid::PLANET,"universe","milky-way","solar-system","earth");
		b = b2;
		REQUIRE (bool(b.astronomical_type == aid::PLANET));
		REQUIRE (bool(b.universe == "universe"));
		REQUIRE (bool(b.galaxy == "milky-way"));
		REQUIRE (bool(b.solar_system == "solar-system"));
		REQUIRE (bool(b.astronomical_body == "earth"));
		aid c;
		aid c2 = aid(aid::PLANET,"universe","milky-way","solar-system","earth");
		c = std::move(c2);
		REQUIRE (bool(c.astronomical_type == aid::PLANET));
		REQUIRE (bool(c.universe == "universe"));
		REQUIRE (bool(c.galaxy == "milky-way"));
		REQUIRE (bool(c.solar_system == "solar-system"));
		REQUIRE (bool(c.astronomical_body == "earth"));
		aid d;
		d = "(SS)universe:milky-way:solar-system";
		REQUIRE (bool(d.astronomical_type == aid::SOLAR_SYSTEM));
		REQUIRE (bool(d.universe == "universe"));
		REQUIRE (bool(d.galaxy == "milky-way"));
		REQUIRE (bool(d.solar_system == "solar-system"));
		REQUIRE (bool(d.astronomical_body == ""));
		aid e;
		e = "(P)universe:milky-way:solar-system:earth";
		REQUIRE (bool(e.astronomical_type == aid::PLANET));
		REQUIRE (bool(e.universe == "universe"));
		REQUIRE (bool(e.galaxy == "milky-way"));
		REQUIRE (bool(e.solar_system == "solar-system"));
		REQUIRE (bool(e.astronomical_body == "earth"));
		aid f;
		f = "(G)universe:milky-way";
		REQUIRE (bool(f.astronomical_type == aid::GALAXY));
		REQUIRE (bool(f.universe == "universe"));
		REQUIRE (bool(f.galaxy == "milky-way"));
		REQUIRE (bool(f.solar_system == ""));
		REQUIRE (bool(f.astronomical_body == ""));
	}

	SECTION("to_string() of aid class")
	{
		aid a("(SS)universe:milky-way:solar-system");
		REQUIRE (bool(to_string(a) == "(SS)universe:milky-way:solar-system"));
		aid b("(U)universe");
		REQUIRE (bool(to_string(b) == "(U)universe"));
		aid c("(G)universe:milky-way");
		REQUIRE (bool(to_string(c) == "(G)universe:milky-way"));
		aid d("(P)universe:milky-way:solar-system:mars");
		REQUIRE (bool(to_string(d) == "(P)universe:milky-way:solar-system:mars"));
		aid e;
		REQUIRE (bool(to_string(e) == ""));
	}

	SECTION("to_string() of aid::type")
	{
		REQUIRE (bool(to_string(aid::UNIVERSE) == "U"));
		REQUIRE (bool(to_string(aid::GALAXY) == "G"));
		REQUIRE (bool(to_string(aid::SOLAR_SYSTEM) == "SS"));
		REQUIRE (bool(to_string(aid::PLANET) == "P"));
		REQUIRE (bool(to_string(aid::STAR) == "ST"));
		REQUIRE (bool(to_string(aid::ASTEROID) == "A"));
		REQUIRE (bool(to_string(aid::MOON) == "MN"));
		REQUIRE (bool(to_string(aid::METEOR) == "MT"));
		REQUIRE (bool(to_string(aid::NONE) == ""));
	}

	SECTION("create_astronomical_type()")
	{
		REQUIRE (bool(create_astronomical_type("U") == aid::UNIVERSE));
		REQUIRE (bool(create_astronomical_type("G") == aid::GALAXY));
		REQUIRE (bool(create_astronomical_type("SS") == aid::SOLAR_SYSTEM));
		REQUIRE (bool(create_astronomical_type("P") == aid::PLANET));
		REQUIRE (bool(create_astronomical_type("ST") == aid::STAR));
		REQUIRE (bool(create_astronomical_type("A") == aid::ASTEROID));
		REQUIRE (bool(create_astronomical_type("MN") == aid::MOON));
		REQUIRE (bool(create_astronomical_type("MT") == aid::METEOR));
		REQUIRE (bool(create_astronomical_type("") == aid::NONE));
	}

	SECTION("Operators of aid class")
	{
		aid a("(G)universe:milky-way");
		aid b("(G)universe:milky-way");
		aid c("(G)universe:andromeda");
		REQUIRE (bool(a == b));
		REQUIRE (bool((a == c) == false));
		REQUIRE (bool(a != c));
	}

	SECTION("String operators of aid class")
	{
		REQUIRE (bool(aid("(SS)universe:milky-way:solar-system") == "(SS)universe:milky-way:solar-system"));
		REQUIRE (bool(aid("(SS)universe:milky-way:solar-system") != "(SS)universe:milky-way:alpha-centauri"));
		REQUIRE (bool("(SS)universe:milky-way:alpha-centauri" == aid("(SS)universe:milky-way:alpha-centauri")));
		REQUIRE (bool("(SS)universe:milky-way:alpha-centauri" != aid("(SS)universe:milky-way:solar-system")));
		string a = "aid ";
		a += aid("(SS)universe:milky-way:alpha-centauri");
		REQUIRE (bool(a == "aid (SS)universe:milky-way:alpha-centauri"));
		aid b = aid("(SS)universe:milky-way:alpha-centauri");
		REQUIRE (bool("b " + b == "b (SS)universe:milky-way:alpha-centauri"));
		REQUIRE (bool(b + " b" == "(SS)universe:milky-way:alpha-centauri b"));
	}

	SECTION("Streams of aid class")
	{
		ostringstream a;
        a << aid("(SS)universe:milky-way:alpha-centauri");
        REQUIRE (bool(a.str() == "(SS)universe:milky-way:alpha-centauri"));
        stringstream b;
        b << "(SS)universe:milky-way:alpha-centauri";
        aid b2;
        b >> b2;
        REQUIRE (bool(to_string(b2) == "(SS)universe:milky-way:alpha-centauri"));
	}
}