## Consumption of memory

scifir-units is a very lightweight library, all classes require just some bytes to work. Then, it can be used in any electronics project, because the memory requirements can be meet.

The prefix class sizes 1 byte. The dimension class sizes 6 bytes.

The scalar_unit and vector unit classes, vector_unid_2d, vector_unid_3d and vector_unit_nd size more than a single float, which uses 4 bytes, but don't size a big amount and so, they can be used in great quantities for any purpose, cause they are very lightweight.

The angle class uses only 4 bytes, and works perfectly fine, very similar to a normal float. Then, you can use it freely every time you need to do calculations that need angles.

The coordinates classes have as member-variables scalar_unit classes, and then they size the bytes of the scalar_unit classes, for each scalar_unit class they have.