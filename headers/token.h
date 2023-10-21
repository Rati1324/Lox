#ifndef TOKEN_H
#define TOKEN_H

#include "tokenTypes.h"
#include <string>

class Token {
    private:
        TokenType type;
        std::string lexeme;
        std::string literal;
        int line;

    public:
        Token(TokenType type, std::string lexeme, std::string literal, int line);
        std::string toString() const;
            
};

#endif