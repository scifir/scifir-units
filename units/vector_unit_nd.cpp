#include "units/vector_unit_nd.hpp"

#include "coordinates/coordinates_2d.hpp"
#include "coordinates/coordinates_3d.hpp"

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
			angles.push_back(angle(x_angle));
		}
	}

	vector_unit_nd::vector_unit_nd(float new_value,const string& init_dimensions,const vector<angle>& new_angles) : scalar_unit(new_value,init_dimensions),angles(new_angles)
	{}

	vector_unit_nd::vector_unit_nd(float new_value,const vector<dimension>& new_dimensions) : scalar_unit(new_value,new_dimensions),angles()
	{}

	vector_unit_nd::vector_unit_nd(float new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles) : scalar_unit(new_value,new_dimensions),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(angle(x_angle));
		}
	}

	vector_unit_nd::vector_unit_nd(float new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles) : scalar_unit(new_value,new_dimensions),angles(new_angles)
	{}

	vector_unit_nd::vector_unit_nd(const scalar_unit& x) : scalar_unit(x),angles()
	{}

	vector_unit_nd::vector_unit_nd(const scalar_unit& x,const vector<float>& new_angles)
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(angle(x_angle));
		}
	}

	vector_unit_nd::vector_unit_nd(const scalar_unit& x,const vector<angle>& new_angles) : scalar_unit(x),angles(new_angles)
	{}

	vector_unit_nd::vector_unit_nd(scalar_unit&& x)
	{}

	vector_unit_nd::vector_unit_nd(scalar_unit&& x,const vector<float>& new_angles) : scalar_unit(x),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(angle(x_angle));
		}
	}

	vector_unit_nd::vector_unit_nd(scalar_unit&& x,const vector<angle>& new_angles) : scalar_unit(x),angles(new_angles)
	{}

	vector_unit_nd::vector_unit_nd(const string& init_scalar,const vector<float>& new_angles) : scalar_unit(init_scalar),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(angle(x_angle));
		}
	}

	vector_unit_nd::vector_unit_nd(const string& init_scalar,const vector<angle>& new_angles) : scalar_unit(init_scalar),angles(new_angles)
	{}

	vector_unit_nd::vector_unit_nd(const string& init_vector_nd) : vector_unit_nd()
	{
		vector<string> values;
		boost::split(values,init_vector_nd,boost::is_any_of(" "));
		set_from_string(values[0]);
		if (values.size() > 1)
		{
			for (int i = 1; i < values.size(); i++)
			{
				angles.push_back(angle(values[i]));
			}
		}
	}

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

	void vector_unit_nd::point_to(direction::name x)
	{
		if (is_nd(1))
		{
			if (x == direction::LEFT)
			{
				if (value > 0)
				{
					value *= -1;
				}
			}
			else if(x == direction::RIGHT)
			{
				if (value < 0)
				{
					value *= -1;
				}
			}
		}
		else if (is_nd(2))
		{
			if (x == direction::LEFT)
			{
				angles[0] = 180;
			}
			else if(x == direction::RIGHT)
			{
				angles[0] = 0;
			}
			else if(x == direction::TOP)
			{
				angles[0] = 90;
			}
			else if(x == direction::BOTTOM)
			{
				angles[0] = 270;
			}
			else if(x == direction::LEFT_TOP)
			{
				angles[0] = 135;
			}
			else if(x == direction::RIGHT_TOP)
			{
				angles[0] = 45;
			}
			else if(x == direction::RIGHT_BOTTOM)
			{
				angles[0] = 315;
			}
			else if(x == direction::LEFT_BOTTOM)
			{
				angles[0] = 225;
			}
		}
		else if (is_nd(3))
		{
			if (x == direction::LEFT)
			{
				angles[0] = 270;
				angles[1] = 90;
			}
			else if(x == direction::RIGHT)
			{
				angles[0] = 90;
				angles[1] = 90;
			}
			else if(x == direction::TOP)
			{
				angles[0] = 0;
				angles[1] = 0;
			}
			else if(x == direction::BOTTOM)
			{
				angles[0] = 0;
				angles[1] = 180;
			}
			else if(x == direction::LEFT_TOP)
			{
				angles[0] = 270;
				angles[1] = 45;
			}
			else if(x == direction::RIGHT_TOP)
			{
				angles[0] = 90;
				angles[1] = 45;
			}
			else if(x == direction::RIGHT_BOTTOM)
			{
				angles[0] = 90;
				angles[1] = 135;
			}
			else if(x == direction::LEFT_BOTTOM)
			{
				angles[0] = 270;
				angles[1] = 135;
			}
			else if(x == direction::FRONT)
			{
				angles[0] = 0;
				angles[1] = 90;
			}
			else if(x == direction::BACK)
			{
				angles[0] = 180;
				angles[1] = 90;
			}
			else if(x == direction::LEFT_FRONT)
			{
				angles[0] = 315;
				angles[1] = 90;
			}
			else if(x == direction::RIGHT_FRONT)
			{
				angles[0] = 45;
				angles[1] = 90;
			}
			else if(x == direction::TOP_FRONT)
			{
				angles[0] = 0;
				angles[1] = 45;
			}
			else if(x == direction::BOTTOM_FRONT)
			{
				angles[0] = 0;
				angles[1] = 135;
			}
			else if(x == direction::LEFT_BACK)
			{
				angles[0] = 225;
				angles[1] = 90;
			}
			else if(x == direction::RIGHT_BACK)
			{
				angles[0] = 135;
				angles[1] = 90;
			}
			else if(x == direction::TOP_BACK)
			{
				angles[0] = 180;
				angles[1] = 45;
			}
			else if(x == direction::BOTTOM_BACK)
			{
				angles[0] = 180;
				angles[1] = 135;
			}
			else if(x == direction::LEFT_TOP_FRONT)
			{
				angles[0] = 315;
				angles[1] = 45;
			}
			else if(x == direction::RIGHT_TOP_FRONT)
			{
				angles[0] = 45;
				angles[1] = 45;
			}
			else if(x == direction::LEFT_BOTTOM_FRONT)
			{
				angles[0] = 315;
				angles[1] = 135;
			}
			else if(x == direction::RIGHT_BOTTOM_FRONT)
			{
				angles[0] = 45;
				angles[1] = 135;
			}
			else if(x == direction::LEFT_TOP_BACK)
			{
				angles[0] = 225;
				angles[1] = 45;
			}
			else if(x == direction::RIGHT_TOP_BACK)
			{
				angles[0] = 135;
				angles[1] = 45;
			}
			else if(x == direction::LEFT_BOTTOM_BACK)
			{
				angles[0] = 225;
				angles[1] = 135;
			}
			else if(x == direction::RIGHT_BOTTOM_BACK)
			{
				angles[0] = 135;
				angles[1] = 135;
			}
		}
	}

	void vector_unit_nd::operator +=(const vector_unit_nd& y)
	{
		if(has_dimensions(y) and get_nd() == y.get_nd())
		{
			if(is_nd(1))
			{
				scalar_unit::value += y.get_value();
			}
			else if(is_nd(2))
			{
				float new_x = float(x_projection() + y.x_projection());
				float new_y = float(y_projection() + y.y_projection());
				scalar_unit::value = cartesian_2d_to_polar_r(new_x, new_y);
				angles[0] = cartesian_2d_to_polar_theta(new_x, new_y);
			}
			else if(is_nd(3))
			{
				float new_x = float(x_projection() + y.x_projection());
				float new_y = float(y_projection() + y.y_projection());
				float new_z = float(z_projection() + y.z_projection());
				scalar_unit::value = cartesian_3d_to_spherical_r(new_x, new_y, new_z);
				angles[0] = cartesian_3d_to_spherical_theta(new_x, new_y, new_z);
				angles[1] = cartesian_3d_to_spherical_phi(new_x, new_y, new_z);
			}
		}
		else
		{
			cerr << "Cannot sum vectors of different dimensions";
		}
	}

	void vector_unit_nd::operator -=(vector_unit_nd y)
	{
		if(has_dimensions(y))
		{
			y.invert();
			*this += y;
		}
		else
		{
			cerr << "Cannot substract vectors of different dimensions";
		}
	}

	vector_unit_nd vector_unit_nd::operator +(const vector_unit_nd& y) const
	{
		if(has_dimensions(y))
		{
			if(is_nd(1))
			{
				float new_value = scalar_unit::value + y.get_value();
				return vector_unit_nd(new_value,get_dimensions());
			}
			else if(is_nd(2))
			{
				float new_x = float(x_projection() + y.x_projection());
				float new_y = float(y_projection() + y.y_projection());
				float new_value = cartesian_2d_to_polar_r(new_x, new_y);
				vector<angle> new_angles = vector<angle>();
				new_angles.push_back(angle(cartesian_2d_to_polar_theta(new_x, new_y)));
				return vector_unit_nd(new_value,get_dimensions(),new_angles);
			}
			else if(is_nd(3))
			{
				float new_x = float(x_projection() + y.x_projection());
				float new_y = float(y_projection() + y.y_projection());
				float new_z = float(z_projection() + y.z_projection());
				float new_value = cartesian_3d_to_spherical_r(new_x, new_y, new_z);
				vector<angle> new_angles = vector<angle>();
				new_angles.push_back(angle(cartesian_3d_to_spherical_theta(new_x, new_y, new_z)));
				new_angles.push_back(angle(cartesian_3d_to_spherical_phi(new_x, new_y, new_z)));
				return vector_unit_nd(new_value,get_dimensions(),new_angles);
			}
			else
			{
				return vector_unit_nd();
			}
		}
		else
		{
			cerr << "Cannot sum vectors of different dimensions";
			return vector_unit_nd();
		}
	}

	vector_unit_nd vector_unit_nd::operator -(vector_unit_nd y) const
	{
		if(has_dimensions(y))
		{
			y.invert();
			if(is_nd(1))
			{
				float new_value = scalar_unit::value + y.get_value();
				return vector_unit_nd(new_value,get_dimensions());
			}
			else if(is_nd(2))
			{
				float new_x = float(x_projection() + y.x_projection());
				float new_y = float(y_projection() + y.y_projection());
				float new_value = cartesian_2d_to_polar_r(new_x, new_y);
				vector<angle> new_angles = vector<angle>();
				new_angles.push_back(angle(cartesian_2d_to_polar_theta(new_x, new_y)));
				return vector_unit_nd(new_value,get_dimensions(),new_angles);
			}
			else if(is_nd(3))
			{
				float new_x = float(x_projection() + y.x_projection());
				float new_y = float(y_projection() + y.y_projection());
				float new_z = float(z_projection() + y.z_projection());
				float new_value = cartesian_3d_to_spherical_r(new_x, new_y, new_z);
				vector<angle> new_angles = vector<angle>();
				new_angles.push_back(angle(cartesian_3d_to_spherical_theta(new_x, new_y, new_z)));
				new_angles.push_back(angle(cartesian_3d_to_spherical_phi(new_x, new_y, new_z)));
				return vector_unit_nd(new_value,get_dimensions(),new_angles);
			}
			else
			{
				return vector_unit_nd();
			}
		}
		else
		{
			cerr << "Cannot sum vectors of different dimensions";
			return vector_unit_nd();
		}
	}

	vector_unit_nd vector_unit_nd::operator *(const scalar_unit& x) const
	{
		long double new_value = scalar_unit::value * x.get_value();
		vector<dimension> new_dimensions = multiply_dimensions(get_dimensions(), x.get_dimensions(),new_value);
		scalar_unit new_unit = scalar_unit(new_value, new_dimensions);
		if(is_nd(1))
		{
			return vector_unit_nd(new_unit);
		}
		else if(is_nd(2))
		{
			return vector_unit_nd(new_unit, {angles[0]});
		}
		else if(is_nd(3))
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
		long double new_value = scalar_unit::value / x.get_value();
		vector<dimension> new_dimensions = divide_dimensions(get_dimensions(), x.get_dimensions(),new_value);
		scalar_unit new_unit = scalar_unit(new_value, new_dimensions);
		if(is_nd(1))
		{
			return vector_unit_nd(new_unit);
		}
		else if(is_nd(2))
		{
			return vector_unit_nd(new_unit, {angles[0]});
		}
		else if(is_nd(3))
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
			if(is_nd(1))
			{
				return vector_unit_nd(new_unit);
			}
			else if(is_nd(2))
			{
				return vector_unit_nd(new_unit, {angles[0]});
			}
			else if(is_nd(3))
			{
				return vector_unit_nd(new_unit, {angles[0], angles[1]});
			}
			else
			{
				return vector_unit_nd();
			}
		}
		else
		{
			return vector_unit_nd();
		}
	}

	scalar_unit vector_unit_nd::n_projection(int i) const
	{
		if (i == 1)
		{
			return x_projection();
		}
		else if (i == 2)
		{
			return y_projection();
		}
		else if (i == 3)
		{
			return z_projection();
		}
		else
		{
			return scalar_unit();
		}
	}

	scalar_unit vector_unit_nd::x_projection() const
	{
		if (is_nd(1))
		{
			return scalar_unit(scalar_unit::value,get_dimensions());
		}
		else if (is_nd(2))
		{
			return scalar_unit(scalar_unit::value * msci::cos(angles[0]),get_dimensions());
		}
		else if (is_nd(3))
		{
			return scalar_unit(scalar_unit::value * msci::cos(angles[0]) * msci::sin(angles[1]),get_dimensions());
		}
		else
		{
			return scalar_unit();
		}
	}

	scalar_unit vector_unit_nd::y_projection() const
	{
		if (is_nd(1))
		{
			return scalar_unit();
		}
		else if (is_nd(2))
		{
			return scalar_unit(scalar_unit::value * msci::sin(angles[0]),get_dimensions());
		}
		else if (is_nd(3))
		{
			return scalar_unit(scalar_unit::value * msci::sin(angles[0]) * msci::sin(angles[1]),get_dimensions());
		}
		else
		{
			return scalar_unit();
		}
	}

	scalar_unit vector_unit_nd::z_projection() const
	{
		if (is_nd(1))
		{
			return scalar_unit();
		}
		else if (is_nd(2))
		{
			return scalar_unit();
		}
		else if (is_nd(3))
		{
			return scalar_unit(scalar_unit::value * msci::cos(angles[1]),get_dimensions());
		}
		else
		{
			return scalar_unit();
		}
	}

	void vector_unit_nd::invert()
	{
		for(angle& x_angle : angles)
		{
			x_angle.invert();
		}
	}

	string to_string(const vector_unit_nd& x)
	{
		ostringstream out;
		out << x.get_value() << " " << x.display_dimensions();
		for (const angle& x_angle : x.angles)
		{
			out << " " << x_angle;
		}
		return out.str();
	}

	scalar_unit norm(const vector_unit_nd& x)
	{
		return scalar_unit(std::abs(x.get_value()),x.get_dimensions());
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
		long double new_value = float(x.x_projection()*y.x_projection() + x.y_projection()*y.y_projection() + x.z_projection()*y.z_projection());
		vector<dimension> new_dimensions = multiply_dimensions(x.get_dimensions(), y.get_dimensions(),new_value);
		return scalar_unit(new_value,new_dimensions);
	}

	vector_unit_nd cross_product(const vector_unit_nd& x,const vector_unit_nd& y)
	{
		if(x.is_nd(3) and y.is_nd(3))
		{
			long double new_value;
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
				float new_x = float(x.y_projection() * y.z_projection() - x.z_projection() * y.y_projection());
				float new_y = float(x.z_projection() * y.x_projection() - x.x_projection() * y.z_projection());
				float new_z = float(x.x_projection() * y.y_projection() - x.y_projection() * y.x_projection());
				new_value = cartesian_3d_to_spherical_r(new_x, new_y, new_z);
				angle1 = cartesian_3d_to_spherical_theta(new_x, new_y, new_z);
				angle2 = cartesian_3d_to_spherical_phi(new_x, new_y, new_z);
			}
			vector<dimension> new_dimensions = multiply_dimensions(x.get_dimensions(), y.get_dimensions(),new_value);
			scalar_unit new_unit = scalar_unit(new_value, new_dimensions);
			vector<angle> angles;
			angles.push_back(angle(angle1));
			angles.push_back(angle(angle2));
			return vector_unit_nd(new_unit, angles);
		}
		else
		{
			return vector_unit_nd();
		}
	}

	angle angle_between(const vector_unit_nd& x,const vector_unit_nd& y)
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

