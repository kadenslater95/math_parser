# math_parser
Project intended for learning about parsing, and to be used with a separate Plotter project.

I will first make an Arithmetic Parser, then incrementally build up from there.


#### Note
Code highlighter might show red, depending on how you have things set up. Cmake can build this just fine, but the code highlighter thinks it can't find gtest include, etc. because cmake brings it in behind the scenes so it highlights red but still compiles.


## Usage
From the project root directory run cmake
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

