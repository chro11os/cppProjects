#include "symbolTable.h"

// Declare a variable in the symbol table
void SymbolTable::declareVariable(const std::string& name, VariableType type) {
    table[name] = type;
}

// Check if a variable is already declared
bool SymbolTable::isDeclared(const std::string& name) const {
    return table.find(name) != table.end();
}

// Get the type of a variable, or UNKNOWN if it’s not declared
VariableType SymbolTable::getType(const std::string& name) const {
    auto it = table.find(name);
    return it != table.end() ? it->second : VariableType::UNKNOWN;
}
