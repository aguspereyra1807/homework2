#include "checkingAccount.h"

bool CheckingAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
    }
    else if (balance + savings->getBalance() >= amount) {
        amount -= balance;
        savings->withdraw(amount); // NO SE SI DE ALGUNA MANERA SIENDO CLASE FRIEND PUEDO ACCEDER DIRECTAMENTE A savings->balance
        cout << "Fondos insuficientes en la Cuenta Corriente, retirando de la Caja de Ahorros" << endl;
    } else {
        cout << "Fondos insutificnetes en ambas cuentas para retirar esa cantidad: " << endl;
        info();
        savings->info();
    }
};