# scifir-units library

[![Linux build status](https://github.com/scifir/scifir-units/actions/workflows/cmake.yml/badge.svg)](https://github.com/scifir/scifir-units/actions/workflows/cmake.yml)

Welcome! The **Scifir Collection** is a set of scientific libraries, written in **C++**, for developing **laboratory machines** and **scientific inventions**. It provides units, molecules, among other features, to allow developers of scientific software to develop their software and firmware easily. Enjoy!

The Scifir Collection is under development, but the units are already released. Molecules aren't, but they will by ready soon!

**scifir-units** includes units with dimensions to use, then it's unneeded to care about having the proper dimensions and prefixes when developing scientific software, you can instantiate any value you have on the machine, without performing operations with a calculator first to convert the units to a common prefix. Learn how to use them at the [Wiki](https://github.com/scifir/scifir-units/wiki). It's been developed under **C++20** and uses **cmake** as build automation tool. It's available for **Linux distributions** and **Windows**.

The **current version** of scifir-units is the **beta-version-2.0**. The version 1.0 has never been released because the version 2.0 was better by a great extent. The version 2.0 includes a better inheritance system and a wide simplification of all the programming of the library and, then, a better compilation and a saving of RAM for each instantiation of each class. Because of that reason, the version 2.0 has been preferred over the version 1.0.

### Team

The **Scifir Collection** is developed by [Ismael Correa Castro](https://iarfen.github.io), a software developer of 32 years old. You can email him if you find bugs, you want to request new features, or have any other need, at ismael.correa.castro@gmail.com. His ORCID is 0009-0007-3815-7053, if you want to reference this work inside any publication.

### Funding

The **Scifir Foundation** is looking for **funding**, in order to do some digital marketing and pay some other needs of the project. If you want to support this libraries, **science will thank you** for that, you can donate in this [sponsors page](https://github.com/sponsors/iarfen).

## Installation

To install **scifir-units** you have to use **CMake** and **make**. scifir-units can be compiled with **g++**, **clang++** and **msvc**. Also, **nvcc** and **dpcpp** can also be used. The compilers for microcontrollers can also be used.

scifir-units uses **icu** and **boost** libraries. Of boost, it uses boost-system. You have to install those two libraries in order to install scifir-units. To do so, use **apt** in Ubuntu and Debian, **yum** for Fedora and similar distributions, or another package manager if your Linux distribution doesn't use those two. Inside Windows, install those libraries through **vcpkg**, if you want to build scifir-units as lib or dll, or through **mingw**, if you want to use scifir-units as on Linux distributions.

Also, if you want to compile the tests, you'll need the library **catch2**, which you can install with the same package manager that you have used to install icu and boost.

If you want to change the compiler to use you have to use the argument **-DCMAKE_CXX_COMPILER** in the first cmake command, the cmake command with the --preset argument. There, you can specify, for example, -DCMAKE_CXX_COMPILER=clang++, to use the **clang++** compiler. You can also specify flags for the compiler using the argument **-DCMAKE_CXX_FLAGS**.

The environment variables needed to be set in your operating system to build scifir-units vary depending on the preset you want to use. For Linux and the WSL (the Windows Subsystem for Linux), you don't need to set any environment variable. For Windows, that's, inside Windows but outside MinGW, you need to set **VCPKG_ROOT** to the installation directory of vcpkg and **VCPKG_DEFAULT_TRIPLET** to the default triplet you're using in that installation of vcpkg. For all builds using vcpkg, even outside Windows, you need to set VCPKG_ROOT and VCPKG_DEFAULT_TRIPLET, not only inside Windows. For MinGW you need to set **MINGW64_DIR** to the installation directory of MinGW. For Android NDK you need to set **ANDROID_NDK_ROOT** to the installation directory of the NDK version you're using (select the folder of the version, there can be more than one version of Android NDK installed in the same installation of Android SDK and Android Studio). To build for microcontrollers you don't need to set any environment variable, but you need to point CMAKE_CXX_COMPILER to the C++ compiler of the toolchain of the microcontroller you want, and set the flag -mmcu of your C++ compiler using CMAKE_CXX_FLAGS="-mmcu=<mmcu-model>" to the model of your microcontroller.

If, for any reason, you need to configure something inside your local installation of cmake to build scifir-units, or if you have any problem building scifir-units, check the documentation of cmake here: [https://www.cmake.org/documentation](https://www.cmake.org/documentation). cmake is a software easy to use, and you shouldn't need more than some days of study (thinking that you don't know cmake yet) to fully learn it.

#### Configuring cmake for boost

To build scifir-units you need to configure cmake to find boost with the module **FindBoost.cmake**. To do so, set the environment variables of cmake called **CMAKE_INCLUDE_PATH** to the include directory (usually **/usr/include** in Linux) and **CMAKE_LIBRARY_PATH** to the link directory (usually **/usr/lib** in Linux). The include directory usually doesn't change with Linux distributions, but the link directory does. The link directory can be, for example, **/usr/lib/x86_64-gnu-linux** in Debian, **/usr/lib64** in Fedora, **/usr/lib** in Arch Linux, other Linux distributions have others link directories.

The link directories of various Linux distributions are the following, set CMAKE_LIBRARY_PATH based on the Linux distribution you're using to build scifir-units:

- **Debian:** /usr/lib/x86_64-gnu-linux.
- **Ubuntu:** /usr/lib/x86_64-gnu-linux.
- **KDE Neon:** /usr/lib/x86_64-gnu-linux.
- **Linux Mint:** /usr/lib/x86_64-gnu-linux.
- **Fedora:** /usr/lib64.
- **CentOS:** /usr/lib64.
- **Arch Linux:** /usr/lib.
- **Manjaro:** /usr/lib.
- **OpenSUSE Leap:** /usr/lib64.
- **OpenSUSE Tumbleweed:** /usr/lib64.
- **Gentoo:** /usr/lib64.

In Windows, you have to set the include directory and the link directory of the toolchain you're using to build scifir-units. For Windows builds, scifir-units comes with the toolchains vcpkg and mingw already configured. If you use another toolchain, look the files CMakeLists.txt and CMakePresets.json to configure your toolchain in the same manner as vcpkg and mingw. Also, cmake can find the boost library when you're using vcpkg only if you set the environment variable **VCPKG_ROOT** to be the installation path of vcpkg.

Also, to configure cmake to find boost with the module FindBoost.cmake you have to set the variables **Boost_LIB_PREFIX**, **Boost_ARCHITECTURE** and **Boost_COMPILER** to the respective values of the version of boost that you've installed in order for the script **FindBoost** to work. If, when using cmake, boost is not found, check a documentation of FindBoost, or just look at the file **FindBoost.cmake**, to correct the problem that impedes cmake to find boost, otherwise scifir-units can't be build. The names of boost libraries follow the following convention:

${Boost_LIB_PREFIX}${Boost_NAMESPACE}_${component}${Boost_COMPILER}${Boost_USE_MULTITHREADED}${_boost_RELEASE_ABI_TAG}${Boost_ARCHITECTURE}-${Boost_LIB_VERSION}

Just look at your boost libraries which name they have and set all those variables to those values.

### Linux

The commands to install scifir-units in Linux distribution are the following (it also works inside **WSL**):

```
cmake --preset=linux
cmake --build --preset=linux
cmake --install ./build/linux
```

Optionally, you can change the installation directory by setting **CMAKE_INSTALL_PREFIX** when running the first command. Set it using -DCMAKE_INSTALL_PREFIX=<path-to-installation-directory>.

### Windows

To install scifir-units inside Windows you have to specify a path to some Windows folder, the file **scifir-units.lib** will be installed there, and also the headers. You have to install using **vcpkg** the packages **icu** and **boost_system** in order to build the library. The commands are the following:

```
cmake --preset=windows -DCMAKE_INSTALL_PREFIX=<path-to-windows-dir>
cmake --build --preset=windows
cmake --install ./build/windows
```

To compile for Windows Universal Applications, which targets both Windows Store and Windows Phone, you have to use the flags **-DCMAKE_SYSTEM_NAME=WindowsStore** and **-DCMAKE_SYSTEM_VERSION="10.0"** with the first command (the command which specifies the preset). CMAKE_SYSTEM_VERSION can be higher than 10.0, but no lower.

### MinGW

To install scifir-units inside MinGW you have to configure **MinGW** with the environment variable **MINGW64_DIR**, which sets the path to the installation directory of MinGW. Inside MinGW you need to install **icu** and **boost_system**. Then, execute the following commands:

```
cmake --preset=windows-mingw
cmake --build --preset=windows-mingw
cmake --install ./build/windows-mingw
```

### MacOS and Apple devices

scifir-units uses the XCode generator of cmake to compile for MacOS. You need to install icu and boost_system to build scifir-units inside MacOS. The commands to compile and install scifir-units inside MacOS are the following:

```
cmake --preset=macos
cmake --build --preset=macos
cmake --install ./build/macos
```

To compile scifir-units for iOS, tvOS, visionOS or watchOS you must add the flag **-DCMAKE_SYSTEM_NAME=<os-name>** to the first command (the command which specifies the preset). Optionally, you can also use the flag **-DCMAKE_OSX_ARCHITECTURES** to specify the architecture of the device or the simulator.

### vcpkg

scifir-units can be compiled with vcpkg inside every triplet of vcpkg, not only inside Windows. To do that, after installing icu and boost_system in vcpkg, use the following commands:

```
cmake --preset=vcpkg
cmake --build --preset=vcpkg
cmake --install ./build/vcpkg
```

### Android

First, set **ANDROID_HOME** and **ANDROID_NDK_ROOT** to the paths of your Android SDK installation and of your Android NDK installation. After that, install vcpkg, and set the environment variable **VCPKG_ROOT** to the installation directory of vcpkg. Set also the environment variable **VCPKG_DEFAULT_TRIPLET** to be the triplet of the computer you're using to build scifir-units. Finally, to compile scifir-units to work inside an Android application that uses Android NDK for that purpose, you have to use the following commands:

```
cmake --preset=android -DCMAKE_INSTALL_PREFIX=<path-to-android-project>
cmake --build --preset=android
cmake --install ./build/android
```

After building scifir-units you have to move the library file to your Android project. Inside Android Studio, create the JNI folder under the right-click menu of the **app folder**, under the option **New > Folder > JNI Folder**. Inside the jni folder, you should create a folder for each **Android ABI** existing, and add scifir-units there compiled for that Android ABI by using the option **-DANDROID_ABI** of this cmake configuration. Search all Android ABIs existing and compile this library for each of them, in order to have your Android application working on all Android devices.

The include path for scifir-units inside your Android Studio project should be the same as the linux distribution, vcpkg or mingw, use the same as always. The headers of scifir-units, then, as any C++ library for Android, doesn't need to be copied inside your Android project and, then, they aren't part of the final **APK file**.

### Microcontrollers

For electronics, you can build scifir-units using the compiler of your microcontroller, which comes with the SDK of your microcontroller. You have to specify, using the option **-DCMAKE_CXX_COMPILER**, the compiler to use, and, also, you have to use the option **-DCMAKE_CXX_FLAGS="-mmcu=<microcontroller-model>"** to specify the model of your microcontroller in order for your compiler to know for which microcontroller model to compile.

The SDK of microcontrollers can be downloaded on the website of the vendor of the microcontroller, which can be **Microchip**, **STMicroelectronics**, or any other.

### cpack

If you need to package scifir-units into any format supported by cpack, you just need to use the preset that you've previously used to build scifir-units.

```
cpack --preset=<your-preset> -G <generator-needed>
```

You can type the command **cpack --help** to check all available generators.

### ctest

You can test scifir-units executing ctest if you want. It's not needed to execute those tests in your local computer, but you can do it if for any reason you find it helpful. To build the tests, add the flags **-DBUILD_TESTING=ON** to the first preset command, in order to set the variable BUILD_TESTING to ON, that variable configures the build to build also all the tests.

```
ctest --preset=<your-preset>
```

## Using the library

First you have to link **scifir-units** to your project. To link scifir-units, after installing it following the steps above, add the following code inside your CMakeLists.txt file:

```
target_link_libraries(your-project scifir-units)
```

Now that the library es linked, you can use it inside your code by including the **header "scifir/units.hpp"**.

```
#include "scifir/units.hpp"
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
- complex_number<T>.
- lab_number<T>.

The coordinates classes handle position in space. The point classes also handle position in space. Coordinates are used for positions and points are intended for more stationary cases, like for example vertex of triangles that form a 3D model.

- coordinates_1d<T>.
- coordinates_2d<T>.
- coordinates_2dr<T>.
- coordinates_3d<T>.
- coordinates_3dr<T>.
- coordinates_nd<T>.
- coordinates_ndr<T>.
- point_1d<T>.
- point_2d<T>.
- point_3d<T>.
- point_nd<T>.
- direction.

The special unit classes handle special cases of values:

- aid.
- zid.
- color.
- percentage.
- pH.
- pOH.
- pixel.
- size_2d<T>.
- size_3d<T>.
- size_nd<T>.

### Data conventions

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

### Consumption of memory

The scalar_unit and vector unit classes, vector_unid_2d, vector_unid_3d and vector_unit_nd size more than a single float, which uses 4 bytes, but don't size a big amount and so, they can be used in great quantities for any purpose, cause they are very lightweight.

The angle class uses only 4 bytes, and works perfectly fine, very similar to a normal float. Then, you can use it freely every time you need to do calculations that need angles.

## Use cases

### Technologies for inventions

scifir-units can be used for any project that needs units of measurement, vectors, coordinates, and related calculations. It's primary intended to program **scientific inventions**, **laboratory machines**, **electronic devices** and **medical devices** (medical devices that need a software, not any medical device). In this section it's explained how to build those devices, in order to be known how to create all the project, and not only how to use scifir-units.

To create the electronic circuit of any electronic device, being it a scientific invention, a laboratory machine, a medical device or of other type, you can use **KiCad**. The electronic circuit is then printed using the file created with KiCad. For the operating system, you can use **FreeRTOS**, **FreeBSD**, or even create a custom linux distribution with **Linux From Scratch**. For the GUI of the software of the invention to run inside this operating system, you can use **GTK+**, **wxWidgets** or **Qt**. The inventions not always use a GUI, they can work just with analog buttons or a LCD display. It's with this software where you can use scifir-units to do the calculations the software requires.

To build a desktop application that connects remotely with the invention, use also GTK+, wxWidgets or Qt to build the GUI. You can use as communication technology **bluetooth**, **wifi direct** (which is a wifi peer-to-peer) or **usb**.

Also, to add 3D to the software, you can use **OpenGL**. To do plots, use **matplot++**, **gnuplot** or **GNU plotutils**. Obviously, to store output from the software, you can use **YAML** or **XML**. To work with XML inside C++ you can use **rapidxml**, **tinyxml** or **libxml2**. To work with YAML you can use **yaml-cpp**. Use **conf** for configuration files, the library of it is **libconfig**. To send messages between different servers/daemons that are run inside the invention, you can use **dbus**. To handle large amounts of data, you can use a simple database, like **SQLite**, with **SQLiteCPP**.

From the graphics part, you can use **SVG++** to work with SVG files. To add GPS to the invention, you can use **gpsd**. To do the translation of the software, use **gettext**.

### Electronic devices

All scientific inventions and medical machines are electronic devices with more components. So, it's first needed to know electronics. An electronic device is composed of an **electronic circuit**, a **microcontroller**, **electronic sensors**, **output devices**, **electronic motors**, an **operating system**, and the **software of the device** (called **firmware**).

The **electronic circuit** connects all the different components and parts of the electronic device, and supplies energy and/or communication signals to each component.

The **microcontroller** executes the software, and sends then signals to one or more electronic component.

The **electronic sensors** measure properties of the environment and send them to the microcontroller, being it able then to read them.

The **output devices** display the output data of the software in some form or another, it can be visual (the monitor), auditive (the speakers), etc.

The **electronic motors** can be powered and controlled by the electronic circuit, and allow to control the movement, like for example the movement of the molecules through a tube.

The **operating system** is the software that handles the processes of the microcontrollers, and executes one process or another, or more than one process at the same time. Good operating systems for electronic devices are **FreeBSD** and **FreeRTOS**.

The **firmware** is the software of the electronic device, it's usually executed inside an operating system, but it can be executed without an operating system too.

### Laboratory machines

A laboratory machine, additional to all the components of electronic devices, contains too output devices and/or input devices that allow to control and get data about the matter, which can be molecules, solids, gases, liquids, cells, or even exotic matter.

Laboratory machines in which to use units are, for example, **NMR spectroscopes**, **IR spectroscopes**, **DNA sequencers**, **Gas chromatographs**. **DNA synthesizers**, a possible scientific invention present in the projects of Scifir, can also be benefited of units. **Printers at nanoscale**, which are essential for **nanotechnology**, are programmed easier, too, with units.

### Scientific inventions

A scientific invention different than a laboratory machine is done similar to those machines. Then, scientific inventions also need electronic components that handle matter. A usual different with laboratory machines is that the inventions usually need other parts too, like for example **spaceships**, which need more mechanical components than the common laboratory machine. Despite that difference, to develop a laboratory machine is similar than to develop any scientific invention.

### Medical devices

A medical device usually controls the flow of some substance, or needs high precision for the position of some part of the machine, and for those purposes scifir-units helps.

Important medical devices which can be benefited with measurement of units are devices of **robotic surgery**, **heart-lung machines**, **mechanical ventilators**, **anesthesic machines**, **lasik machines**, **x-ray machines**, **magnetic resonance imaging machines**, **ultrasound machines**, **tomography machines**.

Other simple devices as **pressure monitor**, **heart rate monitor** and **electrocardiograms** are also improved with units.

### Robotics

**Robotics** is the branch of science, mainly of informatics, whose subject of study are the robots. A **robotist** is a scientist specialized in robotics.

A robot is built with electronics, apart from the components listed previously, it needs a **visual sensor**, a **microphone**, a **speaker**, a **temperature sensor**. It can have also a **sensor of molecules**, in order to have a simulation of the **sense of odor**. In order to build the human shape (or animal shape), you must know **machining**, and use **molds**, the **milling machine** and/or the **lathe** to build each part. For some robotic parts, you can use **carbon fiber**.

All components of robots frequently need at least scalar units, if not also vector units, like for example the visual sensor or the microphone, and so you can use scifir-units inside your robotics projects.

Inside Scifir, it's called **Universal Robotics** an idea of Ismael Correa which consists of robots that can share essentially any part with the other robot. For that purpose, too, scifir-units is useful.

Each component of a robot, being a sensor or a removable part, should be programmed as an independent server inside the operating system of the robot. In that way, it can be restarted, and changed, without modifying the other parts. Then, the visual sensor, the speaker and the temperature sensor, should all be different servers inside the same OS.

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

- **dimensions**: "m2 / s", "J / s2 * kg"
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

In order to store units inside a file an initialization string should be used. For any purpose, when converting some of those classes to an string, the string initialization has to be always used.

### Space

Inside scifir-units the space can be measured with float or with length. Secondarily, any scalar_unit can be used as measure of space, because inside science there are modelings of imaginary spaces, where the length is not used. Because of that reason, all coordinates and point classes are template classes that accept floats or scalar_unit classes.

### Dimensions

Inside scifir-units a **basic dimension** is a dimension considered basic under the SI system of units. Different to that, a **simple dimension** is a dimension without any derived dimension. That's, it's a dimension that's not an abbreviation of two or more other dimensions.

The dimensions that a scalar_unit class can have are available in the enum dimension::type, and are only the SI dimensions or, if there isn't a dimension for an important purpose in the SI system of units, a selected dimension of the different possible options. Only the prefered dimensions have been added to the enum dimension::type, the other dimensions, as for example England units, have been added only as conversion options. With that system, always the same dimensions are used, which simplifies the work inside a laboratory, because then there's less confusion about which dimensions are being used.

#### Dimensions of space

Both the degree and the radian are used for measuring angles. When specifying angles in a human readable way, degree is always or nearly always the prefered choice. When specifying angles within mathematical formulas, radians are used, and the degrees can be converted to radians for that purpose. Given the definition of radian, mathematical formulas naturally have their angles needed to be specified in radians.

| Symbol | Name | Plural | Equivalency | Derived dimensions | Description
| --- | ----- | ----- | --- | -------------------- | --------------------------
| m | Metre | Metres | - | - | Measure of length.
| θ | Degree | Degrees | $$\frac{\pi}{180} rad$$ | - | Measure of length.
| rad | Radian | Radians | $$\frac{180}{\pi} θ$$ | - | Measure of the angle, it's the exact measure of the perimeter of the angle, when that angle is drawn as a circle in a math graph.
| sr | Steradian | Steradians | - | - | Measure of a solid angle, which is defined as an angle in two dimensions.
| L | Litre | Litres | 1 dm3 | dm3 | Measure of volume, frequently used for liquids.

#### Dimensions of time

| Symbol | Name | Plural | Equivalency | Derived dimensions | Description
| --- | ----- | ----- | --- | -------------------- | --------------------------
| s | Second | Seconds | - | - | Measure of time.
| min | Minute | Minutes | - | 60 s | Measure of time.
| hour | Hour | Hours | - | 3,600 s | Measure of time.
| day | Day | Days | - |  86,400 s | Measure of time.
| Hz | Hertz | Hertz | - | 1 / s | Measure of frequency.

#### Dimensions of chemistry and matter

| Symbol | Name | Plural | Equivalency | Derived dimensions | Description
| --- | ----- | ----- | --- | -------------------- | --------------------------
| g | Gram | Grams | - | - | Measure of amount of mass.
| mol | Mole | Moles | N particles (Avogadro number) | - | Amounf of matter.
| particles | Particles | Particles | mol / (Avogadro number) | - | Amount of particles, without using mol.
| M | Molarity | Molarities | - | mol / L | Measure of concentration of a chemical species.
| kat | Katal | Katals | - | mol / s | Catalytic activity.
| Å | Angstrom | Angstroms | - | $$10^{-10} m$$ | Dimension of length, used mainly for wavelengths, inside the laboratory.
| Da | Dalton | Daltons | - | $$1,66053886 * 10^{-24} g$$ | Measure of mass very low that is used for atoms and molecules, at microscopic and quantum scale. One mole of 1 Da is equivalent to 1 g.
| amu | Atomic mass unit | Atomic mass units | 1 Da | Da | Equivalent name to Dalton.

#### Dimensions of force

| Symbol | Name | Plural | Equivalency | Derived dimensions | Description
| --- | ----- | ----- | --- | -------------------- | --------------------------
| N | Newton | Newtons | - | kg * m / s2 | Measure of force.
| Pa | Pascal | Pascals | - | kg / s2 * m | Measure of pressure.

#### Dimensions of energy

| Symbol | Name | Plural | Equivalency | Derived dimensions | Description
| --- | ----- | ----- | --- | -------------------- | --------------------------
| J | Joule | Joules | - | kg * m2 / s2 | Measure of energy.
| W | Watt | Watts | N particles (Avogadro number) | kg * m2 / s3 | Amounf of matter.
| eV | Electron volt | Electron volts | - | $$1.602176634 * 10^{−19} J$$ | Measure of energy, used for quantum physics. It's a very low unit, intended for the quantum scale.

#### Dimensions of optics

| Symbol | Name | Plural | Equivalency | Derived dimensions | Description
| --- | ----- | ----- | --- | -------------------- | --------------------------
| cd | Candela | Candelas | - | - | Measure of luminous intensity.
| lm | Lumen | Lumens | - | cd * sr | Measure of luminous flux.
| lx | Lux | Luxes | - | cd * sr / m2 | Measure of illuminance.

#### Dimensions of heat

| Symbol | Name | Plural | Equivalency | Derived dimensions | Description
| --- | ----- | ----- | --- | -------------------- | --------------------------
| K | Kelvin | Kelvins | - | - | Measure of temperature.

#### Dimensions of electricity

| Symbol | Name | Plural | Equivalency | Derived dimensions | Description
| --- | ----- | ----- | --- | -------------------- | --------------------------
| C | Coulomb | Coulombs | - | - | Measure of electric charge.
| A | Ampere | Amperes | - | C / s | Measure of electric current.
| V | Volt | Volts | - | J / C, W / A | Measure of voltage.
| F | Faraday | Faradays | - | A * s / V | Measure of electric capacitance.
| Ω | Ohm | Ohms | - | V / A | Measure of electric resistance.
| S | Siemens | Siemens | - | 1 / Ω | Measure of electric conductance.
| Wb | Weber | Webers | - | T * m2 | Measure of magnetic flux.
| T | Tesla | Teslas | - | V * s / m2 | Measure of magnetic strength.
| H | Henry | Henries | - | V * s / A | Measure of electric inductance.

#### Dimensions of astronomy

| Symbol | Name | Plural | Equivalency | Derived dimensions | Description
| --- | ----- | ----- | --- | -------------------- | --------------------------
| AU | Astronomical unit | Astronomical units | - | 149,597,870,700 m | Measure of long distances, for use in the space.
| ly | Light year | Light years | 63,241.07 AU | 94,607,304,725,808,000 m | Measure of long distances, for use in the space. It's exactly defined as the amount of distance that the light travels in a year.
| pc | Parsec | Parsecs | - | 3.2616 ly | Measure of long distances, for use in the space.

#### Dimensions of nuclear physics

| Symbol | Name | Plural | Equivalency | Derived dimensions | Description
| --- | ----- | ----- | --- | -------------------- | --------------------------
| Bq | Becquerel | Becquerels | - | 1 / s | Measure of radioactivity.
| Gy | Gray | Grays | - | m2 / s2 | Measure of ionising radiation (absorbed dose).
| Sv | Sievert | Sieverts | - | J / kg | Measure of ionising radiation (equivalent dose).
| Barn | Barn | Barns | - | $$10^{−28} m2$$  | Represents the transversal section of nucleus and nuclear reactions.

#### Dimensions of informatics

| Symbol | Name | Plural | Equivalency | Derived dimensions | Description
| --- | ----- | ----- | --- | -------------------- | --------------------------
| B | Byte | Bytes | - | - | Measure of quantity of information.
| px | Pixel | Pixels | - | - | Measure the amount of pixels or the position inside a screen.

#### Dimensions of biology

Inside scifir-units, a unit for measuring the quantity of memory inside the brain has been invented, and has been called **memo**.

| Symbol | Name | Plural | Equivalency | Derived dimensions | Description
| --- | ----- | ----- | --- | -------------------- | --------------------------
| memo | Memo | Memos | - | - | Measure of quantity of memory.

#### Dimensions of economy

The dimension of money inside scifir-units is just money. Apart from scifir-units, inside the same code, you can use the **ISO 4217**, which is the **ISO of currency codes**, after doing all the math with the money dimension, to convert to the final currency needed.

| Symbol | Name | Plural | Equivalency | Derived dimensions | Description
| --- | ----- | ----- | --- | -------------------- | --------------------------
| money | Money | Money | - | - | Measure of money.

#### Custom dimensions

A custom dimension is a dimension of any name, with any derived dimensions, that can be defined inside each project that uses scifir-units. To use custom dimensions, just initialize a scalar_unit or any vector_unit class with a name different than the default dimensions.

### Angle

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

### Scalar units

Scalar units and vector units are the central objects of scifir-units. They store a value and a set of dimensions, as units on science do. Scalar units are just normal values, while vector units have a value and a direction to which the vector points to.

Scalar units can operate with other scalar units, as well as with numeric primitive types. Functions like abs(), sqrt() and to_string() are supported. They have functions to operate with strings, and functions to operate with streams.

Scalar units can have any dimension of the SI system of units, or, also, any **custom dimension**. A custom dimension is a dimension with an arbitrary name, which is commonly used inside some fields of science when there's no name for a needed dimension.

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
| Length | m | Measures the length occupied in space by an object. |
| Time | s | Measures the duration in time of some event. |
| Mass | g | Measures the amount of substance related to the strength of a gravitational field. |
| Radian | rad | Measures the size of an angle. |
| Steradian | sr | Measures the size of a solid angle. |
| Coulomb | C | Measures the amount of charge. |
| Temperature | K | Measures the amount of hotness or coldness. Microscopically it measures the speed at which the particles that constitute the matter are moving. |
| Mole | mol | Measures the amount of a substance related to the number of its constituent particles. |
| Luminous intensity | cd | Measures the intensity of light. |
| Byte | B | Measures the amount of information. |
| Money | money | Measures the economic value of an entity. |
| Memo | memo | Measures the size occupied by a memory inside the brain of an animal, including human brains. Created by Ismael Correa, it's not an official basic dimension of the SI system of units. |

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

### AID and ZID

An **AID**, acronym of **Astronomycal ID**, is an identifier of an astronomical object, like planets, moons, galaxies, stars, and any other astronomical object.

A **ZID**, acronym of **Zone ID**, is an identifier of a zone, like a region, a district, a store, a lake, a country, and any other zone. A zone is defined here as any closed surface that can be drawn over an astronomycal object. A ZID is composed of the AID of which the zone pertains, and the zone itself.

### percentage

The **percentage** class represents percentages, they calculate the factor of the percentage and automatically, when operating with numeric types, calculate the percentage of that number.

### pixel

The **pixel** class represents pixels, which are the squares that compose screens. It can be used to calculate distance over pixels instead of distances of physical lengths, which is a need of some digital applications.

### pH and pOH

The **pH** class allows to work with pH, which is used inside chemistry software to store data about pH. The **pOH** class is the counterpart of the pH class, and is not commonly needed, but it can be used if the pH class is not being useful for some reason, and if instead the pOH class is useful. The pH class should always be **prefered** to be used over the pOH class, and that last should be used **only** if the pH class is not properly solving the needs.

### Sizes in 2D, 3D and ND

The **size_2d** class allows to store the data of the width and height of an object in length classes. The **size_3d** allows to store the data of the width, the height and the depth of an object in length classes. The **size_nd** class allows to store lengths corresponding to the dimension of an object in a variable number of dimensions.

## Internals

Internally, the library has some important mechanisms important to be known by a serious developer. Those important mechanisms are described here, in order to avoid the developer to read the code of the library and learn every detail.

The first important mechanism to describe is the static storage of custom dimensions. This storage is static, meaning that every time a unit of a dimension not registered is created, this storage is the one used, instead of the name being stored inside the instance. With that behavior, when instantiating a big amount of dimensions, a big amount of memory is saved. To refer to the static storage it's used the char symbol[3] of the dimension class, which uses only 3 bytes instead of the bytes the full dimension name would use. Then, each instance of a dimension class, given that static storage, uses only 6 bytes of memory.

The square of dimensions works in the following way: If the dimension consist only of one type of dimension, independently as if the dimension is a basic dimension or an abbreviation, the dimensions get squared. If the dimension is of more than one type, all the abbreviations are then converted to their derived types, and the total result gets squared. If the dimensions can't be squared because there's an odd number of them, the dimensions are then initialized empty.
