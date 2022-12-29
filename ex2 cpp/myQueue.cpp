/*  Assignment C++: 2
    Author: Amichai Malle,  ID: 308476977
            Eliav Cohen,    ID: 318191913
 */

#include "myQueue.h"
#include <iostream>

myQueue::myQueue() { // default constructor
// nothing to do here
}

myQueue::myQueue(int maxQ) {
    this->maxQ = maxQ; // set the maximum size of the queue
} // constructor

bool myQueue::enQueue(int val) { //
    if (this->queue.size() == this->maxQ) {
        return false;
    }
    this->queue.push_back(val);
    return true;
} // add a value to the queue (if the queue is full, return false)

bool myQueue::deQueue() {
    if (this->queue.empty()) {
        return false;
    }
    this->queue.erase(this->queue.begin());
    return true;
} // remove a value from the queue (if the queue is empty, return false)

bool myQueue::isEmpty() const {
    return this->queue.empty();
} // return true if the queue is empty

int myQueue::peek() const {
    if (this->queue.empty()) {
        return -1;
    }
    else {
        return this->queue[0];
    }
} // peek() – returns a reference to the first element of the queue.


std::ostream& operator<<(std::ostream& os, const myQueue& queue1) {
    for (int i = 0; i < queue1.queue.size(); i++) {
        if (i == queue1.queue.size() - 1)
            os << queue1.queue[i];
        else {
            os << queue1.queue[i] << " <- ";
        }
    }
    return os;
}

// print the queue

myQueue::~myQueue() {
    this->queue.clear();
} // destructor
