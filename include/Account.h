#pragma once 
#include <string> 

enum class AccountType {
    CHECKING, 
    SAVINGS
};

class Account{
private:
    std::string accountId; 
    AccountType accountType; 
    long long balance;

public:
    Account(
        const std::string&accountId, 
        AccountType accountType, 
        long long initialBalance
    );

    const std::string& getAccountId() const; 
    AccountType getAccountType() const; 
    long long getBalance() const; 

    void deposit(long long amount);
    void withdraw(long long amount);
};