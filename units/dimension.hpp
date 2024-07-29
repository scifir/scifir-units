#ifndef SCIFIR_UNITS_UNITS_DIMENSION_HPP_INCLUDED
#define SCIFIR_UNITS_UNITS_DIMENSION_HPP_INCLUDED

#include "./prefix.hpp"

#include "boost/algorithm/string.hpp"

#include <algorithm>
#include <cstring>
#include <cstddef>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class dimension;

	vector<dimension> create_dimensions(string init_dimensions);
	vector<dimension> create_simple_dimensions(const string& init_dimensions);

	class dimension
	{
		public:
			enum type : int8_t
			{
				NONE, METRE, DEGREE, RADIAN, STERADIAN, SECOND, GRAM, COULOMB, KELVIN, MOLE, CANDELA, BYTE, BIT, HERTZ, NEWTON, PASCAL, JOULE, WATT, AMPERE, VOLT, FARAD, OHM, SIEMENS, WEBER, TESLA, HENRY, LUMEN, LUX, BECQUEREL, GRAY, SIEVERT, KATAL, ANGSTROM, LITRE, MINUTE, HOUR, DAY, LIGHT_YEAR, ASTRONOMICAL_UNIT, PARSEC, ELECTRON_VOLT, DALTON, ATOMIC_MASS_UNIT, BARN, MOLARITY, PARTICLES, CUSTOM, CUSTOM_BASIC, CUSTOM_FULL_SYMBOL, MONEY, PIXEL, MEMO
			};

			enum position : int8_t {NO_POSITION, NUMERATOR, DENOMINATOR};

			dimension();
			dimension(const dimension& x);
			dimension(dimension&& x);
			explicit dimension(dimension::type new_dimension_type,scifir::prefix::type new_prefix,dimension::position new_position);
			explicit dimension(dimension::type new_dimension_type,const scifir::prefix& new_prefix,dimension::position new_position);
			explicit dimension(const string& init_dimension,dimension::position new_position);

			dimension& operator =(const dimension& x);
			dimension& operator =(dimension&& x);

			string get_name() const;
			string get_fullname() const;
			string get_plural() const;
			string get_fullplural() const;
			string get_symbol() const;
			long double get_conversion_factor() const;
			long double prefix_math() const;
			long double prefix_math(const prefix& x_prefix) const;

			bool is_simple_dimension() const;
			bool is_composite_dimension() const;

			bool is_base_dimension() const;
			bool is_derived_dimension() const;

			bool is_SI_base_dimension() const;
			bool is_SI_derived_dimension() const;

			bool is_dimensionless() const;

			vector<dimension> get_simple_dimensions() const;

			void invert();

			scifir::prefix prefix;
			dimension::type dimension_type;
			dimension::position dimension_position;
			char symbol[3];

			static void create_custom_dimension(const string& new_symbol,const string& init_dimensions)
			{
				if (dimension::base_dimensions.count(new_symbol) == 0)
				{
					dimension::base_dimensions[new_symbol] = create_simple_dimensions(init_dimensions);
				}
			}

			static char* create_full_symbol(const string& full_symbol)
			{
				char symbol_abbreviation[3] = "";
				total_full_symbols++;
				if (total_full_symbols <= 255)
				{
					if (total_full_symbols <= 32)
					{
						total_full_symbols = 33;
					}
					symbol_abbreviation[0] = char(total_full_symbols);
					symbol_abbreviation[1] = '\n';
					symbol_abbreviation[2] = '\n';
				}
				else if (total_full_symbols <= 65535)
				{
					int char_code1 = (total_full_symbols / 256);
					if (char_code1 <= 32)
					{
						char_code1 = 33;
					}
					symbol_abbreviation[0] += char(char_code1);
					int closest_number = int(floor(total_full_symbols / 256.0)) * 256;
					int char_code2 = total_full_symbols - closest_number;
					if (char_code2 <= 32)
					{
						char_code2 = 33;
					}
					symbol_abbreviation[1] += char(char_code2);
					symbol_abbreviation[2] = '\n';
				}
				else
				{
					int char_code1 = (total_full_symbols / 65536);
					if (char_code1 <= 32)
					{
						char_code1 = 33;
					}
					symbol_abbreviation[0] += char(char_code1);
					int closest_number = int(floor(total_full_symbols / 65536.0)) * 65536;
					int char_code2 = total_full_symbols - closest_number;
					if (char_code2 <= 32)
					{
						char_code2 = 33;
					}
					symbol_abbreviation[1] += char(char_code2);
					int closest_number2 = int(floor(total_full_symbols / 256.0)) * 256;
					int char_code3 = total_full_symbols - closest_number2;
					if (char_code3 <= 32)
					{
						char_code3 = 33;
					}
					symbol_abbreviation[2] += char(char_code3);
				}
				full_symbols[total_full_symbols] = full_symbol;
				return new char[3]{symbol_abbreviation[0],symbol_abbreviation[1],symbol_abbreviation[2]};
			}

			static string get_full_symbol(const char* x_symbol)
			{
				int symbol_code;
				if (x_symbol[1] == '\n')
				{
					symbol_code = int(x_symbol[0]);
				}
				else if (x_symbol[2] == '\n')
				{
					symbol_code = int(x_symbol[0]) * 256;
					symbol_code += int(x_symbol[1]);
				}
				else
				{
					symbol_code = int(x_symbol[0]) * 65536;
					symbol_code += int(x_symbol[1]) * 256;
					symbol_code += int(x_symbol[2]);
				}
				return full_symbols[symbol_code];
			}

		private:
			static map<string,vector<dimension>> base_dimensions;
			static map<int,string> full_symbols;
			static int total_full_symbols;
			static set<string> prefixes_options;
	};

	string to_string(const dimension& x);
	string to_string(const vector<dimension>& x_dimensions,bool with_brackets = false);

	vector<dimension> create_simple_dimensions(const vector<dimension>& x);
	vector<dimension> create_simple_dimensions(const vector<dimension>& x,long double& value);

	vector<dimension> multiply_dimensions(const vector<dimension>& x,const vector<dimension>& y);
	vector<dimension> multiply_dimensions(vector<dimension> x,const vector<dimension>& y,long double& value);
	vector<dimension> divide_dimensions(vector<dimension> x,const vector<dimension>& y,long double& value);
	vector<dimension> square_dimensions(vector<dimension> x,int index,long double& value);
	vector<dimension> power_dimensions(const vector<dimension>& x,int exponent);

	vector<dimension> normalize_dimensions(const vector<dimension>& x);
	vector<dimension> normalize_dimensions(const vector<dimension>& x,long double& value);

	bool common_dimension(const dimension& x,const dimension& y);
	bool equal_dimensions(const string& init_dimensions_x,const string& init_dimensions_y);
	bool equal_dimensions(const vector<dimension>& x,const vector<dimension>& y);
	bool equal_dimensions_and_prefixes(const vector<dimension>& x,const vector<dimension>& y);

	/*constexpr bool is_dimensions(const char* x)
	{
		return true;
	}*/
}

bool operator ==(const scifir::dimension& x,const scifir::dimension& y);
bool operator!=(const scifir::dimension& x,const scifir::dimension& y);

ostream& operator <<(ostream& os, const scifir::dimension& x);

#endif // SCIFIR_UNITS_UNITS_DIMENSION_HPP_INCLUDED
