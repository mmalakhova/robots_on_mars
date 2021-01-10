#include "Playground.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

Playground::Playground()
{
	this->length = 20;
	this->width = 20;
	this->map = new cell* [this->length];
	for (int i = 0; i < this->length; i++) {
		this->map[i] = new cell[this->width];
	}
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < this->width; j++) {
			this->map[i][j] = unknown;
		}
	}


}

int Playground::get_length() {
	return this->length;
}

int Playground::get_width() {
	return this->width;
}

cell Playground::get_data(int pos_x, int pos_y) {
	return this->map[pos_x][pos_y];
}

void Playground::set(int pos_x, int pos_y, cell b) {
	this->map[pos_x][pos_y] = b;
	return;
}


std::ostream& operator<<(std::ostream& out, Playground& map)
{
	for (size_t i = 0; i < map.get_length(); i++) {
		for (size_t j = 0; j < map.get_width(); j++) {

			switch (map.get_data(i, j)) {
			case rock: { cout << '#'; break; }
			case _empty: { cout << '_'; break; }
			case apple: { cout << 'A'; break; }
			case bomb: { cout << 'B'; break; }
			case unknown: { cout << '?' << ' '; break; }
			case sapper: { cout << 'S'; break; }

			}
		}
		cout << endl;
	}
	cout << endl;
	return out;
}


Playground::Playground(const Playground &pg) {
	this->length = pg.length;
	this->width = pg.width;
	this->map = new cell * [this->length];

	for (int i = 0; i < this->length; ++i) {
		this->map[i] = new cell[this->width];
	}

	for (int i = 0; i < this->length; ++i) {
		for (int j = 0; j < this->width; ++j) {
			this->map[i][j] = pg.map[i][j];
		}
	}
}
Playground::~Playground() {
	if (this->map != nullptr) {
		delete[] this->map;
	}
	this->map = nullptr;
}


void Playground::increase_map(movement m) {
	cell** prev = this->map;

	switch (m) {
	case _left: {
		this->map = new  cell* [this->length + 1];

		for (int i = 0; i < this->length + 1; ++i) {
			this->map[i] = new cell[this->width];
			for (int j = 0; j < this->width; ++j) {
				this->map[i][j] = unknown;
			}
		}

		for (int i = 0; i < this->length; ++i) {
			for (int j = 0; j < this->width; ++j) {
				this->map[i + 1][j] = prev[i][j];
			}
		}


		for (int i = 0; i < this->length; ++i) {
			delete[] prev[i];
		}
		delete[] prev;

		++this->length;
		break;
	}

	case _right: {
		this->map = new cell* [this->length + 1];

		for (int i = 0; i < this->length + 1; ++i) {
			this->map[i] = new cell[this->width];
			for (int j = 0; j < this->width; ++j) {
				this->map[i][j] = unknown;
			}
		}

		for (int i = 0; i < this->length; ++i) {
			for (int j = 0; j < this->width; ++j) {
				this->map[i][j] = prev[i][j];
			}
		}


		for (int i = 0; i < this->length; ++i) {
			delete[] prev[i];
		}
		delete[] prev;

		++this->length;
		break;
	}

	case down: {
		this->map = new cell* [this->length];

		for (int i = 0; i < this->length; ++i) {
			this->map[i] = new cell[this->width + 1];
			for (int j = 0; j < this->width + 1; ++j) {
				this->map[i][j] = unknown;
			}
		}

		for (int i = 0; i < this->length; ++i) {
			for (int j = 0; j < this->width; ++j) {
				this->map[i][j + 1] = prev[i][j];
			}
		}


		for (int i = 0; i < this->length; ++i) {
			delete[] prev[i];
		}
		delete[] prev;

		++this->width;
		break;
	}

	case up: {
		this->map = new cell* [this->length];

		for (int i = 0; i < this->length; ++i) {
			this->map[i] = new cell[this->width + 1];
			for (int j = 0; j < this->width + 1; ++j) {
				this->map[i][j] = unknown;
			}
		}

		for (int i = 0; i < this->length; ++i) {
			for (int j = 0; j < this->width; ++j) {
				this->map[i][j] = prev[i][j];
			}
		}


		for (int i = 0; i < this->length; ++i) {
			delete[] prev[i];
		}
		delete[] prev;

		++this->width;
		break;
	}
	}

	return;
}


//______________________________________
//_________ROBOTS_PLAYGROUND____________
//______________________________________


Robot_Playground::Robot_Playground() {
	this->map = new Playground();
	this->shift_x = 1;
	this->shift_y = 1;
}

Robot_Playground::Robot_Playground(const Robot_Playground& pg) {
	this->map = new Playground(*pg.map);
	this->shift_x = pg.shift_x;
	this->shift_y = pg.shift_y;
}
Robot_Playground::~Robot_Playground() {
	if (this->map != nullptr) {
		delete[] this->map;
	}
	this->map = nullptr;
}

cell Robot_Playground::get_data(int pos_x, int pos_y) {
	return this->map->get_data(pos_x + this->shift_x, pos_y + this->shift_y);
}

void Robot_Playground::put(int pos_x, int pos_y, cell b) {
	this->map->set(pos_x + this->shift_x, pos_y + this->shift_y, b);
	return;
}

std::pair<int, int> Robot_Playground::get_shift() {
	return std::pair<int, int>(this->shift_x, this->shift_y);
}

int Robot_Playground::get_length() {
	return this->map->get_length();
}

int Robot_Playground::get_width() {
	return this->map->get_width();
}


//?????????????????????????????????????????????????
//std::vector<std::vector<block>> Robot_Playground::get_renderer_map() {
	//return this->map->get_renderer_map();
//}

bool Robot_Playground::is_robot_on_border(int robot_x, int robot_y) {
	if (((robot_x + shift_x) == (this->get_length() - 1)) || ((robot_x + shift_x) == 0)) {
		return true;
	}
	if (((robot_y + shift_y) == (this->get_width() - 1)) || ((robot_y + shift_y) == 0)) {
		return true;
	}
	return false;
}


//????????????????????????????????????????????
void Robot_Playground::increase_map(movement m) {
	switch (m) {
	case movement::_left: {
		++this->shift_x;
		break;
	}
	case movement::down: {
		++this->shift_y;
		break;
	}
	default: {break; }
	}

	this->map->increase_map(m);
	return;
}



