2024-04-28  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* CHANGELOG.md => NEWS.md: CHANGELOG.md file renamed to NEWS.md, not
	yet updated with all important changes

2024-04-27  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* TODO - MagickScience.md => TODO - Scifir.md: 'TODO -
	MagickScience.md' file renamed to use the name Scifir instead

2024-04-27  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* meca_number/lab_number.hpp: lab_number now handes the error of
	display() with cerr, like scalar_unit classes

2024-04-27  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* meca_number/lab_number.hpp: Symbol of lab_number updated to U+00B1
	of Unicode

2024-04-23  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* : commit 6f948d19bd92d047ca550e9d309c5a2992c3336f Author: Ismael
	Correa Castro <ismael.correa.castro@gmail.com> Date:   Tue Apr 23
	16:46:32 2024 -0400

2024-04-23  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/cmake.yml: File cmake.yml was having a mistaked
	character

2024-04-23  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/cmake.yml: cmake.yml updated with the command of
	build only for scifir-units, tests are temporarily disabled from the
	workflow (they are still active in the local computer)

2024-04-23  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/cmake.yml: Update cmake.yml to only build
	scifir-units, tests have been temporarily disabled because the
	version of catch inside GitHub Action is lower than the current
	version being used

2024-04-23  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* CMakeLists.txt, TODO.md, coordinates/coordinates_1d.hpp,
	coordinates/coordinates_2d.hpp, coordinates/coordinates_2dr.hpp,
	coordinates/coordinates_3d.hpp, coordinates/coordinates_3dr.hpp,
	coordinates/coordinates_nd.hpp, coordinates/coordinates_ndr.hpp,
	special_units/size_2d.hpp, special_units/size_3d.hpp,
	special_units/size_nd.hpp, tests/benchmark_units.cpp,
	tests/coordinates/test_coordinates_1d.cpp,
	tests/coordinates/test_coordinates_2d.cpp,
	tests/coordinates/test_coordinates_2dr.cpp,
	tests/coordinates/test_coordinates_3d.cpp,
	tests/coordinates/test_coordinates_3dr.cpp,
	tests/coordinates/test_coordinates_nd.cpp,
	tests/coordinates/test_coordinates_ndr.cpp,
	tests/meca_number/test_angle.cpp,
	tests/special_units/test_percentage.cpp,
	tests/units/test_dimensions.cpp, tests/units/test_prefixes.cpp,
	tests/units/test_scalar_unit.cpp, tests/units/test_unit_basic.cpp,
	tests/units/test_vector_unit_2d.cpp,
	tests/units/test_vector_unit_3d.cpp,
	tests/units/test_vector_unit_nd.cpp, topology/point_1d.hpp,
	topology/point_2d.hpp, topology/point_3d.hpp, topology/point_nd.hpp: 
	scifir-units now uses C++20

2024-04-23  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* tests/special_units/test_percentage.cpp: test_percentage more
	ready

2024-04-23  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* tests/special_units/test_percentage.cpp: Path of percentage
	updated

2024-04-23  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* tests/special_units/test_percentage.cpp: test_percentage updated
	with new path of units.hpp

2024-04-23  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* tests/benchmark_units.cpp,
	tests/coordinates/test_coordinates_1d.cpp,
	tests/coordinates/test_coordinates_2d.cpp,
	tests/coordinates/test_coordinates_2dr.cpp,
	tests/coordinates/test_coordinates_3d.cpp,
	tests/coordinates/test_coordinates_3dr.cpp,
	tests/coordinates/test_coordinates_nd.cpp,
	tests/coordinates/test_coordinates_ndr.cpp, tests/main_units.cpp,
	tests/meca_number/test_angle.cpp, tests/test_sizeof.cpp,
	tests/units/test_dimensions.cpp, tests/units/test_prefixes.cpp,
	tests/units/test_scalar_unit.cpp, tests/units/test_unit_basic.cpp,
	tests/units/test_vector_unit_2d.cpp,
	tests/units/test_vector_unit_3d.cpp,
	tests/units/test_vector_unit_nd.cpp: Include paths of test files
	updated to don't use units.hpp anymore

2024-04-23  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* CMakeLists.txt, DISCARDED_FEATURES, HISTORY.md, TODO.md,
	coordinates/coordinates_1d.cpp, coordinates/coordinates_1d.hpp,
	coordinates/coordinates_2d.cpp, coordinates/coordinates_2dr.cpp,
	coordinates/coordinates_3d.cpp, coordinates/coordinates_3dr.cpp,
	coordinates/coordinates_nd.cpp, coordinates/coordinates_ndr.cpp,
	coordinates/coordinates_ndr.hpp, meca_number/angle.cpp,
	meca_number/complex_number.cpp, meca_number/complex_number.hpp,
	predefined_units/astronomy_units.cpp,
	predefined_units/chemistry_units.cpp,
	predefined_units/electronics_units.cpp,
	predefined_units/informatics_units.cpp,
	predefined_units/physics_units.cpp,
	predefined_units/radiometry_units.cpp,
	predefined_units/space_units.cpp, special_units/aid.cpp,
	special_units/aid.hpp, special_units/color.cpp,
	special_units/pH.cpp, special_units/pH.hpp, special_units/pOH.cpp,
	special_units/pOH.hpp, special_units/percentage.cpp,
	special_units/percentage.hpp, special_units/pixel.cpp,
	special_units/pixel.hpp, special_units/size_2d.cpp,
	special_units/size_2d.hpp, special_units/size_3d.cpp,
	special_units/size_3d.hpp, special_units/size_nd.cpp,
	special_units/size_nd.hpp, special_units/zid.cpp,
	special_units/zid.hpp, tests/benchmark_units.cpp,
	tests/coordinates/test_coordinates_1d.cpp,
	tests/coordinates/test_coordinates_2d.cpp,
	tests/coordinates/test_coordinates_2dr.cpp,
	tests/coordinates/test_coordinates_3d.cpp,
	tests/coordinates/test_coordinates_3dr.cpp,
	tests/coordinates/test_coordinates_nd.cpp,
	tests/coordinates/test_coordinates_ndr.cpp, tests/main_units.cpp,
	tests/meca_number/test_angle.cpp, tests/test_sizeof.cpp,
	tests/units/test_dimensions.cpp, tests/units/test_prefixes.cpp,
	tests/units/test_scalar_unit.cpp, tests/units/test_unit_basic.cpp,
	tests/units/test_vector_unit_2d.cpp,
	tests/units/test_vector_unit_3d.cpp,
	tests/units/test_vector_unit_nd.cpp, topology/direction.cpp,
	topology/point_1d.cpp, topology/point_1d.hpp,
	topology/point_1d_impl.hpp, topology/point_2d.cpp,
	topology/point_2d_impl.hpp, topology/point_3d.cpp,
	topology/point_3d_impl.hpp, topology/point_nd.cpp,
	topology/point_nd.hpp, topology/point_nd_impl.hpp, units.hpp,
	units/conversion.cpp, units/dimension.cpp, units/prefix.cpp,
	units/scalar_unit.cpp, units/scalar_unit.hpp,
	units/unit_abbreviation.cpp, units/unit_basic.cpp,
	units/vector_unit_2d.cpp, units/vector_unit_2d.hpp,
	units/vector_unit_3d.cpp, units/vector_unit_nd.cpp,
	units/vector_unit_nd.hpp, util/types.cpp: units.hpp file updated,
	and all hpp paths have been changed to be relative, because it's a
	better system. scalar_unit doesn't converts to the closest prefix
	automatically anymore, it does that with a boolean argument

2024-04-22  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* msci.pc, scifir-units.pc: msci.pc renamed and updated to
	scifir-units.pc

2024-04-22  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* tests/coordinates/test_coordinates_nd.cpp,
	tests/coordinates/test_coordinates_ndr.cpp: test of coordinates nd
	and ndr commented to avoid possible errors with ctest, they aren't
	yet finished

2024-04-22  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* CMakeLists.txt, TODO - MagickScience.md, TODO.md,
	coordinates/coordinates_1d.hpp, coordinates/coordinates_2d.hpp,
	coordinates/coordinates_2dr.hpp, coordinates/coordinates_3d.hpp,
	coordinates/coordinates_3dr.hpp, coordinates/coordinates_nd.hpp,
	coordinates/coordinates_ndr.hpp, fields/vector_field_3d.hpp,
	meca_number/angle.hpp, meca_number/complex_number.hpp,
	meca_number/lab_number.hpp, predefined_units/astronomy_units.hpp,
	predefined_units/chemistry_units.hpp,
	predefined_units/electronics_units.hpp,
	predefined_units/informatics_units.hpp,
	predefined_units/physics_units.hpp,
	predefined_units/radiometry_units.hpp,
	predefined_units/space_units.hpp, special_units/pH.hpp,
	special_units/pOH.hpp, special_units/percentage.hpp,
	special_units/pixel.hpp, special_units/size_2d.hpp,
	special_units/size_3d.hpp, special_units/size_nd.hpp,
	special_units/zid.hpp, topology/point_1d.hpp,
	topology/point_1d_impl.hpp, topology/point_2d.hpp,
	topology/point_2d_impl.hpp, topology/point_3d.hpp,
	topology/point_3d_impl.hpp, topology/point_nd.hpp,
	topology/point_nd_impl.hpp, units.hpp, units/conversion.hpp,
	units/dimension.hpp, units/scalar_unit.cpp, units/scalar_unit.hpp,
	units/unit_abbreviation.hpp, units/base_units.hpp,
	units/vector_unit_2d.hpp, units/vector_unit_3d.hpp,
	units/vector_unit_nd.hpp, util/matrix.hpp: headers now use relative
	paths instead of absolute path in order to simplify the use of the
	library. The name now uses a hyphen instead of an underscore.

2024-04-17  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* README.md: Description of special units added to the README.md
	file

2024-04-11  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* tests/test_sizeof.cpp: test_sizeof.cpp updated with new filenames

2024-04-11  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* units.hpp: units.hpp updated with new filenames

2024-04-11  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* CMakeLists.txt, units/dimension.cpp, units/dimension.hpp,
	units/scalar_unit.hpp, units/unit_basic.cpp: Some bugs fixed

2024-04-11  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* : commit c0a32b3845042532657cb9073371eef96d509352 Author: Ismael
	Correa Castro <ismael.correa.castro@gmail.com> Date:   Thu Apr 11
	17:38:33 2024 -0400

2024-04-11  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/cmake.yml: Update cmake.yml to use new
	configuration of CMakeLists.txt

2024-04-07  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* topology/constants.hpp: Avogadro constant updated

2024-04-07  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* DISCARDED_FEATURES, TODO - MagickScience.md, TODO.md: TODO files
	updated, and also DISCARDED_FEATURES

2024-04-07  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* special_units/aid.hpp, topology/direction.hpp,
	units/dimension.hpp, units/prefix.hpp: char in enum changed by
	int8_t

2024-04-07  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* predefined_units/dynamics_units.cpp,
	predefined_units/dynamics_units.hpp,
	predefined_units/electricity_units.cpp,
	predefined_units/electricity_units.hpp,
	predefined_units/fluid_dynamics_units.cpp,
	predefined_units/fluid_dynamics_units.hpp,
	predefined_units/magnetism_units.cpp,
	predefined_units/magnetism_units.hpp,
	predefined_units/optics_units.cpp,
	predefined_units/optics_units.hpp,
	predefined_units/substance_units.cpp,
	predefined_units/substance_units.hpp,
	predefined_units/thermodynamics_units.cpp,
	predefined_units/thermodynamics_units.hpp,
	predefined_units/waves_units.cpp, predefined_units/waves_units.hpp: 
	old files of predefined units deleted

2024-04-07  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* coordinates/coordinates_1d.hpp, coordinates/coordinates_2d.hpp,
	coordinates/coordinates_3d.hpp, coordinates/coordinates_nd.hpp,
	coordinates/coordinates_ndr.hpp,
	predefined_units/chemistry_units.cpp,
	predefined_units/chemistry_units.hpp,
	predefined_units/dynamics_units.cpp,
	predefined_units/dynamics_units.hpp,
	predefined_units/electricity_units.cpp,
	predefined_units/electricity_units.hpp,
	predefined_units/fluid_dynamics_units.cpp,
	predefined_units/fluid_dynamics_units.hpp,
	predefined_units/kinematics_units.cpp,
	predefined_units/kinematics_units.hpp,
	predefined_units/magnetism_units.cpp,
	predefined_units/magnetism_units.hpp,
	predefined_units/optics_units.cpp,
	predefined_units/optics_units.hpp,
	predefined_units/physics_units.cpp,
	predefined_units/physics_units.hpp,
	predefined_units/substance_units.cpp,
	predefined_units/substance_units.hpp,
	predefined_units/thermodynamics_units.cpp,
	predefined_units/thermodynamics_units.hpp,
	predefined_units/waves_units.cpp, predefined_units/waves_units.hpp,
	special_units/pH.hpp, special_units/pOH.hpp, topology/point_1d.hpp,
	topology/point_2d.hpp, topology/point_3d.hpp,
	topology/point_nd.hpp, units.hpp, units/unit_abbreviation.hpp: 
	predefined units reordered, substance units are now inside
	chemistry_units and all physical units are now inside physics_units

2024-04-07  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* README.md: README.md file updated with the new classification of
	predefined units

2024-04-07  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .gitignore: More files to ignore added to gitignore related to
	build and IDEs

2024-04-07  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* predefined_units/biochemistry_units.cpp,
	predefined_units/biochemistry_units.hpp,
	predefined_units/{atoms_units.cpp => chemistry_units.cpp},
	predefined_units/{atoms_units.hpp => chemistry_units.hpp},
	predefined_units/{hardware_units.cpp => electronics_units.cpp},
	predefined_units/{hardware_units.hpp => electronics_units.hpp},
	units.hpp, units/unit_abbreviation.hpp: Predefined units files
	reordered to be better explained for every user

2024-04-07  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* TODO - MagickScience.md, TODO.md: Both TODO files updated to
	explain better some options of features remaining

2024-04-06  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* special_units/{ph.cpp => pH.cpp}, special_units/{ph.hpp =>
	pH.hpp}, special_units/{poh.cpp => pOH.cpp}, special_units/{poh.hpp
	=> pOH.hpp}: pH and pOH filenames updated

2024-04-06  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* units.hpp: units.hpp file updated

2024-04-06  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* predefined_units/acoustics_units.cpp,
	predefined_units/acoustics_units.hpp,
	predefined_units/electricity_units.hpp,
	predefined_units/matter_units.hpp: Files of predefined units
	updated, the code is now more ordered

2024-04-06  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* README.md: Class list added to README.md, explaining all classes
	available

2024-03-21  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* special_units/percentage.hpp,
	tests/special_units/test_percentage.cpp: percentage class updated,
	test of percentage class added too

2024-03-21  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* CMakeLists.txt: CMakeLists.txt updated to don't include yet MinGW
	builds, it works for Linux, WSL and custom builds :D

2024-03-11  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .gitignore, CMakeLists.txt, TODO.md: CMakeLists.txt updated with
	WSL configuration and the possibility to configure all locations of
	libraries to be used for building. TODO.md and gitignore files
	updated

2023-11-14  iarfen <ismael.correa.castro@gmail.com>

	* CMakeLists.txt, TODO - MagickScience.md, TODO.md,
	tests/coordinates/test_coordinates_1d.cpp,
	tests/coordinates/test_coordinates_2d.cpp,
	tests/coordinates/test_coordinates_2dr.cpp,
	tests/coordinates/test_coordinates_3d.cpp,
	tests/coordinates/test_coordinates_3dr.cpp,
	tests/coordinates/test_coordinates_nd.cpp,
	tests/coordinates/test_coordinates_ndr.cpp, tests/{ =>
	special_units}/test_percentage.cpp, tests/{ =>
	units}/test_dimensions.cpp, tests/{ => units}/test_prefixes.cpp,
	tests/{ => units}/test_scalar_unit.cpp, tests/{ =>
	units}/test_unit_basic.cpp, tests/{ =>
	units}/test_vector_unit_2d.cpp, tests/{ =>
	units}/test_vector_unit_3d.cpp, tests/{ =>
	units}/test_vector_unit_nd.cpp, units/vector_unit_2d.hpp,
	units/vector_unit_3d.hpp, units/vector_unit_nd.hpp: tests improved.
	gcov tool added to cmake

2023-09-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* README.md: README.md urls updated

2023-07-15  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_vector_unit_2d.cpp, tests/test_vector_unit_3d.cpp,
	tests/test_vector_unit_nd.cpp: tests updated to use catch2

2023-07-14  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_scalar_unit.cpp, tests/test_vector_unit_2d.cpp,
	tests/test_vector_unit_3d.cpp, tests/test_vector_unit_nd.cpp,
	units/scalar_unit.cpp, units/scalar_unit.hpp,
	units/vector_unit_2d.cpp, units/vector_unit_2d.hpp,
	units/vector_unit_3d.cpp, units/vector_unit_3d.hpp,
	units/vector_unit_nd.cpp, units/vector_unit_nd.hpp: 
	vectorial_display(), vectorial_derived_display() and
	vectorial_custom_display() functions created. tests of these
	functions added. bug with custom_display() of scalar_unit fixed

2023-07-14  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_vector_unit_2d.cpp, tests/test_vector_unit_3d.cpp,
	tests/test_vector_unit_nd.cpp, units/vector_unit_2d.cpp,
	units/vector_unit_3d.cpp, units/vector_unit_nd.cpp: to_string() of
	vector_unit classes now displays as scalar_unit classes, truncating
	more than 2 decimals. They truncate angles to 2 decimals too. tests
	updated to reflect changes

2023-07-14  Ismael Correa <ismael.correa.castro@gmail.com>

	* TODO.md: TODO.md updated with actual tasks

2023-07-14  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_vector_unit_2d.cpp, tests/test_vector_unit_3d.cpp,
	tests/test_vector_unit_nd.cpp, units/vector_unit_2d.hpp,
	units/vector_unit_3d.hpp, units/vector_unit_nd.hpp: static
	constructors with coordinates for vector_unit classes added

2023-07-14  Ismael Correa <ismael.correa.castro@gmail.com>

	* coordinates/coordinates_2d.hpp, coordinates/coordinates_3d.hpp: 
	coordinates classes bug fixed, the angle now is given in grades
	always, not in radians

2023-07-14  Ismael Correa <ismael.correa.castro@gmail.com>

	* DISCARDED_FEATURES: discarded feature of using both angle and
	float combinations inside constructors added in order to avoid that
	to happen

2023-07-14  Ismael Correa <ismael.correa.castro@gmail.com>

	* meca_number/angle.cpp: characters ° and º both supported for
	angle class

2023-07-14  Ismael Correa <ismael.correa.castro@gmail.com>

	* README.md: character º replaced by ° in the README.md

2023-07-14  Ismael Correa <ismael.correa.castro@gmail.com>

	* meca_number/angle.cpp, tests/test_vector_unit_2d.cpp,
	tests/test_vector_unit_3d.cpp, tests/test_vector_unit_nd.cpp,
	units/scalar_unit.cpp, units/vector_unit_2d.cpp,
	units/vector_unit_2d.hpp, units/vector_unit_3d.cpp,
	units/vector_unit_3d.hpp, units/vector_unit_nd.cpp,
	units/vector_unit_nd.hpp: bug corrected with angle. some constructor
	of vector_unit_3d class have been removed in order to have only the
	most important ones. vector_unit_nd bug fixed with some
	constructors. constructors with scalar_unit&& have been deleted in
	vector_unit class because they aren't really needed. tests of all
	constructors of all vector_unit classes created

2023-07-13  Ismael Correa <ismael.correa.castro@gmail.com>

	* README.md: README.md updated explaining that Ismael Correa has
	created the memo dimension

2023-07-13  Ismael Correa <ismael.correa.castro@gmail.com>

	* README.md: README.md updated, all basic dimensions are now
	explained

2023-07-13  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_dimensions.cpp, units/dimension.cpp,
	units/dimension.hpp: memo dimension, invented by Ismael Correa to
	handle the size of the memory of animal brains, including human
	brains, added, intended to be used in neuroscience applications and
	related fields of research

2023-07-13  Ismael Correa <ismael.correa.castro@gmail.com>

	* meca_number/angle.cpp, tests/test_scalar_unit.cpp,
	tests/test_vector_unit_2d.cpp, units/vector_unit_2d.cpp,
	units/vector_unit_2d.hpp, units/vector_unit_3d.cpp,
	units/vector_unit_nd.cpp: tests of constructors of scalar_unit and
	vector_unit_2d classes implemented. bug with constructors on
	vector_unit classes and angle class fixed

2023-07-13  Ismael Correa <ismael.correa.castro@gmail.com>

	* README.md: README.md updated to current version

2023-07-12  Ismael Correa <ismael.correa.castro@gmail.com>

	* CMakeLists.txt, meca_number/angle.cpp, tests/test_dimensions.hpp,
	tests/{test_units.cpp => test_scalar_unit.cpp},
	tests/test_vector_unit_2d.cpp, tests/test_vector_unit_3d.cpp,
	tests/test_vector_unit_nd.cpp, tests/test_vector_units.cpp,
	tests/test_vector_units.hpp, units/vector_unit_2d.cpp,
	units/vector_unit_nd.cpp: tests of scalar_unit and vector_unit
	classes renamed and/or created. Some bugs related to the use of
	UTF16 for some special characters have been corrected

2023-07-12  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_units.cpp, units/scalar_unit.cpp,
	units/scalar_unit.hpp: is_scalar_unit() function created to test if
	an string initializes an scalar_unit. test of is_scalar_unit created

2023-07-12  Ismael Correa <ismael.correa.castro@gmail.com>

	* special_units/size_2d.cpp, special_units/size_2d.hpp,
	special_units/size_3d.cpp, special_units/size_3d.hpp,
	special_units/size_nd.cpp, special_units/size_nd.hpp: size_2d,
	size_3d and size_nd classes now have a specialization with float.
	size_nd now trims inside the string initialization constructor

2023-07-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* : commit 4bb43a54709087734efc5403907840d74d721f18 Author: Ismael
	Correa <ismael.correa.castro@gmail.com> Date:   Tue Jul 11 19:54:57
	2023 -0400

2023-07-11  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/cmake.yml: Update ctest to output any failure

2023-07-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* special_units/size_nd.hpp: size_nd operators now check to have the
	same number of dimensions

2023-07-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* predefined_units/space_units.cpp,
	predefined_units/space_units.hpp: volume_4d class created to handle
	theoretical calculations of 4 dimensions of space

2023-07-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* special_units/size_nd.hpp, units.hpp: size_nd class created to
	allow sizes of any dimension

2023-07-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* : commit f38e1838db96ed90b63f4d42744a33a1c9de3a51 Author: Ismael
	Correa <ismael.correa.castro@gmail.com> Date:   Tue Jul 11 15:48:13
	2023 -0400

2023-07-11  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/cmake.yml: Repairing GitHub Actions

