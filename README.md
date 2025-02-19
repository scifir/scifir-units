# scifir-units

[![Linux build status](https://github.com/scifir/scifir-units/actions/workflows/cmake.yml/badge.svg)](https://github.com/scifir/scifir-units/actions/workflows/cmake.yml)

## Copy-paste symbols

| Symbol | Use
| --- | -----
| θ | String literal of angle and used both in vector_unit_2d and vector_unit_3d.
| Φ | Angle phi, used in vector_unit_3d.
| ° | Degree, used in vector_unit_nd and angle class.
| Ω | String literal of resistance.
| Å | String literal of angstrom.
| µ | Prefix micro, used as part of the string literals with micro.

## Welcome!

Still in **beta version 2.0** (you can use it!)

```
scifir-chemistry, scifir-biology, scifir-geometry, among others, not yet published in GitHub.
```

Welcome! **scifir-units** is a **C++ library**, **portable to other programming languages**, that's a fundamental part of the Scifir collection. It allows to create units of measurement, vectors with units of measurement, coordinates, special units of measurement like percentage and pH, among other topics related to units of measurement. The units of measurement are **very lightweight**, size similar to a float, and can be used to do any math calculation necessary for any electronic invention and digital software. The **prefixes** of the **dimensions** can be changed, in order to display the unit in the more proper dimensions. Also, all the **conversions** are supported.

The unit classes of scifir-units are:

- **scalar_unit:** Handles scalar units, with dimensions and prefixes, and supports conversions.
- **vector_unit_2d:** Handles vector units in 2D dimensions. Inherits scalar_unit.
- **vector_unit_3d:** Handles vector units in 3D dimensions. Inherits scalar_unit.
- **vector_unit_nd:** Handles vector units in ND dimensions. Inherits scalar_unit.

The **Scifir collection** is a set of scientific libraries, written in **C++**, for developing **laboratory machines** and **scientific inventions**. Also, any **electronic device**, **medical machine**, **electrodomestic** or **vehicle** can be benefited with the use of units and related classes. It provides units, molecules, among other features, to allow developers of scientific software to develop their software and firmware easy. Enjoy!

Learn how to use scifir-units in the website [https://scifir.github.io/scifir-units](https://scifir.github.io/scifir-units) (that documentation has been done with **doxygen** and uses the **dox files** located in the folder **./docs/dox**).

scifir-units has been developed under **C++20** and uses **cmake** as build tool. It works in all platforms, including **Linux distributions** and **Windows**.

## Short example

```cpp
#include "scifir/units.hpp"

scifir::length x = 100_km; // length is a child class of scalar_unit, only supports dimensions convertible to metre
cout << x << endl; // Prints "100 km"
x.change_dimensions("m");
cout << x << endl; // Prints "100000 m"

scifir::force_2d y(50_N,20_degree); // force_2d is a child class of vector_unit_2d
cout << y << endl; // Prints "50 N 20θ"

scifir::force_2d y2(30_N,10_degree);
cout << y2 << endl;
cout << (y + y2) << endl; // Prints the vectorial sum of y + y2
y2.theta += 10; // Sums 10 degrees to theta of y2
cout << y2.theta << endl; // Prints theta of y2 "20°"

scifir::force_3d z(50_N,20_degree,40_degree); // force_3d is a child class of vector_unit_3d
cout << z << endl; // Prints "50 N 20θ 40Φ"
z.theta += 15; // Sums 15 degrees to theta of z
z.phi += 10; // Sums 10 degrees to phi of z
cout << z.theta << endl; // Prints theta of z "35°"
cout << z.phi << endl; // Prints phi of z "50°"

scifir::angle a = 100_degree; // angle class is not a scalar_unit
a++; // Increments a by one unit
cout << a << endl; // Prints "100°"

scifir::coordinates_3d<> b(10_m,5_m,30_m); // coordinates_3d<> has length as dimension of space. float and imaginary dimensions are also supported for the space
cout << b << endl; // Prints "(10 m,5 m,30 m)"

scifir::aid c("(P) universe:milky-way:solar-system:earth"); // aid is an identifier for any astronomical object
cout << c << endl; // Prints "(P) universe:milky-way:solar-system:earth"

scifir::zid d("(P) universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia"); // zid is an identifier for any zone, of any astronomical object
cout << d << endl; // Prints "(P) universe:milky-way:solar-system:earth (Z) chile:region-metropolitana:santiago:providencia"

// Among many other features!
```

## Reference

The reference of classes and functions can be read in the [reference of scifir-units](https://scifir.github.io/scifir-units/annotated.html).

## Versions

The **current version** of scifir-units is the **beta-version-2.0**. The version 1.0 has never been released because the version 2.0 was better by a great extent. The version 2.0 includes a better inheritance system and a wide simplification of all the programming of the library and, then, a better compilation and a saving of RAM for each instantiation of each class. Because of that reason, the version 2.0 has been preferred over the version 1.0.

## Class list

- prefix.
- dimension.
- scalar_unit.
- vector_unit_2d, vector_unit_3d, vector_unit_nd.
- angle.
- scalar_field_3d\<T,U\>.
- coordinates_1d\<T\>, coordinates_2d\<T\>, coordinates_3d\<T\>, coordinates_nd\<T\>.
- coordinates_2dr\<T\>, coordinates_3dr\<T\>, coordinates_ndr\<T\>.
- point_1d\<T\>, point_2d\<T\>, point_3d\<T\>, point_nd\<T\>.
- aid, zid.
- percentage.
- complex_number\<T\>.
- lab_number\<T\>.
- size_2d\<T\>, size_3d\<T\>, size_nd\<T\>.
- pH, pOH.

prefix class can have **all SI prefixes**. dimension class has **all SI base dimensions**, **all SI special names**, among other more dimensions. coordinates classes and point classes use a space of metre, float or imaginary dimensions. aid class and zid class are a standard for astronomical ids and zone ids invented inside Scifir.

- All base and derived scalar unit classes inherit directly from scalar_unit class.
- All base and derived vectorial unit classes in 2D inherit directly from vector_unit_2d class, and end with the **suffix _2d**.
- All base and derived vectorial unit classes in 3D inherit directly from vector_unit_3d class, and end with the **suffix _3d**.
- All base and derived vectorial unit classes in ND inherit directly from vector_unit_nd class, and end with the **suffix _nd**.

Base unit classes (they inherit scalar_unit):

- length.
- time_duration.
- mass.
- charge.
- temperature.
- mole.
- light.
- data.

## Data conventions

It's mandatory to follow the **data conventions** of Scifir when using scifir-units, which is used not only for this library but also for every Scifir project. The data conventions of Scifir allow to handle data easy without multiple interpretations of the meaning of any value, because it doesn't has ambiguities.

The conventions are the following:

- **Units:** All units are stored identical to their initialization string, as text.
- **Genes:** Genes are stored by their gene name, following the **scifir nomenclature of genes**.
- **Molecules:** Molecules are stored by their IUPAC name, canonicalized.
- **Zones:** Zones are stored by their ZID initialization string.
- **Positions:** Positions are stored writing their zone, and, in parentheses, the geographic coordinates.
- **Languages:** Languages are stored by their language code of the ISO of languages.
- **Countries:** Countries are stored by their country code of the ISO of countries.
- **Currencies:** Currrencies are stored by their currency code of the ISO of currencies.
- **Phone numbers:** Phone numbers are stored with their phone code of the ISO of phone codes.

The conventions for storing informatic data are the following:

- **Ip addresses:** Store the ip, as is written.
- **Computers:** Store computers by their model name, canonicalized.

### Initialization strings

All the unit classes, and also the other related classes of this library, can be constructed with what is called here an **initialization string**. An initialization string is an string used to instantiate the class, and it's also used when converting the class to an string for any purpose (like printing it on the screen).

The initialization strings are like the following examples:

- **vector\<dimension\>**: "m2 / s", "J / s2 * kg"
- **angle**: "37°" or "37º"
- **scalar_unit**: "1 km"
- **vector_unit_2d**: "5 km 10θ" or "5 km 10°"
- **vector_unit_3d**: "3 km 10θ 20Φ" or "3 km 10° 20°"
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

In order to store units inside a file an initialization string should be used. To store inside a table of a database, use an initialization string too. For any purpose, when converting some of those classes to an string, the string initialization has to be used always.

## Consumption of memory

scifir-units is a very lightweight library, all classes require just some bytes to work. Then, it can be used in any electronics project, because the memory requirements can be meet.

The prefix class sizes 1 byte. The dimension class sizes 6 bytes.

The scalar_unit and vector unit classes, vector_unid_2d, vector_unid_3d and vector_unit_nd size more than a single float, which uses 4 bytes, but don't size a big amount and so, they can be used in great quantities for any purpose, cause they are very lightweight.

The angle class uses only 4 bytes, and works perfectly fine, very similar to a normal float. Then, you can use it freely every time you need to do calculations that need angles.

The coordinates classes have as member-variables scalar_unit classes, and then they size the bytes of the scalar_unit classes, for each scalar_unit class they have.

## Team

The **Scifir Collection** is developed by [Ismael Correa Castro](https://iarfen.github.io), a software developer of 32 years old. You can email him if you find bugs, you want to request new features, or have any other need, at [ismael.correa.castro@gmail.com](mailto:ismael.correa.castro@gmail.com). His ORCID is 0009-0007-3815-7053, if you want to reference this work inside any publication.

## Funding

The **Scifir Foundation** is looking for **funding**, in order to do some digital marketing and pay some other needs of the project. If you want to support this libraries, **science will thank you** for that, you can donate in this [sponsors page](https://github.com/sponsors/iarfen).

## Learn scifir-units

The documentation is **short to read**! Take profit then to read it entirely!

### First information

- [Code examples](https://github.com/scifir/scifir-units/tree/master/docs/readme/code_examples.md)
- [Portability](https://github.com/scifir/scifir-units/tree/master/docs/readme/portability.md)
- [Goal](https://github.com/scifir/scifir-units/tree/master/docs/readme/goal.md)
- [Installation](https://github.com/scifir/scifir-units/tree/master/docs/readme/installation_brief.md)

### Learn the library

- [Introduction](https://github.com/scifir/scifir-units/tree/master/docs/readme/introduction.md)
- [Scalar unit classes](https://github.com/scifir/scifir-units/tree/master/docs/readme/scalar_units.md)
- [Vector unit classes](https://github.com/scifir/scifir-units/tree/master/docs/readme/vector_units.md)
- [Meca numbers](https://github.com/scifir/scifir-units/tree/master/docs/readme/meca_numbers.md)
- [Coordinates and points](https://github.com/scifir/scifir-units/tree/master/docs/readme/coordinates_and_points.md)
- [Special units](https://github.com/scifir/scifir-units/tree/master/docs/readme/special_units.md)
- [Dimensions](https://github.com/scifir/scifir-units/tree/master/docs/readme/dimensions.md)

### Complementary information

- [Folder structure](https://github.com/scifir/scifir-units/tree/master/docs/readme/folder_structure.md)
- [Concepts](https://github.com/scifir/scifir-units/tree/master/docs/readme/concepts.md)
- [History of units of measurement](https://github.com/scifir/scifir-units/tree/master/docs/readme/history.md)
- [Use cases](https://github.com/scifir/scifir-units/tree/master/docs/readme/use_cases.md)
- [Nutrition](https://github.com/scifir/scifir-units/tree/master/docs/readme/nutrition.md)
- [Physics](https://github.com/scifir/scifir-units/tree/master/docs/readme/physics.md)
- [Internals](https://github.com/scifir/scifir-units/tree/master/docs/readme/internals.md)
- [Important future characteristics](https://github.com/scifir/scifir-units/tree/master/docs/readme/important_future_characteristics.md)
- [Thoughts about units](https://github.com/scifir/scifir-units/tree/master/docs/readme/thoughts_about_units.md)
- [Bibliography](https://github.com/scifir/scifir-units/tree/master/docs/readme/bibliography.md)
