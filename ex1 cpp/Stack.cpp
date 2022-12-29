/*  Assignment C++: 1
    Author: Amichai Malle,  ID: 308476977
            Eliav Cohen,    ID: 318191913
 */

#include <climits>
#include <iostream>
using namespace std;
#include "Stack.h"

void Stack::push(int data) {
    StackNode *newNode = new StackNode(data, top);
    top = newNode;
}
void Stack::pop() {
    if (top == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }
    StackNode *temp = top;
    top = top->getNext();
    delete temp; //free(temp)?!
}
bool Stack::isEmpty() const {
    return top == nullptr;
}
int Stack::peek() const {
    if (top == nullptr) {
        return INT_MIN;
    }
    return top->getData();
}
Stack::~Stack(){
    while (top != nullptr){
        StackNode *temp = top;
        top = top->getNext();
        delete temp;
    }
}