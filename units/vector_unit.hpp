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

#define VECTOR_UNIT_HPP_BEGIN(name) class name : public vector_unit_crtp<name> \
	{	\
		public: \
			name(); \
			name(const name&); \
			name(name&&); \
			explicit name(msci::space_type,const string&); \
			explicit name(const unit&,direction_symbol); \
			explicit name(const unit&,angle_type); \
			explicit name(const unit&,angle_type,angle_type); \
			explicit name(const unit&,msci::angle_container); \
			explicit name(unit&&,direction_symbol); \
			explicit name(unit&&,angle_type); \
			explicit name(unit&&,angle_type,angle_type); \
			explicit name(unit&&,msci::angle_container); \
			explicit name(const unit&,direction_symbol,const string&); \
			explicit name(const unit&,angle_type,const string&); \
			explicit name(const unit&,angle_type,angle_type,const string&); \
			explicit name(const unit&,msci::angle_container,const string&); \
			explicit name(unit&&,direction_symbol,const string&); \
			explicit name(unit&&,angle_type,const string&); \
			explicit name(unit&&,angle_type,angle_type,const string&); \
			explicit name(unit&&,msci::angle_container,const string&); \
			explicit name(const string&,direction_symbol); \
			explicit name(const string&,angle_type); \
			explicit name(const string&,angle_type,angle_type); \
			explicit name(const string&,msci::angle_container); \
			name(const vector_unit&); \
			name(vector_unit&&); \
\
			name& operator =(const name&); \
			name& operator =(name&&); \
			name& operator =(const vector_unit&); \
			name& operator =(vector_unit&&); \
			name& operator =(const unit&); \
			name& operator =(unit&&)

#define	VECTOR_UNIT_HPP_END() public: \
		static const string dimensions_match; \
		static const vector_real_dimensions real_dimensions; \
	}

#define VECTOR_UNIT_HPP(name) class name : public vector_unit_crtp<name> \
	{	\
		public: \
			name(); \
			name(const name&); \
			name(name&&); \
			explicit name(msci::space_type,const string&); \
			explicit name(const unit&,direction_symbol); \
			explicit name(const unit&,angle_type); \
			explicit name(const unit&,angle_type,angle_type); \
			explicit name(const unit&,msci::angle_container); \
			explicit name(unit&&,direction_symbol); \
			explicit name(unit&&,angle_type); \
			explicit name(unit&&,angle_type,angle_type); \
			explicit name(unit&&,msci::angle_container); \
			explicit name(const unit&,direction_symbol,const string&); \
			explicit name(const unit&,angle_type,const string&); \
			explicit name(const unit&,angle_type,angle_type,const string&); \
			explicit name(const unit&,msci::angle_container,const string&); \
			explicit name(unit&&,direction_symbol,const string&); \
			explicit name(unit&&,angle_type,const string&); \
			explicit name(unit&&,angle_type,angle_type,const string&); \
			explicit name(unit&&,msci::angle_container,const string&); \
			explicit name(const string&,direction_symbol); \
			explicit name(const string&,angle_type); \
			explicit name(const string&,angle_type,angle_type); \
			explicit name(const string&,msci::angle_container); \
			name(const vector_unit&); \
			name(vector_unit&&); \
\
			name& operator =(const name&); \
			name& operator =(name&&); \
			name& operator =(const vector_unit&); \
			name& operator =(vector_unit&&); \
			name& operator =(const unit&); \
			name& operator =(unit&&); \
\
			static const string dimensions_match; \
			static const vector_real_dimensions real_dimensions; \
	}

#define VECTOR_UNIT_CPP(name,dimensions) name::name() : unit(),vector_unit_crtp<name>() \
			{ \
			} \
\
			name::name(const name& x) : unit(x),vector_unit_crtp<name>(x) \
			{ \
			} \
\
			name::name(name&& x) : unit(move(x)),vector_unit_crtp<name>(move(x)) \
			{ \
			} \
