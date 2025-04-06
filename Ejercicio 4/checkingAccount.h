#pragma once

#include <iostream>
#include <memory>
#include "bankAccount.h"
#include "savingsAccount.h"

using namespace std;

class SavingsAccount;
class CheckingAccount: public BankAccount {
    public:
        CheckingAccount(string name, double initialBalance, shared_ptr<SavingsAccount> newSavingAcc);
        bool withdraw(double amount) override;
        void info() override;
    
    private:
        shared_ptr<SavingsAccount> savings;
};