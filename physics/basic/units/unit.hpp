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
	class unit
	{
		public:
			unit();
			unit(math::topology::space_type, string = "");
			//unit(math::topology::space_type, dimension_symbol = m, prefix_symbol = normal_prefix);
			unit(math::number::unit_number, unit_real_dimensions, const unit_actual_dimensions&);
			explicit unit(string);

			unit operator +(const unit&);
			unit operator -(const unit&);
			unit operator *(const unit&);
			unit operator /(const unit&);
			unit operator ^(const unit&);
			void operator +=(const unit&);
			void operator -=(const unit&);

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator =(T y)
			{
				value = y;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			unit operator +(T y)
			{
				unit z = *this;
				z += y;
				return move(z);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			unit operator -(T y)
			{
				unit z = *this;
				z -= y;
				return move(z);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			unit operator *(T y)
			{
				unit z = *this;
				z *= y;
				return move(z);
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			unit operator /(T y)
			{
				unit z = *this;
				z /= y;
				return move(z);
			}

			template<typename T, typename = typename enable_if<is_integer_number<T>::value>::type>
			unit operator ^(T y)
			{
				math::number::unit_number new_value = value ^ y;
				unit_real_dimensions new_real_dimensions = real_dimensions;
				for(auto& new_real_dimension : new_real_dimensions)
				{
					*new_real_dimension.second ^= y;
				}
				unit_actual_dimensions new_actual_dimensions = actual_dimensions;
				for(const auto& new_actual_dimension : new_actual_dimensions)
				{
					*new_actual_dimension.second ^= y;
				}
				return move(unit(new_value, new_real_dimensions, new_actual_dimensions));
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
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator /=(T y)
			{
				value /= y;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator ^=(T y)
			{
				value = value ^ y;
			}

			unit& operator++();
			unit operator++(int);
			unit& operator--();
			unit operator--(int);

			void dimensions(string);
			bool equal_dimensions(string) const;
			bool equal_dimensions(dimension_symbol) const;
			bool equal_dimensions(const unit_real_dimensions&) const;
			bool empty_dimensions() const;
			void set_same_prefix(const unit_actual_dimensions&);

			const unit_real_dimensions& get_real_dimensions() const;
			const unit_actual_dimensions& get_actual_dimensions() const;
			const math::number::unit_number& get_value() const;

			bool is_defined() const;
			void invalidate(int);

			[[deprecated]]
			void set_prefix(prefix_symbol);

			[[deprecated]]
			void set_prefix(dimension_symbol, prefix_symbol);

			[[deprecated]]
			void add_abbreviation(abbreviation_symbol);

			[[deprecated]]
			void add_abbreviation(abbreviation_symbol, prefix_symbol);

			[[deprecated]]
			void change_abbreviation(abbreviation_symbol, abbreviation_symbol);

			[[deprecated]]
			bool valid_abbreviation(shared_ptr<abbreviation>);

			[[deprecated]]
			bool valid_abbreviation_real(shared_ptr<abbreviation>);

		protected:
			math::number::unit_number value;
			unit_real_dimensions real_dimensions;
			unit_actual_dimensions actual_dimensions;

		private:
			void add_prefix(shared_ptr<prefix>);
			void add_prefix(dimension_prefixes);
			void remove_prefix(shared_ptr<prefix>);
			void remove_prefix(dimension_prefixes);

			void initialize_dimensions(string);
			unit_real_dimensions create_real_dimensions(string) const;
			unit_actual_dimensions create_actual_dimensions(string) const;

			[[deprecated]]
			void swap_prefix(shared_ptr<dimension_abstract>, shared_ptr<dimension_abstract>);

			[[deprecated]]
			void swap_prefix(prefix_symbol, prefix_symbol);

			[[deprecated]]
			void add_internal_abbreviation(abbreviation_symbol);

			[[deprecated]]
			void delete_internal_abbreviation(abbreviation_symbol);
	};

	template<typename T>
	class unit_crtp : public unit
	{
		public:
			unit_crtp() : unit()
			{
			}

			unit_crtp(math::topology::space_type new_value, string dimension_structure) : unit(new_value, dimension_structure)
			{
			}

			/*unit_crtp(math::topology::space_type new_value, dimension_symbol dimension_name, prefix_symbol prefix_name) : unit(new_value, dimension_name, prefix_name)
			{
			}*/

			unit_crtp(math::number::unit_number new_value, unit_real_dimensions new_real_dimensions, const unit_actual_dimensions& new_actual_dimensions) : unit(new_value, new_real_dimensions, new_actual_dimensions)
			{
			}

			unit_crtp(string init_value) : unit(init_value)
			{
			}

			unit_crtp(const unit& new_unit) : unit(new_unit)
			{
			}

			unit_crtp(const unit& new_value,string init_value) : unit(new_value, init_value)
			{
			}

			virtual T* clone() const
			{
				return new T(static_cast<const T&>(*this));
			}

			virtual const string& get_dimensions_match() const
			{
				return T::dimensions_match;
			}
	};

	/*bool equal_dimensions(const unit&,const unit&);
	bool equal_dimensions(const unit_real_dimensions&,const unit_real_dimensions&);*/

	math::topology::space_type abs(const unit&);
	physics::units::unit sqrt(const unit&);
	physics::units::unit sqrt_nth(const unit&, int);
	bool equal_dimensions(const unit&,const unit&);

	[[deprecated]]
	unit get_unit_from_dimensions(math::topology::space_type, unit_real_dimensions);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
physics::units::unit operator +(T x, const physics::units::unit& y)
{
	math::number::unit_number new_value = y.get_value();
	physics::units::unit_real_dimensions new_real_dimensions = y.get_real_dimensions();
	physics::units::unit_actual_dimensions new_actual_dimensions = y.get_actual_dimensions();
	return physics::units::unit(x + new_value, new_real_dimensions, new_actual_dimensions);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
physics::units::unit operator -(T x, const physics::units::unit& y)
{
	math::number::unit_number new_value = y.get_value();
	physics::units::unit_real_dimensions new_real_dimensions = y.get_real_dimensions();
	physics::units::unit_actual_dimensions new_actual_dimensions = y.get_actual_dimensions();
	return physics::units::unit(x - new_value, new_real_dimensions, new_actual_dimensions);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
physics::units::unit operator *(T x, const physics::units::unit& y)
{
	math::number::unit_number new_value = y.get_value();
	physics::units::unit_real_dimensions new_real_dimensions = y.get_real_dimensions();
	physics::units::unit_actual_dimensions new_actual_dimensions = y.get_actual_dimensions();
	return physics::units::unit(x * new_value, new_real_dimensions, new_actual_dimensions);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
physics::units::unit operator /(T x, const physics::units::unit& y)
{
	math::number::unit_number new_value = y.get_value();
	physics::units::unit_real_dimensions new_real_dimensions = y.get_real_dimensions();
	physics::units::unit_actual_dimensions new_actual_dimensions = y.get_actual_dimensions();
	return physics::units::unit(x / new_value, new_real_dimensions, new_actual_dimensions);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
math::number::unit_number operator ^(T x, const physics::units::unit& y)
{
	if(y.empty_dimensions())
	{
		return math::number::unit_number(pow(x, y.get_value().get_value()));
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

void operator +=(wstring&, const physics::units::unit&);
wstring operator +(const wstring&, const physics::units::unit&);
wstring operator +(const physics::units::unit&, const wstring&);

wostream& operator <<(wostream&, const physics::units::unit&);
istream& operator >>(istream&, physics::units::unit&);

#endif
