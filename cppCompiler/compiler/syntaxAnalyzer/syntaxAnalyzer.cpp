#include "parser.h"
#include <stdexcept>

std::shared_ptr<ASTNode> Parser::parse() {
    auto root = std::make_shared<ASTNode>("Program");
    while (pos < tokens.size() && currentToken().type != TokenType::END_OF_FILE) {
        if (currentToken().type == TokenType::INT ||
            currentToken().type == TokenType::FLOAT ||
            currentToken().type == TokenType::BOOL ||
            currentToken().type == TokenType::STRING) {
            root->children.push_back(parseDeclaration());
            } else if (currentToken().type == TokenType::COUT) {
                root->children.push_back(parseCoutStatement());
            }
        advance();
    }
    return root;
}

std::shared_ptr<ASTNode> Parser::parseDeclaration() {
    auto node = std::make_shared<ASTNode>("Declaration");
    node->value = currentToken().lexeme;
    advance();
    if (currentToken().type == TokenType::IDENTIFIER) {
        node->children.push_back(std::make_shared<ASTNode>(currentToken().lexeme));
        advance();
    }
    if (currentToken().type == TokenType::ASSIGN) {
        advance();
        node->children.push_back(parseExpression());
    }
    return node;
}

std::shared_ptr<ASTNode> Parser::parseCoutStatement() {
    auto node = std::make_shared<ASTNode>("Cout");
    advance();
    while (currentToken().type != TokenType::SEMICOLON) {
        if (currentToken().type == TokenType::RIGHT_SHIFT) {
            advance();
            node->children.push_back(parseExpression());
        } else {
            advance();
        }
    }
    return node;
}

std::shared_ptr<ASTNode> Parser::parseExpression() {
    auto node = std::make_shared<ASTNode>(currentToken().lexeme);
    advance();
    return node;
}
