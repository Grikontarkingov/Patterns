#include "Mediator.h"
#include "LevelGUI.h"

Mediator::Mediator(LevelGUI* levelGUI) : pLevelGUI(levelGUI) {}

void Mediator::AddMessageInQueue(uint16_t x, uint16_t y, std::string_view message) {
    pLevelGUI->AddMessage(x, y, message);
}