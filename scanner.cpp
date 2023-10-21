#include <string>
#include <iostream>
#include <vector>
#include "headers/token.h"
#include "headers/scanner.h"
#include "headers/Lox.h"

using namespace std;

Scanner::Scanner(string source) {
    this->source = source;
    this->start = 0;
    this->current = 0;
    this->line = 1;
}

vector<Token> Scanner::scanTokens() {
    while (!isAtEnd()) {
        start = current;
        scanToken();
    }
    Scanner::tokens.push_back(Token(EOF_TOKEN, "", "", line));
    return tokens;
}

void Scanner::scanToken() {
    char c = advance();
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
        case '!':
            addToken(match('=') ? BANG_EQUAL : BANG);
            break;
        default:
            error(line, "Unexpected character.");
            break;
    }
}

bool Scanner::match(char expected) {
    if (isAtEnd()) return false;
    if (Scanner::source[current] != expected) return false;
    current++;
    return true;
}

void Scanner::addToken(TokenType type) {
    addToken(type, "");
}

void Scanner::addToken(TokenType type, string literal) {
    string text = Scanner::source.substr(start, current);
    tokens.push_back(Token(type, text, literal, line));
}

char Scanner::advance() {
    Scanner::current++;
    return Scanner::source[Scanner::current - 1];
}

bool Scanner::isAtEnd() {
    return Scanner::current >= Scanner::source.length();
}

void Scanner::getTokens() {
    for (int i = 0; i < Scanner::tokens.size(); i++) {
        cout << Scanner::tokens[i].toString() << endl;
    }
}