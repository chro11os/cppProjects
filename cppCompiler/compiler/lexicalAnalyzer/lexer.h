#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include "Token.h"

// Lexer class responsible for tokenizing input source code
class Lexer {
public:
    // Constructor that initializes the lexer with source code input
    explicit Lexer(const std::string& sourceCode);

    // Function to retrieve the next token in the input
    Token nextToken();

private:
    std::string sourceCode; // The source code to tokenize
    size_t currentIndex;    // Current index in the source code
    int lineNumber;         // Current line number for error tracking

    // Helper functions for lexical analysis
    char peek() const;           // Peek at the current character without consuming it
    char advance();              // Advance to the next character and return the current one
    void skipWhitespace();       // Skip over whitespace characters
    Token identifierOrKeyword(); // Recognize keywords or identifiers
    Token number();              // Recognize numerical literals
    Token symbol();              // Recognize operators and symbols
};

#endif // LEXER_H
