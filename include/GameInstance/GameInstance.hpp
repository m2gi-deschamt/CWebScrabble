#pragma once

#include "Board.hpp"
#include "Player.hpp"
#include "Piece.hpp"
#include "Game/Scrabble.hpp"
#include "Action.hpp"

#include <array>
#include <string>
#include <set>
#include <memory>

using namespace std;

class GameInstance {
protected:
    std::unique_ptr<Game> game;
    set<Player> players;
    Board board;

public:
    GameInstance(std::unique_ptr<Game> g);
    virtual ~GameInstance();

    void start();
    void play();
    void pause();

    void addPlayer(const Player &player);
    const set<Player>& getPlayers() const;

    void placePiece(Position &position, std::unique_ptr<Piece> piece);
    bool havePiece(Position& pos);
    void display();

    virtual void accept(DrawLetterAction&) = 0;
};

class ScrabbleInstance : public GameInstance {
public:
    ScrabbleInstance(std::unique_ptr<Scrabble> g);

    void accept(DrawLetterAction&);

private:
    void drawLetter();
};