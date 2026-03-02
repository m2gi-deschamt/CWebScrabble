
#include "gameInstance/ScrabbleInstance.hpp"

#include <cstdlib>
#include <ctime>

#include <random>
#include <iostream>

std::random_device rd;
std::mt19937 gen(rd());

using namespace std;

ScrabbleInstance::~ScrabbleInstance() = default;

ScrabbleInstance::ScrabbleInstance(const Scrabble& scrabble)
    : GameInstance(scrabble), stack(scrabble.getLettersVectors())
{};

void ScrabbleInstance::setUp() {
    for(size_t i = 0; i < players.size(); i++) {
        for(size_t countLetter = 0; countLetter < 7; countLetter++) {
            drawLetter(players[i]);
        }
        scrabbleState[players[i].getId()].score = 0;
    };
}

void ScrabbleInstance::drawLetter(const PlayerInstance& player) {
    std::uniform_int_distribution<> dist(0, stack.size());
    int index = dist(gen);
    Letter letter = stack[index];
    stack.erase(stack.begin()+index);
    scrabbleState[player.getId()].rack.push_back(letter);
};


PlayerSet ScrabbleInstance::getPlayerSet(const PlayerId& id) const {
        return scrabbleState.at(id);
}

void ScrabbleInstance::addLetter(PlayerInstance& player, Letter& letter, Position& pos) {

}


/*
    void drawLetter(PlayerInstance& player) {
        game->drawLetter(player.getId());
    }
*/