#include "Mediator.h"
#include "LevelGUI.h"

Mediator::Mediator(LevelGUI* levelGUI) : pLevelGUI(levelGUI) {}

void Mediator::SetMessagesInQueue(std::string message) {
    pLevelGUI->AddMessage(std::move(message));
}