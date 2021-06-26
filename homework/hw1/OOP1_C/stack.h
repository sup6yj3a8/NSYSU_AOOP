//
//  stack.h
//  OOP1_C
//
//  Created by Aaron on 2021/4/1.
//

#ifndef stack_h
#define stack_h

struct stack {
    struct stackNode *firstPtr;
    struct stackNode *lastPtr;
};

extern struct stack* new_stack(void);
extern void delete_stack(struct stack *this);
extern void push(struct stack *this, int x);
extern int pop(struct stack *this);
extern int isEmpty(struct stack *this);

#endif /* stack_h */
