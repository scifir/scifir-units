#include "special_units/zid.hpp"

#include "boost/algorithm/string.hpp"

#include <sstream>

using namespace std;

namespace msci
{
	zid::zid() : regions(),country(),zone()
	{}

	zid::zid(const zid& x) : regions(x.regions),country(x.country),zone(x.zone)
	{}

	zid::zid(zid&& x) : regions(move(x.regions)),country(move(x.country)),zone(move(x.zone))
	{}

	zid::zid(const string& init_zid) : zid()
	{
		vector<string> values;
		boost::split(values,init_zid,boost::is_any_of(":"));
		country = values[0];
		if (values.size() > 2)
		{
			int total_for_values = (values.size() - 1);
			for (int i = 1; i < total_for_values; i++)
			{
				regions.push_back(values[i]);
			}
		}
		if (values.size() >= 2)
		{
			zone = values.back();
		}
	}

	zid& zid::operator=(const zid& x)
	{
		regions = x.regions;
		country = x.country;
		zone = x.zone;
		return *this;
	}

	zid& zid::operator=(zid&& x)
	{
		regions = move(x.regions);
		country = move(x.country);
		zone = move(x.zone);
		return *this;
	}

	string to_string(const zid& x)
	{
		ostringstream out;
		out << x.aid << " " << x.country << ":";
		for (const string& x_region : x.regions)
		{
			out << x_region << ":";
		}
		out << x.zone;
		return out.str();
	}
}

bool operator ==(const msci::zid& x, const msci::zid& y)
{
	if(x.country == y.country)
	{
		for (int i = 0; i < x.regions.size(); i++)
		{
			if (x.regions[i] != y.regions[i])
			{
				return false;
			}
		}
		if (x.zone == y.zone)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::zid& x, const msci::zid& y)
{
	return !(x == y);
}

bool operator ==(const msci::zid& x, const string& y)
{
	msci::zid y_zid = msci::zid(y);
	return (x == y_zid);
}

bool operator !=(const msci::zid& x, const string& y)
{
	return !(x == y);
}

bool operator ==(const string& x, const msci::zid& y)
{
	msci::zid x_zid = msci::zid(x);
	return (x_zid == y);
}

bool operator !=(const string& x, const msci::zid& y)
{
	return !(x == y);
}

void operator +=(string& x, const msci::zid& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const msci::zid& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const msci::zid& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const msci::zid& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, msci::zid& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::zid c(b);
	x = c;
	return is;
}
