#ifndef CONSTANTS_HPP_INCLUDED
#define CONSTANTS_HPP_INCLUDED

#include "topology/topology.hpp"

#include "boost/math/constants/constants.hpp"

using namespace std;

namespace msci
{
	constexpr angle_type PI = boost::math::constants::pi<msci::angle_type>();
	const static unsigned long long int avogadro_constant = 602214078000000000000000ull;
}

#endif // CONSTANTS_HPP_INCLUDED
