# Core functionalities

All the classes of scifir-units are inside the **namespace scifir**, as with all libraries of the **Scifir Collection**. So, to use any of this classes, like angle, you have to type any of the following codes:

```cpp
using namespace scifir; // Maybe this is usually the better choice
scifir::angle a; // You can use the namespace directly
```

All the example code presented here is written assuming you know this namespace scifir.

## String representation of enum types

All enum types, excepting astronomical_body, have a string representation. The string representation is similar to the initialization string of classes, but is for enum types. The string representation of all enum types corresponds to the value in string form, or to an acronym of it. In the reference of the enum type, the string representation is explained for each value. For example, the value GALAXY of aid::type has a string representation "G". You can get the string representation with the to_string() function of scifir-units of that enum type, like, for example, to_string(aid::type).

## Space

Inside scifir-units the space can be measured with length or with float. Secondarily, any scalar_unit can be used as measure of space, because inside science there are modelings of imaginary spaces, where the length is not used. Because of that reason, all coordinates and point classes are template classes that accept floats or scalar_unit classes.

N-dimensions, inside scifir-units, are called **ND** in classnames. ND classes allow to change the number of dimensions of the space where they behave, by just changing their number of values to a different number of them. You can always change the values of ND classes to change the space they operate on to a different space. Then, if you're developing a software where for some reason the space changes from 2D to 3D, or viceversa, you can use ND classes for that purpose.

## Dimensions

A **SI base dimension** is a base dimension under the SI system of units. A **SI derived dimension** is a derived dimension under the SI system of units. The SI base dimensions are the **metre** (m), **kilogram** (kg), **second** (s), **mole** (mol), **candela** (cd), **kelvin** (K) and **ampere** (A).

Inside scifir-units a **base dimension** is a dimension considered base under the SI system of units, excepting AMPERE, which has been changed by COULOMB, among other dimensions more that have been added. The other base dimensions inside scifir-units are **radian** (rad), **steradian** (sr), **byte** (B), **money** (money), **memo** (memo), and all CUSTOM_BASIC dimensions. A **derived dimension** is any dimension that's not a base dimension.

Different to that, a **simple dimension** is a dimension with only one base dimension. A **composite dimension** is a dimension with more than one base dimension.

A dimension is a **special name** if it has a symbol that means one or more base dimensions of the SI system of units, that's used instead of them. Inside scifir-units, it's called **abbreviation** a special name that's not part of the SI system of units, but instead a special name taken from any other system.

A **single dimension** is a scalar unit or vector unit that has only one dimension, which can be any simple dimension or composite dimension, it's only needed to don't be more than one dimension present in the same unit.

The dimensions that a scalar_unit class can have are available in the enum dimension::type, and are only the SI dimensions or, if there isn't a dimension for an important purpose in the SI system of units, a selected dimension of the different possible options. Only the prefered dimensions have been added to the enum dimension::type, the other dimensions, as for example England units, have been added only as conversion options. With that system, always the same dimensions are used, which simplifies the work inside a laboratory, because then there's less confusion about which dimensions are being used.

A dimension inside scifir-units is **dimensionless** if it's dimensionless in the SI system of units. Following that rule, the dimensions degree, radian and steradian are dimensionless. When there's no dimension, because of the value NONE, it's considered dimensionless too.

Dimensions present in scifir-units not so widely known are the **steradian** (sr, solid angles), **katal** (kat, catalytic activity), **angstrom** (Å, length for wavelengths), **dalton** (Da, mass for atoms and molecules), **atomic mass unit** (same as Da), **electron volt** (eV, measure of very small amounts of energy, mainly for quantum physics), **candela** (cd, luminous intensity), **lumen** (lm, luminous flux), **lux** (lx, illuminance), **siemens** (S, electric cnoductance), **weber** (Wb, magnetic flux), **tesla** (T, magnetic strength), **henry** (H, electric inductance), **astronomical unit** (AU, long astronomic distances), **light year** (ly, very long astronomic distances), **parsec** (pc, very long astronomic distances), **becquerel** (Bq, radioactivity), **gray** (Gy, absorbed dose of ionising radiation), **sievert** (Sv, equivalent dose of ionising radiation), **barn** (Barn, transversal section of nuclear reactions). An invented unit inside Scifir is **memo**, which is used to measure the amount of memory inside the brain.

