#ifndef SCIFIR_UNITS_UNITS_VECTOR_UNIT_ND_HPP_INCLUDED
#define SCIFIR_UNITS_UNITS_VECTOR_UNIT_ND_HPP_INCLUDED

#include "./scalar_unit.hpp"
#include "../meca_number/angle.hpp"
#include "../util/is_number.hpp"
#include "../coordinates/direction.hpp"

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
			name##_nd(); \
			name##_nd(const name##_nd&); \
			name##_nd(name##_nd&&); \
			explicit name##_nd(float new_value, dimension::type new_dimension, prefix::type new_prefix, vector<float> new_angles,dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_nd(float new_value, dimension::type new_dimension, prefix::type new_prefix, const vector<angle>& new_angles, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_nd(double new_value, dimension::type new_dimension, prefix::type new_prefix, vector<float> new_angles, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_nd(double new_value, dimension::type new_dimension, prefix::type new_prefix, const vector<angle>& new_angles, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_nd(long double new_value, dimension::type new_dimension, prefix::type new_prefix, vector<float> new_angles, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_nd(long double new_value, dimension::type new_dimension, prefix::type new_prefix, const vector<angle>& new_angles, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_nd(int new_value, dimension::type new_dimension, prefix::type new_prefix, vector<float> new_angles, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_nd(int new_value, dimension::type new_dimension, prefix::type new_prefix, const vector<angle>& new_angles, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_nd(float new_value,const string& init_dimensions); \
			explicit name##_nd(float new_value,const string& init_dimensions,const vector<float>& new_angles); \
			explicit name##_nd(float new_value,const string& init_dimensions,const vector<angle>& new_angles); \
			explicit name##_nd(double new_value,const string& init_dimensions); \
			explicit name##_nd(double new_value,const string& init_dimensions,const vector<float>& new_angles); \
			explicit name##_nd(double new_value,const string& init_dimensions,const vector<angle>& new_angles); \
			explicit name##_nd(long double new_value,const string& init_dimensions); \
			explicit name##_nd(long double new_value,const string& init_dimensions,const vector<float>& new_angles); \
			explicit name##_nd(long double new_value,const string& init_dimensions,const vector<angle>& new_angles); \
			explicit name##_nd(int new_value,const string& init_dimensions); \
			explicit name##_nd(int new_value,const string& init_dimensions,const vector<float>& new_angles); \
			explicit name##_nd(int new_value,const string& init_dimensions,const vector<angle>& new_angles); \
			explicit name##_nd(float new_value,const vector<dimension>& new_dimensions); \
			explicit name##_nd(float new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles); \
			explicit name##_nd(float new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles); \
			explicit name##_nd(double new_value,const vector<dimension>& new_dimensions); \
			explicit name##_nd(double new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles); \
			explicit name##_nd(double new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles); \
			explicit name##_nd(long double new_value,const vector<dimension>& new_dimensions); \
			explicit name##_nd(long double new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles); \
			explicit name##_nd(long double new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles); \
			explicit name##_nd(int new_value,const vector<dimension>& new_dimensions); \
			explicit name##_nd(int new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles); \
			explicit name##_nd(int new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles); \
			explicit name##_nd(const scalar_unit& x); \
			explicit name##_nd(const scalar_unit& x,const vector<float>& new_angles); \
			explicit name##_nd(const scalar_unit& x,const vector<angle>& new_angles); \
			explicit name##_nd(const string& init_scalar,const vector<float>& new_angles); \
			explicit name##_nd(const string& init_scalar,const vector<angle>& new_angles); \
			explicit name##_nd(const string& init_vector_nd); \
			explicit name##_nd(const vector_unit_nd& x); \
			explicit name##_nd(vector_unit_nd&& x); \
			name##_nd& operator =(const name##_nd& x); \
			name##_nd& operator =(name##_nd&& x); \
			using vector_unit_nd::operator =; \
			using vector_unit_nd::operator+=; \
			using vector_unit_nd::operator-=

#define	VECTOR_UNIT_ND_HPP_END() public: \
		static const string dimensions_match; \
		static const vector<dimension> real_dimensions; \
	}

