#ifndef CHEMISTRY_LABORATORY_SUBSTANCE_SUBSTANCE_HPP_INCLUDED
#define CHEMISTRY_LABORATORY_SUBSTANCE_SUBSTANCE_HPP_INCLUDED

#include "chemistry/laboratory/analysis/crystallograph.hpp"
#include "chemistry/laboratory/analysis/spectrometer.hpp"

#include "units.hpp"

using namespace std;

namespace msci::laboratory
{
	class substance
	{
		public:
			substance();
			substance(spectrometer_data, crystallographic_data);

			const density& get_density() const;
			const volume& get_volume() const;
			const mass& get_mass() const;

			const spectrometer_data& get_spectrometer_data() const;
			const crystallographic_data& get_crystallographic_data() const;

			bool is_homogeneous() const;
			bool is_mixture() const;

		private:
			volume V;
			mass m;
			spectrometer_data substance_spectrometer_data;
			crystallographic_data substance_crystallographic_data;
	};
}

#endif // CHEMISTRY_LABORATORY_SUBSTANCE_SUBSTANCE_HPP_INCLUDED
