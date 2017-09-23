#include "hyper_spherical_coordinates.hpp"

#include "math/topology/coordinates/coordinates_2d.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;

namespace math
{
	hyper_spherical_coordinates::hyper_spherical_coordinates() : coordinates_nd(), r(NULL), directions(angle_container()),unidimensional(false)
	{
	}

	hyper_spherical_coordinates::hyper_spherical_coordinates(function<space_type()> new_value) : coordinates_nd(),  directions(angle_container()), unidimensional(false)
	{
		r = new_value;
	}

	hyper_spherical_coordinates::hyper_spherical_coordinates(function<space_type()> new_value, direction_symbol new_direction) : coordinates_nd(), directions(angle_container()), unidimensional(false)
	{
		r = new_value;
		directions.direction = direction_lr(new_direction);
	}

	hyper_spherical_coordinates::hyper_spherical_coordinates(function<space_type()> new_value, angle_type new_angle1) : coordinates_nd(), directions(angle_container()), unidimensional(false)
	{
		r = new_value;
		directions.angles.push_back(math::angle_number(new_angle1));
	}

	hyper_spherical_coordinates::hyper_spherical_coordinates(function<space_type()> new_value, angle_type new_angle1, angle_type new_angle2) : coordinates_nd(), directions(angle_container()), unidimensional(false)
	{
		r = new_value;
		directions.angles.push_back(math::angle_number(new_angle1));
		directions.angles.push_back(math::angle_number(new_angle2));
	}

	hyper_spherical_coordinates::hyper_spherical_coordinates(function<space_type()> new_value, math::angle_container new_angles) : coordinates_nd(), directions(angle_container()), unidimensional(false)
	{
		r = new_value;
		for(auto& new_angle : new_angles)
		{
			directions.angles.push_back(math::angle_number(new_angle));
		}
	}

	hyper_spherical_coordinates::hyper_spherical_coordinates(function<space_type()> new_value, boost::variant<math::angle_container,direction_symbol> new_direction) : coordinates_nd(), directions(angle_container()), unidimensional(false)
	{
		r = new_value;
		if (new_direction.type() == typeid(direction_symbol))
		{
			directions.direction = direction_lr(boost::get<direction_symbol>(new_direction));
			unidimensional = true;
		}
		else
		{
			for(auto& new_angle : boost::get<math::angle_container>(new_direction))
			{
				directions.angles.push_back(math::angle_number(new_angle));
			}
		}
	}

	space_type hyper_spherical_coordinates::get_r() const
	{
		return r();
	}

	const math::angle_number& hyper_spherical_coordinates::get_angle1() const
	{
		if (is_1d())
		{
			throw invalid_argument("Cannot get angle of unidimensional coordinates");
		}
		return directions.angles[0];
	}

	const math::angle_number& hyper_spherical_coordinates::get_angle2() const
	{
		if (is_1d())
		{
			throw invalid_argument("Cannot get angle of unidimensional coordinates");
		}
		return directions.angles[1];
	}

	const math::angle_number& hyper_spherical_coordinates::get_angle(unsigned int i) const
	{
		if (is_1d())
		{
			throw invalid_argument("Cannot get angle of unidimensional coordinates");
		}
		if((i - 1) <= directions.angles.size())
		{
			return directions.angles[i - 1];
		}
		else
		{
			throw invalid_argument("Requested angle doesn't exist");
		}
	}

	const angle_container& hyper_spherical_coordinates::get_angles() const
	{
		if (is_1d())
		{
			throw invalid_argument("Cannot get angle of unidimensional coordinates");
		}
		return directions.angles;
	}

	const direction_symbol& hyper_spherical_coordinates::get_direction() const
	{
		return directions.direction.get_direction();
	}

	space_type hyper_spherical_coordinates::get_value() const
	{
		return r();
	}

	space_type hyper_spherical_coordinates::n_projection(unsigned int i) const
	{
		if(i == 1)
		{
			return x_projection();
		}
		else if(i == 2)
		{
			return y_projection();
		}
		else if(i == 3)
		{
			return z_projection();
		}
		return 0;
	}

