// Homework 17 oop Establishment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Establishment.h"
#include "Restaurant.h"
#include "Pizzeria.h"
#include "Cafe.h"
#include "Glovocourier.h"

int main()
{
    Establishment* restaurantObj = new Restaurant();
    Establishment* pizzeria = new Pizzeria();
    Establishment* cafe = new Cafe();
    std::cout << "&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
    Glovocourier courier;
    courier.deliver(*restaurantObj);
    
    courier.deliver(*pizzeria);
    
    courier.deliver(*cafe);
    std::cout << "&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
    std::cout << "Restaurant Menu:" << std::endl;
    restaurantObj->getMenu();
    std::cout << "&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;

    std::cout << "Pizzeria Menu:" << std::endl;
    pizzeria->getMenu();
    std::cout << "&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
    std::cout << "Cafe Menu:" << std::endl;
    cafe->getMenu();
    std::cout << "&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
    std::cout << "Choose an establishment:" << std::endl;
    std::cout << "1. Restaurant" << std::endl;
    std::cout << "2. Pizzeria" << std::endl;
    std::cout << "3. Cafe" << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
    {
        Glovocourier courier;
        courier.deliver(*restaurantObj);
        std::cout << "Restaurant Menu:" << std::endl;
        restaurantObj->getMenu();
    }
    break;
    std::cout << "&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
    case 2:
    {
        Glovocourier courier;
        courier.deliver(*pizzeria);
        std::cout << "Pizzeria Menu:" << std::endl;
        pizzeria->getMenu();
    }
    break;
    std::cout << "&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
    case 3:
    {
        Glovocourier courier;
        courier.deliver(*cafe);
        std::cout << "Cafe Menu:" << std::endl;
        cafe->getMenu();
    }
    break;
    std::cout << "&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
    default:
        std::cout << "Invalid choice. Exiting..." << std::endl;
        break;
    }
    std::cout << "Bon appetit!" << std::endl;
    delete restaurantObj; 
    delete pizzeria;
    delete cafe;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
