#include "math_function.hpp"

#include <sstream>

using namespace std;

namespace msci
{
	math_function::math_function() : math_variable()
	{
	}

	variable_type math_function::get_type() const
	{
		return variable_type::function_variable;
	}

	string math_function::display(int number_of_decimals) const
	{
		return display_symbol() + " = " + display_expression();
	}

	string math_function::display_symbol() const
	{
		ostringstream display;
		display << symbol << "(";
		int i = 1;
		for (const math_variable& argument : arguments)
		{
			display << argument.display_symbol();
			if (i != arguments.size())
			{
				display << ",";
			}
			i++;
		}
		display << ")";
		return display.str();
	}

	string math_function::display_text(int number_of_decimals) const
	{
		return name + " (" + display_symbol() + ") = " + display_expression();
	}

	string math_function::display_expression() const
	{
		return "";
	}
}
