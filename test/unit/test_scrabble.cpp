#include <gtest/gtest.h>
#include "Board.hpp"
#include "Piece.hpp"
#include "game/Scrabble.hpp"
#include "gameInstance/ScrabbleInstance.hpp"

#include <memory>

using namespace std;


class ScrabbleTest : public ::testing::Test {
protected:
    ScrabbleInstance game;
    Position position11 = {1,1};

    ScrabbleTest() : game(std::make_unique<Scrabble>()) {}

    void SetUp() override {
        std::unique_ptr<Piece> letter = std::make_unique<Letter>('a');
        game.placePiece(position11, std::move(letter));
    }

    void TearDown() override {
        // Optionnel : nettoyage après chaque test
    }
};

TEST_F(ScrabbleTest, HavePieceAt11) {
    EXPECT_TRUE(game.havePiece(position11));
}

TEST_F(ScrabbleTest, PieceValueEqualToA) {
    EXPECT_TRUE(game.havePiece(position11));
}

TEST_F(ScrabbleTest, NoPieceAt12) {
    Position position12 = {1,2};
    EXPECT_FALSE(game.havePiece(position12));
}
