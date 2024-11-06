//
// Created by chro11os on 10/11/24.
//

#ifndef TOKEN_H
#define TOKEN_H
#include <string>


enum TokenType {
    KEYWORD, IDENTIFIER, NUMBER, OPERATOR, PUNCTUATION, LPAREN, RPAREN, AND, OR, EQUAL,
    EQUAL_EQUAL, LESS_THAN, NOT_EQUAL, GREATER, LESS, LESS_EQUAL, GREATER_EQUAL, ASSIGN,
    SEMICOLON,CIN,COUT,LT_LT,GT_GT,END
};


struct Token {
    enum TokenType type;
    std::string value;

    Token(TokenType type, std::string value) : type(type), value(value) {}
};


#endif //TOKEN_H
