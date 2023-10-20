#include <iostream>
#include <fstream>
#include <string>
#include "tokenTypes.h"
#include "token.h"
// #include "scanner.h"
using namespace std;

bool hadError = false;

void run(string source) {
    // Scanner s = Scanner(source);
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
        run(userInput);
        hadError = false;
    }
}

int main(int argc, char** argv) {
    cout << "hi" << endl;
    Token t = Token(LEFT_PAREN, "(", "", 1);
    // cout << tk.toString() << endl;
    if (argc > 2) {
        cout << "Usage: cLox [filename]" << endl;
    } else if (argc == 2) {
        runFile(argv[1]);
    } else {
        runPrompt();
    }
    return 0;
}