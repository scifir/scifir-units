#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../units/dimension.hpp"
#include "../../topology/constants.hpp"

#include "unicode/unistr.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("dimension class","Full test of dimension class") {
	SECTION("Base functionalities of dimension class") {
		dimension a = dimension("m",dimension::POSITIVE);
		REQUIRE (bool(a.dimension_type == dimension::m));
		REQUIRE (bool(a.dimension_sign == dimension::POSITIVE));
		REQUIRE (bool(a.prefix.prefix_type == prefix::no_prefix));
		REQUIRE (bool(a.get_symbol() == "m"));
		dimension b = dimension("m",dimension::NEGATIVE);
		REQUIRE (bool(b.dimension_sign == dimension::NEGATIVE));
	}

	SECTION("Constructors of dimension class")
	{
		dimension a;
		REQUIRE (bool(a.dimension_type == dimension::NONE));
		dimension b2(dimension::m,prefix::no_prefix,dimension::POSITIVE);
		dimension b(b2);
		REQUIRE (bool(b.dimension_type == dimension::m));
		dimension c2(dimension::m,prefix::no_prefix,dimension::POSITIVE);
		dimension c(std::move(c2));
		REQUIRE (bool(c.dimension_type == dimension::m));
		dimension d(dimension::m,prefix::k,dimension::POSITIVE);
		REQUIRE (bool(to_string(d) == "km"));
		prefix e2(prefix::k);
		dimension e(dimension::m,e2,dimension::POSITIVE);
		REQUIRE (bool(to_string(e) == "km"));
	}

	SECTION("Creation of basic dimension classes") {
		dimension a = dimension("m",dimension::POSITIVE);
		REQUIRE (bool(a.get_symbol() == "m"));
		dimension b = dimension("s",dimension::POSITIVE);
		REQUIRE (bool(b.get_symbol() == "s"));
		dimension c = dimension("g",dimension::POSITIVE);
		REQUIRE (bool(c.get_symbol() == "g"));
		dimension d = dimension("C",dimension::POSITIVE);
		REQUIRE (bool(d.get_symbol() == "C"));
		dimension e = dimension("K",dimension::POSITIVE);
		REQUIRE (bool(e.get_symbol() == "K"));
		dimension f = dimension("mol",dimension::POSITIVE);
		REQUIRE (bool(f.get_symbol() == "mol"));
		dimension g = dimension("cd",dimension::POSITIVE);
		REQUIRE (bool(g.get_symbol() == "cd"));
		dimension h = dimension("B",dimension::POSITIVE);
		REQUIRE (bool(h.get_symbol() == "B"));
		dimension i = dimension("rad",dimension::POSITIVE);
		REQUIRE (bool(i.get_symbol() == "rad"));
		dimension j = dimension("sr",dimension::POSITIVE);
		REQUIRE (bool(j.get_symbol() == "sr"));
		dimension k = dimension("money",dimension::POSITIVE);
		REQUIRE (bool(k.get_symbol() == "money"));
		dimension l = dimension("memo",dimension::POSITIVE);
		REQUIRE (bool(l.get_symbol() == "memo"));
	}

	SECTION("Creation of all dimension types")
	{
		dimension a("m",dimension::POSITIVE);
		REQUIRE(bool(a.dimension_type == dimension::m));
		dimension a2("rad",dimension::POSITIVE);
		REQUIRE(bool(a2.dimension_type == dimension::radian));
		dimension a3("sr",dimension::POSITIVE);
		REQUIRE(bool(a3.dimension_type == dimension::steradian));
		dimension a4("s",dimension::POSITIVE);
		REQUIRE(bool(a4.dimension_type == dimension::s));
		dimension a5("g",dimension::POSITIVE);
		REQUIRE(bool(a5.dimension_type == dimension::g));
		dimension a6("C",dimension::POSITIVE);
		REQUIRE(bool(a6.dimension_type == dimension::C));
		dimension a7("K",dimension::POSITIVE);
		REQUIRE(bool(a7.dimension_type == dimension::K));
		dimension a8("mol",dimension::POSITIVE);
		REQUIRE(bool(a8.dimension_type == dimension::mol));
		dimension a9("cd",dimension::POSITIVE);
		REQUIRE(bool(a9.dimension_type == dimension::cd));
		dimension a10("B",dimension::POSITIVE);
		REQUIRE(bool(a10.dimension_type == dimension::B));
		dimension a11("Hz",dimension::POSITIVE);
		REQUIRE(bool(a11.dimension_type == dimension::Hz));
		dimension a12("N",dimension::POSITIVE);
		REQUIRE(bool(a12.dimension_type == dimension::N));
		dimension a13("Pa",dimension::POSITIVE);
		REQUIRE(bool(a13.dimension_type == dimension::Pa));
		dimension a14("J",dimension::POSITIVE);
		REQUIRE(bool(a14.dimension_type == dimension::J));
		dimension a15("W",dimension::POSITIVE);
		REQUIRE(bool(a15.dimension_type == dimension::W));
		dimension a16("A",dimension::POSITIVE);
		REQUIRE(bool(a16.dimension_type == dimension::A));
		dimension a17("V",dimension::POSITIVE);
		REQUIRE(bool(a17.dimension_type == dimension::V));
		dimension a18("F",dimension::POSITIVE);
		REQUIRE(bool(a18.dimension_type == dimension::F));
		dimension a19("ohm",dimension::POSITIVE);
		REQUIRE(bool(a19.dimension_type == dimension::Ohm));
		dimension a19_2("Ohm",dimension::POSITIVE);
		REQUIRE(bool(a19_2.dimension_type == dimension::Ohm));
		/*dimension a19_3("\U000003A9",dimension::POSITIVE);
		REQUIRE(bool(a19_3.dimension_type == dimension::Ohm));*/
		dimension a20("S",dimension::POSITIVE);
		REQUIRE(bool(a20.dimension_type == dimension::S));
		dimension a21("Wb",dimension::POSITIVE);
		REQUIRE(bool(a21.dimension_type == dimension::Wb));
		dimension a22("T",dimension::POSITIVE);
		REQUIRE(bool(a22.dimension_type == dimension::T));
		dimension a23("H",dimension::POSITIVE);
		REQUIRE(bool(a23.dimension_type == dimension::H));
		dimension a24("lm",dimension::POSITIVE);
		REQUIRE(bool(a24.dimension_type == dimension::lm));
		dimension a25("lx",dimension::POSITIVE);
		REQUIRE(bool(a25.dimension_type == dimension::lx));
		dimension a26("Bq",dimension::POSITIVE);
		REQUIRE(bool(a26.dimension_type == dimension::Bq));
		dimension a27("Gy",dimension::POSITIVE);
		REQUIRE(bool(a27.dimension_type == dimension::Gy));
		dimension a28("Sv",dimension::POSITIVE);
		REQUIRE(bool(a28.dimension_type == dimension::Sv));
		dimension a29("kat",dimension::POSITIVE);
		REQUIRE(bool(a29.dimension_type == dimension::kat));
		dimension a30("angstrom",dimension::POSITIVE); // MORE CASES
		REQUIRE(bool(a30.dimension_type == dimension::angstrom));
		dimension a31("L",dimension::POSITIVE);
		REQUIRE(bool(a31.dimension_type == dimension::L));
		dimension a32("min",dimension::POSITIVE);
		REQUIRE(bool(a32.dimension_type == dimension::minute));
		dimension a33("h",dimension::POSITIVE);
		REQUIRE(bool(a33.dimension_type == dimension::h));
		dimension a34("d",dimension::POSITIVE);
		REQUIRE(bool(a34.dimension_type == dimension::d));
		dimension a35("AU",dimension::POSITIVE);
		REQUIRE(bool(a35.dimension_type == dimension::AU));
		dimension a36("pc",dimension::POSITIVE);
		REQUIRE(bool(a36.dimension_type == dimension::pc));
		dimension a37("eV",dimension::POSITIVE);
		REQUIRE(bool(a37.dimension_type == dimension::eV));
		dimension a38("Da",dimension::POSITIVE);
		REQUIRE(bool(a38.dimension_type == dimension::Da));
		dimension a39("amu",dimension::POSITIVE);
		REQUIRE(bool(a39.dimension_type == dimension::amu));
		dimension a40("barn",dimension::POSITIVE);
		REQUIRE(bool(a40.dimension_type == dimension::barn));
		dimension a41("M",dimension::POSITIVE);
		REQUIRE(bool(a41.dimension_type == dimension::M));
		dimension a42("particles",dimension::POSITIVE);
		REQUIRE(bool(a42.dimension_type == dimension::particles));
		dimension a43("money",dimension::POSITIVE);
		REQUIRE(bool(a43.dimension_type == dimension::money));
		dimension a44("px",dimension::POSITIVE);
		REQUIRE(bool(a44.dimension_type == dimension::pixel));
		dimension a45("memo",dimension::POSITIVE);
		REQUIRE(bool(a45.dimension_type == dimension::memo));
		dimension a46("",dimension::POSITIVE);
		REQUIRE(bool(a46.dimension_type == dimension::NONE));
		dimension a47("hello",dimension::POSITIVE);
		REQUIRE(bool(a47.dimension_type == dimension::custom_full_symbol));
	}

	SECTION("Assignments of dimension class")
	{
		dimension a;
		dimension b(dimension::g,prefix::no_prefix,dimension::POSITIVE);
		a = b;
		REQUIRE(bool(a.dimension_type == dimension::g));
		dimension c;
		dimension d(dimension::g,prefix::no_prefix,dimension::POSITIVE);
		c = std::move(d);
		REQUIRE(bool(c.dimension_type == dimension::g));
	}

	SECTION("Testing of length dimensions") {
		dimension a = dimension("Ym",dimension::POSITIVE);
		REQUIRE (bool(to_string(a) == "Ym"));
		dimension b = dimension("Zm",dimension::POSITIVE);
		REQUIRE (bool(to_string(b) == "Zm"));
		dimension c = dimension("Em",dimension::POSITIVE);
		REQUIRE (bool(to_string(c) == "Em"));
		dimension d = dimension("Pm",dimension::POSITIVE);
		REQUIRE (bool(to_string(d) == "Pm"));
		dimension e = dimension("Tm",dimension::POSITIVE);
		REQUIRE (bool(to_string(e) == "Tm"));
		dimension f = dimension("Gm",dimension::POSITIVE);
		REQUIRE (bool(to_string(f) == "Gm"));
		dimension g = dimension("Mm",dimension::POSITIVE);
		REQUIRE (bool(to_string(g) == "Mm"));
		dimension h = dimension("km",dimension::POSITIVE);
		REQUIRE (bool(to_string(h) == "km"));
		dimension i = dimension("hm",dimension::POSITIVE);
		REQUIRE (bool(to_string(i) == "hm"));
		dimension j = dimension("dam",dimension::POSITIVE);
		REQUIRE (bool(to_string(j) == "dam"));
		dimension k = dimension("dm",dimension::POSITIVE);
		REQUIRE (bool(to_string(k) == "dm"));
		dimension l = dimension("cm",dimension::POSITIVE);
		REQUIRE (bool(to_string(l) == "cm"));
		dimension m = dimension("mm",dimension::POSITIVE);
		REQUIRE (bool(to_string(m) == "mm"));
		dimension n = dimension("um",dimension::POSITIVE);
		REQUIRE (bool(to_string(n) == "\u00B5m"));
		//dimension n2 = dimension("\u00B5m",dimension::POSITIVE);
		//cout << "n2: " << to_string(n2) << endl;
		//string n2_icu;
		//icu::UnicodeString("\u00B5m").toUTF8String(n2_icu);
		//REQUIRE (bool(to_string(n2) == n2_icu));
		dimension o = dimension("nm",dimension::POSITIVE);
		REQUIRE (bool(to_string(o) == "nm"));
		dimension p = dimension("pm",dimension::POSITIVE);
		REQUIRE (bool(to_string(p) == "pm"));
		dimension q = dimension("fm",dimension::POSITIVE);
		REQUIRE (bool(to_string(q) == "fm"));
		dimension r = dimension("am",dimension::POSITIVE);
		REQUIRE (bool(to_string(r) == "am"));
		dimension s = dimension("zm",dimension::POSITIVE);
		REQUIRE (bool(to_string(s) == "zm"));
		dimension t = dimension("ym",dimension::POSITIVE);
		REQUIRE (bool(to_string(t) == "ym"));
	}

	SECTION ("get_name(), get_symbol(), get_conversion_factor(), is_simple_dmension(), is_basic_dimension() of dimension class")
	{
		dimension a(dimension::NONE,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a.get_name() == "empty"));
		REQUIRE (bool(a.get_symbol() == "empty"));
		REQUIRE (bool(a.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a.is_simple_dimension() == true));
		REQUIRE (bool(a.is_basic_dimension() == true));
		dimension a2(dimension::m,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a2.get_name() == "meter"));
		REQUIRE (bool(a2.get_symbol() == "m"));
		REQUIRE (bool(a2.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a2.is_simple_dimension() == true));
		REQUIRE (bool(a2.is_basic_dimension() == true));
		dimension a3(dimension::radian,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a3.get_name() == "radian"));
		REQUIRE (bool(a3.get_symbol() == "rad"));
		REQUIRE (bool(a3.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a3.is_simple_dimension() == true));
		REQUIRE (bool(a3.is_basic_dimension() == true));
		dimension a4(dimension::steradian,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a4.get_name() == "steradian"));
		REQUIRE (bool(a4.get_symbol() == "sr"));
		REQUIRE (bool(a4.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a4.is_simple_dimension() == true));
		REQUIRE (bool(a4.is_basic_dimension() == true));
		dimension a5(dimension::s,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a5.get_name() == "second"));
		REQUIRE (bool(a5.get_symbol() == "s"));
		REQUIRE (bool(a5.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a5.is_simple_dimension() == true));
		REQUIRE (bool(a5.is_basic_dimension() == true));
		dimension a6(dimension::g,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a6.get_name() == "gram"));
		REQUIRE (bool(a6.get_symbol() == "g"));
		REQUIRE (bool(a6.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a6.is_simple_dimension() == true));
		REQUIRE (bool(a6.is_basic_dimension() == true));
		dimension a7(dimension::C,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a7.get_name() == "coulomb"));
		REQUIRE (bool(a7.get_symbol() == "C"));
		REQUIRE (bool(a7.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a7.is_simple_dimension() == true));
		REQUIRE (bool(a7.is_basic_dimension() == true));
		dimension a8(dimension::K,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a8.get_name() == "kelvin"));
		REQUIRE (bool(a8.get_symbol() == "K"));
		REQUIRE (bool(a8.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a8.is_simple_dimension() == true));
		REQUIRE (bool(a8.is_basic_dimension() == true));
		dimension a9(dimension::mol,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a9.get_name() == "mole"));
		REQUIRE (bool(a9.get_symbol() == "mol"));
		REQUIRE (bool(a9.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a9.is_simple_dimension() == true));
		REQUIRE (bool(a9.is_basic_dimension() == true));
		dimension a10(dimension::cd,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a10.get_name() == "candela"));
		REQUIRE (bool(a10.get_symbol() == "cd"));
		REQUIRE (bool(a10.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a10.is_simple_dimension() == true));
		REQUIRE (bool(a10.is_basic_dimension() == true));
		dimension a11(dimension::B,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a11.get_name() == "byte"));
		REQUIRE (bool(a11.get_symbol() == "B"));
		REQUIRE (bool(a11.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a11.is_simple_dimension() == true));
		REQUIRE (bool(a11.is_basic_dimension() == true));
		dimension a12(dimension::Hz,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a12.get_name() == "hertz"));
		REQUIRE (bool(a12.get_symbol() == "Hz"));
		REQUIRE (bool(a12.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a12.is_simple_dimension() == true));
		REQUIRE (bool(a12.is_basic_dimension() == false));
		dimension a13(dimension::N,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a13.get_name() == "newton"));
		REQUIRE (bool(a13.get_symbol() == "N"));
		REQUIRE (bool(a13.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a13.is_simple_dimension() == false));
		REQUIRE (bool(a13.is_basic_dimension() == false));
		dimension a14(dimension::Pa,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a14.get_name() == "pascal"));
		REQUIRE (bool(a14.get_symbol() == "Pa"));
		REQUIRE (bool(a14.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a14.is_simple_dimension() == false));
		REQUIRE (bool(a14.is_basic_dimension() == false));
		dimension a15(dimension::J,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a15.get_name() == "joule"));
		REQUIRE (bool(a15.get_symbol() == "J"));
		REQUIRE (bool(a15.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a15.is_simple_dimension() == false));
		REQUIRE (bool(a15.is_basic_dimension() == false));
		dimension a16(dimension::W,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a16.get_name() == "watt"));
		REQUIRE (bool(a16.get_symbol() == "W"));
		REQUIRE (bool(a16.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a16.is_simple_dimension() == false));
		REQUIRE (bool(a16.is_basic_dimension() == false));
		dimension a17(dimension::A,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a17.get_name() == "ampere"));
		REQUIRE (bool(a17.get_symbol() == "A"));
		REQUIRE (bool(a17.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a17.is_simple_dimension() == true));
		REQUIRE (bool(a17.is_basic_dimension() == false));
		dimension a18(dimension::V,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a18.get_name() == "volt"));
		REQUIRE (bool(a18.get_symbol() == "V"));
		REQUIRE (bool(a18.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a18.is_simple_dimension() == false));
		REQUIRE (bool(a18.is_basic_dimension() == false));
		dimension a19(dimension::F,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a19.get_name() == "faraday"));
		REQUIRE (bool(a19.get_symbol() == "F"));
		REQUIRE (bool(a19.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a19.is_simple_dimension() == false));
		REQUIRE (bool(a19.is_basic_dimension() == false));
		dimension a20(dimension::Ohm,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a20.get_name() == "ohm"));
		REQUIRE (bool(a20.get_symbol() == "\U000003A9"));
		REQUIRE (bool(a20.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a20.is_simple_dimension() == false));
		REQUIRE (bool(a20.is_basic_dimension() == false));
		dimension a21(dimension::S,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a21.get_name() == "siemens"));
		REQUIRE (bool(a21.get_symbol() == "S"));
		REQUIRE (bool(a21.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a21.is_simple_dimension() == false));
		REQUIRE (bool(a21.is_basic_dimension() == false));
		dimension a22(dimension::Wb,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a22.get_name() == "weber"));
		REQUIRE (bool(a22.get_symbol() == "Wb"));
		REQUIRE (bool(a22.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a22.is_simple_dimension() == false));
		REQUIRE (bool(a22.is_basic_dimension() == false));
		dimension a23(dimension::T,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a23.get_name() == "tesla"));
		REQUIRE (bool(a23.get_symbol() == "T"));
		REQUIRE (bool(a23.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a23.is_simple_dimension() == false));
		REQUIRE (bool(a23.is_basic_dimension() == false));
		dimension a24(dimension::H,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a24.get_name() == "henry"));
		REQUIRE (bool(a24.get_symbol() == "H"));
		REQUIRE (bool(a24.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a24.is_simple_dimension() == false));
		REQUIRE (bool(a24.is_basic_dimension() == false));
		dimension a25(dimension::lm,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a25.get_name() == "lumen"));
		REQUIRE (bool(a25.get_symbol() == "lm"));
		REQUIRE (bool(a25.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a25.is_simple_dimension() == false));
		REQUIRE (bool(a25.is_basic_dimension() == false));
		dimension a26(dimension::lx,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a26.get_name() == "lux"));
		REQUIRE (bool(a26.get_symbol() == "lx"));
		REQUIRE (bool(a26.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a26.is_simple_dimension() == false));
		REQUIRE (bool(a26.is_basic_dimension() == false));
		dimension a27(dimension::Bq,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a27.get_name() == "becquerel"));
		REQUIRE (bool(a27.get_symbol() == "Bq"));
		REQUIRE (bool(a27.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a27.is_simple_dimension() == true));
		REQUIRE (bool(a27.is_basic_dimension() == false));
		dimension a28(dimension::Gy,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a28.get_name() == "gray"));
		REQUIRE (bool(a28.get_symbol() == "Gy"));
		REQUIRE (bool(a28.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a28.is_simple_dimension() == false));
		REQUIRE (bool(a28.is_basic_dimension() == false));
		dimension a29(dimension::Sv,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a29.get_name() == "sievert"));
		REQUIRE (bool(a29.get_symbol() == "Sv"));
		REQUIRE (bool(a29.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a29.is_simple_dimension() == false));
		REQUIRE (bool(a29.is_basic_dimension() == false));
		dimension a30(dimension::kat,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a30.get_name() == "katal"));
		REQUIRE (bool(a30.get_symbol() == "kat"));
		REQUIRE (bool(a30.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a30.is_simple_dimension() == false));
		REQUIRE (bool(a30.is_basic_dimension() == false));
		dimension a31(dimension::angstrom,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a31.get_name() == "angstrom"));
		REQUIRE (bool(a31.get_symbol() == "\U0000212B"));
		REQUIRE (bool(a31.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a31.is_simple_dimension() == true));
		REQUIRE (bool(a31.is_basic_dimension() == false));
		dimension a32(dimension::L,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a32.get_name() == "liter"));
		REQUIRE (bool(a32.get_symbol() == "L"));
		REQUIRE (bool(a32.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a32.is_simple_dimension() == false));
		REQUIRE (bool(a32.is_basic_dimension() == false));
		dimension a33(dimension::minute,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a33.get_name() == "minute"));
		REQUIRE (bool(a33.get_symbol() == "min"));
		REQUIRE (bool(a33.get_conversion_factor() == 60.0l));
		REQUIRE (bool(a33.is_simple_dimension() == true));
		REQUIRE (bool(a33.is_basic_dimension() == false));
		dimension a34(dimension::h,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a34.get_name() == "hour"));
		REQUIRE (bool(a34.get_symbol() == "h"));
		REQUIRE (bool(a34.get_conversion_factor() == 3600.0l));
		REQUIRE (bool(a34.is_simple_dimension() == true));
		REQUIRE (bool(a34.is_basic_dimension() == false));
		dimension a35(dimension::d,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a35.get_name() == "day"));
		REQUIRE (bool(a35.get_symbol() == "d"));
		REQUIRE (bool(a35.get_conversion_factor() == 86400.0l));
		REQUIRE (bool(a35.is_simple_dimension() == true));
		REQUIRE (bool(a35.is_basic_dimension() == false));
		dimension a36(dimension::AU,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a36.get_name() == "astronomical unit"));
		REQUIRE (bool(a36.get_symbol() == "AU"));
		REQUIRE (bool(a36.get_conversion_factor() == 149597870700.0l));
		REQUIRE (bool(a36.is_simple_dimension() == true));
		REQUIRE (bool(a36.is_basic_dimension() == false));
		dimension a37(dimension::pc,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a37.get_name() == "parsec"));
		REQUIRE (bool(a37.get_symbol() == "pc"));
		REQUIRE (bool(a37.get_conversion_factor() == 30856775814913673.0l));
		REQUIRE (bool(a37.is_simple_dimension() == true));
		REQUIRE (bool(a37.is_basic_dimension() == false));
		dimension a38(dimension::eV,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a38.get_name() == "electronvolt"));
		REQUIRE (bool(a38.get_symbol() == "eV"));
		REQUIRE (bool(a38.get_conversion_factor() == 0.0000000000000000001602176634l));
		REQUIRE (bool(a38.is_simple_dimension() == false));
		REQUIRE (bool(a38.is_basic_dimension() == false));
		dimension a39(dimension::Da,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a39.get_name() == "dalton"));
		REQUIRE (bool(a39.get_symbol() == "Da"));
		REQUIRE (bool(a39.get_conversion_factor() == 0.00000000000000000000000000166053886l));
		REQUIRE (bool(a39.is_simple_dimension() == true));
		REQUIRE (bool(a39.is_basic_dimension() == false));
		dimension a40(dimension::amu,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a40.get_name() == "atomic mass unit"));
		REQUIRE (bool(a40.get_symbol() == "amu"));
		REQUIRE (bool(a40.get_conversion_factor() == 0.00000000000000000000000000166053886l));
		REQUIRE (bool(a40.is_simple_dimension() == true));
		REQUIRE (bool(a40.is_basic_dimension() == false));
		dimension a41(dimension::barn,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a41.get_name() == "barn"));
		REQUIRE (bool(a41.get_symbol() == "barn"));
		REQUIRE (bool(a41.get_conversion_factor() == 0.0000000000000000000000000001l));
		REQUIRE (bool(a41.is_simple_dimension() == false));
		REQUIRE (bool(a41.is_basic_dimension() == false));
		dimension a42(dimension::M,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a42.get_name() == "molarity"));
		REQUIRE (bool(a42.get_symbol() == "M"));
		REQUIRE (bool(a42.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a42.is_simple_dimension() == false));
		REQUIRE (bool(a42.is_basic_dimension() == false));
		dimension a43(dimension::particles,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a43.get_name() == "particles"));
		REQUIRE (bool(a43.get_symbol() == "particles"));
		REQUIRE (bool(a43.get_conversion_factor() == 1l/AVOGADRO_CONSTANT));
		REQUIRE (bool(a43.is_simple_dimension() == true));
		REQUIRE (bool(a43.is_basic_dimension() == false));
		/*dimension a44("hello",dimension::POSITIVE);
		REQUIRE (bool(a44.get_name() == "custom-dimension"));
		REQUIRE (bool(a44.get_symbol() == "hello"));
		REQUIRE (bool(a44.get_conversion_factor() == 1.0));
		REQUIRE (bool(a44.is_simple_dimension() == false));
		REQUIRE (bool(a44.is_basic_dimension() == false));
		dimension a45(dimension::custom_basic,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a45.get_name() == "custom-basic"));
		REQUIRE (bool(a45.get_symbol() == "custom-basic"));
		REQUIRE (bool(a45.get_conversion_factor() == 1.0));
		REQUIRE (bool(a45.is_simple_dimension() == false));
		REQUIRE (bool(a45.is_basic_dimension() == false));
		dimension a46(dimension::custom_full_symbol,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a46.get_name() == "custom-full-symbol"));
		REQUIRE (bool(a46.get_symbol() == ""));
		REQUIRE (bool(a46.get_conversion_factor() == 1.0));
		REQUIRE (bool(a46.is_simple_dimension() == false));
		REQUIRE (bool(a46.is_basic_dimension() == false));*/
		dimension a47(dimension::money,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a47.get_name() == "money"));
		REQUIRE (bool(a47.get_symbol() == "money"));
		REQUIRE (bool(a47.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a47.is_simple_dimension() == true));
		REQUIRE (bool(a47.is_basic_dimension() == true));
		dimension a48(dimension::pixel,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a48.get_name() == "pixel"));
		REQUIRE (bool(a48.get_symbol() == "px"));
		REQUIRE (bool(a48.get_conversion_factor() == 0.00026l));
		REQUIRE (bool(a48.is_simple_dimension() == true));
		REQUIRE (bool(a48.is_basic_dimension() == false));
		dimension a49(dimension::memo,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(a49.get_name() == "memo"));
		REQUIRE (bool(a49.get_symbol() == "memo"));
		REQUIRE (bool(a49.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a49.is_simple_dimension() == true));
		REQUIRE (bool(a49.is_basic_dimension() == true));
	}

	SECTION ("get_basic_dimensions() of dimension class")
	{
		dimension a0("",dimension::POSITIVE);
		vector<dimension> b0 = { dimension(dimension::NONE,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a0.get_basic_dimensions(),b0)));
		dimension a("m",dimension::POSITIVE);
		vector<dimension> b = { dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a.get_basic_dimensions(),b)));
		dimension a2("rad",dimension::POSITIVE);
		vector<dimension> b2 = { dimension(dimension::radian,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a2.get_basic_dimensions(),b2)));
		dimension a3("sr",dimension::POSITIVE);
		vector<dimension> b3 = { dimension(dimension::steradian,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a3.get_basic_dimensions(),b3)));
		dimension a4("s",dimension::POSITIVE);
		vector<dimension> b4 = { dimension(dimension::s,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a4.get_basic_dimensions(),b4)));
		dimension a5("g",dimension::POSITIVE);
		vector<dimension> b5 = { dimension(dimension::g,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a5.get_basic_dimensions(),b5)));
		dimension a6("C",dimension::POSITIVE);
		vector<dimension> b6 = { dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a6.get_basic_dimensions(),b6)));
		dimension a7("K",dimension::POSITIVE);
		vector<dimension> b7 = { dimension(dimension::K,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a7.get_basic_dimensions(),b7)));
		dimension a8("mol",dimension::POSITIVE);
		vector<dimension> b8 = { dimension(dimension::mol,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a8.get_basic_dimensions(),b8)));
		dimension a9("cd",dimension::POSITIVE);
		vector<dimension> b9 = { dimension(dimension::cd,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a9.get_basic_dimensions(),b9)));
		dimension a10("B",dimension::POSITIVE);
		vector<dimension> b10 = { dimension(dimension::B,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a10.get_basic_dimensions(),b10)));
		dimension a11("Hz",dimension::POSITIVE);
		vector<dimension> b11 = { dimension(dimension::Hz,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a11.get_basic_dimensions(),b11)));
		dimension a12("N",dimension::POSITIVE);
		vector<dimension> b12 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		REQUIRE(bool(equal_dimensions(a12.get_basic_dimensions(),b12)));
		dimension a13("Pa",dimension::POSITIVE);
		vector<dimension> b13 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE) };
		REQUIRE(bool(equal_dimensions(a13.get_basic_dimensions(),b13)));
		dimension a14("J",dimension::POSITIVE);
		vector<dimension> b14 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		REQUIRE(bool(equal_dimensions(a14.get_basic_dimensions(),b14)));
		dimension a15("W",dimension::POSITIVE);
		vector<dimension> b15 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		REQUIRE(bool(equal_dimensions(a15.get_basic_dimensions(),b15)));
		dimension a16("A",dimension::POSITIVE);
		vector<dimension> b16 = { dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		REQUIRE(bool(equal_dimensions(a16.get_basic_dimensions(),b16)));
		dimension a17("V",dimension::POSITIVE);
		vector<dimension> b17 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		REQUIRE(bool(equal_dimensions(a17.get_basic_dimensions(),b17)));
		dimension a18("F",dimension::POSITIVE);
		vector<dimension> b18 = { dimension(dimension::g,prefix::k,dimension::NEGATIVE),
				dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE),
				dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE),
				dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
				dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
				dimension(dimension::s,prefix::no_prefix,dimension::POSITIVE),
				dimension(dimension::s,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a18.get_basic_dimensions(),b18)));
		dimension a19("Ohm",dimension::POSITIVE);
		vector<dimension> b19 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		REQUIRE(bool(equal_dimensions(a19.get_basic_dimensions(),b19)));
		dimension a20("S",dimension::POSITIVE);
		vector<dimension> b20 = { dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::g,prefix::k,dimension::NEGATIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE) };
		REQUIRE(bool(equal_dimensions(a20.get_basic_dimensions(),b20)));
		dimension a21("Wb",dimension::POSITIVE);
		vector<dimension> b21 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		REQUIRE(bool(equal_dimensions(a21.get_basic_dimensions(),b21)));
		dimension a22("T",dimension::POSITIVE);
		vector<dimension> b22 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		REQUIRE(bool(equal_dimensions(a22.get_basic_dimensions(),b22)));
		dimension a23("H",dimension::POSITIVE);
		vector<dimension> b23 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a23.get_basic_dimensions(),b23)));
		dimension a24("lm",dimension::POSITIVE);
		vector<dimension> b24 = { dimension(dimension::cd,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::steradian,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a24.get_basic_dimensions(),b24)));
		dimension a25("lx",dimension::POSITIVE);
		vector<dimension> b25 = { dimension(dimension::cd,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::steradian,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE) };
		REQUIRE(bool(equal_dimensions(a25.get_basic_dimensions(),b25)));
		dimension a26("Bq",dimension::POSITIVE);
		vector<dimension> b26 = { dimension(dimension::Bq,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a26.get_basic_dimensions(),b26)));
		dimension a27("Gy",dimension::POSITIVE);
		vector<dimension> b27 = { dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		REQUIRE(bool(equal_dimensions(a27.get_basic_dimensions(),b27)));
		dimension a28("Sv",dimension::POSITIVE);
		vector<dimension> b28 = { dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		REQUIRE(bool(equal_dimensions(a28.get_basic_dimensions(),b28)));
		dimension a29("kat",dimension::POSITIVE);
		vector<dimension> b29 = { dimension(dimension::mol,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		REQUIRE(bool(equal_dimensions(a29.get_basic_dimensions(),b29)));
		dimension a30("angstrom",dimension::POSITIVE);
		vector<dimension> b30 = { dimension(dimension::angstrom,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a30.get_basic_dimensions(),b30)));
		dimension a31("L",dimension::POSITIVE);
		vector<dimension> b31 = { dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a31.get_basic_dimensions(),b31)));
		dimension a32("min",dimension::POSITIVE);
		vector<dimension> b32 = { dimension(dimension::minute,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a32.get_basic_dimensions(),b32)));
		dimension a33("h",dimension::POSITIVE);
		vector<dimension> b33 = { dimension(dimension::h,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a33.get_basic_dimensions(),b33)));
		dimension a34("d",dimension::POSITIVE);
		vector<dimension> b34 = { dimension(dimension::d,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a34.get_basic_dimensions(),b34)));
		dimension a35("AU",dimension::POSITIVE);
		vector<dimension> b35 = { dimension(dimension::AU,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a35.get_basic_dimensions(),b35)));
		dimension a36("pc",dimension::POSITIVE);
		vector<dimension> b36 = { dimension(dimension::pc,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a36.get_basic_dimensions(),b36)));
		dimension a37("eV",dimension::POSITIVE);
		vector<dimension> b37 = { dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		REQUIRE(bool(equal_dimensions(a37.get_basic_dimensions(),b37)));
		dimension a38("Da",dimension::POSITIVE);
		vector<dimension> b38 = { dimension(dimension::Da,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a38.get_basic_dimensions(),b38)));
		dimension a39("amu",dimension::POSITIVE);
		vector<dimension> b39 = { dimension(dimension::amu,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a39.get_basic_dimensions(),b39)));
		dimension a40("barn",dimension::POSITIVE);
		vector<dimension> b40 = { dimension(dimension::barn,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a40.get_basic_dimensions(),b40)));
		dimension a41("M",dimension::POSITIVE);
		vector<dimension> b41 = { dimension(dimension::mol,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE) };
		REQUIRE(bool(equal_dimensions(a41.get_basic_dimensions(),b41)));
		dimension a42("particles",dimension::POSITIVE);
		vector<dimension> b42 = { dimension(dimension::particles,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a42.get_basic_dimensions(),b42)));
		dimension a43("money",dimension::POSITIVE);
		vector<dimension> b43 = { dimension(dimension::money,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a43.get_basic_dimensions(),b43)));
		dimension a44("px",dimension::POSITIVE);
		vector<dimension> b44 = { dimension(dimension::pixel,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a44.get_basic_dimensions(),b44)));
		dimension a45("memo",dimension::POSITIVE);
		vector<dimension> b45 = { dimension(dimension::memo,prefix::no_prefix,dimension::POSITIVE) };
		REQUIRE(bool(equal_dimensions(a45.get_basic_dimensions(),b45)));
	}

	SECTION ("Constructor of custom dimensions")
	{
		dimension a("usd",dimension::POSITIVE);
		vector<dimension> b = { dimension("usd",dimension::POSITIVE) };
		REQUIRE (bool(a.get_name() == "custom-dimension"));
		REQUIRE (bool(a.get_symbol() == "usd"));
		REQUIRE (bool(a.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a.is_simple_dimension() == false));
		REQUIRE (bool(a.is_basic_dimension() == false));
		REQUIRE (bool(equal_dimensions(a.get_basic_dimensions(),b)));
		dimension a2("long-dimension",dimension::POSITIVE);
		vector<dimension> b2 = { dimension("long-dimension",dimension::POSITIVE) };
		REQUIRE (bool(a2.get_name() == "custom-full-symbol"));
		REQUIRE (bool(a2.get_symbol() == "long-dimension"));
		REQUIRE (bool(a2.get_conversion_factor() == 1.0l));
		REQUIRE (bool(a2.is_simple_dimension() == false));
		REQUIRE (bool(a2.is_basic_dimension() == false));
		REQUIRE (bool(equal_dimensions(a2.get_basic_dimensions(),b2)));
	}

	SECTION ("create_custom_dimension(), create_full_symbol() and get_full_symbol() of dimension class")
	{
		dimension::create_custom_dimension("hello","m*s");
		/*char symbol[3];
		string full_symbol = dimension::create_full_symbol("symbol1");
		cout << "full symbol: " << full_symbol << endl;
		cout << "length: " << full_symbol.length() << endl;*/
		//full_symbol.copy(symbol, full_symbol.length() - 1);
		/*REQUIRE (bool(dimension::get_full_symbol(symbol) == "symbol1"));*/
	}

	SECTION("to_string() of dimension class")
	{
		vector<dimension> a = create_dimensions("m*s2/C4");
		REQUIRE (bool(to_string(a) == "m*s2/C4"));
		REQUIRE (bool(to_string(a,true) == "[m*s2/C4]"));
		vector<dimension> b = create_dimensions("1/m");
		REQUIRE (bool(to_string(b) == "1/m"));
		REQUIRE (bool(to_string(b,true) == "[1/m]"));
		dimension c("km",dimension::POSITIVE);
		REQUIRE (bool(to_string(c) == "km"));
	}

	SECTION ("create_dimensions(), create_derived_dimensions() and normalize_dimensions()") {
		vector<dimension> a = create_dimensions("m*s2/C4");
		REQUIRE (bool(to_string(a) == "m*s2/C4"));
		REQUIRE (bool(equal_dimensions(to_string(a),"s2*m/C4")));
		REQUIRE (bool(equal_dimensions(to_string(a),"s2*m/C3*C")));
		vector<dimension> b = create_dimensions("1/C2");
		REQUIRE (bool(to_string(b) == "1/C2"));
		vector<dimension> c = create_dimensions("m");
		REQUIRE (bool(to_string(c) == "m"));
		vector<dimension> d = create_dimensions("m3");
		REQUIRE (bool(to_string(d) == "m3"));
		vector<dimension> e = create_derived_dimensions("N");
		REQUIRE (bool(to_string(e) == "kg*m/s2"));
		vector<dimension> f = create_derived_dimensions("N2");
		REQUIRE (bool(to_string(f) == "kg2*m2/s4"));
		vector<dimension> g = create_dimensions("N");
		vector<dimension> h = create_derived_dimensions(g);
		REQUIRE (bool(to_string(h) == "kg*m/s2"));
		vector<dimension> i = create_dimensions("1/N");
		vector<dimension> j = create_derived_dimensions(i);
		REQUIRE (bool(to_string(j) == "s2/kg*m"));
		vector<dimension> k = create_dimensions("h");
		long double k2 = 10;
		vector<dimension> l = create_derived_dimensions(k,k2);
		REQUIRE (bool(equal_dimensions(k,l)));
		REQUIRE (bool(k2 == 36000));
		vector<dimension> r = create_dimensions("1/h");
		long double r2 = 10;
		vector<dimension> s = create_derived_dimensions(r,r2);
		REQUIRE (bool(equal_dimensions(r,s)));
		REQUIRE (bool(std::fabs(r2 - 0.00277778l) < 0.00000001l));
		vector<dimension> m = create_dimensions("m*s2/m2*C4");
		vector<dimension> n = normalize_dimensions(m);
		REQUIRE (bool(to_string(n) == "s2/m*C4"));
		vector<dimension> o = create_dimensions("kN");
		long double o2 = 1.0;
		vector<dimension> p = normalize_dimensions(o,o2);
		REQUIRE (bool(o2 == 1000.0));
		REQUIRE (bool(to_string(p) == "kg*m/s2"));
		vector<dimension> t = create_dimensions("m2*s2/m4*C3");
		vector<dimension> u = normalize_dimensions(t);
		REQUIRE (bool(to_string(u) == "s2/m2*C3"));
	}

	SECTION ("prefix_math() of dimesion_class")
	{
		dimension a("km",dimension::POSITIVE);
		REQUIRE (bool(a.prefix_math() == 1000));
		dimension b("kB",dimension::POSITIVE);
		REQUIRE (bool(b.prefix_math() == 1024));
	}

	SECTION ("multiply_dimensions(), divide_dimensions(), square_dimensions() and power_dimensions() of dimension class")
	{
		vector<dimension> a0 = create_dimensions("m");
		vector<dimension> b0 = create_dimensions("N");
		vector<dimension> c0 = multiply_dimensions(a0,b0);
		REQUIRE (bool(to_string(c0) == "m*N"));
		vector<dimension> a = create_dimensions("m");
		vector<dimension> b = create_dimensions("N");
		long double a2 = 1.0;
		vector<dimension> c = multiply_dimensions(a,b,a2);
		vector<dimension> d = create_dimensions("kg*m2/s2");
		REQUIRE (bool(equal_dimensions(c,d) == true));
		REQUIRE (bool(a2 == 1));
		vector<dimension> e = create_dimensions("g");
		vector<dimension> f = create_dimensions("h");
		long double e2 = 1.0;
		vector<dimension> g = multiply_dimensions(e,f,e2);
		vector<dimension> h = create_dimensions("g*s");
		REQUIRE (bool(equal_dimensions(g,h) == true));
		REQUIRE (bool(e2 == 3600));
		vector<dimension> i = create_dimensions("g/s");
		vector<dimension> j = create_dimensions("h");
		long double i2 = 1.0;
		vector<dimension> k = multiply_dimensions(i,j,i2);
		vector<dimension> l = create_dimensions("g");
		REQUIRE (bool(equal_dimensions(k,l) == true));
		REQUIRE (bool(i2 == 3600));
		vector<dimension> m = create_dimensions("g*h");
		vector<dimension> n = create_dimensions("s");
		long double m2 = 1.0;
		vector<dimension> o = divide_dimensions(m,n,m2);
		vector<dimension> p = create_dimensions("g");
		REQUIRE (bool(equal_dimensions(o,p) == true));
		REQUIRE (bool(m2 == 3600));
		vector<dimension> q = create_dimensions("g*kh");
		vector<dimension> r = create_dimensions("s");
		long double q2 = 1.0;
		vector<dimension> s = divide_dimensions(q,r,q2);
		vector<dimension> t = create_dimensions("g");
		REQUIRE (bool(equal_dimensions(s,t) == true));
		REQUIRE (bool(q2 == 3600000));
		vector<dimension> u = create_dimensions("kg*m");
		vector<dimension> v = power_dimensions(u,2);
		vector<dimension> w = create_dimensions("kg2*m2");
		REQUIRE (bool(equal_dimensions(v,w) == true));
		vector<dimension> x = create_dimensions("C/mol");
		vector<dimension> y = power_dimensions(x,5);
		vector<dimension> z = create_dimensions("C5/mol5");
		REQUIRE (bool(equal_dimensions(y,z) == true));
		vector<dimension> aa = create_dimensions("m2/s2");
		long double aa2 = 1.0;
		vector<dimension> ab = square_dimensions(aa,aa2,2);
		vector<dimension> ac = create_dimensions("m/s");
		REQUIRE (bool(equal_dimensions(ab,ac) == true));
		REQUIRE (bool(aa2 == 1));
		vector<dimension> ad = create_dimensions("h2/m2");
		long double ad2 = 1.0;
		vector<dimension> ae = square_dimensions(ad,ad2,2);
		vector<dimension> af = create_dimensions("s/m");
		REQUIRE (bool(equal_dimensions(ae,af) == true));
		REQUIRE (bool(ad2 == 12960000.0));
		vector<dimension> ag = create_dimensions("h4");
		long double ag2 = 1.0;
		vector<dimension> ah = square_dimensions(ag,ag2,4);
		vector<dimension> ai = create_dimensions("s");
		REQUIRE (bool(equal_dimensions(ah,ai) == true));
		REQUIRE (bool(ag2 == 167961600000000.0));
		vector<dimension> aj = create_dimensions("s3");
		long double aj2 = 1.0;
		vector<dimension> ak = square_dimensions(aj,aj2,2);
		REQUIRE (bool(ak.size() == 0));
		REQUIRE (bool(aj2 == 1.0));
		vector<dimension> al = create_dimensions("1/s2");
		long double al2 = 4.0;
		vector<dimension> am = square_dimensions(al,al2,2);
		vector<dimension> an = create_dimensions("1/s");
		REQUIRE (bool(equal_dimensions(am,an) == true));
		REQUIRE (bool(al2 == 4.0));
	}

	SECTION("common_dimension(), equal_dimensions() and equal_dimensions_and_prefixes()")
	{
		dimension a(dimension::m,prefix::no_prefix,dimension::POSITIVE);
		dimension b(dimension::AU,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(common_dimension(a,b) == true));
		REQUIRE (bool(equal_dimensions("m","AU") == true));
		REQUIRE (bool(equal_dimensions("m","pc") == true));
		dimension a2(dimension::g,prefix::no_prefix,dimension::POSITIVE);
		REQUIRE (bool(common_dimension(a,a2) == false));
		vector<dimension> c = create_dimensions("m/s");
		vector<dimension> d = create_dimensions("AU/s");
		vector<dimension> e = create_dimensions("pc/s");
		vector<dimension> f = create_dimensions("km/s");
		REQUIRE (bool(equal_dimensions(c,d) == true));
		REQUIRE (bool(equal_dimensions(c,e) == true));
		REQUIRE (bool(equal_dimensions(d,e) == true));
		REQUIRE (bool(equal_dimensions_and_prefixes(c,d) == false));
		REQUIRE (bool(equal_dimensions_and_prefixes(c,e) == false));
		REQUIRE (bool(equal_dimensions_and_prefixes(c,f) == false));
	}

	SECTION("Comparison of dimension classes")
	{
		dimension a(dimension::m,prefix::no_prefix,dimension::POSITIVE);
		dimension b(dimension::m,prefix::no_prefix,dimension::POSITIVE);
		dimension c(dimension::AU,prefix::no_prefix,dimension::POSITIVE);
		dimension d(dimension::m,prefix::no_prefix,dimension::NEGATIVE);
		REQUIRE (bool((a == b) == true));
		REQUIRE (bool((a != c) == true));
		REQUIRE (bool((a == c) == false));
		REQUIRE (bool((a == d) == false));
		REQUIRE (bool((a != d) == true));
	}

	SECTION ("Testing of custom dimensions") {
		dimension::create_custom_dimension("custom_dimension","m*s");
		dimension a = dimension("custom_dimension",dimension::POSITIVE);
		vector<dimension> b = create_dimensions("m*s");
		REQUIRE (bool(a.get_symbol() == "custom_dimension"));
		REQUIRE (bool(equal_dimensions(a.get_basic_dimensions(),b)));
		dimension::create_custom_dimension("uUu","g*m*s");
		dimension c = dimension("uUu",dimension::POSITIVE);
		vector<dimension> d = create_dimensions("g*m*s");
		REQUIRE (bool(c.get_symbol() == "uUu"));
		REQUIRE (bool(equal_dimensions(c.get_basic_dimensions(),d)));
	}
}

