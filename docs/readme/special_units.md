# Special units - scifir-units

## pixel

The **pixel** class represents pixels, which are the squares that compose screens. It can be used to calculate distance over pixels instead of distances of physical lengths, which is a need of some digital applications.

## pH and pOH

The **pH** class allows to work with pH, which is used inside chemistry software to store data about pH. The **pOH** class is the counterpart of the pH class, and is not commonly needed, but it can be used if the pH class is not being useful for some reason, and if instead the pOH class is useful. The pH class should always be **prefered** to be used over the pOH class, and that last should be used **only** if the pH class is not properly solving the needs.

## Sizes in 2D, 3D and ND

The **size_2d** class allows to store the data of the width and height of an object in length classes. The **size_3d** allows to store the data of the width, the height and the depth of an object in length classes. The **size_nd** class allows to store lengths corresponding to the dimension of an object in a variable number of dimensions.
