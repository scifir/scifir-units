#include "./units.hpp"

#include <string>

using namespace std;

namespace msci::units
{
	SCALAR_UNIT_CPP(molarity,"mol/m3");
	SCALAR_UNIT_CPP(molality,"mol/g");
	SCALAR_UNIT_CPP(concentration,"g/g");
	SCALAR_UNIT_CPP(linear_mass_density,"g/m");
	SCALAR_UNIT_CPP(area_density,"g/m2");
	SCALAR_UNIT_CPP(dynamic_viscosity,"g/m*s");
	SCALAR_UNIT_CPP(mass_flow_rate,"g/s");
	SCALAR_UNIT_CPP(catalytic_activity,"kat");
}

wostream& operator <<(wostream& os, const msci::units::concentration& x)
{
	string dimension_structure = msci::units::get_dimension_structure(x.get_actual_dimensions());
	if (dimension_structure != "ppm" and dimension_structure != "ppb")
	{
		return os << (x.get_value() * 100) << "%";
	}
	else
	{
		return os << static_cast<const msci::units::unit&>(x);
	}
}
