// classwork19oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Parrot.h"
#include"Chicken.h"
#include"Penguin.h"
#include"Duck.h"

int main()
{
    Bird* bird1 = new Penguin("Penguin");
    bird1->eat("fish");
    bird1->swim();
    delete bird1;

    Bird* bird2 = new Chicken("Chicken");
    bird2->eat("corn");
    bird2->swim();
    delete bird2;

    Bird* bird3 = new Parrot("Parrot");
    bird3->eat("fruits");
    bird3->fly();
    delete bird3;

    Bird* bird4 = new Duck("Duck");
    bird4->eat("insects");
    bird4->fly();
    bird4->swim();
    delete bird4;

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
