#include "msci/units/units/vector_unit_3d.hpp"

using namespace std;

namespace msci
{
	vector_unit_3d::vector_unit_3d() : scalar_unit(),coord()
	{
	}

	vector_unit_3d::vector_unit_3d(const vector_unit_3d& x) : scalar_unit(x),coord(x.get_value(),x.get_angles())
	{
		operator=(x);
	}

	vector_unit_3d::vector_unit_3d(vector_unit_3d&& x) : scalar_unit(move(x)),coord(x.get_value(),move(x.get_angles()))
	{
		operator=(move(x));
	}

	vector_unit_3d::vector_unit_3d(float new_value,const string& init_value) : scalar_unit(new_value,init_value),coord(new_value, direction_symbol::left)
	{
	}

	vector_unit_3d::vector_unit_3d(const scalar_unit& new_value, direction_symbol new_direction) : scalar_unit(new_value), coord(new_value.get_value(), new_direction)
	{
	}

	vector_unit_3d::vector_unit_3d(const scalar_unit& new_value, float new_angle1) : scalar_unit(new_value), coord(new_value.get_value(), new_angle1)
	{
	}

	vector_unit_3d::vector_unit_3d(const scalar_unit& new_value, float new_angle1, float new_angle2) : scalar_unit(new_value), coord(new_value.get_value(), new_angle1, new_angle2)
	{
	}

	vector_unit_3d::vector_unit_3d(const scalar_unit& new_value, msci::angle_container new_angles) : scalar_unit(new_value), coord(new_value.get_value(), new_angles)
	{
	}

	vector_unit_3d::vector_unit_3d(scalar_unit&& new_value, direction_symbol new_direction) : scalar_unit(move(new_value)), coord(new_value.get_value(), new_direction)
	{
	}

	vector_unit_3d::vector_unit_3d(scalar_unit&& new_value, float new_angle1) : scalar_unit(move(new_value)), coord(new_value.get_value(), new_angle1)
	{
	}

	vector_unit_3d::vector_unit_3d(scalar_unit&& new_value, float new_angle1, float new_angle2) : scalar_unit(move(new_value)), coord(new_value.get_value(), new_angle1, new_angle2)
	{
	}

	vector_unit_3d::vector_unit_3d(scalar_unit&& new_value, msci::angle_container new_angles) : scalar_unit(move(new_value)), coord(new_value.get_value(), new_angles)
	{
	}

	vector_unit_3d::vector_unit_3d(const scalar_unit& new_value, direction_symbol new_direction, const string& init_value) : scalar_unit(new_value,init_value), coord(new_value.get_value(), new_direction)
	{
	}

	vector_unit_3d::vector_unit_3d(const scalar_unit& new_value, float new_angle1, const string& init_value) : scalar_unit(new_value,init_value), coord(new_value.get_value(), new_angle1)
	{
	}

	vector_unit_3d::vector_unit_3d(const scalar_unit& new_value, float new_angle1, float new_angle2, const string& init_value) : scalar_unit(new_value,init_value), coord(new_value.get_value(), new_angle1, new_angle2)
	{
	}

	vector_unit_3d::vector_unit_3d(const scalar_unit& new_value, msci::angle_container new_angles, const string& init_value) : scalar_unit(new_value,init_value), coord(new_value.get_value(), new_angles)
	{
	}

	vector_unit_3d::vector_unit_3d(scalar_unit&& new_value, direction_symbol new_direction, const string& init_value) : scalar_unit(move(new_value),init_value), coord(new_value.get_value(), new_direction)
	{
	}

	vector_unit_3d::vector_unit_3d(scalar_unit&& new_value, float new_angle1, const string& init_value) : scalar_unit(move(new_value),init_value), coord(new_value.get_value(), new_angle1)
	{
	}

	vector_unit_3d::vector_unit_3d(scalar_unit&& new_value, float new_angle1, float new_angle2, const string& init_value) : scalar_unit(move(new_value),init_value), coord(new_value.get_value(), new_angle1, new_angle2)
	{
	}

	vector_unit_3d::vector_unit_3d(scalar_unit&& new_value, msci::angle_container new_angles, const string& init_value) : scalar_unit(move(new_value),init_value), coord(new_value.get_value(), new_angles)
	{
	}

	vector_unit_3d::vector_unit_3d(const string& init_value, direction_symbol new_direction) : scalar_unit(init_value), coord(0.0f, new_direction)
	{
	}

	vector_unit_3d::vector_unit_3d(const string& init_value, float new_angle1) : scalar_unit(init_value), coord(0.0f, new_angle1)
	{
	}

