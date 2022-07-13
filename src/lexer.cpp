#include <lexer.h>
#include <token.h>
#include <vector>
#include <string>
#include <cctype>
#include <iostream>
#include <bits/stdc++.h>


std::vector<Token> tokenise(std::string code) {
    unsigned int line_number;
    bool isDW = false;
    std::string buffer;
    std::vector<Token> tokens;
    bool isBuffering = false;
    for (char character : code) {
        character = std::tolower(character);

        std::vector<std::string> instructions;
        instructions.push_back("add");
        instructions.push_back("rsh");
        instructions.push_back("lod");
        instructions.push_back("str");
        instructions.push_back("bge");
        instructions.push_back("nor");
        instructions.push_back("imm");
        instructions.push_back("in");
        instructions.push_back("out");
        instructions.push_back("dw");
        if (isBuffering) {
            if (isDW) {
            buffer += character;
            } else if (character == ']') {
                isDW = false;
                tokens.push_back(Token{TT_DW, buffer, line_number});
            }
            else if (character == '\n') {
                line_number++;
                if (isDW) {
                    std::cerr << "Not a valid DW instruction" << "\n";
                    exit(-1);
                }
                isDW = false;
                buffer = "";
                isBuffering = false;
            }
        }
        if (character == '\n') {
            line_number++;
            if (isDW) {
                std::cerr << "Not a valid DW instruction" << "\n";
                exit(-1);
            }
            isDW = false;
            buffer = "";
        } else if (character == '[') {
            isDW = true;
        } else if (character == ' ') {
            continue;
        } /* check if a instruction is in the buffer */ else if (std::find(instructions.begin(), instructions.end(), buffer) != instructions.end()) {
            tokens.push_back(Token{TT_INSTRUCTION, buffer, line_number});
            buffer = "";
        } else {
            isBuffering = true;
        } 
    }
    return tokens;
}