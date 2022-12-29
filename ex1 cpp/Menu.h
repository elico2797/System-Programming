/*  Assignment C++: 1
    Author: Amichai Malle,  ID: 308476977
            Eliav Cohen,    ID: 318191913
 */

#ifndef _Menu_H
#define _Menu_H

#include <iostream>
using namespace std;

#include "VendingMachine.h"
#include "Stack.h"

class Menu {// header file that include the function and variable for the menu
private:
    VendingMachine Machine;
    Stack stack;
    int choice;
    void printMainMenu() const;
    void shopMenu();
    void printShopMenu() const;
    void stackMenu();
    void printStackMenu() const;
public:
    Menu();
    void mainMenu();
    ~Menu();
};

#endif