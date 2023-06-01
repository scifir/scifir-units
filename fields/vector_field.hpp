#ifndef MSCI_UNITS_FIELDS_VECTOR_FIELD_HPP_INCLUDED
#define MSCI_UNITS_FIELDS_VECTOR_FIELD_HPP_INCLUDED

using namespace std;

namespace msci
{
	template<typename T>
	class vector_field
	{
		public:
			vector_field();
			vector_field(const vector_field&);
			vector_field(vector_field&&);
			
			T get_value(float,float,float) const;
			
		private:
			string algebraic_function;
	};
}

#endif // MSCI_UNITS_FIELDS_VECTOR_FIELD_HPP_INCLUDED
