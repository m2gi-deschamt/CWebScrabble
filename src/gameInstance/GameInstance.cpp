#include "gameInstance/GameInstance.hpp"
#include "game/Game.hpp"

#include <memory>

GameInstance::GameInstance(Game& g) 
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

void GameInstance::placePiece(Position& position, std::unique_ptr<Piece> piece) {
    board.placePiece(position, std::move(piece));
}

bool GameInstance::havePiece(Position& pos) {
    return board.havePiece(pos);
}

void GameInstance::drawLetter(PlayerInstance& player) {
    throw std::logic_error("Not implemented in this GameInstance");
}