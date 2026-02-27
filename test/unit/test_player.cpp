#include <gtest/gtest.h>
#include "Player.hpp"

TEST(PlayerTest, ConfigPlayer) {
    Player player1 = Player({1}, "Thibaud", 24, MALE);
    EXPECT_TRUE(player1.getId().value == 1);
    EXPECT_TRUE(player1.getAge() == 24);
    EXPECT_TRUE(player1.getName() == "Thibaud");
    EXPECT_TRUE(player1.getGender() == MALE);
}
