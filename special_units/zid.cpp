#include "./zid.hpp"

#include "boost/algorithm/string.hpp"

#include <iostream>
#include <sstream>

using namespace std;

namespace scifir
{
	zid::zid() : aid(),regions(),country(),zone()
	{}

	zid::zid(const zid& x) : aid(x.aid),regions(x.regions),country(x.country),zone(x.zone)
	{}

	zid::zid(zid&& x) : aid(std::move(x.aid)),regions(std::move(x.regions)),country(std::move(x.country)),zone(std::move(x.zone))
	{}

	zid::zid(const scifir::aid& x_aid,const string& new_country,const vector<string>& new_regions,const string& new_zone) : aid(x_aid),country(new_country),regions(new_regions),zone(new_zone)
	{}

	zid::zid(const scifir::aid& x_aid,const string& init_zid) : aid(x_aid),regions(),country(),zone()
	{
		if (init_zid != "")
		{
			vector<string> values;
			boost::split(values,init_zid,boost::is_any_of(":"));
			country = values[0];
			if (values.size() > 2)
			{
				int total_for_values = int(values.size()) - 1;
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
	}

	zid::zid(const string& init_zid_full) : zid()
	{
		initialize_from_string(init_zid_full);
	}

	zid& zid::operator=(const zid& x)
	{
		aid = x.aid;
		regions = x.regions;
		country = x.country;
		zone = x.zone;
		return *this;
	}

	zid& zid::operator=(zid&& x)
	{
		aid = std::move(x.aid);
		regions = std::move(x.regions);
		country = std::move(x.country);
		zone = std::move(x.zone);
		return *this;
	}

	zid& zid::operator=(const string& init_zid_full)
	{
		initialize_from_string(init_zid_full);
		return *this;
	}

	void zid::initialize_from_string(const string& init_zid_full)
	{
		if (init_zid_full != "")
		{
			int number_whitespaces = std::count(init_zid_full.begin(),init_zid_full.end(),' ');
			std::size_t last_whitespace = init_zid_full.find_last_of(' ');
			if (number_whitespaces == 2 or number_whitespaces == 1)
			{
				string init_aid = init_zid_full.substr(0,last_whitespace);
				string init_zid = init_zid_full.substr(last_whitespace + 1);
				aid = scifir::aid(init_aid);
				vector<string> values;
				boost::split(values,init_zid,boost::is_any_of(":"));
				country = values[0];
				if (values.size() > 2)
				{
					int total_for_values = int(values.size()) - 1;
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
			else if (number_whitespaces == 0)
			{
				vector<string> values;
				boost::split(values,init_zid_full,boost::is_any_of(":"));
				country = values[0];
				if (values.size() > 2)
				{
					int total_for_values = int(values.size()) - 1;
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
		}
	}

	string to_string(const zid& x)
	{
		if (x.country != "")
		{
			ostringstream out;
			out << to_string(x.aid) << " " << x.country << ":";
			for (const string& x_region : x.regions)
			{
				out << x_region << ":";
			}
			out << x.zone;
			return out.str();
		}
		else
		{
			return "";
		}
	}
}

bool operator ==(const scifir::zid& x, const scifir::zid& y)
{
	if (x.aid == y.aid)
	{
		if (x.country == y.country)
		{
			for (unsigned int i = 0; i < x.regions.size(); i++)
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
