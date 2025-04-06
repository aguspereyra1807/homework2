#include "checkingAccount.h"
#include "savingsAccount.h"
#include <limits>

void pause() {
    cout << "[Enter] para continuar" << endl;
    cin.get();
}

int main() {

    cout << "\n- Creando caja de ahorros...\n" << endl;
    auto savings = make_shared<SavingsAccount>("Mariano", 1000);
    savings->info();
    pause();

    cout << "- Creando cuenta corriente...\n" << endl;
    auto current = make_unique<CheckingAccount>("Mariano", 100, savings);
    current->info();
    pause();

    cout << "- Depositando $10 en ambas cuentas..\n" << endl;
    current->deposit(10.0);
    current->info();
    savings->deposit(10.0);
    savings->info();
    pause();

    cout << "- Retirando $100 en ambas cuentas.. \n" << endl;
    current->withdraw(100.0);
    current->info();
    savings->withdraw(100.0);
    savings->info();
    pause();

    cout << "- Retirando $100 de la cuenta corriente (fondos insuficientes)\n" << endl;
    current->withdraw(100.0);
    current->info();
    savings->info();
    pause();

    cout << "- Retirando $850 de la cuenta corriente (fondos insuficientes en ambas cuentas)\n" << endl;
    current->withdraw(850.0);
}