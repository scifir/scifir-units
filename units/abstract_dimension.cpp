#include "msci/units/units/abstract_dimension.hpp"
#include "msci/units/units/prefix.hpp"

#include <cmath>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

namespace msci
{
	dimension_prefixes::dimension_prefixes() : map<prefix_symbol, shared_ptr<prefix>>()
	{
	}

	dimension_prefixes::dimension_prefixes(const dimension_prefixes& new_dimension_prefixes)
	{
		for(const auto& new_dimension_prefix : new_dimension_prefixes)
		{
			(*this)[new_dimension_prefix.first] = shared_ptr<prefix>(new_dimension_prefix.second->clone());
		}
	}

	abstract_dimension::abstract_dimension(prefix_symbol prefix_name, int new_scale) : prefixes()
	{
		add_prefix(prefix_name);
	}

	abstract_dimension::abstract_dimension() : abstract_dimension(normal_prefix, 1)
	{
	}

	abstract_dimension::abstract_dimension(prefix& new_prefix, int new_scale) : prefixes()
	{
		shared_ptr<prefix> a = shared_ptr<prefix>(&new_prefix);
		prefixes[a->get_enum_type()] = a;
	}

	const int abstract_dimension::get_scale() const
	{
		int sum = 0;
		for(const auto& prefix : prefixes)
		{
			sum += prefix.second->scale;
		}
		return sum;
	}

	float abstract_dimension::get_prefix_base() const
	{
		return 10;
	}

	void abstract_dimension::add_prefix(prefix_symbol prefix_name)
	{
		if(prefixes.count(prefix_name) > 0)
		{
			prefixes[prefix_name]->scale += 1;
		}
		else
		{
			prefixes[prefix_name] = shared_ptr<prefix>(create_prefix(prefix_name));
		}
	}

	void abstract_dimension::add_prefix(const prefix& new_prefix)
	{
		prefix_symbol prefix_name = new_prefix.get_enum_type();
		if(prefixes.count(prefix_name) > 0)
		{
			prefixes[prefix_name]->scale += new_prefix.scale;
			if(prefixes[prefix_name]->scale == 0)
			{
				remove_prefix(prefix_name);
			}
		}
		else
		{
			prefixes[prefix_name] = shared_ptr<prefix>(create_prefix(prefix_name));
		}
	}

	void abstract_dimension::add_prefix(const dimension_prefixes& new_prefixes)
	{
		for(auto& new_prefix : new_prefixes)
		{
			add_prefix(*new_prefix.second);
		}
	}

	void abstract_dimension::remove_prefix(prefix_symbol prefix_name)
	{
		for(const auto& prefix : prefixes)
		{
			if(prefix.second->get_enum_type() == prefix_name)
			{
				prefixes.erase(prefix.first);
				break;
			}
		}
	}

	void abstract_dimension::remove_prefix(const prefix& new_prefix)
	{
		prefix_symbol prefix_name = new_prefix.get_enum_type();
		if(prefixes.count(prefix_name) > 0)
		{
			prefixes[prefix_name]->scale -= new_prefix.scale;
			if(prefixes[prefix_name]->scale == 0)
			{
				remove_prefix(prefix_name);
			}
		}
		else
		{
			prefixes[prefix_name] = shared_ptr<prefix>(create_prefix(prefix_name));
		}
	}

	void abstract_dimension::remove_prefix(const dimension_prefixes& new_prefixes)
	{
		for(auto& new_prefix : new_prefixes)
		{
			remove_prefix(*new_prefix.second);
		}
	}

	void abstract_dimension::change_prefix(prefix_symbol new_prefix)
	{
		prefixes.erase(prefixes.begin());
		add_prefix(new_prefix);
	}

	int abstract_dimension::total_factor()
	{
		int sum = 0;
		for(auto& prefix : prefixes)
		{
			sum += prefix.second->get_conversion_factor() * prefix.second->scale;
		}
		return sum;
	}

	void abstract_dimension::operator *=(const abstract_dimension& x)
	{
		for(auto& prefix : x.get_dimension_prefixes())
		{
			add_prefix(*prefix.second);
		}
	}

	void abstract_dimension::operator /=(const abstract_dimension& x)
	{
		for(auto& prefix : x.get_dimension_prefixes())
		{
			remove_prefix(*prefix.second);
		}
	}

	void abstract_dimension::sqrt()
	{
		if(remainder(get_scale(), 2) == 0)
		{
			for(auto& new_prefix : prefixes)
			{
				if(remainder(new_prefix.second->scale, 2) != 0)
				{
					throw invalid_argument("Cannot square because some prefixes doesn't match the requirements. " + new_prefix.second->get_name() + " has a scale of " + to_string(new_prefix.second->scale));
				}
			}
			for(auto& new_prefix : prefixes)
			{
				new_prefix.second->scale /= 2;
			}
		}
		else
		{
			throw invalid_argument("Cannot square a dimension without a perfect square at his scale");
		}
	}

	void abstract_dimension::sqrt_nth(int x)
	{
		if(remainder(get_scale(), x) == 0)
		{
			for(auto& new_prefix : prefixes)
			{
				if(remainder(new_prefix.second->scale, x) != 0)
				{
					throw invalid_argument("Cannot square-nth because some prefixes doesn't match the requirements. " + new_prefix.second->get_name() + " has a scale of " + to_string(new_prefix.second->scale));
				}
			}
			for(auto& new_prefix : prefixes)
			{
				new_prefix.second->scale /= x;
			}
		}
		else
		{
			throw invalid_argument("Cannot square-nth a dimension without a perfect square at his scale");
		}
	}
}

bool operator ==(const msci::abstract_dimension& x,const msci::abstract_dimension& y)
{
	if(x.get_scale() == y.get_scale() and x.get_symbol() == y.get_symbol())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::abstract_dimension& x,const msci::abstract_dimension& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os, const msci::abstract_dimension& x)
{
	ostringstream prefix_text;
	if(x.get_dimension_prefixes().size() > 0)
	{
		for(auto& prefix : x.get_dimension_prefixes())
		{
			string prefix_symbol = string(prefix.second->get_symbol().begin(), prefix.second->get_symbol().end());
			string dimension_symbol = string(x.get_symbol().begin(), x.get_symbol().end());
			if(abs(prefix.second->scale) > 1)
			{
				prefix_text << prefix_symbol << dimension_symbol << abs(prefix.second->scale) << "*";
			}
			else
			{
				prefix_text << prefix_symbol << dimension_symbol << "*";
			}
		}
	}
	string final = prefix_text.str();
	return os << final.substr(0,final.length() - 1);
}
