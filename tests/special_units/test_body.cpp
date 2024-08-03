#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../special_units/body.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("body functions") {
	SECTION("to_string() of movement") {
		CHECK(to_string(movement::STILL) == "STILL");
		CHECK(to_string(movement::WALK) == "WALK");
		CHECK(to_string(movement::RUN) == "RUN");
		CHECK(to_string(movement::SWIM) == "SWIM");
		CHECK(to_string(movement::CLIMB) == "CLIMB");
		CHECK(to_string(movement::FLY) == "FLY");
	}

	SECTION("to_string() of movement_state") {
		CHECK(to_string(movement_state::STILL) == "STILL");
		CHECK(to_string(movement_state::ACTIVE) == "ACTIVE");
	}

	SECTION("to_string() of body_health") {
		CHECK(to_string(body_health::HEALTHY) == "HEALTHY");
		CHECK(to_string(body_health::DAMAGED) == "DAMAGED");
		CHECK(to_string(body_health::SICK) == "SICK");
		CHECK(to_string(body_health::SICK_AND_DAMAGED) == "SICK_AND_DAMAGED");
	}
}