
#include <gtest/gtest.h>

#include "math_parser.h"


TEST(DigitsTest, Integer) {
  const char* expression = "25";

  int tokenCount;
  Token* tokens = tokenize(expression, &tokenCount);

  EXPECT_EQ(tokens[0].type, TOKEN_DIGITS);
  EXPECT_STREQ(tokens[0].value, "25");

  freeTokens(tokens, tokenCount);
}


TEST(DigitsTest, Decimal) {
  const char* expression = "3.14";

  int tokenCount;
  Token* tokens = tokenize(expression, &tokenCount);

  EXPECT_EQ(tokens[0].type, TOKEN_DIGITS);
  EXPECT_STREQ(tokens[0].value, "3");

  EXPECT_EQ(tokens[1].type, TOKEN_DECIMAL);
  EXPECT_STREQ(tokens[1].value, ".");

  EXPECT_EQ(tokens[2].type, TOKEN_DIGITS);
  EXPECT_STREQ(tokens[2].value, "14");

  freeTokens(tokens, tokenCount);
}
