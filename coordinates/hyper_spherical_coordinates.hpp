#ifndef HYPER_SPHERICAL_COORDINATES_HPP_INCLUDED
#define HYPER_SPHERICAL_COORDINATES_HPP_INCLUDED

#include "msci/units/meca_number/angle.hpp"
#include "msci/units/coordinates/coordinates_nd.hpp"
#include "msci/units/coordinates/coordinates_3d.hpp"
#include "msci/units/topology/direction.hpp"

#include "boost/variant.hpp"

#include <list>

using namespace std;

namespace msci
{
	class hyper_spherical_coordinates : public coordinates_nd
	{
		public:
			union directions_union
			{
				vector<msci::angle> angles;
				direction_lr direction;
				directions_union(const vector<msci::angle>& x) : angles(x) {}
				~directions_union() {}
			};

			hyper_spherical_coordinates();
			hyper_spherical_coordinates(float);
			hyper_spherical_coordinates(float, direction_symbol);
			hyper_spherical_coordinates(float, float);
			hyper_spherical_coordinates(float, float, float);
			hyper_spherical_coordinates(float, vector<msci::angle>);
			hyper_spherical_coordinates(float, boost::variant<vector<msci::angle>,direction_symbol>);

			inline float& get_r()
			{
				return r;
			}

			inline const float& get_r() const
			{
				return r;
			}

			inline msci::angle& get_angle1()
			{
				return directions.angles[0];
			}

			inline msci::angle& get_angle2()
			{
				return directions.angles[1];
			}

			const msci::angle& get_angle1() const;
			const msci::angle& get_angle2() const;

			inline msci::angle& get_angle(unsigned int i)
			{
				return directions.angles[i];
			}

			const msci::angle& get_angle(unsigned int) const;

			inline vector<msci::angle>& get_angles()
			{
				return directions.angles;
			}

			const vector<msci::angle>& get_angles() const;

			inline direction_lr& get_direction()
			{
				return directions.direction;
			}

			inline const direction_lr& get_direction() const
			{
				return directions.direction;
			}

			inline hyper_spherical_coordinates::directions_union& get_directions()
			{
				return directions;
			}

			inline bool& get_unidimensional()
			{
				return unidimensional;
			}

			virtual float get_value() const;
			virtual float n_projection(unsigned int) const;
			virtual bool is_nd(unsigned int) const;
			virtual int get_nd() const;

			const bool& is_1d() const;
			bool is_2d() const;
			bool is_3d() const;

			float x_projection() const;
			float y_projection() const;
			float z_projection() const;

			void invert();
			void rotate1(float);
			void rotate2(float);
			void rotate(int, float);

			void convert_cartesian_2d(float, float);
			void convert_polar(float, const msci::angle&);
			void convert_cartesian_3d(float, float, float);
			void convert_cylindrical(float, float, float);

		protected:
			float r;
			directions_union directions;
			bool unidimensional;
	};
}

#endif // HYPER_SPHERICAL_COORDINATES_HPP_INCLUDED
