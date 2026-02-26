
#include "gameInstance/ScrabbleInstance.hpp"
using namespace std;

ScrabbleInstance::ScrabbleInstance() = default;
ScrabbleInstance::~ScrabbleInstance() = default;

ScrabbleInstance::ScrabbleInstance(std::unique_ptr<Scrabble> g)
    : GameInstance(std::unique_ptr<Game>(std::move(g))) {};

void ScrabbleInstance::drawLetter(PlayerInstance& player) {

        cout << "\n Draw letter brooo !\n";
};