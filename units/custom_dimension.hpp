#ifndef MSCI_UNITS_UNITS_CUSTOM_DIMENSION_HPP_INCLUDED
#define MSCI_UNITS_UNITS_CUSTOM_DIMENSION_HPP_INCLUDED

#include "units/dimension.hpp"

#include <map>
#include <string>
#include <vector>

using namespace std;

namespace msci
{
/*	class custom_dimension : public dimension
	{
		public:
			custom_dimension();
			custom_dimension(const custom_dimension&);
			custom_dimension(custom_dimension&&);
			custom_dimension(const string&,const msci::prefix&,dimension::sign);

			custom_dimension& operator=(const custom_dimension&);
			custom_dimension& operator=(custom_dimension&&);

			string get_custom_name() const;
			string get_custom_symbol() const;
			
			string get_symbol() const override;
			
			bool is_basic_dimension() const;
			bool is_custom_basic_dimension() const;
			bool is_custom_conversion() const;
			bool is_custom_abbreviation() const;

			string symbol;

			static void create_custom_dimension(const string& symbol,const string& init_dimensions)
			{
				if (custom_dimension::base_dimensions.count(symbol) == 0)
				{
					custom_dimension::base_dimensions[symbol] = create_dimensions(init_dimensions);
				}
			}

		private:
			static map<string,vector<dimension>> base_dimensions;
	};*/
}

/*bool operator==(const msci::custom_dimension&,const msci::custom_dimension&);
bool operator!=(const msci::custom_dimension&,const msci::custom_dimension&);

bool operator==(const msci::custom_dimension&,const msci::dimension&);
bool operator!=(const msci::custom_dimension&,const msci::dimension&);

bool operator==(const msci::dimension&,const msci::custom_dimension&);
bool operator!=(const msci::dimension&,const msci::custom_dimension&);*/

#endif // MSCI_UNITS_UNITS_CUSTOM_DIMENSION_HPP_INCLUDED