### Criterias for inclusion of dimensions

**Any** of the following criterias must be met by a dimension to be added inside scifir-units:

- To be part of the **SI system of units**.
- To be an important unit of measure, being used widely by scientists, defined inside an important science organization.
- To be a liked unit of measure different in use and definition than any other official unit of measure, and being used by scientists.

### Dimensions of space

Both the degree and the radian are used for measuring angles. When specifying angles in a human readable way, degree is always or nearly always the prefered choice. When specifying angles within mathematical formulas, radians are used, and the degrees can be converted to radians for that purpose. Given the definition of radian, mathematical formulas naturally have their angles needed to be specified in radians.

| dimension::type | Symbol | Name | Plural | Type | Equivalency | Derived dimensions | Origin | Description
| ------ | --- | ----- | ----- | -------- | --- | -------------------- | ------------- | --------------------------
| METRE | m | Metre | Metres | Simple, base, SI base | - | - | Metre Convention, France, 1791. | Measure of length.
| DEGREE | θ | Degree | Degrees | Simple, derived, SI derived | $$\frac{\pi}{180} \  rad$$ | - | Babylonians and/or Summerians. | Measure of length.
| RADIAN | rad | Radian | Radians | Simple, base, SI derived | $$\frac{180}{\pi} \  θ$$ | - | Roger Cotes, Harmonia mensurarum, 1722. | Measure of the angle, it's the exact measure of the perimeter of the angle, when that angle is drawn as a circle in a math graph. **Special name**.
| STERADIAN | sr | Steradian | Steradians | Simple, base, SI derived | - | - | 1880 - 1885, France. | Measure of a solid angle, which is defined as an angle in two dimensions. **Special name**.
| LITRE | L | Litre | Litres | Composite, derived | 1 dm3 | dm3 | 1795, France. | Measure of volume, frequently used for liquids.

### Dimensions of time

| dimension::type | Symbol | Name | Plural | Type | Equivalency | Derived dimensions | Origin | Description
| ------ | --- | ----- | ----- | -------- | --- | -------------------- | ------------- | --------------------------
| SECOND | s | Second | Seconds | Simple, base, SI base | - | - | 1656, Christiaan Huygens. Summerians. | Measure of time.
| MINUTE | min | Minute | Minutes | Simple, derived | - | 60 s | Summerians. | Measure of time.
| HOUR | hour | Hour | Hours | Simple, derived | - | 3,600 s | Summerians. | Measure of time.
| DAY | day | Day | Days | Simple, derived | - |  86,400 s | Always existed, summerians. | Measure of time.
| HERTZ | Hz | Hertz | Hertz | Simple, derived, SI derived | - | 1 / s | International Electrotechnical Commission, 1930. | Measure of frequency. **Special name**.

### Dimensions of chemistry and matter

| dimension::type | Symbol | Name | Plural | Type | Equivalency | Derived dimensions | Origin | Description
| ------ | --- | ----- | ----- | -------- | --- | -------------------- | ------------- | --------------------------
| GRAM | g | Gram | Grams | Simple, base, SI base | - | - | French National Convention, 1795. | Measure of amount of mass.
| MOLE | mol | Mole | Moles | Simple, base, SI base | N particles (Avogadro number) | - | Wilhelm Ostwald, 1893. | Amounf of matter.
| PARTICLES | particles | Particles | Particles | Simple, derived | mol / (Avogadro number) | - | scifir-units. | Amount of particles, without using mol.
| MOLARITY | M | Molarity | Molarities | Composite, derived | - | mol / L | 1930. | Measure of concentration of a chemical species.
| KATAL | kat | Katal | Katals | Composite, derived, SI derived | - | mol / s | International Bureau of Weights and Measures (BIPM), 1999. | Catalytic activity.
| ANGSTROM | Å | Angstrom | Angstroms | Simple, derived | - | $$10^{-10} \  m$$ | International Union of Cooperation in Solar Research (currently called International Astronomical Union), 1907. | Dimension of length, used mainly for wavelengths, inside the laboratory.
| DALTON | Da | Dalton | Daltons | Simple, derived | - | $$1,66053886 * 10^{-24} \  g$$ | IUPAC, 1993. | Measure of mass very low that is used for atoms and molecules, at microscopic and quantum scale. One mole of 1 Da is equivalent to 1 g.
| ATOMIC_MASS_UNIT | amu | Atomic mass unit | Atomic mass units | Simple, derived | 1 Da | Da | 1927. | Equivalent name to Dalton.

