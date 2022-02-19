#pragma once

#include <string>

class LevelGUI;

class Mediator {
public:
    explicit Mediator(LevelGUI* levelGUI);

    void AddMessageInQueue(uint16_t x, uint16_t y, std::string_view message);

private:
    LevelGUI* pLevelGUI;
};


