#ifndef MSCI_UNITS_UNITS_VECTOR_UNIT_2D_HPP_INCLUDED
#define MSCI_UNITS_UNITS_VECTOR_UNIT_2D_HPP_INCLUDED

#include "msci/units/units/scalar_unit.hpp"
#include "msci/units/meca_number/angle.hpp"
#include "msci/units/coordinates/coordinates_2d.hpp"

#include "boost/algorithm/string.hpp"

#include <iostream>
#include <string>

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
			explicit vector_unit_2d(float,const string&,const msci::angle&); // Example of initialization (10,"N",50ª)
			explicit vector_unit_2d(float,const vector<dimension>&,float);
			explicit vector_unit_2d(float,const vector<dimension>&,const msci::angle&);
			explicit vector_unit_2d(const scalar_unit&,float);
			explicit vector_unit_2d(const scalar_unit&,const msci::angle&);
			explicit vector_unit_2d(scalar_unit&&,float);
			explicit vector_unit_2d(scalar_unit&&,const msci::angle&);
			explicit vector_unit_2d(const string&,float);
			explicit vector_unit_2d(const string&,const msci::angle&);
			explicit vector_unit_2d(const string&); // Example of initialization string "1N 50º"
			
			vector_unit_2d& operator =(const vector_unit_2d&);
			vector_unit_2d& operator =(vector_unit_2d&&);
			
			vector_unit_2d& operator =(const scalar_unit&);
			vector_unit_2d& operator =(scalar_unit&&);
			
			void operator +=(const vector_unit_2d&);
			void operator -=(const vector_unit_2d&);
			
			vector_unit_2d operator +(const vector_unit_2d&) const;
			vector_unit_2d operator -(const vector_unit_2d&) const;

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

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator ^=(U y)
			{
				scalar_unit::value ^= y;
			}
			
			inline float x_projection() const
			{
				return scalar_unit::value * msci::cos(theta);
			}

			inline float y_projection() const
			{
				return scalar_unit::value * msci::sin(theta);
			}

			inline void invert()
			{
				theta.invert();
			}
			
			msci::angle theta;
	};
	
	string to_string(const vector_unit_2d&);
	scalar_unit norm(const vector_unit_2d&);
	vector_unit_2d sqrt(const vector_unit_2d&);
	vector_unit_2d sqrt_nth(const vector_unit_2d&,int);
	scalar_unit dot_product(const vector_unit_2d&,const vector_unit_2d&);
	msci::angle angle_between(const vector_unit_2d&,const vector_unit_2d&);
	bool same_direction(const vector_unit_2d&,const vector_unit_2d&);
	bool parallel(const vector_unit_2d&,const vector_unit_2d&);
	bool orthogonal(const vector_unit_2d&,const vector_unit_2d&);
}

bool operator ==(const vector_unit_2d&, const vector_unit_2d&);
bool operator !=(const vector_unit_2d&, const vector_unit_2d&);
bool operator <(const vector_unit_2d&, const vector_unit_2d&);
bool operator >(const vector_unit_2d&, const vector_unit_2d&);
bool operator <=(const vector_unit_2d&, const vector_unit_2d&);
bool operator >=(const vector_unit_2d&, const vector_unit_2d&);

bool operator ==(const vector_unit_2d&, const string&);
bool operator !=(const vector_unit_2d&, const string&);
bool operator <(const vector_unit_2d&, const string&);
bool operator >(const vector_unit_2d&, const string&);
bool operator <=(const vector_unit_2d&, const string&);
bool operator >=(const vector_unit_2d&, const string&);

bool operator ==(const string&, const vector_unit_2d&);
bool operator !=(const string&, const vector_unit_2d&);
bool operator <(const string&, const vector_unit_2d&);
bool operator >(const string&, const vector_unit_2d&);
bool operator <=(const string&, const vector_unit_2d&);
bool operator >=(const string&, const vector_unit_2d&);

void operator +=(string&, const vector_unit_2d&);
string operator +(const string&, const vector_unit_2d&);
string operator +(const vector_unit_2d&, const string&);

ostream& operator <<(ostream&, const vector_unit_2d&);
istream& operator >>(istream&, vector_unit_2d&);

#endif // MSCI_UNITS_UNITS_VECTOR_UNIT_2D_HPP_INCLUDED
