#include "./scalar_unit.hpp"

#include "./conversion.hpp"
#include "./unit_basic.hpp"
#include "./prefix.hpp"
#include "../util/types.hpp"

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
	scalar_unit::scalar_unit() : dimensions(),value(0.0f)
	{}

	scalar_unit::scalar_unit(const scalar_unit& x) : dimensions(x.get_dimensions()),value(x.get_value())
	{}

	scalar_unit::scalar_unit(scalar_unit&& x) : dimensions(std::move(x.get_dimensions())),value(std::move(x.get_value()))
	{}

	scalar_unit::scalar_unit(float new_value, const string& init_dimensions) : dimensions(create_dimensions(init_dimensions)),value(new_value)
	{}

	scalar_unit::scalar_unit(double new_value, const string& init_dimensions) : dimensions(create_dimensions(init_dimensions)),value(float(new_value))
	{}

	scalar_unit::scalar_unit(long double new_value, const string& init_dimensions) : dimensions(create_dimensions(init_dimensions)),value(float(new_value))
	{}

	scalar_unit::scalar_unit(int new_value, const string& init_dimensions) : dimensions(create_dimensions(init_dimensions)),value(float(new_value))
	{}

	scalar_unit::scalar_unit(float new_value, const vector<dimension>& new_dimensions) : dimensions(new_dimensions),value(new_value)
	{}

	scalar_unit::scalar_unit(double new_value, const vector<dimension>& new_dimensions) : dimensions(new_dimensions),value(float(new_value))
	{}

	scalar_unit::scalar_unit(long double new_value, const vector<dimension>& new_dimensions) : dimensions(new_dimensions),value(float(new_value))
	{}

	scalar_unit::scalar_unit(int new_value, const vector<dimension>& new_dimensions) : dimensions(new_dimensions),value(float(new_value))
	{}

	scalar_unit::scalar_unit(const string& init_scalar) : scalar_unit()
	{
		//static_assert(is_valid_scalar_unit("asdf"),"invalid initialization string");
		initialize_from_string(init_scalar);
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
			cerr << "Cannot initialize to different dimensions" << endl;
		}
		return *this;
	}

	scalar_unit& scalar_unit::operator =(scalar_unit&& x)
	{
		if (has_dimensions(x))
		{
			dimensions = std::move(x.get_dimensions());
			value = std::move(x.get_value());
		}
		else
		{
			cerr << "Cannot initialize to different dimensions" << endl;
		}
		return *this;
	}

	scalar_unit& scalar_unit::operator =(const string& init_scalar)
	{
		initialize_from_string(init_scalar);
		return *this;
	}

	scalar_unit::operator float() const
	{
		return value;
	}

	bool scalar_unit::operator ==(scalar_unit x) const
	{
		x.change_dimensions(*this);
		if(get_value() == x.get_value() and has_dimensions(x))
		{
			return true;
		}
		else
		{
			return false;
		}
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
			cerr << "Cannot sum different dimensions" << endl;
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
			cerr << "Cannot substract different dimensions" << endl;
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
			return scalar_unit(std::pow(value,x.get_value()),power_dimensions(get_dimensions(),int(x.get_value())));
		}
		else
		{
			cerr << "Exponent of dimensions doesn't exist" << endl;
			return scalar_unit();
		}
	}

	void scalar_unit::operator +=(scalar_unit x)
	{
		if(!has_dimensions(x))
		{
			cerr << "Cannot sum different dimensions" << endl;
			return;
		}
		x.change_dimensions(*this);
		value += x.get_value();
	}

	void scalar_unit::operator -=(scalar_unit x)
	{
		if(!has_dimensions(x))
		{
			cerr << "Cannot substract different dimensions" << endl;
			return;
		}
		x.change_dimensions(*this);
		value -= x.get_value();
	}

	scalar_unit& scalar_unit::operator ++()
	{
		value++;
		return *this;
	}

	scalar_unit& scalar_unit::operator ++(int)
	{
		scalar_unit& tmp(*this);
		operator++();
		return tmp;
	}

	scalar_unit& scalar_unit::operator --()
	{
		value--;
		return *this;
	}

	scalar_unit& scalar_unit::operator --(int)
	{
		scalar_unit& tmp(*this);
		operator--();
		return tmp;
	}

	void scalar_unit::change_dimensions(const string& init_dimensions)
	{
		vector<dimension> new_dimensions = create_dimensions(init_dimensions);
		if(has_dimensions(new_dimensions))
		{
			if (equal_dimensions_and_prefixes(dimensions,new_dimensions))
			{
				return;
			}
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
			if (equal_dimensions_and_prefixes(dimensions,x.get_dimensions()))
			{
				return;
			}
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

	bool scalar_unit::has_dimensions(const string& init_dimensions) const
	{
		vector<dimension> structure_dimensions = create_dimensions(init_dimensions);
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
		return to_string(dimensions);
	}

	/*string scalar_unit::get_dimensions_match() const
	{
		return "";
	}*/

	vector<dimension> scalar_unit::get_derived_dimensions() const
	{
		return create_derived_dimensions(dimensions);
	}

	string scalar_unit::display(int number_of_decimals,bool with_brackets,bool use_close_prefix) const
	{
		ostringstream output;
		if (dimensions.size() == 1 and use_close_prefix == true)
		{
			prefix display_prefix;
			if (get_value() != 0)
			{
				int value_scale = int(log10(get_value()));
				display_prefix = closest_prefix(dimensions[0].prefix,value_scale);
			}
			else
			{
				display_prefix = dimensions[0].prefix;
			}
			long double x_value = get_value();
			x_value *= dimensions[0].prefix_math();
			x_value /= dimensions[0].prefix_math(display_prefix);
			vector<dimension> x_dimensions = dimensions;
			x_dimensions[0].prefix = display_prefix;
			output << display_float(float(x_value),number_of_decimals) << " " << to_string(x_dimensions,with_brackets);
		}
		else
		{
			output << display_float(get_value(),number_of_decimals) << " " << to_string(dimensions,with_brackets);
		}
		return output.str();
	}

	string scalar_unit::derived_display(int number_of_decimals,bool with_brackets,bool use_close_prefix) const
	{
		ostringstream output;
		long double x_value = get_value();
		vector<dimension> derived_dimensions = create_derived_dimensions(dimensions,x_value);
		if (derived_dimensions.size() == 1 and use_close_prefix == true)
		{
			int value_scale = int(log10(get_value()));
			prefix display_prefix = closest_prefix(derived_dimensions[0].prefix,value_scale);
			x_value *= derived_dimensions[0].prefix_math();
			x_value /= derived_dimensions[0].prefix_math(display_prefix);
			vector<dimension> x_dimensions = derived_dimensions;
			x_dimensions[0].prefix = display_prefix;
			output << display_float(float(x_value),number_of_decimals) << " " << to_string(derived_dimensions,with_brackets);
		}
		else
		{
			output << display_float(float(x_value),number_of_decimals) << " " << to_string(derived_dimensions,with_brackets);
		}
		return output.str();
	}

	string scalar_unit::custom_display(const string& init_dimensions,int number_of_decimals,bool with_brackets) const
	{
		ostringstream output;
		long double new_value = get_value();
		if (init_dimensions != "sci")
		{
			vector<dimension> new_dimensions = create_dimensions(init_dimensions);
			for(const dimension& x_dimension : dimensions)
			{
				if (x_dimension.dimension_sign == dimension::NUMERATOR)
				{
					new_value *= x_dimension.get_conversion_factor();
					new_value *= x_dimension.prefix_math();
				}
				else if (x_dimension.dimension_sign == dimension::DENOMINATOR)
				{
					new_value /= x_dimension.get_conversion_factor();
					new_value /= x_dimension.prefix_math();
				}
			}
			vector<dimension> derived_dimensions = create_derived_dimensions(dimensions);
			for(const dimension& x_dimension : derived_dimensions)
			{
				if (x_dimension.dimension_sign == dimension::NUMERATOR)
				{
					new_value *= x_dimension.prefix_math();
				}
				else if (x_dimension.dimension_sign == dimension::DENOMINATOR)
				{
					new_value /= x_dimension.prefix_math();
				}
			}
			for(const dimension& x_new_dimension : new_dimensions)
			{
				if (x_new_dimension.dimension_sign == dimension::NUMERATOR)
				{
					new_value /= x_new_dimension.get_conversion_factor();
					new_value /= x_new_dimension.prefix_math();
				}
				else if (x_new_dimension.dimension_sign == dimension::DENOMINATOR)
				{
					new_value *= x_new_dimension.get_conversion_factor();
					new_value *= x_new_dimension.prefix_math();
				}
			}
			output << display_float(float(new_value),number_of_decimals) << " ";
			if (with_brackets)
			{
				output << "[";
			}
			output << init_dimensions;
			if (with_brackets)
			{
				output << "]";
			}
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
			output << display_float(float(new_value / std::pow(10,value_scale)),number_of_decimals) << "e" << value_scale << " " << to_string(new_dimensions,with_brackets);
		}
		return output.str();
	}

	void scalar_unit::add_dimension(const dimension& new_dimension)
	{
		if (new_dimension.dimension_sign == dimension::NUMERATOR)
		{
			value /= float(new_dimension.get_conversion_factor());
			value /= float(new_dimension.prefix_math());
		}
		else if (new_dimension.dimension_sign == dimension::DENOMINATOR)
		{
			value *= float(new_dimension.get_conversion_factor());
			value *= float(new_dimension.prefix_math());
		}
	}

	void scalar_unit::remove_dimension(const dimension& old_dimension)
	{
		if (old_dimension.dimension_sign == dimension::NUMERATOR)
		{
			value *= float(old_dimension.get_conversion_factor());
			value *= float(old_dimension.prefix_math());
		}
		else if (old_dimension.dimension_sign == dimension::DENOMINATOR)
		{
			value /= float(old_dimension.get_conversion_factor());
			value /= float(old_dimension.prefix_math());
		}
	}

	void scalar_unit::initialize_from_string(string init_scalar)
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

	bool is_scalar_unit(const string& init_scalar)
	{
		bool dot_present = false;
		bool e_present = false;
		unsigned int current_pos = 0;
		int e_present_pos = 0;
		for (unsigned int i = 0; i < init_scalar.length(); i++)
		{
			if (init_scalar[i] == ' ')
			{
				if (e_present and ((unsigned int)(e_present_pos + 1) == i))
				{
					return false;
				}
				current_pos = i;
				break;
			}
			if (e_present == false)
			{
				if (init_scalar[i] == '.')
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
				else if (init_scalar[i] == 'e' or init_scalar[i] == 'E')
				{
					e_present = true;
					e_present_pos = i;
					continue;
				}
				else if (init_scalar[i] == '*')
				{
					if (!(init_scalar.substr(i + 1,3) == "10^"))
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
				else if (!isdigit(init_scalar[i]))
				{
					return false;
				}
				else if (i == (init_scalar.length() - 1))
				{
					return false;
				}
			}
			else
			{
				if (!isdigit(init_scalar[i]))
				{
					return false;
				}
			}
		}
		if (current_pos == (init_scalar.length() - 1))
		{
			return false;
		}
		if (current_pos == 0)
		{
			return false;
		}
		vector<string> values;
		boost::split(values,init_scalar.substr(current_pos),boost::is_any_of("/"));
		if (values.size() == 1)
		{
			vector<string> subvalues;
			boost::split(subvalues,values[0],boost::is_any_of("*"));
			for (string& x_subvalue : subvalues)
			{
				boost::trim(x_subvalue);
				bool number_present = false;
				for (unsigned int i = 0; i < x_subvalue.length(); i++)
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
					for (unsigned int i = 0; i < x_subvalue.length(); i++)
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
				for (unsigned int i = 0; i < x_subvalue.length(); i++)
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

	scalar_unit pow(const scalar_unit& x,int exponent)
	{
		return x ^ exponent;
	}

	scalar_unit sqrt(const scalar_unit& x)
	{
		long double new_value = x.get_value();
		vector<dimension> new_dimensions = square_dimensions(x.get_dimensions(), new_value, 2);
		new_value = std::sqrt(new_value);
		return scalar_unit(new_value, new_dimensions);
	}

	scalar_unit sqrt_nth(const scalar_unit& x, int index)
	{
		long double new_value = x.get_value();
		vector<dimension> new_dimensions = square_dimensions(x.get_dimensions(), new_value, index);
		new_value = std::pow(new_value, 1.0f / index);
		return scalar_unit(new_value, new_dimensions);
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

bool operator ==(const scifir::scalar_unit& x, const string& init_scalar)
{
	scifir::scalar_unit y(init_scalar);
	return (x == y);
}

bool operator !=(const scifir::scalar_unit& x, const string& init_scalar)
{
	return !(x == init_scalar);
}

bool operator <(const scifir::scalar_unit& x, const string& init_scalar)
{
	scifir::scalar_unit y(init_scalar);
	return (x < y);
}

bool operator >(const scifir::scalar_unit& x, const string& init_scalar)
{
	scifir::scalar_unit y(init_scalar);
	return (x > y);
}

bool operator <=(const scifir::scalar_unit& x, const string& init_scalar)
{
	return !(x > init_scalar);
}

bool operator >=(const scifir::scalar_unit& x, const string& init_scalar)
{
	return !(x < init_scalar);
}

bool operator ==(const string& init_scalar, const scifir::scalar_unit& x)
{
	return (x == init_scalar);
}

bool operator !=(const string& init_scalar, const scifir::scalar_unit& x)
{
	return (x != init_scalar);
}

bool operator <(const string& init_scalar, const scifir::scalar_unit& x)
{
	scifir::scalar_unit y(init_scalar);
	return (y < x);
}

bool operator >(const string& init_scalar, const scifir::scalar_unit& x)
{
	scifir::scalar_unit y(init_scalar);
	return (y > x);
}

bool operator <=(const string& init_scalar, const scifir::scalar_unit& x)
{
	return !(init_scalar > x);
}

bool operator >=(const string& init_scalar, const scifir::scalar_unit& x)
{
	return !(init_scalar < x);
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
	x = scifir::scalar_unit(b);
	return is;
}
