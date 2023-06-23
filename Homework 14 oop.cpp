// Homework 14 oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
template <typename T>
class SinglyLinkedList
{
private:
    struct Node {//����������� ��������� ���� ������, ����������:
        T data;//������ ���� T
        Node* next;//��������� �� ��������� ����.
    };

    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}//��������� �� ������ ������, ������������������ ��������� nullptr

    ~SinglyLinkedList() {
        DeleteAll();
    }

    void AddToHead(const T& value) {//����� ���������� �������� value � ������ ������.
        Node* newNode = new Node;
        newNode->data = value;//������� ����� ���� newNode � ������� value.
        newNode->next = head;//��������������� ������ newNode->next �� ������� ������ ������.
        head = newNode;//������ ������ head �����������, �������� �� ����� ���� newNode.
    }

    void AddToTail(const T& value) {//����� ���������� �������� value � ����� ������.
        Node* newNode = new Node;
        newNode->data = value;//��������� ����� ���� newNode � ������� value 
        newNode->next = nullptr;//���������� �� ��������� ���� ������ nullptr.

        if (head == nullptr) {//���� ������ ������
            head = newNode;//������ ������
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void DeleteFromHead() {//����� �������� �������� �� ������ ������.
        if (head == nullptr) {//������ ������
            std::cout << "List is empty. Cannot delete from head." << std::endl;// ������,������ ������
            return;
        }

        Node* nodeToDelete = head;//��������� ���������,������� ��������� �� ������ ������
        head = head->next;
        delete nodeToDelete;
    }

    void DeleteFromTail() {//����� ��������� ������� �������� �� ������� ������.
        if (head == nullptr) {
            std::cout << "List is empty. Cannot delete from tail." << std::endl;//������ ����. ���������� ������� �� ������
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

    void DeleteAll() {// �����  ��� �������� ���� ��������� ������.
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
    void InsertAtPosition(const T& value, int position) {//����� ��� ������� �������� � ������
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

    void DeleteAtPosition(int position) {//�����  ��� �������� �������� �� �������  � ������.
        if (position < 0) {
            std::cout << "Invalid position. Cannot delete element." << std::endl;//�������� �������. ���������� ������� �������.
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

    int Replace(const T& oldValue, const T& newValue) {//�����  ��� ������ ��������� �� ��������� 2 �� 6 � ������
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

    void Reverse() {//�����  ��� ��������� ������.
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
    int FindElement(T value) //����� FindElement ������������ ��� ������ �������� �� ��������� 
    {
        Node* current = head;
        int position = 0;

        while (current != nullptr) {
            if (current->data == value) {
                return position;  // ����� �������, ���������� ��� �������
            }
            current = current->next;
            position++;
        }

        return -1;  // ������� �� ������
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
