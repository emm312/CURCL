#include <lexer.h>
#include <token.h>
#include <transpiler.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <util.h>

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


int main(int argc, char* argv[]) {
    std::ifstream inputFileStream(argv[1]);
    std::string str;
    std::string src;
	while(std::getline(inputFileStream, str))
	{
		auto _toks = split(str, ' ');
		
		for (auto tok: _toks)
		{
			tok = replace(tok, "\t", "");

			src += tok + ' ';
		}

		src += '\n';
	}
    inputFileStream.close();

    std::cout << src << std::endl;

    std::vector<Token> tokens = tokenise(src);


    
    for (Token token : tokens) {
        std::cout << enumToStr(token.type) << " " << token.value << " " << "\n";
    }

}