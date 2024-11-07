#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
    KEYWORD,
    IDENTIFIER,
    OPERATOR,
    LITERAL,
    ASSIGNMENT,
    END_OF_FILE,
    UNKNOWN
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
