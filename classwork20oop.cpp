// classwork20oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "flashdrive.h"
#include "disk.h"

int main() {
    Storage* storage1 = new FlashDrive("Samsung", 32);
    storage1->writeData();
    storage1->readData();
    storage1->format();

    IUsb* usbDevice = dynamic_cast<IUsb*>(storage1);
    if (usbDevice) {
        usbDevice->connect();
        usbDevice->disconnect();
    }

    delete storage1;

    Storage* storage2 = new Disk("Sony", 500, false);
    storage2->writeData();
    storage2->readData();
    storage2->format();

    delete storage2;

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
