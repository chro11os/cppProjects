#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include <memory>
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/syntaxAnalyzer/parser.h"      // Assuming ASTNode is defined in this file
#include "symbolTable.h"  // Includes the SymbolTable class

class SemanticAnalyzer {
public:
    explicit SemanticAnalyzer(const std::shared_ptr<ASTNode>& root);

    // Analyze the AST and check for semantic errors
    void analyze();

private:
    std::shared_ptr<ASTNode> root;
    SymbolTable symbolTable;

    void analyzeNode(const std::shared_ptr<ASTNode>& node);

    // Helper functions for checking declarations and types
    void checkDeclaration(const std::shared_ptr<ASTNode>& node);
    void checkAssignment(const std::shared_ptr<ASTNode>& node);
};

#endif // SEMANTIC_ANALYZER_H
