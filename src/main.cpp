#include <lexer.h>
#include <token.h>
#include <transpiler.h>
#include <string.h>
#include <vector>
#include <iostream>

std::string enumToStr(TokenTypes tok) {
    switch (tok) {
        case TT_INSTRUCTION:
            return "INSTRUCTION";
        case TT_REG:
            return "REGISTER";
        case TT_IMMEDIATE:
            return "IMMEDIATE";
        case TT_LABEL:
            return "LABEL";
        default:
            return "UNKNOWN";
        
    }
}


int main() {
    std::string code = "ADD R1 R2 R3 r1";
    std::vector<Token> tokens = tokenise(code);
    std::cout << tokens.size() << '\n';
    for (Token token : tokens) {
        std::cout << enumToStr(token.type) << " " << token.value << " " << "\n";
    }

}