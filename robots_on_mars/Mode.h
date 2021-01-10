#pragma once
#include "Context.h"
#include "Playground.h"

class IMode {
private:

public:
	virtual void sapper_on(Context* context) = 0;
	virtual void sapper_off(Context* context) = 0;
	virtual bool move_collector(Context* context, movement m) = 0;
	virtual void move_sapper(Context* context, movement m) = 0;
	virtual void grab(Context* context) = 0;
	virtual void scan(Context* context) = 0;
	virtual void scan(Context* context, int N) = 0;
	virtual void auto_grab(Context* context) = 0;
	virtual std::vector<std::vector<cell>> get_render_map(Context* context, 
	int length, int width, int robot_screen_x, int robot_screen_y) = 0;

};



