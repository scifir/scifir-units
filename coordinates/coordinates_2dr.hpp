#ifndef MSCI_UNITS_COORDINATES_COORDINATES_2DR_HPP_INCLUDED
#define MSCI_UNITS_COORDINATES_COORDINATES_2DR_HPP_INCLUDED

#include "topology/point_2d.hpp"
#include "meca_number/angle.hpp"
#include "coordinates/coordinates_2d.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	class coordinates_2dr
	{
		public:
			coordinates_2dr();
			coordinates_2dr(const length&,const length&,const angle&);
			coordinates_2dr(const string&);

			length x;
			length y;
			angle theta;
	};

	string to_string(const coordinates_2dr&);
	length distance(const coordinates_2dr&,const coordinates_2dr&);
}

bool operator ==(const msci::coordinates_2dr&,const msci::coordinates_2dr&);
bool operator !=(const msci::coordinates_2dr&,const msci::coordinates_2dr&);

template<typename T>
bool operator ==(const msci::coordinates_2dr& x,const msci::coordinates_2d<T>& y)
{
	if (x.x == y.x and x.y == y.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const msci::coordinates_2dr& x,const msci::coordinates_2d<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const msci::coordinates_2d<T>& x,const msci::coordinates_2dr& y)
{
	if (x.x == y.x and x.y == y.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const msci::coordinates_2d<T>& x,const msci::coordinates_2dr& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const msci::coordinates_2dr& x,const msci::point_2d<T>& y)
{
	if (x.x == y.x and x.y == y.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const msci::coordinates_2dr& x,const msci::point_2d<T>& y)
{
	return !(x == y);
}

template<typename T>
bool operator ==(const msci::point_2d<T>& x,const msci::coordinates_2dr& y)
{
	if (x.x == y.x and x.y == y.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool operator !=(const msci::point_2d<T>& x,const msci::coordinates_2dr& y)
{
	return !(x == y);
}

ostream& operator << (ostream&, const msci::coordinates_2dr&);

#endif // MSCI_UNITS_COORDINATES_COORDINATES_2DR_HPP_INCLUDED
