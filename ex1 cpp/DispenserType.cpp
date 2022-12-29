/*  Assignment C++: 1
    Author: Amichai Malle,  ID: 308476977
            Eliav Cohen,    ID: 318191913
 */

#include <iostream>
using namespace std;

#include "DispenserType.h"

DispenserType::DispenserType(int setNoOfItems, int setCost) { // constructor that will set the number of items and the cost of the item
    //cout << "DispenserType constructor" << endl;
    numberOfItems = setNoOfItems;
    cost = setCost;
}
void DispenserType::makeSale() {// function that will reduce the number of items by 1, and actually make the sale completed
    this->numberOfItems -= 1;
}
DispenserType::~DispenserType() { // destructor
    //cout << "DispenserType destructor" << endl;
}
