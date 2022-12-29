/*  Assignment C++: 1
    Author: Amichai Malle,  ID: 308476977
            Eliav Cohen,    ID: 318191913
 */

#include "StackNode.h"

StackNode::StackNode(int data, StackNode *next){
    this->data = data;
    this->next = next;
}