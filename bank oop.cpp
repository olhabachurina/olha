// bank oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
const int MAX_CLIENTS = 10;

class Client {
private:
    int identifier;//����������������� ����� �������
    double balance;//������ �������

public:
    Client(int id, double initialBalance) : identifier(id), balance(initialBalance) {}//����������� � �����������,������� ����������� ����������� ��� � ��������� ������
    Client() : identifier(0), balance(0.0) {}//����������� ��� ����������

    void deposit(double amount) {    // ����� ��� ���������� ������� ������� �� ��������� �����
        balance += amount;
        std::cout << "Deposit: $" << amount << " to Client ID: " << identifier << std::endl;
    }

    void withdraw(double amount) {// ����� ��� ������ ��������� ����� � ������� �������
        if (amount <= balance) {
            balance -= amount;
            std::cout << "withdraw: $" << amount << " to Client ID: " << identifier << std::endl;
        }
        else {
            std::cout << "Insufficient balance." << std::endl;
        }
    }

    int getIdentifier() const {// ����� ��� ��������� �������.���� �������
        return identifier;
    }

    double getBalance() const {
        return balance;
    }
};

class Bank {
private:
    Client clients[MAX_CLIENTS]; //������ �������� ������ Client ��� �������� �������� �����
    int numClients;// ���������� �������� � �����

public:
    Bank() : numClients(0) {}// ����������� ������ Bank, �������������� ���������� �������� �����

    void addClient(const Client& client) {// ����� ��� ���������� ������� � ����
        if (numClients < MAX_CLIENTS) {
            clients[numClients++] = client;
        }
        else {
            std::cout << "Maximum number of clients reached." << std::endl;
        }
    }
    void removeClient(const Client& client) { // ����� ��� �������� ������� �� �����
        for (int i = 0; i < numClients; i++) {
            if (clients[i].getIdentifier() == client.getIdentifier()) {
                for (int j = i; j < numClients - 1; j++) {
                    clients[j] = clients[j + 1];
                }
                numClients--;
                break;
            }
        }
    }
    void transferMoney(const Client& sender, const Client& receiver, double amount) { // ����� ��� �������� ����� �� ������ ������� � �������
        for (int i = 0; i < numClients; i++) {
            if (clients[i].getIdentifier() == sender.getIdentifier()) {
                clients[i].withdraw(amount);
            std::cout << "Transfer: $" << amount << " from Client ID: " << sender.getIdentifier();
            
        }
            else if (clients[i].getIdentifier() == receiver.getIdentifier()) {
                clients[i].deposit(amount);
            }
        }
    }
    void printClients() const {
        std::cout << "List of clients:" << std::endl;
        for (int i = 0; i < numClients; i++) {
            const Client& client = clients[i];
            std::cout << "Client ID: " << client.getIdentifier() << ", Balance: " << client.getBalance() << std::endl;
        }
    }
};

int main() {
    Bank bank;// �������� ������� ������ Bank
    Client client1(1, 1000);// �������� ������� ������ Client � �������,����� 1 � ��������� �������� 1000
    Client client2(2, 500);// �������� ������� ������ Client � �������,����� 2 � ��������� �������� 500
    bank.addClient(client1);// ���������� ������� client1 � ����
    bank.addClient(client2);// ���������� ������� client2 � ����
    std::cout << "Client 1 balance: " << client1.getBalance() << std::endl; // ����� ������� ������� client1
    std::cout << "Client 2 balance: " << client2.getBalance() << std::endl;// ����� ������� ������� client2
    std::cout << "_____________________________" << std::endl;
    Client client(1, 1000); // �������� ������� ������ Client � ��������������� 1 � ��������� �������� 1000
    client.deposit(500);// ���������� ������� ������� �� ��������� �����
    std::cout << "New balance: " << client.getBalance() << std::endl;// ����� ������ ������� �������
    client.withdraw(200);
    std::cout << "New balance: " << client.getBalance() << std::endl; // ����� ������ ������� �������
    std::cout << "_____________________________" << std::endl;
    bank.transferMoney(client1, client2, 200);// ������� 200 ������ ����� �� ������� client1 � ������� client2
    std::cout << "New balance: " << client.getBalance() << std::endl;// ����� ������ ������� �������
    std::cout << "_____________________________" << std::endl;
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
