#ifndef MSCI_UNITS_UNITS_DIMENSION_HPP_INCLUDED
#define MSCI_UNITS_UNITS_DIMENSION_HPP_INCLUDED

#include "units/prefix.hpp"

#include <algorithm>
#include <cstring>
#include <cstddef>
#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace msci
{
	class dimension;

	vector<dimension> create_dimensions(string);

	class dimension
	{
		public:
			enum type : char
			{
				m, radian, steradian, s, g, C, K, mol, cd, B, Hz, N, Pa, J, W, A, V, F, Ohm, S, Wb, T, H, lm, lx, Bq, Gy, Sv, kat, angstrom, L, minute, h, d, AU, pc, eV, Da, amu, barn, M, particles, ppm, ppb, custom, custom_basic, custom_full_symbol, money, pixel, none
			};

			enum sign : char {positive,negative};

			dimension();
			dimension(const dimension&);
			dimension(dimension&&);
			explicit dimension(dimension::type,msci::prefix::type,dimension::sign);
			explicit dimension(dimension::type,const msci::prefix&,dimension::sign);
			explicit dimension(const string&,dimension::sign new_sign);
			explicit dimension(const string&,const msci::prefix& new_prefix,dimension::sign new_sign);

			~dimension();

			dimension& operator=(const dimension&);
			dimension& operator=(dimension&&);

			string get_name() const;
			string get_symbol() const;
			long double get_conversion_factor() const;
			long double prefix_math() const;

			bool is_simple_dimension() const;
			bool is_basic_dimension() const;
			bool is_derived_dimension() const;

			vector<dimension> get_basic_dimensions() const;

			void invert();

			msci::prefix prefix;
			dimension::type dimension_type;
			dimension::sign dimension_sign;
			char symbol[3];

			static void create_custom_dimension(const string& new_symbol,const string& init_dimensions)
			{
				if (dimension::base_dimensions.count(new_symbol) == 0)
				{
					dimension::base_dimensions[new_symbol] = create_dimensions(init_dimensions);
				}
			}

			static char* create_full_symbol(const string& full_symbol)
			{
				int symbol_code;
				char symbol_abbreviation[3];
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
					symbol_code = total_full_symbols;
				}
				else if (total_full_symbols <= 65535)
				{
					int char_code1 = (total_full_symbols / 256);
					if (char_code1 <= 32)
					{
						char_code1 = 33;
					}
					symbol_abbreviation[0] += char(char_code1);
					int closest_number = floor(total_full_symbols / 256.0) * 256;
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
					int closest_number = floor(total_full_symbols / 65536.0) * 65536;
					int char_code2 = total_full_symbols - closest_number;
					if (char_code2 <= 32)
					{
						char_code2 = 33;
					}
					symbol_abbreviation[1] += char(char_code2);
					int closest_number2 = floor(total_full_symbols / 256.0) * 256;
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
	};

	string to_string(const dimension&);
	string to_string(const vector<dimension>&);

	vector<dimension> create_derived_dimensions(const string&);
	vector<dimension> create_derived_dimensions(const vector<dimension>&);
	vector<dimension> create_derived_dimensions(const vector<dimension>&,long double&);

	vector<dimension> multiply_dimensions(const vector<dimension>&,const vector<dimension>&);
	vector<dimension> multiply_dimensions(vector<dimension>,const vector<dimension>&,long double&);
	vector<dimension> divide_dimensions(vector<dimension>,const vector<dimension>&,long double&);
	vector<dimension> square_dimensions(vector<dimension>,long double&,int);
	vector<dimension> power_dimensions(const vector<dimension>&,int);
	vector<dimension> normalize_dimensions(const vector<dimension>&);
	vector<dimension> normalize_dimensions(const vector<dimension>&,long double&);
	void prefix_square_difference(const vector<dimension>&,long double&);
	void deleted_derived_dimension_conversion_factor_math(const vector<dimension>&,long double&);
	bool common_dimension(const dimension&,const dimension&);
	bool equal_dimensions(const string&,const string&);
	bool equal_dimensions(const vector<dimension>&,const vector<dimension>&);
}

bool operator==(const msci::dimension&,const msci::dimension&);
bool operator!=(const msci::dimension&,const msci::dimension&);

ostream& operator <<(ostream&, const msci::dimension&);

#endif // MSCI_UNITS_UNITS_DIMENSION_HPP_INCLUDED
