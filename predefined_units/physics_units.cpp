#include "./physics_units.hpp"

namespace scifir
{
	// KINEMATICS
	VECTOR_UNIT_2D_CPP(displacement,"m");
	VECTOR_UNIT_3D_CPP(displacement,"m");
	VECTOR_UNIT_ND_CPP(displacement,"m");
	VECTOR_UNIT_CPP(velocity,"m/s");
	VECTOR_UNIT_CPP(acceleration,"m/s2");
	VECTOR_UNIT_CPP(momentum,"kg*m/s");
	VECTOR_UNIT_CPP(jerk,"m/s3");
	VECTOR_UNIT_CPP(snap,"m/s4");
	VECTOR_UNIT_CPP(angular_velocity,"rad/s");
	VECTOR_UNIT_CPP(angular_acceleration,"rad/s2");
	VECTOR_UNIT_CPP(angular_momentum,"m2*kg/s");

	// DYNAMICS
	VECTOR_UNIT_CPP(impulse,"m*kg/s");
	VECTOR_UNIT_CPP(force,"kg*m/s2");
	VECTOR_UNIT_CPP(torque,"kg*m2/s2");
	VECTOR_UNIT_CPP(pressure,"kg/m*s2");
	VECTOR_UNIT_CPP(surface_tension,"kg/s2");
	SCALAR_UNIT_CPP(stiffness,"kg/s2");
	SCALAR_UNIT_CPP(moment_of_inertia,"m2*kg");

	// ELECTRICITY
	SCALAR_UNIT_CPP(electric_current,"A");
	SCALAR_UNIT_CPP(voltage,"V");
	VECTOR_UNIT_CPP(electric_displacement_field,"A*s/m2");
	SCALAR_UNIT_CPP(electric_charge_density,"A*s/m3");
	SCALAR_UNIT_CPP(electric_current_density,"A/m2");
	VECTOR_UNIT_CPP(electric_field_strength,"kg*m/A*s3");
	SCALAR_UNIT_CPP(electron_mobility,"A*s2/kg");
	SCALAR_UNIT_CPP(inductance,"H");

	// FLUID DYNAMICS
	SCALAR_UNIT_CPP(volumetric_flow,"m3/s");
	SCALAR_UNIT_CPP(diffusion_coefficient,"m2/s");
	SCALAR_UNIT_CPP(compressibility,"m*s2/kg");

	// MAGNETISM
	SCALAR_UNIT_CPP(polarization_density,"A*s/m2");
	SCALAR_UNIT_CPP(magnetic_permeability,"A2*s2/kg*m");
	SCALAR_UNIT_CPP(magnetization,"A/m");
	SCALAR_UNIT_CPP(magnetic_flux,"Wb");
	VECTOR_UNIT_CPP(magnetic_strength,"Wb/m2");
	VECTOR_UNIT_CPP(magnetic_moment,"A*m2");
	SCALAR_UNIT_CPP(magnetic_reluctance,"A2*s2/kg*m2");
	VECTOR_UNIT_CPP(magnetic_vector_potential,"kg*m/A*s2");
	SCALAR_UNIT_CPP(magnetic_rigidity,"kg*m/A*s2");
	VECTOR_UNIT_CPP(magnetomotive_force,"A");
	SCALAR_UNIT_CPP(magnetic_susceptibility,"A2*s2/kg*m");

	// OPTICS
	SCALAR_UNIT_CPP(optical_power,"1/m");
	SCALAR_UNIT_CPP(luminance,"cd/m2");
	SCALAR_UNIT_CPP(illuminance,"lx");
	SCALAR_UNIT_CPP(luminous_flux,"lm");
	SCALAR_UNIT_CPP(luminous_energy,"cd*sr*s");
	SCALAR_UNIT_CPP(luminous_exposure,"cd*sr*s/m2");
	SCALAR_UNIT_CPP(luminous_efficacy,"lm/W");
	SCALAR_UNIT_CPP(ionizing_radiation,"A*s/kg");
	SCALAR_UNIT_CPP(absorbed_dose,"m2/s3");

	// THERMODYNAMICS
	SCALAR_UNIT_CPP(energy,"kg*m2/s2");
	SCALAR_UNIT_CPP(action,"kg*m2/s");
	SCALAR_UNIT_CPP(power,"kg*m2/s3");
	SCALAR_UNIT_CPP(power_density,"kg/m*s3");
	SCALAR_UNIT_CPP(entropy,"kg*m2/K*s2");
	SCALAR_UNIT_CPP(heat_capacity,"kg*m2/K*s2");
	SCALAR_UNIT_CPP(heat_flux_density,"kg/s3");
	SCALAR_UNIT_CPP(thermal_conductivity,"kg*m/K*s3");
	SCALAR_UNIT_CPP(thermal_diffusivity,"m2/s");
	SCALAR_UNIT_CPP(thermal_resistance,"K*s3/kg*m2");
	SCALAR_UNIT_CPP(thermal_expansion_coefficient,"1/K");
	VECTOR_UNIT_CPP(temperature_gradient,"K/m");
	SCALAR_UNIT_CPP(energy_flux_density,"kg/s3");

	// WAVES
	SCALAR_UNIT_CPP(wavenumber,"1/m");
	SCALAR_UNIT_CPP(frequency,"1/s");
}
