/*  Assignment C++: 2
    Author: Amichai Malle,  ID: 308476977
            Eliav Cohen,    ID: 318191913
 */

#ifndef __Set_cpp
#define __Set_cpp

#include "Set.h"
#include <iostream>



Set::Set() { //default constructor, creates an empty set with size 0, and maximum 1000 elements
    this->maxSize = Maximum_Size;
    this->currentSize = 0;
    this->arr = new int[this->maxSize];
}
Set::Set(int maxSize) {
    this->maxSize = maxSize;
    this->currentSize = 0;
    this->arr = new int[this->maxSize];
} // constructor, creates an empty set with size 0, and maximum maxSize elements
//operator implements
Set& Set::operator=(const Set &s) {
    if (this != &s) {
        this->maxSize = s.maxSize;
        this->currentSize = s.currentSize;
        delete[] this->arr;
        this->arr = new int[this->maxSize];
        for (int i = 0; i < this->currentSize; i++) {
            this->arr[i] = s.arr[i];
        }
    }
    return *this;
} // operator = , get set and return a new set with the same values
Set& Set::operator+=(int num){
        for (int i = 0; i < this->currentSize; i++) {
            if (this->arr[i] == num) {
                return *this;
            }
        }
        this->arr[this->currentSize] = num;
        this->currentSize++;
        return *this;
} // operator += , get integer and add it to the set
Set &operator+=(int num, Set &s)  {
        s += num;
        return s;
} // operator += , get integer and add it to the set (friend) in order to support the syntax: 5 += s1;
Set Set::operator+(int num) const {
    //get integer and return new set, that include the union of the set and the integer
    //check if the integer is in the set
    Set s(this->currentSize);
    s = *this;
    bool isExist = false;
    for (int i = 0; i < this->currentSize; i++) {
        if (this->arr[i] == num) {
            isExist = true;
            return s;
        }
    }
    s += num;
    return s;


} // operator + , get integer and return a new set with the union of the set and the integer
Set operator+(int num, const Set &s){
    Set p(s.currentSize);
    p = s;
    bool isExist = false;
    for (int i = 0; i < s.currentSize; i++) {
        if (s.arr[i] == num) {
            isExist = true;
            return p;
        }
    }
    p += num;
    return p;
} // operator + , get integer and return a new set with the union of the set and the integer (friend) in order to support the syntax: 5 + s1;
Set Set::operator+(const Set &s)const {
        //create new set which is the union of the 2 sets, and delete repeation numbers
    Set temp;
    for (int i = 0; i < this->currentSize; i++) {
        temp += this->arr[i];
    }
    for (int i = 0; i < s.currentSize; i++) {
        temp += s.arr[i];
    }
    //remove the repetion  numbers
    for (int i = 0; i < temp.currentSize; i++) {
        for (int j = i + 1; j < temp.currentSize; j++) {
            if (temp.arr[i] == temp.arr[j]) {
                for (int k = j; k < temp.currentSize; k++) {
                    temp.arr[k] = temp.arr[k + 1];
                }
                temp.currentSize--;
                j--;
            }
        }
    }
    return temp;
} // operator + , get 2 sets and return a new set with the union of the 2 sets, without repetition
bool Set::operator>(const Set &s) const{
    if (this->currentSize > s.currentSize) {
        return true;
    }
    return false;
} // operator > , return true if the first set is bigger than the second set
bool Set::operator<(const Set &s) const{
    if (this->currentSize < s.currentSize) {
        return true;
    }
    return false;
}// operator < , return true if the first set is smaller than the second set
const int& Set::operator[](int index) const{
    return this->arr[index];
} // operator [] , get index and return the value in the index
std::ostream& operator<<(std::ostream& os, const Set& s) {
    std::cout << "{";
    for (int i = 0; i < s.currentSize; i++) {
        if (i == s.currentSize - 1) {
            std::cout << s.arr[i];
        } else {
            std::cout << s.arr[i] << ", ";
        }
    }
    std::cout << "}" << std::endl;
    return os;
} // operator << , get ostream and set and print the set
bool Set::isEmpty() const {
    if (this->currentSize == 0) {
        return true;
    }
    return false;
}// return true if the set is empty
Set::~Set() {
    delete[] this->arr;
}

// destructor


#endif