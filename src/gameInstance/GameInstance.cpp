#include "gameInstance/GameInstance.hpp"
#include "game/Game.hpp"

#include <optional>

GameInstance::GameInstance(const Game& g) 
        : game(g),
          board(game.getRows(), game.getCols()),
          players({}) {}

GameInstance::~GameInstance() = default;

void GameInstance::addPlayer(const PlayerInstance &player) {
    if (players.size() < game.getMaxPlayer()) {
        players.push_back(player);
    } else {
        cout << "add new player to this instance is not possible";
    }
};

void GameInstance::start() {

}
void GameInstance::play() {

}
void GameInstance::pause() {

}

void GameInstance::display() {
    cout << "Game instance values : \n game : " << game.getName() << "\n";
};

const std::vector<PlayerInstance>& GameInstance::getPlayers() const {
    return players;
}

shared_ptr<Piece> GameInstance::getPiece(Position &position) {
        return board.getPiece(position);
    }

void GameInstance::placePiece(Position& position, std::shared_ptr<Piece> piece) {
    board.placePiece(position, piece);
}

bool GameInstance::havePiece(Position& pos) {
    return board.havePiece(pos);
}

void GameInstance::drawLetter(const PlayerInstance& player) {
    std::string error = "draw letter not implemented in this " + this->game.getName() + " GameInstance";
    throw std::logic_error(error);
}

void GameInstance::addLetter(PlayerInstance& player, std::shared_ptr<Letter> letter, Position& pos) {
    std::string error = "draw letter not implemented in this " + this->game.getName() + " GameInstance";
    throw std::logic_error(error);
}