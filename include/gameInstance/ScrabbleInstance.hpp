#pragma once
#include "GameInstance.hpp"
#include "Piece.hpp"
#include "Player.hpp"
#include "game/Scrabble.hpp"

#include <memory>
#include <unordered_map>

struct PlayerSet {
    std::vector<Letter> rack;
    int score = 0;
};

class ScrabbleInstance : public GameInstance {
std::vector<Letter> stack;
std::unordered_map<PlayerId, PlayerSet> scrabbleState;
public:
    ScrabbleInstance(const Scrabble& scrabble);
    virtual ~ScrabbleInstance();
    
    void setUp();
    void drawLetter(const PlayerInstance& player);

    PlayerSet getPlayerSet(const PlayerId& id) const;
};