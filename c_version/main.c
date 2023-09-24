
#include "math_parser.h"


int main(int argc, char** argv) {
    const char* expression = "3.14 + (2 * 5)";
    
    int tokenCount;
    Token* tokens = tokenize(expression, &tokenCount);

    printTokens(tokens, tokenCount);

    freeTokens(tokens, tokenCount);

    return 0;
}

