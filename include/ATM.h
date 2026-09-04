#pragma once 
#include <vector> 
#include "Account.h"
#include "Card.h"

enum class ATMState{
    IDLE, 
    CARD_INSERTED, 
    AUTHENTICATED, 
    ACCOUNT_SELECTED
};

class ATM{
private:
    const Card* currentCard; 
    std::vector<Account*> avaiableAccounts; 
    Account* selectedAccount; 
    ATMState state; 

public:
    ATM();

    void insertCard(const Card& card);
    
    void authenticate(
        bool authenticationSucceeded, 
        const std::vector<Account*>& accounts 
    );

    const std::vector<Account*>& getAvailableAccounts() const;

    void selectAccount(std::size_t index);

    long long checkBalance() const; 
    void deposit(long long amount);
    void withdraw(long long amount);

    void ejectCard(); 

    ATMState getState() const; 
};