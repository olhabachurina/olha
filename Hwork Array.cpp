// Hwork Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>

template <typename T>
class Array {
private:
    T* data;           // Указатель на данные
    int size;          // Размер массива (количество элементов)
    int capacity;      // Размер выделенной памяти
    int grow;          // Значение для увеличения размера массива

public:
    
    Array() : data(nullptr), size(0), capacity(0), grow(1) {}

    
    ~Array() {
        delete[] data;
    }

    
    int GetSize() const {// Получение размера массива
        return size;
    }

   
    void SetSize(int newSize, int newGrow = 1) { // Выбор размера массива
        assert(newSize >= 0);

        if (newSize > capacity) {
            
            int newCapacity = newSize + newGrow; // Выделение новой памяти с учетом значения newGrow
            T* newData = new T[newCapacity];

           
            for (int i = 0; i < size; i++) { // Копирование существующих элементов
                newData[i] = data[i];
            }

            
            delete[] data;

            
            data = newData;// Обновление указателей и переменных
            capacity = newCapacity;
        }

        size = newSize;
        grow = newGrow;
    }

    // Получение последнего допустимого индекса в массиве
    int GetUpperBound() const {
        return size - 1;
    }

    // Проверка, является ли массив пустым
    bool IsEmpty() const {
        return size == 0;
    }

    // Удаление "лишней" памяти
    void FreeExtra() {
        if (size < capacity) {
            // Выделение новой памяти с учетом значения grow
            T* newData = new T[size];

            // Копирование существующих элементов
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }

            // Освобождение старой памяти
            delete[] data;

            // Обновление указателей и переменных
            data = newData;
            capacity = size;
        }
    }

    // Удаление всех элементов
    void RemoveAll() {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    // Получение определенного элемента по индексу
    T GetAt(int index) const {
        assert(index >= 0 && index < size);

        return data[index];
    }

    // Установка нового значения для конкретного элемента
    void SetAt(int index, const T& value) {
        assert(index >= 0 && index < size);

        data[index] = value;
    }

    // Оператор доступа к элементу массива
    T& operator[](int index) {
        assert(index >= 0 && index < size);

        return data[index];
    }

    // Добавление элемента в массив
    void Add(const T& element) {
        if (size == capacity) {
            // Выделение новой памяти с учетом значения grow
            int newCapacity = capacity + grow;
            T* newData = new T[newCapacity];

            // Копирование существующих элементов
            for (int i = 0; i < size; i++) {
                newData[i] = data[i - 1];
            }

            // Освобождение старой памяти
            delete[] data;

            // Обновление указателей и переменных
            data = newData;
            capacity = newCapacity;
        }

        data[size] = element;
        size++;
    }

    
    void Append(const Array& otherArray) {// "Сборка" двух массивов
        int newSize = size + otherArray.size;
        int newCapacity = capacity + otherArray.capacity;
        T* newData = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        for (int i = 0; i < otherArray.size; i++) {
            newData[size + i] = otherArray.GetData()[i];
        }
        delete[] data;
        data = newData;
        size = newSize;
        capacity = newCapacity;
    }
    
    Array& operator=(const Array& otherArray) {// Оператор присваивания
        if (this != &otherArray) {
            // Освобождение старой памяти
            delete[] data;

            // Выделение новой памяти
            data = new T[otherArray.capacity];

            // Копирование элементов
            for (int i = 0; i < otherArray.size; i++) {
                data[i] = otherArray.GetData()[i];
            }

            // Обновление размера и емкости
            size = otherArray.size;
            capacity = otherArray.capacity;
            grow = otherArray.grow;
        }

        return *this;
    }

    // Получение адреса массива с данными
    T* GetData() const {
        return data;
    }

    // Вставка элемента в заданную позицию
    void InsertAt(int index, const T& element) {
        assert(index >= 0 && index <= size);

        if (size == capacity) {
            // Выделение новой памяти с учетом значения grow
            int newCapacity = capacity + grow;
            T* newData = new T[newCapacity];

            // Копирование элементов до вставляемого индекса
            for (int i = 0; i < index; i++) {
                newData[i] = data[i];
            }

            // Вставка нового элемента
            newData[index] = element;

            
            for (int i = index; i < size; i++) {// Копирование элементов после вставляемого индекса
                newData[i + 1] = data[i];
            }

            
            delete[] data;// Освобождение старой памяти

           
            data = newData; // Обновление указателей и переменных
            size++;
            capacity = newCapacity;
        }
        else {
           
            for (int i = size - 1; i >= index; i--) { // Сдвиг элементов после вставляемого индекса
                data[i + 1] = data[i];
            }

           
            data[index] = element; // Вставка нового элемента
            size++;
        }
    }

    
    void RemoveAt(int index) {// Удаление элемента из заданной позиции
        assert(index >= 0 && index < size);

        
        for (int i = index; i < size - 1; i++) {// Сдвиг элементов после удаляемого индекса
            data[i] = data[i + 1];
        }

        size--;
    }

    Array(T* data, int size, int capacity, int grow)
        : data(data), size(size), capacity(capacity), grow(grow)
    {
    }
};

