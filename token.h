#ifndef TOKEN_H
#define TOKEN_H
#include "tokenTypes.h"
#include <string>
using namespace std;

class Token {
    private:
        TokenType type;
        string lexeme;
        string literal;
        int line;

    Token(TokenType type, string lexeme, string literal, int line) {
        this->type = type;
        this->lexeme = lexeme;
        this->literal = literal;
        this->type = type;
    }

    public:
        string toString() {
            return type + " " + lexeme + " " + literal;
        }
};

#endif