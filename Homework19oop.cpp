// Homework19oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Manager.h"
#include"Worker.h"
#include"President.h"
#include "Circle.h"
#include"Rectangle.h"
#include"Right_triangle.h"
#include"Trapezoid.h"
#include "Shape.h"
using namespace std;



int main()
{
    std::cout << "Exercise 2" << std::endl;
    President president;
    Manager manager;
    Worker worker;

    president.Print();
    manager.Print();
    worker.Print();
    std::cout << "Exercise 2" <<std:: endl;
    std::cout << "********************" << std::endl;
    Rectangle rectangle(4.0, 5.0);
    Circle circle(3.0);
    RightTriangle rightTriangle(3.0, 4.0);
    Trapezoid trapezoid(2.0, 4.0, 3.0);

    Shape* shapes[] = { &rectangle, &circle, &rightTriangle, &trapezoid };
    int numShapes = sizeof(shapes) / sizeof(shapes[0]);

    for (int i = 0; i < numShapes; i++) {
        std::cout << "Shape: " << shapes[i]->getShapeName() << ", Area: " << shapes[i]->getArea() << std::endl;
    }

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
