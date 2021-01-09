#pragma once
#include "game.h"
#include "Console.h"

//2 - parsing command, that we got from the console
class Parser {
private:
    Game* g;
public:
    Parser(Game*);
    void get_command(Console&);
};

