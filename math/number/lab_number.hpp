#ifndef LAB_UNIT_HPP_INCLUDED
#define LAB_UNIT_HPP_INCLUDED

#include "unit_number.hpp"

#include "math/topology/topology.hpp"
#include "informatics/types/is_number.hpp"

#include <cmath>
#include <string>

using namespace std;

namespace math
{
	class lab_number : public unit_number
	{
		public:
			lab_number();
			lab_number(math::space_type,math::space_type);

			const math::space_type& get_error_value() const;

			lab_number operator +(const lab_number&) const;
			lab_number operator -(const lab_number&) const;
			lab_number operator *(const lab_number&) const;
			lab_number operator /(const lab_number&) const;
			lab_number operator ^(const lab_number&) const;
			void operator +=(const lab_number&);
			void operator -=(const lab_number&);
			void operator *=(const lab_number&);
			void operator /=(const lab_number&);
			void operator ^=(const lab_number&);

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator =(T y)
			{
				value = y;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			lab_number operator +(T y) const
			{
				return lab_number(value + y,error_value);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			lab_number operator -(T y) const
			{
				return lab_number(value - y,error_value);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			lab_number operator *(T y) const
			{
				return lab_number(value * y,error_value * y);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			lab_number operator /(T y) const
			{
				return lab_number(value / y,error_value / y);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			lab_number operator ^(T y) const
			{
				return lab_number(std::pow(value, y),pow(error_value,y));
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator +=(T y)
			{
				value += y;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator -=(T y)
			{
				value -= y;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator *=(T y)
			{
				value *= y;
				error_value *= y;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator /=(T y)
			{
				value /= y;
				error_value /= y;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator ^=(T y)
			{
				value = std::pow(value, y);
				error_value = pow(error_value,y);
			}

			virtual wstring print() const override;

		private:
			math::space_type error_value;
	};
}

wostream& operator <<(wostream&, const math::lab_number&);

#endif // LAB_UNIT_HPP_INCLUDED
