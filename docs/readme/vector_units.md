# Vector units - scifir-units

A vector unit class is any class derived of a vector_unit class, and all the vector_unit classes by themselves. The vector_unit classes are vector_unit_2d, vector_unit_3d and vector_unit_nd. They vary in the amount of space dimensions they are being part, 2d is for two-dimensions, 3d is for three-dimensions, and nd is for a variable number of dimensions when already executing a program with scifir-units, which can be one, two or three, but not all those three options at the same moment.

Vector unit classes behave like scalar unit classes, you can sum, substract and calculate the product of vector unit classes operating them with other vector unit classes.

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