#include "msci/units/units/scalar_unit.hpp"

#include "msci/units/units/conversion.hpp"
#include "msci/units/units/unit_basic.hpp"
#include "msci/units/units/prefix.hpp"

#include "boost/algorithm/string/erase.hpp"
#include "boost/algorithm/string.hpp"

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

using namespace std;

namespace msci
{
	scalar_unit::scalar_unit() : dimensions(),value(0)
	{
	}

	scalar_unit::scalar_unit(const scalar_unit& x) : dimensions(x.get_dimensions()),value(x.get_value())
	{
	}

	scalar_unit::scalar_unit(scalar_unit&& x) : dimensions(move(x.get_dimensions())),value(move(x.get_value()))
	{
	}

	scalar_unit::scalar_unit(const unit_number& new_value, const string& dimension_structure) : dimensions(),value(new_value)
	{
		initialize_dimensions(dimension_structure);
	}

	scalar_unit::scalar_unit(const unit_number& new_value, const vector<dimension>& new_dimensions) : dimensions(new_dimensions),value(new_value)
	{
	}

	scalar_unit::scalar_unit(const scalar_unit& new_value,const string& init_value) : dimensions(create_dimensions(init_value)),value(new_value.get_value())
	{
	}

	scalar_unit::scalar_unit(scalar_unit&& new_value,const string& init_value) : dimensions(create_dimensions(init_value)),value(new_value.get_value())
	{
	}

