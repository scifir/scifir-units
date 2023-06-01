#ifndef MSCI_UNITS_PREDEFINED_UNITS_RADIOMETRY_UNITS_HPP_INCLUDED
#define MSCI_UNITS_PREDEFINED_UNITS_RADIOMETRY_UNITS_HPP_INCLUDED

#include "units/scalar_unit.hpp"
#include "units/vector_unit_3d.hpp"

using namespace std;

namespace msci
{
	SCALAR_UNIT_HPP(radioactivity);
	VECTOR_UNIT_HPP(irradiance);
	VECTOR_UNIT_HPP(radiant_exposure);
	SCALAR_UNIT_HPP(radiant_intensity);
	SCALAR_UNIT_HPP(spectral_intensity);
	SCALAR_UNIT_HPP(radiance);
	SCALAR_UNIT_HPP(spectral_radiance);
	VECTOR_UNIT_HPP(radiant_flux);
	VECTOR_UNIT_HPP(spectral_flux);
}

#endif // MSCI_UNITS_PREDEFINED_UNITS_RADIOMETRY_UNITS_HPP_INCLUDED
