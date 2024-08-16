#include "astPrinter.h"
#include "expr.h"

std::string AstPrinter::print(Expr* expr) {
    return expr->accept(this);
}

std::string AstPrinter::visitLiteral(const Literal* expr) const {
    // parenthesize("name", expr->left, expr->right);
    return "hi";
}

std::string AstPrinter::parenthesize(std::string name, Expr* expr) {
    return "hi from aprenthesize";
    // std::string result = "()";
    // result.append(expr.accept(this))
}