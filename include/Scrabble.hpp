#ifndef SCRABBLE_HPP
#define SCRABBLE_HPP

#include "Game.hpp"

#include <string>

using namespace std;
class Scrabble : public Game {
    private:

    public:
        Scrabble(){};
        bool isMoveValid(Action action, const Board& board) const override;
        bool checkVictory(const Board& board) const override;
        std::string getName() const override {return "Scrabble";}
        int getRows() const override {return 15;}
        int getCols() const override {return 15;}  
        int getMaxPlayer() const override {return 4;}
        int getMinPlayer() const override {return 2;}
};
#endif