2023-07-11  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/cmake.yml: Repairing GitHub Actions

2023-07-11  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/cmake.yml: Repairing tests of GitHub Actions

2023-07-11  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/cmake.yml: Update cmake.yml to repair error with
	ctest

2023-07-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* : commit d676884339820d812a71e69b00eeb5d56b6e5265 Author: Ismael
	Correa <ismael.correa.castro@gmail.com> Date:   Tue Jul 11 13:35:01
	2023 -0400

2023-07-11  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/cmake.yml: Update cmake.yml to check
	test_unit_basic error

2023-07-10  Ismael Correa <ismael.correa.castro@gmail.com>

	* README.md: ORCID of Ismael Correa, 0009-0007-3815-7053, added to
	the README

2023-07-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* coordinates/coordinates_1d.cpp, coordinates/coordinates_1d.hpp,
	coordinates/coordinates_2d.cpp, coordinates/coordinates_2d.hpp,
	coordinates/coordinates_2dr.cpp, coordinates/coordinates_2dr.hpp,
	coordinates/coordinates_3d.cpp, coordinates/coordinates_3d.hpp,
	coordinates/coordinates_3dr.cpp, coordinates/coordinates_3dr.hpp,
	coordinates/coordinates_nd.cpp, coordinates/coordinates_nd.hpp,
	coordinates/coordinates_ndr.cpp, coordinates/coordinates_ndr.hpp,
	fields/scalar_field.hpp, fields/vector_field_3d.hpp,
	meca_number/angle.cpp, meca_number/angle.hpp,
	meca_number/complex_number.cpp, meca_number/complex_number.hpp,
	meca_number/lab_number.hpp, predefined_units/acoustics_units.hpp,
	predefined_units/astronomy_units.cpp,
	predefined_units/astronomy_units.hpp,
	predefined_units/atoms_units.cpp, predefined_units/atoms_units.hpp,
	predefined_units/biochemistry_units.cpp,
	predefined_units/biochemistry_units.hpp,
	predefined_units/dynamics_units.cpp,
	predefined_units/dynamics_units.hpp,
	predefined_units/electricity_units.cpp,
	predefined_units/electricity_units.hpp,
	predefined_units/fluid_dynamics_units.cpp,
	predefined_units/fluid_dynamics_units.hpp,
	predefined_units/hardware_units.cpp,
	predefined_units/hardware_units.hpp,
	predefined_units/informatics_units.cpp,
	predefined_units/informatics_units.hpp,
	predefined_units/kinematics_units.cpp,
	predefined_units/kinematics_units.hpp,
	predefined_units/magnetism_units.cpp,
	predefined_units/magnetism_units.hpp,
	predefined_units/matter_units.hpp,
	predefined_units/optics_units.cpp,
	predefined_units/optics_units.hpp,
	predefined_units/radiometry_units.cpp,
	predefined_units/radiometry_units.hpp,
	predefined_units/space_units.cpp, predefined_units/space_units.hpp,
	predefined_units/substance_units.cpp,
	predefined_units/substance_units.hpp,
	predefined_units/thermodynamics_units.cpp,
	predefined_units/thermodynamics_units.hpp,
	predefined_units/waves_units.cpp, predefined_units/waves_units.hpp,
	special_units/aid.cpp, special_units/aid.hpp,
	special_units/color.cpp, special_units/color.hpp,
	special_units/percentage.cpp, special_units/percentage.hpp,
	special_units/ph.cpp, special_units/ph.hpp,
	special_units/pixel.cpp, special_units/pixel.hpp,
	special_units/poh.cpp, special_units/poh.hpp,
	special_units/size_2d.hpp, special_units/size_3d.hpp,
	special_units/zid.cpp, special_units/zid.hpp, tests/main_units.cpp,
	tests/test_dimensions.hpp, tests/test_sizeof.cpp,
	tests/test_unit_basic.cpp, tests/test_units.cpp,
	tests/test_vector_units.hpp, topology/constants.hpp,
	topology/direction.cpp, topology/direction.hpp,
	topology/point_1d.cpp, topology/point_1d.hpp,
	topology/point_1d_impl.hpp, topology/point_2d.cpp,
	topology/point_2d.hpp, topology/point_2d_impl.hpp,
	topology/point_3d.cpp, topology/point_3d.hpp,
	topology/point_3d_impl.hpp, topology/point_nd.cpp,
	topology/point_nd.hpp, topology/point_nd_impl.hpp, units.hpp,
	units/conversion.cpp, units/conversion.hpp, units/dimension.cpp,
	units/dimension.hpp, units/prefix.cpp, units/prefix.hpp,
	units/scalar_unit.cpp, units/scalar_unit.hpp,
	units/unit_abbreviation.cpp, units/unit_abbreviation.hpp,
	units/unit_basic.cpp, units/base_units.hpp,
	units/vector_unit_2d.cpp, units/vector_unit_2d.hpp,
	units/vector_unit_3d.cpp, units/vector_unit_3d.hpp,
	units/vector_unit_nd.cpp, units/vector_unit_nd.hpp,
	util/is_number.hpp, util/matrix.hpp, util/types.cpp, util/types.hpp: 
	namespace msci changed for scifir

2023-07-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* CMakeLists.txt: CMakeLists.txt now installs inside include/scifir
	instead of include/msci

2023-07-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_unit_basic.cpp: test updated

2023-07-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_units.cpp: time classname updated to time_duration

2023-07-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* CMakeLists.txt, tests/test_sizeof.cpp, tests/test_unit_basic.cpp: 
	test of sizeof updated. test of basic units partially implemented

2023-07-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/unit_abbreviation.cpp, units/unit_abbreviation.hpp,
	units/unit_basic.cpp, units/base_units.hpp: time class name changed
	to time_duration

2023-07-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/unit_basic.cpp, units/base_units.hpp: time class now
	displays in weeks and in months

2023-07-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/unit_basic.cpp, units/base_units.hpp: time class now can
	display in years, days, hours, minutes and seconds

2023-07-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/unit_basic.cpp, units/base_units.hpp: mass now can construct
	with ppm, ppb, ppt and ppq

2023-07-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/unit_basic.cpp, units/base_units.hpp: mole class now can
	construct with ppm, ppb, ppt and ppq

2023-07-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* special_units/percentage.cpp, special_units/percentage.hpp,
	tests/test_percentage.cpp: percentage class updated. A good amount
	of tests of the percentage class implemented

2023-07-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* predefined_units/substance_units.cpp,
	predefined_units/substance_units.hpp, special_units/percentage.cpp,
	special_units/percentage.hpp, special_units/ph.cpp,
	special_units/ph.hpp, special_units/poh.cpp, special_units/poh.hpp,
	units/dimension.cpp, units/dimension.hpp,
	units/unit_abbreviation.cpp, units/unit_abbreviation.hpp: ppm and
	ppb changed to work with percentages instead of with concentration.
	concentration class removed, it's been deprecated in favor of his
	equivalent use with the percentage class. ppm and ppb deleted as
	dimension, now they work with the percentage class as a special unit

2023-07-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* CMakeLists.txt, special_units/percentage.cpp,
	special_units/percentage.hpp, tests/test_percentage.cpp, units.hpp: 
	percentage class now can be constructed with ppm, ppb, ppt and ppq.
	test of percentage class created. units.hpp now includes all special
	units

2023-07-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_dimensions.cpp, units/dimension.cpp,
	units/dimension.hpp: custom dimensions fully implemented.
	test_dimensions now tests custom dimensions

2023-07-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/dimension.cpp, units/dimension.hpp, units/scalar_unit.cpp: 
	prefix_math() function implemented outside dimension to handle all
	cases when that operation is needed

2023-07-04  Ismael Correa <ismael.correa.castro@gmail.com>

	* : commit afe0cdd6befe5461bd1b85cc9c812cd9dbb3b9e6 Author: Ismael
	Correa <ismael.correa.castro@gmail.com> Date:   Tue Jul 4 22:51:42
	2023 -0400

2023-07-04  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/cmake.yml: Update cmake.yml with tests label

2023-07-04  Ismael Correa <ismael.correa.castro@gmail.com>

	* CMakeLists.txt: CMakeLists.txt tests and benchmarks labels updated

2023-07-04  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/dimension.hpp: format improved

2023-07-04  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_dimensions.cpp, units/dimension.cpp,
	units/dimension.hpp: constructor of custom dimensions moved to the
	other. A bug with custom dimensions has been fixed

2023-07-03  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/main_units.cpp, tests/test_dimensions.cpp,
	tests/test_sizeof.cpp, units/dimension.cpp, units/dimension.hpp,
	units/scalar_unit.cpp: enum of sign of dimensions changed to
	uppercase in order to follow a good format

2023-07-03  Ismael Correa <ismael.correa.castro@gmail.com>

	* coordinates/coordinates_3d.hpp, special_units/aid.cpp,
	special_units/aid.hpp, topology/direction.cpp,
	topology/direction.hpp, units/dimension.cpp, units/dimension.hpp: 
	default values for all enum types added. enum of coordinates deleted
	because it's not being used anymore

2023-07-03  Ismael Correa <ismael.correa.castro@gmail.com>

	* coordinates/coordinates_3d.hpp, coordinates/coordinates_3dr.hpp,
	coordinates/coordinates_nd.hpp, coordinates/coordinates_ndr.hpp,
	predefined_units/space_units.cpp, topology/point_3d.hpp,
	topology/point_nd.hpp, units/scalar_unit.cpp,
	units/scalar_unit.hpp, units/vector_unit_2d.cpp,
	units/vector_unit_3d.cpp, units/vector_unit_nd.cpp: function
	set_same_prefix() changed by change_dimensions() in order to include
	abbreviations and any other factor that affects the value

2023-07-03  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/scalar_unit.cpp, units/scalar_unit.hpp,
	units/vector_unit_2d.cpp, units/vector_unit_3d.cpp,
	units/vector_unit_nd.cpp: 
	equal_dimensions(scalar_unit&,scalar_unit&) changed by
	has_dimensions(scalar_unit&) following the same API has other
	functions in order to improve ease of use

2023-07-03  Ismael Correa <ismael.correa.castro@gmail.com>

	* special_units/size_2d.hpp, special_units/size_3d.hpp: get_area()
	and get_volume() of size classes now works for any dimension of
	size, not only for length

2023-07-03  Ismael Correa <ismael.correa.castro@gmail.com>

	* README.md: documentation updated

2023-07-03  Ismael Correa <ismael.correa.castro@gmail.com>

	* README.md: README.md updated

2023-07-03  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/dimension.cpp, units/dimension.hpp: some functions have been
	removed because they've become redundant due to the refactoring

2023-07-03  Ismael Correa <ismael.correa.castro@gmail.com>

	* : commit cf8d2a4a4dd562e95bdf29e2c88a0c80ac62d785 Author: Ismael
	Correa <ismael.correa.castro@gmail.com> Date:   Mon Jul 3 14:49:00
	2023 -0400

2023-07-02  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/codeql.yml: CodeQL now executes each Sunday, not
	on each push request, in order to save time of GitHub Actions per
	month

2023-07-02  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_dimensions.cpp, units/dimension.cpp: 
	normalize_dimensions() now calculates prefixes and conversion
	factors of abbreviations prior to converting the dimensions to the
	derived ones. Test of dimensions extended

2023-07-02  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_dimensions.cpp, units/dimension.cpp,
	units/dimension.hpp, units/scalar_unit.cpp: equal_dimensions now
	works for derived dimensions only in order to avoid misuse of it.
	normalize_dimensions bug solved

2023-07-02  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/main_units.cpp, tests/test_dimensions.cpp,
	tests/test_sizeof.cpp, units/dimension.cpp, units/dimension.hpp: 
	dimension class refactored. pseudo-factory function
	create_dimension() changed for a constructor inside dimension with
	the same functionality

2023-07-02  Ismael Correa <ismael.correa.castro@gmail.com>

	* CMakeLists.txt, tests/main_units.cpp, tests/test_dimensions.cpp,
	tests/test_prefixes.cpp, units/dimension.cpp, units/dimension.hpp,
	units/prefix.cpp, units/prefix.hpp: prefix class refactored.
	dimension class partially refactored. Bugs solved to instantiate
	some prefixes. Test of prefixes and of dimensions implemented

2023-07-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_dimensions.cpp, units/dimension.cpp: Bug solved with
	basic dimensions when creating cd and money dimensions

2023-07-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* CMakeLists.txt, tests/test_dimensions.cpp, units/dimension.cpp: 
	bug when creating derived dimensions fixed. Test of dimension class
	partially implemented

2023-07-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* CMakeLists.txt: C++17 added

2023-07-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* coordinates/coordinates_1d.hpp, coordinates/coordinates_2d.hpp,
	coordinates/coordinates_2dr.hpp, coordinates/coordinates_3d.hpp,
	coordinates/coordinates_3dr.hpp, coordinates/coordinates_nd.hpp,
	coordinates/coordinates_ndr.hpp, tests/test_sizeof.cpp,
	topology/point_1d.hpp, topology/point_2d.hpp,
	topology/point_3d.hpp, topology/point_nd.hpp: default template
	argument set to length for all coordinates and point classes

2023-07-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* meca_number/angle.hpp, meca_number/complex_number.cpp,
	meca_number/complex_number.hpp, special_units/percentage.hpp,
	special_units/ph.hpp, special_units/pixel.hpp,
	special_units/poh.hpp, units/scalar_unit.hpp,
	units/vector_unit_2d.hpp, units/vector_unit_3d.hpp,
	units/vector_unit_nd.hpp, util/is_number.hpp: std namespace of
	is_number and is_integer_number changed to msci

2023-07-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/dimension.cpp, units/dimension.hpp: common_dimension() tests
	now on all derived dimensions. equal_dimensions() now compares with
	derived dimensions

2023-07-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_sizeof.cpp, tests/test_units.cpp, units/dimension.cpp,
	units/dimension.hpp, units/prefix.cpp, units/prefix.hpp,
	units/scalar_unit.cpp, units/scalar_unit.hpp, units/unit_basic.cpp,
	units/base_units.hpp, units/vector_unit_2d.cpp,
	units/vector_unit_3d.cpp, units/vector_unit_nd.cpp: 
	display_derived() added to scalar_unit. Bugs related to
	multiplication and division of dimensions solved. sqrt() and
	sqrt_nth() now work on all cases

2023-06-30  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_units.cpp, units/dimension.cpp, units/dimension.hpp,
	units/scalar_unit.cpp, units/scalar_unit.hpp: sqrt() and sqrt_nth()
	now run on cases of different prefixes, different abbreviations, and
	any other case. They work with the conversion of byte if that
	dimension appears too. Some bugs solved

2023-06-28  Ismael Correa <ismael.correa.castro@gmail.com>

	* TODO.md: TODO.md updated with new tasks

2023-06-28  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/dimension.cpp, units/dimension.hpp, units/scalar_unit.cpp: 
	bug with operations with dimensions solved

2023-06-28  Ismael Correa <ismael.correa.castro@gmail.com>

	* topology/constants.hpp, units/dimension.cpp, units/dimension.hpp,
	units/prefix.cpp, units/prefix.hpp, units/scalar_unit.cpp,
	units/scalar_unit.hpp, units/unit_basic.cpp, units/base_units.hpp: 
	byte dimension now calculates in the order of 1024, as it should.
	full support for conversion factors of dimensions implemented

2023-06-28  Ismael Correa <ismael.correa.castro@gmail.com>

	* topology/constants.hpp, units/dimension.cpp, units/dimension.hpp,
	units/scalar_unit.cpp, units/scalar_unit.hpp, units/unit_basic.cpp: 
	empty value added as dimension type to handle default constructor
	cases. scalar_unit class now has derived dimensions. derived
	dimensions fully implemented in dimension class. time class not
	displays time as expected. avogadro_constant name changed according
	to code formatting standards

2023-06-27  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/unit_basic.cpp, units/base_units.hpp: constructor with
	multiple time dimensions added to time class

2023-06-27  Ismael Correa <ismael.correa.castro@gmail.com>

	* README.md: Message updated

2023-06-27  Ismael Correa <ismael.correa.castro@gmail.com>

	* CMakeLists.txt, README.md: README.md updated with the new name.
	CMakeLists.txt updated with cpack

2023-06-26  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/scalar_unit.hpp, units/unit_basic.cpp,
	units/vector_unit_2d.hpp, units/vector_unit_3d.hpp,
	units/vector_unit_nd.hpp: inheritance of operators -,+= and -= for
	inheriting classes of scalar_unit, vector_unit_2d, vector_unit_3d
	and vector_unit_nd added

2023-06-26  Ismael Correa <ismael.correa.castro@gmail.com>

	* coordinates/coordinates_2dr.hpp, coordinates/coordinates_3dr.hpp,
	tests/test_sizeof.cpp: rotational coordinates now are initiated with
	; to separate coordinate values from rotational values

2023-06-26  Ismael Correa <ismael.correa.castro@gmail.com>

	* special_units/pixel.cpp, special_units/pixel.hpp: pixel class
	created as another special unit to use in graphical computing

2023-06-26  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_units.cpp: test of all decimals added

2023-06-26  Ismael Correa <ismael.correa.castro@gmail.com>

	* meca_number/angle.cpp, special_units/percentage.cpp,
	special_units/percentage.hpp: percentage class created. angle class
	now initializes floating-point values

2023-06-26  Ismael Correa <ismael.correa.castro@gmail.com>

	* predefined_units/space_units.cpp,
	predefined_units/space_units.hpp, special_units/size_2d.hpp,
	special_units/size_3d.hpp, tests/test_sizeof.cpp: size_2d and
	size_3d special units created. area and volume classes now can be
	constructed from a size_2d and a size_3d, respectively

2023-06-26  Ismael Correa <ismael.correa.castro@gmail.com>

	* util/types.cpp: display of all decimals for all numeric displays
	added

2023-06-26  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/scalar_unit.cpp: E case of scientific notation added

2023-06-26  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_units.cpp, units/scalar_unit.cpp: scalar_unit now
	supports scientific notation, tests of scientific notation added

2023-06-26  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/dimension.cpp: dimension.cpp file extra line removed

2023-06-26  Ismael Correa <ismael.correa.castro@gmail.com>

	* .gitignore: .gitignore updated

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_sizeof.cpp: test_sizeof updated for new headers

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* coordinates.hpp, meca_numbers.hpp, units.hpp: header files
	modified to use only units.hpp

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* magick.cpp: magick.cpp file removed from the repository. It's
	being used to test only in local filesystems, it's not part of the
	library files

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* units.kdev4: units.kdev4 file removed from the repository, not
	from local filesystems

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* .gitignore: file units.kdev4 added to .gitignore

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* test_units_include-b12d07c.cmake: two generated files removed from
	the root directory

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* EXTRA: EXTRA file removed

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* .gitignore: .gitignore file added to the repository to ignore some
	generated files and generated folders. KDevelop files and folders
	included

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* : commit b0da8225e419eaf1b5ba3d18442b41c0252cf2c0 Author: Ismael
	Correa <ismael.correa.castro@gmail.com> Date:   Sun Jun 25 18:24:39
	2023 -0400

2023-06-25  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/cmake.yml: cmake.yml now tests only tests with
	label test, no benchmark tests

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* .github/workflows/cmake.yml: cmake.yml changed from github

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* .github/workflows/cmake.yml, CMakeLists.txt,
	tests/benchmark_units.cpp, tests/test_sizeof.cpp: Increased order
	inside the root folder, placing all executables, tests and libraries
	to the bin directory. benchmark of scalar_units created. Tests
	configured to distinguish between benchmark and test.

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* : test_sizeof and test_units executables removed from root folder
	to have more order. They have been moved to the bin folder

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* CHANGELOG.md: CHANGELOG.md file updated with new changes

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* : commit 9502e35c0136886eab8f105f587893fd9259f1c6 Author: Ismael
	Correa <ismael.correa.castro@gmail.com> Date:   Sun Jun 25 16:15:46
	2023 -0400

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* DISCARDED_FEATURES: DISCARDED_FEATURES updated with another
	feature that has been discarded

2023-06-25  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/codeql.yml: CodeQL updated with the dependency
	catch2

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* : commit 94066477977c653025e4f73df34bb686d63b286b Author: Ismael
	Correa <ismael.correa.castro@gmail.com> Date:   Sun Jun 25 14:08:28
	2023 -0400

2023-06-25  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/cmake.yml: catch2 added to the dependencies of
	the workflow

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* units.hpp: units.hpp now includes scalar_unit classes

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* CMakeLists.txt, test_units_include-b12d07c.cmake,
	test_units_tests-b12d07c.cmake, tests/{main.cpp => test_units.cpp},
	tests/test_units.hpp, units/dimension.cpp: Unitary test of
	scalar_unit class created. ctest configured. dimensions now display
	the empty case

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/scalar_unit.cpp, units/scalar_unit.hpp: custom_display added
	to scalar_unit. Bug displaying in some prefix cases solved

2023-06-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/dimension.cpp, units/dimension.hpp: bug comparing equal
	dimensions corrected

2023-06-24  Ismael Correa <ismael.correa.castro@gmail.com>

	* coordinates/coordinates_1d.hpp: coordinates_1d bug with length
	fixed

2023-06-24  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/scalar_unit.hpp: left operators for scalar_units with
	numeric types added again

2023-06-24  Ismael Correa <ismael.correa.castro@gmail.com>

	* README.md: README updated with the initialization strings and the
	documentation of coordinates_1d and coordinates_2d

2023-06-24  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/prefix.cpp, units/prefix.hpp, units/scalar_unit.cpp: auto
	display with the closest prefix added for all unit classes

2023-06-23  Ismael Correa <ismael.correa.castro@gmail.com>

	* CMakeLists.txt: CMakeLists.txt dependency of boost_locale deleted

2023-06-23  Ismael Correa <ismael.correa.castro@gmail.com>

	* meca_number/lab_number.hpp: lab_number<> bug improved

2023-06-23  Ismael Correa <ismael.correa.castro@gmail.com>

	* meca_number/angle.cpp, meca_number/angle.hpp,
	meca_number/lab_number.hpp, special_units/ph.cpp,
	special_units/ph.hpp, special_units/poh.cpp, special_units/poh.hpp,
	units/scalar_unit.cpp, units/scalar_unit.hpp, util/types.cpp,
	util/types.hpp: display up to two decimals for all units and related
	classes added

2023-06-23  Ismael Correa <ismael.correa.castro@gmail.com>

	* meca_numbers.hpp: header guard of meca_numbers.hpp improved

2023-06-23  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/dimension.hpp, units/vector_unit_nd.cpp: reformatting done

2023-06-23  Ismael Correa <ismael.correa.castro@gmail.com>

	* meca_number/angle.cpp, meca_number/angle.hpp: optimization in
	angle class

