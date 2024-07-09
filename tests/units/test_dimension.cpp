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

TEST_CASE("dimension class") {
	SECTION("Base functionalities of dimension class") {
		dimension a = dimension("m",dimension::NUMERATOR);
		CHECK(a.dimension_type == dimension::METRE);
		CHECK(a.dimension_position == dimension::NUMERATOR);
		CHECK(a.prefix.prefix_type == prefix::NONE);
		CHECK(a.get_symbol() == "m");
		dimension b = dimension("m",dimension::DENOMINATOR);
		CHECK(b.dimension_position == dimension::DENOMINATOR);
	}

	SECTION("Constructors of dimension class")
	{
		dimension a;
		CHECK(a.dimension_type == dimension::NONE);
		dimension b2(dimension::METRE,prefix::NONE,dimension::NUMERATOR);
		dimension b(b2);
		CHECK(b.dimension_type == dimension::METRE);
		dimension c2(dimension::METRE,prefix::NONE,dimension::NUMERATOR);
		dimension c(std::move(c2));
		CHECK(c.dimension_type == dimension::METRE);
		dimension d(dimension::METRE,prefix::KILO,dimension::NUMERATOR);
		CHECK(to_string(d) == "km");
		prefix e2(prefix::KILO);
		dimension e(dimension::METRE,e2,dimension::NUMERATOR);
		CHECK(to_string(e) == "km");
	}

	SECTION("Creation of basic dimension class") {
		dimension a = dimension("m",dimension::NUMERATOR);
		CHECK(a.get_symbol() == "m");
		dimension b = dimension("s",dimension::NUMERATOR);
		CHECK(b.get_symbol() == "s");
		dimension c = dimension("g",dimension::NUMERATOR);
		CHECK(c.get_symbol() == "g");
		dimension d = dimension("C",dimension::NUMERATOR);
		CHECK(d.get_symbol() == "C");
		dimension e = dimension("K",dimension::NUMERATOR);
		CHECK(e.get_symbol() == "K");
		dimension f = dimension("mol",dimension::NUMERATOR);
		CHECK(f.get_symbol() == "mol");
		dimension g = dimension("cd",dimension::NUMERATOR);
		CHECK(g.get_symbol() == "cd");
		dimension h = dimension("B",dimension::NUMERATOR);
		CHECK(h.get_symbol() == "B");
		dimension i = dimension("rad",dimension::NUMERATOR);
		CHECK(i.get_symbol() == "rad");
		dimension j = dimension("sr",dimension::NUMERATOR);
		CHECK(j.get_symbol() == "sr");
		dimension k = dimension("money",dimension::NUMERATOR);
		CHECK(k.get_symbol() == "money");
		dimension l = dimension("memo",dimension::NUMERATOR);
		CHECK(l.get_symbol() == "memo");
	}

	SECTION("Creation of all dimension types")
	{
		dimension a("m",dimension::NUMERATOR);
		CHECK(a.dimension_type == dimension::METRE);
		dimension a1_2("grade",dimension::NUMERATOR);
		CHECK(a1_2.dimension_type == dimension::GRADE);
		dimension a2("rad",dimension::NUMERATOR);
		CHECK(a2.dimension_type == dimension::RADIAN);
		dimension a3("sr",dimension::NUMERATOR);
		CHECK(a3.dimension_type == dimension::STERADIAN);
		dimension a4("s",dimension::NUMERATOR);
		CHECK(a4.dimension_type == dimension::SECOND);
		dimension a5("g",dimension::NUMERATOR);
		CHECK(a5.dimension_type == dimension::GRAM);
		dimension a6("C",dimension::NUMERATOR);
		CHECK(a6.dimension_type == dimension::COULOMB);
		dimension a7("K",dimension::NUMERATOR);
		CHECK(a7.dimension_type == dimension::KELVIN);
		dimension a8("mol",dimension::NUMERATOR);
		CHECK(a8.dimension_type == dimension::MOLE);
		dimension a9("cd",dimension::NUMERATOR);
		CHECK(a9.dimension_type == dimension::CANDELA);
		dimension a10("B",dimension::NUMERATOR);
		CHECK(a10.dimension_type == dimension::BYTE);
		dimension a11("Hz",dimension::NUMERATOR);
		CHECK(a11.dimension_type == dimension::HERTZ);
		dimension a12("N",dimension::NUMERATOR);
		CHECK(a12.dimension_type == dimension::NEWTON);
		dimension a13("Pa",dimension::NUMERATOR);
		CHECK(a13.dimension_type == dimension::PASCAL);
		dimension a14("J",dimension::NUMERATOR);
		CHECK(a14.dimension_type == dimension::JOULE);
		dimension a15("W",dimension::NUMERATOR);
		CHECK(a15.dimension_type == dimension::WATT);
		dimension a16("A",dimension::NUMERATOR);
		CHECK(a16.dimension_type == dimension::AMPERE);
		dimension a17("V",dimension::NUMERATOR);
		CHECK(a17.dimension_type == dimension::VOLT);
		dimension a18("F",dimension::NUMERATOR);
		CHECK(a18.dimension_type == dimension::FARADAY);
		dimension a19("ohm",dimension::NUMERATOR);
		CHECK(a19.dimension_type == dimension::OHM);
		dimension a19_2("Ohm",dimension::NUMERATOR);
		CHECK(a19_2.dimension_type == dimension::OHM);
		/*dimension a19_3("\U000003A9",dimension::NUMERATOR);
		CHECK(a19_3.dimension_type == dimension::OHM);*/
		dimension a20("S",dimension::NUMERATOR);
		CHECK(a20.dimension_type == dimension::SIEMENS);
		dimension a21("Wb",dimension::NUMERATOR);
		CHECK(a21.dimension_type == dimension::WEBER);
		dimension a22("T",dimension::NUMERATOR);
		CHECK(a22.dimension_type == dimension::TESLA);
		dimension a23("H",dimension::NUMERATOR);
		CHECK(a23.dimension_type == dimension::HENRY);
		dimension a24("lm",dimension::NUMERATOR);
		CHECK(a24.dimension_type == dimension::LUMEN);
		dimension a25("lx",dimension::NUMERATOR);
		CHECK(a25.dimension_type == dimension::LUX);
		dimension a26("Bq",dimension::NUMERATOR);
		CHECK(a26.dimension_type == dimension::BECQUEREL);
		dimension a27("Gy",dimension::NUMERATOR);
		CHECK(a27.dimension_type == dimension::GRAY);
		dimension a28("Sv",dimension::NUMERATOR);
		CHECK(a28.dimension_type == dimension::SIEVERT);
		dimension a29("kat",dimension::NUMERATOR);
		CHECK(a29.dimension_type == dimension::KATAL);
		dimension a30("angstrom",dimension::NUMERATOR); // MORE CASES
		CHECK(a30.dimension_type == dimension::ANGSTROM);
		dimension a31("L",dimension::NUMERATOR);
		CHECK(a31.dimension_type == dimension::LITRE);
		dimension a32("min",dimension::NUMERATOR);
		CHECK(a32.dimension_type == dimension::MINUTE);
		dimension a33("h",dimension::NUMERATOR);
		CHECK(a33.dimension_type == dimension::HOUR);
		dimension a34("d",dimension::NUMERATOR);
		CHECK(a34.dimension_type == dimension::DAY);
		dimension a35_2("ly",dimension::NUMERATOR);
		CHECK(a35_2.dimension_type == dimension::LIGHT_YEAR);
		dimension a35("AU",dimension::NUMERATOR);
		CHECK(a35.dimension_type == dimension::ASTRONOMICAL_UNIT);
		dimension a36("pc",dimension::NUMERATOR);
		CHECK(a36.dimension_type == dimension::PARSEC);
		dimension a37("eV",dimension::NUMERATOR);
		CHECK(a37.dimension_type == dimension::ELECTRON_VOLT);
		dimension a38("Da",dimension::NUMERATOR);
		CHECK(a38.dimension_type == dimension::DALTON);
		dimension a39("amu",dimension::NUMERATOR);
		CHECK(a39.dimension_type == dimension::ATOMIC_MASS_UNIT);
		dimension a40("barn",dimension::NUMERATOR);
		CHECK(a40.dimension_type == dimension::BARN);
		dimension a41("M",dimension::NUMERATOR);
		CHECK(a41.dimension_type == dimension::MOLARITY);
		dimension a42("particles",dimension::NUMERATOR);
		CHECK(a42.dimension_type == dimension::PARTICLES);
		dimension a43("money",dimension::NUMERATOR);
		CHECK(a43.dimension_type == dimension::MONEY);
		dimension a44("px",dimension::NUMERATOR);
		CHECK(a44.dimension_type == dimension::PIXEL);
		dimension a45("memo",dimension::NUMERATOR);
		CHECK(a45.dimension_type == dimension::MEMO);
		dimension a46("",dimension::NUMERATOR);
		CHECK(a46.dimension_type == dimension::NONE);
		dimension a47("hello",dimension::NUMERATOR);
		CHECK(a47.dimension_type == dimension::CUSTOM_FULL_SYMBOL);
	}

	SECTION("Assignments of dimension class")
	{
		dimension a;
		dimension b(dimension::GRAM,prefix::NONE,dimension::NUMERATOR);
		a = b;
		CHECK(a.dimension_type == dimension::GRAM);
		dimension c;
		dimension d(dimension::GRAM,prefix::NONE,dimension::NUMERATOR);
		c = std::move(d);
		CHECK(c.dimension_type == dimension::GRAM);
	}

	SECTION("Testing of length dimensions") {
		dimension a = dimension("Ym",dimension::NUMERATOR);
		CHECK(to_string(a) == "Ym");
		dimension b = dimension("Zm",dimension::NUMERATOR);
		CHECK(to_string(b) == "Zm");
		dimension c = dimension("Em",dimension::NUMERATOR);
		CHECK(to_string(c) == "Em");
		dimension d = dimension("Pm",dimension::NUMERATOR);
		CHECK(to_string(d) == "Pm");
		dimension e = dimension("Tm",dimension::NUMERATOR);
		CHECK(to_string(e) == "Tm");
		dimension f = dimension("Gm",dimension::NUMERATOR);
		CHECK(to_string(f) == "Gm");
		dimension g = dimension("Mm",dimension::NUMERATOR);
		CHECK(to_string(g) == "Mm");
		dimension h = dimension("km",dimension::NUMERATOR);
		CHECK(to_string(h) == "km");
		dimension i = dimension("hm",dimension::NUMERATOR);
		CHECK(to_string(i) == "hm");
		dimension j = dimension("dam",dimension::NUMERATOR);
		CHECK(to_string(j) == "dam");
		dimension k = dimension("dm",dimension::NUMERATOR);
		CHECK(to_string(k) == "dm");
		dimension l = dimension("cm",dimension::NUMERATOR);
		CHECK(to_string(l) == "cm");
		dimension m = dimension("mm",dimension::NUMERATOR);
		CHECK(to_string(m) == "mm");
		dimension n = dimension("um",dimension::NUMERATOR);
		CHECK(to_string(n) == "\u00B5m");
		//dimension n2 = dimension("\u00B5m",dimension::NUMERATOR);
		//cout << "n2: " << to_string(n2) << endl;
		//string n2_icu;
		//icu::UnicodeString("\u00B5m").toUTF8String(n2_icu);
		//CHECK(to_string(n2) == n2_icu);
		dimension o = dimension("nm",dimension::NUMERATOR);
		CHECK(to_string(o) == "nm");
		dimension p = dimension("pm",dimension::NUMERATOR);
		CHECK(to_string(p) == "pm");
		dimension q = dimension("fm",dimension::NUMERATOR);
		CHECK(to_string(q) == "fm");
		dimension r = dimension("am",dimension::NUMERATOR);
		CHECK(to_string(r) == "am");
		dimension s = dimension("zm",dimension::NUMERATOR);
		CHECK(to_string(s) == "zm");
		dimension t = dimension("ym",dimension::NUMERATOR);
		CHECK(to_string(t) == "ym");
	}

	SECTION ("get_name(), get_symbol(), get_conversion_factor(), is_simple_dmension(), is_basic_dimension() of dimension class")
	{
		dimension a(dimension::NONE,prefix::NONE,dimension::NUMERATOR);
		CHECK(a.get_name() == "empty");
		CHECK(a.get_symbol() == "empty");
		CHECK(a.get_conversion_factor() == 1.0l);
		CHECK(a.is_simple_dimension() == true);
		CHECK(a.is_basic_dimension() == true);
		dimension a2(dimension::METRE,prefix::NONE,dimension::NUMERATOR);
		CHECK(a2.get_name() == "metre");
		CHECK(a2.get_symbol() == "m");
		CHECK(a2.get_conversion_factor() == 1.0l);
		CHECK(a2.is_simple_dimension() == true);
		CHECK(a2.is_basic_dimension() == true);
		dimension a3_2(dimension::GRADE,prefix::NONE,dimension::NUMERATOR);
		CHECK(a3_2.get_name() == "grade");
		CHECK(a3_2.get_symbol() == "\u03B8");
		CHECK(a3_2.get_conversion_factor() == PI / 180.0l);
		CHECK(a3_2.is_simple_dimension() == true);
		CHECK(a3_2.is_basic_dimension() == true);
		dimension a3(dimension::RADIAN,prefix::NONE,dimension::NUMERATOR);
		CHECK(a3.get_name() == "radian");
		CHECK(a3.get_symbol() == "rad");
		CHECK(a3.get_conversion_factor() == 1.0l);
		CHECK(a3.is_simple_dimension() == true);
		CHECK(a3.is_basic_dimension() == true);
		dimension a4(dimension::STERADIAN,prefix::NONE,dimension::NUMERATOR);
		CHECK(a4.get_name() == "steradian");
		CHECK(a4.get_symbol() == "sr");
		CHECK(a4.get_conversion_factor() == 1.0l);
		CHECK(a4.is_simple_dimension() == true);
		CHECK(a4.is_basic_dimension() == true);
		dimension a5(dimension::SECOND,prefix::NONE,dimension::NUMERATOR);
		CHECK(a5.get_name() == "second");
		CHECK(a5.get_symbol() == "s");
		CHECK(a5.get_conversion_factor() == 1.0l);
		CHECK(a5.is_simple_dimension() == true);
		CHECK(a5.is_basic_dimension() == true);
		dimension a6(dimension::GRAM,prefix::NONE,dimension::NUMERATOR);
		CHECK(a6.get_name() == "gram");
		CHECK(a6.get_symbol() == "g");
		CHECK(a6.get_conversion_factor() == 1.0l);
		CHECK(a6.is_simple_dimension() == true);
		CHECK(a6.is_basic_dimension() == true);
		dimension a7(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR);
		CHECK(a7.get_name() == "coulomb");
		CHECK(a7.get_symbol() == "C");
		CHECK(a7.get_conversion_factor() == 1.0l);
		CHECK(a7.is_simple_dimension() == true);
		CHECK(a7.is_basic_dimension() == true);
		dimension a8(dimension::KELVIN,prefix::NONE,dimension::NUMERATOR);
		CHECK(a8.get_name() == "kelvin");
		CHECK(a8.get_symbol() == "K");
		CHECK(a8.get_conversion_factor() == 1.0l);
		CHECK(a8.is_simple_dimension() == true);
		CHECK(a8.is_basic_dimension() == true);
		dimension a9(dimension::MOLE,prefix::NONE,dimension::NUMERATOR);
		CHECK(a9.get_name() == "mole");
		CHECK(a9.get_symbol() == "mol");
		CHECK(a9.get_conversion_factor() == 1.0l);
		CHECK(a9.is_simple_dimension() == true);
		CHECK(a9.is_basic_dimension() == true);
		dimension a10(dimension::CANDELA,prefix::NONE,dimension::NUMERATOR);
		CHECK(a10.get_name() == "candela");
		CHECK(a10.get_symbol() == "cd");
		CHECK(a10.get_conversion_factor() == 1.0l);
		CHECK(a10.is_simple_dimension() == true);
		CHECK(a10.is_basic_dimension() == true);
		dimension a11(dimension::BYTE,prefix::NONE,dimension::NUMERATOR);
		CHECK(a11.get_name() == "byte");
		CHECK(a11.get_symbol() == "B");
		CHECK(a11.get_conversion_factor() == 1.0l);
		CHECK(a11.is_simple_dimension() == true);
		CHECK(a11.is_basic_dimension() == true);
		dimension a12(dimension::HERTZ,prefix::NONE,dimension::NUMERATOR);
		CHECK(a12.get_name() == "hertz");
		CHECK(a12.get_symbol() == "Hz");
		CHECK(a12.get_conversion_factor() == 1.0l);
		CHECK(a12.is_simple_dimension() == true);
		CHECK(a12.is_basic_dimension() == false);
		dimension a13(dimension::NEWTON,prefix::NONE,dimension::NUMERATOR);
		CHECK(a13.get_name() == "newton");
		CHECK(a13.get_symbol() == "N");
		CHECK(a13.get_conversion_factor() == 1.0l);
		CHECK(a13.is_simple_dimension() == false);
		CHECK(a13.is_basic_dimension() == false);
		dimension a14(dimension::PASCAL,prefix::NONE,dimension::NUMERATOR);
		CHECK(a14.get_name() == "pascal");
		CHECK(a14.get_symbol() == "Pa");
		CHECK(a14.get_conversion_factor() == 1.0l);
		CHECK(a14.is_simple_dimension() == false);
		CHECK(a14.is_basic_dimension() == false);
		dimension a15(dimension::JOULE,prefix::NONE,dimension::NUMERATOR);
		CHECK(a15.get_name() == "joule");
		CHECK(a15.get_symbol() == "J");
		CHECK(a15.get_conversion_factor() == 1.0l);
		CHECK(a15.is_simple_dimension() == false);
		CHECK(a15.is_basic_dimension() == false);
		dimension a16(dimension::WATT,prefix::NONE,dimension::NUMERATOR);
		CHECK(a16.get_name() == "watt");
		CHECK(a16.get_symbol() == "W");
		CHECK(a16.get_conversion_factor() == 1.0l);
		CHECK(a16.is_simple_dimension() == false);
		CHECK(a16.is_basic_dimension() == false);
		dimension a17(dimension::AMPERE,prefix::NONE,dimension::NUMERATOR);
		CHECK(a17.get_name() == "ampere");
		CHECK(a17.get_symbol() == "A");
		CHECK(a17.get_conversion_factor() == 1.0l);
		CHECK(a17.is_simple_dimension() == true);
		CHECK(a17.is_basic_dimension() == false);
		dimension a18(dimension::VOLT,prefix::NONE,dimension::NUMERATOR);
		CHECK(a18.get_name() == "volt");
		CHECK(a18.get_symbol() == "V");
		CHECK(a18.get_conversion_factor() == 1.0l);
		CHECK(a18.is_simple_dimension() == false);
		CHECK(a18.is_basic_dimension() == false);
		dimension a19(dimension::FARADAY,prefix::NONE,dimension::NUMERATOR);
		CHECK(a19.get_name() == "faraday");
		CHECK(a19.get_symbol() == "F");
		CHECK(a19.get_conversion_factor() == 1.0l);
		CHECK(a19.is_simple_dimension() == false);
		CHECK(a19.is_basic_dimension() == false);
		dimension a20(dimension::OHM,prefix::NONE,dimension::NUMERATOR);
		CHECK(a20.get_name() == "ohm");
		CHECK(a20.get_symbol() == "\U000003A9");
		CHECK(a20.get_conversion_factor() == 1.0l);
		CHECK(a20.is_simple_dimension() == false);
		CHECK(a20.is_basic_dimension() == false);
		dimension a21(dimension::SIEMENS,prefix::NONE,dimension::NUMERATOR);
		CHECK(a21.get_name() == "siemens");
		CHECK(a21.get_symbol() == "S");
		CHECK(a21.get_conversion_factor() == 1.0l);
		CHECK(a21.is_simple_dimension() == false);
		CHECK(a21.is_basic_dimension() == false);
		dimension a22(dimension::WEBER,prefix::NONE,dimension::NUMERATOR);
		CHECK(a22.get_name() == "weber");
		CHECK(a22.get_symbol() == "Wb");
		CHECK(a22.get_conversion_factor() == 1.0l);
		CHECK(a22.is_simple_dimension() == false);
		CHECK(a22.is_basic_dimension() == false);
		dimension a23(dimension::TESLA,prefix::NONE,dimension::NUMERATOR);
		CHECK(a23.get_name() == "tesla");
		CHECK(a23.get_symbol() == "T");
		CHECK(a23.get_conversion_factor() == 1.0l);
		CHECK(a23.is_simple_dimension() == false);
		CHECK(a23.is_basic_dimension() == false);
		dimension a24(dimension::HENRY,prefix::NONE,dimension::NUMERATOR);
		CHECK(a24.get_name() == "henry");
		CHECK(a24.get_symbol() == "H");
		CHECK(a24.get_conversion_factor() == 1.0l);
		CHECK(a24.is_simple_dimension() == false);
		CHECK(a24.is_basic_dimension() == false);
		dimension a25(dimension::LUMEN,prefix::NONE,dimension::NUMERATOR);
		CHECK(a25.get_name() == "lumen");
		CHECK(a25.get_symbol() == "lm");
		CHECK(a25.get_conversion_factor() == 1.0l);
		CHECK(a25.is_simple_dimension() == false);
		CHECK(a25.is_basic_dimension() == false);
		dimension a26(dimension::LUX,prefix::NONE,dimension::NUMERATOR);
		CHECK(a26.get_name() == "lux");
		CHECK(a26.get_symbol() == "lx");
		CHECK(a26.get_conversion_factor() == 1.0l);
		CHECK(a26.is_simple_dimension() == false);
		CHECK(a26.is_basic_dimension() == false);
		dimension a27(dimension::BECQUEREL,prefix::NONE,dimension::NUMERATOR);
		CHECK(a27.get_name() == "becquerel");
		CHECK(a27.get_symbol() == "Bq");
		CHECK(a27.get_conversion_factor() == 1.0l);
		CHECK(a27.is_simple_dimension() == true);
		CHECK(a27.is_basic_dimension() == false);
		dimension a28(dimension::GRAY,prefix::NONE,dimension::NUMERATOR);
		CHECK(a28.get_name() == "gray");
		CHECK(a28.get_symbol() == "Gy");
		CHECK(a28.get_conversion_factor() == 1.0l);
		CHECK(a28.is_simple_dimension() == false);
		CHECK(a28.is_basic_dimension() == false);
		dimension a29(dimension::SIEVERT,prefix::NONE,dimension::NUMERATOR);
		CHECK(a29.get_name() == "sievert");
		CHECK(a29.get_symbol() == "Sv");
		CHECK(a29.get_conversion_factor() == 1.0l);
		CHECK(a29.is_simple_dimension() == false);
		CHECK(a29.is_basic_dimension() == false);
		dimension a30(dimension::KATAL,prefix::NONE,dimension::NUMERATOR);
		CHECK(a30.get_name() == "katal");
		CHECK(a30.get_symbol() == "kat");
		CHECK(a30.get_conversion_factor() == 1.0l);
		CHECK(a30.is_simple_dimension() == false);
		CHECK(a30.is_basic_dimension() == false);
		dimension a31(dimension::ANGSTROM,prefix::NONE,dimension::NUMERATOR);
		CHECK(a31.get_name() == "angstrom");
		CHECK(a31.get_symbol() == "\U0000212B");
		CHECK(a31.get_conversion_factor() == 1.0l);
		CHECK(a31.is_simple_dimension() == true);
		CHECK(a31.is_basic_dimension() == false);
		dimension a32(dimension::LITRE,prefix::NONE,dimension::NUMERATOR);
		CHECK(a32.get_name() == "litre");
		CHECK(a32.get_symbol() == "L");
		CHECK(a32.get_conversion_factor() == 1.0l);
		CHECK(a32.is_simple_dimension() == false);
		CHECK(a32.is_basic_dimension() == false);
		dimension a33(dimension::MINUTE,prefix::NONE,dimension::NUMERATOR);
		CHECK(a33.get_name() == "minute");
		CHECK(a33.get_symbol() == "min");
		CHECK(a33.get_conversion_factor() == 60.0l);
		CHECK(a33.is_simple_dimension() == true);
		CHECK(a33.is_basic_dimension() == false);
		dimension a34(dimension::HOUR,prefix::NONE,dimension::NUMERATOR);
		CHECK(a34.get_name() == "hour");
		CHECK(a34.get_symbol() == "h");
		CHECK(a34.get_conversion_factor() == 3600.0l);
		CHECK(a34.is_simple_dimension() == true);
		CHECK(a34.is_basic_dimension() == false);
		dimension a35(dimension::DAY,prefix::NONE,dimension::NUMERATOR);
		CHECK(a35.get_name() == "day");
		CHECK(a35.get_symbol() == "d");
		CHECK(a35.get_conversion_factor() == 86400.0l);
		CHECK(a35.is_simple_dimension() == true);
		CHECK(a35.is_basic_dimension() == false);
		dimension a36_2(dimension::LIGHT_YEAR,prefix::NONE,dimension::NUMERATOR);
		CHECK(a36_2.get_name() == "light year");
		CHECK(a36_2.get_symbol() == "ly");
		CHECK(a36_2.get_conversion_factor() == 9.4607379375591e15);
		CHECK(a36_2.is_simple_dimension() == true);
		CHECK(a36_2.is_basic_dimension() == false);
		dimension a36(dimension::ASTRONOMICAL_UNIT,prefix::NONE,dimension::NUMERATOR);
		CHECK(a36.get_name() == "astronomical unit");
		CHECK(a36.get_symbol() == "AU");
		CHECK(a36.get_conversion_factor() == 149597870700.0l);
		CHECK(a36.is_simple_dimension() == true);
		CHECK(a36.is_basic_dimension() == false);
		dimension a37(dimension::PARSEC,prefix::NONE,dimension::NUMERATOR);
		CHECK(a37.get_name() == "parsec");
		CHECK(a37.get_symbol() == "pc");
		CHECK(a37.get_conversion_factor() == 30856775814913673.0l);
		CHECK(a37.is_simple_dimension() == true);
		CHECK(a37.is_basic_dimension() == false);
		dimension a38(dimension::ELECTRON_VOLT,prefix::NONE,dimension::NUMERATOR);
		CHECK(a38.get_name() == "electronvolt");
		CHECK(a38.get_symbol() == "eV");
		CHECK(a38.get_conversion_factor() == 0.0000000000000000001602176634l);
		CHECK(a38.is_simple_dimension() == false);
		CHECK(a38.is_basic_dimension() == false);
		dimension a39(dimension::DALTON,prefix::NONE,dimension::NUMERATOR);
		CHECK(a39.get_name() == "dalton");
		CHECK(a39.get_symbol() == "Da");
		CHECK(a39.get_conversion_factor() == 0.00000000000000000000000000166053886l);
		CHECK(a39.is_simple_dimension() == true);
		CHECK(a39.is_basic_dimension() == false);
		dimension a40(dimension::ATOMIC_MASS_UNIT,prefix::NONE,dimension::NUMERATOR);
		CHECK(a40.get_name() == "atomic mass unit");
		CHECK(a40.get_symbol() == "amu");
		CHECK(a40.get_conversion_factor() == 0.00000000000000000000000000166053886l);
		CHECK(a40.is_simple_dimension() == true);
		CHECK(a40.is_basic_dimension() == false);
		dimension a41(dimension::BARN,prefix::NONE,dimension::NUMERATOR);
		CHECK(a41.get_name() == "barn");
		CHECK(a41.get_symbol() == "barn");
		CHECK(a41.get_conversion_factor() == 0.0000000000000000000000000001l);
		CHECK(a41.is_simple_dimension() == false);
		CHECK(a41.is_basic_dimension() == false);
		dimension a42(dimension::MOLARITY,prefix::NONE,dimension::NUMERATOR);
		CHECK(a42.get_name() == "molarity");
		CHECK(a42.get_symbol() == "M");
		CHECK(a42.get_conversion_factor() == 1.0l);
		CHECK(a42.is_simple_dimension() == false);
		CHECK(a42.is_basic_dimension() == false);
		dimension a43(dimension::PARTICLES,prefix::NONE,dimension::NUMERATOR);
		CHECK(a43.get_name() == "particles");
		CHECK(a43.get_symbol() == "particles");
		CHECK(a43.get_conversion_factor() == 1l/AVOGADRO_CONSTANT);
		CHECK(a43.is_simple_dimension() == true);
		CHECK(a43.is_basic_dimension() == false);
		/*dimension a44("hello",dimension::NUMERATOR);
		CHECK(a44.get_name() == "custom-dimension");
		CHECK(a44.get_symbol() == "hello");
		CHECK(a44.get_conversion_factor() == 1.0);
		CHECK(a44.is_simple_dimension() == false);
		CHECK(a44.is_basic_dimension() == false);
		dimension a45(dimension::CUSTOM_BASIC,prefix::NONE,dimension::NUMERATOR);
		CHECK(a45.get_name() == "custom-basic");
		CHECK(a45.get_symbol() == "custom-basic");
		CHECK(a45.get_conversion_factor() == 1.0);
		CHECK(a45.is_simple_dimension() == false);
		CHECK(a45.is_basic_dimension() == false);
		dimension a46(dimension::CUSTOM_FULL_SYMBOL,prefix::NONE,dimension::NUMERATOR);
		CHECK(a46.get_name() == "custom-full-symbol");
		CHECK(a46.get_symbol() == "");
		CHECK(a46.get_conversion_factor() == 1.0);
		CHECK(a46.is_simple_dimension() == false);
		CHECK(a46.is_basic_dimension() == false);*/
		dimension a47(dimension::MONEY,prefix::NONE,dimension::NUMERATOR);
		CHECK(a47.get_name() == "money");
		CHECK(a47.get_symbol() == "money");
		CHECK(a47.get_conversion_factor() == 1.0l);
		CHECK(a47.is_simple_dimension() == true);
		CHECK(a47.is_basic_dimension() == true);
		dimension a48(dimension::PIXEL,prefix::NONE,dimension::NUMERATOR);
		CHECK(a48.get_name() == "pixel");
		CHECK(a48.get_symbol() == "px");
		CHECK(a48.get_conversion_factor() == 0.00026l);
		CHECK(a48.is_simple_dimension() == true);
		CHECK(a48.is_basic_dimension() == false);
		dimension a49(dimension::MEMO,prefix::NONE,dimension::NUMERATOR);
		CHECK(a49.get_name() == "memo");
		CHECK(a49.get_symbol() == "memo");
		CHECK(a49.get_conversion_factor() == 1.0l);
		CHECK(a49.is_simple_dimension() == true);
		CHECK(a49.is_basic_dimension() == true);
	}

	SECTION ("get_basic_dimensions() of dimension class")
	{
		dimension a0("",dimension::NUMERATOR);
		vector<dimension> b0 = { dimension(dimension::NONE,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a0.get_basic_dimensions(),b0));
		dimension a("m",dimension::NUMERATOR);
		vector<dimension> b = { dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a.get_basic_dimensions(),b));
		dimension a2_2("grade",dimension::NUMERATOR);
		vector<dimension> b2_2 = { dimension(dimension::RADIAN,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a2_2.get_basic_dimensions(),b2_2));
		dimension a2("rad",dimension::NUMERATOR);
		vector<dimension> b2 = { dimension(dimension::RADIAN,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a2.get_basic_dimensions(),b2));
		dimension a3("sr",dimension::NUMERATOR);
		vector<dimension> b3 = { dimension(dimension::STERADIAN,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a3.get_basic_dimensions(),b3));
		dimension a4("s",dimension::NUMERATOR);
		vector<dimension> b4 = { dimension(dimension::SECOND,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a4.get_basic_dimensions(),b4));
		dimension a5("g",dimension::NUMERATOR);
		vector<dimension> b5 = { dimension(dimension::GRAM,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a5.get_basic_dimensions(),b5));
		dimension a6("C",dimension::NUMERATOR);
		vector<dimension> b6 = { dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a6.get_basic_dimensions(),b6));
		dimension a7("K",dimension::NUMERATOR);
		vector<dimension> b7 = { dimension(dimension::KELVIN,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a7.get_basic_dimensions(),b7));
		dimension a8("mol",dimension::NUMERATOR);
		vector<dimension> b8 = { dimension(dimension::MOLE,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a8.get_basic_dimensions(),b8));
		dimension a9("cd",dimension::NUMERATOR);
		vector<dimension> b9 = { dimension(dimension::CANDELA,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a9.get_basic_dimensions(),b9));
		dimension a10("B",dimension::NUMERATOR);
		vector<dimension> b10 = { dimension(dimension::BYTE,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a10.get_basic_dimensions(),b10));
		dimension a11("Hz",dimension::NUMERATOR);
		vector<dimension> b11 = { dimension(dimension::HERTZ,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a11.get_basic_dimensions(),b11));
		dimension a12("N",dimension::NUMERATOR);
		vector<dimension> b12 = { dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR) };
		CHECK(equal_dimensions(a12.get_basic_dimensions(),b12));
		dimension a13("Pa",dimension::NUMERATOR);
		vector<dimension> b13 = { dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR) };
		CHECK(equal_dimensions(a13.get_basic_dimensions(),b13));
		dimension a14("J",dimension::NUMERATOR);
		vector<dimension> b14 = { dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR) };
		CHECK(equal_dimensions(a14.get_basic_dimensions(),b14));
		dimension a15("W",dimension::NUMERATOR);
		vector<dimension> b15 = { dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR) };
		CHECK(equal_dimensions(a15.get_basic_dimensions(),b15));
		dimension a16("A",dimension::NUMERATOR);
		vector<dimension> b16 = { dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR) };
		CHECK(equal_dimensions(a16.get_basic_dimensions(),b16));
		dimension a17("V",dimension::NUMERATOR);
		vector<dimension> b17 = { dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR) };
		CHECK(equal_dimensions(a17.get_basic_dimensions(),b17));
		dimension a18("F",dimension::NUMERATOR);
		vector<dimension> b18 = { dimension(dimension::GRAM,prefix::KILO,dimension::DENOMINATOR),
				dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR),
				dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR),
				dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR),
				dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR),
				dimension(dimension::SECOND,prefix::NONE,dimension::NUMERATOR),
				dimension(dimension::SECOND,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a18.get_basic_dimensions(),b18));
		dimension a19("Ohm",dimension::NUMERATOR);
		vector<dimension> b19 = { dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR) };
		CHECK(equal_dimensions(a19.get_basic_dimensions(),b19));
		dimension a20("S",dimension::NUMERATOR);
		vector<dimension> b20 = { dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::GRAM,prefix::KILO,dimension::DENOMINATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR) };
		CHECK(equal_dimensions(a20.get_basic_dimensions(),b20));
		dimension a21("Wb",dimension::NUMERATOR);
		vector<dimension> b21 = { dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR) };
		CHECK(equal_dimensions(a21.get_basic_dimensions(),b21));
		dimension a22("T",dimension::NUMERATOR);
		vector<dimension> b22 = { dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR),
			dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR) };
		CHECK(equal_dimensions(a22.get_basic_dimensions(),b22));
		dimension a23("H",dimension::NUMERATOR);
		vector<dimension> b23 = { dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::COULOMB,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a23.get_basic_dimensions(),b23));
		dimension a24("lm",dimension::NUMERATOR);
		vector<dimension> b24 = { dimension(dimension::CANDELA,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::STERADIAN,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a24.get_basic_dimensions(),b24));
		dimension a25("lx",dimension::NUMERATOR);
		vector<dimension> b25 = { dimension(dimension::CANDELA,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::STERADIAN,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR) };
		CHECK(equal_dimensions(a25.get_basic_dimensions(),b25));
		dimension a26("Bq",dimension::NUMERATOR);
		vector<dimension> b26 = { dimension(dimension::BECQUEREL,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a26.get_basic_dimensions(),b26));
		dimension a27("Gy",dimension::NUMERATOR);
		vector<dimension> b27 = { dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR) };
		CHECK(equal_dimensions(a27.get_basic_dimensions(),b27));
		dimension a28("Sv",dimension::NUMERATOR);
		vector<dimension> b28 = { dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR) };
		CHECK(equal_dimensions(a28.get_basic_dimensions(),b28));
		dimension a29("kat",dimension::NUMERATOR);
		vector<dimension> b29 = { dimension(dimension::MOLE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR) };
		CHECK(equal_dimensions(a29.get_basic_dimensions(),b29));
		dimension a30("angstrom",dimension::NUMERATOR);
		vector<dimension> b30 = { dimension(dimension::ANGSTROM,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a30.get_basic_dimensions(),b30));
		dimension a31("L",dimension::NUMERATOR);
		vector<dimension> b31 = { dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a31.get_basic_dimensions(),b31));
		dimension a32("min",dimension::NUMERATOR);
		vector<dimension> b32 = { dimension(dimension::MINUTE,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a32.get_basic_dimensions(),b32));
		dimension a33("h",dimension::NUMERATOR);
		vector<dimension> b33 = { dimension(dimension::HOUR,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a33.get_basic_dimensions(),b33));
		dimension a34("d",dimension::NUMERATOR);
		vector<dimension> b34 = { dimension(dimension::DAY,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a34.get_basic_dimensions(),b34));
		dimension a35_2("ly",dimension::NUMERATOR);
		vector<dimension> b35_2 = { dimension(dimension::LIGHT_YEAR,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a35_2.get_basic_dimensions(),b35_2));
		dimension a35("AU",dimension::NUMERATOR);
		vector<dimension> b35 = { dimension(dimension::ASTRONOMICAL_UNIT,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a35.get_basic_dimensions(),b35));
		dimension a36("pc",dimension::NUMERATOR);
		vector<dimension> b36 = { dimension(dimension::PARSEC,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a36.get_basic_dimensions(),b36));
		dimension a37("eV",dimension::NUMERATOR);
		vector<dimension> b37 = { dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::GRAM,prefix::KILO,dimension::NUMERATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR),
			dimension(dimension::SECOND,prefix::NONE,dimension::DENOMINATOR) };
		CHECK(equal_dimensions(a37.get_basic_dimensions(),b37));
		dimension a38("Da",dimension::NUMERATOR);
		vector<dimension> b38 = { dimension(dimension::DALTON,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a38.get_basic_dimensions(),b38));
		dimension a39("amu",dimension::NUMERATOR);
		vector<dimension> b39 = { dimension(dimension::ATOMIC_MASS_UNIT,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a39.get_basic_dimensions(),b39));
		dimension a40("barn",dimension::NUMERATOR);
		vector<dimension> b40 = { dimension(dimension::BARN,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a40.get_basic_dimensions(),b40));
		dimension a41("M",dimension::NUMERATOR);
		vector<dimension> b41 = { dimension(dimension::MOLE,prefix::NONE,dimension::NUMERATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR),
			dimension(dimension::METRE,prefix::NONE,dimension::DENOMINATOR) };
		CHECK(equal_dimensions(a41.get_basic_dimensions(),b41));
		dimension a42("particles",dimension::NUMERATOR);
		vector<dimension> b42 = { dimension(dimension::PARTICLES,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a42.get_basic_dimensions(),b42));
		dimension a43("money",dimension::NUMERATOR);
		vector<dimension> b43 = { dimension(dimension::MONEY,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a43.get_basic_dimensions(),b43));
		dimension a44("px",dimension::NUMERATOR);
		vector<dimension> b44 = { dimension(dimension::PIXEL,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a44.get_basic_dimensions(),b44));
		dimension a45("memo",dimension::NUMERATOR);
		vector<dimension> b45 = { dimension(dimension::MEMO,prefix::NONE,dimension::NUMERATOR) };
		CHECK(equal_dimensions(a45.get_basic_dimensions(),b45));
	}

	SECTION ("Constructor of custom dimensions")
	{
		dimension a("usd",dimension::NUMERATOR);
		vector<dimension> b = { dimension("usd",dimension::NUMERATOR) };
		CHECK(a.get_name() == "custom-dimension");
		CHECK(a.get_symbol() == "usd");
		CHECK(a.get_conversion_factor() == 1.0l);
		CHECK(a.is_simple_dimension() == false);
		CHECK(a.is_basic_dimension() == false);
		CHECK(equal_dimensions(a.get_basic_dimensions(),b));
		dimension a2("long-dimension",dimension::NUMERATOR);
		vector<dimension> b2 = { dimension("long-dimension",dimension::NUMERATOR) };
		CHECK(a2.get_name() == "custom-full-symbol");
		CHECK(a2.get_symbol() == "long-dimension");
		CHECK(a2.get_conversion_factor() == 1.0l);
		CHECK(a2.is_simple_dimension() == false);
		CHECK(a2.is_basic_dimension() == false);
		CHECK(equal_dimensions(a2.get_basic_dimensions(),b2));
	}

	SECTION ("create_custom_dimension(), create_full_symbol() and get_full_symbol() of dimension class")
	{
		dimension::create_custom_dimension("hello","m*s");
		/*char symbol[3];
		string full_symbol = dimension::create_full_symbol("symbol1");
		cout << "full symbol: " << full_symbol << endl;
		cout << "length: " << full_symbol.length() << endl;*/
		//full_symbol.copy(symbol, full_symbol.length() - 1);
		/*CHECK(dimension::get_full_symbol(symbol) == "symbol1");*/
	}

	SECTION("to_string() of dimension class")
	{
		vector<dimension> a = create_dimensions("m*s2/C4");
		CHECK(to_string(a) == "m*s2/C4");
		CHECK(to_string(a,true) == "[m*s2/C4]");
		vector<dimension> b = create_dimensions("1/m");
		CHECK(to_string(b) == "1/m");
		CHECK(to_string(b,true) == "[1/m]");
		dimension c("km",dimension::NUMERATOR);
		CHECK(to_string(c) == "km");
	}

	SECTION ("create_dimensions(), create_derived_dimensions() and normalize_dimensions()") {
		vector<dimension> a = create_dimensions("m*s2/C4");
		CHECK(to_string(a) == "m*s2/C4");
		CHECK(equal_dimensions(to_string(a),"s2*m/C4"));
		CHECK(equal_dimensions(to_string(a),"s2*m/C3*C"));
		vector<dimension> b = create_dimensions("1/C2");
		CHECK(to_string(b) == "1/C2");
		vector<dimension> c = create_dimensions("m");
		CHECK(to_string(c) == "m");
		vector<dimension> d = create_dimensions("m3");
		CHECK(to_string(d) == "m3");
		vector<dimension> e = create_derived_dimensions("N");
		CHECK(to_string(e) == "kg*m/s2");
		vector<dimension> f = create_derived_dimensions("N2");
		CHECK(to_string(f) == "kg2*m2/s4");
		vector<dimension> g = create_dimensions("N");
		vector<dimension> h = create_derived_dimensions(g);
		CHECK(to_string(h) == "kg*m/s2");
		vector<dimension> i = create_dimensions("1/N");
		vector<dimension> j = create_derived_dimensions(i);
		CHECK(to_string(j) == "s2/kg*m");
		vector<dimension> k = create_dimensions("h");
		long double k2 = 10;
		vector<dimension> l = create_derived_dimensions(k,k2);
		CHECK(equal_dimensions(k,l));
		CHECK(k2 == 36000);
		vector<dimension> r = create_dimensions("1/h");
		long double r2 = 10;
		vector<dimension> s = create_derived_dimensions(r,r2);
		CHECK(equal_dimensions(r,s));
		CHECK(std::fabs(r2 - 0.00277778l) < 0.00000001l);
		vector<dimension> m = create_dimensions("m*s2/m2*C4");
		vector<dimension> n = normalize_dimensions(m);
		CHECK(to_string(n) == "s2/m*C4");
		vector<dimension> o = create_dimensions("kN");
		long double o2 = 1.0;
		vector<dimension> p = normalize_dimensions(o,o2);
		CHECK(o2 == 1000.0);
		CHECK(to_string(p) == "kg*m/s2");
		vector<dimension> t = create_dimensions("m2*s2/m4*C3");
		vector<dimension> u = normalize_dimensions(t);
		CHECK(to_string(u) == "s2/m2*C3");
	}

	SECTION ("prefix_math() of dimesion_class")
	{
		dimension a("km",dimension::NUMERATOR);
		CHECK(a.prefix_math() == 1000);
		dimension b("kB",dimension::NUMERATOR);
		CHECK(b.prefix_math() == 1024);
	}

	SECTION ("multiply_dimensions(), divide_dimensions(), square_dimensions() and power_dimensions() of dimension class")
	{
		vector<dimension> a0 = create_dimensions("m");
		vector<dimension> b0 = create_dimensions("N");
		vector<dimension> c0 = multiply_dimensions(a0,b0);
		CHECK(to_string(c0) == "m*N");
		vector<dimension> a = create_dimensions("m");
		vector<dimension> b = create_dimensions("N");
		long double a2 = 1.0;
		vector<dimension> c = multiply_dimensions(a,b,a2);
		vector<dimension> d = create_dimensions("kg*m2/s2");
		CHECK(equal_dimensions(c,d) == true);
		CHECK(a2 == 1);
		vector<dimension> e = create_dimensions("g");
		vector<dimension> f = create_dimensions("h");
		long double e2 = 1.0;
		vector<dimension> g = multiply_dimensions(e,f,e2);
		vector<dimension> h = create_dimensions("g*s");
		CHECK(equal_dimensions(g,h) == true);
		CHECK(e2 == 3600);
		vector<dimension> i = create_dimensions("g/s");
		vector<dimension> j = create_dimensions("h");
		long double i2 = 1.0;
		vector<dimension> k = multiply_dimensions(i,j,i2);
		vector<dimension> l = create_dimensions("g");
		CHECK(equal_dimensions(k,l) == true);
		CHECK(i2 == 3600);
		vector<dimension> m = create_dimensions("g*h");
		vector<dimension> n = create_dimensions("s");
		long double m2 = 1.0;
		vector<dimension> o = divide_dimensions(m,n,m2);
		vector<dimension> p = create_dimensions("g");
		CHECK(equal_dimensions(o,p) == true);
		CHECK(m2 == 3600);
		vector<dimension> q = create_dimensions("g*kh");
		vector<dimension> r = create_dimensions("s");
		long double q2 = 1.0;
		vector<dimension> s = divide_dimensions(q,r,q2);
		vector<dimension> t = create_dimensions("g");
		CHECK(equal_dimensions(s,t) == true);
		CHECK(q2 == 3600000);
		vector<dimension> u = create_dimensions("kg*m");
		vector<dimension> v = power_dimensions(u,2);
		vector<dimension> w = create_dimensions("kg2*m2");
		CHECK(equal_dimensions(v,w) == true);
		vector<dimension> x = create_dimensions("C/mol");
		vector<dimension> y = power_dimensions(x,5);
		vector<dimension> z = create_dimensions("C5/mol5");
		CHECK(equal_dimensions(y,z) == true);
		vector<dimension> aa = create_dimensions("m2/s2");
		long double aa2 = 1.0;
		vector<dimension> ab = square_dimensions(aa,aa2,2);
		vector<dimension> ac = create_dimensions("m/s");
		CHECK(equal_dimensions(ab,ac) == true);
		CHECK(aa2 == 1);
		vector<dimension> ad = create_dimensions("h2/m2");
		long double ad2 = 1.0;
		vector<dimension> ae = square_dimensions(ad,ad2,2);
		vector<dimension> af = create_dimensions("s/m");
		CHECK(equal_dimensions(ae,af) == true);
		CHECK(ad2 == 12960000.0);
		vector<dimension> ag = create_dimensions("h4");
		long double ag2 = 1.0;
		vector<dimension> ah = square_dimensions(ag,ag2,4);
		vector<dimension> ai = create_dimensions("s");
		CHECK(equal_dimensions(ah,ai) == true);
		CHECK(ag2 == 167961600000000.0);
		vector<dimension> aj = create_dimensions("s3");
		long double aj2 = 1.0;
		vector<dimension> ak = square_dimensions(aj,aj2,2);
		CHECK(ak.size() == 0);
		CHECK(aj2 == 1.0);
		vector<dimension> al = create_dimensions("1/s2");
		long double al2 = 4.0;
		vector<dimension> am = square_dimensions(al,al2,2);
		vector<dimension> an = create_dimensions("1/s");
		CHECK(equal_dimensions(am,an) == true);
		CHECK(al2 == 4.0);
	}

	SECTION("common_dimension(), equal_dimensions() and equal_dimensions_and_prefixes()")
	{
		dimension a(dimension::METRE,prefix::NONE,dimension::NUMERATOR);
		dimension b(dimension::ASTRONOMICAL_UNIT,prefix::NONE,dimension::NUMERATOR);
		CHECK(common_dimension(a,b) == true);
		CHECK(equal_dimensions("m","AU") == true);
		CHECK(equal_dimensions("m","pc") == true);
		dimension a2(dimension::GRAM,prefix::NONE,dimension::NUMERATOR);
		CHECK(common_dimension(a,a2) == false);
		vector<dimension> c = create_dimensions("m/s");
		vector<dimension> d = create_dimensions("AU/s");
		vector<dimension> e = create_dimensions("pc/s");
		vector<dimension> f = create_dimensions("km/s");
		CHECK(equal_dimensions(c,d) == true);
		CHECK(equal_dimensions(c,e) == true);
		CHECK(equal_dimensions(d,e) == true);
		CHECK(equal_dimensions_and_prefixes(c,d) == false);
		CHECK(equal_dimensions_and_prefixes(c,e) == false);
		CHECK(equal_dimensions_and_prefixes(c,f) == false);
	}

	SECTION("Comparison of dimension class")
	{
		dimension a(dimension::METRE,prefix::NONE,dimension::NUMERATOR);
		dimension b(dimension::METRE,prefix::NONE,dimension::NUMERATOR);
		dimension c(dimension::ASTRONOMICAL_UNIT,prefix::NONE,dimension::NUMERATOR);
		dimension d(dimension::METRE,prefix::NONE,dimension::DENOMINATOR);
		CHECK((a == b) == true);
		CHECK((a != c) == true);
		CHECK((a == c) == false);
		CHECK((a == d) == false);
		CHECK((a != d) == true);
	}

	SECTION ("Testing of custom dimensions") {
		dimension::create_custom_dimension("custom_dimension","m*s");
		dimension a = dimension("custom_dimension",dimension::NUMERATOR);
		vector<dimension> b = create_dimensions("m*s");
		CHECK(a.get_symbol() == "custom_dimension");
		CHECK(equal_dimensions(a.get_basic_dimensions(),b));
		dimension::create_custom_dimension("uUu","g*m*s");
		dimension c = dimension("uUu",dimension::NUMERATOR);
		vector<dimension> d = create_dimensions("g*m*s");
		CHECK(c.get_symbol() == "uUu");
		CHECK(equal_dimensions(c.get_basic_dimensions(),d));
	}
}
