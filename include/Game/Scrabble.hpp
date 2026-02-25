#pragma once

#include "Game.hpp"
#include "Piece.hpp"
#include <array>
#include <string>

class Board;   
class Action;

class Scrabble : public Game {
private:
    std::array<Letter, 102> letters;
    static std::array<Letter, 102> initLetters();

public:
    Scrabble();
    virtual ~Scrabble();

    bool isMoveValid(const Action& action, const Board& board) const override;
    bool checkVictory(const Board& board) const override;

    std::string getName() const override { return "Scrabble"; }
    int getRows() const override { return 15; }
    int getCols() const override { return 15; }
    int getMaxPlayer() const override { return 4; }
    int getMinPlayer() const override { return 2; }
};