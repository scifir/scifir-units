# Portability

## scifir-units in other programming languages

Although scifir-units currently is only available in C++, it can be created in other programming languages. So, if you need this library in other programming languages, just copy the classes you need and change them to be in the other programming language. For java, for example, copying angle class, the name would be Angle, because of the nomenclature of java, and all functions should be identical in behaviour, but in camelCase as name, because that's the format of java. For example, in java, get_value() would be called getValue(). For normal functions, in java, you need to add them inside the class and make them static, because java doesn't supports functions outside classes.

So, to create the **equivalent library** of scifir-units in another programming language, just copy the same API changing the format of the code to follow the code format of the programming language to which you're replicating the library. The names of the functions equivalent to the special operators are instead, for other programming languages, the functions sum(), substract(), multiply() and divide(). Use increment() and decrement() for the operator ++() and the operator --(), respectively.
