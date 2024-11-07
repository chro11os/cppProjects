#include "lexer.h"
#include <cctype>

// Constructor that initializes the lexer with the source code input
Lexer::Lexer(const std::string& sourceCode)
    : sourceCode(sourceCode), currentIndex(0), lineNumber(1) {}

// Peek at the current character without consuming it
char Lexer::peek() const {
    return currentIndex < sourceCode.size() ? sourceCode[currentIndex] : '\0';
}

// Advance to the next character, updating the current index and line number if needed
char Lexer::advance() {
    char currentChar = peek();
    currentIndex++;
    if (currentChar == '\n') lineNumber++; // Track new lines for error reporting
    return currentChar;
}

// Skip over whitespace characters in the source code
void Lexer::skipWhitespace() {
    while (isspace(peek())) {
        advance();
    }
}

// Retrieve the next token in the source code
Token Lexer::nextToken() {
    skipWhitespace(); // Skip any whitespace before reading a token
    char currentChar = peek();

    // Determine the type of token based on the current character
    if (isalpha(currentChar)) return identifierOrKeyword(); // Check for keywords or identifiers
    if (isdigit(currentChar)) return number();              // Check for numbers
    if (currentChar == '+' || currentChar == '-' || currentChar == '=') return symbol(); // Operators

    // End of input reached
    if (currentChar == '\0') {
        return Token(TokenType::END_OF_FILE, "", lineNumber);
    }

    // Unknown character encountered
    advance();
    return Token(TokenType::UNKNOWN, std::string(1, currentChar), lineNumber);
}

// Identify keywords or identifiers in the source code
Token Lexer::identifierOrKeyword() {
    std::string lexeme;
    while (isalnum(peek())) {
        lexeme += advance();
    }

    // Determine if lexeme is a keyword (e.g., "int", "cout", "cin") or an identifier
    TokenType type = (lexeme == "int" || lexeme == "cout" || lexeme == "cin") ? TokenType::KEYWORD : TokenType::IDENTIFIER;
    return Token(type, lexeme, lineNumber);
}

// Identify numerical literals in the source code
Token Lexer::number() {
    std::string lexeme;
    while (isdigit(peek())) {
        lexeme += advance();
    }
    return Token(TokenType::LITERAL, lexeme, lineNumber);
}

// Identify operators or symbols in the source code
Token Lexer::symbol() {
    char currentChar = advance();
    TokenType type = (currentChar == '=') ? TokenType::ASSIGNMENT : TokenType::OPERATOR;
    return Token(type, std::string(1, currentChar), lineNumber);
}
