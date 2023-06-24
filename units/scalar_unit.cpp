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

namespace msci
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
		if (equal_dimensions(*this,x))
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
		if (equal_dimensions(*this,x))
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
		if(equal_dimensions(*this,x))
		{
			x.set_same_prefix(get_dimensions());
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
		if(equal_dimensions(*this,x))
		{
			x.set_same_prefix(get_dimensions());
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
		float new_value = value;
		if(equal_dimensions(*this,x))
		{
			x.set_same_prefix(get_dimensions());
		}
		new_value *= x.get_value();
		vector<dimension> new_dimensions = multiply_dimensions(get_dimensions(),x.get_dimensions());
		return scalar_unit(new_value, new_dimensions);
	}

	scalar_unit scalar_unit::operator /(scalar_unit x) const
	{
		float new_value = value;
		if(equal_dimensions(*this,x))
		{
			x.set_same_prefix(get_dimensions());
		}
		new_value /= x.get_value();
		vector<dimension> new_dimensions = divide_dimensions(get_dimensions(),x.get_dimensions());
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
		if(!equal_dimensions(*this,x))
		{
			cerr << "Cannot sum different dimensions";
			return;
		}
		x.set_same_prefix(get_dimensions());
		value += x.get_value();
	}

	void scalar_unit::operator -=(scalar_unit x)
	{
		if(!equal_dimensions(*this,x))
		{
			cerr << "Cannot substract different dimensions";
			return;
		}
		x.set_same_prefix(get_dimensions());
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
				remove_prefix(actual_dimension.prefix);
				if(actual_dimension.is_derived_dimension())
				{
					vector<dimension> derived_dimensions = actual_dimension.get_basic_dimensions();
					for(const dimension& derived_dimension : derived_dimensions)
					{
						remove_prefix(derived_dimension.prefix);
					}
				}
			}
			dimensions.clear();
			for(const dimension& new_dimension : new_dimensions)
			{
				add_prefix(new_dimension.prefix);
				if(new_dimension.is_derived_dimension())
				{
					vector<dimension> new_derived_dimensions = new_dimension.get_basic_dimensions();
					for(const dimension& new_derived_dimension : new_derived_dimensions)
					{
						add_prefix(new_derived_dimension.prefix);
					}
				}
				/*shared_ptr<abbreviation> new_actual_dimension_ptr = dynamic_pointer_cast<abbreviation>(new_actual_dimension.second);
				if (new_actual_dimension_ptr)
				{
					value /= new_actual_dimension_ptr->get_factor();
				}*/
			}
			dimensions = new_dimensions;
		}
		else
		{
			cerr << "Cannot change to different base dimensions";
		}
	}

	bool scalar_unit::has_dimensions(const string& dimension_structure) const
	{
		vector<dimension> structure_dimensions = create_dimensions(dimension_structure);
		return has_dimensions(structure_dimensions);
	}

	bool scalar_unit::has_dimensions(const vector<dimension>& x_dimensions) const
	{
		vector<dimension> basic_dimensions = create_derived_dimensions(dimensions);
		vector<dimension> basic_x_dimensions = create_derived_dimensions(dimensions);
		return equal_dimensions(basic_dimensions,basic_x_dimensions);
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
			if(x_dimension.dimension_sign == dimension::positive)
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
		return dimensions;
	}

	string scalar_unit::display(int number_of_decimals) const
	{
		ostringstream output;
		output << display_float(get_value(),number_of_decimals) << " " << display_dimensions();
		return output.str();
	}

	void scalar_unit::add_prefix(const prefix& new_prefix)
	{
		value /= std::pow(new_prefix.get_prefix_base(), new_prefix.get_conversion_factor());
	}

	void scalar_unit::remove_prefix(const prefix& old_prefix)
	{
		value *= std::pow(old_prefix.get_prefix_base(), old_prefix.get_conversion_factor());
	}

	void scalar_unit::set_same_prefix(const vector<dimension>& new_dimensions)
	{
		for(const dimension& x_dimension : dimensions)
		{
			remove_prefix(x_dimension.prefix);
		}
		dimensions.clear();
		for(const dimension& x_new_dimension : new_dimensions)
		{
			add_prefix(x_new_dimension.prefix);
		}
		dimensions = new_dimensions;
	}
	
	void scalar_unit::set_same_prefix(const scalar_unit& x)
	{
		set_same_prefix(x.get_dimensions());
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
			while(isdigit(init_scalar[i]) || init_scalar[i] == '.' || init_scalar[i] == ' ')
			{
				if (init_scalar[i] == ' ')
				{
					break;
				}
				i++;
			}
			string string_value = init_scalar.substr(0, i);
			boost::algorithm::erase_all(string_value, " ");
			value = stof(string_value);
			dimensions = create_dimensions(init_scalar.substr(i));
		}
	}
	
	string to_string(const scalar_unit& x)
	{
		ostringstream output;
		output << x.display(2);
		return output.str();
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
		vector<dimension> new_dimensions = square_dimensions(x.get_dimensions(),2);
		int prefix_scale = prefix_square_difference(x.get_dimensions());
		cout << "prefix_scale: " << prefix_scale << endl;
		float new_value;
		if (prefix_scale != 0)
		{
			new_value = std::sqrt(std::pow(x.get_value(),prefix_scale));
		}
		else
		{
			new_value = std::sqrt(x.get_value());
		}
		return scalar_unit(new_value, new_dimensions);
	}

	scalar_unit sqrt_nth(const scalar_unit& x, int y)
	{
		vector<dimension> new_dimensions = square_dimensions(x.get_dimensions(),y);
		int prefix_scale = prefix_square_difference(x.get_dimensions());
		float new_value = std::pow(std::pow(x.get_value(),prefix_scale), 1 / y);
		return scalar_unit(new_value, new_dimensions);
	}

	bool equal_dimensions(const scalar_unit& x, const scalar_unit& y)
	{
		return x.has_dimensions(y.get_derived_dimensions());
	}
}

