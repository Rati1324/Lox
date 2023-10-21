#include <iostream>
#include <fstream>
#include <string>
#include "headers/tokenTypes.h"
#include "headers/token.h"
#include "headers/scanner.h"
#include "headers/Lox.h"
using namespace std;

bool hadError = false;

void error(int line, string message) {
    cout << "in error" << endl;
    report(line, "", message);
}

void report(int line, string where, string message) {
    cout << "[line " << line << "] Error" << where << ": " + message << endl;
    hadError = true;
}

void run(string source) {
    Scanner s = Scanner(source);
    for (int i = 0; i < source.length(); i++) {
        cout << source[i] << endl;
    }
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

// this one doens't scan the tokens it just runs the prompt
void runPrompt() {
    string userInput;
    while (1) {
        cout << ">";
        getline(cin, userInput);
        if (userInput == "") break;
        run(userInput);
        hadError = false;
    }
}

int main(int argc, char** argv) {
    cout << "hi" << endl;
    Scanner s = Scanner("d");
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