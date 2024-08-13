#ifndef EXPR_H
#define EXPR_H

#include "tokenTypes.h"
#include <iostream>

struct Expr {

};

struct Literal: Expr {
    std::string stringLiteral;
    double doubleLiteral;
    bool isString;
    Literal(std::string stringLiteral, double doubleLiteral, bool isString);
    Literal();
};

struct Token {
    TokenType type;
    std::string lexeme;
    std::string stringLiteral = "";
    Literal lit;
    double doubleLiteral = 0.0;
    int line;

    Token();
    Token(TokenType type, std::string lexeme, Literal, int line);
    std::string toString() const;
};

struct Binary: Expr {
    Expr left;
    Token op;
    Expr right;
    Binary(Expr left, Token op, Expr right);
    void accept();
};

struct Grouping: Expr {
    Expr expression;
    void accept();
};

struct Unary: Expr {
    Token op;
    Expr right;
};

#endif