#ifndef MSCI_scalar_unitS_scalar_unitS_scalar_unit_HPP
#define MSCI_scalar_unitS_scalar_unitS_scalar_unit_HPP

#include "msci/units/units/dimension.hpp"
#include "msci/units/units/prefix.hpp"
#include "msci/units/meca_number/unit_number.hpp"
#include "msci/units/util/is_number.hpp"

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#define SCALAR_UNIT_HPP_BEGIN(name) class name : public scalar_unit \
	{	\
		public: \
			name(); \
			name(const name&); \
			name(name&&); \
			explicit name(float,const string&); \
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
			static const vector<dimension> real_dimensions; \
	}

#define SCALAR_UNIT_HPP(name) class name : public scalar_unit \
	{	\
		public: \
			name(); \
			name(const name&); \
			name(name&&); \
			explicit name(float,const string&); \
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
			static const vector<dimension> real_dimensions; \
	}

#define SCALAR_UNIT_CPP(name,dimensions) name::name() : scalar_unit() \
			{ \
			} \
\
	name::name(const name& x) : scalar_unit(x) \
			{ \
			} \
\
	name::name(name&& x) : scalar_unit(move(x)) \
			{ \
			} \
\
	name::name(float new_value,const string& init_value) : scalar_unit(new_value,init_value) \
			{ \
			} \
\
	name::name(const string& init_value) : scalar_unit(init_value) \
			{ \
			} \
\
	name::name(const scalar_unit& new_unit) : scalar_unit(new_unit) \
			{ \
			} \
\
	name::name(scalar_unit&& new_unit) : scalar_unit(move(new_unit)) \
			{ \
			} \
\
	name::name(const scalar_unit& new_unit,const string& init_value) : scalar_unit(new_unit,init_value) \
			{ \
			} \
\
	name::name(scalar_unit&& new_unit,const string& init_value) : scalar_unit(move(new_unit),init_value) \
			{ \
			} \
\
	name& name::operator =(const name& x) \
	{ \
		scalar_unit::operator=(x); \
		return *this; \
	} \
\
	name& name::operator =(name&& x) \
	{ \
		scalar_unit::operator=(move(x)); \
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
const vector<dimension> name::real_dimensions = create_derived_dimensions(dimensions)

using namespace std;

namespace msci
{
	class scalar_unit
	{
		public:
			scalar_unit();
			scalar_unit(const scalar_unit&);
			scalar_unit(scalar_unit&&);
			explicit scalar_unit(const unit_number&, const string& = "");
			explicit scalar_unit(const unit_number&, const vector<dimension>&);
			explicit scalar_unit(const scalar_unit&,const string&);
			explicit scalar_unit(scalar_unit&&,const string&);
			explicit scalar_unit(const string&);

			scalar_unit& operator =(const scalar_unit&);
			scalar_unit& operator =(scalar_unit&&);

			explicit operator float() const;

			scalar_unit operator +(const scalar_unit&) const;
			scalar_unit operator -(const scalar_unit&) const;
			scalar_unit operator *(const scalar_unit&) const;
			scalar_unit operator /(const scalar_unit&) const;
			scalar_unit operator ^(const scalar_unit&) const;
			void operator +=(const scalar_unit&);
			void operator -=(const scalar_unit&);

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			scalar_unit operator +(T y) const;
			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			scalar_unit operator -(T y) const;
			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			scalar_unit operator *(T y) const;
			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			scalar_unit operator /(T y) const;
			template<typename T, typename = typename enable_if<is_integer_number<T>::value>::type>
			scalar_unit operator ^(T y) const;

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
			bool has_dimensions(const vector<dimension>&) const;
			bool has_empty_dimensions() const;
			string display_dimensions() const;
			void set_same_prefix(const vector<dimension>&);

			string get_dimensions_match() const;
			vector<dimension> get_derived_dimensions() const;
			const vector<dimension>& get_dimensions() const;

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
			vector<dimension> dimensions;
			msci::unit_number value;

			string initial_dimensions_get_structure(const string&) const;

		private:
			void add_prefix(const prefix&,float);
			//void add_prefix(const prefix[],float);
			void remove_prefix(const prefix&,float);
			//void remove_prefix(const prefix[],float);

			void initialize_dimensions(string);
	};

	float abs(const scalar_unit&);
	scalar_unit sqrt(const scalar_unit&);
	scalar_unit sqrt_nth(const scalar_unit&, int);
	bool equal_dimensions(const scalar_unit&,const scalar_unit&);
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