bool operator ==(const msci::scalar_unit& x, const msci::scalar_unit& y)
{
	if(x.get_value() == y.get_value() and equal_dimensions(x, y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::scalar_unit& x, const msci::scalar_unit& y)
{
	return !(x == y);
}

bool operator <(const msci::scalar_unit& x, const msci::scalar_unit& y)
{
	if(!equal_dimensions(x, y))
	{
		return false;
	}
	msci::scalar_unit z = x;
	z.set_same_prefix(y.get_dimensions());
	if(z.get_value() < y.get_value())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator >(const msci::scalar_unit& x, const msci::scalar_unit& y)
{
	if(!equal_dimensions(x, y))
	{
		return false;
	}
	msci::scalar_unit z = x;
	z.set_same_prefix(y.get_dimensions());
	if(z.get_value() > y.get_value())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator <=(const msci::scalar_unit& x, const msci::scalar_unit& y)
{
	return !(x > y);
}

bool operator >=(const msci::scalar_unit& x, const msci::scalar_unit& y)
{
	return !(x < y);
}

bool operator ==(const msci::scalar_unit& x, const string& y_init)
{
	msci::scalar_unit y(y_init);
	return (x == y);
}

bool operator !=(const msci::scalar_unit& x, const string& y_init)
{
	return !(x == y_init);
}

bool operator <(const msci::scalar_unit& x, const string& y_init)
{
	msci::scalar_unit y(y_init);
	return (x < y);
}

bool operator >(const msci::scalar_unit& x, const string& y_init)
{
	msci::scalar_unit y(y_init);
	return (x > y);
}

bool operator <=(const msci::scalar_unit& x, const string& y_init)
{
	return !(x > y_init);
}

bool operator >=(const msci::scalar_unit& x, const string& y_init)
{
	return !(x < y_init);
}

bool operator ==(const string& x_init, const msci::scalar_unit& y)
{
	return (y == x_init);
}

bool operator !=(const string& x_init, const msci::scalar_unit& y)
{
	return (y != x_init);
}

bool operator <(const string& x_init, const msci::scalar_unit& y)
{
	msci::scalar_unit x(x_init);
	return (x < y);
}

bool operator >(const string& x_init, const msci::scalar_unit& y)
{
	msci::scalar_unit x(x_init);
	return (x > y);
}

bool operator <=(const string& x_init, const msci::scalar_unit& y)
{
	return !(x_init > y);
}

bool operator >=(const string& x_init, const msci::scalar_unit& y)
{
	return !(x_init < y);
}

void operator +=(string& x, const msci::scalar_unit& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const msci::scalar_unit& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const msci::scalar_unit& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const msci::scalar_unit& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, msci::scalar_unit& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::scalar_unit c(b);
	x = c;
	return is;
}
