#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../coordinates/address.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("address class") {
	SECTION("Constructors of address class")
	{
		address a;
		CHECK(a.zid.zone_type == zid::NONE);
		CHECK(a.location == "");
		CHECK(a.inner_location == "");
		CHECK(a.postal_code == "");
		aid b3(astronomical_body::EARTH);
		zid b4(b3,zid::COUNTRY,"chile");
		address b2(b4,"Street 1","","0857109321");
		address b(b2);
		CHECK(b.zid.zone_type == zid::COUNTRY);
		CHECK(b.location == "Street 1");
		CHECK(b.inner_location == "");
		CHECK(b.postal_code == "0857109321");
		aid c3(astronomical_body::EARTH);
		zid c4(c3,zid::COUNTRY,"chile");
		address c2(c4,"Street 1","Door 4","0857109321");
		address c(std::move(c2));
		CHECK(c.zid.zone_type == zid::COUNTRY);
		CHECK(c.location == "Street 1");
		CHECK(c.inner_location == "Door 4");
		CHECK(c.postal_code == "0857109321");
		aid d3(astronomical_body::EARTH);
		zid d4(d3,zid::COUNTRY,"chile");
		address d(d4,"Street 1","Door 4","0857109321");
		CHECK(d.zid.zone_type == zid::COUNTRY);
		CHECK(d.location == "Street 1");
		CHECK(d.inner_location == "Door 4");
		CHECK(d.postal_code == "0857109321");
	}

	SECTION("Display of address class")
	{
		aid a3(astronomical_body::EARTH);
		zid a4(a3,zid::COUNTRY,"chile");
		address a(a4,"Street 1","Door 4","0857109321");
		CHECK(a.display() == "(P) milky-way:solar-system:earth (C) chile, Street 1 Door 4");
	}

	SECTION("Streams of address class")
	{
		ostringstream a;
		aid a3(astronomical_body::EARTH);
		zid a4(a3,zid::COUNTRY,"chile");
        a << address(a4,"Street 1","Door 4","0857109321");
        CHECK(a.str() == "(P) milky-way:solar-system:earth (C) chile, Street 1 Door 4");
	}
}