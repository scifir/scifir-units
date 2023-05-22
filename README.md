# MagickScience

Hello! MagickScience is a scientific library for developing lab machines. It provides units, molecules, among other features, to allow developers of scientific software to develop their software easily. Enjoy!

MagickScience is under development, but the units are already released. Molecules aren't, but they will by ready soon!

## Units

MagickScience includes special units to use, then it's unneeded to care about having the proper dimensions and prefixes when developing scientific software. Learn how to use them at the [Wiki](https://github.com/Iarfen/MagickScience/wiki/).

## Atoms and molecules

MagickScience has atoms and molecules to use inside scientific software! It's under development, but a big amount is ready. It'll be completed in some months!

## Team

MagickScience is developed by [Ismael Correa](https://github.com/Iarfen/), a software developer of 27 years old. You can email if you find bugs, request new features, or have any other need, at ismael.correa.castro@gmail.com.

## Example of use

### Angle
An angle object manages angles. It stores angles in grades, rather than in radians. It can be initialized to any grade between 0 and 360 (without including 360, cause this is identical to 0 in meaning), and any initialization that's not inside this range of values gets automatically converted inside it, to his equivalent value between the range.

An example of use of angle is the following:

// Constructors and instantiation
angle y = 54; // Better constructor! Preferred method
angle a = 367; // Gets converted to the value 7, because 7 is the equivalent of 367 inside 0 and 360
angle b = angle(12);
angle c = angle(34_Pa);
angle x = 73_angle; // Not the most optimum constructor, but equally supported
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
