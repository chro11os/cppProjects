#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
    IDENTIFIER, NUMBER, STRING_LITERAL,
    INT, FLOAT, BOOL, STRING,
    COUT, CIN,
    PLUS, MINUS, MULTIPLY, DIVIDE,
    ASSIGN, SEMICOLON,
    LEFT_SHIFT, RIGHT_SHIFT,
    END_OF_FILE, ERROR
};

struct Token {
    TokenType type;
    std::string lexeme;
};

#endif // TOKEN_H
