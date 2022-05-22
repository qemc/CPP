#pragma once
#include "AnimatedSprite.h"
class Asteroid :public AnimatedSprite
{
public:
	Asteroid(const Vector2f &position, const Texture& texture);
	Vector2f asteroid_velocity;
	void move_();
	void colision();

};

