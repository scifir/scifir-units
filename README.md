# scifir-units library

Welcome! The **Scifir Collection** is a set of scientific libraries for developing **laboratory machines** and **scientific inventions**. It provides units, molecules, among other features, to allow developers of scientific software to develop their software and firmware easily. Enjoy!

The Scifir Collection is under development, but the units are already released. Molecules aren't, but they will by ready soon!

**scifir-units** includes special units to use, then it's unneeded to care about having the proper dimensions and prefixes when developing scientific software, you can instantiate any value you have on the machine, without performing operations with a calculator first to convert the units to a common prefix. Learn how to use them at the [Wiki](https://github.com/scifir/scifir-units/wiki).

### Team

The **Scifir Collection** is developed by [Ismael Correa Castro](https://iarfen.github.io), a software developer of 32 years old. You can email him if you find bugs, you want to request new features, or have any other need, at ismael.correa.castro@gmail.com. His ORCID is 0009-0007-3815-7053, if you want to reference this work inside any publication.

### Funding

The **Scifir Foundation** is looking for **funding**, in order to do some digital marketing and pay some other needs of the project. If you want to support this libraries, **science will thank you** for that, you can donate in this [sponsors page](https://github.com/sponsors/iarfen).

## Installation

To install scifir-units you have to use CMake and Make. The library is called scifir_units, the other scifir libraries aren't yet published in the web. The commands to install it are the following:

```
cmake .
make
make install
```

## Introduction

The Scifir Collection is a set of libraries that allows to create the software of scientific inventions, being them scientific machines or just scientific software. This library, scifir-units, allows to handle scalar and vectorial units inside the code. They are very lightweight, they size similar to a float, and can be used extensively to do any math calculation necessary for the invention. The prefixes can be changed, in order to display the units in the more proper dimensions. Also, all the conversions known are supported. Then, instead of the meter, a length can be described by a light-year, an astronomical unit (AU), among other units of measure.

The unit classes that scifir-units provides are the following:

- **scalar_unit:** Handles scalar units. It covers vectors in 1D too.
- **vector_unit_2d:** Handles vector units in 2D dimensions. It inherits scalar_unit.
- **vector_unit_3d:** Handles vector units in 3D dimensions. It inherits scalar_unit.
- **vector_unit_nd:** Handles vector units in ND dimensions. It inherits scalar_unit.

scalar_unit classes can be used both for scalar units and vector units in 1D. In the case of vector units in 1D, a negative value indicates, as on math, that it points to the left on the x axis. Otherwise, if the value is positive, it points to the right.

All the unit classes have fixed dimensions. Once instantiated, they can't change to a different set of dimensions. Besides that, prefixes and abbreviations can be used freely, every unit can change to any other prefix and use any abbreviation that matches the original dimensions (and no other set of dimensions).

There are also special units inside scifir-units. Those special units are aid, color, percentage, pH, pixel, pOH, size_2d, size_3d, size_nd and zid. **Always prefer pH** over pOH, pOH is provided by the library only for very infrequent cases.

### Class list

The most important classes are the scalar units and the vector units. Vector units are in 2D, 3D and ND (a variable number of dimensions).

- scalar_unit.
- vector_unit_2d.
- vector_unit_3d.
- vector_unit_nd.
- dimension.
- prefix.
- conversion.

The classes dimension, prefix and conversion are intended for **internal use** mainly, but they can be used if they are needed.

The basic unit classes that inherit scalar_unit and use, then, too, dimension and prefix classes, are the following:

- length.
- time_duration.
- mass.
- charge.
- temperature.
- mole.
- light.
- data.

Apart from those basic scalar_unit subclasses, there are a great amount of more unit classes defined, that are derived from scalar_unit or from vector_unit. All scalar unit subclasses derive from scalar_unit, and all vector unit subclasses are defined one time for 2d, one time for 3d, one time for nd, and one time for the scalar_unit case. Then, force units, which are vector units, exist as force, force_2d, force_3d and force_nd.

All those additional unit classes are the following:

- **Astronomy:** specific_angular_momentum, specific_angular_momentum_2d, specific_angular_momentum_3d, specific_angular_momentum_nd
- **Chemistry:** density, viscosity, specific_volume, specific_heat_capacity, specific_entropy, specific_energy, molar_volume, molar_mass, molar_heat_capacity, molar_enthalpy, molar_entropy, molar_energy, molar_conductivity, energy_density, catalytic_efficiency
- **Dynamics:** impulse, impulse_2d, impulse_3d, impulse_nd, force, force_2d, force_3d, force_nd, torque, torque_2d, torque_3d, torque_nd, pressure, pressure_2d, pressure_3d, pressure_nd, surface_tension, surface_tension_2d, surface_tension_3d, surface_tension_nd, stiffness, moment_of_inertia
- **Electricity:** electric_current, voltage, electric_charge_density, electric_current_density, electric_field_strength, electric_field_strength_2d, electric_field_strength_3d, electric_field_strength_nd, electron_mobility, inductance
- **Electronics:** electrical_conductivity, resistance, electric_conductance, capacitance, permittivity, resistivity, linear_charge_density, frequency_drift
- **Fluid dynamics:** volumetric_flow, diffusion_coefficient, compressibility
- **Informatics:** transfer_speed
- **Kinematics:** distance, displacement_2d, displacement_3d, displacement_nd, velocity, velocity_2d, velocity_3d, velocity_nd, acceleration, acceleration_2d, acceleration_3d, acceleration_nd, jerk, jerk_2d, jerk_3d, jerk_nd, snap, snap_2d, snap_3d, snap_nd, angular_velocity, angular_velocity_2d, angular_velocity_3d, angular_velocity_nd, angular_acceleration, angular_acceleration_2d, angular_acceleration_3d, angular_acceleration_nd, angular_momentum, angular_momentum_2d, angular_momentum_3d, angular_momentum_nd
- **Magnetism:** magnetic_flux, magnetic_moment, magnetic_moment_2d, magnetic_moment_3d, magnetic_moment_nd, magnetic_reluctance, magnetic_rigidity, magnetomotive_force, magnetomotive_force_2d, magnetomotive_force_3d, magnetomotive_force_nd, magnetic_susceptibility
- **Optics:** optical_power, luminance, illuminance, luminous_flux, luminous_energy, luminous_exposure, luminous_efficacy, ionizing_radiation, absorbed_dose
- **Radiometry:** radioactivity, irradiance, irradiance_2d, irradiance_3d, irradiance_nd, radiant_exposure, radiant_exposure_2d, radiant_exposure_3d, radiant_exposure_nd, radiant_intensity, spectral_intensity, radiance, spectral_radiance, radiant_flux, radiant_flux_2d, radiant_flux_3d, radiant_flux_nd, spectral_flux, spectral_flux_2d, spectral_flux_3d, spectral_flux_nd
- **Space:** area, volume, volume_4d, curvature
- **Substance:** molarity, molality, linear_mass_density, area_density, dynamic_viscosity, mass_flow_rate, catalytic_activity
- **Thermodynamics:** energy, action, power, power_density, enthalpy, entropy, heat_capacity, heat_flux_density, thermal_conductivity, thermal_diffusivity, thermal_resistance, thermal_expansion_coefficient, temperature_gradient, temperature_gradient_2d, temperature_gradient_3d, temperature_gradient_nd, energy_flux_density
- **Waves:** wavenumber, frequency, wavelength

The meca numbers are special numbers that don't behave exactly like an scalar unit:

- angle.
- complex_number.
- lab_number.

The coordinates classes handle position in space. The point classes also handle position in space. Coordinates are used for positions and points are intended for more stationary cases, like for example vertex of triangles that form a 3D model.

- coordinates_1d.
- coordinates_2d.
- coordinates_2dr.
- coordinates_3d.
- coordinates_3dr.
- coordinates_nd.
- coordinates_ndr.
- point_1d.
- point_2d.
- point_3d.
- point_nd.
- direction.

The special unit classes handle special cases of values:

- aid.
- zid.
- color.
- percentage.
- pH.
- pOH.
- pixel.
- size_2d.
- size_3d.
- size_nd.

### Consumption of memory

The scalar_unit and vector unit classes, vector_unid_2d, vector_unid_3d and vector_unit_nd size more than a single float, which uses 4 bytes, but don't size a big amount and so, they can be used in great quantities for any purpose, cause they are very lightweight.

The angle class uses only 4 bytes, and works perfectly fine, very similar to a normal float. Then, you can use it freely every time you need to do calculations that need angles.

## Core functionalities

All the classes of scifir-units are inside the **namespace scifir**, as with all libraries of the **Scifir Collection**. So, to use any of this classes, like angle, you have to type any of the following codes:

```cpp
using namespace scifir; // Maybe this is usually the better choice
scifir::angle a; // You can use the namespace directly
```

All the example code presented here is written assuming you know this namespace scifir.

### Initialization strings

All the unit classes, and also the other related classes of this library, can be constructed with what is called here an **initialization string**. An initialization string is an string used to instantiate the class, and it's also used when converting the class to an string for any purpose (like printing it on the screen).

The initialization strings are the following:

- **angle**: "37°"
- **scalar_unit**: "1 km"
- **vector_unit_2d**: "5 km 10°"
- **vector_unit_3d**: "3 km 10° 20°"
- **vector_unit_nd**: "3 km 10° 20° 35°"
- **point_1d**: "3 m" or "(3 m)"
- **point_2d**: "2 m,4 m" or "(2 m,4 m)"
- **point_3d**: "1 m,9 m,3 m" or "(1 m,9 m,3 m)"
- **point_nd**: "3 m,2 m,4 m,1 m" or "(3 m,2 m,4 m,1 m)"
- **coordinates_1d**: "1 m" or "(1 m)"
- **coordinates_2d**: "1 m,2 m" or "(1 m,2 m)"
- **coordinates_3d**: "1 m,7 m,5 m" or "(1 m,7 m,5 m)"
- **coordinates_nd**: "1 m,7 m,5 m,8 m" or "(1 m,7 m,5 m,8 m)"
- **coordinates_2dr**: "1 m,2 m;45°" or "(1 m,2 m;45°)"
- **coordinates_3dr**: "1 m,7 m,5 m;17° 25°" or "(1 m,7 m,5 m;17° 25°)"
- **coordinates_ndr**: "1 m,7 m,5 m,8 m;32° 56° 78°" or "(1 m,7 m,5 m,8 m;32° 56° 78°)"

In order to store units inside a file an initialization string should be used. For any purpose, when converting some of those classes to an string, the string initialization has to be always used.

### Angle

An angle object manages angles. It stores angles in grades, rather than in radians. It can be initialized to any grade between 0 and 360 (without including 360, cause this is identical to 0 in meaning), and any initialization that's not inside this range of values gets automatically converted inside it, to his equivalent value between the range.

An example of use of angle is the following:

```cpp
// Constructors and instantiation
angle y = 54; // Better constructor! Preferred method
angle a = 367; // Gets converted to the value 7, because 7 is the equivalent of 367 inside 0 and 360
angle b = angle(12);
angle c = angle(34_Pa);
angle z = 23_N; // Angles can be instantiated with units if that is needed, although it's not recommended

// Angles operations with other angles
angle b = a + x;
angle c = a - x;
angle d = a * b;
angle e = a / c;
b += a;
c -= b;
e *= a;
c /= e;
d ^= a;

// Numeric operations
angle x = a + 3;
angle y = x - 6;
angle z = x * 3;
angle g = y / 4;
angle h = z ^ 5;
x += 3;
x -= 6;
x *= 2;
x /= 4;
x ^= 7;
x++;
++x;
x--;
--x;
float a_grade = x.get_grade();
float a_radians = x.get_radian();
x.invert(); // Inverts the angle, the orientation described by this angle points now in the opposite direction
float y = float(x); // Angles can be converted to float
```

### Scalar units

Scalar units and vector units are the central objects of scifir-units. They store a value and a set of dimensions, as units on science do. Scalar units are just normal values, while vector units have a value and a direction to which the vector points to.

Scalar units can operate with other scalar units, as well as with numeric primitive types. Functions like abs(), sqrt() and to_string() are supported. They have functions to operate with strings, and functions to operate with streams.

An example of use of an scalar unit is the following:

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

length w = 100_m;
string d = to_string(w); // Creates the string "100 m"

float a = abs(x); // abs() gives the absolute value of the scalar_unit
scalar_unit b = sqrt(xy); // sqrt() gives the square root of the scalar_unit
scalar_unit c = pow(a,x); // Dimensions would be "m3"

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

The basic dimensions of this library, for scalar_unit classes, all the different vector_unit classes, and all other classes that handle units, are the following. They are all in SI units, excepting memo, which is a basic dimension created by Ismael Correa, the author of this library, to measure the size occupied by a memory inside the animal brain, including human brains.

| Name | Symbol | Description
| ----- | --- | --------------------------|
| Length | m | Measures the length occupied in space by an object |
| Time | s | Measures the duration in time of some event |
| Mass | g | Measures the amount of substance related to the strength of a gravitational field |
| Radian | rad | Measures the size of an angle |
| Steradian | sr | Measures the size of a solid angle |
| Coulomb | C | Measures the amount of charge |
| Temperature | K | Measures the amount of hotness or coldness. Microscopically it measures the speed at which the particles that constitute the matter are moving |
| Mole | mol | Measures the amount of a substance related to the number of its constituent particles |
| Luminous intensity | cd | Measures the intensity of light |
| Byte | B | Measures the amount of information |
| Money | money | Measures the economic value of an entity |
| Memo | memo | Measures the size occupied by a memory inside the brain of an animal, including human brains. Created by Ismael Correa, it's not an official basic dimension of the SI system of units |

There are also derived dimensions of those basic dimensions, which are documented in the reference. Yet, you should memorize all those basic dimensions.

### Vector units in 2D

Vector units in 2D allow to do calculations for lab machines and simulations of physics and other areas of science in 2 dimensions. They inherit scalar_unit, and additional to his member-variables they include the member-variable theta, of class angle (described above).

An example of use of it is the following:

```cpp
force_2d x = force_2d(21_N,56_angle); // Creates a force_2d with a value of 21 N and an inclination angle of 56°
force_2d y = force_2d(32,"mN",11); // vector_unid_2d of force with values "32 mN 11°"
vector_unit_2d z = vector_unid_2d(10,"kPa",48); // vector_unit_2d with values "10 kPa 48°"

x.theta += 21_angle; // theta of x can be accessed directed and used as any angle, it's the better way to use it

x += y; // Sum a vector of the same dimensions
y -= z; // Substraction supported. Can't substract vectors of different dimensions

force_2d a = x + y; // Sum of vector_unid_2d
force_2d b = x - y; // Substraction of vector_unid_2d

velocity_2d acc = acceleration_2d("5 m/s") * 100_s; // vector_unid_2d can multiply with scalar_unit
vector_unid_2d p = x / area("10 m2"); // vector_unid_2d can divide with scalar_unit

vector_unid_2d ab = x + 4; // vector_unid_2d can sum with numeric primitive types
vector_unid_2d ac = y - 7; // vector_unid_2d can substract with numeric primitive types
vector_unid_2d ad = x * 3; // vector_unid_2d can multiply with numeric primitive types
vector_unid_2d ae = y / 5; // vector_unid_2d can divide with numeric primitive types
vector_unid_2d xy = x ^ 2; // vector_unid_2d can power with numeric primitive types

x += 3; // vector_unid_2d with operator+= for numeric primitive types
y -= 9; // vector_unid_2d with operator-= for numeric primitive types
x *= 2; // vector_unid_2d with operator*= for numeric primitive types
y /= 6; // vector_unid_2d with operator/= for numeric primitive types

force e = x.x_projection(); // vector_unid_2d projection on the x axis
force f = x.y_projection(); // vector_unid_2d projection on the y axis

x.invert(); // Now x points to the opposite direction

string x_display = to_string(x); // Prints "21N 56°"
energy c = norm(x) * 2_m; // Use of norm() for vector_unit_2d
vector_unid_2d xy = sqrt(x^4); // Gives x ^ 2
vector_unid_2d xy = sqrt_nth(x^4,4); // Gives x
scalar_unit a = dot_product(x,y); // Gives the dot product of x and y, which is an scalar_unit
angle b = angle_between(x,y); // Gives the angle between the two vectors

if (same_direction(x,y)) // Gives true if the vectors point to the same direction
{}

if (parallel(x,y)) // Gives true if the vectors are parallel (point to the same or to the opposite direction)
{}

if (orthogonal(x,y)) // Gives true if the vectors are orthogonal (have 90° of difference in the direction they point to)
{}

if (x == y) // Gives true if the two vector_unit_2d are equal. There's the operator != too
{}

if (x == "21N 56°") // Gives true if the vector is the specified by the string. There's the operator != too
{}

string b;
b =+ x; // Appends x to the string b
string c = "x: " + x; // Creates a new string by inserting x as with to_string(x)
string d = x + " is a vector"; // Both directions are supported for creating strings with vector_unit_2d

cout << x; // Prints x in the output stream, any ostream can be used, not only cout. x is printed with to_string

vector_unit_2d a;
cin >> a; // Initializes a with the string given to cin

```

### Vector units in 3D

Vector units in 3D are the most useful vectorial units. They allow to do all the simulations of physics and any other area of science in 3D, which is the most common scenario. To work, they have, as vector_unit_2d, a value, dimensions, and an angle theta, but they include the angle phi. So, they work as spherical coordinates, having cartesian projections for each axis. The class vector_unit_3d inherits from scalar_unit, as vector_unit_2d, but not from vector_unit_2d, evading math errors that would be derived from that, because 2D and 3D dimensions are not mathematically equivalent in 2D (when projecting the x and y axis there appears the angle phi on the equations for the 3D cases).

An example of use is the following:

```cpp
force_3d x = force_3d(45_N,12_angle); // Creates a force_3d with a value of 45 N and an inclination angle of 12°
force_3d y = force_3d(78,"kN",67); // vector_unid_3d of force with values "78 mN 67°"
vector_unit_3d z = vector_unid_3d(100,"MPa",60); // vector_unit_3d with values "100 MPa 60°"

x.theta += 16; // theta of x can be accessed directed and used as any angle, it's the better way to use it
x.phi = 90; // phi of x can be accessed directly too

x += y; // Sum a vector of the same dimensions
y -= z; // Substraction supported. Can't substract vectors of different dimensions

force_3d a = x + y; // Sum of vector_unid_3d
force_3d b = x - y; // Substraction of vector_unid_3d

velocity_3d acc = acceleration_3d("25 m/s") * 100_s; // vector_unid_3d can multiply with scalar_unit
vector_unid_3d p = x / area("100 m2"); // vector_unid_3d can divide with scalar_unit

vector_unid_3d ab = x + 16; // vector_unid_3d can sum with numeric primitive types
vector_unid_3d ac = y - 98; // vector_unid_3d can substract with numeric primitive types
vector_unid_3d ad = x * 2; // vector_unid_3d can multiply with numeric primitive types
vector_unid_3d ae = y / 8; // vector_unid_3d can divide with numeric primitive types
vector_unid_3d xy = x ^ 4; // vector_unid_3d can power with numeric primitive types

x += 7; // vector_unid_3d with operator+= for numeric primitive types
y -= 19; // vector_unid_3d with operator-= for numeric primitive types
x *= 4; // vector_unid_3d with operator*= for numeric primitive types
y /= 2; // vector_unid_3d with operator/= for numeric primitive types

force e = x.x_projection(); // vector_unid_3d projection on the x axis
force f = x.y_projection(); // vector_unid_3d projection on the y axis
force f = x.z_projection(); // vector_unid_3d projection on the z axis

x.invert(); // Now x points to the opposite direction

string x_display = to_string(x); // Prints "45N 12°"
energy c = norm(x) * 2_m; // Use of norm() for vector_unit_3d
vector_unid_3d xy = sqrt(x^4); // Gives x ^ 2
vector_unid_3d xy = sqrt_nth(x^4,4); // Gives x
scalar_unit a = dot_product(x,y); // Gives the dot product of x and y, which is an scalar_unit
vector_unit_3d b = cross_product(x,y); // Gives the cross product of x and y, which is a vector_unit_3d
angle b = angle_between(x,y); // Gives the angle between the two vectors

if (same_direction(x,y)) // Gives true if the vectors point to the same direction
{}

if (parallel(x,y)) // Gives true if the vectors are parallel (point to the same or to the opposite direction)
{}

if (orthogonal(x,y)) // Gives true if the vectors are orthogonal (have 90° of difference in the direction they point to)
{}

if (x == y) // Gives true if the two vector_unit_3d are equal. There's the operator != too
{}

if (x == "45N 12°") // Gives true if the vector is the specified by the string. There's the operator != too
{}

string b;
b =+ x; // Appends x to the string b
string c = "x: " + x; // Creates a new string by inserting x as with to_string(x)
string d = x + " is a vector"; // Both directions are supported for creating strings with vector_unit_3d

cout << x; // Prints x in the output stream, any ostream can be used, not only cout. x is printed with to_string

vector_unit_3d a;
cin >> a; // Initializes a with the string given to cin

```

### Vector units in ND

Vector units in ND are very interesting vector units. They allow to operate in ND, which means, inside scifir-units, that the dimensions can be changed. ND allows to operate in 1D, 2D, 3D and more dimensions at the same time. The way they allow that is with a vector<angle> member-variable, which allows to control the angles of the n dimensions were the vector operates. For 2D it has one angle, as vector_unit_2d, and for 3D it has two angles, as vector_unit_3d. For 1D it doesn't has any angle.

An example of use is the following:

```cpp
force_nd x = force_nd(29_N,{8_angle,16_angle,32_angle}); // Creates a force_nd with a value of 29 N and an inclination angle of 8°, another of 16° and another of 32°
force_nd y = force_nd(44,"dN",{55,13,42}); // vector_unid_nd of force with values "44 dN 55° 13° 42°"
vector_unit_nd z = vector_unit_nd(81,"MPa",{32,44,67}); // vector_unit_nd with values "81 MPa 32° 44° 67°"

x.angles[0] += 7; // theta of x can be accessed directed and used as any angle, it's the better way to use it
x.angles[1] = 71; // phi of x can be accessed directly too
x.angles[2] -= 4;

x += y; // Sum a vector of the same dimensions
y -= z; // Substraction supported. Can't substract vectors of different dimensions

force_nd a = x + y; // Sum of vector_unit_nd
force_nd b = x - y; // Substraction of vector_unit_nd

velocity_nd acc = acceleration_nd("19 m/s",{14,52,33}) * 80_s; // vector_unit_nd can multiply with scalar_unit
vector_unit_nd p = x / area("100 m2"); // vector_unit_nd can divide with scalar_unit

vector_unit_nd ab = x + 9; // vector_unit_nd can sum with numeric primitive types
vector_unit_nd ac = y - 78; // vector_unit_nd can substract with numeric primitive types
vector_unit_nd ad = x * 3; // vector_unit_nd can multiply with numeric primitive types
vector_unit_nd ae = y / 5; // vector_unit_nd can divide with numeric primitive types
vector_unit_nd xy = x ^ 3; // vector_unit_nd can power with numeric primitive types

x += 45; // vector_unit_nd with operator+= for numeric primitive types
y -= 15; // vector_unit_nd with operator-= for numeric primitive types
x *= 3; // vector_unit_nd with operator*= for numeric primitive types
y /= 7; // vector_unit_nd with operator/= for numeric primitive types

force e = x.x_projection(); // vector_unit_nd projection on the x axis
force f = x.y_projection(); // vector_unit_nd projection on the y axis
force f = x.z_projection(); // vector_unit_nd projection on the z axis

force f = x.n_projection(2); // vector_unit_nd projection on the y axis, any axis can be specified. x is 1, y is 2, z is 3

x.invert(); // Now x points to the opposite direction

string x_display = to_string(x); // Prints "29N 8° 16° 32°"
energy c = norm(x) * 2_m; // Use of norm() for vector_unit_nd
vector_unid_nd xy = sqrt(x^4); // Gives x ^ 2
vector_unid_nd xy = sqrt_nth(x^4,4); // Gives x
scalar_unit a = dot_product(x,y); // Gives the dot product of x and y, which is an scalar_unit
vector_unit_nd b = cross_product(x,y); // Gives the cross product of x and y, which is a vector_unit_nd
angle b = angle_between(x,y); // Gives the angle between the two vectors

if (same_nd(x,y)) // Gives true if the vector have the same ND, if both are 2D, both are 3D, or both are 1D
{}

if (same_direction(x,y)) // Gives true if the vectors point to the same direction
{}

if (parallel(x,y)) // Gives true if the vectors are parallel (point to the same or to the opposite direction)
{}

if (orthogonal(x,y)) // Gives true if the vectors are orthogonal (have 90° of difference in the direction they point to)
{}

if (x == y) // Gives true if the two vector_unit_nd are equal. There's the operator != too
{}

if (x == "29N 8° 16° 32°") // Gives true if the vector is the specified by the string. There's the operator != too
{}

string b;
b =+ x; // Appends x to the string b
string c = "x: " + x; // Creates a new string by inserting x as with to_string(x)
string d = x + " is a vector"; // Both directions are supported for creating strings with vector_unit_nd

cout << x; // Prints x in the output stream, any ostream can be used, not only cout. x is printed with to_string

vector_unit_nd a;
cin >> a; // Initializes a with the string given to cin

```

### Coordinates and points in 1D

Coordinates in 1D allow to move any object, particle, solid or immaterial, through a 1D space. The coordinates_1d class has been implemented as a template class, allowing to use any scalar_unit, or, also, a single float. Any scalar_unit can be used, because then coordinates_1d allows to move in dimensions different than length, as dimensions on some science-fiction speculations are (because on some science-fiction ideas, a dimension can be anything).

point_1d is equivalent in functionality as coordinates_1d, it has the same member-variables and functions, its intended use is to be an abstract point in 1D, rather than a position in 1D (as coordinates_1d are).

An example of use of coordinates_1d is the following:

```cpp
coordinates_1d<length> x = coordinates_1d<length>(1_m);
coordinates_1d<length> y = coordinates_1d<length>(length(3,"km"));
coordinates_1d<length> z = coordinates_1d<length>("4 dam");
coordinates_1d<float> z = coordinates_1d<float>(12); // coordinates_1d can be used with a float in order to save memory, or if any other unit is useful for the use case

point_1d<length> a = point_1d<length>(1_dm);
x = a; // A coordinates_1d can be assigned a point_1d to get his same position

x.set_position(1_km); // the position is now 1 km
x.move(1_m); // move 1 m to the right
length x_distance = x.distance_to_origin(); // gives the absolute distance to the origin

string x_display = to_string(x); // prints the coordinates_1d
length xy_distance = distance(x,y); // calculates the distance between the two positions
length xa_distance = distance(x,a); // calculates the distance between a coordinates_1d and a point_1d

if (x == y) // gives true if both coordinates_1d are equal
{}

if (x == a) // gives true if coordinates_1d is equal to point_1d
{}

if (x == "1m") // gives true if the coordinates_1d are equal to the specified coordinates in the string
{}

string b;
b += x; // coordinates_1d can be added to an string
string c = "x: " + x; // coordinates_1d has an operator + with string to give another string

cout << x; // coordinates_1d can be printed to cout
cin >> x; // coordinates_1d can be initialized through cin
```

### Coordinates and points in 2D

coordinates_2d class allows to create software with positions in 2D. It has a very similar interface to coordinates_1d, it's initialized with an string of the form "1 m,2 m" or "(1 m,2 m)" because the character '(' can be present or not. It's, as coordinates_1d, a template class, and can then specify coordinates of any scalar_unit (usually, length), or with a float, if there's no unit that represents adequately the coordinates, or if it's needed to save some memory (because the float is lighter than a unit in his consumption of memory).

coordinates_2d can be used as cartesian and as polar coordinates at the same time. It has x and y as member-variables, which can be of the type of any scalar_unit or a float. When working with polar coordinates, the calculations are stored as x and y, that's, as cartesian coordinates, but when accessing it, with functions like get_p() and get_theta(), they give the values in polar coordinates. Then, at the same time, coordinates_2d behave as cartesian and as polar coordinates, by storing the values only once, not two times. Then, coordinates_2d is like a dual object, it contains cartesian_2d and polar_coordinates inside.

point_2d is equivalent to coordinates_2d, it's intended to be used as a point in 2D instead of as a position in 2D (as coordinates_2d). point_2d has the same functionalities as coordinates_2d, that's, the same functions and member-variables, but its use is intended to be semantic, it provides clarity as when in the program the data represents a position (as coordinates_2d) or an abstract point in 2D (as point_2d).

```cpp
coordinates_2d<length> x = coordinates_2d<length>(1_m,2_m);
coordinates_2d<length> y = coordinates_2d<length>(length(3,"km"),length(5,"dam"));
coordinates_2d<length> z = coordinates_2d<length>("4 dam,2 m"); // initialization string
coordinates_2d<float> z = coordinates_2d<float>(12,20); // coordinates_2d can be used with a float in order to save memory, or if any other unit is useful for the use case

point_2d<length> a = point_2d<length>(1_dm,5_cm);
x = a; // A coordinates_2d can be assigned a point_2d to get his same position

length x_p = x.get_p(); // coordinates_2d give the value of p of polar coordinates
angle x_theta = x.get_theta(); // coordinates_2d give the angle theta of polar coordinates

x.set_position(1_km,2_hm); // the position is now "1 km,2 hm"
x.set_position(1_m,angle(10)); // the position has been specified using polar coordinates
x.rotate(angle(10)); // rotate the position in the angle specified related to the origin
x.move(1_m,5_cm); // move 1 m to the right and 5 cm up
x.move(3_m,angle(20)); // move 3 m and 20° specified in polar coordinates
displacement_2d c_displacement = displacement_2d("2 km",10); // create a displacement_2d to specify a movement
x.move(c_displacement); // move in the specified displacement
length x_distance = x.distance_to_origin(); // gives the absolute distance to the origin

string x_display = to_string(x); // prints the coordinates_2d
string x_polar_display = x.display_polar(); // prints the coordinates_2d in polar coordinates
length xy_distance = distance(x,y); // calculates the distance between the two positions
length xa_distance = distance(x,a); // calculates the distance between a coordinates_2d and a point_2d

if (x == y) // gives true if both coordinates_2d are equal
{}

if (x == a) // gives true if coordinates_2d is equal to point_2d
{}

if (x == "1 m,2 m") // gives true if the coordinates_2d are equal to the specified coordinates in the string
{}

string b;
b += x; // coordinates_2d can be added to an string
string c = "x: " + x; // coordinates_2d has an operator + with string to give another string

cout << x; // coordinates_2d can be printed to cout
cin >> x; // coordinates_2d can be initialized through cin
```

### Coordinates and points in 3D

coordinates_3d class allows to work with positions in 3D. Its initialization string is of the form "10 m,5 m,3 m", or of the form "(10 m,5 m,3 m)".

coordinates_3d can be used as cartesian coordinates, as cylindrical coordinates, as spherical coordinates and as geographical coordinates at the same time. It has x, y and z as member-variables, which can be of the type of any scalar_unit or a float. When working with coordinates different than cartesian coordinates, the calculations are stored as x, y and z, that's, as cartesian coordinates, but when accessing it, with functions like get_p(), get_theta() and get_r(), they give the values in the other coordinates systems. Then, at the same time, coordinates_3d behave as cartesian, cylindrical, spherical and geographical coordinates, by storing the values only once, not various times. Then, coordinates_3d is like a multiple object, it contains cartesian_3d_coordinates, cylindrical_coordinates, spherical_coordinates and geographical_coordinates inside.

point_3d is equivalent to coordinates_3d, it change of name but not on functionality related to coordinates_3d. coordinates_3d is intended to represent positions in 3D, and point_3d is intended to be used as a point in 3D for any purpose (like graphical computing, as part of the matter of a physics body, an abstract point in space, etc).

```cpp
coordinates_3d<length> x = coordinates_3d<length>(1_m,2_m,3_m);
coordinates_3d<length> y = coordinates_3d<length>(length(3,"km"),length(5,"dam"),length(7,"hm"));
coordinates_3d<length> z = coordinates_3d<length>("4 dam,2 m,1 km"); // initialization string
coordinates_3d<float> z = coordinates_3d<float>(12,20,15); // coordinates_3d can be used with a float in order to save memory, or if any other unit is useful for the use case

point_3d<length> a = point_3d<length>(1_dm,5_cm,10_mm);
x = a; // A coordinates_3d can be assigned a point_3d to get his same position

length x_p = x.get_p(); // coordinates_3d give the value of p of cylindrical coordinates
angle x_theta = x.get_theta(); // coordinates_3d give the angle theta of cylindrical coordinates
length x_r = x.get_r(); // coordinates_3d give the value of r of spherical coordinates
angle x_phi = x.get_phi(); // coordinates_3d give the angle phi of spherical coordinates
angle x_latitude = x.get_latitude(); // coordinates_3d give the latitude of geographical coordinates
angle x_longitude = x.get_longitude(); // coordinates_3d give the longitude of geographical coordinates
length x_altitude = x.get_altitude(); // coordinates_3d give the altitude of geographical coordinates

x.set_position(1_km,2_hm,5_hm); // the position is now "1 km,2 hm,5 hm"
x.set_position(5_m,angle(46),3_m); // the position has been specified using cylindrical coordinates
x.set_position(1_m,angle(10),angle(15)); // the position has been specified using spherical coordinates
x.set_position(angle(20),angle(15),3_m); // the position has been specified using geographical coordinates
x.rotate_in_x(angle(10)); // rotate the position in the angle specified related to the x axis
x.rotate_in_y(angle(20)); // rotate the position in the angle specified related to the y axis
x.rotate_in_z(angle(35)); // rotate the position in the angle specified related to the z axis
x.move(1_m,5_cm,3_cm); // move 1 m to the right, 5 cm up and 3 cm depth
x.move(3_m,angle(20),2_m); // move 3 m, 20° and 2 m specified in cylindrical coordinates
x.move(5_m,angle(15),angle(10)); // move 5 m, 15° and 10° specified in spherical coordinates
displacement_3d c_displacement = displacement_3d("2 km",10,15); // create a displacement_3d to specify a movement
x.move(c_displacement); // move in the specified displacement
length x_distance = x.distance_to_origin(); // gives the absolute distance to the origin

string x_display = to_string(x); // prints the coordinates_3d
string x_cylindrical_display = x.display_cylindrical(); // prints the coordinates_3d in cylindrical coordinates
string x_spherical_display = x.display_spherical(); // prints the coordinates_3d in spherical coordinates
string x_geographical_display = x.display_geographical(); // prints the coordinates_3d in geographical coordinates
length xy_distance = distance(x,y); // calculates the distance between the two positions
length xa_distance = distance(x,a); // calculates the distance between a coordinates_3d and a point_3d

if (x == y) // gives true if both coordinates_3d are equal
{}

if (x == a) // gives true if coordinates_3d is equal to point_2d
{}

if (x == "1 m,4 m,7 m") // gives true if the coordinates_3d are equal to the specified coordinates in the string
{}

string b;
b += x; // coordinates_3d can be added to an string
string c = "x: " + x; // coordinates_3d has an operator + with string to give another string

cout << x; // coordinates_3d can be printed to cout
cin >> x; // coordinates_3d can be initialized through cin
```

## Internals

Internally, the library has some important mechanisms important to be known by a serious developer. Those important mechanisms are described here, in order to avoid the developer to read the code of the library and learn every detail.

The first important mechanism to describe is the static storage of custom dimensions. This storage is static, meaning that every time a unit of a dimension not registered is created, this storage is the one used, instead of the name being stored inside the instance. With that behavior, when instantiating a big amount of dimensions, a big amount of memory is saved. To refer to the static storage it's used the char symbol[3] of the dimension class, which uses only 3 bytes instead of the bytes the full dimension name would use. Then, each instance of a dimension class, given that static storage, uses only 6 bytes of memory.

The square of dimensions work in the following way: If the dimension consist only of one type of dimension, independently as if the dimension is a basic dimension or an abbreviation, the dimensions get squared. If the dimension is of more than one type, all the abbreviations are then converted to their derived types, and the total result gets squared. If the dimensions can't be squared because there's an odd number of them, the dimensions are then initialized empty.
