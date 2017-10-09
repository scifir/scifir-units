#include "line_2d.hpp"

#include <sstream>

using namespace std;

namespace msci
{
	line_2d::line_2d() : vertex1(),vertex2()
	{
	}

	line_2d::line_2d(const point_2d& x,const point_2d& y) : vertex1(x),vertex2(y)
	{
	}

	length line_2d::get_length() const
	{
		space_type value = distance_between_points(vertex1,vertex2);
		return length(value,"m");
	}

	wstring line_2d::display() const
	{
		wostringstream out;
		out << "2d line: " << vertex1 << " " << vertex2;
		return out.str().c_str();
	}

	void line_2d::print() const
	{
		wcout << display() << endl;
	}
}

bool operator ==(const msci::line_2d& x,const msci::line_2d& y)
{
	return (x.get_vertex1() == y.get_vertex1() and x.get_vertex2() == y.get_vertex2());
}

bool operator !=(const msci::line_2d& x,const msci::line_2d& y)
{
	return !(x == y);
}

wostream& operator <<(wostream& os,const msci::line_2d& x)
{
	return os << x.display();
}
