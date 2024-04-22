#ifndef SCIFIR_UNITS_PREDEFINED_UNITS_SPACE_UNITS_HPP_INCLUDED
#define SCIFIR_UNITS_PREDEFINED_UNITS_SPACE_UNITS_HPP_INCLUDED

#include "../units/scalar_unit.hpp"
#include "../units/vector_unit_3d.hpp"
#include "../units/unit_basic.hpp"

using namespace std;

namespace scifir
{
	template<typename T>
	class size_2d;

	template<typename T>
	class size_3d;

	SCALAR_UNIT_HPP_BEGIN(area);
		public:
			explicit area(const size_2d<length>&);

	SCALAR_UNIT_HPP_END();

	SCALAR_UNIT_HPP_BEGIN(volume);
		public:
			explicit volume(const size_3d<length>&);

	SCALAR_UNIT_HPP_END();

	SCALAR_UNIT_HPP(volume_4d);

	SCALAR_UNIT_HPP(curvature);
}

#endif // SCIFIR_UNITS_PREDEFINED_UNITS_SPACE_UNITS_HPP_INCLUDED
