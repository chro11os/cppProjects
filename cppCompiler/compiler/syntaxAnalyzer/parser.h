//
// Created by chro11os on 10/12/24.
//

#ifndef PARSER_H
#define PARSER_H

#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/lexicalAnalyzer/lexer.h"
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/lexicalAnalyzer/Token.h"

class Parser {
public:

    Parser(Lexer& lexer, Token token): lexer(lexer)
    void parse();


private:
    Lexer& lexer;
    Token currentToken;


    void nextToken();
    void statement();
    void expression();
    void term();
    void factor();

    void expect(TokenType expectedType);
};


#endif //PARSER_H
