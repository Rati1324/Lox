#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>
#include "token.h"
#include <iostream>

using namespace std;

struct Scanner {
    string source;
    vector<Token> tokens;
    int start;
    int current;
    int line;

    Scanner(string source);
    vector<Token> scanTokens();
    void scanToken();
    bool isAtEnd();
    bool match(char expected); 
    char peek(); 
    void catchString();
    void addToken(TokenType type);
    void addToken(TokenType type, string literal);
    void getTokens();
};

#endif