#ifndef MSCI_scalar_unitS_scalar_unitS_scalar_unit_HPP
#define MSCI_scalar_unitS_scalar_unitS_scalar_unit_HPP

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

#define SCALAR_UNIT_HPP_BEGIN(name) class name : public scalar_unit_crtp<name> \
	{	\
		public: \
			name(); \
			name(const name&); \
			name(name&&); \
			explicit name(msci::space_type,const string&); \
			explicit name(const string&); \
			explicit name(const scalar_unit&,const string&); \
			explicit name(scalar_unit&&,const string&); \
			name(const scalar_unit&); \
			name(scalar_unit&&); \
\
			name& operator =(const name&); \
			name& operator =(name&&); \
			name& operator =(const scalar_unit&); \
			name& operator =(scalar_unit&&); \

#define SCALAR_UNIT_HPP_END() public: \
			static const string dimensions_match; \
			static const vector_real_dimensions real_dimensions; \
	}

#define SCALAR_UNIT_HPP(name) class name : public scalar_unit_crtp<name> \
	{	\
		public: \
			name(); \
			name(const name&); \
			name(name&&); \
			explicit name(msci::space_type,const string&); \
			explicit name(const string&); \
			explicit name(const scalar_unit&,const string&); \
			explicit name(scalar_unit&&,const string&); \
			name(const scalar_unit&); \
			name(scalar_unit&&); \
\
			name& operator =(const name&); \
			name& operator =(name&&); \
			name& operator =(const scalar_unit&); \
			name& operator =(scalar_unit&&); \
\
			static const string dimensions_match; \
			static const vector_real_dimensions real_dimensions; \
	}

#define SCALAR_UNIT_CPP(name,dimensions) name::name() : scalar_unit_crtp<name>() \
			{ \
			} \
\
	name::name(const name& x) : scalar_unit_crtp<name>(x) \
			{ \
			} \
\
	name::name(name&& x) : scalar_unit_crtp<name>(move(x)) \
			{ \
			} \
\
	name::name(msci::space_type new_value,const string& init_value) : scalar_unit_crtp<name>(new_value,init_value) \
			{ \
			} \
\
	name::name(const string& init_value) : scalar_unit_crtp<name>(init_value) \
			{ \
			} \
\
	name::name(const scalar_unit& new_unit) : scalar_unit_crtp<name>(new_unit) \
			{ \
			} \
\
	name::name(scalar_unit&& new_unit) : scalar_unit_crtp<name>(move(new_unit)) \
			{ \
			} \
\
	name::name(const scalar_unit& new_unit,const string& init_value) : scalar_unit_crtp<name>(new_unit,init_value) \
			{ \
			} \
\
	name::name(scalar_unit&& new_unit,const string& init_value) : scalar_unit_crtp<name>(move(new_unit),init_value) \
			{ \
			} \
\
	name& name::operator =(const name& x) \
	{ \
		scalar_unit_crtp<name>::operator=(x); \
		return *this; \
	} \
\
	name& name::operator =(name&& x) \
	{ \
		scalar_unit_crtp<name>::operator=(move(x)); \
		return *this; \
	} \
\
	name& name::operator =(const scalar_unit& x) \
	{ \
		scalar_unit::operator=(x); \
		return *this; \
	} \
\
	name& name::operator =(scalar_unit&& x) \
	{ \
		scalar_unit::operator=(move(x)); \
		return *this; \
	} \
const string name::dimensions_match = dimensions; \
const vector_real_dimensions name::real_dimensions = create_real_dimensions(dimensions)

using namespace std;

namespace msci
{
	class auto_scalar;

	class scalar_unit
	{
		public:
			scalar_unit();
			scalar_unit(const scalar_unit&);
			scalar_unit(scalar_unit&&);
			explicit scalar_unit(const unit_number&, const string& = "");
			explicit scalar_unit(const unit_number&, const vector_actual_dimensions&);
			explicit scalar_unit(const scalar_unit&,const string&);
			explicit scalar_unit(scalar_unit&&,const string&);
			explicit scalar_unit(const string&);

			scalar_unit& operator =(const scalar_unit&);
			scalar_unit& operator =(scalar_unit&&);

			virtual scalar_unit* clone() const = 0;

			explicit operator float() const;

			auto_scalar operator +(const scalar_unit&) const;
			auto_scalar operator -(const scalar_unit&) const;
			auto_scalar operator *(const scalar_unit&) const;
			auto_scalar operator /(const scalar_unit&) const;
			auto_scalar operator ^(const scalar_unit&) const;
			void operator +=(const scalar_unit&);
			void operator -=(const scalar_unit&);

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			auto_scalar operator +(T y) const;
			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			auto_scalar operator -(T y) const;
			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			auto_scalar operator *(T y) const;
			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			auto_scalar operator /(T y) const;
			template<typename T, typename = typename enable_if<is_integer_number<T>::value>::type>
			auto_scalar operator ^(T y) const;

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

			scalar_unit& operator++();
			scalar_unit& operator++(int);
			scalar_unit& operator--();
			scalar_unit& operator--(int);

			void change_dimensions(const string&);
			bool has_dimensions(const string&) const;
			bool has_dimensions(const vector_real_dimensions&) const;
			bool has_empty_dimensions() const;
			string display_dimensions() const;
			void set_same_prefix(const vector_actual_dimensions&);

			virtual string get_dimensions_match() const = 0;
			virtual vector_real_dimensions get_real_dimensions() const = 0;
			const vector_actual_dimensions& get_actual_dimensions() const;

