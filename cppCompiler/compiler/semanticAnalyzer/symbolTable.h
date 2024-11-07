//
// Created by chro11os on 11/7/24.
//

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <unordered_map>

enum class VariableType {
    INTEGER,
    UNKNOWN
};

// A symbol table to store variable names and types for scope checking
class SymbolTable {
public:
    // Add a variable to the table with a specified type
    void declareVariable(const std::string& name, VariableType type);

    // Check if a variable is already declared
    bool isDeclared(const std::string& name) const;

    // Get the type of a variable
    VariableType getType(const std::string& name) const;

private:
    std::unordered_map<std::string, VariableType> table;
};

#endif // SYMBOL_TABLE_H
