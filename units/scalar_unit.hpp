#ifndef MSCI_UNITS_UNITS_SCALAR_UNIT_HPP_INCLUDED
#define MSCI_UNITS_UNITS_SCALAR_UNIT_HPP_INCLUDED

#include "units/dimension.hpp"
#include "units/prefix.hpp"
#include "util/is_number.hpp"

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
			name(); \
			name(const scalar_unit&); \
			name(scalar_unit&&); \
			using scalar_unit::operator=; \
			using scalar_unit::operator+=; \
			using scalar_unit::operator-=

#define SCALAR_UNIT_HPP_END() \
\
		public: \
			static const string dimensions_match; \
			static const vector<dimension> real_dimensions; \
	}

#define SCALAR_UNIT_HPP(name) class name : public scalar_unit \
	{	\
		public: \
			using scalar_unit::scalar_unit; \
			name(); \
			name(const scalar_unit&); \
			name(scalar_unit&&); \
			using scalar_unit::operator=; \
			using scalar_unit::operator+=; \
			using scalar_unit::operator-=; \
\
			static const string dimensions_match; \
			static const vector<dimension> real_dimensions; \
	}

#define SCALAR_UNIT_CPP(name,init_dimensions) name::name() : scalar_unit() {} \
\
	name::name(const scalar_unit& x) \
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
const vector<dimension> name::real_dimensions = create_derived_dimensions(init_dimensions)

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

			scalar_unit operator +(scalar_unit) const;
			scalar_unit operator -(scalar_unit) const;
			scalar_unit operator *(scalar_unit) const;
			scalar_unit operator /(scalar_unit) const;
			scalar_unit operator ^(const scalar_unit&) const;
			void operator +=(scalar_unit);
			void operator -=(scalar_unit);

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			scalar_unit operator +(const T y) const
			{
				scalar_unit x = *this;
				x += y;
				return x;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			scalar_unit operator -(const T y) const
			{
				scalar_unit x = *this;
				x -= y;
				return x;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			scalar_unit operator *(const T y) const
			{
				scalar_unit x = *this;
				x *= y;
				return x;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			scalar_unit operator /(const T y) const
			{
				scalar_unit x = *this;
				x /= y;
				return x;
			}

			template<typename T, typename = typename enable_if<is_integer_number<T>::value>::type>
			scalar_unit operator ^(const T y) const
			{
				return scalar_unit(std::pow(get_value(),y),power_dimensions(get_dimensions(),y));
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator +=(const T y)
			{
				value += y;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator -=(const T y)
			{
				value -= y;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator *=(const T y)
			{
				value *= y;
			}

			template<typename T, typename = typename enable_if<is_number<T>::value>::type>
			void operator /=(const T y)
			{
				value /= y;
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
			void set_same_prefix(const scalar_unit&);

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

			string display(int = 2) const;
			string custom_display(const string&,int = 2) const;

		protected:
			vector<dimension> dimensions;
			float value;

			string initial_dimensions_get_structure(const string&) const;
			void add_prefix(const prefix&);
			void remove_prefix(const prefix&);
			void add_dimension(const dimension&);
			void remove_dimension(const dimension&);
			void set_from_string(const string&);
	};

	string to_string(const scalar_unit&);
	float abs(const scalar_unit&);
	scalar_unit pow(const scalar_unit&,int);
	scalar_unit sqrt(const scalar_unit&);
	scalar_unit sqrt_nth(const scalar_unit&, int);
	bool equal_dimensions(const scalar_unit&,const scalar_unit&);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::scalar_unit operator +(const T y,const msci::scalar_unit& x)
{
	msci::scalar_unit z = x;
	z += y;
	return z;
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::scalar_unit operator -(const T y,const msci::scalar_unit& x)
{
	msci::scalar_unit z = msci::scalar_unit(y,x.get_dimensions());
	z -= x;
	return z;
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::scalar_unit operator *(const T y,const msci::scalar_unit& x)
{
	msci::scalar_unit z = x;
	z *= y;
	return z;
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
msci::scalar_unit operator /(const T y,const msci::scalar_unit& x)
{
	msci::scalar_unit z = msci::scalar_unit(y,vector<msci::dimension>());
	return z / x;
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
float operator ^(const T x, const msci::scalar_unit& y)
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

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator ==(const T x, const msci::scalar_unit& y)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator !=(const T x, const msci::scalar_unit& y)
{
	return !(x == y);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <(const T x, const msci::scalar_unit& y)
{
	return (x < y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >(const T x, const msci::scalar_unit& y)
{
	return (x > y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <=(const T x, const msci::scalar_unit& y)
{
	return (x <= y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >=(const T x, const msci::scalar_unit& y)
{
	return (x >= y.get_value());
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator ==(const msci::scalar_unit& x, const T y)
{
	return (x.get_value() == y);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator !=(const msci::scalar_unit& x, const T y)
{
	return !(x == y);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <(const msci::scalar_unit& x,const T y)
{
	return (x.get_value() < y);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >(const msci::scalar_unit& x,const T y)
{
	return (x.get_value() > y);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator <=(const msci::scalar_unit& x,const T y)
{
	return (x.get_value() <= y);
}

template<typename T, typename = typename enable_if<is_number<T>::value>::type>
bool operator >=(const msci::scalar_unit& x,const T y)
{
	return (x.get_value() >= y);
}

void operator +=(string&, const msci::scalar_unit&);
string operator +(const string&, const msci::scalar_unit&);
string operator +(const msci::scalar_unit&, const string&);

ostream& operator <<(ostream&, const msci::scalar_unit&);
istream& operator >>(istream&, msci::scalar_unit&);

#endif // MSCI_UNITS_UNITS_SCALAR_UNIT_HPP_INCLUDED
