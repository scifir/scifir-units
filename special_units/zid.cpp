#include "./zid.hpp"

#include "boost/algorithm/string.hpp"

#include <iostream>
#include <sstream>

using namespace std;

namespace scifir
{
	zid::zid() : aid(),regions(),country(),zone(),zone_type(zid::NONE)
	{}

	zid::zid(const zid& x) : aid(x.aid),regions(x.regions),country(x.country),zone(x.zone),zone_type(x.zone_type)
	{}

	zid::zid(zid&& x) : aid(std::move(x.aid)),regions(std::move(x.regions)),country(std::move(x.country)),zone(std::move(x.zone)),zone_type(std::move(x.zone_type))
	{}

	zid::zid(const scifir::aid& new_aid,const zid::type& new_zid_type,const string& new_country) : aid(),country(),regions(),zone(),zone_type(zid::NONE)
	{
		if (new_zid_type == zid::COUNTRY)
		{
			aid = new_aid;
			country = new_country;
			zone_type = zid::COUNTRY;
		}
	}

	zid::zid(const scifir::aid& new_aid,const string& new_country,const vector<string>& new_regions) : aid(new_aid),country(new_country),regions(new_regions),zone(),zone_type(zid::REGION)
	{}

	zid::zid(const scifir::aid& new_aid,const zid::type& new_zid_type,const string& new_country,const vector<string>& new_regions,const string& new_zone) : aid(),country(),regions(),zone(),zone_type(zid::NONE)
	{
		if (new_zid_type != zid::COUNTRY and new_zid_type != zid::REGION)
		{
			aid = new_aid;
			regions = new_regions;
			country = new_country;
			zone = new_zone;
			zone_type = new_zid_type;
		}
	}

	zid::zid(const scifir::aid& new_aid,const string& init_zid) : aid(new_aid),regions(),country(),zone(),zone_type(zid::NONE)
	{
		if (init_zid != "")
		{
			vector<string> values;
			boost::split(values,init_zid,boost::is_any_of(":"));
			if (values[0].front() == '(' and isalpha(values[0][1]))
			{
				zone_type = create_zone_type(values[0].substr(1,1));
				string new_country;
				if (values[0][3] != ' ')
				{
					new_country = values[0].substr(3);
				}
				else
				{
					new_country = values[0].substr(4);
				}
				if (values.size() == 1 and zone_type == zid::COUNTRY)
				{
					country = new_country;
				}
				if ((values.size() >= 2 and zone_type == zid::REGION) or (values.size() >= 3 and (zone_type == zid::ZONE or zone_type == zid::SETTLEMENT)))
				{
					country = new_country;
					int total_for_values;
					if (zone_type == zid::REGION)
					{
						total_for_values = int(values.size());
					}
					else if (zone_type == zid::ZONE or zone_type == zid::SETTLEMENT)
					{
						total_for_values = int(values.size()) - 1;
					}
					for (int i = 1; i < total_for_values; i++)
					{
						regions.push_back(values[i]);
					}
				}
				if (values.size() >= 3 and (zone_type == zid::ZONE or zone_type == zid::SETTLEMENT))
				{
					country = new_country;
					zone = values.back();
				}
				if (country == "")
				{
					zone_type = zid::NONE;
				}
			}
		}
	}

	zid::zid(const string& init_zid_full) : zid()
	{
		initialize_from_string(init_zid_full);
	}

	zid& zid::operator =(const zid& x)
	{
		aid = x.aid;
		regions = x.regions;
		country = x.country;
		zone = x.zone;
		zone_type = x.zone_type;
		return *this;
	}

	zid& zid::operator =(zid&& x)
	{
		aid = std::move(x.aid);
		regions = std::move(x.regions);
		country = std::move(x.country);
		zone = std::move(x.zone);
		zone_type = std::move(x.zone_type);
		return *this;
	}

	zid& zid::operator =(const string& init_zid_full)
	{
		initialize_from_string(init_zid_full);
		return *this;
	}

	bool zid::has_no_country() const
	{
		return (country == "no-country");
	}

	bool zid::has_unknown_country() const
	{
		return (country == "unknown-country");
	}

	string zid::display() const
	{
		if (country != "")
		{
			ostringstream out;
			out << to_string(aid) << " (" << to_string(zone_type) << ") " << country << ":";
			for (const string& x_region : regions)
			{
				out << x_region << ":";
			}
			out << zone;
			return out.str();
		}
		else
		{
			return "";
		}
	}

	string zid::partial_display() const
	{
		if (country != "")
		{
			ostringstream out;
			out << "(" << to_string(zone_type) << ") " << country << ":";
			for (const string& x_region : regions)
			{
				out << x_region << ":";
			}
			out << zone;
			return out.str();
		}
		else
		{
			return "";
		}
	}

