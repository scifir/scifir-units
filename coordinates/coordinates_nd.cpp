#include "coordinates/coordinates_nd.hpp"

using namespace std;

namespace msci
{
	float distance(const coordinates_nd<float>& x1,const coordinates_nd<float>& x2)
	{
		if (x1.get_nd() == x2.get_nd())
		{
			float x_length = 0;
			for (int i = 0; i < x1.values.size(); i++)
			{
				x_length += std::pow(x1.values[i] - x2.values[i],2);
			}
			return std::sqrt(x_length);
		}
		else
		{
			return float();
		}
	}

	float distance(const coordinates_nd<float>& x1,const point_nd<float>& x2)
	{
		if (x1.get_nd() == x2.get_nd())
		{
			float x_length = 0;
			for (int i = 0; i < x1.values.size(); i++)
			{
				x_length += std::pow(x1.values[i] - x2.values[i],2);
			}
			return std::sqrt(x_length);
		}
		else
		{
			return float();
		}
	}

	float distance(const point_nd<float>& x1,const coordinates_nd<float>& x2)
	{
		if (x1.get_nd() == x2.get_nd())
		{
			float x_length = 0;
			for (int i = 0; i < x1.values.size(); i++)
			{
				x_length += std::pow(x1.values[i] - x2.values[i],2);
			}
			return std::sqrt(x_length);
		}
		else
		{
			return float();
		}
	}
}
