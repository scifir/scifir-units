#ifndef MSCI_UNITS_UNITS_VECTOR_UNIT_3D_HPP_INCLUDED
#define MSCI_UNITS_UNITS_VECTOR_UNIT_3D_HPP_INCLUDED

#include "msci/units/units/scalar_unit.hpp"
#include "msci/units/meca_number/angle.hpp"
#include "msci/units/coordinates/coordinates_2d.hpp"
#include "msci/units/util/is_number.hpp"
#include "msci/units/topology/direction.hpp"
#include "msci/units/units/vector_unit_nd.hpp"

#include "boost/algorithm/string.hpp"
#include "boost/variant.hpp"

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
			using vector_unit_3d::vector_unit_3d

#define	VECTOR_UNIT_3D_HPP_END() public: \
		static const string dimensions_match; \
		static const vector<msci::dimension> real_dimensions; \
	}

#define VECTOR_UNIT_3D_HPP(name) class name##_3d : public vector_unit_3d \
	{	\
		public: \
			using vector_unit_3d::vector_unit_3d; \
\
			static const string dimensions_match; \
			static const vector<msci::dimension> real_dimensions; \
	}

#define VECTOR_UNIT_3D_CPP(name,init_dimensions) const string name##_3d::dimensions_match = init_dimensions; \
const vector<msci::dimension> name##_3d::real_dimensions = create_derived_dimensions(init_dimensions)

#define VECTOR_UNIT_HPP(name) SCALAR_UNIT_HPP(name); \
\
	VECTOR_UNIT_3D_HPP(name); \

#define VECTOR_UNIT_CPP(name,init_dimensions) SCALAR_UNIT_CPP(name,init_dimensions); \
\
	VECTOR_UNIT_3D_CPP(name,init_dimensions); \


using namespace std;
using namespace msci;

namespace msci
{
	class vector_unit_3d : public scalar_unit
	{
		public:
			vector_unit_3d();
			vector_unit_3d(const vector_unit_3d&);
			vector_unit_3d(vector_unit_3d&&);
			explicit vector_unit_3d(float,const string&,float,float);
			explicit vector_unit_3d(float,const string&,const msci::angle&,float);
			explicit vector_unit_3d(float,const string&,float,const msci::angle&);
			explicit vector_unit_3d(float,const string&,const msci::angle&,const msci::angle&);
			explicit vector_unit_3d(float,const string&,const vector<msci::angle>&);
			explicit vector_unit_3d(float,const vector<msci::dimension>&,float,float);
			explicit vector_unit_3d(float,const vector<msci::dimension>&,const msci::angle&,float);
			explicit vector_unit_3d(float,const vector<msci::dimension>&,float,const msci::angle&);
			explicit vector_unit_3d(float,const vector<msci::dimension>&,const msci::angle&,const msci::angle&);
			explicit vector_unit_3d(float,const vector<msci::dimension>&,const vector<msci::angle>&);
			explicit vector_unit_3d(const scalar_unit&,float,float);
			explicit vector_unit_3d(const scalar_unit&,const msci::angle&,float);
			explicit vector_unit_3d(const scalar_unit&,float,const msci::angle&);
			explicit vector_unit_3d(const scalar_unit&,const msci::angle&,const msci::angle&);
			explicit vector_unit_3d(const scalar_unit&,const vector<msci::angle>&);
			explicit vector_unit_3d(scalar_unit&&,float,float);
			explicit vector_unit_3d(scalar_unit&&,const msci::angle&,float);
			explicit vector_unit_3d(scalar_unit&&,float,const msci::angle&);
			explicit vector_unit_3d(scalar_unit&&,const msci::angle&,const msci::angle&);
			explicit vector_unit_3d(scalar_unit&&,const vector<msci::angle>&);
			explicit vector_unit_3d(const string&,float,float);
			explicit vector_unit_3d(const string&,const msci::angle&,float);
			explicit vector_unit_3d(const string&,float,const msci::angle&);
			explicit vector_unit_3d(const string&,const msci::angle&,const msci::angle&);
			explicit vector_unit_3d(const string&,const vector<msci::angle>&);
			explicit vector_unit_3d(const string&); // Initialize "8N 30ª 50ª"

			vector_unit_3d& operator =(const vector_unit_3d&);
			vector_unit_3d& operator =(vector_unit_3d&&);
			
			vector_unit_3d& operator =(const scalar_unit&);
			vector_unit_3d& operator =(scalar_unit&&);

			void point_to(direction_symbol);

			void operator +=(const vector_unit_3d&);
			void operator -=(const vector_unit_3d&);

			vector_unit_3d operator +(const vector_unit_3d&) const;
			vector_unit_3d operator -(const vector_unit_3d&) const;

			vector_unit_3d operator *(const scalar_unit&) const;
			vector_unit_3d operator /(const scalar_unit&) const;
			vector_unit_3d operator ^(const scalar_unit&) const;

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			vector_unit_3d operator +(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			vector_unit_3d operator -(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			vector_unit_3d operator *(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			vector_unit_3d operator /(U) const;
			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			vector_unit_3d operator ^(U) const;

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

			inline float x_projection() const
			{
				return scalar_unit::value * msci::cos(theta) * msci::sin(phi);
			}

			inline float y_projection() const
			{
				return scalar_unit::value * msci::sin(theta) * msci::sin(phi);
			}

			inline float z_projection() const
			{
				return scalar_unit::value * msci::cos(phi);
			}

			inline void invert()
			{
				theta.invert();
				phi.invert();
			}

			msci::angle theta;
			msci::angle phi;
	};

	string to_string(const vector_unit_3d&);
	scalar_unit norm(const vector_unit_3d&);
	vector_unit_3d sqrt(const vector_unit_3d&);
	vector_unit_3d sqrt_nth(const vector_unit_3d&,int);
	scalar_unit dot_product(const vector_unit_3d&,const vector_unit_3d&);
	vector_unit_3d cross_product(const vector_unit_3d&,const vector_unit_3d&);
	msci::angle angle_between(const vector_unit_3d&,const vector_unit_3d&);
	bool same_direction(const vector_unit_3d&,const vector_unit_3d&);
	bool parallel(const vector_unit_3d&,const vector_unit_3d&);
	bool orthogonal(const vector_unit_3d&,const vector_unit_3d&);
}

bool operator ==(const vector_unit_3d&,const vector_unit_3d&);
bool operator !=(const vector_unit_3d&,const vector_unit_3d&);
void operator +=(string&,const vector_unit_3d&);
string operator +(const string&,const vector_unit_3d&);
string operator +(const vector_unit_3d&,const string&);
ostream& operator <<(ostream&,const vector_unit_3d&);
istream& operator >>(istream&,vector_unit_3d&);

#endif // MSCI_UNITS_UNITS_VECTOR_UNIT_3D_HPP_INCLUDED
