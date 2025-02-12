#ifndef SCIFIR_UNITS_UNITS_VECTOR_UNIT_3D_HPP_INCLUDED
#define SCIFIR_UNITS_UNITS_VECTOR_UNIT_3D_HPP_INCLUDED

#include "./scalar_unit.hpp"
#include "./vector_unit_2d.hpp"
#include "./vector_unit_nd.hpp"
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
			name##_3d(); \
			name##_3d(const name##_3d&); \
			name##_3d(name##_3d&&); \
			explicit name##_3d(float new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi,dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_3d(float new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_3d(double new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_3d(double new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_3d(long double new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_3d(long double new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_3d(int new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_3d(int new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_3d(float new_value,const string& init_dimensions,float new_theta,float new_phi); \
			explicit name##_3d(float new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(double new_value,const string& init_dimensions,float new_theta,float new_phi); \
			explicit name##_3d(double new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(long double new_value,const string& init_dimensions,float new_theta,float new_phi); \
			explicit name##_3d(long double new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(int new_value,const string& init_dimensions,float new_theta,float new_phi); \
			explicit name##_3d(int new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(float new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi); \
			explicit name##_3d(float new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(double new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi); \
			explicit name##_3d(double new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(long double new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi); \
			explicit name##_3d(long double new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(int new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi); \
			explicit name##_3d(int new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(const scalar_unit& x,float new_theta,float new_phi); \
			explicit name##_3d(const scalar_unit& x,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(const string& init_scalar,float new_theta,float new_phi); \
			explicit name##_3d(const string& init_scalar,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(const string& init_vector_3d); \
			explicit name##_3d(const vector_unit_3d& init_vector_3d); \
			explicit name##_3d(vector_unit_3d&& init_vector_3d); \
			name##_3d& operator =(const name##_3d& x); \
			name##_3d& operator =(name##_3d&& x); \
			using vector_unit_3d::operator =; \
			using vector_unit_3d::operator+=; \
			using vector_unit_3d::operator-=

#define	VECTOR_UNIT_3D_HPP_END() public: \
		static const string dimensions_match; \
		static const vector<dimension> real_dimensions; \
	}

#define VECTOR_UNIT_3D_HPP(name) class name##_3d : public vector_unit_3d \
	{	\
		public: \
			name##_3d(); \
			name##_3d(const name##_3d&); \
			name##_3d(name##_3d&&); \
			explicit name##_3d(float new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi,dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_3d(float new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_3d(double new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_3d(double new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_3d(long double new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_3d(long double new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_3d(int new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_3d(int new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_3d(float new_value,const string& init_dimensions,float new_theta,float new_phi); \
			explicit name##_3d(float new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(double new_value,const string& init_dimensions,float new_theta,float new_phi); \
			explicit name##_3d(double new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(long double new_value,const string& init_dimensions,float new_theta,float new_phi); \
			explicit name##_3d(long double new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(int new_value,const string& init_dimensions,float new_theta,float new_phi); \
			explicit name##_3d(int new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(float new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi); \
			explicit name##_3d(float new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(double new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi); \
			explicit name##_3d(double new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(long double new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi); \
			explicit name##_3d(long double new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(int new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi); \
			explicit name##_3d(int new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(const scalar_unit& x,float new_theta,float new_phi); \
			explicit name##_3d(const scalar_unit& x,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(const string& init_scalar,float new_theta,float new_phi); \
			explicit name##_3d(const string& init_scalar,const angle& new_theta,const angle& new_phi); \
			explicit name##_3d(const string& init_vector_3d); \
			explicit name##_3d(const vector_unit_3d& init_vector_3d); \
			explicit name##_3d(vector_unit_3d&& init_vector_3d); \
			name##_3d& operator =(const name##_3d& x); \
			name##_3d& operator =(name##_3d&& x); \
			using vector_unit_3d::operator =; \
			using vector_unit_3d::operator+=; \
			using vector_unit_3d::operator-=; \
\
			static const string dimensions_match; \
			static const vector<dimension> real_dimensions; \
	}

