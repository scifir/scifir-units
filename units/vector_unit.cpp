#include "vector_unit.hpp"
#include "auto_scalar.hpp"
#include "auto_vector.hpp"

using namespace std;

namespace msci
{
	vector_unit::vector_unit() : unit(),hyper_spherical_coordinates()
	{
	}

	vector_unit::vector_unit(const vector_unit& x) : unit(x),hyper_spherical_coordinates(lambda_value(),x.get_angles())
	{
		operator=(x);
	}

	vector_unit::vector_unit(vector_unit&& x) : unit(move(x)),hyper_spherical_coordinates(lambda_value(),move(x.get_angles()))
	{
		operator=(move(x));
	}

	vector_unit::vector_unit(msci::space_type new_value,const string& init_value) : unit(new_value,init_value),hyper_spherical_coordinates(lambda_value(), direction_symbol::left)
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

	vector_unit::vector_unit(const unit& new_value, msci::angle_container new_angles) : unit(new_value), hyper_spherical_coordinates(lambda_value(), new_angles)
	{
	}

	vector_unit::vector_unit(unit&& new_value, direction_symbol new_direction) : unit(move(new_value)), hyper_spherical_coordinates(lambda_value(), new_direction)
	{
	}

	vector_unit::vector_unit(unit&& new_value, angle_type new_angle1) : unit(move(new_value)), hyper_spherical_coordinates(lambda_value(), new_angle1)
	{
	}

	vector_unit::vector_unit(unit&& new_value, angle_type new_angle1, angle_type new_angle2) : unit(move(new_value)), hyper_spherical_coordinates(lambda_value(), new_angle1, new_angle2)
	{
	}

	vector_unit::vector_unit(unit&& new_value, msci::angle_container new_angles) : unit(move(new_value)), hyper_spherical_coordinates(lambda_value(), new_angles)
	{
	}

	vector_unit::vector_unit(const unit& new_value, direction_symbol new_direction, const string& init_value) : unit(new_value,init_value), hyper_spherical_coordinates(lambda_value(), new_direction)
	{
	}

	vector_unit::vector_unit(const unit& new_value, angle_type new_angle1, const string& init_value) : unit(new_value,init_value), hyper_spherical_coordinates(lambda_value(), new_angle1)
	{
	}

	vector_unit::vector_unit(const unit& new_value, angle_type new_angle1, angle_type new_angle2, const string& init_value) : unit(new_value,init_value), hyper_spherical_coordinates(lambda_value(), new_angle1, new_angle2)
	{
	}

	vector_unit::vector_unit(const unit& new_value, msci::angle_container new_angles, const string& init_value) : unit(new_value,init_value), hyper_spherical_coordinates(lambda_value(), new_angles)
	{
	}

	vector_unit::vector_unit(unit&& new_value, direction_symbol new_direction, const string& init_value) : unit(move(new_value),init_value), hyper_spherical_coordinates(lambda_value(), new_direction)
	{
	}

	vector_unit::vector_unit(unit&& new_value, angle_type new_angle1, const string& init_value) : unit(move(new_value),init_value), hyper_spherical_coordinates(lambda_value(), new_angle1)
	{
	}

	vector_unit::vector_unit(unit&& new_value, angle_type new_angle1, angle_type new_angle2, const string& init_value) : unit(move(new_value),init_value), hyper_spherical_coordinates(lambda_value(), new_angle1, new_angle2)
	{
	}

	vector_unit::vector_unit(unit&& new_value, msci::angle_container new_angles, const string& init_value) : unit(move(new_value),init_value), hyper_spherical_coordinates(lambda_value(), new_angles)
	{
	}

	vector_unit::vector_unit(const string& init_value, direction_symbol new_direction) : unit(init_value), hyper_spherical_coordinates(lambda_value(), new_direction)
	{
	}

	vector_unit::vector_unit(const string& init_value, angle_type new_angle1) : unit(init_value), hyper_spherical_coordinates(lambda_value(), new_angle1)
	{
	}

	vector_unit::vector_unit(const string& init_value, angle_type new_angle1, angle_type new_angle2) : unit(init_value), hyper_spherical_coordinates(lambda_value(), new_angle1, new_angle2)
	{
	}

	vector_unit::vector_unit(const string& init_value, msci::angle_container new_angles) : unit(init_value), hyper_spherical_coordinates(lambda_value(), new_angles)
	{
	}

	vector_unit& vector_unit::operator =(const vector_unit& x)
	{
		if (same_nd(*this,x))
		{
			unit::operator=(x);
			r = lambda_value();
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
			invalidate(11);
		}
		return *this;
	}

