#include <gtest/gtest.h>

#include "ATM.h"
// TEST(ATMTest, TestEnvironmentWorks){
//     EXPECT_TRUE(true);
// }

TEST(ATMTest, StartsInIdleState){
    ATM atm; 

    EXPECT_EQ(atm.getState(), ATMState::IDLE);
}

TEST(ATMTest, InsertCard){
    ATM atm;
    Card card("1111-2222");

    atm.insertCard(card);

    EXPECT_EQ(
        atm.getState(),
        ATMState::CARD_INSERTED
    );
}

TEST(ATMTest, RejectsSecondCardInsertion){
    ATM atm; 

    Card firstCard("1111-2222");
    Card secondCard("3333-4444");

    atm.insertCard(firstCard);

    EXPECT_THROW(
        atm.insertCard(secondCard),
        std::logic_error
    );

    EXPECT_EQ(
        atm.getState(),
        ATMState::CARD_INSERTED 
    );
}