#define VECTOR_UNIT_3D_CPP(name,init_real_dimensions) name##_3d::name##_3d() : vector_unit_3d() {} \
	name##_3d::name##_3d(const name##_3d& x) : vector_unit_3d(x) {} \
	name##_3d::name##_3d(name##_3d&& x) : vector_unit_3d(std::move(x)) {} \
	name##_3d::name##_3d(float new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi, dimension::position new_position) : vector_unit_3d(new_value,new_dimension,new_prefix,new_theta,new_phi,new_position) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(float new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position) : vector_unit_3d(new_value,new_dimension,new_prefix,new_theta,new_phi,new_position) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(double new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi, dimension::position new_position) : vector_unit_3d(new_value,new_dimension,new_prefix,new_theta,new_phi,new_position) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(double new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position) : vector_unit_3d(new_value,new_dimension,new_prefix,new_theta,new_phi,new_position) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(long double new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi, dimension::position new_position) : vector_unit_3d(new_value,new_dimension,new_prefix,new_theta,new_phi,new_position) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(long double new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position) : vector_unit_3d(new_value,new_dimension,new_prefix,new_theta,new_phi,new_position) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(int new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi, dimension::position new_position) : vector_unit_3d(new_value,new_dimension,new_prefix,new_theta,new_position) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(int new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position) : vector_unit_3d(new_value,new_dimension,new_prefix,new_theta,new_phi,new_position) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(float new_value,const string& init_dimensions,float new_theta,float new_phi) : vector_unit_3d(new_value,init_dimensions,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(float new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi) : vector_unit_3d(new_value,init_dimensions,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(double new_value,const string& init_dimensions,float new_theta,float new_phi) : vector_unit_3d(new_value,init_dimensions,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(double new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi) : vector_unit_3d(new_value,init_dimensions,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(long double new_value,const string& init_dimensions,float new_theta,float new_phi) : vector_unit_3d(new_value,init_dimensions,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(long double new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi) : vector_unit_3d(new_value,init_dimensions,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(int new_value,const string& init_dimensions,float new_theta,float new_phi) : vector_unit_3d(new_value,init_dimensions,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(int new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi) : vector_unit_3d(new_value,init_dimensions,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(float new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi) : vector_unit_3d(new_value,new_dimensions,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(float new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi) : vector_unit_3d(new_value,new_dimensions,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(double new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi) : vector_unit_3d(new_value,new_dimensions,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(double new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi) : vector_unit_3d(new_value,new_dimensions,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(long double new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi) : vector_unit_3d(new_value,new_dimensions,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(long double new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi) : vector_unit_3d(new_value,new_dimensions,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(int new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi) : vector_unit_3d(new_value,new_dimensions,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(int new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi) : vector_unit_3d(new_value,new_dimensions,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(const scalar_unit& x,float new_theta,float new_phi) : vector_unit_3d(x,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(const scalar_unit& x,const angle& new_theta,const angle& new_phi) : vector_unit_3d(x,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(const string& init_scalar,float new_theta,float new_phi) : vector_unit_3d(init_scalar,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(const string& init_scalar,const angle& new_theta,const angle& new_phi) : vector_unit_3d(init_scalar,new_theta,new_phi) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(const string& init_vector_3d) : vector_unit_3d() \
	{ \
		vector_unit_3d::initialize_from_string(init_vector_3d); \
	} \
