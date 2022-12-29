/*  Assignment C++: 2
    Author: Amichai Malle,  ID: 308476977
            Eliav Cohen,    ID: 318191913
 */
#ifndef EX4_SIKSIK_MENU_H
#define EX4_SIKSIK_MENU_H

#include "Set.h"
#include "myQueue.h"

class Menu {
private:
    void setMenu();
    void queueMenu();
    void printMainMenu();
    void printSetMenu();
    void printQueueMenu();

public:
    Menu();
    ~Menu();
    void mainMenu();
};


#endif //EX4_SIKSIK_MENU_H
