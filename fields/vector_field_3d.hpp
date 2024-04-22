#ifndef SCIFIR_UNITS_FIELDS_VECTOR_FIELD_3D_HPP_INCLUDED
#define SCIFIR_UNITS_FIELDS_VECTOR_FIELD_3D_HPP_INCLUDED

#include "../units/scalar_unit.hpp"

#include <string>

using namespace std;

namespace scifir
{
	template<typename T>
	class vector_field_3d
	{
		public:
			vector_field_3d() : algebraic_function()
			{}
			
			vector_field_3d(const vector_field_3d& x) : algebraic_function(x.algebraic_function)
			{}
			
			vector_field_3d(vector_field_3d&& x) : algebraic_function(move(x.algebraic_function))
			{}
			
			vector_field_3d& operator=(const vector_field_3d& x)
			{
				algebraic_function = x.algebraic_function;
			}
			
			vector_field_3d& operator=(vector_field_3d&& x)
			{
				algebraic_function = move(x.algebraic_function);
			}
			
			T get_value(float,float,float) const
			{
				return T();
			}
			
			T get_value(const scalar_unit&,const scalar_unit&,const scalar_unit&) const
			{
				return T();
			}

			string algebraic_function;
	};
}

#endif // SCIFIR_UNITS_FIELDS_VECTOR_FIELD_3D_HPP_INCLUDED
