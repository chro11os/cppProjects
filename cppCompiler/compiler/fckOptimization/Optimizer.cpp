#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/fckOptimization/Optimizer.h"
#include <unordered_set>
#include <sstream>

// Constructor to initialize with the IR code
Optimizer::Optimizer(std::vector<ThreeAddressCode>& irCode) : irCode(irCode) {}

// Apply all optimizations
void Optimizer::optimize() {
    constantFolding();
    eliminateDeadCode();
}

// Constant folding: simplify constant expressions in the IR code
void Optimizer::constantFolding() {
    for (auto& code : irCode) {
        if (code.op == "+" || code.op == "-" || code.op == "*" || code.op == "/") {
            int left, right;

            // Check if both operands are constants (integers)
            if (std::istringstream(code.operand1) >> left && std::istringstream(code.operand2) >> right) {
                int result = 0;
                if (code.op == "+") result = left + right;
                else if (code.op == "-") result = left - right;
                else if (code.op == "*") result = left * right;
                else if (code.op == "/") result = right != 0 ? left / right : 0;

                code.op = ""; // Clear operator
                code.operand1 = std::to_string(result); // Set result as single operand
                code.operand2 = ""; // Clear second operand
            }
        }
    }
}

// Dead code elimination: remove unused assignments
void Optimizer::eliminateDeadCode() {
    std::unordered_set<std::string> usedVars;

    // Mark all variables that are used on the right side of assignments
    for (const auto& code : irCode) {
        if (!code.operand1.empty() && code.op.empty()) { // Only consider simple assignments
            usedVars.insert(code.result);
        }
    }

    // Remove lines where a variable is assigned but never used
    irCode.erase(std::remove_if(irCode.begin(), irCode.end(),
        [&usedVars](const ThreeAddressCode& code) {
            return !usedVars.count(code.result) && code.op.empty();
        }), irCode.end());
}
