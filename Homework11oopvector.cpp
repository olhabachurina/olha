// Homework11oopvector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    T* elements;// Указатель на динамический массив элементов вектора
    size_t size;//Размер вектора

public:
    Vector() : elements(nullptr), size(0) {}// Конструктор по умолчанию, инициализирует указатель на nullptr и размер вектора равным 0

    Vector(size_t size) : elements(new T[size]), size(size) {}// Конструктор, принимающий размер вектора.
                                                              //Создает динамический массив элементов указанного размера и инициализирует размер вектора
    ~Vector() {// Деструктор
        delete[] elements;//oсвобождает память, выделенную для массива элементов вектора
    }

    size_t getSize() const {// Метод для получения размера вектора
        return size;
    }
    Vector<T>& operator=(const Vector<T>& other) {
        if (this != &other) {
            delete[] elements;
            size = other.size;
            elements = new T[size];
            for (size_t i = 0; i < size; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    void resize(size_t newSize) {
        T* newElements = new T[newSize];  // Создание нового динамического массива указанного размера

        
        size_t elementsToCopy = std::min(size, newSize);// Копирование элементов из текущего массива в новый массив
       /* for (size_t i = 0; i < elementsToCopy; ++i) {
            newElements[i] = elements[i];
        }*/

        std::copy(elements, elements + elementsToCopy, newElements);
        delete[] elements;  // Освобождение памяти, выделенной для старого массива
        elements = newElements;  // Установка указателя на новый массив
        size = newSize;  // Обновление размера вектора
    }


    T& operator[](size_t index) {// Перегрузка оператора [] для доступа к элементам вектора по индексу
        return elements[index];
        return elements[index];
    }

    const T& operator[](size_t index) const {// Перегрузка оператора [] для доступа к элементам вектора по индексу (константная версия)
        return elements[index];
    }

    Vector<T> operator+(const Vector<T>& other) const {// Перегрузка оператора + для сложения двух векторов
        if (size != other.size) 
        if (size != other.size) {
            throw std::invalid_argument("Vector sizes don't match.");
        }

        Vector<T> result(size);// Создание нового вектора для хранения результата
        for (size_t i = 0; i < size; ++i) {
            result[i] = elements[i] + other[i];// Сложение соответствующих элементов двух векторов и запись результата в новый вектор
        
        }
        return result;
    }

    Vector<T> operator-(const Vector<T>& other) const {// Перегрузка оператора - для вычитания двух векторов
        if (size != other.size) 
        if (size != other.size) {
            throw std::invalid_argument("Vector sizes don't match.");
        }

        Vector<T> result(size);// Создание нового вектора для хранения результата
        for (size_t i = 0; i < size; ++i) {
            result[i] = elements[i] - other[i];// Вычитание соответствующих элементов двух векторов и запись результата в новый вектор
        
        }
        return result;
    }

    Vector<T> operator*(const T& scalar) const {// Перегрузка оператора * для умножения вектора на скалярное значение
        Vector<T> result(size);// Создание нового вектора для хранения результата
        for (size_t i = 0; i < size; ++i) {
            result[i] = elements[i] * scalar;// Умножение каждого элемента вектора на скалярное значение и запись результата в новый вектор
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
        for (size_t i = 0; i < vec.size; ++i) {
            os << vec[i] << " ";
        }
    

        return os;
    }
};

int main() {
    
    Vector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    Vector<int> v2(3);
    v2[0] = 4;
    v2[1] = 5;
    v2[2] = 6;
    std::cout << "Vector 1: " << v1 << std::endl;
    std::cout << "Vector 2: " << v2 << std::endl;
    Vector<int> sum = v1 + v2;
    Vector<int> diff = v1 - v2;
    Vector<int> scaled = v1 * 2;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;
    std::cout << "Scaled: " << scaled << std::endl;
    Vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    std::cout << "Vector before resizing: " << v << std::endl;
    v.resize(5);  // Изменение размера вектора на 5
    v[3] = 4;
    v[4] = 5;
    std::cout << "Vector after resizing: " << v << std::endl;
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
