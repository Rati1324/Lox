#include "headers/expr.h"
#include <iostream>

Binary::Binary(Expr left, Token op, Expr right) {
    this->left = left;
    this->op = op;
    this->right = right;
};

Literal::Literal(std::string stringLiteral, double doubleLiteral, bool isString) {
    this->doubleLiteral = doubleLiteral;
    this->stringLiteral = stringLiteral;
    this->isString = isString;
}

Literal::Literal(){};

void Binary::accept() {
    std::cout << "accepting binary";
}

void Grouping::accept() {
    std::cout << "accepting grouping";
}
