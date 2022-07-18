#include <lexer.h>
#include <token.h>
#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> getWords(std::string code) {
    std::vector<std::string> toRet;
    std::string buf;
    for (char codeChar : code) {
        if (codeChar == ' ' || codeChar == '\n' || codeChar == '\t' || codeChar == '\r') {
            toRet.push_back(buf);
            buf = "";
            continue;
        } else {
            buf += codeChar;
        }
    }
    return toRet;
}


std::vector<Token> tokenise(std::string code) {
    std::vector<Token> toRet;
    std::vector<std::string> words = getWords(code);

    for (std::string word : words) {
        Token token;
        if (word == "ADD") {
            token.value = "ADD";
            token.type = TT_INSTRUCTION;
            toRet.push_back(token);
        } else if (word == "SUB") {
            token.value = "SUB";
            token.type = TT_INSTRUCTION;
            toRet.push_back(token);
        } else if (word == "MUL") {
            token.value = "MUL";
            token.type = TT_INSTRUCTION;
            toRet.push_back(token);
        } else if (word == "DIV") {
            token.value = "DIV";
            token.type = TT_INSTRUCTION;
            toRet.push_back(token);
        } else if (word == "AND") {
            token.value = "AND";
            token.type = TT_INSTRUCTION;
            toRet.push_back(token);
        } else if (word[0] == 'R' || word[0] == '$') {
            token.value = word;
            token.type = TT_REG;
            toRet.push_back(token);
        } else {

            std::cout << "Unknown token: " << word << '\n';
        }
    }
    

    return toRet;
}