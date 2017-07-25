#ifndef CONSTANTS_HPP_INCLUDED
#define CONSTANTS_HPP_INCLUDED

#include "math/topology/topology.hpp"

#include "boost/math/constants/constants.hpp"

using namespace std;
using namespace math::topology;

namespace math
{
	constexpr topology::angle_type PI = boost::math::constants::pi<math::topology::angle_type>();
}

#endif // CONSTANTS_HPP_INCLUDED