2023-06-23  Ismael Correa <ismael.correa.castro@gmail.com>

	* coordinates.hpp, coordinates/coordinates_1d.cpp,
	coordinates/coordinates_1d.hpp, coordinates/coordinates_2d.cpp,
	coordinates/coordinates_2d.hpp, coordinates/coordinates_2dr.cpp,
	coordinates/coordinates_2dr.hpp, coordinates/coordinates_3d.cpp,
	coordinates/coordinates_3d.hpp, coordinates/coordinates_3dr.cpp,
	coordinates/coordinates_3dr.hpp, coordinates/coordinates_nd.cpp,
	coordinates/coordinates_nd.hpp, coordinates/coordinates_ndr.cpp,
	coordinates/coordinates_ndr.hpp, topology/point_1d.cpp,
	topology/point_1d.hpp, topology/point_1d_impl.hpp,
	topology/point_2d.cpp, topology/point_2d.hpp,
	topology/point_2d_impl.hpp, topology/point_3d.cpp,
	topology/point_3d.hpp, topology/point_3d_impl.hpp,
	topology/point_nd.cpp, topology/point_nd.hpp,
	topology/point_nd_impl.hpp: rotational coordinates implemented and
	some bugs related to coordinates and point classes fixed

2023-06-21  Ismael Correa <ismael.correa.castro@gmail.com>

	* topology/point_2d.hpp, topology/point_3d.hpp,
	topology/point_nd.hpp: point classes now have display functions and
	coordinates methods of coordinates system identical to coordinates
	classes

2023-06-21  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/dimension.cpp, units/dimension.hpp: pixel dimension added to
	allow calculations of length based on pixels. The implementation of
	dimension class has been advanced

2023-06-21  Ismael Correa <ismael.correa.castro@gmail.com>

	* coordinates/coordinates_2d.hpp, coordinates/coordinates_2dr.cpp,
	coordinates/coordinates_3dr.cpp, meca_number/lab_number.hpp,
	special_units/zid.cpp, units/vector_unit_2d.cpp,
	units/vector_unit_3d.cpp, units/vector_unit_nd.cpp: Bugs related to
	boost::split() fixed

2023-06-21  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_sizeof.cpp: test updated

2023-06-21  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/vector_unit_nd.cpp: bug fixed

2023-06-21  Ismael Correa <ismael.correa.castro@gmail.com>

	* : test_sizeof updated

2023-06-21  Ismael Correa <ismael.correa.castro@gmail.com>

	* coordinates/coordinates_1d.cpp, coordinates/coordinates_1d.hpp,
	coordinates/coordinates_2d.cpp, coordinates/coordinates_2d.hpp,
	coordinates/coordinates_2dr.cpp, coordinates/coordinates_2dr.hpp,
	coordinates/coordinates_3d.cpp, coordinates/coordinates_3d.hpp,
	coordinates/coordinates_3dr.cpp, coordinates/coordinates_3dr.hpp,
	coordinates/coordinates_nd.cpp, coordinates/coordinates_nd.hpp,
	topology/point_1d.cpp, topology/point_1d.hpp,
	topology/point_1d_impl.hpp, topology/point_2d.cpp,
	topology/point_2d.hpp, topology/point_2d_impl.hpp,
	topology/point_3d.cpp, topology/point_3d.hpp,
	topology/point_3d_impl.hpp, topology/point_nd.cpp,
	topology/point_nd.hpp, topology/point_nd_impl.hpp: point and
	coordinates classes now are template classes to allow the use of any
	scalar_unit, not only length, and also to allow to use float if it's
	needed to save memory

2023-06-21  Ismael Correa <ismael.correa.castro@gmail.com>

	* meca_number/angle.cpp: angle class tww bugs solved

2023-06-20  Ismael Correa <ismael.correa.castro@gmail.com>

	* : commit 4686d421fb56968496323ef9a1b179f7e79af90e Author: Ismael
	Correa <ismael.correa.castro@gmail.com> Date:   Tue Jun 20 01:43:22
	2023 -0400

2023-06-18  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/FUNDING.yml: Update FUNDING.yml Liberapay profile added

2023-06-18  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/FUNDING.yml: Create FUNDING.yml Sponsors button added to the repository

2023-06-18  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/dependabot.yml: Create dependabot.yml Dependabot configured for version updates

2023-06-18  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/codeql.yml: Update codeql.yml CodeQL environment variable added

2023-06-18  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/codeql.yml: Update codeql.yml CodeQL configured to use CMake

2023-06-18  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/codeql.yml: Create codeql.yml CodeQL analysis added

2023-06-18  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/cmake.yml: Update cmake.yml Dependencies job added

2023-06-18  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* .github/workflows/cmake.yml: Create cmake.yml CMake workflow created to automate builds in the repository

2023-06-12  Ismael Correa <ismael.correa.castro@gmail.com>

	* special_units/aid.cpp: Initialization of aid specifying type of
	astronomical body added following the planified ISO of astronomical
	identifiers (aids)

2023-06-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* special_units/aid.cpp, special_units/aid.hpp,
	special_units/zid.cpp, special_units/zid.hpp, units/dimension.cpp,
	units/scalar_unit.cpp, units/vector_unit_nd.cpp: aid and zid classes
	created, giving and identifier for astronomical bodies and for
	geographical zones, respectively. Bug with empty() function fixed

2023-06-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* coordinates/coordinates_2d.cpp, coordinates/coordinates_3d.cpp,
	coordinates/coordinates_nd.cpp, topology/point_2d.cpp,
	topology/point_3d.cpp, topology/point_nd.cpp: coordinates and point
	classes string constructor now supports cartesian, polar,
	cylindrical, spherical and geographical initialization

2023-06-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* CMakeLists.txt, meca_number/angle.cpp, meca_number/angle.hpp: 
	angle class bug with the character º fixed. Library libicuuc added
	and working with a wide amount of versions for this library

2023-06-09  Ismael Correa <ismael.correa.castro@gmail.com>

	* README.md: vector_unit_nd class documented in the README.md file

2023-06-09  Ismael Correa <ismael.correa.castro@gmail.com>

	* meca_number/angle.cpp, meca_number/angle.hpp: angle class
	assignment operators implemented

2023-06-09  Ismael Correa <ismael.correa.castro@gmail.com>

	* special_units/ph.cpp, special_units/ph.hpp,
	special_units/poh.cpp, special_units/poh.hpp: pH and pOH created to
	handle the pH. They distinguish acidic, basic and neutral values,
	and allow to get the respective concentration of H+ and OH- that the
	pH specifies

2023-06-09  Ismael Correa <ismael.correa.castro@gmail.com>

	* README.md: Description of vector_unit_3d class added to the
	README.md file

2023-06-09  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/dimension.cpp, units/dimension.hpp, units/scalar_unit.cpp: 
	sqrt() and sqrt_nth() now is working for dimensions. Abbreviations
	in de denominator aren't still covered

2023-06-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/dimension.cpp, units/dimension.hpp: Added new dimension of
	money to handle any currency. The abbreviations of each one have to
	be created for each case, currently the reason of that is the fact
	that the change of one money to another varies each day

2023-06-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/vector_unit_2d.cpp, units/vector_unit_2d.hpp,
	units/vector_unit_3d.hpp, units/vector_unit_nd.cpp,
	units/vector_unit_nd.hpp: vector_unit classes now give their axis
	projections in scalar_unit classes

2023-06-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/dimension.cpp, units/dimension.hpp: Custom dimensions
	implemented with char[3] and an efficient memory system that handles
	all strings inside a map in order to save memory. Some bugs related
	to dimensions have been fixed

2023-06-07  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/dimension.cpp, units/dimension.hpp: Destructor added to
	dimension

2023-06-07  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_sizeof.cpp, units/dimension.cpp: custom_dimension.hpp
	header deleted

2023-06-07  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/custom_dimension.cpp, units/custom_dimension.hpp: 
	custom_dimencion.cpp and custom_dimension.hpp files deleted

2023-06-07  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/custom_dimension.cpp, units/custom_dimension.hpp,
	units/dimension.cpp, units/dimension.hpp: custom dimensions
	implemented

2023-06-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/scalar_unit.cpp: Initialization of 1/g and similar
	dimensions, with dimensions only in the denomintar, supported

2023-06-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/test_sizeof.cpp, units/dimension.cpp, units/dimension.hpp: 
	dimensions updated to reflect new implementations

2023-06-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/dimension.cpp, units/prefix.cpp, units/prefix.hpp: dimension
	and prefix migrations developed

2023-06-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* predefined_units/substance_units.cpp, units/custom_dimension.cpp,
	units/custom_dimension.hpp, units/dimension.cpp,
	units/dimension.hpp: implementations of functions of dimensions
	finished

2023-06-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/dimension.cpp: Greek Omega symbol for the resistance added

2023-06-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/unit_basic.cpp, units/base_units.hpp: msci::time now
	operates with duration and then it can be used with STL clocks of
	<chrono>

2023-06-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/dimension.cpp, units/dimension.hpp: equal_dimensions()
	function for comparing two different strings of dimensions to check
	if they are equal in their basic dimensions

2023-06-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* CMakeLists.txt, README.md, TODO.md, coordinates.hpp,
	coordinates/coordinates_3d.hpp, meca_numbers.hpp,
	predefined_units/dynamics_units.cpp,
	predefined_units/dynamics_units.hpp, tests/test_sizeof.cpp,
	topology/direction.hpp, units/custom_dimension.cpp,
	units/custom_dimension.hpp, units/dimension.hpp, units/prefix.hpp,
	units/base_units.hpp, units/vector_unit_2d.hpp,
	units/vector_unit_3d.hpp, units/vector_unit_nd.hpp, util/matrix.hpp: 
	header meca_numbers.hpp updated. test_sizeof added inside CMake.
	README and TODO updated. enums updated to use only 1 byte instead of
	4 bytes. custom_dimension advance. vector_unit classes operator ^=
	deleted to match scalar_unit. force changed to be a vector_unit

2023-06-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/base_units.hpp: ostream operator not more needed

2023-06-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* TODO.md, units/unit_abbreviation.cpp,
	units/unit_abbreviation.hpp, units/unit_basic.cpp,
	units/base_units.hpp: time class now can display as time as a string
	for any case, not only for streams. Literals _m bug fixed

2023-06-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* README.md, compile_commands.json: README updated

2023-06-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* TODO.md, meca_number/angle.cpp, meca_number/angle.hpp,
	units/vector_unit_2d.cpp, units/vector_unit_3d.cpp,
	units/vector_unit_nd.cpp: operator == now checks dimensions for
	vector_unit classes. Angle bug fixed

2023-06-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* CMakeLists.txt, README.md: Installation instructions updated

2023-06-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/scalar_unit.cpp, units/scalar_unit.hpp: operators * and / of
	scalar_unit improved

2023-06-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* meca_number/angle.hpp, units/scalar_unit.cpp,
	units/scalar_unit.hpp: operators++ improved. operators + and - of
	scalar_unit improved too

2023-06-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* TODO.md, units/custom_dimension.cpp, units/custom_dimension.hpp,
	units/dimension.cpp, units/dimension.hpp, units/scalar_unit.cpp,
	units/vector_unit_2d.cpp, units/vector_unit_2d.hpp,
	units/vector_unit_3d.cpp, units/vector_unit_3d.hpp,
	units/vector_unit_nd.cpp, units/vector_unit_nd.hpp: scalar_unit and
	vector_unit classes bug fixes. custom_dimension created!

2023-06-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* README.md, units/scalar_unit.hpp, units/unit_abbreviation.hpp: 
	README updated. A bug on scalar_units has been fixed

2023-06-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/unit_abbreviation.cpp, units/unit_abbreviation.hpp: length
	literals added

2023-06-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* coordinates/coordinates_nd.hpp, tests/test_sizeof.cpp,
	topology/point_1d.hpp, topology/point_2d.hpp,
	topology/point_3d.hpp, topology/point_nd.hpp, units.hpp,
	units/unit_abbreviation.hpp: units headers improved

2023-06-04  Ismael Correa <ismael.correa.castro@gmail.com>

	* meca_number/lab_number.hpp: istream for lab_number<T>

2023-06-04  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/vector_unit_nd.cpp, units/vector_unit_nd.hpp: to_string()
	function for vector_unit_nd

2023-06-04  Ismael Correa <ismael.correa.castro@gmail.com>

	* DISCARDED_FEATURES, TODO.md, coordinates/coordinates_1d.cpp,
	coordinates/coordinates_1d.hpp, coordinates/coordinates_2d.cpp,
	coordinates/coordinates_2d.hpp, coordinates/coordinates_3d.cpp,
	coordinates/coordinates_3d.hpp, coordinates/coordinates_nd.cpp,
	coordinates/coordinates_nd.hpp, meca_number/angle.cpp,
	meca_number/angle.hpp, meca_number/lab_number.hpp,
	topology/direction.cpp, topology/direction.hpp,
	topology/point_1d.cpp, topology/point_1d.hpp,
	topology/point_2d.cpp, topology/point_2d.hpp,
	topology/point_3d.cpp, topology/point_3d.hpp,
	topology/point_nd.cpp, topology/point_nd.hpp, units/conversion.hpp,
	units/dimension.cpp, units/dimension.hpp, units/prefix.cpp,
	units/prefix.hpp, units/scalar_unit.cpp, units/unit_basic.cpp,
	units/base_units.hpp, util/matrix.hpp: coordinates and points now
	have operators and stream for string cases. Some refactoring and
	improvements with headers have been done

2023-06-04  Ismael Correa <ismael.correa.castro@gmail.com>

	* TODO.md, units/vector_unit_2d.cpp, units/vector_unit_2d.hpp,
	units/vector_unit_3d.cpp, units/vector_unit_3d.hpp,
	units/vector_unit_nd.cpp, units/vector_unit_nd.hpp: vector_unit
	classes now operate with strings, operator == bug fixed

2023-06-04  Ismael Correa <ismael.correa.castro@gmail.com>

	* coordinates/coordinates_2d.cpp, coordinates/coordinates_2d.hpp,
	coordinates/coordinates_nd.cpp, coordinates/coordinates_nd.hpp,
	meca_number/lab_number.hpp, units/dimension.cpp,
	units/dimension.hpp, units/prefix.cpp, units/prefix.hpp: 
	coordinates_nd now can behave at the same time as polar,
	cylindrical, spherical and carrtesian coordinates. Some refactorings
	done

2023-06-04  Ismael Correa <ismael.correa.castro@gmail.com>

	* compile_commands.json, coordinates/coordinates_1d.cpp,
	coordinates/coordinates_1d.hpp, coordinates/coordinates_2d.cpp,
	coordinates/coordinates_2d.hpp, coordinates/coordinates_2dr.cpp,
	coordinates/coordinates_2dr.hpp, coordinates/coordinates_3d.cpp,
	coordinates/coordinates_3d.hpp, coordinates/coordinates_3dr.cpp,
	coordinates/coordinates_nd.cpp, coordinates/coordinates_nd.hpp,
	magick.cpp, meca_number/angle.hpp,
	predefined_units/kinematics_units.cpp,
	predefined_units/kinematics_units.hpp, tests/main_units.cpp,
	tests/test_sizeof.cpp, topology/point_1d.cpp,
	topology/point_1d.hpp, topology/point_2d.cpp,
	topology/point_2d.hpp, topology/point_3d.cpp,
	topology/point_3d.hpp, topology/point_nd.cpp,
	topology/point_nd.hpp, units/dimension.cpp, units/dimension.hpp,
	units/scalar_unit.hpp, units/vector_unit_2d.cpp,
	units/vector_unit_2d.hpp, units/vector_unit_3d.cpp,
	units/vector_unit_3d.hpp, units/vector_unit_nd.cpp,
	units/vector_unit_nd.hpp: point_nd and coordinates_nd implemented
	like the others

2023-06-03  Ismael Correa <ismael.correa.castro@gmail.com>

	* compile_commands.json, coordinates/coordinates_1d.cpp,
	coordinates/coordinates_1d.hpp, coordinates/coordinates_2d.cpp,
	coordinates/coordinates_2d.hpp, coordinates/coordinates_3d.cpp,
	coordinates/coordinates_3d.hpp, coordinates/coordinates_nd.cpp,
	topology/point_1d.cpp, topology/point_1d.hpp,
	topology/point_2d.cpp, topology/point_2d.hpp,
	topology/point_3d.hpp, units/vector_unit_2d.cpp,
	units/vector_unit_3d.cpp, units/vector_unit_nd.cpp: coordinates_1d
	and point_1d created

2023-06-03  Ismael Correa <ismael.correa.castro@gmail.com>

	* TODO.md, compile_commands.json, coordinates/coordinates_1d.cpp,
	coordinates/coordinates_1d.hpp, coordinates/coordinates_2d.cpp,
	coordinates/coordinates_2d.hpp, coordinates/coordinates_3d.cpp,
	coordinates/coordinates_3d.hpp, coordinates/coordinates_ndr.cpp,
	coordinates/coordinates_ndr.hpp, fields/vector_field.cpp,
	fields/vector_field.hpp, fields/vector_field_3d.hpp, magick.cpp,
	meca_number/angle.hpp, predefined_units/kinematics_units.cpp,
	predefined_units/kinematics_units.hpp, special_units/color.hpp,
	topology/direction.cpp, topology/direction.hpp,
	topology/point_1d.cpp, topology/point_1d.hpp,
	topology/point_2d.cpp, topology/point_2d.hpp,
	topology/point_3d.cpp, topology/point_3d.hpp,
	topology/point_nd.cpp, topology/point_nd.hpp,
	units/scalar_unit.cpp, units/scalar_unit.hpp, units/unit_basic.cpp,
	units/base_units.hpp, units/vector_unit_2d.cpp,
	units/vector_unit_2d.hpp, units/vector_unit_3d.cpp,
	units/vector_unit_3d.hpp, units/vector_unit_nd.cpp,
	units/vector_unit_nd.hpp: coordinates and points of 2d and 3d cases
	improved

2023-06-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* README.md: README actualizado

2023-06-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* CMakeLists.txt, EXTRA, TODO.md, compile_commands.json,
	coordinates/cartesian_coordinates_2d.cpp,
	coordinates/cartesian_coordinates_2d.hpp,
	coordinates/cartesian_coordinates_3d.cpp,
	coordinates/cartesian_coordinates_3d.hpp,
	coordinates/coordinates.cpp, coordinates/coordinates.hpp,
	coordinates/coordinates_1d.cpp, coordinates/coordinates_1d.hpp,
	coordinates/coordinates_2d.cpp, coordinates/coordinates_2d.hpp,
	coordinates/coordinates_2dr.cpp, coordinates/coordinates_2dr.hpp,
	coordinates/coordinates_3d.cpp, coordinates/coordinates_3d.hpp,
	coordinates/coordinates_3dr.cpp, coordinates/coordinates_3dr.hpp,
	coordinates/coordinates_nd.cpp, coordinates/coordinates_nd.hpp,
	coordinates/cylindrical_coordinates.cpp,
	coordinates/cylindrical_coordinates.hpp,
	coordinates/directional_coordinates.cpp,
	coordinates/directional_coordinates.hpp,
	coordinates/hyper_spherical_coordinates.cpp,
	coordinates/hyper_spherical_coordinates.hpp,
	coordinates/light/cartesian_2d.cpp,
	coordinates/light/cartesian_2d.hpp,
	coordinates/light/cartesian_2dr.cpp,
	coordinates/light/cartesian_2dr.hpp,
	coordinates/light/cartesian_3d.cpp,
	coordinates/light/cartesian_3d.hpp,
	coordinates/light/cartesian_3dr.cpp,
	coordinates/light/cartesian_3dr.hpp,
	coordinates/polar_coordinates.cpp,
	coordinates/polar_coordinates.hpp, coordinates/rotation_1d.cpp,
	coordinates/rotation_1d.hpp, coordinates/spherical_coordinates.cpp,
	coordinates/spherical_coordinates.hpp, error_log, fields/field.cpp,
	fields/field.hpp, fields/vector_field.hpp, magick.cpp,
	meca_number/angle.cpp, meca_number/angle.hpp,
	meca_number/lab_number.hpp, meca_numbers.hpp,
	predefined_units/acoustics_units.hpp,
	predefined_units/astronomy_units.cpp,
	predefined_units/astronomy_units.hpp,
	predefined_units/atoms_units.cpp, predefined_units/atoms_units.hpp,
	predefined_units/biochemistry_units.cpp,
	predefined_units/biochemistry_units.hpp,
	predefined_units/dynamics_units.cpp,
	predefined_units/dynamics_units.hpp,
	predefined_units/electricity_units.cpp,
	predefined_units/electricity_units.hpp,
	predefined_units/fluid_dynamics_units.cpp,
	predefined_units/fluid_dynamics_units.hpp,
	predefined_units/hardware_units.cpp,
	predefined_units/hardware_units.hpp,
	predefined_units/informatics_units.cpp,
	predefined_units/informatics_units.hpp,
	predefined_units/kinematics_units.cpp,
	predefined_units/kinematics_units.hpp,
	predefined_units/magnetism_units.cpp,
	predefined_units/magnetism_units.hpp,
	predefined_units/matter_units.hpp,
	predefined_units/optics_units.cpp,
	predefined_units/optics_units.hpp,
	predefined_units/radiometry_units.cpp,
	predefined_units/radiometry_units.hpp,
	predefined_units/space_units.cpp, predefined_units/space_units.hpp,
	predefined_units/substance_units.cpp,
	predefined_units/substance_units.hpp,
	predefined_units/thermodynamics_units.cpp,
	predefined_units/thermodynamics_units.hpp,
	predefined_units/waves_units.cpp, predefined_units/waves_units.hpp,
	special_units/color.cpp, tests/main.cpp, tests/main_units.cpp,
	tests/test_dimensions.hpp, tests/test_sizeof.cpp,
	tests/test_units.hpp, tests/test_vector_units.cpp,
	tests/test_vector_units.hpp, topology/direction.cpp,
	topology/direction.hpp, topology/point_2d.cpp,
	topology/point_2d.hpp, topology/point_3d.cpp,
	topology/point_3d.hpp, units.hpp, units.kdev4,
	units/conversion.cpp, units/conversion.hpp, units/dimension.cpp,
	units/dimension.hpp, units/prefix.cpp, units/scalar_unit.cpp,
	units/scalar_unit.hpp, units/unit_abbreviation.cpp,
	units/unit_abbreviation.hpp, units/unit_basic.cpp,
	units/base_units.hpp, units/vector_unit_2d.cpp,
	units/vector_unit_2d.hpp, units/vector_unit_3d.cpp,
	units/vector_unit_3d.hpp, units/vector_unit_nd.cpp,
	units/vector_unit_nd.hpp, util/matrix.hpp, util/types.cpp: Library
	advancing, improved

