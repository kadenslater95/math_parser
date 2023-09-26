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
cmake -S . -B debug
cmake --build debug
```

Then you can go into `debug/test` and run
```
ctest
```
to run the tests.
Or, to run individual tests (such as NumberTest) you can use
```
./math_parser_test --gtest_filter=NumberTest.*
```
.

The math_parser lib is located in `debug/src` as `libmath_parser.so`