\
			name::name(msci::space_type new_value,const string& init_value) : unit(new_value,init_value),vector_unit_crtp<name>(new_value,init_value) \
			{ \
			} \
\
			name::name(const unit& new_value,direction_symbol new_direction) : unit(new_value),vector_unit_crtp<name>(new_value,new_direction) \
			{ \
			} \
\
			name::name(const unit& new_value,angle_type new_angle1) : unit(new_value),vector_unit_crtp<name>(new_value,new_angle1) \
			{ \
			} \
\
			name::name(const unit& new_value,angle_type new_angle1,angle_type new_angle2) : unit(new_value),vector_unit_crtp<name>(new_value,new_angle1,new_angle2) \
			{ \
			} \
\
			name::name(const unit& new_value,msci::angle_container new_angles) : unit(new_value),vector_unit_crtp<name>(new_value,new_angles) \
			{ \
			} \
\
			name::name(unit&& new_value,direction_symbol new_direction) : unit(move(new_value)),vector_unit_crtp<name>(move(new_value),new_direction) \
			{ \
			} \
\
			name::name(unit&& new_value,angle_type new_angle1) : unit(move(new_value)),vector_unit_crtp<name>(move(new_value),new_angle1) \
			{ \
			} \
\
			name::name(unit&& new_value,angle_type new_angle1,angle_type new_angle2) : unit(move(new_value)),vector_unit_crtp<name>(move(new_value),new_angle1,new_angle2) \
			{ \
			} \
\
			name::name(unit&& new_value,msci::angle_container new_angles) : unit(move(new_value)),vector_unit_crtp<name>(move(new_value),new_angles) \
			{ \
			} \
\
			name::name(const unit& new_value,direction_symbol new_direction, const string& init_value) : unit(new_value,init_value),vector_unit_crtp<name>(new_value,new_direction,init_value) \
			{ \
			} \
\
			name::name(const unit& new_value,angle_type new_angle1, const string& init_value) : unit(new_value,init_value),vector_unit_crtp<name>(new_value,new_angle1,init_value) \
			{ \
			} \
\
			name::name(const unit& new_value,angle_type new_angle1,angle_type new_angle2, const string& init_value) : unit(new_value,init_value),vector_unit_crtp<name>(new_value,new_angle1,new_angle2,init_value) \
			{ \
			} \
\
			name::name(const unit& new_value,msci::angle_container new_angles, const string& init_value) : unit(new_value,init_value),vector_unit_crtp<name>(new_value,new_angles,init_value) \
			{ \
			} \
\
			name::name(unit&& new_value,direction_symbol new_direction, const string& init_value) : unit(move(new_value),init_value),vector_unit_crtp<name>(move(new_value),new_direction,init_value) \
			{ \
			} \
\
			name::name(unit&& new_value,angle_type new_angle1, const string& init_value) : unit(move(new_value),init_value),vector_unit_crtp<name>(move(new_value),new_angle1,init_value) \
			{ \
			} \
\
			name::name(unit&& new_value,angle_type new_angle1,angle_type new_angle2, const string& init_value) : unit(move(new_value),init_value),vector_unit_crtp<name>(move(new_value),new_angle1,new_angle2,init_value) \
			{ \
			} \
\
			name::name(unit&& new_value,msci::angle_container new_angles, const string& init_value) : unit(move(new_value),init_value),vector_unit_crtp<name>(move(new_value),new_angles,init_value) \
			{ \
			} \
\
			name::name(const string& init_value,direction_symbol new_direction) : unit(init_value),vector_unit_crtp<name>(init_value,new_direction) \
			{ \
			} \
\
			name::name(const string& init_value,angle_type new_angle1) : unit(init_value),vector_unit_crtp<name>(init_value,new_angle1) \
			{ \
			} \
\
			name::name(const string& init_value,angle_type new_angle1,angle_type new_angle2) : unit(init_value),vector_unit_crtp<name>(init_value,new_angle1,new_angle2) \
			{ \
			} \
