#ifndef MSCI_UNITS_UNITS_VECTOR_UNIT_2D_HPP_INCLUDED
#define MSCI_UNITS_UNITS_VECTOR_UNIT_2D_HPP_INCLUDED

#include "units/scalar_unit.hpp"
#include "meca_number/angle.hpp"

#include "boost/algorithm/string.hpp"

#include <iostream>
#include <string>

#define VECTOR_UNIT_2D_HPP_BEGIN(name) class name##_2d : public vector_unit_2d \
	{	\
		public: \
			using vector_unit_2d::vector_unit_2d; \
			name##_2d(); \
			name##_2d(const name##_2d&); \
			name##_2d(name##_2d&&); \
			using vector_unit_2d::operator=; \
			using vector_unit_2d::operator+=; \
			using vector_unit_2d::operator-=

#define	VECTOR_UNIT_2D_HPP_END() public: \
		static const string dimensions_match; \
		static const vector<dimension> real_dimensions; \
	}

#define VECTOR_UNIT_2D_HPP(name) class name##_2d : public vector_unit_2d \
	{	\
		public: \
			using vector_unit_2d::vector_unit_2d; \
			name##_2d(); \
			name##_2d(const name##_2d&); \
			name##_2d(name##_2d&&); \
			using vector_unit_2d::operator=; \
			using vector_unit_2d::operator+=; \
			using vector_unit_2d::operator-=; \
\
			static const string dimensions_match; \
			static const vector<dimension> real_dimensions; \
	}

#define VECTOR_UNIT_2D_CPP(name,init_dimensions) name##_2d::name##_2d() : vector_unit_2d() {} \
	name##_2d::name##_2d(const name##_2d& x) : vector_unit_2d(x) {} \
	name##_2d::name##_2d(name##_2d&& x) : vector_unit_2d(move(x)) {} \
const string name##_2d::dimensions_match = init_dimensions; \
const vector<dimension> name##_2d::real_dimensions = create_derived_dimensions(init_dimensions)

using namespace std;
using namespace msci;

namespace msci
{
	class vector_unit_2d : public scalar_unit
	{
		public:
			vector_unit_2d();
			vector_unit_2d(const vector_unit_2d&);
			vector_unit_2d(vector_unit_2d&&);
			explicit vector_unit_2d(float,const string&,float); // Example of initialization (10,"N",50)
			explicit vector_unit_2d(float,const string&,const angle&); // Example of initialization (10,"N",50ª)
			explicit vector_unit_2d(float,const vector<dimension>&,float);
			explicit vector_unit_2d(float,const vector<dimension>&,const angle&);
			explicit vector_unit_2d(const scalar_unit&,float);
			explicit vector_unit_2d(const scalar_unit&,const angle&);
			explicit vector_unit_2d(scalar_unit&&,float);
			explicit vector_unit_2d(scalar_unit&&,const angle&);
			explicit vector_unit_2d(const string&,float);
			explicit vector_unit_2d(const string&,const angle&);
			explicit vector_unit_2d(const string&); // Example of initialization string "1N 50º"
			
			vector_unit_2d& operator =(const vector_unit_2d&);
			vector_unit_2d& operator =(vector_unit_2d&&);
			
			vector_unit_2d& operator =(const scalar_unit&);
			vector_unit_2d& operator =(scalar_unit&&);
			
			void operator +=(const vector_unit_2d&);
			void operator -=(vector_unit_2d);
			
			vector_unit_2d operator +(const vector_unit_2d&) const;
			vector_unit_2d operator -(vector_unit_2d) const;

			vector_unit_2d operator *(const scalar_unit&) const;
			vector_unit_2d operator /(const scalar_unit&) const;
			vector_unit_2d operator ^(const scalar_unit&) const;
			
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			vector_unit_2d operator +(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			vector_unit_2d operator -(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			vector_unit_2d operator *(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			vector_unit_2d operator /(U) const;
			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			vector_unit_2d operator ^(U) const;

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
					theta.invert();
				}
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator /=(U y)
			{
				scalar_unit::value /= y;
				if(y < 0)
				{
					theta.invert();
				}
			}
			
			inline scalar_unit x_projection() const
			{
				return scalar_unit(scalar_unit::value * msci::cos(theta),get_dimensions());
			}

			inline scalar_unit y_projection() const
			{
				return scalar_unit(scalar_unit::value * msci::sin(theta),get_dimensions());
			}

			inline void invert()
			{
				theta.invert();
			}
			
			angle theta;
	};
	
	string to_string(const vector_unit_2d&);
	scalar_unit norm(const vector_unit_2d&);
	vector_unit_2d sqrt(const vector_unit_2d&);
	vector_unit_2d sqrt_nth(const vector_unit_2d&,int);
	scalar_unit dot_product(const vector_unit_2d&,const vector_unit_2d&);
	angle angle_between(const vector_unit_2d&,const vector_unit_2d&);
	bool same_direction(const vector_unit_2d&,const vector_unit_2d&);
	bool parallel(const vector_unit_2d&,const vector_unit_2d&);
	bool orthogonal(const vector_unit_2d&,const vector_unit_2d&);
}

bool operator ==(const vector_unit_2d&, vector_unit_2d);
bool operator !=(const vector_unit_2d&, const vector_unit_2d&);

bool operator ==(const vector_unit_2d&, const string&);
bool operator !=(const vector_unit_2d&, const string&);

bool operator ==(const string&, const vector_unit_2d&);
bool operator !=(const string&, const vector_unit_2d&);

void operator +=(string&, const vector_unit_2d&);
string operator +(const string&, const vector_unit_2d&);
string operator +(const vector_unit_2d&, const string&);

ostream& operator <<(ostream&, const vector_unit_2d&);
istream& operator >>(istream&, vector_unit_2d&);

#endif // MSCI_UNITS_UNITS_VECTOR_UNIT_2D_HPP_INCLUDED
