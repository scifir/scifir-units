#include "msci/units.hpp"

#include <iostream>

using namespace std;

int main()
{
	msci::auto_scalar a("50 m");
	msci::auto_scalar b("30 m");
	msci::auto_scalar c("30 s");
	msci::length d("5.41905738 mm");
	msci::length e("5 cm");

	cout << "a + b: " << (a + b) << endl;
	cout << "a + c: " << (a + c) << endl;
	cout << "a + d: " << (a + d) << endl;
	cout << "d + e: " << (e + d) << endl;

	msci::length f = e + d;
	cout << "f: " << f.display(0) << endl;
}
