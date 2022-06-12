#pragma once
#include "Menu.h"

class Start:public Menu
{


public:
	Start(const vector<Texture> &textures);

	void draw(RenderTarget& target, RenderStates state)const override;
	void update(const Vector2f &m_pos);
	string select();
	bool start = false;
	Vector2f m_pos_;
	vector<Sprite> maps;




};

