#ifndef MSCI_UNITS_UNITS_PREFIX_HPP
#define MSCI_UNITS_UNITS_PREFIX_HPP

#include <map>
#include <memory>
#include <string>
using namespace std;

namespace msci
{
	class prefix
	{
		public:
			enum type {Y,Z,E,P,T,G,M,k,h,da,normal,d,c,m,u,n,p,f,a,z,y};

			prefix();
			prefix(prefix::type);
			prefix(const string&);

			prefix(const prefix&);
			prefix(prefix&&);

			prefix& operator=(const prefix&);
			prefix& operator=(prefix&&);

			int get_conversion_factor() const;
			string get_name() const;
			string get_symbol() const;

			const prefix::type prefix_type;
	};

	prefix::type prefix_string(const string&);

	prefix create_prefix(prefix::type);
	prefix create_prefix(const string&);
}

#endif
