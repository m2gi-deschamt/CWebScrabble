#pragma once
#include "GameInstance.hpp"

#include <memory>

class ScrabbleInstance : public GameInstance {
public:
    ScrabbleInstance();
    ScrabbleInstance(std::unique_ptr<Scrabble> g);
    virtual ~ScrabbleInstance();
    void accept(DrawLetterAction&);

private:
    void drawLetter();
};