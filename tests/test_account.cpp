#include <gtest/gtest.h>

#include "Account.h"
// TEST(AccountTest, TestEnvironmentWorks){
//     EXPECT_TRUE(true);
// }

TEST(AccountTest, CreateAccountWithInitialBalance){
    Account account(
        "123-456",
        AccountType::CHECKING, 
        1000
    );

    EXPECT_EQ(account.getAccountId(), "123-456");
    EXPECT_EQ(account.getAccountType(), AccountType::CHECKING);
    EXPECT_EQ(account.getBalance(), 1000);
}

TEST(AccountTest, DepositsValidAmount){
    Account account(
        "123-456",
        AccountType::CHECKING, 
        1000
    );

    account.deposit(500);

    EXPECT_EQ(account.getBalance(), 1500);
    
}

TEST(AccountTest, RejectsZeroDeposit){
    Account account(
        "123-456",
        AccountType::CHECKING, 
        1000
    );

    EXPECT_THROW(
        account.deposit(-1000),
        std::invalid_argument
    );
    EXPECT_EQ(account.getBalance(), 1000);
 
}

TEST(AccountTest, WithdrawsValidAmount){
    Account account(
        "123-456",
        AccountType::CHECKING, 
        1000
    );

    account.withdraw(300);
    EXPECT_EQ(account.getBalance(), 700);
 
}

TEST(AccountTest, AllowsWithdrawingEntireBalance){
    Account account(
        "123-456",
        AccountType::CHECKING, 
        1000
    );

    account.withdraw(1000);
    EXPECT_EQ(account.getBalance(), 0);
 
}

TEST(AccountTest, RejectsWithdrawalAboveBalance){
    Account account(
        "123-456",
        AccountType::CHECKING, 
        1000
    );

    EXPECT_THROW(
        account.withdraw(1500),
        std::runtime_error
    );
    EXPECT_EQ(account.getBalance(), 1000);
 
}

TEST(AccountTest, RejectsNonPositiveWithDrawl){
    Account account(
        "123-456",
        AccountType::CHECKING, 
        1000
    );

    EXPECT_THROW(
        account.withdraw(0),
        std::invalid_argument
    );
    EXPECT_THROW(
        account.withdraw(-1000),
        std::invalid_argument
    );
    EXPECT_EQ(account.getBalance(), 1000);
 
}

TEST(AccountTest, RejectsNegativeInitialBalance){
    EXPECT_THROW(
        Account account(
            "123-456",
            AccountType::CHECKING, 
            -100
        ),
    std::invalid_argument
    );
 
}