#ifndef PARSER_H
#define PARSER_H

#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/lexicalAnalyzer/lexer.h"
#include <memory>
#include <vector>

struct ASTNode {
    std::string value;
    std::vector<std::shared_ptr<ASTNode>> children;
    ASTNode(const std::string& value) : value(value) {}
};

class Parser {
public:
    Parser(const std::vector<Token>& tokens) : tokens(tokens), pos(0) {}
    std::shared_ptr<ASTNode> parse();

private:
    std::vector<Token> tokens;
    size_t pos;

    std::shared_ptr<ASTNode> parseDeclaration();
    std::shared_ptr<ASTNode> parseCoutStatement();
    std::shared_ptr<ASTNode> parseExpression();

    Token currentToken() const { return tokens[pos]; }
    void advance() { pos++; }
};

#endif // PARSER_H
