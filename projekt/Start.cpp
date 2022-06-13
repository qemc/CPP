#include "Start.h"


Start::Start(const vector<Texture>& textures) {

	for (int i = 0; i < 3; i++) {
		Sprite sprite;
		sprite.setTexture(textures[i]);

		sprite.setScale(0.3, 0.3);
		maps.emplace_back(sprite);

	}
	maps[0].setPosition(10, 10);
	maps[1].setPosition(10, 290);
	maps[2].setPosition(10, 580);

	font.loadFromFile("huston.otf");
	title.setFont(font);

	title.setPosition(300, 300);
	title.setCharacterSize(40);
	title.setString("steal the tank!");

	inst.setFont(font);
	inst.setPosition(300, 350);
	inst.setCharacterSize(20);
	inst.setString("choose map");

	result.setFont(font);
	result.setPosition(300, 380);
	result.setCharacterSize(20);
	


}


void Start::update(const Vector2f& m_pos) {

	Color c(160, 160, 160);

	if (maps[0].getGlobalBounds().contains(m_pos)) {

		maps[0].setColor(c);

	}
	else {
		maps[0].setColor(Color::White);
	}

	if (maps[0].getGlobalBounds().contains(m_pos) && Mouse::isButtonPressed(Mouse::Left)) {
		start = true;
	}
	else {
		start = false;
	}


	if (maps[1].getGlobalBounds().contains(m_pos)) {

		maps[1].setColor(c);

	}
	else {
		maps[1].setColor(Color::White);
	}

	if (maps[1].getGlobalBounds().contains(m_pos) && Mouse::isButtonPressed(Mouse::Left)) {
		start = true;
	}
	else {
		start = false;
	}



	if (maps[2].getGlobalBounds().contains(m_pos)) {

		maps[2].setColor(c);

	}
	else {
		maps[2].setColor(Color::White);
	}

	if (maps[2].getGlobalBounds().contains(m_pos) && Mouse::isButtonPressed(Mouse::Left)) {
		start = true;
	}
	else {
		start = false;
	}

	



}

void Start::draw(RenderTarget& target, RenderStates state)const {

	for (int i = 0; i < 3; i++) {
		target.draw(maps[i]);
	}
	target.draw(this->title);
	target.draw(this->inst);
	target.draw(this->result);
}