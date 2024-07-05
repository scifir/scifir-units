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

TEST_CASE("percentage class") {
	SECTION("Constructors of percentage class") {
		percentage a;
		CHECK(a.get_value() == 0.0f);
		percentage b("23%");
		percentage c(b);
		CHECK(c.get_value() == 23.0f);
		percentage c2(std::move(b));
		CHECK(c.get_value() == 23.0f);
		percentage d(26.0f);
		CHECK(d.get_value() == 26.0f);
		percentage d2(26.0);
		CHECK(d2.get_value() == 26.0f);
		percentage d3(26.0l);
		CHECK(d3.get_value() == 26.0f);
		percentage d4(26);
		CHECK(d4.get_value() == 26.0f);
		percentage e(28.0f,"%");
		CHECK(e.get_value() == 28.0f);
		percentage e2(28.0f,"ppm");
		CHECK(e2.get_value() == (28.0f / 10000.0f));
		percentage e3(28.0f,"a");
		CHECK(e3.get_value() == 0.0f);
		/*percentage e3(28.0f,"ppb");
		CHECK(e3.get_value() == (28.0f / 10000000.0f));
		percentage e4(28.0f,"ppt");
		CHECK(e4.get_value() == (28.0f / 10000000000.0f));
		percentage e5(28.0f,"ppq");
		CHECK(e5.get_value() == (28.0f / 10000000000000.0f));*/
		percentage f(28.0,"%");
		CHECK(f.get_value() == 28.0f);
		percentage f2(28.0,"ppm");
		CHECK(f2.get_value() == (28.0f / 10000.0f));
		percentage f3(28.0,"a");
		CHECK(f3.get_value() == 0.0f);
		/*percentage f3(28.0,"ppb");
		CHECK(f3.get_value() == (28.0f / 10000000.0f));
		percentage f4(28.0,"ppt");
		CHECK(f4.get_value() == (28.0f / 10000000000.0f));
		percentage f5(28.0,"ppq");
		CHECK(f5.get_value() == (28.0f / 10000000000000.0f));*/
		percentage g(28.0l,"%");
		CHECK(g.get_value() == 28.0f);
		percentage g2(28.0l,"ppm");
		CHECK(g2.get_value() == (28.0f / 10000.0f));
		percentage g3(28.0l,"a");
		CHECK(g3.get_value() == 0.0f);
		/*percentage g3(28.0l,"ppb");
		CHECK(g3.get_value() == (28.0f / 10000000.0f));
		percentage g4(28.0l,"ppt");
		CHECK(g4.get_value() == (28.0f / 10000000000.0f));
		percentage g5(28.0l,"ppq");
		CHECK(g5.get_value() == (28.0f / 10000000000000.0f));*/
		percentage h(28,"%");
		CHECK(h.get_value() == 28.0f);
		percentage h2(28,"ppm");
		CHECK(h2.get_value() == (28.0f / 10000.0f));
		percentage h3(28,"a");
		CHECK(h3.get_value() == 0.0f);
		/*percentage h3(28,"ppb");
		CHECK(h3.get_value() == (28.0f / 10000000.0f));
		percentage h4(28,"ppt");
		CHECK(h4.get_value() == (28.0f / 10000000000.0f));
		percentage h5(28,"ppq");
		CHECK(h5.get_value() == (28.0f / 10000000000000.0f));*/
		percentage i("24%");
		CHECK(i.get_value() == 24.0f);
		percentage i2("24ppm");
		CHECK(i2.get_value() == (24.0f / 10000.0f));
		percentage i3("24a");
		CHECK(i3.get_value() == 0.0f);
		percentage i4("24aqw");
		CHECK(i4.get_value() == 0.0f);
		/*percentage i3("24ppb");
		CHECK(i3.get_value() == (24.0f / 10000000.0f));
		percentage i4("24ppt");
		CHECK(i4.get_value() == (24.0f / 10000000000.0f));
		percentage i5("24ppq");
		CHECK(i5.get_value() == (24.0f / 10000000000000.0f));*/
		percentage i6("24 ppm");
		CHECK(i6.get_value() == (24.0f / 10000.0f));
		percentage i7("24 a");
		CHECK(i7.get_value() == 0.0f);
		/*percentage i7("24 ppb");
		CHECK(i7.get_value() == (24.0f / 10000000.0f));
		percentage i8("24 ppt");
		CHECK(i8.get_value() == (24.0f / 10000000000.0f));
		percentage i9("24 ppq");
		CHECK(i9.get_value() == (24.0f / 10000000000000.0f));*/
		scalar_unit j2 = 100_N;
		percentage j(j2 / 10_N);
		CHECK(j.get_value() == 10.0f);
		percentage j3(j2);
		CHECK(j3.get_value() == 0.0f);
	}

	SECTION("Assignments of percentage class") {
		percentage a("40%");
		percentage b("20%");
		a = b;
		CHECK(a.get_value() == 20.0f);
		percentage c("30%");
		a = std::move(c);
		CHECK(a.get_value() == 30.0f);
		a = 24.0f;
		CHECK(a.get_value() == 24.0f);
		a = 24.0;
		CHECK(a.get_value() == 24.0f);
		a = 24.0l;
		CHECK(a.get_value() == 24.0f);
		a = "29%";
		CHECK(a.get_value() == 29.0f);
		a = "29ppm";
		CHECK(a.get_value() == (29.0f / 10000.0f));
		a = "29a";
		CHECK(a.get_value() == 0.0f);
		a = "29aqe";
		CHECK(a.get_value() == 0.0f);
		/*a = "29ppb";
		CHECK(a.get_value() == (29.0f / 10000000.0f));
		a = "29ppt";
		CHECK(a.get_value() == (29.0f / 10000000000.0f));
		a = "29ppq";
		CHECK(a.get_value() == (29.0f / 10000000000000.0f));*/
		a = "29 ppm";
		CHECK(a.get_value() == (29.0f / 10000.0f));
		a = "29 a";
		CHECK(a.get_value() == 0.0f);
		/*a = "29 ppb";
		CHECK(a.get_value() == (29.0f / 10000000.0f));
		a = "29 ppt";
		CHECK(a.get_value() == (29.0f / 10000000000.0f));
		a = "29 ppq";
		CHECK(a.get_value() == (29.0f / 10000000000000.0f));*/
		scalar_unit d = 42_N;
		a = d / 21_N;
		CHECK(a.get_value() == 2.0f);
		a = d / 21.0f;
		CHECK(a.get_value() == 0.0f);
	}

	SECTION("Implicit conversion of percentage class") {
		percentage a = percentage("17%");
		CHECK(float(a) == 17.0f);
	}

	SECTION("Base functionalities of percentage class") {
		percentage a = percentage("90%");
		CHECK(a.get_factor() == 0.9f);
		CHECK(to_string(a) == "90%");
		percentage b = percentage("110%");
		CHECK(b.get_factor() == 1.1f);
		CHECK(to_string(b) == "110%");
		percentage c = percentage(30);
		CHECK(to_string(c) == "30%");
		percentage d = percentage(50,"%");
		CHECK(to_string(d) == "50%");
		percentage e = percentage(10_m / 1_m);
		CHECK(to_string(e) == "10%");
		percentage f = percentage("1 ppm");
		CHECK(f.get_factor() == 0.000001f);
		CHECK(f.display_ppm() == "1 ppm");
		/*percentage g = percentage("1 ppb");
		CHECK(g.get_factor() == 0.000000001f);
		CHECK(g.display_ppb() == "1 ppb");
		percentage h = percentage("1 ppt");
		CHECK(h.get_factor() == 0.000000000001f);
		CHECK(h.display_ppt() == "1 ppt");
		percentage i = percentage("1 ppq");
		CHECK(i.get_factor() == 0.000000000000001f);
		CHECK(i.display_ppq() == "1 ppq");*/
		percentage i = percentage("70%");
		CHECK(to_string(i) == "70%");
		i = 65;
		CHECK(to_string(i) == "65%");
		i = "46%";
		CHECK(to_string(i) == "46%");
		i = 50_s / 25_s;
		CHECK(to_string(i) == "2%");
		percentage j = percentage("34%");
		CHECK(float(j) == 34.0f);
		CHECK(j.get_value() == 34.0f);
		CHECK(to_string(a + j) == "124%");
		CHECK(to_string(a - j) == "56%");
		percentage k = percentage("50%");
		CHECK(to_string(a * k) == "45%");
		CHECK(to_string(a / k) == "180%");
		k += percentage("25%");
		CHECK(to_string(k) == "75%");
		k -= percentage("12%");
		CHECK(to_string(k) == "63%");
		percentage l = percentage("30%");
		percentage m = percentage("50%");
		l *= m;
		CHECK(to_string(l) == "15%");
		percentage n = percentage("30%");
		percentage o = percentage("50%");
		n /= o;
		CHECK(to_string(n) == "60%");
		percentage p = percentage("50%");
		p = 20;
		CHECK(to_string(p) == "20%");
		percentage q = percentage("50%");
		CHECK(to_string(q + 10) == "60%");
		percentage r = percentage("50%");
		CHECK(to_string(r - 10) == "40%");
		percentage s = percentage("50%");
		CHECK(to_string(s * 10) == "5.000000");
		percentage t = percentage("50%");
		CHECK(to_string(t / 2) == "0.250000");
		percentage u = percentage("50%");
		u += 20;
		CHECK(to_string(u) == "70%");
		percentage v = percentage("50%");
		v -= 5;
		CHECK(to_string(v) == "45%");
		percentage w = percentage("30%");
		w *= 2;
		CHECK(to_string(w) == "60%");
		percentage x = percentage("40%");
		x /= 2;
		CHECK(to_string(x) == "20%");
		percentage y = percentage("40%");
		y++;
		CHECK(to_string(y) == "41%");
		percentage z = percentage("30%");
		++z;
		CHECK(to_string(z) == "31%");
		percentage aa = percentage("40%");
		aa--;
		CHECK(to_string(aa) == "39%");
		percentage ab = percentage("30%");
		--ab;
		CHECK(to_string(ab) == "29%");
		percentage ac = percentage("20%");
		scalar_unit ad = scalar_unit("5 N");
		scalar_unit ae = ac * ad;
		CHECK(to_string(ae) == "1 N");
		CHECK(to_string(ad * ac) == "1 N");
		percentage af = percentage("200%");
		scalar_unit ag = scalar_unit("4 N");
		scalar_unit ah = af / ag;
		CHECK(to_string(ah) == "0.5 s2/kg*m");
		cout << "ag / af: " << to_string(ag / af) << endl;
		CHECK(to_string(ag / af) == "2 N");
		percentage ai = percentage("70%");
		CHECK(ai.get_factor() == 0.7f);
	}

	SECTION("ppm functions of percentage class") {
		percentage a = percentage("30%");
		CHECK(a.get_ppm() == 300000.0f);
		/*CHECK(a.get_ppb() == 300000000.0f);
		CHECK(a.get_ppt() == 300000000000.0f);
		CHECK(a.get_ppq() == 300000000000000.0f);*/
		CHECK(a.display_percentage() == "30%");
		CHECK(a.display_ppm() == "300000 ppm");
		/*cout << "ppb: " << a.display_ppb() << endl;
		cout << "ppt: " << a.display_ppt() << endl;
		cout << "ppq: " << a.display_ppq() << endl;
		CHECK(a.display_ppb() == "300000000 ppb");
		CHECK(a.display_ppt() == "300000000000 ppt");
		CHECK(a.display_ppq() == "300000000000000 ppq");*/
	}

	SECTION("to_string() function of percentage class") {
		percentage a = percentage("30%");
		CHECK(to_string(a) == "30%");
	}

	SECTION("Number operators of percentage class") {
		percentage a = percentage("30%");
		CHECK(bool((a + 20.0f) == percentage("50%")));
		CHECK(bool((a - 7.0f) == percentage("23%")));
		CHECK((a * 100.0f) == 30.0f);
		CHECK((a / 15.0f) == 0.02f);
		CHECK(bool(a == 30.0f));
		CHECK(bool(a != 20.0f));
		CHECK(bool(a > 20.0f));
		CHECK(bool(a < 35.0f));
		CHECK(bool(a >= 25.0f));
		CHECK(bool(a <= 40.0f));
		CHECK(bool((20.0f + a) == percentage("50%")));
		CHECK(bool((37.0f - a) == percentage("7%")));
		CHECK((100.0f * a) == 30.0f);
		CHECK((60.0f / a) == 200.0f);
		CHECK(bool(30.0f == a));
		CHECK(bool(20.0f != a));
		CHECK(bool(20.0f < a));
		CHECK(bool(35.0f > a));
		CHECK(bool(25.0f <= a));
		CHECK(bool(40.0f >= a));
	}

	SECTION("is_percentage() function")
	{
		CHECK(is_percentage("90%") == true);
		CHECK(is_percentage("90ppm") == true);
		/*CHECK(is_percentage("90ppb") == true);
		CHECK(is_percentage("90ppt") == true);
		CHECK(is_percentage("90ppq") == true);*/
		CHECK(is_percentage("90 ppm") == true);
		/*CHECK(is_percentage("90 ppb") == true);
		CHECK(is_percentage("90 ppt") == true);
		CHECK(is_percentage("90 ppq") == true);*/
		CHECK(is_percentage("90sad") == false);
		CHECK(is_percentage("90sad%") == false);
		CHECK(is_percentage("90.0%") == true);
		CHECK(is_percentage("90.0.0%") == false);
	}

	SECTION("Operators of percentage class with other percentage class") {
		percentage a = percentage("30%");
		percentage b = percentage("20%");
		CHECK(bool(a > b));
		CHECK(bool(a >= b));
		percentage c = percentage("30%");
		percentage d = percentage("20%");
		CHECK(bool(d < c));
		CHECK(bool(d <= c));
		percentage e = percentage("20%");
		percentage f = percentage("20%");
		CHECK(bool(e <= f));
		CHECK(bool(e >= f));
		CHECK(bool(e == f));
		CHECK(bool(a != b));
	}

	SECTION("String operators of percentage class") {
		CHECK(bool(percentage("45%") == "45%"));
		CHECK(bool(percentage("45%") != "40%"));
		CHECK(bool("45%" == percentage("45%")));
		CHECK(bool("40%" != percentage("45%")));
		string a = "percentage ";
		a += percentage("40%");
		CHECK(a == "percentage 40%");
		percentage b = percentage("20%");
		CHECK("b " + b == "b 20%");
		CHECK(b + " b" == "20% b");
	}

	SECTION("String operators of percentage class") {
		percentage a = percentage("25%");
		ostringstream out;
		out << "a " << a;
		CHECK(out.str() == "a 25%");
		stringstream b;
        b << "72%";
        percentage b2;
        b >> b2;
        CHECK(to_string(b2) == "72%");
	}
}


