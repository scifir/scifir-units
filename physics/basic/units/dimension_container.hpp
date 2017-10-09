#ifndef DIMENSION_CONTAINER_HPP_INCLUDED
#define DIMENSION_CONTAINER_HPP_INCLUDED

#include "abbreviation.hpp"
#include "dimension.hpp"
#include "dimension_abstract.hpp"
#include "prefix.hpp"

#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace msci
{
	class vector_actual_dimensions : public map<int,shared_ptr<dimension_abstract>>
	{
		public:
			vector_actual_dimensions();
			vector_actual_dimensions(const vector_actual_dimensions&);
	};

	class vector_real_dimensions : public map<int,shared_ptr<dimension>>
	{
		public:
			vector_real_dimensions();
			vector_real_dimensions(const vector_real_dimensions&);
	};

	string get_dimension_structure(const vector_actual_dimensions&);
	string get_dimension_structure(const vector_real_dimensions&);
	vector_real_dimensions create_real_dimensions(string);
	vector_actual_dimensions create_actual_dimensions(string);

	vector_actual_dimensions multiply_actual_dimensions(const vector_actual_dimensions&,const vector_actual_dimensions&);
	vector_real_dimensions multiply_real_dimensions(const vector_real_dimensions&,const vector_real_dimensions&);
	vector_actual_dimensions divide_actual_dimensions(const vector_actual_dimensions&,const vector_actual_dimensions&);
	vector_real_dimensions divide_real_dimensions(const vector_real_dimensions&,const vector_real_dimensions&);
	vector_actual_dimensions power_actual_dimensions(const vector_actual_dimensions&,int);
	vector_real_dimensions power_real_dimensions(const vector_real_dimensions&,int);
}

wostream& operator <<(wostream&, const msci::vector_real_dimensions&);
wostream& operator <<(wostream&, const msci::vector_actual_dimensions&);

#endif // DIMENSION_CONTAINER_HPP_INCLUDED
