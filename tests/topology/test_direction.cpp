#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../topology/direction.hpp"
#include "../../util/types.hpp"

using namespace std;
using namespace scifir;

TEST_CASE("class direction")
{
	SECTION("Constructors of direction class")
	{
		direction a;
		CHECK(to_string(a) == "");
		direction b2(direction::RIGHT);
		direction b(b2);
		CHECK(to_string(b) == "right");
		direction c2(direction::RIGHT);
		direction c(std::move(c2));
		CHECK(to_string(c) == "right");
		direction d(direction::TOP);
		CHECK(to_string(d) == "top");
		direction e("bottom");
		CHECK(to_string(e) == "bottom");
	}

	SECTION("Assignments of direction class")
	{
		direction a;
		direction a2(direction::BOTTOM);
		a = a2;
		CHECK(to_string(a) == "bottom");
		direction b;
		direction b2(direction::LEFT_TOP);
		b = std::move(b2);
		CHECK(to_string(b) == "left-top");
		direction c;
		c = direction::RIGHT;
		CHECK(to_string(c) == "right");
	}

	SECTION("invert() function of direction class")
	{
		direction a(direction::RIGHT_TOP);
		a.invert();
		CHECK(to_string(a) == "left-bottom");
	}

	SECTION("to_string() function of direction::name enum")
	{
		CHECK(to_string(direction::NONE) == "");
		CHECK(to_string(direction::LEFT) == "left");
		CHECK(to_string(direction::RIGHT) == "right");
		CHECK(to_string(direction::TOP) == "top");
		CHECK(to_string(direction::BOTTOM) == "bottom");
		CHECK(to_string(direction::FRONT) == "front");
		CHECK(to_string(direction::BACK) == "back");
		CHECK(to_string(direction::LEFT_TOP) == "left-top");
		CHECK(to_string(direction::LEFT_BOTTOM) == "left-bottom");
		CHECK(to_string(direction::RIGHT_TOP) == "right-top");
		CHECK(to_string(direction::RIGHT_BOTTOM) == "right-bottom");
		CHECK(to_string(direction::LEFT_FRONT) == "left-front");
		CHECK(to_string(direction::LEFT_BACK) == "left-back");
		CHECK(to_string(direction::RIGHT_FRONT) == "right-front");
		CHECK(to_string(direction::RIGHT_BACK) == "right-back");
		CHECK(to_string(direction::TOP_FRONT) == "top-front");
		CHECK(to_string(direction::TOP_BACK) == "top-back");
		CHECK(to_string(direction::BOTTOM_FRONT) == "bottom-front");
		CHECK(to_string(direction::BOTTOM_BACK) == "bottom-back");
		CHECK(to_string(direction::LEFT_TOP_FRONT) == "left-top-front");
		CHECK(to_string(direction::LEFT_TOP_BACK) == "left-top-back");
		CHECK(to_string(direction::LEFT_BOTTOM_FRONT) == "left-bottom-front");
		CHECK(to_string(direction::LEFT_BOTTOM_BACK) == "left-bottom-back");
		CHECK(to_string(direction::RIGHT_TOP_FRONT) == "right-top-front");
		CHECK(to_string(direction::RIGHT_TOP_BACK) == "right-top-back");
		CHECK(to_string(direction::RIGHT_BOTTOM_FRONT) == "right-bottom-front");
		CHECK(to_string(direction::RIGHT_BOTTOM_BACK) == "right-bottom-back");
	}

	SECTION("to_string() function of direction class")
	{
		direction a(direction::BOTTOM);
		CHECK(to_string(a) == "bottom");
	}

	SECTION("create_direction() function of direction::name enum")
	{
		CHECK(create_direction("") == direction::NONE);
		CHECK(create_direction("afadw") == direction::NONE);
		CHECK(create_direction("left") == direction::LEFT);
		CHECK(create_direction("right") == direction::RIGHT);
		CHECK(create_direction("top") == direction::TOP);
		CHECK(create_direction("bottom") == direction::BOTTOM);
		CHECK(create_direction("front") == direction::FRONT);
		CHECK(create_direction("back") == direction::BACK);
		CHECK(create_direction("left-top") == direction::LEFT_TOP);
		CHECK(create_direction("left-bottom") == direction::LEFT_BOTTOM);
		CHECK(create_direction("right-top") == direction::RIGHT_TOP);
		CHECK(create_direction("right-bottom") == direction::RIGHT_BOTTOM);
		CHECK(create_direction("left-front") == direction::LEFT_FRONT);
		CHECK(create_direction("left-back") == direction::LEFT_BACK);
		CHECK(create_direction("right-front") == direction::RIGHT_FRONT);
		CHECK(create_direction("right-back") == direction::RIGHT_BACK);
		CHECK(create_direction("top-front") == direction::TOP_FRONT);
		CHECK(create_direction("top-back") == direction::TOP_BACK);
		CHECK(create_direction("bottom-front") == direction::BOTTOM_FRONT);
		CHECK(create_direction("bottom-back") == direction::BOTTOM_BACK);
		CHECK(create_direction("left-top-front") == direction::LEFT_TOP_FRONT);
		CHECK(create_direction("left-top-back") == direction::LEFT_TOP_BACK);
		CHECK(create_direction("left-bottom-front") == direction::LEFT_BOTTOM_FRONT);
		CHECK(create_direction("left-bottom-back") == direction::LEFT_BOTTOM_BACK);
		CHECK(create_direction("right-top-front") == direction::RIGHT_TOP_FRONT);
		CHECK(create_direction("right-top-back") == direction::RIGHT_TOP_BACK);
		CHECK(create_direction("right-bottom-front") == direction::RIGHT_BOTTOM_FRONT);
		CHECK(create_direction("right-bottom-back") == direction::RIGHT_BOTTOM_BACK);
	}

	SECTION("invert() function of direction::name enum")
	{
		CHECK(invert(direction::NONE) == direction::NONE);
		CHECK(invert(direction::LEFT) == direction::RIGHT);
		CHECK(invert(direction::RIGHT) == direction::LEFT);
		CHECK(invert(direction::TOP) == direction::BOTTOM);
		CHECK(invert(direction::BOTTOM) == direction::TOP);
		CHECK(invert(direction::FRONT) == direction::BACK);
		CHECK(invert(direction::BACK) == direction::FRONT);
		CHECK(invert(direction::LEFT_TOP) == direction::RIGHT_BOTTOM);
		CHECK(invert(direction::LEFT_BOTTOM) == direction::RIGHT_TOP);
		CHECK(invert(direction::RIGHT_TOP) == direction::LEFT_BOTTOM);
		CHECK(invert(direction::RIGHT_BOTTOM) == direction::LEFT_TOP);
		CHECK(invert(direction::LEFT_FRONT) == direction::RIGHT_BACK);
		CHECK(invert(direction::LEFT_BACK) == direction::RIGHT_FRONT);
		CHECK(invert(direction::RIGHT_FRONT) == direction::LEFT_BACK);
		CHECK(invert(direction::RIGHT_BACK) == direction::LEFT_FRONT);
		CHECK(invert(direction::TOP_FRONT) == direction::BOTTOM_BACK);
		CHECK(invert(direction::TOP_BACK) == direction::BOTTOM_FRONT);
		CHECK(invert(direction::BOTTOM_FRONT) == direction::TOP_BACK);
		CHECK(invert(direction::BOTTOM_BACK) == direction::TOP_FRONT);
		CHECK(invert(direction::LEFT_TOP_FRONT) == direction::RIGHT_BOTTOM_BACK);
		CHECK(invert(direction::LEFT_TOP_BACK) == direction::RIGHT_BOTTOM_FRONT);
		CHECK(invert(direction::LEFT_BOTTOM_FRONT) == direction::RIGHT_TOP_BACK);
		CHECK(invert(direction::LEFT_BOTTOM_BACK) == direction::RIGHT_TOP_FRONT);
		CHECK(invert(direction::RIGHT_TOP_FRONT) == direction::LEFT_BOTTOM_BACK);
		CHECK(invert(direction::RIGHT_TOP_BACK) == direction::LEFT_BOTTOM_FRONT);
		CHECK(invert(direction::RIGHT_BOTTOM_FRONT) == direction::LEFT_TOP_BACK);
		CHECK(invert(direction::RIGHT_BOTTOM_BACK) == direction::LEFT_TOP_FRONT);
	}

	SECTION("Relational operators of direction class")
	{
		direction a(direction::LEFT);
		direction b(direction::LEFT);
		direction c(direction::TOP);
		CHECK(bool(a == b));
		CHECK(bool(a == c) == false);
		CHECK(bool(a != c));
		CHECK(bool(a == direction::LEFT));
		CHECK(bool(a != direction::RIGHT));
		CHECK(bool(direction::LEFT == a));
		CHECK(bool(direction::RIGHT != a));
	}

	SECTION("String operators of direction class")
	{
		direction a(direction::RIGHT_TOP);
		CHECK(bool(a == "right-top"));
		CHECK(bool(a != "left-top"));
		CHECK(bool("right-top" == a));
		CHECK(bool("bottom" != a));
		std::string b = "x: ";
		b += a;
		CHECK(b == "x: right-top");
		CHECK(("x: " + a) == "x: right-top");
		CHECK("x: right-top" == ("x: " + a));
		CHECK((a + " direction") == "right-top direction");
	}

	SECTION("Streams of direction class")
	{
		direction a(direction::FRONT);
		std::ostringstream out;
		out << a;
		CHECK(out.str() == "front");
		std::istringstream iss("left-front");
		direction b;
		iss >> b;
		CHECK(to_string(b) == "left-front");
	}
}