2023-05-22  Ismael Correa <ismael.correa.castro@gmail.com>

	* HISTORY.md, README.md, TODO.md,
	coordinates/cartesian_coordinates_2d.cpp,
	coordinates/cartesian_coordinates_3d.cpp,
	coordinates/coordinates_2d.hpp, coordinates/coordinates_3d.cpp,
	coordinates/coordinates_3d.hpp,
	coordinates/cylindrical_coordinates.cpp,
	coordinates/hyper_spherical_coordinates.cpp,
	coordinates/hyper_spherical_coordinates.hpp,
	coordinates/light/cartesian_2d.cpp,
	coordinates/light/cartesian_2d.hpp,
	coordinates/light/cartesian_2dr.cpp,
	coordinates/light/cartesian_2dr.hpp,
	coordinates/light/cartesian_3d.cpp,
	coordinates/light/cartesian_3d.hpp,
	coordinates/light/cartesian_3dr.cpp,
	coordinates/light/cartesian_3dr.hpp, error_log, fields/field.hpp,
	fields/scalar_field.hpp, fields/vector_field.hpp,
	meca_number/angle.cpp, meca_number/angle.hpp,
	meca_number/lab_number.cpp, meca_number/lab_number.hpp,
	meca_number/perfect_number.hpp, meca_number/undefined_number.hpp,
	meca_number/unit_number.cpp, meca_number/unit_number.hpp,
	predefined_units/acoustics_units.hpp,
	predefined_units/astronomy_units.hpp,
	predefined_units/biochemistry_units.hpp,
	predefined_units/dynamics_units.cpp,
	predefined_units/dynamics_units.hpp,
	predefined_units/electricity_units.hpp,
	predefined_units/fluid_dynamics_units.hpp,
	predefined_units/hardware_units.hpp,
	predefined_units/informatics_units.hpp,
	predefined_units/kinematics_units.hpp,
	predefined_units/magnetism_units.hpp,
	predefined_units/matter_units.hpp,
	predefined_units/optics_units.hpp,
	predefined_units/radiometry_units.hpp,
	predefined_units/space_units.hpp,
	predefined_units/substance_units.hpp,
	predefined_units/thermodynamics_units.hpp,
	predefined_units/waves_units.hpp, special_units/color.hpp,
	tests/main_units.cpp, tests/test_dimensions.hpp,
	tests/test_sizeof.cpp, tests/test_units.hpp,
	tests/test_vector_units.hpp, topology/constants.hpp,
	topology/direction.cpp, topology/direction.hpp,
	topology/point_2d.hpp, topology/point_3d.cpp,
	topology/point_3d.hpp, units.hpp, units.kdev4,
	units/conversion.hpp, units/dimension.cpp, units/dimension.hpp,
	units/prefix.cpp, units/prefix.hpp, units/scalar_unit.cpp,
	units/scalar_unit.hpp, units/unit_abbreviation.cpp,
	units/unit_abbreviation.hpp, units/unit_basic.cpp,
	units/base_units.hpp, units/vector_unit_2d.cpp,
	units/vector_unit_2d.hpp, units/vector_unit_3d.cpp,
	units/vector_unit_3d.hpp, units/vector_unit_nd.cpp,
	units/vector_unit_nd.hpp, util/is_number.hpp, util/matrix.hpp: Good
	amount of changes, now it's more light

2019-07-23  Ismael Correa <ismael.correa.castro@gmail.com>

	* TODO - MagickScience.md, TODO.md,
	coordinates/cartesian_coordinates_2d.cpp,
	coordinates/cartesian_coordinates_2d.hpp,
	coordinates/cartesian_coordinates_3d.cpp,
	coordinates/cartesian_coordinates_3d.hpp,
	coordinates/coordinates_1d.hpp, coordinates/coordinates_2d.hpp,
	coordinates/coordinates_3d.cpp, coordinates/coordinates_3d.hpp,
	coordinates/coordinates_nd.hpp,
	coordinates/cylindrical_coordinates.cpp,
	coordinates/cylindrical_coordinates.hpp,
	coordinates/directional_coordinates.cpp,
	coordinates/directional_coordinates.hpp,
	coordinates/hyper_spherical_coordinates.cpp,
	coordinates/hyper_spherical_coordinates.hpp,
	coordinates/light/cartesian_2d.cpp,
	coordinates/light/cartesian_2d.hpp,
	coordinates/light/cartesian_2dr.cpp,
	coordinates/light/cartesian_2dr.hpp,
	coordinates/light/cartesian_3d.cpp,
	coordinates/light/cartesian_3dr.cpp,
	coordinates/light/cartesian_3dr.hpp,
	coordinates/polar_coordinates.cpp,
	coordinates/polar_coordinates.hpp, coordinates/rotation_1d.cpp,
	coordinates/rotation_1d.hpp, coordinates/spherical_coordinates.cpp,
	coordinates/spherical_coordinates.hpp, magick.cpp,
	meca_number/angle.cpp, meca_number/angle.hpp,
	meca_number/angle_number.cpp, meca_number/angle_number.hpp,
	meca_number/lab_number.cpp, meca_number/lab_number.hpp,
	meca_number/undefined_number.hpp, meca_number/unit_number.cpp,
	meca_number/unit_number.hpp, meca_numbers.hpp,
	predefined_units/acoustics_units.hpp,
	predefined_units/astronomy_units.hpp,
	predefined_units/dynamics_units.hpp,
	predefined_units/electricity_units.hpp,
	predefined_units/hardware_units.hpp,
	predefined_units/kinematics_units.hpp,
	predefined_units/magnetism_units.hpp,
	predefined_units/optics_units.hpp,
	predefined_units/radiometry_units.hpp,
	predefined_units/space_units.hpp,
	predefined_units/substance_units.cpp,
	predefined_units/thermodynamics_units.hpp,
	predefined_units/waves_units.hpp, tests/test_sizeof.cpp,
	tests/test_vector_units.hpp, topology/constants.hpp,
	topology/direction.cpp, topology/point_2d.cpp,
	topology/point_2d.hpp, topology/point_3d.cpp,
	topology/point_3d.hpp, topology/topology.hpp, units.hpp,
	units/abbreviation.cpp, units/abbreviation.hpp,
	units/abstract_dimension.cpp, units/abstract_dimension.hpp,
	units/auto_scalar.cpp, units/auto_scalar.hpp,
	units/auto_vector.cpp, units/auto_vector.hpp, units/dimension.cpp,
	units/dimension.hpp, units/dimension_container.cpp,
	units/dimension_container.hpp, units/prefix.cpp, units/prefix.hpp,
	units/scalar_unit.cpp, units/scalar_unit.hpp, units/unit_basic.cpp,
	units/base_units.hpp, units/vector_unit.cpp, units/vector_unit.hpp,
	units/vector_unit_3d.cpp, units/vector_unit_3d.hpp,
	util/is_number.hpp, util/matrix.hpp: Refactoring of units nearly
	ready

2019-06-14  Ismael Correa <ismael.correa.castro@gmail.com>

	* TODO - MagickScience.md, TODO - units, meca numbers, fields.md,
	TODO.md, coordinates/coordinates_3d.hpp,
	coordinates/light/cartesian_2d.cpp,
	coordinates/light/cartesian_2d.hpp, coordinates/rotation_1d.cpp,
	coordinates/rotation_1d.hpp, meca_number/angle_number.cpp,
	meca_number/angle_number.hpp, meca_number/unit_number.cpp,
	predefined_units/atoms_units.hpp,
	predefined_units/matter_units.hpp,
	predefined_units/substance_units.cpp, tests/main_units.cpp,
	topology/point_2d.cpp, topology/point_2d.hpp, units.hpp,
	units/auto_scalar.cpp, units/auto_scalar.hpp,
	units/auto_vector.cpp, units/auto_vector.hpp, units/{unit.cpp =>
	scalar_unit.cpp}, units/scalar_unit.hpp, units/unit.hpp,
	units/unit_abbreviation.hpp, units/unit_basic.cpp,
	units/base_units.hpp, units/vector_unit.cpp, units/vector_unit.hpp,
	util/matrix.hpp: new units hierarchy starting by scalar_unit has
	been started

2019-06-14  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/auto_unit.cpp, units/auto_unit.hpp, units/scalar_unit.cpp,
	units/scalar_unit.hpp: new progress of the units library

2019-05-22  Ismael Correa <ismael.correa.castro@gmail.com>

	* CHANGELOG.md, CMakeLists.txt, CODE_OF_CONDUCT.md,
	CONTRIBUTING.md, LICENSE, README.md, TODO - units, meca numbers,
	fields.md, TODO.md, coordinates/cartesian_coordinates_2d.cpp,
	coordinates/cartesian_coordinates_2d.hpp,
	coordinates/cartesian_coordinates_3d.cpp,
	coordinates/cartesian_coordinates_3d.hpp,
	coordinates/coordinates.cpp, coordinates/coordinates.hpp,
	coordinates/coordinates_1d.cpp, coordinates/coordinates_1d.hpp,
	coordinates/coordinates_2d.cpp, coordinates/coordinates_2d.hpp,
	coordinates/coordinates_3d.cpp, coordinates/coordinates_3d.hpp,
	coordinates/coordinates_nd.cpp, coordinates/coordinates_nd.hpp,
	coordinates/cylindrical_coordinates.cpp,
	coordinates/cylindrical_coordinates.hpp,
	coordinates/directional_coordinates.cpp,
	coordinates/directional_coordinates.hpp,
	coordinates/hyper_spherical_coordinates.cpp,
	coordinates/hyper_spherical_coordinates.hpp,
	coordinates/light/cartesian_2d.cpp,
	coordinates/light/cartesian_2d.hpp,
	coordinates/light/cartesian_2dr.cpp,
	coordinates/light/cartesian_2dr.hpp,
	coordinates/light/cartesian_3d.cpp,
	coordinates/light/cartesian_3d.hpp,
	coordinates/light/cartesian_3dr.cpp,
	coordinates/light/cartesian_3dr.hpp,
	coordinates/polar_coordinates.cpp,
	coordinates/polar_coordinates.hpp,
	coordinates/spherical_coordinates.cpp,
	coordinates/spherical_coordinates.hpp, fields/field.hpp,
	fields/scalar_field.hpp, fields/vector_field.hpp, magick.cpp,
	meca_number/angle_number.cpp, meca_number/angle_number.hpp,
	meca_number/lab_number.cpp, meca_number/lab_number.hpp,
	meca_number/perfect_number.hpp, meca_number/undefined_number.hpp,
	meca_number/unit_number.cpp, meca_number/unit_number.hpp,
	meca_numbers.hpp, msci.pc, predefined_units/acoustics_units.hpp,
	predefined_units/astronomy_units.cpp,
	predefined_units/astronomy_units.hpp,
	predefined_units/atoms_units.cpp, predefined_units/atoms_units.hpp,
	predefined_units/biochemistry_units.cpp,
	predefined_units/biochemistry_units.hpp,
	predefined_units/dynamics_units.cpp,
	predefined_units/dynamics_units.hpp,
	predefined_units/electricity_units.cpp,
	predefined_units/electricity_units.hpp,
	predefined_units/fluid_dynamics_units.cpp,
	predefined_units/fluid_dynamics_units.hpp,
	predefined_units/hardware_units.cpp,
	predefined_units/hardware_units.hpp,
	predefined_units/informatics_units.cpp,
	predefined_units/informatics_units.hpp,
	predefined_units/kinematics_units.cpp,
	predefined_units/kinematics_units.hpp,
	predefined_units/magnetism_units.cpp,
	predefined_units/magnetism_units.hpp,
	predefined_units/matter_units.hpp,
	predefined_units/optics_units.cpp,
	predefined_units/optics_units.hpp,
	predefined_units/radiometry_units.cpp,
	predefined_units/radiometry_units.hpp,
	predefined_units/space_units.cpp, predefined_units/space_units.hpp,
	predefined_units/substance_units.cpp,
	predefined_units/substance_units.hpp,
	predefined_units/thermodynamics_units.cpp,
	predefined_units/thermodynamics_units.hpp,
	predefined_units/waves_units.cpp, predefined_units/waves_units.hpp,
	special_units/color.cpp, special_units/color.hpp, tests/main.cpp,
	tests/test_dimensions.hpp, tests/test_sizeof.cpp,
	tests/test_units.hpp, tests/test_vector_units.cpp,
	tests/test_vector_units.hpp, topology/constants.hpp,
	topology/direction.cpp, topology/direction.hpp,
	topology/point_2d.cpp, topology/point_2d.hpp,
	topology/point_3d.cpp, topology/point_3d.hpp,
	topology/topology.hpp, units.hpp, units/abbreviation.cpp,
	units/abbreviation.hpp, units/abstract_dimension.cpp,
	units/abstract_dimension.hpp, units/auto_scalar.cpp,
	units/auto_scalar.hpp, units/auto_unit.cpp, units/auto_unit.hpp,
	units/auto_vector.cpp, units/auto_vector.hpp, units/conversion.cpp,
	units/conversion.hpp, units/dimension.cpp, units/dimension.hpp,
	units/dimension_container.cpp, units/dimension_container.hpp,
	units/prefix.cpp, units/prefix.hpp, units/scalar_unit.cpp,
	units/scalar_unit.hpp, units/unit.cpp, units/unit.hpp,
	units/unit_abbreviation.cpp, units/unit_abbreviation.hpp,
	units/unit_basic.cpp, units/base_units.hpp, units/vector_unit.cpp,
	units/vector_unit.hpp, util/is_number.hpp, util/matrix.hpp,
	util/types.cpp, util/types.hpp: msci units library updated

2018-08-21  Ismael Correa <ismael.correa.castro@gmail.com>

	* CHANGELOG.md, CMakeLists.txt, TODO - units, meca numbers,
	fields.md, TODO biology.md, TODO chemistry.md, TODO math.md, TODO
	physics.md, biology/dna/chromosome.cpp, biology/dna/chromosome.hpp,
	biology/dna/dna.cpp, biology/dna/dna.hpp, biology/dna/gene.cpp,
	biology/dna/gene.hpp, biology/dna/nitrogenous_base.cpp,
	biology/dna/nitrogenous_base.hpp, chemistry.hpp,
	chemistry/general/atoms.hpp, chemistry/general/atoms/atom.cpp,
	chemistry/general/atoms/atom.hpp,
	chemistry/general/atoms/atomic_orbital.cpp,
	chemistry/general/atoms/atomic_orbital.hpp,
	chemistry/general/atoms/atoms.cpp,
	chemistry/general/atoms/atoms.hpp,
	chemistry/general/atoms/atoms_ac.cpp,
	chemistry/general/atoms/atoms_ac.hpp,
	chemistry/general/atoms/atoms_ia.cpp,
	chemistry/general/atoms/atoms_ia.hpp,
	chemistry/general/atoms/atoms_ib.cpp,
	chemistry/general/atoms/atoms_ib.hpp,
	chemistry/general/atoms/atoms_iia.cpp,
	chemistry/general/atoms/atoms_iia.hpp,
	chemistry/general/atoms/atoms_iib.cpp,
	chemistry/general/atoms/atoms_iib.hpp,
	chemistry/general/atoms/atoms_iiia.cpp,
	chemistry/general/atoms/atoms_iiia.hpp,
	chemistry/general/atoms/atoms_iiib.cpp,
	chemistry/general/atoms/atoms_iiib.hpp,
	chemistry/general/atoms/atoms_iva.cpp,
	chemistry/general/atoms/atoms_iva.hpp,
	chemistry/general/atoms/atoms_ivb.cpp,
	chemistry/general/atoms/atoms_ivb.hpp,
	chemistry/general/atoms/atoms_la.cpp,
	chemistry/general/atoms/atoms_la.hpp,
	chemistry/general/atoms/atoms_va.cpp,
	chemistry/general/atoms/atoms_va.hpp,
	chemistry/general/atoms/atoms_vb.cpp,
	chemistry/general/atoms/atoms_vb.hpp,
	chemistry/general/atoms/atoms_via.cpp,
	chemistry/general/atoms/atoms_via.hpp,
	chemistry/general/atoms/atoms_vib.cpp,
	chemistry/general/atoms/atoms_vib.hpp,
	chemistry/general/atoms/atoms_viia.cpp,
	chemistry/general/atoms/atoms_viia.hpp,
	chemistry/general/atoms/atoms_viib.cpp,
	chemistry/general/atoms/atoms_viib.hpp,
	chemistry/general/atoms/atoms_viiia.cpp,
	chemistry/general/atoms/atoms_viiia.hpp,
	chemistry/general/atoms/atoms_viiib.cpp,
	chemistry/general/atoms/atoms_viiib.hpp,
	chemistry/general/atoms/bonds/bonds_ia.hpp,
	chemistry/general/atoms/datom.cpp,
	chemistry/general/atoms/datom.hpp,
	chemistry/general/atoms/datoms_ia.hpp,
	chemistry/general/atoms/electron_cloud.hpp,
	chemistry/general/atoms/normal_atom.hpp,
	chemistry/general/molecules/atomic_bond.cpp,
	chemistry/general/molecules/atomic_bond.hpp,
	chemistry/general/molecules/atomic_group.cpp,
	chemistry/general/molecules/atomic_group.hpp,
	chemistry/general/molecules/bit_molecule.cpp,
	chemistry/general/molecules/bit_molecule.hpp,
	chemistry/general/molecules/chemical_reaction.cpp,
	chemistry/general/molecules/chemical_reaction.hpp,
	chemistry/general/molecules/molecule.cpp,
	chemistry/general/molecules/molecule.hpp,
	chemistry/general/molecules/normal_molecule.cpp,
	chemistry/general/molecules/normal_molecule.hpp,
	chemistry/general/substance/substance.hpp,
	chemistry/general/substance/substance_ia.hpp,
	chemistry/laboratory/analysis/crystallograph.hpp,
	chemistry/laboratory/analysis/spectrometer.hpp,
	coordinates/cartesian_coordinates_2d.cpp,
	coordinates/cartesian_coordinates_2d.hpp,
	coordinates/cartesian_coordinates_3d.cpp,
	coordinates/cartesian_coordinates_3d.hpp,
	coordinates/coordinates_1d.cpp, coordinates/coordinates_1d.hpp,
	coordinates/coordinates_2d.cpp, coordinates/coordinates_2d.hpp,
	coordinates/coordinates_3d.cpp, coordinates/coordinates_3d.hpp,
	coordinates/coordinates_nd.cpp, coordinates/coordinates_nd.hpp,
	coordinates/cylindrical_coordinates.cpp,
	coordinates/cylindrical_coordinates.hpp,
	coordinates/directional_coordinates.cpp,
	coordinates/directional_coordinates.hpp,
	coordinates/hyper_spherical_coordinates.cpp,
	coordinates/hyper_spherical_coordinates.hpp,
	coordinates/light/cartesian_2d.cpp,
	coordinates/light/cartesian_2d.hpp,
	coordinates/polar_coordinates.cpp,
	coordinates/polar_coordinates.hpp,
	coordinates/spherical_coordinates.cpp,
	coordinates/spherical_coordinates.hpp, magick.cpp,
	math/algebra/math_expression.cpp, math/algebra/math_expression.hpp,
	math/algebra/math_expression_variable.cpp,
	math/algebra/math_expression_variable.hpp,
	math/algebra/math_function.cpp, math/algebra/math_function.hpp,
	math/algebra/math_term.cpp, math/algebra/math_term.hpp,
	math/algebra/math_variable.cpp, math/algebra/math_variable.hpp,
	math/topology/curve_2d.cpp, math/topology/curve_2d.hpp,
	math/topology/curve_3d.cpp, math/topology/curve_3d.hpp,
	math/topology/figure_2d/circle.cpp,
	math/topology/figure_2d/circle.hpp,
	math/topology/figure_2d/figure_2d.cpp,
	math/topology/figure_2d/figure_2d.hpp,
	math/topology/figure_2d/irregular_polygon.cpp,
	math/topology/figure_2d/irregular_polygon.hpp,
	math/topology/figure_2d/linear_figure_2d.cpp,
	math/topology/figure_2d/linear_figure_2d.hpp,
	math/topology/figure_2d/parallelogram.cpp,
	math/topology/figure_2d/parallelogram.hpp,
	math/topology/figure_2d/polygon.cpp,
	math/topology/figure_2d/polygon.hpp,
	math/topology/figure_2d/rectangle.cpp,
	math/topology/figure_2d/rectangle.hpp,
	math/topology/figure_2d/rhombus.cpp,
	math/topology/figure_2d/rhombus.hpp,
	math/topology/figure_2d/spatial_figure.hpp,
	math/topology/figure_2d/square.cpp,
	math/topology/figure_2d/square.hpp,
	math/topology/figure_2d/triangle.cpp,
	math/topology/figure_2d/triangle.hpp,
	math/topology/figure_3d/figure_3d.cpp,
	math/topology/figure_3d/figure_3d.hpp, math/topology/line_2d.cpp,
	math/topology/line_2d.hpp, math/topology/line_3d.cpp,
	math/topology/line_3d.hpp, meca_number/angle_number.cpp,
	meca_number/angle_number.hpp, meca_number/lab_number.cpp,
	meca_number/lab_number.hpp, meca_number/undefined_number.hpp,
	meca_number/unit_number.cpp, meca_number/unit_number.hpp,
	meca_numbers.hpp, physics/particles.hpp,
	physics/quantical/particles/electron.cpp,
	physics/quantical/particles/electron.hpp,
	physics/quantical/particles/proton.cpp,
	physics/quantical/particles/proton.hpp,
	predefined_units/acoustics_units.hpp,
	predefined_units/astronomy_units.cpp,
	predefined_units/astronomy_units.hpp,
	predefined_units/atoms_units.cpp, predefined_units/atoms_units.hpp,
	predefined_units/biochemistry_units.cpp,
	predefined_units/biochemistry_units.hpp,
	predefined_units/dynamics_units.cpp,
	predefined_units/dynamics_units.hpp,
	predefined_units/electricity_units.cpp,
	predefined_units/electricity_units.hpp,
	predefined_units/fluid_dynamics_units.cpp,
	predefined_units/fluid_dynamics_units.hpp,
	predefined_units/hardware_units.cpp,
	predefined_units/hardware_units.hpp,
	predefined_units/informatics_units.cpp,
	predefined_units/informatics_units.hpp,
	predefined_units/kinematics_units.cpp,
	predefined_units/kinematics_units.hpp,
	predefined_units/magnetism_units.cpp,
	predefined_units/magnetism_units.hpp,
	predefined_units/matter_units.hpp,
	predefined_units/optics_units.cpp,
	predefined_units/optics_units.hpp,
	predefined_units/radiometry_units.cpp,
	predefined_units/radiometry_units.hpp,
	predefined_units/space_units.cpp, predefined_units/space_units.hpp,
	predefined_units/substance_units.cpp,
	predefined_units/substance_units.hpp,
	predefined_units/thermodynamics_units.cpp,
	predefined_units/thermodynamics_units.hpp,
	predefined_units/waves_units.cpp, predefined_units/waves_units.hpp,
	spatial_math.hpp, {informatics/graphical =>
	special_units}/color.cpp, {informatics/graphical =>
	special_units}/color.hpp, tests/main.cpp,
	tests/test_dimensions.hpp, tests/test_sizeof.cpp,
	tests/test_units.hpp, tests/test_vector_units.cpp,
	tests/test_vector_units.hpp, topology/constants.hpp,
	topology/direction.cpp, topology/point_2d.cpp,
	topology/point_2d.hpp, topology/point_3d.cpp,
	topology/point_3d.hpp, units.hpp, units/abbreviation.cpp,
	units/abbreviation.hpp, units/abstract_dimension.cpp,
	units/abstract_dimension.hpp, units/auto_scalar.cpp,
	units/auto_scalar.hpp, units/auto_unit.cpp, units/auto_unit.hpp,
	units/auto_vector.cpp, units/auto_vector.hpp, units/conversion.cpp,
	units/conversion.hpp, units/dimension.cpp, units/dimension.hpp,
	units/dimension_container.cpp, units/dimension_container.hpp,
	units/prefix.cpp, units/prefix.hpp, units/scalar_unit.cpp,
	units/scalar_unit.hpp, units/unit.cpp, units/unit.hpp,
	units/unit_abbreviation.cpp, units/unit_abbreviation.hpp,
	units/unit_basic.cpp, units/base_units.hpp, units/vector_unit.cpp,
	units/vector_unit.hpp, {informatics/types => util}/is_number.hpp,
	{math/linear_algebra => util}/matrix.hpp: msci units library