\
	name##_3d::name##_3d(const vector_unit_3d& x) : vector_unit_3d(x) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d::name##_3d(vector_unit_3d&& x) : vector_unit_3d(x) \
	{ \
		scalar_unit::check_dimensions(name##_3d::real_dimensions); \
	} \
\
	name##_3d& name##_3d::operator =(const name##_3d& x) \
	{ \
		vector_unit_3d::operator =(x); \
		return *this; \
	} \
\
	name##_3d& name##_3d::operator =(name##_3d&& x) \
	{ \
		vector_unit_3d::operator =(std::move(x)); \
		return *this; \
	} \
const string name##_3d::dimensions_match = init_real_dimensions; \
const vector<dimension> name##_3d::real_dimensions = create_base_dimensions(init_real_dimensions)

#define VECTOR_UNIT_HPP(name) SCALAR_UNIT_HPP(name); \
VECTOR_UNIT_2D_HPP(name); \
VECTOR_UNIT_3D_HPP(name); \
VECTOR_UNIT_ND_HPP(name)

#define VECTOR_UNIT_CPP(name,init_real_dimensions) SCALAR_UNIT_CPP(name,init_real_dimensions); \
VECTOR_UNIT_2D_CPP(name,init_real_dimensions); \
VECTOR_UNIT_3D_CPP(name,init_real_dimensions); \
VECTOR_UNIT_ND_CPP(name,init_real_dimensions)

using namespace std;

namespace scifir
{
	class vector_unit_3d : public scalar_unit
	{
		public:
			vector_unit_3d();
			vector_unit_3d(const vector_unit_3d& x);
			vector_unit_3d(vector_unit_3d&& x);
			explicit vector_unit_3d(float new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi,dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_3d(float new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_3d(double new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_3d(double new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_3d(long double new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_3d(long double new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_3d(int new_value, dimension::type new_dimension, prefix::type new_prefix, float new_theta, float new_phi, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_3d(int new_value, dimension::type new_dimension, prefix::type new_prefix, const angle& new_theta, const angle& new_phi, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_3d(float new_value,const string& init_dimensions,float new_theta,float new_phi);
			explicit vector_unit_3d(float new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi);
			explicit vector_unit_3d(double new_value,const string& init_dimensions,float new_theta,float new_phi);
			explicit vector_unit_3d(double new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi);
			explicit vector_unit_3d(long double new_value,const string& init_dimensions,float new_theta,float new_phi);
			explicit vector_unit_3d(long double new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi);
			explicit vector_unit_3d(int new_value,const string& init_dimensions,float new_theta,float new_phi);
			explicit vector_unit_3d(int new_value,const string& init_dimensions,const angle& new_theta,const angle& new_phi);
			explicit vector_unit_3d(float new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi);
			explicit vector_unit_3d(float new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi);
			explicit vector_unit_3d(double new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi);
			explicit vector_unit_3d(double new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi);
			explicit vector_unit_3d(long double new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi);
			explicit vector_unit_3d(long double new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi);
			explicit vector_unit_3d(int new_value,const vector<dimension>& new_dimensions,float new_theta,float new_phi);
			explicit vector_unit_3d(int new_value,const vector<dimension>& new_dimensions,const angle& new_theta,const angle& new_phi);
			explicit vector_unit_3d(const scalar_unit& x,float new_theta,float new_phi);
			explicit vector_unit_3d(const scalar_unit& x,const angle& new_theta,const angle& new_phi);
			explicit vector_unit_3d(const string& init_scalar,float new_theta,float new_phi);
			explicit vector_unit_3d(const string& init_scalar,const angle& new_theta,const angle& new_phi);
			explicit vector_unit_3d(const string& init_vector_3d);

			static vector_unit_3d cartesian_3d(const string& init_dimensions,float new_x,float new_y,float new_z)
			{
				float new_value = float(std::sqrt(std::pow(new_x,2) + std::pow(new_y,2) + std::pow(new_z,2)));
				float new_theta = scifir::atan_degree(new_y / new_x);
				float new_phi = scifir::acos_degree(new_z / new_value);
				return vector_unit_3d(new_value,init_dimensions,angle(new_theta),angle(new_phi));
			}

			static vector_unit_3d cylindrical(const string& init_dimensions,float new_p,angle new_theta,float new_z)
			{
				float new_value = float(std::sqrt(std::pow(new_p,2) + std::pow(new_z,2)));
				float new_phi = scifir::atan_degree(new_p / new_z);
				return vector_unit_3d(new_value,init_dimensions,new_theta,angle(new_phi));
			}

			vector_unit_3d& operator =(const vector_unit_3d& x);
			vector_unit_3d& operator =(vector_unit_3d&& x);
			vector_unit_3d& operator =(const scalar_unit& x);
			vector_unit_3d& operator =(scalar_unit&& x);
			vector_unit_3d& operator =(const string& init_vector_3d);

			bool operator ==(vector_unit_3d x) const;

			void point_to(direction::name x);

			void operator +=(const vector_unit_3d& x);
			void operator -=(vector_unit_3d x);

			vector_unit_3d operator +(const vector_unit_3d& x) const;
			vector_unit_3d operator -(vector_unit_3d x) const;

			vector_unit_3d operator *(const scalar_unit& x) const;
			vector_unit_3d operator /(const scalar_unit& x) const;
			vector_unit_3d operator ^(const scalar_unit& x) const;

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			vector_unit_3d operator +(T x) const
			{
				vector_unit_3d y = *this;
				y += x;
				return y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			vector_unit_3d operator -(T x) const
			{
				vector_unit_3d y = *this;
				y -= x;
				return y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			vector_unit_3d operator *(T x) const
			{
				vector_unit_3d y = *this;
				y *= x;
				return y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			vector_unit_3d operator /(T x) const
			{
				vector_unit_3d y = *this;
				y /= x;
				return y;
			}

			template<typename T, typename = typename enable_if<is_integer_number<T>::value>::type>
			vector_unit_3d operator ^(T x) const
			{
				return vector_unit_3d(std::pow(get_value(),x),power_dimensions(get_dimensions(),x),theta,phi);
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
					invert();
				}
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator /=(T x)
			{
				scalar_unit::value /= std::abs(x);
				if(x < 0)
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

			string vectorial_display(int number_of_decimals = 2) const;
			string vectorial_base_display(int number_of_decimals = 2) const;
			string vectorial_custom_display(const string& init_dimensions,int number_of_decimals = 2) const;

			angle theta;
			angle phi;

		protected:
			void initialize_from_string(string init_vector_3d);
	};

	string to_string(const vector_unit_3d& x);
	scalar_unit norm(const vector_unit_3d& x);
	vector_unit_3d sqrt(const vector_unit_3d& x);
	vector_unit_3d sqrt_nth(const vector_unit_3d& x,int index);
	scalar_unit dot_product(const vector_unit_3d& x,const vector_unit_3d& y);
	vector_unit_3d cross_product(const vector_unit_3d& x,const vector_unit_3d& y);
	angle angle_between(const vector_unit_3d& x,const vector_unit_3d& y);
	bool same_direction(const vector_unit_3d& x,const vector_unit_3d& y);
	bool parallel(const vector_unit_3d& x,const vector_unit_3d& y);
	bool orthogonal(const vector_unit_3d& x,const vector_unit_3d& y);
}

scifir::vector_unit_3d operator *(const scifir::scalar_unit& x,const scifir::vector_unit_3d& y);

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

bool operator !=(const scifir::vector_unit_3d& x, const scifir::vector_unit_3d& y);

bool operator ==(const scifir::vector_unit_3d& x, const string& init_vector_3d);
bool operator !=(const scifir::vector_unit_3d& x, const string& init_vector_3d);
bool operator ==(const string& init_vector_3d, const scifir::vector_unit_3d& x);
bool operator !=(const string& init_vector_3d, const scifir::vector_unit_3d& x);

void operator +=(string& x, const scifir::vector_unit_3d& y);
string operator +(const string& x, const scifir::vector_unit_3d& y);
string operator +(const scifir::vector_unit_3d& y, const string& x);

ostream& operator <<(ostream& os, const scifir::vector_unit_3d& x);
istream& operator >>(istream& is, scifir::vector_unit_3d& x);

#endif // SCIFIR_UNITS_UNITS_VECTOR_UNIT_3D_HPP_INCLUDED
