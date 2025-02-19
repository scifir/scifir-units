# Coordinates and points - scifir-units

Coordinates in scifir-units are **lightweight**, they only instantiate the three variables x, y and z of cartesian coordinates and, the better of them, they allow with only those three variables to have at the same time all the coordinates systems of the corresponding number of dimensions inside a single coordinates class. Then, for example, coordinates_3d can work at the same time as cartesian, as cylindrical, as spherical, and as geodesical coordinates.

The coordinates of scifir-units are intended, then, to work generically in any kind of science project, that is their central purpose.

The coordinates systems of each coordinates class are the following:

- **coordinates_3d:** cartesian 3d, cylindrical, spherical, geodesical.
- **coordinates_2d:** cartesian 2d, polar.
- **coordinates_nd:** All coordinates systems of coordinates_3d and of coordinates_2d.

coordinates classes can be diplayed in any of their systems of coordinates that they support, and can be added and substracted like any scalar_unit class. Their x, y and z variables are length classes or, for imaginary spaces, scalar_unit classes with an imaginary dimension. Imaginary dimensions are used for some purposes inside quantum physics and relativity, and then they are supported inside scifir-units.

Each coordinates class has an equal **point class** that can be used when there's more than one center of coordinates for an object. Point classes and coordinates classes are equal in all their ther aspects, except for their name.

## Coordinates and points in 3D

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

## Coordinates and points in 2D

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

## aid and zid

An **aid**, acronym of **Astronomycal ID**, is an identifier of an astronomical object, like planets, moons, galaxies, stars, and any other astronomical object. For example, the aid of the Earth is **"(P) milky-way:solar-system:earth"**.

A **zid**, acronym of **Zone ID**, is an identifier of a zone, like a region, a district, a store, a lake, a country, and any other zone. A zone is defined here as any closed surface that can be drawn over an astronomycal object. A ZID is composed of the AID of which the zone pertains, and the zone itself. For example, the zid of Las Condes in Chile is **"(P) milky-way:solar-system:earth chile:region-metropolitana:santiago:las-condes"**.

## Addresses

## Extra - Coordinates and points in 1D

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