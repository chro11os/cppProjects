#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/lexicalAnalyzer/lexer.h"
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/syntaxAnalyzer/parser.h"
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/semanticAnalyzer/semanticAnalyzer.h"
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/codeGeneration/CodeGenerator.h"
#include "/Users/neilbragsguzman/Documents/GitHub/cppProjects/cppCompiler/compiler/fckOptimization/Optimizer.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>

// Function to print the Abstract Syntax Tree (AST)
void printAST(const std::shared_ptr<ASTNode>& node, int depth = 0) {
    if (!node) return;
    std::cout << std::string(depth * 2, ' ') << node->value << "\n";
    for (const auto& child : node->children) {
        printAST(child, depth + 1);
    }
}

void compileCode(const std::string& sourceCode) {
    // Lexical Analysis
    Lexer lexer(sourceCode);
    std::vector<Token> tokens = lexer.getTokens();

    std::cout << "Tokens:\n";
    for (const auto& token : tokens) {
        std::cout << "Token: " << token.lexeme << ", Type: " << static_cast<int>(token.type) << "\n";
    }

    // Parsing
    Parser parser(tokens);
    std::shared_ptr<ASTNode> ast = parser.parse();

    std::cout << "\nAbstract Syntax Tree:\n";
    printAST(ast);

    // Intermediate Representation
    CodeGenerator codeGen(ast);
    codeGen.generateIR();
    std::cout << "\nIntermediate Representation (IR):\n";
    for (const auto& ir : codeGen.getIRCode()) {
        std::cout << ir.op << " " << ir.arg1 << " " << ir.arg2 << " -> " << ir.result << "\n";
    }

    // C++ Code Generation
    codeGen.generateCpp();
    std::cout << "\nGenerated C++ Code:\n";
    codeGen.printCpp();
}

int main() {
    int choice;
    std::cout << "Select an option:\n";
    std::cout << "1. Upload a file\n";
    std::cout << "2. Code a file\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1) {
        std::string filePath;
        std::cout << "Enter file path: ";
        std::getline(std::cin, filePath);

        std::ifstream file(filePath);
        if (!file) {
            std::cerr << "Error: Could not open file.\n";
            return 1;
        }
        std::string sourceCode((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        compileCode(sourceCode);

    } else if (choice == 2) {
        std::string sourceCode, line;
        std::cout << "Enter your code below. Type 'COMPILE' on a new line to finish and compile:\n";

        while (true) {
            std::getline(std::cin, line);
            if (line == "COMPILE") break;
            sourceCode += line + "\n";
        }

        compileCode(sourceCode);
    } else {
        std::cerr << "Invalid choice. Exiting.\n";
        return 1;
    }

    return 0;
}
