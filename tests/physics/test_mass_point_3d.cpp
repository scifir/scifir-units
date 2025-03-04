#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../physics/mass_point_3d.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("mass_point_3d<T> class") {
	SECTION("Constructors of mass_point_3d<T> class") {
		mass_point_3d<> a;
		REQUIRE(to_string(a.mass) == "0 g");
		REQUIRE(to_string(a.coordinates_3d) == "(0 m,0 m,0 m)");
		mass_point_3d<> b(3_g,coordinates_3d<>(1_m,2_m,1_m));
		REQUIRE(to_string(b.mass) == "3 g");
		REQUIRE(to_string(b.coordinates_3d) == "(1 m,2 m,1 m)");
	}

	SECTION("Addition of mass_point_3d<T>") {
		mass_point_3d<> a(3_g,coordinates_3d<>(1_m,1_m,1_m));
		mass_point_3d<> b(3_g,coordinates_3d<>(3_m,3_m,3_m));
		mass_point_3d<> c = a + b;
		REQUIRE(to_string(c.mass) == "6 g");
		REQUIRE(to_string(c.coordinates_3d) == "(2 m,2 m,2 m)");
	}

	SECTION("Comparison of mass_point_3d<T>") {
		mass_point_3d<> a(3_g,coordinates_3d<>(1_m,1_m,1_m));
		mass_point_3d<> b(3_g,coordinates_3d<>(3_m,3_m,3_m));
		mass_point_3d<> c(3_g,coordinates_3d<>(1_m,1_m,1_m));
		REQUIRE(bool(a == c));
		REQUIRE(bool(a != b));
	}
}