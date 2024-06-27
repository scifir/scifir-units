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
		CHECK (bool(a.get_value() == 0.0f));
		percentage b("23%");
		percentage c(b);
		CHECK (bool(c.get_value() == 23.0f));
		percentage c2(std::move(b));
		CHECK (bool(c.get_value() == 23.0f));
		percentage d(26.0f);
		CHECK (bool(d.get_value() == 26.0f));
		percentage d2(26.0);
		CHECK (bool(d2.get_value() == 26.0f));
		percentage d3(26.0l);
		CHECK (bool(d3.get_value() == 26.0f));
		percentage d4(26);
		CHECK (bool(d4.get_value() == 26.0f));
		percentage e(28.0f,"%");
		CHECK (bool(e.get_value() == 28.0f));
		percentage e2(28.0f,"ppm");
		CHECK (bool(e2.get_value() == (28.0f / 10000.0f)));
		percentage e3(28.0f,"a");
		CHECK (bool(e3.get_value() == 0.0f));
		/*percentage e3(28.0f,"ppb");
		CHECK (bool(e3.get_value() == (28.0f / 10000000.0f)));
		percentage e4(28.0f,"ppt");
		CHECK (bool(e4.get_value() == (28.0f / 10000000000.0f)));
		percentage e5(28.0f,"ppq");
		CHECK (bool(e5.get_value() == (28.0f / 10000000000000.0f)));*/
		percentage f(28.0,"%");
		CHECK (bool(f.get_value() == 28.0f));
		percentage f2(28.0,"ppm");
		CHECK (bool(f2.get_value() == (28.0f / 10000.0f)));
		percentage f3(28.0,"a");
		CHECK (bool(f3.get_value() == 0.0f));
		/*percentage f3(28.0,"ppb");
		CHECK (bool(f3.get_value() == (28.0f / 10000000.0f)));
		percentage f4(28.0,"ppt");
		CHECK (bool(f4.get_value() == (28.0f / 10000000000.0f)));
		percentage f5(28.0,"ppq");
		CHECK (bool(f5.get_value() == (28.0f / 10000000000000.0f)));*/
		percentage g(28.0l,"%");
		CHECK (bool(g.get_value() == 28.0f));
		percentage g2(28.0l,"ppm");
		CHECK (bool(g2.get_value() == (28.0f / 10000.0f)));
		percentage g3(28.0l,"a");
		CHECK (bool(g3.get_value() == 0.0f));
		/*percentage g3(28.0l,"ppb");
		CHECK (bool(g3.get_value() == (28.0f / 10000000.0f)));
		percentage g4(28.0l,"ppt");
		CHECK (bool(g4.get_value() == (28.0f / 10000000000.0f)));
		percentage g5(28.0l,"ppq");
		CHECK (bool(g5.get_value() == (28.0f / 10000000000000.0f)));*/
		percentage h(28,"%");
		CHECK (bool(h.get_value() == 28.0f));
		percentage h2(28,"ppm");
		CHECK (bool(h2.get_value() == (28.0f / 10000.0f)));
		percentage h3(28,"a");
		CHECK (bool(h3.get_value() == 0.0f));
		/*percentage h3(28,"ppb");
		CHECK (bool(h3.get_value() == (28.0f / 10000000.0f)));
		percentage h4(28,"ppt");
		CHECK (bool(h4.get_value() == (28.0f / 10000000000.0f)));
		percentage h5(28,"ppq");
		CHECK (bool(h5.get_value() == (28.0f / 10000000000000.0f)));*/
		percentage i("24%");
		CHECK (bool(i.get_value() == 24.0f));
		percentage i2("24ppm");
		CHECK (bool(i2.get_value() == (24.0f / 10000.0f)));
		percentage i3("24a");
		CHECK (bool(i3.get_value() == 0.0f));
		percentage i4("24aqw");
		CHECK (bool(i4.get_value() == 0.0f));
		/*percentage i3("24ppb");
		CHECK (bool(i3.get_value() == (24.0f / 10000000.0f)));
		percentage i4("24ppt");
		CHECK (bool(i4.get_value() == (24.0f / 10000000000.0f)));
		percentage i5("24ppq");
		CHECK (bool(i5.get_value() == (24.0f / 10000000000000.0f)));*/
		percentage i6("24 ppm");
		CHECK (bool(i6.get_value() == (24.0f / 10000.0f)));
		percentage i7("24 a");
		CHECK (bool(i7.get_value() == 0.0f));
		/*percentage i7("24 ppb");
		CHECK (bool(i7.get_value() == (24.0f / 10000000.0f)));
		percentage i8("24 ppt");
		CHECK (bool(i8.get_value() == (24.0f / 10000000000.0f)));
		percentage i9("24 ppq");
		CHECK (bool(i9.get_value() == (24.0f / 10000000000000.0f)));*/
		scalar_unit j2 = 100_N;
		percentage j(j2 / 10_N);
		CHECK (bool(j.get_value() == 10.0f));
		percentage j3(j2);
		CHECK (bool(j3.get_value() == 0.0f));
	}

	SECTION("Assignments of percentage class") {
		percentage a("40%");
		percentage b("20%");
		a = b;
		CHECK (bool(a.get_value() == 20.0f));
		percentage c("30%");
		a = std::move(c);
		CHECK (bool(a.get_value() == 30.0f));
		a = 24.0f;
		CHECK (bool(a.get_value() == 24.0f));
		a = 24.0;
		CHECK (bool(a.get_value() == 24.0f));
		a = 24.0l;
		CHECK (bool(a.get_value() == 24.0f));
		a = "29%";
		CHECK (bool(a.get_value() == 29.0f));
		a = "29ppm";
		CHECK (bool(a.get_value() == (29.0f / 10000.0f)));
		a = "29a";
		CHECK (bool(a.get_value() == 0.0f));
		a = "29aqe";
		CHECK (bool(a.get_value() == 0.0f));
		/*a = "29ppb";
		CHECK (bool(a.get_value() == (29.0f / 10000000.0f)));
		a = "29ppt";
		CHECK (bool(a.get_value() == (29.0f / 10000000000.0f)));
		a = "29ppq";
		CHECK (bool(a.get_value() == (29.0f / 10000000000000.0f)));*/
		a = "29 ppm";
		CHECK (bool(a.get_value() == (29.0f / 10000.0f)));
		a = "29 a";
		CHECK (bool(a.get_value() == 0.0f));
		/*a = "29 ppb";
		CHECK (bool(a.get_value() == (29.0f / 10000000.0f)));
		a = "29 ppt";
		CHECK (bool(a.get_value() == (29.0f / 10000000000.0f)));
		a = "29 ppq";
		CHECK (bool(a.get_value() == (29.0f / 10000000000000.0f)));*/
		scalar_unit d = 42_N;
		a = d / 21_N;
		CHECK (bool(a.get_value() == 2.0f));
		a = d / 21.0f;
		CHECK (bool(a.get_value() == 0.0f));
	}

	SECTION("Implicit conversion of percentage class") {
		percentage a = percentage("17%");
		CHECK (bool(float(a) == 17.0f));
	}

	SECTION("Base functionalities of percentage class") {
		percentage a = percentage("90%");
		CHECK (bool(a.get_factor() == 0.9f));
		CHECK (bool(to_string(a) == "90%"));
		percentage b = percentage("110%");
		CHECK (bool(b.get_factor() == 1.1f));
		CHECK (bool(to_string(b) == "110%"));
		percentage c = percentage(30);
		CHECK (bool(to_string(c) == "30%"));
		percentage d = percentage(50,"%");
		CHECK (bool(to_string(d) == "50%"));
		percentage e = percentage(10_m / 1_m);
		CHECK (bool(to_string(e) == "10%"));
		percentage f = percentage("1 ppm");
		CHECK (bool(f.get_factor() == 0.000001f));
		CHECK (bool(f.display_ppm() == "1 ppm"));
		/*percentage g = percentage("1 ppb");
		CHECK (bool(g.get_factor() == 0.000000001f));
		CHECK (bool(g.display_ppb() == "1 ppb"));
		percentage h = percentage("1 ppt");
		CHECK (bool(h.get_factor() == 0.000000000001f));
		CHECK (bool(h.display_ppt() == "1 ppt"));
		percentage i = percentage("1 ppq");
		CHECK (bool(i.get_factor() == 0.000000000000001f));
		CHECK (bool(i.display_ppq() == "1 ppq"));*/
		percentage i = percentage("70%");
		CHECK (bool(to_string(i) == "70%"));
		i = 65;
		CHECK (bool(to_string(i) == "65%"));
		i = "46%";
		CHECK (bool(to_string(i) == "46%"));
		i = 50_s / 25_s;
		CHECK (bool(to_string(i) == "2%"));
		percentage j = percentage("34%");
		CHECK (bool(float(j) == 34.0f));
		CHECK (bool(j.get_value() == 34.0f));
		CHECK (bool(to_string(a + j) == "124%"));
		CHECK (bool(to_string(a - j) == "56%"));
		percentage k = percentage("50%");
		CHECK (bool(to_string(a * k) == "45%"));
		CHECK (bool(to_string(a / k) == "180%"));
		k += percentage("25%");
		CHECK (bool(to_string(k) == "75%"));
		k -= percentage("12%");
		CHECK (bool(to_string(k) == "63%"));
		percentage l = percentage("30%");
		percentage m = percentage("50%");
		l *= m;
		CHECK (bool(to_string(l) == "15%"));
		percentage n = percentage("30%");
		percentage o = percentage("50%");
		n /= o;
		CHECK (bool(to_string(n) == "60%"));
		percentage p = percentage("50%");
		p = 20;
		CHECK (bool(to_string(p) == "20%"));
		percentage q = percentage("50%");
		CHECK (bool(to_string(q + 10) == "60%"));
		percentage r = percentage("50%");
		CHECK (bool(to_string(r - 10) == "40%"));
		percentage s = percentage("50%");
		CHECK (bool(to_string(s * 10) == "5.000000"));
		percentage t = percentage("50%");
		CHECK (bool(to_string(t / 2) == "0.250000"));
		percentage u = percentage("50%");
		u += 20;
		CHECK (bool(to_string(u) == "70%"));
		percentage v = percentage("50%");
		v -= 5;
		CHECK (bool(to_string(v) == "45%"));
		percentage w = percentage("30%");
		w *= 2;
		CHECK (bool(to_string(w) == "60%"));
		percentage x = percentage("40%");
		x /= 2;
		CHECK (bool(to_string(x) == "20%"));
		percentage y = percentage("40%");
		y++;
		CHECK (bool(to_string(y) == "41%"));
		percentage z = percentage("30%");
		++z;
		CHECK (bool(to_string(z) == "31%"));
		percentage aa = percentage("40%");
		aa--;
		CHECK (bool(to_string(aa) == "39%"));
		percentage ab = percentage("30%");
		--ab;
		CHECK (bool(to_string(ab) == "29%"));
		percentage ac = percentage("20%");
		scalar_unit ad = scalar_unit("5 N");
		scalar_unit ae = ac * ad;
		CHECK (bool(to_string(ae) == "1 N"));
		CHECK (bool(to_string(ad * ac) == "1 N"));
		percentage af = percentage("200%");
		scalar_unit ag = scalar_unit("4 N");
		scalar_unit ah = af / ag;
		CHECK (bool(to_string(ah) == "0.5 s2/kg*m"));
		cout << "ag / af: " << to_string(ag / af) << endl;
		CHECK (bool(to_string(ag / af) == "2 N"));
		percentage ai = percentage("70%");
		CHECK (bool(ai.get_factor() == 0.7f));
	}

	SECTION("ppm functions of percentage class") {
		percentage a = percentage("30%");
		CHECK (bool(a.get_ppm() == 300000.0f));
		/*CHECK (bool(a.get_ppb() == 300000000.0f));
		CHECK (bool(a.get_ppt() == 300000000000.0f));
		CHECK (bool(a.get_ppq() == 300000000000000.0f));*/
		CHECK (bool(a.display_ppm() == "300000 ppm"));
		/*cout << "ppb: " << a.display_ppb() << endl;
		cout << "ppt: " << a.display_ppt() << endl;
		cout << "ppq: " << a.display_ppq() << endl;
		CHECK (bool(a.display_ppb() == "300000000 ppb"));
		CHECK (bool(a.display_ppt() == "300000000000 ppt"));
		CHECK (bool(a.display_ppq() == "300000000000000 ppq"));*/
	}

	SECTION("to_string() function of percentage class") {
		percentage a = percentage("30%");
		CHECK (bool(to_string(a) == "30%"));
	}

	SECTION("Number operators of percentage class") {
		percentage a = percentage("30%");
		CHECK (bool((a + 20.0f) == percentage("50%")));
		CHECK (bool((a - 7.0f) == percentage("23%")));
		CHECK (bool((a * 100.0f) == 30.0f));
		CHECK (bool((a / 15.0f) == 0.02f));
		CHECK (bool(a == 30.0f));
		CHECK (bool(a != 20.0f));
		CHECK (bool(a > 20.0f));
		CHECK (bool(a < 35.0f));
		CHECK (bool(a >= 25.0f));
		CHECK (bool(a <= 40.0f));
		CHECK (bool((20.0f + a) == percentage("50%")));
		CHECK (bool((37.0f - a) == percentage("7%")));
		CHECK (bool((100.0f * a) == 30.0f));
		CHECK (bool((60.0f / a) == 200.0f));
		CHECK (bool(30.0f == a));
		CHECK (bool(20.0f != a));
		CHECK (bool(20.0f < a));
		CHECK (bool(35.0f > a));
		CHECK (bool(25.0f <= a));
		CHECK (bool(40.0f >= a));
	}

	SECTION("is_percentage() function")
	{
		CHECK (bool(is_percentage("90%") == true));
		CHECK (bool(is_percentage("90ppm") == true));
		/*CHECK (bool(is_percentage("90ppb") == true));
		CHECK (bool(is_percentage("90ppt") == true));
		CHECK (bool(is_percentage("90ppq") == true));*/
		CHECK (bool(is_percentage("90 ppm") == true));
		/*CHECK (bool(is_percentage("90 ppb") == true));
		CHECK (bool(is_percentage("90 ppt") == true));
		CHECK (bool(is_percentage("90 ppq") == true));*/
		CHECK (bool(is_percentage("90sad") == false));
		CHECK (bool(is_percentage("90sad%") == false));
		CHECK (bool(is_percentage("90.0%") == true));
		CHECK (bool(is_percentage("90.0.0%") == false));
	}

	SECTION("Operators of percentage class with other percentage classes") {
		percentage a = percentage("30%");
		percentage b = percentage("20%");
		CHECK (bool(a > b));
		CHECK (bool(a >= b));
		percentage c = percentage("30%");
		percentage d = percentage("20%");
		CHECK (bool(d < c));
		CHECK (bool(d <= c));
		percentage e = percentage("20%");
		percentage f = percentage("20%");
		CHECK (bool(e <= f));
		CHECK (bool(e >= f));
		CHECK (bool(e == f));
		CHECK (bool(a != b));
	}

	SECTION("String operators of percentage class") {
		CHECK (bool(percentage("45%") == "45%"));
		CHECK (bool(percentage("45%") != "40%"));
		CHECK (bool("45%" == percentage("45%")));
		CHECK (bool("40%" != percentage("45%")));
		string a = "percentage ";
		a += percentage("40%");
		CHECK (bool(a == "percentage 40%"));
		percentage b = percentage("20%");
		CHECK (bool("b " + b == "b 20%"));
		CHECK (bool(b + " b" == "20% b"));
	}

	SECTION("String operators of percentage class") {
		percentage a = percentage("25%");
		ostringstream out;
		out << "a " << a;
		CHECK (bool(out.str() == "a 25%"));
		stringstream b;
        b << "72%";
        percentage b2;
        b >> b2;
        CHECK (bool(to_string(b2) == "72%"));
	}
}