2018-07-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* CMakeLists.txt, TODO - units, meca numbers, fields.md, TODO.md,
	fields/field.cpp, fields/field.hpp, fields/scalar_field.cpp,
	fields/scalar_field.hpp, fields/vector_field.cpp,
	fields/vector_field.hpp, magick.cpp,
	math/algebra/math_expression.cpp, math/algebra/math_expression.hpp,
	math/algebra/math_expression_variable.cpp,
	math/algebra/math_expression_variable.hpp,
	math/algebra/math_function.cpp, math/algebra/math_function.hpp,
	math/algebra/math_term.cpp, math/algebra/math_term.hpp,
	math/algebra/math_variable.cpp, math/algebra/math_variable.hpp,
	msci.pc, tests/main.cpp, tests/test_dimensions.hpp,
	tests/test_sizeof.cpp, tests/test_vector_units.cpp,
	tests/test_vector_units.hpp: new files committed to divide
	magickscience properly

2018-07-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.hpp,
	chemistry/general/molecules/molecule.hpp, meca_numbers.hpp: 
	meca_numbers paths updated

2018-07-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* biology/dna/chromosome.cpp, biology/dna/dna.cpp: dna classes now
	work as expected

2018-07-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/vector_unit.cpp: vector_unit now has a better display

2018-07-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* {predefined_units => tests}/test_units.hpp: test_units.hpp file
	has been moved improperly, fixed

2018-07-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* units/abbreviation.cpp, units/abbreviation.hpp,
	units/{dimension_abstract.cpp => abstract_dimension.cpp},
	units/{dimension_abstract.hpp => abstract_dimension.hpp},
	units/dimension.cpp, units/dimension.hpp,
	units/dimension_container.cpp, units/dimension_container.hpp,
	units/unit_basic.cpp: dimension_abstract class name changed to
	abstract_dimension

2018-07-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/constants.hpp: chemistry/constants.hpp file deleted
	because the avogadro constant is now part of topology/constants.hpp
	file

2018-07-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/constants.hpp,
	coordinates/cartesian_coordinates_2d.hpp,
	coordinates/coordinates_1d.hpp, coordinates/coordinates_2d.hpp,
	coordinates/coordinates_3d.cpp, coordinates/coordinates_3d.hpp,
	coordinates/coordinates_nd.hpp,
	coordinates/cylindrical_coordinates.hpp,
	coordinates/directional_coordinates.hpp,
	coordinates/hyper_spherical_coordinates.cpp,
	coordinates/hyper_spherical_coordinates.hpp,
	coordinates/polar_coordinates.hpp,
	coordinates/spherical_coordinates.hpp, magick.cpp,
	math/linear_algebra/matrix.hpp, meca_number/angle_number.hpp,
	meca_number/lab_number.hpp, meca_number/undefined_number.hpp,
	meca_number/unit_number.hpp, predefined_units/acoustics_units.hpp,
	predefined_units/astronomy_units.hpp,
	predefined_units/atoms_units.hpp,
	predefined_units/biochemistry_units.hpp,
	predefined_units/dynamics_units.hpp,
	predefined_units/electricity_units.hpp,
	predefined_units/fluid_dynamics_units.hpp,
	predefined_units/hardware_units.hpp,
	predefined_units/informatics_units.hpp,
	predefined_units/kinematics_units.hpp,
	predefined_units/magnetism_units.hpp,
	predefined_units/matter_units.hpp,
	predefined_units/optics_units.hpp,
	predefined_units/radiometry_units.hpp,
	predefined_units/space_units.hpp,
	predefined_units/substance_units.hpp,
	predefined_units/test_units.hpp,
	predefined_units/thermodynamics_units.hpp,
	predefined_units/waves_units.hpp, topology/constants.hpp,
	units.hpp, units/abbreviation.cpp, units/auto_unit.hpp,
	units/auto_vector.hpp, units/unit.hpp, units/unit_basic.cpp,
	units/vector_unit.hpp: new msci_units files changed in order to have
	to follow the new #include paths

2018-07-28  Ismael Correa <ismael.correa.castro@gmail.com>

	* {math => topology}/constants.hpp, {math/topology =>
	topology}/topology.hpp: math/constans.hpp and
	math/topology/topology.hpp have been moved to topology folder

2018-07-28  Ismael Correa <ismael.correa.castro@gmail.com>

	* {math/topology => topology}/direction.cpp, {math/topology =>
	topology}/direction.hpp, {math/topology => topology}/point_2d.cpp,
	{math/topology => topology}/point_2d.hpp, {math/topology =>
	topology}/point_3d.cpp, {math/topology => topology}/point_3d.hpp: 
	topology classes have been moved to topology for being part of
	msci_units

2018-07-28  Ismael Correa <ismael.correa.castro@gmail.com>

	* {math/topology/coordinates =>
	coordinates}/cartesian_coordinates_2d.cpp,
	{math/topology/coordinates =>
	coordinates}/cartesian_coordinates_2d.hpp,
	{math/topology/coordinates =>
	coordinates}/cartesian_coordinates_3d.cpp,
	{math/topology/coordinates =>
	coordinates}/cartesian_coordinates_3d.hpp,
	{math/topology/coordinates => coordinates}/coordinates_1d.cpp,
	{math/topology/coordinates => coordinates}/coordinates_1d.hpp,
	{math/topology/coordinates => coordinates}/coordinates_2d.cpp,
	{math/topology/coordinates => coordinates}/coordinates_2d.hpp,
	{math/topology/coordinates => coordinates}/coordinates_3d.cpp,
	{math/topology/coordinates => coordinates}/coordinates_3d.hpp,
	{math/topology/coordinates => coordinates}/coordinates_nd.cpp,
	{math/topology/coordinates => coordinates}/coordinates_nd.hpp,
	{math/topology/coordinates =>
	coordinates}/cylindrical_coordinates.cpp,
	{math/topology/coordinates =>
	coordinates}/cylindrical_coordinates.hpp,
	{math/topology/coordinates =>
	coordinates}/directional_coordinates.cpp,
	{math/topology/coordinates =>
	coordinates}/directional_coordinates.hpp,
	{math/topology/coordinates =>
	coordinates}/hyper_spherical_coordinates.cpp,
	{math/topology/coordinates =>
	coordinates}/hyper_spherical_coordinates.hpp,
	{math/topology/coordinates => coordinates}/polar_coordinates.cpp,
	{math/topology/coordinates => coordinates}/polar_coordinates.hpp,
	{math/topology/coordinates =>
	coordinates}/spherical_coordinates.cpp, {math/topology/coordinates
	=> coordinates}/spherical_coordinates.hpp, {math/number =>
	meca_number}/angle_number.cpp, {math/number =>
	meca_number}/angle_number.hpp, {math/number =>
	meca_number}/lab_number.cpp, {math/number =>
	meca_number}/lab_number.hpp, {math/number =>
	meca_number}/perfect_number.hpp, {math/number =>
	meca_number}/undefined_number.hpp, {math/number =>
	meca_number}/unit_number.cpp, {math/number =>
	meca_number}/unit_number.hpp: meca_numbers and coordinates have also
	been moved in order to create the units library

2018-07-28  Ismael Correa <ismael.correa.castro@gmail.com>

	* {physics/waves/acoustics =>
	predefined_units}/acoustics_units.cpp, {physics/waves/acoustics =>
	predefined_units}/acoustics_units.hpp, {physics/astronomy =>
	predefined_units}/astronomy_units.cpp, {physics/astronomy =>
	predefined_units}/astronomy_units.hpp, {chemistry/general/atoms =>
	predefined_units}/atoms_units.cpp, {chemistry/general/atoms =>
	predefined_units}/atoms_units.hpp, {chemistry/biochemistry =>
	predefined_units}/biochemistry_units.cpp, {chemistry/biochemistry
	=> predefined_units}/biochemistry_units.hpp,
	{physics/mechanics/dynamics =>
	predefined_units}/dynamics_units.cpp, {physics/mechanics/dynamics
	=> predefined_units}/dynamics_units.hpp,
	{physics/electromagnetism/electricity =>
	predefined_units}/electricity_units.cpp,
	{physics/electromagnetism/electricity =>
	predefined_units}/electricity_units.hpp,
	{physics/mechanics/fluid_dynamics =>
	predefined_units}/fluid_dynamics_units.cpp,
	{physics/mechanics/fluid_dynamics =>
	predefined_units}/fluid_dynamics_units.hpp,
	{physics/electromagnetism/hardware =>
	predefined_units}/hardware_units.cpp,
	{physics/electromagnetism/hardware =>
	predefined_units}/hardware_units.hpp, {informatics =>
	predefined_units}/informatics_units.cpp, {informatics =>
	predefined_units}/informatics_units.hpp,
	{physics/mechanics/kinematics =>
	predefined_units}/kinematics_units.cpp,
	{physics/mechanics/kinematics =>
	predefined_units}/kinematics_units.hpp,
	{physics/electromagnetism/magnetism =>
	predefined_units}/magnetism_units.cpp,
	{physics/electromagnetism/magnetism =>
	predefined_units}/magnetism_units.hpp, {chemistry/general/matter =>
	predefined_units}/matter_units.hpp, {physics/waves/optics =>
	predefined_units}/optics_units.cpp, {physics/waves/optics =>
	predefined_units}/optics_units.hpp, {physics/waves/radiometry =>
	predefined_units}/radiometry_units.cpp, {physics/waves/radiometry
	=> predefined_units}/radiometry_units.hpp, {physics/mechanics/space
	=> predefined_units}/space_units.cpp, {physics/mechanics/space =>
	predefined_units}/space_units.hpp, {chemistry/general/substance =>
	predefined_units}/substance_units.cpp, {chemistry/general/substance
	=> predefined_units}/substance_units.hpp, {tests =>
	predefined_units}/test_units.hpp, {physics/thermodynamics =>
	predefined_units}/thermodynamics_units.cpp, {physics/thermodynamics
	=> predefined_units}/thermodynamics_units.hpp, {physics/waves =>
	predefined_units}/waves_units.cpp, {physics/waves =>
	predefined_units}/waves_units.hpp, {physics/basic/units =>
	units}/abbreviation.cpp, {physics/basic/units =>
	units}/abbreviation.hpp, {physics/basic/units =>
	units}/auto_scalar.cpp, {physics/basic/units =>
	units}/auto_scalar.hpp, {physics/basic/units =>
	units}/auto_unit.cpp, {physics/basic/units => units}/auto_unit.hpp,
	{physics/basic/units => units}/auto_vector.cpp,
	{physics/basic/units => units}/auto_vector.hpp,
	{physics/basic/units => units}/conversion.cpp, {physics/basic/units
	=> units}/conversion.hpp, {physics/basic/units =>
	units}/dimension.cpp, {physics/basic/units => units}/dimension.hpp,
	{physics/basic/units => units}/dimension_abstract.cpp,
	{physics/basic/units => units}/dimension_abstract.hpp,
	{physics/basic/units => units}/dimension_container.cpp,
	{physics/basic/units => units}/dimension_container.hpp,
	{physics/basic/units => units}/prefix.cpp, {physics/basic/units =>
	units}/prefix.hpp, {physics/basic/units => units}/scalar_unit.cpp,
	{physics/basic/units => units}/scalar_unit.hpp,
	{physics/basic/units => units}/unit.cpp, {physics/basic/units =>
	units}/unit.hpp, {physics/basic/units =>
	units}/unit_abbreviation.cpp, {physics/basic/units =>
	units}/unit_abbreviation.hpp, {physics/basic/units =>
	units}/unit_basic.cpp, {physics/basic/units =>
	units}/base_units.hpp, {physics/basic/units =>
	units}/vector_unit.cpp, {physics/basic/units =>
	units}/vector_unit.hpp: msic_units library created, separated from
	the other msci libraries (every msci library has been divided in
	order to have a better order and more scalability).

2018-07-22  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.hpp,
	chemistry/general/molecules/atomic_bond.cpp,
	chemistry/general/molecules/chemical_reaction.hpp, units.hpp: other
	files of the previous commit also have changed

2018-07-22  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/biochemistry/biochemistry_units.cpp,
	chemistry/general/atoms/atoms_units.cpp,
	chemistry/general/substance/substance_units.cpp,
	informatics/informatics_units.cpp,
	physics/astronomy/astronomy_units.cpp,
	physics/electromagnetism/electricity/electricity_units.cpp,
	physics/electromagnetism/hardware/hardware_units.cpp,
	physics/electromagnetism/magnetism/magnetism_units.cpp,
	physics/mechanics/dynamics/dynamics_units.cpp,
	physics/mechanics/fluid_dynamics/fluid_dynamics_units.cpp,
	physics/mechanics/kinematics/kinematics_units.cpp,
	physics/mechanics/space/space_units.cpp,
	physics/thermodynamics/thermodynamics_units.cpp,
	physics/waves/optics/optics_units.cpp,
	physics/waves/radiometry/radiometry_units.cpp,
	physics/waves/waves_units.cpp: units.hpp and units.cpp files name
	changed

2018-07-22  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/biochemistry/{units.cpp => biochemistry_units.cpp},
	chemistry/biochemistry/{units.hpp => biochemistry_units.hpp},
	chemistry/general/atoms/{units.cpp => atoms_units.cpp},
	chemistry/general/atoms/{units.hpp => atoms_units.hpp},
	chemistry/general/matter/{units.hpp => matter_units.hpp},
	chemistry/general/substance/{units.cpp => substance_units.cpp},
	chemistry/general/substance/{units.hpp => substance_units.hpp},
	informatics/{units.cpp => informatics_units.cpp},
	informatics/{units.hpp => informatics_units.hpp},
	physics/astronomy/{units.cpp => astronomy_units.cpp},
	physics/astronomy/{units.hpp => astronomy_units.hpp},
	physics/electromagnetism/electricity/{units.cpp =>
	electricity_units.cpp},
	physics/electromagnetism/electricity/{units.hpp =>
	electricity_units.hpp},
	physics/electromagnetism/hardware/{units.cpp =>
	hardware_units.cpp}, physics/electromagnetism/hardware/{units.hpp
	=> hardware_units.hpp},
	physics/electromagnetism/magnetism/{units.cpp =>
	magnetism_units.cpp}, physics/electromagnetism/magnetism/{units.hpp
	=> magnetism_units.hpp}, physics/mechanics/dynamics/{units.cpp =>
	dynamics_units.cpp}, physics/mechanics/dynamics/{units.hpp =>
	dynamics_units.hpp}, physics/mechanics/fluid_dynamics/{units.cpp =>
	fluid_dynamics_units.cpp},
	physics/mechanics/fluid_dynamics/{units.hpp =>
	fluid_dynamics_units.hpp}, physics/mechanics/kinematics/{units.cpp
	=> kinematics_units.cpp}, physics/mechanics/kinematics/{units.hpp
	=> kinematics_units.hpp}, physics/mechanics/space/{units.cpp =>
	space_units.cpp}, physics/mechanics/space/{units.hpp =>
	space_units.hpp}, physics/thermodynamics/{units.cpp =>
	thermodynamics_units.cpp}, physics/thermodynamics/{units.hpp =>
	thermodynamics_units.hpp}, physics/waves/acoustics/{units.cpp =>
	acoustics_units.cpp}, physics/waves/acoustics/{units.hpp =>
	acoustics_units.hpp}, physics/waves/optics/{units.cpp =>
	optics_units.cpp}, physics/waves/optics/{units.hpp =>
	optics_units.hpp}, physics/waves/radiometry/{units.cpp =>
	radiometry_units.cpp}, physics/waves/radiometry/{units.hpp =>
	radiometry_units.hpp}, physics/waves/{units.cpp =>
	waves_units.cpp}, physics/waves/{units.hpp => waves_units.hpp}: unit
	files renamed

2018-07-22  Ismael Correa <ismael.correa.castro@gmail.com>

	* TODO - units, meca numbers, fields.md, TODO biology.md, TODO
	chemistry.md, TODO math.md, TODO physics.md, TODO.md: Actual TODO
	files

2017-11-12  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.cpp: atom class now displays without
	[]

2017-11-12  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.cpp,
	chemistry/general/atoms/atom.hpp: atom class getters for static
	properties implemented with reference in order to improve
	performance. to_string() functions for some enum classes created in
	order to display them as strings

2017-11-12  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/units.cpp,
	chemistry/general/atoms/units.hpp: cas_number class display()
	function implemented

2017-11-12  Ismael Correa <ismael.correa.castro@gmail.com>

	* math/topology/line_3d.hpp.save-failed: hpp file that was
	duplicated by mistake deleted

2017-11-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atoms_ac.cpp,
	chemistry/general/atoms/atoms_ac.hpp,
	chemistry/general/atoms/atoms_ia.cpp,
	chemistry/general/atoms/atoms_ia.hpp,
	chemistry/general/atoms/atoms_ib.cpp,
	chemistry/general/atoms/atoms_ib.hpp,
	chemistry/general/atoms/atoms_iia.cpp,
	chemistry/general/atoms/atoms_iia.hpp,
	chemistry/general/atoms/atoms_iib.cpp,
	chemistry/general/atoms/atoms_iib.hpp,
	chemistry/general/atoms/atoms_iiia.cpp,
	chemistry/general/atoms/atoms_iiia.hpp,
	chemistry/general/atoms/atoms_iiib.cpp,
	chemistry/general/atoms/atoms_iiib.hpp,
	chemistry/general/atoms/atoms_iva.cpp,
	chemistry/general/atoms/atoms_iva.hpp,
	chemistry/general/atoms/atoms_ivb.cpp,
	chemistry/general/atoms/atoms_ivb.hpp,
	chemistry/general/atoms/atoms_la.cpp,
	chemistry/general/atoms/atoms_la.hpp,
	chemistry/general/atoms/atoms_va.cpp,
	chemistry/general/atoms/atoms_va.hpp,
	chemistry/general/atoms/atoms_vb.cpp,
	chemistry/general/atoms/atoms_vb.hpp,
	chemistry/general/atoms/atoms_via.cpp,
	chemistry/general/atoms/atoms_via.hpp,
	chemistry/general/atoms/atoms_vib.cpp,
	chemistry/general/atoms/atoms_vib.hpp,
	chemistry/general/atoms/atoms_viia.cpp,
	chemistry/general/atoms/atoms_viia.hpp,
	chemistry/general/atoms/atoms_viib.cpp,
	chemistry/general/atoms/atoms_viib.hpp,
	chemistry/general/atoms/atoms_viiia.cpp,
	chemistry/general/atoms/atoms_viiia.hpp,
	chemistry/general/atoms/atoms_viiib.cpp,
	chemistry/general/atoms/atoms_viiib.hpp: chemistry atom static
	properties implemented without constexpr in order to avoid some bugs

2017-11-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/prefix.cpp: μ of micro prefix now is
	displayed correctly

2017-10-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.cpp,
	chemistry/general/atoms/atom.hpp,
	chemistry/general/molecules/molecule.cpp,
	chemistry/general/molecules/molecule.hpp,
	chemistry/general/substance/units.cpp,
	chemistry/general/substance/units.hpp,
	informatics/graphical/color.cpp, informatics/graphical/color.hpp,
	math/linear_algebra/matrix.hpp, math/number/angle_number.cpp,
	math/number/angle_number.hpp, math/number/lab_number.cpp,
	math/number/lab_number.hpp, math/number/undefined_number.hpp,
	math/number/unit_number.cpp, math/number/unit_number.hpp,
	math/topology/figure_2d/circle.cpp,
	math/topology/figure_2d/circle.hpp,
	math/topology/figure_2d/figure_2d.cpp,
	math/topology/figure_2d/figure_2d.hpp,
	math/topology/figure_2d/polygon.cpp,
	math/topology/figure_2d/polygon.hpp, math/topology/line_2d.cpp,
	math/topology/line_2d.hpp, math/topology/line_3d.cpp,
	math/topology/line_3d.hpp, math/topology/point_2d.cpp,
	math/topology/point_2d.hpp, math/topology/point_3d.cpp,
	math/topology/point_3d.hpp, physics/basic/units/abbreviation.cpp,
	physics/basic/units/conversion.cpp,
	physics/basic/units/dimension_abstract.cpp,
	physics/basic/units/dimension_abstract.hpp,
	physics/basic/units/dimension_container.cpp,
	physics/basic/units/dimension_container.hpp,
	physics/basic/units/unit.cpp, physics/basic/units/unit.hpp,
	physics/basic/units/unit_abbreviation.cpp,
	physics/basic/units/unit_basic.cpp,
	physics/basic/units/base_units.hpp,
	physics/basic/units/vector_unit.cpp,
	physics/basic/units/vector_unit.hpp: All wstring and related classes
	have been changed to string and related classes in order to use only
	UTF8. Also, vectors now are well displayed with their angle
	character

2017-10-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/substance/substance.hpp: substance now includes
	some headers

2017-10-18  Ismael Correa <ismael.correa.castro@gmail.com>

	* TODO.md: New tasks update

2017-10-10  Ismael Correa <ismael.correa.castro@gmail.com>

	* biology/dna/dna.cpp, biology/dna/dna.hpp,
	chemistry/general/molecules/molecule.hpp: is_cyclical() and
	is_acyclical() member-functions of the dna class

