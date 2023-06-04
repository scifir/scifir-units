#include "topology/point_nd.hpp"

#include "coordinates/coordinates_nd.hpp"
#include "predefined_units/kinematics_units.hpp"

#include "boost/algorithm/string.hpp"

namespace msci
{
	point_nd::point_nd() : values()
	{}
	
	point_nd::point_nd(const point_nd& x) : values(x.values)
	{}
	
	point_nd::point_nd(point_nd&& x) : values(std::move(x.values))
	{}
	
	point_nd::point_nd(const vector<length>& new_values) : values(new_values)
	{}
	
	point_nd::point_nd(const length& new_x) : values()
	{
		values[0] = new_x;
	}
	
	point_nd::point_nd(const length& new_x,const length& new_y) : values()
	{
		values[0] = new_x;
		values[1] = new_y;
	}
	
	point_nd::point_nd(const length& new_p,const angle& new_theta) : values()
	{
		set_position(new_p,new_theta);
	}
	
	point_nd::point_nd(const length& new_x,const length& new_y,const length& new_z) : values()
	{
		values[0] = new_x;
		values[1] = new_y;
		values[2] = new_z;
	}
	
	point_nd::point_nd(const length& new_p,const angle& new_theta,length new_z) : values()
	{
		set_position(new_p,new_theta,new_z);
	}
	
	point_nd::point_nd(const length& new_r,const angle& new_theta,const angle& new_phi) : values()
	{
		set_position(new_r,new_theta,new_phi);
	}
	
	point_nd::point_nd(const angle& new_latitude,const angle& new_longitude,const length& new_altitude) : values()
	{
		set_position(new_latitude,new_longitude,new_altitude);
	}
	
	point_nd::point_nd(const coordinates_nd& new_coordinates) : values(new_coordinates.values)
	{}
	
	point_nd::point_nd(string init_point_nd) : values()
	{
		vector<string> init_values;
		if (init_point_nd.front() == '(')
		{
			init_point_nd.erase(0,1);
		}
		if (init_point_nd.back() == ')')
		{
			init_point_nd.erase(init_point_nd.size()-1,1);
		}
		boost::split(init_values,init_point_nd,boost::is_any_of(","));
		for (const string& x_value : init_values)
		{
			values.push_back(length(x_value));
		}
	}

	point_nd& point_nd::operator=(const point_nd& x_point)
	{
		values = x_point.values;
		return *this;
	}
	
	point_nd& point_nd::operator=(point_nd&& x_point)
	{
		values = std::move(x_point.values);
		return *this;
	}
	
	point_nd& point_nd::operator=(const coordinates_nd& x_coordinates)
	{
		values = x_coordinates.values;
		return *this;
	}
	
	bool point_nd::is_nd(int i) const
	{
		return values.size() == (i - 1);
	}
			
	int point_nd::get_nd() const
	{
		return (values.size() + 1);
	}
	
	void point_nd::set_position(const length& new_x)
	{
		values.empty();
		values[0] = new_x;
	}
	
	void point_nd::set_position(const length& new_x,const length& new_y)
	{
		values.empty();
		values[0] = new_x;
		values[1] = new_y;
	}
	
	void point_nd::set_position(const length& new_p,const angle& new_theta)
	{
		values.empty();
		values[0] = length(new_p * msci::cos(new_theta));
		values[1] = length(new_p * msci::sin(new_theta));
	}
	
	void point_nd::set_position(const length& new_x,const length& new_y,const length& new_z)
	{
		values.empty();
		values[0] = new_x;
		values[1] = new_y;
		values[2] = new_z;
	}
	
	void point_nd::set_position(const length& new_p,const angle& new_theta,length new_z)
	{
		values.empty();
		new_z.set_same_prefix(new_p);
		values[0] = length(new_p * msci::cos(new_theta));
		values[1] = length(new_p * msci::sin(new_theta));
		values[2] = new_z;
	}
	
	void point_nd::set_position(const length& new_r,const angle& new_theta,const angle& new_phi)
	{
		values.empty();
		values[0] = length(new_r * msci::cos(new_theta) * msci::sin(new_phi));
		values[1] = length(new_r * msci::sin(new_theta) * msci::sin(new_phi));
		values[2] = length(new_r * msci::cos(new_phi));
	}
	
	void point_nd::set_position(const angle& new_latitude,const angle& new_longitude,const length& new_altitude)
	{
		values.empty();
		values[0] = length(new_altitude * msci::cos(new_latitude) * msci::cos(new_longitude));
		values[1] = length(new_altitude * msci::cos(new_latitude) * msci::sin(new_longitude));
		values[2] = length(new_altitude * msci::sin(new_latitude));
	}
	
