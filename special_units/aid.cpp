#include "aid.hpp"

#include "boost/algorithm/string.hpp"

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

namespace msci
{
	aid::aid() : universe(),galaxy(),solar_system(),astronomical_body(),astronomical_type(aid::NONE)
	{}

	aid::aid(const aid& x) : universe(x.universe),galaxy(x.galaxy),solar_system(x.solar_system),astronomical_body(x.astronomical_body),astronomical_type(x.astronomical_type)
	{}

	aid::aid(aid&& x) : universe(move(x.universe)),galaxy(move(x.galaxy)),solar_system(move(x.solar_system)),astronomical_body(move(x.astronomical_body)),astronomical_type(move(x.astronomical_type))
	{}
	
	aid::aid(const enum astronomical_body& x) : aid()
	{
		universe = "universe";
		if (x == astronomical_body::MILKY_WAY)
		{
			galaxy = "milky-way";
			astronomical_type = aid::GALAXY;
		}
		else if (x == astronomical_body::ANDROMEDA)
		{
			galaxy = "andromeda";
			astronomical_type = aid::GALAXY;
		}
		else if (x == astronomical_body::SOLAR_SYSTEM)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_type = aid::SOLAR_SYSTEM;
		}
		else if (x == astronomical_body::SUN)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "sun";
			astronomical_type = aid::STAR;
		}
		else if (x == astronomical_body::MOON)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "moon";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::MERCURY)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "mercury";
			astronomical_type = aid::PLANET;
		}
		else if (x == astronomical_body::VENUS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "venus";
			astronomical_type = aid::PLANET;
		}
		else if (x == astronomical_body::EARTH)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "earth";
			astronomical_type = aid::PLANET;
		}
		else if (x == astronomical_body::MARS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "mars";
			astronomical_type = aid::PLANET;
		}
		else if (x == astronomical_body::JUPITER)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "jupiter";
			astronomical_type = aid::PLANET;
		}
		else if (x == astronomical_body::SATURN)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "saturn";
			astronomical_type = aid::PLANET;
		}
		else if (x == astronomical_body::URANUS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "uranus";
			astronomical_type = aid::PLANET;
		}
		else if (x == astronomical_body::NEPTUNE)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "neptune";
			astronomical_type = aid::PLANET;
		}
		else if (x == astronomical_body::CERES)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "ceres";
			astronomical_type = aid::PLANET;
		}
		else if (x == astronomical_body::ORCUS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "orcus";
			astronomical_type = aid::PLANET;
		}
		else if (x == astronomical_body::PLUTO)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "pluto";
			astronomical_type = aid::PLANET;
		}
		else if (x == astronomical_body::HAUMEA)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "haumea";
			astronomical_type = aid::PLANET;
		}
		else if (x == astronomical_body::QUAOAR)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "quaoar";
			astronomical_type = aid::PLANET;
		}
		else if (x == astronomical_body::MAKEMAKE)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "makemake";
			astronomical_type = aid::PLANET;
		}
		else if (x == astronomical_body::GONGGONG)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "gonggong";
			astronomical_type = aid::PLANET;
		}
		else if (x == astronomical_body::ERIS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "eris";
			astronomical_type = aid::PLANET;
		}
		else if (x == astronomical_body::SEDNA)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "sedna";
			astronomical_type = aid::PLANET;
		}
		else if (x == astronomical_body::IO)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "io";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::EUROPA)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "europa";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::GANYMEDE)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "ganymede";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::CALLISTO)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "callisto";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::MIMAS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "mimas";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::ENCELADUS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "enceladus";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::TETHYS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "tethys";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::DIONE)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "dione";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::RHEA)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "rhea";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::TITAN)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "titan";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::IAPETUS)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "iapetus";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::MIRANDA)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "miranda";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::ARIEL)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "ariel";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::UMBRIEL)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "umbriel";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::TITANIA)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "titania";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::OBERON)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "oberon";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::TRITON)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "triton";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::CHARON)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "charon";
			astronomical_type = aid::MOON;
		}
		else if (x == astronomical_body::DYSNOMIA)
		{
			galaxy = "milky-way";
			solar_system = "solar-system";
			astronomical_body = "dysnomia";
			astronomical_type = aid::MOON;
		}
	}

	aid::aid(const string& new_universe,const string& new_galaxy) : universe(new_universe),galaxy(new_galaxy),solar_system(),astronomical_body(),astronomical_type(aid::GALAXY)
	{}

	aid::aid(const string& new_universe,const string& new_galaxy,const string& new_solar_system) : universe(new_universe),galaxy(new_galaxy),solar_system(new_solar_system),astronomical_body(),astronomical_type(aid::SOLAR_SYSTEM)
	{}

	aid::aid(const aid::type& new_astronomical_type,const string& new_universe,const string& new_galaxy,const string& new_solar_system,const string& new_astronomical_body) : universe(new_universe),galaxy(new_galaxy),solar_system(new_solar_system),astronomical_body(new_astronomical_body),astronomical_type(new_astronomical_type)
	{}

	aid::aid(const string& init_aid) : aid()
	{
		vector<string> values;
		boost::split(values,init_aid,boost::is_any_of(":"));
		string aid_type;
		if (values[0].front() == '(' and isalpha(values[0][1]))
		{
			if (isalpha(values[0][2]))
			{
				astronomical_type = create_astronomical_type(values[0].substr(1,2));
				universe = values[0].substr(4);
			}
			else
			{
				astronomical_type = create_astronomical_type(values[0].substr(1,1));
				universe = values[0].substr(3);
			}
			if (values.size() == 4)
			{
				galaxy = values[1];
				solar_system = values[2];
				astronomical_body = values[3];
			}
			else if (values.size() == 3)
			{
				galaxy = values[1];
				solar_system = values[2];
			}
			else if (values.size() == 2)
			{
				galaxy = values[1];
			}
		}
	}
	
	aid& aid::operator=(const aid& x)
	{
		universe = x.universe;
		galaxy = x.galaxy;
		solar_system = x.solar_system;
		astronomical_body = x.astronomical_body;
		astronomical_type = x.astronomical_type;
		return *this;
	}
	
	aid& aid::operator=(aid&& x)
	{
		universe = move(x.universe);
		galaxy = move(x.galaxy);
		solar_system = move(x.solar_system);
		astronomical_body = move(x.astronomical_body);
		astronomical_type = move(x.astronomical_type);
		return *this;
	}

	string to_string(const aid& x)
	{
		ostringstream out;
		out << "(" << to_string(x.astronomical_type) << ")";
		if (x.astronomical_type == aid::UNIVERSE)
		{
			out << x.universe;
		}
		else if (x.astronomical_type == aid::GALAXY)
		{
			out << x.universe << ":" << x.galaxy;
		}
		else if (x.astronomical_type == aid::SOLAR_SYSTEM)
		{
			out << x.universe << ":" << x.galaxy << ":" << x.solar_system;
		}
		else
		{
			if (x.universe != "")
			{
				out << x.universe << ":";
			}
			out << x.galaxy << ":" << x.solar_system << ":" << x.astronomical_body;
		}
		return out.str();
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
		return "U";
	}

	aid::type create_astronomical_type(const string& x)
	{
		if (x == "U")
		{
			return aid::UNIVERSE;
		}
		else if (x == "G")
		{
			return aid::GALAXY;
		}
		else if (x == "SS")
		{
			return aid::SOLAR_SYSTEM;
		}
		else if (x == "P")
		{
			return aid::PLANET;
		}
		else if (x == "ST")
		{
			return aid::STAR;
		}
		else if (x == "A")
		{
			return aid::ASTEROID;
		}
		else if (x == "MN")
		{
			return aid::MOON;
		}
		else if (x == "MT")
		{
			return aid::METEOR;
		}
		else
		{
			return aid::NONE;
		}
	}
}

bool operator ==(const msci::aid& x, const msci::aid& y)
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

bool operator !=(const msci::aid& x, const msci::aid& y)
{
	return !(x == y);
}

bool operator ==(const msci::aid& x, const string& y)
{
	msci::aid y_aid = msci::aid(y);
	return (x == y_aid);
}

bool operator !=(const msci::aid& x, const string& y)
{
	return !(x == y);
}

bool operator ==(const string& x, const msci::aid& y)
{
	msci::aid x_aid = msci::aid(x);
	return (x_aid == y);
}

bool operator !=(const string& x, const msci::aid& y)
{
	return !(x == y);
}

void operator +=(string& x, const msci::aid& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const msci::aid& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const msci::aid& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const msci::aid& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, msci::aid& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::aid c(b);
	x = c;
	return is;
}