2017-10-09  Ismael Correa <ismael.correa.castro@gmail.com>

	* biology/dna/dna.cpp, biology/dna/dna.hpp,
	biology/dna/nitrogenous_base.cpp, biology/dna/nitrogenous_base.hpp,
	chemistry/general/atoms/datom.cpp,
	chemistry/general/atoms/datom.hpp,
	chemistry/general/molecules/atomic_bond.cpp,
	chemistry/general/molecules/atomic_bond.hpp,
	chemistry/general/molecules/bit_molecule.cpp,
	chemistry/general/molecules/chemical_reaction.cpp,
	chemistry/general/molecules/normal_molecule.cpp,
	chemistry/general/molecules/normal_molecule.hpp,
	chemistry/general/substance/substance.hpp,
	informatics/graphical/color.cpp, informatics/graphical/color.hpp,
	math/linear_algebra/matrix.hpp, math/number/angle_number.cpp,
	math/number/angle_number.hpp, math/number/lab_number.cpp,
	math/number/lab_number.hpp, math/number/undefined_number.hpp,
	math/topology/coordinates/cylindrical_coordinates.cpp,
	math/topology/coordinates/cylindrical_coordinates.hpp,
	math/topology/coordinates/directional_coordinates.cpp,
	math/topology/coordinates/directional_coordinates.hpp,
	math/topology/coordinates/hyper_spherical_coordinates.cpp,
	math/topology/coordinates/hyper_spherical_coordinates.hpp,
	math/topology/coordinates/polar_coordinates.cpp,
	math/topology/coordinates/polar_coordinates.hpp,
	math/topology/coordinates/spherical_coordinates.cpp,
	math/topology/coordinates/spherical_coordinates.hpp,
	math/topology/direction.cpp, math/topology/direction.hpp,
	math/topology/figure_2d/square.cpp,
	math/topology/figure_2d/square.hpp,
	physics/basic/units/auto_scalar.cpp,
	physics/basic/units/auto_scalar.hpp,
	physics/basic/units/auto_unit.cpp,
	physics/basic/units/auto_unit.hpp,
	physics/basic/units/auto_vector.cpp,
	physics/basic/units/auto_vector.hpp,
	physics/basic/units/conversion.cpp,
	physics/basic/units/conversion.hpp,
	physics/basic/units/dimension.cpp,
	physics/basic/units/scalar_unit.hpp,
	physics/basic/units/vector_unit.cpp,
	physics/basic/units/vector_unit.hpp,
	physics/quantical/particles/electron.cpp,
	physics/quantical/particles/electron.hpp: inline functions and
	default constructor added to some classes in order to improve the
	code

2017-10-09  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/biochemistry/units.cpp,
	chemistry/biochemistry/units.hpp, chemistry/general/atoms/atom.hpp,
	chemistry/general/atoms/units.cpp,
	chemistry/general/atoms/units.hpp,
	chemistry/general/matter/units.hpp,
	chemistry/general/molecules/atomic_bond.hpp,
	chemistry/general/molecules/chemical_reaction.cpp,
	chemistry/general/molecules/chemical_reaction.hpp,
	chemistry/general/substance/substance.hpp,
	chemistry/general/substance/units.cpp,
	chemistry/general/substance/units.hpp, informatics/units.cpp,
	informatics/units.hpp, math/number/angle_number.hpp,
	math/topology/figure_2d/circle.cpp,
	math/topology/figure_2d/figure_2d.hpp,
	math/topology/figure_2d/linear_figure_2d.cpp,
	math/topology/figure_2d/linear_figure_2d.hpp,
	math/topology/figure_2d/parallelogram.cpp,
	math/topology/line_2d.cpp, math/topology/line_2d.hpp,
	math/topology/line_3d.cpp, math/topology/line_3d.hpp,
	math/topology/point_2d.cpp, math/topology/point_2d.hpp,
	math/topology/point_3d.cpp, math/topology/point_3d.hpp,
	physics/astronomy/units.cpp, physics/astronomy/units.hpp,
	physics/basic/units/abbreviation.cpp,
	physics/basic/units/abbreviation.hpp,
	physics/basic/units/auto_scalar.cpp,
	physics/basic/units/auto_scalar.hpp,
	physics/basic/units/auto_unit.cpp,
	physics/basic/units/auto_unit.hpp,
	physics/basic/units/auto_vector.cpp,
	physics/basic/units/auto_vector.hpp,
	physics/basic/units/conversion.cpp,
	physics/basic/units/conversion.hpp,
	physics/basic/units/dimension.cpp,
	physics/basic/units/dimension.hpp,
	physics/basic/units/dimension_abstract.cpp,
	physics/basic/units/dimension_abstract.hpp,
	physics/basic/units/dimension_container.cpp,
	physics/basic/units/dimension_container.hpp,
	physics/basic/units/prefix.cpp, physics/basic/units/prefix.hpp,
	physics/basic/units/scalar_unit.cpp,
	physics/basic/units/scalar_unit.hpp, physics/basic/units/unit.cpp,
	physics/basic/units/unit.hpp,
	physics/basic/units/unit_abbreviation.cpp,
	physics/basic/units/unit_abbreviation.hpp,
	physics/basic/units/unit_basic.cpp,
	physics/basic/units/base_units.hpp,
	physics/basic/units/vector_unit.cpp,
	physics/basic/units/vector_unit.hpp,
	physics/electromagnetism/electricity/units.cpp,
	physics/electromagnetism/electricity/units.hpp,
	physics/electromagnetism/hardware/units.cpp,
	physics/electromagnetism/hardware/units.hpp,
	physics/electromagnetism/magnetism/units.cpp,
	physics/electromagnetism/magnetism/units.hpp,
	physics/mechanics/dynamics/units.cpp,
	physics/mechanics/dynamics/units.hpp,
	physics/mechanics/fluid_dynamics/units.cpp,
	physics/mechanics/fluid_dynamics/units.hpp,
	physics/mechanics/kinematics/units.cpp,
	physics/mechanics/kinematics/units.hpp,
	physics/mechanics/space/units.cpp,
	physics/mechanics/space/units.hpp,
	physics/quantical/particles/electron.cpp,
	physics/quantical/particles/electron.hpp,
	physics/quantical/particles/proton.cpp,
	physics/quantical/particles/proton.hpp,
	physics/thermodynamics/units.cpp, physics/thermodynamics/units.hpp,
	physics/waves/acoustics/units.hpp, physics/waves/optics/units.cpp,
	physics/waves/optics/units.hpp, physics/waves/radiometry/units.cpp,
	physics/waves/radiometry/units.hpp, physics/waves/units.cpp,
	physics/waves/units.hpp: namespace msci::units changed to namespace
	msci. Also, distance() function name changed to
	distance_between_points() in order to don't collide with distance
	class

2017-10-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/normal_atom.hpp: normal_atom class now has
	static_cast<> for the abs function in order to avoid a commmon
	warning of comparison between signed and unsigned integer
	expressions

2017-10-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* CHANGELOG.md, biology/dna/chromosome.cpp,
	biology/dna/chromosome.hpp, biology/dna/dna.cpp,
	biology/dna/dna.hpp, biology/dna/gene.cpp, biology/dna/gene.hpp,
	biology/dna/nitrogenous_base.cpp, biology/dna/nitrogenous_base.hpp,
	chemistry/biochemistry/units.cpp, chemistry/biochemistry/units.hpp,
	chemistry/constants.hpp, chemistry/general/atoms/atom.cpp,
	chemistry/general/atoms/atom.hpp,
	chemistry/general/atoms/atomic_orbital.cpp,
	chemistry/general/atoms/atomic_orbital.hpp,
	chemistry/general/atoms/atoms.cpp,
	chemistry/general/atoms/atoms.hpp,
	chemistry/general/atoms/atoms_ac.cpp,
	chemistry/general/atoms/atoms_ac.hpp,
	chemistry/general/atoms/atoms_ia.cpp,
	chemistry/general/atoms/atoms_ia.hpp,
	chemistry/general/atoms/atoms_ib.cpp,
	chemistry/general/atoms/atoms_ib.hpp,
	chemistry/general/atoms/atoms_iia.cpp,
	chemistry/general/atoms/atoms_iia.hpp,
	chemistry/general/atoms/atoms_iib.cpp,
	chemistry/general/atoms/atoms_iib.hpp,
	chemistry/general/atoms/atoms_iiia.cpp,
	chemistry/general/atoms/atoms_iiia.hpp,
	chemistry/general/atoms/atoms_iiib.cpp,
	chemistry/general/atoms/atoms_iiib.hpp,
	chemistry/general/atoms/atoms_iva.cpp,
	chemistry/general/atoms/atoms_iva.hpp,
	chemistry/general/atoms/atoms_ivb.cpp,
	chemistry/general/atoms/atoms_ivb.hpp,
	chemistry/general/atoms/atoms_la.cpp,
	chemistry/general/atoms/atoms_la.hpp,
	chemistry/general/atoms/atoms_va.cpp,
	chemistry/general/atoms/atoms_va.hpp,
	chemistry/general/atoms/atoms_vb.cpp,
	chemistry/general/atoms/atoms_vb.hpp,
	chemistry/general/atoms/atoms_via.cpp,
	chemistry/general/atoms/atoms_via.hpp,
	chemistry/general/atoms/atoms_vib.cpp,
	chemistry/general/atoms/atoms_vib.hpp,
	chemistry/general/atoms/atoms_viia.cpp,
	chemistry/general/atoms/atoms_viia.hpp,
	chemistry/general/atoms/atoms_viib.cpp,
	chemistry/general/atoms/atoms_viib.hpp,
	chemistry/general/atoms/atoms_viiia.cpp,
	chemistry/general/atoms/atoms_viiia.hpp,
	chemistry/general/atoms/atoms_viiib.cpp,
	chemistry/general/atoms/atoms_viiib.hpp,
	chemistry/general/atoms/datom.cpp,
	chemistry/general/atoms/datom.hpp,
	chemistry/general/atoms/datoms_ia.hpp,
	chemistry/general/atoms/electron_cloud.hpp,
	chemistry/general/atoms/normal_atom.hpp,
	chemistry/general/atoms/units.cpp,
	chemistry/general/atoms/units.hpp,
	chemistry/general/matter/units.hpp,
	chemistry/general/molecules/atomic_bond.cpp,
	chemistry/general/molecules/atomic_bond.hpp,
	chemistry/general/molecules/atomic_group.cpp,
	chemistry/general/molecules/atomic_group.hpp,
	chemistry/general/molecules/bit_molecule.cpp,
	chemistry/general/molecules/bit_molecule.hpp,
	chemistry/general/molecules/chemical_reaction.cpp,
	chemistry/general/molecules/chemical_reaction.hpp,
	chemistry/general/molecules/molecule.cpp,
	chemistry/general/molecules/molecule.hpp,
	chemistry/general/molecules/normal_molecule.cpp,
	chemistry/general/molecules/normal_molecule.hpp,
	chemistry/general/substance/substance.hpp,
	chemistry/general/substance/substance_ia.hpp,
	chemistry/general/substance/units.cpp,
	chemistry/general/substance/units.hpp,
	chemistry/laboratory/analysis/crystallograph.hpp,
	chemistry/laboratory/analysis/spectrometer.hpp,
	informatics/graphical/color.cpp, informatics/graphical/color.hpp,
	informatics/units.cpp, informatics/units.hpp, math/constants.hpp,
	math/linear_algebra/matrix.hpp, math/number/angle_number.cpp,
	math/number/angle_number.hpp, math/number/lab_number.cpp,
	math/number/lab_number.hpp, math/number/perfect_number.hpp,
	math/number/undefined_number.hpp, math/number/unit_number.cpp,
	math/number/unit_number.hpp,
	math/topology/coordinates/cartesian_coordinates_2d.cpp,
	math/topology/coordinates/cartesian_coordinates_2d.hpp,
	math/topology/coordinates/cartesian_coordinates_3d.cpp,
	math/topology/coordinates/cartesian_coordinates_3d.hpp,
	math/topology/coordinates/coordinates_1d.cpp,
	math/topology/coordinates/coordinates_1d.hpp,
	math/topology/coordinates/coordinates_2d.cpp,
	math/topology/coordinates/coordinates_2d.hpp,
	math/topology/coordinates/coordinates_3d.cpp,
	math/topology/coordinates/coordinates_3d.hpp,
	math/topology/coordinates/coordinates_nd.cpp,
	math/topology/coordinates/coordinates_nd.hpp,
	math/topology/coordinates/cylindrical_coordinates.cpp,
	math/topology/coordinates/cylindrical_coordinates.hpp,
	math/topology/coordinates/directional_coordinates.cpp,
	math/topology/coordinates/directional_coordinates.hpp,
	math/topology/coordinates/hyper_spherical_coordinates.cpp,
	math/topology/coordinates/hyper_spherical_coordinates.hpp,
	math/topology/coordinates/polar_coordinates.cpp,
	math/topology/coordinates/polar_coordinates.hpp,
	math/topology/coordinates/spherical_coordinates.cpp,
	math/topology/coordinates/spherical_coordinates.hpp,
	math/topology/direction.cpp, math/topology/direction.hpp,
	math/topology/figure_2d/circle.cpp,
	math/topology/figure_2d/circle.hpp,
	math/topology/figure_2d/figure_2d.cpp,
	math/topology/figure_2d/figure_2d.hpp,
	math/topology/figure_2d/irregular_polygon.cpp,
	math/topology/figure_2d/irregular_polygon.hpp,
	math/topology/figure_2d/linear_figure_2d.cpp,
	math/topology/figure_2d/linear_figure_2d.hpp,
	math/topology/figure_2d/parallelogram.cpp,
	math/topology/figure_2d/parallelogram.hpp,
	math/topology/figure_2d/polygon.cpp,
	math/topology/figure_2d/polygon.hpp,
	math/topology/figure_2d/spatial_figure.hpp,
	math/topology/figure_2d/square.cpp,
	math/topology/figure_2d/square.hpp,
	math/topology/figure_3d/figure_3d.cpp,
	math/topology/figure_3d/figure_3d.hpp, math/topology/line_2d.cpp,
	math/topology/line_2d.hpp, math/topology/line_3d.cpp,
	math/topology/line_3d.hpp, math/topology/point_2d.cpp,
	math/topology/point_2d.hpp, math/topology/point_3d.cpp,
	math/topology/point_3d.hpp, math/topology/topology.hpp,
	physics/astronomy/units.cpp, physics/astronomy/units.hpp,
	physics/basic/units/abbreviation.cpp,
	physics/basic/units/abbreviation.hpp,
	physics/basic/units/auto_scalar.cpp,
	physics/basic/units/auto_scalar.hpp,
	physics/basic/units/auto_unit.cpp,
	physics/basic/units/auto_unit.hpp,
	physics/basic/units/auto_vector.cpp,
	physics/basic/units/auto_vector.hpp,
	physics/basic/units/conversion.cpp,
	physics/basic/units/conversion.hpp,
	physics/basic/units/dimension.cpp,
	physics/basic/units/dimension.hpp,
	physics/basic/units/dimension_abstract.cpp,
	physics/basic/units/dimension_abstract.hpp,
	physics/basic/units/dimension_container.cpp,
	physics/basic/units/dimension_container.hpp,
	physics/basic/units/prefix.cpp, physics/basic/units/prefix.hpp,
	physics/basic/units/scalar_unit.cpp,
	physics/basic/units/scalar_unit.hpp, physics/basic/units/unit.cpp,
	physics/basic/units/unit.hpp,
	physics/basic/units/unit_abbreviation.cpp,
	physics/basic/units/unit_abbreviation.hpp,
	physics/basic/units/unit_basic.cpp,
	physics/basic/units/base_units.hpp,
	physics/basic/units/vector_unit.cpp,
	physics/basic/units/vector_unit.hpp,
	physics/electromagnetism/electricity/units.cpp,
	physics/electromagnetism/electricity/units.hpp,
	physics/electromagnetism/hardware/units.cpp,
	physics/electromagnetism/hardware/units.hpp,
	physics/electromagnetism/magnetism/units.cpp,
	physics/electromagnetism/magnetism/units.hpp,
	physics/mechanics/dynamics/units.cpp,
	physics/mechanics/dynamics/units.hpp,
	physics/mechanics/fluid_dynamics/units.cpp,
	physics/mechanics/fluid_dynamics/units.hpp,
	physics/mechanics/kinematics/units.cpp,
	physics/mechanics/kinematics/units.hpp,
	physics/mechanics/space/units.cpp,
	physics/mechanics/space/units.hpp,
	physics/quantical/particles/electron.cpp,
	physics/quantical/particles/electron.hpp,
	physics/quantical/particles/proton.cpp,
	physics/quantical/particles/proton.hpp,
	physics/thermodynamics/units.cpp, physics/thermodynamics/units.hpp,
	physics/waves/acoustics/units.hpp, physics/waves/optics/units.cpp,
	physics/waves/optics/units.hpp, physics/waves/radiometry/units.cpp,
	physics/waves/radiometry/units.hpp, physics/waves/units.cpp,
	physics/waves/units.hpp: namespaces physics, chemistry, biology,
	math and informatics name changed to the general namespace msci

2017-10-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.hpp,
	chemistry/general/atoms/atoms_ac.hpp,
	chemistry/general/atoms/atoms_ia.hpp,
	chemistry/general/atoms/atoms_ib.hpp,
	chemistry/general/atoms/atoms_iia.hpp,
	chemistry/general/atoms/atoms_iib.hpp,
	chemistry/general/atoms/atoms_iiia.hpp,
	chemistry/general/atoms/atoms_iiib.hpp,
	chemistry/general/atoms/atoms_iva.hpp,
	chemistry/general/atoms/atoms_ivb.hpp,
	chemistry/general/atoms/atoms_la.hpp,
	chemistry/general/atoms/atoms_va.hpp,
	chemistry/general/atoms/atoms_vb.hpp,
	chemistry/general/atoms/atoms_via.hpp,
	chemistry/general/atoms/atoms_vib.hpp,
	chemistry/general/atoms/atoms_viia.hpp,
	chemistry/general/atoms/atoms_viib.hpp,
	chemistry/general/atoms/atoms_viiia.hpp,
	chemistry/general/atoms/atoms_viiib.hpp: constexpr added to
	primitive types in order to have a better performance

2017-10-07  Ismael Correa <ismael.correa.castro@gmail.com>

	* biology/dna/chromosome.cpp, biology/dna/chromosome.hpp,
	biology/dna/dna.cpp, biology/dna/dna.hpp, biology/dna/gene.cpp,
	biology/dna/gene.hpp, biology/dna/nitrogenous_base.cpp,
	biology/dna/nitrogenous_base.hpp,
	chemistry/general/atoms/atoms.cpp,
	chemistry/general/atoms/atoms.hpp,
	chemistry/general/molecules/atomic_bond.cpp,
	chemistry/general/molecules/atomic_bond.hpp,
	chemistry/general/molecules/molecule.cpp,
	chemistry/general/molecules/molecule.hpp,
	chemistry/general/molecules/normal_molecule.cpp,
	chemistry/general/molecules/normal_molecule.hpp,
	physics/basic/units/abbreviation.cpp,
	physics/basic/units/abbreviation.hpp,
	physics/basic/units/auto_scalar.cpp,
	physics/basic/units/auto_scalar.hpp,
	physics/basic/units/auto_unit.cpp,
	physics/basic/units/auto_unit.hpp,
	physics/basic/units/auto_vector.cpp,
	physics/basic/units/auto_vector.hpp,
	physics/basic/units/conversion.cpp,
	physics/basic/units/conversion.hpp,
	physics/basic/units/dimension.cpp,
	physics/basic/units/dimension.hpp, physics/basic/units/prefix.cpp,
	physics/basic/units/prefix.hpp,
	physics/basic/units/scalar_unit.cpp,
	physics/basic/units/scalar_unit.hpp, physics/basic/units/unit.cpp,
	physics/basic/units/unit.hpp, physics/basic/units/unit_basic.cpp,
	physics/basic/units/vector_unit.cpp,
	physics/basic/units/vector_unit.hpp: functions that have an string
	parameter that can be const string& now are const string& in order
	to improve performance

2017-10-07  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry.hpp: chemistry.hpp header created to use all chemistry
	classes

2017-10-07  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/datom.cpp,
	chemistry/general/atoms/datom.hpp,
	chemistry/general/atoms/datoms_ia.hpp,
	chemistry/general/molecules/atomic_bond.hpp,
	chemistry/general/molecules/atomic_group.cpp,
	chemistry/general/molecules/atomic_group.hpp,
	chemistry/general/molecules/chemical_reaction.cpp,
	chemistry/general/molecules/chemical_reaction.hpp,
	chemistry/general/molecules/molecule.cpp,
	chemistry/general/molecules/molecule.hpp,
	chemistry/general/molecules/normal_molecule.cpp,
	chemistry/general/molecules/normal_molecule.hpp,
	chemistry/general/substance/substance_ia.hpp: big advance inside
	chemistry classes

2017-10-07  Ismael Correa <ismael.correa.castro@gmail.com>

	* spatial_math.hpp: spatial_math.hpp now includes figure_3d

2017-10-07  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_scalar.cpp,
	physics/basic/units/auto_scalar.hpp: noexcept deleted in order to
	follow new code metrics

2017-10-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/{detailed_atom.hpp => datom.hpp}: 
	detailed_atom.hpp filename changed to datom.hpp

2017-10-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* : diagram of unit classes detail ammeliorated

2017-10-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* : diagram of unit classes created

2017-09-24  Ismael Correa <ismael.correa.castro@gmail.com>

	* spatial_math.hpp: spatial_math.hpp header updated with new
	geometry classes

2017-09-24  Ismael Correa <ismael.correa.castro@gmail.com>

	* biology/dna/chromosome.cpp,
	chemistry/general/molecules/bit_molecule.cpp: dna classes fix

2017-09-24  Ismael Correa <ismael.correa.castro@gmail.com>

	* math/topology/curve_2d.cpp, math/topology/curve_2d.hpp,
	math/topology/curve_3d.cpp, math/topology/curve_3d.hpp,
	math/topology/figure_2d/circle.cpp,
	math/topology/figure_2d/circle.hpp,
	math/topology/figure_2d/figure_2d.cpp,
	math/topology/figure_2d/figure_2d.hpp,
	math/topology/figure_2d/irregular_polygon.cpp,
	math/topology/figure_2d/irregular_polygon.hpp,
	math/topology/figure_2d/linear_figure_2d.cpp,
	math/topology/figure_2d/linear_figure_2d.hpp,
	math/topology/figure_2d/parallelogram.cpp,
	math/topology/figure_2d/parallelogram.hpp,
	math/topology/figure_2d/polygon.cpp,
	math/topology/figure_2d/polygon.hpp,
	math/topology/figure_3d/figure_3d.cpp,
	math/topology/figure_3d/figure_3d.hpp, math/topology/line_2d.cpp,
	math/topology/line_2d.hpp, math/topology/line_3d.cpp,
	math/topology/line_3d.hpp, math/topology/line_3d.hpp.save-failed,
	math/topology/point_2d.cpp, math/topology/point_2d.hpp,
	math/topology/point_3d.cpp, math/topology/point_3d.hpp: math
	geometry figures and related classes implemented majoritarily

