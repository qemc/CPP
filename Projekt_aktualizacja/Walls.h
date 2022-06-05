#pragma once


#include "Bullets.h"
#include "Player.h"
#include "Enemy.h"



class Walls : public RectangleShape
{
public:

	Walls(const Vector2f& position, const Vector2f& size);
	void collision(Player &player);
	void bullet_collision(Player &player);

	FloatRect playerBounds;
	FloatRect rectangleBounds;
};

