#include "lexer.h"

// Constructor to initialize Lexer with source code
Lexer::Lexer(const std::string& sourceCode)
    : sourceCode(sourceCode), currentPosition(0), lineNumber(1) {
    tokenize(); // Automatically tokenize upon initialization
}

// Method to tokenize the source code
void Lexer::tokenize() {
    while (currentPosition < sourceCode.size()) {
        char currentChar = sourceCode[currentPosition];

        // Check for semicolon
        if (currentChar == ';') {
            tokens.push_back(Token(TokenType::SEMICOLON, ";", lineNumber));
            advance();
            continue;
        }

        // Check for assignment operator '='
        if (currentChar == '=') {
            tokens.push_back(Token(TokenType::ASSIGNMENT, "=", lineNumber));
            advance();
            continue;
        }

        // Check for operators (+, -, *, /)
        if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            tokens.push_back(Token(TokenType::OPERATOR, std::string(1, currentChar), lineNumber));
            advance();
            continue;
        }

        // Check for identifiers (starting with a letter)
        if (isalpha(currentChar)) {
            std::string lexeme;
            while (isalnum(currentChar)) {  // Continue while alphanumeric
                lexeme += currentChar;
                advance();
                currentChar = sourceCode[currentPosition];
            }
            tokens.push_back(Token(TokenType::IDENTIFIER, lexeme, lineNumber));
            continue;
        }

        // Check for literals (numbers)
        if (isdigit(currentChar)) {
            std::string lexeme;
            while (isdigit(currentChar)) {  // Continue while numeric
                lexeme += currentChar;
                advance();
                currentChar = sourceCode[currentPosition];
            }
            tokens.push_back(Token(TokenType::LITERAL, lexeme, lineNumber));
            continue;
        }

        // Advance to the next character if no match
        advance();
    }

    // Add end of file token at the end
    tokens.push_back(Token(TokenType::END_OF_FILE, "", lineNumber));
}

// Method to retrieve the next token
Token Lexer::nextToken() {
    if (tokenIndex < tokens.size()) {
        return tokens[tokenIndex++];
    }
    return Token(TokenType::END_OF_FILE, "", lineNumber); // Return END_OF_FILE if no more tokens
}

// Method to move the lexer to the next character
void Lexer::advance() {
    currentPosition++;
    if (currentPosition < sourceCode.size() && sourceCode[currentPosition] == '\n') {
        lineNumber++;
    }
}
