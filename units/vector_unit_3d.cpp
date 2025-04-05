#include "./vector_unit_3d.hpp"

#include "../coordinates/coordinates_3d.hpp"
#include "../util/types.hpp"

using namespace std;

namespace scifir
{
	vector_unit_3d::vector_unit_3d() : scalar_unit(),theta(),phi()
	{}

	vector_unit_3d::vector_unit_3d(const vector_unit_3d& x) : scalar_unit(x),theta(x.theta),phi(x.phi)
	{}

	vector_unit_3d::vector_unit_3d(vector_unit_3d&& x) : scalar_unit(std::move(x)),theta(std::move(x.theta)),phi(std::move(x.phi))
	{}

	vector_unit_3d::vector_unit_3d(float new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi, dimension::position new_position) : scalar_unit(new_value,new_dimension,new_prefix,new_position),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(float new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position) : scalar_unit(new_value,new_dimension,new_prefix,new_position),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(double new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi, dimension::position new_position) : scalar_unit(new_value,new_dimension,new_prefix,new_position),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(double new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position) : scalar_unit(new_value,new_dimension,new_prefix,new_position),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(long double new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi, dimension::position new_position) : scalar_unit(new_value,new_dimension,new_prefix,new_position),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(long double new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position) : scalar_unit(new_value,new_dimension,new_prefix,new_position),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(int new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi, dimension::position new_position) : scalar_unit(new_value,new_dimension,new_prefix,new_position),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(int new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position) : scalar_unit(new_value,new_dimension,new_prefix,new_position),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(float new_value,const string& init_dimensions,float new_theta,float new_phi) : scalar_unit(new_value,init_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(float new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi) : scalar_unit(new_value,init_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(double new_value,const string& init_dimensions,float new_theta,float new_phi) : scalar_unit(new_value,init_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(double new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi) : scalar_unit(new_value,init_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(long double new_value,const string& init_dimensions,float new_theta,float new_phi) : scalar_unit(new_value,init_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(long double new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi) : scalar_unit(new_value,init_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(int new_value,const string& init_dimensions,float new_theta,float new_phi) : scalar_unit(new_value,init_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(int new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi) : scalar_unit(new_value,init_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(float new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi) : scalar_unit(new_value,new_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(float new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi) : scalar_unit(new_value,new_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(double new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi) : scalar_unit(new_value,new_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(double new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi) : scalar_unit(new_value,new_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(long double new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi) : scalar_unit(new_value,new_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(long double new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi) : scalar_unit(new_value,new_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(int new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi) : scalar_unit(new_value,new_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(int new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi) : scalar_unit(new_value,new_dimensions),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(const scalar_unit& x,float new_theta,float new_phi) : scalar_unit(x),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(const scalar_unit& x,const angle& new_theta,const angle& new_phi) : scalar_unit(x),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(const string& init_scalar,float new_theta,float new_phi) : scalar_unit(init_scalar),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(const string& init_scalar,const angle& new_theta,const angle& new_phi) : scalar_unit(init_scalar),theta(new_theta),phi(new_phi)
	{}

	vector_unit_3d::vector_unit_3d(const string& init_vector_3d) : vector_unit_3d()
	{
		vector_unit_3d::initialize_from_string(init_vector_3d);
	}

	vector_unit_3d& vector_unit_3d::operator =(const vector_unit_3d& x)
	{
		scalar_unit::operator =(x);
		theta = x.theta;
		phi = x.phi;
		return *this;
	}

	vector_unit_3d& vector_unit_3d::operator =(vector_unit_3d&& x)
	{
		scalar_unit::operator =(std::move(x));
		theta = std::move(x.theta);
		phi = std::move(x.phi);
		return *this;
	}

	vector_unit_3d& vector_unit_3d::operator =(const scalar_unit& x)
	{
		scalar_unit::operator =(x);
		return *this;
	}

	vector_unit_3d& vector_unit_3d::operator =(scalar_unit&& x)
	{
		scalar_unit::operator =(std::move(x));
		return *this;
	}

	vector_unit_3d& vector_unit_3d::operator =(const string& init_vector_3d)
	{
		vector_unit_3d::initialize_from_string(init_vector_3d);
		return *this;
	}

	bool vector_unit_3d::operator ==(scifir::vector_unit_3d x) const
	{
		x.change_dimensions(*this);
		if(get_value() == x.get_value() and scifir::same_direction(*this,x) and has_dimensions(x))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void vector_unit_3d::point_to(direction::name x)
	{
		if (x == direction::LEFT)
		{
			theta = 270.0f;
			phi = 90.0f;
		}
		else if(x == direction::RIGHT)
		{
			theta = 90.0f;
			phi = 90.0f;
		}
		else if(x == direction::TOP)
		{
			theta = 0.0f;
			phi = 0.0f;
		}
		else if(x == direction::BOTTOM)
		{
			theta = 0.0f;
			phi = 180.0f;
		}
		else if(x == direction::LEFT_TOP)
		{
			theta = 270.0f;
			phi = 45.0f;
		}
		else if(x == direction::RIGHT_TOP)
		{
			theta = 90.0f;
			phi = 45.0f;
		}
		else if(x == direction::RIGHT_BOTTOM)
		{
			theta = 90.0f;
			phi = 135.0f;
		}
		else if(x == direction::LEFT_BOTTOM)
		{
			theta = 270.0f;
			phi = 135.0f;
		}
		else if(x == direction::FRONT)
		{
			theta = 0.0f;
			phi = 90.0f;
		}
		else if(x == direction::BACK)
		{
			theta = 180.0f;
			phi = 90.0f;
		}
		else if(x == direction::LEFT_FRONT)
		{
			theta = 315.0f;
			phi = 90.0f;
		}
		else if(x == direction::RIGHT_FRONT)
		{
			theta = 45.0f;
			phi = 90.0f;
		}
		else if(x == direction::TOP_FRONT)
		{
			theta = 0.0f;
			phi = 45.0f;
		}
		else if(x == direction::BOTTOM_FRONT)
		{
			theta = 0.0f;
			phi = 135.0f;
		}
		else if(x == direction::LEFT_BACK)
		{
			theta = 225.0f;
			phi = 90.0f;
		}
		else if(x == direction::RIGHT_BACK)
		{
			theta = 135.0f;
			phi = 90.0f;
		}
		else if(x == direction::TOP_BACK)
		{
			theta = 180.0f;
			phi = 45.0f;
		}
		else if(x == direction::BOTTOM_BACK)
		{
			theta = 180.0f;
			phi = 135.0f;
		}
		else if(x == direction::LEFT_TOP_FRONT)
		{
			theta = 315.0f;
			phi = 45.0f;
		}
		else if(x == direction::RIGHT_TOP_FRONT)
		{
			theta = 45.0f;
			phi = 45.0f;
		}
		else if(x == direction::LEFT_BOTTOM_FRONT)
		{
			theta = 315.0f;
			phi = 135.0f;
		}
		else if(x == direction::RIGHT_BOTTOM_FRONT)
		{
			theta = 45.0f;
			phi = 135.0f;
		}
		else if(x == direction::LEFT_TOP_BACK)
		{
			theta = 225.0f;
			phi = 45.0f;
		}
		else if(x == direction::RIGHT_TOP_BACK)
		{
			theta = 135.0f;
			phi = 45.0f;
		}
		else if(x == direction::LEFT_BOTTOM_BACK)
		{
			theta = 225.0f;
			phi = 135.0f;
		}
		else if(x == direction::RIGHT_BOTTOM_BACK)
		{
			theta = 135.0f;
			phi = 135.0f;
		}
	}

	void vector_unit_3d::operator +=(const vector_unit_3d& x)
	{
		if(has_dimensions(x))
		{
			float new_x = float(x_projection() + x.x_projection());
			float new_y = float(y_projection() + x.y_projection());
			float new_z = float(z_projection() + x.z_projection());
			scalar_unit::value = cartesian_3d_to_spherical_r(new_x, new_y, new_z);
			theta = angle(cartesian_3d_to_spherical_theta(new_x, new_y, new_z));
			phi = angle(cartesian_3d_to_spherical_phi(new_x, new_y, new_z));
		}
		else
		{
			cerr << "Cannot sum vectors of different dimensions" << endl;
		}
	}

	void vector_unit_3d::operator -=(vector_unit_3d x)
	{
		if(has_dimensions(x))
		{
			x.invert();
			*this += x;
		}
		else
		{
			cerr << "Cannot substract vectors of different dimensions" << endl;
		}
	}

	vector_unit_3d vector_unit_3d::operator +(const vector_unit_3d& x) const
	{
		if (has_dimensions(x))
		{
			float new_x = float(x_projection() + x.x_projection());
			float new_y = float(y_projection() + x.y_projection());
			float new_z = float(z_projection() + x.z_projection());
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

	vector_unit_3d vector_unit_3d::operator -(vector_unit_3d x) const
	{
		if (has_dimensions(x))
		{
			x.invert();
			float new_x = float(x_projection() + x.x_projection());
			float new_y = float(y_projection() + x.y_projection());
			float new_z = float(z_projection() + x.z_projection());
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
		return vector_unit_3d(float(new_value), new_dimensions, theta, phi);
	}

	vector_unit_3d vector_unit_3d::operator /(const scalar_unit& x) const
	{
		long double new_value = scalar_unit::value / x.get_value();
		vector<dimension> new_dimensions = divide_dimensions(get_dimensions(), x.get_dimensions(),new_value);
		return vector_unit_3d(float(new_value), new_dimensions, theta, phi);
	}

	vector_unit_3d vector_unit_3d::operator ^(const scalar_unit& x) const
	{
		if(x.has_empty_dimensions())
		{
			scalar_unit new_unit = scalar_unit::operator^(x);
			return vector_unit_3d(new_unit, theta, phi);
		}
		else
		{
			cerr << "Cannot power with as exponent a unit with dimensions" << endl;
			return vector_unit_3d();
		}
	}

#ifdef IS_UNIX
	string vector_unit_3d::vectorial_display(int number_of_decimals) const
	{
		ostringstream out;
		out << display(number_of_decimals) << " " << display_float(theta.get_value(),number_of_decimals) << "θ " << display_float(phi.get_value(),number_of_decimals) << "Φ";
		return out.str();
	}

	string vector_unit_3d::vectorial_base_display(int number_of_decimals) const
	{
		ostringstream out;
		out << base_display(number_of_decimals) << " " << display_float(theta.get_value(),number_of_decimals) << "θ " << display_float(phi.get_value(),number_of_decimals) << "Φ";
		return out.str();
	}

	string vector_unit_3d::vectorial_custom_display(const string& init_dimensions,int number_of_decimals) const
	{
		ostringstream out;
		out << custom_display(init_dimensions,number_of_decimals) << " " << display_float(theta.get_value(),number_of_decimals) << "θ " << display_float(phi.get_value(),number_of_decimals) << "Φ";
		return out.str();
	}

	string to_string(const vector_unit_3d& x)
	{
		return x.vectorial_display(2);
	}
#elif IS_WINDOWS
	string vector_unit_3d::vectorial_display(int number_of_decimals) const
	{
		ostringstream out;
		out << display(number_of_decimals) << " " << display_float(theta.get_value(),number_of_decimals) << "θ " << display_float(phi.get_value(),number_of_decimals) << "Φ";
		return out.str();
	}

	string vector_unit_3d::vectorial_base_display(int number_of_decimals) const
	{
		ostringstream out;
		out << base_display(number_of_decimals) << " " << display_float(theta.get_value(),number_of_decimals) << "θ " << display_float(phi.get_value(),number_of_decimals) << "Φ";
		return out.str();
	}

	string vector_unit_3d::vectorial_custom_display(const string& init_dimensions,int number_of_decimals) const
	{
		ostringstream out;
		out << custom_display(init_dimensions,number_of_decimals) << " " << display_float(theta.get_value(),number_of_decimals) << "θ " << display_float(phi.get_value(),number_of_decimals) << "Φ";
		return out.str();
	}

	string to_string(const vector_unit_3d& x)
	{
		return x.vectorial_display(2);
	}
#endif

	void vector_unit_3d::initialize_from_string(string init_vector_3d)
	{
		vector<string> values;
		boost::split(values,init_vector_3d,boost::is_any_of(" "));
		if (values.size() == 4)
		{
			scalar_unit::initialize_from_string(values[0] + " " + values[1],vector<dimension>());
			theta = angle(values[2]);
			phi = angle(values[3]);
		}
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

	vector_unit_3d sqrt_nth(const vector_unit_3d& x, int index)
	{
		scalar_unit new_value = scifir::sqrt_nth(scalar_unit(x), index);
		return vector_unit_3d(new_value, x.theta, x.phi);
	}

	scalar_unit dot_product(const vector_unit_3d& x, const vector_unit_3d& y)
	{
		long double new_value = float(x.x_projection()*y.x_projection() + x.y_projection()*y.y_projection() + x.z_projection()*y.z_projection());
		vector<dimension> new_dimensions = multiply_dimensions(x.get_dimensions(), y.get_dimensions(),new_value);
		return scalar_unit(float(new_value),new_dimensions);
	}

	vector_unit_3d cross_product(const vector_unit_3d& x,const vector_unit_3d& y)
	{
		long double new_value;
		angle new_theta;
		angle new_phi;
		if(y.theta == x.theta and y.phi == x.phi)
		{
			new_value = 0.0l;
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
		return vector_unit_3d(float(new_value), new_dimensions, new_theta, new_phi);
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
		if ((x.theta == y.theta and x.phi == y.phi) or (x.theta == (180.0f + y.theta) and x.phi == (180.0f - y.phi)))
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
		scifir::angle x_angle = angle_between(x,y);
		return (x_angle == 90.0f);
	}
}

scifir::vector_unit_3d operator *(const scifir::scalar_unit& x,const scifir::vector_unit_3d& y)
{
	long double new_value = x.get_value() * y.get_value();
	vector<scifir::dimension> new_dimensions = multiply_dimensions(x.get_dimensions(), y.get_dimensions(),new_value);
	return scifir::vector_unit_3d(float(new_value), new_dimensions, y.theta, y.phi);
}

bool operator !=(const scifir::vector_unit_3d& x, const scifir::vector_unit_3d& y)
{
	return !(x == y);
}

bool operator ==(const scifir::vector_unit_3d& x, const string& init_vector_3d)
{
	scifir::vector_unit_3d y(init_vector_3d);
	return (x == y);
}

bool operator !=(const scifir::vector_unit_3d& x, const string& init_vector_3d)
{
	return !(x == init_vector_3d);
}

bool operator ==(const string& init_vector_3d, const scifir::vector_unit_3d& y)
{
	scifir::vector_unit_3d x(init_vector_3d);
	return (x == y);
}

bool operator !=(const string& init_vector_3d, const scifir::vector_unit_3d& y)
{
	return !(init_vector_3d == y);
}

void operator +=(string& x, const scifir::vector_unit_3d& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const scifir::vector_unit_3d& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const scifir::vector_unit_3d& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const scifir::vector_unit_3d& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, scifir::vector_unit_3d& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	x = scifir::vector_unit_3d(b);
	return is;
}
