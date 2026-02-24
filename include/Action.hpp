#ifndef ACTION_HPP
#define ACTION_HPP

class Action {
public:
    virtual ~Action() = default;
    virtual void execute(GameInstance& instance) = 0;
};

class DrawLetterAction : public Action {
public:
    void execute(GameInstance& instance) override {
        instance.drawLetter();
    }
};

#endif