#ifndef CHEMISTRY_GENERAL_SUBSTANCE_SUBSTANCE_IA_HPP_INCLUDED
#define CHEMISTRY_GENERAL_SUBSTANCE_SUBSTANCE_IA_HPP_INCLUDED

using namespace std;

namespace chemistry
{
	class substance_Li
	{
		static const temperature melting_point;
		static const temperature boiling_point;
		static const density density_stp;

		static const molar_enthalpy heat_of_fusion;
		static const molar_enthalpy heat_of_vaporization;
		static const molar_heat_capacity heat_capacity;

		static const crystal_structure crystal_structure;
		static const thermal_conductivity thermal_conductivity;
		static const magnetic_ordering magnetic_ordering;
		static const magnetic_susceptibility magnetic_susceptibility;
	};
}

#endif // CHEMISTRY_GENERAL_SUBSTANCE_SUBSTANCE_IA_HPP_INCLUDED
