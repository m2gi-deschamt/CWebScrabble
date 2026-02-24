#include <gtest/gtest.h>
#include "Board.hpp"
#include "Piece.hpp"
#include "Game.hpp"
#include "Scrabble.hpp"

using namespace std;


class ScrabbleTest : public ::testing::Test {
protected:
    Scrabble scrabble;
    GameInstance game;

    ScrabbleTest() : game(std::make_unique<Scrabble>()) {}

    void SetUp() override {
        std::unique_ptr<Piece> letter = std::make_unique<Letter>('a');
        game.placePiece({1,1}, std::move(letter));
    }

    void TearDown() override {
        // Optionnel : nettoyage après chaque test
    }
};

TEST_F(ScrabbleTest, HavePieceAt11) {
    EXPECT_TRUE(game.havePiece({1,1}));
}

TEST_F(ScrabbleTest, PieceValueEqualToA) {
    EXPECT_TRUE(game.havePiece({1,1}));
}

TEST_F(ScrabbleTest, NoPieceAt12) {
    EXPECT_FALSE(game.havePiece({1,2}));
}
