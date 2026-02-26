#pragma once

#include "Board.hpp"
#include "Player.hpp"
#include "Piece.hpp"
#include "game/Scrabble.hpp"
#include "Action.hpp"

#include <array>
#include <string>
#include <set>
#include <memory>

using namespace std;

class GameInstance {
protected:
    std::unique_ptr<Game> game;
    set<PlayerInstance> players;
    Board board;

public:
    GameInstance();
    GameInstance(std::unique_ptr<Game> g);
    virtual ~GameInstance();

    void start();
    void play();
    void pause();

    void addPlayer(const PlayerInstance &player);
    const set<PlayerInstance>& getPlayers() const;

    void placePiece(Position &position, std::unique_ptr<Piece> piece);
    bool havePiece(Position& pos);
    void display();

    virtual void drawLetter(PlayerInstance& player);
};