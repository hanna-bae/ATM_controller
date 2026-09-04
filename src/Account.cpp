#include "Account.h"

#include <stdexcept> 

Account::Account(
    const std::string& accountId, 
    AccountType accountType, 
    long long initialBalance
)
    :accountId(accountId),
    accountType(accountType),
    balance(initialBalance)
{
    if (initialBalance < 0){
        throw std::invalid_argument(
            "Initial Balance cannot be negative"
        );
    }
}

const std::string&Account::getAccountId() const {
    return accountId; 
}

AccountType Account::getAccountType() const {
    return accountType;
}

long long Account::getBalance() const {
    return balance; 
}

void Account::deposit(long long amount){
    if (amount <=0){
        throw std::invalid_argument(
            "Deposit amount must be positive"
        );
    }

    balance += amount; 
}

void Account::withdraw(long long amount){
    if (amount <= 0){
        throw std::invalid_argument(
            "Withdrawal amount must be positive"
        );
    }

    if (balance < amount){
        throw std::runtime_error(
            "Insufficient balance"
        );
    }
    balance -= amount; 
}
