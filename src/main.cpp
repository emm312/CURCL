#include <lexer.h>
#include <token.h>
#include <transpiler.h>
#include <string.h>
#include <vector>
#include <iostream>


int main() {
    std::string code = "add\nimm";
    std::vector<Token> tokens = tokenise(code);
    for (Token token : tokens) {
        std::cout << token.type << " " << token.value << " " << token.lineno << "\n";
    }

}