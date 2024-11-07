#include "semanticAnalyzer.h"
#include <stdexcept>
#include <iostream>

// Initialize the analyzer with the root of the AST
SemanticAnalyzer::SemanticAnalyzer(std::shared_ptr<ASTNode> root)
    : root(root) {}

// Run the semantic checks on the AST
void SemanticAnalyzer::analyze() {
    checkNode(root);
}

// Recursively check each node in the AST
void SemanticAnalyzer::checkNode(std::shared_ptr<ASTNode> node) {
    if (node->value == "Assignment") {
        checkAssignment(node);
    } else {
        for (const auto& child : node->children) {
            checkNode(child);
        }
    }
}

// Check assignment statements
void SemanticAnalyzer::checkAssignment(std::shared_ptr<ASTNode> node) {
    // The first child is the variable, the second is the expression
    std::string variableName = node->children[0]->value;

    // Declare the variable if it's the first assignment
    if (!symbolTable.isDeclared(variableName)) {
        symbolTable.declareVariable(variableName, VariableType::INTEGER);
    }

    // Check the expression assigned to the variable
    checkExpression(node->children[1]);
}

// Check expressions for type correctness
void SemanticAnalyzer::checkExpression(std::shared_ptr<ASTNode> node) {
    // Check for type mismatches or undeclared variables
    if (node->value == "+" || node->value == "-") {
        for (const auto& child : node->children) {
            if (child->value != "num" && !symbolTable.isDeclared(child->value)) {
                throw std::runtime_error("Undeclared variable: " + child->value);
            }
        }
    }
}
