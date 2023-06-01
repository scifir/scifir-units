#ifndef MSCI_UNITS_COORDINATES_COORDINATES_ND_HPP_INCLUDED
#define MSCI_UNITS_COORDINATES_COORDINATES_ND_HPP_INCLUDED

#include "meca_number/angle.hpp"
#include "coordinates/coordinates_3d.hpp"
#include "topology/direction.hpp"
#include "units.hpp"

#include "boost/variant.hpp"

#include <list>

using namespace std;

namespace msci
{
	class coordinates_nd
	{
		public:
			coordinates_nd();
			coordinates_nd(const coordinates_nd&);
			coordinates_nd(coordinates_nd&&);
			coordinates_nd(float,const string&);
			coordinates_nd(float,const string&,const vector<float>&);
			coordinates_nd(float,const string&,const vector<msci::angle>&);
			coordinates_nd(const length&);
			coordinates_nd(const length&,const vector<float>&);
			coordinates_nd(const length&,const vector<msci::angle>&);
			coordinates_nd(length&&);
			coordinates_nd(length&&,const vector<float>&);
			coordinates_nd(length&&,const vector<msci::angle>&);
			coordinates_nd(const string&,const vector<float>&);
			coordinates_nd(const string&,const vector<msci::angle>&);
			coordinates_nd(const string&);

			length n_projection(int) const;
			bool is_nd(int) const;
			int get_nd() const;

			length x_projection() const;
			length y_projection() const;
			length z_projection() const;

			void invert();

			void convert_cartesian_2d(float, float);
			void convert_polar(float, const msci::angle&);
			void convert_cartesian_3d(const length&, const length&, const length&);
			void convert_cylindrical(const length&, const msci::angle&, const length&);

			length r;
			vector<msci::angle> angles;
	};
}

#endif // MSCI_UNITS_COORDINATES_COORDINATES_ND_HPP_INCLUDED