### Dimensions of force

| dimension::type | Symbol | Name | Plural | Type | Equivalency | Derived dimensions | Origin | Description
| ------ | --- | ----- | ----- | -------- | --- | -------------------- | ------------- | --------------------------
| NEWTON | N | Newton | Newtons | Composite, derived, SI derived | - | kg * m / s2 | International Bureau of Weights and Measures (BIPM), 1948. | Measure of force. **Special name**.
| PASCAL | Pa | Pascal | Pascals | Composite, derived, SI derived | - | kg / s2 * m | International Bureau of Weights and Measures (BIPM), 1971. | Measure of pressure. **Special name**.

### Dimensions of energy

| dimension::type | Symbol | Name | Plural | Type | Equivalency | Derived dimensions | Origin | Description
| ------ | --- | ----- | ----- | -------- | --- | -------------------- | ------------- | --------------------------
| JOULE | J | Joule | Joules | Composite, derived, SI derived | - | kg * m2 / s2 | Wilhelm Siemens, British Association for the Advancement of Science, 23 August 1882. | Measure of energy. **Special name**.
| WATT | W | Watt | Watts | Composite, derived, SI derived | N particles (Avogadro number) | kg * m2 / s3 | Wilhelm Siemens, British Association for the Advancement of Science, 23 August 1882. | Amounf of matter. **Special name**.
| ELECTRON_VOLT | eV | Electron volt | Electron volts | Composite, derived | - | $$1.602176634 * 10^{−19} \  J$$ | After 1909. | Measure of energy, used for quantum physics. It's a very low unit, intended for the quantum scale.

### Dimensions of optics

| dimension::type | Symbol | Name | Plural | Type | Equivalency | Derived dimensions | Origin | Description
| ------ | --- | ----- | ----- | -------- | --- | -------------------- | ------------- | --------------------------
| CANDELA | cd | Candela | Candelas | Simple, base, SI base | - | - | 1948, International Bureau of Weights and Measures (BIPM). | Measure of luminous intensity.
| LUMEN | lm | Lumen | Lumens | Composite, derived, SI derived | - | cd * sr | André-Eugène, late 19th century. | Measure of luminous flux. **Special name**.
| LUX | lx | Lux | Luxes | Composite, derived, SI derived | - | cd * sr / m2 | Bartholomew of Bologna, 13th century. | Measure of illuminance. **Special name**.

### Dimensions of heat

| dimension::type | Symbol | Name | Plural | Type | Equivalency | Derived dimensions | Origin | Description
| ------ | --- | ----- | ----- | -------- | --- | -------------------- | ------------- | --------------------------
| KELVIN | K | Kelvin | Kelvins | Simple, base, SI base | - | - | Lord Kelvin, 1848. | Measure of temperature.
| CELSIUS | °C | Celsius | Celsius | Simple, derived, SI derived | 1°C = K - 273.15 | K | Anders Celsius, 1742. | Measure of temperature, derived from kelvin. **Special name**.

### Dimensions of electricity

