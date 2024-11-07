#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/codeGeneration/CodeGenerator.h"
#include <iostream>

CodeGenerator::CodeGenerator(const std::shared_ptr<ASTNode>& root)
    : root(root) {}

// Main function to start IR generation
void CodeGenerator::generateIR() {
    if (root) {
        for (const auto& child : root->children) {
            if (child->value == "Declaration") {
                generateDeclaration(child);
            } else if (child->value == "Assignment") {
                generateAssignment(child);
            }
        }
    }
}

// Getter for accessing the generated IR code
std::vector<IRInstruction>& CodeGenerator::getIRCode() {
    return irCode;
}

// Helper function to generate IR for declarations
void CodeGenerator::generateDeclaration(const std::shared_ptr<ASTNode>& node) {
    if (node->children.size() < 3) {
        throw std::runtime_error("Invalid declaration structure");
    }

    std::string variableName = node->children[1]->value; // Variable name
    std::string initialValue = generateExpression(node->children[2]); // Initial value

    // Store the initial value in the declared variable
    irCode.push_back({"STORE", initialValue, "", variableName});
}

// Helper function to generate IR for assignment nodes
void CodeGenerator::generateAssignment(const std::shared_ptr<ASTNode>& node) {
    if (node->children.size() < 2) {
        throw std::runtime_error("Invalid assignment structure");
    }

    std::string target = node->children[0]->value; // Left-hand side variable
    std::string exprResult = generateExpression(node->children[1]); // Right-hand side expression

    // Store the result of the expression in the target variable
    irCode.push_back({"STORE", exprResult, "", target});
}

// Helper function to generate IR for expressions
std::string CodeGenerator::generateExpression(const std::shared_ptr<ASTNode>& node) {
    if (node->children.empty()) {
        return node->value;  // Base case: literal or variable
    }

    // For binary operations like +, -, *, /
    std::string left = generateExpression(node->children[0]);
    std::string right = generateExpression(node->children[1]);
    std::string tempVar = "t" + std::to_string(irCode.size()); // Temporary variable

    // Add the appropriate IR instruction based on the operator
    irCode.push_back({node->value, left, right, tempVar});
    return tempVar;
}

// Print the generated IR for debugging
void CodeGenerator::printIR() const {
    for (const auto& instr : irCode) {
        if (instr.arg2.empty()) {
            std::cout << instr.op << " " << instr.arg1 << " " << instr.result << "\n";
        } else {
            std::cout << instr.op << " " << instr.arg1 << ", " << instr.arg2 << " -> " << instr.result << "\n";
        }
    }
}
