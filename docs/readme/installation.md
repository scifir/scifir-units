# Installation

To install **scifir-units** you have to use **CMake** and **make**. scifir-units can be compiled with **g++**, **clang++** and **msvc**. Also, **nvcc** and **dpcpp** can also be used. The compilers for microcontrollers can also be used.

scifir-units uses **icu** and **boost** libraries. Of boost, it uses **boost-system**. You have to install those two libraries in order to install scifir-units. To do so, use **apt** in Ubuntu and Debian, **yum** for Fedora and similar distributions, or another package manager if your Linux distribution doesn't use those. Inside Windows, install those libraries through **vcpkg** if you want to build scifir-units as lib or dll, or through **mingw** if you want to use scifir-units as on Linux distributions.

Also, if you want to compile the tests, you'll need the library **catch2**, which you can install with the same package manager that you have used to install icu and boost.

## Add scifir-units inside your project

First you have to link **scifir-units** to your project. To link scifir-units, after installing it following the steps above, add the following code inside your CMakeLists.txt file:

```
target_link_libraries(your-project scifir-units)
```

Now that the library is linked, you can use it inside your code by including the **header "scifir/units.hpp"**. All classes of scifir-units are inside the **namespace scifir**.

```
#include "scifir/units.hpp"
```

## Build options

If you want to change the compiler to use you have to use the argument **-DCMAKE_CXX_COMPILER** in the first cmake command, the cmake command with the --preset argument. There, you can specify, for example, -DCMAKE_CXX_COMPILER=clang++, to use the **clang++** compiler. You can also specify flags for the compiler using the argument **-DCMAKE_CXX_FLAGS**.

The environment variables needed to be set in your operating system to build scifir-units vary depending on the preset you want to use. For Linux and the WSL (the Windows Subsystem for Linux), you don't need to set any environment variable. For Windows, that's, inside Windows but outside MinGW, you need to set **VCPKG_ROOT** to the installation directory of vcpkg and **VCPKG_DEFAULT_TRIPLET** to the default triplet you're using in that installation of vcpkg. For all builds using vcpkg, even outside Windows, you need to set VCPKG_ROOT and VCPKG_DEFAULT_TRIPLET, not only inside Windows. For MinGW you need to set **MINGW64_DIR** to the installation directory of MinGW. For Android NDK you need to set **ANDROID_NDK_ROOT** to the installation directory of the NDK version you're using (select the folder of the version, there can be more than one version of Android NDK installed in the same installation of Android SDK and Android Studio). To build for microcontrollers you don't need to set any environment variable, but you need to point CMAKE_CXX_COMPILER to the C++ compiler of the toolchain of the microcontroller you want, and set the flag -mmcu of your C++ compiler using CMAKE_CXX_FLAGS="-mmcu=<mmcu-model>" to the model of your microcontroller.