			inline msci::unit_number& get_value()
			{
				return value;
			}

			inline const msci::unit_number& get_value() const
			{
				return value;
			}

			inline bool is_defined() const
			{
				return value.is_defined();
			}

			inline void invalidate(int x)
			{
				value.invalidate(x);
			}

			string display(int = 2) const;

		protected:
			vector_actual_dimensions actual_dimensions;
			msci::unit_number value;

			string initial_dimensions_get_structure(const string&) const;

		private:
			void add_prefix(shared_ptr<prefix>,float);
			void add_prefix(dimension_prefixes,float);
			void remove_prefix(shared_ptr<prefix>,float);
			void remove_prefix(dimension_prefixes,float);

			void initialize_dimensions(string);
	};

	msci::space_type abs(const scalar_unit&);
	auto_scalar sqrt(const scalar_unit&);
	auto_scalar sqrt_nth(const scalar_unit&, int);
	bool equal_dimensions(const scalar_unit&,const scalar_unit&);

	template<typename T>
	class scalar_unit_crtp : public scalar_unit
	{
		public:
			scalar_unit_crtp() : scalar_unit()
			{
			}

			scalar_unit_crtp(const scalar_unit_crtp<T>& x) : scalar_unit(x)
			{
			}

			scalar_unit_crtp(scalar_unit_crtp<T>&& x) : scalar_unit(move(x))
			{
			}

			explicit scalar_unit_crtp(msci::space_type new_value,const string& init_value) : scalar_unit(new_value,init_value)
			{
			}

			explicit scalar_unit_crtp(const string& init_value) : scalar_unit(init_value)
			{
			}

			explicit scalar_unit_crtp(const scalar_unit& new_unit,const string& init_value) : scalar_unit(new_unit,init_value)
			{
			}

			explicit scalar_unit_crtp(scalar_unit&& new_unit,const string& init_value) : scalar_unit(move(new_unit),init_value)
			{
			}

			scalar_unit_crtp(const scalar_unit& x) : scalar_unit(x)
			{
			}

			scalar_unit_crtp(scalar_unit&& x) : scalar_unit(move(x))
			{
			}

			scalar_unit_crtp<T>& operator =(const scalar_unit_crtp<T>& x)
			{
				scalar_unit::operator =(x);
				return *this;
			}

			scalar_unit_crtp<T>& operator =(scalar_unit_crtp<T>&& x)
			{
				scalar_unit::operator =(move(x));
				return *this;
			}

			scalar_unit_crtp<T>& operator =(const scalar_unit& x)
			{
				scalar_unit::operator =(x);
				return *this;
			}

			scalar_unit_crtp<T>& operator =(scalar_unit&& x)
			{
				scalar_unit::operator =(move(x));
				return *this;
			}

			/*auto_scalar operator +(const scalar_unit&) const;
			auto_scalar operator -(const scalar_unit&) const;
			auto_scalar operator *(const scalar_unit&) const;
			auto_scalar operator /(const scalar_unit&) const;
			auto_scalar operator ^(const scalar_unit&) const;

			void operator +=(const scalar_unit& x)
			{
				scalar_unit::operator+=(x);
			}

			void operator -=(const scalar_unit& x)
			{
				scalar_unit::operator-=(x);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_scalar operator +(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_scalar operator -(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_scalar operator *(U) const;
			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			auto_scalar operator /(U) const;
			template<typename U, typename = typename enable_if<is_integer_number<U>::value>::type>
			auto_scalar operator ^(U) const;

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator +=(U y)
			{
				scalar_unit::operator+=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator -=(U y)
			{
				scalar_unit::operator-=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator *=(U y)
			{
				scalar_unit::operator*=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator /=(U y)
			{
				scalar_unit::operator/=(y);
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator ^=(U y)
			{
				scalar_unit::operator^=(y);
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
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::unit_number operator ^(T x, const msci::scalar_unit& y)
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

bool operator ==(const msci::scalar_unit&, const msci::scalar_unit&);
bool operator !=(const msci::scalar_unit&, const msci::scalar_unit&);
bool operator <(const msci::scalar_unit&, const msci::scalar_unit&);
bool operator >(const msci::scalar_unit&, const msci::scalar_unit&);
bool operator <=(const msci::scalar_unit&, const msci::scalar_unit&);
bool operator >=(const msci::scalar_unit&, const msci::scalar_unit&);

bool operator ==(const msci::scalar_unit&, const string&);
bool operator !=(const msci::scalar_unit&, const string&);
bool operator <(const msci::scalar_unit&, const string&);
bool operator >(const msci::scalar_unit&, const string&);
bool operator <=(const msci::scalar_unit&, const string&);
bool operator >=(const msci::scalar_unit&, const string&);

bool operator ==(const string&, const msci::scalar_unit&);
bool operator !=(const string&, const msci::scalar_unit&);
bool operator <(const string&, const msci::scalar_unit&);
bool operator >(const string&, const msci::scalar_unit&);
bool operator <=(const string&, const msci::scalar_unit&);
bool operator >=(const string&, const msci::scalar_unit&);

void operator +=(string&, const msci::scalar_unit&);
string operator +(const string&, const msci::scalar_unit&);
string operator +(const msci::scalar_unit&, const string&);

ostream& operator <<(ostream&, const msci::scalar_unit&);
istream& operator >>(istream&, msci::scalar_unit&);

#endif
