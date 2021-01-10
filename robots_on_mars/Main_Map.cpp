#include "Main_Map.h"

void Main_Map::create_robot_collector() {
	//srand(time(NULL));
	this->coll_alive = true;
	int length = this->map->get_length();
	int width = this->map->get_width();
	
	while (true) {
		int x = (rand() % (width - 1)) + 1;
		int y = (rand() % (length - 1)) + 1;
		cell b = this->map->get_data(x, y);

		if (b != cell::bomb && b != cell::rock) {
			this->robot_coll_x = x;
			this->robot_coll_y = y;
			break;
		}
	}
	return;
}

void Main_Map::create_robot_sapper(int x, int y)
{
	//может нужно рандомно генерировать сдвиг???
	this->sapp_alive = true;
	this->robot_sapp_x = this->robot_coll_x + x;
	this->robot_sapp_y = this->robot_coll_y + y;
}

void Main_Map::demine()
{
	this->update_map(this->robot_sapp_x, this->robot_sapp_y, _empty);
}

void Main_Map::grab()
{
	this->update_map(this->robot_sapp_x, this->robot_sapp_y, _empty);

}

void Main_Map::update_map(int x, int y, cell c)
{
	this->map->set(x, y, c);
}

Main_Map::Main_Map()
{
	this->map = new Playground();
	this->robot_sapp_x = 0;
	this->robot_sapp_y = 0;

	this->robot_coll_x = 0;
	this->robot_coll_y = 0;
}

Main_Map::~Main_Map()
{
	if (this->map != nullptr) {
		delete this->map;
	}
	this->map = nullptr;
}

void Main_Map::move_robot_collector(movement m)
{
}

void Main_Map::move_robot_sapper(movement m)
{
}

void Main_Map::update_robot_collector_existence()
{
	if (this->map->get_data(robot_coll_x, robot_coll_y) == bomb) {
		this->coll_alive = false;
	}
	return;
}

void Main_Map::update_robot_sapper_existence(bool flag)
{
	this->sapp_alive = flag;
	return;
}

bool Main_Map::robot_collector_exist()
{
	return this->coll_alive;
}

bool Main_Map::robot_sapper_exist()
{
	return this->sapp_alive;
}

cell Main_Map::get_robot_collector_block(int shift_x, int shift_y)
{
	cell result = this->map->get_data(this->robot_coll_x + shift_x, this->robot_coll_y + shift_y);
	return result;
}

