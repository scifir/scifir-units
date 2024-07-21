#ifndef SCIFIR_UNITS_PREDEFINED_UNITS_KINEMATICS_UNITS_HPP_INCLUDED
#define SCIFIR_UNITS_PREDEFINED_UNITS_KINEMATICS_UNITS_HPP_INCLUDED

#include "../units/scalar_unit.hpp"
#include "../units/vector_unit_2d.hpp"
#include "../units/vector_unit_3d.hpp"
#include "../units/unit_basic.hpp"

using namespace std;

namespace scifir
{
	// KINEMATICS
	VECTOR_UNIT_2D_HPP(displacement);
	VECTOR_UNIT_3D_HPP(displacement);
	VECTOR_UNIT_ND_HPP(displacement);
	VECTOR_UNIT_HPP(velocity);
	VECTOR_UNIT_HPP(acceleration);
	VECTOR_UNIT_HPP(jerk);
	VECTOR_UNIT_HPP(snap);
	VECTOR_UNIT_HPP(angular_velocity);
	VECTOR_UNIT_HPP(angular_acceleration);
	VECTOR_UNIT_HPP(angular_momentum);

	// DYNAMICS
	VECTOR_UNIT_HPP(impulse);
	VECTOR_UNIT_HPP(force);
	VECTOR_UNIT_HPP(torque);
	VECTOR_UNIT_HPP(pressure);
	VECTOR_UNIT_HPP(surface_tension);
	SCALAR_UNIT_HPP(stiffness);
	SCALAR_UNIT_HPP(moment_of_inertia);

	// ELECTRICITY
	SCALAR_UNIT_HPP(electric_current);
	SCALAR_UNIT_HPP(voltage);
	VECTOR_UNIT_HPP(electric_displacement_field);  // TODO: vector_field
	SCALAR_UNIT_HPP(electric_charge_density);
	SCALAR_UNIT_HPP(electric_current_density);
	VECTOR_UNIT_HPP(electric_field_strength);
	SCALAR_UNIT_HPP(electron_mobility);
	SCALAR_UNIT_HPP(inductance);

	// FLUID DYNAMICS
	SCALAR_UNIT_HPP(volumetric_flow);
	SCALAR_UNIT_HPP(diffusion_coefficient);
	SCALAR_UNIT_HPP(compressibility);

	// MAGNETISM
	SCALAR_UNIT_HPP(polarization_density); // TODO: vector_field
	SCALAR_UNIT_HPP(magnetic_permeability); // TODO: vector_field
	SCALAR_UNIT_HPP(magnetization); // TODO: vector_field
	SCALAR_UNIT_HPP(magnetic_flux);
	VECTOR_UNIT_HPP(magnetic_strength); // TODO: vector_field
	VECTOR_UNIT_HPP(magnetic_moment);
	SCALAR_UNIT_HPP(magnetic_reluctance);
	VECTOR_UNIT_HPP(magnetic_vector_potential); // TODO: vector_field
	SCALAR_UNIT_HPP(magnetic_rigidity);
	VECTOR_UNIT_HPP(magnetomotive_force);
	SCALAR_UNIT_HPP(magnetic_susceptibility);

	// OPTICS
	SCALAR_UNIT_HPP(optical_power);
	SCALAR_UNIT_HPP(luminance);
	SCALAR_UNIT_HPP(illuminance);
	SCALAR_UNIT_HPP(luminous_flux);
	SCALAR_UNIT_HPP(luminous_energy);
	SCALAR_UNIT_HPP(luminous_exposure);
	SCALAR_UNIT_HPP(luminous_efficacy);
	SCALAR_UNIT_HPP(ionizing_radiation);
	SCALAR_UNIT_HPP(absorbed_dose);

	// THERMODYNAMICS
	SCALAR_UNIT_HPP(energy);
	SCALAR_UNIT_HPP(action);
	SCALAR_UNIT_HPP(power);
	SCALAR_UNIT_HPP(power_density);
	SCALAR_UNIT_HPP(entropy);
	SCALAR_UNIT_HPP(heat_capacity);
	SCALAR_UNIT_HPP(heat_flux_density);
	SCALAR_UNIT_HPP(thermal_conductivity);
	SCALAR_UNIT_HPP(thermal_diffusivity);
	SCALAR_UNIT_HPP(thermal_resistance);
	SCALAR_UNIT_HPP(thermal_expansion_coefficient);
	VECTOR_UNIT_HPP(temperature_gradient);
	SCALAR_UNIT_HPP(energy_flux_density);

	// WAVES
	SCALAR_UNIT_HPP(wavenumber);
	SCALAR_UNIT_HPP(frequency);
	
	typedef length wavelength;
}

#endif // SCIFIR_UNITS_PREDEFINED_UNITS_KINEMATICS_UNITS_HPP_INCLUDED
