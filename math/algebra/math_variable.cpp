#include "math_variable.hpp"

using namespace std;

namespace msci
{
	math_variable::math_variable() : value(),symbol(),name(),description()
	{
	}

	math_variable::math_variable(const string& new_symbol) : value(),symbol(new_symbol),name(),description()
	{
	}

	math_variable::math_variable(const string& new_symbol,const unit& new_value) : value(new_value),symbol(new_symbol),name(),description()
	{
	}

	math_variable::math_variable(const string& new_symbol,const unit& new_value,const string& new_name) : value(new_value),symbol(new_symbol),name(new_name),description()
	{
	}

	math_variable::math_variable(const string& new_symbol,const unit& new_value,const string& new_name,const string& new_description) : value(new_value),symbol(new_symbol),name(new_name),description(new_description)
	{
	}

	math_variable math_variable::operator +(const math_variable& x) const
	{
		return math_variable("(" + symbol + " + " + x.get_symbol() + ")",value + x.get_value());
	}

	math_variable math_variable::operator -(const math_variable& x) const
	{
		return math_variable("(" + symbol + " - " + x.get_symbol() + ")",value - x.get_value());
	}

	math_variable math_variable::operator *(const math_variable& x) const
	{
		return math_variable(symbol + x.get_symbol(),value * x.get_value());
	}

	math_variable math_variable::operator /(const math_variable& x) const
	{
		return math_variable(symbol + " / " + x.get_symbol(),value / x.get_value());
	}

	math_variable math_variable::operator ^(const math_variable& x) const
	{
		return math_variable(symbol + " ^ " + x.get_symbol(),value ^ x.get_value());
	}

	variable_type math_variable::get_type() const
	{
		return variable_type::value_variable;
	}

	string math_variable::display(int number_of_decimals) const
	{
		return display_symbol() + " = " + value.display(number_of_decimals);
	}

	string math_variable::display_symbol() const
	{
		return symbol;
	}

	string math_variable::display_text(int number_of_decimals) const
	{
		return name + " (" + display_symbol() + ") = " + value.display(number_of_decimals);
	}
}

ostream& operator << (ostream& os,const msci::math_variable& x)
{
	return os << x.display();
}
