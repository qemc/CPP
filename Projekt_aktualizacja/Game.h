#pragma once

#include "Enemy.h"
#include "Player.h"
#include "Game.h"

#include "Walls.h"


class Game
{
public:
	void update(Player player, Enemy enemy);


	void bullet_player_collision(Walls &wall);


	bool atack;

	



};

