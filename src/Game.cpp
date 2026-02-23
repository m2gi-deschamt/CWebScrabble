#include "Game.hpp"

#include <iostream>

void GameInstance::addPlayer(const Player &player) {
    if (players.size() < game->getMaxPlayer()) {
        players.insert(player);
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
    cout << "Game instance values : \n game : " << game->getName() << "\n";
};

const set<Player>& GameInstance::getPlayers() const {
    return players;
}

void GameInstance::placePiece(Position position, std::unique_ptr<Piece> piece) {
    board.placePiece(position, std::move(piece));
}

bool GameInstance::havePiece(Position pos) const {
    return board.havePiece(pos);
}