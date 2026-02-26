#pragma once
#include "GameInstance.hpp"
#include "Piece.hpp"

#include <memory>
#include <unordered_map>

struct PlayerTools {
    std::vector<Letter> letters;
    int score;
};

class ScrabbleInstance : public GameInstance {
std::unordered_map<PlayerInstance*, PlayerTools> players;
public:
    ScrabbleInstance();
    ScrabbleInstance(std::unique_ptr<Scrabble> g);
    virtual ~ScrabbleInstance();
    void drawLetter(PlayerInstance& player) override;
};