\
			name::name(const string& init_value,msci::angle_container new_angles) : unit(init_value),vector_unit_crtp<name>(init_value,new_angles) \
			{ \
			} \
\
			name::name(const vector_unit& x) : unit(x),vector_unit_crtp<name>(x) \
			{ \
			} \
\
			name::name(vector_unit&& x) : unit(move(x)),vector_unit_crtp<name>(move(x)) \
			{ \
			} \
\
			name& name::operator =(const name& x) \
			{ \
				vector_unit_crtp<name>::operator=(x); \
				return *this; \
			} \
\
			name& name::operator =(name&& x) \
			{ \
				vector_unit_crtp<name>::operator=(move(x)); \
				return *this; \
			} \
\
			name& name::operator =(const vector_unit& x) \
			{ \
				vector_unit::operator=(x); \
				return *this; \
			} \
\
			name& name::operator =(vector_unit&& x) \
			{ \
				vector_unit::operator=(move(x)); \
				return *this; \
			} \
\
			name& name::operator =(const unit& x) \
			{ \
				unit::operator=(x); \
				return *this; \
			} \
\
			name& name::operator =(unit&& x) \
			{ \
				unit::operator=(move(x)); \
				return *this; \
			} \
\
const string name::dimensions_match = dimensions; \
const vector_real_dimensions name::real_dimensions = create_real_dimensions(dimensions)

using namespace std;
using namespace msci;

namespace msci
{
	class auto_vector;

	class vector_unit : public virtual unit, public hyper_spherical_coordinates
	{
		public:
			vector_unit();
			vector_unit(const vector_unit&);
			vector_unit(vector_unit&&);
			explicit vector_unit(msci::space_type,const string&);
			explicit vector_unit(const unit&,direction_symbol);
			explicit vector_unit(const unit&,angle_type);
			explicit vector_unit(const unit&,angle_type,angle_type);
			explicit vector_unit(const unit&,msci::angle_container);
			explicit vector_unit(unit&&,direction_symbol);
			explicit vector_unit(unit&&,angle_type);
			explicit vector_unit(unit&&,angle_type,angle_type);
			explicit vector_unit(unit&&,msci::angle_container);
			explicit vector_unit(const unit&,direction_symbol,const string&);
			explicit vector_unit(const unit&,angle_type,const string&);
			explicit vector_unit(const unit&,angle_type,angle_type,const string&);
			explicit vector_unit(const unit&,msci::angle_container,const string&);
			explicit vector_unit(unit&&,direction_symbol,const string&);
			explicit vector_unit(unit&&,angle_type,const string&);
			explicit vector_unit(unit&&,angle_type,angle_type,const string&);
			explicit vector_unit(unit&&,msci::angle_container,const string&);
			explicit vector_unit(const string&,direction_symbol);
			explicit vector_unit(const string&,angle_type);
			explicit vector_unit(const string&,angle_type,angle_type);
			explicit vector_unit(const string&,msci::angle_container);

			vector_unit& operator =(const vector_unit&);
			vector_unit& operator =(vector_unit&&);
			vector_unit& operator =(const unit&);
			vector_unit& operator =(unit&&);

			void point_to(direction_symbol);

			/*virtual unit* clone() const
			{
				return new T(static_cast<const T&>(*this));
			}*/

			auto_vector operator +(const vector_unit&) const;
			auto_vector operator -(const vector_unit&) const;
			void operator +=(const vector_unit&);
			void operator -=(const vector_unit&);

