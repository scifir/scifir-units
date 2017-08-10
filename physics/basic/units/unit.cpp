#include "abbreviation.hpp"
#include "conversion.hpp"
#include "dimension_container.hpp"
#include "unit.hpp"
#include "unit_basic.hpp"
#include "prefix.hpp"

#include "boost/algorithm/string/erase.hpp"
#include <boost/algorithm/string.hpp>

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <locale>
#include <map>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>
using namespace std;

namespace physics::units
{
	unit::unit() : value(math::number::unit_number(0)), actual_dimensions(vector_actual_dimensions())
	{
	}

	unit::unit(math::topology::space_type new_value, string dimension_structure) : unit()
	{
		value = math::number::unit_number(new_value);
		initialize_dimensions(dimension_structure);
	}

	/*unit::unit(math::topology::space_type new_value, dimension_symbol dimension_name, prefix_symbol prefix_name) : unit()
	{
		shared_ptr<dimension> new_dimension = shared_ptr<dimension>(create_dimension(dimension_name));
		real_dimensions[dimension_name] = new_dimension;
		new_dimension->change_prefix(prefix_name);
		actual_dimensions[dimension_name] = new_dimension;
		value = new_value;
	}*/

	unit::unit(math::number::unit_number new_value, vector_real_dimensions new_real_dimensions, const vector_actual_dimensions& new_actual_dimensions) : unit()
	{
		value = move(new_value);
		actual_dimensions = move(new_actual_dimensions);
	}

	unit::unit(const unit& new_value,string init_value) : unit(new_value)
	{
		change_dimensions(init_value);
	}

	unit::unit(string init_value) : unit()
	{
		if(!isdigit(init_value[0]))
		{
			throw invalid_argument("Unit string bad defined: '" + init_value + "'");
		}
		else
		{
			int i = 0;
			while(isdigit(init_value[i]) || init_value[i] == '.')
			{
				i++;
			}
			value = math::number::unit_number(stof(init_value.substr(0, i)));
			if(init_value[i] != ' ')
			{
				throw invalid_argument("Unit string must have the value separated from units with a single space");
			}
			initialize_dimensions(init_value.substr(i));
		}
	}

	auto_unit unit::operator +(const unit& x)
	{
		if(x.equal_dimensions(get_real_dimensions()))
		{
			auto_unit a = *this;
			auto_unit y = x;
			y.set_same_prefix(unit::get_actual_dimensions());
			a += y.get_value().get_value();
			return move(a);
		}
		else
		{
			auto_unit y = auto_unit(0);
			y.invalidate(8);
			return move(y);
		}
	}

	auto_unit unit::operator -(const unit& x)
	{
		if(x.equal_dimensions(get_real_dimensions()))
		{
			auto_unit a = *this;
			auto_unit y = x;
			y.set_same_prefix(unit::get_actual_dimensions());
			a -= y.get_value().get_value();
			return move(a);
		}
		else
		{
			auto_unit y = auto_unit(0);
			y.invalidate(9);
			return move(y);
		}
	}

	auto_unit unit::operator *(const unit& x)
	{
		math::number::unit_number new_value = value;
		auto_unit y = x;
		if(y.equal_dimensions(get_real_dimensions()))
		{
			y.set_same_prefix(get_actual_dimensions());
		}
		new_value *= y.get_value().get_value();
		vector_real_dimensions new_real_dimensions = multiply_real_dimensions(get_real_dimensions(),y.get_real_dimensions());
		vector_actual_dimensions new_actual_dimensions = multiply_actual_dimensions(get_actual_dimensions(),y.get_actual_dimensions());
		/*vector_real_dimensions new_real_dimensions = get_real_dimensions();
		for(auto& key : y.get_real_dimensions())
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
		vector_actual_dimensions new_actual_dimensions = get_actual_dimensions();
		for(auto& key : y.get_actual_dimensions())
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
		}*/
		return move(auto_unit(new_value, new_real_dimensions, new_actual_dimensions));
	}

