#pragma once
#include "Mode.h"
#include "Context.h"
#include "Playground.h"


class Manual : public IMode {
private:
	//зачем нужен отдельный класс Сканнер в привате
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

