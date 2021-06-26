//
//  main.cpp
//  OOP1_CPP
//
//  Created by Aaron on 2021/4/1.
//

#include <iostream>
#include "stack.h"
using namespace std;

const int NUM_ITEMS = 200;

int main() {
    Stack stk1;
    Stack stk2;
    
    // Push data
    for (int i=0; i<NUM_ITEMS; ++i) {
        stk1.push(i);
        stk2.push(i);
    }
    
    // Print and pop stack 1
    cout << "Dump of stack 1:" << endl;
    for (int i=0; i<NUM_ITEMS; ++i) {
        cout << stk1.pop() << endl;
    }
    
    // Print and pop stack 2
    cout << "Dump of stack 2:" << endl;
    for (int i=0; i<NUM_ITEMS; ++i) {
        cout << stk2.pop() << endl;
    }
    
    return 0;
}
