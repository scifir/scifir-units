#ifndef DIMENSION_CONTAINER_HPP_INCLUDED
#define DIMENSION_CONTAINER_HPP_INCLUDED

#include "abbreviation.hpp"
#include "dimension.hpp"
#include "dimension_abstract.hpp"
#include "prefix.hpp"

#include <map>
#include <string>
#include <vector>

using namespace std;

namespace physics::units
{
	class unit_actual_dimensions : public map<int,shared_ptr<dimension_abstract>>
	{
		public:
			unit_actual_dimensions();
			unit_actual_dimensions(const unit_actual_dimensions&);
	};

	class unit_real_dimensions : public map<int,shared_ptr<dimension>>
	{
		public:
			unit_real_dimensions();
			unit_real_dimensions(const unit_real_dimensions&);
	};

	string get_dimension_structure(const unit_actual_dimensions&);

	unit_actual_dimensions multiply_actual_dimensions(const unit_actual_dimensions&,const unit_actual_dimensions&);
	unit_real_dimensions multiply_real_dimensions(const unit_real_dimensions&,const unit_real_dimensions&);
	unit_actual_dimensions divide_actual_dimensions(const unit_actual_dimensions&,const unit_actual_dimensions&);
	unit_real_dimensions divide_real_dimensions(const unit_real_dimensions&,const unit_real_dimensions&);
}

#endif // DIMENSION_CONTAINER_HPP_INCLUDED
