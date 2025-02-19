# Scalar units - scifir-units

Scalar units and vector units are the central objects of scifir-units. They store a value and a set of dimensions, as units on science do. Scalar units are just normal values, while vector units have a value and a direction to which the vector points to.

All scalar unit classes are either scalar_unit class or a child class of scalar_unit class, without vector_unit_2d, vector_unit_3d and vector_unit_nd possible cases for this definition.

Scalar unit classes have a fixed set of dimensions that can be changed to any equivalent set of dimensions, and can't be changed, because the scalar_unit class impedes it, to any set of dimensions that's not equivalent to the original dimensions. For example, a scalar unit class that has of dimensions "m" can't be changed to dimensions "Pa", but can be changed to dimensions "Å" (angstrom dimension). Dimensions can be changed whenever is wanted if an equivalent set of dimensions if more comfortable to do the calculations than the original dimensions the scalar unit class has been instantiated with.

Derived scalar unit classes have a fixed set of dimensions. For example, length classes have dimension "m", and mole classes have dimension "mol". Pressure class has dimension "Pa", etc.

Scalar units can operate with other scalar units, as well as with numeric primitive types. Functions like abs(), sqrt() and to_string() are supported. They have functions to operate with strings, and functions to operate with streams.

Scalar units can have any dimension of the SI system of units, or, also, any **custom dimension**. A custom dimension is a dimension with an arbitrary name, which is commonly used inside some fields of science when there's no name for a needed dimension.

An example of use of scalar_unit is the following:

```cpp
length x = 10_m;
length y = length(8,"mm");
length z = length("10 m");
area xy = area(100,"m2");

x = 2_m;

length a = x + 3.2_dm;
length e = x - 1_mm;
area b = y * 3_m;
length c = b / 2_m;

x += 1_km;
y -= 50_cm;

length f = a + 1.5;
length g = b - 7;
length h = c * 3;
length i = c / 1.5;
area j = c ^ 2;

f += 2;
f -= 1;
g *= 1.5;
h /= 5;

x++;
y--;

x.change_dimensions("mm"); // Dimensions can be set to any prefix
x.change_dimensions("s"); // An scalar_unit can't change to other dimensions different than the dimensions they started

if (x.has_dimensions("km")) // Dimensions are compared without prefixes
{}

x.change_dimensions(y); // Now x has dimensions "mm" as y

ostringstream out;
out << x; // scalar_unit classes can operate with streams

cout << x.display(); // Displays the scalar_unit up to 2 decimal digits with his dimensions
cout << x.custom_display("sci"); // Displays the scalar_unit in scientific notation without prefixes for any of his dimensions

length w = 100_m;
string d = to_string(w); // Creates the string "100 m"

float a = abs(x); // abs() gives the absolute value of the scalar_unit
scalar_unit b = sqrt(x*y); // sqrt() gives the square root of the scalar_unit
scalar_unit c = pow(x,3); // Dimensions would be "m3"

if (x.has_dimensions(y)) // Evaluates to true if the two scalar_unit objects have the same dimensions, independent of prefixes
{}

if (x == y) // Evaluates to true if the scalar_unit objects have the same value and the same dimensions
{}

if (x == 3) // Compares by value, it's better to only compare scalar_unit. To use 3_m instead would have been better, but numeric primitive types are allow to be used
{}

length a;
cin >> a; // There's support for input streams

string a;
a += x; // Adds the scalar_unit to the string

string b = "x: " + x;
string c = x + " value";
```

A base and a derived unit is a child class of scalar_unit class or of one of the vector unit classes (which are vector_unit_2d, vector_unit_3d and vector_unit_nd). A base and a derived unit adds always in his name a suffix **_2d**, **_3d** or **_nd**, if they inherit from vector_unit_2d, vector_unit_3d or vector_unit_nd, respectively.

## List of scalar unit classes

Rememer that you can define new scalar unit classes with the macros SCALAR_UNIT_HPP and SCALAR_UNIT_CPP.

### Base unit classes

