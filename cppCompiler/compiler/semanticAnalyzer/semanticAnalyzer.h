#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include <memory>
#include "symbolTable.h"
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/syntaxAnalyzer/parser.h"  // For ASTNode

// SemanticAnalyzer class to perform type and scope checking
class SemanticAnalyzer {
public:
    explicit SemanticAnalyzer(std::shared_ptr<ASTNode> root);

    // Run the semantic analysis on the AST
    void analyze();

private:
    std::shared_ptr<ASTNode> root;
    SymbolTable symbolTable;

    void checkNode(std::shared_ptr<ASTNode> node);
    void checkAssignment(std::shared_ptr<ASTNode> node);
    void checkExpression(std::shared_ptr<ASTNode> node);
};

#endif // SEMANTIC_ANALYZER_H
