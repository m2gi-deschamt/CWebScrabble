#pragma once

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