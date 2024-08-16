#include "headers/expr.h"
#include "headers/tokenTypes.h"
#include <iostream>

Token::Token(){};

Token::Token(TokenType type, std::string lexeme, Literal lit, int line) {
    this->type = type;
    this->lexeme = lexeme;
    this->line = line;
    this->lit = lit;
}

std::string Token::toString() const{
    return "lexeme: " + lexeme + "\nliteral: " + (lit.isString ? lit.stringLiteral : std::to_string(lit.doubleLiteral));
}

Binary::Binary(Expr* left, Token op, Expr* right) {
    this->left = left;
    this->op = op;
    this->right = right;
};

// void* Binary::accept(Visitor* visitor) const {
//     return visitor->visitBinary(this);
// }

Literal::Literal(std::string stringLiteral, double doubleLiteral, bool isString) {
    this->doubleLiteral = doubleLiteral;
    this->stringLiteral = stringLiteral;
    this->isString = isString;
}

std::string Literal::accept(Visitor* visitor) const {
    return visitor->visitLiteral(this);
}

Literal::Literal(){};
