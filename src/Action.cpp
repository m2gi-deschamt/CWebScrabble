#include "Action.hpp"
#include "gameInstance/GameInstance.hpp"
#include "Player.hpp"


Action::Action() = default;
Action::~Action() = default;

DrawLetterAction::DrawLetterAction() = default;
DrawLetterAction::~DrawLetterAction() = default;
void DrawLetterAction::execute(GameInstance& instance, PlayerInstance& player) {
        instance.drawLetter(player);
}