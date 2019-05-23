#ifndef MSCI_UNITS_UNITS_UNIT_HPP
#define MSCI_UNITS_UNITS_UNIT_HPP

#include "msci/units/units/abbreviation.hpp"
#include "msci/units/units/dimension.hpp"
#include "msci/units/units/dimension_container.hpp"
#include "msci/units/units/prefix.hpp"
#include "msci/units/meca_number/unit_number.hpp"
#include "msci/units/util/is_number.hpp"

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

namespace msci
{
	class auto_unit;

	class unit
	{
		public:
			unit();
			unit(const unit&);
			unit(unit&&);
			explicit unit(msci::space_type, const string& = "");
			explicit unit(msci::unit_number, const vector_actual_dimensions&);
			explicit unit(const unit&,const string&);
			explicit unit(unit&&,const string&);
			explicit unit(const string&);

			unit& operator =(const unit&);
			unit& operator =(unit&&);

			virtual unit* clone() const = 0;

			explicit operator float() const;

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

			void change_dimensions(const string&);
			bool has_dimensions(const string&) const;
			bool has_dimensions(const vector_real_dimensions&) const;
			bool has_empty_dimensions() const;
			string display_dimensions() const;
			void set_same_prefix(const vector_actual_dimensions&);

			virtual string get_dimensions_match() const = 0;
			virtual vector_real_dimensions get_real_dimensions() const = 0;
			const vector_actual_dimensions& get_actual_dimensions() const;
			virtual const msci::unit_number& get_value() const;

			/// Returns true if it's defined
			inline bool is_defined() const
			{
				return value.is_defined();
			}

			/// Invalidates the unit for cases when there are errors
			inline void invalidate(int x)
			{
				value.invalidate(x);
			}

			string display(int = 2) const;

		protected:
			msci::unit_number value;
			vector_actual_dimensions actual_dimensions;

			string initial_dimensions_get_structure(const string&) const;

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
			unit_crtp() : unit()
			{
			}

			unit_crtp(const unit_crtp<T>& x) : unit(x)
			{
			}

			unit_crtp(unit_crtp<T>&& x) : unit(move(x))
			{
			}

			explicit unit_crtp(msci::space_type new_value, const string& init_value) : unit(new_value,init_value)
			{
			}

			explicit unit_crtp(const unit& new_unit,const string& init_value) : unit(new_unit,init_value)
			{
				if(!has_dimensions(init_value))
				{
					unit::invalidate(7);
				}
			}

			explicit unit_crtp(unit&& new_unit,const string& init_value) : unit(move(new_unit),init_value)
			{
				if(!has_dimensions(init_value))
				{
					unit::invalidate(7);
				}
			}

			explicit unit_crtp(const string& init_value) : unit(init_value)
			{
			}

			unit_crtp(const unit& new_unit) : unit(new_unit)
			{
				if(!new_unit.has_dimensions(get_dimensions_match()))
				{
					unit::invalidate(7);
				}
			}

			unit_crtp(unit&& new_unit) : unit(move(new_unit))
			{
				if(!new_unit.has_dimensions(get_dimensions_match()))
				{
					unit::invalidate(7);
				}
			}

			virtual unit* clone() const
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

	msci::space_type abs(const unit&);
	auto_unit sqrt(const unit&);
	auto_unit sqrt_nth(const unit&, int);
	bool equal_dimensions(const unit&,const unit&);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::unit_number operator ^(T x, const msci::unit& y)
{
	if(y.has_empty_dimensions())
	{
		return msci::unit_number(pow(x, y.get_value().get_value()));
	}
	else
	{
		return 0;
	}
}

bool operator ==(const msci::unit&, const msci::unit&);
bool operator !=(const msci::unit&, const msci::unit&);
bool operator <(const msci::unit&, const msci::unit&);
bool operator >(const msci::unit&, const msci::unit&);
bool operator <=(const msci::unit&, const msci::unit&);
bool operator >=(const msci::unit&, const msci::unit&);

bool operator ==(const msci::unit&, const string&);
bool operator !=(const msci::unit&, const string&);
bool operator <(const msci::unit&, const string&);
bool operator >(const msci::unit&, const string&);
bool operator <=(const msci::unit&, const string&);
bool operator >=(const msci::unit&, const string&);

bool operator ==(const string&, const msci::unit&);
bool operator !=(const string&, const msci::unit&);
bool operator <(const string&, const msci::unit&);
bool operator >(const string&, const msci::unit&);
bool operator <=(const string&, const msci::unit&);
bool operator >=(const string&, const msci::unit&);

void operator +=(string&, const msci::unit&);
string operator +(const string&, const msci::unit&);
string operator +(const msci::unit&, const string&);

ostream& operator <<(ostream&, const msci::unit&);
istream& operator >>(istream&, msci::unit&);

#endif
