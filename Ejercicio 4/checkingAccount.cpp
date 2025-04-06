#include "checkingAccount.h"
#include "savingsAccount.h"

CheckingAccount::CheckingAccount(string name, double initialBalance, shared_ptr<SavingsAccount> newSavingAcc): BankAccount(name, initialBalance) {
    savings = newSavingAcc;
}

bool CheckingAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    else if (balance + savings->getBalance() >= amount) {
        amount -= balance;
        balance = 0;
        savings->withdraw(amount);
        cout << "Fondos insuficientes en la Cuenta Corriente, retirando de la Caja de Ahorros" << endl;
        return true;
    } else {
        cout << "Fondos insuficientes en ambas cuentas para retirar esa cantidad: " << endl;
        info();
        savings->info();
        return false;
    }
};

void CheckingAccount::info() {
    cout << "===============================\n" 
         << "CUENTA CORRIENTE\n" 
         << "Titular: " << owner << "\n"
         << "Balance: " << balance << "\n"
         << "===============================\n"<< endl;
}