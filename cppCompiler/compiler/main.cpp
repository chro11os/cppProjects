#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include </Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/lexicalAnalyzer/Token.h>
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/lexicalAnalyzer/lexer.h"
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/syntaxAnalyzer/parser.h"
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/semanticAnalyzer/semanticAnalyzer.h"
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/IR_generation/IRGenerator.h"
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/fckOptimization/Optimizer.h"
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/codeGeneration/CodeGenerator.h"

int main() {
    // Read source code from a file
    std::ifstream file("/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/source.cpp");
    if (!file) {
        std::cerr << "Error: Could not open source file.\n";
        return 1;
    }
    std::string sourceCode((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // Step 1: Lexical Analysis
    Lexer lexer(sourceCode);
    std::vector<Token> tokens;
    Token token;
    while ((token = lexer.nextToken()).type != TokenType::END_OF_FILE) {
        tokens.push_back(token);
    }

    // Step 2: Syntax Analysis (Parsing)
    Parser parser(tokens);
    std::shared_ptr<ASTNode> ast;
    try {
        ast = parser.parse();
    } catch (const std::runtime_error& e) {
        std::cerr << "Syntax error: " << e.what() << "\n";
        return 1;
    }

    // Step 3: Semantic Analysis
    SemanticAnalyzer analyzer(ast);
    try {
        analyzer.analyze();
    } catch (const std::runtime_error& e) {
        std::cerr << "Semantic error: " << e.what() << "\n";
        return 1;
    }

    // Step 4: Intermediate Code Generation
    IRGenerator irGen(ast);
    auto irCode = irGen.generateIR();

    // Step 5: Optimization
    Optimizer optimizer(irCode);
    optimizer.optimize();

    // Step 6: Code Generation
    CodeGenerator codeGen(irCode);
    auto assemblyCode = codeGen.generateAssembly();

    // Output final assembly code
    std::cout << "Generated Assembly Code:\n";
    for (const auto& line : assemblyCode) {
        std::cout << line << "\n";
    }

    return 0;
}
