// #include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;

void read_file(char* filename) {
    fstream my_file;
    my_file.open(filename, ios::in);
    if (!my_file) {
        printf("File not found!");
    }
    else {
        char ch;
        printf("\n", ch);
        while (my_file >> ch) {
            printf("%c \n", ch);
        }
        my_file.close();
    }
}

int main(int argc, char** argv) {
    printf("%s", argv[1]);
    read_file(argv[1]);
    return 0;
}