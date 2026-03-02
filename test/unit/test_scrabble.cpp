#include <gtest/gtest.h>
#include "Board.hpp"
#include "Piece.hpp"
#include "game/Scrabble.hpp"
#include "gameInstance/ScrabbleInstance.hpp"
#include "Action.hpp"

#include <memory>

using namespace std;


class ScrabbleTest : public ::testing::Test {
protected:
    Scrabble scrabble;
    ScrabbleInstance game;
    Position position11 = {1,1};
    Player player1;
    Player player2;
    PlayerInstance player1Instance;
    PlayerInstance player2Instance;

    ScrabbleTest() : game(scrabble) {}

    void SetUp() override {
        player1 = Player({0},"Thibaud", 32, MALE);
        player2 = Player({1},"Olivier", 24, MALE);
        player1Instance = PlayerInstance(player1);
        player2Instance = PlayerInstance(player2);
    }

    void TearDown() override {
        // Optionnel : nettoyage après chaque test
    }
};

TEST_F(ScrabbleTest, pidValue) {
    EXPECT_EQ(player1Instance.getId().value, 0);
    EXPECT_EQ(player2Instance.getId().value, 1);
}

TEST_F(ScrabbleTest, setUp) {
    game.addPlayer(player1Instance);
    game.setUp();
    
    PlayerSet playerData = game.getPlayerSet(player1Instance.getId());
    
    //char letter = playerData.rack[0].getLetter();
    int len = playerData.rack.size();
    //EXPECT_TRUE(letter == 'a');
    EXPECT_TRUE(len == 7);
}

TEST_F(ScrabbleTest, rackSize) {
    game.addPlayer(player1Instance);
    game.setUp();
    PlayerId pid = player1Instance.getId();
    
    DrawLetterAction action;
    PlayerSet playerData = game.getPlayerSet(player1Instance.getId());
    int len = playerData.rack.size();
    EXPECT_EQ(len, 7);
}

TEST_F(ScrabbleTest, drawLetterAction) {
    DrawLetterAction action;

    game.addPlayer(player1Instance);
    game.setUp();
    PlayerId pid = player1Instance.getId();
    int initialSize = game.getPlayerSet(pid).rack.size();
    
    action.execute(game, player1Instance);

    int newSize = game.getPlayerSet(pid).rack.size();
    EXPECT_EQ(newSize, initialSize + 1);
}