	vector_unit_3d::vector_unit_3d(const string& init_value, float new_angle1, float new_angle2) : scalar_unit(init_value), coord(0.0f, new_angle1, new_angle2)
	{
	}

	vector_unit_3d::vector_unit_3d(const string& init_value, msci::angle_container new_angles) : scalar_unit(init_value), coord(0.0f, new_angles)
	{
	}

	vector_unit_3d& vector_unit_3d::operator =(const vector_unit_3d& x)
	{
		if (same_nd(*this,x))
		{
			scalar_unit::operator=(x);
			coord.get_r() = x.get_value();
			if (x.is_1d())
			{
				coord.get_direction() = x.get_direction();
				coord.get_unidimensional() = true;
			}
			else
			{
				coord.get_angles() = x.get_angles();
			}
		}
		else
		{
			invalidate(11);
		}
		return *this;
	}

	vector_unit_3d& vector_unit_3d::operator =(vector_unit_3d&& x)
	{
		if (same_nd(*this,x))
		{
			scalar_unit::operator=(move(x));
			coord.get_r() = x.get_value();
			if (x.is_1d())
			{
				coord.get_direction() = move(x.get_direction());
				coord.get_unidimensional() = true;
			}
			else
			{
				coord.get_angles() = move(x.get_angles());
			}
		}
		else
		{
			invalidate(11);
		}
		return *this;
	}

	vector_unit_3d& vector_unit_3d::operator =(const scalar_unit& x)
	{
		scalar_unit::operator=(x);
		return *this;
	}

	vector_unit_3d& vector_unit_3d::operator =(scalar_unit&& x)
	{
		scalar_unit::operator=(move(x));
		return *this;
	}

	void vector_unit_3d::point_to(direction_symbol x)
	{
		if (is_1d())
		{
			if (x == direction_symbol::left)
			{
				coord.get_direction().go_left();
			}
			else if(x == direction_symbol::right)
			{
				coord.get_direction().go_right();
			}
		}
		else if (is_2d())
		{
			if (x == direction_symbol::left)
			{
				coord.get_angle1() = 180;
			}
			else if(x == direction_symbol::right)
			{
				coord.get_angle1() = 0;
			}
			else if(x == top)
			{
				coord.get_angle1() = 90;
			}
			else if(x == bottom)
			{
				coord.get_angle1() = 270;
			}
			else if(x == left_top)
			{
				coord.get_angle1() = 135;
			}
			else if(x == right_top)
			{
				coord.get_angle1() = 45;
			}
			else if(x == right_bottom)
			{
				coord.get_angle1() = 315;
			}
			else if(x == left_bottom)
			{
				coord.get_angle1() = 225;
			}
		}
		else if (is_3d())
		{
			if (x == direction_symbol::left)
			{
				coord.get_angle1() = 270;
				coord.get_angle2() = 90;
			}
			else if(x == direction_symbol::right)
			{
				coord.get_angle1() = 90;
				coord.get_angle2() = 90;
			}
			else if(x == top)
			{
				coord.get_angle1() = 0;
				coord.get_angle2() = 0;
			}
			else if(x == bottom)
			{
				coord.get_angle1() = 0;
				coord.get_angle2() = 180;
			}
			else if(x == left_top)
			{
				coord.get_angle1() = 270;
				coord.get_angle2() = 45;
			}
			else if(x == right_top)
			{
				coord.get_angle1() = 90;
				coord.get_angle2() = 45;
			}
			else if(x == right_bottom)
			{
				coord.get_angle1() = 90;
				coord.get_angle2() = 135;
			}
			else if(x == left_bottom)
			{
				coord.get_angle1() = 270;
				coord.get_angle2() = 135;
			}
			else if(x == front)
			{
				coord.get_angle1() = 0;
				coord.get_angle2() = 90;
			}
			else if(x == back)
			{
				coord.get_angle1() = 180;
				coord.get_angle2() = 90;
			}
			else if(x == left_front)
			{
				coord.get_angle1() = 315;
				coord.get_angle2() = 90;
			}
			else if(x == right_front)
			{
				coord.get_angle1() = 45;
				coord.get_angle2() = 90;
			}
			else if(x == top_front)
			{
				coord.get_angle1() = 0;
				coord.get_angle2() = 45;
			}
			else if(x == bottom_front)
			{
				coord.get_angle1() = 0;
				coord.get_angle2() = 135;
			}
			else if(x == left_back)
			{
				coord.get_angle1() = 225;
				coord.get_angle2() = 90;
			}
			else if(x == right_back)
			{
				coord.get_angle1() = 135;
				coord.get_angle2() = 90;
			}
			else if(x == top_back)
			{
				coord.get_angle1() = 180;
				coord.get_angle2() = 45;
			}
			else if(x == bottom_back)
			{
				coord.get_angle1() = 180;
				coord.get_angle2() = 135;
			}
			else if(x == left_top_front)
			{
				coord.get_angle1() = 315;
				coord.get_angle2() = 45;
			}
			else if(x == right_top_front)
			{
				coord.get_angle1() = 45;
				coord.get_angle2() = 45;
			}
			else if(x == left_bottom_front)
			{
				coord.get_angle1() = 315;
				coord.get_angle2() = 135;
			}
			else if(x == right_bottom_front)
			{
				coord.get_angle1() = 45;
				coord.get_angle2() = 135;
			}
			else if(x == left_top_back)
			{
				coord.get_angle1() = 225;
				coord.get_angle2() = 45;
			}
			else if(x == right_top_back)
			{
				coord.get_angle1() = 135;
				coord.get_angle2() = 45;
			}
			else if(x == left_bottom_back)
			{
				coord.get_angle1() = 225;
				coord.get_angle2() = 135;
			}
			else if(x == right_bottom_back)
			{
				coord.get_angle1() = 135;
				coord.get_angle2() = 135;
			}
		}
	}

