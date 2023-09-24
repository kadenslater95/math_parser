# math_parser
Project intended for learning about parsing, and to be used with a separate Plotter project. I will first make an Arithmetic Parser, then incrementally build up from there.

### Usage
Run cmake from project root
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

