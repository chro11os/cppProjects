#ifndef PARSER_H
#define PARSER_H

#include <memory>
#include <vector>
#include <stdexcept>
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/lexicalAnalyzer/Token.h"

// AST Node structure representing nodes in the AST
struct ASTNode {
    std::string value;
    std::vector<std::shared_ptr<ASTNode>> children;

    ASTNode(const std::string& value) : value(value) {}
};

// Parser class to build the AST from tokens
class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens);
    std::shared_ptr<ASTNode> parse();  // Entry point for parsing

private:
    std::vector<Token> tokens;
    size_t currentTokenIndex;

    Token peek() const;                  // Peek at the current token
    Token advance();                     // Advance to the next token
    bool match(TokenType type);          // Check and consume token if type matches

    std::shared_ptr<ASTNode> parseAssignment(); // Parse assignment rules
    std::shared_ptr<ASTNode> parseExpression(); // Parse expressions
    std::shared_ptr<ASTNode> parseTerm();       // Parse terms
    std::shared_ptr<ASTNode> parseFactor();     // Parse factors
};

#endif // PARSER_H
