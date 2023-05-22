#ifndef MSCI_UNITS_FIELDS_FIELD_HPP_INCLUDED
#define MSCI_UNITS_FIELDS_FIELD_HPP_INCLUDED

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

#endif // MSCI_UNITS_FIELDS_FIELD_HPP_INCLUDED
