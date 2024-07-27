#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../trajectories/trajectory_3d.hpp"
#include "../../units/base_units.hpp"
#include "../../units/unit_abbreviation.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("trajectory_3d<T> class") {
	SECTION("Constructors of trajectory_3d class")
	{
		trajectory_3d<length> a([](float t) -> coordinates_3d<> { return coordinates_3d<>(length(t * 2,"m"),length(t + 5,"m"),length(2*t + 2,"m")); });
		CHECK(bool(a(0) == "(0 m,5 m,2 m)"));
		CHECK(bool(a(1) == "(2 m,6 m,4 m)"));
		CHECK(bool(a(2) == "(4 m,7 m,6 m)"));
    }
}