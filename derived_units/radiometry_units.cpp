#include "./radiometry_units.hpp"

using namespace std;

namespace scifir
{
	SCALAR_UNIT_CPP(radioactivity,"Bq");
	VECTOR_UNIT_CPP(irradiance,"kg/s3");
	VECTOR_UNIT_CPP(radiant_exposure,"kg/s2");
	SCALAR_UNIT_CPP(radiant_intensity,"kg*m2/s3");
	SCALAR_UNIT_CPP(radiance,"kg/s3");
	SCALAR_UNIT_CPP(spectral_radiance,"kg/m*s3");
	VECTOR_UNIT_CPP(radiant_flux,"kg*m2/s3");
	VECTOR_UNIT_CPP(spectral_flux,"kg*m/s3");
}
