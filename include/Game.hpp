#ifndef GAME_HPP
#define GAME_HPP


#include "Board.hpp"
#include "Action.hpp"
#include "Player.hpp"
#include "Piece.hpp"

#include <string>
#include <set>

using namespace std;
enum GameState {
    START,
    INPROGRESS,
    FINISH
};

class Game {
    public:
        Game() = default;
        virtual bool isMoveValid(Action action, const Board& board) const = 0;
        virtual bool checkVictory(const Board& board) const = 0;
        virtual std::string getName() const = 0;
        virtual int getRows() const = 0;
        virtual int getCols() const = 0;
        virtual int getMinPlayer() const = 0;
        virtual int getMaxPlayer() const = 0;

    private: 
};

class GameInstance {
    private:
        std::unique_ptr<Game> game;
        set<Player> players;
        Board board;
        enum GameState state = START;
        
    public:
        GameInstance(std::unique_ptr<Game> g)
        : game(std::move(g)), board(game->getRows(), game->getCols()) {}
        
        void start();
        void play();
        void pause();
       
        void addPlayer(const Player &player);
        const set<Player>& getPlayers() const;
        
        void placePiece(Position position, std::unique_ptr<Piece> piece);
        bool havePiece(Position pos);
        void display();
};



class ScrabbleInstance : public GameInstance {
    public: 
        Letter drawLetter(){

        }
};

#endif