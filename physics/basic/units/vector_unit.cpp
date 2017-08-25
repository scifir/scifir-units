#include "vector_unit.hpp"
#include "auto_scalar.hpp"
#include "auto_vector.hpp"

using namespace std;

namespace physics::units
{
	vector_unit::vector_unit(const unit& new_value) : unit(new_value), hyper_spherical_coordinates(lambda_value())
	{
	}

	vector_unit::vector_unit(math::space_type new_value,string init_value) : unit(new_value,init_value),hyper_spherical_coordinates(lambda_value(), direction_symbol::left)
	{
	}

	vector_unit::vector_unit(const unit& new_value,string init_value) : unit(new_value,init_value), hyper_spherical_coordinates(lambda_value(), direction_symbol::left)
	{
	}

	vector_unit::vector_unit(const unit& new_value, direction_symbol new_direction) : unit(new_value), hyper_spherical_coordinates(lambda_value(), new_direction)
	{
	}

	vector_unit::vector_unit(const unit& new_value, angle_type new_angle1) : unit(new_value), hyper_spherical_coordinates(lambda_value(), new_angle1)
	{
	}

	vector_unit::vector_unit(const unit& new_value, angle_type new_angle1, angle_type new_angle2) : unit(new_value), hyper_spherical_coordinates(lambda_value(), new_angle1, new_angle2)
	{
	}

	vector_unit::vector_unit(const unit& new_value, math::angle_container new_angles) : unit(new_value), hyper_spherical_coordinates(lambda_value(), new_angles)
	{
	}

	vector_unit::vector_unit(string init_value) : unit(init_value), hyper_spherical_coordinates(lambda_value())
	{
	}

	vector_unit::vector_unit(string init_value, angle_type new_angle1) : unit(init_value), hyper_spherical_coordinates(lambda_value(), new_angle1)
	{
	}

	vector_unit::vector_unit(string init_value, angle_type new_angle1, angle_type new_angle2) : unit(init_value), hyper_spherical_coordinates(lambda_value(), new_angle1, new_angle2)
	{
	}

	vector_unit::vector_unit(string init_value, math::angle_container new_angles) : unit(init_value), hyper_spherical_coordinates(lambda_value(), new_angles)
	{
	}

	vector_unit::vector_unit(const vector_unit& x) : unit(x),hyper_spherical_coordinates(lambda_value(),x.get_angles())
	{
		*this = x;
	}