#define VECTOR_UNIT_ND_HPP(name) class name##_nd : public vector_unit_nd \
	{	\
		public: \
			name##_nd(); \
			name##_nd(const name##_nd&); \
			name##_nd(name##_nd&&); \
			explicit name##_nd(float new_value, dimension::type new_dimension, prefix::type new_prefix, vector<float> new_angles,dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_nd(float new_value, dimension::type new_dimension, prefix::type new_prefix, const vector<angle>& new_angles, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_nd(double new_value, dimension::type new_dimension, prefix::type new_prefix, vector<float> new_angles, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_nd(double new_value, dimension::type new_dimension, prefix::type new_prefix, const vector<angle>& new_angles, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_nd(long double new_value, dimension::type new_dimension, prefix::type new_prefix, vector<float> new_angles, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_nd(long double new_value, dimension::type new_dimension, prefix::type new_prefix, const vector<angle>& new_angles, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_nd(int new_value, dimension::type new_dimension, prefix::type new_prefix, vector<float> new_angles, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_nd(int new_value, dimension::type new_dimension, prefix::type new_prefix, const vector<angle>& new_angles, dimension::position new_position = dimension::NUMERATOR); \
			explicit name##_nd(float new_value,const string& init_dimensions); \
			explicit name##_nd(float new_value,const string& init_dimensions,const vector<float>& new_angles); \
			explicit name##_nd(float new_value,const string& init_dimensions,const vector<angle>& new_angles); \
			explicit name##_nd(double new_value,const string& init_dimensions); \
			explicit name##_nd(double new_value,const string& init_dimensions,const vector<float>& new_angles); \
			explicit name##_nd(double new_value,const string& init_dimensions,const vector<angle>& new_angles); \
			explicit name##_nd(long double new_value,const string& init_dimensions); \
			explicit name##_nd(long double new_value,const string& init_dimensions,const vector<float>& new_angles); \
			explicit name##_nd(long double new_value,const string& init_dimensions,const vector<angle>& new_angles); \
			explicit name##_nd(int new_value,const string& init_dimensions); \
			explicit name##_nd(int new_value,const string& init_dimensions,const vector<float>& new_angles); \
			explicit name##_nd(int new_value,const string& init_dimensions,const vector<angle>& new_angles); \
			explicit name##_nd(float new_value,const vector<dimension>& new_dimensions); \
			explicit name##_nd(float new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles); \
			explicit name##_nd(float new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles); \
			explicit name##_nd(double new_value,const vector<dimension>& new_dimensions); \
			explicit name##_nd(double new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles); \
			explicit name##_nd(double new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles); \
			explicit name##_nd(long double new_value,const vector<dimension>& new_dimensions); \
			explicit name##_nd(long double new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles); \
			explicit name##_nd(long double new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles); \
			explicit name##_nd(int new_value,const vector<dimension>& new_dimensions); \
			explicit name##_nd(int new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles); \
			explicit name##_nd(int new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles); \
			explicit name##_nd(const scalar_unit& x); \
			explicit name##_nd(const scalar_unit& x,const vector<float>& new_angles); \
			explicit name##_nd(const scalar_unit& x,const vector<angle>& new_angles); \
			explicit name##_nd(const string& init_scalar,const vector<float>& new_angles); \
			explicit name##_nd(const string& init_scalar,const vector<angle>& new_angles); \
			explicit name##_nd(const string& init_vector_nd); \
			explicit name##_nd(const vector_unit_nd& x); \
			explicit name##_nd(vector_unit_nd&& x); \
			name##_nd& operator =(const name##_nd& x); \
			name##_nd& operator =(name##_nd&& x); \
			using vector_unit_nd::operator =; \
			using vector_unit_nd::operator+=; \
			using vector_unit_nd::operator-=; \
\
			static const string dimensions_match; \
			static const vector<dimension> real_dimensions; \
	}

#define VECTOR_UNIT_ND_CPP(name,init_real_dimensions) name##_nd::name##_nd() : vector_unit_nd() {} \
	name##_nd::name##_nd(const name##_nd& x) : vector_unit_nd(x) {} \
	name##_nd::name##_nd(name##_nd&& x) : vector_unit_nd(std::move(x)) {} \
	name##_nd::name##_nd(float new_value, dimension::type new_dimension, prefix::type new_prefix, vector<float> new_angles, dimension::position new_position) : vector_unit_nd(new_value,new_dimension,new_prefix,new_angles,new_position) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
		for(const float& x_angle : new_angles) \
		{ \
			angles.push_back(angle(x_angle)); \
		} \
	} \
