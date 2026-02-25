#include <gtest/gtest.h>
#include "Game.hpp"
#include "Player.hpp"

using namespace std;

TEST(GameTest, AddPlayers) {
    Player player1("Thibaud", 32, MALE);
    Player player2("Olivier", 24, MALE);
    Scrabble scrabble;
    ScrabbleInstance game(std::make_unique<Scrabble>());
    EXPECT_TRUE(game.getPlayers().size() == 0);
    game.addPlayer(player1);
    EXPECT_TRUE(game.getPlayers().size() == 1);
}

TEST(GameTest, PLAYERMAX) {
    Player player1("Thibaud", 32, MALE);
    Player player2("Olivier", 24, MALE);
    Player player3("Mylene", 28, FEMALE);
    Player player4("Marie", 18, FEMALE);
    Player player5("Damien", 42, MALE);
    Scrabble scrabble;
    ScrabbleInstance game(std::make_unique<Scrabble>());
    game.addPlayer(player1);
    game.addPlayer(player2);
    EXPECT_TRUE(game.getPlayers().size() == 2);
    game.addPlayer(player3); 
    game.addPlayer(player4);
    game.addPlayer(player5); // should return warning
    EXPECT_TRUE(game.getPlayers().size() == 4);
}

