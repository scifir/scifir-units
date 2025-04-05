# Code examples

## Molecules synthetizer

A **molecules synthetizer** is any scientific machines that automates a chemical synthesis.

A simple example of a molecules synthetizer that automates a chemical reaction between molecule A and molecule B, allowing to select between three different sets of quantities to synthetise, is the following code:

```cpp
// molecules_synthetizer.hpp

void synthetize_molecules();

// molecules_synthetizer.cpp

using namespace scifir;

void synthetize_molecules()
{
	mass mass_molecule_a;
	mass mass_molecule_b;
	if (amount == 1_g)
	{
		mass_molecule_a = 0.8_g;
		mass_molecule_b = 0.2_g;
	}
	else if (amount == 20_g)
	{
		mass_molecule_a = 16_g;
		mass_molecule_b = 4_g;
	}
	else if (amount == 100_g)
	{
		mass_molecule_a = 80_g;
		mass_molecule_b = 20_g;
	}
	// Rest of the function, it's needed to open the valves of molecule_a and molecule_b to release the amount of mass specified for each molecule
}
```

## Movement of a robot

The software of a **robot** can use scifir-units to handle the movement with units of measurement, angles, coordinates, etc. It's very helpful for a robot to use units of measurement, because then the program of the robot is more easy to understand and more precise. Also, the programming of it is simplified.

```cpp
// arms.hpp

using namespace scifir;

class robot_arm
{
	public:
		robot_arm();
		robot_arm(const angle& new_elbow_angle);

		angle elbow_angle;
};

// robot.hpp

void move_arms();

// arms.cpp

#include "arms.hpp"

using namespace scifir;

robot_arm::robot_arm() : elbow_angle()
{}

robot_arm::robot_arm(const angle& new_elbow_angle) : elbow_angle(new_elbow_angle)
{}

// robot.cpp

#include "robot.hpp"

using namespace scifir;

void move_arms()
{
	robot_arm left_robot_arm = robot_arm();
	left_robot_arm.elbow_angle = 180_degree; // The left elbow will be flat
	robot_arm right_robot_arm = robot_arm();
	right_robot_arm.elbow_angle = 90_degree; // The right elbow will be folded in 90 degrees
}
```

## Calculating angles in robots

To calculate angles in robots can be very helpful, it allows to do calculations of movement, among other calculus of physics, easily. To calculate the angles, you can use the function scifir::angle_between(), given the coordinates inside the space of two different entities.

```cpp
// robot.hpp

void calculate_angle();

// robot.cpp

#include "robot.hpp"

using namespace scifir;

void calculate_angle()
{
	coordinates_3d object_a; // With some system, which can be AI or GPS, set the coordinates of object_a
	coordinates_3d object_b; // With some system, which can be AI or GPS, set the coordinates of object_b
	angle angle_objects = angle_between(vector_unit_3d::cartesian_3d(object_a.x,object_a.y,object_a.z),vector_unit_3d::cartesian_3d(object_b.x,object_b.y,object_b.z));
}
```

## Math intervals for fields

Adding a math interval to a field of scifir-units is easy. Just add it inside a conditional if statement, testing if the values of the parameters are inside the interval. An example is the following:

```cpp
scalar_field_3d<length,length> a([](const length& x,const length& y,const length& z) -> length { 
	if (x >= 2_m and x <= 5_m and y >= 1_m and y <= 8_m and z >= 3_m and z <= 15_m)
	{
		return (x + 2*y + 5*z);
	}
});
```

## Using mEq

The dimension **mEq** is called **milli-equivalent**, and it corresponds to the amount of mg that are equivalent to an arbitrary amount of another substance in a given chemical reaction. To get the amount of mg needed of a substance, use the mEq of the given chemical reaction with the following math formula:

$$mEq\frac{MW}{V}$$

Where mEq is the **mEq of the given chemical reaction**, MW is the **molecular weight** of the new substance to use as equivalent to the original substance (of which we have calculated the mEq we are using), and V is the **valence** of the new substance.

An example in code that uses mEq is the following:

```cpp
// mEq.hpp

void calculate_mEq_potassium_reaction();

// mEq.cpp

using namespace scifir;

void calculate_mEq_potassium_reaction()
{
	scalar_unit mEq_potassium_reaction = 20_mEq;
	mass mass_potassium_citrate_monohydrate = mass(mEq_potassium_reaction*324.0f/3,"mg"); // You need to set the MW of the potassium citrate monohydrate, which is 324, and the V of it, which is 3
	mass mass_potassium_gluconate  = mass(mEq_potassium_reaction*234.245f/1,"mg"); // You need to set the MW of the potassium citrate monohydrate, which is 324, and the V of it, which is 3
}
```

## Using the dimension "money"

The dimension money can represent any currency. So, to use it, just select the currency of some country to use as equivalent to 1 money, and convert it to any other currency using the current exchange rate of currencies, which, as you should know of banks, varies every day. Use a web service to get the exchange rate of every currency updated daily.

Remember to use the **ISO 4217 of currencies** to know the abbreviation codes of each currency.

```cpp
scalar_unit a("100 money");
cout << "Money (USD): " << a.get_value() << " USD" << endl; // Prints the money in USD
cout << "Money (CLP): " << (a.get_value() * 750) << " CLP" << endl; // Prints the money in CLP, with an exchange rate of 1 USD to 750 CLP
```
