#include "Paddle.h"


Paddle::Paddle(const Texture& texture, const Vector2f& position) {


	setTexture(texture);
	setPosition(position);
	setRotation(90);



}

void Paddle::control_k() {

	if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
		p_velocity.x = 0;
		p_velocity.y = -4;
		
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
		p_velocity.x = 0;
		p_velocity.y = 4;
		
	}

	if (this->getPosition().y + this->getGlobalBounds().height >= 800) {
		this->setPosition(this->getPosition().x, 800 - this->getGlobalBounds().height);
		//p_velocity.y = 0;
	}
	if (this->getPosition().y  <= 0) {
		this->setPosition(this->getPosition().x,  0);
		//p_velocity.y = 0;
	}


	move(p_velocity);

}



void Paddle::control_m() {

	if (rusz == true) {

		if (mouse_pos.y < getPosition().y) {

			p_velocity.y = -3;


		}
		if (mouse_pos.y > getPosition().y) {

			p_velocity.y = 3;

		}

	}

	if (this->getPosition().y + this->getGlobalBounds().height >= 800) {
		this->setPosition(this->getPosition().x, 800 - this->getGlobalBounds().height);
		//p_velocity.y = 0;

	}
	if (this->getPosition().y <= 0) {
		this->setPosition(this->getPosition().x, 0);
		//p_velocity.y = 0;
	}
		


	


		move(p_velocity);

}