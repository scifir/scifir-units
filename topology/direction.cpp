#include "topology/direction.hpp"

#include <stdexcept>

using namespace std;

namespace msci
{
	direction::direction() : direction_value()
	{
	}

	direction::direction(direction::value new_direction) : direction_value(new_direction)
	{
	}
	
	void direction::invert()
	{
		direction_value = opposite_direction(direction_value);
	}

	void direction::operator =(direction::value new_direction)
	{
		direction_value = new_direction;
	}

	string direction::display() const
	{
		return direction_string(direction_value);
	}

	direction::value opposite_direction(direction::value x)
	{
		if (x == direction::left)
		{
			return direction::right;
		}
		else if (x == direction::right)
		{
			return direction::left;
		}
		else if (x == direction::top)
		{
			return direction::bottom;
		}
		else if (x == direction::bottom)
		{
			return direction::top;
		}
		else if (x == direction::front)
		{
			return direction::back;
		}
		else if (x == direction::back)
		{
			return direction::front;
		}
		else if (x == direction::left_top)
		{
			return direction::right_bottom;
		}
		else if (x == direction::left_bottom)
		{
			return direction::right_top;
		}
		else if (x == direction::right_top)
		{
			return direction::left_bottom;
		}
		else if (x == direction::right_bottom)
		{
			return direction::left_top;
		}
		else if (x == direction::left_front)
		{
			return direction::right_back;
		}
		else if (x == direction::left_back)
		{
			return direction::right_front;
		}
		else if (x == direction::right_front)
		{
			return direction::left_back;
		}
		else if (x == direction::right_back)
		{
			return direction::left_front;
		}
		else if (x == direction::top_front)
		{
			return direction::bottom_back;
		}
		else if (x == direction::top_back)
		{
			return direction::bottom_front;
		}
		else if (x == direction::bottom_front)
		{
			return direction::top_back;
		}
		else if (x == direction::bottom_back)
		{
			return direction::top_front;
		}
		else if (x == direction::left_top_front)
		{
			return direction::right_bottom_back;
		}
		else if (x == direction::left_top_back)
		{
			return direction::right_bottom_front;
		}
		else if (x == direction::left_bottom_front)
		{
			return direction::right_top_back;
		}
		else if (x == direction::left_bottom_back)
		{
			return direction::right_top_front;
		}
		else if (x == direction::right_top_front)
		{
			return direction::left_bottom_back;
		}
		else if (x == direction::right_top_back)
		{
			return direction::left_bottom_front;
		}
		else if (x == direction::right_bottom_front)
		{
			return direction::left_top_back;
		}
		else if (x == direction::right_bottom_back)
		{
			return direction::left_top_front;
		}
		else
		{
			return direction::left;
		}
	}

	string direction_string(direction::value x)
	{
		switch (x)
		{
			case direction::left:
				return "left";
			case direction::right:
				return "right";
			case direction::top:
				return "top";
			case direction::bottom:
				return "bottom";
			case direction::front:
				return "front";
			case direction::back:
				return "back";
			case direction::left_top:
				return "left-top";
			case direction::left_bottom:
				return "left-bottom";
			case direction::right_top:
				return "right-top";
			case direction::right_bottom:
				return "right-bottom";
			case direction::left_front:
				return "left-front";
			case direction::left_back:
				return "left-back";
			case direction::right_front:
				return "right-front";
			case direction::right_back:
				return "right-back";
			case direction::top_front:
				return "top-front";
			case direction::top_back:
				return "top-back";
			case direction::bottom_front:
				return "bottom-front";
			case direction::bottom_back:
				return "bottom-back";
			case direction::left_top_front:
				return "left-top-front";
			case direction::left_top_back:
				return "left-top-back";
			case direction::left_bottom_front:
				return "left-bottom-front";
			case direction::left_bottom_back:
				return "left-bottom-back";
			case direction::right_top_front:
				return "right-top-front";
			case direction::right_top_back:
				return "right-top-back";
			case direction::right_bottom_front:
				return "right-bottom-front";
			case direction::right_bottom_back:
				return "right-bottom-back";
		}
		return "";
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

bool operator ==(const msci::direction& x, msci::direction::value y)
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

bool operator !=(const msci::direction& x, msci::direction::value y)
{
	return !(x == y);
}

bool operator ==(msci::direction::value y, const msci::direction& x)
{
	return (x == y);
}

bool operator !=(msci::direction::value y, const msci::direction& x)
{
	return !(x == y);
}

ostream& operator <<(ostream& os, const msci::direction& x)
{
	return os << x.display();
}