\
	name##_nd::name##_nd(float new_value, dimension::type new_dimension, prefix::type new_prefix, const vector<angle>& new_angles, dimension::position new_position) : vector_unit_nd(new_value,new_dimension,new_prefix,new_angles,new_position) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(double new_value, dimension::type new_dimension, prefix::type new_prefix, vector<float> new_angles, dimension::position new_position) : vector_unit_nd(new_value,new_dimension,new_prefix,new_angles,new_position) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
		for(const float& x_angle : new_angles) \
		{ \
			angles.push_back(angle(x_angle)); \
		} \
	} \
\
	name##_nd::name##_nd(double new_value, dimension::type new_dimension, prefix::type new_prefix, const vector<angle>& new_angles, dimension::position new_position) : vector_unit_nd(new_value,new_dimension,new_prefix,new_angles,new_position) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(long double new_value, dimension::type new_dimension, prefix::type new_prefix, vector<float> new_angles, dimension::position new_position) : vector_unit_nd(new_value,new_dimension,new_prefix,new_angles,new_position) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
		for(const float& x_angle : new_angles) \
		{ \
			angles.push_back(angle(x_angle)); \
		} \
	} \
\
	name##_nd::name##_nd(long double new_value, dimension::type new_dimension, prefix::type new_prefix, const vector<angle>& new_angles, dimension::position new_position) : vector_unit_nd(new_value,new_dimension,new_prefix,new_angles,new_position) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(int new_value, dimension::type new_dimension, prefix::type new_prefix, vector<float> new_angles, dimension::position new_position) : vector_unit_nd(new_value,new_dimension,new_prefix,new_angles,new_position) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
		for(const float& x_angle : new_angles) \
		{ \
			angles.push_back(angle(x_angle)); \
		} \
	} \
\
	name##_nd::name##_nd(int new_value, dimension::type new_dimension, prefix::type new_prefix, const vector<angle>& new_angles, dimension::position new_position) : vector_unit_nd(new_value,new_dimension,new_prefix,new_angles,new_position) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(float new_value,const string& init_dimensions) : vector_unit_nd(new_value,init_dimensions) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(float new_value,const string& init_dimensions,const vector<float>& new_angles) : vector_unit_nd(new_value,init_dimensions) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
		for(const float& x_angle : new_angles) \
		{ \
			angles.push_back(angle(x_angle)); \
		} \
	} \
\
	name##_nd::name##_nd(float new_value,const string& init_dimensions,const vector<angle>& new_angles) : vector_unit_nd(new_value,init_dimensions,new_angles) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(double new_value,const string& init_dimensions) : vector_unit_nd(new_value,init_dimensions) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(double new_value,const string& init_dimensions,const vector<float>& new_angles) : vector_unit_nd(new_value,init_dimensions) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
		for(const float& x_angle : new_angles) \
		{ \
			angles.push_back(angle(x_angle)); \
		} \
	} \
\
	name##_nd::name##_nd(double new_value,const string& init_dimensions,const vector<angle>& new_angles) : vector_unit_nd(new_value,init_dimensions,new_angles) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(long double new_value,const string& init_dimensions) : vector_unit_nd(new_value,init_dimensions) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(long double new_value,const string& init_dimensions,const vector<float>& new_angles) : vector_unit_nd(new_value,init_dimensions) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
		for(const float& x_angle : new_angles) \
		{ \
			angles.push_back(angle(x_angle)); \
		} \
	} \
\
	name##_nd::name##_nd(long double new_value,const string& init_dimensions,const vector<angle>& new_angles) : vector_unit_nd(new_value,init_dimensions,new_angles) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(int new_value,const string& init_dimensions) : vector_unit_nd(new_value,init_dimensions) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(int new_value,const string& init_dimensions,const vector<float>& new_angles) : vector_unit_nd(new_value,init_dimensions) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
		for(const float& x_angle : new_angles) \
		{ \
			angles.push_back(angle(x_angle)); \
		} \
	} \
\
	name##_nd::name##_nd(int new_value,const string& init_dimensions,const vector<angle>& new_angles) : vector_unit_nd(new_value,init_dimensions,new_angles) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(float new_value,const vector<dimension>& new_dimensions) : vector_unit_nd(new_value,new_dimensions) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(float new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles) : vector_unit_nd(new_value,new_dimensions) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
		for(const float& x_angle : new_angles) \
		{ \
			angles.push_back(angle(x_angle)); \
		} \
	} \
