#include "units/dimension.hpp"

#include "units/custom_dimension.hpp"

#include "boost/algorithm/string.hpp"

#include <cmath>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
using namespace std;

namespace msci
{
	dimension::dimension() : prefix(),dimension_type(),dimension_sign()
	{}
	
	dimension::dimension(const dimension& x) : prefix(x.prefix),dimension_type(x.dimension_type),dimension_sign(x.dimension_sign)
	{}
	
	dimension::dimension(dimension&& x) : prefix(move(x.prefix)),dimension_type(move(x.dimension_type)),dimension_sign(move(x.dimension_sign))
	{}

	dimension::dimension(dimension::type new_dimension_type,msci::prefix::type new_prefix,dimension::sign new_sign) : prefix(new_prefix),dimension_type(new_dimension_type),dimension_sign(new_sign)
	{}

	dimension::dimension(dimension::type new_dimension_type,const msci::prefix& new_prefix,dimension::sign new_sign) : prefix(new_prefix),dimension_type(new_dimension_type),dimension_sign(new_sign)
	{}

	dimension& dimension::operator=(const dimension& x)
	{
		prefix = x.prefix;
		dimension_type = x.dimension_type;
		dimension_sign = x.dimension_sign;
		return *this;
	}
	
	dimension& dimension::operator=(dimension&& x)
	{
		prefix = move(x.prefix);
		dimension_type = move(x.dimension_type);
		dimension_sign = move(x.dimension_sign);
		return *this;
	}

	string dimension::get_name() const
	{
		switch(dimension_type)
		{
			case dimension::m:
				return "meter";
			case dimension::angle:
				return "angle";
			case dimension::solid_angle:
				return "solid angle";
			case dimension::g:
				return "gram";
			case dimension::s:
				return "second";
			case dimension::C:
				return "coulomb";
			case dimension::K:
				return "kelvin";
			case dimension::mol:
				return "mole";
			case dimension::cd:
				return "candela";
			case dimension::B:
				return "byte";
			case dimension::custom:
				return static_cast<msci::custom_dimension&>(const_cast<dimension&>(*this)).symbol;
			case dimension::custom_basic:
				return "custom-basic";
		}
		return "";
	}

	string dimension::get_symbol() const
	{
		switch(dimension_type)
		{
			case dimension::m:
				return "m";
			case dimension::angle:
				return "angle";
			case dimension::solid_angle:
				return "solid_angle";
			case dimension::g:
				return "g";
			case dimension::s:
				return "s";
			case dimension::C:
				return "C";
			case dimension::K:
				return "K";
			case dimension::mol:
				return "mol";
			case dimension::cd:
				return "cd";
			case dimension::B:
				return "B";
			case dimension::custom:
				return static_cast<msci::custom_dimension&>(const_cast<dimension&>(*this)).symbol;
			case dimension::custom_basic:
				return "custom-basic";
		}
		return "";
	}

	int dimension::get_scale() const
	{
		if (is_basic_dimension())
		{
			return 1;
		}
		else
		{
			switch(dimension_type)
			{
				case dimension::Hz:
					return 1;
				case dimension::N:
					return 2;
				case dimension::Pa:
					return 2;
				case dimension::J:
					return 2;
				case dimension::W:
					return 2;
				case dimension::A:
					return 2;
				case dimension::V:
					return 2;
				case dimension::F:
					return 2;
				case dimension::Ohm:
					return 2;
				case dimension::S:
					return 2;
				case dimension::Wb:
					return 2;
				case dimension::T:
					return 2;
				case dimension::H:
					return 2;
				case dimension::lm:
					return 2;
				case dimension::lx:
					return 2;
				case dimension::Bq:
					return 2;
				case dimension::Gy:
					return 2;
				case dimension::Sv:
					return 2;
				case dimension::kat:
					return 2;
				case dimension::angstrom:
					return 2;
				case dimension::L:
					return 2;
				case dimension::minute:
					return 2;
				case dimension::h:
					return 2;
				case dimension::d:
					return 2;
				case dimension::AU:
					return 2;
				case dimension::pc:
					return 2;
				case dimension::eV:
					return 2;
				case dimension::Da:
					return 2;
				case dimension::amu:
					return 2;
				case dimension::barn:
					return 2;
				case dimension::M:
					return 2;
				case dimension::particles:
					return 2;
				case dimension::ppm:
					return 2;
				case dimension::ppb:
					return 2;
			}
			return 0;
		}
	}