| dimension::type | Symbol | Name | Plural | Type | Equivalency | Derived dimensions | Origin | Description
| ------ | --- | ----- | ----- | -------- | --- | -------------------- | ------------- | --------------------------
| COULOMB | C | Coulomb | Coulombs | Simple, base, SI derived | - | - | International Electrical Congress, 1881. | Measure of electric charge. **Special name**.
| AMPERE | A | Ampere | Amperes | Simple, derived, SI base | - | C / s | International Exposition of Electricity, 1881. | Measure of electric current.
| VOLT | V | Volt | Volts | Composite, derived, SI derived | - | J / C, W / A | International Electrical Congress, 1881. | Measure of voltage. **Special name**.
| FARAD | F | Farad | Farads | Composite, derived, SI derived | - | A * s / V | International Electrical Congress, 1881. | Measure of electric capacitance. **Special name**.
| OHM | Ω | Ohm | Ohms | Composite, derived, SI derived | - | V / A | International Electrical Congress, 1881. | Measure of electric resistance. **Special name**.
| SIEMENS | S | Siemens | Siemens | Composite, derived, SI derived | - | 1 / Ω | International Electrical Congress, 1935. | Measure of electric conductance. **Special name**.
| WEBER | Wb | Weber | Webers | Composite, derived, SI derived | - | T * m2 | International Electrotechnical Commission, 1935. | Measure of magnetic flux. **Special name**.
| TESLA | T | Tesla | Teslas | Composite, derived, SI derived | - | V * s / m2 | International Bureau of Weights and Measures (BIPM), 1960. | Measure of magnetic strength. **Special name**.
| HENRY | H | Henry | Henries | Composite, derived, SI derived | - | V * s / A | International Electrical Congress, 1893. | Measure of electric inductance. **Special name**.

### Dimensions of astronomy

| dimension::type | Symbol | Name | Plural | Type | Equivalency | Derived dimensions | Origin | Description
| ------ | --- | ----- | ----- | -------- | --- | -------------------- | ------------- | --------------------------
| ASTRONOMICAL_UNIT | AU | Astronomical unit | Astronomical units | Simple, derived | - | 149,597,870,700 m | International Astronomical Union, 1976. | Measure of long distances, for use in the space.
| LIGHT_YEAR | ly | Light year | Light years | Simple, derived | 63,241.07 AU | 9,460,730,472,580,800 m | Friedrich Bessel, 1838. | Measure of long distances, for use in the space. It's exactly defined as the amount of distance that the light travels in a year. Prefixes commonly used with light-years when distances are too large are **kly**, **Mly** and **Gly**, any other prefix is possible to use too. Use them if the distance in space is large enough that even ly is small.
| PARSEC | pc | Parsec | Parsecs | Simple, derived | - | 3.2616 ly | Herbert Hall Turner, 1913. | Measure of long distances, for use in the space.

### Dimensions of nuclear physics

| dimension::type | Symbol | Name | Plural | Type | Equivalency | Derived dimensions | Origin | Description
| ------ | --- | ----- | ----- | -------- | --- | -------------------- | ------------- | --------------------------
| BECQUEREL | Bq | Becquerel | Becquerels | Simple, derived, SI derived | - | 1 / s | International Commission on Radiation Units and Measurements (ICRU), 1975. | Measure of radioactivity. **Special name**.
| GRAY | Gy | Gray | Grays | Composite, derived, SI derived | - | m2 / s2 | International Commission on Radiation Units and Measurements (ICRU), 1975. | Measure of ionising radiation (absorbed dose). **Special name**.
| SIEVERT | Sv | Sievert | Sieverts | Composite, derived, SI derived | - | J / kg | International Commission on Radiation Units and Measurements (ICRU), after 1975. | Measure of ionising radiation (equivalent dose). **Special name**.
| BARN | Barn |  Barn | Barns | Composite, derived | - | $$10^{−28} \  m2$$  | MG Holloway and CP Baker, 1942. | Represents the transversal section of nucleus and nuclear reactions.

### Dimensions of informatics

