#include "Sapper.h"


Sapper::Sapper(Robot_Playground* rpg, int my_x, int my_y, int collector_x, int collector_y) {
	this->sapp_x = my_x;
	this->sapp_y = my_y;
	this->coll_x = collector_x;
	this->coll_y = collector_y;
	this->map = new Robot_Playground(*rpg);
}

void Sapper:: sapp_move(movement m) {
	switch (m) {
	case _right: {
		++this->sapp_x;	return;	}
	
	case _left: {
		--this->sapp_x;	return; }
	
	case down: {	
		--this->sapp_y;	return;	}
	
	case up: {		
		++this->sapp_y;	return;	}
	
	default: {return; }
	}
	return;
}

void Sapper::update_coll_coords(movement m) {
	switch (m) {
	
	case _right: {
		++this->coll_x;	return;	}
	
	case _left: {	
		--this->coll_x;	return; }
	
	case down: {	
		--this->coll_y;	return;	}
	
	case up: {		
		++this->coll_y;	return;	}
	
	default: {return; }
	}
	return;
}

void Sapper::update_map(Robot_Playground* rpg) {
	delete this->map;
	this->map = new Robot_Playground(*rpg);
	return;
}


void Sapper:: sapp_devouse() {
	this->map->put(this->sapp_x, this->sapp_y, _empty);
	return;
}

cell Sapper::get_cell(int shift_x, int shift_y) {
	return this->map->get_data(this->sapp_x + shift_x, this->sapp_y + shift_y);
}

std::pair<int, int> Sapper::get_own_coords() {
	return std::pair<int, int> { this->sapp_x, this->sapp_y };
}

Robot_Playground* Sapper::get_map() {
	return this->map;
}







