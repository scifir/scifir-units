#include "abbreviation.hpp"
#include "dimension.hpp"
#include "dimension_container.hpp"
#include "conversion.hpp"

#include <map>
#include <string>

using namespace std;

namespace physics::units
{
	vector_actual_dimensions::vector_actual_dimensions() : map<int,shared_ptr<dimension_abstract>>()
	{
	}

	vector_actual_dimensions::vector_actual_dimensions(const vector_actual_dimensions& actual_dimensions)
	{
		for (const auto& new_actual_dimension : actual_dimensions)
		{
			(*this)[new_actual_dimension.first] = shared_ptr<dimension_abstract>(new_actual_dimension.second->clone());
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
}
