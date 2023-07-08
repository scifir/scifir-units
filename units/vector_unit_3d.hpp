#ifndef SCIFIR_UNITS_UNITS_VECTOR_UNIT_3D_HPP_INCLUDED
#define SCIFIR_UNITS_UNITS_VECTOR_UNIT_3D_HPP_INCLUDED

#include "units/scalar_unit.hpp"
#include "units/vector_unit_2d.hpp"
#include "units/vector_unit_nd.hpp"
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

#define VECTOR_UNIT_3D_HPP_BEGIN(name) class name##_3d : public vector_unit_3d \
	{	\
		public: \
			using vector_unit_3d::vector_unit_3d; \
			name##_3d(); \
			name##_3d(const name##_3d&); \
			name##_3d(name##_3d&&); \
			using vector_unit_3d::operator=; \
			using vector_unit_3d::operator+=; \
			using vector_unit_3d::operator-=

#define	VECTOR_UNIT_3D_HPP_END() public: \
		static const string dimensions_match; \
		static const vector<dimension> real_dimensions; \
	}

#define VECTOR_UNIT_3D_HPP(name) class name##_3d : public vector_unit_3d \
	{	\
		public: \
			using vector_unit_3d::vector_unit_3d; \
			name##_3d(); \
			name##_3d(const name##_3d&); \
			name##_3d(name##_3d&&); \
			using vector_unit_3d::operator=; \
			using vector_unit_3d::operator+=; \
			using vector_unit_3d::operator-=; \
\
			static const string dimensions_match; \
			static const vector<dimension> real_dimensions; \
	}

#define VECTOR_UNIT_3D_CPP(name,init_dimensions) name##_3d::name##_3d() : vector_unit_3d() {} \
	name##_3d::name##_3d(const name##_3d& x) : vector_unit_3d(x) {} \
	name##_3d::name##_3d(name##_3d&& x) : vector_unit_3d(move(x)) {} \
const string name##_3d::dimensions_match = init_dimensions; \
const vector<dimension> name##_3d::real_dimensions = create_derived_dimensions(init_dimensions)

#define VECTOR_UNIT_HPP(name) SCALAR_UNIT_HPP(name); \
VECTOR_UNIT_2D_HPP(name); \
VECTOR_UNIT_3D_HPP(name); \
VECTOR_UNIT_ND_HPP(name)

#define VECTOR_UNIT_CPP(name,init_dimensions) SCALAR_UNIT_CPP(name,init_dimensions); \
VECTOR_UNIT_2D_CPP(name,init_dimensions); \
VECTOR_UNIT_3D_CPP(name,init_dimensions); \
VECTOR_UNIT_ND_CPP(name,init_dimensions)

using namespace std;
using namespace scifir;

namespace scifir
{
	class vector_unit_3d : public scalar_unit
	{
		public:
			vector_unit_3d();
			vector_unit_3d(const vector_unit_3d&);
			vector_unit_3d(vector_unit_3d&&);
			explicit vector_unit_3d(float,const string&,float,float);
			explicit vector_unit_3d(float,const string&,const angle&,float);
			explicit vector_unit_3d(float,const string&,float,const angle&);
			explicit vector_unit_3d(float,const string&,const angle&,const angle&);
			explicit vector_unit_3d(float,const string&,const vector<angle>&);
			explicit vector_unit_3d(float,const vector<dimension>&,float,float);
			explicit vector_unit_3d(float,const vector<dimension>&,const angle&,float);
			explicit vector_unit_3d(float,const vector<dimension>&,float,const angle&);
			explicit vector_unit_3d(float,const vector<dimension>&,const angle&,const angle&);
			explicit vector_unit_3d(float,const vector<dimension>&,const vector<angle>&);
			explicit vector_unit_3d(const scalar_unit&,float,float);
			explicit vector_unit_3d(const scalar_unit&,const angle&,float);
			explicit vector_unit_3d(const scalar_unit&,float,const angle&);
			explicit vector_unit_3d(const scalar_unit&,const angle&,const angle&);
			explicit vector_unit_3d(const scalar_unit&,const vector<angle>&);
			explicit vector_unit_3d(scalar_unit&&,float,float);
			explicit vector_unit_3d(scalar_unit&&,const angle&,float);
			explicit vector_unit_3d(scalar_unit&&,float,const angle&);
			explicit vector_unit_3d(scalar_unit&&,const angle&,const angle&);
			explicit vector_unit_3d(scalar_unit&&,const vector<angle>&);
			explicit vector_unit_3d(const string&,float,float);
			explicit vector_unit_3d(const string&,const angle&,float);
			explicit vector_unit_3d(const string&,float,const angle&);
			explicit vector_unit_3d(const string&,const angle&,const angle&);
			explicit vector_unit_3d(const string&,const vector<angle>&);
			explicit vector_unit_3d(const string&); // Initialize "8N 30ª 50ª"

