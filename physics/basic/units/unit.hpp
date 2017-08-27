#ifndef UNIT_BASE_HPP_
#define UNIT_BASE_HPP_

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include "abbreviation.hpp"
#include "dimension.hpp"
#include "dimension_container.hpp"
#include "prefix.hpp"
#include "math/number/unit_number.hpp"
#include "informatics/types/is_number.hpp"
using namespace std;

namespace physics::units
{
	class auto_unit;

	class unit
	{
		public:
			unit();
			explicit unit(math::space_type, string = "");
			explicit unit(math::unit_number, const vector_actual_dimensions&);
			explicit unit(const unit&,string);
			explicit unit(const auto_unit&,string);
			explicit unit(string);
			unit(const unit&);

			void operator =(const unit&);

			auto_unit operator +(const unit&) const;
			auto_unit operator -(const unit&) const;
			auto_unit operator *(const unit&) const;
			auto_unit operator /(const unit&) const;
			auto_unit operator ^(const unit&) const;
			void operator +=(const unit&);
			void operator -=(const unit&);

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			auto_unit operator +(T y) const;
			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			auto_unit operator -(T y) const;
			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			auto_unit operator *(T y) const;
			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			auto_unit operator /(T y) const;
			template<typename T, typename = typename enable_if<is_integer_number<T>::value>::type>
			auto_unit operator ^(T y) const;

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
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator /=(T y)
			{
				value /= y;
			}

			template<typename T, typename = typename enable_if<is_integer_number<T>::value>::type>
			void operator ^=(T y)
			{
				value = value ^ y;
			}

			unit& operator++();
			unit& operator++(int);
			unit& operator--();
			unit& operator--(int);

			void change_dimensions(string);
			bool equal_dimensions(string) const;
			bool equal_dimensions(dimension_symbol) const;
			bool equal_dimensions(const vector_real_dimensions&) const;
			bool empty_dimensions() const;
			void set_same_prefix(const vector_actual_dimensions&);

			virtual string get_dimensions_match() const = 0;
			virtual vector_real_dimensions get_real_dimensions() const = 0;
			const vector_actual_dimensions& get_actual_dimensions() const;
			virtual const math::unit_number& get_value() const;

			bool is_defined() const;
			void invalidate(int);

		protected:
			math::unit_number value;
			vector_actual_dimensions actual_dimensions;

			string initial_dimensions_get_structure(string) const;

		private:
			void add_prefix(shared_ptr<prefix>,float);
			void add_prefix(dimension_prefixes,float);
			void remove_prefix(shared_ptr<prefix>,float);
			void remove_prefix(dimension_prefixes,float);

			void initialize_dimensions(string);
	};

	template<typename T>
	class unit_crtp : public virtual unit
	{
		public:
			unit_crtp(const unit& new_unit) : unit(new_unit)
			{
				if(!new_unit.equal_dimensions(get_dimensions_match()))
				{
					unit::invalidate(7);
				}
			}

			explicit unit_crtp(math::space_type new_value, string init_value) : unit(new_value,init_value)
			{
			}

			explicit unit_crtp(const unit& new_unit,string init_value) : unit(new_unit,init_value)
			{
				if(!new_unit.equal_dimensions(get_dimensions_match()))
				{
					unit::invalidate(7);
				}
			}

			explicit unit_crtp(string init_value) : unit(init_value)
			{
			}

			unit_crtp(const unit_crtp<T>& x) : unit(x)
			{
			}

			virtual T* clone() const
			{
				return new T(static_cast<const T&>(*this));
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

	math::space_type abs(const unit&);
	auto_unit sqrt(const unit&);
	auto_unit sqrt_nth(const unit&, int);
	bool equal_dimensions(const unit&,const unit&);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
math::unit_number operator ^(T x, const physics::units::unit& y)
{
	if(y.empty_dimensions())
	{
		return math::unit_number(pow(x, y.get_value().get_value()));
	}
	else
	{
		return 0;
	}
}

bool operator ==(const physics::units::unit&, const physics::units::unit&);
bool operator !=(const physics::units::unit&, const physics::units::unit&);
bool operator <(const physics::units::unit&, const physics::units::unit&);
bool operator >(const physics::units::unit&, const physics::units::unit&);
bool operator <=(const physics::units::unit&, const physics::units::unit&);
bool operator >=(const physics::units::unit&, const physics::units::unit&);

bool operator ==(const physics::units::unit&, string);
bool operator !=(const physics::units::unit&, string);
bool operator <(const physics::units::unit&, string);
bool operator >(const physics::units::unit&, string);
bool operator <=(const physics::units::unit&, string);
bool operator >=(const physics::units::unit&, string);

bool operator ==(string, const physics::units::unit&);
bool operator !=(string, const physics::units::unit&);
bool operator <(string, const physics::units::unit&);
bool operator >(string, const physics::units::unit&);
bool operator <=(string, const physics::units::unit&);
bool operator >=(string, const physics::units::unit&);

void operator +=(wstring&, const physics::units::unit&);
wstring operator +(const wstring&, const physics::units::unit&);
wstring operator +(const physics::units::unit&, const wstring&);

wostream& operator <<(wostream&, const physics::units::unit&);
istream& operator >>(istream&, physics::units::unit&);

#endif
