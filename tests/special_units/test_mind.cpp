#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../special_units/mind.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("mind functions") {
	SECTION("to_string() of alert_state") {
		CHECK(to_string(alert_state::VIGIL) == "VIGIL");
		CHECK(to_string(alert_state::SLEEP) == "SLEEP");
		CHECK(to_string(alert_state::MEDITATION) == "MEDITATION");
	}

	SECTION("to_string() of feeling") {
		CHECK(to_string(feeling::SADNESS) == "SADNESS");
		CHECK(to_string(feeling::RANCOR) == "RANCOR");
		CHECK(to_string(feeling::LOVE) == "LOVE");
	}

	SECTION("to_string() of emotion") {
		CHECK(to_string(emotion::HAPPY) == "HAPPY");
		CHECK(to_string(emotion::EXCITED) == "EXCITED");
		CHECK(to_string(emotion::TENDER) == "TENDER");
		CHECK(to_string(emotion::SCARED) == "SCARED");
		CHECK(to_string(emotion::ANGRY) == "ANGRY");
		CHECK(to_string(emotion::SAD) == "SAD");
	}

	SECTION("to_string() of sensation") {
		CHECK(to_string(sensation::LIGHT) == "LIGHT");
		CHECK(to_string(sensation::SOUND) == "SOUND");
		CHECK(to_string(sensation::ACCELERATION) == "ACCELERATION");
		CHECK(to_string(sensation::ODOR) == "ODOR");
		CHECK(to_string(sensation::TASTE) == "TASTE");
		CHECK(to_string(sensation::TOUCH) == "TOUCH");
		CHECK(to_string(sensation::TEMPERATURE) == "TEMPERATURE");
	}

	SECTION("to_string() of sense") {
		CHECK(to_string(sense::SIGHT) == "SIGHT");
		CHECK(to_string(sense::HEARING) == "HEARING");
		CHECK(to_string(sense::SMELL) == "SMELL");
		CHECK(to_string(sense::TOUCH) == "TOUCH");
		CHECK(to_string(sense::TASTE) == "TASTE");
		CHECK(to_string(sense::THERMOCEPTION) == "THERMOCEPTION");
		CHECK(to_string(sense::PROPRIOCEPTION) == "PROPRIOCEPTION");
	}

	SECTION("to_string() of conscience_state") {
		CHECK(to_string(conscience_state::NORMAL) == "NORMAL");
		CHECK(to_string(conscience_state::ALTERED) == "ALTERED");
	}
}