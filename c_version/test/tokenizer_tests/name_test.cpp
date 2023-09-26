
#include <gtest/gtest.h>

#include "math_parser.h"


TEST(NameTest, Variable) {
  const char* expression = "z = 25 + x*y";

  int tokenCount;
  Token* tokens = tokenize(expression, &tokenCount);

  EXPECT_EQ(tokens[0].type, TOKEN_NAME);
  EXPECT_STREQ(tokens[0].value, "z");

  EXPECT_EQ(tokens[4].type, TOKEN_NAME);
  EXPECT_STREQ(tokens[4].value, "x");

  EXPECT_EQ(tokens[6].type, TOKEN_NAME);
  EXPECT_STREQ(tokens[6].value, "y");

  freeTokens(tokens, tokenCount);
}


TEST(NameTest, Function) {
  const char* expression = "5*sin(g(x))";

  int tokenCount;
  Token* tokens = tokenize(expression, &tokenCount);

  EXPECT_EQ(tokens[2].type, TOKEN_NAME);
  EXPECT_STREQ(tokens[2].value, "sin");

  EXPECT_EQ(tokens[4].type, TOKEN_NAME);
  EXPECT_STREQ(tokens[4].value, "g");

  freeTokens(tokens, tokenCount);
}


TEST(NameTest, Tool) {
  const char* expression = "Curve(x^2, x, -3, 3)";

  int tokenCount;
  Token* tokens = tokenize(expression, &tokenCount);

  EXPECT_EQ(tokens[0].type, TOKEN_NAME);
  EXPECT_STREQ(tokens[0].value, "Curve");

  freeTokens(tokens, tokenCount);
}
