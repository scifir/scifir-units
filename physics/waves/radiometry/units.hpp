#ifndef PHYSICS_WAVES_RADIOMETRY_UNITS_HPP_INCLUDED
#define PHYSICS_WAVES_RADIOMETRY_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"

using namespace std;

namespace physics::units
{
	class irradiance : public vector_unit<irradiance>
	{
		public:
			using vector_unit::vector_unit;

			static const string dimensions_match;
	};

	class radiant_exposure : public vector_unit<radiant_exposure>
	{
		public:
			using vector_unit::vector_unit;

			static const string dimensions_match;
	};

	class radiant_intensity : public scalar_unit<radiant_intensity>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class spectral_intensity : public scalar_unit<spectral_intensity>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class radiance : public scalar_unit<radiance>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class spectral_radiance : public scalar_unit<spectral_radiance>
	{
		public:
			using scalar_unit::scalar_unit;

			static const string dimensions_match;
	};

	class radiant_flux : public vector_unit<radiant_flux>
	{
		public:
			using vector_unit::vector_unit;

			static const string dimensions_match;
	};

	class spectral_flux : public vector_unit<spectral_flux>
	{
		public:
			using vector_unit::vector_unit;

			static const string dimensions_match;
	};
}

#endif // PHYSICS_WAVES_RADIOMETRY_UNITS_HPP_INCLUDED
