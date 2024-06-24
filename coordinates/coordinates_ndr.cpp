#include "./coordinates_ndr.hpp"

using namespace std;

namespace scifir
{
	angle coordinates_ndr_no_angle = angle();
	float coordinates_ndr<float>::no_value = 0;

	string to_string(const coordinates_ndr<float>& x)
	{
		ostringstream out;
		out << "(";
		if (x.get_values().size() > 0)
		{
			for (int i = 0; i < x.get_values().size(); i++)
			{
				out << display_float(x.get_value(i));
				if ((i + 1) != x.get_values().size())
				{
					out << ",";
				}
			}
		}
		out << ";";
		if (x.get_angles().size() > 0)
		{
			for (int i = 0; i < x.get_angles().size(); i++)
			{
				out << x.get_angle(i);
				if ((i + 1) != x.get_angles().size())
				{
					out << ",";
				}
			}
		}
		out << ")";
		return out.str();
	}

	float distance(const coordinates_ndr<float>& x1,const coordinates_ndr<float>& x2)
	{
		if (x1.get_nd() == x2.get_nd())
		{
			float x_length = 0;
			for (unsigned int i = 0; i < x1.get_values().size(); i++)
			{
				x_length += float(std::pow(x1.get_value(i) - x2.get_value(i),2));
			}
			return std::sqrt(x_length);
		}
		else
		{
			return float();
		}
	}

	float distance(const coordinates_ndr<float>& x1,const coordinates_nd<float>& x2)
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

	float distance(const coordinates_nd<float>& x1,const coordinates_ndr<float>& x2)
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

	float distance(const coordinates_ndr<float>& x1,const point_nd<float>& x2)
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

	float distance(const point_nd<float>& x1,const coordinates_ndr<float>& x2)
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
