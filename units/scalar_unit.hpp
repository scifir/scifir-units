#ifndef MSCI_UNITS_UNITS_SCALAR_UNIT_HPP_INCLUDED
#define MSCI_UNITS_UNITS_SCALAR_UNIT_HPP_INCLUDED

#include "msci/units/units/dimension.hpp"
#include "msci/units/units/prefix.hpp"
#include "msci/units/util/is_number.hpp"

#include <cmath>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#define SCALAR_UNIT_HPP_BEGIN(name) class name : public scalar_unit \
	{	\
		public: \
			using scalar_unit::scalar_unit; \
			name(const scalar_unit&); \
			name(scalar_unit&&);

#define SCALAR_UNIT_HPP_END() \
\
			static const string dimensions_match; \
			static const vector<msci::dimension> real_dimensions; \
	}

#define SCALAR_UNIT_HPP(name) class name : public scalar_unit \
	{	\
		public: \
			using scalar_unit::scalar_unit; \
			name(const scalar_unit&); \
			name(scalar_unit&&); \
\
			static const string dimensions_match; \
			static const vector<msci::dimension> real_dimensions; \
	}

#define SCALAR_UNIT_CPP(name,init_dimensions) name::name(const scalar_unit& x) \
	{ \
		if (x.has_dimensions(name::real_dimensions)) \
		{ \
			value = x.get_value(); \
			dimensions = x.get_dimensions(); \
		} \
	} \
\
	name::name(scalar_unit&& x) \
	{ \
		if (x.has_dimensions(name::real_dimensions)) \
		{ \
			value = move(x.get_value()); \
			dimensions = move(x.get_dimensions()); \
		} \
	} \
\
const string name::dimensions_match = init_dimensions; \
const vector<msci::dimension> name::real_dimensions = create_derived_dimensions(init_dimensions)

using namespace std;

namespace msci
{
	class scalar_unit
	{
		public:
			scalar_unit();
			scalar_unit(const scalar_unit&);
			scalar_unit(scalar_unit&&);
			explicit scalar_unit(float, const string&);
			explicit scalar_unit(float, const vector<dimension>&);
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
			scalar_unit operator +(T y) const
			{
				scalar_unit x = *this;
				x += y;
				return x;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			scalar_unit operator -(T y) const
			{
				scalar_unit x = *this;
				x -= y;
				return x;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			scalar_unit operator *(T y) const
			{
				scalar_unit x = *this;
				x *= y;
				return x;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			scalar_unit operator /(T y) const
			{
				scalar_unit x = *this;
				x /= y;
				return x;
			}

			template<typename T, typename = typename enable_if<is_integer_number<T>::value>::type>
			scalar_unit operator ^(T y) const
			{
				scalar_unit x = *this;
				x ^= y;
				return x;
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

			template<typename T, typename = typename enable_if<is_integer_number<T>::value>::type>
			void operator ^=(T y)
			{
				value = std::pow(value,y);
				dimensions = power_dimensions(dimensions,y);
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
			
			inline const vector<dimension>& get_dimensions() const
			{
				return dimensions;
			}

			inline const float& get_value() const
			{
				return value;
			}

		protected:
			vector<dimension> dimensions;
			float value;

			string initial_dimensions_get_structure(const string&) const;
			void add_prefix(const prefix&);
			void remove_prefix(const prefix&);
	};

	string to_string(const scalar_unit&,int = 2);
	float abs(const scalar_unit&);
	scalar_unit pow(const scalar_unit&,int);
	scalar_unit sqrt(const scalar_unit&);
	scalar_unit sqrt_nth(const scalar_unit&, int);
	bool equal_dimensions(const scalar_unit&,const scalar_unit&);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
float operator ^(T x, const msci::scalar_unit& y)
{
	if(y.has_empty_dimensions())
	{
		return std::pow(x, y.get_value());
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

#endif // MSCI_UNITS_UNITS_SCALAR_UNIT_HPP_INCLUDED
