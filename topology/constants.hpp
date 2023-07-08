#ifndef SCIFIR_UNITS_TOPOLOGY_CONSTANTS_HPP_INCLUDED
#define SCIFIR_UNITS_TOPOLOGY_CONSTANTS_HPP_INCLUDED

#include "boost/math/constants/constants.hpp"

using namespace std;

namespace scifir
{
	constexpr float PI = boost::math::constants::pi<float>();
	const static long double AVOGADRO_CONSTANT = 602214078000000000000000.0l;
}

#endif // SCIFIR_UNITS_TOPOLOGY_CONSTANTS_HPP_INCLUDED
