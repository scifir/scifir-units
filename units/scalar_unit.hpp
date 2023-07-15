#ifndef SCIFIR_UNITS_UNITS_SCALAR_UNIT_HPP_INCLUDED
#define SCIFIR_UNITS_UNITS_SCALAR_UNIT_HPP_INCLUDED

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

namespace scifir
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

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			scalar_unit operator +(const T y) const
			{
				scalar_unit x = *this;
				x += y;
				return x;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			scalar_unit operator -(const T y) const
			{
				scalar_unit x = *this;
				x -= y;
				return x;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			scalar_unit operator *(const T y) const
			{
				scalar_unit x = *this;
				x *= y;
				return x;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
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

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator +=(const T y)
			{
				value += y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator -=(const T y)
			{
				value -= y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator *=(const T y)
			{
				value *= y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator /=(const T y)
			{
				value /= y;
			}

			scalar_unit& operator++();
			scalar_unit& operator++(int);
			scalar_unit& operator--();
			scalar_unit& operator--(int);

			void change_dimensions(const string&);
			void change_dimensions(const scalar_unit&);
			bool has_dimensions(const string&) const;
			bool has_dimensions(const vector<dimension>&) const;
			bool has_dimensions(const scalar_unit& x) const;
			bool has_empty_dimensions() const;
			string display_dimensions() const;

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
			string derived_display(int = 2) const;
			string custom_display(const string&,int = 2) const;

		protected:
			vector<dimension> dimensions;
			float value;

			string initial_dimensions_get_structure(const string&) const;
			void add_dimension(const dimension&);
			void remove_dimension(const dimension&);
			void set_from_string(const string&);
	};

	string to_string(const scalar_unit&);
	bool is_scalar_unit(const string&);
	float abs(const scalar_unit&);
	scalar_unit pow(const scalar_unit&,int);
	scalar_unit sqrt(const scalar_unit&);
	scalar_unit sqrt_nth(const scalar_unit&, int);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::scalar_unit operator +(const T y,const scifir::scalar_unit& x)
{
	scifir::scalar_unit z = x;
	z += y;
	return z;
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::scalar_unit operator -(const T y,const scifir::scalar_unit& x)
{
	scifir::scalar_unit z = scifir::scalar_unit(y,x.get_dimensions());
	z -= x;
	return z;
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::scalar_unit operator *(const T y,const scifir::scalar_unit& x)
{
	scifir::scalar_unit z = x;
	z *= y;
	return z;
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::scalar_unit operator /(const T y,const scifir::scalar_unit& x)
{
	scifir::scalar_unit z = scifir::scalar_unit(y,vector<scifir::dimension>());
	return z / x;
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
float operator ^(const T x, const scifir::scalar_unit& y)
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

bool operator ==(const scifir::scalar_unit&, scifir::scalar_unit);
bool operator !=(const scifir::scalar_unit&, scifir::scalar_unit);
bool operator <(const scifir::scalar_unit&, const scifir::scalar_unit&);
bool operator >(const scifir::scalar_unit&, const scifir::scalar_unit&);
bool operator <=(const scifir::scalar_unit&, const scifir::scalar_unit&);
bool operator >=(const scifir::scalar_unit&, const scifir::scalar_unit&);

bool operator ==(const scifir::scalar_unit&, const string&);
bool operator !=(const scifir::scalar_unit&, const string&);
bool operator <(const scifir::scalar_unit&, const string&);
bool operator >(const scifir::scalar_unit&, const string&);
bool operator <=(const scifir::scalar_unit&, const string&);
bool operator >=(const scifir::scalar_unit&, const string&);

bool operator ==(const string&, const scifir::scalar_unit&);
bool operator !=(const string&, const scifir::scalar_unit&);
bool operator <(const string&, const scifir::scalar_unit&);
bool operator >(const string&, const scifir::scalar_unit&);
bool operator <=(const string&, const scifir::scalar_unit&);
bool operator >=(const string&, const scifir::scalar_unit&);

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator ==(const T x, const scifir::scalar_unit& y)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator !=(const T x, const scifir::scalar_unit& y)
{
	return !(x == y);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <(const T x, const scifir::scalar_unit& y)
{
	return (x < y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >(const T x, const scifir::scalar_unit& y)
{
	return (x > y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <=(const T x, const scifir::scalar_unit& y)
{
	return (x <= y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >=(const T x, const scifir::scalar_unit& y)
{
	return (x >= y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator ==(const scifir::scalar_unit& x, const T y)
{
	return (x.get_value() == y);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator !=(const scifir::scalar_unit& x, const T y)
{
	return !(x == y);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <(const scifir::scalar_unit& x,const T y)
{
	return (x.get_value() < y);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >(const scifir::scalar_unit& x,const T y)
{
	return (x.get_value() > y);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <=(const scifir::scalar_unit& x,const T y)
{
	return (x.get_value() <= y);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >=(const scifir::scalar_unit& x,const T y)
{
	return (x.get_value() >= y);
}

void operator +=(string&, const scifir::scalar_unit&);
string operator +(const string&, const scifir::scalar_unit&);
string operator +(const scifir::scalar_unit&, const string&);

ostream& operator <<(ostream&, const scifir::scalar_unit&);
istream& operator >>(istream&, scifir::scalar_unit&);

#endif // SCIFIR_UNITS_UNITS_SCALAR_UNIT_HPP_INCLUDED
