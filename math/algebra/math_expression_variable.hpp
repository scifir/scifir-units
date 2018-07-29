#ifndef MATH_ALGEBRA_MATH_EXPRESSION_VARIABLE_HPP_INCLUDED
#define MATH_ALGEBRA_MATH_EXPRESSION_VARIABLE_HPP_INCLUDED

#include "math_variable.hpp"

using namespace std;

namespace msci
{
	enum class operation_type {sum,substract,multiply,divide};

	class math_expression_variable
	{
		public:
			math_expression_variable();

			inline math_expression_variable* get_related_to()
			{
				return related_to;
			}

			inline const math_expression_variable* get_related_to() const
			{
				return related_to;
			}

			inline math_variable& get_variable()
			{
				return variable;
			}

			inline const math_variable& get_variable() const
			{
				return variable;
			}

			inline operation_type& get_operation()
			{
				return operation;
			}

			inline const operation_type& get_operation() const
			{
				return operation;
			}

			inline unsigned int& get_exponent()
			{
				return exponent;
			}

			inline const unsigned int& get_exponent() const
			{
				return exponent;
			}

		private:
			math_expression_variable* related_to;
			math_variable variable;
			operation_type operation;
			unsigned int exponent;
	};
}

#endif // MATH_ALGEBRA_MATH_EXPRESSION_VARIABLE_HPP_INCLUDED
