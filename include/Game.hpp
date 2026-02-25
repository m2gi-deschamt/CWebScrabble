#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Player.hpp"
#include "Piece.hpp"

#include <array>
#include <string>
#include <set>
#include <memory>

using namespace std;

class Action;
class DrawLetterAction;

enum GameState {
    START,
    INPROGRESS,
    FINISH
};

class Game {
public:
    Game() = default;
    virtual ~Game() = default;

    virtual bool isMoveValid(const Action& action, const Board& board) const = 0;
    virtual bool checkVictory(const Board& board) const = 0;
    virtual std::string getName() const = 0;
    virtual int getRows() const = 0;
    virtual int getCols() const = 0;
    virtual int getMinPlayer() const = 0;
    virtual int getMaxPlayer() const = 0;
};

class Scrabble : public Game {
private:
    std::array<Letter, 102> letters;
    static std::array<Letter, 102> initLetters();

public:
    Scrabble() = default;

    bool isMoveValid(const Action& action, const Board& board) const override;
    bool checkVictory(const Board& board) const override;

    std::string getName() const override { return "Scrabble"; }
    int getRows() const override { return 15; }
    int getCols() const override { return 15; }
    int getMaxPlayer() const override { return 4; }
    int getMinPlayer() const override { return 2; }
};


class GameInstance {
protected:
    std::unique_ptr<Game> game;
    set<Player> players;
    Board board;
    GameState state = START;

public:
    GameInstance(std::unique_ptr<Game> g)
        : game(std::move(g)),
          board(game->getRows(), game->getCols()) {}

    virtual ~GameInstance() = default;

    void start();
    void play();
    void pause();

    void addPlayer(const Player &player);
    const set<Player>& getPlayers() const;

    void placePiece(Position position, std::unique_ptr<Piece> piece);
    bool havePiece(Position pos);
    void display();

    virtual void accept(DrawLetterAction&) = 0;
};

class ScrabbleInstance : public GameInstance {
public:
    ScrabbleInstance(std::unique_ptr<Scrabble> g)
    : GameInstance(std::unique_ptr<Game>(std::move(g))) {}

    void accept(DrawLetterAction&);

private:
    void drawLetter();
};

#endif