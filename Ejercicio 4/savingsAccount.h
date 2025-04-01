#pragma once

#include <iostream>
#include "bankAccount.h"
#include "checkingAccount.h"


class SavingsAccount: public BankAccount {
    public:
        SavingsAccount(string name, double initialBalance): BankAccount(name, initialBalance) {}
        bool withdraw(double amount) override;
        void info() override;
        double getBalance();
    
    private:
        int showCounter;
        friend class CheckingAccont;
};