#ifndef VECTORIAL_UNIT_HPP_INCLUDED
#define VECTORIAL_UNIT_HPP_INCLUDED

#include "msci/units/units/dimension_container.hpp"
#include "msci/units/units/scalar_unit.hpp"
#include "msci/units/meca_number/angle_number.hpp"
#include "msci/units/topology/topology.hpp"
#include "msci/units/coordinates/hyper_spherical_coordinates.hpp"
#include "msci/units/coordinates/coordinates_2d.hpp"
#include "msci/units/util/is_number.hpp"

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
			explicit name(const scalar_unit&,direction_symbol); \
			explicit name(const scalar_unit&,angle_type); \
			explicit name(const scalar_unit&,angle_type,angle_type); \
			explicit name(const scalar_unit&,msci::angle_container); \
			explicit name(scalar_unit&&,direction_symbol); \
			explicit name(scalar_unit&&,angle_type); \
			explicit name(scalar_unit&&,angle_type,angle_type); \
			explicit name(scalar_unit&&,msci::angle_container); \
			explicit name(const scalar_unit&,direction_symbol,const string&); \
			explicit name(const scalar_unit&,angle_type,const string&); \
			explicit name(const scalar_unit&,angle_type,angle_type,const string&); \
			explicit name(const scalar_unit&,msci::angle_container,const string&); \
			explicit name(scalar_unit&&,direction_symbol,const string&); \
			explicit name(scalar_unit&&,angle_type,const string&); \
			explicit name(scalar_unit&&,angle_type,angle_type,const string&); \
			explicit name(scalar_unit&&,msci::angle_container,const string&); \
			explicit name(const string&,direction_symbol); \
			explicit name(const string&,angle_type); \
			explicit name(const string&,angle_type,angle_type); \
			explicit name(const string&,msci::angle_container); \
			name(const vector_unit&); \
			name(vector_unit&&); \
\

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
			explicit name(const scalar_unit&,direction_symbol); \
			explicit name(const scalar_unit&,angle_type); \
			explicit name(const scalar_unit&,angle_type,angle_type); \
			explicit name(const scalar_unit&,msci::angle_container); \
			explicit name(scalar_unit&&,direction_symbol); \
			explicit name(scalar_unit&&,angle_type); \
			explicit name(scalar_unit&&,angle_type,angle_type); \
			explicit name(scalar_unit&&,msci::angle_container); \
			explicit name(const scalar_unit&,direction_symbol,const string&); \
			explicit name(const scalar_unit&,angle_type,const string&); \
			explicit name(const scalar_unit&,angle_type,angle_type,const string&); \
			explicit name(const scalar_unit&,msci::angle_container,const string&); \
			explicit name(scalar_unit&&,direction_symbol,const string&); \
			explicit name(scalar_unit&&,angle_type,const string&); \
			explicit name(scalar_unit&&,angle_type,angle_type,const string&); \
			explicit name(scalar_unit&&,msci::angle_container,const string&); \
			explicit name(const string&,direction_symbol); \
			explicit name(const string&,angle_type); \
			explicit name(const string&,angle_type,angle_type); \
			explicit name(const string&,msci::angle_container); \
			name(const vector_unit&); \
			name(vector_unit&&); \
\
			static const string dimensions_match; \
			static const vector_real_dimensions real_dimensions; \
	}

#define VECTOR_UNIT_CPP(name,dimensions) name::name() : vector_unit_crtp<name>() \
			{ \
			} \
\
			name::name(const name& x) : vector_unit_crtp<name>(x) \
			{ \
			} \
\
			name::name(name&& x) : vector_unit_crtp<name>(move(x)) \
			{ \
			} \
\
			name::name(msci::space_type new_value,const string& init_value) : vector_unit_crtp<name>(new_value,init_value) \
			{ \
			} \
\
			name::name(const scalar_unit& new_value,direction_symbol new_direction) : vector_unit_crtp<name>(new_value,new_direction) \
			{ \
			} \
