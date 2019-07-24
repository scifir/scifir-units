#ifndef VECTORIAL_UNIT_HPP_INCLUDED
#define VECTORIAL_UNIT_HPP_INCLUDED

#include "msci/units/units/scalar_unit.hpp"
#include "msci/units/meca_number/angle.hpp"
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

#define VECTOR_UNIT_HPP_BEGIN(name) class name : public vector_unit_3d \
	{	\
		public: \
			name(); \
			name(const name&); \
			name(name&&); \
			explicit name(float,const string&); \
			explicit name(const scalar_unit&,direction_symbol); \
			explicit name(const scalar_unit&,float); \
			explicit name(const scalar_unit&,float,float); \
			explicit name(const scalar_unit&,msci::angle_container); \
			explicit name(scalar_unit&&,direction_symbol); \
			explicit name(scalar_unit&&,float); \
			explicit name(scalar_unit&&,float,float); \
			explicit name(scalar_unit&&,msci::angle_container); \
			explicit name(const scalar_unit&,direction_symbol,const string&); \
			explicit name(const scalar_unit&,float,const string&); \
			explicit name(const scalar_unit&,float,float,const string&); \
			explicit name(const scalar_unit&,msci::angle_container,const string&); \
			explicit name(scalar_unit&&,direction_symbol,const string&); \
			explicit name(scalar_unit&&,float,const string&); \
			explicit name(scalar_unit&&,float,float,const string&); \
			explicit name(scalar_unit&&,msci::angle_container,const string&); \
			explicit name(const string&,direction_symbol); \
			explicit name(const string&,float); \
			explicit name(const string&,float,float); \
			explicit name(const string&,msci::angle_container); \
			name(const vector_unit_3d&); \
			name(vector_unit_3d&&); \
\

#define	VECTOR_UNIT_HPP_END() public: \
		static const string dimensions_match; \
		static const vector<dimension> real_dimensions; \
	}

#define VECTOR_UNIT_HPP(name) class name : public vector_unit_3d \
	{	\
		public: \
			name(); \
			name(const name&); \
			name(name&&); \
			explicit name(float,const string&); \
			explicit name(const scalar_unit&,direction_symbol); \
			explicit name(const scalar_unit&,float); \
			explicit name(const scalar_unit&,float,float); \
			explicit name(const scalar_unit&,msci::angle_container); \
			explicit name(scalar_unit&&,direction_symbol); \
			explicit name(scalar_unit&&,float); \
			explicit name(scalar_unit&&,float,float); \
			explicit name(scalar_unit&&,msci::angle_container); \
			explicit name(const scalar_unit&,direction_symbol,const string&); \
			explicit name(const scalar_unit&,float,const string&); \
			explicit name(const scalar_unit&,float,float,const string&); \
			explicit name(const scalar_unit&,msci::angle_container,const string&); \
			explicit name(scalar_unit&&,direction_symbol,const string&); \
			explicit name(scalar_unit&&,float,const string&); \
			explicit name(scalar_unit&&,float,float,const string&); \
			explicit name(scalar_unit&&,msci::angle_container,const string&); \
			explicit name(const string&,direction_symbol); \
			explicit name(const string&,float); \
			explicit name(const string&,float,float); \
			explicit name(const string&,msci::angle_container); \
			name(const vector_unit_3d&); \
			name(vector_unit_3d&&); \
\
			static const string dimensions_match; \
			static const vector<dimension> real_dimensions; \
	}

#define VECTOR_UNIT_CPP(name,dimensions) name::name() : vector_unit_3d() \
			{ \
			} \
\
			name::name(const name& x) : vector_unit_3d(x) \
			{ \
			} \
\
			name::name(name&& x) : vector_unit_3d(move(x)) \
			{ \
			} \
\
			name::name(float new_value,const string& init_value) : vector_unit_3d(new_value,init_value) \
			{ \
			} \
\
			name::name(const scalar_unit& new_value,direction_symbol new_direction) : vector_unit_3d(new_value,new_direction) \
			{ \
			} \
\
			name::name(const scalar_unit& new_value,float new_angle1) : vector_unit_3d(new_value,new_angle1) \
			{ \
			} \
