#include "parser.h"

// Constructor that initializes the parser with tokens
Parser::Parser(const std::vector<Token>& tokens)
    : tokens(tokens), currentTokenIndex(0) {}

// Peek at the current token without consuming it
Token Parser::peek() const {
    return currentTokenIndex < tokens.size() ? tokens[currentTokenIndex] : Token(TokenType::END_OF_FILE, "", -1);
}

// Advance to the next token, updating the current index
Token Parser::advance() {
    return tokens[currentTokenIndex++];
}

// Check if the current token matches the expected type, advancing if it does
bool Parser::match(TokenType type) {
    if (peek().type == type) {
        advance();
        return true;
    }
    return false;
}

// Entry point for parsing, handling the start rule: S -> id = E
std::shared_ptr<ASTNode> Parser::parse() {
    return parseAssignment();
}

// Parse assignment statements: id = E
std::shared_ptr<ASTNode> Parser::parseAssignment() {
    auto node = std::make_shared<ASTNode>("Assignment");

    // Expect an identifier, followed by an assignment, then an expression
    if (match(TokenType::IDENTIFIER)) {
        node->children.push_back(std::make_shared<ASTNode>(tokens[currentTokenIndex - 1].lexeme));

        if (match(TokenType::ASSIGNMENT)) {
            node->children.push_back(parseExpression());
        } else {
            throw std::runtime_error("Expected '=' in assignment");
        }
    } else {
        throw std::runtime_error("Expected identifier in assignment");
    }

    return node;
}

// Parse expressions: E -> E + T | E - T | T
std::shared_ptr<ASTNode> Parser::parseExpression() {
    auto node = parseTerm();

    while (peek().type == TokenType::OPERATOR && (peek().lexeme == "+" || peek().lexeme == "-")) {
        auto operatorNode = std::make_shared<ASTNode>(advance().lexeme);
        operatorNode->children.push_back(node);
        operatorNode->children.push_back(parseTerm());
        node = operatorNode;
    }

    return node;
}

// Parse terms: T -> T * F | T / F | F
std::shared_ptr<ASTNode> Parser::parseTerm() {
    auto node = parseFactor();

    while (peek().type == TokenType::OPERATOR && (peek().lexeme == "*" || peek().lexeme == "/")) {
        auto operatorNode = std::make_shared<ASTNode>(advance().lexeme);
        operatorNode->children.push_back(node);
        operatorNode->children.push_back(parseFactor());
        node = operatorNode;
    }

    return node;
}

// Parse factors: F -> ( E ) | id | num
std::shared_ptr<ASTNode> Parser::parseFactor() {
    // Parse a numerical literal
    if (match(TokenType::LITERAL)) {
        return std::make_shared<ASTNode>(tokens[currentTokenIndex - 1].lexeme);
    }

    // Parse an identifier (variable)
    if (match(TokenType::IDENTIFIER)) {
        return std::make_shared<ASTNode>(tokens[currentTokenIndex - 1].lexeme);
    }

    // Parse grouped expressions in parentheses
    if (match(TokenType::OPERATOR) && tokens[currentTokenIndex - 1].lexeme == "(") {
        auto node = parseExpression();

        if (!match(TokenType::OPERATOR) || tokens[currentTokenIndex - 1].lexeme != ")") {
            throw std::runtime_error("Expected ')' after expression");
        }
        return node;
    }

    throw std::runtime_error("Expected factor (number, identifier, or expression in parentheses)");
}
