#pragma once

#include <iostream>
#include <memory>
#include "bankAccount.h"
#include "savingsAccount.h"

using namespace std;

class CheckingAccount: public BankAccount {
    public:
        CheckingAccount(string name, double initialBalance, SavingsAccount newSavingAcc): BankAccount(name, initialBalance), savings(make_unique<SavingsAccount>(newSavingAcc)) {}
        bool withdraw(double amount) override;
        void info() override;
    
    private:
        unique_ptr<SavingsAccount> savings;
};