\
			name::name(const scalar_unit& new_value,angle_type new_angle1) : vector_unit_crtp<name>(new_value,new_angle1) \
			{ \
			} \
\
			name::name(const scalar_unit& new_value,angle_type new_angle1,angle_type new_angle2) : vector_unit_crtp<name>(new_value,new_angle1,new_angle2) \
			{ \
			} \
\
			name::name(const scalar_unit& new_value,msci::angle_container new_angles) : vector_unit_crtp<name>(new_value,new_angles) \
			{ \
			} \
\
			name::name(scalar_unit&& new_value,direction_symbol new_direction) : vector_unit_crtp<name>(move(new_value),new_direction) \
			{ \
			} \
\
			name::name(scalar_unit&& new_value,angle_type new_angle1) : vector_unit_crtp<name>(move(new_value),new_angle1) \
			{ \
			} \
\
			name::name(scalar_unit&& new_value,angle_type new_angle1,angle_type new_angle2) : vector_unit_crtp<name>(move(new_value),new_angle1,new_angle2) \
			{ \
			} \
\
			name::name(scalar_unit&& new_value,msci::angle_container new_angles) : vector_unit_crtp<name>(move(new_value),new_angles) \
			{ \
			} \
\
			name::name(const scalar_unit& new_value,direction_symbol new_direction, const string& init_value) : vector_unit_crtp<name>(new_value,new_direction,init_value) \
			{ \
			} \
\
			name::name(const scalar_unit& new_value,angle_type new_angle1, const string& init_value) : vector_unit_crtp<name>(new_value,new_angle1,init_value) \
			{ \
			} \
\
			name::name(const scalar_unit& new_value,angle_type new_angle1,angle_type new_angle2, const string& init_value) : vector_unit_crtp<name>(new_value,new_angle1,new_angle2,init_value) \
			{ \
			} \
\
			name::name(const scalar_unit& new_value,msci::angle_container new_angles, const string& init_value) : vector_unit_crtp<name>(new_value,new_angles,init_value) \
			{ \
			} \
\
			name::name(scalar_unit&& new_value,direction_symbol new_direction, const string& init_value) : vector_unit_crtp<name>(move(new_value),new_direction,init_value) \
			{ \
			} \
\
			name::name(scalar_unit&& new_value,angle_type new_angle1, const string& init_value) : vector_unit_crtp<name>(move(new_value),new_angle1,init_value) \
			{ \
			} \
\
			name::name(scalar_unit&& new_value,angle_type new_angle1,angle_type new_angle2, const string& init_value) : vector_unit_crtp<name>(move(new_value),new_angle1,new_angle2,init_value) \
			{ \
			} \
\
			name::name(scalar_unit&& new_value,msci::angle_container new_angles, const string& init_value) : vector_unit_crtp<name>(move(new_value),new_angles,init_value) \
			{ \
			} \
\
			name::name(const string& init_value,direction_symbol new_direction) : vector_unit_crtp<name>(init_value,new_direction) \
			{ \
			} \
\
			name::name(const string& init_value,angle_type new_angle1) : vector_unit_crtp<name>(init_value,new_angle1) \
			{ \
			} \
\
			name::name(const string& init_value,angle_type new_angle1,angle_type new_angle2) : vector_unit_crtp<name>(init_value,new_angle1,new_angle2) \
			{ \
			} \
\
			name::name(const string& init_value,msci::angle_container new_angles) : vector_unit_crtp<name>(init_value,new_angles) \
			{ \
			} \
\
			name::name(const vector_unit& x) : vector_unit_crtp<name>(x) \
			{ \
			} \
\
			name::name(vector_unit&& x) : vector_unit_crtp<name>(move(x)) \
			{ \
			} \
\
const string name::dimensions_match = dimensions; \
const vector_real_dimensions name::real_dimensions = create_real_dimensions(dimensions)

using namespace std;
using namespace msci;

namespace msci
{
	class auto_vector;