	scalar_unit::scalar_unit(const string& init_value) : scalar_unit()
	{
		if(!isdigit(init_value[0]))
		{
			return;
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
				return;
			}
			string string_value = init_value.substr(0, i);
			boost::algorithm::erase_all(string_value, " ");
			value = msci::unit_number(stof(string_value));
			initialize_dimensions(init_value.substr(i));
		}
	}

	scalar_unit& scalar_unit::operator =(const scalar_unit& x)
	{
		if (x.is_defined())
		{
			if (msci::equal_dimensions(*this,x))
			{
				dimensions = x.get_dimensions();
				value = x.get_value();
			}
			else
			{
				invalidate(7);
			}
		}
		else
		{
			invalidate(1);
		}
		return *this;
	}

	scalar_unit& scalar_unit::operator =(scalar_unit&& x)
	{
		if (x.is_defined())
		{
			if (msci::equal_dimensions(*this,x))
			{
				dimensions = move(x.get_dimensions());
				value = move(x.get_value());
			}
			else
			{
				invalidate(7);
			}
		}
		else
		{
			invalidate(1);
		}
		return *this;
	}

	scalar_unit::operator float() const
	{
		return value.get_value();
	}

	scalar_unit scalar_unit::operator +(const scalar_unit& x) const
	{
		if(x.has_dimensions(get_derived_dimensions()))
		{
			scalar_unit a = *this;
			scalar_unit y = x;
			y.set_same_prefix(scalar_unit::get_dimensions());
			a += y.get_value().get_value();
			return move(a);
		}
		else
		{
			scalar_unit y = scalar_unit();
			y.invalidate(8);
			return move(y);
		}
	}

	scalar_unit scalar_unit::operator -(const scalar_unit& x) const
	{
		if(x.has_dimensions(get_derived_dimensions()))
		{
			scalar_unit a = *this;
			scalar_unit y = x;
			y.set_same_prefix(scalar_unit::get_dimensions());
			a -= y.get_value().get_value();
			return move(a);
		}
		else
		{
			scalar_unit y = scalar_unit();
			y.invalidate(9);
			return move(y);
		}
	}

	scalar_unit scalar_unit::operator *(const scalar_unit& x) const
	{
		msci::unit_number new_value = value;
		scalar_unit y = x;
		if(y.has_dimensions(get_derived_dimensions()))
		{
			y.set_same_prefix(get_dimensions());
		}
		new_value *= y.get_value().get_value();
		vector<dimension> new_dimensions = multiply_dimensions(get_dimensions(),y.get_dimensions());
		return move(scalar_unit(new_value, new_dimensions));
	}

	scalar_unit scalar_unit::operator /(const scalar_unit& x) const
	{
		msci::unit_number new_value = value;
		scalar_unit y = x;
		if(y.has_dimensions(get_derived_dimensions()))
		{
			y.set_same_prefix(scalar_unit::get_dimensions());
		}
		new_value /= y.get_value().get_value();
		vector<dimension> new_dimensions = divide_dimensions(get_dimensions(),y.get_dimensions());
		return move(scalar_unit(new_value, new_dimensions));
	}

	scalar_unit scalar_unit::operator ^(const scalar_unit& x) const
	{
		if(x.has_empty_dimensions())
		{
			return move(*this ^ int(x.get_value().get_value()));
		}
		else
		{
			scalar_unit y = scalar_unit();
			y.invalidate(10);
			return move(y);
		}
	}

	void scalar_unit::operator +=(const scalar_unit& x)
	{
		scalar_unit z = x;
		z.set_same_prefix(get_dimensions());
		if(!x.has_dimensions(get_derived_dimensions()))
		{
			invalidate(8);
		}
		value += z.get_value();
	}

	void scalar_unit::operator -=(const scalar_unit& x)
	{
		scalar_unit z = x;
		z.set_same_prefix(get_dimensions());
		if(!x.has_dimensions(get_derived_dimensions()))
		{
			invalidate(9);
		}
		value -= z.get_value();
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
		/*if(has_dimensions(new_dimensions))
		{
			int x_dimensions_count = sizeof(x_dimensions) / sizeof(dimension);
			for(int i = 0; i < x_dimensions_count; i++)
			{
				remove_prefix(dimensions[i].dimension_prefix);
				if(dimensions[i].is_derived_dimension())
				{
					dimensions* derived_dimensions = dimensions[i].get_derived_dimensions();
					int derived_dimensions_count = sizeof(derived_dimensions) / sizeof(dimension);
					for(int j = 0; j < derived_dimensions_count; j++)
					{
						remove_prefix(derived_dimensions[j].dimension_prefix);
					}
				}*/
				/*shared_ptr<abbreviation> actual_dimension_ptr = dynamic_pointer_cast<abbreviation>(actual_dimension.second);
				if (actual_dimension_ptr)
				{
					value *= actual_dimension_ptr->get_factor();
				}*/
			//}
			//dimensions.empty();
			/*dimension* new_dimensions = create_dimensions(new_dimensions_str);
			int new_dimensions_count = sizeof(new_dimensions) / sizeof(dimension);
			for(int i = 0; i < new_dimensions_count; i++)
			{
				add_prefix(new_dimensions[i]);*/
				/*if(new_dimensions[i].is_derived_dimension())
				{
					shared_ptr<abbreviation> actual_abbreviation (new_actual_abbreviation);
					scalar_unit abbreviation_scalar_unit("1 " + actual_abbreviation->get_dimensions_match());
					for(auto& actual_dimension2 : abbreviation_scalar_unit.get_dimensions())
					{
						add_prefix(actual_dimension2.second->get_dimension_prefixes(),actual_dimension2.second->get_prefix_base());
					}
				}
				shared_ptr<abbreviation> new_actual_dimension_ptr = dynamic_pointer_cast<abbreviation>(new_actual_dimension.second);
				if (new_actual_dimension_ptr)
				{
					value /= new_actual_dimension_ptr->get_factor();
				}*/
			/*}
			dimensions = new_dimensions;
		}
		else
		{
			invalidate(7);
		}*/
	}

	bool scalar_unit::has_dimensions(const string& dimension_structure) const
	{
		vector<dimension> structure_dimensions = create_dimensions(dimension_structure);
		return has_dimensions(structure_dimensions);
	}

	bool scalar_unit::has_dimensions(const vector<dimension>& second_dimensions) const
	{
		//int dimensions_count = sizeof(dimensions) / sizeof(dimension);
		//int second_dimensions_count = sizeof(second_dimensions) / sizeof(dimension);
		return true;
		/*if(dimensions_count == second_dimensions_count)
		{
			for(int i = 0; i < second_dimensions_count; i++)
			{
				if(real_dimensions_tmp.count(key.first) == 0 or *real_dimensions_tmp[key.first] != *key.second)
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}*/
	}

	bool scalar_unit::has_empty_dimensions() const
	{
		return false;
		/*if(get_derived_dimensions().size() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}*/
	}

	string scalar_unit::display_dimensions() const
	{
		ostringstream dimension_text;
		ostringstream dimension_up_text;
		ostringstream dimension_down_text;
		int dimensions_count = sizeof(dimensions) / sizeof(dimension);
		for(int i = 0; i < dimensions_count; i++)
		{
			if(dimensions[i].dimension_sign == dimension::positive)
			{
				dimension_up_text << dimensions[i];
			}
			else
			{
				dimension_down_text << dimensions[i];
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

	const vector<dimension>& scalar_unit::get_dimensions() const
	{
		return dimensions;
	}

	string scalar_unit::display(int number_of_decimals) const
	{
		/*locale loc = locale("en_US.UTF8");
		os.imbue(loc);*/
		return value.print(number_of_decimals) + " " + display_dimensions();
	}

	void scalar_unit::add_prefix(const prefix& new_prefix,float prefix_base)
	{
		//value /= pow(prefix_base, new_prefix.get_conversion_factor());
	}

	//void scalar_unit::add_prefix(const prefix[] new_prefixes,float prefix_base)
	//{
		/*int prefixes_count = sizeof(new_prefixes) / sizeof(prefix);
		for(int i = 0; i < prefixes_count; i++)
		{
			add_prefix(new_prefixes[i],prefix_base);
		}*/
	//}

	void scalar_unit::remove_prefix(const prefix& old_prefix,float prefix_base)
	{
		//value *= pow(prefix_base, old_prefix.get_conversion_factor());
	}

	//void scalar_unit::remove_prefix(const prefix[] new_prefixes,float prefix_base)
	//{
		/*int prefixes_count = sizeof(new_prefixes) / sizeof(prefix);
		for(int i = 0; i < prefixes_count; i++)
		{
			remove_prefix(new_prefixes[i],prefix_base);
		}*/
	//}

	void scalar_unit::set_same_prefix(const vector<dimension>& new_dimensions)
	{
		/*int dimensions_count = sizeof(dimensions) / sizeof(dimension);
		for(int i = 0; i < dimensions_count; i++)
		{
			remove_prefix(dimensions[i].dimension_prefix);
			shared_ptr<abbreviation> actual_dimension_ptr = dynamic_pointer_cast<abbreviation>(dimensions[i]);
			if (actual_dimension_ptr)
			{
				value *= actual_dimension_ptr->get_factor();
			}
		}*/
		// dimensions.clear()
		/*int new_dimensions_count = sizeof(new_dimensions) / sizeof(dimension);
		for(int i = 0; i < new_dimensions_count; i++)
		{
			add_prefix(new_dimensions[i].dimension_prefix);
			dimensions[new_dimensions[i]->get_type()] = new_dimensions[i];
			shared_ptr<abbreviation> actual_dimension_ptr = dynamic_pointer_cast<abbreviation>(new_dimensions[i]);
			if (actual_dimension_ptr)
			{
				value /= actual_dimension_ptr->get_factor();
			}
		}*/
	}

	void scalar_unit::initialize_dimensions(string init_value)
	{
		/*int new_start = 0;
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
					dimensions[actual_dimension->get_enum_type()] = actual_dimension;

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
						dimensions[actual_dimension->get_enum_type()] = actual_dimension;

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
						dimensions[add_abbreviation->get_enum_type()] = add_abbreviation;
					}
				}
				new_dimension.clear();
				new_scale = 1;
				new_size = 0;
			}
			j++;
			new_size++;
		}*/
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

	float abs(const scalar_unit& x)
	{
		return msci::abs(x.get_value());
	}

	scalar_unit sqrt(const scalar_unit& x)
	{
		msci::unit_number new_value = msci::sqrt(x.get_value());
		vector<dimension> new_dimensions = x.get_dimensions();
		/*for(auto& new_actual_dimension : new_dimensions)
		{
			new_actual_dimension.second->sqrt();
		}*/
		return scalar_unit(new_value, new_dimensions);
	}

	scalar_unit sqrt_nth(const scalar_unit& x, int y)
	{
		msci::unit_number new_value = msci::sqrt_nth(x.get_value(), y);
		vector<dimension> new_dimensions = x.get_dimensions();
		/*for(auto& new_actual_dimension : new_dimensions)
		{
			new_actual_dimension.second->sqrt_nth(y);
		}*/
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
	return os << x.display();
}

/*istream& operator >>(istream& is, msci::scalar_unit& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::scalar_unit c(b);
	x = c;
	return is;
}*/
