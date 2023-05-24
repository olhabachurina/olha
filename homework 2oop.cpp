// homework 2oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
class String {
private:
    static int count; // ����������� ���������� ��� �������� ���������� ��������� �������� �����
    char* data; // ��������� �� ���������� ������
    int size; // ������ ������

public:
    
    String() : String(80) {}// ����������� �� ���������

   
    explicit String(int length) : data(new char[length]), size(length) { // �����������, ����������� ��������� ������ ������������� �������
        ++count; // ����������� ������� �������� �����
    }

    
    // �����������, ��������� ������ � ���������������� �� �������, ���������� �� ������������
    String(const char* inputString) : data(new char[strlen(inputString) + 1]), size(strlen(inputString) + 1) {
        strcpy_s(data, size, inputString);
        ++count; // ����������� ������� �������� �����
    }

    
    ~String() {// ����������
        delete[] data; // ����������� ������, ���������� ��� ����������� �������
        --count; // ��������� ������� �������� �����
    }

    // ����� ��� ����� ������ �� ����������
    void inputString() {
        std::cin.getline(data, size);
    }

    void printString() const { // ����� ��� ������ ������ �� �����
        std::cout << data << std::endl;
    }

    
    static int getCount() {// ����������� �������-����, ������������ ���������� ��������� �������� �����
        return count;
    }
};

int String::count = 0; // ������������� ����������� ���������� ������

int main() {
    String str1; // ����� ������������ �� ���������
    std::cout << "Count: " << String::getCount() << std::endl; // ������� ���������� ��������� �������� �����

    String str2(50); // ����� ������������ � ��������� ��������
    std::cout << "Count: " << String::getCount() << std::endl;

    String str3("Have a good mood!"); // ����� ������������ � �������������� �� ������������
    std::cout << "Count: " << String::getCount() << std::endl;

    str1.inputString(); // ���� ������ ��� ������� str1
    str1.printString(); // ����� ������ ������� str1

    str2.inputString(); // ���� ������ ��� ������� str2
    str2.printString(); // ����� ������ ������� str2

    str3.printString(); // ����� ������ ������� str3

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
