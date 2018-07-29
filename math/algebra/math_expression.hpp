#ifndef MATH_ALGEBRA_MATH_EQUATION_HPP_INCLUDED
#define MATH_ALGEBRA_MATH_EQUATION_HPP_INCLUDED

#include "math_expression_variable.hpp"

#include <vector>

using namespace std;

namespace msci
{
	class math_expression
	{
		public:
			math_expression();

			inline vector<math_expression_variable>& get_terms()
			{
				return terms;
			}

			inline const vector<math_expression_variable>& get_terms() const
			{
				return terms;
			}

		private:
			vector<math_expression_variable> terms;
	};
}

#endif // MATH_ALGEBRA_MATH_EQUATION_HPP_INCLUDED
