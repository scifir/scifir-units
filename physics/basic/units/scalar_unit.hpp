#ifndef SCALAR_UNIT_HPP_INCLUDED
#define SCALAR_UNIT_HPP_INCLUDED

#include "unit.hpp"

#include <type_traits>

using namespace std;

namespace physics::units
{
	template<typename T>
	class scalar_unit : public unit_crtp<T>
	{
		public:
			scalar_unit() : unit_crtp<T>()
			{
			}

			scalar_unit(math::topology::space_type new_value, string init_value) : unit_crtp<T>(new_value, init_value)
			{
			}

			/*scalar_unit(math::topology::space_type new_value, dimension_symbol dimension_name, prefix_symbol prefix_name) : unit_crtp<T>(new_value, dimension_name, prefix_name)
			{
			}*/

			explicit scalar_unit(string init_value) : unit_crtp<T>(init_value)
			{
			}

			scalar_unit(const unit& new_unit) : unit_crtp<T>(new_unit)
			{
				/*wcout << "this: " << *this << endl;
				wcout << "new unit: " << new_unit << endl;*/
				if(!new_unit.equal_dimensions(unit_crtp<T>::get_dimensions_match()))
				{
					throw invalid_argument("a scalar unit can only be initialized by other scalar units of the same real dimensions");
				}
			}

			scalar_unit(const unit& new_value,string init_value) : unit_crtp<T>(new_value, init_value)
			{
				wcout << "hello!" << endl;
			}

			template<typename U>
			scalar_unit(const scalar_unit<U>& x)
			{
				*this = x;
			}

			template<typename U>
			void operator =(const scalar_unit<U>& x)
			{
				if(x.is_defined())
				{
					if(x.equal_dimensions(unit_crtp<T>::get_dimensions_match()))
					{
						unit::value = x.get_value();
						unit::actual_dimensions = x.get_actual_dimensions();
						unit::real_dimensions = x.get_real_dimensions();
					}
					else
					{
						unit::invalidate(7);
					}
				}
				else
				{
					unit::invalidate(1);
				}
			}

			template<typename U>
			U operator +(const scalar_unit<U>& x)
			{
				return U(unit::operator+(x));
			}

			template<typename U>
			U operator -(const scalar_unit<U>& x)
			{
				return U(unit::operator-(x));
			}

			template<typename U>
			unit operator *(const scalar_unit<U>& x)
			{
				return unit(unit::operator*(x));
			}

			template<typename U>
			unit operator /(const scalar_unit<U>& x)
			{
				return unit(unit::operator/(x));
			}

			template<typename U>
			unit operator ^(const scalar_unit<U>& x)
			{
				return unit(unit::operator^(x));
			}

			template<typename U>
			void operator +=(const scalar_unit<U>& x)
			{
				unit::operator+=(x);
			}

			template<typename U>
			void operator -=(const scalar_unit<U>& x)
			{
				unit::operator-=(x);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator =(U y)
			{
				unit::value = y;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			T operator +(U y)
			{
				T z = *this;
				z += y;
				return z;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			T operator -(U y)
			{
				T z = *this;
				z -= y;
				return z;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			T operator *(U y)
			{
				T z = *this;
				z *= y;
				return z;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			T operator /(U y)
			{
				T z = *this;
				z /= y;
				return z;
			}

			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			T operator ^(U y)
			{
				T a = unit::operator^(y);
				return a;
			}

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
}

#endif // SCALAR_UNIT_HPP_INCLUDED
