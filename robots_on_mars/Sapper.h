#pragma once
#include "Robot.h"


class Sapper : public Robot {
private:
	Robot_Playground* map;
	int sapp_x, sapp_y;
	int coll_x, coll_y;
public:
	Sapper(Robot_Playground* playg, int sapp_x, int sapp_y, int coll_x, int coll_y);
	void sapp_move(movement m);
	void update_coll_coords(movement m);
	void update_map(Robot_Playground* playg);
	std::pair<int, int> get_own_coords();
	cell get_cell(int shift_x, int shift_y);
	Robot_Playground* get_map();
	void sapp_devouse();
};
