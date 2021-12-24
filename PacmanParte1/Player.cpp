#include "Player.h"
#include "Inputs.h"
#include "main.cpp"

Player::Player()
{
	spawn = { 0,0 };
	plposition = { 0,0 };
}

Player::Player(COORD _spawn)
{
	spawn = _spawn;
	plposition = _spawn;
}

void Player::Draw()
{
	ConsoleUtils::Console_SetPos(plposition);
	ConsoleUtils::Console_SetColor(foreground, background);
	std::cout << character;
}

void Player::PlayerMovement() 
{
    int player_y_new = plposition.Y;
    int player_x_new = plposition.X;
    switch (input)
    {
    case UP:
        player_y_new--;
        break;
    case DOWN:
        player_y_new++;
        break;
    case RIGHT:
        player_x_new++;
        break;
    case LEFT:
        player_x_new--;
        break;
    case QUIT:
        run = false;
        break;
    }
    if (player_x_new < 0)
    {
        player_x_new = pacman_map.Width - 1;
    }
    player_x_new %= pacman_map.Width;
    if (player_y_new < 0)
    {
        player_y_new = pacman_map.Height - 1;
    }
    player_y_new %= pacman_map.Height;

    switch (pacman_map.GetTile(player_x_new, player_y_new))
    {
    case Map::MAP_TILES::MAP_WALL:
        player_y_new = plposition.Y;
        player_x_new = plposition.X;
        break;
    case Map::MAP_TILES::MAP_POINT:
        pacman_map.points--;
        player_points++;
        pacman_map.SetTile(player_x_new, player_y_new, Map::MAP_TILES::MAP_EMPTY);
        break;
    case Map::MAP_TILES::MAP_POWERUP:
        player_points += 25;
        for (size_t i = 0; i < enemigos.size(); i++)
        {
            enemigos[i].PowerUpPicked();
        }
        pacman_map.SetTile(player_x_new, player_y_new, Map::MAP_TILES::MAP_EMPTY);
        break;
    }

    plposition.Y = player_y_new;
    plposition.X = player_x_new;
}