	void zid::initialize_from_string(const string& init_zid_full)
	{
		if (init_zid_full != "")
		{
			if (!(init_zid_full[1] == 'C' or init_zid_full[1] == 'R' or init_zid_full[1] == 'Z'))
			{
				std::size_t last_whitespace = init_zid_full.find(" (");
				string init_aid = init_zid_full.substr(0,last_whitespace);
				string init_zid = init_zid_full.substr(last_whitespace + 1);
				aid = scifir::aid(init_aid);
				vector<string> values;
				boost::split(values,init_zid,boost::is_any_of(":"));
				if (values[0].front() == '(' and isalpha(values[0][1]))
				{
					zone_type = create_zone_type(values[0].substr(1,1));
					string new_country;
					if (values[0][3] != ' ')
					{
						new_country = values[0].substr(3);
					}
					else
					{
						new_country = values[0].substr(4);
					}
					if (values.size() == 1 and zone_type == zid::COUNTRY)
					{
						country = new_country;
					}
					if ((values.size() >= 2 and zone_type == zid::REGION) or (values.size() >= 3 and (zone_type == zid::ZONE or zone_type == zid::SETTLEMENT)))
					{
						country = new_country;
						int total_for_values;
						if (zone_type == zid::REGION)
						{
							total_for_values = int(values.size());
						}
						else if (zone_type == zid::ZONE or zone_type == zid::SETTLEMENT)
						{
							total_for_values = int(values.size()) - 1;
						}
						for (int i = 1; i < total_for_values; i++)
						{
							regions.push_back(values[i]);
						}
					}
					if (values.size() >= 3 and (zone_type == zid::ZONE or zone_type == zid::SETTLEMENT))
					{
						country = new_country;
						zone = values.back();
					}
					if (country == "")
					{
						zone_type = zid::NONE;
					}
				}
			}
			else
			{
				vector<string> values;
				boost::split(values,init_zid_full,boost::is_any_of(":"));
				if (values[0].front() == '(' and isalpha(values[0][1]))
				{
					zone_type = create_zone_type(values[0].substr(1,1));
					string new_country;
					if (values[0][3] != ' ')
					{
						new_country = values[0].substr(3);
					}
					else
					{
						new_country = values[0].substr(4);
					}
					if (values.size() == 1 and zone_type == zid::COUNTRY)
					{
						country = new_country;
					}
					if ((values.size() >= 2 and zone_type == zid::REGION) or (values.size() >= 3 and (zone_type == zid::ZONE or zone_type == zid::SETTLEMENT)))
					{
						country = new_country;
						int total_for_values;
						if (zone_type == zid::REGION)
						{
							total_for_values = int(values.size());
						}
						else if (zone_type == zid::ZONE or zone_type == zid::SETTLEMENT)
						{
							total_for_values = int(values.size()) - 1;
						}
						for (int i = 1; i < total_for_values; i++)
						{
							regions.push_back(values[i]);
						}
					}
					if (values.size() >= 3 and (zone_type == zid::ZONE or zone_type == zid::SETTLEMENT))
					{
						country = new_country;
						zone = values.back();
					}
					if (country == "")
					{
						zone_type = zid::NONE;
					}
				}
			}
		}
	}

	string to_string(const zid& x)
	{
		return x.display();
	}

	string to_string(const zid::type& x)
	{
		switch (x)
		{
			case zid::NONE:
				return "";
			case zid::COUNTRY:
				return "C";
			case zid::REGION:
				return "R";
			case zid::SETTLEMENT:
				return "S";
			case zid::ZONE:
				return "Z";
		}
		return "";
	}

	zid::type create_zone_type(const string& zone_type_abbreviation)
	{
		if (zone_type_abbreviation == "C")
		{
			return zid::COUNTRY;
		}
		else if (zone_type_abbreviation == "R")
		{
			return zid::REGION;
		}
		else if (zone_type_abbreviation == "S")
		{
			return zid::SETTLEMENT;
		}
		else if (zone_type_abbreviation == "Z")
		{
			return zid::ZONE;
		}
		else
		{
			return zid::NONE;
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

bool operator ==(const scifir::zid& x, const string& init_zid_full)
{
	scifir::zid y = scifir::zid(init_zid_full);
	return (x == y);
}

bool operator !=(const scifir::zid& x, const string& init_zid_full)
{
	return !(x == init_zid_full);
}

bool operator ==(const string& init_zid_full, const scifir::zid& x)
{
	scifir::zid y = scifir::zid(init_zid_full);
	return (x == y);
}

bool operator !=(const string& init_zid_full, const scifir::zid& x)
{
	return !(init_zid_full == x);
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
	x = scifir::zid(b);
	return is;
}
