//
//  stack.cpp
//  OOP1_CPP
//
//  Created by Aaron on 2021/4/1.
//

#include <stdio.h>
#include "stack.h"
using namespace std;

// Default constructor
Stack::Stack()
:firstPtr(NULL), lastPtr(NULL)
{};

// Destructor
Stack::~Stack(){};

// Push data
void Stack::push(int x){
    StackNode *newPtr = new StackNode(x);
    if (isEmpty()) {
        firstPtr = lastPtr = newPtr;
    }else{
        lastPtr->nextPtr = newPtr;
        lastPtr = newPtr;
    }
}

// Pop and return a top data
int Stack::pop(){
    if (isEmpty()) {
        return false;
    }else{
        StackNode *tmpPtr = lastPtr; // Hold last element
        if (firstPtr == lastPtr) {
            firstPtr = lastPtr = NULL;
        }else{
            StackNode *currentPtr = firstPtr;
            
            // Locate second-to-last element
            while (currentPtr->nextPtr != lastPtr) {
                currentPtr = currentPtr->nextPtr;
            }
            
            // Update lastPtr
            lastPtr = currentPtr;
            currentPtr->nextPtr = NULL;
        }
        
        // Release last element and return a top data
        int topData = tmpPtr->data;
        delete tmpPtr;
        return topData;
    }
}

// Is stack empty?
int Stack::isEmpty(){
    return firstPtr == NULL;
}
