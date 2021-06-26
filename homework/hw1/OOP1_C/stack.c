//
//  stack.c
//  OOP1_C
//
//  Created by Aaron on 2021/4/1.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stackNode {
    int data;
    struct stackNode *nextPtr;
};

struct stackNode* new_stackNode(const int newData){
    struct stackNode* newPtr = (struct stackNode*)malloc(sizeof(struct stackNode));
    newPtr->data = newData;
    newPtr->nextPtr = NULL;
    return newPtr;
}

struct stack* new_stack(void){
    struct stack* newPtr = (struct stack*)malloc(sizeof(struct stack));
    newPtr->firstPtr = newPtr->lastPtr = NULL; // Initialization
    return newPtr;
}

void delete_stack(struct stack *this){
    free(this);
};

// Push data
void push(struct stack *this, int x){
    struct stackNode *newPtr = new_stackNode(x);
    if (isEmpty(this)) {
        this->firstPtr = this->lastPtr = newPtr;
    }else{
        this->lastPtr->nextPtr = newPtr;
        this->lastPtr = newPtr;
    }
};

// Pop and return a top data
int pop(struct stack *this){
    
    if (isEmpty(this)) {
        return 0;
    }else{
        struct stackNode *tmp = this->lastPtr;
        if (this->firstPtr == this->lastPtr) {
            this->firstPtr = this->lastPtr = NULL;
        }else{
            struct stackNode *currentPtr = this->firstPtr;
            
            // Locate second-to-last element
            while (currentPtr->nextPtr != this->lastPtr) {
                currentPtr = currentPtr->nextPtr;
            }
            
            // Update lastPtr
            this->lastPtr = currentPtr;
            currentPtr->nextPtr = NULL;
        }
        
        // Release last element and return a top data
        int topData = tmp->data;
        free(tmp);
        return topData;
    }
};

int isEmpty(struct stack *this){
    return this->firstPtr == NULL;
};