	vector_unit& vector_unit::operator =(vector_unit&& x)
	{
		if (same_nd(*this,x))
		{
			unit::operator=(move(x));
			r = lambda_value();
			if (x.is_1d())
			{
				directions.direction = move(x.get_direction());
				unidimensional = true;
			}
			else
			{
				directions.angles = move(x.get_angles());
			}
		}
		else
		{
			invalidate(11);
		}
		return *this;
	}

	vector_unit& vector_unit::operator =(const unit& x)
	{
		unit::operator=(x);
		return *this;
	}

	vector_unit& vector_unit::operator =(unit&& x)
	{
		unit::operator=(move(x));
		return *this;
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
		if(has_dimensions(y.get_real_dimensions()) and unit::is_defined() and y.is_defined())
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
						unit::value = msci::abs(unit::value);
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
		if(has_dimensions(y.get_real_dimensions()) and unit::is_defined() and y.is_defined())
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
		else
		{
			return auto_vector(new_unit, directions.angles);
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
		else
		{
			return auto_vector(new_unit, directions.angles);
		}
	}

	auto_vector vector_unit::operator ^(const scalar_unit& x) const
	{
		if(x.has_empty_dimensions())
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
		return auto_vector("0 m", direction_symbol::left);
	}

	auto_scalar norm(const vector_unit& x)
	{
		return auto_scalar(x.unit::get_value(),x.get_real_dimensions(),x.get_actual_dimensions());
	}

	auto_vector sqrt(const vector_unit& x)
	{
		auto_unit new_value = msci::sqrt(x);
		return auto_vector(new_value, x.get_angles());
	}

	auto_vector sqrt_nth(const vector_unit& x, int y)
	{
		auto_unit new_value = msci::sqrt_nth(x, y);
		return auto_vector(new_value, x.get_angles());
	}

	auto_scalar dot_product(const vector_unit& x, const vector_unit& y)
	{
		msci::unit_number new_value = x.x_projection()*y.x_projection() + x.y_projection()*y.y_projection() + x.z_projection()*y.z_projection();
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
			msci::angle_container angles;
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

	msci::angle_number angle_between_vectors(const vector_unit& x,const vector_unit& y)
	{
		return msci::acos(float(dot_product(x,y)/(norm(x)*norm(y))));
	}

	bool same_nd(const vector_unit& x, const vector_unit& y)
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
		msci::angle_container compare_angles = x.get_angles();
		msci::angle_container other_angles = y.get_angles();
		for(unsigned int i = 0; i < compare_angles.size(); i++)
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
		msci::angle_container compare_angles = x.get_angles();
		msci::angle_container other_angles = y.get_angles();
		for(unsigned int i = 0; i < compare_angles.size(); i++)
		{
			if(!msci::parallel(compare_angles[i], other_angles[i]))
			{
				return false;
			}
		}
		return true;
	}

	bool orthogonal(const vector_unit& x,const vector_unit& y)
	{
		msci::angle_container compare_angles = x.get_angles();
		msci::angle_container other_angles = y.get_angles();
		for(unsigned int i = 0; i < compare_angles.size(); i++)
		{
			if(msci::orthogonal(compare_angles[i], other_angles[i]))
			{
				return true;
			}
		}
		return false;
	}
}

bool operator ==(const msci::vector_unit& x, const msci::vector_unit& y)
{
	if(msci::same_nd(x, y))
	{
		if(x.unit::get_value() == y.unit::get_value() and msci::same_direction(x, y))
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

bool operator !=(const msci::vector_unit& x, const msci::vector_unit& y)
{
	return !(x == y);
}

void operator +=(string& x, const msci::vector_unit& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const msci::vector_unit& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const msci::vector_unit& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const msci::vector_unit& x)
{
	ostringstream angles_text;
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
		int i = 1;
		string angle_symbol;
		msci::angle_container angles = x.get_angles();
		for(const auto& angle : angles)
		{
			angles_text << angle;
			if (i == 1)
			{
				angles_text << "\u03B8";
				angles_text << " ";
			}
			else if (i == 2)
			{
				angles_text << "\u03A6";
			}
			i++;
		}
	}
	return os << x.msci::unit::get_value() << " " << x.msci::unit::display_dimensions() << " " << angles_text.str();
}

istream& operator >>(istream& is, msci::vector_unit& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::auto_vector c(b,10,10);
	x = c;
	return is;
}
