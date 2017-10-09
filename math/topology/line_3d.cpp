#include "line_3d.hpp"

#include <sstream>

using namespace std;

namespace msci
{
	line_3d::line_3d() : vertex1(),vertex2()
	{
	}

	line_3d::line_3d(const point_3d& x,const point_3d& y) : vertex1(x),vertex2(y)
	{
	}

	length line_3d::get_length() const
	{
		space_type value = distance_between_points(vertex1,vertex2);
		return length(value,"m");
	}

	wstring line_3d::display() const
	{
		wostringstream out;
		out << "3d line: " << vertex1 << " " << vertex2;
		return out.str().c_str();
	}

	void line_3d::print() const
	{
		wcout << display() << endl;
	}
}

bool operator ==(const msci::line_3d& x,const msci::line_3d& y)
{
	return (x.get_vertex1() == y.get_vertex1() and x.get_vertex2() == y.get_vertex2());
}

bool operator !=(const msci::line_3d& x,const msci::line_3d& y)
{
	return !(x == y);
}

wostream& operator <<(wostream& os,const msci::line_3d& x)
{
	return os << x.display();
}
