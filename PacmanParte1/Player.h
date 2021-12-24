#pragma once
#include "ConsoleUtils.h"
#include "Map.h"
#include "TimeManager.h"
#include <stdlib.h>
#include <time.h>

class Player
{
private:
	COORD spawn;
	
	COORD direction;
	
	char character = 'O';
public:
	int player_points;
	COORD plposition;
	ConsoleUtils::CONSOLE_COLOR foreground = ConsoleUtils::CONSOLE_COLOR::DARK_YELLOW;
	ConsoleUtils::CONSOLE_COLOR background = ConsoleUtils::CONSOLE_COLOR::BLACK;
	Player();
	Player(COORD _spawn);
	void Draw();

	void PlayerMovement();

};

