#ifndef SCALAR_UNIT_HPP_INCLUDED
#define SCALAR_UNIT_HPP_INCLUDED

#include "unit.hpp"
#include "auto_unit.hpp"

#include <type_traits>

using namespace std;

namespace physics::units
{
	class auto_scalar;

	class scalar_unit : public virtual unit
	{
		public:
			scalar_unit(const unit&);
			explicit scalar_unit(math::topology::space_type,string);
			explicit scalar_unit(string);
			explicit scalar_unit(const unit&,string);

			void operator =(const scalar_unit&);
			auto_scalar operator +(const scalar_unit&);
			auto_scalar operator -(const scalar_unit&);
			auto_scalar operator *(const scalar_unit&);
			auto_scalar operator /(const scalar_unit&);
			auto_scalar operator ^(const scalar_unit&);
			void operator +=(const scalar_unit&);
			void operator -=(const scalar_unit&);

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_scalar operator +(U y);
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_scalar operator -(U y);
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_scalar operator *(U y);
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_scalar operator /(U y);
			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			auto_scalar operator ^(U y);

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
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator /=(U y)
			{
				unit::value /= y;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator ^=(U y)
			{
				unit::value = unit::value ^ y;
			}
	};

	template<typename T>
	class scalar_unit_crtp : public scalar_unit,public unit_crtp<T>
	{
		public:
			explicit scalar_unit_crtp(math::topology::space_type new_value,string init_value) : unit(new_value,init_value),unit_crtp<T>(new_value,init_value),scalar_unit(new_value,init_value)
			{
			}

			explicit scalar_unit_crtp(string init_value) : unit(init_value),unit_crtp<T>(init_value),scalar_unit(init_value)
			{
			}

			scalar_unit_crtp(const unit& new_unit) : unit(new_unit),unit_crtp<T>(new_unit),scalar_unit(new_unit)
			{
			}

			explicit scalar_unit_crtp(const unit& new_unit,string init_value) : unit(new_unit,init_value),unit_crtp<T>(new_unit,init_value),scalar_unit(new_unit,init_value)
			{
			}
	};
}

#endif // SCALAR_UNIT_HPP_INCLUDED
