
add_executable(
  tokenizer_test
  digits_test.cpp
  operator_test.cpp
  name_test.cpp
)

gtest_discover_tests(tokenizer_test)