	auto_unit unit::operator /(const unit& x)
	{
		math::number::unit_number new_value = value;
		auto_unit y = x;
		if(y.equal_dimensions(get_real_dimensions()))
		{
			y.set_same_prefix(unit::get_actual_dimensions());
		}
		new_value /= y.get_value().get_value();
		vector_real_dimensions new_real_dimensions = divide_real_dimensions(get_real_dimensions(),y.get_real_dimensions());
		vector_actual_dimensions new_actual_dimensions = divide_actual_dimensions(get_actual_dimensions(),y.get_actual_dimensions());
		/*vector_real_dimensions new_real_dimensions = get_real_dimensions();
		for(const auto& key : y.get_real_dimensions())
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
		vector_actual_dimensions new_actual_dimensions = get_actual_dimensions();
		for(const auto& key : y.get_actual_dimensions())
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
		}*/
		return move(auto_unit(new_value, new_real_dimensions, new_actual_dimensions));
	}

	auto_unit unit::operator ^(const unit& x)
	{
		if(empty_dimensions())
		{
			auto_unit y = *this;
			if(unit::empty_dimensions())
			{
				y ^= int(x.get_value().get_value());
			}
			return move(y);
		}
		else
		{
			auto_unit y = auto_unit(0);
			y.invalidate(10);
			return move(y);
		}
	}

	void unit::operator +=(const unit& x)
	{
		if(!x.equal_dimensions(get_real_dimensions()))
		{
			invalidate(8);
		}
		unit::value += x.get_value();
	}

	void unit::operator -=(const unit& x)
	{
		if(!x.equal_dimensions(get_real_dimensions()))
		{
			invalidate(9);
		}
		unit::value -= x.get_value();
	}

	unit& unit::operator++()
	{
		value++;
		return *this;
	}

	unit& unit::operator++(int)
	{
		unit& tmp(*this);
		operator++();
		return tmp;
	}

	unit& unit::operator--()
	{
		value--;
		return *this;
	}

	unit& unit::operator--(int)
	{
		unit& tmp(*this);
		operator--();
		return tmp;
	}

	/// Sets the dimensions to the dimensions given string. It invalidates the object if the dimensions aren't compatible with the real dimensions
	void unit::change_dimensions(string new_dimensions)
	{
		if(equal_dimensions(new_dimensions))
		{
			for(auto& actual_dimension : actual_dimensions)
			{
				remove_prefix(actual_dimension.second->get_dimension_prefixes());
				abbreviation* new_actual_abbreviation = create_abbreviation(actual_dimension.second->get_symbol());
				if(new_actual_abbreviation != nullptr)
				{
					shared_ptr<abbreviation> actual_abbreviation = shared_ptr<abbreviation>(new_actual_abbreviation);
					auto_unit abbreviation_unit("1 " + actual_abbreviation->get_dimensions_match());
					for(auto& actual_dimension2 : abbreviation_unit.get_actual_dimensions())
					{
						remove_prefix(actual_dimension2.second->get_dimension_prefixes());
					}
				}
			}
			actual_dimensions.empty();
			vector_actual_dimensions new_actual_dimensions = create_actual_dimensions(new_dimensions);
			for(auto& new_actual_dimension : new_actual_dimensions)
			{
				add_prefix(new_actual_dimension.second->get_dimension_prefixes());
				abbreviation* new_actual_abbreviation = create_abbreviation(new_actual_dimension.second->get_symbol());
				if(new_actual_abbreviation != nullptr)
				{
					shared_ptr<abbreviation> actual_abbreviation = shared_ptr<abbreviation>(new_actual_abbreviation);
					auto_unit abbreviation_unit("1 " + actual_abbreviation->get_dimensions_match());
					for(auto& actual_dimension2 : abbreviation_unit.get_actual_dimensions())
					{
						add_prefix(actual_dimension2.second->get_dimension_prefixes());
					}
				}
			}
			actual_dimensions = new_actual_dimensions;
		}
		else
		{
			invalidate(11);
		}
	}

	/// Calculates if the dimensions are equal related to the given string
	bool unit::equal_dimensions(string dimension_structure) const
	{
		vector_real_dimensions structure_dimensions = create_real_dimensions(dimension_structure);
		return equal_dimensions(structure_dimensions);
	}

