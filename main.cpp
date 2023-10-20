#include <iostream>
#include <fstream>
#include <string>
#include "TokenTypes.h"
using namespace std;

bool hadError = false;

void run(string source) {
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
    if (argc > 2) {
        cout << "Usage: cLox [filename]" << endl;
    } else if (argc == 2) {
        runFile(argv[1]);
    } else {
        runPrompt();
    }
    return 0;
}