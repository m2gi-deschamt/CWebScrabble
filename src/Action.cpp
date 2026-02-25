#include "Action.hpp"
#include "GameInstance/GameInstance.hpp"

void DrawLetterAction::execute(GameInstance& instance) {
        instance.accept(*this);
}