| Name | Dimensions | Type | Literals | Description
| ----- | ----- | ----- | ----------- | --------------------------
| length | m | scalar_unit | _m and _Tm, _km, etc (all prefixes supported). Also, _AU and _AU, _kAU, etc (all prefixes supported). And also, _pc and _Tpc, _kpc, etc (all prefixes supported) | Measures the length.
| time_duration | s | scalar_unit | _s and _Ts, _ks, etc (all prefixes supported). There's also _min, _hour and _day | Measures time. Intended to be used in calculations with other scalar_unit classes, for other time uses inside a code use chrono or ctime of the standard library.
| mass | g | scalar_unit | _g and _Tg, _kg, etc (all prefixes supported). Also, _Da and _amu | Measures the mass.
| charge | C | scalar_unit | _C and _TC, _kC, etc (all prefixes supported) | Measures the charge.
| temperature | K | scalar_unit | _K and _TK, _kK, etc (all prefixes supported). There's also _celsius | Measures the temperature. The temperature corresponds to the movement of molecules.
| mole | mol | scalar_unit | _mol and _Tmol, _kmol, etc (all prefixes supported). Also, use _particles for specifying an exact amount of particles. | Amount of matter, by number.
| light_intensity | cd | scalar_unit | _cd and _Tcd, _kcd, etc (all prefixes supported) | Intensity of light.
| information_size | B | scalar_unit | _B and _TB, _kB, etc (all prefixes supported) | Amount of information.

### Space units

| Name | Dimensions | Type | Literals | Description
| ----- | ----- | ----- | ----------- | --------------------------
| area | m2 | scalar_unit | For nuclear calculations, you can use _barn and _Tbarn, _kbarn, etc (all prefixes supported). Otherwise use "m2" instead. | Measures the area.
| volume | m3 | scalar_unit | _L and _TL, _kL, etc (all prefixes supported). You can use m3 too as string, the litre literals aren't the only choice (use the most appropriate for each case). | Measures the volume.
| volume_4d | m4 | scalar_unit | - | Measures the volume in 4D.
| curvature | 1/m | scalar_unit | - | Measures the curvature.

### Kinematics units

| Name | Dimensions | Type | Literals | Description
| ----- | ----- | ----- | ----------- | --------------------------
| displacement_2d, displacement_3d, displacement_nd | m | vector_unit_2d, vector_unit_3d, vector_unit_nd | - | Measures the displacement.
| velocity, velocity_2d, velocity_3d, velocity_nd | m/s | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | Measures the velocity of an object.
| acceleration, acceleration_2d, acceleration_3d, acceleration_nd | m/s2 | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | The increase of the velocity by time.
| jerk, jerk_2d, jerk_3d, jerk_nd | m/s3 | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | The rate of change of the acceleration over time.
| snap, snap_2d, snap_3d, snap_nd | m/s4 | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | The fourth derivative of the position vector with respect to time.
| angular_velocity, angular_velocity_2d, angular_velocity_3d, angular_velocity_nd | rad/s | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | Measures the velocity of an object around a center.
| angular_acceleration, angular_acceleration_2d, angular_acceleration_3d, angular_acceleration_nd | rad/s2 | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | The increase of angular velocity by time.
| angular_momentum, angular_momentum_2d, angular_momentum_3d, angular_momentum_nd | m2*kg/s | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | A momentum, but related to the angular movement.

### Dynamics units

| Name | Dimensions | Type | Literals | Description
| ----- | ----- | ----- | ----------- | --------------------------
| impulse, impulse_2d, impulse_3d, impulse_nd | m*kg/s | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | Measures the amount of change in momentum.
| force, force_2d, force_3d, force_nd | kg*m/s2 | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | _N and _TN, _kN, etc (all prefixes supported) | The force is what changes the acceleration of some matter.
| torque, torque_2d, torque_3d, torque_nd | kg*m2/s2 | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | A force that does a rotation.
| pressure, pressure_2d, pressure_3d, pressure_nd | kg/m*s2 | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | _Pa and _TPa, _kPa, etc (all prefixes supported) | Force applied to a surface.
| surface_tension, surface_tension_2d, surface_tension_3d, surface_tension_nd | kg/s2 | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | Tension in a surface.
| stiffness | kg/s2 | scalar_unit | - | Extent to which an object resists deformation.
| moment_of_inertia | m2*kg | scalar_unit | - | Torque needed for a desired angular acceleration about a rotational axis.
| yank, yank_2d, yank_3d, yank_nd | N/s | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | Rate of change of force.

