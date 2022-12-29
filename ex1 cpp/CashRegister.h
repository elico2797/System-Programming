
/*  Assignment C++: 1
    Author: Amichai Malle,  ID: 308476977
            Eliav Cohen,    ID: 318191913
 */
#ifndef __CASHREGISTER_H
#define __CASHREGISTER_H


class CashRegister {// this is the class that include the function and variable for the cash register
    //the integer cashOnhand on the class is private because we dont want to change the value of the cash register
    //we will use the function to change the value of the cash register
private:
    int cashOnHand;
public:
    CashRegister() {cashOnHand=0;};                     //sets the cash in the register to 0.
    CashRegister(int cashIn) {cashOnHand = cashIn;};    //sets the cash in the register to a specific amount.
    int getCurrentBalance() const {return cashOnHand;}; //returns value of cashOnHand.
    void acceptAmount(int amountIn);                    //receive the amount deposited by the customer and update the amount in the register.
    ~CashRegister(){};
};
#endif
