#ifndef MSCI_UNITS_UNITS_PREFIX_HPP_INCLUDED
#define MSCI_UNITS_UNITS_PREFIX_HPP_INCLUDED

#include <iostream>
#include <map>
#include <string>

using namespace std;

namespace msci
{
	class prefix
	{
		public:
			enum type : char {no_prefix,Y,Z,E,P,T,G,M,k,h,da,d,c,m,u,n,p,f,a,z,y};

			prefix();
			prefix(const prefix&);
			prefix(prefix&&);
			explicit prefix(prefix::type);
			explicit prefix(const string&);

			prefix& operator=(const prefix&);
			prefix& operator=(prefix&&);

			int get_conversion_factor() const;
			string get_name() const;
			string get_symbol() const;

			bool operator<(const msci::prefix&) const;

			prefix::type prefix_type;
	};

	prefix::type prefix_string(const string&);

	prefix create_prefix(prefix::type);
	prefix create_prefix(const string&);

	prefix closest_prefix(const prefix&,int);
	prefix create_prefix_by_factor(int);
}

bool operator ==(const msci::prefix&,const msci::prefix&);
bool operator !=(const msci::prefix&,const msci::prefix&);
bool operator <=(const msci::prefix&,const msci::prefix&);
bool operator >(const msci::prefix&,const msci::prefix&);
bool operator >=(const msci::prefix&,const msci::prefix&);

ostream& operator <<(ostream&, const msci::prefix&);

#endif // MSCI_UNITS_UNITS_PREFIX_HPP_INCLUDED