	void vector_unit::point_to(direction_symbol x)
	{
		if (is_1d())
		{
			if (x == direction_symbol::left)
			{
				directions.direction.go_left();
			}
			else if(x == direction_symbol::right)
			{
				directions.direction.go_right();
			}
		}
		else if (is_2d())
		{
			if (x == direction_symbol::left)
			{
				directions.angles[0] = 180;
			}
			else if(x == direction_symbol::right)
			{
				directions.angles[0] = 0;
			}
			else if(x == top)
			{
				directions.angles[0] = 90;
			}
			else if(x == bottom)
			{
				directions.angles[0] = 270;
			}
			else if(x == left_top)
			{
				directions.angles[0] = 135;
			}
			else if(x == right_top)
			{
				directions.angles[0] = 45;
			}
			else if(x == right_bottom)
			{
				directions.angles[0] = 315;
			}
			else if(x == left_bottom)
			{
				directions.angles[0] = 225;
			}
		}
		else if (is_3d())
		{
			if (x == direction_symbol::left)
			{
				directions.angles[0] = 270;
				directions.angles[1] = 90;
			}
			else if(x == direction_symbol::right)
			{
				directions.angles[0] = 90;
				directions.angles[1] = 90;
			}
			else if(x == top)
			{
				directions.angles[0] = 0;
				directions.angles[1] = 0;
			}
			else if(x == bottom)
			{
				directions.angles[0] = 0;
				directions.angles[1] = 180;
			}
			else if(x == left_top)
			{
				directions.angles[0] = 270;
				directions.angles[1] = 45;
			}
			else if(x == right_top)
			{
				directions.angles[0] = 90;
				directions.angles[1] = 45;
			}
			else if(x == right_bottom)
			{
				directions.angles[0] = 90;
				directions.angles[1] = 135;
			}
			else if(x == left_bottom)
			{
				directions.angles[0] = 270;
				directions.angles[1] = 135;
			}
			else if(x == front)
			{
				directions.angles[0] = 0;
				directions.angles[1] = 90;
			}
			else if(x == back)
			{
				directions.angles[0] = 180;
				directions.angles[1] = 90;
			}
			else if(x == left_front)
			{
				directions.angles[0] = 315;
				directions.angles[1] = 90;
			}
			else if(x == right_front)
			{
				directions.angles[0] = 45;
				directions.angles[1] = 90;
			}
			else if(x == top_front)
			{
				directions.angles[0] = 0;
				directions.angles[1] = 45;
			}
			else if(x == bottom_front)
			{
				directions.angles[0] = 0;
				directions.angles[1] = 135;
			}
			else if(x == left_back)
			{
				directions.angles[0] = 225;
				directions.angles[1] = 90;
			}
			else if(x == right_back)
			{
				directions.angles[0] = 135;
				directions.angles[1] = 90;
			}
			else if(x == top_back)
			{
				directions.angles[0] = 180;
				directions.angles[1] = 45;
			}
			else if(x == bottom_back)
			{
				directions.angles[0] = 180;
				directions.angles[1] = 135;
			}
			else if(x == left_top_front)
			{
				directions.angles[0] = 315;
				directions.angles[1] = 45;
			}
			else if(x == right_top_front)
			{
				directions.angles[0] = 45;
				directions.angles[1] = 45;
			}
			else if(x == left_bottom_front)
			{
				directions.angles[0] = 315;
				directions.angles[1] = 135;
			}
			else if(x == right_bottom_front)
			{
				directions.angles[0] = 45;
				directions.angles[1] = 135;
			}
			else if(x == left_top_back)
			{
				directions.angles[0] = 225;
				directions.angles[1] = 45;
			}
			else if(x == right_top_back)
			{
				directions.angles[0] = 135;
				directions.angles[1] = 45;
			}
			else if(x == left_bottom_back)
			{
				directions.angles[0] = 225;
				directions.angles[1] = 135;
			}
			else if(x == right_bottom_back)
			{
				directions.angles[0] = 135;
				directions.angles[1] = 135;
			}
		}
	}

	void vector_unit::operator =(const vector_unit& x)
	{
		if(x.is_defined())
		{
			if(x.equal_dimensions(get_dimensions_match()))
			{
				unit::value = x.unit::get_value();
				r = lambda_value();
				unit::actual_dimensions = x.get_actual_dimensions();
				if (x.is_1d())
				{
					directions.direction = x.get_direction();
					unidimensional = true;
				}
				else
				{
					directions.angles = x.get_angles();
				}
			}
			else
			{
				unit::invalidate(7);
			}
		}
		else
		{
			unit::invalidate(1);
		}
	}

	auto_vector vector_unit::operator +(const vector_unit& y) const
	{
		auto_vector z = *this;
		z += y;
		return z;
	}

	auto_vector vector_unit::operator -(const vector_unit& y) const
	{
		auto_vector z = *this;
		z -= y;
		return z;
	}

	void vector_unit::operator +=(const vector_unit& y)
	{
		if(equal_dimensions(y.get_real_dimensions()) and unit::is_defined() and y.is_defined())
		{
			if(is_1d())
			{
				if(get_direction() == y.get_direction())
				{
					unit::value += y.unit::get_value();
				}
				else
				{
					unit::value -= y.unit::get_value();
					if(unit::value < 0)
					{
						directions.direction.invert();
						unit::value = math::abs(unit::value);
					}
				}
			}
			else if(is_2d())
			{
				space_type new_x = x_projection() + y.x_projection();
				space_type new_y = y_projection() + y.y_projection();
				unit::value = cartesian_2d_to_polar_r(new_x, new_y);
				directions.angles[0] = cartesian_2d_to_polar_angle(new_x, new_y);
			}
			else if(is_3d())
			{
				space_type new_x = x_projection() + y.x_projection();
				space_type new_y = y_projection() + y.y_projection();
				space_type new_z = z_projection() + y.z_projection();
				unit::value = cartesian_3d_to_spherical_r(new_x, new_y, new_z);
				directions.angles[0] = cartesian_3d_to_spherical_angle1(new_x, new_y, new_z);
				directions.angles[1] = cartesian_3d_to_spherical_angle2(new_x, new_y, new_z);
			}
		}
		else
		{
			unit::invalidate(8);
		}
	}

