#include <gtest/gtest.h>
#include "Board.hpp"
#include "Piece.hpp"
#include "game/Scrabble.hpp"
#include "gameInstance/ScrabbleInstance.hpp"
#include "Player.hpp"

using namespace std;


class GameInstanceTest : public ::testing::Test {
protected:
    Scrabble scrabble;
    ScrabbleInstance game;
    Position position11 = {1,1};

    GameInstanceTest() : game(std::make_unique<Scrabble>()) {}

    void SetUp() override {
        game.placePiece(position11, std::make_unique<Pawn>());
    }

    void TearDown() override {
        // Optionnel : nettoyage après chaque test
    }
};

TEST_F(GameInstanceTest, HavePieceAt11) {
    EXPECT_TRUE(game.havePiece(position11));
}

TEST_F(GameInstanceTest, NoPieceAt12) {
    Position position12 = {1,2};
    EXPECT_FALSE(game.havePiece(position12));
}