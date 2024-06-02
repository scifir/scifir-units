#include "./point_nd.hpp"

#include "../coordinates/coordinates_nd.hpp"

using namespace std;

namespace scifir
{
	point_nd<float>::point_nd(const coordinates_nd<float>& new_coordinates) : values(new_coordinates.values)
	{}

	point_nd<float>& point_nd<float>::operator=(const coordinates_nd<float>& x_coordinates)
	{
		values = x_coordinates.values;
		return *this;
	}

	float distance(const point_nd<float>& x1,const point_nd<float>& x2)
	{
		if (x1.get_nd() == x2.get_nd())
		{
			float x_length = 0;
			for (unsigned int i = 0; i < x1.values.size(); i++)
			{
				x_length += float(std::pow(x1.values[i] - x2.values[i],2));
			}
			return std::sqrt(x_length);
		}
		else
		{
			return float();
		}
	}
}
