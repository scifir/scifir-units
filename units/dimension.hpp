#ifndef MSCI_UNITS_UNITS_DIMENSION_HPP_INCLUDED
#define MSCI_UNITS_UNITS_DIMENSION_HPP_INCLUDED

#include "units/prefix.hpp"

#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace msci
{
	class dimension
	{
		public:
			enum type : char
			{
				m, radian, steradian, s, g, C, K, mol, cd, B, Hz, N, Pa, J, W, A, V, F, Ohm, S, Wb, T, H, lm, lx, Bq, Gy, Sv, kat, angstrom, L, minute, h, d, AU, pc, eV, Da, amu, barn, M, particles, ppm, ppb, custom, custom_basic
			};

			enum sign : char {positive,negative};

			dimension();
			dimension(const dimension&);
			dimension(dimension&&);
			explicit dimension(dimension::type,msci::prefix::type,dimension::sign);
			explicit dimension(dimension::type,const msci::prefix&,dimension::sign);

			dimension& operator=(const dimension&);
			dimension& operator=(dimension&&);

			string get_name() const;
			string get_symbol() const;

			int get_scale() const;
			int get_absolute_scale() const;

			bool is_basic_dimension() const;
			bool is_derived_dimension() const;

			vector<dimension> get_basic_dimensions() const;

			void invert();

			msci::prefix prefix;
			dimension::type dimension_type;
			dimension::sign dimension_sign;
	};

	dimension create_dimension(const string&,dimension::sign);

	string to_string(const vector<dimension>&);

	vector<dimension> create_dimensions(string);
	vector<dimension> create_derived_dimensions(string);
	vector<dimension> create_derived_dimensions(const vector<dimension>&);

	vector<dimension> multiply_dimensions(const vector<dimension>&,const vector<dimension>&);
	vector<dimension> divide_dimensions(const vector<dimension>&,const vector<dimension>&);
	vector<dimension> square_dimensions(const vector<dimension>&,int);
	vector<dimension> power_dimensions(const vector<dimension>&,int);
	vector<dimension> normalize_dimensions(const vector<dimension>&);
	bool equal_dimensions(const string&,const string&);
	bool equal_dimensions(const vector<dimension>&,const vector<dimension>&);
}

bool operator==(const msci::dimension&,const msci::dimension&);
bool operator!=(const msci::dimension&,const msci::dimension&);

ostream& operator <<(ostream&, const msci::dimension&);

#endif // MSCI_UNITS_UNITS_DIMENSION_HPP_INCLUDED
