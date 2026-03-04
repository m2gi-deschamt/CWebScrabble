#pragma once

#include "Piece.hpp"
#include "Board.hpp"
class GameInstance;
class PlayerInstance;

#include <optional>

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
        std::shared_ptr<Letter> letter;
        Position position;

    public:
        AddLetterAction(std::shared_ptr<Letter> letter, Position& position);
        virtual ~AddLetterAction();
        void execute(GameInstance& instance, PlayerInstance& player) override;
};