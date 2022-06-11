#pragma once

#include "Enemy.h"
#include "Player.h"
#include "Game.h"

#include "Walls.h"


class Game
{
public:
	Game game();
	bool start = false;



	void shoot(Player &player, Enemy &enemy);


	bool atack;

	



};

