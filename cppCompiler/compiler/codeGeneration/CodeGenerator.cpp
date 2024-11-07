#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/codeGeneration/CodeGenerator.h"

// Constructor that takes optimized IR code as input
CodeGenerator::CodeGenerator(const std::vector<ThreeAddressCode>& optimizedCode)
    : optimizedCode(optimizedCode) {}

// Main function to generate assembly code from optimized IR
std::vector<std::string> CodeGenerator::generateAssembly() {
    for (const auto& code : optimizedCode) {
        generateInstruction(code);
    }
    return assemblyCode;
}

// Generate assembly instructions for each line of three-address code
void CodeGenerator::generateInstruction(const ThreeAddressCode& code) {
    if (code.op.empty()) {
        // Simple assignment: x = y
        assemblyCode.push_back("LOAD " + code.operand1);
        assemblyCode.push_back("STORE " + code.result);
    } else {
        // Binary operation: x = y op z
        assemblyCode.push_back("LOAD " + code.operand1);
        if (code.op == "+") {
            assemblyCode.push_back("ADD " + code.operand2);
        } else if (code.op == "-") {
            assemblyCode.push_back("SUB " + code.operand2);
        } else if (code.op == "*") {
            assemblyCode.push_back("MUL " + code.operand2);
        } else if (code.op == "/") {
            assemblyCode.push_back("DIV " + code.operand2);
        }
        assemblyCode.push_back("STORE " + code.result);
    }
}
