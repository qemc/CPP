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
//
//string Start::select() {
//
//	cout << "dzialam" << endl;
//
//		if (maps[0].getGlobalBounds().contains(m_pos_)&& Mouse::isButtonPressed(Mouse::Left)) {
//
//			start = true;
//
//			cout << "map1.png" << endl;
//
//			return "map1.png";
//		
//
//		}
//		if (maps[1].getGlobalBounds().contains(m_pos_) && Mouse::isButtonPressed(Mouse::Left)) {
//
//			start = true;
//
//			cout << "map2.png" << endl;
//
//			return "map2.png";
//
//
//		}
//		if (maps[2].getGlobalBounds().contains(m_pos_) && Mouse::isButtonPressed(Mouse::Left)) {
//
//			start = true;
//
//			cout << "map3.png" << endl;
//
//			return "map3.png";
//
//
//		}
//
//
//
//
//
//
//}


void Start::draw(RenderTarget& target, RenderStates state)const {

	for (int i = 0; i < 3; i++) {
		target.draw(maps[i]);
	}


}