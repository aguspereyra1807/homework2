#pragma once
#include <string>

using namespace std;

class BankAccount { // Clase Abstracta
    public:
        BankAccount(string name, double initialBalance): owner(name), balance(initialBalance) {}
        virtual void deposit(double amount) { balance += amount; }
        virtual bool withdraw(double amount) = 0; // Puramente vitual, no necesita implementación
        virtual void info() = 0;
        virtual ~BankAccount() = default;

    protected:
        double balance = 0.0;
        string owner;
};