#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../units/vector_unit_nd.hpp"
#include "../../units/unit_basic.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class vector_unit_nd","Complete test of vector_unit_nd")
{
	SECTION("Constructors of vector_unit_nd classes")
	{
		vector_unit_nd a;
		REQUIRE (bool(to_string(a) == "0 [empty]"));
		vector_unit_nd b = vector_unit_nd("100 g",{50,20,20});
		vector_unit_nd c = vector_unit_nd(b);
		REQUIRE (bool(to_string(c) == "100 g 50° 20° 20°"));
		vector_unit_nd d = vector_unit_nd(50,"m",{20,20,20});
		REQUIRE (bool(to_string(d) == "50 m 20° 20° 20°"));
		vector_unit_nd e = vector_unit_nd(50,"m",{angle(20.0f),angle(20.0f)});
		REQUIRE (bool(to_string(e) == "50 m 20° 20°"));
		vector_unit_nd f = vector_unit_nd(50,{dimension("m",dimension::POSITIVE)},{20,20,20});
		REQUIRE (bool(to_string(f) == "50 m 20° 20° 20°"));
		vector_unit_nd g = vector_unit_nd(50,{dimension("m",dimension::POSITIVE)},{angle(20.0f),angle(20.0f)});
		REQUIRE (bool(to_string(g) == "50 m 20° 20°"));
		scalar_unit h2 = scalar_unit("50 g");
		vector_unit_nd h = vector_unit_nd(h2,{20,20,20});
		REQUIRE (bool(to_string(h) == "50 g 20° 20° 20°"));
		vector_unit_nd i = vector_unit_nd(h2,{angle(20.0f),angle(20.0f)});
		REQUIRE (bool(to_string(i) == "50 g 20° 20°"));
		vector_unit_nd j("100 g",{24,24,24});
		REQUIRE (bool(to_string(j) == "100 g 24° 24° 24°"));
		vector_unit_nd k("100 g",{angle(24.0f),angle(24.0f)});
		REQUIRE (bool(to_string(k) == "100 g 24° 24°"));
		vector_unit_nd l("100 g 20 20 20");
		REQUIRE (bool(to_string(l) == "100 g 20° 20° 20°"));
		vector_unit_nd m("100 g 20° 20° 20° 20°");
		REQUIRE (bool(to_string(m) == "100 g 20° 20° 20° 20°"));
		vector_unit_nd n = vector_unit_nd::cartesian_2d("m",1,1);
		REQUIRE (bool(to_string(n) == "1.41 m 45°"));
		vector_unit_nd o = vector_unit_nd::cartesian_3d("m",1,1,1);
		REQUIRE (bool(to_string(o) == "1.73 m 45° 54.73°"));
		vector_unit_nd p = vector_unit_nd::cylindrical("m",1,angle(45.0f),1);
		REQUIRE (bool(to_string(p) == "1.41 m 45° 45°"));
	}

	SECTION("Display of vector_unit_nd classes")
	{
		vector_unit_nd a = vector_unit_nd(1,"N",{20,20,20,20});
		REQUIRE (bool(a.vectorial_display() == "1 N 20° 20° 20° 20°"));
		REQUIRE (bool(a.vectorial_derived_display() == "1 kg*m/s2 20° 20° 20° 20°"));
		REQUIRE (bool(a.vectorial_custom_display("g*m/s2") == "1000 g*m/s2 20° 20° 20° 20°"));
	}
}

