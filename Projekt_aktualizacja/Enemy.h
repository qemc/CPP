#pragma once
#include "Soldiers.h"
#include "Bullets.h"
#include "Player.h"

class Enemy:public Soldiers
{
public:
	Enemy(const Vector2f& range_, const Vector2f& position, bool vert_, const Vector2f& range_size, const Vector2f& range_pos);

	void control(Player player);
	

	Vector2f range_a;
	bool vert;
	Vector2f velocity;

	RectangleShape range;
	
	vector<Bullets> bullets;
	void draw(RenderTarget& target, RenderStates state)const override;

	Vector2f dirVec;

	Clock e_clock_s;

	Vector2f player_pos;
	Vector2f current_pos;
	Vector2f shootDir;

	void move_();
};

