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

        void scanToken() {
            char c = source[current];
            switch (c) {
                case '(': addToken(LEFT_PAREN); break;
                case ')': addToken(RIGHT_PAREN); break;
                case '{': addToken(LEFT_BRACE); break;
                case '}': addToken(RIGHT_BRACE); break;
                case ',': addToken(COMMA); break;
                case '.': addToken(DOT); break;
                case '-': addToken(MINUS); break;
                case '+': addToken(PLUS); break;
                case ';': addToken(SEMICOLON); break;
                case '*': addToken(STAR); break;
            }
            advance();
        }

        void advance() {
            current++;
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
            tokens.push_back(Token(EOF_TOKEN, "", "", line));
            return tokens;
        }

        void addToken(TokenType type) {
            addToken(type, "");
        }

        void addToken(TokenType type, string literal) {
            string text = source.substr(start, current);
            tokens.push_back(Token(type, text, literal, line));
        }

        void getTokens() {
            for (int i = 0; i < tokens.size(); i++) {
                cout << tokens[i].toString() << endl;
            }
        }
};