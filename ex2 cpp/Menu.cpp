/*  Assignment C++: 2
    Author: Amichai Malle,  ID: 308476977
            Eliav Cohen,    ID: 318191913
 */

#include "Menu.h"
#include <iostream>


Menu::Menu() {
// default constructor
}

Menu::~Menu() {
    // default destructor
}

void Menu::mainMenu() {
    int choice;
    do {
        this->printMainMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                this->setMenu();
                break;
            case 2:
                this->queueMenu();
                break;
            case 3:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid selection." << std::endl;
                break;
        }
    } while (choice != 3);
} //main menu function, the user can choose between set and queue menu

void Menu::setMenu() {
    int choice, val;
    Set s1, s2;
    do {
        this->printSetMenu();
        std::cin >> choice;
        switch (choice) {
            case 1: {
                if (s1.isEmpty()) {
                    std::cout << "Set 1 is empty" << std::endl;
                } else {
                    std::cout << s1 ;
                }
                break;
            }
            case 2: {
                if (s2.isEmpty()) {
                    std::cout << "Set 2 is empty" << std::endl;
                } else {
                    std::cout << s2 ;
                }
                break;
            }
                case 3: {
                    std::cout << "Give a number:";
                    std::cin >> val;
                    s1 += val;
                    break;
                }
                case 4: {
                    std::cout << "Give a number:";
                    std::cin >> val;
                    s2 += val;
                    break;
                }
                case 5: {
                    Set s3 = s1 + s2;
                    if (s3.isEmpty()) {
                        std::cout << "The union is empty" << std::endl;
                    } else {
                        std::cout << s3 ;
                    }
                    break;
                }
                case 6: {
                    continue;
                }
                default:
                    std::cout << "Invalid selection." << std::endl;
                break;
            }

        }
        while (choice != 6);
    } //set menu function, the user can choose between 6 options in order to configure and control the sets

void Menu::queueMenu() {
    int choice, queueSize, val;
    std::cout << "Enter the size of the queue: ";
    std::cin >> queueSize;
    myQueue q1(queueSize);
    do {
        this->printQueueMenu();
        std::cin >> choice;
        switch (choice) {
            case 1: {
                if (q1.isEmpty()) {
                    std::cout << "The queue is empty" << std::endl;
                } else
                    std::cout << q1 << std::endl;
                break;
            }
            case 2: {
                std::cout << "insert new element:";
                std::cin >> val;
                if (q1.enQueue(val)) {
                    std::cout << "The new queue:" << std::endl;
                    std::cout << q1 << std::endl;
                } else {
                    std::cout << "Queue is full" << std::endl;
                }
                break;
            }
            case 3: {
                q1.deQueue();
                if (!q1.isEmpty()) {
                    std::cout << "The new queue:" << std::endl;
                    std::cout << q1 << std::endl;
                } else {
                    std::cout << "Queue is empty" << std::endl;
                }
                break;
            }
            case 4: {
                std::cout << q1.peek() << std::endl;
                break;
            }
            case 5: {
                continue;
            }
            default:
                std::cout << "Invalid selection." << std::endl;
                break;

        }

    } while (choice != 5);


} // queue menu function, the user can choose between 5 options in order to configure and control the queue

void Menu::printMainMenu() {
    std::cout << "(1) Set Menu" << std::endl;
    std::cout << "(2) Integer Queue Menu" << std::endl;
    std::cout << "(3) Exit" << std::endl;
}// print function for the main menu

void Menu::printSetMenu() {
    std::cout << "*** Welcome to Set Menu ***" << std::endl;
    std::cout << "To select an item, enter" << std::endl;
    std::cout << "1 Show set 1" << std::endl;
    std::cout << "2 Show set 2" << std::endl;
    std::cout << "3 add element to set 1" << std::endl;
    std::cout << "4 add element to set 2" << std::endl;
    std::cout << "5 Show set1 U set 2 (union)" << std::endl;
    std::cout << "6 to exit" << std::endl;
} // print function for the set menu

void Menu::printQueueMenu() {
    std::cout << "*** Welcome to Queue Menu ***" << std::endl;
    std::cout << "To select an item, enter" << std::endl;
    std::cout << "1 Show Queue" << std::endl;
    std::cout << "2 Insert new element" << std::endl;
    std::cout << "3 Remove element" << std::endl;
    std::cout << "4 Check the first element" << std::endl;
    std::cout << "5 to exit" << std::endl;
}// print function for the queue menu