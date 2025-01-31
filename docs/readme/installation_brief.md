# Installation

- Supported compilers: g++, clang++ msvc, nvcc, dpcpp, (C++ compilers for microcontrollers).
- Required libraries: icu, boost-system, catch2 (optional, if you want to test with ctest).

```bash
cmake --preset=linux // Use windows,mingw,macos,vcpkg or android, depending on your platform
cmake --build --preset=linux
cmake --install ./build/linux
```

If you need it, read [extensive installation instructions](https://github.com/scifir/scifir-units/tree/master/docs/readme/installation.md).

## scifir-units in your project

Inside your **CMakeLists.txt** file add:

```cmake
target_link_libraries(your-project scifir-units)
```

Include the header:

```cpp
#include "scifir/units.hpp"

using namespace scifir; // Optional
```
