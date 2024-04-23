#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "../../coordinates/coordinates_ndr.hpp"

#include <iostream>

using namespace std;
using namespace scifir;

TEST_CASE("class coordinates_ndr","Complete test of coordinates_ndr")
{
	SECTION("Constructors of coordinates_ndr classes")
	{
		coordinates_ndr<> a;
		//cout << "a: " << a << endl;
	}

	SECTION("Operations of coordinates_ndr classes")
	{
		
	}

	SECTION("Display of coordinates_ndr classes")
	{
		
	}
}

