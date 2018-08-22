#ifndef SCALAR_UNIT_HPP_INCLUDED
#define SCALAR_UNIT_HPP_INCLUDED

#include "msci/units/units/unit.hpp"
#include "msci/units/units/auto_unit.hpp"

#include <type_traits>

#define SCALAR_UNIT_HPP_BEGIN(name) class name : public scalar_unit_crtp<name> \
	{	\
		public: \
			name(); \
			name(const name&); \
			name(name&&); \
			explicit name(msci::space_type,const string&); \
			explicit name(const string&); \
			explicit name(const unit&,const string&); \
			explicit name(unit&&,const string&); \
			name(const unit&); \
			name(unit&&); \
\
			name& operator =(const name&); \
			name& operator =(name&&); \
			name& operator =(const unit&); \
			name& operator =(unit&&); \
\
			name& operator =(const auto_vector& x) = delete; \
			name& operator =(auto_vector&& x) = delete

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
			explicit name(const unit&,const string&); \
			explicit name(unit&&,const string&); \
			name(const unit&); \
			name(unit&&); \
\
			name& operator =(const name&); \
			name& operator =(name&&); \
			name& operator =(const unit&); \
			name& operator =(unit&&); \
\
			name& operator =(const auto_vector& x) = delete; \
			name& operator =(auto_vector&& x) = delete; \
\
			static const string dimensions_match; \
			static const vector_real_dimensions real_dimensions; \
	}

#define SCALAR_UNIT_CPP(name,dimensions) name::name() : unit(),scalar_unit_crtp<name>() \
			{ \
			} \
\
	name::name(const name& x) : unit(x),scalar_unit_crtp<name>(x) \
			{ \
			} \
\
	name::name(name&& x) : unit(move(x)),scalar_unit_crtp<name>(move(x)) \
			{ \
			} \
\
	name::name(msci::space_type new_value,const string& init_value) : unit(new_value,init_value),scalar_unit_crtp<name>(new_value,init_value) \
			{ \
			} \
\
	name::name(const string& init_value) : unit(init_value),scalar_unit_crtp<name>(init_value) \
			{ \
			} \
\
	name::name(const unit& new_unit) : unit(new_unit),scalar_unit_crtp<name>(new_unit) \
			{ \
			} \
\
	name::name(unit&& new_unit) : unit(move(new_unit)),scalar_unit_crtp<name>(move(new_unit)) \
			{ \
			} \
\
	name::name(const unit& new_unit,const string& init_value) : unit(new_unit,init_value),scalar_unit_crtp<name>(new_unit,init_value) \
			{ \
			} \
\
	name::name(unit&& new_unit,const string& init_value) : unit(move(new_unit),init_value),scalar_unit_crtp<name>(move(new_unit),init_value) \
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
	name& name::operator =(const unit& x) \
	{ \
		unit::operator=(x); \
		return *this; \
	} \
\
	name& name::operator =(unit&& x) \
	{ \
		unit::operator=(move(x)); \
		return *this; \
	} \
const string name::dimensions_match = dimensions; \
const vector_real_dimensions name::real_dimensions = create_real_dimensions(dimensions)

using namespace std;

namespace msci
{
	class auto_scalar;
	class auto_vector;

	class scalar_unit : public virtual unit
	{
		public:
			scalar_unit();
			scalar_unit(const scalar_unit&);
			scalar_unit(scalar_unit&&);
			explicit scalar_unit(msci::space_type,const string&);
			explicit scalar_unit(msci::unit_number, const vector_actual_dimensions&);
			explicit scalar_unit(const string&);
			explicit scalar_unit(const unit&,const string&);
			explicit scalar_unit(unit&&,const string&);
			scalar_unit(const unit&);
			scalar_unit(unit&&);

			scalar_unit& operator =(const scalar_unit&);
			scalar_unit& operator =(scalar_unit&&);
			scalar_unit& operator =(const unit&);
			scalar_unit& operator =(unit&&);

			scalar_unit& operator =(const auto_vector&) = delete;
			scalar_unit& operator =(auto_vector&&) = delete;

			auto_scalar operator +(const scalar_unit&) const;
			auto_scalar operator -(const scalar_unit&) const;
			auto_scalar operator *(const scalar_unit&) const;
			auto_scalar operator /(const scalar_unit&) const;
			auto_scalar operator ^(const scalar_unit&) const;
			void operator +=(const scalar_unit&);
			void operator -=(const scalar_unit&);

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
				unit::value += y;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator -=(U y)
			{
				unit::value -= y;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator *=(U y)
			{
				unit::value *= y;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator /=(U y)
			{
				unit::value /= y;
			}

			template<typename U, typename = typename enable_if<is_number<U>::value>::type>
			void operator ^=(U y)
			{
				unit::value = unit::value ^ y;
			}
	};

	template<typename T>
	class scalar_unit_crtp : public unit_crtp<T>,public scalar_unit
	{
		public:
			scalar_unit_crtp() : unit(),unit_crtp<T>(),scalar_unit()
			{
			}

			scalar_unit_crtp(const scalar_unit_crtp<T>& x) : unit(x),unit_crtp<T>(x),scalar_unit(x)
			{
			}

			scalar_unit_crtp(scalar_unit_crtp<T>&& x) : unit(move(x)),unit_crtp<T>(move(x)),scalar_unit(move(x))
			{
			}

			explicit scalar_unit_crtp(msci::space_type new_value,const string& init_value) : unit(new_value,init_value),unit_crtp<T>(new_value,init_value),scalar_unit(new_value,init_value)
			{
			}

			explicit scalar_unit_crtp(const string& init_value) : unit(init_value),unit_crtp<T>(init_value),scalar_unit(init_value)
			{
			}

			explicit scalar_unit_crtp(const unit& new_unit,const string& init_value) : unit(new_unit,init_value),unit_crtp<T>(new_unit,init_value),scalar_unit(new_unit,init_value)
			{
			}

			explicit scalar_unit_crtp(unit&& new_unit,const string& init_value) : unit(move(new_unit),init_value),unit_crtp<T>(move(new_unit),init_value),scalar_unit(move(new_unit),init_value)
			{
			}

			scalar_unit_crtp(const unit& x) : unit(x),unit_crtp<T>(x),scalar_unit(x)
			{
			}

			scalar_unit_crtp(unit&& x) : unit(move(x)),unit_crtp<T>(move(x)),scalar_unit(move(x))
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

			scalar_unit_crtp<T>& operator =(const unit& x)
			{
				unit::operator =(x);
				return *this;
			}

			scalar_unit_crtp<T>& operator =(unit&& x)
			{
				unit::operator =(move(x));
				return *this;
			}

			scalar_unit_crtp<T>& operator =(const auto_vector& x) = delete;
			scalar_unit_crtp<T>& operator =(auto_vector&& x) = delete;

			auto_scalar operator +(const scalar_unit&) const;
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
			}
	};
}

#endif // SCALAR_UNIT_HPP_INCLUDED
