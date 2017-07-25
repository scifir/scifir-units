#include "units.hpp"

using namespace std;

namespace physics::units
{
	const string impulse::dimensions_match = "m*kg/s";
	const string force::dimensions_match = "kg*m/s2";
	const string torque::dimensions_match = "kg*m2/s2";
	const string pressure::dimensions_match = "kg/m*s2";
	const string surface_tension::dimensions_match = "kg/s2";
	const string stiffness::dimensions_match = "kg/s2";
	const string moment_of_inertia::dimensions_match = "m2*kg";
}
