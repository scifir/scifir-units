#include "gene.hpp"

using namespace std;

namespace msci
{
	gene::gene() : name()
	{
	}

	gene::gene(vector_nitrogenous_bases new_bases,const string& new_name) : /*bases(new_bases),*/name(new_name)
	{
	}

	gene::gene(const string& bases_content,const string& new_name) : /*bases(),*/name(new_name)
	{

	}

	/*molecule gene::operator[](int x) const
	{

	}*/
}
