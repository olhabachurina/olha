// bank oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
const int MAX_CLIENTS = 10;

class Client {
private:
    int identifier;//идентификационный номер клиента
    double balance;//баланс клиента

public:
    Client(int id, double initialBalance) : identifier(id), balance(initialBalance) {}//конструктор с аргументами,который принимающий идентификац код и начальный баланс
    Client() : identifier(0), balance(0.0) {}//конструктор без аргументов

    void deposit(double amount) {    // Метод для пополнения баланса клиента на указанную сумму
        balance += amount;
        std::cout << "Deposit: $" << amount << " to Client ID: " << identifier << std::endl;
    }

    void withdraw(double amount) {// Метод для снятия указанной суммы с баланса клиента
        if (amount <= balance) {
            balance -= amount;
            std::cout << "withdraw: $" << amount << " to Client ID: " << identifier << std::endl;
        }
        else {
            std::cout << "Insufficient balance." << std::endl;
        }
    }

    int getIdentifier() const {// Метод для получения идентиф.кода клиента
        return identifier;
    }

    double getBalance() const {
        return balance;
    }
};

class Bank {
private:
    Client clients[MAX_CLIENTS]; //Массив объектов класса Client для хранения клиентов банка
    int numClients;// Количество клиентов в банке

public:
    Bank() : numClients(0) {}// Конструктор класса Bank, инициализирует количество клиентов нулем

    void addClient(const Client& client) {// Метод для добавления клиента в банк
        if (numClients < MAX_CLIENTS) {
            clients[numClients++] = client;
        }
        else {
            std::cout << "Maximum number of clients reached." << std::endl;
        }
    }
    void removeClient(const Client& client) { // Метод для удаления клиента из банка
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
    void transferMoney(const Client& sender, const Client& receiver, double amount) { // Метод для перевода денег от одного клиента к другому
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
    Bank bank;// Создание объекта класса Bank
    Client client1(1, 1000);// Создание объекта класса Client с идентиф,кодом 1 и начальным балансом 1000
    Client client2(2, 500);// Создание объекта класса Client с идентиф,кодом 2 и начальным балансом 500
    bank.addClient(client1);// Добавление клиента client1 в банк
    bank.addClient(client2);// Добавление клиента client2 в банк
    std::cout << "Client 1 balance: " << client1.getBalance() << std::endl; // Вывод баланса клиента client1
    std::cout << "Client 2 balance: " << client2.getBalance() << std::endl;// Вывод баланса клиента client2
    std::cout << "_____________________________" << std::endl;
    Client client(1, 1000); // Создание объекта класса Client с идентификатором 1 и начальным балансом 1000
    client.deposit(500);// Пополнение баланса клиента на указанную сумму
    std::cout << "New balance: " << client.getBalance() << std::endl;// Вывод нового баланса клиента
    client.withdraw(200);
    std::cout << "New balance: " << client.getBalance() << std::endl; // Вывод нового баланса клиента
    std::cout << "_____________________________" << std::endl;
    bank.transferMoney(client1, client2, 200);// Перевод 200 единиц денег от клиента client1 к клиенту client2
    std::cout << "New balance: " << client.getBalance() << std::endl;// Вывод нового баланса клиента
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
