#include "headers/tokenTypes.h"
#include "headers/expr.h"
#include "headers/token.h"
#include <string>
using namespace std;

Token::Token(){};

Token::Token(TokenType type, std::string lexeme, Literal lit, int line) {
    this->type = type;
    this->lexeme = lexeme;
    this->line = line;
    this->lit = lit;
}

string Token::toString() const{
    return "lexeme: " + lexeme + "\nliteral: " + (lit.isString ? lit.stringLiteral : to_string(lit.doubleLiteral));
}