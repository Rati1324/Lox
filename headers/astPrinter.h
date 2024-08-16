#ifndef ASTPRINTER_H
#define ASTPRINTER_H

#include "expr.h"
#include <iostream>

class AstPrinter: public Visitor {
    public:
        std::string visitLiteral(const Literal* expr) const override;
        std::string print(Expr* expr);
        std::string parenthesize(std::string name, Expr* expr);
};

#endif
