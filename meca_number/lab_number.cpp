#include "./lab_number.hpp"

using namespace std;

namespace scifir
{
	bool is_lab_number(const string& init_lab_number)
	{
		if ((init_lab_number.find("\u00B1") != string::npos or init_lab_number.find("+") != string::npos or init_lab_number.find("-") != string::npos) and init_lab_number.length() > 1)
		{
			vector<string> numbers;
			boost::split(numbers,init_lab_number,boost::is_any_of("+-,\u00B1"));
			if (numbers.size() != 3)
			{
				return false;
			}
			if (numbers[2].length() < 1)
			{
				return false;
			}
			bool dot_present = false;
			bool after_whitespace = false;
			bool after_alpha = false;
			boost::trim(numbers[0]);
			boost::trim(numbers[2]);
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
				else if (after_whitespace == true)
				{
					if (after_alpha == true and std::isalpha(numbers[0][i]))
					{
						return false;
					}
					else if (std::isalpha(numbers[0][i]))
					{
						continue;
					}
					else if (std::isdigit(numbers[0][i]))
					{
						after_alpha = true;
					}
				}
			}
			dot_present = false;
			after_whitespace = false;
			after_alpha = false;
			for (unsigned int i = 0; i < numbers[2].length(); i++)
			{
				if (numbers[2][i] == '.')
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
				else if (numbers[2][i] == ' ')
				{
					after_whitespace = true;
					continue;
				}
				else if (!std::isdigit(numbers[2][i]) and after_whitespace == false)
				{
					return false;
				}
				else if (after_whitespace == true)
				{
					if (after_alpha == true and std::isalpha(numbers[2][i]))
					{
						return false;
					}
					else if (std::isalpha(numbers[2][i]))
					{
						continue;
					}
					else if (std::isdigit(numbers[2][i]))
					{
						after_alpha = true;
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
}
