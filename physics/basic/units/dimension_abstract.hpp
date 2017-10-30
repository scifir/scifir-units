#ifndef DIMENSION_ABSTRACT_HPP_INCLUDED
#define DIMENSION_ABSTRACT_HPP_INCLUDED

#include "prefix.hpp"
#include "informatics/types/is_number.hpp"

#include "boost/variant.hpp"

#include <cmath>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

using namespace std;

namespace msci
{
	class dimension_prefixes : public map<prefix_symbol,shared_ptr<prefix>>
	{
		public:
			dimension_prefixes();
			dimension_prefixes(const dimension_prefixes&);
	};

	class dimension_abstract
	{
		public:
			dimension_abstract();
			dimension_abstract(prefix_symbol,int);
			dimension_abstract(prefix&,int);
			virtual dimension_abstract* clone() const = 0;

			inline const dimension_prefixes& get_dimension_prefixes() const
			{
				return prefixes;
			}

			virtual int get_enum_type() const = 0;
			virtual const string& get_name() const = 0;
			const int get_scale() const;
			virtual const string& get_symbol() const = 0;
			virtual float get_prefix_base() const;

			void add_prefix(prefix_symbol);
			void add_prefix(const prefix&);
			void add_prefix(const dimension_prefixes&);
			void remove_prefix(prefix_symbol);
			void remove_prefix(const prefix&);
			void remove_prefix(const dimension_prefixes&);
			void change_prefix(prefix_symbol);

			int total_factor();
			void operator *=(const dimension_abstract&);
			void operator /=(const dimension_abstract&);

			template <typename T,typename = typename enable_if<is_integer_number<T>::value>::type>
			void operator ^=(T x)
			{
				if (x < 0)
				{
					for (auto& prefix : prefixes)
					{
						if (x < 0)
						{
							prefix.second->scale *= -1;
						}
					}
				}
				dimension_prefixes new_prefixes = prefixes;
				for (int i = 1; i < abs(x); i++)
				{
					for (auto& prefix : new_prefixes)
					{
						add_prefix(*prefix.second);
					}
				}
			}

			void sqrt();
			void sqrt_nth(int);

		private:
			dimension_prefixes prefixes;
	};
}

bool operator ==(const msci::dimension_abstract&,const msci::dimension_abstract&);
bool operator !=(const msci::dimension_abstract&,const msci::dimension_abstract&);

ostream& operator <<(ostream&, const msci::dimension_abstract&);

#endif // DIMENSION_ABSTRACT_HPP_INCLUDED
