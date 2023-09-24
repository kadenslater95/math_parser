# math_parser
Project intended for learning about parsing, and to be used with a separate Plotter project.

I will first make an Arithmetic Parser, then incrementally build up from there.

There is a <b>c_version</b> for now with the whole project built in C, and later I will make a C++ version that uses Object Oriented features, the Standard Template Library, etc.


### Usage
From the Project root directory,
```
cd c_version
```
to go into the root directory for the c_version of this parser. 
Run cmake from this c_version directory
```
cmake -S . -B build
cmake --build build
```

Then you can go into `build/test` and run
```
ctest
```
to run the tests.

The math_parser lib is located in `build/src` as `libmath_parser.so`

