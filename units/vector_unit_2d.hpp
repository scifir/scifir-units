#ifndef SCIFIR_UNITS_UNITS_VECTOR_UNIT_2D_HPP_INCLUDED
#define SCIFIR_UNITS_UNITS_VECTOR_UNIT_2D_HPP_INCLUDED

#include "./scalar_unit.hpp"
#include "../meca_number/angle.hpp"
#include "../util/is_number.hpp"
#include "../topology/direction.hpp"

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
			using vector_unit_2d::operator =; \
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
			using vector_unit_2d::operator =; \
			using vector_unit_2d::operator+=; \
			using vector_unit_2d::operator-=; \
\
			static const string dimensions_match; \
			static const vector<dimension> real_dimensions; \
	}

#define VECTOR_UNIT_2D_CPP(name,init_dimensions) name##_2d::name##_2d() : vector_unit_2d() {} \
	name##_2d::name##_2d(const name##_2d& x) : vector_unit_2d(x) {} \
	name##_2d::name##_2d(name##_2d&& x) : vector_unit_2d(std::move(x)) {} \
const string name##_2d::dimensions_match = init_dimensions; \
const vector<dimension> name##_2d::real_dimensions = create_base_dimensions(init_dimensions)

using namespace std;

namespace scifir
{
	class vector_unit_2d : public scalar_unit
	{
		public:
			vector_unit_2d();
			vector_unit_2d(const vector_unit_2d& x);
			vector_unit_2d(vector_unit_2d&& x);
			explicit vector_unit_2d(float new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta,dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_2d(float new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_2d(double new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_2d(double new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_2d(long double new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_2d(long double new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_2d(int new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_2d(int new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_2d(float new_value,const string& init_dimensions,float new_theta); // Example of initialization (10,"N",50)
			explicit vector_unit_2d(float new_value,const string& init_dimensions,const angle& new_theta); // Example of initialization (10,"N",50ª)
			explicit vector_unit_2d(double new_value,const string& init_dimensions,float new_theta); // Example of initialization (10,"N",50)
			explicit vector_unit_2d(double new_value,const string& init_dimensions,const angle& new_theta);
			explicit vector_unit_2d(long double new_value,const string& init_dimensions,float new_theta); // Example of initialization (10,"N",50)
			explicit vector_unit_2d(long double new_value,const string& init_dimensions,const angle& new_theta);
			explicit vector_unit_2d(int new_value,const string& init_dimensions,float new_theta);
			explicit vector_unit_2d(int new_value,const string& init_dimensions,const angle& new_theta);
			explicit vector_unit_2d(float new_value,const vector<dimension>& new_dimensions,float new_theta);
			explicit vector_unit_2d(float new_value,const vector<dimension>& new_dimensions,const angle& new_theta);
			explicit vector_unit_2d(double new_value,const vector<dimension>& new_dimensions,float new_theta);
			explicit vector_unit_2d(double new_value,const vector<dimension>& new_dimensions,const angle& new_theta);
			explicit vector_unit_2d(long double new_value,const vector<dimension>& new_dimensions,float new_theta);
			explicit vector_unit_2d(long double new_value,const vector<dimension>& new_dimensions,const angle& new_theta);
			explicit vector_unit_2d(int new_value,const vector<dimension>& new_dimensions,float new_theta);
			explicit vector_unit_2d(int new_value,const vector<dimension>& new_dimensions,const angle& new_theta);
			explicit vector_unit_2d(const scalar_unit& x,float new_theta);
			explicit vector_unit_2d(const scalar_unit& x,const angle& new_theta);
			explicit vector_unit_2d(const string& init_scalar,float new_theta);
			explicit vector_unit_2d(const string& init_scalar,const angle& new_theta);
			explicit vector_unit_2d(const string& init_vector_2d); // Example of initialization string "1N 50º"

			static vector_unit_2d cartesian_2d(const string& init_dimensions,float new_x,float new_y)
			{
				float new_value = float(std::sqrt(std::pow(new_x,2) + std::pow(new_y,2)));
				float new_theta = scifir::atan_degree(new_y / new_x);
				return vector_unit_2d(new_value,init_dimensions,angle(new_theta));
			}

			vector_unit_2d& operator =(const vector_unit_2d& x);
			vector_unit_2d& operator =(vector_unit_2d&& x);
			vector_unit_2d& operator =(const scalar_unit& x);
			vector_unit_2d& operator =(scalar_unit&& x);
			vector_unit_2d& operator =(const string& init_vector_2d);

			bool operator ==(vector_unit_2d x) const;

			void point_to(direction::name x);

			void operator +=(const vector_unit_2d& x);
			void operator -=(vector_unit_2d x);

			vector_unit_2d operator +(const vector_unit_2d& x) const;
			vector_unit_2d operator -(vector_unit_2d x) const;

			vector_unit_2d operator *(const scalar_unit& x) const;
			vector_unit_2d operator /(const scalar_unit& x) const;
			vector_unit_2d operator ^(const scalar_unit& x) const;

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			vector_unit_2d operator +(T x) const
			{
				vector_unit_2d y = *this;
				y += x;
				return y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			vector_unit_2d operator -(T x) const
			{
				vector_unit_2d y = *this;
				y -= x;
				return y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			vector_unit_2d operator *(T x) const
			{
				vector_unit_2d y = *this;
				y *= x;
				return y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			vector_unit_2d operator /(T x) const
			{
				vector_unit_2d y = *this;
				y /= x;
				return y;
			}

			template<typename T, typename = typename enable_if<is_integer_number<T>::value>::type>
			vector_unit_2d operator ^(T x) const
			{
				return vector_unit_2d(std::pow(get_value(),x),power_dimensions(get_dimensions(),x),theta);
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator +=(T x)
			{
				scalar_unit::value += x;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator -=(T x)
			{
				scalar_unit::value -= x;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator *=(T x)
			{
				scalar_unit::value *= std::abs(x);
				if(x < 0)
				{
					theta.invert();
				}
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator /=(T x)
			{
				scalar_unit::value /= std::abs(x);
				if(x < 0)
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

			string vectorial_display(int number_of_decimals = 2) const;
			string vectorial_base_display(int number_of_decimals = 2) const;
			string vectorial_custom_display(const string& init_dimensions,int number_of_decimals = 2) const;

			angle theta;

		private:
			void initialize_from_string(string init_vector_2d);
	};

	string to_string(const vector_unit_2d& x);
	scalar_unit norm(const vector_unit_2d& x);
	vector_unit_2d sqrt(const vector_unit_2d& x);
	vector_unit_2d sqrt_nth(const vector_unit_2d& x,int index);
	scalar_unit dot_product(const vector_unit_2d& x,const vector_unit_2d& y);
	angle angle_between(const vector_unit_2d& x,const vector_unit_2d& y);
	bool same_direction(const vector_unit_2d& x,const vector_unit_2d& y);
	bool parallel(const vector_unit_2d& x,const vector_unit_2d& y);
	bool orthogonal(const vector_unit_2d& x,const vector_unit_2d& y);
}

scifir::vector_unit_2d operator *(const scifir::scalar_unit& x,const scifir::vector_unit_2d& y);

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

bool operator !=(const scifir::vector_unit_2d& x, const scifir::vector_unit_2d& y);

bool operator ==(const scifir::vector_unit_2d& x, const string& init_vector_2d);
bool operator !=(const scifir::vector_unit_2d& x, const string& init_vector_2d);

bool operator ==(const string& init_vector_2d, const scifir::vector_unit_2d& x);
bool operator !=(const string& init_vector_2d, const scifir::vector_unit_2d& x);

void operator +=(string& x, const scifir::vector_unit_2d& y);
string operator +(const string& x, const scifir::vector_unit_2d& y);
string operator +(const scifir::vector_unit_2d& y, const string& x);

ostream& operator <<(ostream& os, const scifir::vector_unit_2d& x);
istream& operator >>(istream& is, scifir::vector_unit_2d& x);

#endif // SCIFIR_UNITS_UNITS_VECTOR_UNIT_2D_HPP_INCLUDED
