#include "units/scalar_unit.hpp"

#include "units/conversion.hpp"
#include "units/unit_basic.hpp"
#include "units/prefix.hpp"
#include "util/types.hpp"

#include "boost/algorithm/string/erase.hpp"
#include "boost/algorithm/string.hpp"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

namespace scifir
{
	scalar_unit::scalar_unit() : dimensions(),value(0)
	{}

	scalar_unit::scalar_unit(const scalar_unit& x) : dimensions(x.get_dimensions()),value(x.get_value())
	{}

	scalar_unit::scalar_unit(scalar_unit&& x) : dimensions(move(x.get_dimensions())),value(move(x.get_value()))
	{}

	scalar_unit::scalar_unit(float new_value, const string& init_dimensions) : value(new_value),dimensions(create_dimensions(init_dimensions))
	{}

	scalar_unit::scalar_unit(float new_value, const vector<dimension>& new_dimensions) : value(new_value),dimensions(new_dimensions)
	{}

	scalar_unit::scalar_unit(const string& init_scalar) : scalar_unit()
	{
		set_from_string(init_scalar);
	}

	scalar_unit& scalar_unit::operator =(const scalar_unit& x)
	{
		if (has_dimensions(x))
		{
			dimensions = x.get_dimensions();
			value = x.get_value();
		}
		else
		{
			cerr << "Cannot initialize to different dimensions";
		}
		return *this;
	}

	scalar_unit& scalar_unit::operator =(scalar_unit&& x)
	{
		if (has_dimensions(x))
		{
			dimensions = move(x.get_dimensions());
			value = move(x.get_value());
		}
		else
		{
			cerr << "Cannot initialize to different dimensions";
		}
		return *this;
	}

	scalar_unit::operator float() const
	{
		return value;
	}

	scalar_unit scalar_unit::operator +(scalar_unit x) const
	{
		if(has_dimensions(x))
		{
			x.change_dimensions(*this);
			scalar_unit a = *this;
			a += x.get_value();
			return a;
		}
		else
		{
			cerr << "Cannot sum different dimensions";
			return scalar_unit();
		}
	}

	scalar_unit scalar_unit::operator -(scalar_unit x) const
	{
		if(has_dimensions(x))
		{
			x.change_dimensions(*this);
			scalar_unit a = *this;
			a -= x.get_value();
			return a;
		}
		else
		{
			cerr << "Cannot substract different dimensions";
			return scalar_unit();
		}
	}

	scalar_unit scalar_unit::operator *(scalar_unit x) const
	{
		long double new_value = value;
		new_value *= x.get_value();
		vector<dimension> new_dimensions = multiply_dimensions(get_dimensions(),x.get_dimensions(),new_value);
		return scalar_unit(new_value, new_dimensions);
	}

	scalar_unit scalar_unit::operator /(scalar_unit x) const
	{
		long double new_value = value;
		new_value /= x.get_value();
		vector<dimension> new_dimensions = divide_dimensions(get_dimensions(),x.get_dimensions(),new_value);
		return scalar_unit(new_value, new_dimensions);
	}

	scalar_unit scalar_unit::operator ^(const scalar_unit& x) const
	{
		if(x.has_empty_dimensions())
		{
			return (*this ^ int(x.get_value()));
		}
		else
		{
			cerr << "Exponent of dimensions doesn't exist";
			return scalar_unit();
		}
	}

	void scalar_unit::operator +=(scalar_unit x)
	{
		if(!has_dimensions(x))
		{
			cerr << "Cannot sum different dimensions";
			return;
		}
		x.change_dimensions(x);
		value += x.get_value();
	}

	void scalar_unit::operator -=(scalar_unit x)
	{
		if(!has_dimensions(x))
		{
			cerr << "Cannot substract different dimensions";
			return;
		}
		x.change_dimensions(x);
		value -= x.get_value();
	}

	scalar_unit& scalar_unit::operator++()
	{
		value++;
		return *this;
	}

	scalar_unit& scalar_unit::operator++(int)
	{
		scalar_unit& tmp(*this);
		operator++();
		return tmp;
	}

	scalar_unit& scalar_unit::operator--()
	{
		value--;
		return *this;
	}

	scalar_unit& scalar_unit::operator--(int)
	{
		scalar_unit& tmp(*this);
		operator--();
		return tmp;
	}

