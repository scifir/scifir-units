#include "./complex_number.hpp"

using namespace std;

namespace scifir
{
	bool is_complex(const string& init_complex_number)
	{
		if ((init_complex_number.find("+") != string::npos or init_complex_number.find("-") != string::npos) and init_complex_number.length() > 1)
		{
			vector<string> numbers;
			boost::split(numbers,init_complex_number,boost::is_any_of("+-"));
			if (numbers.size() != 2)
			{
				return false;
			}
			int imaginary_length = int(numbers[1].length()) - 3;
			if (numbers[1].substr(imaginary_length) == "(i)")
			{
				bool dot_present = false;
				bool after_whitespace = false;
				bool after_alpha = false;
				for (unsigned int i = 0; i < numbers[0].length(); i++)
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
							continue;
						}
					}
					else if (numbers[0][i] == ' ')
					{
						after_whitespace = true;
						continue;
					}
					else if (!std::isdigit(numbers[0][i]) and after_whitespace == false)
					{
						return false;
					}
					else if (!std::isalpha(numbers[0][i]) and after_whitespace == true)
					{
						if (after_alpha == true and std::isalpha(numbers[0][i]))
						{
							return false;
						}
						else if (std::isdigit(numbers[0][i]))
						{
							after_alpha = true;
						}
						else
						{
							return false;
						}
					}
				}
				dot_present = false;
				after_whitespace = false;
				after_alpha = false;
				for (unsigned int i = 0; i < imaginary_length; i++)
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
							continue;
						}
					}
					else if (numbers[1][i] == ' ')
					{
						after_whitespace = true;
						continue;
					}
					else if (!std::isdigit(numbers[1][i]) and after_whitespace == false)
					{
						return false;
					}
					else if (!std::isalpha(numbers[1][i]) and after_whitespace == true)
					{
						if (after_alpha == true and std::isalpha(numbers[1][i]))
						{
							return false;
						}
						else if (std::isdigit(numbers[1][i]))
						{
							after_alpha = true;
						}
						else
						{
							return false;
						}
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
