#ifndef TOKEN_H
#define TOKEN_H
enum TokenTypes {
    TT_INSTRUCTION,
    TT_IMMEDIATE,
    TT_LABEL,
};
typedef enum TokenTypes TokenTypes;

struct Token {
    TokenTypes type;
    char* value;
};
typedef struct Token Token;

#endif