#include "tokenTypes.h"
#include <string>
using namespace std;

class Token {
    private:
        TokenType type;
        string lexeme;
        string literal;
        int line;

    public:
        Token(TokenType type, string lexeme, string literal, int line) {
            this->type = type;
            this->lexeme = lexeme;
            this->literal = literal;
            this->type = type;
        }

        string toString() {
            return type + " " + lexeme + " " + literal;
        }
};