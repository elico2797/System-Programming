/*  Assignment C++: 2
    Author: Amichai Malle,  ID: 308476977
            Eliav Cohen,    ID: 318191913
 */
#ifndef __SET_H
#define __SET_H

#include <iostream>
#define Maximum_Size 1000

class Set{
private:
    int *arr;
    int maxSize;
    int currentSize;
public:
    Set(); //default constructor, creates an empty set with size 0, and maximum 1000 elements
    Set(int); // constructor, creates an empty set with size 0, and maximum maxSize elements
    Set& operator=(const Set &s);   //operator equals
    Set& operator+=(int num);//operator += , get integer and add it to the set
    Set operator+(int num) const;     //operator + get integer and retern a new set with the union of the set and the integer
    Set operator+(const Set &s) const;//operator + , get 2 sets and return a new set with the union of the 2 sets
    bool operator>(const Set &s) const;// operator > , return true if the first set is bigger than the second set
    bool operator<(const Set &s) const;// operator < , return true if the first set is smaller than the second set
    const int& operator[] (int index) const; // operator [] , get index and return the value in the index
    friend std::ostream& operator<<(std::ostream& os, const Set& s);//operator << , get ostream and set and print the set
    friend Set operator+(int, const Set &s); // operator + , get integer and set and return a new set with the union of the set and the integer
    friend Set& operator+=(int, Set &s) ;// operator += , get integer and set and add the integer to the set
    bool isEmpty() const; // return true if the set is empty
    inline int getCurrentSize() {return this->currentSize;};
    ~Set(); //  destructor
};


#endif // __SET_H