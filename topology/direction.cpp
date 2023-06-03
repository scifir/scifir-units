#include "topology/direction.hpp"

#include <stdexcept>

using namespace std;

namespace msci
{
	direction::direction() : value()
	{}
	
	direction::direction(const direction& x) : direction(x.value)
	{}
	
	direction::direction(direction&& x) : direction(move(x.value))
	{}

	direction::direction(direction::name new_direction) : value(new_direction)
	{}
	
	void direction::operator=(const direction& x)
	{
		value = x.value;
	}
	
	void direction::operator=(direction&& x)
	{
		value = move(x.value);
	}
	
	void direction::operator =(direction::name new_direction)
	{
		value = new_direction;
	}
	
	void direction::invert()
	{
		value = msci::invert(value);
	}

	direction::name invert(direction::name x)
	{
		if (x == direction::LEFT)
		{
			return direction::RIGHT;
		}
		else if (x == direction::RIGHT)
		{
			return direction::LEFT;
		}
		else if (x == direction::TOP)
		{
			return direction::BOTTOM;
		}
		else if (x == direction::BOTTOM)
		{
			return direction::TOP;
		}
		else if (x == direction::FRONT)
		{
			return direction::BACK;
		}
		else if (x == direction::BACK)
		{
			return direction::FRONT;
		}
		else if (x == direction::LEFT_TOP)
		{
			return direction::RIGHT_BOTTOM;
		}
		else if (x == direction::LEFT_BOTTOM)
		{
			return direction::RIGHT_TOP;
		}
		else if (x == direction::RIGHT_TOP)
		{
			return direction::LEFT_BOTTOM;
		}
		else if (x == direction::RIGHT_BOTTOM)
		{
			return direction::LEFT_TOP;
		}
		else if (x == direction::LEFT_FRONT)
		{
			return direction::RIGHT_BACK;
		}
		else if (x == direction::LEFT_BACK)
		{
			return direction::RIGHT_FRONT;
		}
		else if (x == direction::RIGHT_FRONT)
		{
			return direction::LEFT_BACK;
		}
		else if (x == direction::RIGHT_BACK)
		{
			return direction::LEFT_FRONT;
		}
		else if (x == direction::TOP_FRONT)
		{
			return direction::BOTTOM_BACK;
		}
		else if (x == direction::TOP_BACK)
		{
			return direction::BOTTOM_FRONT;
		}
		else if (x == direction::BOTTOM_FRONT)
		{
			return direction::TOP_BACK;
		}
		else if (x == direction::BOTTOM_BACK)
		{
			return direction::TOP_FRONT;
		}
		else if (x == direction::LEFT_TOP_FRONT)
		{
			return direction::RIGHT_BOTTOM_BACK;
		}
		else if (x == direction::LEFT_TOP_BACK)
		{
			return direction::RIGHT_BOTTOM_FRONT;
		}
		else if (x == direction::LEFT_BOTTOM_FRONT)
		{
			return direction::RIGHT_TOP_BACK;
		}
		else if (x == direction::LEFT_BOTTOM_BACK)
		{
			return direction::RIGHT_TOP_FRONT;
		}
		else if (x == direction::RIGHT_TOP_FRONT)
		{
			return direction::LEFT_BOTTOM_BACK;
		}
		else if (x == direction::RIGHT_TOP_BACK)
		{
			return direction::LEFT_BOTTOM_FRONT;
		}
		else if (x == direction::RIGHT_BOTTOM_FRONT)
		{
			return direction::LEFT_TOP_BACK;
		}
		else if (x == direction::RIGHT_BOTTOM_BACK)
		{
			return direction::LEFT_TOP_FRONT;
		}
		else
		{
			return direction::LEFT;
		}
	}

	string to_string(direction::name x)
	{
		switch (x)
		{
			case direction::LEFT:
				return "left";
			case direction::RIGHT:
				return "right";
			case direction::TOP:
				return "top";
			case direction::BOTTOM:
				return "bottom";
			case direction::FRONT:
				return "front";
			case direction::BACK:
				return "back";
			case direction::LEFT_TOP:
				return "left-top";
			case direction::LEFT_BOTTOM:
				return "left-bottom";
			case direction::RIGHT_TOP:
				return "right-top";
			case direction::RIGHT_BOTTOM:
				return "right-bottom";
			case direction::LEFT_FRONT:
				return "left-front";
			case direction::LEFT_BACK:
				return "left-back";
			case direction::RIGHT_FRONT:
				return "right-front";
			case direction::RIGHT_BACK:
				return "right-back";
			case direction::TOP_FRONT:
				return "top-front";
			case direction::TOP_BACK:
				return "top-back";
			case direction::BOTTOM_FRONT:
				return "bottom-front";
			case direction::BOTTOM_BACK:
				return "bottom-back";
			case direction::LEFT_TOP_FRONT:
				return "left-top-front";
			case direction::LEFT_TOP_BACK:
				return "left-top-back";
			case direction::LEFT_BOTTOM_FRONT:
				return "left-bottom-front";
			case direction::LEFT_BOTTOM_BACK:
				return "left-bottom-back";
			case direction::RIGHT_TOP_FRONT:
				return "right-top-front";
			case direction::RIGHT_TOP_BACK:
				return "right-top-back";
			case direction::RIGHT_BOTTOM_FRONT:
				return "right-bottom-front";
			case direction::RIGHT_BOTTOM_BACK:
				return "right-bottom-back";
		}
		return "";
	}
	
	string to_string(const direction& x)
	{
		return to_string(x.value);
	}
}

bool operator ==(const msci::direction& x, const msci::direction& y)
{
	if(x.value == y.value)
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

bool operator ==(const msci::direction& x, msci::direction::name y)
{
	if(x.value == y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const msci::direction& x, msci::direction::name y)
{
	return !(x == y);
}

bool operator ==(msci::direction::name y, const msci::direction& x)
{
	return (x == y);
}

bool operator !=(msci::direction::name y, const msci::direction& x)
{
	return !(x == y);
}

ostream& operator <<(ostream& os, const msci::direction& x)
{
	return os << to_string(x);
}