2017-09-23  Ismael Correa <ismael.correa.castro@gmail.com>

	* meca_numbers.hpp, spatial_math.hpp: headers for math classes added

2017-09-23  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.cpp,
	chemistry/general/atoms/atom.hpp,
	chemistry/general/atoms/atomic_orbital.cpp,
	chemistry/general/atoms/atomic_orbital.hpp,
	chemistry/general/atoms/atoms.cpp,
	chemistry/general/atoms/normal_atom.hpp,
	chemistry/general/molecules/atomic_bond.cpp,
	chemistry/general/molecules/molecule.cpp,
	math/topology/coordinates/coordinates_3d.cpp,
	math/topology/coordinates/coordinates_nd.hpp,
	math/topology/coordinates/directional_coordinates.cpp,
	math/topology/coordinates/hyper_spherical_coordinates.cpp,
	math/topology/coordinates/hyper_spherical_coordinates.hpp,
	math/topology/direction.cpp, math/topology/figure_2d/polygon.cpp,
	physics/basic/units/auto_unit.cpp,
	physics/basic/units/auto_unit.hpp,
	physics/basic/units/dimension.cpp,
	physics/basic/units/vector_unit.cpp: magickscience updated in order
	to don't have warnings when compiling. A big amount of code updated
	for that purpose. Now there are very few warnings

2017-09-23  Ismael Correa <ismael.correa.castro@gmail.com>

	* biology/dna/chromosome.cpp, biology/dna/chromosome.hpp,
	biology/dna/dna.cpp, biology/dna/dna.hpp, biology/dna/gene.cpp,
	biology/dna/gene.hpp, biology/dna/nitrogenous_base.hpp: dna classes
	created, with dna class, chromosome class and gene class.
	nitrogenous_base class updated

2017-09-22  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/molecules/bit_molecule.hpp: class bit_molecule
	created

2017-09-22  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_unit.cpp,
	physics/basic/units/auto_unit.hpp: auto_unit class now has some
	operators it was lacking. Bug fixed

2017-09-21  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_vector.hpp: bug fixed to allow
	MagickScience to compile with clang

2017-09-14  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/molecules/molecule.cpp: molecule class
	member-function get_canonical_formula() bug fixed

2017-09-14  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/molecules/normal_molecule.cpp: normal_molecule
	class now has double bonds and triple bonds inside the constructor
	and inside the save() function

2017-09-14  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/molecules/atomic_bond.hpp: class atomib_bond
	weight member-functions created

2017-09-14  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.cpp,
	chemistry/general/atoms/atom.hpp: atom class get_bond_of(const
	atom&) member-function created

2017-09-13  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.cpp, physics/basic/units/unit.hpp: 
	member-function display_dimensions() of class unit implemented

2017-09-12  Ismael Correa <ismael.correa.castro@gmail.com>

	* math/number/angle_number.cpp: class angle_number function
	empty_dimensions() name updated to has_empty_dimensions()

2017-09-12  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_unit.hpp, physics/basic/units/unit.cpp,
	physics/basic/units/unit.hpp, physics/basic/units/vector_unit.cpp: 
	class unit member-function equal_dimensions() changed to
	has_dimensions() and empty_dimensions() changed to
	has_empty_dimensions()

2017-09-12  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit_basic.cpp,
	physics/basic/units/base_units.hpp: bug fixed. _angle and
	_solid_angle literals removed

2017-09-12  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/abbreviation.cpp,
	physics/basic/units/abbreviation.hpp,
	physics/basic/units/dimension.cpp,
	physics/basic/units/dimension.hpp,
	physics/basic/units/dimension_abstract.cpp,
	physics/basic/units/dimension_abstract.hpp: const prefix& changed to
	prefix& in order to prevent a bug. Commit reverted

2017-09-12  Ismael Correa <ismael.correa.castro@gmail.com>

	* math/number/unit_number.cpp: unit_number message updated to a best
	explained one

2017-09-12  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/abbreviation.cpp,
	physics/basic/units/abbreviation.hpp,
	physics/basic/units/dimension.cpp,
	physics/basic/units/dimension.hpp,
	physics/basic/units/dimension_abstract.cpp,
	physics/basic/units/dimension_abstract.hpp: prefix& changed inside
	constructors by const prefix&

2017-09-12  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit_basic.cpp,
	physics/basic/units/base_units.hpp: angle and solid_angle unit
	classes removed in order to used angle_number instead

2017-09-12  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.cpp, physics/basic/units/unit.hpp: unit
	class member-function equal_dimensions(dimension_symbol) deleted in
	order to use equal_dimensions(string) instead

2017-09-12  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_scalar.cpp,
	physics/basic/units/auto_scalar.hpp,
	physics/basic/units/auto_unit.cpp,
	physics/basic/units/auto_unit.hpp,
	physics/basic/units/auto_vector.cpp,
	physics/basic/units/auto_vector.hpp,
	physics/basic/units/scalar_unit.cpp,
	physics/basic/units/scalar_unit.hpp, physics/basic/units/unit.cpp,
	physics/basic/units/unit.hpp, physics/basic/units/unit_basic.cpp,
	physics/basic/units/vector_unit.cpp,
	physics/basic/units/vector_unit.hpp: Constructors of units classes
	improved and updated. Move assignment and copy assignment also
	improved. Constructors and assignments for units are finished

2017-09-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.cpp,
	chemistry/general/atoms/atom.hpp,
	chemistry/general/atoms/normal_atom.hpp,
	chemistry/general/molecules/molecule.hpp: TODO tasks deleted from
	source files in order to have a better order. Deprecated function
	get_atom deleted

2017-09-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_unit.cpp,
	physics/basic/units/auto_unit.hpp, physics/basic/units/unit.cpp,
	physics/basic/units/unit.hpp: move constructor implemented and move
	assingment improved for unit and auto_unit classes

2017-09-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_unit.cpp,
	physics/basic/units/auto_unit.hpp, physics/basic/units/unit.cpp,
	physics/basic/units/unit.hpp: class unit and class auto_unit
	constructors and assignments improved, initializing values inside
	the initializer-list, returning reference for operators. Also, the
	clone() function has been implemented

2017-09-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/normal_atom.hpp: 
	normal_atom::is_factible() function bug corrected

2017-09-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.cpp,
	chemistry/general/atoms/atom.hpp: member-function
	atom::is_valence_full() ready for atoms of group a

2017-09-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/normal_atom.hpp,
	chemistry/general/molecules/molecule.cpp,
	chemistry/general/molecules/molecule.hpp: is_factible() functions of
	atom and molecule class created

2017-09-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/molecules/molecule.hpp,
	chemistry/general/molecules/normal_molecule.cpp,
	chemistry/general/molecules/normal_molecule.hpp: normal_molecule
	constructor now accepts direct xml, additionally as xml files, to
	initialize molecules. Constructor with vector<shared_ptr<atom>> and
	vector<shared_ptr<atomib_bond>> has also been created. Bug with the
	constructor that was duplicating atomic_bonds has been fixed.
	bonds_graph has been deleted

2017-09-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/molecules/molecule.hpp,
	chemistry/general/molecules/normal_molecule.cpp,
	chemistry/general/molecules/normal_molecule.hpp: save() function for
	molecules created to allow to store the created molecules in the
	hard-drive. normal_molecule(string) constructor bug with bonds
	solved

2017-09-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/molecules/atomic_bond.hpp: atomic_bond class now
	has all his functions implemented. get_atom1() and get_atom2()
	functions created

2017-09-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.cpp,
	chemistry/general/atoms/atom.hpp,
	chemistry/general/atoms/normal_atom.hpp: atom class and normal_atom
	class now has bonded_to() function, add_bond() function is finished
	and file_format() function has been also defined and implemented

2017-09-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.hpp,
	chemistry/general/atoms/normal_atom.hpp: atom::is_exotic()
	member-function created for the cases of muons

2017-09-07  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/molecules/atomic_bond.cpp,
	chemistry/general/molecules/molecule.cpp,
	chemistry/general/molecules/molecule.hpp,
	chemistry/general/molecules/normal_molecule.cpp,
	chemistry/general/molecules/normal_molecule.hpp: molecules released!
	they can be created by special xml files. They can contain any
	number of atoms, as desired, they are ready to use

2017-09-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atoms.cpp,
	chemistry/general/atoms/atoms.hpp: create_atom() function to be
	available to create atoms. It includes all atoms of the periodic
	table, already created

2017-09-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atoms_iiib.hpp: bug with atoms of IIIB
	group solved

2017-09-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atomic_orbital.cpp,
	chemistry/general/atoms/atomic_orbital.hpp: atomic_orbital class
	added again, it was a deprecated class today deleted. This class is
	actual and will be used for detailed_atoms classes

2017-09-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.cpp,
	chemistry/general/atoms/atom.hpp,
	chemistry/general/molecules/atomic_bond.cpp,
	chemistry/general/molecules/atomic_bond.hpp: some bugs fixed with
	atom and atomic_bond class

2017-09-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/molecules/atomic_bond.hpp: member-function
	atomic_bond::get_atomic_bond_type() created

2017-09-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/compounds [deprecated]/atom.cpp,
	chemistry/general/compounds [deprecated]/atom.hpp,
	chemistry/general/compounds [deprecated]/atoms_ac.hpp,
	chemistry/general/compounds [deprecated]/atoms_ia.cpp,
	chemistry/general/compounds [deprecated]/atoms_ia.hpp,
	chemistry/general/compounds [deprecated]/atoms_ib.hpp,
	chemistry/general/compounds [deprecated]/atoms_iia.cpp,
	chemistry/general/compounds [deprecated]/atoms_iia.hpp,
	chemistry/general/compounds [deprecated]/atoms_iib.hpp,
	chemistry/general/compounds [deprecated]/atoms_iiia.hpp,
	chemistry/general/compounds [deprecated]/atoms_iiib.hpp,
	chemistry/general/compounds [deprecated]/atoms_iva.hpp,
	chemistry/general/compounds [deprecated]/atoms_ivb.hpp,
	chemistry/general/compounds [deprecated]/atoms_la.hpp,
	chemistry/general/compounds [deprecated]/atoms_va.hpp,
	chemistry/general/compounds [deprecated]/atoms_vb.hpp,
	chemistry/general/compounds [deprecated]/atoms_via.hpp,
	chemistry/general/compounds [deprecated]/atoms_vib.hpp,
	chemistry/general/compounds [deprecated]/atoms_viia.hpp,
	chemistry/general/compounds [deprecated]/atoms_viib.hpp,
	chemistry/general/compounds [deprecated]/atoms_viiia.hpp,
	chemistry/general/compounds [deprecated]/atoms_viiib.hpp,
	chemistry/general/compounds [deprecated]/bonds/bonds_ia.hpp,
	chemistry/general/compounds [deprecated]/bound.cpp,
	chemistry/general/compounds [deprecated]/bound.hpp,
	chemistry/general/compounds [deprecated]/compound.cpp,
	chemistry/general/compounds [deprecated]/compound.hpp,
	chemistry/general/compounds [deprecated]/orbital.cpp,
	chemistry/general/compounds [deprecated]/orbital.hpp,
	chemistry/general/compounds [deprecated]/units.cpp,
	chemistry/general/compounds [deprecated]/units.hpp: deleted
	deprecated files

2017-09-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* : commit 7c4f731bd5e37a3b912953b006e0054eae0862eb Author: Ismael
	Correa <ismael.correa.castro@gmail.com> Date:   Wed Sep 6 19:25:25
	2017 -0300

2017-09-06  Ismael Correa Castro <ismael.correa.castro@gmail.com>

	* LICENSE: LICENSE LICENSE created! GPLv3.0 has been choiced

2017-09-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* README.md: README.md file updated

2017-09-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* CONTRIBUTING.md: CONTRIBUTING.md file created, now everyone can
	contribute to MagickScience

2017-09-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* CODE_OF_CONDUCT.md: New code of conduct for the project, in order
	to have a good climate if they appear contributors :D

2017-09-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms.hpp: atoms.hpp file included

2017-09-06  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.cpp,
	chemistry/general/atoms/atom.hpp: member-function atom::add_bond()
	created to store bonds, yet unfinished

2017-09-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/molecules/atomic_bond.cpp,
	chemistry/general/molecules/atomic_bond.hpp: atomic_bond constructor
	updated to use const-reference

2017-09-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/molecules/molecule.cpp,
	chemistry/general/molecules/molecule.hpp: molecule member-functions
	get_ionic_charge(), is_ion(), is_anion(), is_cation() and
	is_neutral() created

2017-09-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/molecules/molecule.cpp: 
	molecule::get_canonical_formula() member-function implemented

2017-09-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.cpp,
	chemistry/general/atoms/atom.hpp: same_specimen() function created
	to distinguish among different atoms but isotopes

2017-09-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.cpp: indentation of colors changed to
	the adequeate level

2017-09-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.hpp,
	chemistry/general/atoms/normal_atom.hpp: member-function
	atom::is_factible() created. It'll be useful for detailed_atoms,
	because some of them aren't factible in real life

2017-09-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atoms_ac.cpp,
	chemistry/general/atoms/atoms_ac.hpp: All atoms classes of group AC
	created with all their properties

2017-09-05  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atoms_la.cpp,
	chemistry/general/atoms/atoms_la.hpp: Lanthanide atoms classes
	created with all their properties completed

2017-09-04  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atoms_ib.cpp,
	chemistry/general/atoms/atoms_ib.hpp,
	chemistry/general/atoms/atoms_iib.cpp,
	chemistry/general/atoms/atoms_iib.hpp,
	chemistry/general/atoms/atoms_iiia.cpp,
	chemistry/general/atoms/atoms_iiia.hpp,
	chemistry/general/atoms/atoms_iiib.cpp,
	chemistry/general/atoms/atoms_iiib.hpp,
	chemistry/general/atoms/atoms_ivb.cpp,
	chemistry/general/atoms/atoms_ivb.hpp,
	chemistry/general/atoms/atoms_vb.cpp,
	chemistry/general/atoms/atoms_vb.hpp,
	chemistry/general/atoms/atoms_vib.cpp,
	chemistry/general/atoms/atoms_vib.hpp,
	chemistry/general/atoms/atoms_viib.cpp,
	chemistry/general/atoms/atoms_viib.hpp,
	chemistry/general/atoms/atoms_viiia.cpp,
	chemistry/general/atoms/atoms_viiib.cpp,
	chemistry/general/atoms/atoms_viiib.hpp: All atoms of group B
	created

2017-09-04  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.hpp: last atom symbols updated to
	their new name

2017-09-04  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atoms_iia.cpp,
	chemistry/general/atoms/atoms_iia.hpp,
	chemistry/general/atoms/atoms_iiia.cpp,
	chemistry/general/atoms/atoms_iiia.hpp,
	chemistry/general/atoms/atoms_iva.cpp,
	chemistry/general/atoms/atoms_iva.hpp,
	chemistry/general/atoms/atoms_va.cpp,
	chemistry/general/atoms/atoms_va.hpp,
	chemistry/general/atoms/atoms_via.cpp,
	chemistry/general/atoms/atoms_via.hpp,
	chemistry/general/atoms/atoms_viia.cpp,
	chemistry/general/atoms/atoms_viia.hpp,
	chemistry/general/atoms/atoms_viiia.cpp,
	chemistry/general/atoms/atoms_viiia.hpp: All atoms classes of A
	groups created

2017-09-04  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.hpp: member-function
	get_valence_number() is unfinished, it lacks the number of actinides
	and lanthanides, TODO task added

2017-09-03  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.hpp,
	chemistry/general/atoms/atoms_ia.hpp: macros added to atom.hpp

2017-09-03  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atoms_ia.cpp,
	chemistry/general/atoms/atoms_ia.hpp: atoms classes of IA group
	completed

2017-09-03  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.hpp: is_rare_earth() function created
	for atom classes. some functions of physical properties hidded in
	order to migrate them to other classes

2017-09-02  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.hpp: get_valence_number() function of
	class atom finished

2017-09-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.hpp,
	chemistry/general/atoms/atoms_ia.cpp,
	chemistry/general/atoms/atoms_ia.hpp,
	chemistry/general/atoms/normal_atom.hpp: atoms perfected.
	get_valence_number() now returns in function of the group, it's not
	a static variable. neutrons_number name changed by mass_number. Some
	properties have been moved to substances because they aren't
	inherently of atoms alone

2017-08-31  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.hpp,
	chemistry/general/atoms/atoms.hpp,
	chemistry/general/atoms/atoms_ia.cpp,
	chemistry/general/atoms/atoms_ia.hpp,
	chemistry/general/atoms/normal_atom.hpp: atom_H finished, with all
	the basic functions created working

2017-08-31  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/units.cpp,
	chemistry/general/atoms/units.hpp: cas_number class created.
	Unfinished, because patterns aren't ready, but works for the actual
	purpose

2017-08-31  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/units.cpp,
	chemistry/general/atoms/units.hpp: molar_enthalpy unit created of
	dimensions J/mol

2017-08-30  Ismael Correa <ismael.correa.castro@gmail.com>

	* math/number/angle_number.cpp: angle_number class bug fixed for abs
	function

2017-08-30  Ismael Correa <ismael.correa.castro@gmail.com>

	* TODO.md: TODO.md file that lists the tasks to do

2017-08-30  Ismael Correa <ismael.correa.castro@gmail.com>

	* math/number/angle_number.cpp, math/number/angle_number.hpp: 
	constructor of angle_number for empty units added

2017-08-30  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit_basic.cpp: time_display months added
	again

2017-08-30  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit_basic.cpp: time_display of class time now
	doesn't changes dimensions because of bug fixed, it loads faster

2017-08-30  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.cpp: operator += and operator -= of class
	unit bug solved

2017-08-30  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit_basic.cpp,
	physics/basic/units/base_units.hpp: class physics::units::time
	operator << finished for time_display and get_finish_date() function
	created, which displays the day at which the time set will end

2017-08-30  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.cpp: bug solved with comparison operators
	for different actual dimensions

2017-08-30  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.hpp: bug solved with unit_crtp class
	constructor

2017-08-30  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_unit.cpp, physics/basic/units/unit.cpp: 
	unit and auto_unit classes bugs with constructors and prefixes
	solved

2017-08-30  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_scalar.hpp,
	physics/basic/units/auto_vector.hpp,
	physics/basic/units/scalar_unit.hpp,
	physics/basic/units/vector_unit.hpp: operators of scalar_unit and
	vector_unit classes updated to support auto_scalar and auto_vector,
	bug fixed

2017-08-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.cpp: copy constructor changed to avoid an
	error with abstract function call

2017-08-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/abbreviation.cpp,
	physics/basic/units/auto_unit.cpp,
	physics/basic/units/dimension_container.cpp,
	physics/basic/units/unit.cpp: shared_ptr initialized in a better way

2017-08-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.hpp: typecast operator float() of class
	unit now is explicit in order to avoid possible bugs

2017-08-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_scalar.cpp: assignment operators of
	auto_scalar class now return *this to avoid a warning. Bug fixed

2017-08-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/dimension.hpp: static_cast changed to match
	normal syntax of the library

2017-08-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/biochemistry/units.cpp,
	chemistry/general/atoms/units.cpp,
	chemistry/general/substance/units.cpp, informatics/units.cpp,
	physics/astronomy/units.cpp,
	physics/electromagnetism/electricity/units.cpp,
	physics/electromagnetism/hardware/units.cpp,
	physics/electromagnetism/magnetism/units.cpp,
	physics/mechanics/dynamics/units.cpp,
	physics/mechanics/fluid_dynamics/units.cpp,
	physics/mechanics/kinematics/units.cpp,
	physics/mechanics/space/units.cpp,
	physics/thermodynamics/units.cpp, physics/waves/optics/units.cpp,
	physics/waves/radiometry/units.cpp, physics/waves/units.cpp: units
	paths updated to always match local file

2017-08-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/abbreviation.cpp,
	physics/basic/units/abbreviation.hpp,
	physics/basic/units/dimension.cpp,
	physics/basic/units/dimension.hpp, physics/basic/units/prefix.cpp,
	physics/basic/units/prefix.hpp: constructor inheritance added
	instead of definition of each constructor inside dimension,
	abbreviation and prefix classes

2017-08-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/vector_unit.cpp,
	physics/basic/units/vector_unit.hpp: norm() and
	angle_between_vectors() functions created for vector_unit classes

2017-08-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.cpp, physics/basic/units/unit.hpp: class
	unit now has a typecast operator float()

2017-08-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/vector_unit.cpp,
	physics/basic/units/vector_unit.hpp: same_spatial_dimensions()
	function name changed to same_nd() in order to have a more clear
	name

2017-08-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit_basic.cpp,
	physics/basic/units/base_units.hpp: angle and solid_angle literals
	added

2017-08-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/dimension.cpp,
	physics/basic/units/dimension.hpp,
	physics/basic/units/unit_basic.cpp,
	physics/basic/units/base_units.hpp: enum dimension name of angle and
	solid_angle changed to angle_symbol and solid_angle_symbol,
	respectively, in order to avoid class name collision with new angle
	and solid_angle classes created

2017-08-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit_basic.cpp: temperature class now supports
	K dimensions, and doesn't load the previous constructor

2017-08-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/dimension_abstract.cpp,
	physics/basic/units/dimension_abstract.hpp,
	physics/basic/units/unit.cpp, physics/basic/units/unit.hpp,
	physics/basic/units/base_units.hpp: inline functions added to some
	unit classes

2017-08-29  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/scalar_unit.cpp,
	physics/basic/units/scalar_unit.hpp, physics/basic/units/unit.hpp: 
	default constructors added for various unit classes

2017-08-27  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/abbreviation.cpp,
	physics/basic/units/abbreviation.hpp, physics/basic/units/unit.cpp: 
	abbreviation factors now are working, they change the value, as
	happens with minutes, hours and days

2017-08-27  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/conversion.cpp: some new names for common
	england conversions added

2017-08-27  Ismael Correa <ismael.correa.castro@gmail.com>

	* math/number/unit_number.cpp, math/number/unit_number.hpp,
	physics/basic/units/unit.cpp, physics/basic/units/unit.hpp: 
	display(int) member-function of class unit created which allows to
	change the amount of decimals to display from a unit. class
	unit_number now also can print a variable amount of decimals

2017-08-27  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.cpp, physics/basic/units/unit.hpp: copy
	constructors of unit and unit_crtp<T> created

2017-08-27  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/substance/units.cpp,
	chemistry/general/substance/units.hpp: operator << of class
	concentration specialized in displaying percentage

2017-08-27  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/substance/units.cpp: dimensions of molality
	corrected to mol/g

2017-08-27  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/abbreviation.cpp,
	physics/basic/units/abbreviation.hpp: factor changed to be a double
	in order to have clarity

2017-08-27  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.cpp: Initialization of numbers corrected
	to be the one of english numbers (it was the one of spanish numbers
	previously)

2017-08-27  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.cpp: initialization of units allowing to
	add spaces inside the number to display it clearer. Example: "10 000
	N" instead of "10000 N" for the same purpose

