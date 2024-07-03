#include "./vector_unit_nd.hpp"

#include "../coordinates/coordinates_2d.hpp"
#include "../coordinates/coordinates_3d.hpp"

using namespace std;

namespace scifir
{
	vector_unit_nd::vector_unit_nd() : scalar_unit(),angles()
	{}

	vector_unit_nd::vector_unit_nd(const vector_unit_nd& x) : scalar_unit(x),angles(x.angles)
	{}

	vector_unit_nd::vector_unit_nd(vector_unit_nd&& x) : scalar_unit(std::move(x)),angles(std::move(x.angles))
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

	vector_unit_nd::vector_unit_nd(double new_value,const string& init_dimensions) : scalar_unit(new_value,init_dimensions),angles()
	{}

	vector_unit_nd::vector_unit_nd(double new_value,const string& init_dimensions,const vector<float>& new_angles) : scalar_unit(new_value,init_dimensions),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(angle(x_angle));
		}
	}

	vector_unit_nd::vector_unit_nd(double new_value,const string& init_dimensions,const vector<angle>& new_angles) : scalar_unit(new_value,init_dimensions),angles(new_angles)
	{}

	vector_unit_nd::vector_unit_nd(long double new_value,const string& init_dimensions) : scalar_unit(new_value,init_dimensions),angles()
	{}

	vector_unit_nd::vector_unit_nd(long double new_value,const string& init_dimensions,const vector<float>& new_angles) : scalar_unit(new_value,init_dimensions),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(angle(x_angle));
		}
	}

	vector_unit_nd::vector_unit_nd(long double new_value,const string& init_dimensions,const vector<angle>& new_angles) : scalar_unit(new_value,init_dimensions),angles(new_angles)
	{}

	vector_unit_nd::vector_unit_nd(int new_value,const string& init_dimensions) : scalar_unit(new_value,init_dimensions),angles()
	{}

	vector_unit_nd::vector_unit_nd(int new_value,const string& init_dimensions,const vector<float>& new_angles) : scalar_unit(new_value,init_dimensions),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(angle(x_angle));
		}
	}

	vector_unit_nd::vector_unit_nd(int new_value,const string& init_dimensions,const vector<angle>& new_angles) : scalar_unit(new_value,init_dimensions),angles(new_angles)
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

	vector_unit_nd::vector_unit_nd(double new_value,const vector<dimension>& new_dimensions) : scalar_unit(new_value,new_dimensions),angles()
	{}

	vector_unit_nd::vector_unit_nd(double new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles) : scalar_unit(new_value,new_dimensions),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(angle(x_angle));
		}
	}

	vector_unit_nd::vector_unit_nd(double new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles) : scalar_unit(new_value,new_dimensions),angles(new_angles)
	{}

	vector_unit_nd::vector_unit_nd(long double new_value,const vector<dimension>& new_dimensions) : scalar_unit(new_value,new_dimensions),angles()
	{}

	vector_unit_nd::vector_unit_nd(long double new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles) : scalar_unit(new_value,new_dimensions),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(angle(x_angle));
		}
	}

	vector_unit_nd::vector_unit_nd(long double new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles) : scalar_unit(new_value,new_dimensions),angles(new_angles)
	{}

	vector_unit_nd::vector_unit_nd(int new_value,const vector<dimension>& new_dimensions) : scalar_unit(new_value,new_dimensions),angles()
	{}

	vector_unit_nd::vector_unit_nd(int new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles) : scalar_unit(new_value,new_dimensions),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(angle(x_angle));
		}
	}

	vector_unit_nd::vector_unit_nd(int new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles) : scalar_unit(new_value,new_dimensions),angles(new_angles)
	{}

	vector_unit_nd::vector_unit_nd(const scalar_unit& x) : scalar_unit(x),angles()
	{}

	vector_unit_nd::vector_unit_nd(const scalar_unit& x,const vector<float>& new_angles) : scalar_unit(x),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(angle(x_angle));
		}
	}

	vector_unit_nd::vector_unit_nd(const scalar_unit& x,const vector<angle>& new_angles) : scalar_unit(x),angles(new_angles)
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
		vector_unit_nd::initialize_from_string(init_vector_nd);
	}

	vector_unit_nd& vector_unit_nd::operator =(const vector_unit_nd& x)
	{
		scalar_unit::operator=(x);
		angles = x.angles;
		return *this;
	}

	vector_unit_nd& vector_unit_nd::operator =(vector_unit_nd&& x)
	{
		scalar_unit::operator=(std::move(x));
		angles = std::move(x.angles);
		return *this;
	}

	vector_unit_nd& vector_unit_nd::operator =(const scalar_unit& x)
	{
		scalar_unit::operator=(x);
		return *this;
	}

	vector_unit_nd& vector_unit_nd::operator =(scalar_unit&& x)
	{
		scalar_unit::operator=(std::move(x));
		return *this;
	}

	vector_unit_nd& vector_unit_nd::operator =(const string& init_vector_nd)
	{
		vector_unit_nd::initialize_from_string(init_vector_nd);
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
				angles[0] = 180.0f;
			}
			else if(x == direction::RIGHT)
			{
				angles[0] = 0.0f;
			}
			else if(x == direction::TOP)
			{
				angles[0] = 90.0f;
			}
			else if(x == direction::BOTTOM)
			{
				angles[0] = 270.0f;
			}
			else if(x == direction::LEFT_TOP)
			{
				angles[0] = 135.0f;
			}
			else if(x == direction::RIGHT_TOP)
			{
				angles[0] = 45.0f;
			}
			else if(x == direction::RIGHT_BOTTOM)
			{
				angles[0] = 315.0f;
			}
			else if(x == direction::LEFT_BOTTOM)
			{
				angles[0] = 225.0f;
			}
		}
		else if (is_nd(3))
		{
			if (x == direction::LEFT)
			{
				angles[0] = 270.0f;
				angles[1] = 90.0f;
			}
			else if(x == direction::RIGHT)
			{
				angles[0] = 90.0f;
				angles[1] = 90.0f;
			}
			else if(x == direction::TOP)
			{
				angles[0] = 0.0f;
				angles[1] = 0.0f;
			}
			else if(x == direction::BOTTOM)
			{
				angles[0] = 0.0f;
				angles[1] = 180.0f;
			}
			else if(x == direction::LEFT_TOP)
			{
				angles[0] = 270.0f;
				angles[1] = 45.0f;
			}
			else if(x == direction::RIGHT_TOP)
			{
				angles[0] = 90.0f;
				angles[1] = 45.0f;
			}
			else if(x == direction::RIGHT_BOTTOM)
			{
				angles[0] = 90.0f;
				angles[1] = 135.0f;
			}
			else if(x == direction::LEFT_BOTTOM)
			{
				angles[0] = 270.0f;
				angles[1] = 135.0f;
			}
			else if(x == direction::FRONT)
			{
				angles[0] = 0.0f;
				angles[1] = 90.0f;
			}
			else if(x == direction::BACK)
			{
				angles[0] = 180.0f;
				angles[1] = 90.0f;
			}
			else if(x == direction::LEFT_FRONT)
			{
				angles[0] = 315.0f;
				angles[1] = 90.0f;
			}
			else if(x == direction::RIGHT_FRONT)
			{
				angles[0] = 45.0f;
				angles[1] = 90.0f;
			}
			else if(x == direction::TOP_FRONT)
			{
				angles[0] = 0.0f;
				angles[1] = 45.0f;
			}
			else if(x == direction::BOTTOM_FRONT)
			{
				angles[0] = 0.0f;
				angles[1] = 135.0f;
			}
			else if(x == direction::LEFT_BACK)
			{
				angles[0] = 225.0f;
				angles[1] = 90.0f;
			}
			else if(x == direction::RIGHT_BACK)
			{
				angles[0] = 135.0f;
				angles[1] = 90.0f;
			}
			else if(x == direction::TOP_BACK)
			{
				angles[0] = 180.0f;
				angles[1] = 45.0f;
			}
			else if(x == direction::BOTTOM_BACK)
			{
				angles[0] = 180.0f;
				angles[1] = 135.0f;
			}
			else if(x == direction::LEFT_TOP_FRONT)
			{
				angles[0] = 315.0f;
				angles[1] = 45.0f;
			}
			else if(x == direction::RIGHT_TOP_FRONT)
			{
				angles[0] = 45.0f;
				angles[1] = 45.0f;
			}
			else if(x == direction::LEFT_BOTTOM_FRONT)
			{
				angles[0] = 315.0f;
				angles[1] = 135.0f;
			}
			else if(x == direction::RIGHT_BOTTOM_FRONT)
			{
				angles[0] = 45.0f;
				angles[1] = 135.0f;
			}
			else if(x == direction::LEFT_TOP_BACK)
			{
				angles[0] = 225.0f;
				angles[1] = 45.0f;
			}
			else if(x == direction::RIGHT_TOP_BACK)
			{
				angles[0] = 135.0f;
				angles[1] = 45.0f;
			}
			else if(x == direction::LEFT_BOTTOM_BACK)
			{
				angles[0] = 225.0f;
				angles[1] = 135.0f;
			}
			else if(x == direction::RIGHT_BOTTOM_BACK)
			{
				angles[0] = 135.0f;
				angles[1] = 135.0f;
			}
		}
	}

	void vector_unit_nd::operator +=(const vector_unit_nd& x)
	{
		if(has_dimensions(x) and get_nd() == x.get_nd())
		{
			if(is_nd(1))
			{
				scalar_unit::value += x.get_value();
			}
			else if(is_nd(2))
			{
				float new_x = float(x_projection() + x.x_projection());
				float new_y = float(y_projection() + x.y_projection());
				scalar_unit::value = cartesian_2d_to_polar_p(new_x, new_y);
				angles[0] = cartesian_2d_to_polar_theta(new_x, new_y);
			}
			else if(is_nd(3))
			{
				float new_x = float(x_projection() + x.x_projection());
				float new_y = float(y_projection() + x.y_projection());
				float new_z = float(z_projection() + x.z_projection());
				scalar_unit::value = cartesian_3d_to_spherical_r(new_x, new_y, new_z);
				angles[0] = cartesian_3d_to_spherical_theta(new_x, new_y, new_z);
				angles[1] = cartesian_3d_to_spherical_phi(new_x, new_y, new_z);
			}
		}
		else
		{
			cerr << "Cannot sum vectors of different dimensions" << endl;
		}
	}

	void vector_unit_nd::operator -=(vector_unit_nd x)
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

	vector_unit_nd vector_unit_nd::operator +(const vector_unit_nd& x) const
	{
		if(has_dimensions(x))
		{
			if(is_nd(1))
			{
				float new_value = scalar_unit::value + x.get_value();
				return vector_unit_nd(new_value,get_dimensions());
			}
			else if(is_nd(2))
			{
				float new_x = float(x_projection() + x.x_projection());
				float new_y = float(y_projection() + x.y_projection());
				float new_value = cartesian_2d_to_polar_p(new_x, new_y);
				vector<angle> new_angles = vector<angle>();
				new_angles.push_back(cartesian_2d_to_polar_theta(new_x, new_y));
				return vector_unit_nd(new_value,get_dimensions(),new_angles);
			}
			else if(is_nd(3))
			{
				float new_x = float(x_projection() + x.x_projection());
				float new_y = float(y_projection() + x.y_projection());
				float new_z = float(z_projection() + x.z_projection());
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
			cerr << "Cannot sum vectors of different dimensions" << endl;
			return vector_unit_nd();
		}
	}

	vector_unit_nd vector_unit_nd::operator -(vector_unit_nd x) const
	{
		if(has_dimensions(x))
		{
			if(is_nd(1))
			{
				float new_value = scalar_unit::value - x.get_value();
				return vector_unit_nd(new_value,get_dimensions());
			}
			else if(is_nd(2))
			{
				x.invert();
				float new_x = float(x_projection() + x.x_projection());
				float new_y = float(y_projection() + x.y_projection());
				float new_value = cartesian_2d_to_polar_p(new_x, new_y);
				vector<angle> new_angles = vector<angle>();
				new_angles.push_back(cartesian_2d_to_polar_theta(new_x, new_y));
				return vector_unit_nd(new_value,get_dimensions(),new_angles);
			}
			else if(is_nd(3))
			{
				x.invert();
				float new_x = float(x_projection() + x.x_projection());
				float new_y = float(y_projection() + x.y_projection());
				float new_z = float(z_projection() + x.z_projection());
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
			cerr << "Cannot sum vectors of different dimensions" << endl;
			return vector_unit_nd();
		}
	}

	vector_unit_nd vector_unit_nd::operator *(const scalar_unit& x) const
	{
		long double new_value = scalar_unit::value * x.get_value();
		vector<dimension> new_dimensions = multiply_dimensions(get_dimensions(), x.get_dimensions(),new_value);
		if(is_nd(1))
		{
			return vector_unit_nd(float(new_value), new_dimensions);
		}
		else if(is_nd(2))
		{
			return vector_unit_nd(float(new_value), new_dimensions, {angles[0]});
		}
		else if(is_nd(3))
		{
			return vector_unit_nd(float(new_value), new_dimensions, {angles[0], angles[1]});
		}
		else
		{
			return vector_unit_nd(float(new_value), new_dimensions, angles);
		}
	}

	vector_unit_nd vector_unit_nd::operator /(const scalar_unit& x) const
	{
		long double new_value = scalar_unit::value / x.get_value();
		vector<dimension> new_dimensions = divide_dimensions(get_dimensions(), x.get_dimensions(),new_value);
		if(is_nd(1))
		{
			return vector_unit_nd(float(new_value), new_dimensions);
		}
		else if(is_nd(2))
		{
			return vector_unit_nd(float(new_value), new_dimensions, {angles[0]});
		}
		else if(is_nd(3))
		{
			return vector_unit_nd(float(new_value), new_dimensions, {angles[0], angles[1]});
		}
		else
		{
			return vector_unit_nd(float(new_value), new_dimensions, angles);
		}
	}

	vector_unit_nd vector_unit_nd::operator ^(const scalar_unit& x) const
	{
		if(x.has_empty_dimensions())
		{
			scalar_unit new_unit = scalar_unit::operator^(x);
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
		else
		{
			cerr << "Cannot power with as exponent a unit with dimensions" << endl;
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
			return scalar_unit(scalar_unit::value * scifir::cos(angles[0]),get_dimensions());
		}
		else if (is_nd(3))
		{
			return scalar_unit(scalar_unit::value * scifir::cos(angles[0]) * scifir::sin(angles[1]),get_dimensions());
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
			return scalar_unit(scalar_unit::value * scifir::sin(angles[0]),get_dimensions());
		}
		else if (is_nd(3))
		{
			return scalar_unit(scalar_unit::value * scifir::sin(angles[0]) * scifir::sin(angles[1]),get_dimensions());
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
			return scalar_unit(scalar_unit::value * scifir::cos(angles[1]),get_dimensions());
		}
		else
		{
			return scalar_unit();
		}
	}

	void vector_unit_nd::invert()
	{
		if (is_nd(2))
		{
			angles[0].invert();
		}
		else if (is_nd(3))
		{
			angles[0].invert();
			angles[1] = 180.0f - angles[1];
		}
	}

	string vector_unit_nd::vectorial_display(int number_of_decimals) const
	{
		ostringstream out;
		out << display(number_of_decimals);
		for (const angle& x_angle : angles)
		{
			out << " " << x_angle.display(number_of_decimals);
		}
		return out.str();
	}

	string vector_unit_nd::vectorial_derived_display(int number_of_decimals) const
	{
		ostringstream out;
		out << derived_display(number_of_decimals);
		for (const angle& x_angle : angles)
		{
			out << " " << x_angle.display(number_of_decimals);
		}
		return out.str();
	}

	string vector_unit_nd::vectorial_custom_display(const string& init_dimensions,int number_of_decimals) const
	{
		ostringstream out;
		out << custom_display(init_dimensions,number_of_decimals);
		for (const angle& x_angle : angles)
		{
			out << " " << x_angle.display(number_of_decimals);
		}
		return out.str();
	}

	void vector_unit_nd::initialize_from_string(string init_vector_nd)
	{
		vector<string> values;
		boost::split(values,init_vector_nd,boost::is_any_of(" "));
		scalar_unit::initialize_from_string(values[0] + " " + values[1]);
		if (values.size() > 2)
		{
			angles.clear();
			for (unsigned int i = 2; i < values.size(); i++)
			{
				angles.push_back(angle(values[i]));
			}
		}
	}

	string to_string(const vector_unit_nd& x)
	{
		ostringstream out;
		out << x.display(2);
		for (const angle& x_angle : x.angles)
		{
			out << " " << x_angle.display(2);
		}
		return out.str();
	}

	scalar_unit norm(const vector_unit_nd& x)
	{
		return scalar_unit(std::abs(x.get_value()),x.get_dimensions());
	}

	vector_unit_nd sqrt(const vector_unit_nd& x)
	{
		scalar_unit new_value = scifir::sqrt(scalar_unit(x));
		return vector_unit_nd(new_value, x.angles);
	}

	vector_unit_nd sqrt_nth(const vector_unit_nd& x, int index)
	{
		scalar_unit new_value = scifir::sqrt_nth(scalar_unit(x), index);
		return vector_unit_nd(new_value, x.angles);
	}

	scalar_unit dot_product(const vector_unit_nd& x, const vector_unit_nd& y)
	{
		long double new_value = float(x.x_projection()*y.x_projection() + x.y_projection()*y.y_projection() + x.z_projection()*y.z_projection());
		vector<dimension> new_dimensions = multiply_dimensions(x.get_dimensions(), y.get_dimensions(),new_value);
		return scalar_unit(float(new_value),new_dimensions);
	}

	vector_unit_nd cross_product(const vector_unit_nd& x,const vector_unit_nd& y)
	{
		if(x.is_nd(3) and y.is_nd(3))
		{
			long double new_value;
			angle new_theta;
			angle new_phi;
			if(y.angles[0] == x.angles[0] and y.angles[1] == x.angles[1])
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
			scalar_unit new_unit = scalar_unit(float(new_value), new_dimensions);
			vector<angle> angles;
			angles.push_back(new_theta);
			angles.push_back(new_phi);
			return vector_unit_nd(new_unit, angles);
		}
		else
		{
			return vector_unit_nd();
		}
	}

	angle angle_between(const vector_unit_nd& x,const vector_unit_nd& y)
	{
		return scifir::acos(float(dot_product(x,y)/(norm(x) * norm(y))));
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
		if (same_nd(x,y))
		{
			if (x.get_nd() == 1)
			{
				return true;
			}
			else if (x.get_nd() == 2)
			{
				return scifir::parallel(x.angles[0],y.angles[0]);
			}
			else if (x.get_nd() == 3)
			{
				if ((x.angles[0] == y.angles[0] and x.angles[1] == y.angles[1]) or (x.angles[0] == (180.0f + y.angles[0]) and x.angles[1] == (180.0f - y.angles[1])))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		return false;
	}

	bool orthogonal(const vector_unit_nd& x,const vector_unit_nd& y)
	{
		if (same_nd(x,y))
		{
			if (x.get_nd() == 1)
			{
				return false;
			}
			else if (x.get_nd() == 2)
			{
				return scifir::orthogonal(x.angles[0],y.angles[0]);
			}
			else if (x.get_nd() == 3)
			{
				scifir::angle x_angle = angle_between(x,y);
				return (x_angle == 90.0f);
			}
		}
		return false;
	}
}

scifir::vector_unit_nd operator *(const scifir::scalar_unit& x,const scifir::vector_unit_nd& y)
{
	long double new_value = y.get_value() * x.get_value();
	vector<scifir::dimension> new_dimensions = multiply_dimensions(y.get_dimensions(), x.get_dimensions(),new_value);
	if(y.is_nd(1))
	{
		return scifir::vector_unit_nd(float(new_value), new_dimensions);
	}
	else if(y.is_nd(2))
	{
		return scifir::vector_unit_nd(float(new_value), new_dimensions, {y.angles[0]});
	}
	else if(y.is_nd(3))
	{
		return scifir::vector_unit_nd(float(new_value), new_dimensions, {y.angles[0], y.angles[1]});
	}
	else
	{
		return scifir::vector_unit_nd(float(new_value), new_dimensions, y.angles);
	}
}

bool operator ==(const scifir::vector_unit_nd& x, scifir::vector_unit_nd y)
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

bool operator !=(const scifir::vector_unit_nd& x, const scifir::vector_unit_nd& y)
{
	return !(x == y);
}

bool operator ==(const scifir::vector_unit_nd& x, const string& init_vector_nd)
{
	scifir::vector_unit_nd y(init_vector_nd);
	return (x == y);
}

bool operator !=(const scifir::vector_unit_nd& x, const string& init_vector_nd)
{
	return !(x == init_vector_nd);
}

bool operator ==(const string& init_vector_nd, const scifir::vector_unit_nd& x)
{
	scifir::vector_unit_nd y(init_vector_nd);
	return (y == x);
}

bool operator !=(const string& init_vector_nd, const scifir::vector_unit_nd& x)
{
	return !(init_vector_nd == x);
}

void operator +=(string& x, const scifir::vector_unit_nd& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const scifir::vector_unit_nd& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const scifir::vector_unit_nd& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const scifir::vector_unit_nd& x)
{
	ostringstream angles_text;
	if (!x.is_nd(1))
	{
		for(const auto& x_angle : x.angles)
		{
			angles_text << " ";
			angles_text << x_angle;
		}
	}
	return os << x.get_value() << " " << x.display_dimensions() << angles_text.str();
}

istream& operator >>(istream& is, scifir::vector_unit_nd& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	x = scifir::vector_unit_nd(b);
	return is;
}
 
