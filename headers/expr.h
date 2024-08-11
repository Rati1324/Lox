#include "token.h"

#ifndef EXPR_H
#define EXPR_H

struct Expr {

};

struct Binary: Expr {
    Expr left;
    Token op;
    Expr right;
    Binary(Expr left, Token op, Expr right);
};

struct Grouping: Expr {
    Expr expression;
};

struct Literal: Expr {
    std::string value;
};

struct Unary: Expr {
    Token op;
    Expr right;
};

#endif