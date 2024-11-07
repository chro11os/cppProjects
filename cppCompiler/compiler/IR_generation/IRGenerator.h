#ifndef IR_GENERATOR_H
#define IR_GENERATOR_H

#include <memory>
#include <vector>
#include <string>
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/syntaxAnalyzer/parser.h" // For ASTNode

// Structure to hold a single line of three-address code
struct ThreeAddressCode {
    std::string result;
    std::string operand1;
    std::string op;
    std::string operand2;

    std::string toString() const;
};

// Class to generate intermediate representation (IR) code
class IRGenerator {
public:
    explicit IRGenerator(std::shared_ptr<ASTNode> root);
    std::vector<ThreeAddressCode> generateIR();

private:
    std::shared_ptr<ASTNode> root;
    int tempVarCount;

    std::string newTempVar();
    void generateNode(std::shared_ptr<ASTNode> node, std::string& resultVar);
    std::vector<ThreeAddressCode> code;
};

#endif // IR_GENERATOR_H
