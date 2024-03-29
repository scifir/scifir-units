#include "units/vector_unit_3d.hpp"

#include "coordinates/coordinates_3d.hpp"
#include "util/types.hpp"

using namespace std;

namespace scifir
{
	vector_unit_3d::vector_unit_3d() : scalar_unit(),theta(),phi()
	{}

	vector_unit_3d::vector_unit_3d(const vector_unit_3d& x) : scalar_unit(x),theta(x.theta),phi(x.phi)
	{}

	vector_unit_3d::vector_unit_3d(vector_unit_3d&& x) : scalar_unit(x),theta(x.theta),phi(x.phi)
	{}

	vector_unit_3d::vector_unit_3d(float new_value,const string& init_dimensions,float new_theta,float new_phi) : scalar_unit(new_value,init_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(float new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi) : scalar_unit(new_value,init_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(float new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi) : scalar_unit(new_value,new_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(float new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi) : scalar_unit(new_value,new_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(const scalar_unit& x,float new_theta,float new_phi) : scalar_unit(x),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(const scalar_unit& x,const angle& new_theta,const angle& new_phi) : scalar_unit(x),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(const string& init,float new_theta,float new_phi) : scalar_unit(init),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(const string& init,const angle& new_theta,const angle& new_phi) : scalar_unit(init),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(const string& init_vector_3d) : vector_unit_3d()
	{
		vector<string> values;
		boost::split(values,init_vector_3d,boost::is_any_of(" "));
		if (values.size() == 4)
		{
			set_from_string(values[0] + " " + values[1]);
			theta = angle(values[2]);
			phi = angle(values[3]);
		}
	}
	

	vector_unit_3d& vector_unit_3d::operator =(const vector_unit_3d& x)
	{
		scalar_unit::operator=(x);
		theta = x.theta;
		phi = x.phi;
		return *this;
	}

	vector_unit_3d& vector_unit_3d::operator =(vector_unit_3d&& x)
	{
		scalar_unit::operator=(move(x));
		theta = move(x.theta);
		phi = move(x.phi);
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

	void vector_unit_3d::point_to(direction::name x)
	{
		if (x == direction::LEFT)
		{
			theta = 270;
			phi = 90;
		}
		else if(x == direction::RIGHT)
		{
			theta = 90;
			phi = 90;
		}
		else if(x == direction::TOP)
		{
			theta = 0;
			phi = 0;
		}
		else if(x == direction::BOTTOM)
		{
			theta = 0;
			phi = 180;
		}
		else if(x == direction::LEFT_TOP)
		{
			theta = 270;
			phi = 45;
		}
		else if(x == direction::RIGHT_TOP)
		{
			theta = 90;
			phi = 45;
		}
		else if(x == direction::RIGHT_BOTTOM)
		{
			theta = 90;
			phi = 135;
		}
		else if(x == direction::LEFT_BOTTOM)
		{
			theta = 270;
			phi = 135;
		}
		else if(x == direction::FRONT)
		{
			theta = 0;
			phi = 90;
		}
		else if(x == direction::BACK)
		{
			theta = 180;
			phi = 90;
		}
		else if(x == direction::LEFT_FRONT)
		{
			theta = 315;
			phi = 90;
		}
		else if(x == direction::RIGHT_FRONT)
		{
			theta = 45;
			phi = 90;
		}
		else if(x == direction::TOP_FRONT)
		{
			theta = 0;
			phi = 45;
		}
		else if(x == direction::BOTTOM_FRONT)
		{
			theta = 0;
			phi = 135;
		}
		else if(x == direction::LEFT_BACK)
		{
			theta = 225;
			phi = 90;
		}
		else if(x == direction::RIGHT_BACK)
		{
			theta = 135;
			phi = 90;
		}
		else if(x == direction::TOP_BACK)
		{
			theta = 180;
			phi = 45;
		}
		else if(x == direction::BOTTOM_BACK)
		{
			theta = 180;
			phi = 135;
		}
		else if(x == direction::LEFT_TOP_FRONT)
		{
			theta = 315;
			phi = 45;
		}
		else if(x == direction::RIGHT_TOP_FRONT)
		{
			theta = 45;
			phi = 45;
		}
		else if(x == direction::LEFT_BOTTOM_FRONT)
		{
			theta = 315;
			phi = 135;
		}
		else if(x == direction::RIGHT_BOTTOM_FRONT)
		{
			theta = 45;
			phi = 135;
		}
		else if(x == direction::LEFT_TOP_BACK)
		{
			theta = 225;
			phi = 45;
		}
		else if(x == direction::RIGHT_TOP_BACK)
		{
			theta = 135;
			phi = 45;
		}
		else if(x == direction::LEFT_BOTTOM_BACK)
		{
			theta = 225;
			phi = 135;
		}
		else if(x == direction::RIGHT_BOTTOM_BACK)
		{
			theta = 135;
			phi = 135;
		}
	}
	
	void vector_unit_3d::operator +=(const vector_unit_3d& y)
	{
		if(has_dimensions(y))
		{
			float new_x = float(x_projection() + y.x_projection());
			float new_y = float(y_projection() + y.y_projection());
			float new_z = float(z_projection() + y.z_projection());
			scalar_unit::value = cartesian_3d_to_spherical_r(new_x, new_y, new_z);
			theta = angle(cartesian_3d_to_spherical_theta(new_x, new_y, new_z));
			phi = angle(cartesian_3d_to_spherical_phi(new_x, new_y, new_z));
		}
		else
		{
			cerr << "Cannot sum vectors of different dimensions";
		}
	}

	void vector_unit_3d::operator -=(vector_unit_3d y)
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

	vector_unit_3d vector_unit_3d::operator +(const vector_unit_3d& y) const
	{
		if (has_dimensions(y))
		{
			float new_x = float(x_projection() + y.x_projection());
			float new_y = float(y_projection() + y.y_projection());
			float new_z = float(z_projection() + y.z_projection());
			float new_value = cartesian_3d_to_spherical_r(new_x, new_y, new_z);
			angle new_theta = angle(cartesian_3d_to_spherical_theta(new_x, new_y, new_z));
			angle new_phi = angle(cartesian_3d_to_spherical_phi(new_x, new_y, new_z));
			return vector_unit_3d(new_value,get_dimensions(),new_theta,new_phi);
		}
		else
		{
			return vector_unit_3d();
		}
	}

	vector_unit_3d vector_unit_3d::operator -(vector_unit_3d y) const
	{
		if (has_dimensions(y))
		{
			y.invert();
			float new_x = float(x_projection() + y.x_projection());
			float new_y = float(y_projection() + y.y_projection());
			float new_z = float(z_projection() + y.z_projection());
			float new_value = cartesian_3d_to_spherical_r(new_x, new_y, new_z);
			angle new_theta = angle(cartesian_3d_to_spherical_theta(new_x, new_y, new_z));
			angle new_phi = angle(cartesian_3d_to_spherical_phi(new_x, new_y, new_z));
			return vector_unit_3d(new_value,get_dimensions(),new_theta,new_phi);
		}
		else
		{
			return vector_unit_3d();
		}
	}

	vector_unit_3d vector_unit_3d::operator *(const scalar_unit& x) const
	{
		long double new_value = scalar_unit::value * x.get_value();
		vector<dimension> new_dimensions = multiply_dimensions(get_dimensions(), x.get_dimensions(),new_value);
		return vector_unit_3d(new_value, new_dimensions, theta, phi);
	}

	vector_unit_3d vector_unit_3d::operator /(const scalar_unit& x) const
	{
		long double new_value = scalar_unit::value / x.get_value();
		vector<dimension> new_dimensions = divide_dimensions(get_dimensions(), x.get_dimensions(),new_value);
		return vector_unit_3d(new_value, new_dimensions, theta, phi);
	}

	vector_unit_3d vector_unit_3d::operator ^(const scalar_unit& x) const
	{
		if(x.has_empty_dimensions())
		{
			scalar_unit new_unit = *this ^ x;
			return vector_unit_3d(new_unit, theta, phi);
		}
		else
		{
			cerr << "Cannot power with as exponent a unit with dimensions";
			return vector_unit_3d();
		}
	}

	string vector_unit_3d::vectorial_display(int number_of_decimals) const
	{
		ostringstream out;
		out << display(number_of_decimals) << " " << display_float(theta.get_value(),number_of_decimals) << "\u03B8 " << display_float(phi.get_value(),number_of_decimals) << "\u03A6";
		return out.str();
	}

	string vector_unit_3d::vectorial_derived_display(int number_of_decimals) const
	{
		ostringstream out;
		out << derived_display(number_of_decimals) << " " << display_float(theta.get_value(),number_of_decimals) << "\u03B8 " << display_float(phi.get_value(),number_of_decimals) << "\u03A6";
		return out.str();
	}

	string vector_unit_3d::vectorial_custom_display(const string& new_dimensions_str,int number_of_decimals) const
	{
		ostringstream out;
		out << custom_display(new_dimensions_str,number_of_decimals) << " " << display_float(theta.get_value(),number_of_decimals) << "\u03B8 " << display_float(phi.get_value(),number_of_decimals) << "\u03A6";
		return out.str();
	}

	string to_string(const vector_unit_3d& x)
	{
		ostringstream out;
		out << x.display(2) << " " << display_float(x.theta.get_value(),2) << "\u03B8 " << display_float(x.phi.get_value(),2) << "\u03A6";
		return out.str();
	}

	scalar_unit norm(const vector_unit_3d& x)
	{
		return scalar_unit(std::abs(x.get_value()),x.get_dimensions());
	}

	vector_unit_3d sqrt(const vector_unit_3d& x)
	{
		scalar_unit new_value = scifir::sqrt(scalar_unit(x));
		return vector_unit_3d(new_value, x.theta, x.phi);
	}

	vector_unit_3d sqrt_nth(const vector_unit_3d& x, int y)
	{
		scalar_unit new_value = scifir::sqrt_nth(scalar_unit(x), y);
		return vector_unit_3d(new_value, x.theta, x.phi);
	}

	scalar_unit dot_product(const vector_unit_3d& x, const vector_unit_3d& y)
	{
		long double new_value = float(x.x_projection()*y.x_projection() + x.y_projection()*y.y_projection() + x.z_projection()*y.z_projection());
		vector<dimension> new_dimensions = multiply_dimensions(x.get_dimensions(), y.get_dimensions(),new_value);
		return scalar_unit(new_value,new_dimensions);
	}

	vector_unit_3d cross_product(const vector_unit_3d& x,const vector_unit_3d& y)
	{
		long double new_value;
		float new_theta;
		float new_phi;
		if(y.theta == x.theta and y.phi == x.phi)
		{
			new_value = 0;
			new_theta = 0;
			new_phi = 0;
		}
		else
		{
			float new_x = float(x.y_projection() * y.z_projection() - x.z_projection() * y.y_projection());
			float new_y = float(x.z_projection() * y.x_projection() - x.x_projection() * y.z_projection());
			float new_z = float(x.x_projection() * y.y_projection() - x.y_projection() * y.x_projection());
			new_value = cartesian_3d_to_spherical_r(new_x, new_y, new_z);
			new_theta = cartesian_3d_to_spherical_theta(new_x, new_y, new_z);
			new_phi = cartesian_3d_to_spherical_phi(new_x, new_y, new_z);
		}
		vector<dimension> new_dimensions = multiply_dimensions(x.get_dimensions(), y.get_dimensions(),new_value);
		return vector_unit_3d(new_value, new_dimensions, new_theta, new_phi);
	}

	angle angle_between(const vector_unit_3d& x,const vector_unit_3d& y)
	{
		return scifir::acos(float(dot_product(x,y)/(norm(x)*norm(y))));
	}

	bool same_direction(const vector_unit_3d& x, const vector_unit_3d& y)
	{
		if (x.theta == y.theta and x.phi == y.phi)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool parallel(const vector_unit_3d& x, const vector_unit_3d& y)
	{
		if (scifir::parallel(x.theta,y.theta) and scifir::parallel(x.phi,y.phi) )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool orthogonal(const vector_unit_3d& x,const vector_unit_3d& y)
	{
		if (scifir::orthogonal(x.theta,y.theta) and scifir::orthogonal(x.phi,y.phi) )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool operator ==(const vector_unit_3d& x, vector_unit_3d y)
{
	y.change_dimensions(x);
	if(x.get_value() == y.get_value() and scifir::same_direction(x,y) and x.has_dimensions(y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const vector_unit_3d& x, const vector_unit_3d& y)
{
	return !(x == y);
}

bool operator ==(const vector_unit_3d& x, const string& y)
{
	vector_unit_3d y_vector = vector_unit_3d(y);
	return (x == y_vector);
}

bool operator !=(const vector_unit_3d& x, const string& y)
{
	return !(x == y);
}

bool operator ==(const string& x, const vector_unit_3d& y)
{
	vector_unit_3d x_vector = vector_unit_3d(x);
	return (x_vector == y);
}

bool operator !=(const string& x, const vector_unit_3d& y)
{
	return !(x == y);
}

void operator +=(string& x, const vector_unit_3d& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const vector_unit_3d& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const vector_unit_3d& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const vector_unit_3d& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, vector_unit_3d& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	vector_unit_3d c(b);
	x = c;
	return is;
}