	void point_nd::set_position(const vector<length>& new_values)
	{
		values.empty();
		values = new_values;
	}

	void point_nd::rotate(int dimension_number,int axis,const angle& new_theta)
	{
		if (dimension_number == 2 and get_nd() == 2)
		{
			length x_coord = values[0];
			length y_coord = values[1];
			values[0] = x_coord * msci::cos(new_theta) - y_coord * msci::sin(new_theta);
			values[1] = x_coord * msci::sin(new_theta) + y_coord * msci::cos(new_theta);
		}
		else if (dimension_number == 3 and get_nd() == 3)
		{
			length coord_1 = values[axis + 1];
			length coord_2 = values[axis + 2];
			values[axis + 1] = coord_1 * msci::cos(new_theta) - coord_2 * msci::sin(new_theta);
			values[axis + 2] = coord_1 * msci::sin(new_theta) + coord_2 * msci::cos(new_theta);
		}
	}
	
	void point_nd::move(const length& new_x)
	{
		values[0] += new_x;
	}
	
	void point_nd::move(const displacement_2d& x_displacement)
	{
		values[0] += x_displacement.x_projection();
		values[1] += x_displacement.y_projection();
	}
	
	void point_nd::move(const length& new_x,const length& new_y)
	{
		values[0] += new_x;
		values[1] += new_y;
	}
	
	void point_nd::move(const length& new_p,const angle& new_theta)
	{
		values[0] += new_p * msci::cos(new_theta);
		values[1] += new_p * msci::sin(new_theta);
	}
	
	void point_nd::move(const displacement_3d& x_displacement)
	{
		values[0] += x_displacement.x_projection();
		values[1] += x_displacement.y_projection();
		values[2] += x_displacement.z_projection();
	}
	
	void point_nd::move(const length& new_x,const length& new_y,const length& new_z)
	{
		values[0] += new_x;
		values[1] += new_y;
		values[2] += new_z;
	}
	
	void point_nd::move(const length& new_p,const angle& new_theta,length new_z)
	{
		new_z.set_same_prefix(new_p);
		values[0] += length(new_p * msci::cos(new_theta));
		values[1] += length(new_p * msci::sin(new_theta));
		values[2] += new_z;
	}
	
	void point_nd::move(const length& new_r,const angle& new_theta,const angle& new_phi)
	{
		values[0] += length(new_r * msci::cos(new_theta) * msci::sin(new_phi));
		values[1] += length(new_r * msci::sin(new_theta) * msci::sin(new_phi));
		values[2] += length(new_r * msci::cos(new_phi));
	}
	
	void point_nd::move(const displacement_nd& x_displacement)
	{
		if (x_displacement.get_nd() == get_nd())
		{
			for (int i = 0; i < x_displacement.get_nd(); i++)
			{
				values[i] += x_displacement.n_projection(i);
			}
		}
	}
	
	void point_nd::move(const length& new_r,const vector<angle>& new_angles)
	{
		displacement_nd x_displacement = displacement_nd(new_r,new_angles);
		move(x_displacement);
	}

	length point_nd::distance_to_origin() const
	{
		scalar_unit x_length = scalar_unit(0,"m2");
		for (int i = 0; i < values.size(); i++)
		{
			x_length += msci::pow(values[i],2);
		}
		return msci::sqrt(x_length);
	}
	
	string to_string(const point_nd& x)
	{
		ostringstream out;
		out << "(";
		for (int i = 0; i < x.values.size(); i++)
		{
			out << x.values[i];
			if ((i + 1) != x.values.size())
			{
				out << ",";
			}
		}
		out << ")";
		return out.str();
	}

	length distance(const point_nd& x1,const point_nd& x2)
	{
		if (x1.get_nd() == x2.get_nd())
		{
			scalar_unit x_length = scalar_unit(0,"m2");
			for (int i = 0; i < x1.values.size(); i++)
			{
				x_length += msci::pow(x1.values[i] - x2.values[i],2);
			}
			return msci::sqrt(x_length);
		}
		else
		{
			return length();
		}
	}
}

bool operator ==(const msci::point_nd& x,const msci::point_nd& y)
{
	for (int i = 0; i < x.values.size(); i++)
	{
		if (x.values[i] != y.values[i])
		{
			return false;
		}
	}
	return true;
}

bool operator !=(const msci::point_nd& x,const msci::point_nd& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const msci::point_nd& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, msci::point_nd& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::point_nd c(b);
	x = c;
	return is;
}
