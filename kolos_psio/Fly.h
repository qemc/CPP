#pragma once
#include "AnimatedSprite.h"
#include "Spaceship.h"
class Fly:public AnimatedSprite
{
public:
	Vector2f fly_velocity;
	Fly(const Vector2f& position, const Texture& texture, const IntRect& choose_sprite);
	bool is_chasing = false;
	void chasing(const Spaceship& spaceship);
};

