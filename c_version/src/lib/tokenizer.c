
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "tokenizer.h"




bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


Token* tokenize(const char* raw, int* tokenCount) {
    int rawLen = strlen(raw);
    Token* tokens = (Token*)malloc(rawLen * sizeof(Token));
    int tokenIndex = 0;

    for (int raw_i = 0; raw_i < rawLen; raw_i++) {
        // Skip whitespace characters
        if (isspace(raw[raw_i])) {
            continue;
        }

        // Check if it's a number
        if (isdigit(raw[raw_i])) {
            int raw_j = raw_i;
            while (raw_j < rawLen && isdigit(raw[raw_j])) {
                raw_j++;
            }

            int tokenLen = raw_j - raw_i;
            tokens[tokenIndex].type = TOKEN_DIGITS;
            tokens[tokenIndex].value = (char*)malloc(tokenLen + 1);
            strncpy(tokens[tokenIndex].value, raw + raw_i, tokenLen);
            tokens[tokenIndex].value[tokenLen] = '\0';
            raw_i = raw_j - 1; // Move the index to the end of the number
        }
		// Check if it's a decimal
		else if(raw[raw_i] == '.') {
			tokens[tokenIndex].type = TOKEN_DECIMAL;
            tokens[tokenIndex].value = (char*)malloc(2);
            tokens[tokenIndex].value[0] = '.';
            tokens[tokenIndex].value[1] = '\0';
		}
        // Check if it's an operator
        else if (isOperator(raw[raw_i])) {
            tokens[tokenIndex].type = TOKEN_OPERATOR;
            tokens[tokenIndex].value = (char*)malloc(2);
            tokens[tokenIndex].value[0] = raw[raw_i];
            tokens[tokenIndex].value[1] = '\0';
        }
        // Check for parentheses
        else if (raw[raw_i] == '(') {
            tokens[tokenIndex].type = TOKEN_LPAREN;
            tokens[tokenIndex].value = (char*)malloc(2);
            tokens[tokenIndex].value[0] = '(';
            tokens[tokenIndex].value[1] = '\0';
        } else if (raw[raw_i] == ')') {
            tokens[tokenIndex].type = TOKEN_RPAREN;
            tokens[tokenIndex].value = (char*)malloc(2);
            tokens[tokenIndex].value[0] = ')';
            tokens[tokenIndex].value[1] = '\0';
        } else {
            tokens[tokenIndex].type = TOKEN_UNKNOWN;
            tokens[tokenIndex].value = NULL;
        }

        tokenIndex++;
    }

    *tokenCount = tokenIndex;
    return tokens;
}


void freeTokens(Token* tokens, int tokenCount) {
    for (int i = 0; i < tokenCount; i++) {
        free(tokens[i].value);
    }
    free(tokens);
}



char* stringTokenType(TokenType type) {
	if(type == TOKEN_DIGITS) {
		return "TOKEN_DIGITS";
	}
	if(type == TOKEN_DECIMAL) {
		return "TOKEN_DECIMAL";
	}
	if(type == TOKEN_OPERATOR) {
		return "TOKEN_OPERATOR";
	}
	if(type == TOKEN_LPAREN) {
		return "TOKEN_LPAREN";
	}
	if(type == TOKEN_RPAREN) {
		return "TOKEN_RPAREN";
	}

	return "TOKEN_UNKNOWN";
}


void printTokens(Token* tokens, int tokenCount) {
	for(int i = 0; i < tokenCount; i++) {
		printf("{\n\tIndex: %d,\n\tTokenType: %s,\n\tValue: %s\n}", i, stringTokenType(tokens[i].type), tokens[i].value);
	}
}