| dimension::type | Symbol | Name | Plural | Type | Equivalency | Derived dimensions | Origin | Description
| ------ | --- | ----- | ----- | -------- | --- | -------------------- | ------------- | --------------------------
| BYTE | B | Byte | Bytes | Simple, base | - | - | Werner Buchholz, june 1956. | Measure of quantity of information.
| BIT | bit | bit | bits | Simple, derived | - | - | Claude Shannon, 1948. | Measure of quantity of information, of each binary digit.
| PIXEL | px | Pixel | Pixels | Simple, base | - | - | SPIE, 1965. | Measure the amount of pixels or the position inside a screen.

### Dimensions of biology

Inside scifir-units, a unit for measuring the quantity of memory inside the brain has been invented, and has been called **memo**.

| dimension::type | Symbol | Name | Plural | Type | Equivalency | Derived dimensions | Origin | Description
| ------ | --- | ----- | ----- | -------- | --- | -------------------- | ------------- | --------------------------
| MEMO | memo | Memo | Memos | Simple, base | - | - | scifir-units, 2022. | Measure of quantity of memory.

### Dimensions of pharmacology

**Be careful!** International units (IU) vary in the amount of mass they represent for different substances.

| dimension::type | Symbol | Name | Plural | Type | Equivalency | Derived dimensions | Origin | Description
| ------ | --- | ----- | ----- | -------- | --- | -------------------- | ------------- | --------------------------
| INTERNATIONAL_UNIT | IU | International unit | International units | Simple, base | - | - | League of Nations Health Organisation, 1931. | Measure of the effect or biological activity of a substance. It varies for each substance the amount of grams it represents for that substance.
| MILLIEQUIVALENT | mEq | Milliequivalent | Milliequivalents | Simple, base | - | - | Jeremias Benjamin Richter, 1792. | Amount of moles in a given chemical reaction needed to react with an amount of moles of another substance.

### Dimensions of economy

The dimension of money inside scifir-units is just money. Apart from scifir-units, inside the same code, you can use the **ISO 4217**, which is the **ISO of currency codes**, after doing all the math with the money dimension, to convert to the final currency needed.

| dimension::type | Symbol | Name | Plural | Type | Equivalency | Derived dimensions | Origin | Description
| ------ | --- | ----- | ----- | -------- | --- | -------------------- | ------------- | --------------------------
| MONEY | money | Money | Money | Simple, base | - | - | 700 BC. | Measure of money.

### Custom dimensions

A custom dimension is a dimension of any name, with any number of base dimensions, that can be defined inside each project that uses scifir-units. To use custom dimensions, just initialize a scalar_unit or any vector_unit class with a name different than the default dimensions.

The dimension::type enum contains for the custom dimensions the values CUSTOM, CUSTOM_FULL_SYMBOL and CUSTOM_BASIC.

## Prefix

The prefixes are writed before the dimension, both on string literals and initialization strings. In any initialization string of dimensions you can write the symbol of the prefix before the symbol of the dimension.

| prefix::type | Symbol | Scale
| ------ | --- | ---
| QUETTA | Q | 30
| RONNA | R | 27
| YOTTA | Y | 24
| ZETTA | Z | 21
| EXA | E | 18
| PETA | P | 15
| TERA | T | 12
| GIGA | G | 9
| MEGA | M | 6
| KILO | k | 3
| HECTO | h | 2
| DECA | da | 1
| NONE | - | 0
| DECI | d | -1
| CENTI | c | -2
| MILLI | m | -3
| MICRO | µ | -6
| NANO | n | -9
| PICO | p | -12
| FEMTO | f | -15
| ATTO | a | -18
| ZEPTO | z | -21
| YOCTO | y | -24
| RONTO | r | -27
| QUECTO | q | -30

## Angle

An angle object manages angles. It stores angles in degrees, rather than in radians. It can be initialized to any degree between 0 and 360 (without including 360, cause this is identical to 0 in meaning), and any initialization that's not inside this range of values gets automatically converted inside it, to his equivalent value between the range.

An example of use of angle is the following:

