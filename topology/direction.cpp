#include "topology/direction.hpp"

#include "boost/algorithm/string.hpp"

#include <sstream>

using namespace std;

namespace msci
{
	direction::direction() : value(direction::NONE)
	{}
	
	direction::direction(const direction& x) : direction(x.value)
	{}
	
	direction::direction(direction&& x) : direction(move(x.value))
	{}

	direction::direction(direction::name new_direction) : value(new_direction)
	{}
	
	direction::direction(const string& new_direction) : value(create_direction(new_direction))
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
	
	direction::name create_direction(const string& x)
	{
		if (x == "left")
		{
			return direction::LEFT;
		}
		else if (x == "right")
		{
			return direction::RIGHT;
		}
		else if (x == "top")
		{
			return direction::TOP;
		}
		else if (x == "bottom")
		{
			return direction::BOTTOM;
		}
		else if (x == "front")
		{
			return direction::FRONT;
		}
		else if (x == "back")
		{
			return direction::BACK;
		}
		else if (x == "left-top")
		{
			return direction::LEFT_TOP;
		}
		else if (x == "left-bottom")
		{
			return direction::LEFT_BOTTOM;
		}
		else if (x == "right-top")
		{
			return direction::RIGHT_TOP;
		}
		else if (x == "right-bottom")
		{
			return direction::RIGHT_BOTTOM;
		}
		else if (x == "left-front")
		{
			return direction::LEFT_FRONT;
		}
		else if (x == "left-back")
		{
			return direction::LEFT_BACK;
		}
		else if (x == "right-front")
		{
			return direction::RIGHT_FRONT;
		}
		else if (x == "right-back")
		{
			return direction::RIGHT_BACK;
		}
		else if (x == "top-front")
		{
			return direction::TOP_FRONT;
		}
		else if (x == "top-back")
		{
			return direction::TOP_BACK;
		}
		else if (x == "bottom-front")
		{
			return direction::BOTTOM_FRONT;
		}
		else if (x == "bottom-back")
		{
			return direction::BOTTOM_BACK;
		}
		else if (x == "left-top-front")
		{
			return direction::LEFT_TOP_FRONT;
		}
		else if (x == "left-top-back")
		{
			return direction::LEFT_TOP_BACK;
		}
		else if (x == "left-bottom-front")
		{
			return direction::LEFT_BOTTOM_FRONT;
		}
		else if (x == "left-bottom-back")
		{
			return direction::LEFT_BOTTOM_BACK;
		}
		else if (x == "right-top-front")
		{
			return direction::RIGHT_TOP_FRONT;
		}
		else if (x == "right-top-back")
		{
			return direction::RIGHT_TOP_BACK;
		}
		else if (x == "right-bottom-front")
		{
			return direction::RIGHT_BOTTOM_FRONT;
		}
		else if (x == "right-bottom-back")
		{
			return direction::RIGHT_BOTTOM_BACK;
		}
		else
		{
			return direction::NONE;
		}
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
			return direction::NONE;
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
			case direction::NONE:
				return "";
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

bool operator ==(const msci::direction& x, const string& y)
{
	msci::direction y_direction = msci::direction(y);
	return (x == y_direction);
}

bool operator !=(const msci::direction& x, const string& y)
{
	return !(x == y);
}

bool operator ==(const string& x, const msci::direction& y)
{
	msci::direction x_direction = msci::direction(x);
	return (x_direction == y);
}

bool operator !=(const string& x, const msci::direction& y)
{
	return !(x == y);
}

void operator +=(string& x, const msci::direction& y)
{
	ostringstream output;
	output << y;
	x += output.str();
}

string operator +(const string& x, const msci::direction& y)
{
	ostringstream output;
	output << x;
	output << y;
	return output.str();
}

string operator +(const msci::direction& y, const string& x)
{
	ostringstream output;
	output << y;
	output << x;
	return output.str();
}

ostream& operator <<(ostream& os, const msci::direction& x)
{
	return os << to_string(x);
}

istream& operator >>(istream& is, msci::direction& x)
{
	char a[256];
	is.getline(a, 256);
	string b(a);
	boost::trim(b);
	msci::direction c(b);
	x = c;
	return is;
}
