#include "Action.hpp"
#include "gameInstance/GameInstance.hpp"

void DrawLetterAction::execute(GameInstance& instance) {
        instance.accept(*this);
}