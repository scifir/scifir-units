#include "coordinates/coordinates_nd.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;

namespace msci
{
	coordinates_nd::coordinates_nd() : r(),angles()
	{}
	
	coordinates_nd::coordinates_nd(const coordinates_nd& x) : r(x.r),angles(x.angles)
	{}
	
	coordinates_nd::coordinates_nd(coordinates_nd&& x) : r(move(x.r)),angles(move(x.angles))
	{}
	
	coordinates_nd::coordinates_nd(float new_value,const string& init_dimensions) : r(new_value,init_dimensions),angles()
	{}
	
	coordinates_nd::coordinates_nd(float new_value,const string& init_dimensions,const vector<float>& new_angles) : r(new_value,init_dimensions),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(msci::angle(x_angle));
		}
	}
	
	coordinates_nd::coordinates_nd(float new_value,const string& init_dimensions,const vector<msci::angle>& new_angles) : r(new_value,init_dimensions),angles(new_angles)
	{}
	
	coordinates_nd::coordinates_nd(const length& new_r) : r(new_r),angles()
	{}
	
	coordinates_nd::coordinates_nd(const length& new_r,const vector<float>& new_angles) : r(new_r),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(msci::angle(x_angle));
		}
	}
	
	coordinates_nd::coordinates_nd(const length& new_r,const vector<msci::angle>& new_angles) : r(new_r),angles(new_angles)
	{}
	
	coordinates_nd::coordinates_nd(length&& new_r) : r(new_r),angles()
	{}
	
	coordinates_nd::coordinates_nd(length&& new_r,const vector<float>& new_angles) : r(new_r),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(msci::angle(x_angle));
		}
	}
	
	coordinates_nd::coordinates_nd(length&& new_r,const vector<msci::angle>& new_angles) : r(new_r),angles(new_angles)
	{}
	
	coordinates_nd::coordinates_nd(const string& init_scalar,const vector<float>& new_angles) : r(init_scalar),angles()
	{
		for(const float& x_angle : new_angles)
		{
			angles.push_back(msci::angle(x_angle));
		}
	}
	
	coordinates_nd::coordinates_nd(const string& init_scalar,const vector<msci::angle>& new_angles) : r(init_scalar),angles(new_angles)
	{}
	
	coordinates_nd::coordinates_nd(const string& init_coordinates_nd)
	{}

	length coordinates_nd::n_projection(int i) const
	{
		if(i == 1)
		{
			return x_projection();
		}
		else if(i == 2)
		{
			return y_projection();
		}
		else if(i == 3)
		{
			return z_projection();
		}
		return length();
	}

	bool coordinates_nd::is_nd(int i) const
	{
		return (angles.size() == (i - 1));
	}

	int coordinates_nd::get_nd() const
	{
		return angles.size() + 1;
	}

	length coordinates_nd::x_projection() const
	{
		if (is_nd(1))
		{
			return r;
		}
		else if (is_nd(2))
		{
			return r * msci::cos(angles[0]);
		}
		else if (is_nd(3))
		{
			return r * msci::cos(angles[0]) * msci::sin(angles[1]);
		}
		else
		{
			return length();
		}
	}

	length coordinates_nd::y_projection() const
	{
		if (is_nd(1))
		{
			return length();
		}
		else if (is_nd(2))
		{
			return r * msci::sin(angles[0]);
		}
		else if (is_nd(3))
		{
			return r * msci::sin(angles[0]) * msci::sin(angles[1]);
		}
		else
		{
			return length();
		}
	}

	length coordinates_nd::z_projection() const
	{
		if (is_nd(1))
		{
			return length();
		}
		else if (is_nd(2))
		{
			return length();
		}
		else if (is_nd(3))
		{
			return r * msci::cos(angles[1]);
		}
		else
		{
			return length();
		}
	}

	void coordinates_nd::invert()
	{
		for(msci::angle& x_angle : angles)
		{
			x_angle.invert();
		}
	}

	void coordinates_nd::convert_cartesian_3d(const length& x,const length& y,const length& z)
	{
		r = msci::sqrt(msci::pow(x,2) + msci::pow(y,2) + msci::pow(z,2));
		angles.empty();
		angles[0] = cartesian_3d_to_spherical_theta(float(x),float(y),float(z));
		angles[1] = cartesian_3d_to_spherical_phi(float(x),float(y),float(z));
	}

	void coordinates_nd::convert_cylindrical(const length& x,const msci::angle& y,const length& z)
	{
		r = length(cylindrical_to_spherical_r(float(x),y,float(z)),"m");
		angles.empty();
		angles[0] = cylindrical_to_spherical_theta(float(x),y,float(z));
		angles[1] = cylindrical_to_spherical_phi(float(x),y,float(z));
	}
}
