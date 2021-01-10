#include "Context.h"
#include "Main_Map.h"


Context::Context() {
	this->map = nullptr;
	this->Rob_C = nullptr;
	this->Rob_S = nullptr;
	
	this->Rob_C = new Collector();
	this->map->create_robot_collector();
	this->map = new Main_Map();
}

Context::~Context() {
	delete this->map;
	delete this->Rob_C;
	delete this->Rob_S;
}


