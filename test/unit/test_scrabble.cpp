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
        player1 = Player({1},"Thibaud", 32, MALE);
        player2 = Player({2},"Olivier", 24, MALE);
        player1Instance = PlayerInstance(player1);
        player2Instance = PlayerInstance(player2);
        std::unique_ptr<Piece> letter = std::make_unique<Letter>('a');
        game.placePiece(position11, std::move(letter));
    }

    void TearDown() override {
        // Optionnel : nettoyage après chaque test
    }
};

TEST_F(ScrabbleTest, setUp) {
    cout << "Yo comprend\n" << flush;
    
    game.addPlayer(player1);
    game.addPlayer(player2);
    game.setUp();
     
    PlayerId pid = player1.getId();
    EXPECT_TRUE(pid.value == 1);
    PlayerId pid2 = player2.getId();
    EXPECT_TRUE(pid2.value == 2);

    PlayerSet playerData = game.getPlayerSet(pid);
    
    int score = playerData.score;
    EXPECT_TRUE(score == 1);

    char letter = playerData.rack[0].getLetter();
    EXPECT_TRUE(letter == 'a');

    //DrawLetterAction action;
    //action.execute(game,player1Instance);
}

/*
TEST_F(ScrabbleTest, execAction) {
    DrawLetterAction action;
    action.execute(game,player1Instance);
}
    */
