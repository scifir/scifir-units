#include "./coordinates_3dr.hpp"

using namespace std;

namespace scifir
{
	string to_string(const coordinates_3dr<float>& x)
	{
		ostringstream out;
		out << "(" << display_float(x.x) << "," << display_float(x.y) << "," << display_float(x.z) << ";" << x.theta << "," << x.phi << ")";
		return out.str();
	}

	float distance(const coordinates_3dr<float>& x,const coordinates_3dr<float>& y)
	{
		return float(std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2) + std::pow(x.z - y.z,2)));
	}

	float distance(const coordinates_3dr<float>& x,const coordinates_3d<float>& y)
	{
		return float(std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2) + std::pow(x.z - y.z,2)));
	}

	float distance(const coordinates_3d<float>& x,const coordinates_3dr<float>& y)
	{
		return float(std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2) + std::pow(x.z - y.z,2)));
	}

	float distance(const coordinates_3dr<float>& x,const point_3d<float>& y)
	{
		return float(std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2) + std::pow(x.z - y.z,2)));
	}

	float distance(const point_3d<float>& x,const coordinates_3dr<float>& y)
	{
		return float(std::sqrt(std::pow(x.x - y.x,2) + std::pow(x.y - y.y,2) + std::pow(x.z - y.z,2)));
	}
}