	void vector_unit::operator -=(const vector_unit& y)
	{
		if(equal_dimensions(y.get_real_dimensions()) and unit::is_defined() and y.is_defined())
		{
			auto_vector z = auto_vector(y);
			z.invert();
			*this += z;
		}
		else
		{
			unit::invalidate(9);
		}
	}

	auto_vector vector_unit::operator *(const scalar_unit& x) const
	{
		space_type new_value = unit::value.get_value() * x.get_value().get_value();
		vector_real_dimensions new_real_dimensions = multiply_real_dimensions(get_real_dimensions(), x.get_real_dimensions());
		vector_actual_dimensions new_actual_dimensions = multiply_actual_dimensions(unit::get_actual_dimensions(), x.get_actual_dimensions());
		auto_unit new_unit = auto_unit(new_value, new_real_dimensions, new_actual_dimensions);
		if(is_1d())
		{
			return auto_vector(new_unit, directions.direction.get_direction());
		}
		else if(is_2d())
		{
			return auto_vector(new_unit, directions.angles[0]);
		}
		else if(is_3d())
		{
			return auto_vector(new_unit, directions.angles[0], directions.angles[1]);
		}
	}

	auto_vector vector_unit::operator /(const scalar_unit& x) const
	{
		space_type new_value = unit::value.get_value() / x.get_value().get_value();
		vector_real_dimensions new_real_dimensions = divide_real_dimensions(get_real_dimensions(), x.get_real_dimensions());
		vector_actual_dimensions new_actual_dimensions = divide_actual_dimensions(unit::get_actual_dimensions(), x.get_actual_dimensions());
		auto_unit new_unit = auto_unit(new_value, new_real_dimensions, new_actual_dimensions);
		if(is_1d())
		{
			return auto_vector(new_unit, directions.direction.get_direction());
		}
		else if(is_2d())
		{
			return auto_vector(new_unit, directions.angles[0]);
		}
		else if(is_3d())
		{
			return auto_vector(new_unit, directions.angles[0], directions.angles[1]);
		}
	}

	auto_vector vector_unit::operator ^(const scalar_unit& x) const
	{
		if(x.empty_dimensions())
		{
			auto_unit new_unit = *this ^ x;
			if(is_1d())
			{
				return auto_vector(new_unit, directions.direction.get_direction());
			}
			else if(is_2d())
			{
				return auto_vector(new_unit, directions.angles[0]);
			}
			else if(is_3d())
			{
				return auto_vector(new_unit, directions.angles[0], directions.angles[1]);
			}
		}
		else
		{
			return auto_vector(0, {});
		}
	}

	auto_vector sqrt(const vector_unit& x)
	{
		auto_unit new_value = physics::units::sqrt(x);
		return auto_vector(new_value, x.get_angles());
	}

	auto_vector sqrt_nth(const vector_unit& x, int y)
	{
		auto_unit new_value = physics::units::sqrt_nth(x, y);
		return auto_vector(new_value, x.get_angles());
	}

	auto_scalar dot_product(const vector_unit& x, const vector_unit& y)
	{
		math::unit_number new_value = x.x_projection()*y.x_projection() + x.y_projection()*y.y_projection() + x.z_projection()*y.z_projection();
		vector_real_dimensions new_real_dimensions = multiply_real_dimensions(x.get_real_dimensions(), y.get_real_dimensions());
		vector_actual_dimensions new_actual_dimensions = multiply_actual_dimensions(x.get_actual_dimensions(), y.get_actual_dimensions());
		return auto_scalar(new_value,new_real_dimensions,new_actual_dimensions);
	}

