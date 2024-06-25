#include "./coordinates_nd.hpp"

using namespace std;

namespace scifir
{
	string to_string(const coordinates_nd<float>& x)
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

	float distance(const coordinates_nd<float>& x1,const coordinates_nd<float>& x2)
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
			return 0.0f;
		}
	}

	float distance(const coordinates_nd<float>& x1,const point_nd<float>& x2)
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
			return 0.0f;
		}
	}

	float distance(const point_nd<float>& x1,const coordinates_nd<float>& x2)
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
			return 0.0f;
		}
	}
}
