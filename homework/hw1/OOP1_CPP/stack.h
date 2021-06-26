//
//  stack.h
//  OOP1_CPP
//
//  Created by Aaron on 2021/4/1.
//

#ifndef stack_h
#define stack_h

#include "stackNode.h"

class Stack{
public:
    explicit Stack();
    ~Stack();
    
    void push(int x);
    int pop();
    int isEmpty();
    
private:
    StackNode *firstPtr;
    StackNode *lastPtr;
};

#endif /* stack_h */
