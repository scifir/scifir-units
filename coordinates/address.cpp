#include "./address.hpp"

using namespace std;

namespace scifir
{
	address::address() : zid(),location(),inner_location(),postal_code()
	{}

	address::address(const address& x) : zid(x.zid),location(x.location),inner_location(x.inner_location),postal_code(x.postal_code)
	{}

	address::address(address&& x) : zid(std::move(x.zid)),location(std::move(x.location)),inner_location(std::move(x.inner_location)),postal_code(std::move(x.postal_code))
	{}

	address::address(const scifir::zid& new_zid,const string& new_location,const string& new_inner_location,const string& new_postal_code) : zid(new_zid),location(new_location),inner_location(new_inner_location),postal_code(new_postal_code)
	{}

	address& address::operator =(const address& x)
	{
		zid = x.zid;
		location = x.location;
		inner_location = x.inner_location;
		postal_code = x.postal_code;
		return *this;
	}
	
	address& address::operator =(address&& x)
	{
		zid = std::move(x.zid);
		location = std::move(x.location);
		inner_location = std::move(x.inner_location);
		postal_code = std::move(x.postal_code);
		return *this;
	}

	address::type address::get_type() const
	{
		if (inner_location != "")
		{
			return address::INTERNAL;
		}
		else
		{
			return address::EXTERNAL;
		}
	}

	string address::display() const
	{
		if (inner_location != "")
		{
			return zid + ", " + location + " " + inner_location;
		}
		else
		{
			return partial_display();
		}
	}

	string address::partial_display() const
	{
		return location + " " + inner_location;
	}

	string address::text_display() const
	{
		ostringstream out;
		out << zid << "\n";
		out << location << "\n";
		out << inner_location << "\n";
		return out.str();
	}
}

bool operator ==(const scifir::address& x, const scifir::address& y)
{
	if(x.zid == y.zid and x.location == y.location and x.postal_code == y.postal_code and x.inner_location == y.inner_location)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const scifir::address& x, const scifir::address& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os, const scifir::address& x)
{
	return os << x.display();
}