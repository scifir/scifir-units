#ifndef SCIFIR_UNITS_TOPOLOGY_CONSTANTS_HPP_INCLUDED
#define SCIFIR_UNITS_TOPOLOGY_CONSTANTS_HPP_INCLUDED

#include "boost/math/constants/constants.hpp"

using namespace std;

namespace scifir
{
	constexpr float PI = boost::math::constants::pi<float>();
	const static long double AVOGADRO_CONSTANT = 6.02214076e23;
}

#endif // SCIFIR_UNITS_TOPOLOGY_CONSTANTS_HPP_INCLUDED
