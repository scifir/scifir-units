# Internals

Internally, the library has some important mechanisms important to be known by a serious developer. Those important mechanisms are described here, in order to avoid the developer to read the code of the library and learn every detail.

The first important mechanism to describe is the static storage of custom dimensions. This storage is static, meaning that every time a unit of a dimension not registered is created, this storage is the one used, instead of the name being stored inside the instance. With that behavior, when instantiating a big amount of dimensions, a big amount of memory is saved. To refer to the static storage it's used the char symbol[3] of the dimension class, which uses only 3 bytes instead of the bytes the full dimension name would use. Then, each instance of a dimension class, given that static storage, uses only 6 bytes of memory.

The square of dimensions works in the following way: If the dimension consist only of one type of dimension, independently as if the dimension is a base dimension or a special name, the dimensions get squared. If the dimension is of more than one type, all the special names are then converted to their derived types, and the total result gets squared. If the dimensions can't be squared because there's an odd number of them, the dimensions are then initialized empty.
