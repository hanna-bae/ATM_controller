#include "ATM.h"

#include <stdexcept>

ATM::ATM()
    :currentCard(nullptr),
    selectedAccount(nullptr),
    state(ATMState::IDLE)
{
}

void ATM::insertCard(const Card& card){
    if (state != ATMState::IDLE){
        throw std::logic_error(
            "A card is already inserted"
        );
    }

    currentCard = &card; 
    state = ATMState::CARD_INSERTED; 
}

void ATM::authenticate(
    bool authenticationSucceeded, 
    const std::vector<Account*>& accounts 
){
    if (state != ATMState::CARD_INSERTED){
        throw std::logic_error(
            "Card must be inserted before authentication"
        );
    }
    if (!authenticationSucceeded){
        return;
    }

    avaiableAccounts = accounts;
    state = ATMState::AUTHENTICATED;
}

const std::vector<Account*>&ATM::getAvailableAccounts() const {
    if (
        state != ATMState::AUTHENTICATED && 
        state != ATMState::ACCOUNT_SELECTED
    ) {
        throw std::logic_error(
            "Authentication is required"
        );
    }
    return avaiableAccounts; 
}

void ATM::selectAccount(std::size_t index){
    if (state != ATMState::AUTHENTICATED){
        throw std::logic_error(
            "Authentication is required before selecting an account"
        );
    }

    if (index >= avaiableAccounts.size()){
        throw std::logic_error(
            "Invalid account selection"
        );
    }

    selectedAccount = avaiableAccounts[index];
    state = ATMState::ACCOUNT_SELECTED;
}

long long ATM::checkBalance() const {
    if (state != ATMState::ACCOUNT_SELECTED){
        throw std::logic_error(
            "An account must be selected"
        );
    }

    return selectedAccount->getBalance();
}

void ATM::deposit(long long amount){
    if (state != ATMState::ACCOUNT_SELECTED){
        throw std::logic_error(
            "An account must be selected"
        );
    }

    selectedAccount->deposit(amount); 
}

void ATM::withdraw(long long amount){
    if (state != ATMState::ACCOUNT_SELECTED){
        throw std::logic_error(
            "An account must be selected"
        );
    }

    selectedAccount->withdraw(amount); 
}

void ATM::ejectCard(){
    currentCard = nullptr;
    selectedAccount = nullptr;
    avaiableAccounts.clear(); 

    state = ATMState::IDLE;
}

ATMState ATM::getState() const{
    return state;
}