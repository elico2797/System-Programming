/*  Assignment C++: 2
    Author: Amichai Malle,  ID: 308476977
            Eliav Cohen,    ID: 318191913
 */

#ifndef EX4_SIKSIK_MYQUEUE_H
#define EX4_SIKSIK_MYQUEUE_H
#include <vector>
#include <iostream>

class myQueue {
private:
    std::vector<int> queue; // the queue, implemented as a vector
    int maxQ ; // the maximum size of the queue
public:
    myQueue(); // default constructor
    myQueue(int); // constructor
    bool enQueue(int val); // add a value to the queue
    bool deQueue(); // remove a value from the queue
    bool isEmpty () const; // return true if the queue is empty
    int peek() const;    //peek() – returns a first element of the queue, and if empty return -1
    inline int getSize() const {return this->queue.size();}; // return the size of the queue
    friend std::ostream& operator<<(std::ostream& os, const myQueue& queue1);
    ~myQueue(); // destructor
};


#endif //EX4_SIKSIK_MYQUEUE_H
