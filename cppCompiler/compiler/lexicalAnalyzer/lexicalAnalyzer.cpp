#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& source) : source(source), pos(0) {
    keywords = {
        {"int", TokenType::INT}, {"float", TokenType::FLOAT},
        {"bool", TokenType::BOOL}, {"string", TokenType::STRING},
        {"cout", TokenType::COUT}, {"cin", TokenType::CIN}
    };
}

bool Lexer::isAtEnd() const {
    return pos >= source.length();
}

char Lexer::advance() {
    return source[pos++];
}

char Lexer::peek() const {
    return isAtEnd() ? '\0' : source[pos];
}

Token Lexer::makeToken(TokenType type, const std::string& lexeme) {
    return Token{type, lexeme};
}

Token Lexer::nextToken() {
    while (!isAtEnd()) {
        char c = advance();
        if (isspace(c)) continue;

        if (isalpha(c)) {
            std::string lexeme(1, c);
            while (isalnum(peek())) lexeme += advance();
            if (keywords.find(lexeme) != keywords.end()) {
                return makeToken(keywords[lexeme], lexeme);
            }
            return makeToken(TokenType::IDENTIFIER, lexeme);
        }

        if (isdigit(c)) {
            std::string lexeme(1, c);
            while (isdigit(peek())) lexeme += advance();
            return makeToken(TokenType::NUMBER, lexeme);
        }

        switch (c) {
            case '+': return makeToken(TokenType::PLUS, "+");
            case '-': return makeToken(TokenType::MINUS, "-");
            case '*': return makeToken(TokenType::MULTIPLY, "*");
            case '/': return makeToken(TokenType::DIVIDE, "/");
            case '=': return makeToken(TokenType::ASSIGN, "=");
            case ';': return makeToken(TokenType::SEMICOLON, ";");

            case '<':
                if (peek() == '<') { advance(); return makeToken(TokenType::LEFT_SHIFT, "<<"); }
                break;
            case '>':
                if (peek() == '>') { advance(); return makeToken(TokenType::RIGHT_SHIFT, ">>"); }
                break;
        }
    }
    return makeToken(TokenType::END_OF_FILE, "");
}

std::vector<Token> Lexer::getTokens() {
    std::vector<Token> tokens;
    while (!isAtEnd()) {
        tokens.push_back(nextToken());
    }
    tokens.push_back(makeToken(TokenType::END_OF_FILE, ""));
    return tokens;
}
