#ifndef TOKEN_H
#define TOKEN_H

#include "tokenTypes.h"
#include <string>

struct Token {
    TokenType type;
    std::string lexeme;
    std::string literal;
    int line;

    Token(TokenType type, std::string lexeme, std::string literal, int line);
    std::string toString() const;
};

#endif