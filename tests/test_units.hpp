#ifndef TEST_UNITS_HPP_INCLUDED
#define TEST_UNITS_HPP_INCLUDED

#include "msci/units.hpp"

#include <iostream>
#include <sstream>

using namespace std;

TEST_CASE("class unit","Test of abstract class unit using class auto_unit")
{
	auto_unit a(100,"g");
	ostringstream a_out;
	a_out << a;
	REQUIRE (a_out.str() == "100 g");
	auto_unit b(50,"g");
	ostringstream b_out;
	b_out << b;
	REQUIRE (b_out.str() == "50 g");
	REQUIRE ((a + b) == 150_g);
	REQUIRE ((a - b) == 50_g);
	REQUIRE ((a * b) == "5000 g2");
	REQUIRE ((a / b) == "2 [empty]");
	REQUIRE_FALSE ((a ^ b).is_defined());
	a += b;
	REQUIRE (a == 150_g);
	a = auto_unit(100,"g");
	a -= b;
	REQUIRE (a == 50_g);
	a = auto_unit(100,"g");
	REQUIRE ((a + 20) == 120_g);
	REQUIRE ((a - 10) == 90_g);
	REQUIRE ((a * 5) == 500_g);
	REQUIRE ((a / 2) == 50_g);
	REQUIRE ((a ^ 3) == "1000000 g3");
	REQUIRE ((20 + a) == 120_g);
	REQUIRE ((150 - a) == 50_g);
	REQUIRE ((3 * a) == 300_g);
	REQUIRE ((200 / a) == "2 1/g");
	a = auto_unit(100,"g");
	a += 10;
	REQUIRE (a == 110_g);
	a = auto_unit(100,"g");
	a -= 5;
	REQUIRE (a == 95_g);
	a = auto_unit(100,"g");
	a *= 2;
	REQUIRE (a == 200_g);
	a = auto_unit(100,"g");
	a /= 4;
	REQUIRE (a == 25_g);
	a = auto_unit(100,"g");
	a ^= 2;
	REQUIRE (a == 10000_g);
	a = auto_unit(100,"g");
	a++;
	REQUIRE (a == 101_g);
	a = auto_unit(100,"g");
	++a;
	REQUIRE (a == 101_g);
	a = auto_unit(100,"g");
	a--;
	REQUIRE (a == 99_g);
	a = auto_unit(100,"g");
	--a;
	REQUIRE (a == 99_g);
	a = auto_unit(100,"g");
	a.change_dimensions("kg");
	a_out = ostringstream();
	a_out << a;
	REQUIRE (a_out.str() == "0.1 kg");
	a.change_dimensions("mg");
	a_out = ostringstream();
	a_out << a;
	REQUIRE (a_out.str() == "100000 mg");
	REQUIRE (a.has_dimensions("g"));
	REQUIRE (a.has_dimensions("kg"));
	REQUIRE (a.has_dimensions("mg"));
	REQUIRE_FALSE(a.has_empty_dimensions());
	a = auto_unit(100,"g");
	b = auto_unit(50,"g");
	REQUIRE ((a / b).has_empty_dimensions());
	REQUIRE (a < 110_g);
	REQUIRE_FALSE (a < 90_g);
	REQUIRE (a > 70_g);
	REQUIRE_FALSE (a > 120_g);
	REQUIRE (a <= 100_g);
	REQUIRE_FALSE (a <= 90_g);
	REQUIRE (a >= 100_g);
	REQUIRE_FALSE (a >= 110_g);
	auto_unit c = auto_unit(100,"g");
	auto_unit d = auto_unit(50,"m");
	c = d;
	REQUIRE_FALSE (c.is_defined());
	/*cout << "cout << "a (real_dimensions): " << a.get_real_dimensions() << endl;
	cout << "a (actual_dimensions): " << a.get_actual_dimensions() << endl;
	a = auto_unit(100,"g");
	b = auto_unit(50,"g");
	cout << "b + a++: " << (b + a++) << endl;
	a = auto_unit(100,"g");
	b = auto_unit(50,"g");
	cout << "b + ++a: " << (b + ++a) << endl;
	a = auto_unit(100,"g");
	b = auto_unit(50,"g");
	cout << "b + a--: " << (b + a--) << endl;
	a = auto_unit(100,"g");
	b = auto_unit(50,"g");
	cout << "b + --a: " << (b + --a) << endl;
	cout << endl;*/
}

#endif // TEST_UNITS_HPP_INCLUDED
