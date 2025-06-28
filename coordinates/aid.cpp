#include "./aid.hpp"

#include "boost/algorithm/string.hpp"

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

namespace scifir
{
	aid::aid() : universe(),galaxy(),solar_system(),astronomical_body(),astronomical_type(aid::NONE)
	{}

	aid::aid(const aid& x) : universe(x.universe),galaxy(x.galaxy),solar_system(x.solar_system),astronomical_body(x.astronomical_body),astronomical_type(x.astronomical_type)
	{}

	aid::aid(aid&& x) : universe(std::move(x.universe)),galaxy(std::move(x.galaxy)),solar_system(std::move(x.solar_system)),astronomical_body(std::move(x.astronomical_body)),astronomical_type(std::move(x.astronomical_type))
	{}

	aid::aid(const scifir::astronomical_body& predefined_astronomical_body) : aid()
	{
		if (predefined_astronomical_body != astronomical_body::NONE)
		{
			universe = "universe";
		}
		if (predefined_astronomical_body == astronomical_body::MILKY_WAY)
		{
			galaxy = "milky-way";
			astronomical_type = aid::GALAXY;
		}
		else if (predefined_astronomical_body == astronomical_body::ANDROMEDA)
		{
			galaxy = "andromeda";
			astronomical_type = aid::GALAXY;
		}
		else if (predefined_astronomical_body == astronomical_body::SOLAR_SYSTEM)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_type = aid::SOLAR_SYSTEM;
		}
		else if (predefined_astronomical_body == astronomical_body::SUN)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "sun";
			astronomical_type = aid::STAR;
		}
		else if (predefined_astronomical_body == astronomical_body::MOON)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "moon";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::MERCURY)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "mercury";
			astronomical_type = aid::PLANET;
		}
		else if (predefined_astronomical_body == astronomical_body::VENUS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "venus";
			astronomical_type = aid::PLANET;
		}
		else if (predefined_astronomical_body == astronomical_body::EARTH)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "earth";
			astronomical_type = aid::PLANET;
		}
		else if (predefined_astronomical_body == astronomical_body::MARS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "mars";
			astronomical_type = aid::PLANET;
		}
		else if (predefined_astronomical_body == astronomical_body::JUPITER)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "jupiter";
			astronomical_type = aid::PLANET;
		}
		else if (predefined_astronomical_body == astronomical_body::SATURN)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "saturn";
			astronomical_type = aid::PLANET;
		}
		else if (predefined_astronomical_body == astronomical_body::URANUS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "uranus";
			astronomical_type = aid::PLANET;
		}
		else if (predefined_astronomical_body == astronomical_body::NEPTUNE)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "neptune";
			astronomical_type = aid::PLANET;
		}
		else if (predefined_astronomical_body == astronomical_body::CERES)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "ceres";
			astronomical_type = aid::PLANET;
		}
		else if (predefined_astronomical_body == astronomical_body::ORCUS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "orcus";
			astronomical_type = aid::PLANET;
		}
		else if (predefined_astronomical_body == astronomical_body::PLUTO)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "pluto";
			astronomical_type = aid::PLANET;
		}
		else if (predefined_astronomical_body == astronomical_body::HAUMEA)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "haumea";
			astronomical_type = aid::PLANET;
		}
		else if (predefined_astronomical_body == astronomical_body::QUAOAR)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "quaoar";
			astronomical_type = aid::PLANET;
		}
		else if (predefined_astronomical_body == astronomical_body::MAKEMAKE)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "makemake";
			astronomical_type = aid::PLANET;
		}
		else if (predefined_astronomical_body == astronomical_body::GONGGONG)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "gonggong";
			astronomical_type = aid::PLANET;
		}
		else if (predefined_astronomical_body == astronomical_body::ERIS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "eris";
			astronomical_type = aid::PLANET;
		}
		else if (predefined_astronomical_body == astronomical_body::SEDNA)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "sedna";
			astronomical_type = aid::PLANET;
		}
		else if (predefined_astronomical_body == astronomical_body::IO)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "io";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::EUROPA)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "europa";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::GANYMEDE)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "ganymede";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::CALLISTO)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "callisto";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::MIMAS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "mimas";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::ENCELADUS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "enceladus";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::TETHYS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "tethys";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::DIONE)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "dione";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::RHEA)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "rhea";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::TITAN)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "titan";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::IAPETUS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "iapetus";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::MIRANDA)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "miranda";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::ARIEL)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "ariel";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::UMBRIEL)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "umbriel";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::TITANIA)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "titania";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::OBERON)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "oberon";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::TRITON)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "triton";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::CHARON)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "charon";
			astronomical_type = aid::MOON;
		}
		else if (predefined_astronomical_body == astronomical_body::DYSNOMIA)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "dysnomia";
			astronomical_type = aid::MOON;
		}
	}

	aid::aid(const aid::type& new_astronomical_type,const string& new_astro1,const string& new_astro2,const string& new_astro3,const string& new_astro4) : universe(),galaxy(),solar_system(),astronomical_body(),astronomical_type(aid::NONE)
	{
		if (new_astronomical_type == aid::UNIVERSE)
		{
			universe = new_astro1;
			astronomical_type = aid::UNIVERSE;
		}
		else if (new_astronomical_type == aid::GALAXY)
		{
			if (new_astro2 != "")
			{
				universe = new_astro2;
			}
			else
			{
				universe = "universe";
			}
			galaxy = new_astro1;
			astronomical_type = aid::GALAXY;
		}
		else if (new_astronomical_type == aid::SOLAR_SYSTEM)
		{
			if (new_astro3 != "")
			{
				universe = new_astro3;
			}
			else
			{
				universe = "universe";
			}
			galaxy = new_astro1;
			solar_system = new_astro2;
			astronomical_type = aid::SOLAR_SYSTEM;
		}
		else if (new_astronomical_type != aid::UNIVERSE and new_astronomical_type != aid::GALAXY and new_astronomical_type != aid::SOLAR_SYSTEM and new_astronomical_type != aid::NONE)
		{
			if (new_astro4 != "")
			{
				universe = new_astro4;
			}
			else
			{
				universe = "universe";
			}
			galaxy = new_astro1;
			solar_system = new_astro2;
			astronomical_body = new_astro3;
			astronomical_type = new_astronomical_type;
		}
	}

	aid::aid(const string& init_aid) : aid()
	{
		initialize_from_string(init_aid);
	}
	
	aid& aid::operator =(const aid& x)
	{
		universe = x.universe;
		galaxy = x.galaxy;
		solar_system = x.solar_system;
		astronomical_body = x.astronomical_body;
		astronomical_type = x.astronomical_type;
		return *this;
	}
	
	aid& aid::operator =(aid&& x)
	{
		universe = std::move(x.universe);
		galaxy = std::move(x.galaxy);
		solar_system = std::move(x.solar_system);
		astronomical_body = std::move(x.astronomical_body);
		astronomical_type = std::move(x.astronomical_type);
		return *this;
	}

	aid& aid::operator =(const string& init_aid)
	{
		initialize_from_string(init_aid);
		return *this;
	}

	bool aid::has_no_universe() const
	{
		return (universe == "no-universe");
	}

	bool aid::has_unknown_universe() const
	{
		return (universe == "unknown-universe");
	}

	bool aid::has_no_galaxy() const
	{
		return (galaxy == "no-galaxy");
	}

	bool aid::has_unknown_galaxy() const
	{
		return (galaxy == "unknown-galaxy");
	}

	bool aid::has_unknown_solar_system() const
	{
		return (solar_system == "unknown-solar-system");
	}

	bool aid::has_no_solar_system() const
	{
		return (solar_system == "no-solar-system");
	}

	bool aid::has_unknown_planet() const
	{
		return (astronomical_body == "unknown-planet");
	}

	bool aid::has_unknown_moon() const
	{
		return (astronomical_body == "unknown-moon");
	}

	bool aid::has_unknown_star() const
	{
		return (astronomical_body == "unknown-star");
	}

	bool aid::has_unknown_asteroid() const
	{
		return (astronomical_body == "unknown-asteroid");
	}

	void aid::initialize_from_string(const string& init_aid)
	{
		if (init_aid.size() == 0)
		{
			return;
		}
		vector<string> values;
		boost::split(values,init_aid,boost::is_any_of(":"));
		string aid_type;
		if (values[0].front() == '(' and isalpha(values[0][1]))
		{
			string new_value1;
			if (isalpha(values[0][2]))
			{
				astronomical_type = create_astronomical_type(values[0].substr(1,2));
				if (values[0].at(4) != ' ')
				{
					new_value1 = values[0].substr(4);
				}
				else
				{
					new_value1 = values[0].substr(5);
				}
			}
			else
			{
				astronomical_type = create_astronomical_type(values[0].substr(1,1));
				if (values[0].at(3) != ' ')
				{
					new_value1 = values[0].substr(3);
				}
				else
				{
					new_value1 = values[0].substr(4);
				}
			}
			if (astronomical_type != aid::UNIVERSE and astronomical_type != aid::GALAXY and astronomical_type != aid::SOLAR_SYSTEM)
			{
				if (values.size() == 4)
				{
					universe = new_value1;
					galaxy = values[1];
					solar_system = values[2];
					astronomical_body = values[3];
				}
				else if (values.size() == 3)
				{
					universe = "universe";
					galaxy = new_value1;
					solar_system = values[1];
					astronomical_body = values[2];
				}
				else
				{
					astronomical_type = aid::NONE;
				}
			}
			else if (astronomical_type == aid::SOLAR_SYSTEM)
			{
				if (values.size() == 3)
				{
					universe = new_value1;
					galaxy = values[1];
					solar_system = values[2];
				}
				else if (values.size() == 2)
				{
					universe = "universe";
					galaxy = new_value1;
					solar_system = values[1];
				}
				else
				{
					astronomical_type = aid::NONE;
				}
			}
			else if (astronomical_type == aid::GALAXY)
			{
				if (values.size() == 2)
				{
					universe = new_value1;
					galaxy = values[1];
				}
				else if (values.size() == 1)
				{
					universe = "universe";
					galaxy = new_value1;
				}
				else
				{
					astronomical_type = aid::NONE;
				}
			}
			else if (astronomical_type == aid::UNIVERSE)
			{
				universe = new_value1;
			}
		}
	}

	string aid::display() const
	{
		if (astronomical_type != aid::NONE)
		{
			ostringstream out;
			out << "(" << to_string(astronomical_type) << ") ";
			if (astronomical_type == aid::UNIVERSE)
			{
				out << universe;
			}
			else if (astronomical_type == aid::GALAXY)
			{
				if (universe != "" and universe != "universe")
				{
					out << universe << ":";
				}
				out << galaxy;
			}
			else if (astronomical_type == aid::SOLAR_SYSTEM)
			{
				if (universe != "" and universe != "universe")
				{
					out << universe << ":";
				}
				out << galaxy << ":" << solar_system;
			}
			else
			{
				if (universe != "" and universe != "universe")
				{
					out << universe << ":";
				}
				out << galaxy << ":" << solar_system << ":" << astronomical_body;
			}
			return out.str();
		}
		else
		{
			return "";
		}
	}

	string to_string(const aid& x)
	{
		return x.display();
	}

	string to_string(const aid::type& x)
	{
		switch (x)
		{
			case aid::UNIVERSE:
				return "U";
			case aid::GALAXY:
				return "G";
			case aid::SOLAR_SYSTEM:
				return "SS";
			case aid::PLANET:
				return "P";
			case aid::STAR:
				return "ST";
			case aid::ASTEROID:
				return "A";
			case aid::MOON:
				return "MN";
			case aid::METEOR:
				return "MT";
			case aid::NONE:
				return "";
		}
		return "";
	}

	aid::type create_astronomical_type(const string& astronomical_type_abbreviation)
	{
		if (astronomical_type_abbreviation == "U")
		{
			return aid::UNIVERSE;
		}
		else if (astronomical_type_abbreviation == "G")
		{
			return aid::GALAXY;
		}
		else if (astronomical_type_abbreviation == "SS")
		{
			return aid::SOLAR_SYSTEM;
		}
		else if (astronomical_type_abbreviation == "P")
		{
			return aid::PLANET;
		}
		else if (astronomical_type_abbreviation == "ST")
		{
			return aid::STAR;
		}
		else if (astronomical_type_abbreviation == "A")
		{
			return aid::ASTEROID;
		}
		else if (astronomical_type_abbreviation == "MN")
		{
			return aid::MOON;
		}
		else if (astronomical_type_abbreviation == "MT")
		{
			return aid::METEOR;
		}
		else
		{
			return aid::NONE;
		}
	}
}

bool operator ==(const scifir::aid& x, const scifir::aid& y)
{
	if(x.universe == y.universe and x.galaxy == y.galaxy and x.solar_system == y.solar_system and x.astronomical_body == y.astronomical_body)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const scifir::aid& x, const scifir::aid& y)
{
	return !(x == y);
}

bool operator ==(const scifir::aid& x, const string& init_aid)
{
	scifir::aid y = scifir::aid(init_aid);
	return (x == y);
}

bool operator !=(const scifir::aid& x, const string& init_aid)
{
	return !(x == init_aid);
}

bool operator ==(const string& init_aid, const scifir::aid& x)
{
	scifir::aid y = scifir::aid(init_aid);
	return (x == y);
}

bool operator !=(const string& init_aid, const scifir::aid& x)
{
	return !(init_aid == x);
}

void operator +=(string& x, const scifir::aid& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const scifir::aid& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const scifir::aid& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const scifir::aid& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, scifir::aid& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	x = scifir::aid(b);
	return is;
}
