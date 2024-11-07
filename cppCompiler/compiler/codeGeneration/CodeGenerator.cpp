#include "CodeGenerator.h"
#include <iostream>

CodeGenerator::CodeGenerator(const std::shared_ptr<ASTNode>& root) : root(root) {}

std::vector<IRInstruction>& CodeGenerator::getIRCode() {
    return irCode;
}

void CodeGenerator::generateIR() {
    if (root) {
        for (const auto& child : root->children) {
            if (child->value == "Declaration") {
                generateDeclaration(child);
            } else if (child->value == "Cout") {
                generateCout(child);
            }
        }
    }
}

void CodeGenerator::generateDeclaration(const std::shared_ptr<ASTNode>& node) {
    if (node->children.size() < 2) return;
    std::string varType = node->value;
    std::string varName = node->children[0]->value;
    std::string initialValue = node->children.size() > 1 ? node->children[1]->value : "0";
    irCode.push_back({"STORE", initialValue, "", varName});
}

void CodeGenerator::generateCout(const std::shared_ptr<ASTNode>& node) {
    for (const auto& child : node->children) {
        irCode.push_back({"PRINT", child->value, "", ""});
    }
}

void CodeGenerator::generateCpp() {
    for (const auto& instr : irCode) {
        if (instr.op == "STORE") {
            cppCode.push_back(instr.result + " = " + instr.arg1 + ";");
        } else if (instr.op == "PRINT") {
            cppCode.push_back("cout << " + instr.arg1 + ";");
        }
    }
}

void CodeGenerator::printCpp() const {
    for (const auto& line : cppCode) {
        std::cout << line << "\n";
    }
}