	class vector_unit : public scalar_unit
	{
		public:
			vector_unit();
			vector_unit(const vector_unit&);
			vector_unit(vector_unit&&);
			explicit vector_unit(msci::space_type,const string&);
			explicit vector_unit(const scalar_unit&,direction_symbol);
			explicit vector_unit(const scalar_unit&,angle_type);
			explicit vector_unit(const scalar_unit&,angle_type,angle_type);
			explicit vector_unit(const scalar_unit&,msci::angle_container);
			explicit vector_unit(scalar_unit&&,direction_symbol);
			explicit vector_unit(scalar_unit&&,angle_type);
			explicit vector_unit(scalar_unit&&,angle_type,angle_type);
			explicit vector_unit(scalar_unit&&,msci::angle_container);
			explicit vector_unit(const scalar_unit&,direction_symbol,const string&);
			explicit vector_unit(const scalar_unit&,angle_type,const string&);
			explicit vector_unit(const scalar_unit&,angle_type,angle_type,const string&);
			explicit vector_unit(const scalar_unit&,msci::angle_container,const string&);
			explicit vector_unit(scalar_unit&&,direction_symbol,const string&);
			explicit vector_unit(scalar_unit&&,angle_type,const string&);
			explicit vector_unit(scalar_unit&&,angle_type,angle_type,const string&);
			explicit vector_unit(scalar_unit&&,msci::angle_container,const string&);
			explicit vector_unit(const string&,direction_symbol);
			explicit vector_unit(const string&,angle_type);
			explicit vector_unit(const string&,angle_type,angle_type);
			explicit vector_unit(const string&,msci::angle_container);

			vector_unit& operator =(const vector_unit&);
			vector_unit& operator =(vector_unit&&);
			vector_unit& operator =(const scalar_unit&);
			vector_unit& operator =(scalar_unit&&);

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
					for(msci::angle_number& angle : coord.get_directions().angles)
					{
						angle *= -1;
					}
				}
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator /=(U y)
			{
				scalar_unit::value /= y;
				if(y < 0)
				{
					for(msci::angle_number& angle : coord.get_directions().angles)
					{
						angle *= -1;
					}
				}
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator ^=(U y)
			{
				scalar_unit::value ^= y;
			}

			inline hyper_spherical_coordinates& get_coordinates()
			{
				return coord;
			}

			inline const hyper_spherical_coordinates& get_coordinates() const
			{
				return coord;
			}

			inline const msci::angle_number& get_angle1() const
			{
				return coord.get_angle1();
			}

			inline const msci::angle_number& get_angle2() const
			{
				return coord.get_angle2();
			}

			inline const msci::angle_number& get_angle(unsigned int i) const
			{
				return coord.get_angle(i);
			}

			inline const angle_container& get_angles() const
			{
				return coord.get_angles();
			}

			inline const direction_lr& get_direction() const
			{
				return coord.get_direction();
			}

			inline const bool& is_1d() const
			{
				return coord.is_1d();
			}

			inline bool is_2d() const
			{
				return coord.is_2d();
			}

			inline bool is_3d() const
			{
				return coord.is_3d();
			}

			inline space_type x_projection() const
			{
				return coord.x_projection();
			}

			inline space_type y_projection() const
			{
				return coord.y_projection();
			}

			inline space_type z_projection() const
			{
				return coord.z_projection();
			}

			inline void invert()
			{
				coord.invert();
			}

		private:
			inline function<space_type()> lambda_value()
			{
				return [this]()
				{
					return scalar_unit::value.get_value();
				};
			}

			hyper_spherical_coordinates coord;
	};

	template<typename T>
	class vector_unit_crtp : public vector_unit
	{
		public:
			vector_unit_crtp() : vector_unit()
			{
			}

			vector_unit_crtp(const vector_unit_crtp<T>& x) : vector_unit(x)
			{
			}

			vector_unit_crtp(vector_unit_crtp<T>&& x) : vector_unit(move(x))
			{
			}

			explicit vector_unit_crtp(msci::space_type new_value,const string& init_value) : vector_unit(new_value,init_value)
			{
			}

