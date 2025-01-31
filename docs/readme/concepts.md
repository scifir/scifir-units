# Concepts

- In science, a **scalar unit** is a unit of measurement that adds dimensions to a number, in order to allow to manage concepts represents with numbers better. The dimensions can have prefixes, like kilo and deci, that scale the value by multiples of 10.
- The **International System of Units**, of abbreviation **SI**, defines the following **base units**: metre (m), second (s), gram (g), electric current (A), temperature (K), amount of substance (mol), luminous intensity (cd).
- The **decimal prefixes** are part of the SI system of units scale the value of the base unit by a factor. Examples of prefixes are the kilo (k, factor 3), deci (d, factor -1) and milli (m, factor -3).
- The **derived units**, part of the SI system of units, are the units derived from the base units.
- The **angle** is not exactly a scalar unit, but is similar. Its main difference with a scalar unit is that it's a mathematical concept, not a concept defined from natural science.
- As the angle, the **complex number** also is not a scalar unit, because it's a mathematical concept, not defined from natural science.
- The **laboratory number** allows to work with measures and possible errors of those measures. It's a mathematical concept invented for the laboratory.
- A **vector unit** is a vector that also has dimensions, like scalar units.
- A **scalar field** is a function that assigns a scalar unit to each point inside a space.
- A **vector field** is a function that assigns a vector unit to each point inside a space.
- The **space** is measured in units of lengths, which in the SI system of units is the metre. Inside scifir-units, it can be used a length, a float or a scalar unit of an imaginary dimension. The scalar_unit is the better system, the float is intended for high-performance computation needs, and the imaginary dimensions are needed when they are being used for some purpose in the project (and that's why they are supported here).
- A **space of two dimensions** has only two edges, it's an imaginary space that doesn't exist in the real world, but is used for simulations and some reasonings. It's abbreviated **2D**.
- A **space of three dimensions** has three edges, it can represent both the real world and imaginary worlds. It's abbreviated **3D**.
- Inside scifir-units, a space of a variable number of dimensions is abbreviated **ND**, of **space of n-dimensions**. ND can be sometimes 2D, sometimes 3D, also it can be 1D if needed, and even a space of a greather number of dimensions.
- The **tensors** are used inside scifir-units as any other scalar_unit, vector_unit or matrix, there's no tensor class because with those classes it's not needed.
- The **coordinates** are the position of an object in the space. There are coordinates for 2D and for 3D spaces, which are different systems of coordinates. For 2D spaces there exist the **cartesian coordinates** and the **polar coordinates**. For 3D space there exist the **cartesian coordinates**, the **cylindrical coordinates** and the **spherical coordinates**. The cartesian coordinates in 3D contain one more component of coordinates than their 2D counterpart.
- The **points**, although can be thinked as being identical to coordinates, are usually fixed in the space. The coordinates are used for the positions of objects inside the space, and the points for more fixed uses.
- A **percentage** is a mathematical concept that represents a fraction of some value, the fraction can be better than the value too.
- **AID**, acronym of **Astronomical ID**, and **ZID**, acronym of **Zone ID**, are two identifiers invented in Scifir that provide a text-based identifier to refer to astronomical objects and zones, respectively. They are considered a special unit inside scifir-units.
- The **pH** is a concept used in chemistry for measuring the concentration of H+ ions in a solution.
- The **concentrations** different than the molar concentration and the mass concentration are managed with ppm, ppb, ppt and ppq, which are part of the percentage class. Use percentage then for the **volume concentration**, the **mole fraction**, the **mole ratio**, the **mass fraction**, the **mass ratio** and the **volume fraction**.

## Tools of units in real life

### Base units

- **Length:** Ruler, tape measure, micrometer.
- **Angles:** Conveyor.
- **Volume:** Volumetric flask.
- **Mass:** Balance.
- **Time:** Chronometer, clock. Old tools: sundial, waterclock.
- **Electric current:** Amperimeter, oscilloscope.
- **Temperature:** Thermometre.
- **Amount of substance:** Volumetric flask with balance, then calculations.
- **Luminous intensity:** Photometer.

### Derived units

- **Pressure:** Barometer.
- **pH meter:** pH.
- **Geographical position:** GPS receiver.
- **Voltage:** Voltimeter.
- **Electrical resistance:** Multimeter.
- **Wavelength of light waves:** Interferometer.
- **Astronomical distances:** Astrolabe.

### Electronic sensors of units

- **Acceleration:** Accelerometer.
- **Angular velocity:** Gyroscope.
- **Geographical position:** GPS sensor.
- **Temperature:** Analog temperature sensor, digital temperature sensor, temperature switch, thermocouple ICs.
- **Infrared light:** IR sensor.
- **Electric field:** Electric field meter sensor.
- **Magnetic field:** Magnetic sensor.
- **Force:** Force sensor.

### Electronic motors of units

- **Movement:** Electronic motor (very different sizes available).
- **Valve:** Electronic valve.

## Constants

### Constants of the SI system of units

All constants of the SI system of units are implemeneted inside scifir-units, in the file **units/constants.hpp**. They are all **long double** types, use them to calculate anything you need.

| Constant | Value
| ------ | ------
| HYPERFINE_TRANSITION_FREQUENCY_OF_CS | $$9192631770 \  Hz$$
| SPEED_OF_LIGHT | $$299792458 \  m/s$$
| PLANCK_CONSTANT | $$6.62607015×10^{−34} \  J⋅s$$
| ELEMENTARY_CHARGE | $$1.602176634×10^{−19} \  C$$
| BOLTZMANN_CONSTANT | $$1.380649×10^{−23} \  J/K$$
| AVOGADRO_CONSTANT | $$6.02214076×10^{23} \  mol^{−1}$$
| LUMINOUS_EFFICACY_OF_540_THZ_RADIATION | $$683 \  lm/W$$

### Important science constants

| Constant | Value | Description
| ------ | ------ | ---------------
| GRAVITATIONAL_CONSTANT | $$6.6743×10^{-11} \  N*m2/kg2$$ | Proportionality constant connecting the gravitational force between two bodies.
| MOLAR_GAS_CONSTANT | $$8.31446261815324 \  J/K*mol$$ | Used the law of ideal gas. Energy per temperature increment per amount of substance.
| ATOMIC_MASS_CONSTANT | $$1.66053906660×10^{-27} \  Da$$ | Mass of an atom.
| COULOMB_CONSTANT | $$8.9875517873681764×10^9 \  N*m2/C2$$ | Constant of proportionality for the electrical variables.
| VACUUM_PERMITTIVITY | $$8.8541878188×10^{-12} \  F/m$$ | Value of the asbolute dielectric permittivity of classical vacuum.
| RYDBERG_CONSTANT | $$1.0973731568539×10^7 \  1/m$$ | Relates the electromagnetic spectra of an atom.
| FARADAY_CONSTANT | $$9.64853321233100184×10^4 \  C/mol$$ | It's the electric charge of one mole of elementary carriers.

## Preferences of use

- Always use the dimensions of the SI system over the imperial system, or any other system. Use always the system of units in use of your team, or on the board, with first preference, if there's a system selected.
- Always **prefer to use the string literals** when instantiating any scalar_unit or other class that uses it. Use the other constructors only if they are strictly needed.
- Prefer the **light year** over **parsec** and **astronomical units**. Use astronomical units only for distances of the same solar system.
- Use **degree** over radian, because it's more easy to understand by humans. Use radian when the value in radians is the direct result of some equation, as usually happens.
- The dimension degree and radian should be avoided in preference of the **angle class**.
- Use **kelvin** over celsius, because it's the current standard in science.
- Use the **litre** for volumes of liquids over cubic metres.
- Use pixel inside any digital space that needs it. You can convert to some amount of length, or another different amount of length, in different applications, as needed. The conversion of pixel to length varies depending on the reasoning behind each different use of pixel.
- The dimension **pixel** should always be avoided, in preference of the class pixel instead. Use this dimension only when it's strictly needed to have a scalar_unit, and then the class pixel can't be used.
- The dimension **money** is intended to be converted later to some concrete currency, with other libraries and data sources.
- **IU** should be converted specifically for each different reaction, because the IU unit is defined in science different for each case of use. Then, it doesn't has a direct conversion, and only one formula.

## Things to remember

- To store scalar_unit classes, any vector unit class, coordinates, and any other class of scifir-units, in a file or in a database, **store it in string form**. For example, to store the scalar_unit "100 m" inside a XML file, just store it as "100 m". Later, when parsing the XML file, you can construct the scalar_unit again, because the string form is the same as the initialization string of scalar_unit.
- All **vector unit classes inherit scalar_unit**. Then, vector_unit_2d, vector_unit_3d and vector_unit_nd are also scalar_unit classes.
- The **display()** function in all classes displays the number truncated to 2 digits of the decimal part by default. The number of digits in the decimal part can be changed to a value different than 2 in each call of that function.
- When comparing two numerical values, the display() function is truncating the decimal part, and so two classes can display identical but have a decimal part in the portion that hasn't been displayed. Then, the comparison will give false even if the display is equal. If you want to compare only the display of the class, then the comparison has to be done for the display.
- If you want to compare two numerical values that are similar but not necessarily identical, you can use **std::fabs(a - b) < 0.01f** to test if the values are similar.
- All coordinates classes have support at the same time all the coordinates systems of their respective number of dimensions, not only cartesian coordinates.
- To create, in your project, derived units, with base dimensions different than the base and derived units defined inside scifir-units, use **SCALAR_UNIT_HPP(new_unit)** and **SCALAR_UNIT_CPP(new_unit,"init_dimensions")** to define new scalar_unit classes. Use **VECTOR_UNIT_HPP** and **VECTOR_UNIT_CPP** in the same manner to define all vector_unit classes (2d, 3d and nd) and also the scalar_unit class. The suffixes _2d, _3d and _nd will be automatically added. Use **VECTOR_UNIT_2D_HPP**, **VECTOR_UNIT_3D_HPP** and **VECTOR_UNIT_ND_HPP** with their respective **VECTOR_UNIT_2D_CPP**, **VECTOR_UNIT_3D_CPP** and **VECTOR_UNIT_ND_CPP** to define only the respective vector unit class without defining the other types too.
