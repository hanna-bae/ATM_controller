#include <gtest/gtest.h>
#include "Card.h"
// TEST(CardTest, TestEnvironmentWorks){
//     EXPECT_TRUE(true);
// }

TEST(CardTest, CreatesCardWithCardNumber){
    Card card("1234-5667-8999-2222");

    EXPECT_EQ(
        card.getCardNumber(), 
        "1234-5667-8999-2222"
    );

}

TEST(CardTest, RejectsEmptyCardNumber){
    EXPECT_THROW(
        Card(""),
        std::invalid_argument
    );

}