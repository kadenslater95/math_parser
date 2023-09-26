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

Then you can go into any test subfolder e.g. `debug/test/tokenizer_tests` and run
```
ctest
```
to run the tests.
Or, to run individual tests (such as DigitsTest) you can use
```
./tokenizer_test --gtest_filter=DigitsTest.*
```
depending on what the executable was called, but the naming convention is to match the singular version of the pluralized folder name.

The math_parser lib is located in `debug/src` as `libmath_parser.so`

