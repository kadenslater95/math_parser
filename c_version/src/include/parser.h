#ifndef PARSER_H

#define PARSER_H

#ifdef __cplusplus
extern "C" {
#endif


#include "tokenizer.h"


typedef struct ASTNode {
    Token value;
    struct ASTNode* parent;
    struct ASTNode** children;
} ASTNode;


ASTNode* parse(Token**);



#ifdef __cplusplus
}
#endif

#endif