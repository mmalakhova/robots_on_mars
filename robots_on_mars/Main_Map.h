#pragma once
#include <vector>
#include <iostream>
#include "Playground.h"

class Main_Map {
private:
	Playground* map;
	int robot_coll_x, robot_coll_y, robot_sapp_x, robot_sapp_y;
	bool coll_alive, sapp_alive;
	void update_map(int x, int y, cell c);

public:
	Main_Map();
	~Main_Map();
	//Main_map(const char* path);
	void move_robot_collector(movement m);
	void move_robot_sapper(movement m);
	void update_robot_collector_existence();
	void update_robot_sapper_existence(bool flag);
	
	bool robot_collector_exist();
	bool robot_sapper_exist();

	cell get_robot_collector_block(int shift_x, int shift_y);
	
	void create_robot_collector();
	void create_robot_sapper(int x, int y);

	void demine();
	void grab();
	

};

