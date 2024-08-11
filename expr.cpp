#include "headers/expr.h"
#include "headers/token.h"

Binary::Binary(Expr left, Token op, Expr right) {
    this->left = left;
    this->op = op;
    this->right = right;
};