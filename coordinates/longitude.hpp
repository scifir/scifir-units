#ifndef SCIFIR_UNITS_COORDINATES_LONGITUDE_HPP_INCLUDED
#define SCIFIR_UNITS_COORDINATES_LONGITUDE_HPP_INCLUDED

#include "../units/constants.hpp"
#include "../util/is_number.hpp"
#include "../units/scalar_unit.hpp"
#include "./../meca_number/angle.hpp"

#include <cmath>
#include <string>

using namespace std;

namespace scifir
{
	class longitude : public angle
	{
		public:
			enum position : int8_t {EAST, WEST, CENTER};

			longitude();
			longitude(const longitude& x);
			longitude(longitude&& x);
			explicit longitude(float new_value);
			explicit longitude(double new_value);
			explicit longitude(long double new_value);
			explicit longitude(int new_value);
			explicit longitude(const string& init_longitude);
			explicit longitude(const scalar_unit& x);
			explicit longitude(const angle& x);

			longitude& operator =(const longitude& x);
			longitude& operator =(longitude&& x);
			longitude& operator =(float new_value);
			longitude& operator =(const string& init_longitude);
			longitude& operator =(const scalar_unit& x);

			longitude::position get_position() const;

			void invert();

		private:
			void normalize_value();
			void initialize_from_angle(const angle& x);
			void initialize_from_string(string init_longitude);
	};
}

#endif // SCIFIR_UNITS_COORDINATES_LONGITUDE_HPP_INCLUDED
