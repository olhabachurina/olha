// Homework8oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

class String {
private:
    static int count;
    char* data;
    int size;

public:
    String() : String(80) {}

    explicit String(int length) : data(new char[length]), size(length) {
        ++count;
    }

    String(const char* inputString) : data(nullptr), size(0) {
        if (inputString != nullptr) {
            size = strlen(inputString) + 1;
            data = new char[size];
            strcpy_s(data, size, inputString);
        }
        ++count;
    }

    String(const String& other) : data(new char[other.size]), size(other.size) {
        strcpy_s(data, size, other.data);
        ++count;
    }

    ~String() {
        delete[] data;
        --count;
    }

    void inputString() {
        std::cin.getline(data, size);
    }

    void printString() const {
        std::cout << data << std::endl;
    }

    int getSize() const {
        return size;
    }

    char& operator[](int index) {
        return data[index];
    }

    int operator()(char c) const {
        for (int i = 0; i < size; ++i) {
            if (data[i] == c) {
                return i;
            }
        }
        return -1;
    }

    operator int() const {
        return size - 1;
    }

    static int getCount() {
        return count;
    }
};

int String::count = 0;

int main() {
    String str("Hello, World!");

    std::cout << "String length: " << int(str) << std::endl;

    std::cout << "Character at index 7: " << str[7] << std::endl;

    int index = str('W');
    if (index != -1) {
        std::cout << "Character 'W' found at index: " << index << std::endl;
    }
    else {
        std::cout << "Character 'W' not found in the string." << std::endl;
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
