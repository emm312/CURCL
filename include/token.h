#ifndef TOKEN_H
#define TOKEN_H
#include  <string>
enum TokenTypes {
    TT_INSTRUCTION,
    TT_IMMEDIATE,
    TT_LABEL,
    TT_DW,
};

struct Token {
    TokenTypes type;
    std::string value;
    unsigned int lineno;
};

#endif