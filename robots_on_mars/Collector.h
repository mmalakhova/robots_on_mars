#pragma once
#include "Robot.h"
#include "Map.h"

class Collector : public IRobot {
private:
    size_t apple_count;
    size_t col_x;
    size_t col_y;
    Map* col_map;
public:

};

