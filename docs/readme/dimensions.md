# Dimensions - scifir-units

Dimensions are the available dimensions that a scalar unit class, and also a vector unit class, can use to display it's value in reference to that dimension.

A **SI base dimension** is a base dimension under the SI system of units. A **SI derived dimension** is a derived dimension under the SI system of units. The SI base dimensions are the **metre** (m), **kilogram** (kg), **second** (s), **mole** (mol), **candela** (cd), **kelvin** (K) and **ampere** (A).

Inside scifir-units a **base dimension** is a dimension considered base under the SI system of units, excepting AMPERE, which has been changed by COULOMB, among other dimensions more that have been added. The other base dimensions inside scifir-units are **radian** (rad), **steradian** (sr), **byte** (B), **money** (money), **memo** (memo), and all CUSTOM_BASIC dimensions. A **derived dimension** is any dimension that's not a base dimension.

Different to that, a **simple dimension** is a dimension with only one base dimension. A **composite dimension** is a dimension with more than one base dimension.

A dimension is a **special name** if it has a symbol that means one or more base dimensions of the SI system of units, that's used instead of them. Inside scifir-units, it's called **abbreviation** a special name that's not part of the SI system of units, but instead a special name taken from any other system.

A dimension inside scifir-units is **dimensionless** if it's dimensionless in the SI system of units. Following that rule, the dimensions degree, radian and steradian are dimensionless.

## Dimensions frequently unknown

Dimensions present in scifir-units not so widely known are the **steradian** (sr, solid angles), **katal** (kat, catalytic activity), **angstrom** (Å, length for wavelengths), **dalton** (Da, mass for atoms and molecules), **atomic mass unit** (same as Da), **electron volt** (eV, measure of very small amounts of energy, mainly for quantum physics), **candela** (cd, luminous intensity), **lumen** (lm, luminous flux), **lux** (lx, illuminance), **siemens** (S, electric cnoductance), **weber** (Wb, magnetic flux), **tesla** (T, magnetic strength), **henry** (H, electric inductance), **astronomical unit** (AU, long astronomic distances), **light year** (ly, very long astronomic distances), **parsec** (pc, very long astronomic distances), **becquerel** (Bq, radioactivity), **gray** (Gy, absorbed dose of ionising radiation), **sievert** (Sv, equivalent dose of ionising radiation), **barn** (Barn, transversal section of nuclear reactions). An invented unit inside Scifir is **memo**, which is used to measure the amount of memory inside the brain.

## Our criterias for inclusion of dimensions in scifir-units

**Any** of the following criterias must be met by a dimension to be added inside scifir-units:

- To be part of the **SI system of units**.
- To be an important unit of measure, being used widely by scientists, defined inside an important science organization.
- To be a liked unit of measure different in use and definition than any other official unit of measure, and being used by scientists.

## Prefixes

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

## List of dimensions

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
| DIMENSION_PASCAL | Pa | Pascal | Pascals | Composite, derived, SI derived | - | kg / s2 * m | International Bureau of Weights and Measures (BIPM), 1971. | Measure of pressure. **Special name**. It's called DIMENSION_PASCAL instead of PASCAL in order to have compatibility with the compiler msvc.

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