### Electricity units

| Name | Dimensions | Type | Literals | Description
| ----- | ----- | ----- | ----------- | --------------------------
| electric_current | A | scalar_unit | _A and _TA, _kA, etc (all prefixes supported) | Measures the amount of current.
| voltage | V | scalar_unit | _V and _TV, _kV, etc (all prefixes supported) | The intensity of the electric force.
| electric_charge_density | C/m3 | scalar_unit | - | Density of the electric charge of a charged object.
| electric_current_density | A/m2 | scalar_unit | - | Density of the electric current.
| electric_field_strength, electric_field_strength_2d, electric_field_strength_3d, electric_field_strength_nd | V/m | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | The strength of the electric field.
| electron_mobility | m2/V*s | scalar_unit | - | How quickly an electron can move through a metal or semiconductor.
| inductance | H | scalar_unit | _H and _TH, _kH, etc (all prefixes supported) | The tendency of an electrical conductor to oppose a change in the electric current flowing through it.

### Fluid dynamics units

| Name | Dimensions | Type | Literals | Description
| ----- | ----- | ----- | ----------- | --------------------------
| volumetric_flow | m3/s | scalar_unit | - | Quantity of fluid per second.
| diffusion_coefficient | m2/s | scalar_unit | - | Coefficient of diffusion.
| compressibility | m*s2/kg | scalar_unit | - | How easy it's to compress the fluid.

### Magnetism units

| Name | Dimensions | Type | Literals | Description
| ----- | ----- | ----- | ----------- | --------------------------
| magnetic_permeability | H/m | scalar_unit | - | Measure of the magnetization produced in a material in response to an applied magnetic field.
| magnetic_flux | Wb | scalar_unit | _Wb and _TWb, _kWb, etc (all prefixes supported) | Amount of magnetism per surface.
| magnetic_moment, magnetic_moment_2d, magnetic_moment_3d, magnetic_moment_nd | Wb*m | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | Combination of strength and orientation of a magnet or other object that exerts a magnetic field.
| magnetic_reluctance | 1/H | scalar_unit | - | It's a resistance to the magnetism.
| magnetic_rigidity | T*m | scalar_unit | - | Resistance to magnetism.
| magnetomotive_force, magnetomotive_force_2d, magnetomotive_force_3d, magnetomotive_force_nd | A*rad | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | It's the property that gives rise to magnetic fields.
| magnetic_susceptibility | m/H | scalar_unit | - | It's a measure of how much a material will become magnetized in an applied magnetic field.

### Optics units

| Name | Dimensions | Type | Literals | Description
| ----- | ----- | ----- | ----------- | --------------------------
| optical_power | 1/m | scalar_unit | - | Degree to which a lens, mirror or other optical system converges or diverges light.
| illuminance | lx | scalar_unit | _lx and _Tlx, _klx, etc (all prefixes supported) | Luminous flux incident in a surface.
| luminous_flux | lm | scalar_unit | _lm and _Tlm, _klm, etc (all prefixes supported) | The perceived power of light.
| luminous_energy | lm*s | scalar_unit | - | Perceived fraction of energy transported by the light waves.
| luminous_exposure | lx*s | scalar_unit | - | Amount of light per unit area.
| luminous_efficacy | lm/W | scalar_unit | - | Measure of how well a light source produces visible light.
| ionizing_radiation | Gy | scalar_unit | _Gy and _TGy, _kGy, etc (all prefixes supported). Also, _Sv and _TSv, _kSv, etc (all prefixes supported) | Subatomic particles or electromagnetic waves that have sufficient energy to ionize atoms or molecules by detaching electrons from them.
| absorbed_dose | m2/s3 | scalar_unit | - | Measure of the energy deposited in matter by ionizing radiation per unit mass.

### Thermodynamics units

