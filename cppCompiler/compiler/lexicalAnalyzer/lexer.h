#ifndef LEXER_H
#define LEXER_H

#include "Token.h"
#include <vector>
#include <string>
#include <unordered_map>

class Lexer {
public:
    Lexer(const std::string& source);
    Token nextToken();
    std::vector<Token> getTokens(); // Tokenizes the entire source

private:
    std::string source;
    size_t pos;
    bool isAtEnd() const;
    char advance();
    char peek() const;
    Token makeToken(TokenType type, const std::string& lexeme);
    std::unordered_map<std::string, TokenType> keywords;
};

#endif // LEXER_H
