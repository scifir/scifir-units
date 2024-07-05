#include "./point_nd.hpp"

#include "../coordinates/coordinates_nd.hpp"
#include "../util/types.hpp"

using namespace std;

namespace scifir
{
	point_nd<float>::point_nd(const coordinates_nd<float>& x_coordinates) : values(x_coordinates.values)
	{}

	point_nd<float>::point_nd(coordinates_nd<float>&& x_coordinates) : values(std::move(x_coordinates.values))
	{}

	point_nd<float>& point_nd<float>::operator=(const coordinates_nd<float>& x_coordinates)
	{
		values = x_coordinates.values;
		return *this;
	}

	point_nd<float>& point_nd<float>::operator=(coordinates_nd<float>&& x_coordinates)
	{
		values = std::move(x_coordinates.values);
		return *this;
	}

	string to_string(const point_nd<float>& x)
	{
		if (x.values.size() > 0)
		{
			ostringstream out;
			out << "(";
			for (int i = 0; i < x.values.size(); i++)
			{
				out << display_float(x.values[i]);
				if ((i + 1) != x.values.size())
				{
					out << ",";
				}
			}
			out << ")";
			return out.str();
		}
		else
		{
			return "[empty]";
		}
	}

	float distance(const point_nd<float>& x,const point_nd<float>& y)
	{
		if (x.get_nd() == y.get_nd())
		{
			float x_length = 0;
			for (unsigned int i = 0; i < x.values.size(); i++)
			{
				x_length += float(std::pow(x.values[i] - y.values[i],2));
			}
			return std::sqrt(x_length);
		}
		else
		{
			return float();
		}
	}
}

ostream& operator <<(ostream& os,const scifir::point_nd<float>& x)
{
	return os << scifir::to_string(x);
}