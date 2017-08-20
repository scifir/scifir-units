#ifndef CONSTANTS_HPP_INCLUDED
#define CONSTANTS_HPP_INCLUDED

#include "math/topology/topology.hpp"

#include "boost/math/constants/constants.hpp"

using namespace std;

namespace math
{
	constexpr angle_type PI = boost::math::constants::pi<math::angle_type>();
}

#endif // CONSTANTS_HPP_INCLUDED
