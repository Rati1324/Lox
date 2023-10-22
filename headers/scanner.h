#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>
#include "token.h"
#include "literal.h"
#include <iostream>

using namespace std;

struct Scanner {
    string source;
    vector<Token> tokens;
    int start = 0;
    int current = 0;
    int line = 1;

    Scanner(string source);
    vector<Token> scanTokens();
    void scanToken();
    bool isAtEnd();
    bool match(char expected); 
    char peek(); 
    void catchString();
    void addToken(TokenType type);
    void addToken(TokenType type, Literal lit);
    void getTokens();
    bool isDigit(char c);
    void catchNumber();
    char peekNext();
};

#endif