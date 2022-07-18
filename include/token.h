#ifndef TOKEN_H
#define TOKEN_H
#include  <string>
enum TokenTypes {
    TT_INSTRUCTION,
    TT_IMMEDIATE,
    TT_LABEL,
    TT_DW,
    TT_REG,
    TT_MEM,
};

struct Token {
    TokenTypes type;
    std::string value;
};

#endif