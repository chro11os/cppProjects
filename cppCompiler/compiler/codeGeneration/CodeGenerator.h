#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include <vector>
#include <string>
#include <memory>
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/syntaxAnalyzer/parser.h"

struct IRInstruction {
    std::string op;
    std::string arg1;
    std::string arg2;
    std::string result;
};

class CodeGenerator {
public:
    explicit CodeGenerator(const std::shared_ptr<ASTNode>& root);
    void generateIR();
    void generateCpp();
    void printCpp() const;

    std::vector<IRInstruction>& getIRCode();

private:
    std::shared_ptr<ASTNode> root;
    std::vector<IRInstruction> irCode;
    std::vector<std::string> cppCode;

    void generateDeclaration(const std::shared_ptr<ASTNode>& node);
    void generateCout(const std::shared_ptr<ASTNode>& node);
};

#endif // CODE_GENERATOR_H
