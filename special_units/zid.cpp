#include "./zid.hpp"

#include "boost/algorithm/string.hpp"

#include <sstream>

using namespace std;

namespace scifir
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

bool operator ==(const scifir::zid& x, const scifir::zid& y)
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

bool operator !=(const scifir::zid& x, const scifir::zid& y)
{
	return !(x == y);
}

bool operator ==(const scifir::zid& x, const string& y)
{
	scifir::zid y_zid = scifir::zid(y);
	return (x == y_zid);
}

bool operator !=(const scifir::zid& x, const string& y)
{
	return !(x == y);
}

bool operator ==(const string& x, const scifir::zid& y)
{
	scifir::zid x_zid = scifir::zid(x);
	return (x_zid == y);
}

bool operator !=(const string& x, const scifir::zid& y)
{
	return !(x == y);
}

void operator +=(string& x, const scifir::zid& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const scifir::zid& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const scifir::zid& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const scifir::zid& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, scifir::zid& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	scifir::zid c(b);
	x = c;
	return is;
}
