#ifndef MATH_ALGEBRA_MATH_VARIABLE_HPP_INCLUDED
#define MATH_ALGEBRA_MATH_VARIABLE_HPP_INCLUDED

#include "../../units.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace msci
{
	enum class variable_type {value_variable,function_variable};

	class math_expression;

	class math_variable
	{
		public:
			math_variable();
			explicit math_variable(const string&);
			explicit math_variable(const string&,const unit&);
			explicit math_variable(const string&,const unit&,const string&);
			explicit math_variable(const string&,const unit&,const string&,const string&);

			inline unit& get_value()
			{
				return value;
			}

			inline const unit& get_value() const
			{
				return value;
			}

			inline string& get_symbol()
			{
				return symbol;
			}

			inline const string& get_symbol() const
			{
				return symbol;
			}

			inline string& get_name()
			{
				return name;
			}

			inline const string& get_name() const
			{
				return name;
			}

			inline string& get_description()
			{
				return description;
			}

			inline const string& get_description() const
			{
				return description;
			}

			math_variable operator +(const math_variable&) const;
			math_variable operator -(const math_variable&) const;
			math_variable operator *(const math_variable&) const;
			math_variable operator /(const math_variable&) const;
			math_variable operator ^(const math_variable&) const;

			virtual variable_type get_type() const;

			virtual string display(int = 2) const;
			virtual string display_symbol() const;
			virtual string display_text(int = 2) const;

		protected:
			string symbol;
			string name;

		private:
			auto_unit value;
			string description;
	};
}

ostream& operator << (ostream&,const msci::math_variable&);

#endif // MATH_ALGEBRA_MATH_VARIABLE_HPP_INCLUDED
