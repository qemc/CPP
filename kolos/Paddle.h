#pragma once
#include "AnimatedSprite.h"

class Paddle :public AnimatedSprite
{
public:
	Vector2f p_velocity;
	bool rusz = false;
	Paddle(const Texture& texture, const Vector2f& position);

	void control_k();
	Vector2f mouse_pos;

	int points = 0;
	

	void control_m();


};

