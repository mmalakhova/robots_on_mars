#pragma once
#include "Map.h"
#include "Robot.h"
#include "Mode.h"

class Game {
private:
    Map* general_map;
    IRobot* robots;
    IMode mode;
public:
    Game();
    ~Game();
    void change_mode(IMode);
    void play();
};
