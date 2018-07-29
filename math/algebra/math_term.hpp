#ifndef MATH_ALGEBRA_MATH_TERM_HPP_INCLUDED
#define MATH_ALGEBRA_MATH_TERM_HPP_INCLUDED

#include "math_variable.hpp"

#include <vector>

using namespace std;

namespace msci
{
	class math_term
	{
		public:
			math_term();

			inline vector<math_variable>& get_variables()
			{
				return variables;
			}

			inline const vector<math_variable>& get_variables() const
			{
				return variables;
			}

			inline vector<int>& get_exponents()
			{
				return exponents;
			}

			inline const vector<int>& get_exponents() const
			{
				return exponents;
			}

		private:
			vector<math_variable> variables;
			vector<int> exponents;
	};
}

#endif // MATH_ALGEBRA_MATH_TERM_HPP_INCLUDED
