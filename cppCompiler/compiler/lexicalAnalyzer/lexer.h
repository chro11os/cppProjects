//
// Created by chro11os on 10/12/24.
//

#ifndef LEXER_H
#define LEXER_H
#include "Token.h"

class Lexer {
private:
    std::string source;
    size_t index;

public:
    Lexer(std::string source);

    bool isEnd() const;
    Token getNextToken();

};

#endif //LEXER_H
