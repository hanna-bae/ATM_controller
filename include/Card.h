#pragma once 
#include <string> 
class Card{
private: 
    std::string cardNumber; 

public:
    explicit Card(const std::string& cardNumber);

    const std::string& getCardNumber() const; 
};