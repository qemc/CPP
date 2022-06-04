#pragma once
#include "AnimatedSprite.h"

class Ball :public AnimatedSprite
{
public:

	Vector2f b_velocity;

	Ball(const Texture& texture, const IntRect& choose_sprite);


	void movement();

	void movement_c();


};

