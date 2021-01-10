#include "Collector.h"

Collector::Collector() {
	this->apple_count = 0;
	this->col_x = 0;
	this->col_y = 0;
	this->map = new Robot_Playground();
}

void Collector::collector_move(movement m) {
	switch (m) {
	case _right: {
		++this->col_x;	break;}
	
	case _left: {	
		--this->col_x;	break;}
	
	case down: {
		--this->col_y;	break;}
	
	case up: {
		++this->col_y;break;}
	
	default: {return; }
	}

	if (this->map->is_robot_on_border(this->col_x, this->col_y)) {
		this->map->increase_map(m);
	}

	return;
}

void Collector:: collector_scan(std::vector<cell> neighbourhood) {
	this->map->put(this->col_x - 1, this->col_y, neighbourhood[0]);
	this->map->put(this->col_x, this->col_y + 1, neighbourhood[1]);
	this->map->put(this->col_x + 1, this->col_y, neighbourhood[2]);
	this->map->put(this->col_x, this->col_y - 1, neighbourhood[3]);
	this->map->put(this->col_x, this->col_y, neighbourhood[4]);
	return;
}

void Collector:: collector_grab() {
	++this->apple_count;
	this->map->put(this->col_x, this->col_y, _empty);
	return;
}

int Collector::get_apple() {
	return this->apple_count;
}

Robot_Playground* Collector::get_map() {
	return this->map;
}

std::pair<int, int> Collector::get_coords_on_own_map() {
	return std::pair<int, int> { this->col_x, this->col_y };
}






