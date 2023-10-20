#ifndef SCANNER_H
#define SCANNER_H
#include <string>
#include <iostream>
#include <vector>
#include "token.h"
using namespace std;

class Scanner {
    private:
        string source;
        vector<Token> tokens;
        int start = 0;
        int current = 0;
        int line = 1;

        scanToken() {
            char 
        }
        bool isAtEnd() {
            return current >= source.length();
        }

    public:
        Scanner(string source) {
            this->source = source;
        }

        vector<Token> scanTokens() {
            while (!isAtEnd()) {
                start = current;
                scanToken();
            }
            tokens.add(new Token(EOF_TOKEN, "", null, line));
            return tokens;
        }

        // public void addToken()
        
};

#endif