#ifndef MATH_ALGEBRA_MATH_FUNCTION_HPP_INCLUDED
#define MATH_ALGEBRA_MATH_FUNCTION_HPP_INCLUDED

#include "math_variable.hpp"

using namespace std;

namespace msci
{
	class math_function : public math_variable
	{
		public:
			math_function();

			inline vector<math_variable>& get_arguments()
			{
				return arguments;
			}

			inline const vector<math_variable>& get_arguments() const
			{
				return arguments;
			}

			virtual variable_type get_type() const;

			virtual string display(int = 2) const;
			virtual string display_symbol() const;
			virtual string display_text(int = 2) const;

			string display_expression() const;

		private:
			vector<math_variable> arguments;
	};
}

#endif // MATH_ALGEBRA_MATH_FUNCTION_HPP_INCLUDED
