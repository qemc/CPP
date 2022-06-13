#pragma once

#include "Enemy.h"
#include "Player.h"
#include "Game.h"

#include "Walls.h"


class Game :public Sprite
{
public:
	Game(const Texture &testure);
	bool start = false;
	void shoot(Player &player, Enemy &enemy);
	bool win = false;
	bool lost = false;

};

