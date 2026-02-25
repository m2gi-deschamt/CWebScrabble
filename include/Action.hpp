#pragma once

class GameInstance;

class Action {
public:
    Action();
    virtual ~Action();
    virtual void execute(GameInstance& instance) = 0;
};

class DrawLetterAction : public Action {
public:
    void execute(GameInstance& instance) override;
};