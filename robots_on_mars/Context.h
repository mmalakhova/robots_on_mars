#pragma once
#include "Main_Map.h"
#include "Robot.h"
#include "Collector.h"
#include "Sapper.h"
#include "Playground.h"

class Context
{
private:
public:
	Main_Map* map;
	Collector* Rob_C;
	Sapper* Rob_S;

	Context();
	~Context();

};

