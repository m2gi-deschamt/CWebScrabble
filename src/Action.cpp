#include "Action.hpp"
#include "Game.hpp"

void DrawLetterAction::execute(GameInstance& instance) {
        instance.accept(*this);
}