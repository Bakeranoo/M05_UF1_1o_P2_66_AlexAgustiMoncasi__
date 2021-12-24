#pragma once
#include "Map.h"
#include <stdlib.h>
#include<time.h>

class Enemy
{
private:
	COORD spawn;
	COORD position;
	COORD direction;
	char character = 'X';
	ConsoleUtils::CONSOLE_COLOR foreground = ConsoleUtils::CONSOLE_COLOR::DARK_RED;
	ConsoleUtils::CONSOLE_COLOR background = ConsoleUtils::CONSOLE_COLOR::BLACK;
	void RandomDirection();
public:
	Enemy();
	Enemy(COORD _spawn);
	void Draw();
	void Update(Map* _map);
};