	void scalar_unit::change_dimensions(const string& new_dimensions_str)
	{
		vector<dimension> new_dimensions = create_dimensions(new_dimensions_str);
		if(has_dimensions(new_dimensions))
		{
			for(const dimension& actual_dimension : dimensions)
			{
				remove_dimension(actual_dimension);
				if(actual_dimension.is_derived_dimension())
				{
					vector<dimension> derived_dimensions = actual_dimension.get_basic_dimensions();
					for(const dimension& derived_dimension : derived_dimensions)
					{
						remove_dimension(derived_dimension);
					}
				}
			}
			dimensions.clear();
			for(const dimension& new_dimension : new_dimensions)
			{
				add_dimension(new_dimension);
				if(new_dimension.is_derived_dimension())
				{
					vector<dimension> new_derived_dimensions = new_dimension.get_basic_dimensions();
					for(const dimension& new_derived_dimension : new_derived_dimensions)
					{
						add_dimension(new_derived_dimension);
					}
				}
			}
			dimensions = new_dimensions;
		}
		else
		{
			cerr << "Cannot change to different base dimensions" << endl;
		}
	}

	void scalar_unit::change_dimensions(const scalar_unit& x)
	{
		if(has_dimensions(x.get_dimensions()))
		{
			for(const dimension& actual_dimension : dimensions)
			{
				remove_dimension(actual_dimension);
				if(actual_dimension.is_derived_dimension())
				{
					vector<dimension> derived_dimensions = actual_dimension.get_basic_dimensions();
					for(const dimension& derived_dimension : derived_dimensions)
					{
						remove_dimension(derived_dimension);
					}
				}
			}
			dimensions.clear();
			for(const dimension& new_dimension : x.get_dimensions())
			{
				add_dimension(new_dimension);
				if(new_dimension.is_derived_dimension())
				{
					vector<dimension> new_derived_dimensions = new_dimension.get_basic_dimensions();
					for(const dimension& new_derived_dimension : new_derived_dimensions)
					{
						add_dimension(new_derived_dimension);
					}
				}
			}
			dimensions = x.get_dimensions();
		}
		else
		{
			cerr << "Cannot change to different base dimensions" << endl;
		}
	}

	bool scalar_unit::has_dimensions(const string& dimension_structure) const
	{
		vector<dimension> structure_dimensions = create_dimensions(dimension_structure);
		return has_dimensions(structure_dimensions);
	}

	bool scalar_unit::has_dimensions(const vector<dimension>& x_dimensions) const
	{
		return equal_dimensions(dimensions,x_dimensions);
	}

	bool scalar_unit::has_dimensions(const scalar_unit& x) const
	{
		return equal_dimensions(dimensions,x.get_dimensions());
	}