	vector_unit_3d vector_unit_3d::operator +(const vector_unit_3d& y) const
	{
		vector_unit_3d z = *this;
		z += y;
		return z;
	}

	vector_unit_3d vector_unit_3d::operator -(const vector_unit_3d& y) const
	{
		vector_unit_3d z = *this;
		z -= y;
		return z;
	}

	void vector_unit_3d::operator +=(const vector_unit_3d& y)
	{
		if(has_dimensions(y.get_derived_dimensions()) and scalar_unit::is_defined() and y.is_defined())
		{
			if(is_1d())
			{
				if(get_direction() == y.get_direction())
				{
					scalar_unit::value += y.get_value();
				}
				else
				{
					scalar_unit::value -= y.get_value();
					if(scalar_unit::value < 0)
					{
						coord.invert();
						scalar_unit::value = msci::abs(scalar_unit::value);
					}
				}
			}
			else if(is_2d())
			{
				float new_x = x_projection() + y.x_projection();
				float new_y = y_projection() + y.y_projection();
				scalar_unit::value = cartesian_2d_to_polar_r(new_x, new_y);
				coord.get_angle1() = cartesian_2d_to_polar_angle(new_x, new_y);
			}
			else if(is_3d())
			{
				float new_x = x_projection() + y.x_projection();
				float new_y = y_projection() + y.y_projection();
				float new_z = z_projection() + y.z_projection();
				scalar_unit::value = cartesian_3d_to_spherical_r(new_x, new_y, new_z);
				coord.get_angle1() = cartesian_3d_to_spherical_angle1(new_x, new_y, new_z);
				coord.get_angle2() = cartesian_3d_to_spherical_angle2(new_x, new_y, new_z);
			}
		}
		else
		{
			scalar_unit::invalidate(8);
		}
	}

	void vector_unit_3d::operator -=(const vector_unit_3d& y)
	{
		if(has_dimensions(y.get_derived_dimensions()) and scalar_unit::is_defined() and y.is_defined())
		{
			vector_unit_3d z = vector_unit_3d(y);
			z.invert();
			*this += z;
		}
		else
		{
			scalar_unit::invalidate(9);
		}
	}

	vector_unit_3d vector_unit_3d::operator *(const scalar_unit& x) const
	{
		float new_value = scalar_unit::value.get_value() * x.get_value().get_value();
		vector<dimension> new_dimensions = multiply_dimensions(get_dimensions(), x.get_dimensions());
		scalar_unit new_unit = scalar_unit(new_value, new_dimensions);
		if(is_1d())
		{
			return vector_unit_3d(new_unit, coord.get_direction().get_direction());
		}
		else if(is_2d())
		{
			return vector_unit_3d(new_unit, coord.get_angle1());
		}
		else if(is_3d())
		{
			return vector_unit_3d(new_unit, coord.get_angle1(), coord.get_angle2());
		}
		else
		{
			return vector_unit_3d(new_unit, coord.get_angles());
		}
	}

	vector_unit_3d vector_unit_3d::operator /(const scalar_unit& x) const
	{
		float new_value = scalar_unit::value.get_value() / x.get_value().get_value();
		vector<dimension> new_dimensions = divide_dimensions(get_dimensions(), x.get_dimensions());
		scalar_unit new_unit = scalar_unit(new_value, new_dimensions);
		if(is_1d())
		{
			return vector_unit_3d(new_unit, coord.get_direction().get_direction());
		}
		else if(is_2d())
		{
			return vector_unit_3d(new_unit, coord.get_angle1());
		}
		else if(is_3d())
		{
			return vector_unit_3d(new_unit, coord.get_angle1(), coord.get_angle2());
		}
		else
		{
			return vector_unit_3d(new_unit, coord.get_angles());
		}
	}

