#include "Optimizer.h"
#include <iostream>
#include <unordered_map>
#include <string>

Optimizer::Optimizer(std::vector<IRInstruction>& irCode) : irCode(irCode) {}

// Main function to run all optimizations
void Optimizer::optimize() {
    constantFolding();
    deadCodeElimination();
}

// Constant folding: simplify expressions with constant values
void Optimizer::constantFolding() {
    for (auto& instr : irCode) {
        // Only optimize ADD, SUB, MUL, DIV with numeric arguments
        if ((instr.op == "ADD" || instr.op == "SUB" || instr.op == "MUL" || instr.op == "DIV") &&
            isdigit(instr.arg1[0]) && isdigit(instr.arg2[0])) {

            // Convert arguments to integers and perform the operation
            int left = std::stoi(instr.arg1);
            int right = std::stoi(instr.arg2);
            int result;

            if (instr.op == "ADD") result = left + right;
            else if (instr.op == "SUB") result = left - right;
            else if (instr.op == "MUL") result = left * right;
            else if (instr.op == "DIV") result = right != 0 ? left / right : left; // Prevent division by zero

            // Replace instruction with a single STORE of the result
            instr.op = "STORE";
            instr.arg1 = std::to_string(result);
            instr.arg2 = "";
            instr.result = instr.result;
        }
    }
}

// Dead code elimination: remove instructions with unused results
void Optimizer::deadCodeElimination() {
    std::unordered_map<std::string, bool> usedVars;

    // Mark variables that are used later in the code
    for (const auto& instr : irCode) {
        if (!instr.result.empty()) {
            usedVars[instr.result] = false;
        }
        if (!instr.arg1.empty() && usedVars.find(instr.arg1) != usedVars.end()) {
            usedVars[instr.arg1] = true;
        }
        if (!instr.arg2.empty() && usedVars.find(instr.arg2) != usedVars.end()) {
            usedVars[instr.arg2] = true;
        }
    }

    // Remove instructions that produce unused results
    irCode.erase(std::remove_if(irCode.begin(), irCode.end(),
                                [&usedVars](const IRInstruction& instr) {
                                    return !instr.result.empty() && !usedVars[instr.result];
                                }),
                 irCode.end());
}