| Name | Dimensions | Type | Literals | Description
| ----- | ----- | ----- | ----------- | --------------------------
| energy | J | scalar_unit | _J and _TJ, _kJ, etc (all prefixes supported). Also, _eV and _TeV, _keV, etc (all prefixes supported) | Entity needed to create a force.
| action | kg*m2/s | scalar_unit | - | It describes how the balance between kinetic versus potential energy changes with the trajectory.
| power | W | scalar_unit | _W and _TW, _kW, etc (all prefixes supported) | Energy per second.
| power_density | kg/m*s3 | scalar_unit | - | Energy per second per volume.
| entropy | kg*m2/K*s2 | scalar_unit | - | Amount of disorder in nature.
| heat_capacity | J/K | scalar_unit | - | Amount of heat that matter needs to change temperature.
| heat_flux_density | kg/s3 | scalar_unit | - | Amount of heat per surface.
| thermal_conductivity | W/m*K | scalar_unit | - | How easy matters conducts thermal energy.
| thermal_diffusivity | m2/s | scalar_unit | - | The diffusivity of the thermal energy.
| thermal_resistance | K/W | scalar_unit | - | The resistance to thermal change.
| thermal_expansion_coefficient | 1/K | scalar_unit | - | The coefficient at which matter expands due to heat.
| temperature_gradient, temperature_gradient_2d, temperature_gradient_3d, temperature_gradient_nd | K/m | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | The gradient of change of temperature inside the space.
| energy_flux_density | kg/s3 | scalar_unit | - | Density of a flux of energy.
| fuel_efficiency | 1/m2 | scalar_unit | - | Ratio of the result of conversion of chemical potential energy into kinetic energy or work.

### Waves units

| Name | Dimensions | Type | Literals | Description
| ----- | ----- | ----- | ----------- | --------------------------
| wavenumber | 1/m | scalar_unit | - | Number of times a wave vibrates over a distance.
| frequency | Hz | scalar_unit | _Hz and _THz, _kHz, etc (all prefixes supported) | Number of repetitions over time.

### Astronomy units

| Name | Dimensions | Type | Literals | Description
| ----- | ----- | ----- | ----------- | --------------------------
| specific_angular_momentum, specific_angular_momentum_2d, specific_angular_momentum_3d, specific_angular_momentum_nd | m2/s | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | Angular momentum of a particular celestial body.

### General chemistry units

| Name | Dimensions | Type | Literals | Description
| ----- | ----- | ----- | ----------- | --------------------------
| density | g/m3 | scalar_unit | - | Amount of mass per unit of volume.
| viscosity | m2/s | scalar_unit | - | Resistance to the movement done by the solvent.
| specific_volume | m3/g | scalar_unit | - | Volume per unit of mass.
| specific_heat_capacity | J/K*kg | scalar_unit | - | Heat capacity of a particular substance.
| specific_entropy | m2/s2*K | scalar_unit | - | Entropy of a substance.
| specific_energy | m2/s2 | scalar_unit | - | Energy per unit of mass
| molar_volume | m3/mol | scalar_unit | - | Volume of each mole of a substance.
| molar_mass | g/mol | scalar_unit | - | Mass of each mole of a substance.
| molar_heat_capacity | m2*g/s2*K*mol | scalar_unit | - | Heat capacity of each mole of a substance.
| molar_enthalpy | m2*g/s2*mol | scalar_unit | - | Enthalpy of each mole of a substance.
| molar_entropy | m2*g/s2*K*mol | scalar_unit | - | Entropy of each mole of a substance.
| molar_energy | m2*g/s2*mol | scalar_unit | - | Energy of each mole of a substance.
| molar_conductivity | s3*A2/g*mol | scalar_unit | - | Conductivity of each mole of a substance.
| energy_density | g/m*s2 | scalar_unit | - | Amount of energy per unit of volume.
| catalytic_efficiency | m3/s*mol | scalar_unit | - | How efficiently an enzyme converts substrates into products.

### Substance units