bool operator ==(const vector_unit_nd& x, vector_unit_nd y)
{
	y.change_dimensions(x);
	if(x.get_value() == y.get_value() and msci::same_direction(x,y) and x.has_dimensions(y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const vector_unit_nd& x, const vector_unit_nd& y)
{
	return !(x == y);
}

bool operator ==(const vector_unit_nd& x, const string& y)
{
	vector_unit_nd y_vector = vector_unit_nd(y);
	return (x == y_vector);
}

bool operator !=(const vector_unit_nd& x, const string& y)
{
	return !(x == y);
}

bool operator ==(const string& x, const vector_unit_nd& y)
{
	vector_unit_nd x_vector = vector_unit_nd(x);
	return (x_vector == y);
}

bool operator !=(const string& x, const vector_unit_nd& y)
{
	return !(x == y);
}

void operator +=(string& x, const vector_unit_nd& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const vector_unit_nd& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const vector_unit_nd& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const vector_unit_nd& x)
{
	ostringstream angles_text;
	if (!x.is_nd(1))
	{
		for(const auto& x_angle : x.angles)
		{
			angles_text << x_angle;
			angles_text << " ";
		}
	}
	return os << x.get_value() << " " << x.display_dimensions() << " " << angles_text.str().substr(0,-1);
}

istream& operator >>(istream& is, vector_unit_nd& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::vector_unit_nd c(b);
	x = c;
	return is;
}
 