```cpp
// Constructors and instantiation
angle x = 37_degree; // Better constructor for degrees! Prefered method for degrees
angle x2 = 3_rad; // Better constructor for radians! Prefered method for radians
angle y = 54; // Other good constructor! Of the prefered methods
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
float a_degree = x.get_degree();
float a_radian = x.get_radian();
x.invert(); // Inverts the angle, the orientation described by this angle points now in the opposite direction
float y = float(x); // Angles can be converted to float
```

### Angle literals

| Literal | Use
| ----- | --------------------------
| _degree | Creates a new angle of the degrees given. **Example:** scifir::angle a = 30_degree.
| _rad | Creates a new angle of the radians given. The value of the radian is internally converted to degrees, angle class always uses degrees internally. The value can be obtained in radian form using get_radian(). **Example:** scifir::angle a = 5.0_rad.

## Scalar units

Scalar units and vector units are the central objects of scifir-units. They store a value and a set of dimensions, as units on science do. Scalar units are just normal values, while vector units have a value and a direction to which the vector points to.

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

## Vector units in 2D

Vector units in 2D allow to do calculations for lab machines and simulations of physics and other areas of science in 2 dimensions. They inherit scalar_unit, and additional to his member-variables they include the member-variable theta, of class angle (described above).

Vector unit classes in 2D, representing either base or derived vectorial units, have in their name the **suffix _2d**.

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

## Vector units in 3D

Vector units in 3D are the most useful vectorial units. They allow to do all the simulations of physics and any other area of science in 3D, which is the most common scenario. To work, they have, as vector_unit_2d, a value, dimensions, and an angle theta, but they include the angle phi. So, they work as spherical coordinates, having cartesian projections for each axis. The class vector_unit_3d inherits from scalar_unit, as vector_unit_2d, but not from vector_unit_2d, evading math errors that would be derived from that, because 2D and 3D dimensions are not mathematically equivalent in 2D (when projecting the x and y axis there appears the angle phi on the equations for the 3D cases).

Vector unit classes in 3D, representing either base or derived vectorial units, have in their name the **suffix _3d**.

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

## Vector units in ND

Vector units in ND are very interesting vector units. They allow to operate in ND, which means, inside scifir-units, that the dimensions can be changed. ND allows to operate in 1D, 2D, 3D and more dimensions at the same time. The way they allow that is with a vector<angle> member-variable, which allows to control the angles of the n dimensions were the vector operates. For 2D it has one angle, as vector_unit_2d, and for 3D it has two angles, as vector_unit_3d. For 1D it doesn't has any angle.

Vector unit classes in ND, representing either base or derived vectorial units, have in their name the **suffix _nd**.

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

## Coordinates and points in 1D

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

## Coordinates and points in 2D

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

## Coordinates and points in 3D

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

## AID and ZID

An **AID**, acronym of **Astronomycal ID**, is an identifier of an astronomical object, like planets, moons, galaxies, stars, and any other astronomical object.

A **ZID**, acronym of **Zone ID**, is an identifier of a zone, like a region, a district, a store, a lake, a country, and any other zone. A zone is defined here as any closed surface that can be drawn over an astronomycal object. A ZID is composed of the AID of which the zone pertains, and the zone itself.

## percentage

The **percentage** class represents percentages, they calculate the factor of the percentage and automatically, when operating with numeric types, calculate the percentage of that number.

## pixel

The **pixel** class represents pixels, which are the squares that compose screens. It can be used to calculate distance over pixels instead of distances of physical lengths, which is a need of some digital applications.

## pH and pOH

The **pH** class allows to work with pH, which is used inside chemistry software to store data about pH. The **pOH** class is the counterpart of the pH class, and is not commonly needed, but it can be used if the pH class is not being useful for some reason, and if instead the pOH class is useful. The pH class should always be **prefered** to be used over the pOH class, and that last should be used **only** if the pH class is not properly solving the needs.

## Sizes in 2D, 3D and ND

The **size_2d** class allows to store the data of the width and height of an object in length classes. The **size_3d** allows to store the data of the width, the height and the depth of an object in length classes. The **size_nd** class allows to store lengths corresponding to the dimension of an object in a variable number of dimensions.
