#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../fields/scalar_field_3d.hpp"
#include "../../units/unit_basic.hpp"
#include "../../units/unit_abbreviation.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("scalar_field_3d<T,U> class") {
	SECTION("Constructors of scalar_field_3d class")
	{
        scalar_field_3d<length,length> a;
		scalar_field_3d<length,length> d([](const length& x,const length& y,const length& z) -> length { return length(x); });
		CHECK(bool(d(2_m,0_m,1_m) == "2 m"));
		scalar_field_3d<length,length> e([](const length& x,const length& y,const length& z) -> length { return (x + y + 2*z); });
		CHECK(bool(e(2_m,1_m,3_m) == "9 m"));
		CHECK(bool(e(2_m,2_m,3_m) == "10 m"));
    }
}