\
	name##_nd::name##_nd(float new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles) : vector_unit_nd(new_value,new_dimensions,new_angles) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(double new_value,const vector<dimension>& new_dimensions) : vector_unit_nd(new_value,new_dimensions) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(double new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles) : vector_unit_nd(new_value,new_dimensions) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
		for(const float& x_angle : new_angles) \
		{ \
			angles.push_back(angle(x_angle)); \
		} \
	} \
\
	name##_nd::name##_nd(double new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles) : vector_unit_nd(new_value,new_dimensions,new_angles) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(long double new_value,const vector<dimension>& new_dimensions) : vector_unit_nd(new_value,new_dimensions) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(long double new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles) : vector_unit_nd(new_value,new_dimensions) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
		for(const float& x_angle : new_angles) \
		{ \
			angles.push_back(angle(x_angle)); \
		} \
	} \
\
	name##_nd::name##_nd(long double new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles) : vector_unit_nd(new_value,new_dimensions,new_angles) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(int new_value,const vector<dimension>& new_dimensions) : vector_unit_nd(new_value,new_dimensions) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(int new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles) : vector_unit_nd(new_value,new_dimensions) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
		for(const float& x_angle : new_angles) \
		{ \
			angles.push_back(angle(x_angle)); \
		} \
	} \
\
	name##_nd::name##_nd(int new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles) : vector_unit_nd(new_value,new_dimensions,new_angles) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(const scalar_unit& x) : vector_unit_nd(x) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(const scalar_unit& x,const vector<float>& new_angles) : vector_unit_nd(x) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
		for(const float& x_angle : new_angles) \
		{ \
			angles.push_back(angle(x_angle)); \
		} \
	} \
\
	name##_nd::name##_nd(const scalar_unit& x,const vector<angle>& new_angles) : vector_unit_nd(x,new_angles) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(const string& init_scalar,const vector<float>& new_angles) : vector_unit_nd(init_scalar) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
		for(const float& x_angle : new_angles) \
		{ \
			angles.push_back(angle(x_angle)); \
		} \
	} \
\
	name##_nd::name##_nd(const string& init_scalar,const vector<angle>& new_angles) : vector_unit_nd(init_scalar,new_angles) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(const string& init_vector_nd) : vector_unit_nd() \
	{ \
		vector_unit_nd::initialize_from_string(init_vector_nd); \
	} \
