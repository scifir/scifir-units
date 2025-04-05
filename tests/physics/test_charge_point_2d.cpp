#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../physics/charge_point_2d.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("charge_point_2d<T> class") {
	SECTION("Constructors of charge_point_2d<T> class") {
		charge_point_2d<> a;
		CHECK(to_string(a.charge) == "0 C");
		CHECK(to_string(a.coordinates) == "(0 m,0 m)");
		charge_point_2d<> b(3_C,coordinates_2d<>(1_m,2_m));
		CHECK(to_string(b.charge) == "3 C");
		CHECK(to_string(b.coordinates) == "(1 m,2 m)");
	}

	SECTION("Comparison of charge_point_2d<T>") {
		charge_point_2d<> a(3_C,coordinates_2d<>(1_m,1_m));
		charge_point_2d<> b(3_C,coordinates_2d<>(3_m,3_m));
		charge_point_2d<> c(3_C,coordinates_2d<>(1_m,1_m));
		CHECK(bool(a == c));
		CHECK(bool(a != b));
	}

	SECTION("display() of charge_point_2d<T>") {
		charge_point_2d<> a(3_C,coordinates_2d<>(1_m,1_m));
		CHECK(a.display() == "3 C (1 m,1 m)");
	}
}