#include "savingsAccount.h"

bool SavingsAccount::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        return true;
    } else {
        cout << "Fondos insuficientes" << endl;
        return false;
    }
}

void SavingsAccount::info() {
    if (++showCounter > 2) {
        cout << "Se le descontaron $20 en su caja de ahorros\n" << endl;
        balance -= 20;
        showCounter = 0;
    }

    cout << "===============================\n" 
         << "CAJA DE AHORROS\n" 
         << "Titular: " << owner << "\n"
         << "Balance: " << balance << "\n"
         << "===============================\n"<< endl;
}

double SavingsAccount::getBalance() {
    return balance;
}