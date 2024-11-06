#include <iostream>
#include "lexicalAnalyzer/Token.h"
#include "lexicalAnalyzer/lexer.h"

int main () {
    std::string input = "if (x + 5) while (y == 10) x = y + 1";

    Lexer lexer(input);
    Token token = lexer.getNextToken();

    while (token.type != TokenType::END_OF_FILE) {
        std::cout << "Token: " << token.value << "| Type: " << static_cast<int>(token.type) << std::endl;
        token = lexer.getNextToken();

    }
    return 0;
}