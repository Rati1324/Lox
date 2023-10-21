#include <iostream>
#include <fstream>
#include <string>
#include "headers/tokenTypes.h"
#include "headers/token.h"
#include "headers/scanner.h"
using namespace std;

class Lox {
    bool hadError = false;

    public:
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

        
};

int main(int argc, char** argv) {
    cout << "hi" << endl;
    Lox lx = Lox();
    if (argc > 2) {
        cout << "Usage: cLox [filename]" << endl;
    } else if (argc == 2) {
        lx.runFile(argv[1]);
    } else {
        lx.runPrompt();
    }
    return 0;
}