//
//  main.c
//  OOP1_C
//
//  Created by Aaron on 2021/4/1.
//

#include <stdio.h>
#include "stack.h"

const int NUM_ITEMS = 200;

int main(void) {
    // Create a new stack
    struct stack* stk1 = new_stack();
    struct stack* stk2 = new_stack();
    
    // Push data
    for (int i=0; i<NUM_ITEMS; ++i) {
        push(stk1, 200+i);
        push(stk2, 700+i);
    }
    
    // Print and pop a top element of stack 1
    printf("Dump of stack 1:\n");
    for (int i=0; i<NUM_ITEMS; ++i) {
        printf("%d\n", pop(stk1));
    }
    
    // Print and pop a top element of stack 2
    printf("Dump of stack 2:\n");
    for (int i=0; i<NUM_ITEMS; ++i) {
        printf("%d\n", pop(stk2));
    }
    
    // Delete a stack
    delete_stack(stk1);
    delete_stack(stk2);
    
    return 0;
}
