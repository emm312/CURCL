#ifndef LEXER_H
#define LEXER_H
#include <string.h>
#include <vector>
#include <token.h>


std::vector<Token> tokenise(std::string code);

#endif