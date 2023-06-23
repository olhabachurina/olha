// Homework 14 oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
template <typename T>
class SinglyLinkedList
{
private:
    struct Node {//Определение структуры узла списка, содержащей:
        T data;//данные типа T
        Node* next;//указатель на следующий узел.
    };

    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}//указатель на голову списка, инициализированный значением nullptr

    ~SinglyLinkedList() {
        DeleteAll();
    }

    void AddToHead(const T& value) {//Метод добавления элемента value в голову списка.
        Node* newNode = new Node;
        newNode->data = value;//Создаем новый узел newNode с данными value.
        newNode->next = head;//Устанавливается ссылка newNode->next на текущую голову списка.
        head = newNode;//Голова списка head обновляется, указывая на новый узел newNode.
    }

    void AddToTail(const T& value) {//Метод добавления элемента value в хвост списка.
        Node* newNode = new Node;
        newNode->data = value;//Создается новый узел newNode с данными value 
        newNode->next = nullptr;//указателем на следующий узел равным nullptr.

        if (head == nullptr) {//Если список пустой
            head = newNode;//голова списка
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void DeleteFromHead() {//Метод удаления элемента из головы списка.
        if (head == nullptr) {//список пустой
            std::cout << "List is empty. Cannot delete from head." << std::endl;// ошибка,список пустой
            return;
        }

        Node* nodeToDelete = head;//временный указатель,который указывает на голову списка
        head = head->next;
        delete nodeToDelete;
    }

    void DeleteFromTail() {//метод обработки попыток удаления из пустого списка.
        if (head == nullptr) {
            std::cout << "List is empty. Cannot delete from tail." << std::endl;//Список пуст. Невозможно удалить из хвоста
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    void DeleteAll() {// метод  для удаления всех элементов списка.
        while (head != nullptr) {
            Node* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
        }
    }

    void Show() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    void InsertAtPosition(const T& value, int position) {//метод для вставки элемента в списке
        if (position < 0) {
            std::cout << "Invalid position. Cannot insert element." << std::endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;

        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        int currentPosition = 0;
        while (current != nullptr && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        if (current == nullptr) {
            std::cout << "Invalid position. Cannot insert element." << std::endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void DeleteAtPosition(int position) {//Метод  для удаления элемента на позиции  в списке.
        if (position < 0) {
            std::cout << "Invalid position. Cannot delete element." << std::endl;//Неверная позиция. Невозможно удалить элемент.
            return;
        }

        if (position == 0) {
            DeleteFromHead();
            return;
        }

        Node* current = head;
        int currentPosition = 0;
        while (current != nullptr && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        if (current == nullptr || current->next == nullptr) {
            std::cout << "Invalid position. Cannot delete element." << std::endl;
            return;
        }

        Node* nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    Node* Find(const T& value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    int Replace(const T& oldValue, const T& newValue) {//Метод  для замены элементов со значением 2 на 6 в списке
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldValue) {
                current->data = newValue;
                count++;
            }
            current = current->next;
        }
        return count;
    }

    void Reverse() {//Метод  для разворота списка.
        Node* previous = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        head = previous;
    }
    int FindElement(T value) //Метод FindElement используется для поиска элемента со значением 
    {
        Node* current = head;
        int position = 0;

        while (current != nullptr) {
            if (current->data == value) {
                return position;  // Нашли элемент, возвращаем его позицию
            }
            current = current->next;
            position++;
        }

        return -1;  // Элемент не найден
    }

};

int main() {
    SinglyLinkedList<int> list;


    list.AddToHead(3);
    list.AddToHead(2);
    list.AddToTail(4);
    list.Show();
    list.InsertAtPosition(5, 1);
    list.Show();
    list.DeleteAtPosition(2);
    list.Show();
    int position = list.FindElement(5);
    if (position != -1) {
        std::cout << "Element found at position: " << position << std::endl;
    }
    else {
        std::cout << "Element not found." << std::endl;
    }
    int replacements = list.Replace(2, 6);
    std::cout << "Replaced " << replacements << " element(s)." << std::endl;
    list.Show();
    list.Reverse();
    list.Show();
    list.DeleteAll();
    list.Show();
    list.DeleteFromHead();
    list.DeleteFromTail();
    list.Show();

    list.DeleteAll();
    list.Show();

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
