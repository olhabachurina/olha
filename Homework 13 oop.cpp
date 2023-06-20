// Homework 13 oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>

bool isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')')      // Проверяем, являются ли открывающая и закрывающая скобки парой
        return true;
    else if (opening == '{' && closing == '}')
        return true;
    else if (opening == '[' && closing == ']')
        return true;
    return false;
}

int main() {
    std::string expression;
    std::cout << "Enter the string: ";            // Просим ввести строку
    std::getline(std::cin, expression);        // Считываем строку
    std::cout << "Input string: " << expression << std::endl;// Распечатаем строку в консоли
    std::stack<char> stack;                    // Создаем стек для хранения открывающих скобок
    bool isCorrect = true;                      // Флаг для определения корректности строки
    int errorPosition = -1;                     // Позиция первой ошибки

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            stack.push(expression[i]);          // Если символ - открывающая скобка, добавляем ее в стек
        }
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (stack.empty() || !isMatchingPair(stack.top(), expression[i])) {
                isCorrect = false; // Если стек пустой или скобки не соответствуют друг другу, считаем строку некорректной
                errorPosition = i;
                break;
            }
            else {
                stack.pop();                    // Если скобки соответствуют, удаляем открывающую скобку из стека
            }
        }
    }

    if (!stack.empty() && isCorrect) {
        
        isCorrect = false;// Если после обхода строки стек не пустой, строка также считается некорректной
        errorPosition = expression.length();
    }

    if (isCorrect) {
        std::cout << "The string is correct." << std::endl;
    }
    else {
        std::cout << "The string is invalid. The error occurs at the position " << errorPosition + 1 << "." << std::endl;
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
