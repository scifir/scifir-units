#ifndef PHYSICS_BASIC_FIELDS_FIELD_HPP_INCLUDED
#define PHYSICS_BASIC_FIELDS_FIELD_HPP_INCLUDED

using namespace std;

namespace msci
{
	class field
	{
		public:
			field();

		protected:
			msci::unit_number value;
			vector_actual_dimensions actual_dimensions;
	};
}

#endif // PHYSICS_BASIC_FIELDS_FIELD_HPP_INCLUDED
