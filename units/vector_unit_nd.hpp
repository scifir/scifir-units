#ifndef SCIFIR_UNITS_UNITS_VECTOR_UNIT_ND_HPP_INCLUDED
#define SCIFIR_UNITS_UNITS_VECTOR_UNIT_ND_HPP_INCLUDED

#include "units/scalar_unit.hpp"
#include "meca_number/angle.hpp"
#include "util/is_number.hpp"
#include "topology/direction.hpp"

#include "boost/algorithm/string.hpp"

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
			using vector_unit_nd::vector_unit_nd; \
			name##_nd(); \
			name##_nd(const name##_nd&); \
			name##_nd(name##_nd&&); \
			using vector_unit_nd::operator=; \
			using vector_unit_nd::operator+=; \
			using vector_unit_nd::operator-=

#define	VECTOR_UNIT_ND_HPP_END() public: \
		static const string dimensions_match; \
		static const vector<dimension> real_dimensions; \
	}

#define VECTOR_UNIT_ND_HPP(name) class name##_nd : public vector_unit_nd \
	{	\
		public: \
			using vector_unit_nd::vector_unit_nd; \
			name##_nd(); \
			name##_nd(const name##_nd&); \
			name##_nd(name##_nd&&); \
			using vector_unit_nd::operator=; \
			using vector_unit_nd::operator+=; \
			using vector_unit_nd::operator-=; \
\
			static const string dimensions_match; \
			static const vector<dimension> real_dimensions; \
	}

#define VECTOR_UNIT_ND_CPP(name,init_dimensions) name##_nd::name##_nd() : vector_unit_nd() {} \
	name##_nd::name##_nd(const name##_nd& x) : vector_unit_nd(x) {} \
	name##_nd::name##_nd(name##_nd&& x) : vector_unit_nd(move(x)) {} \
const string name##_nd::dimensions_match = init_dimensions; \
const vector<dimension> name##_nd::real_dimensions = create_derived_dimensions(init_dimensions)

using namespace std;
using namespace scifir;

namespace scifir
{
	class vector_unit_nd : public scalar_unit
	{
		public:
			vector_unit_nd();
			vector_unit_nd(const vector_unit_nd&);
			vector_unit_nd(vector_unit_nd&&);
			explicit vector_unit_nd(float,const string&);
			explicit vector_unit_nd(float,const string&,const vector<float>&);
			explicit vector_unit_nd(float,const string&,const vector<angle>&);
			explicit vector_unit_nd(float,const vector<dimension>&);
			explicit vector_unit_nd(float,const vector<dimension>&,const vector<float>&);
			explicit vector_unit_nd(float,const vector<dimension>&,const vector<angle>&);
			explicit vector_unit_nd(const scalar_unit&);
			explicit vector_unit_nd(const scalar_unit&,const vector<float>&);
			explicit vector_unit_nd(const scalar_unit&,const vector<angle>&);
			explicit vector_unit_nd(const string&,const vector<float>&);
			explicit vector_unit_nd(const string&,const vector<angle>&);
			explicit vector_unit_nd(const string&);

			vector_unit_nd& operator =(const vector_unit_nd&);
			vector_unit_nd& operator =(vector_unit_nd&&);
			vector_unit_nd& operator =(const scalar_unit&);
			vector_unit_nd& operator =(scalar_unit&&);

			void point_to(direction::name);
			
			void operator +=(const vector_unit_nd&);
			void operator -=(vector_unit_nd);

			vector_unit_nd operator +(const vector_unit_nd&) const;
			vector_unit_nd operator -(vector_unit_nd) const;

			vector_unit_nd operator *(const scalar_unit&) const;
			vector_unit_nd operator /(const scalar_unit&) const;
			vector_unit_nd operator ^(const scalar_unit&) const;

			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			vector_unit_nd operator +(U) const;
			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			vector_unit_nd operator -(U) const;
			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			vector_unit_nd operator *(U) const;
			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			vector_unit_nd operator /(U) const;
			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			vector_unit_nd operator ^(U) const;

			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			void operator +=(U y)
			{
				scalar_unit::value += y;
			}

			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			void operator -=(U y)
			{
				scalar_unit::value -= y;
			}

			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			void operator *=(U y)
			{
				scalar_unit::value *= y;
				if(y < 0)
				{
					invert();
				}
			}

			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			void operator /=(U y)
			{
				scalar_unit::value /= y;
				if(y < 0)
				{
					invert();
				}
			}

			inline bool is_nd(int i) const
			{
				return angles.size() == (i - 1);
			}
			
			inline int get_nd() const
			{
				return (angles.size() + 1);
			}

			scalar_unit n_projection(int) const;
			scalar_unit x_projection() const;
			scalar_unit y_projection() const;
			scalar_unit z_projection() const;

			void invert();

			vector<angle> angles;
	};

	string to_string(const vector_unit_nd&);
	scalar_unit norm(const vector_unit_nd&);
	vector_unit_nd sqrt(const vector_unit_nd&);
	vector_unit_nd sqrt_nth(const vector_unit_nd&,int);
	scalar_unit dot_product(const vector_unit_nd&,const vector_unit_nd&);
	vector_unit_nd cross_product(const vector_unit_nd&,const vector_unit_nd&);
	angle angle_between(const vector_unit_nd&,const vector_unit_nd&);
	bool same_nd(const vector_unit_nd&,const vector_unit_nd&);
	bool same_direction(const vector_unit_nd&,const vector_unit_nd&);
	bool parallel(const vector_unit_nd&,const vector_unit_nd&);
	bool orthogonal(const vector_unit_nd&,const vector_unit_nd&);
}

bool operator ==(const vector_unit_nd&, vector_unit_nd);
bool operator !=(const vector_unit_nd&, const vector_unit_nd&);

bool operator ==(const vector_unit_nd&, const string&);
bool operator !=(const vector_unit_nd&, const string&);

bool operator ==(const string&, const vector_unit_nd&);
bool operator !=(const string&, const vector_unit_nd&);

void operator +=(string&, const vector_unit_nd&);
string operator +(const string&, const vector_unit_nd&);
string operator +(const vector_unit_nd&, const string&);

ostream& operator <<(ostream&, const vector_unit_nd&);
istream& operator >>(istream&, vector_unit_nd&);

#endif // SCIFIR_UNITS_UNITS_VECTOR_UNIT_ND_HPP_INCLUDED
 
