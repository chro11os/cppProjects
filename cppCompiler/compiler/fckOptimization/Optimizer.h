#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <vector>
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/codeGeneration/CodeGenerator.h"  // Absolute path if required

class Optimizer {
public:
    explicit Optimizer(std::vector<IRInstruction>& irCode);

    // Runs all optimizations
    void optimize();

private:
    std::vector<IRInstruction>& irCode;  // Reference to IR for in-place optimization

    // Helper optimization functions
    void constantFolding();
    void deadCodeElimination();
};

#endif // OPTIMIZER_H
