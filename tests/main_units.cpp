#include "units.hpp"

#include <iostream>

using namespace std;

int main()
{
	scifir::prefix prefix_a("m");
	scifir::prefix prefix_b = prefix("m");

	cout << "prefix a: " << prefix_a << endl;
	cout << "prefix b: " << prefix_b << endl;

	dimension dimension_a = dimension("cm",dimension::POSITIVE);

	cout << "dimension a: " << dimension_a << endl;

	scifir::length a("50 m");
	scifir::length b("30 m");
	scifir::length c("30 s");
	scifir::length d("5.41905738 mm");
	scifir::length e("5 cm");

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

	/*scifir::length f = e + d;
	cout << "f: " << f.display(0) << endl;*/
}