			vector_unit_3d& operator =(const vector_unit_3d&);
			vector_unit_3d& operator =(vector_unit_3d&&);
			
			vector_unit_3d& operator =(const scalar_unit&);
			vector_unit_3d& operator =(scalar_unit&&);

			void point_to(direction::name);

			void operator +=(const vector_unit_3d&);
			void operator -=(vector_unit_3d);

			vector_unit_3d operator +(const vector_unit_3d&) const;
			vector_unit_3d operator -(vector_unit_3d) const;

			vector_unit_3d operator *(const scalar_unit&) const;
			vector_unit_3d operator /(const scalar_unit&) const;
			vector_unit_3d operator ^(const scalar_unit&) const;

			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			vector_unit_3d operator +(U) const;
			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			vector_unit_3d operator -(U) const;
			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			vector_unit_3d operator *(U) const;
			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			vector_unit_3d operator /(U) const;
			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			vector_unit_3d operator ^(U) const;

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

			inline scalar_unit x_projection() const
			{
				return scalar_unit(scalar_unit::value * scifir::cos(theta) * scifir::sin(phi),get_dimensions());
			}

			inline scalar_unit y_projection() const
			{
				return scalar_unit(scalar_unit::value * scifir::sin(theta) * scifir::sin(phi),get_dimensions());
			}

			inline scalar_unit z_projection() const
			{
				return scalar_unit(scalar_unit::value * scifir::cos(phi),get_dimensions());
			}

			inline void invert()
			{
				theta.invert();
				phi.invert();
			}

			angle theta;
			angle phi;
	};

	string to_string(const vector_unit_3d&);
	scalar_unit norm(const vector_unit_3d&);
	vector_unit_3d sqrt(const vector_unit_3d&);
	vector_unit_3d sqrt_nth(const vector_unit_3d&,int);
	scalar_unit dot_product(const vector_unit_3d&,const vector_unit_3d&);
	vector_unit_3d cross_product(const vector_unit_3d&,const vector_unit_3d&);
	angle angle_between(const vector_unit_3d&,const vector_unit_3d&);
	bool same_direction(const vector_unit_3d&,const vector_unit_3d&);
	bool parallel(const vector_unit_3d&,const vector_unit_3d&);
	bool orthogonal(const vector_unit_3d&,const vector_unit_3d&);
}

bool operator ==(const vector_unit_3d&, vector_unit_3d);
bool operator !=(const vector_unit_3d&, const vector_unit_3d&);

bool operator ==(const vector_unit_3d&, const string&);
bool operator !=(const vector_unit_3d&, const string&);

bool operator ==(const string&, const vector_unit_3d&);
bool operator !=(const string&, const vector_unit_3d&);

void operator +=(string&, const vector_unit_3d&);
string operator +(const string&, const vector_unit_3d&);
string operator +(const vector_unit_3d&, const string&);

ostream& operator <<(ostream&, const vector_unit_3d&);
istream& operator >>(istream&, vector_unit_3d&);

#endif // SCIFIR_UNITS_UNITS_VECTOR_UNIT_3D_HPP_INCLUDED
