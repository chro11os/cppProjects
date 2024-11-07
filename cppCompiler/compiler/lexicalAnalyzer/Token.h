#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
    KEYWORD = 1,
    IDENTIFIER = 1,
    OPERATOR = 2,
    LITERAL = 3,
    ASSIGNMENT = 4,
    SEMICOLON = 5,
    END_OF_FILE = 6,
    UNKNOWN = 7
};

class Token {
public:
    TokenType type;
    std::string lexeme;
    int lineNumber;

    // Default constructor
    Token() : type(TokenType::UNKNOWN), lexeme(""), lineNumber(0) {}

    // Parameterized constructor
    Token(TokenType type, const std::string& lexeme, int lineNumber)
        : type(type), lexeme(lexeme), lineNumber(lineNumber) {}
};

#endif // TOKEN_H
