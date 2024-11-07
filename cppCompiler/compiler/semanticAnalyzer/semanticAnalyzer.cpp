#include "semanticAnalyzer.h"
#include <stdexcept>
#include <iostream>

SemanticAnalyzer::SemanticAnalyzer(const std::shared_ptr<ASTNode>& root)
    : root(root) {}

// Analyze the AST and check for semantic errors
void SemanticAnalyzer::analyze() {
    analyzeNode(root);
}

// Recursively analyze each node in the AST
void SemanticAnalyzer::analyzeNode(const std::shared_ptr<ASTNode>& node) {
    if (!node) return;

    // Check if the node is a declaration or assignment
    if (node->value == "Declaration") {
        checkDeclaration(node);
    } else if (node->value == "Assignment") {
        checkAssignment(node);
    }

    // Recursively analyze each child node
    for (const auto& child : node->children) {
        analyzeNode(child);
    }
}

// Check declarations and add variables to the symbol table
void SemanticAnalyzer::checkDeclaration(const std::shared_ptr<ASTNode>& node) {
    if (node->children.size() < 2) {
        throw std::runtime_error("Invalid declaration structure");
    }

    std::string variableName = node->children[1]->value; // Variable name is the second child
    if (symbolTable.isDeclared(variableName)) {
        throw std::runtime_error("Variable '" + variableName + "' already declared");
    }

    // Declare variable as INTEGER type
    symbolTable.declareVariable(variableName, VariableType::INTEGER);
}

// Check assignments for undeclared variables and type consistency
void SemanticAnalyzer::checkAssignment(const std::shared_ptr<ASTNode>& node) {
    if (node->children.size() < 2) {
        throw std::runtime_error("Invalid assignment structure");
    }

    std::string variableName = node->children[0]->value; // Left-hand side variable

    // Check if the variable is declared
    if (!symbolTable.isDeclared(variableName)) {
        throw std::runtime_error("Undeclared variable '" + variableName + "' in assignment");
    }

    // For now, assume all variables are INTEGERs; check if expressions involve only INTEGERs
    // Further type checking can be added as needed, based on AST structure and project requirements
}
