#include "tokenTypes.h"
#include "token.h"
#include <string>
using namespace std;

Token::Token(TokenType type, std::string lexeme, std::string literal, int line) {
    this->type = type;
    this->lexeme = lexeme;
    this->literal = literal;
    this->line = line;
}

string Token::toString() const{
    // return type + " " + lexeme + " " + literal;
    return lexeme;
}