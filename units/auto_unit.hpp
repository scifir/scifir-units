#ifndef PHYSICS_BASIC_UNITS_AUTO_UNIT_HPP_INCLUDED
#define PHYSICS_BASIC_UNITS_AUTO_UNIT_HPP_INCLUDED

#include "units/unit.hpp"

using namespace std;

namespace msci
{
	class auto_unit : public virtual unit
	{
		public:
			auto_unit();
			auto_unit(const auto_unit&);
			auto_unit(auto_unit&&);
			explicit auto_unit(msci::space_type, const string& = "");
			explicit auto_unit(msci::unit_number, const vector_real_dimensions&, const vector_actual_dimensions&);
			explicit auto_unit(const unit&,const string&);
			explicit auto_unit(unit&&,const string&);
			explicit auto_unit(const string&);
			auto_unit(const unit&);
			auto_unit(unit&&);

			auto_unit& operator =(const auto_unit&);
			auto_unit& operator =(auto_unit&&);
			auto_unit& operator =(const unit&);
			auto_unit& operator =(unit&&);

			auto_unit operator +(const auto_unit&) const;
			auto_unit operator -(const auto_unit&) const;
			auto_unit operator *(const auto_unit&) const;
			auto_unit operator /(const auto_unit&) const;
			auto_unit operator ^(const auto_unit&) const;
			void operator +=(const auto_unit&);
			void operator -=(const auto_unit&);

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_unit operator +(U x) const
			{
				return unit::operator+(x);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_unit operator -(U x) const
			{
				return unit::operator-(x);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_unit operator *(U x) const
			{
				return unit::operator*(x);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_unit operator /(U x) const
			{
				return unit::operator/(x);
			}

			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			auto_unit operator ^(U x) const
			{
				return unit::operator^(x);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator +=(U y)
			{
				unit::operator+=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator -=(U y)
			{
				unit::operator-=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator *=(U y)
			{
				unit::operator*=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator /=(U y)
			{
				unit::operator/=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator ^=(U y)
			{
				unit::operator^=(y);
			}

			virtual unit* clone() const;

			void initialize_real_dimensions(string);

			virtual string get_dimensions_match() const;
			virtual vector_real_dimensions get_real_dimensions() const;

		private:
			const vector_real_dimensions real_dimensions;
	};

	template<typename T, typename>
	auto_unit unit::operator +(T y) const
	{
		auto_unit z = *this;
		z += y;
		return move(z);
	}

	template<typename T, typename>
	auto_unit unit::operator -(T y) const
	{
		auto_unit z = *this;
		z -= y;
		return move(z);
	}

	template<typename T, typename>
	auto_unit unit::operator *(T y) const
	{
		auto_unit z = *this;
		z *= y;
		return move(z);
	}

	template<typename T, typename>
	auto_unit unit::operator /(T y) const
	{
		auto_unit z = *this;
		z /= y;
		return move(z);
	}

	template<typename T, typename>
	auto_unit unit::operator ^(T y) const
	{
		msci::unit_number new_value = value ^ y;
		vector_real_dimensions new_real_dimensions = power_real_dimensions(get_real_dimensions(),y);
		vector_actual_dimensions new_actual_dimensions = power_actual_dimensions(actual_dimensions,y);
		return move(auto_unit(new_value, new_real_dimensions, new_actual_dimensions));
	}
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_unit operator +(T x, const msci::unit& y)
{
	msci::unit_number new_value = y.get_value();
	msci::vector_real_dimensions new_real_dimensions = y.get_real_dimensions();
	msci::vector_actual_dimensions new_actual_dimensions = y.get_actual_dimensions();
	return msci::auto_unit(x + new_value, new_real_dimensions, new_actual_dimensions);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_unit operator -(T x, const msci::unit& y)
{
	msci::unit_number new_value = y.get_value();
	msci::vector_real_dimensions new_real_dimensions = y.get_real_dimensions();
	msci::vector_actual_dimensions new_actual_dimensions = y.get_actual_dimensions();
	return msci::auto_unit(x - new_value, new_real_dimensions, new_actual_dimensions);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_unit operator *(T x, const msci::unit& y)
{
	msci::unit_number new_value = y.get_value();
	msci::vector_real_dimensions new_real_dimensions = y.get_real_dimensions();
	msci::vector_actual_dimensions new_actual_dimensions = y.get_actual_dimensions();
	return msci::auto_unit(x * new_value, new_real_dimensions, new_actual_dimensions);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_unit operator /(T x, const msci::unit& y)
{
	msci::unit_number new_value = y.get_value();
	msci::vector_real_dimensions new_real_dimensions = power_real_dimensions(y.get_real_dimensions(),-1);
	msci::vector_actual_dimensions new_actual_dimensions = power_actual_dimensions(y.get_actual_dimensions(),-1);
	return msci::auto_unit(x / new_value, new_real_dimensions, new_actual_dimensions);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_unit operator ^(T x, const msci::unit& y)
{
	if (y.has_empty_dimensions())
	{
		msci::unit_number new_value = y.get_value();
		msci::vector_real_dimensions new_real_dimensions = power_real_dimensions(y.get_real_dimensions(),new_value);
		msci::vector_actual_dimensions new_actual_dimensions = power_actual_dimensions(y.get_actual_dimensions(),new_value);
		return msci::auto_unit(x ^ new_value, new_real_dimensions, new_actual_dimensions);
	}
	else
	{
		msci::auto_unit y = msci::auto_unit(0);
		y.invalidate(10);
		return move(y);
	}
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_unit operator +(T x, const msci::auto_unit& y)
{
	return x + static_cast<const msci::unit&>(y);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_unit operator -(T x, const msci::auto_unit& y)
{
	return x - static_cast<const msci::unit&>(y);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_unit operator *(T x, const msci::auto_unit& y)
{
	return x * static_cast<const msci::unit&>(y);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_unit operator /(T x, const msci::auto_unit& y)
{
	return x / static_cast<const msci::unit&>(y);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::auto_unit operator ^(T x, const msci::auto_unit& y)
{
	return x ^ static_cast<const msci::unit&>(y);
}

#endif // PHYSICS_BASIC_UNITS_AUTO_UNIT_HPP_INCLUDED