			explicit vector_unit_crtp(const scalar_unit& new_value,direction_symbol new_direction) : vector_unit(new_value,new_direction)
			{
			}

			explicit vector_unit_crtp(const scalar_unit& new_value,angle_type new_angle1) : vector_unit(new_value,new_angle1)
			{
			}

			explicit vector_unit_crtp(const scalar_unit& new_value,angle_type new_angle1,angle_type new_angle2) : vector_unit(new_value,new_angle1,new_angle2)
			{
			}

			explicit vector_unit_crtp(const scalar_unit& new_value,msci::angle_container new_angles) : vector_unit(new_value,new_angles)
			{
			}

			explicit vector_unit_crtp(scalar_unit&& new_value,direction_symbol new_direction) : vector_unit(move(new_value),new_direction)
			{
			}

			explicit vector_unit_crtp(scalar_unit&& new_value,angle_type new_angle1) : vector_unit(move(new_value),new_angle1)
			{
			}

			explicit vector_unit_crtp(scalar_unit&& new_value,angle_type new_angle1,angle_type new_angle2) : vector_unit(move(new_value),new_angle1,new_angle2)
			{
			}

			explicit vector_unit_crtp(scalar_unit&& new_value,msci::angle_container new_angles) : vector_unit(move(new_value),new_angles)
			{
			}

			explicit vector_unit_crtp(const scalar_unit& new_value,direction_symbol new_direction, const string& init_value) : vector_unit(new_value,new_direction,init_value)
			{
			}

			explicit vector_unit_crtp(const scalar_unit& new_value,angle_type new_angle1, const string& init_value) : vector_unit(new_value,new_angle1,init_value)
			{
			}

			explicit vector_unit_crtp(const scalar_unit& new_value,angle_type new_angle1,angle_type new_angle2, const string& init_value) : vector_unit(new_value,new_angle1,new_angle2,init_value)
			{
			}

			explicit vector_unit_crtp(const scalar_unit& new_value,msci::angle_container new_angles, const string& init_value) : vector_unit(new_value,new_angles,init_value)
			{
			}

			explicit vector_unit_crtp(scalar_unit&& new_value,direction_symbol new_direction, const string& init_value) : vector_unit(move(new_value),new_direction,init_value)
			{
			}

			explicit vector_unit_crtp(scalar_unit&& new_value,angle_type new_angle1, const string& init_value) : vector_unit(move(new_value),new_angle1,init_value)
			{
			}

			explicit vector_unit_crtp(scalar_unit&& new_value,angle_type new_angle1,angle_type new_angle2, const string& init_value) : vector_unit(move(new_value),new_angle1,new_angle2,init_value)
			{
			}

			explicit vector_unit_crtp(scalar_unit&& new_value,msci::angle_container new_angles, const string& init_value) : vector_unit(move(new_value),new_angles,init_value)
			{
			}

			explicit vector_unit_crtp(const string& init_value,direction_symbol new_direction) : vector_unit(init_value,new_direction)
			{
			}

			explicit vector_unit_crtp(const string& init_value,angle_type new_angle1) : vector_unit(init_value,new_angle1)
			{
			}

			explicit vector_unit_crtp(const string& init_value,angle_type new_angle1,angle_type new_angle2) : vector_unit(init_value,new_angle1,new_angle2)
			{
			}

			explicit vector_unit_crtp(const string& init_value,msci::angle_container new_angles) : vector_unit(init_value,new_angles)
			{
			}

			vector_unit_crtp(const vector_unit& x) : vector_unit(x)
			{
			}

			vector_unit_crtp(vector_unit&& x) : vector_unit(move(x))
			{
			}

			/*vector_unit_crtp<T>& operator =(const vector_unit_crtp<T>& x)
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
			}*/

			virtual scalar_unit* clone() const
			{
				return new T(dynamic_cast<const T&>(*this));
			}

			virtual string get_dimensions_match() const
			{
				return T::dimensions_match;
			}

			virtual vector_real_dimensions get_real_dimensions() const
			{
				return T::real_dimensions;
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