If, for any reason, you need to configure something inside your local installation of cmake to build scifir-units, or if you have any problem building scifir-units, check the documentation of cmake here: [https://www.cmake.org/documentation](https://www.cmake.org/documentation). cmake is a software easy to use, and you shouldn't need more than some days of study (thinking that you don't know cmake yet) to fully learn it.

## Configuring cmake for boost

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

## Linux

The commands to install scifir-units in Linux distribution are the following (it also works inside **WSL**):

```
cmake --preset=linux
cmake --build --preset=linux
cmake --install ./build/linux
```

Optionally, you can change the installation directory by setting **CMAKE_INSTALL_PREFIX** when running the first command. Set it using -DCMAKE_INSTALL_PREFIX=<path-to-installation-directory>.

## Windows

To install scifir-units inside Windows you have to specify a path to some Windows folder, the file **scifir-units.lib** will be installed there, and also the headers. You have to install using **vcpkg** the packages **icu** and **boost_system** in order to build the library. The commands are the following:

```
cmake --preset=windows -DCMAKE_INSTALL_PREFIX=<path-to-windows-dir>
cmake --build --preset=windows
cmake --install ./build/windows
```

To compile for Windows Universal Applications, which targets both Windows Store and Windows Phone, you have to use the flags **-DCMAKE_SYSTEM_NAME=WindowsStore** and **-DCMAKE_SYSTEM_VERSION="10.0"** with the first command (the command which specifies the preset). CMAKE_SYSTEM_VERSION can be higher than 10.0, but no lower.

## MinGW

To install scifir-units inside MinGW you have to configure **MinGW** with the environment variable **MINGW64_DIR**, which sets the path to the installation directory of MinGW. Inside MinGW you need to install **icu** and **boost_system**. Then, execute the following commands:

```
cmake --preset=windows-mingw
cmake --build --preset=windows-mingw
cmake --install ./build/windows-mingw
```

## MacOS and Apple devices

scifir-units uses the XCode generator of cmake to compile for MacOS. You need to install icu and boost_system to build scifir-units inside MacOS. The commands to compile and install scifir-units inside MacOS are the following:

```
cmake --preset=macos
cmake --build --preset=macos
cmake --install ./build/macos
```

To compile scifir-units for iOS, tvOS, visionOS or watchOS you must add the flag **-DCMAKE_SYSTEM_NAME=<os-name>** to the first command (the command which specifies the preset). Optionally, you can also use the flag **-DCMAKE_OSX_ARCHITECTURES** to specify the architecture of the device or the simulator.

## vcpkg

scifir-units can be compiled with vcpkg inside every triplet of vcpkg, not only inside Windows. To do that, after installing icu and boost_system in vcpkg, use the following commands:

```
cmake --preset=vcpkg
cmake --build --preset=vcpkg
cmake --install ./build/vcpkg
```

## Android

First, set **ANDROID_HOME** and **ANDROID_NDK_ROOT** to the paths of your Android SDK installation and of your Android NDK installation. After that, install vcpkg, and set the environment variable **VCPKG_ROOT** to the installation directory of vcpkg. Set also the environment variable **VCPKG_DEFAULT_TRIPLET** to be the triplet of the computer you're using to build scifir-units. Finally, to compile scifir-units to work inside an Android application that uses Android NDK for that purpose, you have to use the following commands:

```
cmake --preset=android -DCMAKE_INSTALL_PREFIX=<path-to-android-project>
cmake --build --preset=android
cmake --install ./build/android
```

After building scifir-units you have to move the library file to your Android project. Inside Android Studio, create the JNI folder under the right-click menu of the **app folder**, under the option **New > Folder > JNI Folder**. Inside the jni folder, you should create a folder for each **Android ABI** existing, and add scifir-units there compiled for that Android ABI by using the option **-DANDROID_ABI** of this cmake configuration. Search all Android ABIs existing and compile this library for each of them, in order to have your Android application working on all Android devices.

The include path for scifir-units inside your Android Studio project should be the same as the linux distribution, vcpkg or mingw, use the same as always. The headers of scifir-units, then, as any C++ library for Android, doesn't need to be copied inside your Android project and, then, they aren't part of the final **APK file**.

## Microcontrollers

For electronics, you can build scifir-units using the compiler of your microcontroller, which comes with the SDK of your microcontroller. You have to specify, using the option **-DCMAKE_CXX_COMPILER**, the compiler to use, and, also, you have to use the option **-DCMAKE_CXX_FLAGS="-mmcu=<microcontroller-model>"** to specify the model of your microcontroller in order for your compiler to know for which microcontroller model to compile.

The SDK of microcontrollers can be downloaded on the website of the vendor of the microcontroller, which can be **Microchip**, **STMicroelectronics**, or any other.

## cpack

If you need to package scifir-units into any format supported by cpack, you just need to use the preset that you've previously used to build scifir-units.

```
cpack --preset=<your-preset> -G <generator-needed>
```

You can type the command **cpack --help** to check all available generators.

## ctest

You can test scifir-units executing ctest if you want. It's not needed to execute those tests in your local computer, but you can do it if for any reason you find it helpful. To build the tests, add the flags **-DBUILD_TESTING=ON** to the first preset command, in order to set the variable BUILD_TESTING to ON, that variable configures the build to build also all the tests.

```
ctest --preset=<your-preset> -L tests
```

In order to check the code coverage of the unitary tests, execute after that first command the following commands:

```
ctest --preset=<your-preset> -L tests -T coverage
gcovr .
```

gcovr prints the % of coverage for each piece of code, based on gcov data. You can install gcovr through apt in some Linux distributions, for other operating systems search through internet how to install gcovr there, usually it's easy.

## Generating the documentation

scifir-units uses **doxygen** to generate the documentation. In your local computer, you can have a copy of the documentation in the website of scifir-units, to do that use the following command:

```cpp
doxygen Doxyfile
```

The command generates all the documentation of doxygen inside your hard disk. You can then open the documentation in the browser, by opening the file **./docs/index.html** of the documentation generated by doxygen.

Remember that doxygen uses dox files to generate his documentation. You can view the dox files of this library in the folder **./docs/dox**.
