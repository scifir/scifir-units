#include "./latitude.hpp"

#include "../util/types.hpp"

#include "boost/algorithm/string.hpp"
#include "unicode/unistr.h"
#include "unicode/uchar.h"

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace scifir
{
	latitude::latitude() : angle()
	{}

	latitude::latitude(const latitude& x) : angle(x)
	{}

	latitude::latitude(latitude&& x) : angle(std::move(x))
	{}

	latitude::latitude(float new_value) : angle()
	{
		value = new_value;
		normalize_value();
	}

	latitude::latitude(double new_value) : angle()
	{
		value = float(new_value);
		normalize_value();
	}

	latitude::latitude(long double new_value) : angle()
	{
		value = float(new_value);
		normalize_value();
	}

	latitude::latitude(int new_value) : angle()
	{
		value = float(new_value);
		normalize_value();
	}

	latitude::latitude(const string& init_latitude) : angle()
	{
		initialize_from_string(init_latitude);
	}

	latitude::latitude(const scalar_unit& x) : angle()
	{
		if (x.has_empty_dimensions())
		{
			value = float(x);
			normalize_value();
		}
		else
		{
			cerr << "A latitude cannot be initialized with dimensions" << endl;
			value = 0.0f;
		}
	}

	latitude& latitude::operator =(const latitude& x)
	{
		value = x.get_value();
		return *this;
	}

	latitude& latitude::operator =(latitude&& x)
	{
		value = std::move(x.get_value());
		return *this;
	}

	latitude& latitude::operator =(float new_value)
	{
		value = new_value;
		normalize_value();
		return *this;
	}

	latitude& latitude::operator =(const string& init_latitude)
	{
		initialize_from_string(init_latitude);
		return *this;
	}

	latitude& latitude::operator =(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = x.get_value();
			normalize_value();
		}
		else
		{
			cerr << "A latitude cannot be initialized with dimensions" << endl;
		}
		return *this;
	}

	latitude::position latitude::get_position() const
	{
		if (value > 0.0f)
		{
			return latitude::NORTH;
		}
		else if (value < 0.0f)
		{
			return latitude::SOUTH;
		}
		else if (value == 0.0f)
		{
			return latitude::CENTER;
		}
		return latitude::CENTER;
	}

	void latitude::invert()
	{
		if (value > 0.0f)
		{
			value = -90.0f + std::abs(value);
		}
		else if (value < 0.0f)
		{
			value = 90.0f - std::abs(value);
		}
	}

	void latitude::normalize_value()
	{
		if(isfinite(value))
		{
			if (value > 90.0f)
			{
				value = 0.0f;
			}
			else if (value < -90.0f)
			{
				value = 0.0f;
			}
		}
	}

	void latitude::initialize_from_angle(const angle& x)
	{
		if (x >= 270.0f)
		{
			value = -90.0f + std::abs(x.get_value() - 270.0f);
		}
		else if (x <= 90.0f)
		{
			value = x.get_value();
		}
		else
		{
			value = 0.0f;
		}
	}

	void latitude::initialize_from_string(string init_latitude)
	{
		if (init_latitude.length() >= 3)
		{
			if (init_latitude.substr(init_latitude.length() - 1) == "N")
			{
				value = stof(init_latitude.substr(0,init_latitude.length() - 2));
				normalize_value();
				return;
			}
			else if (init_latitude.substr(init_latitude.length() - 1) == "S")
			{
				value = -1.0f * stof(init_latitude.substr(0,init_latitude.length() - 2));
				normalize_value();
				return;
			}
		}
		icu::UnicodeString init_latitude_unicode = icu::UnicodeString(init_latitude.c_str());
		if (init_latitude_unicode.endsWith(0x00B0) or init_latitude_unicode.endsWith(0x00BA))
		{
			value = stof(init_latitude);
			normalize_value();
		}
	}
}