2017-08-27  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit_basic.cpp,
	physics/basic/units/base_units.hpp: typecast of class time to
	chrono::seconds class of the std library

2017-08-27  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/dimension.cpp,
	physics/basic/units/dimension.hpp,
	physics/basic/units/dimension_abstract.cpp,
	physics/basic/units/dimension_abstract.hpp,
	physics/basic/units/unit.cpp, physics/basic/units/unit.hpp: 
	dimensions now have a prefix_base function to specify the way to
	convert the value. dimension_byte now works properly when converting
	prefixes

2017-08-26  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/abbreviation.cpp,
	physics/basic/units/abbreviation.hpp,
	physics/basic/units/unit_abbreviation.cpp,
	physics/basic/units/unit_abbreviation.hpp: ppm and ppb abbreviations
	created with their respective literals

2017-08-26  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/substance/units.cpp,
	chemistry/general/substance/units.hpp: concentration unit for mass
	percentage, ppm and ppb

2017-08-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/substance/units.cpp: dimensions of molality
	updated

2017-08-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.cpp,
	chemistry/general/molecules/atomic_bond.cpp,
	math/topology/coordinates/cartesian_coordinates_2d.cpp,
	math/topology/coordinates/cartesian_coordinates_3d.cpp,
	math/topology/coordinates/cylindrical_coordinates.cpp: 
	member-initializer lists added to more classes

2017-08-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/dimension_abstract.cpp,
	physics/basic/units/unit.cpp: member-initializer lists added instead
	of previous initialization

2017-08-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_vector.cpp,
	physics/basic/units/auto_vector.hpp,
	physics/basic/units/vector_unit.cpp,
	physics/basic/units/vector_unit.hpp: dot_product() function
	implemented. operator * of vector_unit replaced by cross_product()
	function which is more explicative

2017-08-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_scalar.cpp,
	physics/basic/units/auto_scalar.hpp,
	physics/basic/units/scalar_unit.cpp,
	physics/basic/units/scalar_unit.hpp: new constructor of scalar_unit
	to allow to create scalar_units based only on values and dimensions

2017-08-20  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.cpp,
	chemistry/general/atoms/atom.hpp,
	chemistry/general/atoms/normal_atom.hpp,
	chemistry/general/molecules/atomic_bond.cpp,
	chemistry/general/molecules/molecule.cpp,
	chemistry/general/molecules/molecule.hpp: different fixes to atom
	and molecule classes made

2017-08-20  Ismael Correa <ismael.correa.castro@gmail.com>

	* math/topology/figure_2d/circle.cpp,
	math/topology/figure_2d/circle.hpp,
	math/topology/figure_2d/figure_2d.cpp,
	math/topology/figure_2d/figure_2d.hpp,
	math/topology/figure_2d/parallelogram.cpp,
	math/topology/figure_2d/parallelogram.hpp,
	math/topology/figure_2d/polygon.cpp,
	math/topology/figure_2d/polygon.hpp,
	math/topology/figure_2d/rectangle.cpp,
	math/topology/figure_2d/rectangle.hpp,
	math/topology/figure_2d/rhombus.cpp,
	math/topology/figure_2d/rhombus.hpp,
	math/topology/figure_2d/spatial_figure.hpp,
	math/topology/figure_2d/square.cpp,
	math/topology/figure_2d/square.hpp,
	math/topology/figure_2d/triangle.cpp,
	math/topology/figure_2d/triangle.hpp, math/topology/point_2d.cpp,
	math/topology/point_2d.hpp, math/topology/point_3d.cpp,
	math/topology/point_3d.hpp: geometric classes created. point_2d and
	point_3d classes also created. They aren't ready, and they will
	possibly wrap some geometric library using vector_units instead, in
	order to provide a good development system. Those classes can't be
	used yet

2017-08-19  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.cpp,
	chemistry/general/atoms/atom.hpp, math/constants.hpp,
	math/number/angle_number.cpp, math/number/angle_number.hpp,
	math/number/lab_number.cpp, math/number/lab_number.hpp,
	math/number/undefined_number.hpp, math/number/unit_number.cpp,
	math/number/unit_number.hpp,
	math/topology/coordinates/cartesian_coordinates_2d.cpp,
	math/topology/coordinates/cartesian_coordinates_2d.hpp,
	math/topology/coordinates/cartesian_coordinates_3d.cpp,
	math/topology/coordinates/cartesian_coordinates_3d.hpp,
	math/topology/coordinates/coordinates_1d.cpp,
	math/topology/coordinates/coordinates_1d.hpp,
	math/topology/coordinates/coordinates_2d.cpp,
	math/topology/coordinates/coordinates_2d.hpp,
	math/topology/coordinates/coordinates_3d.cpp,
	math/topology/coordinates/coordinates_3d.hpp,
	math/topology/coordinates/coordinates_nd.cpp,
	math/topology/coordinates/coordinates_nd.hpp,
	math/topology/coordinates/cylindrical_coordinates.cpp,
	math/topology/coordinates/cylindrical_coordinates.hpp,
	math/topology/coordinates/directional_coordinates.cpp,
	math/topology/coordinates/directional_coordinates.hpp,
	math/topology/coordinates/hyper_spherical_coordinates.cpp,
	math/topology/coordinates/hyper_spherical_coordinates.hpp,
	math/topology/coordinates/polar_coordinates.cpp,
	math/topology/coordinates/polar_coordinates.hpp,
	math/topology/coordinates/spherical_coordinates.cpp,
	math/topology/coordinates/spherical_coordinates.hpp,
	math/topology/direction.cpp, math/topology/direction.hpp,
	math/topology/topology.hpp, physics/basic/units/auto_scalar.cpp,
	physics/basic/units/auto_scalar.hpp,
	physics/basic/units/auto_unit.cpp,
	physics/basic/units/auto_unit.hpp,
	physics/basic/units/auto_vector.cpp,
	physics/basic/units/auto_vector.hpp,
	physics/basic/units/scalar_unit.cpp,
	physics/basic/units/scalar_unit.hpp, physics/basic/units/unit.cpp,
	physics/basic/units/unit.hpp, physics/basic/units/unit_basic.cpp,
	physics/basic/units/vector_unit.cpp,
	physics/basic/units/vector_unit.hpp: namespaces math::number and
	math::topology updated to math in order to have a best organization
	inside the code

2017-08-19  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_unit.cpp,
	physics/basic/units/conversion.cpp,
	physics/basic/units/conversion.hpp, physics/basic/units/unit.cpp: 
	conversion class updated with all england units. Also, member
	variables are now private to protect them

2017-08-18  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_scalar.hpp,
	physics/basic/units/auto_vector.cpp,
	physics/basic/units/auto_vector.hpp: vector_unit class now has
	left-hand operators + - * with scalar_unit classes

2017-08-18  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_scalar.hpp,
	physics/basic/units/auto_vector.hpp: operators of scalar_units and
	vector_units with numbers added for the left-side

2017-08-18  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_unit.hpp: operator ^ for class unit

2017-08-18  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_unit.cpp,
	physics/basic/units/auto_unit.hpp, physics/basic/units/unit.cpp: 
	initialize_real_dimensions() function for class auto_unit and
	corrections maked for initialize_dimensions() for class unit

2017-08-18  Ismael Correa <ismael.correa.castro@gmail.com>

	* math/number/angle_number.cpp, math/number/angle_number.hpp,
	math/number/lab_number.cpp, math/number/lab_number.hpp: operators +
	- * / ^ of classes angle_number and lab_number are now const

2017-08-18  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_scalar.cpp,
	physics/basic/units/auto_scalar.hpp,
	physics/basic/units/auto_vector.cpp,
	physics/basic/units/auto_vector.hpp: operators added to auto_scalar
	and auto_vector in order to select which one to use because of the
	multi-inheritance

2017-08-18  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_unit.cpp,
	physics/basic/units/dimension_container.cpp,
	physics/basic/units/dimension_container.hpp: fucntion
	get_dimensions_match() of auto_unit class finished

2017-08-18  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_unit.cpp, physics/basic/units/unit.cpp: 
	operator = for auto_unit and unit classes now check real dimensions

2017-08-16  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.hpp,
	physics/basic/units/vector_unit.cpp,
	physics/basic/units/vector_unit.hpp: class vector_unit now has the
	constructors vector_unit(unit,string) and vector_unit(float,string)
	that work as their scalar_unit counterpart

2017-08-16  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit_abbreviation.hpp: units.hpp included in
	this file to have more clarity

2017-08-16  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/biochemistry/units.cpp,
	chemistry/general/atoms/units.cpp,
	chemistry/general/matter/units.hpp,
	chemistry/general/substance/units.cpp,
	chemistry/general/substance/units.hpp, informatics/units.cpp,
	physics/astronomy/units.cpp,
	physics/electromagnetism/electricity/units.cpp,
	physics/electromagnetism/electricity/units.hpp,
	physics/electromagnetism/hardware/units.cpp,
	physics/electromagnetism/magnetism/units.cpp,
	physics/mechanics/dynamics/units.cpp,
	physics/mechanics/fluid_dynamics/units.cpp,
	physics/mechanics/kinematics/units.cpp,
	physics/mechanics/space/units.cpp,
	physics/thermodynamics/units.cpp, physics/waves/optics/units.cpp,
	physics/waves/radiometry/units.cpp, physics/waves/units.cpp: include
	path of units files changed to a full path

2017-08-16  Ismael Correa <ismael.correa.castro@gmail.com>

	* units.hpp: units.hpp file corrected to include
	unit_abbreviation.hpp at last

2017-08-16  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.hpp,
	chemistry/general/atoms/atoms_ia.hpp,
	chemistry/general/atoms/normal_atom.hpp,
	chemistry/general/molecules/atomic_bond.hpp,
	chemistry/general/molecules/molecule.hpp,
	chemistry/general/substance/substance.hpp,
	physics/quantical/particles/electron.hpp,
	physics/quantical/particles/proton.cpp,
	physics/quantical/particles/proton.hpp: included path to
	physics/units.hpp changed to units.hpp

2017-08-16  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/quantical/particles/electron.cpp: test of mass for the
	electron

2017-08-15  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/units.hpp => units.hpp: header file physics/units.hpp
	moved to root because it includes all units, so it's a more logical
	arrangement

2017-08-15  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit_abbreviation.cpp,
	physics/basic/units/unit_abbreviation.hpp: abbreviation classes now
	use direct classes in order to save some resources taking profit of
	the static real dimensions

2017-08-15  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/substance/units.cpp,
	chemistry/general/substance/units.hpp,
	physics/electromagnetism/electricity/units.cpp,
	physics/electromagnetism/electricity/units.hpp,
	physics/electromagnetism/hardware/units.cpp,
	physics/electromagnetism/hardware/units.hpp,
	physics/electromagnetism/magnetism/units.cpp,
	physics/electromagnetism/magnetism/units.hpp,
	physics/waves/optics/units.cpp, physics/waves/optics/units.hpp,
	physics/waves/radiometry/units.cpp,
	physics/waves/radiometry/units.hpp: new important unit classes
	created

2017-08-14  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit_basic.cpp,
	physics/basic/units/base_units.hpp: unit literals now return their
	more common class instead of auto_unit. That improves performance

2017-08-14  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.cpp, physics/basic/units/unit.hpp: class
	unit copy assignment created explicitly to avoid warning
	-Wvirtual-move-assign

2017-08-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit_basic.cpp,
	physics/basic/units/base_units.hpp: class mole now can give the
	total amount of particles represented by the mole or by te particles
	abbreviation

2017-08-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_scalar.hpp,
	physics/basic/units/auto_vector.hpp,
	physics/basic/units/scalar_unit.cpp,
	physics/basic/units/scalar_unit.hpp,
	physics/basic/units/vector_unit.cpp,
	physics/basic/units/vector_unit.hpp: operational operators inherited
	for template classes scalar_unit_crtp<T> and vector_unit_crtp<T>

2017-08-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* math/number/undefined_number.hpp: class undefined_number updated
	to have const operators, as they should be

2017-08-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_unit.hpp, physics/basic/units/unit.cpp,
	physics/basic/units/unit.hpp: class unit operators with other units
	and with numbers now are const, as they should always be

2017-08-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit_basic.cpp,
	physics/basic/units/base_units.hpp: basic units now are initialized
	with macros

2017-08-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/scalar_unit.hpp,
	physics/basic/units/vector_unit.hpp: macros for defining units with
	aditional member functions and member variables created. They are
	called SCALAR_UNIT_HPP_BEGIN(), SCALAR_UNIT_HPP_END(),
	VECTOR_UNIT_HPP_BEGIN(), VECTOR_UNIT_HPP_END()

2017-08-11  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/vector_unit.cpp: one comented line of legacy
	code removed

2017-08-10  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/vector_unit.cpp,
	physics/basic/units/vector_unit.hpp: legacy constructors of
	vector_unit class deleted

2017-08-10  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_unit.hpp,
	physics/basic/units/auto_vector.hpp, physics/basic/units/unit.cpp: 
	operator ^ and functions power_real_dimensions() and
	power_actual_dimensions() used to always change dimensions scale,
	except for the express case of the ^= operator

2017-08-10  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/dimension_abstract.cpp,
	physics/basic/units/dimension_abstract.hpp,
	physics/basic/units/unit.cpp, physics/basic/units/unit.hpp: 
	deprecated functions deleted from actual code. Legacy code of
	dimension_abstract also erased

2017-08-10  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_unit.cpp, physics/basic/units/unit.cpp,
	physics/basic/units/unit.hpp: constructor of
	unit(unit_number,vector_real_dimensions,vector_actual_dimensions)
	updated to unit(unit_number,vector_actual_dimensions)

2017-08-10  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.cpp, physics/basic/units/unit.hpp: Some
	legacy code commented has been deleted

2017-08-10  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/biochemistry/units.cpp,
	chemistry/biochemistry/units.hpp,
	chemistry/general/atoms/units.cpp,
	chemistry/general/atoms/units.hpp,
	chemistry/general/substance/units.cpp,
	chemistry/general/substance/units.hpp, informatics/units.cpp,
	informatics/units.hpp, physics/astronomy/units.cpp,
	physics/astronomy/units.hpp,
	physics/electromagnetism/electricity/units.cpp,
	physics/electromagnetism/electricity/units.hpp,
	physics/electromagnetism/hardware/units.cpp,
	physics/electromagnetism/hardware/units.hpp,
	physics/electromagnetism/magnetism/units.cpp,
	physics/electromagnetism/magnetism/units.hpp,
	physics/mechanics/dynamics/units.cpp,
	physics/mechanics/dynamics/units.hpp,
	physics/mechanics/fluid_dynamics/units.cpp,
	physics/mechanics/fluid_dynamics/units.hpp,
	physics/mechanics/kinematics/units.hpp,
	physics/mechanics/space/units.cpp,
	physics/mechanics/space/units.hpp,
	physics/thermodynamics/units.cpp, physics/thermodynamics/units.hpp,
	physics/waves/acoustics/units.hpp, physics/waves/optics/units.cpp,
	physics/waves/optics/units.hpp, physics/waves/radiometry/units.cpp,
	physics/waves/radiometry/units.hpp, physics/waves/units.cpp,
	physics/waves/units.hpp: All new units updated to the macro system.
	Now they are ready to be used, both vectors and scalars

2017-08-10  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/mechanics/kinematics/units.cpp,
	physics/mechanics/kinematics/units.hpp: kinematics units now use the
	new macros to define scalar and vector units

2017-08-10  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.cpp: comments changed in order to avoid
	some warnings during refactoring

2017-08-10  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/scalar_unit.hpp,
	physics/basic/units/vector_unit.hpp: macros for quick implementation
	of units. The new macros are SCALAR_UNIT_HPP(name),
	SCALAR_UNIT_CPP(name,dimensions), VECTOR_UNIT_HPP(name),
	VECTOR_UNIT_CPP(name,dimensions) and they allow to define the units
	with a single line on the header and a single line on the source
	file

2017-08-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/constants.hpp: chemistry/constants.hpp file including
	the avogadro constant for working with particles. It was from a
	previous commit

2017-08-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/vector_unit.cpp,
	physics/basic/units/vector_unit.hpp: same_dimensions() function name
	changed to same_spacial_dimensions() in order to distinguish the
	function from equal_dimensions()

2017-08-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.cpp, physics/basic/units/unit.hpp: 
	comparison operators for units with strings created

2017-08-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/auto_unit.hpp: operator / of units now divides
	the dimensions, instead of dividing only values and keeping
	dimensions identical

2017-08-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/abbreviation.cpp,
	physics/basic/units/abbreviation.hpp,
	physics/basic/units/unit_abbreviation.cpp,
	physics/basic/units/unit_abbreviation.hpp: particles abbreviation
	created. _particles literal created. Factory function
	create_abbreviation() now supports abbreviation_particles class

2017-08-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/dimension.cpp: create dimension bug fix solved
	for mol

2017-08-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/dimension_container.cpp,
	physics/basic/units/dimension_container.hpp: power_real_dimensions()
	and power_actual_dimensions() functions created

2017-08-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* tests/main.cpp, tests/test_units.hpp: unit test system with CATCH
	library created

2017-08-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/mechanics/kinematics/units.cpp: units.cpp commited, wasn't
	included previousy

2017-08-08  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/biochemistry/units.hpp,
	chemistry/general/atoms/units.hpp,
	chemistry/general/substance/units.hpp, informatics/units.hpp,
	math/topology/coordinates/hyper_spherical_coordinates.cpp,
	math/topology/coordinates/hyper_spherical_coordinates.hpp,
	physics/astronomy/units.hpp, physics/basic/units/auto_scalar.cpp,
	physics/basic/units/auto_scalar.hpp,
	physics/basic/units/auto_unit.cpp,
	physics/basic/units/auto_unit.hpp,
	physics/basic/units/auto_vector.cpp,
	physics/basic/units/auto_vector.hpp,
	physics/basic/units/scalar_unit.cpp,
	physics/basic/units/scalar_unit.hpp, physics/basic/units/unit.cpp,
	physics/basic/units/unit.hpp,
	physics/basic/units/unit_abbreviation.cpp,
	physics/basic/units/unit_abbreviation.hpp,
	physics/basic/units/unit_basic.cpp,
	physics/basic/units/base_units.hpp,
	physics/basic/units/vector_unit.cpp,
	physics/basic/units/vector_unit.hpp,
	physics/electromagnetism/electricity/units.hpp,
	physics/electromagnetism/hardware/units.hpp,
	physics/electromagnetism/magnetism/units.hpp,
	physics/mechanics/dynamics/units.hpp,
	physics/mechanics/fluid_dynamics/units.hpp,
	physics/mechanics/kinematics/units.hpp,
	physics/mechanics/space/units.hpp,
	physics/thermodynamics/units.hpp, physics/units.hpp,
	physics/waves/optics/units.hpp, physics/waves/radiometry/units.hpp,
	physics/waves/units.hpp: auto_unit, auto_scalar and auto_vector
	finished. scalar_unit and vector_unit classes updated to be abstract
	rather than template classes. units.hpp updated to that new topology
	of classes. Some units.hpp now have ready their real_dimensions as
	static variables. hyper_spherical_coordinates class updated to this
	new topology, too

2017-08-03  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/dimension_abstract.cpp,
	physics/basic/units/dimension_container.cpp,
	physics/basic/units/dimension_container.hpp: vector_real_dimensions
	and vector_actual_dimensions now have a special output stream. Also,
	the bug for negative units is solved

2017-08-03  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.cpp,
	chemistry/general/atoms/atom.hpp: Atom constructor defined inside
	the cpp file, as it should

2017-08-02  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/dimension_container.cpp,
	physics/basic/units/dimension_container.hpp,
	physics/basic/units/unit.cpp, physics/basic/units/unit.hpp: 
	member-functions create_real_dimensions() and
	create_actual_dimensions() of class unit changed to be inside
	dimension_container to have more order inside the code

2017-08-02  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.cpp, physics/basic/units/unit.hpp: member
	function name dimensions() change by change_dimensions() in order to
	have more clarity

2017-08-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* biology/dna/dna.hpp, biology/dna/gene.hpp: New dna and gene
	classes, they will be implemented in the future

2017-08-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/dimension_container.cpp,
	physics/basic/units/dimension_container.hpp,
	physics/basic/units/unit.cpp, physics/basic/units/unit.hpp,
	physics/basic/units/unit_basic.cpp,
	physics/basic/units/vector_unit.hpp: Typedef unit_real_dimensions
	changed for vector_real_dimensions in order to have more clarity.
	Typedef unit_actual_dimensions changed for vector_actual_dimensions
	in order to improve clarity.

2017-08-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/abbreviation.cpp,
	physics/basic/units/abbreviation.hpp,
	physics/basic/units/unit_abbreviation.cpp,
	physics/basic/units/unit_abbreviation.hpp: Abbreviation uma was bad,
	it was the spanish therm of the abbrevation amu. Changed. Also,
	abbreviation now can be initialized with long double literals

2017-08-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/scalar_unit.hpp: Bug of scalar units solved

2017-08-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/dimension.cpp: Bug of units with the da prefix
	solved

2017-08-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/thermodynamics/units.cpp,
	physics/thermodynamics/units.hpp: New scalar unit enthalpy created

2017-08-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* informatics/graphical/color.hpp: Color class improved

2017-08-01  Ismael Correa <ismael.correa.castro@gmail.com>

	* chemistry/general/atoms/atom.cpp,
	chemistry/general/atoms/atom.hpp,
	chemistry/general/atoms/atoms_ia.cpp,
	chemistry/general/atoms/atoms_ia.hpp,
	chemistry/general/atoms/electron_cloud.hpp,
	chemistry/general/atoms/normal_atom.hpp,
	chemistry/general/molecules/atomic_bond.cpp,
	chemistry/general/molecules/atomic_bond.hpp,
	chemistry/general/molecules/bit_molecule.hpp,
	chemistry/general/molecules/molecule.cpp,
	chemistry/general/molecules/molecule.hpp,
	chemistry/general/molecules/normal_molecule.cpp,
	chemistry/general/molecules/normal_molecule.hpp: New features added
	to atoms and molecules. Molecules, based on the complexity of their
	data, can be normal_molecules or bit_molecules. Atoms now have more
	features, they are nearly ready. Class atomic_bond also has been
	created

2017-07-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* informatics/graphical/color.cpp, informatics/graphical/color.hpp: 
	New category 'informatics/graphical' intended for usually uncovered
	topics of graphical computing (it'll cover topics that aren't
	adequately found or treated inside graphical libraries like OpenGL,
	Cairo, among others, in order to cover the scientific perspective).
	New color class created inside it, with basic functionality

2017-07-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* physics/basic/units/unit.cpp, physics/basic/units/unit.hpp: Bug
	with units corrected

2017-07-25  Ismael Correa <ismael.correa.castro@gmail.com>

	* Magick Science with units and some features of atoms

