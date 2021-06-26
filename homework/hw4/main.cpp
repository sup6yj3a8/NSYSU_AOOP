//
//  main.cpp
//  OOP4
//
//  Created by Aaron on 2021/5/11.
//

#include <iostream>
#include "lexer.hpp"
#include <cctype>
using std::cout;
using std::endl;

const std::string TRANSLATE[] = {
    "AND", "BASIC", "BREAK", "DO", "ELSE",
    "EQ", "FALSE", "GE", "ID", "IF",
    "INDEX", "LE", "MINUS", "NE", "NUM",
    "OR", "REAL", "TEMP", "TRUE", "WHILE"};

int main(int argc, const char * argv[]) {
    Lexer lexer(argv[1]);
    try {
        while (true) {
            Token t = lexer.scan();
            cout << '(';
            if ( t.tag < 256 ) {
                cout << t.toString();
            }else{
                cout << TRANSLATE[t.tag - 256];
            }
            cout << ')' << endl;
        }
    } catch (IOExeception &e) {
        cout << e.what() << endl;
    }
    return 0;
}