	/// Calculates if the dimensions are equal related to the symbol
	bool unit::equal_dimensions(dimension_symbol new_dimension) const
	{
		vector_real_dimensions real_dimensions = get_real_dimensions();
		if(real_dimensions.count(new_dimension) == 1 and real_dimensions.at(new_dimension)->get_scale() == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	/// Calculates if the dimensions are equal related to the real dimensions map
	bool unit::equal_dimensions(const vector_real_dimensions& second_dimensions) const
	{
		vector_real_dimensions real_dimensions_tmp = get_real_dimensions();
		if(real_dimensions_tmp.size() == second_dimensions.size())
		{
			for(const auto& key : second_dimensions)
			{
				if(real_dimensions_tmp.count(key.first) == 0 or *real_dimensions_tmp[key.first] != *key.second)
				{
					wcout << "here!" << endl;
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	/// Returns true if the dimensions are empty
	bool unit::empty_dimensions() const
	{
		if(get_real_dimensions().size() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	/// Returns the actual dimensions map
	const vector_actual_dimensions& unit::get_actual_dimensions() const
	{
		return actual_dimensions;
	}

	/// Returns the unit_number that stores the value
	const math::number::unit_number& unit::get_value() const
	{
		return value;
	}

	/// Returns true if the unit is defined
	bool unit::is_defined() const
	{
		return value.is_defined();
	}

	/// Invalidates the function
	void unit::invalidate(int x)
	{
		value.invalidate(x);
	}

	/// Updates the value to the prefix added
	void unit::add_prefix(shared_ptr<prefix> new_prefix)
	{
		value /= pow(10, new_prefix->get_conversion_factor() * new_prefix->scale);
	}

	/// Updates the value to the set of prefixes added
	void unit::add_prefix(dimension_prefixes new_prefixes)
	{
		for(auto& map_value : new_prefixes)
		{
			add_prefix(map_value.second);
		}
	}

	/// Updates the value to the prefix removed
	void unit::remove_prefix(shared_ptr<prefix> old_prefix)
	{
		value *= pow(10, old_prefix->get_conversion_factor() * old_prefix->scale);
	}

	/// Updates the value to the set of prefixes removed
	void unit::remove_prefix(dimension_prefixes new_prefixes)
	{
		for(auto& map_value : new_prefixes)
		{
			remove_prefix(map_value.second);
		}
	}

	/// Updates the prefixes of the unit to the actual dimensions given
	void unit::set_same_prefix(const vector_actual_dimensions& new_dimensions)
	{
		for(const auto& map_value : actual_dimensions)
		{
			remove_prefix(map_value.second->get_dimension_prefixes());
		}
		actual_dimensions.clear();
		for(const auto& map_value : new_dimensions)
		{
			add_prefix(map_value.second->get_dimension_prefixes());
			actual_dimensions[map_value.second->get_enum_type()] = map_value.second;
		}
	}

	/// Creates the real dimensions and the actual dimensions that the function gives
	void unit::initialize_dimensions(string init_value)
	{
		//wcout << "initialize dimensions: " << init_value.c_str() << endl;
		int new_start = 0;
		int j = new_start;
		boost::algorithm::erase_all(init_value, " ");
		bool numerator = true;
		string new_dimension;
		int new_scale = 1;
		int new_size = 1;
		while(isalnum(init_value[j]) or init_value[j] == '*' or init_value[j] == '/' or init_value[j] == '_')
		{
			if(isdigit(init_value[j]))
			{
				new_dimension = init_value.substr(new_start, new_size - 1);
				new_scale = stoi(init_value.substr(j, 1));
			}
			else if(!(isalnum(init_value[j + 1]) or init_value[j + 1] == '_'))
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
					shared_ptr<dimension> real_dimension = shared_ptr<dimension>(new_dimension_real);
					shared_ptr<dimension> actual_dimension = shared_ptr<dimension>(create_dimension(new_dimension));
					if(new_scale > 1)
					{
						*real_dimension ^= new_scale;
						*actual_dimension ^= new_scale;
					}
					if(numerator == false)
					{
						*real_dimension ^= -1;
						*actual_dimension ^= -1;
					}
					actual_dimensions[actual_dimension->get_enum_type()] = actual_dimension;
					//real_dimensions[real_dimension->get_enum_type()] = real_dimension;

					new_abbreviation_actual = nullptr;
				}
				else
				{
					new_abbreviation_actual = create_abbreviation(new_dimension);
				}
				if(new_abbreviation_actual != nullptr)
				{
					shared_ptr<abbreviation> add_abbreviation = shared_ptr<abbreviation>(new_abbreviation_actual);
					if(new_scale > 1)
					{
						*add_abbreviation ^= new_scale;
					}
					if(numerator == false)
					{
						*add_abbreviation ^= -1;
					}
					actual_dimensions[add_abbreviation->get_enum_type()] = add_abbreviation;
					vector_real_dimensions abbreviation_dimensions = create_real_dimensions(add_abbreviation->get_dimensions_match());
					/*for(const auto& map_value : abbreviation_dimensions)
					{
						for(int i = 0; i < abs(new_scale); i++)
						{
							if(real_dimensions.count(map_value.first) > 0)
							{
								if(numerator == true)
								{
									*real_dimensions[map_value.first] *= *map_value.second;
								}
								else
								{
									*real_dimensions[map_value.first] /= *map_value.second;
								}
							}
							else
							{
								real_dimensions[map_value.first] = map_value.second;
							}
						}
					}*/
				}
				else if(get_conversion.count(new_dimension) > 0)
				{
					conversion new_conversion = get_conversion[new_dimension];
					if(numerator == true)
					{
						value *= new_conversion.factor * new_scale;
					}
					else
					{
						value /= new_conversion.factor * new_scale;
					}
					dimension* new_dimension_real = create_dimension(new_conversion.unit_to);
					abbreviation* new_abbreviation_actual;
					if(new_dimension_real != nullptr)
					{
						shared_ptr<dimension> real_dimension = shared_ptr<dimension>(new_dimension_real);
						shared_ptr<dimension> actual_dimension = shared_ptr<dimension>(create_dimension(new_conversion.unit_to));
						if(new_scale > 1)
						{
							*real_dimension ^= new_scale;
							*actual_dimension ^= new_scale;
						}
						if(numerator == false)
						{
							*real_dimension ^= -1;
							*actual_dimension ^= -1;
						}
						//real_dimensions[real_dimension->get_enum_type()] = real_dimension;
						actual_dimensions[actual_dimension->get_enum_type()] = actual_dimension;

						new_abbreviation_actual = nullptr;
					}
					else
					{
						new_abbreviation_actual = create_abbreviation(new_conversion.unit_to);
					}
					if(new_abbreviation_actual != nullptr)
					{
						shared_ptr<abbreviation> add_abbreviation = shared_ptr<abbreviation>(new_abbreviation_actual);
						if(new_scale > 1)
						{
							*add_abbreviation ^= new_scale;
						}
						if(numerator == false)
						{
							*add_abbreviation ^= -1;
						}
						actual_dimensions[add_abbreviation->get_enum_type()] = add_abbreviation;
						vector_real_dimensions abbreviation_dimensions = create_real_dimensions(add_abbreviation->get_dimensions_match());
						/*for(const auto& map_value : abbreviation_dimensions)
						{
							for(int i = 0; i < abs(new_scale); i++)
							{
								if(real_dimensions.count(map_value.first) > 0)
								{
									if(numerator == true)
									{
										*real_dimensions[map_value.first] *= *map_value.second;
									}
									else
									{
										*real_dimensions[map_value.first] /= *map_value.second;
									}
								}
								else
								{
									real_dimensions[map_value.first] = map_value.second;
								}
							}
						}*/
					}
				}
				new_dimension.clear();
				new_scale = 1;
				new_size = 0;
			}
			j++;
			new_size++;
		}
	}

	string unit::initial_dimensions_get_structure(string init_value) const
	{
		if(!isdigit(init_value[0]))
		{
			throw invalid_argument("Unit string bad defined: '" + init_value + "'");
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
				throw invalid_argument("Unit string must have the value separated from units with a single space");
			}
			return init_value.substr(i);
		}
	}

	/// \deprecated
	/// Deprecated in order for the dimensions() function to be used only
	void unit::set_prefix(prefix_symbol prefix_type)
	{
		/*if(real_dimensions.size() == 1)
		{
			shared_ptr<dimension_abstract> old_dimension = actual_dimensions.begin()->second;
			actual_dimensions.begin()->second->change_prefix(prefix_type);
			shared_ptr<dimension_abstract> new_dimension = actual_dimensions.begin()->second;
			swap_prefix(old_dimension, new_dimension);
		}*/
	}

	/// \deprecated
	/// Deprecated in order for the dimensions() function to be used only
	void unit::set_prefix(dimension_symbol dimension_type, prefix_symbol prefix_type)
	{
		shared_ptr<dimension_abstract> old_dimension = actual_dimensions[dimension_type];
		actual_dimensions[dimension_type]->change_prefix(prefix_type);
		shared_ptr<dimension_abstract> new_dimension = actual_dimensions[dimension_type];
		swap_prefix(old_dimension, new_dimension);
	}

	/// \deprecated
	/// Deprecated in order for the dimensions() function to be used only
	void unit::add_abbreviation(abbreviation_symbol abbreviation_name)
	{
		shared_ptr<abbreviation> new_abbreviation = shared_ptr<abbreviation>(create_abbreviation(abbreviation_name));
		if(valid_abbreviation(new_abbreviation))
		{
			vector_actual_dimensions abbreviation_dimensions = create_actual_dimensions(new_abbreviation->get_dimensions_match());
			for(const auto& abbreviation_dimension : abbreviation_dimensions)
			{
				remove_prefix(actual_dimensions[abbreviation_dimension.second->get_enum_type()]->get_dimension_prefixes());
				add_prefix(abbreviation_dimension.second->get_dimension_prefixes());
				actual_dimensions.erase(abbreviation_dimension.second->get_enum_type());
			}
			add_prefix(new_abbreviation->get_dimension_prefixes());
			actual_dimensions[new_abbreviation->get_enum_type()] = new_abbreviation;
			//actual_dimensions[container::get_all_dimension(new_abbreviation->get_symbol())] = new_abbreviation;
			value /= new_abbreviation->get_factor();
		}
	}

	/// \deprecated
	/// Deprecated in order for the dimensions() function to be used only
	void unit::add_abbreviation(abbreviation_symbol abbreviation_name, prefix_symbol new_prefix)
	{
		add_abbreviation(abbreviation_name);
		actual_dimensions[abbreviation_name]->change_prefix(normal_prefix, new_prefix);
		swap_prefix(normal_prefix, new_prefix);
	}

	/// \deprecated
	/// Deprecated in order for the dimensions() function to be used only
	void unit::change_abbreviation(abbreviation_symbol old_abbreviation_name, abbreviation_symbol new_abbreviation_name)
	{
		shared_ptr<abbreviation> new_abbreviation = shared_ptr<abbreviation>(create_abbreviation(new_abbreviation_name));
		if(valid_abbreviation_real(new_abbreviation))
		{
			delete_internal_abbreviation(old_abbreviation_name);
			add_internal_abbreviation(new_abbreviation_name);
		}
	}

	/// \deprecated
	/// Calculates if the abbreviation is valid related to the actual dimensions
	/// Fix: This function should calculate related to the actual dimensions and not to the real dimensions
	bool unit::valid_abbreviation(shared_ptr<abbreviation> new_abbreviation)
	{
		vector_real_dimensions abbreviation_dimensions = create_real_dimensions(new_abbreviation->get_dimensions_match());
		/*for(auto& map_value : abbreviation_dimensions)
		{
			bool find = false;
			for(auto& map_value2 : actual_dimensions)
			{
				if (dimension_enum.count(map_value2.second->get_symbol()) > 0)
				{
					if (map_value.second->get_symbol() == map_value2.second->get_symbol() and map_value.second->get_scale() <= map_value2.second->get_scale())
					{
						find = true;
					}
				}
			}
			if(find == false)
			{
				return false;
			}
		}*/
		return true;
	}

	/// \deprecated
	/// Calculates if the abbreviation is valid related to the real dimensions
	bool unit::valid_abbreviation_real(shared_ptr<abbreviation> new_abbreviation)
	{
		vector_real_dimensions abbreviation_dimensions = create_real_dimensions(new_abbreviation->get_dimensions_match());
		return equal_dimensions(abbreviation_dimensions);
	}

	/// \deprecated
	/// Updates the value related to the added dimension and the removed dimension
	void unit::swap_prefix(shared_ptr<dimension_abstract> old_dimension, shared_ptr<dimension_abstract> new_dimension)
	{
		value *= pow(10, old_dimension->total_factor());
		value /= pow(10, new_dimension->total_factor());
	}

	/// \deprecated
	/// Updates the value related to the added prefix and the removed prefix
	void unit::swap_prefix(prefix_symbol old_prefix_name, prefix_symbol new_prefix_name)
	{
		shared_ptr<prefix> old_prefix = shared_ptr<prefix>(create_prefix(old_prefix_name));
		value *= pow(10, old_prefix->get_conversion_factor());
		shared_ptr<prefix> new_prefix = shared_ptr<prefix>(create_prefix(new_prefix_name));
		value /= pow(10, new_prefix->get_conversion_factor());
	}

	/// \deprecated
	/// This function is only needed by deprecated functions
	void unit::add_internal_abbreviation(abbreviation_symbol new_abbreviation_name)
	{
		shared_ptr<abbreviation> new_abbreviation = shared_ptr<abbreviation>(create_abbreviation(new_abbreviation_name));
		add_prefix(new_abbreviation->get_dimension_prefixes());
		value /= new_abbreviation->get_factor();
		actual_dimensions[new_abbreviation_name] = new_abbreviation;
		//actual_dimensions[container::get_all_dimension(new_abbreviation_name)] = new_abbreviation;
	}

	/// \deprecated
	/// This function is only needed by deprecated functions
	void unit::delete_internal_abbreviation(abbreviation_symbol old_abbreviation_name)
	{
		remove_prefix(actual_dimensions[old_abbreviation_name]->get_dimension_prefixes());
		value *= create_abbreviation(old_abbreviation_name)->get_factor();
		actual_dimensions.erase(old_abbreviation_name);
	}

	/*bool equal_dimensions(const unit& x,const unit& y)
	{
		return equal_dimensions(x.get_real_dimensions(),y.get_real_dimensions());
	}

	bool equal_dimensions(const vector_real_dimensions& x,const vector_real_dimensions& y)
	{
		if(x.size() == y.size())
		{
			for(auto& key : y)
			{
				if(x[key.first] != key.second)
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}*/

	math::topology::space_type abs(const unit& x)
	{
		return math::number::abs(x.get_value());
	}

	auto_unit sqrt(const unit& x)
	{
		math::number::unit_number new_value = math::number::sqrt(x.get_value());
		vector_real_dimensions new_real_dimensions = x.get_real_dimensions();
		for(auto& new_real_dimension : new_real_dimensions)
		{
			new_real_dimension.second->sqrt();
		}
		vector_actual_dimensions new_actual_dimensions = x.get_actual_dimensions();
		for(auto& new_actual_dimension : new_actual_dimensions)
		{
			new_actual_dimension.second->sqrt();
		}
		return auto_unit(new_value, new_real_dimensions, new_actual_dimensions);
	}

	auto_unit sqrt_nth(const unit& x, int y)
	{
		math::number::unit_number new_value = math::number::sqrt_nth(x.get_value(), y);
		vector_real_dimensions new_real_dimensions = x.get_real_dimensions();
		for(auto& new_real_dimension : new_real_dimensions)
		{
			new_real_dimension.second->sqrt_nth(y);
		}
		vector_actual_dimensions new_actual_dimensions = x.get_actual_dimensions();
		for(auto& new_actual_dimension : new_actual_dimensions)
		{
			new_actual_dimension.second->sqrt_nth(y);
		}
		return auto_unit(new_value, new_real_dimensions, new_actual_dimensions);
	}

	/// Calculates if the dimensions are equal related to the unit
	bool equal_dimensions(const unit& x, const unit& y)
	{
		return x.equal_dimensions(y.get_real_dimensions());
	}

	/// \deprecated
	/*unit* get_unit_from_dimensions(math::topology::space_type value, vector_real_dimensions dimensions)
	{
		if(dimensions.size() == 1)
		{
			int key;
			int scale;
			for(auto& value2 : dimensions)
			{
				key = value2.first;
				scale = value2.second->get_scale();
			}
			if(scale == 1)
			{
				switch(key)
				{
					case m:
						return new length(value);
					case s:
						return new time(value);
					case g:
						return new mass(value);
					case A:
						return new charge(value);
					case K:
						return new temperature(value);
					case mol:
						return new mole(value);
					case cd:
						return new light(value);
				}
			}
			else
			{
				// Multidimensional dimensions
			}
		}
		else
		{
			// Compound dimensions
		}
		return new unit(value);
	}*/
}

bool operator ==(const physics::units::unit& x, const physics::units::unit& y)
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

bool operator !=(const physics::units::unit& x, const physics::units::unit& y)
{
	return !(x == y);
}

bool operator <(const physics::units::unit& x, const physics::units::unit& y)
{
	if(!equal_dimensions(x, y))
	{
		throw invalid_argument("Units of different dimensions cannot be compared");
	}
	if(x.get_value() < y.get_value())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator >(const physics::units::unit& x, const physics::units::unit& y)
{
	if(!equal_dimensions(x, y))
	{
		throw invalid_argument("Units of different dimensions cannot be compared");
	}
	if(x.get_value() > y.get_value())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator <=(const physics::units::unit& x, const physics::units::unit& y)
{
	return !(x > y);
}

bool operator >=(const physics::units::unit& x, const physics::units::unit& y)
{
	return !(x < y);
}

bool operator ==(const physics::units::unit& x, string y_init)
{
	physics::units::auto_unit y(y_init);
	return (x == y);
}

bool operator !=(const physics::units::unit& x, string y_init)
{
	return !(x == y_init);
}

bool operator <(const physics::units::unit& x, string y_init)
{
	physics::units::auto_unit y(y_init);
	return (x < y);
}

bool operator >(const physics::units::unit& x, string y_init)
{
	physics::units::auto_unit y(y_init);
	return (x > y);
}

bool operator <=(const physics::units::unit& x, string y_init)
{
	return !(x > y_init);
}

bool operator >=(const physics::units::unit& x, string y_init)
{
	return !(x < y_init);
}

bool operator ==(string x_init, const physics::units::unit& y)
{
	return (y == x_init);
}

bool operator !=(string x_init, const physics::units::unit& y)
{
	return (y != x_init);
}

bool operator <(string x_init, const physics::units::unit& y)
{
	physics::units::auto_unit x(x_init);
	return (x < y);
}

bool operator >(string x_init, const physics::units::unit& y)
{
	physics::units::auto_unit x(x_init);
	return (x > y);
}

bool operator <=(string x_init, const physics::units::unit& y)
{
	return !(x_init > y);
}

bool operator >=(string x_init, const physics::units::unit& y)
{
	return !(x_init < y);
}

void operator +=(wstring& x, const physics::units::unit& y)
{
	wostringstream output;
	output << y;
	x += output.str();
}

wstring operator +(const wstring& x, const physics::units::unit& y)
{
	wostringstream output;
	output << x;
	output << y;
	return output.str();
}

wstring operator +(const physics::units::unit& y, const wstring& x)
{
	wostringstream output;
	output << y;
	output << x;
	return output.str();
}

wostream& operator <<(wostream& os, const physics::units::unit& x)
{
	/*locale loc = locale("en_US.UTF8");
	os.imbue(loc);*/
	wostringstream dimension_text;
	wostringstream dimension_up_text;
	wostringstream dimension_down_text;
	for(const auto& actual_dimension : x.get_actual_dimensions())
	{
		if(actual_dimension.second->get_scale() > 0)
		{
			dimension_up_text << *actual_dimension.second;
		}
		else
		{
			dimension_down_text << *actual_dimension.second;
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
	return os << x.get_value() << " " << dimension_text.str();
}

/*istream& operator >>(istream& is, physics::units::auto_unit& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	physics::units::auto_unit c(b);
	x = c;
	return is;
}*/
