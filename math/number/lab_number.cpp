#include "lab_number.hpp"

#include <cmath>
#include <sstream>

using namespace std;

namespace math
{
	lab_number::lab_number() : undefined_number<unit_number>(), unit_number(), error_value(0)
	{
	}

	lab_number::lab_number(math::space_type new_value, math::space_type new_error_value) : undefined_number<unit_number>(new_value), unit_number(new_value)
	{
		error_value = new_error_value;
	}

	const math::space_type& lab_number::get_error_value() const
	{
		return error_value;
	}

	lab_number lab_number::operator +(const lab_number& x) const
	{
		return lab_number(value + x.get_value(), error_value + x.get_error_value());
	}

	lab_number lab_number::operator -(const lab_number& x) const
	{
		return lab_number(value - x.get_value(), error_value - x.get_error_value());
	}

	lab_number lab_number::operator *(const lab_number& x) const
	{
		return lab_number(value * x.get_value(), error_value * x.get_error_value());
	}

	lab_number lab_number::operator /(const lab_number& x) const
	{
		return lab_number(value / x.get_value(), error_value / x.get_error_value());
	}

	lab_number lab_number::operator ^(const lab_number& x) const
	{
		return lab_number(pow(value, x.get_value()), pow(error_value, x.get_error_value()));
	}

	void lab_number::operator +=(const lab_number& x)
	{
		value += x.get_value();
		error_value += x.get_error_value();
	}

	void lab_number::operator -=(const lab_number& x)
	{
		value -= x.get_value();
		error_value -= x.get_error_value();
	}

	void lab_number::operator *=(const lab_number& x)
	{
		value *= x.get_value();
		error_value *= x.get_error_value();
	}

	void lab_number::operator /=(const lab_number& x)
	{
		value /= x.get_value();
		error_value /= x.get_error_value();
	}

	void lab_number::operator ^=(const lab_number& x)
	{
		value = pow(value, x.get_value());
		error_value = pow(error_value, x.get_error_value());
	}

	wstring lab_number::print() const
	{
		wostringstream output;
		output << setprecision(numeric_limits<float>::max_exponent10 + 1);
		if(is_defined())
		{
			if(std::abs(get_error_value()) > std::abs(get_value()))
			{
				output << "Error: error greater than value" << endl;
			}
			else
			{
				output << get_value() << " +- " << get_error_value();
			}
			return output.str();
		}
		else
		{
			return unit_number::print();
		}
	}
}

wostream& operator <<(wostream& os, const math::lab_number& x)
{
	return os << x.print();
}
