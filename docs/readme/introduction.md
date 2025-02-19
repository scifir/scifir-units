# Introduction - scifir-units

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