	bool scalar_unit::has_empty_dimensions() const
	{
		vector<dimension> derived_dimensions = create_derived_dimensions(dimensions);
		if(derived_dimensions.size() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string scalar_unit::display_dimensions() const
	{
		ostringstream dimension_text;
		ostringstream dimension_up_text;
		ostringstream dimension_down_text;
		for(const dimension& x_dimension : dimensions)
		{
			if(x_dimension.dimension_sign == dimension::POSITIVE)
			{
				dimension_up_text << x_dimension;
			}
			else
			{
				dimension_down_text << x_dimension;
			}
		}
		if(dimension_up_text.tellp() > 0 and dimension_down_text.tellp() > 0)
		{
			dimension_text << dimension_up_text.str() << "/" << dimension_down_text.str();
		}
		else if(dimension_up_text.tellp() > 0)
		{
			dimension_text << dimension_up_text.str();
		}
		else if(dimension_down_text.tellp() > 0)
		{
			dimension_text << "1/" << dimension_down_text.str();
		}
		else
		{
			dimension_text << "[empty]";
		}
		return dimension_text.str();
	}

	string scalar_unit::get_dimensions_match() const
	{
		return "";
	}

	vector<dimension> scalar_unit::get_derived_dimensions() const
	{
		return create_derived_dimensions(dimensions);
	}

	string scalar_unit::display(int number_of_decimals) const
	{
		ostringstream output;
		if (dimensions.size() == 1)
		{
			int value_scale = int(log10(get_value()));
			prefix display_prefix = closest_prefix(dimensions[0].prefix,value_scale);
			float x_value = get_value();
			x_value *= dimensions[0].prefix_math();
			x_value /= prefix_math(dimensions[0],display_prefix);
			vector<dimension> x_dimensions = dimensions;
			x_dimensions[0].prefix = display_prefix;
			output << display_float(x_value,number_of_decimals) << " " << to_string(x_dimensions);
		}
		else
		{
			output << display_float(get_value(),number_of_decimals) << " " << to_string(dimensions);
		}
		return output.str();
	}

	string scalar_unit::derived_display(int number_of_decimals) const
	{
		ostringstream output;
		long double x_value = get_value();
		vector<dimension> derived_dimensions = create_derived_dimensions(dimensions,x_value);
		if (derived_dimensions.size() == 1)
		{
			int value_scale = int(log10(get_value()));
			prefix display_prefix = closest_prefix(derived_dimensions[0].prefix,value_scale);
			x_value *= derived_dimensions[0].prefix_math();
			x_value /= prefix_math(derived_dimensions[0],display_prefix);
			vector<dimension> x_dimensions = derived_dimensions;
			x_dimensions[0].prefix = display_prefix;
			output << display_float(x_value,number_of_decimals) << " " << to_string(derived_dimensions);
		}
		else
		{
			output << display_float(x_value,number_of_decimals) << " " << to_string(derived_dimensions);
		}
		return output.str();
	}

	string scalar_unit::custom_display(const string& new_dimensions_str,int number_of_decimals) const
	{
		ostringstream output;
		float new_value = get_value();
		if (new_dimensions_str != "sci")
		{
			vector<dimension> new_dimensions = create_dimensions(new_dimensions_str);
			for(const dimension& x_dimension : dimensions)
			{
				if (x_dimension.dimension_sign == dimension::POSITIVE)
				{
					new_value *= x_dimension.get_conversion_factor();
					new_value *= x_dimension.prefix_math();
				}
				else if (x_dimension.dimension_sign == dimension::NEGATIVE)
				{
					new_value /= x_dimension.get_conversion_factor();
					new_value /= x_dimension.prefix_math();
				}
			}
			vector<dimension> derived_dimensions = create_derived_dimensions(dimensions);
			for(const dimension& x_dimension : derived_dimensions)
			{
				if (x_dimension.dimension_sign == dimension::POSITIVE)
				{
					new_value *= x_dimension.prefix_math();
				}
				else if (x_dimension.dimension_sign == dimension::NEGATIVE)
				{
					new_value /= x_dimension.prefix_math();
				}
			}
			for(const dimension& x_new_dimension : new_dimensions)
			{
				if (x_new_dimension.dimension_sign == dimension::POSITIVE)
				{
					new_value /= x_new_dimension.get_conversion_factor();
					new_value /= x_new_dimension.prefix_math();
				}
				else if (x_new_dimension.dimension_sign == dimension::NEGATIVE)
				{
					new_value *= x_new_dimension.get_conversion_factor();
					new_value *= x_new_dimension.prefix_math();
				}
			}
			output << display_float(new_value,number_of_decimals) << " " << new_dimensions_str;
		}
		else
		{
			for (const dimension& x_dimension : dimensions)
			{
				new_value *= x_dimension.prefix_math();
			}
			vector<dimension> new_dimensions = dimensions;
			for (dimension& x_new_dimension : new_dimensions)
			{
				x_new_dimension.prefix.prefix_type = prefix::no_prefix;
			}
			int value_scale = int(log10(get_value()));
			output << display_float(new_value / std::pow(10,value_scale),number_of_decimals) << "e" << value_scale << " " << to_string(new_dimensions);
		}
		return output.str();
	}

	void scalar_unit::add_dimension(const dimension& new_dimension)
	{
		if (new_dimension.dimension_sign == dimension::POSITIVE)
		{
			value /= new_dimension.get_conversion_factor();
			value /= new_dimension.prefix_math();
		}
		else if (new_dimension.dimension_sign == dimension::NEGATIVE)
		{
			value *= new_dimension.get_conversion_factor();
			value *= new_dimension.prefix_math();
		}
	}

	void scalar_unit::remove_dimension(const dimension& old_dimension)
	{
		if (old_dimension.dimension_sign == dimension::POSITIVE)
		{
			value *= old_dimension.get_conversion_factor();
			value *= old_dimension.prefix_math();
		}
		else if (old_dimension.dimension_sign == dimension::NEGATIVE)
		{
			value /= old_dimension.get_conversion_factor();
			value /= old_dimension.prefix_math();
		}
	}

	string scalar_unit::initial_dimensions_get_structure(const string& init_value) const
	{
		return "";
		/*if(!isdigit(init_value[0]))
		{
			return;
		}
		else
		{
			int i = 0;
			while(isdigit(init_value[i]) || init_value[i] == '.')
			{
				i++;
			}
			if(init_value[i] != ' ')
			{
				return;
			}
			return init_value.substr(i);
		}*/
	}

	void scalar_unit::set_from_string(const string& init_scalar)
	{
		if(!isdigit(init_scalar[0]))
		{
			return;
		}
		else
		{
			int i = 0;
			while(isdigit(init_scalar[i]) || init_scalar[i] == '.' || init_scalar[i] == ' ' || init_scalar[i] == '*' || init_scalar[i] == '^' || init_scalar[i] == 'e' || init_scalar[i] == 'E')
			{
				if (init_scalar[i] == ' ')
				{
					break;
				}
				i++;
			}
			string string_value = init_scalar.substr(0, i);
			boost::algorithm::erase_all(string_value, " ");
			size_t search_e = string_value.find("E");
			if (search_e != string::npos)
			{
				string_value.replace(search_e,1,"e");
			}
			size_t search_10 = string_value.find("*10^");
			if (search_10 != string::npos)
			{
				string_value.replace(search_10,4,"e");
			}
			stringstream ss(string_value);
			ss >> value;
			dimensions = create_dimensions(init_scalar.substr(i));
		}
	}

	string to_string(const scalar_unit& x)
	{
		ostringstream output;
		output << x.display(2);
		return output.str();
	}

	bool is_scalar_unit(const string& x)
	{
		bool dot_present = false;
		bool e_present = false;
		int current_pos = 0;
		int e_present_pos = 0;
		for (int i = 0; i < x.length(); i++)
		{
			if (x[i] == ' ')
			{
				if (e_present and ((e_present_pos + 1) == i))
				{
					return false;
				}
				current_pos = i;
				break;
			}
			if (e_present == false)
			{
				if (x[i] == '.')
				{
					if (dot_present)
					{
						return false;
					}
					else
					{
						dot_present = true;
					}
				}
				else if (x[i] == 'e' or x[i] == 'E')
				{
					e_present = true;
					e_present_pos = i;
					continue;
				}
				else if (x[i] == '*')
				{
					if (!(x.substr(i + 1,3) == "10^"))
					{
						return false;
					}
					else
					{
						e_present = true;
						i += 3;
						e_present_pos = i;
						continue;
					}
				}
				else if (!isdigit(x[i]))
				{
					return false;
				}
				else if (i == (x.length() - 1))
				{
					return false;
				}
			}
			else
			{
				if (!isdigit(x[i]))
				{
					return false;
				}
			}
		}
		if (current_pos == (x.length() - 1))
		{
			return false;
		}
		if (current_pos == 0)
		{
			return false;
		}
		vector<string> values;
		boost::split(values,x.substr(current_pos),boost::is_any_of("/"));
		if (values.size() == 1)
		{
			vector<string> subvalues;
			boost::split(subvalues,values[0],boost::is_any_of("*"));
			for (string& x_subvalue : subvalues)
			{
				boost::trim(x_subvalue);
				bool number_present = false;
				for (int i = 0; i < x_subvalue.length(); i++)
				{
					if (number_present == false)
					{
						if (isdigit(x_subvalue[i]))
						{
							number_present = true;
							continue;
						}
						else if (!isalpha(x_subvalue[i]))
						{
							return false;
						}
					}
					else
					{
						if (!isdigit(x_subvalue[i]))
						{
							return false;
						}
					}
				}
			}
			return true;
		}
		else if (values.size() == 2)
		{
			if (values[0] != "1")
			{
				vector<string> subvalues;
				boost::split(subvalues,values[0],boost::is_any_of("*"));
				for (string& x_subvalue : subvalues)
				{
					boost::trim(x_subvalue);
					bool number_present = false;
					for (int i = 0; i < x_subvalue.length(); i++)
					{
						if (number_present == false)
						{
							if (isdigit(x_subvalue[i]))
							{
								number_present = true;
								continue;
							}
							else if (!isalpha(x_subvalue[i]))
							{
								return false;
							}
						}
						else
						{
							if (!isdigit(x_subvalue[i]))
							{
								return false;
							}
						}
					}
				}
			}
			vector<string> subvalues_denominator;
			boost::split(subvalues_denominator,values[1],boost::is_any_of("*"));
			for (string& x_subvalue : subvalues_denominator)
			{
				boost::trim(x_subvalue);
				bool number_present = false;
				for (int i = 0; i < x_subvalue.length(); i++)
				{
					if (number_present == false)
					{
						if (isdigit(x_subvalue[i]))
						{
							number_present = true;
							continue;
						}
						else if (!isalpha(x_subvalue[i]))
						{
							return false;
						}
					}
					else
					{
						if (!isdigit(x_subvalue[i]))
						{
							return false;
						}
					}
				}
			}
			return true;
		}
		return false;
	}

	float abs(const scalar_unit& x)
	{
		return std::abs(x.get_value());
	}

	scalar_unit pow(const scalar_unit& x,int y)
	{
		return x ^ y;
	}

	scalar_unit sqrt(const scalar_unit& x)
	{
		long double new_value = x.get_value();
		vector<dimension> new_dimensions = square_dimensions(x.get_dimensions(), new_value, 2);
		new_value = std::sqrt(new_value);
		return scalar_unit(new_value, new_dimensions);
	}

	scalar_unit sqrt_nth(const scalar_unit& x, int y)
	{
		long double new_value = x.get_value();
		vector<dimension> new_dimensions = square_dimensions(x.get_dimensions(), new_value, y);
		new_value = std::pow(new_value, 1.0 / y);
		return scalar_unit(new_value, new_dimensions);
	}
}

bool operator ==(const scifir::scalar_unit& x, scifir::scalar_unit y)
{
	y.change_dimensions(x);
	if(x.get_value() == y.get_value() and x.has_dimensions(y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const scifir::scalar_unit& x, scifir::scalar_unit y)
{
	return !(x == y);
}

bool operator <(const scifir::scalar_unit& x, const scifir::scalar_unit& y)
{
	if(!x.has_dimensions(y))
	{
		return false;
	}
	scifir::scalar_unit z = x;
	z.change_dimensions(y);
	if(z.get_value() < y.get_value())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator >(const scifir::scalar_unit& x, const scifir::scalar_unit& y)
{
	if(!x.has_dimensions(y))
	{
		return false;
	}
	scifir::scalar_unit z = x;
	z.change_dimensions(y);
	if(z.get_value() > y.get_value())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator <=(const scifir::scalar_unit& x, const scifir::scalar_unit& y)
{
	return !(x > y);
}

bool operator >=(const scifir::scalar_unit& x, const scifir::scalar_unit& y)
{
	return !(x < y);
}

bool operator ==(const scifir::scalar_unit& x, const string& y_init)
{
	scifir::scalar_unit y(y_init);
	return (x == y);
}

bool operator !=(const scifir::scalar_unit& x, const string& y_init)
{
	return !(x == y_init);
}

bool operator <(const scifir::scalar_unit& x, const string& y_init)
{
	scifir::scalar_unit y(y_init);
	return (x < y);
}

bool operator >(const scifir::scalar_unit& x, const string& y_init)
{
	scifir::scalar_unit y(y_init);
	return (x > y);
}

bool operator <=(const scifir::scalar_unit& x, const string& y_init)
{
	return !(x > y_init);
}

bool operator >=(const scifir::scalar_unit& x, const string& y_init)
{
	return !(x < y_init);
}

bool operator ==(const string& x_init, const scifir::scalar_unit& y)
{
	return (y == x_init);
}

bool operator !=(const string& x_init, const scifir::scalar_unit& y)
{
	return (y != x_init);
}

bool operator <(const string& x_init, const scifir::scalar_unit& y)
{
	scifir::scalar_unit x(x_init);
	return (x < y);
}

bool operator >(const string& x_init, const scifir::scalar_unit& y)
{
	scifir::scalar_unit x(x_init);
	return (x > y);
}

bool operator <=(const string& x_init, const scifir::scalar_unit& y)
{
	return !(x_init > y);
}

bool operator >=(const string& x_init, const scifir::scalar_unit& y)
{
	return !(x_init < y);
}

void operator +=(string& x, const scifir::scalar_unit& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const scifir::scalar_unit& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const scifir::scalar_unit& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const scifir::scalar_unit& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, scifir::scalar_unit& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	scifir::scalar_unit c(b);
	x = c;
	return is;
}
