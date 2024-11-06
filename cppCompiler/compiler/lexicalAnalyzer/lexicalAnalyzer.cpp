#include "Token.h"
#include "lexer.h"   // Include the Lexer header
#include <cctype>    // For isdigit, isalpha
#include <iostream>
#include <string>


Lexer::Lexer(std::string source) : source(source), index(0) {}

bool Lexer::isEnd() const {
    return index >= source.size();
}

Token Lexer::getNextToken() {
    while (!isEnd() && std::isspace(source[index])) {
        index++;
    }

    if (isEnd()) {
        return Token(TokenType::END_OF_FILE, "");
    }

    char currentChar = source[index];

    if (std::isdigit(currentChar)) {
        std::string numStr;
        while (!isEnd() && std::isdigit(source[index])) {
            numStr += source[index++];
        }
        return Token(TokenType::NUMBER, numStr);
    }
    if (std::isalpha(currentChar)) {
        std::string identifier;
        while (!isEnd() && std::isalnum(source[index])) {
            identifier += source[index++];
        }
        if (identifier == "if" || identifier == "else" || identifier == "while") {
            return Token(TokenType::KEYWORD, identifier);
        }
        return Token(TokenType::IDENTIFIER, identifier);
    }

    if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
        index++;
        return Token(TokenType::OPERATOR, std::string(1, currentChar));
    }

    if (currentChar == '(' || currentChar == ')' || currentChar == ';') {
        index++;
        return Token(TokenType::PUNCTUATION, std::string(1, currentChar));
    }

    index++;
    return getNextToken();
}