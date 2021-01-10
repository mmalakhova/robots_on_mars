#pragma once
#include "Mode.h"


class Auto : public IMode {
private:
	void delouse(Context* context);
	std::vector<movement> find_path_collector(Context* context);
	std::vector<movement> find_path_sapper(Context* context);
	bool bombs_on_map(Context* context);
	bool apples_on_map(Context* context);
	bool check_collector_move(std::vector<std::vector<cell>> map, int x, int y, int sapp_x, int sapp_y, int length, int width, bool sapp_alive);
	bool check_sapper_move(std::vector<std::vector<cell>> map, int x, int y, int coll_x, int coll_y, int length, int width);

public:
	virtual void sapper_on(Context* context);
	virtual void sapper_off(Context* context);
	virtual bool move_collector(Context* context, movement m);
	virtual void move_sapper(Context* context, movement m);
	virtual void grab(Context* context);
	virtual void scan(Context* context);
	virtual void scan(Context* context, int N);
	virtual void auto_grab(Context* context);
	virtual std::vector<std::vector<cell>> get_render_map(Context* context,
		int length, int width, int robot_screen_x, int robot_screen_y);

};

