#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include <vector>
#include <string>
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/IR_generation/IRGenerator.h" // For ThreeAddressCode

class CodeGenerator {
public:
    explicit CodeGenerator(const std::vector<ThreeAddressCode>& optimizedCode);
    std::vector<std::string> generateAssembly();

private:
    const std::vector<ThreeAddressCode>& optimizedCode;
    std::vector<std::string> assemblyCode;

    void generateInstruction(const ThreeAddressCode& code);
};

#endif // CODE_GENERATOR_H
