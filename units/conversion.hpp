#ifndef SCIFIR_UNITS_UNITS_CONVERSION_HPP_INCLUDED
#define SCIFIR_UNITS_UNITS_CONVERSION_HPP_INCLUDED

#include "./dimension.hpp"

#include <string>

using namespace std;

namespace scifir
{
	class conversion
	{
		public:
			conversion();
			explicit conversion(const string& new_unit_to, float new_factor);
			explicit conversion(const string& new_unit_to, double new_factor);
			explicit conversion(const string& new_unit_to, long double new_factor);

			inline const long double& get_factor() const
			{
				return factor;
			}

			inline const string& get_unit_to() const
			{
				return unit_to;
			}

		private:
			string unit_to;
			long double factor;
	};

	extern map<string, conversion> get_conversion;
}

#endif // SCIFIR_UNITS_UNITS_CONVERSION_HPP_INCLUDED
