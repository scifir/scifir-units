#include "msci/units/units/abbreviation.hpp"
#include "msci/units/units/dimension.hpp"
#include "msci/units/units/dimension_container.hpp"
#include "msci/units/units/conversion.hpp"

#include "boost/algorithm/string/erase.hpp"

#include <map>
#include <string>

using namespace std;

namespace msci
{
	vector_actual_dimensions::vector_actual_dimensions() : map<int,shared_ptr<abstract_dimension>>()
	{
	}

	vector_actual_dimensions::vector_actual_dimensions(const vector_actual_dimensions& actual_dimensions)
	{
		for (const auto& new_actual_dimension : actual_dimensions)
		{
			(*this)[new_actual_dimension.first] = shared_ptr<abstract_dimension>(new_actual_dimension.second->clone());
		}
	}

	vector_real_dimensions::vector_real_dimensions() : map<int,shared_ptr<dimension>>()
	{
	}

	vector_real_dimensions::vector_real_dimensions(const vector_real_dimensions& real_dimensions)
	{
		for (const auto& new_real_dimension : real_dimensions)
		{
			(*this)[new_real_dimension.first] = shared_ptr<dimension>(new_real_dimension.second->clone());
		}
	}

	string get_dimension_structure(const vector_actual_dimensions& actual_dimensions)
	{
		string value;
		for (const auto& actual_dimension : actual_dimensions)
		{
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
		for (const auto& actual_dimension : actual_dimensions)
		{
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
		return value;
	}

	string get_dimension_structure(const vector_real_dimensions& real_dimensions)
	{
		string value;
		for (const auto& real_dimension : real_dimensions)
		{
			if (real_dimension.second->get_scale() > 0)
			{
				if (real_dimension.second->get_scale() > 1)
				{
					value += real_dimension.second->get_symbol() + to_string(real_dimension.second->get_scale()) + "*";
				}
				else
				{
					value += real_dimension.second->get_symbol() + "*";
				}
			}
		}
		value = value.substr(0,value.length() - 1) + "/";
		for (const auto& real_dimension : real_dimensions)
		{
			if (real_dimension.second->get_scale() < 0)
			{
				if (real_dimension.second->get_scale() < -1)
				{
					value += real_dimension.second->get_symbol() + "*";
				}
				else
				{
					value += real_dimension.second->get_symbol() + to_string(real_dimension.second->get_scale()) + "*";
				}
			}
		}
		value = value.substr(0,value.length() - 1);
		return value;
	}

	/// Creates the real dimensions related to the given string
	vector_real_dimensions create_real_dimensions(string init_value)
	{
		vector_real_dimensions dimensions = vector_real_dimensions();
		int new_start = 0;
		int j = new_start;
		boost::algorithm::erase_all(init_value, " ");
		bool numerator = true;
		string new_dimension;
		int new_scale = 1;
		int new_size = 1;
		while(isalnum(init_value[j]) or init_value[j] == '*' or init_value[j] == '/')
		{
			if(isdigit(init_value[j]))
			{
				new_dimension = init_value.substr(new_start, new_size - 1);
				new_scale = stoi(init_value.substr(j, 1));
			}
			else if(!isalnum(init_value[j + 1]))
			{
				new_dimension = init_value.substr(new_start, new_size);
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
			if(!new_dimension.empty())
			{
				dimension* new_dimension_real = create_dimension(new_dimension);
				abbreviation* new_abbreviation_actual;
				if(new_dimension_real != nullptr)
				{
					shared_ptr<dimension> add_dimension (new_dimension_real);
					if(new_scale > 1)
					{
						*add_dimension ^= new_scale;
					}
					if(numerator == false)
					{
						*add_dimension ^= -1;
					}
					dimensions[add_dimension->get_enum_type()] = add_dimension;

					new_abbreviation_actual = nullptr;
				}
				else
				{
					new_abbreviation_actual = create_abbreviation(new_dimension);
				}
				if(new_abbreviation_actual != nullptr)
				{
					vector_real_dimensions abbreviation_dimensions = create_real_dimensions(new_abbreviation_actual->get_dimensions_match());
					for(const auto& map_value : abbreviation_dimensions)
					{
						for(int i = 0; i < abs(new_scale); i++)
						{
							if(dimensions.count(map_value.first) > 0)
							{
								if(numerator == true)
								{
									*dimensions[map_value.first] *= *map_value.second;
								}
								else
								{
									*dimensions[map_value.first] /= *map_value.second;
								}
							}
							else
							{
								dimensions[map_value.first] = map_value.second;
							}
						}
					}
				}
				new_dimension.clear();
				new_scale = 1;
				new_size = 0;
			}
			j++;
			new_size++;
		}
		return dimensions;
	}

	/// Creates the actual dimensions related to the given string
	vector_actual_dimensions create_actual_dimensions(string init_value)
	{
		vector_actual_dimensions dimensions = vector_actual_dimensions();
		int new_start = 0;
		int j = new_start;
		boost::algorithm::erase_all(init_value, " ");
		bool numerator = true;
		string new_dimension;
		int new_scale = 1;
		int new_size = 1;
		while(isalnum(init_value[j]) or init_value[j] == '*' or init_value[j] == '/')
		{
			if(isdigit(init_value[j]))
			{
				new_dimension = init_value.substr(new_start, new_size - 1);
				new_scale = stoi(init_value.substr(j, 1));
			}
			else if(!isalnum(init_value[j + 1]))
			{
				new_dimension = init_value.substr(new_start, new_size);
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
			if(!new_dimension.empty())
			{
				dimension* new_dimension_real = create_dimension(new_dimension);
				abbreviation* new_abbreviation_actual;
				if(new_dimension_real != nullptr)
				{
					shared_ptr<dimension> add_dimension (create_dimension(new_dimension));
					if(new_scale > 1)
					{
						*add_dimension ^= new_scale;
					}
					if(numerator == false)
					{
						*add_dimension ^= -1;
					}
					dimensions[add_dimension->get_enum_type()] = add_dimension;

					new_abbreviation_actual = nullptr;
				}
				else
				{
					new_abbreviation_actual = create_abbreviation(new_dimension);
				}
				if(new_abbreviation_actual != nullptr)
				{
					shared_ptr<abbreviation> add_abbreviation (new_abbreviation_actual);
					if(new_scale > 1)
					{
						*add_abbreviation ^= new_scale;
					}
					if(numerator == false)
					{
						*add_abbreviation ^= -1;
					}
					dimensions[add_abbreviation->get_enum_type()] = add_abbreviation;
				}
				new_dimension.clear();
				new_scale = 1;
				new_size = 0;
			}
			j++;
			new_size++;
		}
		return dimensions;
	}

	vector_actual_dimensions multiply_actual_dimensions(const vector_actual_dimensions& x,const vector_actual_dimensions& y)
	{
		vector_actual_dimensions new_actual_dimensions = x;
		for(const auto& key : y)
		{
			if(new_actual_dimensions.count(key.first))
			{
				*new_actual_dimensions[key.first] *= *key.second;
				if(new_actual_dimensions[key.first]->get_scale() == 0)
				{
					new_actual_dimensions.erase(key.first);
				}
			}
			else
			{
				new_actual_dimensions[key.first] = key.second;
			}
		}
		return move(new_actual_dimensions);
	}

	vector_real_dimensions multiply_real_dimensions(const vector_real_dimensions& x,const vector_real_dimensions& y)
	{
		vector_real_dimensions new_real_dimensions = x;
		for(const auto& key : y)
		{
			if(new_real_dimensions.count(key.first))
			{
				*new_real_dimensions[key.first] *= *key.second;
				if(new_real_dimensions[key.first]->get_scale() == 0)
				{
					new_real_dimensions.erase(key.first);
				}
			}
			else
			{
				new_real_dimensions[key.first] = key.second;
			}
		}
		return move(new_real_dimensions);
	}

	vector_actual_dimensions divide_actual_dimensions(const vector_actual_dimensions& x,const vector_actual_dimensions& y)
	{
		vector_actual_dimensions new_actual_dimensions = x;
		for(const auto& key : y)
		{
			if(new_actual_dimensions.count(key.first))
			{
				*new_actual_dimensions[key.first] /= *key.second;
				if(new_actual_dimensions[key.first]->get_scale() == 0)
				{
					new_actual_dimensions.erase(key.first);
				}
			}
			else
			{
				new_actual_dimensions[key.first] = key.second;
				*new_actual_dimensions[key.first] ^= -1;
			}
		}
		return move(new_actual_dimensions);
	}

	vector_real_dimensions divide_real_dimensions(const vector_real_dimensions& x,const vector_real_dimensions& y)
	{
		vector_real_dimensions new_real_dimensions = x;
		for(const auto& key : y)
		{
			if(new_real_dimensions.count(key.first))
			{
				*new_real_dimensions[key.first] /= *key.second;
				if(new_real_dimensions[key.first]->get_scale() == 0)
				{
					new_real_dimensions.erase(key.first);
				}
			}
			else
			{
				new_real_dimensions[key.first] = key.second;
				*new_real_dimensions[key.first] ^= -1;
			}
		}
		return move(new_real_dimensions);
	}

	vector_actual_dimensions power_actual_dimensions(const vector_actual_dimensions& actual_dimensions,int scale)
	{
		vector_actual_dimensions new_actual_dimensions = vector_actual_dimensions();
		for (auto& dimension : actual_dimensions)
		{
			auto new_dimension = dimension.second;
			*new_dimension ^= scale;
			new_actual_dimensions[dimension.first] = new_dimension;
		}
		return new_actual_dimensions;
	}

	vector_real_dimensions power_real_dimensions(const vector_real_dimensions& real_dimensions,int scale)
	{
		vector_real_dimensions new_real_dimensions = vector_real_dimensions();
		for (auto& dimension : real_dimensions)
		{
			auto new_dimension = dimension.second;
			*new_dimension ^= scale;
			new_real_dimensions[dimension.first] = new_dimension;
		}
		return new_real_dimensions;
	}
}

ostream& operator <<(ostream& os, const msci::vector_real_dimensions& x)
{
	ostringstream dimension_text;
	ostringstream dimension_up_text;
	ostringstream dimension_down_text;
	for(const auto& real_dimension : x)
	{
		if(real_dimension.second->get_scale() > 0)
		{
			dimension_up_text << *real_dimension.second << " ";
		}
		else
		{
			dimension_down_text << *real_dimension.second << " ";
		}
	}
	if(dimension_up_text.tellp() > 0 and dimension_down_text.tellp() > 0)
	{
		dimension_text << dimension_up_text.str() << "/ " << dimension_down_text.str();
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
	return os << dimension_text.str();
}

ostream& operator <<(ostream& os, const msci::vector_actual_dimensions& x)
{
	ostringstream dimension_text;
	ostringstream dimension_up_text;
	ostringstream dimension_down_text;
	for(const auto& actual_dimension : x)
	{
		if(actual_dimension.second->get_scale() > 0)
		{
			dimension_up_text << *actual_dimension.second << " ";
		}
		else
		{
			dimension_down_text << *actual_dimension.second << " ";
		}
	}
	if(dimension_up_text.tellp() > 0 and dimension_down_text.tellp() > 0)
	{
		dimension_text << dimension_up_text.str() << "/ " << dimension_down_text.str();
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
	return os << dimension_text.str();
}