	bool hyper_spherical_coordinates::is_nd(unsigned int i) const
	{
		if (i == 1)
		{
			return is_1d();
		}
		else if((i - 1) <= directions.angles.size())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int hyper_spherical_coordinates::get_nd() const
	{
		if (is_1d())
		{
			return 1;
		}
		else
		{
			return (directions.angles.size() + 1);
		}
	}

	const bool& hyper_spherical_coordinates::is_1d() const
	{
		return unidimensional;
	}

	bool hyper_spherical_coordinates::is_2d() const
	{
		if(!unidimensional and directions.angles.size() == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool hyper_spherical_coordinates::is_3d() const
	{
		if(!unidimensional and directions.angles.size() == 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	space_type hyper_spherical_coordinates::x_projection() const
	{
		space_type result;
		if (is_1d())
		{
			if (directions.direction == right)
			{
				result = r();
			}
			else
			{
				result = -r();
			}
		}
		else if(is_2d())
		{
			result = polar_to_cartesian_2d_x(r(),directions.angles[0]);
		}
		else if(is_3d())
		{
			result = spherical_to_cartesian_3d_x(r(),directions.angles[0],directions.angles[1]);
		}
		else
		{
			result = 0;
		}
		if(result == -0)
		{
			return 0;
		}
		else
		{
			return result;
		}
	}

	space_type hyper_spherical_coordinates::y_projection() const
	{
		space_type result;
		if (is_1d())
		{
			throw invalid_argument("unidimensional coordinates doesn't have y projection");
		}
		else if(is_2d())
		{
			result = polar_to_cartesian_2d_y(r(),directions.angles[0]);
		}
		else if(is_3d())
		{
			result = spherical_to_cartesian_3d_y(r(),directions.angles[0],directions.angles[1]);
		}
		else
		{
			result = 0;
		}
		if(result == -0)
		{
			return 0;
		}
		else
		{
			return result;
		}
	}

	space_type hyper_spherical_coordinates::z_projection() const
	{
		space_type result;
		if (is_1d())
		{
			throw invalid_argument("unidimensional coordinates doesn't have z projection");
		}
		else if(is_2d())
		{
			throw invalid_argument("2d coordinates doesn't have a z projection");
		}
		else if(is_3d())
		{
			result = spherical_to_cartesian_3d_z(r(),directions.angles[0],directions.angles[1]);
		}
		else
		{
			result = 0;
		}
		if(result == -0)
		{
			return 0;
		}
		else
		{
			return result;
		}
	}

	void hyper_spherical_coordinates::invert()
	{
		if (is_1d())
		{
			directions.direction.invert();
		}
		else if (is_2d())
		{
			directions.angles[0].invert();
		}
		else if(is_3d())
		{
			directions.angles[0].invert();
			if (directions.angles[1] == 0)
			{
				directions.angles[1] = 180;
			}
			else if(directions.angles[1] < 90)
			{
				directions.angles[1] += 90;
			}
			else if(directions.angles[1] == 90)
			{
				directions.angles[1];
			}
			else if(directions.angles[1] < 180)
			{
				directions.angles[1] -= 90;
			}
			else if(directions.angles[1] == 180)
			{
				directions.angles[1] = 0;
			}
		}
	}

	void hyper_spherical_coordinates::rotate1(angle_type x)
	{
		if(is_1d())
		{
			throw invalid_argument("Cannot rotate unidimensional vector");
		}
		directions.angles[0] += x;
	}

	void hyper_spherical_coordinates::rotate2(angle_type x)
	{
		if(is_1d())
		{
			throw invalid_argument("Cannot rotate unidimensional vector");
		}
		if ((directions.angles[1] + x) <= 180)
		{
			directions.angles[1] += x;
		}
		else if ((directions.angles[1] + x) <= 360)
		{
			directions.angles[1] = 360 - x - directions.angles[1];
			directions.angles[0] += 180;
		}
		else
		{
			math::angle_number y = math::angle_number(x);
			rotate2(x);
		}
	}

	void hyper_spherical_coordinates::rotate(int x,angle_type y)
	{
		if(is_1d())
		{
			throw invalid_argument("Cannot rotate unidimensional vector");
		}
		if (x == 1)
		{
			rotate1(y);
		}
		else if (x == 2)
		{
			rotate2(y);
		}
	}

	void hyper_spherical_coordinates::convert_cartesian_3d(space_type x,space_type y,space_type z)
	{
		if (is_3d())
		{
			//r() = cartesian_3d_to_spherical_r(x,y,z);
			directions.angles[0] = cartesian_3d_to_spherical_angle1(x,y,z);
			directions.angles[1] = cartesian_3d_to_spherical_angle2(x,y,z);
		}
		else
		{
			throw invalid_argument("You can't convert a non-3D vector into a 3D one after initialization");
		}
	}

	void hyper_spherical_coordinates::convert_cylindrical(space_type x,const math::angle_number& y,space_type z)
	{
		if (is_3d())
		{
			//r() = cartesian_3d_to_spherical_r(x,y,z);
			directions.angles[0] = cartesian_3d_to_spherical_angle1(x,y,z);
			directions.angles[1] = cartesian_3d_to_spherical_angle2(x,y,z);
		}
		else
		{
			throw invalid_argument("You can't convert a non-3D vector into a 3D one after initialization");
		}
	}
}
