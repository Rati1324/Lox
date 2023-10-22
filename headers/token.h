#ifndef TOKEN_H
#define TOKEN_H

#include "tokenTypes.h"
#include "literal.h"
#include <string>

struct Token {
    TokenType type;
    std::string lexeme;
    std::string stringLiteral = "";
    Literal lit;
    double doubleLiteral = 0.0;
    int line;

    Token(TokenType type, std::string lexeme, Literal, int line);
    std::string toString() const;
};

#endif