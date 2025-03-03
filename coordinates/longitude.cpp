#include "./longitude.hpp"

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
	longitude::longitude() : angle()
	{}

	longitude::longitude(const longitude& x) : angle(x.get_value())
	{}

	longitude::longitude(longitude&& x) : angle(std::move(x.get_value()))
	{}

	longitude::longitude(float new_value) : angle()
	{
		value = new_value;
		normalize_value();
	}

	longitude::longitude(double new_value) : angle()
	{
		value = float(new_value);
		normalize_value();
	}

	longitude::longitude(long double new_value) : angle()
	{
		value = float(new_value);
		normalize_value();
	}

	longitude::longitude(int new_value) : angle()
	{
		value = float(new_value);
		normalize_value();
	}

	longitude::longitude(const string& init_longitude) : angle()
	{
		initialize_from_string(init_longitude);
	}

	longitude::longitude(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = float(x);
			normalize_value();
		}
		else
		{
			cerr << "A longitude cannot be initialized with dimensions" << endl;
			value = 0.0f;
		}
	}

	longitude::longitude(const angle& x)
	{
		initialize_from_angle(x);
	}

	longitude& longitude::operator =(const longitude& x)
	{
		value = x.get_value();
		return *this;
	}

	longitude& longitude::operator =(longitude&& x)
	{
		value = std::move(x.get_value());
		return *this;
	}

	longitude& longitude::operator =(float new_value)
	{
		value = new_value;
		normalize_value();
		return *this;
	}

	longitude& longitude::operator =(const string& init_longitude)
	{
		initialize_from_string(init_longitude);
		return *this;
	}

	longitude& longitude::operator =(const scalar_unit& x)
	{
		if (x.has_empty_dimensions())
		{
			value = x.get_value();
			normalize_value();
		}
		else
		{
			cerr << "A longitude cannot be initialized with dimensions" << endl;
		}
		return *this;
	}

	longitude::position longitude::get_position() const
	{
		if (value > 0.0f)
		{
			return longitude::EAST;
		}
		else if (value < 0.0f)
		{
			return longitude::WEST;
		}
		else if (value == 0.0f)
		{
			return longitude::CENTER;
		}
		return longitude::CENTER;
	}

	void longitude::invert()
	{
		if (value > 0.0f)
		{
			value = -180.0f + std::abs(value);
		}
		else if (value < 0.0f)
		{
			value = 180.0f - std::abs(value);
		}
	}

	void longitude::normalize_value()
	{
		if(isfinite(value))
		{
			if (value > 180.0f)
			{
				value = 0.0f;
			}
			else if (value < -180.0f)
			{
				value = 0.0f;
			}
		}
	}

	void longitude::initialize_from_angle(const angle& x)
	{
		if (x > 180.0f)
		{
			value = -180.0f + std::abs(x.get_value() - 180.0f);
		}
		else if (x <= 180.0f)
		{
			value = x.get_value();
		}
	}

	void longitude::initialize_from_string(string init_longitude)
	{
		if (init_longitude.length() >= 3)
		{
			if (init_longitude.substr(init_longitude.length() - 1) == "E")
			{
				value = stof(init_longitude.substr(0,init_longitude.length() - 2));
				normalize_value();
				return;
			}
			else if (init_longitude.substr(init_longitude.length() - 1) == "W")
			{
				value = -1.0f * stof(init_longitude.substr(0,init_longitude.length() - 2));
				normalize_value();
				return;
			}
		}
		icu::UnicodeString init_longitude_unicode = icu::UnicodeString(init_longitude.c_str());
		if (init_longitude_unicode.endsWith(0x00B0) or init_longitude_unicode.endsWith(0x00BA))
		{
			value = stof(init_longitude);
			normalize_value();
		}
	}
}
