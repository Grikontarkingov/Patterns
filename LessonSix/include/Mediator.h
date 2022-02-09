#pragma once

#include <string>

class LevelGUI;

class Mediator {
public:
    explicit Mediator(LevelGUI* levelGUI);

    void AddMessageInQueue(std::string message);

private:
    LevelGUI* pLevelGUI;
};