	int dimension::get_absolute_scale() const
	{
		if (is_basic_dimension())
		{
			return 1;
		}
		else
		{
			switch(dimension_type)
			{
				case dimension::Hz:
					return 1;
				case dimension::N:
					return 4;
				case dimension::Pa:
					return 2;
				case dimension::J:
					return 2;
				case dimension::W:
					return 2;
				case dimension::A:
					return 2;
				case dimension::V:
					return 2;
				case dimension::F:
					return 2;
				case dimension::Ohm:
					return 2;
				case dimension::S:
					return 2;
				case dimension::Wb:
					return 2;
				case dimension::T:
					return 2;
				case dimension::H:
					return 2;
				case dimension::lm:
					return 2;
				case dimension::lx:
					return 2;
				case dimension::Bq:
					return 2;
				case dimension::Gy:
					return 2;
				case dimension::Sv:
					return 2;
				case dimension::kat:
					return 2;
				case dimension::angstrom:
					return 2;
				case dimension::L:
					return 2;
				case dimension::minute:
					return 2;
				case dimension::h:
					return 2;
				case dimension::d:
					return 2;
				case dimension::AU:
					return 2;
				case dimension::pc:
					return 2;
				case dimension::eV:
					return 2;
				case dimension::Da:
					return 2;
				case dimension::amu:
					return 2;
				case dimension::barn:
					return 2;
				case dimension::M:
					return 2;
				case dimension::particles:
					return 2;
				case dimension::ppm:
					return 2;
				case dimension::ppb:
					return 2;
			}
			return 0;
		}
	}

	bool dimension::is_basic_dimension() const
	{
		switch(dimension_type)
		{
			case dimension::m:
				return true;
			case dimension::angle:
				return true;
			case dimension::solid_angle:
				return true;
			case dimension::g:
				return true;
			case dimension::s:
				return true;
			case dimension::C:
				return true;
			case dimension::K:
				return true;
			case dimension::mol:
				return true;
			case dimension::cd:
				return true;
			case dimension::B:
				return true;
		}
		return false;
	}

	bool dimension::is_derived_dimension() const
	{
		return !is_basic_dimension();
	}

