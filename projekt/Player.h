#pragma once
#include "Soldiers.h"

class Player:public Soldiers
{

private:

	Vector2f m_pos2;
	Clock p_clock_s;
	Vector2f shootDir;
	Vector2f mouse_pos;
	Vector2f current_pos;


public:

	Player();

	Vector2f velocity;
	vector<Bullets> bullets_;

	static Vector2f m_pos;

	void draw(RenderTarget& target, RenderStates state)const override;
	void get_dir_vec_player(const Vector2f& mousepos);
	void control();
	
};


