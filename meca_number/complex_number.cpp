#include "meca_number/complex_number.hpp"

using namespace std;

namespace scifir
{
	bool is_complex(const string& init_complex_number)
	{
		if (init_complex_number.find("+"))
		{
			vector<string> numbers;
			boost::split(numbers,init_complex_number,boost::is_any_of("+"));
			if (numbers.size() != 2)
			{
				return false;
			}
			int imaginary_length = numbers[1].length() - 3;
			if (numbers[1].substr(0,imaginary_length) == "(i)")
			{
				bool dot_present = false;
				for (int i = 0; i < numbers[0].length(); i++)
				{
					if (numbers[0][i] == '.')
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
					else if (!std::isdigit(numbers[0][i]))
					{
						return false;
					}
				}
				dot_present = false;
				for (int i = 0; i < (imaginary_length); i++)
				{
					if (numbers[1][i] == '.')
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
					else if (!std::isdigit(numbers[1][i]))
					{
						return false;
					}
				}
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
}
