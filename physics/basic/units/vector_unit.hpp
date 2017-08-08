#ifndef VECTORIAL_UNIT_HPP_INCLUDED
#define VECTORIAL_UNIT_HPP_INCLUDED

#include "dimension_container.hpp"
#include "unit.hpp"
#include "auto_unit.hpp"
#include "scalar_unit.hpp"
#include "math/number/angle_number.hpp"
#include "math/topology/topology.hpp"
#include "math/topology/coordinates/hyper_spherical_coordinates.hpp"
#include "math/topology/coordinates/coordinates_2d.hpp"
#include "informatics/types/is_number.hpp"

#include "boost/algorithm/string.hpp"
#include "boost/variant.hpp"

#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace math::topology;

namespace physics::units
{
	class auto_vector;

	class vector_unit : public virtual unit, public hyper_spherical_coordinates
	{
		public:
			vector_unit(const unit&);
			explicit vector_unit(const unit&,direction_symbol);
			explicit vector_unit(const unit&,angle_type);
			explicit vector_unit(const unit&,angle_type,angle_type);
			explicit vector_unit(const unit&,math::topology::angle_container);
			explicit vector_unit(string);
			explicit vector_unit(string,angle_type);
			explicit vector_unit(string,angle_type,angle_type);
			explicit vector_unit(string,math::topology::angle_container);
			vector_unit(const vector_unit&);
			/*vector_unit(vector_unit_tuple new_tuple) : unit_crtp<T>(move(get<0>(new_tuple))), hyper_spherical_coordinates(lambda_value(), move(boost::apply_visitor(
      [](auto val){ return hyper_spherical_coordinates(lambda_value(),val); },
		get<1>(new_tuple)
    )))*/

			/*vector_unit(vector_unit_tuple new_tuple) : unit_crtp<T>(move(get<0>(new_tuple))), hyper_spherical_coordinates(lambda_value(), get<1>(new_tuple))*/

			void operator =(const vector_unit&);

			void point_to(direction_symbol);

			/*virtual unit* clone() const
			{
				return new T(static_cast<const T&>(*this));
			}*/

			auto_vector operator +(const vector_unit&);
			auto_vector operator -(const vector_unit&);
			auto_vector operator *(const vector_unit&);
			void operator +=(const vector_unit&);
			void operator -=(const vector_unit&);

			auto_vector operator *(const scalar_unit&);
			auto_vector operator /(const scalar_unit&);
			auto_vector operator ^(const scalar_unit&);

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_vector operator +(U y);
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_vector operator -(U y);
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_vector operator *(U y);
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_vector operator /(U y);
			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			auto_vector operator ^(U);

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator +=(U y)
			{
				unit::value += y;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator -=(U y)
			{
				unit::value -= y;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator *=(U y)
			{
				unit::value *= y;
				if(y < 0)
				{
					for(math::number::angle_number& angle : directions.angles)
					{
						angle *= -1;
					}
				}
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator /=(U y)
			{
				unit::value /= y;
				if(y < 0)
				{
					for(math::number::angle_number& angle : directions.angles)
					{
						angle *= -1;
					}
				}
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator ^=(U y)
			{
				unit::value ^= y;
			}

		private:
			inline function<space_type()> lambda_value()
			{
				return [this]()
				{
					return unit::value.get_value();
				};
			}
	};

	template<typename T>
	class vector_unit_crtp : public vector_unit, public unit_crtp<T>
	{
		public:
			vector_unit_crtp(const unit& new_value) : unit(new_value),unit_crtp<T>(new_value),vector_unit(new_value)
			{
			}

			explicit vector_unit_crtp(const unit& new_value,direction_symbol new_direction) : unit(new_value),unit_crtp<T>(new_value),vector_unit(new_value,new_direction)
			{
			}

			explicit vector_unit_crtp(const unit& new_value,angle_type new_angle1) : unit(new_value),unit_crtp<T>(new_value),vector_unit(new_value,new_angle1)
			{
			}

			explicit vector_unit_crtp(const unit& new_value,angle_type new_angle1,angle_type new_angle2) : unit(new_value),unit_crtp<T>(new_value),vector_unit(new_value,new_angle1,new_angle2)
			{
			}

			explicit vector_unit_crtp(const unit& new_value,list<angle_type> new_angles) : unit(new_value),unit_crtp<T>(new_value),vector_unit(new_value,new_angles)
			{
			}

			explicit vector_unit_crtp(string init_value) : unit(init_value),unit_crtp<T>(init_value),vector_unit(init_value)
			{
			}

			explicit vector_unit_crtp(string init_value,angle_type new_angle1) : unit(init_value),unit_crtp<T>(init_value),vector_unit(init_value,new_angle1)
			{
			}

			explicit vector_unit_crtp(string init_value,angle_type new_angle1,angle_type new_angle2) : unit(init_value),unit_crtp<T>(init_value),vector_unit(init_value,new_angle1,new_angle2)
			{
			}

			explicit vector_unit_crtp(string init_value,list<angle_type> new_angles) : unit(init_value),unit_crtp<T>(init_value),vector_unit(init_value,new_angles)
			{
			}

			vector_unit_crtp(const vector_unit& x) : unit(x),unit_crtp<T>(x),vector_unit(x)
			{
			}
	};

	auto_vector sqrt(const vector_unit&);
	auto_vector sqrt_nth(const vector_unit&,int);
	auto_scalar dot_product(const vector_unit&,const vector_unit&);
	bool same_spacial_dimensions(const vector_unit&,const vector_unit&);
	bool same_direction(const vector_unit&,const vector_unit&);
	bool parallel(const vector_unit&,const vector_unit&);
	bool orthogonal(const vector_unit&,const vector_unit&);
}

bool operator ==(const physics::units::vector_unit&,const physics::units::vector_unit&);
bool operator !=(const physics::units::vector_unit&,const physics::units::vector_unit&);
void operator +=(wstring&,const physics::units::vector_unit&);
wstring operator +(const wstring&,const physics::units::vector_unit&);
wstring operator +(const physics::units::vector_unit&,const wstring&);
wostream& operator <<(wostream&,const physics::units::vector_unit&);
istream& operator >>(istream&,physics::units::vector_unit&);

#endif // VECTORIAL_UNIT_HPP_INCLUDED