| Name | Dimensions | Type | Literals | Description
| ----- | ----- | ----- | ----------- | --------------------------
| molarity | M | scalar_unit | _M and _TM, _kM, etc (all prefixes supported) | Amount of moles per volume, usually per litres.
| molality | mol/g | scalar_unit | - | Amount of moles per mass.
| linear_mass_density | g/m | scalar_unit | - | Amount of mass per length.
| area_density | g/m2 | scalar_unit | - | Amount of mass per surface.
| dynamic_viscosity | g/m*s | scalar_unit | - | Relation between the viscous stresses in a material to the rate of change of a deformation.
| mass_flow_rate | g/s | scalar_unit | - | Mass per second.
| catalytic_activity | kat | scalar_unit | _kat and _Tkat, _kkat, etc (all prefixes supported) | Rate of conversion of catalysis, amount of moles per second.

### Electronics units

| Name | Dimensions | Type | Literals | Description
| ----- | ----- | ----- | ----------- | --------------------------
| electrical_conductivity | S/m | scalar_unit | - | Amount of current conducted.
| resistance | Ω | scalar_unit | _Ω and _TΩ, _kΩ, etc (all prefixes supported) | Opposition to the flow of current of a substance.
| electric_conductance | S | scalar_unit | _S and _TS, _kS, etc (all prefixes supported) | The inverse of the resistance.
| capacitance | F | scalar_unit | _F and _TF, _kF, etc (all prefixes supported) | Amount of charge that can be stored by a capacitor.
| permittivity | F/m | scalar_unit | - | The electric polarizability of a dieletric material.
| resistivity | Ω*m | scalar_unit | - | How much a material stops the flow of electric current through it.
| linear_charge_density | C/m | scalar_unit | - | The amount of electric charge per unit length.
| surface_charge_density | C/m2 | scalar_unit | - | The amount of electric charge per unit area.
| volume_charge_density | C/m3 | scalar_unit | - | The amount of electric charge per unit volume.
| frequency_drift | 1/s2 | scalar_unit | - | Offset of an oscillator from its nominal frequency.

### Radiometry units

| Name | Dimensions | Type | Literals | Description
| ----- | ----- | ----- | ----------- | --------------------------
| radioactivity | Bq | scalar_unit | _Bq and _TBq, _kBq, etc (all prefixes supported) | Presence of nuclear radiation.
| radiant_exposure, radiant_exposure_2d, radiant_exposure_3d, radiant_exposure_nd | kg/s2 | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | Radiant energy received by a surface per unit area.
| radiant_intensity | kg*m2/s3 | scalar_unit | - | Radiant flux emitted per unit solid angle.
| radiance | kg/s3 | scalar_unit | - | Radiant flux emitted by a surface per unit solid angle per unit projected area.
| spectral_radiance | kg/m*s3 | scalar_unit | - | Radiance of a surface per unit frequency or wavelength.
| radiant_flux, radiant_flux_2d, radiant_flux_3d, radiant_flux_nd | kg*m2/s3 | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | Radiant energy emitted per unit time.
| spectral_flux, spectral_flux_2d, spectral_flux_3d, spectral_flux_nd | kg*m/s3 | scalar_unit, vector_unit_2d, vector_unit_3d, vector_unit_nd | - | Radiant flux per unit frequency or wavelength.

### Informatics units

| Name | Dimensions | Type | Literals | Description
| ----- | ----- | ----- | ----------- | --------------------------
| transfer_speed | B/s | scalar_unit | - | Bytes emitted or received per second.

### Pharmacology units

| Name | Dimensions | Type | Literals | Description
| ----- | ----- | ----- | ----------- | --------------------------
| amount_of_effect | IU | scalar_unit | _IU and _TIU, _kIU, etc (all prefixes supported) | Amount of pharmacological effect that some amount of a substance does.

### Some unique functions of base unit classes

All base unit and derived unit classes inherit scalar_unit and, then, work with their functions. Additional to that, there are some special functions of some base unit classes, described here.

```cpp
mole a = 1_mol;
cout << a.number_of_particles(); // Returns the total of particles, using Avogadro number

mole b(30_percentage,1_mol); // Initialiazes 30% of a mole
mole c("30 %","1 mol"); // Initialiazes 30% of a mole with strings

mass d(30_percentage,10_kg); // Initialiazes 30% of 10 kg
mass e("30 %","10 kg"); // Initialiazes 30% of 10 kg with strings
```