	auto_vector cross_product(const vector_unit& x,const vector_unit& y)
	{
		if(x.is_defined() and y.is_defined() and x.is_3d() and y.is_3d())
		{
			space_type new_value;
			angle_type angle1;
			angle_type angle2;
			if(y.get_angle(1) == x.get_angle(1) and y.get_angle(2) == x.get_angle(2))
			{
				new_value = 0;
				angle1 = 0;
				angle2 = 0;
			}
			else
			{
				space_type new_x = x.y_projection() * y.z_projection() - x.z_projection() * y.y_projection();
				space_type new_y = x.z_projection() * y.x_projection() - x.x_projection() * y.z_projection();
				space_type new_z = x.x_projection() * y.y_projection() - x.y_projection() * y.x_projection();
				new_value = cartesian_3d_to_spherical_r(new_x, new_y, new_z);
				angle1 = cartesian_3d_to_spherical_angle1(new_x, new_y, new_z);
				angle2 = cartesian_3d_to_spherical_angle2(new_x, new_y, new_z);
			}
			vector_real_dimensions new_real_dimensions = multiply_real_dimensions(x.get_real_dimensions(), y.get_real_dimensions());
			vector_actual_dimensions new_actual_dimensions = multiply_actual_dimensions(x.get_actual_dimensions(), y.get_actual_dimensions());
			auto_unit new_unit = auto_unit(new_value, new_real_dimensions, new_actual_dimensions);
			math::angle_container angles;
			angles.push_back(angle1);
			angles.push_back(angle2);
			return auto_vector(new_unit, angles);
		}
		else
		{
			auto_unit z = auto_unit(0);
			z.invalidate(13);
			return auto_vector(z,direction_symbol::left);
		}
	}

	bool same_spacial_dimensions(const vector_unit& x, const vector_unit& y)
	{
		if(x.get_angles().size() == y.get_angles().size())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool same_direction(const vector_unit& x, const vector_unit& y)
	{
		math::angle_container compare_angles = x.get_angles();
		math::angle_container other_angles = y.get_angles();
		for(int i = 0; i < compare_angles.size(); i++)
		{
			if(compare_angles[i] != other_angles[i])
			{
				return false;
			}
		}
		return true;
	}

	bool parallel(const vector_unit& x, const vector_unit& y)
	{
		math::angle_container compare_angles = x.get_angles();
		math::angle_container other_angles = y.get_angles();
		for(int i = 0; i < compare_angles.size(); i++)
		{
			if(!math::parallel(compare_angles[i], other_angles[i]))
			{
				return false;
			}
		}
		return true;
	}

	bool orthogonal(const vector_unit& x,const vector_unit& y)
	{
		math::angle_container compare_angles = x.get_angles();
		math::angle_container other_angles = y.get_angles();
		for(int i = 0; i < compare_angles.size(); i++)
		{
			if(math::orthogonal(compare_angles[i], other_angles[i]))
			{
				return true;
			}
		}
		return false;
	}
}

bool operator ==(const physics::units::vector_unit& x, const physics::units::vector_unit& y)
{
	if(physics::units::same_spacial_dimensions(x, y))
	{
		if(x.unit::get_value() == y.unit::get_value() and physics::units::same_direction(x, y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		throw invalid_argument("Cannot compare vectors of different dimensions");
	}
}

bool operator !=(const physics::units::vector_unit& x, const physics::units::vector_unit& y)
{
	return !(x == y);
}

void operator +=(wstring& x, const physics::units::vector_unit& y)
{
	wostringstream output;
	output << y;
	x += output.str();
}

wstring operator +(const wstring& x, const physics::units::vector_unit& y)
{
	wostringstream output;
	output << x;
	output << y;
	return output.str();
}

wstring operator +(const physics::units::vector_unit& y, const wstring& x)
{
	wostringstream output;
	output << y;
	output << x;
	return output.str();
}

wostream& operator <<(wostream& os, const physics::units::vector_unit& x)
{
	wostringstream angles_text;
	if (x.is_1d())
	{
		if (x.get_direction() == direction_symbol::left)
		{
			angles_text << "(l)";
		}
		else if (x.get_direction() == direction_symbol::right)
		{
			angles_text << "(r)";
		}
	}
	else
	{
		//wcout << "holaas" << endl; // TODO: this function doesn't work well because L strings block the execution when displayed with angles_text.str()
		int i = 1;
		wstring angle_symbol;
		math::angle_container angles = x.get_angles();
		for(const auto& angle : angles)
		{
			//wcout << "angle" << endl;
			if (i == 1)
			{
				//angle_symbol = L"θ";
				os << L"θ";
			}
			else if (i == 2)
			{
				//angle_symbol == L"φ";
				os << L"φ";
			}
			//wcout << "angle: " << angle << endl;
			//wcout << angle_symbol << endl;
			//angles_text << angle << L"θ" << L" ";
			i++;
		}
	}
	//wcout << "A" << endl;
	//wcout << angles_text.str() << endl;
	return os << x.physics::units::unit::get_value();// << " " << angles_text.str();
}

istream& operator >>(istream& is, physics::units::vector_unit& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	physics::units::auto_vector c(b);
	x = c;
	return is;
}
