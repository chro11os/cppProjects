#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include <vector>
#include <string>
#include <memory>
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/syntaxAnalyzer/parser.h"  // Use the absolute path if needed

// Structure for a single IR instruction (e.g., three-address code)
struct IRInstruction {
    std::string op;     // Operation (e.g., "ADD", "STORE")
    std::string arg1;   // First argument
    std::string arg2;   // Second argument (if applicable)
    std::string result; // Result or destination
};

class CodeGenerator {
public:
    explicit CodeGenerator(const std::shared_ptr<ASTNode>& root);
    void generateIR();                   // Generates intermediate code
    void printIR() const;                // Prints the IR for debugging

private:
    std::shared_ptr<ASTNode> root;
    std::vector<IRInstruction> irCode;   // Vector to hold generated IR instructions

    // Helper functions to generate IR for specific node types
    std::string generateExpression(const std::shared_ptr<ASTNode>& node);
    void generateAssignment(const std::shared_ptr<ASTNode>& node);
    void generateDeclaration(const std::shared_ptr<ASTNode>& node); // Add this declaration
};

#endif // CODE_GENERATOR_H
