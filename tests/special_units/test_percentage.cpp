#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../special_units/percentage.hpp"
#include "../../units/unit_basic.hpp"
#include "../../units/unit_abbreviation.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("percentage class","Full test of percentage class") {
	SECTION("Constructors of percentage class") {
		percentage a;
		REQUIRE (bool(a.get_value() == 0.0f));
		percentage b("23%");
		percentage c(b);
		REQUIRE (bool(c.get_value() == 23.0f));
		percentage c2(std::move(b));
		REQUIRE (bool(c.get_value() == 23.0f));
		percentage d(26.0f);
		REQUIRE (bool(d.get_value() == 26.0f));
		percentage d2(26.0);
		REQUIRE (bool(d2.get_value() == 26.0f));
		percentage d3(26.0l);
		REQUIRE (bool(d3.get_value() == 26.0f));
		percentage d4(26);
		REQUIRE (bool(d4.get_value() == 26.0f));
		percentage e(28.0f,"%");
		REQUIRE (bool(e.get_value() == 28.0f));
		percentage e2(28.0f,"ppm");
		REQUIRE (bool(e2.get_value() == (28.0f / 10000.0f)));
		percentage e3(28.0f,"a");
		REQUIRE (bool(e3.get_value() == 0.0f));
		/*percentage e3(28.0f,"ppb");
		REQUIRE (bool(e3.get_value() == (28.0f / 10000000.0f)));
		percentage e4(28.0f,"ppt");
		REQUIRE (bool(e4.get_value() == (28.0f / 10000000000.0f)));
		percentage e5(28.0f,"ppq");
		REQUIRE (bool(e5.get_value() == (28.0f / 10000000000000.0f)));*/
		percentage f(28.0,"%");
		REQUIRE (bool(f.get_value() == 28.0f));
		percentage f2(28.0,"ppm");
		REQUIRE (bool(f2.get_value() == (28.0f / 10000.0f)));
		percentage f3(28.0,"a");
		REQUIRE (bool(f3.get_value() == 0.0f));
		/*percentage f3(28.0,"ppb");
		REQUIRE (bool(f3.get_value() == (28.0f / 10000000.0f)));
		percentage f4(28.0,"ppt");
		REQUIRE (bool(f4.get_value() == (28.0f / 10000000000.0f)));
		percentage f5(28.0,"ppq");
		REQUIRE (bool(f5.get_value() == (28.0f / 10000000000000.0f)));*/
		percentage g(28.0l,"%");
		REQUIRE (bool(g.get_value() == 28.0f));
		percentage g2(28.0l,"ppm");
		REQUIRE (bool(g2.get_value() == (28.0f / 10000.0f)));
		percentage g3(28.0l,"a");
		REQUIRE (bool(g3.get_value() == 0.0f));
		/*percentage g3(28.0l,"ppb");
		REQUIRE (bool(g3.get_value() == (28.0f / 10000000.0f)));
		percentage g4(28.0l,"ppt");
		REQUIRE (bool(g4.get_value() == (28.0f / 10000000000.0f)));
		percentage g5(28.0l,"ppq");
		REQUIRE (bool(g5.get_value() == (28.0f / 10000000000000.0f)));*/
		percentage h(28,"%");
		REQUIRE (bool(h.get_value() == 28.0f));
		percentage h2(28,"ppm");
		REQUIRE (bool(h2.get_value() == (28.0f / 10000.0f)));
		percentage h3(28,"a");
		REQUIRE (bool(h3.get_value() == 0.0f));
		/*percentage h3(28,"ppb");
		REQUIRE (bool(h3.get_value() == (28.0f / 10000000.0f)));
		percentage h4(28,"ppt");
		REQUIRE (bool(h4.get_value() == (28.0f / 10000000000.0f)));
		percentage h5(28,"ppq");
		REQUIRE (bool(h5.get_value() == (28.0f / 10000000000000.0f)));*/
		percentage i("24%");
		REQUIRE (bool(i.get_value() == 24.0f));
		percentage i2("24ppm");
		REQUIRE (bool(i2.get_value() == (24.0f / 10000.0f)));
		percentage i3("24a");
		REQUIRE (bool(i3.get_value() == 0.0f));
		percentage i4("24aqw");
		REQUIRE (bool(i4.get_value() == 0.0f));
		/*percentage i3("24ppb");
		REQUIRE (bool(i3.get_value() == (24.0f / 10000000.0f)));
		percentage i4("24ppt");
		REQUIRE (bool(i4.get_value() == (24.0f / 10000000000.0f)));
		percentage i5("24ppq");
		REQUIRE (bool(i5.get_value() == (24.0f / 10000000000000.0f)));*/
		percentage i6("24 ppm");
		REQUIRE (bool(i6.get_value() == (24.0f / 10000.0f)));
		percentage i7("24 a");
		REQUIRE (bool(i7.get_value() == 0.0f));
		/*percentage i7("24 ppb");
		REQUIRE (bool(i7.get_value() == (24.0f / 10000000.0f)));
		percentage i8("24 ppt");
		REQUIRE (bool(i8.get_value() == (24.0f / 10000000000.0f)));
		percentage i9("24 ppq");
		REQUIRE (bool(i9.get_value() == (24.0f / 10000000000000.0f)));*/
		scalar_unit j2 = 100_N;
		percentage j(j2 / 10_N);
		REQUIRE (bool(j.get_value() == 10.0f));
		percentage j3(j2);
		REQUIRE (bool(j3.get_value() == 0.0f));
	}

	SECTION("Assignments of percentage class") {
		percentage a("40%");
		percentage b("20%");
		a = b;
		REQUIRE (bool(a.get_value() == 20.0f));
		percentage c("30%");
		a = std::move(c);
		REQUIRE (bool(a.get_value() == 30.0f));
		a = 24.0f;
		REQUIRE (bool(a.get_value() == 24.0f));
		a = 24.0;
		REQUIRE (bool(a.get_value() == 24.0f));
		a = 24.0l;
		REQUIRE (bool(a.get_value() == 24.0f));
		a = "29%";
		REQUIRE (bool(a.get_value() == 29.0f));
		a = "29ppm";
		REQUIRE (bool(a.get_value() == (29.0f / 10000.0f)));
		a = "29a";
		REQUIRE (bool(a.get_value() == 0.0f));
		a = "29aqe";
		REQUIRE (bool(a.get_value() == 0.0f));
		/*a = "29ppb";
		REQUIRE (bool(a.get_value() == (29.0f / 10000000.0f)));
		a = "29ppt";
		REQUIRE (bool(a.get_value() == (29.0f / 10000000000.0f)));
		a = "29ppq";
		REQUIRE (bool(a.get_value() == (29.0f / 10000000000000.0f)));*/
		a = "29 ppm";
		REQUIRE (bool(a.get_value() == (29.0f / 10000.0f)));
		a = "29 a";
		REQUIRE (bool(a.get_value() == 0.0f));
		/*a = "29 ppb";
		REQUIRE (bool(a.get_value() == (29.0f / 10000000.0f)));
		a = "29 ppt";
		REQUIRE (bool(a.get_value() == (29.0f / 10000000000.0f)));
		a = "29 ppq";
		REQUIRE (bool(a.get_value() == (29.0f / 10000000000000.0f)));*/
		scalar_unit d = 42_N;
		a = d / 21_N;
		REQUIRE (bool(a.get_value() == 2.0f));
		a = d / 21.0f;
		REQUIRE (bool(a.get_value() == 0.0f));
	}

	SECTION("Implicit conversion of percentage class") {
		percentage a = percentage("17%");
		REQUIRE (bool(float(a) == 17.0f));
	}

	SECTION("Base functionalities of percentage class") {
		percentage a = percentage("90%");
		REQUIRE (bool(a.get_factor() == 0.9f));
		REQUIRE (bool(to_string(a) == "90%"));
		percentage b = percentage("110%");
		REQUIRE (bool(b.get_factor() == 1.1f));
		REQUIRE (bool(to_string(b) == "110%"));
		percentage c = percentage(30);
		REQUIRE (bool(to_string(c) == "30%"));
		percentage d = percentage(50,"%");
		REQUIRE (bool(to_string(d) == "50%"));
		percentage e = percentage(10_m / 1_m);
		REQUIRE (bool(to_string(e) == "10%"));
		percentage f = percentage("1 ppm");
		REQUIRE (bool(f.get_factor() == 0.000001f));
		REQUIRE (bool(f.display_ppm() == "1 ppm"));
		/*percentage g = percentage("1 ppb");
		REQUIRE (bool(g.get_factor() == 0.000000001f));
		REQUIRE (bool(g.display_ppb() == "1 ppb"));
		percentage h = percentage("1 ppt");
		REQUIRE (bool(h.get_factor() == 0.000000000001f));
		REQUIRE (bool(h.display_ppt() == "1 ppt"));
		percentage i = percentage("1 ppq");
		REQUIRE (bool(i.get_factor() == 0.000000000000001f));
		REQUIRE (bool(i.display_ppq() == "1 ppq"));*/
		percentage i = percentage("70%");
		REQUIRE (bool(to_string(i) == "70%"));
		i = 65;
		REQUIRE (bool(to_string(i) == "65%"));
		i = "46%";
		REQUIRE (bool(to_string(i) == "46%"));
		i = 50_s / 25_s;
		REQUIRE (bool(to_string(i) == "2%"));
		percentage j = percentage("34%");
		REQUIRE (bool(float(j) == 34.0f));
		REQUIRE (bool(j.get_value() == 34.0f));
		REQUIRE (bool(to_string(a + j) == "124%"));
		REQUIRE (bool(to_string(a - j) == "56%"));
		percentage k = percentage("50%");
		REQUIRE (bool(to_string(a * k) == "45%"));
		REQUIRE (bool(to_string(a / k) == "180%"));
		k += percentage("25%");
		REQUIRE (bool(to_string(k) == "75%"));
		k -= percentage("12%");
		REQUIRE (bool(to_string(k) == "63%"));
		percentage l = percentage("30%");
		percentage m = percentage("50%");
		l *= m;
		REQUIRE (bool(to_string(l) == "15%"));
		percentage n = percentage("30%");
		percentage o = percentage("50%");
		n /= o;
		REQUIRE (bool(to_string(n) == "60%"));
		percentage p = percentage("50%");
		p = 20;
		REQUIRE (bool(to_string(p) == "20%"));
		percentage q = percentage("50%");
		REQUIRE (bool(to_string(q + 10) == "60%"));
		percentage r = percentage("50%");
		REQUIRE (bool(to_string(r - 10) == "40%"));
		percentage s = percentage("50%");
		REQUIRE (bool(to_string(s * 10) == "5.000000"));
		percentage t = percentage("50%");
		REQUIRE (bool(to_string(t / 2) == "0.250000"));
		percentage u = percentage("50%");
		u += 20;
		REQUIRE (bool(to_string(u) == "70%"));
		percentage v = percentage("50%");
		v -= 5;
		REQUIRE (bool(to_string(v) == "45%"));
		percentage w = percentage("30%");
		w *= 2;
		REQUIRE (bool(to_string(w) == "60%"));
		percentage x = percentage("40%");
		x /= 2;
		REQUIRE (bool(to_string(x) == "20%"));
		percentage y = percentage("40%");
		y++;
		REQUIRE (bool(to_string(y) == "41%"));
		percentage z = percentage("30%");
		++z;
		REQUIRE (bool(to_string(z) == "31%"));
		percentage aa = percentage("40%");
		aa--;
		REQUIRE (bool(to_string(aa) == "39%"));
		percentage ab = percentage("30%");
		--ab;
		REQUIRE (bool(to_string(ab) == "29%"));
		percentage ac = percentage("20%");
		scalar_unit ad = scalar_unit("5 N");
		scalar_unit ae = ac * ad;
		REQUIRE (bool(to_string(ae) == "1 N"));
		REQUIRE (bool(to_string(ad * ac) == "1 N"));
		percentage af = percentage("200%");
		scalar_unit ag = scalar_unit("4 N");
		scalar_unit ah = af / ag;
		REQUIRE (bool(to_string(ah) == "0.5 s2/kg*m"));
		cout << "ag / af: " << to_string(ag / af) << endl;
		REQUIRE (bool(to_string(ag / af) == "2 N"));
		percentage ai = percentage("70%");
		REQUIRE (bool(ai.get_factor() == 0.7f));
	}

	SECTION("ppm functions of percentage class") {
		percentage a = percentage("30%");
		REQUIRE (bool(a.get_ppm() == 300000.0f));
		/*REQUIRE (bool(a.get_ppb() == 300000000.0f));
		REQUIRE (bool(a.get_ppt() == 300000000000.0f));
		REQUIRE (bool(a.get_ppq() == 300000000000000.0f));*/
		REQUIRE (bool(a.display_ppm() == "300000 ppm"));
		/*cout << "ppb: " << a.display_ppb() << endl;
		cout << "ppt: " << a.display_ppt() << endl;
		cout << "ppq: " << a.display_ppq() << endl;
		REQUIRE (bool(a.display_ppb() == "300000000 ppb"));
		REQUIRE (bool(a.display_ppt() == "300000000000 ppt"));
		REQUIRE (bool(a.display_ppq() == "300000000000000 ppq"));*/
	}

	SECTION("to_string() function of percentage class") {
		percentage a = percentage("30%");
		REQUIRE (bool(to_string(a) == "30%"));
	}

	SECTION("Number operators of percentage class") {
		percentage a = percentage("30%");
		REQUIRE (bool((a + 20.0f) == percentage("50%")));
		REQUIRE (bool((a - 7.0f) == percentage("23%")));
		REQUIRE (bool((a * 100.0f) == 30.0f));
		REQUIRE (bool((a / 15.0f) == 0.02f));
		REQUIRE (bool(a == 30.0f));
		REQUIRE (bool(a != 20.0f));
		REQUIRE (bool(a > 20.0f));
		REQUIRE (bool(a < 35.0f));
		REQUIRE (bool(a >= 25.0f));
		REQUIRE (bool(a <= 40.0f));
		REQUIRE (bool((20.0f + a) == percentage("50%")));
		REQUIRE (bool((37.0f - a) == percentage("7%")));
		REQUIRE (bool((100.0f * a) == 30.0f));
		REQUIRE (bool((60.0f / a) == 200.0f));
		REQUIRE (bool(30.0f == a));
		REQUIRE (bool(20.0f != a));
		REQUIRE (bool(20.0f < a));
		REQUIRE (bool(35.0f > a));
		REQUIRE (bool(25.0f <= a));
		REQUIRE (bool(40.0f >= a));
	}

	SECTION("is_percentage() function")
	{
		REQUIRE (bool(is_percentage("90%") == true));
		REQUIRE (bool(is_percentage("90ppm") == true));
		/*REQUIRE (bool(is_percentage("90ppb") == true));
		REQUIRE (bool(is_percentage("90ppt") == true));
		REQUIRE (bool(is_percentage("90ppq") == true));*/
		REQUIRE (bool(is_percentage("90 ppm") == true));
		/*REQUIRE (bool(is_percentage("90 ppb") == true));
		REQUIRE (bool(is_percentage("90 ppt") == true));
		REQUIRE (bool(is_percentage("90 ppq") == true));*/
		REQUIRE (bool(is_percentage("90sad") == false));
		REQUIRE (bool(is_percentage("90sad%") == false));
		REQUIRE (bool(is_percentage("90.0%") == true));
		REQUIRE (bool(is_percentage("90.0.0%") == false));
	}

	SECTION("Operators of percentage class with other percentage classes") {
		percentage a = percentage("30%");
		percentage b = percentage("20%");
		REQUIRE (bool(a > b));
		REQUIRE (bool(a >= b));
		percentage c = percentage("30%");
		percentage d = percentage("20%");
		REQUIRE (bool(d < c));
		REQUIRE (bool(d <= c));
		percentage e = percentage("20%");
		percentage f = percentage("20%");
		REQUIRE (bool(e <= f));
		REQUIRE (bool(e >= f));
		REQUIRE (bool(e == f));
		REQUIRE (bool(a != b));
	}

	SECTION("String operators of percentage class") {
		REQUIRE (bool(percentage("45%") == "45%"));
		REQUIRE (bool(percentage("45%") != "40%"));
		REQUIRE (bool("45%" == percentage("45%")));
		REQUIRE (bool("40%" != percentage("45%")));
		string a = "percentage ";
		a += percentage("40%");
		REQUIRE (bool(a == "percentage 40%"));
		percentage b = percentage("20%");
		REQUIRE (bool("b " + b == "b 20%"));
		REQUIRE (bool(b + " b" == "20% b"));
	}

	SECTION("String operators of percentage class") {
		percentage a = percentage("25%");
		ostringstream out;
		out << "a " << a;
		REQUIRE (bool(out.str() == "a 25%"));
		stringstream b;
        b << "72%";
        percentage b2;
        b >> b2;
        REQUIRE (bool(to_string(b2) == "72%"));
	}
}


