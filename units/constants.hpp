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
}

#endif // SCIFIR_UNITS_UNITS_CONSTANTS_HPP_INCLUDED