\
	name##_nd::name##_nd(const vector_unit_nd& x) : vector_unit_nd(x) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd::name##_nd(vector_unit_nd&& x) : vector_unit_nd(x) \
	{ \
		scalar_unit::check_dimensions(name##_nd::real_dimensions); \
	} \
\
	name##_nd& name##_nd::operator =(const name##_nd& x) \
	{ \
		vector_unit_nd::operator =(x); \
		return *this; \
	} \
\
	name##_nd& name##_nd::operator =(name##_nd&& x) \
	{ \
		vector_unit_nd::operator =(std::move(x)); \
		return *this; \
	} \
const string name##_nd::dimensions_match = init_real_dimensions; \
const vector<dimension> name##_nd::real_dimensions = create_base_dimensions(init_real_dimensions)

using namespace std;

namespace scifir
{
	class vector_unit_nd : public scalar_unit
	{
		public:
			vector_unit_nd();
			vector_unit_nd(const vector_unit_nd& x);
			vector_unit_nd(vector_unit_nd&& x);
			explicit vector_unit_nd(float new_value, dimension::type new_dimension, prefix::type new_prefix, vector<float> new_angles,dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_nd(float new_value, dimension::type new_dimension, prefix::type new_prefix, const vector<angle>& new_angles, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_nd(double new_value, dimension::type new_dimension, prefix::type new_prefix, vector<float> new_angles, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_nd(double new_value, dimension::type new_dimension, prefix::type new_prefix, const vector<angle>& new_angles, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_nd(long double new_value, dimension::type new_dimension, prefix::type new_prefix, vector<float> new_angles, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_nd(long double new_value, dimension::type new_dimension, prefix::type new_prefix, const vector<angle>& new_angles, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_nd(int new_value, dimension::type new_dimension, prefix::type new_prefix, vector<float> new_angles, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_nd(int new_value, dimension::type new_dimension, prefix::type new_prefix, const vector<angle>& new_angles, dimension::position new_position = dimension::NUMERATOR);
			explicit vector_unit_nd(float new_value,const string& init_dimensions);
			explicit vector_unit_nd(float new_value,const string& init_dimensions,const vector<float>& new_angles);
			explicit vector_unit_nd(float new_value,const string& init_dimensions,const vector<angle>& new_angles);
			explicit vector_unit_nd(double new_value,const string& init_dimensions);
			explicit vector_unit_nd(double new_value,const string& init_dimensions,const vector<float>& new_angles);
			explicit vector_unit_nd(double new_value,const string& init_dimensions,const vector<angle>& new_angles);
			explicit vector_unit_nd(long double new_value,const string& init_dimensions);
			explicit vector_unit_nd(long double new_value,const string& init_dimensions,const vector<float>& new_angles);
			explicit vector_unit_nd(long double new_value,const string& init_dimensions,const vector<angle>& new_angles);
			explicit vector_unit_nd(int new_value,const string& init_dimensions);
			explicit vector_unit_nd(int new_value,const string& init_dimensions,const vector<float>& new_angles);
			explicit vector_unit_nd(int new_value,const string& init_dimensions,const vector<angle>& new_angles);
			explicit vector_unit_nd(float new_value,const vector<dimension>& new_dimensions);
			explicit vector_unit_nd(float new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles);
			explicit vector_unit_nd(float new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles);
			explicit vector_unit_nd(double new_value,const vector<dimension>& new_dimensions);
			explicit vector_unit_nd(double new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles);
			explicit vector_unit_nd(double new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles);
			explicit vector_unit_nd(long double new_value,const vector<dimension>& new_dimensions);
			explicit vector_unit_nd(long double new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles);
			explicit vector_unit_nd(long double new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles);
			explicit vector_unit_nd(int new_value,const vector<dimension>& new_dimensions);
			explicit vector_unit_nd(int new_value,const vector<dimension>& new_dimensions,const vector<float>& new_angles);
			explicit vector_unit_nd(int new_value,const vector<dimension>& new_dimensions,const vector<angle>& new_angles);
			explicit vector_unit_nd(const scalar_unit& x);
			explicit vector_unit_nd(const scalar_unit& x,const vector<float>& new_angles);
			explicit vector_unit_nd(const scalar_unit& x,const vector<angle>& new_angles);
			explicit vector_unit_nd(const string& init_scalar,const vector<float>& new_angles);
			explicit vector_unit_nd(const string& init_scalar,const vector<angle>& new_angles);
			explicit vector_unit_nd(const string& init_vector_nd);

			static vector_unit_nd cartesian_2d(const string& init_dimensions,float new_x,float new_y)
			{
				float new_value = float(std::sqrt(std::pow(new_x,2) + std::pow(new_y,2)));
				float new_theta = scifir::atan_degree(new_y / new_x);
				return vector_unit_nd(new_value,init_dimensions, {angle(new_theta)});
			}

			static vector_unit_nd cartesian_3d(const string& init_dimensions,float new_x,float new_y,float new_z)
			{
				float new_value = float(std::sqrt(std::pow(new_x,2) + std::pow(new_y,2) + std::pow(new_z,2)));
				float new_theta = scifir::atan_degree(new_y / new_x);
				float new_phi = scifir::acos_degree(new_z / new_value);
				return vector_unit_nd(new_value,init_dimensions, {angle(new_theta), angle(new_phi)});
			}

			static vector_unit_nd cylindrical(const string& init_dimensions,float new_p,angle new_theta,float new_z)
			{
				float new_value = float(std::sqrt(std::pow(new_p,2) + std::pow(new_z,2)));
				float new_phi = scifir::atan_degree(new_p / new_z);
				return vector_unit_nd(new_value,init_dimensions, {new_theta, angle(new_phi)});
			}

			vector_unit_nd& operator =(const vector_unit_nd& x);
			vector_unit_nd& operator =(vector_unit_nd&& x);
			vector_unit_nd& operator =(const scalar_unit& x);
			vector_unit_nd& operator =(scalar_unit&& x);
			vector_unit_nd& operator =(const string& init_vector_nd);

			bool operator ==(vector_unit_nd x) const;

			void point_to(direction::name x);
			
			void operator +=(const vector_unit_nd& x);
			void operator -=(vector_unit_nd x);

			vector_unit_nd operator +(const vector_unit_nd& x) const;
			vector_unit_nd operator -(vector_unit_nd x) const;

			vector_unit_nd operator *(const scalar_unit& x) const;
			vector_unit_nd operator /(const scalar_unit& x) const;
			vector_unit_nd operator ^(const scalar_unit& x) const;

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			vector_unit_nd operator +(T x) const
			{
				vector_unit_nd y = *this;
				y += x;
				return y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			vector_unit_nd operator -(T x) const
			{
				vector_unit_nd y = *this;
				y -= x;
				return y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			vector_unit_nd operator *(T x) const
			{
				vector_unit_nd y = *this;
				y *= x;
				return y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			vector_unit_nd operator /(T x) const
			{
				vector_unit_nd y = *this;
				y /= x;
				return y;
			}

			template<typename T, typename = typename enable_if<is_integer_number<T>::value>::type>
			vector_unit_nd operator ^(T x) const
			{
				return vector_unit_nd(std::pow(get_value(),x),power_dimensions(get_dimensions(),x),angles);
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

			inline bool is_nd(unsigned int i) const
			{
				return angles.size() == (i - 1);
			}
			
			inline int get_nd() const
			{
				return int(angles.size() + 1);
			}

			scalar_unit n_projection(int i) const;
			scalar_unit x_projection() const;
			scalar_unit y_projection() const;
			scalar_unit z_projection() const;

			void invert();

			string vectorial_display(int number_of_decimals = 2) const;
			string vectorial_base_display(int number_of_decimals = 2) const;
			string vectorial_custom_display(const string& init_dimensions,int number_of_decimals = 2) const;

			vector<angle> angles;

		protected:
			void initialize_from_string(string init_vector_nd);
	};

	string to_string(const vector_unit_nd& x);
	scalar_unit norm(const vector_unit_nd& x);
	vector_unit_nd sqrt(const vector_unit_nd& x);
	vector_unit_nd sqrt_nth(const vector_unit_nd& x,int index);
	scalar_unit dot_product(const vector_unit_nd& x,const vector_unit_nd& y);
	vector_unit_nd cross_product(const vector_unit_nd& x,const vector_unit_nd& y);
	angle angle_between(const vector_unit_nd& x,const vector_unit_nd& y);
	bool same_nd(const vector_unit_nd& x,const vector_unit_nd& y);
	bool same_direction(const vector_unit_nd& x,const vector_unit_nd& y);
	bool parallel(const vector_unit_nd& x,const vector_unit_nd& y);
	bool orthogonal(const vector_unit_nd& x,const vector_unit_nd& y);
}

scifir::vector_unit_nd operator *(const scifir::scalar_unit& x,const scifir::vector_unit_nd& y);

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::vector_unit_nd operator +(const T y,const scifir::vector_unit_nd& x)
{
	scifir::vector_unit_nd z = x;
	z += y;
	return z;
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::vector_unit_nd operator -(const T y,const scifir::vector_unit_nd& x)
{
	return scifir::vector_unit_nd(y - x.get_value(),x.get_dimensions(),x.angles);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::vector_unit_nd operator *(const T y,const scifir::vector_unit_nd& x)
{
	scifir::vector_unit_nd z = x;
	z *= y;
	return z;
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::vector_unit_nd operator /(const T y,const scifir::vector_unit_nd& x)
{
	vector<scifir::dimension> new_dimensions = x.get_dimensions();
	for (scifir::dimension& new_dimension : new_dimensions)
	{
		new_dimension.invert();
	}
	return scifir::vector_unit_nd(y / x.get_value(),new_dimensions,x.angles);
}

bool operator !=(const scifir::vector_unit_nd& x, const scifir::vector_unit_nd& y);

bool operator ==(const scifir::vector_unit_nd& x, const string& init_vector_nd);
bool operator !=(const scifir::vector_unit_nd& x, const string& init_vector_nd);

bool operator ==(const string& init_vector_nd, const scifir::vector_unit_nd& x);
bool operator !=(const string& init_vector_nd, const scifir::vector_unit_nd& x);

void operator +=(string& x, const scifir::vector_unit_nd& y);
string operator +(const string& x, const scifir::vector_unit_nd& y);
string operator +(const scifir::vector_unit_nd& y, const string& x);

ostream& operator <<(ostream& os, const scifir::vector_unit_nd& x);
istream& operator >>(istream& is, scifir::vector_unit_nd& x);

#endif // SCIFIR_UNITS_UNITS_VECTOR_UNIT_ND_HPP_INCLUDED
 
