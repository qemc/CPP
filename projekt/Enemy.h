#pragma once
#include "Soldiers.h"
#include "Bullets.h"
#include "Player.h"

class Enemy:public Soldiers
{


private:
	Vector2f range_a;
	Vector2f velocity;
	Vector2f player_pos;
	Vector2f current_pos;
	Vector2f shootDir;
	Vector2f dirVec;

	RectangleShape range;

	Clock e_clock_s;

	vector<Bullets> bullets;

	bool vert;

public:


	Enemy(const Vector2f& range_, const Vector2f& position, bool vert_, const Vector2f& range_size, const Vector2f& range_pos);

	void control(Player player);
	void draw(RenderTarget& target, RenderStates state)const override;
	void move_();
};

