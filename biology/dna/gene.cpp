#include "gene.hpp"

using namespace std;

namespace biology
{
	gene::gene() : name()
	{
	}

	gene::gene(vector_nitrogenous_bases new_bases,string new_name) : /*bases(new_bases),*/name(new_name)
	{
	}

	gene::gene(string bases_content,string new_name) : /*bases(),*/name(new_name)
	{

	}

	/*molecule gene::operator[](int x) const
	{

	}*/
}
