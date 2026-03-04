#pragma once
#include "GameInstance.hpp"
#include "Piece.hpp"
#include "Player.hpp"
#include "game/Scrabble.hpp"

#include <optional>
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
    void addLetter(PlayerInstance& player, std::optional<Letter> letter, Position& pos);

    PlayerSet getPlayerSet(const PlayerId& id) const;
};