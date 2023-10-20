#include <iostream>
// #include <cstdio>
#include <fstream>
#include <string>
using namespace std;

void run(string source) {
    for (int i = 0; i < source.length(); i++) {
        cout << source[i] << endl;
    }
}

string read_file(char* filename) {
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
    return source;
}

void runPrompt() {
    string userInput;
    while (1) {
        cout << ">";
        getline(cin, userInput);
        if (userInput == "") break;
        run(userInput);
    }
}

int main(int argc, char** argv) {
    if (argc > 2) {
        cout << "Usage: cLox [filename]" << endl;
    } else if (argc == 2) {
        string source = read_file(argv[1]);
        run(source);
    } else {
        runPrompt();
    }

    return 0;
}