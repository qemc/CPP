#include "Pacman.h"


Pacman::Pacman(const Texture& textrue) {

	setTexture(textrue);
	setPosition(Vector2f(384, 384));

}

void Pacman::control() {


	if (getPosition().x - getGlobalBounds().width >= 800) {
		setPosition(0, getPosition().y);
	}

	if (getPosition().x + getGlobalBounds().height <= 0) {
		setPosition(800, getPosition().y);

	}
	if (getPosition().y - getGlobalBounds().height >= 800) {
		setPosition(getPosition().x, 0);
	}
	if (getPosition().y + getGlobalBounds().height <= 0) {
		setPosition(getPosition().x, 800);
	}



	if (rusz == false) {
		p_velocity.x = 4;
		p_velocity.y = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
		p_velocity.x = 0;
		p_velocity.y = -4;
		rusz = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
		p_velocity.x = -4;
		p_velocity.y = 0;
		rusz = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
		p_velocity.x = 0;
		p_velocity.y = 4;
		rusz = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
		p_velocity.x = 4;
		p_velocity.y = 0;
		rusz = true;
	}
	move(p_velocity);
}