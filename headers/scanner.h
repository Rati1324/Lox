#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>
#include "token.h"
#include <iostream>

using namespace std;

class Scanner {
    private:
        string source;
        vector<Token> tokens;
        int start;
        int current;
        int line;

        void scanToken();
        char advance();
        bool isAtEnd();
        bool match(char expected); 
        bool peek(); 

    public:
        Scanner(string source);
        vector<Token> scanTokens();
        void addToken(TokenType type);
        void addToken(TokenType type, string literal);
        void getTokens();
};

#endif