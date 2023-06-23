// Hwork Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>

template <typename T>
class Array {
private:
    T* data;           // ��������� �� ������
    int size;          // ������ ������� (���������� ���������)
    int capacity;      // ������ ���������� ������
    int grow;          // �������� ��� ���������� ������� �������

public:
    
    Array() : data(nullptr), size(0), capacity(0), grow(1) {}

    
    ~Array() {
        delete[] data;
    }

    
    int GetSize() const {// ��������� ������� �������
        return size;
    }

   
    void SetSize(int newSize, int newGrow = 1) { // ����� ������� �������
        assert(newSize >= 0);

        if (newSize > capacity) {
            
            int newCapacity = newSize + newGrow; // ��������� ����� ������ � ������ �������� newGrow
            T* newData = new T[newCapacity];

           
            for (int i = 0; i < size; i++) { // ����������� ������������ ���������
                newData[i] = data[i];
            }

            
            delete[] data;

            
            data = newData;// ���������� ���������� � ����������
            capacity = newCapacity;
        }

        size = newSize;
        grow = newGrow;
    }

    // ��������� ���������� ����������� ������� � �������
    int GetUpperBound() const {
        return size - 1;
    }

    // ��������, �������� �� ������ ������
    bool IsEmpty() const {
        return size == 0;
    }

    // �������� "������" ������
    void FreeExtra() {
        if (size < capacity) {
            // ��������� ����� ������ � ������ �������� grow
            T* newData = new T[size];

            // ����������� ������������ ���������
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }

            // ������������ ������ ������
            delete[] data;

            // ���������� ���������� � ����������
            data = newData;
            capacity = size;
        }
    }

    // �������� ���� ���������
    void RemoveAll() {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    // ��������� ������������� �������� �� �������
    T GetAt(int index) const {
        assert(index >= 0 && index < size);

        return data[index];
    }

    // ��������� ������ �������� ��� ����������� ��������
    void SetAt(int index, const T& value) {
        assert(index >= 0 && index < size);

        data[index] = value;
    }

    // �������� ������� � �������� �������
    T& operator[](int index) {
        assert(index >= 0 && index < size);

        return data[index];
    }

    // ���������� �������� � ������
    void Add(const T& element) {
        if (size == capacity) {
            // ��������� ����� ������ � ������ �������� grow
            int newCapacity = capacity + grow;
            T* newData = new T[newCapacity];

            // ����������� ������������ ���������
            for (int i = 0; i < size; i++) {
                newData[i] = data[i - 1];
            }

            // ������������ ������ ������
            delete[] data;

            // ���������� ���������� � ����������
            data = newData;
            capacity = newCapacity;
        }

        data[size] = element;
        size++;
    }

    
    void Append(const Array& otherArray) {// "������" ���� ��������
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
    
    Array& operator=(const Array& otherArray) {// �������� ������������
        if (this != &otherArray) {
            // ������������ ������ ������
            delete[] data;

            // ��������� ����� ������
            data = new T[otherArray.capacity];

            // ����������� ���������
            for (int i = 0; i < otherArray.size; i++) {
                data[i] = otherArray.GetData()[i];
            }

            // ���������� ������� � �������
            size = otherArray.size;
            capacity = otherArray.capacity;
            grow = otherArray.grow;
        }

        return *this;
    }

    // ��������� ������ ������� � �������
    T* GetData() const {
        return data;
    }

    // ������� �������� � �������� �������
    void InsertAt(int index, const T& element) {
        assert(index >= 0 && index <= size);

        if (size == capacity) {
            // ��������� ����� ������ � ������ �������� grow
            int newCapacity = capacity + grow;
            T* newData = new T[newCapacity];

            // ����������� ��������� �� ������������ �������
            for (int i = 0; i < index; i++) {
                newData[i] = data[i];
            }

            // ������� ������ ��������
            newData[index] = element;

            
            for (int i = index; i < size; i++) {// ����������� ��������� ����� ������������ �������
                newData[i + 1] = data[i];
            }

            
            delete[] data;// ������������ ������ ������

           
            data = newData; // ���������� ���������� � ����������
            size++;
            capacity = newCapacity;
        }
        else {
           
            for (int i = size - 1; i >= index; i--) { // ����� ��������� ����� ������������ �������
                data[i + 1] = data[i];
            }

           
            data[index] = element; // ������� ������ ��������
            size++;
        }
    }

    
    void RemoveAt(int index) {// �������� �������� �� �������� �������
        assert(index >= 0 && index < size);

        
        for (int i = index; i < size - 1; i++) {// ����� ��������� ����� ���������� �������
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
    
    Array<int> intArray;// �������� ������� ������ Array ��� �������� int

    
    intArray.SetSize(5, 5);// ����� ������� �������

    
    for (int i = 0; i < 10; i++) {// ���������� ��������� � ������
        intArray.Add(i);
    }

   
    std::cout << "Size of intArray: " << intArray.GetSize() << std::endl; // ��������� ������� �������
    std::cout << "------------------------------" << std::endl;
    
    std::cout << "Upper bound of intArray: " << intArray.GetUpperBound() << std::endl;// ��������� ���������� ����������� �������

    
    std::cout << "Is intArray empty? " << (intArray.IsEmpty() ? "Yes" : "No") << std::endl;// ��������, �������� �� ������ ������

    
    intArray.FreeExtra();
    std::cout << "------------------------------" << std::endl;// �������� "������" ������
    
    std::cout << "Element at index 3: " << intArray.GetAt(3) << std::endl;// ��������� �������� �� �������
    std::cout << "------------------------------" << std::endl;
   
    intArray.SetAt(2, 100); // ��������� ������ �������� ��� ��������
    
    
    intArray[4] = 50;// ������������� ��������� ������� � �������� �������
    
    
    std::cout << "Elements of intArray: ";// ����� ���� ��������� �������
    for (int i = 0; i < intArray.GetSize(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
   
    Array<int> secondIntArray; // �������� ������� ������� ������ Array ��� �������� int
   
    
    secondIntArray.SetSize(3);

   
    for (int i = 0; i < 3; i++) { // ���������� ��������� �� ������ ������
        secondIntArray.Add(i + 10);
    }
    
    
    intArray.Append(secondIntArray);// "������" ���� ��������
    std::cout << "------------------------------" << std::endl;
    
    std::cout << "Elements of intArray after appending secondIntArray: ";// ����� ���� ��������� ������� ����� "������"
    for (int i = 0; i < intArray.GetSize(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------" << std::endl;
   
    Array<int> assignedArray; // �������� ������������
    assignedArray = intArray;
   
    
    std::cout << "Elements of assignedArray: ";// ����� ���� ��������� ������������ �������
    for (int i = 0; i < assignedArray.GetSize(); i++) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;
    

    
    int* data = assignedArray.GetData();// ��������� ������ ������� � �������
    
    
    assignedArray.InsertAt(2, 999);// ������� �������� � �������� �������
    std::cout << "------------------------------" << std::endl;
    
    std::cout << "Elements of assignedArray after insertion: ";// ����� ���� ��������� ����� �������
    for (int i = 0; i < assignedArray.GetSize(); i++) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------" << std::endl;
    
    assignedArray.RemoveAt(4);// �������� �������� �� �������� �������
    
    std::cout << "Elements of assignedArray after removal: ";// ����� ���� ��������� ����� ��������
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