			auto_vector operator *(const scalar_unit&) const;
			auto_vector operator /(const scalar_unit&) const;
			auto_vector operator ^(const scalar_unit&) const;

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_vector operator +(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_vector operator -(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_vector operator *(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_vector operator /(U) const;
			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			auto_vector operator ^(U) const;

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
					for(msci::angle_number& angle : directions.angles)
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
					for(msci::angle_number& angle : directions.angles)
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
	class vector_unit_crtp : public unit_crtp<T>,public vector_unit
	{
		public:
			vector_unit_crtp() : unit(),unit_crtp<T>(),vector_unit()
			{
			}

			vector_unit_crtp(const vector_unit_crtp<T>& x) : unit(x),unit_crtp<T>(x),vector_unit(x)
			{
			}

			vector_unit_crtp(vector_unit_crtp<T>&& x) : unit(move(x)),unit_crtp<T>(move(x)),vector_unit(move(x))
			{
			}

			explicit vector_unit_crtp(msci::space_type new_value,const string& init_value) : unit(new_value,init_value),unit_crtp<T>(new_value,init_value),vector_unit(new_value,init_value)
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

			explicit vector_unit_crtp(const unit& new_value,msci::angle_container new_angles) : unit(new_value),unit_crtp<T>(new_value),vector_unit(new_value,new_angles)
			{
			}

			explicit vector_unit_crtp(unit&& new_value,direction_symbol new_direction) : unit(move(new_value)),unit_crtp<T>(move(new_value)),vector_unit(move(new_value),new_direction)
			{
			}

			explicit vector_unit_crtp(unit&& new_value,angle_type new_angle1) : unit(move(new_value)),unit_crtp<T>(move(new_value)),vector_unit(move(new_value),new_angle1)
			{
			}

			explicit vector_unit_crtp(unit&& new_value,angle_type new_angle1,angle_type new_angle2) : unit(move(new_value)),unit_crtp<T>(move(new_value)),vector_unit(move(new_value),new_angle1,new_angle2)
			{
			}

			explicit vector_unit_crtp(unit&& new_value,msci::angle_container new_angles) : unit(move(new_value)),unit_crtp<T>(move(new_value)),vector_unit(move(new_value),new_angles)
			{
			}

			explicit vector_unit_crtp(const unit& new_value,direction_symbol new_direction, const string& init_value) : unit(new_value,init_value),unit_crtp<T>(new_value,init_value),vector_unit(new_value,new_direction,init_value)
			{
			}

			explicit vector_unit_crtp(const unit& new_value,angle_type new_angle1, const string& init_value) : unit(new_value,init_value),unit_crtp<T>(new_value,init_value),vector_unit(new_value,new_angle1,init_value)
			{
			}

			explicit vector_unit_crtp(const unit& new_value,angle_type new_angle1,angle_type new_angle2, const string& init_value) : unit(new_value,init_value),unit_crtp<T>(new_value,init_value),vector_unit(new_value,new_angle1,new_angle2,init_value)
			{
			}

			explicit vector_unit_crtp(const unit& new_value,msci::angle_container new_angles, const string& init_value) : unit(new_value,init_value),unit_crtp<T>(new_value,init_value),vector_unit(new_value,new_angles,init_value)
			{
			}

			explicit vector_unit_crtp(unit&& new_value,direction_symbol new_direction, const string& init_value) : unit(move(new_value),init_value),unit_crtp<T>(move(new_value),init_value),vector_unit(move(new_value),new_direction,init_value)
			{
			}

			explicit vector_unit_crtp(unit&& new_value,angle_type new_angle1, const string& init_value) : unit(move(new_value),init_value),unit_crtp<T>(move(new_value),init_value),vector_unit(move(new_value),new_angle1,init_value)
			{
			}

			explicit vector_unit_crtp(unit&& new_value,angle_type new_angle1,angle_type new_angle2, const string& init_value) : unit(move(new_value),init_value),unit_crtp<T>(move(new_value),init_value),vector_unit(move(new_value),new_angle1,new_angle2,init_value)
			{
			}

			explicit vector_unit_crtp(unit&& new_value,msci::angle_container new_angles, const string& init_value) : unit(move(new_value),init_value),unit_crtp<T>(move(new_value),init_value),vector_unit(move(new_value),new_angles,init_value)
			{
			}

			explicit vector_unit_crtp(const string& init_value,direction_symbol new_direction) : unit(init_value),unit_crtp<T>(init_value),vector_unit(init_value,new_direction)
			{
			}

			explicit vector_unit_crtp(const string& init_value,angle_type new_angle1) : unit(init_value),unit_crtp<T>(init_value),vector_unit(init_value,new_angle1)
			{
			}

			explicit vector_unit_crtp(const string& init_value,angle_type new_angle1,angle_type new_angle2) : unit(init_value),unit_crtp<T>(init_value),vector_unit(init_value,new_angle1,new_angle2)
			{
			}

			explicit vector_unit_crtp(const string& init_value,msci::angle_container new_angles) : unit(init_value),unit_crtp<T>(init_value),vector_unit(init_value,new_angles)
			{
			}

			vector_unit_crtp(const vector_unit& x) : unit(x),unit_crtp<T>(x),vector_unit(x)
			{
			}

			vector_unit_crtp(vector_unit&& x) : unit(move(x)),unit_crtp<T>(move(x)),vector_unit(move(x))
			{
			}

			vector_unit_crtp<T>& operator =(const vector_unit_crtp<T>& x)
			{
				vector_unit::operator =(x);
				return *this;
			}

			vector_unit_crtp<T>& operator =(vector_unit_crtp<T>&& x)
			{
				vector_unit::operator =(move(x));
				return *this;
			}

			vector_unit_crtp<T>& operator =(const vector_unit& x)
			{
				vector_unit::operator =(x);
				return *this;
			}

			vector_unit_crtp<T>& operator =(vector_unit&& x)
			{
				vector_unit::operator =(move(x));
				return *this;
			}

			vector_unit_crtp<T>& operator =(const unit& x)
			{
				unit::operator =(x);
				return *this;
			}

			vector_unit_crtp<T>& operator =(unit&& x)
			{
				unit::operator =(move(x));
				return *this;
			}

			auto_vector operator +(const vector_unit&) const;
			auto_vector operator -(const vector_unit&) const;

			void operator +=(const vector_unit& x)
			{
				vector_unit::operator+=(x);
			}

			void operator -=(const vector_unit& x)
			{
				vector_unit::operator-=(x);
			}

			auto_vector operator *(const scalar_unit&) const;
			auto_vector operator /(const scalar_unit&) const;
			auto_vector operator ^(const scalar_unit&) const;

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_vector operator +(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_vector operator -(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_vector operator *(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_vector operator /(U) const;
			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			auto_vector operator ^(U) const;

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator +=(U y)
			{
				vector_unit::operator+=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator -=(U y)
			{
				vector_unit::operator-=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator *=(U y)
			{
				vector_unit::operator*=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator /=(U y)
			{
				vector_unit::operator/=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator ^=(U y)
			{
				vector_unit::operator^=(y);
			}
	};

	auto_scalar norm(const vector_unit&);
	auto_vector sqrt(const vector_unit&);
	auto_vector sqrt_nth(const vector_unit&,int);
	auto_scalar dot_product(const vector_unit&,const vector_unit&);
	auto_vector cross_product(const vector_unit&,const vector_unit&);
	msci::angle_number angle_between_vectors(const vector_unit&,const vector_unit&);
	bool same_nd(const vector_unit&,const vector_unit&);
	bool same_direction(const vector_unit&,const vector_unit&);
	bool parallel(const vector_unit&,const vector_unit&);
	bool orthogonal(const vector_unit&,const vector_unit&);
}

bool operator ==(const msci::vector_unit&,const msci::vector_unit&);
bool operator !=(const msci::vector_unit&,const msci::vector_unit&);
void operator +=(string&,const msci::vector_unit&);
string operator +(const string&,const msci::vector_unit&);
string operator +(const msci::vector_unit&,const string&);
ostream& operator <<(ostream&,const msci::vector_unit&);
istream& operator >>(istream&,msci::vector_unit&);

#endif // VECTORIAL_UNIT_HPP_INCLUDED
