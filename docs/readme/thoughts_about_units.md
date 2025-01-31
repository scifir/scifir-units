# Thoughts about units

## Interpretation of composite dimensions

Composite dimensions, inside scifir-units, are the dimensions when there's more than one base dimension present. Their interpretation is as follows: the m means it's through a trajectory, the m2 means it's  through a surface, and the m3 means it's through a volume. The second in the denominator means it's per second, the s2 means it's an increase per second of something that happens each second.

Then, the energy, which has the dimensions kg*m2/s2 means the following: the increment per second of mass inside a surface increasing per second.

## Area and volume dimensions

**Area** and **volume**, as thinked by the author of this library, can be considered simple or composite dimensions, depending on the point of view. From the point of view that's used inside the SI system of units, they are composite dimensions because there's more than one base dimension. From another point of view, it can be thinked that, given the fact that the same dimension is present with an exponent, then it's just a simple dimension. With this in mind, it can be thinked a unitary square and a unitary cube as the base of this simple dimension.
