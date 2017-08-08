#include "units.hpp"

namespace physics::units
{
	const string distance::dimensions_match = "m";
	const vector_real_dimensions distance::real_dimensions = create_real_dimensions(distance::dimensions_match);
	const string velocity::dimensions_match = "m/s";
	const vector_real_dimensions velocity::real_dimensions = create_real_dimensions(velocity::dimensions_match);
	const string acceleration::dimensions_match = "m/s2";
	const vector_real_dimensions acceleration::real_dimensions = create_real_dimensions(acceleration::dimensions_match);
	const string jerk::dimensions_match = "m/s3";
	const vector_real_dimensions jerk::real_dimensions = create_real_dimensions(jerk::dimensions_match);
	const string snap::dimensions_match = "m/s4";
	const vector_real_dimensions snap::real_dimensions = create_real_dimensions(snap::dimensions_match);
	const string angular_velocity::dimensions_match = "rad/s";
	const vector_real_dimensions angular_velocity::real_dimensions = create_real_dimensions(angular_velocity::dimensions_match);
	const string angular_acceleration::dimensions_match = "rad/s2";
	const vector_real_dimensions angular_acceleration::real_dimensions = create_real_dimensions(angular_acceleration::dimensions_match);
	const string angular_momentum::dimensions_match = "m2*kg/s";
	const vector_real_dimensions angular_momentum::real_dimensions = create_real_dimensions(angular_momentum::dimensions_match);
}
