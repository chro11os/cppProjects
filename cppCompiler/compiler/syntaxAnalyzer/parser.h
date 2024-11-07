#ifndef PARSER_H
#define PARSER_H

#include <memory>
#include <vector>
#include <string>
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/lexicalAnalyzer/Token.h"

// AST Node structure
struct ASTNode {
    std::string value;
    std::vector<std::shared_ptr<ASTNode>> children;

    ASTNode(const std::string& value) : value(value) {}
};

// Parser class to build the AST from tokens
class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens);
    std::shared_ptr<ASTNode> parse();

private:
    std::vector<Token> tokens;
    size_t currentTokenIndex;

    Token peek() const;
    Token advance();
    bool match(TokenType type);

    // Declaration for parseStatement and parseDeclaration
    std::shared_ptr<ASTNode> parseStatement();
    std::shared_ptr<ASTNode> parseDeclaration();
    std::shared_ptr<ASTNode> parseAssignment();
    std::shared_ptr<ASTNode> parseExpression();
    std::shared_ptr<ASTNode> parseTerm();
    std::shared_ptr<ASTNode> parseFactor();
};

#endif // PARSER_H
