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


bool isNumber(const std::string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
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
        } else if (word[0] == '.' || word[1] == '.') {
            token.value = word;
            token.type = TT_LABEL;
            toRet.push_back(token);
        } else if (word[0] == '#') {
            token.value = word;
            token.type = TT_MEM;
            toRet.push_back(token);
        } else if (word == "\n" || word == "\r" || word == "\t" || word == "\r\n") {
            continue;
        } else {
            if (isNumber(word)) {
                token.value = word;
                token.type = TT_IMMEDIATE;
                toRet.push_back(token);
            } else {
                std::cout << "Unknown token: " << word << std::endl;
            }
        }
    }
    return toRet;
}