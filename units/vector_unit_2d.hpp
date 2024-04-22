#ifndef SCIFIR_UNITS_UNITS_VECTOR_UNIT_2D_HPP_INCLUDED
#define SCIFIR_UNITS_UNITS_VECTOR_UNIT_2D_HPP_INCLUDED

#include "../units/scalar_unit.hpp"
#include "../meca_number/angle.hpp"
#include "../util/is_number.hpp"

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
using namespace scifir;

namespace scifir
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
			explicit vector_unit_2d(const string&,float);
			explicit vector_unit_2d(const string&,const angle&);
			explicit vector_unit_2d(const string&); // Example of initialization string "1N 50º"

			static vector_unit_2d cartesian_2d(const string& new_dimensions,float new_x,float new_y)
			{
				float new_value = std::sqrt(std::pow(new_x,2) + std::pow(new_y,2));
				float new_theta = scifir::atan_grade(new_y / new_x);
				return vector_unit_2d(new_value,new_dimensions,angle(new_theta));
			}

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

			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			vector_unit_2d operator +(U x) const
			{
				vector_unit_2d y = *this;
				y += x;
				return y;
			}

			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			vector_unit_2d operator -(U x) const
			{
				vector_unit_2d y = *this;
				y -= x;
				return y;
			}

			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			vector_unit_2d operator *(U x) const
			{
				vector_unit_2d y = *this;
				y *= x;
				return y;
			}

			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			vector_unit_2d operator /(U x) const
			{
				vector_unit_2d y = *this;
				y /= x;
				return y;
			}

			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			vector_unit_2d operator ^(U x) const
			{
				return vector_unit_2d(std::pow(get_value(),x),power_dimensions(get_dimensions(),x),theta);
			}

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
					theta.invert();
				}
			}

			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
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
				return scalar_unit(scalar_unit::value * scifir::cos(theta),get_dimensions());
			}

			inline scalar_unit y_projection() const
			{
				return scalar_unit(scalar_unit::value * scifir::sin(theta),get_dimensions());
			}

			inline void invert()
			{
				theta.invert();
			}

			string vectorial_display(int = 2) const;
			string vectorial_derived_display(int = 2) const;
			string vectorial_custom_display(const string&,int = 2) const;

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

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::vector_unit_2d operator +(const T y,const scifir::vector_unit_2d& x)
{
	scifir::vector_unit_2d z = x;
	z += y;
	return z;
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::vector_unit_2d operator -(const T y,const scifir::vector_unit_2d& x)
{
	return scifir::vector_unit_2d(y - x.get_value(),x.get_dimensions(),x.theta);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::vector_unit_2d operator *(const T y,const scifir::vector_unit_2d& x)
{
	scifir::vector_unit_2d z = x;
	z *= y;
	return z;
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::vector_unit_2d operator /(const T y,const scifir::vector_unit_2d& x)
{
	vector<scifir::dimension> new_dimensions = x.get_dimensions();
	for (scifir::dimension& new_dimension : new_dimensions)
	{
		new_dimension.invert();
	}
	return scifir::vector_unit_2d(y / x.get_value(),new_dimensions,x.theta);
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

#endif // SCIFIR_UNITS_UNITS_VECTOR_UNIT_2D_HPP_INCLUDED
