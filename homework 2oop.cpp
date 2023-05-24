// homework 2oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
class String {
private:
    static int count; // статическая переменная для подсчета количества созданных объектов строк
    char* data; // указатель на символьный массив
    int size; // размер строки

public:
    
    String() : String(80) {}// Конструктор по умолчанию

   
    explicit String(int length) : data(new char[length]), size(length) { // Конструктор, позволяющий создавать строку произвольного размера
        ++count; // увеличиваем счетчик объектов строк
    }

    
    // Конструктор, создающий строку и инициализирующий ее строкой, полученной от пользователя
    String(const char* inputString) : data(new char[strlen(inputString) + 1]), size(strlen(inputString) + 1) {
        strcpy_s(data, size, inputString);
        ++count; // увеличиваем счетчик объектов строк
    }

    
    ~String() {// Деструктор
        delete[] data; // освобождаем память, выделенную для символьного массива
        --count; // уменьшаем счетчик объектов строк
    }

    // Метод для ввода строки из клавиатуры
    void inputString() {
        std::cin.getline(data, size);
    }

    void printString() const { // Метод для вывода строки на экран
        std::cout << data << std::endl;
    }

    
    static int getCount() {// Статическая функция-член, возвращающая количество созданных объектов строк
        return count;
    }
};

int String::count = 0; // инициализация статической переменной класса

int main() {
    String str1; // вызов конструктора по умолчанию
    std::cout << "Count: " << String::getCount() << std::endl; // выводим количество созданных объектов строк

    String str2(50); // вызов конструктора с указанным размером
    std::cout << "Count: " << String::getCount() << std::endl;

    String str3("Have a good mood!"); // вызов конструктора с инициализацией от пользователя
    std::cout << "Count: " << String::getCount() << std::endl;

    str1.inputString(); // ввод строки для объекта str1
    str1.printString(); // вывод строки объекта str1

    str2.inputString(); // ввод строки для объекта str2
    str2.printString(); // вывод строки объекта str2

    str3.printString(); // вывод строки объекта str3

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
