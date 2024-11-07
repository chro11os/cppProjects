#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <vector>
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/IR_generation/IRGenerator.h" // For ThreeAddressCode

class Optimizer {
public:
    explicit Optimizer(std::vector<ThreeAddressCode>& irCode);
    void optimize();

private:
    std::vector<ThreeAddressCode>& irCode;

    void eliminateDeadCode();
    void constantFolding();
};

#endif // OPTIMIZER_H
