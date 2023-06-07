#include "units/custom_dimension.hpp"

using namespace std;

namespace msci
{
/*	map<string,vector<dimension>> custom_dimension::base_dimensions = map<string,vector<dimension>>();

	custom_dimension::custom_dimension() : dimension(dimension::custom,prefix::no_prefix,dimension::positive),symbol()
	{}

	custom_dimension::custom_dimension(const custom_dimension& x) : dimension(x),symbol(x.symbol)
	{}

	custom_dimension::custom_dimension(custom_dimension&& x) : dimension(x),symbol(move(x.symbol))
	{}

	custom_dimension::custom_dimension(const string& x,const msci::prefix& new_prefix,dimension::sign new_sign) : dimension(dimension::custom,new_prefix,new_sign),symbol(x)
	{}

	string custom_dimension::get_custom_name() const
	{
		return symbol;
	}

	string custom_dimension::get_custom_symbol() const
	{
		return symbol;
	}
	
	string custom_dimension::get_symbol() const
	{
		return symbol;
	}
	
	bool custom_dimension::is_basic_dimension() const
	{
		if (custom_dimension::base_dimensions.size() == 1)
		{
			return custom_dimension::base_dimensions[symbol][0].is_basic_dimension();
		}
		else
		{
			return false;
		}
	}

	bool custom_dimension::is_custom_basic_dimension() const
	{
		if (custom_dimension::base_dimensions.size() == 1)
		{
			return (custom_dimension::base_dimensions[symbol][0].dimension_type == dimension::custom_basic);
		}
		else
		{
			return false;
		}
	}

	bool custom_dimension::is_custom_conversion() const
	{
		if (custom_dimension::base_dimensions[symbol].size() == 1)
		{
			return (custom_dimension::base_dimensions[symbol][0].dimension_type != dimension::custom_basic and custom_dimension::base_dimensions[symbol][0].dimension_type != dimension::custom);
		}
		else
		{
			return false;
		}
	}

	bool custom_dimension::is_custom_abbreviation() const
	{
		if (custom_dimension::base_dimensions[symbol].size() == 1)
		{
			return (custom_dimension::base_dimensions[symbol][0].dimension_type != dimension::custom_basic and custom_dimension::base_dimensions[symbol][0].dimension_type != dimension::custom);
		}
		else if (custom_dimension::base_dimensions[symbol].size() > 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}*/
}
