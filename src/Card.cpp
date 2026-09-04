#include "Card.h"
#include <stdexcept> 

Card::Card(const std::string& cardNumber)
    : cardNumber(cardNumber)
{
    if (cardNumber.empty()){
        throw std::invalid_argument(
            "Card number cannot be empty"
        );
    }
}

const std::string&Card::getCardNumber() const{
    return cardNumber;
}