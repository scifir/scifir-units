#ifndef SCIFIR_UNITS_UNITS_SCALAR_UNIT_HPP_INCLUDED
#define SCIFIR_UNITS_UNITS_SCALAR_UNIT_HPP_INCLUDED

#include "../units/dimension.hpp"
#include "../units/prefix.hpp"
#include "../util/is_number.hpp"

#include <cmath>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <string_view>
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

#define SCALAR_UNIT_CPP(name,init_dimensions) name::name() : scalar_unit() { \
	scalar_unit::dimensions = name::real_dimensions; \
} \
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
			value = std::move(x.get_value()); \
			dimensions = std::move(x.get_dimensions()); \
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
			scalar_unit(const scalar_unit& x);
			scalar_unit(scalar_unit&& x);
			explicit scalar_unit(float new_value, const string& init_dimensions);
			explicit scalar_unit(double new_value, const string& init_dimensions);
			explicit scalar_unit(long double new_value, const string& init_dimensions);
			explicit scalar_unit(int new_value, const string& init_dimensions);
			explicit scalar_unit(float new_value, const vector<dimension>& new_dimensions);
			explicit scalar_unit(double new_value, const vector<dimension>& new_dimensions);
			explicit scalar_unit(long double new_value, const vector<dimension>& new_dimensions);
			explicit scalar_unit(int new_value, const vector<dimension>& new_dimensions);
			explicit scalar_unit(const string& init_scalar);

			scalar_unit& operator =(const scalar_unit& x);
			scalar_unit& operator =(scalar_unit&& x);
			scalar_unit& operator =(const string& init_scalar);

			explicit operator float() const;

			bool operator ==(scalar_unit x) const;

			scalar_unit operator +(scalar_unit x) const;
			scalar_unit operator -(scalar_unit x) const;
			scalar_unit operator *(scalar_unit x) const;
			scalar_unit operator /(scalar_unit x) const;
			scalar_unit operator ^(const scalar_unit& x) const;
			void operator +=(scalar_unit x);
			void operator -=(scalar_unit x);

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			scalar_unit operator +(T y) const
			{
				scalar_unit x = *this;
				x += y;
				return x;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			scalar_unit operator -(T y) const
			{
				scalar_unit x = *this;
				x -= y;
				return x;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			scalar_unit operator *(T y) const
			{
				scalar_unit x = *this;
				x *= y;
				return x;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			scalar_unit operator /(T y) const
			{
				scalar_unit x = *this;
				x /= y;
				return x;
			}

			template<typename T, typename = typename enable_if<is_integer_number<T>::value>::type>
			scalar_unit operator ^(T y) const
			{
				return scalar_unit(std::pow(get_value(),y),power_dimensions(get_dimensions(),y));
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator +=(T y)
			{
				value += y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator -=(T y)
			{
				value -= y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator *=(T y)
			{
				value *= y;
			}

			template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
			void operator /=(T y)
			{
				value /= y;
			}

			scalar_unit& operator ++();
			scalar_unit& operator ++(int);
			scalar_unit& operator --();
			scalar_unit& operator --(int);

			void change_dimensions(const string& init_dimensions);
			void change_dimensions(const scalar_unit& x);
			bool has_dimensions(const string& init_dimensions) const;
			bool has_dimensions(const vector<dimension>& x_dimensions) const;
			bool has_dimensions(const scalar_unit& x) const;
			bool has_empty_dimensions() const;
			string display_dimensions() const;

			//string get_dimensions_match() const;
			vector<dimension> get_derived_dimensions() const;
			
			inline const vector<dimension>& get_dimensions() const
			{
				return dimensions;
			}

			inline const float& get_value() const
			{
				return value;
			}

			string display(int number_of_decimals = 2 ,bool with_brackets = false,bool use_close_prefix = false) const;
			string derived_display(int number_of_decimals = 2,bool with_brackets = false,bool use_close_prefix = false) const;
			string custom_display(const string& init_dimensions,int number_of_decimals = 2,bool with_brackets = false) const;

		protected:
			vector<dimension> dimensions;
			float value;

			void add_dimension(const dimension& new_dimension);
			void remove_dimension(const dimension& old_dimension);
			void initialize_from_string(string init_scalar);
	};

	string to_string(const scalar_unit& x);
	bool is_scalar_unit(const string& init_scalar);
	float abs(const scalar_unit& x);
	scalar_unit pow(const scalar_unit& x,int exponent);
	scalar_unit sqrt(const scalar_unit& x);
	scalar_unit sqrt_nth(const scalar_unit& x, int index);

	/*constexpr bool is_valid_scalar_unit(const char* x_init)
	{
		string_view x = x_init;
		bool dot_present = false;
		bool e_present = false;
		int current_pos = 0;
		int e_present_pos = 0;
		for (int i = 0; i < x.length(); i++)
		{
			if (x[i] == ' ')
			{
				if (e_present and ((e_present_pos + 1) == i))
				{
					return false;
				}
				current_pos = i;
				break;
			}
			if (e_present == false)
			{
				if (x[i] == '.')
				{
					if (dot_present)
					{
						return false;
					}
					else
					{
						dot_present = true;
					}
				}
				else if (x[i] == 'e' or x[i] == 'E')
				{
					e_present = true;
					e_present_pos = i;
					continue;
				}
				else if (x[i] == '*')
				{
					if (!(x.substr(i + 1,3) == "10^"))
					{
						return false;
					}
					else
					{
						e_present = true;
						i += 3;
						e_present_pos = i;
						continue;
					}
				}
				else if (!isdigit(x[i]))
				{
					return false;
				}
				else if (i == (x.length() - 1))
				{
					return false;
				}
			}
			else
			{
				if (!isdigit(x[i]))
				{
					return false;
				}
			}
		}
		if (current_pos == (x.length() - 1))
		{
			return false;
		}
		if (current_pos == 0)
		{
			return false;
		}
		vector<string_view> values = x | std::ranges::split(x,"/") | std::ranges::to<std::vector>();
//		boost::split(values,x.substr(current_pos),boost::is_any_of("/"));
		if (values.size() == 1)
		{
			vector<string_view> subvalues;
			boost::split(subvalues,values[0],boost::is_any_of("*"));
			for (string_view& x_subvalue : subvalues)
			{
				boost::trim(x_subvalue);
				bool number_present = false;
				for (int i = 0; i < x_subvalue.length(); i++)
				{
					if (number_present == false)
					{
						if (isdigit(x_subvalue[i]))
						{
							number_present = true;
							continue;
						}
						else if (!isalpha(x_subvalue[i]))
						{
							return false;
						}
					}
					else
					{
						if (!isdigit(x_subvalue[i]))
						{
							return false;
						}
					}
				}
			}
			return true;
		}
		else if (values.size() == 2)
		{
			if (values[0] != "1")
			{
				vector<string_view> subvalues;
				boost::split(subvalues,values[0],boost::is_any_of("*"));
				for (string_view& x_subvalue : subvalues)
				{
					boost::trim(x_subvalue);
					bool number_present = false;
					for (int i = 0; i < x_subvalue.length(); i++)
					{
						if (number_present == false)
						{
							if (isdigit(x_subvalue[i]))
							{
								number_present = true;
								continue;
							}
							else if (!isalpha(x_subvalue[i]))
							{
								return false;
							}
						}
						else
						{
							if (!isdigit(x_subvalue[i]))
							{
								return false;
							}
						}
					}
				}
			}
			vector<string_view> subvalues_denominator;
			boost::split(subvalues_denominator,values[1],boost::is_any_of("*"));
			for (string_view& x_subvalue : subvalues_denominator)
			{
				boost::trim(x_subvalue);
				bool number_present = false;
				for (int i = 0; i < x_subvalue.length(); i++)
				{
					if (number_present == false)
					{
						if (isdigit(x_subvalue[i]))
						{
							number_present = true;
							continue;
						}
						else if (!isalpha(x_subvalue[i]))
						{
							return false;
						}
					}
					else
					{
						if (!isdigit(x_subvalue[i]))
						{
							return false;
						}
					}
				}
			}
			return true;
		}
		return false;
	}*/
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::scalar_unit operator +(const T& y,const scifir::scalar_unit& x)
{
	scifir::scalar_unit z = x;
	z += y;
	return z;
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::scalar_unit operator -(const T& y,const scifir::scalar_unit& x)
{
	scifir::scalar_unit z = scifir::scalar_unit((long double)y,x.get_dimensions());
	z -= x;
	return z;
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::scalar_unit operator *(const T& y,const scifir::scalar_unit& x)
{
	scifir::scalar_unit z = x;
	z *= y;
	return z;
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
scifir::scalar_unit operator /(const T& y,const scifir::scalar_unit& x)
{
	scifir::scalar_unit z = scifir::scalar_unit((long double)y,vector<scifir::dimension>());
	return z / x;
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
float operator ^(const T& x, const scifir::scalar_unit& y)
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

bool operator !=(const scifir::scalar_unit& x, scifir::scalar_unit y);
bool operator <(const scifir::scalar_unit& x, const scifir::scalar_unit& y);
bool operator >(const scifir::scalar_unit& x, const scifir::scalar_unit& y);
bool operator <=(const scifir::scalar_unit& x, const scifir::scalar_unit& y);
bool operator >=(const scifir::scalar_unit& x, const scifir::scalar_unit& y);

bool operator ==(const scifir::scalar_unit& x, const string& init_scalar);
bool operator !=(const scifir::scalar_unit& x, const string& init_scalar);
bool operator <(const scifir::scalar_unit& x, const string& init_scalar);
bool operator >(const scifir::scalar_unit& x, const string& init_scalar);
bool operator <=(const scifir::scalar_unit& x, const string& init_scalar);
bool operator >=(const scifir::scalar_unit& x, const string& init_scalar);

bool operator ==(const string& init_scalar, const scifir::scalar_unit& x);
bool operator !=(const string& init_scalar, const scifir::scalar_unit& x);
bool operator <(const string& init_scalar, const scifir::scalar_unit& x);
bool operator >(const string& init_scalar, const scifir::scalar_unit& x);
bool operator <=(const string& init_scalar, const scifir::scalar_unit& x);
bool operator >=(const string& init_scalar, const scifir::scalar_unit& x);

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator ==(const T& x, const scifir::scalar_unit& y)
{
	return (x == y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator !=(const T& x, const scifir::scalar_unit& y)
{
	return !(x == y);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <(const T& x, const scifir::scalar_unit& y)
{
	return (x < y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >(const T& x, const scifir::scalar_unit& y)
{
	return (x > y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <=(const T& x, const scifir::scalar_unit& y)
{
	return (x <= y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >=(const T& x, const scifir::scalar_unit& y)
{
	return (x >= y.get_value());
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator ==(const scifir::scalar_unit& x, const T& y)
{
	return (x.get_value() == y);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator !=(const scifir::scalar_unit& x, const T& y)
{
	return !(x == y);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <(const scifir::scalar_unit& x,const T& y)
{
	return (x.get_value() < y);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >(const scifir::scalar_unit& x,const T& y)
{
	return (x.get_value() > y);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator <=(const scifir::scalar_unit& x,const T& y)
{
	return (x.get_value() <= y);
}

template<typename T, typename = typename enable_if<scifir::is_number<T>::value>::type>
bool operator >=(const scifir::scalar_unit& x,const T& y)
{
	return (x.get_value() >= y);
}

void operator +=(string& x, const scifir::scalar_unit& y);
string operator +(const string& x, const scifir::scalar_unit& y);
string operator +(const scifir::scalar_unit& y, const string& x);

ostream& operator <<(ostream& os, const scifir::scalar_unit& x);
istream& operator >>(istream& is, scifir::scalar_unit& x);

#endif // SCIFIR_UNITS_UNITS_SCALAR_UNIT_HPP_INCLUDED
