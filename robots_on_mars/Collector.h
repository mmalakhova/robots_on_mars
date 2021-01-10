#pragma once
#include "Robot.h"



class Collector : public Robot {
private:
    Robot_Playground* map;
    int col_x, col_y;
    int apple_count;
public:
    Collector();
    void collector_move(movement m);
    void collector_scan(std::vector<cell> around);
    void collector_grab();
    int get_apple();
    std::pair<int, int> get_coords_on_own_map();
    Robot_Playground* get_map();
};

