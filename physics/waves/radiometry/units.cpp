#include "units.hpp"

using namespace std;

namespace physics::units
{
	const string irradiance::dimensions_match = "kg/s3";
	const string radiant_exposure::dimensions_match = "kg/s2";
	const string radiant_intensity::dimensions_match = "kg*m2/s3";
	const string spectral_intensity::dimensions_match = "kg*m/s3";
	const string radiance::dimensions_match = "kg/s3";
	const string spectral_radiance::dimensions_match = "kg/m*s3";
	const string radiant_flux::dimensions_match = "kg*m2/s3";
	const string spectral_flux::dimensions_match = "kg/m/s3";
}
