#include "units.hpp"

using namespace std;

namespace physics::units
{
	const string polarization_density::dimensions_match = "A*s/m2";
	const string magnetic_permeability::dimensions_match = "A2*s2/kg*m";
	const string magnetization::dimensions_match = "A/m";
	const string magnetic_moment::dimensions_match = "A*m2";
	const string magnetic_reluctance::dimensions_match = "A2*s2/kg*m2";
	const string magnetic_vector_potential::dimensions_match = "kg*m/A*s2";
	const string magnetic_rigidity::dimensions_match = "kg*m/A*s2";
	const string magnetomotive_force::dimensions_match = "A";
	const string magnetic_susceptibility::dimensions_match = "A2*s2/kg*m";
}
