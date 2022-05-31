#pragma once
#include "Soldiers.h"

class Player:public Soldiers
{
public:

	Player();



	Vector2f shootDir;
	Vector2f mouse_pos;
	Vector2f current_pos;


	void draw(RenderTarget& target, RenderStates state)const override;

	void get_dir_vec_player(const Vector2f& mousepos);

	static Vector2f m_pos;
	Vector2f m_pos2;
	Vector2f velocity;

	Clock p_clock_s;
	vector<Bullets> bullets_;


	void control();


};


