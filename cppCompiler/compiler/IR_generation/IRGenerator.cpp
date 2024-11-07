#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/IR_generation/IRGenerator.h"
#include <sstream>

// Constructor to initialize the IR generator with the root of the AST
IRGenerator::IRGenerator(std::shared_ptr<ASTNode> root)
    : root(root), tempVarCount(0) {}

// Generate a new temporary variable name
std::string IRGenerator::newTempVar() {
    return "t" + std::to_string(tempVarCount++);
}

// Generate IR code for the AST
std::vector<ThreeAddressCode> IRGenerator::generateIR() {
    std::string resultVar;
    generateNode(root, resultVar);
    return code;
}

// Generate IR code for a specific node
void IRGenerator::generateNode(std::shared_ptr<ASTNode> node, std::string& resultVar) {
    if (node->value == "Assignment") {
        std::string variable = node->children[0]->value;
        generateNode(node->children[1], resultVar);
        code.push_back({variable, resultVar, "=", ""});
    }
    else if (node->value == "+" || node->value == "-" || node->value == "*" || node->value == "/") {
        std::string left, right;
        generateNode(node->children[0], left);
        generateNode(node->children[1], right);
        resultVar = newTempVar();
        code.push_back({resultVar, left, node->value, right});
    }
    else {
        resultVar = node->value;
    }
}

// Convert a line of three-address code to string
std::string ThreeAddressCode::toString() const {
    if (op.empty()) {
        return result + " = " + operand1;
    }
    return result + " = " + operand1 + " " + op + " " + operand2;
}
