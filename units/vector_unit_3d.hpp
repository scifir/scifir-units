#ifndef SCIFIR_UNITS_UNITS_VECTOR_UNIT_3D_HPP_INCLUDED
#define SCIFIR_UNITS_UNITS_VECTOR_UNIT_3D_HPP_INCLUDED

#include "../units/scalar_unit.hpp"
#include "../units/vector_unit_2d.hpp"
#include "../units/vector_unit_nd.hpp"
#include "../meca_number/angle.hpp"
#include "../util/is_number.hpp"
#include "../topology/direction.hpp"

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
	name##_3d::name##_3d(name##_3d&& x) : vector_unit_3d(std::move(x)) {} \
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
			explicit vector_unit_3d(float,const string&,const angle&,const angle&);
			explicit vector_unit_3d(double,const string&,float,float);
			explicit vector_unit_3d(double,const string&,const angle&,const angle&);
			explicit vector_unit_3d(long double,const string&,float,float);
			explicit vector_unit_3d(long double,const string&,const angle&,const angle&);
			explicit vector_unit_3d(int,const string&,float,float);
			explicit vector_unit_3d(int,const string&,const angle&,const angle&);
			explicit vector_unit_3d(float,const vector<dimension>&,float,float);
			explicit vector_unit_3d(float,const vector<dimension>&,const angle&,const angle&);
			explicit vector_unit_3d(double,const vector<dimension>&,float,float);
			explicit vector_unit_3d(double,const vector<dimension>&,const angle&,const angle&);
			explicit vector_unit_3d(long double,const vector<dimension>&,float,float);
			explicit vector_unit_3d(long double,const vector<dimension>&,const angle&,const angle&);
			explicit vector_unit_3d(int,const vector<dimension>&,float,float);
			explicit vector_unit_3d(int,const vector<dimension>&,const angle&,const angle&);
			explicit vector_unit_3d(const scalar_unit&,float,float);
			explicit vector_unit_3d(const scalar_unit&,const angle&,const angle&);
			explicit vector_unit_3d(const string&,float,float);
			explicit vector_unit_3d(const string&,const angle&,const angle&);
			explicit vector_unit_3d(const string&);

			static vector_unit_3d cartesian_3d(const string& new_dimensions,float new_x,float new_y,float new_z)
			{
				float new_value = float(std::sqrt(std::pow(new_x,2) + std::pow(new_y,2) + std::pow(new_z,2)));
				float new_theta = scifir::atan_grade(new_y / new_x);
				float new_phi = scifir::acos_grade(new_z / new_value);
				return vector_unit_3d(new_value,new_dimensions,angle(new_theta),angle(new_phi));
			}

			static vector_unit_3d cylindrical(const string& new_dimensions,float new_p,angle new_theta,float new_z)
			{
				float new_value = float(std::sqrt(std::pow(new_p,2) + std::pow(new_z,2)));
				float new_phi = scifir::atan_grade(new_p / new_z);
				return vector_unit_3d(new_value,new_dimensions,new_theta,angle(new_phi));
			}

			vector_unit_3d& operator =(const vector_unit_3d&);
			vector_unit_3d& operator =(vector_unit_3d&&);
			vector_unit_3d& operator =(const scalar_unit&);
			vector_unit_3d& operator =(scalar_unit&&);
			vector_unit_3d& operator =(const string&);

			void point_to(direction::name);

			void operator +=(const vector_unit_3d&);
			void operator -=(vector_unit_3d);

			vector_unit_3d operator +(const vector_unit_3d&) const;
			vector_unit_3d operator -(vector_unit_3d) const;

			vector_unit_3d operator *(const scalar_unit&) const;
			vector_unit_3d operator /(const scalar_unit&) const;
			vector_unit_3d operator ^(const scalar_unit&) const;

			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			vector_unit_3d operator +(U x) const
			{
				vector_unit_3d y = *this;
				y += x;
				return y;
			}

			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			vector_unit_3d operator -(U x) const
			{
				vector_unit_3d y = *this;
				y -= x;
				return y;
			}

			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			vector_unit_3d operator *(U x) const
			{
				vector_unit_3d y = *this;
				y *= x;
				return y;
			}

			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			vector_unit_3d operator /(U x) const
			{
				vector_unit_3d y = *this;
				y /= x;
				return y;
			}

			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			vector_unit_3d operator ^(U x) const
			{
				return vector_unit_3d(std::pow(get_value(),x),power_dimensions(get_dimensions(),x),theta,phi);
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
				scalar_unit::value *= std::abs(y);
				if(y < 0)
				{
					invert();
				}
			}

			template<typename U, typename = typename enable_if<scifir::is_number<U>::value>::type>
			void operator /=(U y)
			{
				scalar_unit::value /= std::abs(y);
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
				phi = 180.0f - phi;
			}

			string vectorial_display(int = 2) const;
			string vectorial_derived_display(int = 2) const;
			string vectorial_custom_display(const string&,int = 2) const;

			angle theta;
			angle phi;

		private:
			void initialize_from_string(string);
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

vector_unit_3d operator *(const scifir::scalar_unit&,const scifir::vector_unit_3d&);

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::vector_unit_3d operator +(const T y,const scifir::vector_unit_3d& x)
{
	scifir::vector_unit_3d z = x;
	z += y;
	return z;
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::vector_unit_3d operator -(const T y,const scifir::vector_unit_3d& x)
{
	return scifir::vector_unit_3d(y - x.get_value(),x.get_dimensions(),x.theta,x.phi);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::vector_unit_3d operator *(const T y,const scifir::vector_unit_3d& x)
{
	scifir::vector_unit_3d z = x;
	z *= y;
	return z;
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::vector_unit_3d operator /(const T y,const scifir::vector_unit_3d& x)
{
	vector<scifir::dimension> new_dimensions = x.get_dimensions();
	for (scifir::dimension& new_dimension : new_dimensions)
	{
		new_dimension.invert();
	}
	return scifir::vector_unit_3d(y / x.get_value(),new_dimensions,x.theta,x.phi);
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
