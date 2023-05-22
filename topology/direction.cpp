#include "msci/units/topology/direction.hpp"

#include <stdexcept>

using namespace std;

namespace msci
{
	direction::direction() : direction_value()
	{
	}

	direction::direction(direction_symbol new_direction) : direction_value(new_direction)
	{
	}

	void direction::operator =(direction_symbol new_direction)
	{
		direction_value = new_direction;
	}

	string direction::display() const
	{
		return direction_string(direction_value);
	}

	direction_lr::direction_lr() : direction()
	{
	}

	direction_lr::direction_lr(direction_symbol new_direction) : direction(new_direction)
	{
		if (!(new_direction == left or new_direction == right))
		{
			return;
		}
	}

	void direction_lr::operator =(direction_symbol new_direction)
	{
		if (!(new_direction == left or new_direction == right))
		{
			return;
		}
		direction_value = new_direction;
	}

	string direction_lr::display() const
	{
		return direction_string(direction_value);
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
		return left;
	}

	string direction_string(direction_symbol x)
	{
		switch (x)
		{
			case left:
				return "left";
			case right:
				return "right";
			case top:
				return "top";
			case bottom:
				return "bottom";
			case front:
				return "front";
			case back:
				return "back";
			case left_top:
				return "left-top";
			case left_bottom:
				return "left-bottom";
			case right_top:
				return "right-top";
			case right_bottom:
				return "right-bottom";
			case left_front:
				return "left-front";
			case left_back:
				return "left-back";
			case right_front:
				return "right-front";
			case right_back:
				return "right-back";
			case top_front:
				return "top-front";
			case top_back:
				return "top-back";
			case bottom_front:
				return "bottom-front";
			case bottom_back:
				return "bottom-back";
			case left_top_front:
				return "left-top-front";
			case left_top_back:
				return "left-top-back";
			case left_bottom_front:
				return "left-bottom-front";
			case left_bottom_back:
				return "left-bottom-back";
			case right_top_front:
				return "right-top-front";
			case right_top_back:
				return "right-top-back";
			case right_bottom_front:
				return "right-bottom-front";
			case right_bottom_back:
				return "right-bottom-back";
		}
	}
}

bool operator ==(const msci::direction& x, const msci::direction& y)
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

bool operator !=(const msci::direction& x, const msci::direction& y)
{
	return !(x == y);
}

bool operator ==(const msci::direction& x, msci::direction_symbol y)
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

bool operator !=(const msci::direction& x, msci::direction_symbol y)
{
	return !(x == y);
}

bool operator ==(msci::direction_symbol y, const msci::direction& x)
{
	return (x == y);
}

bool operator !=(msci::direction_symbol y, const msci::direction& x)
{
	return !(x == y);
}

bool operator ==(const msci::direction_lr& x, const msci::direction_lr& y)
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

bool operator !=(const msci::direction_lr& x, const msci::direction_lr& y)
{
	return !(x == y);
}

bool operator ==(const msci::direction_lr& x, msci::direction_symbol y)
{
	if (!(y == msci::left or y == msci::right))
	{
		return false;
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

bool operator !=(const msci::direction_lr& x, msci::direction_symbol y)
{
	return !(x == y);
}

bool operator ==(msci::direction_symbol y, const msci::direction_lr& x)
{
	return (x == y);
}

bool operator !=(msci::direction_symbol y, const msci::direction_lr& x)
{
	return !(x == y);
}

ostream& operator <<(ostream& os, const msci::direction& x)
{
	return os << x.display();
}

ostream& operator <<(ostream& os, const msci::direction_lr& x)
{
	return os << x.display();
}
