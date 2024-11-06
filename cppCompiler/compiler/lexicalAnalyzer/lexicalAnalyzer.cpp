#include "Token.h"
#include "lexer.h"   // Include the Lexer header
#include <cctype>    // For isdigit, isalpha
#include <iostream>
#include <string>
#include <cstring>

// Constructor to initialize Lexer with source code
Lexer::Lexer(std::string source) : source(source), index(0) {}

// Checks if we've reached the end of the source code
bool Lexer::isEnd() const {
    return index >= source.size();
}

// Main function to retrieve the next token from the source code
Token Lexer::getNextToken() {
    // Skip any whitespace characters
    while (!isEnd() && std::isspace(source[index])) {
        index++;
    }

    // If we've reached the end, return an END token
    if (isEnd()) {
        return Token(TokenType::END, "");
    }

    // Variable to build the current string being processed
    std::string currentString = "";
    char currentChar = source[index];

    // Check for numeric literals (numbers)
    if (std::isdigit(currentChar)) {
        std::string numStr;
        while (!isEnd() && std::isdigit(source[index])) {
            numStr += source[index++];
        }
        return Token(TokenType::NUMBER, numStr); // Return a NUMBER token
    }

    // Check for keywords and identifiers
    
    if (std::isalpha(currentChar)) {
        // Build the current identifier/keyword string
        while (!isEnd() && std::isalpha(source[index])) {
            currentString += source[index++];
        }

        // Check if it's a specific keyword ("cin" or "cout")
        if (currentString == "cin") {
            return Token(TokenType::CIN, currentString); // Return CIN token
        }
        if (currentString == "cout") {
            return Token(TokenType::COUT, currentString); // Return COUT token
        }

        // Check if it matches other keywords ("if", "else", "while")
        if (currentString == "if" || currentString == "else" || currentString == "while") {
            return Token(TokenType::KEYWORD, currentString); // Return KEYWORD token
        }

        // Otherwise, treat it as a general identifier (variable name)
        return Token(TokenType::IDENTIFIER, currentString);
    }

    // Check for operators (+, -, *, /)
    if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
        index++;
        return Token(TokenType::OPERATOR, std::string(1, currentChar)); // Return OPERATOR token
    }

    // Check for punctuation symbols like parentheses and semicolon
    if (currentChar == '(' || currentChar == ')' || currentChar == ';') {
        index++;
        return Token(TokenType::PUNCTUATION, std::string(1, currentChar)); // Return PUNCTUATION token
    }

    // Skip unrecognized characters and continue to the next token
    index++;
    return getNextToken();
}
