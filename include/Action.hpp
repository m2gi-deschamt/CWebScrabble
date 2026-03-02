#pragma once

#include "Piece.hpp"
#include "Board.hpp"
class GameInstance;
class PlayerInstance;

class Action {
public:
    Action();
    virtual ~Action();
    virtual void execute(GameInstance& instance, PlayerInstance& player) = 0;
};

class DrawLetterAction : public Action {
public:
    DrawLetterAction();
    virtual ~DrawLetterAction();
    void execute(GameInstance& instance, PlayerInstance& player) override;
};

class AddLetterAction : public Action {
    private:
        Letter letter;
        Position position;

    public:
        AddLetterAction(Letter& letter, Position& position);
        virtual ~AddLetterAction();
        void execute(GameInstance& instance, PlayerInstance& player) override;
};