#include <iostream>

#include "ATM.h"
#include "Account.h"
#include "Card.h"


int main(){
    Card card("1111-2222");

    Account checking(
        "checking-001",
        AccountType::CHECKING,
        1000
    );

    Account savings(
        "savings-001",
        AccountType::SAVINGS, 
        2000
    );

    ATM atm; 

    atm.insertCard(card);

    atm.authenticate(true, {&checking, &savings});

    atm.selectAccount(0);

    std::cout << "Initial balance: " << atm.checkBalance() << '\n';

    atm.deposit(500);

    std::cout << "After deposit: " << atm.checkBalance() << '\n';

    atm.withdraw(300);
    std::cout << "After withdrawal: " << atm.checkBalance() << '\n';

    atm.ejectCard(); 

    return 0; 

}