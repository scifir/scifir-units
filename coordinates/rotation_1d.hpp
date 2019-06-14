#ifndef MSCI_UNITS_COORDINATES_ROTATION_1D_HPP_INCLUDED
#define MSCI_UNITS_COORDINATES_ROTATION_1D_HPP_INCLUDED

#include "msci/units/meca_number/angle_number.hpp"
#include "msci/units/coordinates/light/cartesian_2d.hpp"

namespace msci
{
	class rotation_1d
	{
		public:
			rotation_1d();

			inline angle_number& get_angle()
			{
				return x_angle;
			}

			inline const angle_number& get_angle() const
			{
				return x_angle;
			}

			void move_angle(const angle_number&);

		private:
			angle_number x_angle;
	};

	string complete_display(const msci::cartesian_2d&,const msci::rotation_1d&);
}

bool operator == (const msci::rotation_1d&,const msci::rotation_1d&);
bool operator != (const msci::rotation_1d&,const msci::rotation_1d&);

#endif // MSCI_UNITS_COORDINATES_ROTATION_1D_HPP_INCLUDED
