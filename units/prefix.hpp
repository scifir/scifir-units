#ifndef MSCI_UNITS_UNITS_PREFIX_HPP_INCLUDED
#define MSCI_UNITS_UNITS_PREFIX_HPP_INCLUDED

#include <iostream>
#include <map>
#include <memory>
#include <string>

using namespace std;

namespace msci
{
	class prefix
	{
		public:
			enum type {no_prefix,Y,Z,E,P,T,G,M,k,h,da,d,c,m,u,n,p,f,a,z,y};

			prefix();
			prefix(const prefix&);
			prefix(prefix&&);
			prefix(prefix::type);
			prefix(const string&);
			
			prefix& operator=(const prefix&);
			prefix& operator=(prefix&&);

			int get_conversion_factor() const;
			float get_prefix_base() const;
			string get_name() const;
			string get_symbol() const;

			prefix::type prefix_type;
	};

	prefix::type prefix_string(const string&);

	prefix create_prefix(prefix::type);
	prefix create_prefix(const string&);
}

ostream& operator <<(ostream&, const msci::prefix&);

#endif // MSCI_UNITS_UNITS_PREFIX_HPP_INCLUDED
