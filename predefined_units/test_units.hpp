#ifndef TEST_UNITS_HPP_INCLUDED
#define TEST_UNITS_HPP_INCLUDED

#include "physics/units.hpp"

#include <iostream>
#include <sstream>

using namespace std;

TEST_CASE("Testing autounit","Testing of autounit")
{
	auto_unit a(100,"g");
	wostringstream a_out;
	a_out << a;
	REQUIRE (a_out.str() == L"100 g");
	auto_unit b(50,"g");
	wostringstream b_out;
	b_out << b;
	REQUIRE (b_out.str() == L"50 g");
	REQUIRE ((a + b) == 150_g);
	REQUIRE ((a - b) == 50_g);
	REQUIRE ((a * b) == "5000 g2");
	/*wcout << "wcout << "a (real_dimensions): " << a.get_real_dimensions() << endl;
	wcout << "a (actual_dimensions): " << a.get_actual_dimensions() << endl;
	wcout << "a + b: " << (a + b) << endl;
	wcout << "a - b: " << (a - b) << endl;
	wcout << "a * b: " << (a * b) << endl;
	wcout << "a / b: " << (a / b) << endl;
	wcout << "a ^ b: " << (a ^ b) << endl;
	a += b;
	wcout << "a += b: " << a << endl;
	a -= b;
	wcout << "a -= b: " << a << endl;
	wcout << "a + 20: " << (a + 20) << endl;
	wcout << "a - 10: " << (a - 10) << endl;
	wcout << "a * 5: " << (a * 5) << endl;
	wcout << "a / 2: " << (a / 2) << endl;
	wcout << "a ^ 3: " << (a ^ 3) << endl;
	wcout << "20 + a: " << (20 + a) << endl;
	wcout << "150 - a: " << (150 - a) << endl;
	wcout << "3 * a: " << (3 * a) << endl;
	wcout << "200 / a: " << (200 / a) << endl;
	a = auto_unit(30,"g");
	wcout << "a = 30: " << a << endl;
	a = auto_unit(100,"g");
	a += 10;
	wcout << "a += 10: " << a << endl;
	a = auto_unit(100,"g");
	a -= 5;
	wcout << "a -= 5: " << a << endl;
	a = auto_unit(100,"g");
	a *= 2;
	wcout << "a *= 2: " << a << endl;
	a = auto_unit(100,"g");
	a /= 4;
	wcout << "a /= 4: " << a << endl;
	a = auto_unit(100,"g");
	a ^= 2;
	wcout << "a ^= 2: " << a << endl;
	a = auto_unit(100,"g");
	a.change_dimensions("kg");
	wcout << "a (in kg): " << a << endl;
	a.change_dimensions("mg");
	wcout << "a (in mg): " << a << endl;
	a = auto_unit(100,"g");
	a++;
	wcout << "a++: " << a << endl;
	a = auto_unit(100,"g");
	++a;
	wcout << "++a: " << a << endl;
	a = auto_unit(100,"g");
	a--;
	wcout << "a--: " << a << endl;
	a = auto_unit(100,"g");
	--a;
	wcout << "--a: " << a << endl;
	a = auto_unit(100,"g");
	b = auto_unit(50,"g");
	wcout << "b + a++: " << (b + a++) << endl;
	a = auto_unit(100,"g");
	b = auto_unit(50,"g");
	wcout << "b + ++a: " << (b + ++a) << endl;
	a = auto_unit(100,"g");
	b = auto_unit(50,"g");
	wcout << "b + a--: " << (b + a--) << endl;
	a = auto_unit(100,"g");
	b = auto_unit(50,"g");
	wcout << "b + --a: " << (b + --a) << endl;
	wcout << "a (equal dimensions to g): " << a.equal_dimensions("g") << endl;
	wcout << "a (equal dimensions to kg): " << a.equal_dimensions("kg") << endl;
	wcout << endl;*/
}

#endif // TEST_UNITS_HPP_INCLUDED