\
			name::name(const scalar_unit& new_value,float new_angle1,float new_angle2) : vector_unit_3d(new_value,new_angle1,new_angle2) \
			{ \
			} \
\
			name::name(const scalar_unit& new_value,msci::angle_container new_angles) : vector_unit_3d(new_value,new_angles) \
			{ \
			} \
\
			name::name(scalar_unit&& new_value,direction_symbol new_direction) : vector_unit_3d(move(new_value),new_direction) \
			{ \
			} \
\
			name::name(scalar_unit&& new_value,float new_angle1) : vector_unit_3d(move(new_value),new_angle1) \
			{ \
			} \
\
			name::name(scalar_unit&& new_value,float new_angle1,float new_angle2) : vector_unit_3d(move(new_value),new_angle1,new_angle2) \
			{ \
			} \
\
			name::name(scalar_unit&& new_value,msci::angle_container new_angles) : vector_unit_3d(move(new_value),new_angles) \
			{ \
			} \
\
			name::name(const scalar_unit& new_value,direction_symbol new_direction, const string& init_value) : vector_unit_3d(new_value,new_direction,init_value) \
			{ \
			} \
\
			name::name(const scalar_unit& new_value,float new_angle1, const string& init_value) : vector_unit_3d(new_value,new_angle1,init_value) \
			{ \
			} \
\
			name::name(const scalar_unit& new_value,float new_angle1,float new_angle2, const string& init_value) : vector_unit_3d(new_value,new_angle1,new_angle2,init_value) \
			{ \
			} \
\
			name::name(const scalar_unit& new_value,msci::angle_container new_angles, const string& init_value) : vector_unit_3d(new_value,new_angles,init_value) \
			{ \
			} \
\
			name::name(scalar_unit&& new_value,direction_symbol new_direction, const string& init_value) : vector_unit_3d(move(new_value),new_direction,init_value) \
			{ \
			} \
\
			name::name(scalar_unit&& new_value,float new_angle1, const string& init_value) : vector_unit_3d(move(new_value),new_angle1,init_value) \
			{ \
			} \
\
			name::name(scalar_unit&& new_value,float new_angle1,float new_angle2, const string& init_value) : vector_unit_3d(move(new_value),new_angle1,new_angle2,init_value) \
			{ \
			} \
\
			name::name(scalar_unit&& new_value,msci::angle_container new_angles, const string& init_value) : vector_unit_3d(move(new_value),new_angles,init_value) \
			{ \
			} \
\
			name::name(const string& init_value,direction_symbol new_direction) : vector_unit_3d(init_value,new_direction) \
			{ \
			} \
\
			name::name(const string& init_value,float new_angle1) : vector_unit_3d(init_value,new_angle1) \
			{ \
			} \
\
			name::name(const string& init_value,float new_angle1,float new_angle2) : vector_unit_3d(init_value,new_angle1,new_angle2) \
			{ \
			} \
\
			name::name(const string& init_value,msci::angle_container new_angles) : vector_unit_3d(init_value,new_angles) \
			{ \
			} \
\
			name::name(const vector_unit_3d& x) : vector_unit_3d(x) \
			{ \
			} \
\
			name::name(vector_unit_3d&& x) : vector_unit_3d(move(x)) \
			{ \
			} \
\
const string name::dimensions_match = dimensions; \
const vector<dimension> name::real_dimensions = create_derived_dimensions(dimensions)

using namespace std;
using namespace msci;

namespace msci
{
	class auto_vector;

