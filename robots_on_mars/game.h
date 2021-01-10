#pragma once
#include "Main_Map.h"
#include "Robot.h"
#include "Mode.h"

class Game {
private:
    Main_Map* general_map;
    Robot* robots;
    //IMode mode;
public:
    Game();
    ~Game();
    void change_mode(IMode);
    void play();
};
