//
// Created by chro11os on 10/12/24.
//
#include "parser.h"
#include <iostream>

Parser::Parser (Lexer& lexer) : lexer(lexer), currentToken(currentToken(Token())) {

    nextToken();

}
