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
	unit::unit() : value(0),actual_dimensions()
	{
	}

	unit::unit(math::space_type new_value, string dimension_structure) : value(new_value),actual_dimensions()
	{
		initialize_dimensions(dimension_structure);
	}

	unit::unit(math::unit_number new_value, const vector_actual_dimensions& new_actual_dimensions) : unit()
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
			while(isdigit(init_value[i]) || init_value[i] == '.' || init_value[i] == ' ')
			{
				if (init_value[i] == ' ' and !isdigit(init_value[i + 1]))
				{
					break;
				}
				i++;
			}
			if(init_value[i] != ' ')
			{
				throw invalid_argument("Unit string must have the value separated from units with a single space");
			}
			string string_value = init_value.substr(0, i);
			boost::algorithm::erase_all(string_value, " ");
			value = math::unit_number(stof(string_value));
			initialize_dimensions(init_value.substr(i));
		}
	}

	unit::unit(const unit& x)
	{
		actual_dimensions = x.get_actual_dimensions();
		value = x.get_value();
	}

	void unit::operator =(const unit& x)
	{
		if (physics::units::equal_dimensions(*this,x))
		{
			actual_dimensions = x.get_actual_dimensions();
			value = x.get_value();
		}
		else
		{
			invalidate(11);
		}
	}

	unit::operator float() const
	{
		return value.get_value();
	}

	auto_unit unit::operator +(const unit& x) const
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

	auto_unit unit::operator -(const unit& x) const
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

	auto_unit unit::operator *(const unit& x) const
	{
		math::unit_number new_value = value;
		auto_unit y = x;
		if(y.equal_dimensions(get_real_dimensions()))
		{
			y.set_same_prefix(get_actual_dimensions());
		}
		new_value *= y.get_value().get_value();
		vector_real_dimensions new_real_dimensions = multiply_real_dimensions(get_real_dimensions(),y.get_real_dimensions());
		vector_actual_dimensions new_actual_dimensions = multiply_actual_dimensions(get_actual_dimensions(),y.get_actual_dimensions());
		return move(auto_unit(new_value, new_real_dimensions, new_actual_dimensions));
	}

	auto_unit unit::operator /(const unit& x) const
	{
		math::unit_number new_value = value;
		auto_unit y = x;
		if(y.equal_dimensions(get_real_dimensions()))
		{
			y.set_same_prefix(unit::get_actual_dimensions());
		}
		new_value /= y.get_value().get_value();
		vector_real_dimensions new_real_dimensions = divide_real_dimensions(get_real_dimensions(),y.get_real_dimensions());
		vector_actual_dimensions new_actual_dimensions = divide_actual_dimensions(get_actual_dimensions(),y.get_actual_dimensions());
		return move(auto_unit(new_value, new_real_dimensions, new_actual_dimensions));
	}

	auto_unit unit::operator ^(const unit& x) const
	{
		if(x.empty_dimensions())
		{
			return move(*this ^ int(x.get_value().get_value()));
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
				remove_prefix(actual_dimension.second->get_dimension_prefixes(),actual_dimension.second->get_prefix_base());
				abbreviation* new_actual_abbreviation = create_abbreviation(actual_dimension.second->get_symbol());
				if(new_actual_abbreviation != nullptr)
				{
					shared_ptr<abbreviation> actual_abbreviation (new_actual_abbreviation);
					auto_unit abbreviation_unit("1 " + actual_abbreviation->get_dimensions_match());
					for(auto& actual_dimension2 : abbreviation_unit.get_actual_dimensions())
					{
						remove_prefix(actual_dimension2.second->get_dimension_prefixes(),actual_dimension2.second->get_prefix_base());
					}
				}
				shared_ptr<abbreviation> actual_dimension_ptr = dynamic_pointer_cast<abbreviation>(actual_dimension.second);
				if (actual_dimension_ptr)
				{
					value *= actual_dimension_ptr->get_factor();
				}
			}
			actual_dimensions.empty();
			vector_actual_dimensions new_actual_dimensions = create_actual_dimensions(new_dimensions);
			for(auto& new_actual_dimension : new_actual_dimensions)
			{
				add_prefix(new_actual_dimension.second->get_dimension_prefixes(),new_actual_dimension.second->get_prefix_base());
				abbreviation* new_actual_abbreviation = create_abbreviation(new_actual_dimension.second->get_symbol());
				if(new_actual_abbreviation != nullptr)
				{
					shared_ptr<abbreviation> actual_abbreviation (new_actual_abbreviation);
					auto_unit abbreviation_unit("1 " + actual_abbreviation->get_dimensions_match());
					for(auto& actual_dimension2 : abbreviation_unit.get_actual_dimensions())
					{
						add_prefix(actual_dimension2.second->get_dimension_prefixes(),actual_dimension2.second->get_prefix_base());
					}
				}
				shared_ptr<abbreviation> new_actual_dimension_ptr = dynamic_pointer_cast<abbreviation>(new_actual_dimension.second);
				if (new_actual_dimension_ptr)
				{
					value /= new_actual_dimension_ptr->get_factor();
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
	const math::unit_number& unit::get_value() const
	{
		return value;
	}

	wstring unit::display(int number_of_decimals) const
	{
		/*locale loc = locale("en_US.UTF8");
		os.imbue(loc);*/
		wostringstream dimension_text;
		wostringstream dimension_up_text;
		wostringstream dimension_down_text;
		for(const auto& actual_dimension : get_actual_dimensions())
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
		return value.print(number_of_decimals) + L" " + dimension_text.str();
	}

	/// Updates the value to the prefix added
	void unit::add_prefix(shared_ptr<prefix> new_prefix,float prefix_base)
	{
		value /= pow(prefix_base, new_prefix->get_conversion_factor() * new_prefix->scale);
	}

	/// Updates the value to the set of prefixes added
	void unit::add_prefix(dimension_prefixes new_prefixes,float prefix_base)
	{
		for(auto& map_value : new_prefixes)
		{
			add_prefix(map_value.second,prefix_base);
		}
	}

	/// Updates the value to the prefix removed
	void unit::remove_prefix(shared_ptr<prefix> old_prefix,float prefix_base)
	{
		value *= pow(prefix_base, old_prefix->get_conversion_factor() * old_prefix->scale);
	}

	/// Updates the value to the set of prefixes removed
	void unit::remove_prefix(dimension_prefixes new_prefixes,float prefix_base)
	{
		for(auto& map_value : new_prefixes)
		{
			remove_prefix(map_value.second,prefix_base);
		}
	}

	/// Updates the prefixes of the unit to the actual dimensions given
	void unit::set_same_prefix(const vector_actual_dimensions& new_dimensions)
	{
		for(const auto& map_value : actual_dimensions)
		{
			remove_prefix(map_value.second->get_dimension_prefixes(),map_value.second->get_prefix_base());
		}
		actual_dimensions.clear();
		for(const auto& map_value : new_dimensions)
		{
			add_prefix(map_value.second->get_dimension_prefixes(),map_value.second->get_prefix_base());
			actual_dimensions[map_value.second->get_enum_type()] = map_value.second;
		}
	}

	/// Creates the real dimensions and the actual dimensions that the function gives
	void unit::initialize_dimensions(string init_value)
	{
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
					shared_ptr<dimension> actual_dimension (create_dimension(new_dimension));
					if(new_scale > 1)
					{
						*actual_dimension ^= new_scale;
					}
					if(numerator == false)
					{
						*actual_dimension ^= -1;
					}
					actual_dimensions[actual_dimension->get_enum_type()] = actual_dimension;

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
					actual_dimensions[add_abbreviation->get_enum_type()] = add_abbreviation;
				}
				else if(get_conversion.count(new_dimension) > 0)
				{
					conversion new_conversion = get_conversion[new_dimension];
					if(numerator == true)
					{
						value *= new_conversion.get_factor() * new_scale;
					}
					else
					{
						value /= new_conversion.get_factor() * new_scale;
					}
					dimension* new_dimension_real = create_dimension(new_conversion.get_unit_to());
					abbreviation* new_abbreviation_actual;
					if(new_dimension_real != nullptr)
					{
						shared_ptr<dimension> actual_dimension (create_dimension(new_conversion.get_unit_to()));
						if(new_scale > 1)
						{
							*actual_dimension ^= new_scale;
						}
						if(numerator == false)
						{
							*actual_dimension ^= -1;
						}
						actual_dimensions[actual_dimension->get_enum_type()] = actual_dimension;

						new_abbreviation_actual = nullptr;
					}
					else
					{
						new_abbreviation_actual = create_abbreviation(new_conversion.get_unit_to());
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
						actual_dimensions[add_abbreviation->get_enum_type()] = add_abbreviation;
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

	math::space_type abs(const unit& x)
	{
		return math::abs(x.get_value());
	}

	auto_unit sqrt(const unit& x)
	{
		math::unit_number new_value = math::sqrt(x.get_value());
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
		math::unit_number new_value = math::sqrt_nth(x.get_value(), y);
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
	return os << x.display();
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
