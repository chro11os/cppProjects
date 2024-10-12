//
// Created by chro11os on 10/11/24.
//

#ifndef TOKEN_H
#define TOKEN_H
#include <string>


enum TokenType {
    KEYWORD, IDENTIFIER, NUMBER, OPERATOR, PUNCTUATION, END_OF_FILE
};


struct Token {
    enum TokenType type;
    std::string value;

    Token(TokenType type, std::string value) : type(type), value(value) {}
};


#endif //TOKEN_H
