/*  Assignment C++: 1
    Author: Amichai Malle,  ID: 308476977
            Eliav Cohen,    ID: 318191913
 */

#include <iostream>
using namespace std;

#include "VendingMachine.h"

VendingMachine::VendingMachine() // this is the constructor , here we define the options, and the cash register object
{
    orange = DispenserType(10, 45);
    carrot = DispenserType(5, 50);
    pomegranate = DispenserType(4, 75);
    counter = CashRegister();
};
void VendingMachine::sellProduct(char product) {// this function will sell the product, and will call the other functions to make the sale
    int Payment = 0;
    switch (product) {
        case 'O':
            sellFruit(orange);
            break;
        case 'C':
            sellFruit(carrot);
            break;
        case 'P':
            sellFruit(pomegranate);
            break;
        default:
            break;
    }
}
void VendingMachine::sellFruit(DispenserType &fruit) { // this function will sell the fruit, and will call the other functions to make the sale
    int moneyReceived = 0;
    if (fruit.getNoOfItems() > 0) {
        moneyReceived = getPayment(fruit.getCost());
        if (moneyReceived >= fruit.getCost()) {
            printCollectItem();
            fruit.makeSale();
            counter.acceptAmount(moneyReceived);
        } else {
            printNotEnoughMoney();
        }
    } else {printSoldOut();}
}
int VendingMachine::getPayment(int price) { // this function will get the payment from the user
    int moneyInHand = 0;
    int moneyRecived = 0;
    cout << "Please deposit " << price << " cents" << endl;
    cin >> moneyInHand;
    moneyRecived = moneyInHand;
    if (moneyRecived < price){
        cout << "Please deposit another " << price - moneyRecived << " cents" << endl;
        cin >> moneyInHand;
        moneyRecived = moneyRecived + moneyInHand;
    }
    return moneyRecived;
}
void VendingMachine::printSoldOut() const {
    cout << "Sorry, this item is sold out." << endl;
}
void VendingMachine::printCollectItem() const {
    cout << "Collect your item at the bottom and enjoy" << endl;
    cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl;
    cout << endl;

}
void VendingMachine::printNotEnoughMoney() const {
    cout << "The amount is not enough. Collect what you deposited" << endl;
    cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl;
    cout << endl;

}
VendingMachine::~VendingMachine() {}