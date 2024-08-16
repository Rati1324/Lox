#ifndef EXPR_H
#define EXPR_H

#include "tokenTypes.h"
#include <iostream>

class Visitor {
    public:
        virtual std::string visitLiteral(const Literal* literal) const = 0;
        // virtual void* visitBinary(const Binary* Binary) const = 0;
};

class Expr {
    public:
        virtual ~Expr() {}
        virtual std::string accept(Visitor* visitor) const = 0;
};

class Literal: public Expr {
    public:
        std::string stringLiteral;
        double doubleLiteral;
        bool isString;
        std::string accept(Visitor* visitor) const override;
        Literal(std::string stringLiteral, double doubleLiteral, bool isString);
        Literal();
};

class Token {
    public:
        TokenType type;
        std::string lexeme;
        Literal lit;
        int line;

        Token();
        Token(TokenType type, std::string lexeme, Literal, int line);
        std::string toString() const;
};

class Binary: public Expr {
    public:
        Expr* left;
        Token op;
        Expr* right;
        Binary(Expr* left, Token op, Expr* right);
        // void* accept(Visitor* visitor) const override;
};

class Grouping: public Expr {
    public:
        Expr* expression;
        // void accept();
};

class Unary: public Expr {
    public:
        Token op;
        Expr* right;
};

#endif