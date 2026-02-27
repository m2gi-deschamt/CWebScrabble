
#include "gameInstance/ScrabbleInstance.hpp"
using namespace std;

ScrabbleInstance::~ScrabbleInstance() = default;

ScrabbleInstance::ScrabbleInstance(Scrabble& scrabble)
    : GameInstance(scrabble), stack(scrabble.getLettersVectors())
{};

void ScrabbleInstance::setUp() {
    for(size_t i = 0; i < players.size(); i++) {
        std::vector<Letter> rack;
        for(size_t countLetter = 0; countLetter < 7; countLetter++) {
            rack.push_back(Letter('a'));
        }
        scrabbleState[players[i].getId()] = {rack, 1};
    };
}

void ScrabbleInstance::drawLetter(PlayerInstance& player) {
        cout << "\n Draw letter brooo !\n";
};


PlayerSet ScrabbleInstance::getPlayerSet(PlayerId& id){
        return scrabbleState[id];
}


/*
    void drawLetter(PlayerInstance& player) {
        game->drawLetter(player.getId());
    }
*/