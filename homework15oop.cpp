// homework15oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "laptop.h"

int main() {
    Processor* processor = new Processor("intel core i7");
    Mouse* mouse = new Mouse("SpaceMouse Pro");
    Printer* printer = new Printer("HP DesignJet");
    VideoCard* videoCard = new VideoCard("AMD");

    Laptop* laptop = new Laptop("HP Elite", processor, "ExampleMouse",
        mouse, "ExamplePrinter", printer, "ExampleVideoCard",
        videoCard);

    std::cout << "Laptop brand: " << laptop->GetBrand() << std::endl;
    std::cout << "Processor model: " << laptop->GetProcessorModel() << std::endl;
    std::cout << "Mouse brand: " << laptop->GetMouseBrand() << std::endl;
    std::cout << "Printer brand: " << laptop->GetPrinterBrand() << std::endl;
    std::cout << "Video card model: " << laptop->GetVideoCardModel() << std::endl;
    delete laptop;  // Удаление компьютера, но мышка и принтер остаются
    std::cout << "Mouse brand: " << mouse->GetBrand() << std::endl;
    std::cout << "Printer brand: " << printer->GetBrand() << std::endl;
   
    

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