int main() {
    
    Array<int> intArray;// Создание объекта класса Array для хранения int

    
    intArray.SetSize(5, 5);// Выбор размера массива

    
    for (int i = 0; i < 10; i++) {// Добавление элементов в массив
        intArray.Add(i);
    }

   
    std::cout << "Size of intArray: " << intArray.GetSize() << std::endl; // Получение размера массива
    std::cout << "------------------------------" << std::endl;
    
    std::cout << "Upper bound of intArray: " << intArray.GetUpperBound() << std::endl;// Получение последнего допустимого индекса

    
    std::cout << "Is intArray empty? " << (intArray.IsEmpty() ? "Yes" : "No") << std::endl;// Проверка, является ли массив пустым

    
    intArray.FreeExtra();
    std::cout << "------------------------------" << std::endl;// Удаление "лишней" памяти
    
    std::cout << "Element at index 3: " << intArray.GetAt(3) << std::endl;// Получение элемента по индексу
    std::cout << "------------------------------" << std::endl;
   
    intArray.SetAt(2, 100); // Установка нового значения для элемента
    
    
    intArray[4] = 50;// Использование оператора доступа к элементу массива
    
    
    std::cout << "Elements of intArray: ";// Вывод всех элементов массива
    for (int i = 0; i < intArray.GetSize(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
   
    Array<int> secondIntArray; // Создание второго объекта класса Array для хранения int
   
    
    secondIntArray.SetSize(3);

   
    for (int i = 0; i < 3; i++) { // Добавление элементов во второй массив
        secondIntArray.Add(i + 10);
    }
    
    
    intArray.Append(secondIntArray);// "Сборка" двух массивов
    std::cout << "------------------------------" << std::endl;
    
    std::cout << "Elements of intArray after appending secondIntArray: ";// Вывод всех элементов массива после "сборки"
    for (int i = 0; i < intArray.GetSize(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------" << std::endl;
   
    Array<int> assignedArray; // Оператор присваивания
    assignedArray = intArray;
   
    
    std::cout << "Elements of assignedArray: ";// Вывод всех элементов присвоенного массива
    for (int i = 0; i < assignedArray.GetSize(); i++) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;
    

    
    int* data = assignedArray.GetData();// Получение адреса массива с данными
    
    
    assignedArray.InsertAt(2, 999);// Вставка элемента в заданную позицию
    std::cout << "------------------------------" << std::endl;
    
    std::cout << "Elements of assignedArray after insertion: ";// Вывод всех элементов после вставки
    for (int i = 0; i < assignedArray.GetSize(); i++) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------" << std::endl;
    
    assignedArray.RemoveAt(4);// Удаление элемента из заданной позиции
    
    std::cout << "Elements of assignedArray after removal: ";// Вывод всех элементов после удаления
    for (int i = 0; i < assignedArray.GetSize(); i++) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------" << std::endl;
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
