#include "checkingAccount.h"

bool CheckingAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
    }
    else if (balance + savings->getBalance() >= amount) {
        amount -= balance;
        savings->withdraw(amount); 
        cout << "Fondos insuficientes en la Cuenta Corriente, retirando de la Caja de Ahorros" << endl;
    } else {
        cout << "Fondos insuficientes en ambas cuentas para retirar esa cantidad: " << endl;
        info();
        savings->info();
    }
};