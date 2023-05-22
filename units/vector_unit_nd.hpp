#ifndef MSCI_UNITS_UNITS_VECTOR_UNIT_3D_HPP_INCLUDED
#define MSCI_UNITS_UNITS_VECTOR_UNIT_3D_HPP_INCLUDED

#include "msci/units/units/scalar_unit.hpp"
#include "msci/units/meca_number/angle.hpp"
#include "msci/units/coordinates/coordinates_2d.hpp"
#include "msci/units/util/is_number.hpp"
#include "msci/units/topology/direction.hpp"

#include "boost/algorithm/string.hpp"
#include "boost/variant.hpp"

#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

#define VECTOR_UNIT_ND_HPP_BEGIN(name) class name##_nd : public vector_unit_nd \
	{	\
		public: \
			using vector_unit_nd::vector_unit_nd

#define	VECTOR_UNIT_ND_HPP_END() public: \
		static const string dimensions_match; \
		static const vector<dimension> real_dimensions; \
	}

#define VECTOR_UNIT_ND_HPP(name) class name##_nd : public vector_unit_nd \
	{	\
		public: \
			using vector_unit_nd::vector_unit_nd; \
\
			static const string dimensions_match; \
			static const vector<msci::dimension> real_dimensions; \
	}

#define VECTOR_UNIT_ND_CPP(name,init_dimensions) const string name##_nd::dimensions_match = init_dimensions; \
const vector<dimension> name##_nd::real_dimensions = create_derived_dimensions(init_dimensions)

using namespace std;
using namespace msci;

namespace msci
{
	class vector_unit_nd : public scalar_unit
	{
		public:
			vector_unit_nd();
			vector_unit_nd(const vector_unit_nd&);
			vector_unit_nd(vector_unit_nd&&);
			explicit vector_unit_nd(float,const string&);
			explicit vector_unit_nd(float,const string&,const vector<float>&);
			explicit vector_unit_nd(float,const string&,const vector<msci::angle>&);
			explicit vector_unit_nd(float,const vector<dimension>&);
			explicit vector_unit_nd(float,const vector<dimension>&,const vector<float>&);
			explicit vector_unit_nd(float,const vector<dimension>&,const vector<msci::angle>&);
			explicit vector_unit_nd(const scalar_unit&);
			explicit vector_unit_nd(const scalar_unit&,const vector<float>&);
			explicit vector_unit_nd(const scalar_unit&,const vector<msci::angle>&);
			explicit vector_unit_nd(scalar_unit&&);
			explicit vector_unit_nd(scalar_unit&&,const vector<float>&);
			explicit vector_unit_nd(scalar_unit&&,const vector<msci::angle>&);
			explicit vector_unit_nd(const string&,const vector<float>&);
			explicit vector_unit_nd(const string&,const vector<msci::angle>&);
			explicit vector_unit_nd(const string&);

			vector_unit_nd& operator =(const vector_unit_nd&);
			vector_unit_nd& operator =(vector_unit_nd&&);
			vector_unit_nd& operator =(const scalar_unit&);
			vector_unit_nd& operator =(scalar_unit&&);

			void point_to(direction_symbol);
			
			void operator +=(const vector_unit_nd&);
			void operator -=(const vector_unit_nd&);

			vector_unit_nd operator +(const vector_unit_nd&) const;
			vector_unit_nd operator -(const vector_unit_nd&) const;

			vector_unit_nd operator *(const scalar_unit&) const;
			vector_unit_nd operator /(const scalar_unit&) const;
			vector_unit_nd operator ^(const scalar_unit&) const;

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			vector_unit_nd operator +(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			vector_unit_nd operator -(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			vector_unit_nd operator *(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			vector_unit_nd operator /(U) const;
			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			vector_unit_nd operator ^(U) const;

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator +=(U y)
			{
				scalar_unit::value += y;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator -=(U y)
			{
				scalar_unit::value -= y;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator *=(U y)
			{
				scalar_unit::value *= y;
				if(y < 0)
				{
					invert();
				}
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator /=(U y)
			{
				scalar_unit::value /= y;
				if(y < 0)
				{
					invert();
				}
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator ^=(U y)
			{
				scalar_unit::value ^= y;
			}

			inline const bool& is_1d() const
			{
				return angles.size() == 0;
			}

			inline bool is_2d() const
			{
				return angles.size() == 1;
			}

			inline bool is_3d() const
			{
				return angles.size() == 2;
			}
			
			inline bool is_nd(int i) const
			{
				return angles.size() == (i - 1);
			}

			inline float x_projection() const
			{
				if (is_1d())
				{
					return get_value();
				}
				else if (is_2d())
				{
					return scalar_unit::value * msci::cos(angles[0]);
				}
				else if (is_3d())
				{
					return scalar_unit::value * msci::cos(angles[0]) * msci::sin(angles[1]);
				}
			}

			inline float y_projection() const
			{
				if (is_1d())
				{
					return 0;
				}
				else if (is_2d())
				{
					return scalar_unit::value * msci::sin(angles[0]);
				}
				else if (is_3d())
				{
					return scalar_unit::value * msci::sin(angles[0]) * msci::sin(angles[1]);
				}
			}

			inline float z_projection() const
			{
				if (is_1d())
				{
					return 0;
				}
				else if (is_2d())
				{
					return 0;
				}
				else if (is_3d())
				{
					return scalar_unit::value * msci::cos(angles[1]);
				}
			}

			inline void invert()
			{
				for(msci::angle& x_angle : angles)
				{
					x_angle.invert();
				}
			}

			vector<msci::angle> angles;
	};

	scalar_unit norm(const vector_unit_nd&);
	vector_unit_nd sqrt(const vector_unit_nd&);
	vector_unit_nd sqrt_nth(const vector_unit_nd&,int);
	scalar_unit dot_product(const vector_unit_nd&,const vector_unit_nd&);
	vector_unit_nd cross_product(const vector_unit_nd&,const vector_unit_nd&);
	msci::angle angle_between(const vector_unit_nd&,const vector_unit_nd&);
	bool same_nd(const vector_unit_nd&,const vector_unit_nd&);
	bool same_direction(const vector_unit_nd&,const vector_unit_nd&);
	bool parallel(const vector_unit_nd&,const vector_unit_nd&);
	bool orthogonal(const vector_unit_nd&,const vector_unit_nd&);
}

bool operator ==(const msci::vector_unit_nd&,const msci::vector_unit_nd&);
bool operator !=(const msci::vector_unit_nd&,const msci::vector_unit_nd&);
void operator +=(string&,const msci::vector_unit_nd&);
string operator +(const string&,const msci::vector_unit_nd&);
string operator +(const msci::vector_unit_nd&,const string&);
ostream& operator <<(ostream&,const msci::vector_unit_nd&);
istream& operator >>(istream&,msci::vector_unit_nd&);

#endif // MSCI_UNITS_UNITS_VECTOR_UNIT_3D_HPP_INCLUDED
 
