#ifndef CONSTANTS_HPP_INCLUDED
#define CONSTANTS_HPP_INCLUDED

#include "boost/math/constants/constants.hpp"

using namespace std;

namespace msci
{
	constexpr float PI = boost::math::constants::pi<float>();
	const static float avogadro_constant = 602214078000000000000000.0f;
}

#endif // CONSTANTS_HPP_INCLUDED