	class vector_unit_3d : public scalar_unit
	{
		public:
			vector_unit_3d();
			vector_unit_3d(const vector_unit_3d&);
			vector_unit_3d(vector_unit_3d&&);
			explicit vector_unit_3d(float,const string&);
			explicit vector_unit_3d(const scalar_unit&,direction_symbol);
			explicit vector_unit_3d(const scalar_unit&,float);
			explicit vector_unit_3d(const scalar_unit&,float,float);
			explicit vector_unit_3d(const scalar_unit&,msci::angle_container);
			explicit vector_unit_3d(scalar_unit&&,direction_symbol);
			explicit vector_unit_3d(scalar_unit&&,float);
			explicit vector_unit_3d(scalar_unit&&,float,float);
			explicit vector_unit_3d(scalar_unit&&,msci::angle_container);
			explicit vector_unit_3d(const scalar_unit&,direction_symbol,const string&);
			explicit vector_unit_3d(const scalar_unit&,float,const string&);
			explicit vector_unit_3d(const scalar_unit&,float,float,const string&);
			explicit vector_unit_3d(const scalar_unit&,msci::angle_container,const string&);
			explicit vector_unit_3d(scalar_unit&&,direction_symbol,const string&);
			explicit vector_unit_3d(scalar_unit&&,float,const string&);
			explicit vector_unit_3d(scalar_unit&&,float,float,const string&);
			explicit vector_unit_3d(scalar_unit&&,msci::angle_container,const string&);
			explicit vector_unit_3d(const string&,direction_symbol);
			explicit vector_unit_3d(const string&,float);
			explicit vector_unit_3d(const string&,float,float);
			explicit vector_unit_3d(const string&,msci::angle_container);

			vector_unit_3d& operator =(const vector_unit_3d&);
			vector_unit_3d& operator =(vector_unit_3d&&);
			vector_unit_3d& operator =(const scalar_unit&);
			vector_unit_3d& operator =(scalar_unit&&);

			void point_to(direction_symbol);

			/*virtual unit* clone() const
			{
				return new T(static_cast<const T&>(*this));
			}*/

			vector_unit_3d operator +(const vector_unit_3d&) const;
			vector_unit_3d operator -(const vector_unit_3d&) const;
			void operator +=(const vector_unit_3d&);
			void operator -=(const vector_unit_3d&);

			vector_unit_3d operator *(const scalar_unit&) const;
			vector_unit_3d operator /(const scalar_unit&) const;
			vector_unit_3d operator ^(const scalar_unit&) const;

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			vector_unit_3d operator +(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			vector_unit_3d operator -(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			vector_unit_3d operator *(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			vector_unit_3d operator /(U) const;
			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			vector_unit_3d operator ^(U) const;

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
					for(msci::angle& angle : coord.get_directions().angles)
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
					for(msci::angle& angle : coord.get_directions().angles)
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

			inline const msci::angle& get_angle1() const
			{
				return coord.get_angle1();
			}

			inline const msci::angle& get_angle2() const
			{
				return coord.get_angle2();
			}

			inline const msci::angle& get_angle(unsigned int i) const
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

			inline float x_projection() const
			{
				return coord.x_projection();
			}

			inline float y_projection() const
			{
				return coord.y_projection();
			}

			inline float z_projection() const
			{
				return coord.z_projection();
			}

			inline void invert()
			{
				coord.invert();
			}

		private:
			inline function<float()> lambda_value()
			{
				return [this]()
				{
					return scalar_unit::value.get_value();
				};
			}

			hyper_spherical_coordinates coord;
	};

	scalar_unit norm(const vector_unit_3d&);
	vector_unit_3d sqrt(const vector_unit_3d&);
	vector_unit_3d sqrt_nth(const vector_unit_3d&,int);
	scalar_unit dot_product(const vector_unit_3d&,const vector_unit_3d&);
	vector_unit_3d cross_product(const vector_unit_3d&,const vector_unit_3d&);
	msci::angle angle_between_vectors(const vector_unit_3d&,const vector_unit_3d&);
	bool same_nd(const vector_unit_3d&,const vector_unit_3d&);
	bool same_direction(const vector_unit_3d&,const vector_unit_3d&);
	bool parallel(const vector_unit_3d&,const vector_unit_3d&);
	bool orthogonal(const vector_unit_3d&,const vector_unit_3d&);
}

bool operator ==(const msci::vector_unit_3d&,const msci::vector_unit_3d&);
bool operator !=(const msci::vector_unit_3d&,const msci::vector_unit_3d&);
void operator +=(string&,const msci::vector_unit_3d&);
string operator +(const string&,const msci::vector_unit_3d&);
string operator +(const msci::vector_unit_3d&,const string&);
ostream& operator <<(ostream&,const msci::vector_unit_3d&);
istream& operator >>(istream&,msci::vector_unit_3d&);

#endif // VECTORIAL_UNIT_HPP_INCLUDED
