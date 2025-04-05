# Meca numbers - scifir-units

A meca number is how is called inside scifir-units any number that behaves in a mechanic way. The angle, for example, returns to 0 when arrives to the value 360, and then it behaves mechanically instead of behaving like other normal numbers.

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

## percentage

The **percentage** class represents percentages, they calculate the factor of the percentage and automatically, when operating with numeric types, calculate the percentage of that number.