#include "./units.hpp"

namespace physics::units
{
	SCALAR_UNIT_CPP(distance,"m");
	VECTOR_UNIT_CPP(velocity,"m/s");
	VECTOR_UNIT_CPP(acceleration,"m/s2");
	VECTOR_UNIT_CPP(jerk,"m/s3");
	VECTOR_UNIT_CPP(snap,"m/s4");
	VECTOR_UNIT_CPP(angular_velocity,"rad/s");
	VECTOR_UNIT_CPP(angular_acceleration,"rad/s2");
	VECTOR_UNIT_CPP(angular_momentum,"m2*kg/s");
}
