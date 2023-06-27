// homework 16 oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Student.h"
#include "Aspirant.h"
#include "ForeignPassport.h"
using namespace std;

int main() {
   std:: cout << "Exercise 1" <<std:: endl;
    Student student("Petrenko", 21);
    Aspirant aspirant("Gurtenko", 25, "Interaction between classes");

    student.displayInfo();
    aspirant.displayInfo();
    std::cout << "/**/**/**/**/**/**/**/**" << std::endl;
    std::cout << "Exercise 2" << std::endl;
    ForeignPassport foreignPassport("Petr", "Naumov", "007777777", "Ukrainian", "FN888888", "CANADA Visa");
    foreignPassport.displayForeignPassportInfo();
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
