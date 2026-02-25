
#include "gameInstance/ScrabbleInstance.hpp"

ScrabbleInstance::ScrabbleInstance() = default;
ScrabbleInstance::~ScrabbleInstance() = default;

ScrabbleInstance::ScrabbleInstance(std::unique_ptr<Scrabble> g)
    : GameInstance(std::unique_ptr<Game>(std::move(g))) {};

void ScrabbleInstance::accept(DrawLetterAction&) {
        drawLetter();
}

void ScrabbleInstance::drawLetter() {
        cout << "implem drawLetter bro !! ";
}