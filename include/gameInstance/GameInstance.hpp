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
    const Game &game;
    std::vector<PlayerInstance> players;
    Board board;

public:
    virtual ~GameInstance();
    GameInstance(const Game& g);

    void start();
    void play();
    void pause();

    void addPlayer(const PlayerInstance &player);
    const vector<PlayerInstance>& getPlayers() const;

    shared_ptr<Piece> getPiece(Position &position);

    void placePiece(Position &position, std::shared_ptr<Piece> piece);
    bool havePiece(Position& pos);
    void display();

    virtual void drawLetter(const PlayerInstance& player);
    virtual void addLetter(PlayerInstance& player, std::shared_ptr<Letter> letter, Position& pos);
};