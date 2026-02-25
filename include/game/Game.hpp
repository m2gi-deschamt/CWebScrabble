#pragma once

#include <string>

using namespace std;

class Action;
class Board;

enum GameState {
    START,
    INPROGRESS,
    FINISH
};

class Game {
public:
    Game();
    virtual ~Game();

    virtual bool isMoveValid(const Action& action, const Board& board) const = 0;
    virtual bool checkVictory(const Board& board) const = 0;
    virtual std::string getName() const = 0;
    virtual int getRows() const = 0;
    virtual int getCols() const = 0;
    virtual int getMinPlayer() const = 0;
    virtual int getMaxPlayer() const = 0;
};