	vector_unit_3d vector_unit_3d::operator ^(const scalar_unit& x) const
	{
		if(x.has_empty_dimensions())
		{
			scalar_unit new_unit = *this ^ x;
			if(is_1d())
			{
				return vector_unit_3d(new_unit, coord.get_direction().get_direction());
			}
			else if(is_2d())
			{
				return vector_unit_3d(new_unit, coord.get_angle1());
			}
			else if(is_3d())
			{
				return vector_unit_3d(new_unit, coord.get_angle1(), coord.get_angle2());
			}
		}
		return vector_unit_3d("0 m", direction_symbol::left);
	}

	scalar_unit norm(const vector_unit_3d& x)
	{
		return scalar_unit(x.get_value(),x.get_dimensions());
	}

	vector_unit_3d sqrt(const vector_unit_3d& x)
	{
		scalar_unit new_value = msci::sqrt(x);
		return vector_unit_3d(new_value, x.get_angles());
	}

	vector_unit_3d sqrt_nth(const vector_unit_3d& x, int y)
	{
		scalar_unit new_value = msci::sqrt_nth(x, y);
		return vector_unit_3d(new_value, x.get_angles());
	}

	scalar_unit dot_product(const vector_unit_3d& x, const vector_unit_3d& y)
	{
		msci::unit_number new_value = x.x_projection()*y.x_projection() + x.y_projection()*y.y_projection() + x.z_projection()*y.z_projection();
		vector<dimension> new_dimensions = multiply_dimensions(x.get_dimensions(), y.get_dimensions());
		return scalar_unit(new_value,new_dimensions);
	}

	vector_unit_3d cross_product(const vector_unit_3d& x,const vector_unit_3d& y)
	{
		if(x.is_defined() and y.is_defined() and x.is_3d() and y.is_3d())
		{
			float new_value;
			float angle1;
			float angle2;
			if(y.get_angle(1) == x.get_angle(1) and y.get_angle(2) == x.get_angle(2))
			{
				new_value = 0;
				angle1 = 0;
				angle2 = 0;
			}
			else
			{
				float new_x = x.y_projection() * y.z_projection() - x.z_projection() * y.y_projection();
				float new_y = x.z_projection() * y.x_projection() - x.x_projection() * y.z_projection();
				float new_z = x.x_projection() * y.y_projection() - x.y_projection() * y.x_projection();
				new_value = cartesian_3d_to_spherical_r(new_x, new_y, new_z);
				angle1 = cartesian_3d_to_spherical_angle1(new_x, new_y, new_z);
				angle2 = cartesian_3d_to_spherical_angle2(new_x, new_y, new_z);
			}
			vector<dimension> new_dimensions = multiply_dimensions(x.get_dimensions(), y.get_dimensions());
			scalar_unit new_unit = scalar_unit(new_value, new_dimensions);
			msci::angle_container angles;
			angles.push_back(angle1);
			angles.push_back(angle2);
			return vector_unit_3d(new_unit, angles);
		}
		else
		{
			scalar_unit z = scalar_unit();
			z.invalidate(13);
			return vector_unit_3d(z,direction_symbol::left);
		}
	}

	msci::angle angle_between_vectors(const vector_unit_3d& x,const vector_unit_3d& y)
	{
		return msci::acos(float(dot_product(x,y)/(norm(x)*norm(y))));
	}

	bool same_nd(const vector_unit_3d& x, const vector_unit_3d& y)
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

	bool same_direction(const vector_unit_3d& x, const vector_unit_3d& y)
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

	bool parallel(const vector_unit_3d& x, const vector_unit_3d& y)
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

	bool orthogonal(const vector_unit_3d& x,const vector_unit_3d& y)
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

bool operator ==(const msci::vector_unit_3d& x, const msci::vector_unit_3d& y)
{
	if(msci::same_nd(x, y))
	{
		if(x.get_value() == y.get_value() and msci::same_direction(x, y))
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
		return false;
	}
}

bool operator !=(const msci::vector_unit_3d& x, const msci::vector_unit_3d& y)
{
	return !(x == y);
}

void operator +=(string& x, const msci::vector_unit_3d& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const msci::vector_unit_3d& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const msci::vector_unit_3d& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const msci::vector_unit_3d& x)
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
	return os << x.get_value() << " " << x.display_dimensions() << " " << angles_text.str();
}

istream& operator >>(istream& is, msci::vector_unit_3d& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::vector_unit_3d c(b,10,10);
	x = c;
	return is;
}
