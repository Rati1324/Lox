#include <iostream>
#include <fstream>
#include <string>
#include "headers/expr.h"
// #include "headers/token.h"
#include "headers/tokenTypes.h"
#include "headers/scanner.h"
#include "headers/lox.h"

using namespace std;

bool hadError = false;

void runPrompt();
void runFile(char* filename);

int main(int argc, char** argv) {
    cout << "hi" << endl;
    Scanner s = Scanner("\"string example\"");
    s.scanTokens();
    s.getTokens();

    if (argc > 2) {
        cout << "Usage: cLox [filename]" << endl;
    } else if (argc == 2) {
        runFile(argv[1]);
    } else {
        runPrompt();
    }
    return 0;
}

void error(int line, string message) {
    report(line, "", message);
}

void report(int line, string where, string message) {
    cout << "[line " << line << "] Error" << where << ": " + message << endl;
    hadError = true;
}

void run(string source) {
    Scanner s = Scanner(source);
    s.scanTokens();
    s.getTokens();
    // for (int i = 0; i < source.length(); i++) {
    //     cout << source[i] << endl;
    // }
}

void runFile(char* filename) {
    fstream my_file;
    string source;
    my_file.open(filename, ios::in);

    if (!my_file) {
        cout << "File not found" << endl;
    }
    else {
        char ch;
        while (my_file.get(ch)) {
            source.push_back(ch);
        }
        my_file.close();
    }
    run(source);
    if (hadError) exit(64);
}

void runPrompt() {
    string userInput;
    while (1) {
        cout << ">";
        getline(cin, userInput);
        if (userInput == "") break;
        // run(userInput);

        Scanner s = Scanner(userInput);
        s.scanTokens();
        s.getTokens();
        hadError = false;
    }
}

