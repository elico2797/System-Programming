/*  Assignment C++: 1
    Author: Amichai Malle,  ID: 308476977
            Eliav Cohen,    ID: 318191913
 */
#ifndef __STACK_H
#define __STACK_H
#include "StackNode.h"

class Stack { // stack class, user StackNode class , and create a stack of StackNode
    //we will define our stack as a linked list, so we will have a pointer to the top of the stack
    //and a pointer to the bottom of the stack
    // in the header file we will define the functions and the variables

private:
    StackNode *top;
public:
    Stack() {top = nullptr;}
    void push(int data);
    void pop();
    bool isEmpty() const;
    int peek() const;
    ~Stack();
};

#endif