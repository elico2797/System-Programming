/*  Assignment C++: 1
    Author: Amichai Malle,  ID: 308476977
            Eliav Cohen,    ID: 318191913
 */
#ifndef _VendorMachine_H
#define _VendorMachine_H

#include "DispenserType.h"
#include "CashRegister.h"

class VendingMachine { // this is a header file for the VendingMachine, which is the machine of the drinks
private:
    DispenserType orange;
    DispenserType carrot;
    DispenserType pomegranate;
    CashRegister counter;
    int getPayment(int price);
    void printSoldOut() const;
    void sellFruit(DispenserType&);
    void printCollectItem() const;
    void printNotEnoughMoney() const;
public:
    VendingMachine();
    void sellProduct(char product);
    ~VendingMachine();
};

#endif
