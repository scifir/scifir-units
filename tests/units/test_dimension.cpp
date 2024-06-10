#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../units/dimension.hpp"

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
	
	SECTION ("Functionalities of dimension class") {
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
		REQUIRE (bool(k2 = 36000));
		vector<dimension> r = create_dimensions("1/h");
		long double r2 = 10;
		vector<dimension> s = create_derived_dimensions(r,r2);
		REQUIRE (bool(equal_dimensions(r,s)));
		REQUIRE (bool(r2 = 0.00277778));
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
	
	SECTION ("Operations with dimensions") {
		
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

