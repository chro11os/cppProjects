#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/syntaxAnalyzer/parser.h"
#include <stdexcept>
#include <iostream>

// Initialize the parser with tokens
Parser::Parser(const std::vector<Token>& tokens)
    : tokens(tokens), currentTokenIndex(0) {}

std::shared_ptr<ASTNode> Parser::parse() {
    auto root = std::make_shared<ASTNode>("Program");

    // Loop to process multiple statements
    while (currentTokenIndex < tokens.size() && peek().type != TokenType::END_OF_FILE) {
        root->children.push_back(parseStatement());
    }

    return root;
}

// Determine if the current statement is a declaration or an assignment
std::shared_ptr<ASTNode> Parser::parseStatement() {
    if (peek().type == TokenType::KEYWORD && peek().lexeme == "int") {
        return parseDeclaration();
    } else {
        return parseAssignment();
    }
}

// Parse declaration (e.g., "int x = 5;")
std::shared_ptr<ASTNode> Parser::parseDeclaration() {
    auto node = std::make_shared<ASTNode>("Declaration");

    // Expect the 'int' keyword
    if (match(TokenType::KEYWORD) && tokens[currentTokenIndex - 1].lexeme == "int") {
        node->children.push_back(std::make_shared<ASTNode>("int"));
    } else {
        throw std::runtime_error("Expected 'int' keyword in declaration");
    }

    // Expect an identifier
    if (match(TokenType::IDENTIFIER)) {
        node->children.push_back(std::make_shared<ASTNode>(tokens[currentTokenIndex - 1].lexeme));

        // Optional assignment (e.g., "int x = 5;")
        if (match(TokenType::ASSIGNMENT)) {
            node->children.push_back(parseExpression());
        }

        // Ensure the declaration ends with a semicolon
        if (!match(TokenType::SEMICOLON)) {
            throw std::runtime_error("Expected ';' at the end of declaration");
        }
    } else {
        throw std::runtime_error("Expected identifier after 'int' in variable declaration");
    }

    return node;
}


// Parse assignment (e.g., "x = x + 10;")
#include "parser.h"
#include <stdexcept>
#include <iostream>

std::shared_ptr<ASTNode> Parser::parseAssignment() {
    auto node = std::make_shared<ASTNode>("Assignment");

    // Expect an identifier on the left side of the assignment
    if (match(TokenType::IDENTIFIER)) {
        node->children.push_back(std::make_shared<ASTNode>(tokens[currentTokenIndex - 1].lexeme));

        // Expect '=' in assignment
        if (match(TokenType::ASSIGNMENT)) {
            node->children.push_back(parseExpression());
        } else {
            throw std::runtime_error("Expected '=' in assignment");
        }

        // Ensure assignment ends with a semicolon
        if (!match(TokenType::SEMICOLON)) {
            throw std::runtime_error("Expected ';' at the end of assignment");
        }
    } else {
        throw std::runtime_error("Expected identifier on the left side of the assignment");
    }

    return node;
}



// Parse expressions with addition and subtraction: E -> E + T | E - T | T
std::shared_ptr<ASTNode> Parser::parseExpression() {
    auto node = parseTerm();

    // Handle addition and subtraction within expressions
    while (peek().type == TokenType::OPERATOR && (peek().lexeme == "+" || peek().lexeme == "-")) {
        auto operatorNode = std::make_shared<ASTNode>(advance().lexeme);
        operatorNode->children.push_back(node);
        operatorNode->children.push_back(parseTerm());
        node = operatorNode;
    }

    return node;
}


// Parse terms with multiplication and division: T -> T * F | T / F | F
std::shared_ptr<ASTNode> Parser::parseTerm() {
    auto node = parseFactor();

    // Handle multiplication and division within terms
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
    // Handle literals and identifiers as factors
    if (match(TokenType::LITERAL)) {
        return std::make_shared<ASTNode>(tokens[currentTokenIndex - 1].lexeme);
    }

    if (match(TokenType::IDENTIFIER)) {
        return std::make_shared<ASTNode>(tokens[currentTokenIndex - 1].lexeme);
    }

    // Handle grouped expressions
    if (match(TokenType::OPERATOR) && tokens[currentTokenIndex - 1].lexeme == "(") {
        auto node = parseExpression();
        if (!match(TokenType::OPERATOR) || tokens[currentTokenIndex - 1].lexeme != ")") {
            throw std::runtime_error("Expected ')' after expression");
        }
        return node;
    }

    throw std::runtime_error("Expected factor (number, identifier, or expression in parentheses)");
}




// Peek at the current token without consuming it
Token Parser::peek() const {
    return currentTokenIndex < tokens.size() ? tokens[currentTokenIndex] : Token(TokenType::END_OF_FILE, "", -1);
}

// Advance to the next token
Token Parser::advance() {
    return tokens[currentTokenIndex++];
}

// Check and consume token if it matches the expected type
bool Parser::match(TokenType type) {
    if (peek().type == type) {
        advance();
        return true;
    }
    return false;
}
