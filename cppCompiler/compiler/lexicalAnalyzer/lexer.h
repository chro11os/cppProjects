#ifndef LEXER_H
#define LEXER_H

#include "Token.h"
#include <vector>
#include <string>

class Lexer {
public:
    Lexer(const std::string& sourceCode); // Constructor
    void tokenize(); // Tokenizes the source code
    Token nextToken(); // Retrieve the next token
    std::vector<Token> getTokens() const { return tokens; }

private:
    std::string sourceCode;
    size_t currentPosition;
    int lineNumber;
    std::vector<Token> tokens;
    size_t tokenIndex = 0; // Track position in the tokens vector

    void advance(); // Moves to the next character
};

#endif // LEXER_H
