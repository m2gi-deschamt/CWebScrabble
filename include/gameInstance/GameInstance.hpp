#pragma once

#include "Board.hpp"
#include "Player.hpp"
#include "Piece.hpp"
#include "game/Scrabble.hpp"
#include "Action.hpp"

#include <string>
#include <vector>
#include <memory>

using namespace std;


class GameInstance {
protected:
    Game &game;
    std::vector<PlayerInstance> players;
    Board board;

public:
    virtual ~GameInstance();
    GameInstance(Game& g);

    void start();
    void play();
    void pause();

    void addPlayer(const PlayerInstance &player);
    const vector<PlayerInstance>& getPlayers() const;

    void placePiece(Position &position, std::unique_ptr<Piece> piece);
    bool havePiece(Position& pos);
    void display();

    virtual void drawLetter(PlayerInstance& player);
};