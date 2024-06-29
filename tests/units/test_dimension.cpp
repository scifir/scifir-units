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
		dimension a = dimension("m",dimension::POSITIVE);
		CHECK(a.dimension_type == dimension::m);
		CHECK(a.dimension_sign == dimension::POSITIVE);
		CHECK(a.prefix.prefix_type == prefix::no_prefix);
		CHECK(a.get_symbol() == "m");
		dimension b = dimension("m",dimension::NEGATIVE);
		CHECK(b.dimension_sign == dimension::NEGATIVE);
	}

	SECTION("Constructors of dimension class")
	{
		dimension a;
		CHECK(a.dimension_type == dimension::NONE);
		dimension b2(dimension::m,prefix::no_prefix,dimension::POSITIVE);
		dimension b(b2);
		CHECK(b.dimension_type == dimension::m);
		dimension c2(dimension::m,prefix::no_prefix,dimension::POSITIVE);
		dimension c(std::move(c2));
		CHECK(c.dimension_type == dimension::m);
		dimension d(dimension::m,prefix::k,dimension::POSITIVE);
		CHECK(to_string(d) == "km");
		prefix e2(prefix::k);
		dimension e(dimension::m,e2,dimension::POSITIVE);
		CHECK(to_string(e) == "km");
	}

	SECTION("Creation of basic dimension class") {
		dimension a = dimension("m",dimension::POSITIVE);
		CHECK(a.get_symbol() == "m");
		dimension b = dimension("s",dimension::POSITIVE);
		CHECK(b.get_symbol() == "s");
		dimension c = dimension("g",dimension::POSITIVE);
		CHECK(c.get_symbol() == "g");
		dimension d = dimension("C",dimension::POSITIVE);
		CHECK(d.get_symbol() == "C");
		dimension e = dimension("K",dimension::POSITIVE);
		CHECK(e.get_symbol() == "K");
		dimension f = dimension("mol",dimension::POSITIVE);
		CHECK(f.get_symbol() == "mol");
		dimension g = dimension("cd",dimension::POSITIVE);
		CHECK(g.get_symbol() == "cd");
		dimension h = dimension("B",dimension::POSITIVE);
		CHECK(h.get_symbol() == "B");
		dimension i = dimension("rad",dimension::POSITIVE);
		CHECK(i.get_symbol() == "rad");
		dimension j = dimension("sr",dimension::POSITIVE);
		CHECK(j.get_symbol() == "sr");
		dimension k = dimension("money",dimension::POSITIVE);
		CHECK(k.get_symbol() == "money");
		dimension l = dimension("memo",dimension::POSITIVE);
		CHECK(l.get_symbol() == "memo");
	}

	SECTION("Creation of all dimension types")
	{
		dimension a("m",dimension::POSITIVE);
		CHECK(a.dimension_type == dimension::m);
		dimension a1_2("grade",dimension::POSITIVE);
		CHECK(a1_2.dimension_type == dimension::grade);
		dimension a2("rad",dimension::POSITIVE);
		CHECK(a2.dimension_type == dimension::radian);
		dimension a3("sr",dimension::POSITIVE);
		CHECK(a3.dimension_type == dimension::steradian);
		dimension a4("s",dimension::POSITIVE);
		CHECK(a4.dimension_type == dimension::s);
		dimension a5("g",dimension::POSITIVE);
		CHECK(a5.dimension_type == dimension::g);
		dimension a6("C",dimension::POSITIVE);
		CHECK(a6.dimension_type == dimension::C);
		dimension a7("K",dimension::POSITIVE);
		CHECK(a7.dimension_type == dimension::K);
		dimension a8("mol",dimension::POSITIVE);
		CHECK(a8.dimension_type == dimension::mol);
		dimension a9("cd",dimension::POSITIVE);
		CHECK(a9.dimension_type == dimension::cd);
		dimension a10("B",dimension::POSITIVE);
		CHECK(a10.dimension_type == dimension::B);
		dimension a11("Hz",dimension::POSITIVE);
		CHECK(a11.dimension_type == dimension::Hz);
		dimension a12("N",dimension::POSITIVE);
		CHECK(a12.dimension_type == dimension::N);
		dimension a13("Pa",dimension::POSITIVE);
		CHECK(a13.dimension_type == dimension::Pa);
		dimension a14("J",dimension::POSITIVE);
		CHECK(a14.dimension_type == dimension::J);
		dimension a15("W",dimension::POSITIVE);
		CHECK(a15.dimension_type == dimension::W);
		dimension a16("A",dimension::POSITIVE);
		CHECK(a16.dimension_type == dimension::A);
		dimension a17("V",dimension::POSITIVE);
		CHECK(a17.dimension_type == dimension::V);
		dimension a18("F",dimension::POSITIVE);
		CHECK(a18.dimension_type == dimension::F);
		dimension a19("ohm",dimension::POSITIVE);
		CHECK(a19.dimension_type == dimension::Ohm);
		dimension a19_2("Ohm",dimension::POSITIVE);
		CHECK(a19_2.dimension_type == dimension::Ohm);
		/*dimension a19_3("\U000003A9",dimension::POSITIVE);
		CHECK(a19_3.dimension_type == dimension::Ohm);*/
		dimension a20("S",dimension::POSITIVE);
		CHECK(a20.dimension_type == dimension::S);
		dimension a21("Wb",dimension::POSITIVE);
		CHECK(a21.dimension_type == dimension::Wb);
		dimension a22("T",dimension::POSITIVE);
		CHECK(a22.dimension_type == dimension::T);
		dimension a23("H",dimension::POSITIVE);
		CHECK(a23.dimension_type == dimension::H);
		dimension a24("lm",dimension::POSITIVE);
		CHECK(a24.dimension_type == dimension::lm);
		dimension a25("lx",dimension::POSITIVE);
		CHECK(a25.dimension_type == dimension::lx);
		dimension a26("Bq",dimension::POSITIVE);
		CHECK(a26.dimension_type == dimension::Bq);
		dimension a27("Gy",dimension::POSITIVE);
		CHECK(a27.dimension_type == dimension::Gy);
		dimension a28("Sv",dimension::POSITIVE);
		CHECK(a28.dimension_type == dimension::Sv);
		dimension a29("kat",dimension::POSITIVE);
		CHECK(a29.dimension_type == dimension::kat);
		dimension a30("angstrom",dimension::POSITIVE); // MORE CASES
		CHECK(a30.dimension_type == dimension::angstrom);
		dimension a31("L",dimension::POSITIVE);
		CHECK(a31.dimension_type == dimension::L);
		dimension a32("min",dimension::POSITIVE);
		CHECK(a32.dimension_type == dimension::minute);
		dimension a33("h",dimension::POSITIVE);
		CHECK(a33.dimension_type == dimension::h);
		dimension a34("d",dimension::POSITIVE);
		CHECK(a34.dimension_type == dimension::d);
		dimension a35_2("ly",dimension::POSITIVE);
		CHECK(a35_2.dimension_type == dimension::ly);
		dimension a35("AU",dimension::POSITIVE);
		CHECK(a35.dimension_type == dimension::AU);
		dimension a36("pc",dimension::POSITIVE);
		CHECK(a36.dimension_type == dimension::pc);
		dimension a37("eV",dimension::POSITIVE);
		CHECK(a37.dimension_type == dimension::eV);
		dimension a38("Da",dimension::POSITIVE);
		CHECK(a38.dimension_type == dimension::Da);
		dimension a39("amu",dimension::POSITIVE);
		CHECK(a39.dimension_type == dimension::amu);
		dimension a40("barn",dimension::POSITIVE);
		CHECK(a40.dimension_type == dimension::barn);
		dimension a41("M",dimension::POSITIVE);
		CHECK(a41.dimension_type == dimension::M);
		dimension a42("particles",dimension::POSITIVE);
		CHECK(a42.dimension_type == dimension::particles);
		dimension a43("money",dimension::POSITIVE);
		CHECK(a43.dimension_type == dimension::money);
		dimension a44("px",dimension::POSITIVE);
		CHECK(a44.dimension_type == dimension::pixel);
		dimension a45("memo",dimension::POSITIVE);
		CHECK(a45.dimension_type == dimension::memo);
		dimension a46("",dimension::POSITIVE);
		CHECK(a46.dimension_type == dimension::NONE);
		dimension a47("hello",dimension::POSITIVE);
		CHECK(a47.dimension_type == dimension::custom_full_symbol);
	}

	SECTION("Assignments of dimension class")
	{
		dimension a;
		dimension b(dimension::g,prefix::no_prefix,dimension::POSITIVE);
		a = b;
		CHECK(a.dimension_type == dimension::g);
		dimension c;
		dimension d(dimension::g,prefix::no_prefix,dimension::POSITIVE);
		c = std::move(d);
		CHECK(c.dimension_type == dimension::g);
	}

	SECTION("Testing of length dimensions") {
		dimension a = dimension("Ym",dimension::POSITIVE);
		CHECK(to_string(a) == "Ym");
		dimension b = dimension("Zm",dimension::POSITIVE);
		CHECK(to_string(b) == "Zm");
		dimension c = dimension("Em",dimension::POSITIVE);
		CHECK(to_string(c) == "Em");
		dimension d = dimension("Pm",dimension::POSITIVE);
		CHECK(to_string(d) == "Pm");
		dimension e = dimension("Tm",dimension::POSITIVE);
		CHECK(to_string(e) == "Tm");
		dimension f = dimension("Gm",dimension::POSITIVE);
		CHECK(to_string(f) == "Gm");
		dimension g = dimension("Mm",dimension::POSITIVE);
		CHECK(to_string(g) == "Mm");
		dimension h = dimension("km",dimension::POSITIVE);
		CHECK(to_string(h) == "km");
		dimension i = dimension("hm",dimension::POSITIVE);
		CHECK(to_string(i) == "hm");
		dimension j = dimension("dam",dimension::POSITIVE);
		CHECK(to_string(j) == "dam");
		dimension k = dimension("dm",dimension::POSITIVE);
		CHECK(to_string(k) == "dm");
		dimension l = dimension("cm",dimension::POSITIVE);
		CHECK(to_string(l) == "cm");
		dimension m = dimension("mm",dimension::POSITIVE);
		CHECK(to_string(m) == "mm");
		dimension n = dimension("um",dimension::POSITIVE);
		CHECK(to_string(n) == "\u00B5m");
		//dimension n2 = dimension("\u00B5m",dimension::POSITIVE);
		//cout << "n2: " << to_string(n2) << endl;
		//string n2_icu;
		//icu::UnicodeString("\u00B5m").toUTF8String(n2_icu);
		//CHECK(to_string(n2) == n2_icu);
		dimension o = dimension("nm",dimension::POSITIVE);
		CHECK(to_string(o) == "nm");
		dimension p = dimension("pm",dimension::POSITIVE);
		CHECK(to_string(p) == "pm");
		dimension q = dimension("fm",dimension::POSITIVE);
		CHECK(to_string(q) == "fm");
		dimension r = dimension("am",dimension::POSITIVE);
		CHECK(to_string(r) == "am");
		dimension s = dimension("zm",dimension::POSITIVE);
		CHECK(to_string(s) == "zm");
		dimension t = dimension("ym",dimension::POSITIVE);
		CHECK(to_string(t) == "ym");
	}

	SECTION ("get_name(), get_symbol(), get_conversion_factor(), is_simple_dmension(), is_basic_dimension() of dimension class")
	{
		dimension a(dimension::NONE,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a.get_name() == "empty");
		CHECK(a.get_symbol() == "empty");
		CHECK(a.get_conversion_factor() == 1.0l);
		CHECK(a.is_simple_dimension() == true);
		CHECK(a.is_basic_dimension() == true);
		dimension a2(dimension::m,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a2.get_name() == "meter");
		CHECK(a2.get_symbol() == "m");
		CHECK(a2.get_conversion_factor() == 1.0l);
		CHECK(a2.is_simple_dimension() == true);
		CHECK(a2.is_basic_dimension() == true);
		dimension a3_2(dimension::grade,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a3_2.get_name() == "grade");
		CHECK(a3_2.get_symbol() == "\u03B8");
		CHECK(a3_2.get_conversion_factor() == PI / 180.0l);
		CHECK(a3_2.is_simple_dimension() == true);
		CHECK(a3_2.is_basic_dimension() == true);
		dimension a3(dimension::radian,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a3.get_name() == "radian");
		CHECK(a3.get_symbol() == "rad");
		CHECK(a3.get_conversion_factor() == 1.0l);
		CHECK(a3.is_simple_dimension() == true);
		CHECK(a3.is_basic_dimension() == true);
		dimension a4(dimension::steradian,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a4.get_name() == "steradian");
		CHECK(a4.get_symbol() == "sr");
		CHECK(a4.get_conversion_factor() == 1.0l);
		CHECK(a4.is_simple_dimension() == true);
		CHECK(a4.is_basic_dimension() == true);
		dimension a5(dimension::s,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a5.get_name() == "second");
		CHECK(a5.get_symbol() == "s");
		CHECK(a5.get_conversion_factor() == 1.0l);
		CHECK(a5.is_simple_dimension() == true);
		CHECK(a5.is_basic_dimension() == true);
		dimension a6(dimension::g,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a6.get_name() == "gram");
		CHECK(a6.get_symbol() == "g");
		CHECK(a6.get_conversion_factor() == 1.0l);
		CHECK(a6.is_simple_dimension() == true);
		CHECK(a6.is_basic_dimension() == true);
		dimension a7(dimension::C,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a7.get_name() == "coulomb");
		CHECK(a7.get_symbol() == "C");
		CHECK(a7.get_conversion_factor() == 1.0l);
		CHECK(a7.is_simple_dimension() == true);
		CHECK(a7.is_basic_dimension() == true);
		dimension a8(dimension::K,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a8.get_name() == "kelvin");
		CHECK(a8.get_symbol() == "K");
		CHECK(a8.get_conversion_factor() == 1.0l);
		CHECK(a8.is_simple_dimension() == true);
		CHECK(a8.is_basic_dimension() == true);
		dimension a9(dimension::mol,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a9.get_name() == "mole");
		CHECK(a9.get_symbol() == "mol");
		CHECK(a9.get_conversion_factor() == 1.0l);
		CHECK(a9.is_simple_dimension() == true);
		CHECK(a9.is_basic_dimension() == true);
		dimension a10(dimension::cd,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a10.get_name() == "candela");
		CHECK(a10.get_symbol() == "cd");
		CHECK(a10.get_conversion_factor() == 1.0l);
		CHECK(a10.is_simple_dimension() == true);
		CHECK(a10.is_basic_dimension() == true);
		dimension a11(dimension::B,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a11.get_name() == "byte");
		CHECK(a11.get_symbol() == "B");
		CHECK(a11.get_conversion_factor() == 1.0l);
		CHECK(a11.is_simple_dimension() == true);
		CHECK(a11.is_basic_dimension() == true);
		dimension a12(dimension::Hz,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a12.get_name() == "hertz");
		CHECK(a12.get_symbol() == "Hz");
		CHECK(a12.get_conversion_factor() == 1.0l);
		CHECK(a12.is_simple_dimension() == true);
		CHECK(a12.is_basic_dimension() == false);
		dimension a13(dimension::N,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a13.get_name() == "newton");
		CHECK(a13.get_symbol() == "N");
		CHECK(a13.get_conversion_factor() == 1.0l);
		CHECK(a13.is_simple_dimension() == false);
		CHECK(a13.is_basic_dimension() == false);
		dimension a14(dimension::Pa,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a14.get_name() == "pascal");
		CHECK(a14.get_symbol() == "Pa");
		CHECK(a14.get_conversion_factor() == 1.0l);
		CHECK(a14.is_simple_dimension() == false);
		CHECK(a14.is_basic_dimension() == false);
		dimension a15(dimension::J,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a15.get_name() == "joule");
		CHECK(a15.get_symbol() == "J");
		CHECK(a15.get_conversion_factor() == 1.0l);
		CHECK(a15.is_simple_dimension() == false);
		CHECK(a15.is_basic_dimension() == false);
		dimension a16(dimension::W,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a16.get_name() == "watt");
		CHECK(a16.get_symbol() == "W");
		CHECK(a16.get_conversion_factor() == 1.0l);
		CHECK(a16.is_simple_dimension() == false);
		CHECK(a16.is_basic_dimension() == false);
		dimension a17(dimension::A,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a17.get_name() == "ampere");
		CHECK(a17.get_symbol() == "A");
		CHECK(a17.get_conversion_factor() == 1.0l);
		CHECK(a17.is_simple_dimension() == true);
		CHECK(a17.is_basic_dimension() == false);
		dimension a18(dimension::V,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a18.get_name() == "volt");
		CHECK(a18.get_symbol() == "V");
		CHECK(a18.get_conversion_factor() == 1.0l);
		CHECK(a18.is_simple_dimension() == false);
		CHECK(a18.is_basic_dimension() == false);
		dimension a19(dimension::F,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a19.get_name() == "faraday");
		CHECK(a19.get_symbol() == "F");
		CHECK(a19.get_conversion_factor() == 1.0l);
		CHECK(a19.is_simple_dimension() == false);
		CHECK(a19.is_basic_dimension() == false);
		dimension a20(dimension::Ohm,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a20.get_name() == "ohm");
		CHECK(a20.get_symbol() == "\U000003A9");
		CHECK(a20.get_conversion_factor() == 1.0l);
		CHECK(a20.is_simple_dimension() == false);
		CHECK(a20.is_basic_dimension() == false);
		dimension a21(dimension::S,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a21.get_name() == "siemens");
		CHECK(a21.get_symbol() == "S");
		CHECK(a21.get_conversion_factor() == 1.0l);
		CHECK(a21.is_simple_dimension() == false);
		CHECK(a21.is_basic_dimension() == false);
		dimension a22(dimension::Wb,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a22.get_name() == "weber");
		CHECK(a22.get_symbol() == "Wb");
		CHECK(a22.get_conversion_factor() == 1.0l);
		CHECK(a22.is_simple_dimension() == false);
		CHECK(a22.is_basic_dimension() == false);
		dimension a23(dimension::T,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a23.get_name() == "tesla");
		CHECK(a23.get_symbol() == "T");
		CHECK(a23.get_conversion_factor() == 1.0l);
		CHECK(a23.is_simple_dimension() == false);
		CHECK(a23.is_basic_dimension() == false);
		dimension a24(dimension::H,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a24.get_name() == "henry");
		CHECK(a24.get_symbol() == "H");
		CHECK(a24.get_conversion_factor() == 1.0l);
		CHECK(a24.is_simple_dimension() == false);
		CHECK(a24.is_basic_dimension() == false);
		dimension a25(dimension::lm,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a25.get_name() == "lumen");
		CHECK(a25.get_symbol() == "lm");
		CHECK(a25.get_conversion_factor() == 1.0l);
		CHECK(a25.is_simple_dimension() == false);
		CHECK(a25.is_basic_dimension() == false);
		dimension a26(dimension::lx,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a26.get_name() == "lux");
		CHECK(a26.get_symbol() == "lx");
		CHECK(a26.get_conversion_factor() == 1.0l);
		CHECK(a26.is_simple_dimension() == false);
		CHECK(a26.is_basic_dimension() == false);
		dimension a27(dimension::Bq,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a27.get_name() == "becquerel");
		CHECK(a27.get_symbol() == "Bq");
		CHECK(a27.get_conversion_factor() == 1.0l);
		CHECK(a27.is_simple_dimension() == true);
		CHECK(a27.is_basic_dimension() == false);
		dimension a28(dimension::Gy,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a28.get_name() == "gray");
		CHECK(a28.get_symbol() == "Gy");
		CHECK(a28.get_conversion_factor() == 1.0l);
		CHECK(a28.is_simple_dimension() == false);
		CHECK(a28.is_basic_dimension() == false);
		dimension a29(dimension::Sv,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a29.get_name() == "sievert");
		CHECK(a29.get_symbol() == "Sv");
		CHECK(a29.get_conversion_factor() == 1.0l);
		CHECK(a29.is_simple_dimension() == false);
		CHECK(a29.is_basic_dimension() == false);
		dimension a30(dimension::kat,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a30.get_name() == "katal");
		CHECK(a30.get_symbol() == "kat");
		CHECK(a30.get_conversion_factor() == 1.0l);
		CHECK(a30.is_simple_dimension() == false);
		CHECK(a30.is_basic_dimension() == false);
		dimension a31(dimension::angstrom,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a31.get_name() == "angstrom");
		CHECK(a31.get_symbol() == "\U0000212B");
		CHECK(a31.get_conversion_factor() == 1.0l);
		CHECK(a31.is_simple_dimension() == true);
		CHECK(a31.is_basic_dimension() == false);
		dimension a32(dimension::L,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a32.get_name() == "liter");
		CHECK(a32.get_symbol() == "L");
		CHECK(a32.get_conversion_factor() == 1.0l);
		CHECK(a32.is_simple_dimension() == false);
		CHECK(a32.is_basic_dimension() == false);
		dimension a33(dimension::minute,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a33.get_name() == "minute");
		CHECK(a33.get_symbol() == "min");
		CHECK(a33.get_conversion_factor() == 60.0l);
		CHECK(a33.is_simple_dimension() == true);
		CHECK(a33.is_basic_dimension() == false);
		dimension a34(dimension::h,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a34.get_name() == "hour");
		CHECK(a34.get_symbol() == "h");
		CHECK(a34.get_conversion_factor() == 3600.0l);
		CHECK(a34.is_simple_dimension() == true);
		CHECK(a34.is_basic_dimension() == false);
		dimension a35(dimension::d,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a35.get_name() == "day");
		CHECK(a35.get_symbol() == "d");
		CHECK(a35.get_conversion_factor() == 86400.0l);
		CHECK(a35.is_simple_dimension() == true);
		CHECK(a35.is_basic_dimension() == false);
		dimension a36_2(dimension::ly,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a36_2.get_name() == "light year");
		CHECK(a36_2.get_symbol() == "ly");
		CHECK(a36_2.get_conversion_factor() == 9.4607379375591e15);
		CHECK(a36_2.is_simple_dimension() == true);
		CHECK(a36_2.is_basic_dimension() == false);
		dimension a36(dimension::AU,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a36.get_name() == "astronomical unit");
		CHECK(a36.get_symbol() == "AU");
		CHECK(a36.get_conversion_factor() == 149597870700.0l);
		CHECK(a36.is_simple_dimension() == true);
		CHECK(a36.is_basic_dimension() == false);
		dimension a37(dimension::pc,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a37.get_name() == "parsec");
		CHECK(a37.get_symbol() == "pc");
		CHECK(a37.get_conversion_factor() == 30856775814913673.0l);
		CHECK(a37.is_simple_dimension() == true);
		CHECK(a37.is_basic_dimension() == false);
		dimension a38(dimension::eV,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a38.get_name() == "electronvolt");
		CHECK(a38.get_symbol() == "eV");
		CHECK(a38.get_conversion_factor() == 0.0000000000000000001602176634l);
		CHECK(a38.is_simple_dimension() == false);
		CHECK(a38.is_basic_dimension() == false);
		dimension a39(dimension::Da,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a39.get_name() == "dalton");
		CHECK(a39.get_symbol() == "Da");
		CHECK(a39.get_conversion_factor() == 0.00000000000000000000000000166053886l);
		CHECK(a39.is_simple_dimension() == true);
		CHECK(a39.is_basic_dimension() == false);
		dimension a40(dimension::amu,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a40.get_name() == "atomic mass unit");
		CHECK(a40.get_symbol() == "amu");
		CHECK(a40.get_conversion_factor() == 0.00000000000000000000000000166053886l);
		CHECK(a40.is_simple_dimension() == true);
		CHECK(a40.is_basic_dimension() == false);
		dimension a41(dimension::barn,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a41.get_name() == "barn");
		CHECK(a41.get_symbol() == "barn");
		CHECK(a41.get_conversion_factor() == 0.0000000000000000000000000001l);
		CHECK(a41.is_simple_dimension() == false);
		CHECK(a41.is_basic_dimension() == false);
		dimension a42(dimension::M,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a42.get_name() == "molarity");
		CHECK(a42.get_symbol() == "M");
		CHECK(a42.get_conversion_factor() == 1.0l);
		CHECK(a42.is_simple_dimension() == false);
		CHECK(a42.is_basic_dimension() == false);
		dimension a43(dimension::particles,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a43.get_name() == "particles");
		CHECK(a43.get_symbol() == "particles");
		CHECK(a43.get_conversion_factor() == 1l/AVOGADRO_CONSTANT);
		CHECK(a43.is_simple_dimension() == true);
		CHECK(a43.is_basic_dimension() == false);
		/*dimension a44("hello",dimension::POSITIVE);
		CHECK(a44.get_name() == "custom-dimension");
		CHECK(a44.get_symbol() == "hello");
		CHECK(a44.get_conversion_factor() == 1.0);
		CHECK(a44.is_simple_dimension() == false);
		CHECK(a44.is_basic_dimension() == false);
		dimension a45(dimension::custom_basic,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a45.get_name() == "custom-basic");
		CHECK(a45.get_symbol() == "custom-basic");
		CHECK(a45.get_conversion_factor() == 1.0);
		CHECK(a45.is_simple_dimension() == false);
		CHECK(a45.is_basic_dimension() == false);
		dimension a46(dimension::custom_full_symbol,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a46.get_name() == "custom-full-symbol");
		CHECK(a46.get_symbol() == "");
		CHECK(a46.get_conversion_factor() == 1.0);
		CHECK(a46.is_simple_dimension() == false);
		CHECK(a46.is_basic_dimension() == false);*/
		dimension a47(dimension::money,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a47.get_name() == "money");
		CHECK(a47.get_symbol() == "money");
		CHECK(a47.get_conversion_factor() == 1.0l);
		CHECK(a47.is_simple_dimension() == true);
		CHECK(a47.is_basic_dimension() == true);
		dimension a48(dimension::pixel,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a48.get_name() == "pixel");
		CHECK(a48.get_symbol() == "px");
		CHECK(a48.get_conversion_factor() == 0.00026l);
		CHECK(a48.is_simple_dimension() == true);
		CHECK(a48.is_basic_dimension() == false);
		dimension a49(dimension::memo,prefix::no_prefix,dimension::POSITIVE);
		CHECK(a49.get_name() == "memo");
		CHECK(a49.get_symbol() == "memo");
		CHECK(a49.get_conversion_factor() == 1.0l);
		CHECK(a49.is_simple_dimension() == true);
		CHECK(a49.is_basic_dimension() == true);
	}

	SECTION ("get_basic_dimensions() of dimension class")
	{
		dimension a0("",dimension::POSITIVE);
		vector<dimension> b0 = { dimension(dimension::NONE,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a0.get_basic_dimensions(),b0));
		dimension a("m",dimension::POSITIVE);
		vector<dimension> b = { dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a.get_basic_dimensions(),b));
		dimension a2_2("grade",dimension::POSITIVE);
		vector<dimension> b2_2 = { dimension(dimension::radian,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a2_2.get_basic_dimensions(),b2_2));
		dimension a2("rad",dimension::POSITIVE);
		vector<dimension> b2 = { dimension(dimension::radian,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a2.get_basic_dimensions(),b2));
		dimension a3("sr",dimension::POSITIVE);
		vector<dimension> b3 = { dimension(dimension::steradian,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a3.get_basic_dimensions(),b3));
		dimension a4("s",dimension::POSITIVE);
		vector<dimension> b4 = { dimension(dimension::s,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a4.get_basic_dimensions(),b4));
		dimension a5("g",dimension::POSITIVE);
		vector<dimension> b5 = { dimension(dimension::g,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a5.get_basic_dimensions(),b5));
		dimension a6("C",dimension::POSITIVE);
		vector<dimension> b6 = { dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a6.get_basic_dimensions(),b6));
		dimension a7("K",dimension::POSITIVE);
		vector<dimension> b7 = { dimension(dimension::K,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a7.get_basic_dimensions(),b7));
		dimension a8("mol",dimension::POSITIVE);
		vector<dimension> b8 = { dimension(dimension::mol,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a8.get_basic_dimensions(),b8));
		dimension a9("cd",dimension::POSITIVE);
		vector<dimension> b9 = { dimension(dimension::cd,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a9.get_basic_dimensions(),b9));
		dimension a10("B",dimension::POSITIVE);
		vector<dimension> b10 = { dimension(dimension::B,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a10.get_basic_dimensions(),b10));
		dimension a11("Hz",dimension::POSITIVE);
		vector<dimension> b11 = { dimension(dimension::Hz,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a11.get_basic_dimensions(),b11));
		dimension a12("N",dimension::POSITIVE);
		vector<dimension> b12 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		CHECK(equal_dimensions(a12.get_basic_dimensions(),b12));
		dimension a13("Pa",dimension::POSITIVE);
		vector<dimension> b13 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE) };
		CHECK(equal_dimensions(a13.get_basic_dimensions(),b13));
		dimension a14("J",dimension::POSITIVE);
		vector<dimension> b14 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		CHECK(equal_dimensions(a14.get_basic_dimensions(),b14));
		dimension a15("W",dimension::POSITIVE);
		vector<dimension> b15 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		CHECK(equal_dimensions(a15.get_basic_dimensions(),b15));
		dimension a16("A",dimension::POSITIVE);
		vector<dimension> b16 = { dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		CHECK(equal_dimensions(a16.get_basic_dimensions(),b16));
		dimension a17("V",dimension::POSITIVE);
		vector<dimension> b17 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		CHECK(equal_dimensions(a17.get_basic_dimensions(),b17));
		dimension a18("F",dimension::POSITIVE);
		vector<dimension> b18 = { dimension(dimension::g,prefix::k,dimension::NEGATIVE),
				dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE),
				dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE),
				dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
				dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
				dimension(dimension::s,prefix::no_prefix,dimension::POSITIVE),
				dimension(dimension::s,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a18.get_basic_dimensions(),b18));
		dimension a19("Ohm",dimension::POSITIVE);
		vector<dimension> b19 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		CHECK(equal_dimensions(a19.get_basic_dimensions(),b19));
		dimension a20("S",dimension::POSITIVE);
		vector<dimension> b20 = { dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::g,prefix::k,dimension::NEGATIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE) };
		CHECK(equal_dimensions(a20.get_basic_dimensions(),b20));
		dimension a21("Wb",dimension::POSITIVE);
		vector<dimension> b21 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		CHECK(equal_dimensions(a21.get_basic_dimensions(),b21));
		dimension a22("T",dimension::POSITIVE);
		vector<dimension> b22 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		CHECK(equal_dimensions(a22.get_basic_dimensions(),b22));
		dimension a23("H",dimension::POSITIVE);
		vector<dimension> b23 = { dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::C,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a23.get_basic_dimensions(),b23));
		dimension a24("lm",dimension::POSITIVE);
		vector<dimension> b24 = { dimension(dimension::cd,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::steradian,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a24.get_basic_dimensions(),b24));
		dimension a25("lx",dimension::POSITIVE);
		vector<dimension> b25 = { dimension(dimension::cd,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::steradian,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE) };
		CHECK(equal_dimensions(a25.get_basic_dimensions(),b25));
		dimension a26("Bq",dimension::POSITIVE);
		vector<dimension> b26 = { dimension(dimension::Bq,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a26.get_basic_dimensions(),b26));
		dimension a27("Gy",dimension::POSITIVE);
		vector<dimension> b27 = { dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		CHECK(equal_dimensions(a27.get_basic_dimensions(),b27));
		dimension a28("Sv",dimension::POSITIVE);
		vector<dimension> b28 = { dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		CHECK(equal_dimensions(a28.get_basic_dimensions(),b28));
		dimension a29("kat",dimension::POSITIVE);
		vector<dimension> b29 = { dimension(dimension::mol,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		CHECK(equal_dimensions(a29.get_basic_dimensions(),b29));
		dimension a30("angstrom",dimension::POSITIVE);
		vector<dimension> b30 = { dimension(dimension::angstrom,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a30.get_basic_dimensions(),b30));
		dimension a31("L",dimension::POSITIVE);
		vector<dimension> b31 = { dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a31.get_basic_dimensions(),b31));
		dimension a32("min",dimension::POSITIVE);
		vector<dimension> b32 = { dimension(dimension::minute,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a32.get_basic_dimensions(),b32));
		dimension a33("h",dimension::POSITIVE);
		vector<dimension> b33 = { dimension(dimension::h,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a33.get_basic_dimensions(),b33));
		dimension a34("d",dimension::POSITIVE);
		vector<dimension> b34 = { dimension(dimension::d,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a34.get_basic_dimensions(),b34));
		dimension a35_2("ly",dimension::POSITIVE);
		vector<dimension> b35_2 = { dimension(dimension::ly,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a35_2.get_basic_dimensions(),b35_2));
		dimension a35("AU",dimension::POSITIVE);
		vector<dimension> b35 = { dimension(dimension::AU,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a35.get_basic_dimensions(),b35));
		dimension a36("pc",dimension::POSITIVE);
		vector<dimension> b36 = { dimension(dimension::pc,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a36.get_basic_dimensions(),b36));
		dimension a37("eV",dimension::POSITIVE);
		vector<dimension> b37 = { dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::g,prefix::k,dimension::POSITIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::s,prefix::no_prefix,dimension::NEGATIVE) };
		CHECK(equal_dimensions(a37.get_basic_dimensions(),b37));
		dimension a38("Da",dimension::POSITIVE);
		vector<dimension> b38 = { dimension(dimension::Da,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a38.get_basic_dimensions(),b38));
		dimension a39("amu",dimension::POSITIVE);
		vector<dimension> b39 = { dimension(dimension::amu,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a39.get_basic_dimensions(),b39));
		dimension a40("barn",dimension::POSITIVE);
		vector<dimension> b40 = { dimension(dimension::barn,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a40.get_basic_dimensions(),b40));
		dimension a41("M",dimension::POSITIVE);
		vector<dimension> b41 = { dimension(dimension::mol,prefix::no_prefix,dimension::POSITIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE),
			dimension(dimension::m,prefix::no_prefix,dimension::NEGATIVE) };
		CHECK(equal_dimensions(a41.get_basic_dimensions(),b41));
		dimension a42("particles",dimension::POSITIVE);
		vector<dimension> b42 = { dimension(dimension::particles,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a42.get_basic_dimensions(),b42));
		dimension a43("money",dimension::POSITIVE);
		vector<dimension> b43 = { dimension(dimension::money,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a43.get_basic_dimensions(),b43));
		dimension a44("px",dimension::POSITIVE);
		vector<dimension> b44 = { dimension(dimension::pixel,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a44.get_basic_dimensions(),b44));
		dimension a45("memo",dimension::POSITIVE);
		vector<dimension> b45 = { dimension(dimension::memo,prefix::no_prefix,dimension::POSITIVE) };
		CHECK(equal_dimensions(a45.get_basic_dimensions(),b45));
	}

	SECTION ("Constructor of custom dimensions")
	{
		dimension a("usd",dimension::POSITIVE);
		vector<dimension> b = { dimension("usd",dimension::POSITIVE) };
		CHECK(a.get_name() == "custom-dimension");
		CHECK(a.get_symbol() == "usd");
		CHECK(a.get_conversion_factor() == 1.0l);
		CHECK(a.is_simple_dimension() == false);
		CHECK(a.is_basic_dimension() == false);
		CHECK(equal_dimensions(a.get_basic_dimensions(),b));
		dimension a2("long-dimension",dimension::POSITIVE);
		vector<dimension> b2 = { dimension("long-dimension",dimension::POSITIVE) };
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
		dimension c("km",dimension::POSITIVE);
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
		dimension a("km",dimension::POSITIVE);
		CHECK(a.prefix_math() == 1000);
		dimension b("kB",dimension::POSITIVE);
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
		dimension a(dimension::m,prefix::no_prefix,dimension::POSITIVE);
		dimension b(dimension::AU,prefix::no_prefix,dimension::POSITIVE);
		CHECK(common_dimension(a,b) == true);
		CHECK(equal_dimensions("m","AU") == true);
		CHECK(equal_dimensions("m","pc") == true);
		dimension a2(dimension::g,prefix::no_prefix,dimension::POSITIVE);
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
		dimension a(dimension::m,prefix::no_prefix,dimension::POSITIVE);
		dimension b(dimension::m,prefix::no_prefix,dimension::POSITIVE);
		dimension c(dimension::AU,prefix::no_prefix,dimension::POSITIVE);
		dimension d(dimension::m,prefix::no_prefix,dimension::NEGATIVE);
		CHECK((a == b) == true);
		CHECK((a != c) == true);
		CHECK((a == c) == false);
		CHECK((a == d) == false);
		CHECK((a != d) == true);
	}

	SECTION ("Testing of custom dimensions") {
		dimension::create_custom_dimension("custom_dimension","m*s");
		dimension a = dimension("custom_dimension",dimension::POSITIVE);
		vector<dimension> b = create_dimensions("m*s");
		CHECK(a.get_symbol() == "custom_dimension");
		CHECK(equal_dimensions(a.get_basic_dimensions(),b));
		dimension::create_custom_dimension("uUu","g*m*s");
		dimension c = dimension("uUu",dimension::POSITIVE);
		vector<dimension> d = create_dimensions("g*m*s");
		CHECK(c.get_symbol() == "uUu");
		CHECK(equal_dimensions(c.get_basic_dimensions(),d));
	}
}
