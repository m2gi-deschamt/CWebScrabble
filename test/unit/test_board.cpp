#include <gtest/gtest.h>
#include "Board.hpp"
#include "Piece.hpp"
#include "Game.hpp"

using namespace std;


class GameInstanceTest : public ::testing::Test {
protected:
    Scrabble scrabble;
    ScrabbleInstance game;

    GameInstanceTest() : game(std::make_unique<Scrabble>()) {}

    void SetUp() override {
        game.placePiece({1,1}, std::make_unique<Pawn>());
    }

    void TearDown() override {
        // Optionnel : nettoyage après chaque test
    }
};

TEST_F(GameInstanceTest, HavePieceAt11) {
    EXPECT_TRUE(game.havePiece({1,1}));
}

TEST_F(GameInstanceTest, NoPieceAt12) {
    EXPECT_FALSE(game.havePiece({1,2}));
}
