#include <gtest/gtest.h>
#include "game/Scrabble.hpp"
#include "gameInstance/ScrabbleInstance.hpp"
#include "Player.hpp"

using namespace std;


class GameTest : public ::testing::Test {
protected:
    ScrabbleInstance game;
    Position position11;
    Player player1;
    Player player2;
    PlayerInstance player1Instance;
    PlayerInstance player2Instance;

    GameTest() : game(std::make_unique<Scrabble>()) {}

    void SetUp() override {
        position11 = {1,1};
        player1 = Player("Thibaud", 32, MALE);
        player2 = Player("Olivier", 24, MALE);
        player1Instance = PlayerInstance(player1);
        player2Instance = PlayerInstance(player2);
        std::unique_ptr<Piece> letter = std::make_unique<Letter>('a');
        game.placePiece(position11, std::move(letter));
    }

    void TearDown() override {
        // Optionnel : nettoyage après chaque test
    }
};

TEST_F(GameTest, AddPlayers) {
    
    Scrabble scrabble;
    ScrabbleInstance game(std::make_unique<Scrabble>());
    EXPECT_TRUE(game.getPlayers().size() == 0);
    game.addPlayer(player1Instance);
    EXPECT_TRUE(game.getPlayers().size() == 1);
}

TEST_F(GameTest, PLAYERMAX) {
    Player player3("Mylene", 28, FEMALE);
    Player player4("Marie", 18, FEMALE);
    Player player5("Damien", 42, MALE);
    PlayerInstance player3Instance(player3);
    PlayerInstance player4Instance(player4);
    PlayerInstance player5Instance(player5);
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

