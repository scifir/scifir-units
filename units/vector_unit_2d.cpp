#include "./vector_unit_2d.hpp"

#include "../coordinates/coordinates_2d.hpp"
#include "../util/types.hpp"

#include "boost/algorithm/string.hpp"

using namespace std;

namespace scifir
{
	vector_unit_2d::vector_unit_2d() : scalar_unit(),theta()
	{}
	
	vector_unit_2d::vector_unit_2d(const vector_unit_2d& x) : scalar_unit(x),theta(x.theta)
	{}
	
	vector_unit_2d::vector_unit_2d(vector_unit_2d&& x) : scalar_unit(std::move(x)),theta(std::move(x.theta))
	{}
	
	vector_unit_2d::vector_unit_2d(float new_value,const string& new_dimensions,float new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(float new_value,const string& new_dimensions,const angle& new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}

	vector_unit_2d::vector_unit_2d(double new_value,const string& new_dimensions,float new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(double new_value,const string& new_dimensions,const angle& new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}

	vector_unit_2d::vector_unit_2d(long double new_value,const string& new_dimensions,float new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(long double new_value,const string& new_dimensions,const angle& new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}

	vector_unit_2d::vector_unit_2d(int new_value,const string& new_dimensions,float new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(int new_value,const string& new_dimensions,const angle& new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(float new_value,const vector<dimension>& new_dimensions,float new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(float new_value,const vector<dimension>& new_dimensions,const angle& new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}

	vector_unit_2d::vector_unit_2d(double new_value,const vector<dimension>& new_dimensions,float new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(double new_value,const vector<dimension>& new_dimensions,const angle& new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}

	vector_unit_2d::vector_unit_2d(long double new_value,const vector<dimension>& new_dimensions,float new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(long double new_value,const vector<dimension>& new_dimensions,const angle& new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}

	vector_unit_2d::vector_unit_2d(int new_value,const vector<dimension>& new_dimensions,float new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(int new_value,const vector<dimension>& new_dimensions,const angle& new_angle) : scalar_unit(new_value,new_dimensions),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(const scalar_unit& x,float new_angle) : scalar_unit(x),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(const scalar_unit& x,const angle& new_angle) : scalar_unit(x),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(const string& init_scalar,float new_angle) : scalar_unit(init_scalar),theta(new_angle)
	{}
	
	vector_unit_2d::vector_unit_2d(const string& init_scalar,const angle& new_angle) : scalar_unit(init_scalar),theta(new_angle)
	{}

	vector_unit_2d::vector_unit_2d(const string& init_vector_2d) : vector_unit_2d()
	{
		vector_unit_2d::initialize_from_string(init_vector_2d);
	}
	
	vector_unit_2d& vector_unit_2d::operator =(const vector_unit_2d& x)
	{
		scalar_unit::operator=(x);
		theta = x.theta;
		return *this;
	}

	vector_unit_2d& vector_unit_2d::operator =(vector_unit_2d&& x)
	{
		scalar_unit::operator=(std::move(x));
		theta = std::move(x.theta);
		return *this;
	}

	vector_unit_2d& vector_unit_2d::operator =(const scalar_unit& x)
	{
		scalar_unit::operator=(x);
		return *this;
	}

	vector_unit_2d& vector_unit_2d::operator =(scalar_unit&& x)
	{
		scalar_unit::operator=(std::move(x));
		return *this;
	}

	vector_unit_2d& vector_unit_2d::operator =(const string& init_vector_2d)
	{
		vector_unit_2d::initialize_from_string(init_vector_2d);
		return *this;
	}

	void vector_unit_2d::point_to(direction::name x)
	{
		if (x == direction::LEFT)
		{
			theta = 180.0f;
		}
		else if(x == direction::RIGHT)
		{
			theta = 0.0f;
		}
		else if(x == direction::TOP)
		{
			theta = 90.0f;
		}
		else if(x == direction::BOTTOM)
		{
			theta = 270.0f;
		}
		else if(x == direction::LEFT_TOP)
		{
			theta = 135.0f;
		}
		else if(x == direction::RIGHT_TOP)
		{
			theta = 45.0f;
		}
		else if(x == direction::RIGHT_BOTTOM)
		{
			theta = 315.0f;
		}
		else if(x == direction::LEFT_BOTTOM)
		{
			theta = 225.0f;
		}
	}

	void vector_unit_2d::operator +=(const vector_unit_2d& y)
	{
		if(has_dimensions(y))
		{
				float new_x = float(x_projection() + y.x_projection());
				float new_y = float(y_projection() + y.y_projection());
				scalar_unit::value = cartesian_2d_to_polar_p(new_x, new_y);
				theta = cartesian_2d_to_polar_theta(new_x, new_y);
		}
		else
		{
			cerr << "Cannot sum vectors of different dimensions" << endl;
		}
	}

	void vector_unit_2d::operator -=(vector_unit_2d y)
	{
		if(has_dimensions(y))
		{
			y.invert();
			*this += y;
		}
		else
		{
			cerr << "Cannot substract vectors of different dimensions" << endl;
		}
	}

	vector_unit_2d vector_unit_2d::operator +(const vector_unit_2d& y) const
	{
		if (has_dimensions(y))
		{
			float new_x = float(x_projection() + y.x_projection());
			float new_y = float(y_projection() + y.y_projection());
			float value = cartesian_2d_to_polar_p(new_x, new_y);
			angle theta = cartesian_2d_to_polar_theta(new_x, new_y);
			return vector_unit_2d(value,get_dimensions(),theta);
		}
		else
		{
			return vector_unit_2d();
		}
	}

	vector_unit_2d vector_unit_2d::operator -(vector_unit_2d y) const
	{
		if (has_dimensions(y))
		{
			y.invert();
			float new_x = float(x_projection() + y.x_projection());
			float new_y = float(y_projection() + y.y_projection());
			float value = cartesian_2d_to_polar_p(new_x, new_y);
			angle theta = cartesian_2d_to_polar_theta(new_x, new_y);
			return vector_unit_2d(value,get_dimensions(),theta);
		}
		else
		{
			return vector_unit_2d();
		}
	}

	vector_unit_2d vector_unit_2d::operator *(const scalar_unit& x) const
	{
		long double new_value = (long double)(scalar_unit::value * x.get_value());
		vector<dimension> new_dimensions = multiply_dimensions(get_dimensions(), x.get_dimensions(),new_value);
		return vector_unit_2d(new_value, new_dimensions, theta);
	}

	vector_unit_2d vector_unit_2d::operator /(const scalar_unit& x) const
	{
		long double new_value = (long double)(scalar_unit::value / x.get_value());
		vector<dimension> new_dimensions = divide_dimensions(get_dimensions(), x.get_dimensions(),new_value);
		return vector_unit_2d(new_value, new_dimensions, theta);
	}

	vector_unit_2d vector_unit_2d::operator ^(const scalar_unit& x) const
	{
		if(x.has_empty_dimensions())
		{
			scalar_unit new_unit = scalar_unit::operator^(x);
			return vector_unit_2d(new_unit, theta);
		}
		else
		{
			cerr << "Cannot power with as exponent a unit with dimensions" << endl;
			return vector_unit_2d();
		}
	}

#ifdef IS_UNIX
	string vector_unit_2d::vectorial_display(int number_of_decimals) const
	{
		ostringstream out;
		out << display(number_of_decimals) << " " << display_float(theta.get_value(),number_of_decimals) << "\U000003B8";
		return out.str();
	}

	string vector_unit_2d::vectorial_derived_display(int number_of_decimals) const
	{
		ostringstream out;
		out << derived_display(number_of_decimals) << " " << display_float(theta.get_value(),number_of_decimals) << "\U000003B8";
		return out.str();
	}

	string vector_unit_2d::vectorial_custom_display(const string& new_dimensions_str,int number_of_decimals) const
	{
		ostringstream out;
		out << custom_display(new_dimensions_str,number_of_decimals) << " " << display_float(theta.get_value(),number_of_decimals) << "\U000003B8";
		return out.str();
	}

	string to_string(const vector_unit_2d& x)
	{
		ostringstream out;
		out << x.display(2) << " " << display_float(x.theta.get_value(),2) << "\U000003B8";
		return out.str();
	}
#elif IS_WINDOWS
	string vector_unit_2d::vectorial_display(int number_of_decimals) const
	{
		ostringstream out;
		out << display(number_of_decimals) << " " << display_float(theta.get_value(),number_of_decimals) << "\U03B8";
		return out.str();
	}

	string vector_unit_2d::vectorial_derived_display(int number_of_decimals) const
	{
		ostringstream out;
		out << derived_display(number_of_decimals) << " " << display_float(theta.get_value(),number_of_decimals) << "\U03B8";
		return out.str();
	}

	string vector_unit_2d::vectorial_custom_display(const string& new_dimensions_str,int number_of_decimals) const
	{
		ostringstream out;
		out << custom_display(new_dimensions_str,number_of_decimals) << " " << display_float(theta.get_value(),number_of_decimals) << "\U03B8";
		return out.str();
	}

	string to_string(const vector_unit_2d& x)
	{
		ostringstream out;
		out << x.display(2) << " " << display_float(x.theta.get_value(),2) << "\U03B8";
		return out.str();
	}
#endif

	void vector_unit_2d::initialize_from_string(string init_vector_2d)
	{
		vector<string> values;
		boost::split(values,init_vector_2d,boost::is_any_of(" "));
		if (values.size() == 3)
		{
			scalar_unit::initialize_from_string(values[0] + " " + values[1]);
			theta = angle(values[2]);
		}
	}

	scalar_unit norm(const vector_unit_2d& x)
	{
		return scalar_unit(std::abs(x.get_value()),x.get_dimensions());
	}

	vector_unit_2d sqrt(const vector_unit_2d& x)
	{
		scalar_unit new_value = scifir::sqrt(scalar_unit(x));
		return vector_unit_2d(new_value, x.theta);
	}

	vector_unit_2d sqrt_nth(const vector_unit_2d& x, int y)
	{
		scalar_unit new_value = scifir::sqrt_nth(scalar_unit(x), y);
		return vector_unit_2d(new_value, x.theta);
	}

	scalar_unit dot_product(const vector_unit_2d& x, const vector_unit_2d& y)
	{
		long double new_value = (x.x_projection() * y.x_projection() + x.y_projection() * y.y_projection()).get_value();
		vector<dimension> new_dimensions = multiply_dimensions(x.get_dimensions(), y.get_dimensions(),new_value);
		return scalar_unit(new_value,new_dimensions);
	}

	angle angle_between(const vector_unit_2d& x,const vector_unit_2d& y)
	{
		return angle(radian_to_grade(std::atan2(float(y.y_projection() * x.x_projection() - y.x_projection() * x.y_projection()),float(y.x_projection() * x.x_projection() + y.y_projection() * x.y_projection()))));
	}

	bool same_direction(const vector_unit_2d& x, const vector_unit_2d& y)
	{
		return x.theta == y.theta;
	}

	bool parallel(const vector_unit_2d& x, const vector_unit_2d& y)
	{
		return scifir::parallel(x.theta,y.theta);
	}

	bool orthogonal(const vector_unit_2d& x,const vector_unit_2d& y)
	{
		return scifir::orthogonal(x.theta,y.theta);
	}
}

vector_unit_2d operator *(const scifir::scalar_unit& x,const scifir::vector_unit_2d& y)
{
	long double new_value = x.get_value() * y.get_value();
	vector<dimension> new_dimensions = multiply_dimensions(x.get_dimensions(), y.get_dimensions(),new_value);
	return vector_unit_2d(float(new_value), new_dimensions, y.theta);
}

bool operator ==(const vector_unit_2d& x, vector_unit_2d y)
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
 
