/*  Assignment C++: 1
    Author: Amichai Malle,  ID: 308476977
            Eliav Cohen,    ID: 318191913
 */
#ifndef _DispenserType_H
#define _DispenserType_H


class DispenserType {// this class will define the dispenser type, and will include the number of items and the cost of the item
    // we will define the constructor and the destructor
    // we will define the function makeSale that will reduce the number of items by 1
    // we will define the function getNoOfItems that will return the number of items
    // we will define the function getCost that will return the cost of the item

private:
    int numberOfItems;
    int cost;
public:
    DispenserType() {numberOfItems=0; cost=0;};
    DispenserType(int setNoOfItems, int setCost);
    int getNoOfItems() const {return numberOfItems;};
    int getCost() const {return cost;};
    void makeSale();
    void setNoOfItems(int num) {numberOfItems = num;};
    void setCost(int num) {cost = num;};
    ~DispenserType();
};

#endif