#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ostream>

enum cell {rock, _empty, apple, bomb, unknown, sapper};

enum movement {_right, _left, up, down};

class Playground
{
private:
	cell** map;
	int length, width;
public:
	Playground();
	~Playground();
	Playground(const Playground& );

	int get_length();
	int get_width();
	cell get_data(int , int);
	void set(int, int, cell);

	void increase_map(movement m);
	//œŒ ¿ Õ≈œŒÕﬂ“ÕŒ, Õ”∆ÕŒ À» ›“Œ ¬ ÃŒ≈… –≈¿À»«¿÷»»
	//std::vector<std::vector<block>> Playground::get_renderer_map();
};

std::ostream& operator<<(std::ostream&, Playground& );


class Robot_Playground
{
private:
	Playground* map;
	int shift_x, shift_y;
public:
	Robot_Playground();
	~Robot_Playground();
	Robot_Playground(const Robot_Playground&);

	int get_length();
	int get_width();
	std:: pair<int, int> get_shift();
	cell get_data(int, int);
	void put(int, int, cell);

	bool is_robot_on_border(int, int);
	void increase_map(movement);

};

