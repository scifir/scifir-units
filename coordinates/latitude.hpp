#ifndef SCIFIR_UNITS_COORDINATES_LATITUDE_HPP_INCLUDED
#define SCIFIR_UNITS_COORDINATES_LATITUDE_HPP_INCLUDED

#include "../units/constants.hpp"
#include "../util/is_number.hpp"
#include "../units/scalar_unit.hpp"
#include "./../meca_number/angle.hpp"

#include <cmath>
#include <string>

using namespace std;

namespace scifir
{
	class latitude : public angle
	{
		public:
			enum position : int8_t {NORTH, SOUTH, CENTER};

			latitude();
			latitude(const latitude& x);
			latitude(latitude&& x);
			explicit latitude(float new_value);
			explicit latitude(double new_value);
			explicit latitude(long double new_value);
			explicit latitude(int new_value);
			explicit latitude(const string& init_latitude);
			explicit latitude(const scalar_unit& x);

			latitude& operator =(const latitude& x);
			latitude& operator =(latitude&& x);
			latitude& operator =(float new_value);
			latitude& operator =(const string& init_latitude);
			latitude& operator =(const scalar_unit& x);

			latitude::position get_position() const;

			void invert();

		private:
			void normalize_value();
			void initialize_from_angle(const angle& x);
			void initialize_from_string(string init_latitude);
	};
}

#endif // SCIFIR_UNITS_COORDINATES_LATITUDE_HPP_INCLUDED