	vector<dimension> dimension::get_basic_dimensions() const
	{
		int basic_dimensions_count = get_absolute_scale();
		vector<dimension> basic_dimensions = vector<dimension>();
		switch (dimension_type)
		{
			case dimension::N:
				basic_dimensions.push_back(dimension(dimension::m,prefix::no_prefix,dimension::positive));
				basic_dimensions.push_back(dimension(dimension::g,prefix::no_prefix,dimension::positive));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::negative));
				basic_dimensions.push_back(dimension(dimension::s,prefix::no_prefix,dimension::negative));
				break;
		}
		return basic_dimensions;
	}

	void dimension::invert()
	{
		if (dimension_sign == dimension::positive)
		{
			dimension_sign = dimension::negative;
		}
		else
		{
			dimension_sign = dimension::positive;
		}
	}

	/*float dimension_byte::get_prefix_base() const
	{
		return 10.0793684;
	}*/

	dimension create_dimension(dimension::type x)
	{
		switch(x)
		{
			case dimension::m:
				return dimension(dimension::m,prefix::no_prefix,dimension::positive);
			case dimension::angle:
				return dimension(dimension::m,prefix::no_prefix,dimension::positive);
			case dimension::solid_angle:
				return dimension(dimension::m,prefix::no_prefix,dimension::positive);
			case dimension::g:
				return dimension(dimension::m,prefix::no_prefix,dimension::positive);
			case dimension::s:
				return dimension(dimension::m,prefix::no_prefix,dimension::positive);
			case dimension::C:
				return dimension(dimension::m,prefix::no_prefix,dimension::positive);
			case dimension::K:
				return dimension(dimension::m,prefix::no_prefix,dimension::positive);
			case dimension::mol:
				return dimension(dimension::m,prefix::no_prefix,dimension::positive);
			case dimension::cd:
				return dimension(dimension::m,prefix::no_prefix,dimension::positive);
			case dimension::B:
				return dimension(dimension::m,prefix::no_prefix,dimension::positive);
		}
		return dimension();
	}

	dimension create_dimension(const string& x)
	{
		if (x == "")
		{
			return dimension();
		}
		string dimension_name;
		string prefix_name;
		set<string> prefixes_options {"Y", "E", "P", "T", "G", "M", "k", "h", "d", "c", "m", "u", "n", "p", "f", "a", "z", "y"};
		if(prefixes_options.count(x.substr(0,1)) and x != "angle" and x != "solid_angle" and x != "m" and x.substr(0,2) != "da" and x.substr(0,3) != "mol")
		{
			prefix_name = x.substr(0,1);
			dimension_name = x.substr(1);
		}
		else if(x.substr(0,2) == "da")
		{
			prefix_name = "da";
			dimension_name = x.substr(2);
		}
		else
		{
			prefix_name = "";
			dimension_name = x;
		}
		prefix new_prefix = create_prefix(prefix_name);
		if(dimension_name == "m")
		{
			return dimension(dimension::m,new_prefix,dimension::positive);
		}
		else if(dimension_name == "angle")
		{
			return dimension(dimension::m,new_prefix,dimension::positive);
		}
		else if(dimension_name == "solid_angle")
		{
			return dimension(dimension::m,new_prefix,dimension::positive);
		}
		else if(dimension_name == "g")
		{
			return dimension(dimension::m,new_prefix,dimension::positive);
		}
		else if(dimension_name == "s")
		{
			return dimension(dimension::m,new_prefix,dimension::positive);
		}
		else if(dimension_name == "C")
		{
			return dimension(dimension::m,new_prefix,dimension::positive);
		}
		else if(dimension_name == "K")
		{
			return dimension(dimension::m,new_prefix,dimension::positive);
		}
		else if(dimension_name == "mol")
		{
			return dimension(dimension::m,new_prefix,dimension::positive);
		}
		else if(dimension_name == "cd")
		{
			return dimension(dimension::m,new_prefix,dimension::positive);
		}
		else if(dimension_name == "B")
		{
			return dimension(dimension::m,new_prefix,dimension::positive);
		}
		else
		{
			return custom_dimension(dimension_name);
		}
	}
	
	string get_dimension_structure(const vector<dimension>& actual_dimensions)
	{
		return "";
		/*string value;
		int dimensions_number = sizeof(actual_dimensions) / sizeof(dimension);
		for (int i = 0; i < dimensions_number; i++)
		{
			dimension actual_dimension = actual_dimensions[i];
			if (actual_dimension.second->get_scale() > 0)
			{
				if (actual_dimension.second->get_scale() > 1)
				{
					value += actual_dimension.second->get_symbol() + to_string(actual_dimension.second->get_scale()) + "*";
				}
				else
				{
					value += actual_dimension.second->get_symbol() + "*";
				}
			}
		}
		value = value.substr(0,value.length() - 1) + "/";
		for (int i = 0; i < dimensions_number; i++)
		{
			dimension actual_dimension = actual_dimensions[i];
			if (actual_dimension.second->get_scale() < 0)
			{
				if (actual_dimension.second->get_scale() < -1)
				{
					value += actual_dimension.second->get_symbol() + "*";
				}
				else
				{
					value += actual_dimension.second->get_symbol() + to_string(actual_dimension.second->get_scale()) + "*";
				}
			}
		}
		value = value.substr(0,value.length() - 1);
		return value;*/
	}

	vector<dimension> create_dimensions(string init_value)
	{
		int new_start = 0;
		boost::algorithm::erase_all(init_value, " ");
		bool numerator = true;
		int new_scale = 1;
		int new_size = 1;
		string new_dimension_str;
		vector<dimension> dimensions = vector<dimension>();
		for(int j = 0; j <= new_start; j++)
		{
			if(isdigit(init_value[j]))
			{
				new_dimension_str = init_value.substr(new_start, new_size - 1);
				new_scale = stoi(init_value.substr(j, 1));
			}
			else if(!isalnum(init_value[j + 1]))
			{
				new_dimension_str = init_value.substr(new_start, new_size);
			}
			if(init_value[j] == '*')
			{
				new_start = j + 1;
				new_size = 1;
			}
			else if(init_value[j] == '/')
			{
				numerator = false;
				new_start = j + 1;
				new_size = 1;
			}
			if(!new_dimension_str.empty())
			{
				dimension new_dimension = create_dimension(new_dimension_str);
				for (int k = 0; k < new_scale; k++)
				{
					dimensions.push_back(new_dimension);
				}
				new_dimension_str.clear();
				new_scale = 1;
				new_size = 0;
			}
			j++;
			new_size++;
		}
		return dimensions;
	}

	vector<dimension> create_derived_dimensions(string init_value)
	{
		int new_start = 0;
		int j = new_start;
		boost::algorithm::erase_all(init_value, " ");
		int total_of_dimensions = 0;
		while(isalnum(init_value[j]) or init_value[j] == '*' or init_value[j] == '/')
		{
			total_of_dimensions++;
		}
		bool numerator = true;
		int new_scale = 1;
		int new_size = 1;
		string new_dimension_str;
		vector<dimension> dimensions = vector<dimension>();
		for(int j = 0; j < total_of_dimensions; j++)
		{
			if(isdigit(init_value[j]))
			{
				new_dimension_str = init_value.substr(new_start, new_size - 1);
				new_scale = stoi(init_value.substr(j, 1));
			}
			else if(!isalnum(init_value[j + 1]))
			{
				new_dimension_str = init_value.substr(new_start, new_size);
			}
			if(init_value[j] == '*')
			{
				new_start = j + 1;
				new_size = 0;
			}
			else if(init_value[j] == '/')
			{
				numerator = false;
				new_start = j + 1;
				new_size = 0;
			}
			if(!new_dimension_str.empty())
			{
				dimension new_dimension = create_dimension(new_dimension_str);
				for (int k = 0; k < new_scale; k++)
				{
					dimensions.push_back(new_dimension);
				}
				new_dimension_str.clear();
				new_scale = 1;
				new_size = 0;
			}
			j++;
			new_size++;
		}
		return dimensions;
	}

	vector<dimension> create_derived_dimensions(const vector<dimension>& x)
	{
		vector<dimension> new_x = vector<dimension>();
		for(int i = 0; i < x.size(); i++)
		{
			if (x[i].is_derived_dimension())
			{
				vector<dimension> x_subdimensions = x[i].get_basic_dimensions();
				for (const dimension& x_subdimension : x_subdimensions)
				{
					new_x.push_back(x_subdimension);
				}
			}
			else
			{
				new_x.push_back(x[i]);
			}
		}
		return new_x;
	}

	vector<dimension> multiply_dimensions(const vector<dimension>& x,const vector<dimension>& y)
	{
		vector<dimension> new_dimensions = vector<dimension>();
		for(const dimension& x_dimension: x)
		{
			new_dimensions.push_back(x_dimension);
		}
		for(const dimension& y_dimension : y)
		{
			new_dimensions.push_back(y_dimension);
		}
		return new_dimensions;
	}

	vector<dimension> divide_dimensions(const vector<dimension>& x,const vector<dimension>& y)
	{
		vector<dimension> new_dimensions = vector<dimension>();
		for(const dimension& x_dimension: x)
		{
			new_dimensions.push_back(x_dimension);
		}
		for(dimension y_dimension : y)
		{
			y_dimension.invert();
			new_dimensions.push_back(y_dimension);
		}
		return normalize_dimensions(new_dimensions);
	}

	vector<dimension> power_dimensions(const vector<dimension>& x,int scale)
	{
		vector<dimension> new_dimensions = vector<dimension>();
		for (const dimension& x_dimension: x)
		{
			for (int j = 1; j <= scale; j++)
			{
				new_dimensions.push_back(x_dimension);
			}
		}
		return new_dimensions;
	}

	vector<dimension> normalize_dimensions(const vector<dimension>& x)
	{
		vector<int> skip_dimensions = vector<int>();
		vector<dimension> new_x = create_derived_dimensions(x);
		for(int i = 0; i < new_x.size(); i++)
		{
			dimension x_dimension = new_x[i];
			for(int j = i; j < new_x.size(); j++)
			{
				dimension y_dimension = new_x[j];
				if (x_dimension.dimension_type == y_dimension.dimension_type and x_dimension.dimension_sign != y_dimension.dimension_sign)
				{
					skip_dimensions.push_back(i);
					skip_dimensions.push_back(j);
				}
			}
		}
		vector<dimension> new_dimensions = vector<dimension>();
		for(int i = 0; i < new_x.size(); i++)
		{
			bool skip = false;
			for(int j = 0; j < skip_dimensions.size(); j++)
			{
				if (i == skip_dimensions[j])
				{
					skip = true;
				}
			}
			if (!skip)
			{
				new_dimensions.push_back(new_x[i]);
			}
		}
		return new_dimensions;
	}

	bool equal_dimensions(const vector<dimension>& x,const vector<dimension>& y)
	{
		vector<int> skip = vector<int>();
		for (const dimension& x_dimension: x)
		{
			bool is_equal = false;
			for (int j = 0; j < y.size(); j++)
			{
				bool skip_j = false;
				if (skip.size() > 0)
				{
					for (int k = 0; k < skip.size(); k++)
					{
						if (j == skip[k])
						{
							skip_j = true;
						}
					}
				}
				if (skip_j)
				{
					continue;
				}
				if (x_dimension == y[j])
				{
					skip.push_back(j);
					is_equal = true;
				}
			}
			if (!is_equal)
			{
				return false;
			}
		}
		return true;
	}
}

bool operator==(const msci::dimension& x,const msci::dimension& y)
{
	if (x.dimension_type == y.dimension_type and x.dimension_sign == y.dimension_sign)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const msci::dimension& x,const msci::dimension& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os, const msci::dimension& x)
{
	return os << x.prefix.get_symbol() << x.get_symbol();
}
