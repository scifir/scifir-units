#include "msci/units.hpp"

#include <iostream>

using namespace std;

int main()
{
	msci::prefix prefix_a("m");
	msci::prefix prefix_b = create_prefix("m");

	cout << "prefix a: " << prefix_a << endl;
	cout << "prefix b: " << prefix_b << endl;

	msci::dimension dimension_a = create_dimension("cm");

	cout << "dimension a: " << dimension_a << endl;

	msci::length a("50 m");
	msci::length b("30 m");
	msci::length c("30 s");
	msci::length d("5.41905738 mm");
	msci::length e("5 cm");

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
	cout << "e: " << e << endl;

	cout << "a + b: " << (a + b) << endl;
	cout << "a + c: " << (a + c) << endl;
	cout << "a + d: " << (a + d) << endl;
	cout << "d + a: " << (d + a) << endl;
	cout << "d + e: " << (e + d) << endl;

	/*msci::length f = e + d;
	cout << "f: " << f.display(0) << endl;*/
}
