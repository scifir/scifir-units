#include "msci/units/units/vector_unit_nd.hpp"
#include "msci/units/coordinates/coordinates_3d.hpp"

using namespace std;

namespace msci
{
	vector_unit_nd::vector_unit_nd() : scalar_unit(),angles()
	{}
	
	vector_unit_nd::vector_unit_nd(const vector_unit_nd& x) : scalar_unit(x),angles(x.angles)
	{}
	
	vector_unit_nd::vector_unit_nd(vector_unit_nd&& x) : scalar_unit(move(x)),angles(move(x.angles))
	{}
	
	vector_unit_nd::vector_unit_nd(float new_value,const string& init_dimensions) : scalar_unit(new_value,init_dimensions),angles()
	{}
	
	vector_unit_nd::vector_unit_nd(float new_value,const string& init_dimensions,const vector<float>& new_angles) : scalar_unit(new_value,init_dimensions),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(msci::angle(x_angle));
		}
	}
	
	vector_unit_nd::vector_unit_nd(float new_value,const string& init_dimensions,const vector<msci::angle>& new_angles) : scalar_unit(new_value,init_dimensions),angles(new_angles)
	{}
	
	vector_unit_nd::vector_unit_nd(float new_value,const vector<dimension>& new_dimensions) : scalar_unit(new_value,new_dimensions),angles()
	{}
	
	vector_unit_nd::vector_unit_nd(float new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles) : scalar_unit(new_value,new_dimensions),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(msci::angle(x_angle));
		}
	}
	
	vector_unit_nd::vector_unit_nd(float new_value,const vector<dimension>& new_dimensions,const vector<msci::angle>& new_angles) : scalar_unit(new_value,new_dimensions),angles(new_angles)
	{}
	
	vector_unit_nd::vector_unit_nd(const scalar_unit& x) : scalar_unit(x),angles()
	{}
	
	vector_unit_nd::vector_unit_nd(const scalar_unit& x,const vector<float>& new_angles)
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(msci::angle(x_angle));
		}
	}
	
	vector_unit_nd::vector_unit_nd(const scalar_unit& x,const vector<msci::angle>& new_angles) : scalar_unit(x),angles(new_angles)
	{}
	
	vector_unit_nd::vector_unit_nd(scalar_unit&& x)
	{}
	
	vector_unit_nd::vector_unit_nd(scalar_unit&& x,const vector<float>& new_angles) : scalar_unit(x),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(msci::angle(x_angle));
		}
	}
	
	vector_unit_nd::vector_unit_nd(scalar_unit&& x,const vector<msci::angle>& new_angles) : scalar_unit(x),angles(new_angles)
	{}
	
	vector_unit_nd::vector_unit_nd(const string& init_scalar,const vector<float>& new_angles) : scalar_unit(init_scalar),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(msci::angle(x_angle));
		}
	}
	
	vector_unit_nd::vector_unit_nd(const string& init_scalar,const vector<msci::angle>& new_angles) : scalar_unit(init_scalar),angles(new_angles)
	{}
	
	vector_unit_nd::vector_unit_nd(const string& init_vector_nd)
	{}

	vector_unit_nd& vector_unit_nd::operator =(const vector_unit_nd& x)
	{
		scalar_unit::operator=(x);
		angles = x.angles;
		return *this;
	}

	vector_unit_nd& vector_unit_nd::operator =(vector_unit_nd&& x)
	{
		scalar_unit::operator=(move(x));
		angles = move(x.angles);
		return *this;
	}

	vector_unit_nd& vector_unit_nd::operator =(const scalar_unit& x)
	{
		scalar_unit::operator=(x);
		return *this;
	}

	vector_unit_nd& vector_unit_nd::operator =(scalar_unit&& x)
	{
		scalar_unit::operator=(move(x));
		return *this;
	}

	void vector_unit_nd::point_to(direction_symbol x)
	{
		if (is_1d())
		{
			if (x == direction_symbol::left)
			{
				if (value > 0)
				{
					value *= -1;
				}
			}
			else if(x == direction_symbol::right)
			{
				if (value < 0)
				{
					value *= -1;
				}
			}
		}
		else if (is_2d())
		{
			if (x == direction_symbol::left)
			{
				angles[0] = 180;
			}
			else if(x == direction_symbol::right)
			{
				angles[0] = 0;
			}
			else if(x == top)
			{
				angles[0] = 90;
			}
			else if(x == bottom)
			{
				angles[0] = 270;
			}
			else if(x == left_top)
			{
				angles[0] = 135;
			}
			else if(x == right_top)
			{
				angles[0] = 45;
			}
			else if(x == right_bottom)
			{
				angles[0] = 315;
			}
			else if(x == left_bottom)
			{
				angles[0] = 225;
			}
		}
		else if (is_3d())
		{
			if (x == direction_symbol::left)
			{
				angles[0] = 270;
				angles[1] = 90;
			}
			else if(x == direction_symbol::right)
			{
				angles[0] = 90;
				angles[1] = 90;
			}
			else if(x == top)
			{
				angles[0] = 0;
				angles[1] = 0;
			}
			else if(x == bottom)
			{
				angles[0] = 0;
				angles[1] = 180;
			}
			else if(x == left_top)
			{
				angles[0] = 270;
				angles[1] = 45;
			}
			else if(x == right_top)
			{
				angles[0] = 90;
				angles[1] = 45;
			}
			else if(x == right_bottom)
			{
				angles[0] = 90;
				angles[1] = 135;
			}
			else if(x == left_bottom)
			{
				angles[0] = 270;
				angles[1] = 135;
			}
			else if(x == front)
			{
				angles[0] = 0;
				angles[1] = 90;
			}
			else if(x == back)
			{
				angles[0] = 180;
				angles[1] = 90;
			}
			else if(x == left_front)
			{
				angles[0] = 315;
				angles[1] = 90;
			}
			else if(x == right_front)
			{
				angles[0] = 45;
				angles[1] = 90;
			}
			else if(x == top_front)
			{
				angles[0] = 0;
				angles[1] = 45;
			}
			else if(x == bottom_front)
			{
				angles[0] = 0;
				angles[1] = 135;
			}
			else if(x == left_back)
			{
				angles[0] = 225;
				angles[1] = 90;
			}
			else if(x == right_back)
			{
				angles[0] = 135;
				angles[1] = 90;
			}
			else if(x == top_back)
			{
				angles[0] = 180;
				angles[1] = 45;
			}
			else if(x == bottom_back)
			{
				angles[0] = 180;
				angles[1] = 135;
			}
			else if(x == left_top_front)
			{
				angles[0] = 315;
				angles[1] = 45;
			}
			else if(x == right_top_front)
			{
				angles[0] = 45;
				angles[1] = 45;
			}
			else if(x == left_bottom_front)
			{
				angles[0] = 315;
				angles[1] = 135;
			}
			else if(x == right_bottom_front)
			{
				angles[0] = 45;
				angles[1] = 135;
			}
			else if(x == left_top_back)
			{
				angles[0] = 225;
				angles[1] = 45;
			}
			else if(x == right_top_back)
			{
				angles[0] = 135;
				angles[1] = 45;
			}
			else if(x == left_bottom_back)
			{
				angles[0] = 225;
				angles[1] = 135;
			}
			else if(x == right_bottom_back)
			{
				angles[0] = 135;
				angles[1] = 135;
			}
		}
	}
	
	void vector_unit_nd::operator +=(const vector_unit_nd& y)
	{
		if(has_dimensions(y.get_derived_dimensions()))
		{
			if(is_1d())
			{
				scalar_unit::value += y.get_value();
			}
			else if(is_2d())
			{
				float new_x = x_projection() + y.x_projection();
				float new_y = y_projection() + y.y_projection();
				scalar_unit::value = cartesian_2d_to_polar_r(new_x, new_y);
				angles[0] = cartesian_2d_to_polar_angle(new_x, new_y);
			}
			else if(is_3d())
			{
				float new_x = x_projection() + y.x_projection();
				float new_y = y_projection() + y.y_projection();
				float new_z = z_projection() + y.z_projection();
				scalar_unit::value = cartesian_3d_to_spherical_r(new_x, new_y, new_z);
				angles[0] = cartesian_3d_to_spherical_angle1(new_x, new_y, new_z);
				angles[1] = cartesian_3d_to_spherical_angle2(new_x, new_y, new_z);
			}
		}
		else
		{
			cerr << "Cannot sum vectors of different dimensions";
		}
	}

	void vector_unit_nd::operator -=(const vector_unit_nd& y)
	{
		if(has_dimensions(y.get_derived_dimensions()))
		{
			vector_unit_nd z = vector_unit_nd(y);
			z.invert();
			*this += z;
		}
		else
		{
			cerr << "Cannot substract vectors of different dimensions";
		}
	}

	vector_unit_nd vector_unit_nd::operator +(const vector_unit_nd& y) const
	{
		vector_unit_nd z = *this;
		z += y;
		return z;
	}

	vector_unit_nd vector_unit_nd::operator -(const vector_unit_nd& y) const
	{
		vector_unit_nd z = *this;
		z -= y;
		return z;
	}

	vector_unit_nd vector_unit_nd::operator *(const scalar_unit& x) const
	{
		float new_value = scalar_unit::value * x.get_value();
		vector<dimension> new_dimensions = multiply_dimensions(get_dimensions(), x.get_dimensions());
		scalar_unit new_unit = scalar_unit(new_value, new_dimensions);
		if(is_1d())
		{
			return vector_unit_nd(new_unit);
		}
		else if(is_2d())
		{
			return vector_unit_nd(new_unit, {angles[0]});
		}
		else if(is_3d())
		{
			return vector_unit_nd(new_unit, {angles[0], angles[1]});
		}
		else
		{
			return vector_unit_nd(new_unit, angles);
		}
	}

	vector_unit_nd vector_unit_nd::operator /(const scalar_unit& x) const
	{
		float new_value = scalar_unit::value / x.get_value();
		vector<dimension> new_dimensions = divide_dimensions(get_dimensions(), x.get_dimensions());
		scalar_unit new_unit = scalar_unit(new_value, new_dimensions);
		if(is_1d())
		{
			return vector_unit_nd(new_unit);
		}
		else if(is_2d())
		{
			return vector_unit_nd(new_unit, {angles[0]});
		}
		else if(is_3d())
		{
			return vector_unit_nd(new_unit, {angles[0], angles[1]});
		}
		else
		{
			return vector_unit_nd(new_unit, angles);
		}
	}

	vector_unit_nd vector_unit_nd::operator ^(const scalar_unit& x) const
	{
		if(x.has_empty_dimensions())
		{
			scalar_unit new_unit = *this ^ x;
			if(is_1d())
			{
				return vector_unit_nd(new_unit);
			}
			else if(is_2d())
			{
				return vector_unit_nd(new_unit, {angles[0]});
			}
			else if(is_3d())
			{
				return vector_unit_nd(new_unit, {angles[0], angles[1]});
			}
		}
		else
		{
			return vector_unit_nd();
		}
	}

	scalar_unit norm(const vector_unit_nd& x)
	{
		return scalar_unit(x.get_value(),x.get_dimensions());
	}

	vector_unit_nd sqrt(const vector_unit_nd& x)
	{
		scalar_unit new_value = msci::sqrt(x);
		return vector_unit_nd(new_value, x.angles);
	}

	vector_unit_nd sqrt_nth(const vector_unit_nd& x, int y)
	{
		scalar_unit new_value = msci::sqrt_nth(scalar_unit(x), y);
		return vector_unit_nd(new_value, x.angles);
	}

	scalar_unit dot_product(const vector_unit_nd& x, const vector_unit_nd& y)
	{
		float new_value = x.x_projection()*y.x_projection() + x.y_projection()*y.y_projection() + x.z_projection()*y.z_projection();
		vector<dimension> new_dimensions = multiply_dimensions(x.get_dimensions(), y.get_dimensions());
		return scalar_unit(new_value,new_dimensions);
	}

	vector_unit_nd cross_product(const vector_unit_nd& x,const vector_unit_nd& y)
	{
		if(x.is_3d() and y.is_3d())
		{
			float new_value;
			float angle1;
			float angle2;
			if(y.angles[0] == x.angles[0] and y.angles[1] == x.angles[1])
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
			vector<msci::angle> angles;
			angles.push_back(msci::angle(angle1));
			angles.push_back(msci::angle(angle2));
			return vector_unit_nd(new_unit, angles);
		}
		else
		{
			return vector_unit_nd();
		}
	}

	msci::angle angle_between(const vector_unit_nd& x,const vector_unit_nd& y)
	{
		return msci::acos(float(dot_product(x,y)/(norm(x) * norm(y))));
	}

	bool same_nd(const vector_unit_nd& x, const vector_unit_nd& y)
	{
		if(x.angles.size() == y.angles.size())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool same_direction(const vector_unit_nd& x, const vector_unit_nd& y)
	{
		for(unsigned int i = 0; i < x.angles.size(); i++)
		{
			if(x.angles[i] != y.angles[i])
			{
				return false;
			}
		}
		return true;
	}

	bool parallel(const vector_unit_nd& x, const vector_unit_nd& y)
	{
		for(unsigned int i = 0; i < x.angles.size(); i++)
		{
			if(!msci::parallel(x.angles[i], y.angles[i]))
			{
				return false;
			}
		}
		return true;
	}

	bool orthogonal(const vector_unit_nd& x,const vector_unit_nd& y)
	{
		for(unsigned int i = 0; i < x.angles.size(); i++)
		{
			if(msci::orthogonal(x.angles[i], y.angles[i]))
			{
				return true;
			}
		}
		return false;
	}
}

bool operator ==(const msci::vector_unit_nd& x, const msci::vector_unit_nd& y)
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

bool operator !=(const msci::vector_unit_nd& x, const msci::vector_unit_nd& y)
{
	return !(x == y);
}

void operator +=(string& x, const msci::vector_unit_nd& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const msci::vector_unit_nd& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const msci::vector_unit_nd& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const msci::vector_unit_nd& x)
{
	ostringstream angles_text;
	if (!x.is_1d())
	{
		for(const auto& x_angle : x.angles)
		{
			angles_text << x_angle;
			angles_text << " ";
		}
	}
	return os << x.get_value() << " " << x.display_dimensions() << " " << angles_text.str().substr(0,-1);
}

istream& operator >>(istream& is, msci::vector_unit_nd& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::vector_unit_nd c(b);
	x = c;
	return is;
}
 
