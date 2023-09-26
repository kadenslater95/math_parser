#ifndef TOKENIZER_H

#define TOKENIZER_H

#ifdef __cplusplus
extern "C" {
#endif


typedef enum {
    TOKEN_DIGITS,
	TOKEN_DECIMAL,

    TOKEN_OPERATOR,

    TOKEN_LPAREN,
    TOKEN_RPAREN,

    // Could be a Variable, Could be a Function, etc.
    // Allows Alphabetic, _, and still deciding if others
    TOKEN_NAME,

    TOKEN_UNKNOWN
} TokenType;


typedef struct {
    TokenType type;
    char* value;
} Token;


Token* tokenize(const char*, int*);

void freeTokens(Token*, int);

void printTokens(Token*, int);


#ifdef __cplusplus
}
#endif

#endif