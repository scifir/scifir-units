#ifndef SCIFIR_UNITS_PREDEFINED_UNITS_WAVES_UNITS_HPP_INCLUDED
#define SCIFIR_UNITS_PREDEFINED_UNITS_WAVES_UNITS_HPP_INCLUDED

#include "units/scalar_unit.hpp"
#include "units/vector_unit_3d.hpp"

#include "units/unit_basic.hpp"

using namespace std;

namespace scifir
{
	SCALAR_UNIT_HPP(wavenumber);
	SCALAR_UNIT_HPP(frequency);
	
	typedef length wavelength;
}

#endif // SCIFIR_UNITS_PREDEFINED_UNITS_WAVES_UNITS_HPP_INCLUDED
