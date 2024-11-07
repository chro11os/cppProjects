#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/lexicalAnalyzer/lexer.h"
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/syntaxAnalyzer/parser.h"
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/semanticAnalyzer/semanticAnalyzer.h"
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/codeGeneration/CodeGenerator.h"
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/fckOptimization/Optimizer.h"

#include <iostream>
#include <vector>
#include <memory>

void printAST(const std::shared_ptr<ASTNode>& node, int depth = 0) {
    if (!node) return;
    std::cout << std::string(depth * 2, ' ') << node->value << "\n";
    for (const auto& child : node->children) {
        printAST(child, depth + 1);
    }
}

int main() {
    Lexer lexer("int x = 5; x = x + 10;");
    std::vector<Token> tokens = lexer.getTokens();

    // Print tokens for verification
    std::cout << "Tokens:\n";
    for (const auto& token : tokens) {
        std::cout << "Token: " << token.lexeme << ", Type: " << static_cast<int>(token.type) << "\n";
    }

    Parser parser(tokens);
    std::shared_ptr<ASTNode> ast = parser.parse();

    // Print AST structure
    std::cout << "\nAbstract Syntax Tree:\n";
    printAST(ast);

    // Perform semantic analysis
    SemanticAnalyzer analyzer(ast);
    analyzer.analyze();
    std::cout << "Semantic analysis completed successfully.\n";

    // Generate and print intermediate code
    CodeGenerator codeGen(ast);
    codeGen.generateIR();
    std::cout << "\nIntermediate Representation (IR) before optimization:\n";
    codeGen.printIR();

    // Optimize the IR using the getIRCode() method
    Optimizer optimizer(codeGen.getIRCode());
    optimizer.optimize();
    std::cout << "\nIntermediate Representation (IR) after optimization:\n";
    codeGen.printIR();

    return 0;
}
