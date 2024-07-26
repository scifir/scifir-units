#include "../units/prefix.hpp"
#include "../units/dimension.hpp"
#include "../meca_number/angle.hpp"
#include "../meca_number/complex_number.hpp"
#include "../meca_number/lab_number.hpp"
#include "../units/scalar_unit.hpp"
#include "../units/base_units.hpp"
#include "../units/vector_unit_2d.hpp"
#include "../units/vector_unit_3d.hpp"
#include "../units/vector_unit_nd.hpp"
#include "../topology/direction.hpp"
#include "../topology/point_1d.hpp"
#include "../topology/point_2d.hpp"
#include "../topology/point_3d.hpp"
#include "../topology/point_nd.hpp"
#include "../coordinates/coordinates_1d.hpp"
#include "../coordinates/coordinates_2d.hpp"
#include "../coordinates/coordinates_2dr.hpp"
#include "../coordinates/coordinates_3d.hpp"
#include "../coordinates/coordinates_3dr.hpp"
#include "../coordinates/coordinates_nd.hpp"
#include "../coordinates/coordinates_ndr.hpp"
#include "../special_units/aid.hpp"
#include "../special_units/percentage.hpp"
#include "../special_units/pH.hpp"
#include "../special_units/pixel.hpp"
#include "../special_units/pOH.hpp"
#include "../special_units/size_2d.hpp"
#include "../special_units/size_3d.hpp"
#include "../special_units/size_nd.hpp"
#include "../special_units/zid.hpp"

#include <iostream>
#include <string>

using namespace std;
using namespace scifir;

int main()
{
	cout << "sizes of the different classes of scifir-units, obtained with the sizeof() keyword of C++:" << endl;
	cout << "prefix: " << sizeof(prefix) << endl;
	cout << "dimension: " << sizeof(dimension) << endl;
	cout << "vector<float>: " << sizeof(vector<float>) << endl;
	cout << "vector<dimension>: " << sizeof(vector<dimension>) << endl;
	cout << "dimension[]: " << sizeof(dimension[1]) << endl;
	cout << endl;
	cout << "angle: " << sizeof(angle) << endl;
	cout << "complex_number<>: " << sizeof(complex_number<length>) << endl;
	cout << "lab_number<>: " << sizeof(lab_number<length>) << endl;
	cout << endl;
	cout << "scalar_unit: " << sizeof(scalar_unit) << endl;
	cout << "vector_unit_2d: " << sizeof(vector_unit_2d) << endl;
	cout << "vector_unit_3d: " << sizeof(vector_unit_3d) << endl;
	cout << "vector_unit_nd: " << sizeof(vector_unit_nd) << endl;
	cout << endl;
	cout << "direction: " << sizeof(direction) << endl;
	cout << "point_1d<>: " << sizeof(point_1d<>) << endl;
	cout << "point_2d<>: " << sizeof(point_2d<>) << endl;
	cout << "point_3d<>: " << sizeof(point_3d<>) << endl;
	cout << "point_nd<>: " << sizeof(point_nd<>) << endl;
	cout << endl;
	cout << "point_1d<float>: " << sizeof(point_1d<float>) << endl;
	cout << "point_2d<float>: " << sizeof(point_2d<float>) << endl;
	cout << "point_3d<float>: " << sizeof(point_3d<float>) << endl;
	cout << "point_nd<float>: " << sizeof(point_nd<float>) << endl;
	cout << endl;
	cout << "coordinates_1d<>: " << sizeof(coordinates_1d<>) << endl;
	cout << "coordinates_2d<>: " << sizeof(coordinates_2d<>) << endl;
	cout << "coordinates_2dr<>: " << sizeof(coordinates_2dr<>) << endl;
	cout << "coordinates_3d<>: " << sizeof(coordinates_3d<>) << endl;
	cout << "coordinates_3dr<>: " << sizeof(coordinates_3dr<>) << endl;
	cout << "coordinates_nd<>: " << sizeof(coordinates_nd<>) << endl;
	cout << "coordinates_ndr<>: " << sizeof(coordinates_ndr<>) << endl;
	cout << endl;
	cout << "coordinates_1d<float>: " << sizeof(coordinates_1d<float>) << endl;
	cout << "coordinates_2d<float>: " << sizeof(coordinates_2d<float>) << endl;
	cout << "coordinates_2dr<float>: " << sizeof(coordinates_2dr<float>) << endl;
	cout << "coordinates_3d<float>: " << sizeof(coordinates_3d<float>) << endl;
	cout << "coordinates_3dr<float>: " << sizeof(coordinates_3dr<float>) << endl;
	cout << "coordinates_nd<float>: " << sizeof(coordinates_nd<float>) << endl;
	cout << "coordinates_ndr<float>: " << sizeof(coordinates_ndr<float>) << endl;
	cout << endl;
	cout << "aid: " << sizeof(aid) << endl;
	cout << "percentage: " << sizeof(percentage) << endl;
	cout << "pH: " << sizeof(pH) << endl;
	cout << "pixel: " << sizeof(pixel) << endl;
	cout << "pOH: " << sizeof(pOH) << endl;
	cout << "size_2d<>: " << sizeof(size_2d<>) << endl;
	cout << "size_3d<>: " << sizeof(size_3d<>) << endl;
	cout << "size_nd<>: " << sizeof(size_nd<>) << endl;
	cout << "zid: " << sizeof(zid) << endl;
	cout << endl;
	cout << "C++ types:" << endl;
	cout << "short: " << sizeof(short) << endl;
	cout << "int: " << sizeof(int) << endl;
	cout << "long: " << sizeof(long) << endl;
	cout << "long long: " << sizeof(long long) << endl;
	cout << "float: " << sizeof(float) << endl;
	cout << "double: " << sizeof(double) << endl;
	cout << "long double: " << sizeof(long double) << endl;
	cout << endl;
	cout << "string: " << sizeof(string) << endl;
}
