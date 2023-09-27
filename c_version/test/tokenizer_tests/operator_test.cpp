
#include <gtest/gtest.h>

#include "math_parser.h"


TEST(OperatorTest, Multiplication) {
  const char* expression = "2 * 5";

  int tokenCount;
  Token* tokens = tokenize(expression, &tokenCount);

  EXPECT_EQ(tokens[1].type, TOKEN_OPERATOR);
  EXPECT_STREQ(tokens[1].value, "*");

  freeTokens(tokens, tokenCount);
}


TEST(OperatorTest, Parentheses) {
  const char* expression = "(3 + 4) * 5";

  int tokenCount;
  Token* tokens = tokenize(expression, &tokenCount);

  EXPECT_EQ(tokens[0].type, TOKEN_LPAREN);
  EXPECT_STREQ(tokens[0].value, "(");

  EXPECT_EQ(tokens[4].type, TOKEN_RPAREN);
  EXPECT_STREQ(tokens[4].value, ")");

  freeTokens(tokens, tokenCount);
}


TEST(OperatorTest, Interval) {
  const char* expression = "0 <= x < 7";

  int tokenCount;
  Token* tokens = tokenize(expression, &tokenCount);

  EXPECT_EQ(tokens[1].type, TOKEN_OPERATOR);
  EXPECT_STREQ(tokens[1].value, "<");

  EXPECT_EQ(tokens[2].type, TOKEN_OPERATOR);
  EXPECT_STREQ(tokens[2].value, "=");

  EXPECT_EQ(tokens[4].type, TOKEN_OPERATOR);
  EXPECT_STREQ(tokens[4].value, "<");

  freeTokens(tokens, tokenCount);
}

