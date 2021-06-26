//
//  stackNode.h
//  OOP1_CPP
//
//  Created by Aaron on 2021/4/1.
//

#ifndef stackNode_h
#define stackNode_h

class Stack; // Forward declarartion

class StackNode {
    friend class Stack; // Make stack a friend
public:
    explicit StackNode(const int &inputData)
    :data(inputData), nextPtr(NULL)
    {};
    
private:
    int data;
    StackNode *nextPtr;
};

#endif /* stackNode_h */
