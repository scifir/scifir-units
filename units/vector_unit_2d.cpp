#include "units/vector_unit_2d.hpp"

#include "coordinates/coordinates_2d.hpp"

#include "boost/algorithm/string.hpp"

using namespace std;

namespace msci
{
	vector_unit_2d::vector_unit_2d() : scalar_unit(),theta()
	{}
	
	vector_unit_2d::vector_unit_2d(const vector_unit_2d& x) : scalar_unit(x),theta(x.theta)
	{}
	
	vector_unit_2d::vector_unit_2d(vector_unit_2d&& x) : scalar_unit(x),theta(x.theta)
	{}
	
	vector_unit_2d::vector_unit_2d(float new_value,const string& new_dimensions,float new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(float new_value,const string& new_dimensions,const angle& new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(float new_value,const vector<dimension>& new_dimensions,float new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(float new_value,const vector<dimension>& new_dimensions,const angle& new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(const scalar_unit& x,float new_angle) : scalar_unit(x),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(const scalar_unit& x,const angle& new_angle) : scalar_unit(x),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(scalar_unit&& x,float new_angle) : scalar_unit(x),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(scalar_unit&& x,const angle& new_angle) : scalar_unit(x),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(const string& init_scalar,float new_angle) : scalar_unit(init_scalar),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(const string& init_scalar,const angle& new_angle) : scalar_unit(init_scalar),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(const string& init_vector_2d)
	{
		vector<string> values;
		boost::split(values,init_vector_2d,boost::is_any_of(" "));
		set_from_string(values[0]);
		theta = angle(values[1]);
	}
	
	vector_unit_2d& vector_unit_2d::operator =(const vector_unit_2d& x)
	{
		scalar_unit::operator=(x);
		theta = x.theta;
		return *this;
	}

	vector_unit_2d& vector_unit_2d::operator =(vector_unit_2d&& x)
	{
		scalar_unit::operator=(move(x));
		theta = move(x.theta);
		return *this;
	}

	vector_unit_2d& vector_unit_2d::operator =(const scalar_unit& x)
	{
		scalar_unit::operator=(x);
		return *this;
	}

	vector_unit_2d& vector_unit_2d::operator =(scalar_unit&& x)
	{
		scalar_unit::operator=(move(x));
		return *this;
	}
	
	void vector_unit_2d::operator +=(const vector_unit_2d& y)
	{
		if(has_dimensions(y.get_derived_dimensions()))
		{
				float new_x = x_projection() + y.x_projection();
				float new_y = y_projection() + y.y_projection();
				scalar_unit::value = cartesian_2d_to_polar_r(new_x, new_y);
				theta = cartesian_2d_to_polar_theta(new_x, new_y);
		}
		else
		{
			cerr << "Cannot sum vectors of different dimensions";
		}
	}

	void vector_unit_2d::operator -=(const vector_unit_2d& y)
	{
		if(has_dimensions(y.get_derived_dimensions()))
		{
			vector_unit_2d z = vector_unit_2d(y);
			z.invert();
			*this += z;
		}
		else
		{
			cerr << "Cannot substract vectors of different dimensions";
		}
	}

	vector_unit_2d vector_unit_2d::operator +(const vector_unit_2d& y) const
	{
		vector_unit_2d z = *this;
		z += y;
		return z;
	}

	vector_unit_2d vector_unit_2d::operator -(const vector_unit_2d& y) const
	{
		vector_unit_2d z = *this;
		z -= y;
		return z;
	}

	vector_unit_2d vector_unit_2d::operator *(const scalar_unit& x) const
	{
		float new_value = scalar_unit::value * x.get_value();
		vector<dimension> new_dimensions = multiply_dimensions(get_dimensions(), x.get_dimensions());
		return vector_unit_2d(new_value, new_dimensions, theta);
	}

	vector_unit_2d vector_unit_2d::operator /(const scalar_unit& x) const
	{
		float new_value = scalar_unit::value / x.get_value();
		vector<dimension> new_dimensions = divide_dimensions(get_dimensions(), x.get_dimensions());
		return vector_unit_2d(new_value, new_dimensions, theta);
	}

	vector_unit_2d vector_unit_2d::operator ^(const scalar_unit& x) const
	{
		if(x.has_empty_dimensions())
		{
			scalar_unit new_unit = *this ^ x;
			return vector_unit_2d(new_unit, theta);
		}
		else
		{
			cerr << "Cannot power with as exponent a unit with dimensions";
			return vector_unit_2d();
		}
	}
	
	string to_string(const vector_unit_2d& x)
	{
		ostringstream out;
		out << x.get_value() << " " << x.display_dimensions() << " " << x.theta;
		return out.str();
	}

	scalar_unit norm(const vector_unit_2d& x)
	{
		return scalar_unit(std::abs(x.get_value()),x.get_dimensions());
	}

	vector_unit_2d sqrt(const vector_unit_2d& x)
	{
		scalar_unit new_value = msci::sqrt(scalar_unit(x));
		return vector_unit_2d(new_value, x.theta);
	}

	vector_unit_2d sqrt_nth(const vector_unit_2d& x, int y)
	{
		scalar_unit new_value = msci::sqrt_nth(scalar_unit(x), y);
		return vector_unit_2d(new_value, x.theta);
	}

	scalar_unit dot_product(const vector_unit_2d& x, const vector_unit_2d& y)
	{
		float new_value = x.x_projection() * y.x_projection() + x.y_projection() * y.y_projection();
		vector<dimension> new_dimensions = multiply_dimensions(x.get_dimensions(), y.get_dimensions());
		return scalar_unit(new_value,new_dimensions);
	}

	angle angle_between(const vector_unit_2d& x,const vector_unit_2d& y)
	{
		return angle(std::atan2(y.y_projection() * x.x_projection() - y.x_projection() * x.y_projection(),y.x_projection() * x.x_projection() + y.y_projection() * x.y_projection()));
	}

	bool same_direction(const vector_unit_2d& x, const vector_unit_2d& y)
	{
		return x.theta == y.theta;
	}

	bool parallel(const vector_unit_2d& x, const vector_unit_2d& y)
	{
		return msci::parallel(x.theta,y.theta);
	}

	bool orthogonal(const vector_unit_2d& x,const vector_unit_2d& y)
	{
		return msci::orthogonal(x.theta,y.theta);
	}
}

bool operator ==(const vector_unit_2d& x, vector_unit_2d y)
{
	y.set_same_prefix(x);
	if(x.get_value() == y.get_value() and msci::same_direction(x,y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const vector_unit_2d& x, const vector_unit_2d& y)
{
	return !(x == y);
}

bool operator ==(const vector_unit_2d& x, const string& y)
{
	vector_unit_2d y_vector = vector_unit_2d(y);
	return (x == y_vector);
}

bool operator !=(const vector_unit_2d& x, const string& y)
{
	return !(x == y);
}

bool operator ==(const string& x, const vector_unit_2d& y)
{
	vector_unit_2d x_vector = vector_unit_2d(x);
	return (x_vector == y);
}

bool operator !=(const string& x, const vector_unit_2d& y)
{
	return !(x == y);
}

void operator +=(string& x, const vector_unit_2d& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const vector_unit_2d& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const vector_unit_2d& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const vector_unit_2d& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, vector_unit_2d& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	vector_unit_2d c(b);
	x = c;
	return is;
}
 
