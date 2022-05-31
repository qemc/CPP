#pragma once
#include "Soldiers.h"
#include "Bullets.h"
#include "Player.h"

class Enemy:public Soldiers
{
public:
	Enemy();

	void control(Player player);
	Vector2f velocity;

	
	vector<Bullets> bullets;
	void draw(RenderTarget& target, RenderStates state)const override;

	Vector2f dirVec;

	Clock e_clock_s;

	Vector2f player_pos;
	Vector2f current_pos;
	Vector2f shootDir;
};

