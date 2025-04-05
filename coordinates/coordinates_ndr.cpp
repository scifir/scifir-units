#include "./coordinates_ndr.hpp"

using namespace std;

namespace scifir
{
	angle coordinates_ndr_no_angle = angle();
	float coordinates_ndr<float>::no_value = 0;

	string to_string(const coordinates_ndr<float>& x)
	{
		if (x.get_values().size() > 0)
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
			if (x.get_angles().size() > 0)
			{
				out << ";";
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
		else
		{
			return "[empty]";
		}
	}

	float distance(const coordinates_ndr<float>& x,const coordinates_ndr<float>& y)
	{
		if (x.get_nd() == y.get_nd())
		{
			float x_length = 0;
			for (unsigned int i = 0; i < x.get_values().size(); i++)
			{
				x_length += float(std::pow(x.get_value(i) - y.get_value(i),2));
			}
			return std::sqrt(x_length);
		}
		else
		{
			return 0.0f;
		}
	}

	float distance(const coordinates_ndr<float>& x,const coordinates_nd<float>& y)
	{
		if (x.get_nd() == y.get_nd())
		{
			float x_length = 0;
			for (unsigned int i = 0; i < x.get_values().size(); i++)
			{
				x_length += float(std::pow(x.get_value(i) - y.values[i],2));
			}
			return std::sqrt(x_length);
		}
		else
		{
			return 0.0f;
		}
	}

	float distance(const coordinates_nd<float>& x,const coordinates_ndr<float>& y)
	{
		if (x.get_nd() == y.get_nd())
		{
			float x_length = 0;
			for (unsigned int i = 0; i < x.values.size(); i++)
			{
				x_length += float(std::pow(x.values[i] - y.get_value(i),2));
			}
			return std::sqrt(x_length);
		}
		else
		{
			return 0.0f;
		}
	}
}

ostream& operator <<(ostream& os,const scifir::coordinates_ndr<float>& x)
{
	return os << scifir::to_string(x);
}