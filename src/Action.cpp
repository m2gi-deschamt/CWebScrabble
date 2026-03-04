#include "Action.hpp"
#include "gameInstance/GameInstance.hpp"
#include "Player.hpp"
#include "Piece.hpp"
#include "Board.hpp"

#include <optional>

Action::Action() = default;
Action::~Action() = default;

DrawLetterAction::DrawLetterAction() = default;
DrawLetterAction::~DrawLetterAction() = default;
void DrawLetterAction::execute(GameInstance& instance, PlayerInstance& player) {
        instance.drawLetter(player);
}

AddLetterAction::AddLetterAction(std::shared_ptr<Letter> letter, Position& position):
letter(letter), position(position){};

AddLetterAction::~AddLetterAction() = default;
void AddLetterAction::execute(GameInstance& instance, PlayerInstance& player) {
        instance.addLetter(player, letter, position);
}