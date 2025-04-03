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
        cout << "Se le descontaron $20\n" << endl;
        showCounter = 0;
    }

    cout << "Titular: " << owner << "\n"
         << "Tipo de cuenta: Caja de Ahorro\n"
         << "Balance: " << balance << endl;
}

double SavingsAccount::getBalance() {
    return balance;
}