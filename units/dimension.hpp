#ifndef DIMENSION_HPP_
#define DIMENSION_HPP_

#include "msci/units/units/prefix.hpp"

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
			enum type
			{
				m, angle, solid_angle, s, g, C, K, mol, cd, B, Hz, N, Pa, J, W, A, V, F, Ohm, S, Wb, T, H, lm, lx, Bq, Gy, Sv, kat, angstrom, L, minute, h, d, AU, pc, eV, Da, amu, barn, M, particles, ppm, ppb
			};

			enum sign {positive,negative};

			dimension();
			dimension(msci::dimension::type,msci::prefix::type,msci::dimension::sign);
			dimension(msci::dimension::type,const msci::prefix&,msci::dimension::sign);

			dimension operator = (const dimension&);

			string get_name() const;
			string get_symbol() const;

			int get_scale() const;
			int get_absolute_scale() const;

			bool is_basic_dimension() const;
			bool is_derived_dimension() const;

			vector<dimension> get_basic_dimensions() const;

			msci::prefix prefix;
			const dimension::type dimension_type;
			msci::dimension::sign dimension_sign;
	};

	dimension create_dimension(dimension::type);
	dimension create_dimension(const string&);

	string get_dimension_structure(const vector<dimension>&);

	vector<dimension> create_dimensions(string);
	vector<dimension> create_derived_dimensions(string);

	vector<dimension> multiply_dimensions(const vector<dimension>&,const vector<dimension>&);
	vector<dimension> divide_dimensions(const vector<dimension>&,const vector<dimension>&);
	vector<dimension> power_dimensions(const vector<dimension>&,int);
}

ostream& operator <<(ostream&, const msci::dimension&);

#endif
