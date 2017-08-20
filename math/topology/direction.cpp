#include "direction.hpp"

#include <stdexcept>

using namespace std;

namespace math
{
	direction::direction(direction_symbol new_direction) : direction_value(new_direction)
	{
	}

	const direction_symbol& direction::get_direction() const
	{
		return direction_value;
	}

	void direction::invert()
	{
		direction_value = opposite_direction(direction_value);
	}

	void direction::operator =(direction_symbol new_direction)
	{
		direction_value = new_direction;
	}

	direction_lr::direction_lr(direction_symbol new_direction) : direction(new_direction)
	{
		if (!(new_direction == left or new_direction == right))
		{
			throw invalid_argument("Invalid direction. Only left and right allowed");
		}
	}

	void direction_lr::operator =(direction_symbol new_direction)
	{
		if (!(new_direction == left or new_direction == right))
		{
			throw invalid_argument("Invalid direction. Only left and right allowed");
		}
		direction_value = new_direction;
	}

	bool direction_lr::goes_left()
	{
		return (direction_value == left);
	}

	bool direction_lr::goes_right()
	{
		return (direction_value == right);
	}

	void direction_lr::go_left()
	{
		direction_value = left;
	}

	void direction_lr::go_right()
	{
		direction_value = right;
	}

	direction_symbol opposite_direction(direction_symbol x)
	{
		if (x == left)
		{
			return right;
		}
		else if (x == right)
		{
			return left;
		}
		else if (x == top)
		{
			return bottom;
		}
		else if (x == bottom)
		{
			return top;
		}
		else if (x == front)
		{
			return back;
		}
		else if (x == back)
		{
			return front;
		}
		else if (x == left_top)
		{
			return right_bottom;
		}
		else if (x == left_bottom)
		{
			return right_top;
		}
		else if (x == right_top)
		{
			return left_bottom;
		}
		else if (x == right_bottom)
		{
			return left_top;
		}
		else if (x == left_front)
		{
			return right_back;
		}
		else if (x == left_back)
		{
			return right_front;
		}
		else if (x == right_front)
		{
			return left_back;
		}
		else if (x == right_back)
		{
			return left_front;
		}
		else if (x == top_front)
		{
			return bottom_back;
		}
		else if (x == top_back)
		{
			return bottom_front;
		}
		else if (x == bottom_front)
		{
			return top_back;
		}
		else if (x == bottom_back)
		{
			return top_front;
		}
		else if (x == left_top_front)
		{
			return right_bottom_back;
		}
		else if (x == left_top_back)
		{
			return right_bottom_front;
		}
		else if (x == left_bottom_front)
		{
			return right_top_back;
		}
		else if (x == left_bottom_back)
		{
			return right_top_front;
		}
		else if (x == right_top_front)
		{
			return left_bottom_back;
		}
		else if (x == right_top_back)
		{
			return left_bottom_front;
		}
		else if (x == right_bottom_front)
		{
			return left_top_back;
		}
		else if (x == right_bottom_back)
		{
			return left_top_front;
		}
	}
}

bool operator ==(const math::direction& x, const math::direction& y)
{
	if(x.get_direction() == y.get_direction())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const math::direction& x, const math::direction& y)
{
	return !(x == y);
}

bool operator ==(const math::direction& x, math::direction_symbol y)
{
	if(x.get_direction() == y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const math::direction& x, math::direction_symbol y)
{
	return !(x == y);
}

bool operator ==(math::direction_symbol y, const math::direction& x)
{
	return (x == y);
}

bool operator !=(math::direction_symbol y, const math::direction& x)
{
	return !(x == y);
}

bool operator ==(const math::direction_lr& x, const math::direction_lr& y)
{
	if(x.get_direction() == y.get_direction())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const math::direction_lr& x, const math::direction_lr& y)
{
	return !(x == y);
}

bool operator ==(const math::direction_lr& x, math::direction_symbol y)
{
	if (!(y == math::left or y == math::right))
	{
		throw invalid_argument("direction_lr cannot be compared with a direction different than left or right");
	}
	if(x.get_direction() == y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const math::direction_lr& x, math::direction_symbol y)
{
	return !(x == y);
}

bool operator ==(math::direction_symbol y, const math::direction_lr& x)
{
	return (x == y);
}

bool operator !=(math::direction_symbol y, const math::direction_lr& x)
{
	return !(x == y);
}
