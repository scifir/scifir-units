#ifndef SCIFIR_UNITS_UNITS_CONSTANTS_HPP_INCLUDED
#define SCIFIR_UNITS_UNITS_CONSTANTS_HPP_INCLUDED

#include "boost/math/constants/constants.hpp"

using namespace std;

namespace scifir
{
	constexpr float PI = boost::math::constants::pi<float>();
	const long double HYPERFINE_TRANSITION_FREQUENCY_OF_CS = 9192631770.0l;
	const long double SPEED_OF_LIGHT = 299792458.0l;
	const long double PLANCK_CONSTANT = 6.62607015e-34;
	const long double ELEMENTARY_CHARGE = 1.602176634e-19;
	const long double BOLTZMANN_CONSTANT = 1.380649e-23;
	const long double AVOGADRO_CONSTANT = 6.02214076e23;
	const long double LUMINOUS_EFFICACY_OF_540_THZ_RADIATION = 683.0l;

	const long double GRAVITATIONAL_CONSTANT = 6.6743e-11;
	const long double MOLAR_GAS_CONSTANT = 8.31446261815324l;
	const long double ATOMIC_MASS_CONSTANT = 1.66053906660e-27;
	const long double COULOMB_CONSTANT = 8.9875517873681764e9;
	const long double VACUUM_PERMITTIVITY = 8.8541878188e-12;
	const long double RYDBERG_CONSTANT = 1.0973731568539e7;
	const long double FARADAY_CONSTANT = 9.64853321233100184e4;
}

#endif // SCIFIR_UNITS_UNITS_CONSTANTS_HPP_INCLUDED
