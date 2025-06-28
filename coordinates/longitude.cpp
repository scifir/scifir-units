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

	bool is_longitude(const string& init_longitude)
	{
		if (init_longitude.length() == 0 or init_longitude.length() < 3)
		{
			return false;
		}
		bool cardinale_point_present = false;
		if (init_longitude.substr(init_longitude.length() - 1) == "E")
		{
			cardinale_point_present = true;
		}
		else if (init_longitude.substr(init_longitude.length() - 1) == "W")
		{
			cardinale_point_present = true;
		}
		int start_point = 0;
		if (cardinale_point_present == false && init_longitude[0] == '-')
		{
			start_point++;
		}
		int total_chars = int(init_longitude.size());
		if (cardinale_point_present)
		{
			total_chars--;
		}
		bool loop = false;
		if (init_longitude.substr(total_chars - 2,2) == "°" || init_longitude.substr(total_chars - 2,2) == "º")
		{
			loop = true;
		}
		if (loop == false)
		{
			return false;
		}
		bool dot_present = false;
		for (int i = start_point; i < (total_chars - 2); i++)
		{
			if (init_longitude[i] == '.')
			{
				if (dot_present)
				{
					return false;
				}
				else
				{
					dot_present = true;
				}
			}
			else if (!isdigit(init_longitude[i]))
			{
				return false;
			}
		}
		return true;
	}
}
