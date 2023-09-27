
#include "math_parser.h"


int main(int argc, char** argv) {
    const char* expression = "Curve(5.0*cos(3.14*t + 0.5) + 2.5, 5.0*sin(3.14*t + 0.5) + 2.5, t, 0 <= t < 6.28)";
    
    int tokenCount;
    Token* tokens = tokenize(expression, &tokenCount);

    printTokens(tokens, tokenCount);

    freeTokens(tokens, tokenCount);

    return 0;
}

