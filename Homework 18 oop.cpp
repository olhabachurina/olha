// Homework 18 oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "LinearEquation.h"
#include "QuadraticEquation.h"
#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"

using namespace std;
int main() 
{
    std:: cout << "Exercise 1" << std::endl;
    LinearEquation linearEquation(2, 3);
    linearEquation.roots(); // ����� ������ roots() ��� ��������� ���������

    QuadraticEquation quadraticEquation(1, -5, 6);
    quadraticEquation.roots(); // ����� ������ roots() ��� ����������� ���������
    std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
    std::cout << "Exercise 2" << std::endl;
      
    Shape* shapes[4];// ������� ������ ���������� �� ������� Shape ��� �������� �����

    shapes[0] = new Square(1, 1, 5);// ������� ���������� ��������� ����� � ��������� �� � �������
    shapes[1] = new Rectangle(2, 2, 6, 3);
    shapes[2] = new Circle(3, 3, 4);
    shapes[3] = new Ellipse(4, 4, 7, 2);

    std::ofstream file("shapes.txt");// ��������� ���� ��� ������
    if (file.is_open()) {
        for (int i = 0; i < 4; i++) {// ���������� �� ������� � ��������� ������ � �����
            shapes[i]->Save(file);
        }
        file.close();
    }
    else {
        std::cout << "Unable to open file." << std::endl;
    }

    Shape* loadedShapes[4];// ������� ������ ���������� �� ������� Shape ��� �������� ����������� �����
    std::ifstream loadedFile("shapes.txt");// ��������� ���� ��� ������
    if (loadedFile.is_open()) {
        std::string shapeType;
        for (int i = 0; i < 4; i++) {// ������ ���������� � ������ ������ �� �����
            loadedFile >> shapeType;
            Shape* shape = nullptr;
            if (shapeType == "Square") {// ������� ��������������� ������ ������ � ����������� �� ����
                shape = new Square(0, 0, 0);
            }
            else if (shapeType == "Rectangle") {
                shape = new Rectangle(0, 0, 0, 0);
            }
            else if (shapeType == "Circle") {
                shape = new Circle(0, 0, 0);
            }
            else if (shapeType == "Ellipse") {
                shape = new Ellipse(0, 0, 0, 0);
            }

            if (shape) {
                shape->Load(loadedFile);
                loadedShapes[i] = shape;
            }
        }
        loadedFile.close();
    }
    else {
        std::cout << "Unable to open file." << std::endl;
    }

    for (int i = 0; i < 4; i++) {// ������� ���������� � ������ ����������� ������
        loadedShapes[i]->Show();
    }

    for (int i = 0; i < 4; i++) {// ����������� ������, ������ ��������� ������
        delete shapes[i];
        delete loadedShapes[i];
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
