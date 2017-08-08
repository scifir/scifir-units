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
			explicit unit(math::topology::space_type, string = "");
			//unit(math::topology::space_type, dimension_symbol = m, prefix_symbol = normal_prefix);
			explicit unit(math::number::unit_number, vector_real_dimensions, const vector_actual_dimensions&); // TODO: check what to change here now that vector_real_dimensions is unneeded
			explicit unit(const unit&,string);
			explicit unit(const auto_unit&,string);
			explicit unit(string);

			auto_unit operator +(const unit&);
			auto_unit operator -(const unit&);
			auto_unit operator *(const unit&);
			auto_unit operator /(const unit&);
			auto_unit operator ^(const unit&);
			void operator +=(const unit&);
			void operator -=(const unit&);

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			auto_unit operator +(T y);
			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			auto_unit operator -(T y);
			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			auto_unit operator *(T y);
			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			auto_unit operator /(T y);
			template<typename T, typename = typename enable_if<is_integer_number<T>::value>::type>
			auto_unit operator ^(T y);

			/*template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator =(T y)
			{
				value = y;
			}*/

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
			virtual const math::number::unit_number& get_value() const;

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
			vector_actual_dimensions actual_dimensions;

			string initial_dimensions_get_structure(string) const;

		private:
			void add_prefix(shared_ptr<prefix>);
			void add_prefix(dimension_prefixes);
			void remove_prefix(shared_ptr<prefix>);
			void remove_prefix(dimension_prefixes);

			void initialize_dimensions(string);

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
	class unit_crtp : public virtual unit
	{
		public:
			//using unit::unit;

			unit_crtp(const unit& new_unit) : unit(new_unit)
			{
				if(!new_unit.equal_dimensions(get_dimensions_match()))
				{
					unit::invalidate(7);
				}
			}

			explicit unit_crtp(math::topology::space_type new_value, string init_value) : unit(new_value,init_value)
			{
				// TODO: finish this function
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
				// TODO: finish this function
			}

			/*unit_crtp() : unit()
			{
			}

			unit_crtp(math::topology::space_type new_value, string dimension_structure) : unit(new_value, dimension_structure)
			{
			}*/

			/*unit_crtp(math::topology::space_type new_value, dimension_symbol dimension_name, prefix_symbol prefix_name) : unit(new_value, dimension_name, prefix_name)
			{
			}*/

			/*unit_crtp(math::number::unit_number new_value, vector_real_dimensions new_real_dimensions, const vector_actual_dimensions& new_actual_dimensions) : unit(new_value, new_real_dimensions, new_actual_dimensions)
			{
			}

			unit_crtp(string init_value) : unit(init_value)
			{
			}

			unit_crtp(const unit& new_unit) : unit(new_unit)
			{
			}

			unit_crtp(const unit& new_value,string init_value) : unit(new_value,init_value)
			{
			}*/

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

	/*bool equal_dimensions(const unit&,const unit&);
	bool equal_dimensions(const vector_real_dimensions&,const vector_real_dimensions&);*/

	math::topology::space_type abs(const unit&);
	auto_unit sqrt(const unit&);
	auto_unit sqrt_nth(const unit&, int);
	bool equal_dimensions(const unit&,const unit&);

	//[[deprecated]]
	//unit* get_unit_from_dimensions(math::topology::space_type, vector_real_dimensions);
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
