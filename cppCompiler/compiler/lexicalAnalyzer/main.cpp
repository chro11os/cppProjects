// Lexical Analyzer
// Created by chro11os on 10/11/24.

#include "token.h"
#include <iostream>
#include <cctype>
#include <string>

class Lexer {
private:
    std::string source;
    size_t index;

public:
    Lexer(std::string source) : source(source), index(0) {}

    bool isEnd() const {
        return index >= source.size();
    }

    Token getNextToken() {
        while(!isEnd() && std::isspace(source[index])) {
            index++;
        }

    if (isEnd()) {
        return Token(TokenType::END_OF_FILE, "");
    }

    char currentChar = source [index];

    if (std::isdigit(currentChar)) {
        std::string numStr;
        while (!isEnd() && std::isdigit(source[index])) {
            numStr += source[index++];
        }
        return Token(TokenType::NUMBER, numStr);
    }

    if (std::isalpha(currentChar)) {
        std::string identifier;
        while (!isEnd()) && std::isalnum(source[index])) {
            identifier += source[index++];
        }
    }

    }

}


