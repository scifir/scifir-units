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
		CHECK (bool(a.astronomical_type == aid::NONE));
		CHECK (bool(a.universe == ""));
		CHECK (bool(a.galaxy == ""));
		CHECK (bool(a.solar_system == ""));
		CHECK (bool(a.astronomical_body == ""));
		aid b2 = aid(aid::PLANET,"universe","milky-way","solar-system","earth");
		aid b(b2);
		CHECK (bool(b.astronomical_type == aid::PLANET));
		CHECK (bool(b.universe == "universe"));
		CHECK (bool(b.galaxy == "milky-way"));
		CHECK (bool(b.solar_system == "solar-system"));
		CHECK (bool(b.astronomical_body == "earth"));
		aid c2 = aid(aid::PLANET,"universe","milky-way","solar-system","earth");
		aid c(std::move(c2));
		CHECK (bool(c.astronomical_type == aid::PLANET));
		CHECK (bool(c.universe == "universe"));
		CHECK (bool(c.galaxy == "milky-way"));
		CHECK (bool(c.solar_system == "solar-system"));
		CHECK (bool(c.astronomical_body == "earth"));
		aid d("universe","milky-way");
		CHECK (bool(d.astronomical_type == aid::GALAXY));
		CHECK (bool(d.universe == "universe"));
		CHECK (bool(d.galaxy == "milky-way"));
		CHECK (bool(d.solar_system == ""));
		CHECK (bool(d.astronomical_body == ""));
		aid e("universe","milky-way","solar-system");
		CHECK (bool(e.astronomical_type == aid::SOLAR_SYSTEM));
		CHECK (bool(e.universe == "universe"));
		CHECK (bool(e.galaxy == "milky-way"));
		CHECK (bool(e.solar_system == "solar-system"));
		CHECK (bool(e.astronomical_body == ""));
		aid f(aid::PLANET,"universe","milky-way","solar-system","earth");
		CHECK (bool(f.astronomical_type == aid::PLANET));
		CHECK (bool(f.universe == "universe"));
		CHECK (bool(f.galaxy == "milky-way"));
		CHECK (bool(f.solar_system == "solar-system"));
		CHECK (bool(f.astronomical_body == "earth"));
		aid g("(P)universe:milky-way:solar-system:earth");
		CHECK (bool(g.astronomical_type == aid::PLANET));
		CHECK (bool(g.universe == "universe"));
		CHECK (bool(g.galaxy == "milky-way"));
		CHECK (bool(g.solar_system == "solar-system"));
		CHECK (bool(g.astronomical_body == "earth"));
		aid h("(G)universe:milky-way");
		CHECK (bool(h.astronomical_type == aid::GALAXY));
		CHECK (bool(h.universe == "universe"));
		CHECK (bool(h.galaxy == "milky-way"));
		CHECK (bool(h.solar_system == ""));
		CHECK (bool(h.astronomical_body == ""));
		aid i("(SS)universe:milky-way:solar-system");
		CHECK (bool(i.astronomical_type == aid::SOLAR_SYSTEM));
		CHECK (bool(i.universe == "universe"));
		CHECK (bool(i.galaxy == "milky-way"));
		CHECK (bool(i.solar_system == "solar-system"));
		CHECK (bool(i.astronomical_body == ""));
		aid j("");
		CHECK (bool(j.astronomical_type == aid::NONE));
		CHECK (bool(j.universe == ""));
		CHECK (bool(j.galaxy == ""));
		CHECK (bool(j.solar_system == ""));
		CHECK (bool(j.astronomical_body == ""));
	}

	SECTION("Constructors of aid class that use the enum astronomical_body")
	{
		aid a(astronomical_body::NONE);
		CHECK (bool(a.astronomical_type == aid::NONE));
		CHECK (bool(a.universe == ""));
		CHECK (bool(a.galaxy == ""));
		CHECK (bool(a.solar_system == ""));
		CHECK (bool(a.astronomical_body == ""));
		aid a2(astronomical_body::MILKY_WAY);
		CHECK (bool(a2.astronomical_type == aid::GALAXY));
		CHECK (bool(a2.universe == "universe"));
		CHECK (bool(a2.galaxy == "milky-way"));
		CHECK (bool(a2.solar_system == ""));
		CHECK (bool(a2.astronomical_body == ""));
		aid a3(astronomical_body::ANDROMEDA);
		CHECK (bool(a3.astronomical_type == aid::GALAXY));
		CHECK (bool(a3.universe == "universe"));
		CHECK (bool(a3.galaxy == "andromeda"));
		CHECK (bool(a3.solar_system == ""));
		CHECK (bool(a3.astronomical_body == ""));
		aid a4(astronomical_body::SOLAR_SYSTEM);
		CHECK (bool(a4.astronomical_type == aid::SOLAR_SYSTEM));
		CHECK (bool(a4.universe == "universe"));
		CHECK (bool(a4.galaxy == "milky-way"));
		CHECK (bool(a4.solar_system == "solar-system"));
		CHECK (bool(a4.astronomical_body == ""));
		aid a5(astronomical_body::SUN);
		CHECK (bool(a5.astronomical_type == aid::STAR));
		CHECK (bool(a5.universe == "universe"));
		CHECK (bool(a5.galaxy == "milky-way"));
		CHECK (bool(a5.solar_system == "solar-system"));
		CHECK (bool(a5.astronomical_body == "sun"));
		aid a6(astronomical_body::MOON);
		CHECK (bool(a6.astronomical_type == aid::MOON));
		CHECK (bool(a6.universe == "universe"));
		CHECK (bool(a6.galaxy == "milky-way"));
		CHECK (bool(a6.solar_system == "solar-system"));
		CHECK (bool(a6.astronomical_body == "moon"));
		aid a7(astronomical_body::MERCURY);
		CHECK (bool(a7.astronomical_type == aid::PLANET));
		CHECK (bool(a7.universe == "universe"));
		CHECK (bool(a7.galaxy == "milky-way"));
		CHECK (bool(a7.solar_system == "solar-system"));
		CHECK (bool(a7.astronomical_body == "mercury"));
		aid a8(astronomical_body::VENUS);
		CHECK (bool(a8.astronomical_type == aid::PLANET));
		CHECK (bool(a8.universe == "universe"));
		CHECK (bool(a8.galaxy == "milky-way"));
		CHECK (bool(a8.solar_system == "solar-system"));
		CHECK (bool(a8.astronomical_body == "venus"));
		aid a9(astronomical_body::EARTH);
		CHECK (bool(a9.astronomical_type == aid::PLANET));
		CHECK (bool(a9.universe == "universe"));
		CHECK (bool(a9.galaxy == "milky-way"));
		CHECK (bool(a9.solar_system == "solar-system"));
		CHECK (bool(a9.astronomical_body == "earth"));
		aid a10(astronomical_body::MARS);
		CHECK (bool(a10.astronomical_type == aid::PLANET));
		CHECK (bool(a10.universe == "universe"));
		CHECK (bool(a10.galaxy == "milky-way"));
		CHECK (bool(a10.solar_system == "solar-system"));
		CHECK (bool(a10.astronomical_body == "mars"));
		aid a11(astronomical_body::JUPITER);
		CHECK (bool(a11.astronomical_type == aid::PLANET));
		CHECK (bool(a11.universe == "universe"));
		CHECK (bool(a11.galaxy == "milky-way"));
		CHECK (bool(a11.solar_system == "solar-system"));
		CHECK (bool(a11.astronomical_body == "jupiter"));
		aid a12(astronomical_body::SATURN);
		CHECK (bool(a12.astronomical_type == aid::PLANET));
		CHECK (bool(a12.universe == "universe"));
		CHECK (bool(a12.galaxy == "milky-way"));
		CHECK (bool(a12.solar_system == "solar-system"));
		CHECK (bool(a12.astronomical_body == "saturn"));
		aid a13(astronomical_body::URANUS);
		CHECK (bool(a13.astronomical_type == aid::PLANET));
		CHECK (bool(a13.universe == "universe"));
		CHECK (bool(a13.galaxy == "milky-way"));
		CHECK (bool(a13.solar_system == "solar-system"));
		CHECK (bool(a13.astronomical_body == "uranus"));
		aid a14(astronomical_body::NEPTUNE);
		CHECK (bool(a14.astronomical_type == aid::PLANET));
		CHECK (bool(a14.universe == "universe"));
		CHECK (bool(a14.galaxy == "milky-way"));
		CHECK (bool(a14.solar_system == "solar-system"));
		CHECK (bool(a14.astronomical_body == "neptune"));
		aid a15(astronomical_body::CERES);
		CHECK (bool(a15.astronomical_type == aid::PLANET));
		CHECK (bool(a15.universe == "universe"));
		CHECK (bool(a15.galaxy == "milky-way"));
		CHECK (bool(a15.solar_system == "solar-system"));
		CHECK (bool(a15.astronomical_body == "ceres"));
		aid a16(astronomical_body::ORCUS);
		CHECK (bool(a16.astronomical_type == aid::PLANET));
		CHECK (bool(a16.universe == "universe"));
		CHECK (bool(a16.galaxy == "milky-way"));
		CHECK (bool(a16.solar_system == "solar-system"));
		CHECK (bool(a16.astronomical_body == "orcus"));
		aid a17(astronomical_body::PLUTO);
		CHECK (bool(a17.astronomical_type == aid::PLANET));
		CHECK (bool(a17.universe == "universe"));
		CHECK (bool(a17.galaxy == "milky-way"));
		CHECK (bool(a17.solar_system == "solar-system"));
		CHECK (bool(a17.astronomical_body == "pluto"));
		aid a18(astronomical_body::HAUMEA);
		CHECK (bool(a18.astronomical_type == aid::PLANET));
		CHECK (bool(a18.universe == "universe"));
		CHECK (bool(a18.galaxy == "milky-way"));
		CHECK (bool(a18.solar_system == "solar-system"));
		CHECK (bool(a18.astronomical_body == "haumea"));
		aid a19(astronomical_body::QUAOAR);
		CHECK (bool(a19.astronomical_type == aid::PLANET));
		CHECK (bool(a19.universe == "universe"));
		CHECK (bool(a19.galaxy == "milky-way"));
		CHECK (bool(a19.solar_system == "solar-system"));
		CHECK (bool(a19.astronomical_body == "quaoar"));
		aid a20(astronomical_body::MAKEMAKE);
		CHECK (bool(a20.astronomical_type == aid::PLANET));
		CHECK (bool(a20.universe == "universe"));
		CHECK (bool(a20.galaxy == "milky-way"));
		CHECK (bool(a20.solar_system == "solar-system"));
		CHECK (bool(a20.astronomical_body == "makemake"));
		aid a21(astronomical_body::GONGGONG);
		CHECK (bool(a21.astronomical_type == aid::PLANET));
		CHECK (bool(a21.universe == "universe"));
		CHECK (bool(a21.galaxy == "milky-way"));
		CHECK (bool(a21.solar_system == "solar-system"));
		CHECK (bool(a21.astronomical_body == "gonggong"));
		aid a22(astronomical_body::ERIS);
		CHECK (bool(a22.astronomical_type == aid::PLANET));
		CHECK (bool(a22.universe == "universe"));
		CHECK (bool(a22.galaxy == "milky-way"));
		CHECK (bool(a22.solar_system == "solar-system"));
		CHECK (bool(a22.astronomical_body == "eris"));
		aid a23(astronomical_body::SEDNA);
		CHECK (bool(a23.astronomical_type == aid::PLANET));
		CHECK (bool(a23.universe == "universe"));
		CHECK (bool(a23.galaxy == "milky-way"));
		CHECK (bool(a23.solar_system == "solar-system"));
		CHECK (bool(a23.astronomical_body == "sedna"));
		aid a24(astronomical_body::IO);
		CHECK (bool(a24.astronomical_type == aid::MOON));
		CHECK (bool(a24.universe == "universe"));
		CHECK (bool(a24.galaxy == "milky-way"));
		CHECK (bool(a24.solar_system == "solar-system"));
		CHECK (bool(a24.astronomical_body == "io"));
		aid a25(astronomical_body::EUROPA);
		CHECK (bool(a25.astronomical_type == aid::MOON));
		CHECK (bool(a25.universe == "universe"));
		CHECK (bool(a25.galaxy == "milky-way"));
		CHECK (bool(a25.solar_system == "solar-system"));
		CHECK (bool(a25.astronomical_body == "europa"));
		aid a26(astronomical_body::GANYMEDE);
		CHECK (bool(a26.astronomical_type == aid::MOON));
		CHECK (bool(a26.universe == "universe"));
		CHECK (bool(a26.galaxy == "milky-way"));
		CHECK (bool(a26.solar_system == "solar-system"));
		CHECK (bool(a26.astronomical_body == "ganymede"));
		aid a27(astronomical_body::CALLISTO);
		CHECK (bool(a27.astronomical_type == aid::MOON));
		CHECK (bool(a27.universe == "universe"));
		CHECK (bool(a27.galaxy == "milky-way"));
		CHECK (bool(a27.solar_system == "solar-system"));
		CHECK (bool(a27.astronomical_body == "callisto"));
		aid a28(astronomical_body::MIMAS);
		CHECK (bool(a28.astronomical_type == aid::MOON));
		CHECK (bool(a28.universe == "universe"));
		CHECK (bool(a28.galaxy == "milky-way"));
		CHECK (bool(a28.solar_system == "solar-system"));
		CHECK (bool(a28.astronomical_body == "mimas"));
		aid a29(astronomical_body::ENCELADUS);
		CHECK (bool(a29.astronomical_type == aid::MOON));
		CHECK (bool(a29.universe == "universe"));
		CHECK (bool(a29.galaxy == "milky-way"));
		CHECK (bool(a29.solar_system == "solar-system"));
		CHECK (bool(a29.astronomical_body == "enceladus"));
		aid a30(astronomical_body::TETHYS);
		CHECK (bool(a30.astronomical_type == aid::MOON));
		CHECK (bool(a30.universe == "universe"));
		CHECK (bool(a30.galaxy == "milky-way"));
		CHECK (bool(a30.solar_system == "solar-system"));
		CHECK (bool(a30.astronomical_body == "tethys"));
		aid a31(astronomical_body::DIONE);
		CHECK (bool(a31.astronomical_type == aid::MOON));
		CHECK (bool(a31.universe == "universe"));
		CHECK (bool(a31.galaxy == "milky-way"));
		CHECK (bool(a31.solar_system == "solar-system"));
		CHECK (bool(a31.astronomical_body == "dione"));
		aid a32(astronomical_body::RHEA);
		CHECK (bool(a32.astronomical_type == aid::MOON));
		CHECK (bool(a32.universe == "universe"));
		CHECK (bool(a32.galaxy == "milky-way"));
		CHECK (bool(a32.solar_system == "solar-system"));
		CHECK (bool(a32.astronomical_body == "rhea"));
		aid a33(astronomical_body::TITAN);
		CHECK (bool(a33.astronomical_type == aid::MOON));
		CHECK (bool(a33.universe == "universe"));
		CHECK (bool(a33.galaxy == "milky-way"));
		CHECK (bool(a33.solar_system == "solar-system"));
		CHECK (bool(a33.astronomical_body == "titan"));
		aid a34(astronomical_body::IAPETUS);
		CHECK (bool(a34.astronomical_type == aid::MOON));
		CHECK (bool(a34.universe == "universe"));
		CHECK (bool(a34.galaxy == "milky-way"));
		CHECK (bool(a34.solar_system == "solar-system"));
		CHECK (bool(a34.astronomical_body == "iapetus"));
		aid a35(astronomical_body::MIRANDA);
		CHECK (bool(a35.astronomical_type == aid::MOON));
		CHECK (bool(a35.universe == "universe"));
		CHECK (bool(a35.galaxy == "milky-way"));
		CHECK (bool(a35.solar_system == "solar-system"));
		CHECK (bool(a35.astronomical_body == "miranda"));
		aid a36(astronomical_body::ARIEL);
		CHECK (bool(a36.astronomical_type == aid::MOON));
		CHECK (bool(a36.universe == "universe"));
		CHECK (bool(a36.galaxy == "milky-way"));
		CHECK (bool(a36.solar_system == "solar-system"));
		CHECK (bool(a36.astronomical_body == "ariel"));
		aid a37(astronomical_body::UMBRIEL);
		CHECK (bool(a37.astronomical_type == aid::MOON));
		CHECK (bool(a37.universe == "universe"));
		CHECK (bool(a37.galaxy == "milky-way"));
		CHECK (bool(a37.solar_system == "solar-system"));
		CHECK (bool(a37.astronomical_body == "umbriel"));
		aid a38(astronomical_body::TITANIA);
		CHECK (bool(a38.astronomical_type == aid::MOON));
		CHECK (bool(a38.universe == "universe"));
		CHECK (bool(a38.galaxy == "milky-way"));
		CHECK (bool(a38.solar_system == "solar-system"));
		CHECK (bool(a38.astronomical_body == "titania"));
		aid a39(astronomical_body::OBERON);
		CHECK (bool(a39.astronomical_type == aid::MOON));
		CHECK (bool(a39.universe == "universe"));
		CHECK (bool(a39.galaxy == "milky-way"));
		CHECK (bool(a39.solar_system == "solar-system"));
		CHECK (bool(a39.astronomical_body == "oberon"));
		aid a40(astronomical_body::TRITON);
		CHECK (bool(a40.astronomical_type == aid::MOON));
		CHECK (bool(a40.universe == "universe"));
		CHECK (bool(a40.galaxy == "milky-way"));
		CHECK (bool(a40.solar_system == "solar-system"));
		CHECK (bool(a40.astronomical_body == "triton"));
		aid a41(astronomical_body::CHARON);
		CHECK (bool(a41.astronomical_type == aid::MOON));
		CHECK (bool(a41.universe == "universe"));
		CHECK (bool(a41.galaxy == "milky-way"));
		CHECK (bool(a41.solar_system == "solar-system"));
		CHECK (bool(a41.astronomical_body == "charon"));
		aid a42(astronomical_body::DYSNOMIA);
		CHECK (bool(a42.astronomical_type == aid::MOON));
		CHECK (bool(a42.universe == "universe"));
		CHECK (bool(a42.galaxy == "milky-way"));
		CHECK (bool(a42.solar_system == "solar-system"));
		CHECK (bool(a42.astronomical_body == "dysnomia"));
	}

	SECTION("Assignments of aid class")
	{
		aid b;
		aid b2 = aid(aid::PLANET,"universe","milky-way","solar-system","earth");
		b = b2;
		CHECK (bool(b.astronomical_type == aid::PLANET));
		CHECK (bool(b.universe == "universe"));
		CHECK (bool(b.galaxy == "milky-way"));
		CHECK (bool(b.solar_system == "solar-system"));
		CHECK (bool(b.astronomical_body == "earth"));
		aid c;
		aid c2 = aid(aid::PLANET,"universe","milky-way","solar-system","earth");
		c = std::move(c2);
		CHECK (bool(c.astronomical_type == aid::PLANET));
		CHECK (bool(c.universe == "universe"));
		CHECK (bool(c.galaxy == "milky-way"));
		CHECK (bool(c.solar_system == "solar-system"));
		CHECK (bool(c.astronomical_body == "earth"));
		aid d;
		d = "(SS)universe:milky-way:solar-system";
		CHECK (bool(d.astronomical_type == aid::SOLAR_SYSTEM));
		CHECK (bool(d.universe == "universe"));
		CHECK (bool(d.galaxy == "milky-way"));
		CHECK (bool(d.solar_system == "solar-system"));
		CHECK (bool(d.astronomical_body == ""));
		aid e;
		e = "(P)universe:milky-way:solar-system:earth";
		CHECK (bool(e.astronomical_type == aid::PLANET));
		CHECK (bool(e.universe == "universe"));
		CHECK (bool(e.galaxy == "milky-way"));
		CHECK (bool(e.solar_system == "solar-system"));
		CHECK (bool(e.astronomical_body == "earth"));
		aid f;
		f = "(G)universe:milky-way";
		CHECK (bool(f.astronomical_type == aid::GALAXY));
		CHECK (bool(f.universe == "universe"));
		CHECK (bool(f.galaxy == "milky-way"));
		CHECK (bool(f.solar_system == ""));
		CHECK (bool(f.astronomical_body == ""));
	}

	SECTION("to_string() of aid class")
	{
		aid a("(SS)universe:milky-way:solar-system");
		CHECK (bool(to_string(a) == "(SS)universe:milky-way:solar-system"));
		aid b("(U)universe");
		CHECK (bool(to_string(b) == "(U)universe"));
		aid c("(G)universe:milky-way");
		CHECK (bool(to_string(c) == "(G)universe:milky-way"));
		aid d("(P)universe:milky-way:solar-system:mars");
		CHECK (bool(to_string(d) == "(P)universe:milky-way:solar-system:mars"));
		aid e;
		CHECK (bool(to_string(e) == ""));
	}

	SECTION("to_string() of aid::type")
	{
		CHECK (bool(to_string(aid::UNIVERSE) == "U"));
		CHECK (bool(to_string(aid::GALAXY) == "G"));
		CHECK (bool(to_string(aid::SOLAR_SYSTEM) == "SS"));
		CHECK (bool(to_string(aid::PLANET) == "P"));
		CHECK (bool(to_string(aid::STAR) == "ST"));
		CHECK (bool(to_string(aid::ASTEROID) == "A"));
		CHECK (bool(to_string(aid::MOON) == "MN"));
		CHECK (bool(to_string(aid::METEOR) == "MT"));
		CHECK (bool(to_string(aid::NONE) == ""));
	}

	SECTION("create_astronomical_type()")
	{
		CHECK (bool(create_astronomical_type("U") == aid::UNIVERSE));
		CHECK (bool(create_astronomical_type("G") == aid::GALAXY));
		CHECK (bool(create_astronomical_type("SS") == aid::SOLAR_SYSTEM));
		CHECK (bool(create_astronomical_type("P") == aid::PLANET));
		CHECK (bool(create_astronomical_type("ST") == aid::STAR));
		CHECK (bool(create_astronomical_type("A") == aid::ASTEROID));
		CHECK (bool(create_astronomical_type("MN") == aid::MOON));
		CHECK (bool(create_astronomical_type("MT") == aid::METEOR));
		CHECK (bool(create_astronomical_type("") == aid::NONE));
	}

	SECTION("Operators of aid class")
	{
		aid a("(G)universe:milky-way");
		aid b("(G)universe:milky-way");
		aid c("(G)universe:andromeda");
		CHECK (bool(a == b));
		CHECK (bool((a == c) == false));
		CHECK (bool(a != c));
	}

	SECTION("String operators of aid class")
	{
		CHECK (bool(aid("(SS)universe:milky-way:solar-system") == "(SS)universe:milky-way:solar-system"));
		CHECK (bool(aid("(SS)universe:milky-way:solar-system") != "(SS)universe:milky-way:alpha-centauri"));
		CHECK (bool("(SS)universe:milky-way:alpha-centauri" == aid("(SS)universe:milky-way:alpha-centauri")));
		CHECK (bool("(SS)universe:milky-way:alpha-centauri" != aid("(SS)universe:milky-way:solar-system")));
		string a = "aid ";
		a += aid("(SS)universe:milky-way:alpha-centauri");
		CHECK (bool(a == "aid (SS)universe:milky-way:alpha-centauri"));
		aid b = aid("(SS)universe:milky-way:alpha-centauri");
		CHECK (bool("b " + b == "b (SS)universe:milky-way:alpha-centauri"));
		CHECK (bool(b + " b" == "(SS)universe:milky-way:alpha-centauri b"));
	}

	SECTION("Streams of aid class")
	{
		ostringstream a;
        a << aid("(SS)universe:milky-way:alpha-centauri");
        CHECK (bool(a.str() == "(SS)universe:milky-way:alpha-centauri"));
        stringstream b;
        b << "(SS)universe:milky-way:alpha-centauri";
        aid b2;
        b >> b2;
        CHECK (bool(to_string(b2) == "(SS)universe:milky-way:alpha-centauri"));
	}
}